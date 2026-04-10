#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
using namespace std;


//  RE-THROW DEMO

    // Simulasi logger sederhana
        void logError(const string& konteks, const string& pesan) {
            cerr << "[LOG] " << konteks << ": " << pesan << endl;
        }

    // Fungsi layer bawah yang throw
        void operasiDB(bool gagal) {
            if (gagal) throw runtime_error("Koneksi database timeout");
            cout << "  DB: operasi berhasil" << endl;
        }

    // Layer tengah: log lalu re-throw
        void layerService(bool gagal) {
            try {
                operasiDB(gagal);
            }
            catch (const exception& e) {
                logError("layerService", e.what());
                throw;   // re-throw: lempar exception yang SAMA ke atas
            }
        }

    // Layer atas: tangkap akhir
        void layerController(bool gagal) {
            try {
                layerService(gagal);
            }
            catch (const runtime_error& e) {
                cout << "  [Controller] Exception ditangkap: " << e.what() << endl;
            }
        }


//  EXCEPTION SAFETY DEMO

    // Resource sederhana untuk demo
        class Resource {
        public:
            string nama;
            Resource(const string& n) : nama(n) {
                cout << "  [+] " << nama << " dibuat" << endl;
            }
            ~Resource() {
                cout << "  [-] " << nama << " dihancurkan (aman)" << endl;
            }
        };

    // BERBAHAYA: raw pointer tanpa RAII
        void contohTidakAman(bool gagal) {
            int* data = new int[100];   // alokasi manual
            cout << "  Raw pointer dialokasikan" << endl;
            if (gagal) {
                throw runtime_error("Error sebelum delete");
                // delete[] data;  // TIDAK PERNAH DIEKSEKUSI -> MEMORY LEAK!
            }
            delete[] data;
            cout << "  Raw pointer dibebaskan (hanya kalau tidak throw)" << endl;
        }

    // AMAN: pakai RAII (unique_ptr)
        void contohAman(bool gagal) {
            auto data = make_unique<int[]>(100);   // RAII
            cout << "  unique_ptr dialokasikan" << endl;
            if (gagal) {
                throw runtime_error("Error tapi unique_ptr aman");
                // unique_ptr otomatis di-delete saat exception!
            }
            cout << "  unique_ptr dibebaskan saat keluar scope" << endl;
        }


//  EXCEPTION DI CONSTRUCTOR
    class BukuCatatan {
    private:
        string judul_;
        int    halaman_;
    public:
        BukuCatatan(const string& judul, int halaman) {
            if (judul.empty())
                throw invalid_argument("Judul tidak boleh kosong");
            if (halaman <= 0)
                throw invalid_argument("Halaman harus positif, dapat: " + to_string(halaman));
            judul_   = judul;
            halaman_ = halaman;
            cout << "  BukuCatatan '" << judul_ << "' dibuat (" << halaman_ << " hal)" << endl;
        }
        ~BukuCatatan() {
            cout << "  BukuCatatan '" << judul_ << "' dihancurkan" << endl;
        }
        string judul()   const { return judul_; }
        int    halaman() const { return halaman_; }
    };


//  STRONG GUARANTEE: copy-then-swap idiom
    class DataStore {
    private:
        vector<int> data_;
    public:
        DataStore(initializer_list<int> init) : data_(init) {}

        void tampilkan() const {
            cout << "  DataStore: [";
            for (int i = 0; i < (int)data_.size(); i++) {
                cout << data_[i];
                if (i < (int)data_.size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }

        // Strong guarantee: copy-then-swap
        // Kalau ada yang throw, data_ asli tidak berubah
        void tambahData(const vector<int>& baru) {
            vector<int> kopian = data_;   // buat salinan dulu
            for (int x : baru) {
                if (x < 0) throw invalid_argument("Nilai negatif tidak diperbolehkan: " + to_string(x));
                kopian.push_back(x);
            }
            data_.swap(kopian);   // baru swap kalau semua berhasil (no-throw!)
        }
    };


int main() {

    // ----- 1. Re-throw -----
        cout << "=== 1. Re-throw Exception ===" << endl;

        cout << "Kasus berhasil:" << endl;
        layerController(false);

        cout << "Kasus gagal (log + re-throw):" << endl;
        layerController(true);


    // ----- 2. RAII vs Raw Pointer -----
        cout << endl << "=== 2. RAII vs Raw Pointer ===" << endl;

        cout << "Raw pointer (tidak aman):" << endl;
        try {
            contohTidakAman(true);
        }
        catch (const exception& e) {
            cout << "  Caught: " << e.what() << endl;
            cout << "  MEMORY LEAK terjadi! data tidak di-delete." << endl;
        }

        cout << endl << "unique_ptr (RAII, aman):" << endl;
        try {
            contohAman(true);
        }
        catch (const exception& e) {
            cout << "  Caught: " << e.what() << endl;
            cout << "  Tidak ada memory leak! unique_ptr sudah auto-delete." << endl;
        }


    // ----- 3. RAII: Destruktor Selalu Dipanggil -----
        cout << endl << "=== 3. Destruktor Selalu Dipanggil (Stack Unwinding) ===" << endl;

        try {
            Resource r1("R1");
            Resource r2("R2");
            Resource r3("R3");
            throw runtime_error("Error di tengah jalan");
            Resource r4("R4");  // tidak dibuat
        }
        catch (const exception& e) {
            cout << "  Caught: " << e.what() << endl;
            cout << "  r1, r2, r3 semua dihancurkan saat stack unwind!" << endl;
        }


    // ----- 4. Exception di Constructor -----
        cout << endl << "=== 4. Exception di Constructor ===" << endl;

        struct TestBuku { string judul; int hal; };
        TestBuku test[] = {
            {"C++ Handbook", 300},
            {"",             100},
            {"Valid Book",  -50}
        };

        for (const auto& t : test) {
            try {
                BukuCatatan buku(t.judul, t.hal);
            }
            catch (const invalid_argument& e) {
                cout << "  Gagal buat buku: " << e.what() << endl;
            }
        }


    // ----- 5. Strong Guarantee -----
        cout << endl << "=== 5. Strong Guarantee (copy-then-swap) ===" << endl;

        DataStore store = {10, 20, 30};
        cout << "Awal:";
        store.tampilkan();

        cout << "Tambah data valid {40, 50}:" << endl;
        try {
            store.tambahData({40, 50});
        }
        catch (...) {}
        cout << "Setelah:";
        store.tampilkan();

        cout << "Tambah data invalid {60, -1} (ada negatif):" << endl;
        try {
            store.tambahData({60, -1});
        }
        catch (const invalid_argument& e) {
            cout << "  Exception: " << e.what() << endl;
        }
        cout << "Setelah (harus sama seperti sebelumnya!):";
        store.tampilkan();

        return 0;
}

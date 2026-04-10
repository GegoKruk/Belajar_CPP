#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
using namespace std;


//  PERBANDINGAN: BENAR vs SALAH

    // ----- Best Practice 1: Throw by value, catch by const ref -----
        void demoThrowCatch() {
            cout << "--- Throw by value, Catch by const ref ---" << endl;

            // BENAR
            try {
                throw runtime_error("Pesan error");
            }
            catch (const runtime_error& e) {   // const reference - efisien & polimorfisme
                cout << "  Benar: " << e.what() << endl;
            }

            // SALAH tapi ditampilkan untuk edukasi
            cout << "  Salah: catch (runtime_error e) -> membuat salinan, kehilangan info polimorfisme" << endl;
            cout << "  Salah: catch (runtime_error* e) -> siapa yang delete pointer-nya?" << endl;
        }


    // ----- Anti-pattern: Exception Swallowing -----
        void antiPatternSwallowing() {
            cout << "--- Anti-pattern: Exception Swallowing ---" << endl;

            // SANGAT SALAH: exception hilang tanpa jejak
            try {
                throw runtime_error("Error penting!");
            }
            catch (...) {
                // Tidak ada log, tidak ada re-throw
                // Error ini "ditelan" -> bug tersembunyi yang sangat sulit ditemukan!
            }
            cout << "  Exception 'ditelan' - tidak ada tanda error!" << endl;
            cout << "  Ini sangat berbahaya karena bug tersembunyi." << endl;

            // LEBIH BAIK: minimal log
            try {
                throw runtime_error("Error penting!");
            }
            catch (const exception& e) {
                cerr << "  [LOG] Exception: " << e.what() << endl;
                // throw;   // bisa re-throw kalau mau propagate ke atas
            }
        }


    // ----- Anti-pattern: Throw dari Destruktor -----
        class BerbahayaClass {
        public:
            ~BerbahayaClass() {
                // JANGAN LAKUKAN INI!
                // throw runtime_error("dari destruktor");
                // Kalau ada exception aktif -> terminate() -> CRASH!
            }
        };

        class AmanClass {
        public:
            ~AmanClass() noexcept {
                try {
                    // lakukan pembersihan yang mungkin throw
                }
                catch (...) {
                    // tangkap di sini, jangan propagate
                    cerr << "  [LOG] Error saat cleanup di destruktor" << endl;
                }
            }
        };


    // ----- Pola: Validasi Input -----
        struct UserInput {
            string nama;
            int    umur;
            string email;
        };

        UserInput validasiInput(const string& nama, int umur, const string& email) {
            if (nama.empty())
                throw invalid_argument("Nama tidak boleh kosong");
            if (nama.length() < 3)
                throw invalid_argument("Nama terlalu pendek (min 3 karakter): '" + nama + "'");
            if (umur < 0 || umur > 120)
                throw out_of_range("Umur tidak valid (0-120): " + to_string(umur));
            if (email.find('@') == string::npos)
                throw invalid_argument("Email tidak valid: '" + email + "'");
            return {nama, umur, email};
        }


    // ----- Pola: Exception di Constructor -----
        class Koneksi {
        private:
            string host_;
            int    port_;
            bool   terhubung_;
        public:
            Koneksi(const string& host, int port) : terhubung_(false) {
                if (host.empty())
                    throw invalid_argument("Host tidak boleh kosong");
                if (port <= 0 || port > 65535)
                    throw out_of_range("Port tidak valid (1-65535): " + to_string(port));
                if (host == "host-mati")
                    throw runtime_error("Tidak bisa konek ke: " + host);
                host_      = host;
                port_      = port;
                terhubung_ = true;
                cout << "  Koneksi ke " << host << ":" << port << " berhasil" << endl;
            }
            ~Koneksi() {
                if (terhubung_) {
                    cout << "  Koneksi ke " << host_ << ":" << port_ << " ditutup" << endl;
                }
            }
            bool terhubung() const noexcept { return terhubung_; }
        };


    // ----- Pola: Exception vs Return Code -----
        // Kasus 1: Gunakan exception (kondisi tidak normal)
            void prosesFile(const string& namaFile) {
                if (namaFile.empty())
                    throw invalid_argument("Nama file tidak boleh kosong");
                if (namaFile.find(".cpp") == string::npos)
                    throw runtime_error("Hanya file .cpp yang diizinkan: " + namaFile);
                cout << "  Proses file: " << namaFile << " berhasil." << endl;
            }

        // Kasus 2: Gunakan return (kondisi normal yang bisa gagal)
            bool cariElemenArray(const int arr[], int n, int target, int& indexHasil) {
                for (int i = 0; i < n; i++) {
                    if (arr[i] == target) {
                        indexHasil = i;
                        return true;
                    }
                }
                return false;   // tidak ditemukan = kondisi normal, bukan error!
            }


int main() {

    // ----- 1. Best Practice: Throw/Catch -----
        cout << "=== 1. Best Practice: Throw/Catch ===" << endl;
        demoThrowCatch();


    // ----- 2. Anti-pattern: Swallowing -----
        cout << endl << "=== 2. Anti-pattern: Exception Swallowing ===" << endl;
        antiPatternSwallowing();


    // ----- 3. Pola Validasi Input -----
        cout << endl << "=== 3. Pola Validasi Input ===" << endl;

        struct TestInput { string nama; int umur; string email; };
        TestInput tests[] = {
            {"Budi",   25, "budi@mail.com"},
            {"",       20, "sari@mail.com"},
            {"Al",     20, "andi@mail.com"},
            {"Dina", -5,   "dina@mail.com"},
            {"Eka",   30,   "eka-no-at"}
        };

        for (const auto& t : tests) {
            try {
                UserInput hasil = validasiInput(t.nama, t.umur, t.email);
                cout << "  OK: " << hasil.nama << ", " << hasil.umur << endl;
            }
            catch (const invalid_argument& e) {
                cout << "  invalid_argument: " << e.what() << endl;
            }
            catch (const out_of_range& e) {
                cout << "  out_of_range: " << e.what() << endl;
            }
        }


    // ----- 4. Exception di Constructor -----
        cout << endl << "=== 4. Exception di Constructor ===" << endl;

        struct TestKoneksi { string host; int port; };
        TestKoneksi koneksiTests[] = {
            {"db.server.com", 5432},
            {"",              5432},
            {"api.server.com", 0},
            {"host-mati",     8080}
        };

        for (const auto& k : koneksiTests) {
            try {
                Koneksi conn(k.host, k.port);
            }
            catch (const exception& e) {
                cout << "  Gagal: " << e.what() << endl;
            }
        }


    // ----- 5. Exception vs Return Code -----
        cout << endl << "=== 5. Exception vs Return Code ===" << endl;

        cout << "Exception (kondisi tidak normal):" << endl;
        string files[] = {"main.cpp", "", "data.txt"};
        for (const string& f : files) {
            try {
                prosesFile(f);
            }
            catch (const exception& e) {
                cout << "  Error: " << e.what() << endl;
            }
        }

        cout << endl << "Return code (cari elemen - kondisi normal):" << endl;
        int data[] = {10, 20, 30, 40, 50};
        int idx;
        bool ketemu = cariElemenArray(data, 5, 30, idx);
        cout << "  Cari 30: " << (ketemu ? "ketemu di index " + to_string(idx) : "tidak ketemu") << endl;
        ketemu = cariElemenArray(data, 5, 99, idx);
        cout << "  Cari 99: " << (ketemu ? "ketemu di index " + to_string(idx) : "tidak ketemu") << endl;


    // ----- 6. Ringkasan Best Practices -----
        cout << endl << "=== 6. Ringkasan Best Practices ===" << endl;
        cout << "Do (Lakukan):" << endl;
        cout << "  - throw by value, catch by const reference" << endl;
        cout << "  - Urutan catch dari spesifik ke umum" << endl;
        cout << "  - Pakai exception class standar atau turunannya" << endl;
        cout << "  - noexcept untuk destruktor, swap, move semantics" << endl;
        cout << "  - Log sebelum re-throw untuk debugging" << endl;
        cout << "  - RAII untuk resource safety" << endl;
        cout << endl;
        cout << "Don't (Jangan):" << endl;
        cout << "  - Jangan 'telan' exception: catch (...) {}" << endl;
        cout << "  - Jangan throw dari destruktor" << endl;
        cout << "  - Jangan catch by value atau by pointer" << endl;
        cout << "  - Jangan throw tipe primitif (int, C-string)" << endl;
        cout << "  - Jangan pakai exception untuk flow control biasa" << endl;
        cout << "  - Jangan pakai exception specification lama: throw(int)" << endl;

    return 0;
}

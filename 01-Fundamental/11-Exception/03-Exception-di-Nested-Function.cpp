
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


// ----- Demo stack unwinding -----
    class Resource {
    public:
        string nama;
        Resource(const string& n) : nama(n) {
            cout << "  [+] Resource '" << nama << "' dibuat" << endl;
        }
        ~Resource() {
            cout << "  [-] Resource '" << nama << "' dihancurkan (destruktor)" << endl;
        }
    };


// ----- Fungsi berlevel -----
    void level3() {
        Resource r3("r3-dalam-level3");
        cout << "  level3: sebelum throw" << endl;
        throw runtime_error("Exception dari level3!");
        cout << "  level3: setelah throw (tidak dieksekusi)" << endl;
    }

    void level2() {
        Resource r2("r2-dalam-level2");
        cout << "  level2: sebelum panggil level3" << endl;
        level3();
        cout << "  level2: setelah panggil level3 (tidak dieksekusi)" << endl;
    }

    void level1() {
        Resource r1("r1-dalam-level1");
        cout << "  level1: sebelum panggil level2" << endl;
        level2();
        cout << "  level1: setelah panggil level2 (tidak dieksekusi)" << endl;
    }


// ----- Fungsi dengan catch di tengah -----
    void level3b() {
        throw invalid_argument("Error dari level3b");
    }

    void level2b() {
        try {
            level3b();   // exception dari level3b
        }
        catch (const invalid_argument& e) {
            cout << "  level2b menangkap: " << e.what() << endl;
            // Exception BERHENTI di sini, tidak naik lagi
        }
    }


// ----- Fungsi yang hanya catch sebagian -----
    void level3c() {
        throw runtime_error("runtime error dari level3c");
    }

    void level2c() {
        try {
            level3c();
        }
        catch (const invalid_argument& e) {
            // Tipe tidak cocok -> exception TETAP naik!
            cout << "  level2c: catch ini tidak cocok" << endl;
        }
        // runtime_error tidak ditangkap, akan naik ke pemanggil
    }


int main() {

    // ----- 1. Exception Melewati 3 Level -----
        cout << "=== 1. Exception Propagate Melewati 3 Level ===" << endl;
        cout << endl << "Urutan kejadian:" << endl;

        try {
            level1();
        }
        catch (const runtime_error& e) {
            cout << endl;
            cout << "  main: exception tertangkap: " << e.what() << endl;
        }

        cout << endl << "Perhatikan:" << endl;
        cout << "  - Destruktor r3, r2, r1 dipanggil saat stack unwind" << endl;
        cout << "  - Urutan destruktor = kebalikan dari konstruktor" << endl;
        cout << "  - Tidak ada resource leak!" << endl;


    // ----- 2. Catch di Tengah Jalan -----
        cout << endl << "=== 2. Catch di Tengah Jalan (level2b) ===" << endl;

        try {
            level2b();
            cout << "  main: kode setelah level2b tetap jalan" << endl;
            cout << "  (karena exception sudah ditangkap di level2b)" << endl;
        }
        catch (const exception& e) {
            cout << "  main catch: tidak sampai sini" << endl;
        }


    // ----- 3. Exception Naik Terus Kalau Tipe Tidak Cocok -----
        cout << endl << "=== 3. Catch Tidak Cocok -> Naik Terus ===" << endl;

        try {
            level2c();   // level2c punya catch tapi tidak cocok
        }
        catch (const runtime_error& e) {
            cout << "  main: akhirnya tertangkap di sini: " << e.what() << endl;
        }


    // ----- 4. Tidak Ada Catch -> Terminate -----
        cout << endl << "=== 4. Tidak Ada Catch -> terminate() ===" << endl;

        cout << "Jika exception tidak tertangkap di MANA PUN:" << endl;
        cout << "  -> std::terminate() dipanggil" << endl;
        cout << "  -> Program CRASH dengan pesan error" << endl;
        cout << "  -> Selalu pastikan ada catch untuk exception penting!" << endl;

        cout << endl << "Contoh kode berbahaya:" << endl;
        cout << "  void fungsi() { throw runtime_error(\"error\"); }" << endl;
        cout << "  int main() { fungsi(); }   // tidak ada try-catch!" << endl;
        cout << "  // -> terminate() dipanggil -> crash!" << endl;


    // ----- 5. Simulasi Call Stack yang Lebih Realistis -----
        cout << endl << "=== 5. Simulasi Nyata: Validasi Berlapis ===" << endl;

        auto hitungRataRata = [](const int arr[], int n) -> double {
            if (n <= 0) throw invalid_argument("Array tidak boleh kosong");
            int total = 0;
            for (int i = 0; i < n; i++) total += arr[i];
            return (double)total / n;
        };

        auto prosesLaporan = [&](const int data[], int n) {
            cout << "  prosesLaporan: hitung rata-rata..." << endl;
            double rata = hitungRataRata(data, n);
            cout << "  prosesLaporan: rata-rata = " << rata << endl;
        };

    // Kasus normal
        cout << "Kasus normal:" << endl;
        try {
            int data1[] = {10, 20, 30, 40, 50};
            prosesLaporan(data1, 5);
        }
        catch (const invalid_argument& e) {
            cout << "  Error: " << e.what() << endl;
        }

    // Kasus error (array kosong)
        cout << "Kasus array kosong:" << endl;
        try {
            prosesLaporan(nullptr, 0);
        }
        catch (const invalid_argument& e) {
            cout << "  Error tertangkap di main: " << e.what() << endl;
        }

    return 0;
}


#include <iostream>
#include <string>
using namespace std;


// GLOBAL VARIABLE -- di luar semua function
// Ini contoh BURUK (global variable yang bisa diubah):
    int globalCounter = 0;

// Ini contoh BAIK (konstanta global):
    const double PI = 3.14159265358979;
    const string VERSI = "1.0.0";
    const int BATAS_NILAI = 100;


// DEMO LOCAL VARIABLE
    void demoLocalVariable() {
        cout << "------------------------------------------------------------" << endl;
        cout << "  1. Local Variable" << endl;
        cout << "------------------------------------------------------------" << endl;

        int lokal = 42;
        string pesan = "Saya lokal!";
        cout << "\n  Di dalam demoLocalVariable():" << endl;
        cout << "  lokal = " << lokal << endl;
        cout << "  pesan = " << pesan << endl;

        // Scope blok -- variabel hanya ada di dalam { }
        {
            int dalamBlok = 100;
            cout << "\n  Di dalam blok { }:" << endl;
            cout << "  dalamBlok = " << dalamBlok << "  (hanya ada di dalam blok ini)" << endl;
            cout << "  lokal     = " << lokal     << "  (masih bisa akses dari luar blok)" << endl;
        }
        // dalamBlok SUDAH TIDAK ADA di sini
        // cout << dalamBlok;  // <- COMPILE ERROR jika di-uncomment

        cout << "\n  Setelah blok { }, dalamBlok sudah tidak bisa diakses." << endl;

        // Scope di for loop
        cout << "\n  Scope variabel i di for loop:" << endl;
        for (int i = 0; i < 3; i++) {
            int dalamFor = i * 10;   // dibuat dan dihapus tiap iterasi
            cout << "  i=" << i << ", dalamFor=" << dalamFor << endl;
        }
        // i dan dalamFor SUDAH TIDAK ADA
        // cout << i;        // <- COMPILE ERROR
        // cout << dalamFor; // <- COMPILE ERROR

        cout << "\n  Variabel dengan nama sama di scope berbeda:" << endl;
        int x = 1;
        cout << "  x = " << x << " (scope function)" << endl;
        {
            int x = 2;   // x baru, shadow x luar
            cout << "  x = " << x << " (scope blok dalam)" << endl;
            {
                int x = 3;   // x baru lagi
                cout << "  x = " << x << " (scope blok dalam-dalam)" << endl;
            }
            cout << "  x = " << x << " (kembali ke scope blok dalam)" << endl;
        }
        cout << "  x = " << x << " (kembali ke scope function)" << endl;
    }

// DEMO GLOBAL VARIABLE
    void tambahCounter() {
        globalCounter++;   // function apapun bisa ubah ini!
    }

    void resetCounter() {
        globalCounter = 0;
    }

    void demoGlobalVariable() {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  2. Global Variable" << endl;
        cout << "------------------------------------------------------------" << endl;

        cout << "\n  Konstanta global (ini BAIK):" << endl;
        cout << "  PI     = " << PI     << endl;
        cout << "  VERSI  = " << VERSI  << endl;
        cout << "  BATAS  = " << BATAS_NILAI << endl;

        cout << "\n  Global variable yang bisa diubah (ini BURUK):" << endl;
        cout << "  globalCounter = " << globalCounter << " (awal)" << endl;
        tambahCounter();
        tambahCounter();
        tambahCounter();
        cout << "  globalCounter = " << globalCounter << " (setelah tambahCounter 3x)" << endl;
        resetCounter();
        cout << "  globalCounter = " << globalCounter << " (setelah resetCounter)" << endl;

        cout << "\n  Masalah dengan global variable yang bisa diubah:" << endl;
        cout << "  - Siapapun di program bisa mengubahnya kapan saja" << endl;
        cout << "  - Susah dilacak: siapa yang mengubah? di baris mana?" << endl;
        cout << "  - Susah di-test secara terisolasi" << endl;
        cout << "  - Di program besar: sumber bug yang sulit ditemukan" << endl;
    }

// DEMO VARIABLE SHADOWING
    int nilaiGlobal = 100;   // global

    void demoShadowing() {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  3. Variable Shadowing" << endl;
        cout << "------------------------------------------------------------" << endl;

        int nilaiGlobal = 5;   // local -- menutupi / shadow global!

        cout << "\n  nilaiGlobal global = 100 (di luar function)" << endl;
        cout << "  nilaiGlobal local  = 5   (di dalam function ini)" << endl;
        cout << "\n  Di dalam demoShadowing():" << endl;
        cout << "  nilaiGlobal = " << nilaiGlobal << "  (local shadow global!)" << endl;
        cout << "  ::nilaiGlobal = " << ::nilaiGlobal << "  (:: paksa akses global)" << endl;

        {
            int nilaiGlobal = 999;
            cout << "\n  Di dalam blok nested:" << endl;
            cout << "  nilaiGlobal   = " << nilaiGlobal   << "  (blok ini)" << endl;
            cout << "  ::nilaiGlobal = " << ::nilaiGlobal << "  (global, via ::)" << endl;
        }

        cout << "\n  Kembali ke scope function:" << endl;
        cout << "  nilaiGlobal = " << nilaiGlobal << "  (local function lagi)" << endl;

        cout << "\n  Saran: hindari nama variabel yang sama dengan global." << endl;
        cout << "  Membingungkan dan rawan bug!" << endl;
    }

// DEMO BEST PRACTICE
    // BURUK -- bergantung global variable
        int hasilGlobal = 0;
        void hitungBuruk(int a, int b) {
            hasilGlobal = a * b + 10;   // mengisi global
        }

    // BAIK -- pure function, data via parameter dan return
        int hitungBaik(int a, int b) {
            return a * b + 10;   // kembalikan via return, tidak sentuh global
        }

        void demoBestPractice() {
            cout << "\n------------------------------------------------------------" << endl;
            cout << "  4. Best Practice: Parameter & Return Value" << endl;
            cout << "------------------------------------------------------------" << endl;

            cout << "\n  Contoh BURUK -- function bergantung global:" << endl;
            hitungBuruk(5, 3);
            cout << "  hitungBuruk(5,3) -> hasilGlobal = " << hasilGlobal << endl;
            hitungBuruk(7, 2);
            cout << "  hitungBuruk(7,2) -> hasilGlobal = " << hasilGlobal << endl;
            cout << "  Sulit ditest, sulit dilacak, bergantung state luar!" << endl;

            cout << "\n  Contoh BAIK -- pure function:" << endl;
            int r1 = hitungBaik(5, 3);
            int r2 = hitungBaik(7, 2);
            cout << "  hitungBaik(5,3) = " << r1 << endl;
            cout << "  hitungBaik(7,2) = " << r2 << endl;
            cout << "  Input sama -> output selalu sama. Mudah ditest!" << endl;

            cout << "\n  Ringkasan Best Practice:" << endl;
            cout << "  - Pakai local variable sebisa mungkin" << endl;
            cout << "  - Kirim data yang dibutuhkan lewat parameter" << endl;
            cout << "  - Kembalikan hasil lewat return atau reference" << endl;
            cout << "  - Global HANYA untuk: const dan constexpr" << endl;
        }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.10 -- Scope: Local vs Global Variable" << endl;
    cout << "============================================================" << endl;

    demoLocalVariable();
    demoGlobalVariable();
    demoShadowing();
    demoBestPractice();

    return 0;
}

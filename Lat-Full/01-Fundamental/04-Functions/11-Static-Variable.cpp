#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// DEMO 1 -- PERBEDAAN LOCAL vs STATIC LOCAL
    void fungsiLokalBiasa() {
        int counter = 0;   // SELALU direset ke 0 setiap dipanggil!
        counter++;
        cout << "  [local biasa]  counter = " << counter << endl;
    }

    void fungsiStaticLokal() {
        static int counter = 0;   // hanya diinisialisasi SEKALI!
        counter++;
        cout << "  [static local] counter = " << counter << endl;
    }


// DEMO 2 -- ID GENERATOR
    int generateID() {
        static int nextID = 1000;   // mulai dari 1000, tidak direset
        return nextID++;
    }

    string generateKodeProduk(string prefix) {
        static int nomor = 1;
        string kode = prefix + "-" + to_string(nomor++);
        return kode;
    }


// DEMO 3 -- COUNTER PEMANGGILAN

    void prosesData(int nilai) {
        static int totalDipanggil = 0;
        static int totalValid     = 0;
        static int totalInvalid   = 0;

        totalDipanggil++;

        if (nilai >= 0 && nilai <= 100) {
            totalValid++;
            cout << "  Nilai " << setw(3) << nilai << " -> valid    ";
        } else {
            totalInvalid++;
            cout << "  Nilai " << setw(3) << nilai << " -> INVALID  ";
        }

        cout << "(total dipanggil: " << totalDipanggil
            << ", valid: " << totalValid
            << ", invalid: " << totalInvalid << ")" << endl;
    }


// DEMO 4 -- MEMOIZATION / CACHE SEDERHANA
    /*
        Fibonacci rekursif naive: O(2^n) -- sangat lambat.
        Dengan static cache: setiap nilai hanya dihitung SEKALI,
        sisanya ambil dari cache.
    */

    long long fibMemo(int n) {
        static long long cache[60] = {};   // static array, inisialisasi ke 0 sekali
        static bool sudahDihitung[60] = {};

        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (sudahDihitung[n]) return cache[n];   // sudah ada di cache!

        cache[n]        = fibMemo(n-1) + fibMemo(n-2);
        sudahDihitung[n] = true;
        return cache[n];
    }


// DEMO 5 -- TOGGLE / ON-OFF STATE
    bool toggleStatus() {
        static bool aktif = false;   // mulai dari false
        aktif = !aktif;              // balik setiap kali dipanggil
        return aktif;
    }

    int getLevel() {
        static int level = 0;
        if (level < 5) level++;   // naik sampai max 5
        return level;
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.11 -- Static Local Variable" << endl;
    cout << "============================================================" << endl;

    cout << "\n  static: nilai BERTAHAN antar pemanggilan." << endl;
    cout << "  Scope tetap lokal, tapi lifetime seperti global." << endl;

    // ---- Local vs Static ----
        cout << "\n[ 1. Local Biasa vs Static Local ]" << endl;
        cout << "\n  Panggil masing-masing 5 kali:" << endl;
        for (int i = 1; i <= 5; i++) {
            fungsiLokalBiasa();
        }
        cout << endl;
        for (int i = 1; i <= 5; i++) {
            fungsiStaticLokal();
        }
        cout << "\n  local biasa  : selalu mulai dari 1 (direset tiap panggilan)" << endl;
        cout << "  static local : terus bertambah (nilai diingat)" << endl;

    // ---- ID Generator ----
        cout << "\n[ 2. ID Generator dengan Static ]" << endl;
        cout << "\n  generateID() -- ID unik otomatis:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  ID baru: " << generateID() << endl;
        }
        cout << "\n  generateKodeProduk() -- kode produk otomatis:" << endl;
        cout << "  " << generateKodeProduk("BRG") << endl;
        cout << "  " << generateKodeProduk("BRG") << endl;
        cout << "  " << generateKodeProduk("PRD") << endl;
        cout << "  " << generateKodeProduk("PRD") << endl;

    // ---- Counter Pemanggilan ----
        cout << "\n[ 3. Counter Pemanggilan dengan Static ]" << endl;
        cout << "\n  prosesData() dengan berbagai input:" << endl;
        int testData[] = {85, -5, 100, 150, 72, 0, 99, -1};
        for (int d : testData) {
            prosesData(d);
        }

    // ---- Memoization ----
        cout << "\n[ 4. Memoization Fibonacci dengan Static Cache ]" << endl;
        cout << "\n  fibMemo() -- tiap nilai hanya dihitung sekali:" << endl;
        cout << "  n  : ";
        for (int i = 0; i <= 15; i++) cout << setw(6) << i;
        cout << endl;
        cout << "  fib: ";
        for (int i = 0; i <= 15; i++) cout << setw(6) << fibMemo(i);
        cout << endl;

        cout << "\n  Nilai besar (cepat karena cache):" << endl;
        cout << "  fib(30) = " << fibMemo(30) << endl;
        cout << "  fib(45) = " << fibMemo(45) << endl;
        cout << "  fib(50) = " << fibMemo(50) << endl;

    // ---- Toggle & Level ----
        cout << "\n[ 5. Toggle dan Level dengan Static ]" << endl;

        cout << "\n  toggleStatus() -- on/off bergantian:" << endl;
        for (int i = 1; i <= 6; i++) {
            cout << "  Panggilan " << i << ": " << (toggleStatus() ? "ON" : "OFF") << endl;
        }

        cout << "\n  getLevel() -- naik sampai maksimum:" << endl;
        for (int i = 1; i <= 8; i++) {
            cout << "  Panggilan " << i << ": Level " << getLevel() << endl;
        }

        // ---- Perbandingan Tiga Jenis ----
        cout << "\n[ 6. Perbandingan Lengkap ]" << endl;
        cout << R"(
            +----------------+-------------------+-------------------+-------------------+
            | Aspek          | Local Biasa       | Static Local      | Global            |
            +----------------+-------------------+-------------------+-------------------+
            | Scope          | Dalam function    | Dalam function    | Seluruh file      |
            | Lifetime       | Saat fn dipanggil | Sepanjang program | Sepanjang program |
            | Nilai          | Direset tiap call | Bertahan          | Bertahan          |
            | Inisialisasi   | Tiap pemanggilan  | Hanya sekali      | Hanya sekali      |
            | Akses dari luar| Tidak bisa        | Tidak bisa        | Bisa (bahaya!)    |
            +----------------+-------------------+-------------------+-------------------+
            | Kapan pakai    | Data sementara    | Counter, cache,   | Konstanta saja    |
            |                | per pemanggilan   | ID generator      | (const/constexpr) |
            +----------------+-------------------+-------------------+-------------------+
        )";

    return 0;
}

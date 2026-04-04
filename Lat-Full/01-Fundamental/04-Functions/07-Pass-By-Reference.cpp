#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// BUKTI PASS BY REFERENCE -- ASLI IKUT BERUBAH
    void gandaNilai(int &x) {
        x = x * 2;   // mengubah x = mengubah variabel asli!
    }

    void isiNilai(int &target, int nilai) {
        target = nilai;   // mengisi variabel asli dari luar
    }

    void naikkanSeratus(double &angka) {
        angka += 100.0;
    }


// SWAP -- CONTOH KLASIK PASS BY REFERENCE
    // Swap yang BERHASIL dengan reference
    void swapInt(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
        // a dan b adalah referensi ke aslinya -- asli ikut bertukar
    }

    void swapDouble(double &a, double &b) {
        double temp = a;
        a = b;
        b = temp;
    }

    void swapString(string &a, string &b) {
        string temp = a;
        a = b;
        b = temp;
    }


// MODIFIKASI ARRAY -- ARRAY SELALU BY REFERENCE
    /*
        Array di C++ secara otomatis selalu dikirim by reference
        (sebenarnya dikirim sebagai pointer ke elemen pertama).
        Tidak perlu simbol & untuk array.
    */

    void naikkanSemua(int arr[], int ukuran, int kenaikan) {
        for (int i = 0; i < ukuran; i++) {
            arr[i] += kenaikan;   // langsung ubah array aslinya
        }
    }

    void urutkanBubble(int arr[], int ukuran) {
        for (int i = 0; i < ukuran - 1; i++) {
            for (int j = 0; j < ukuran - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swapInt(arr[j], arr[j + 1]);
                }
            }
        }
    }


// CONST REFERENCE -- CEPAT TAPI AMAN
    /*
        const tipe &nama:
            - Dikirim via reference (tidak ada overhead copy) -> cepat
            - Tapi TIDAK BISA diubah di dalam function -> aman

        Cocok untuk: string, struct, vector, array yang besar
        yang hanya perlu DIBACA, bukan diubah.
    */

    // Tanpa const reference -- string disalin seluruhnya (boros untuk string panjang)
        int hitungVokal_byValue(string kata) {
            int count = 0;
            for (char c : kata) {
                c = tolower(c);
                if (c=='a' || c=='i' || c=='u' || c=='e' || c=='o') count++;
            }
            return count;
        }

    // Dengan const reference -- tidak ada copy, tapi aman (tidak bisa diubah)
        int hitungVokal_byConstRef(const string &kata) {
            int count = 0;
            for (char c : kata) {
                char lower = tolower(c);
                if (lower=='a' || lower=='i' || lower=='u' || lower=='e' || lower=='o') count++;
            }
            return count;
            // kata = "ubah";  // <- COMPILE ERROR! const reference tidak bisa diubah
        }

        void tampilkanInfo(const string &nama, const string &kota, int usia) {
            cout << "  Nama : " << nama << endl;
            cout << "  Kota : " << kota << endl;
            cout << "  Usia : " << usia << " tahun" << endl;
            // nama = "ubah";  // <- COMPILE ERROR! const tidak bisa diubah
        }

        bool adaKata(const string &kalimat, const string &kata) {
            return kalimat.find(kata) != string::npos;
        }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.7 -- Pass by Reference & Const Reference" << endl;
    cout << "============================================================" << endl;

    cout << "\n  Pass by reference: function menerima ALAMAT variabel." << endl;
    cout << "  Perubahan di function LANGSUNG mengubah variabel asli." << endl;

    // ---- Bukti Asli Ikut Berubah ----
        cout << "\n[ 1. Bukti -- Variabel Asli IKUT BERUBAH ]" << endl;

        int n = 5;
        cout << "\n  n = " << n << endl;
        gandaNilai(n);
        cout << "  Setelah gandaNilai(n): n = " << n << " <- BERUBAH!" << endl;
        gandaNilai(n);
        cout << "  Setelah gandaNilai(n) lagi: n = " << n << endl;

        int target = 0;
        cout << "\n  target = " << target << endl;
        isiNilai(target, 99);
        cout << "  Setelah isiNilai(target, 99): target = " << target << " <- DIISI dari luar!" << endl;

        double saldo = 500000.0;
        cout << "\n  saldo = " << saldo << endl;
        naikkanSeratus(saldo);
        naikkanSeratus(saldo);
        naikkanSeratus(saldo);
        cout << "  Setelah naikkanSeratus 3x: saldo = " << saldo << endl;

    // ---- Swap Berhasil ----
        cout << "\n[ 2. Swap -- Contoh Klasik Pass by Reference ]" << endl;

        int a = 10, b = 20;
        cout << "\n  swapInt:" << endl;
        cout << "  Sebelum: a=" << a << ", b=" << b << endl;
        swapInt(a, b);
        cout << "  Sesudah: a=" << a << ", b=" << b << " <- BERHASIL DITUKAR!" << endl;

        double x = 3.14, y = 2.72;
        cout << "\n  swapDouble:" << endl;
        cout << fixed << setprecision(2);
        cout << "  Sebelum: x=" << x << ", y=" << y << endl;
        swapDouble(x, y);
        cout << "  Sesudah: x=" << x << ", y=" << y << endl;
        cout << defaultfloat;

        string s1 = "Mangga", s2 = "Apel";
        cout << "\n  swapString:" << endl;
        cout << "  Sebelum: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;
        swapString(s1, s2);
        cout << "  Sesudah: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;

    // ---- Array by Reference ----
        cout << "\n[ 3. Array -- Selalu By Reference Otomatis ]" << endl;

        int arr[] = {40, 10, 30, 50, 20};
        int ukuran = 5;
        cout << "\n  Array awal: ";
        for (int i = 0; i < ukuran; i++) cout << arr[i] << " ";
        cout << endl;

        naikkanSemua(arr, ukuran, 10);
        cout << "  Setelah naikkanSemua +10: ";
        for (int i = 0; i < ukuran; i++) cout << arr[i] << " ";
        cout << endl;

        urutkanBubble(arr, ukuran);
        cout << "  Setelah diurutkan: ";
        for (int i = 0; i < ukuran; i++) cout << arr[i] << " ";
        cout << endl;

    // ---- Const Reference ----
        cout << "\n[ 4. Const Reference -- Cepat tapi Aman ]" << endl;

        string kalimat = "Belajar pemrograman C++ sangat menyenangkan";
        cout << "\n  Kalimat: \"" << kalimat << "\"" << endl;
        cout << "  Jumlah vokal (byValue)   = " << hitungVokal_byValue(kalimat)    << endl;
        cout << "  Jumlah vokal (constRef)  = " << hitungVokal_byConstRef(kalimat) << endl;
        cout << "  Kalimat asli setelah itu: \"" << kalimat << "\" (tidak berubah)" << endl;

        cout << "\n  tampilkanInfo() dengan const string &:" << endl;
        tampilkanInfo("Gega Ramadhan", "Yogyakarta", 20);

        cout << "\n  adaKata():" << endl;
        cout << "  Ada 'menyenangkan'? " << (adaKata(kalimat, "menyenangkan") ? "ya" : "tidak") << endl;
        cout << "  Ada 'susah'?        " << (adaKata(kalimat, "susah")        ? "ya" : "tidak") << endl;

        // ---- Tabel Perbandingan ----
        cout << "\n[ 5. Perbandingan Lengkap ]" << endl;
        cout << R"(
            +--------------------+------------------+------------------+--------------------+
            | Aspek              | Pass by Value    | Pass by Ref      | Const Reference    |
            +--------------------+------------------+------------------+--------------------+
            | Yang dikirim       | Salinan nilai    | Alamat memori    | Alamat memori      |
            | Ubah variabel asli | Tidak            | Ya               | Tidak (dilindungi) |
            | Overhead copy      | Ada              | Tidak ada        | Tidak ada          |
            | Keamanan           | Aman             | Perlu hati-hati  | Aman               |
            | Simbol             | tipe nama        | tipe &nama       | const tipe &nama   |
            | Cocok untuk        | int,double,char  | swap, modifikasi | string,struct besar|
            +--------------------+------------------+------------------+--------------------+
        )";

        cout << "  Panduan memilih:" << endl;
        cout << "  - int, double, bool, char  -> pass by value" << endl;
        cout << "  - Perlu modifikasi asli    -> pass by reference (&)" << endl;
        cout << "  - Baca data besar, aman    -> const reference (const &)" << endl;

    return 0;
}

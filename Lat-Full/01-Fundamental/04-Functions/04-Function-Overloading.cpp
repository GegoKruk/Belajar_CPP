#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// OVERLOAD 1 -- BEDA TIPE DATA PARAMETER
    void cetak(int angka) {
        cout << "  [cetak int]    " << angka << endl;
    }

    void cetak(double angka) {
        cout << "  [cetak double] " << fixed << setprecision(4) << angka << endl;
        cout << defaultfloat;
    }

    void cetak(string teks) {
        cout << "  [cetak string] \"" << teks << "\"" << endl;
    }

    void cetak(bool kondisi) {
        cout << "  [cetak bool]   " << (kondisi ? "true" : "false") << endl;
    }

    void cetak(char karakter) {
        cout << "  [cetak char]   '" << karakter << "' (ASCII " << (int)karakter << ")" << endl;
    }


// OVERLOAD 2 -- BEDA JUMLAH PARAMETER
    int tambah(int a, int b) {
        cout << "  [tambah 2 param] " << a << " + " << b;
        return a + b;
    }

    int tambah(int a, int b, int c) {
        cout << "  [tambah 3 param] " << a << " + " << b << " + " << c;
        return a + b + c;
    }

    int tambah(int a, int b, int c, int d) {
        cout << "  [tambah 4 param] " << a << " + " << b << " + " << c << " + " << d;
        return a + b + c + d;
    }

    double luas(double sisi) {
        cout << "  [luas persegi]         sisi=" << sisi;
        return sisi * sisi;
    }

    double luas(double panjang, double lebar) {
        cout << "  [luas persegi panjang] p=" << panjang << " l=" << lebar;
        return panjang * lebar;
    }

    double luas(double alas, double tinggi, bool segitigaFlag) {
        cout << "  [luas segitiga]        a=" << alas << " t=" << tinggi;
        return 0.5 * alas * tinggi;
    }


// OVERLOAD 3 -- BEDA URUTAN TIPE
    void info(string nama, int angka) {
        cout << "  [string,int] nama=\"" << nama << "\", angka=" << angka << endl;
    }

    void info(int angka, string nama) {
        cout << "  [int,string] angka=" << angka << ", nama=\"" << nama << "\"" << endl;
    }


// OVERLOAD 4 -- LOGIKA BERBEDA PER TIPE (Kasus Nyata)

    // Hitung nilai maksimum -- logika sama, tipe berbeda
        int nilaiMaks(int a, int b) {
            return (a > b) ? a : b;
        }

        double nilaiMaks(double a, double b) {
            return (a > b) ? a : b;
        }

        int nilaiMaks(int a, int b, int c) {
            return nilaiMaks(nilaiMaks(a, b), c);   // overload saling memanggil!
        }

    // Konversi ke string -- logika berbeda per tipe
        string keString(int n) {
            return "int:" + to_string(n);
        }

        string keString(double d) {
            return "double:" + to_string(d).substr(0, 6);
        }

        string keString(bool b) {
            return "bool:" + string(b ? "true" : "false");
        }

    // Hitung panjang -- arti "panjang" berbeda per tipe
        int panjang(string teks) {
            return (int)teks.length();
        }

        int panjang(int n) {
            if (n == 0) return 1;
            int digit = 0;
            int temp  = (n < 0) ? -n : n;
            while (temp > 0) { temp /= 10; digit++; }
            return digit;
        }


// OVERLOADING vs DEFAULT PARAMETER -- Perbandingan
    // Pakai DEFAULT PARAMETER -- cocok, logika sama, hanya nilai berbeda
        void cetakGaris(int panjang = 40, char karakter = '-') {
            cout << "  ";
            for (int i = 0; i < panjang; i++) cout << karakter;
            cout << endl;
        }

    // Pakai OVERLOADING -- cocok, karena tipe berbeda menghasilkan output berbeda
        void tampilkan(int nilai) {
            cout << "  Menampilkan int    : " << nilai << " (desimal)" << endl;
        }

        void tampilkan(double nilai) {
            cout << "  Menampilkan double : " << fixed << setprecision(3) << nilai << endl;
            cout << defaultfloat;
        }

        void tampilkan(string teks) {
            cout << "  Menampilkan string : [" << teks << "] panjang=" << teks.length() << endl;
        }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.4 -- Function Overloading" << endl;
    cout << "============================================================" << endl;

    // ---- Beda Tipe Data ----
        cout << "\n[ 1. Overload -- Tipe Data Parameter Berbeda ]" << endl;
        cout << "  Compiler pilih versi yang sesuai tipe argumen:\n" << endl;
        cetak(42);
        cetak(3.14159);
        cetak("Halo dunia");
        cetak(true);
        cetak(false);
        cetak('Z');

    // ---- Beda Jumlah ----
        cout << "\n[ 2. Overload -- Jumlah Parameter Berbeda ]" << endl;

        cout << "\n  tambah() -- 2, 3, atau 4 angka:" << endl;
        int h1 = tambah(3, 4);        cout << " = " << h1 << endl;
        int h2 = tambah(3, 4, 5);     cout << " = " << h2 << endl;
        int h3 = tambah(3, 4, 5, 6);  cout << " = " << h3 << endl;

        cout << "\n  luas() -- 1, 2, atau 3 parameter:" << endl;
        cout << fixed << setprecision(2);
        double la = luas(5.0);           cout << " = " << la << endl;
        double lb = luas(8.0, 3.5);      cout << " = " << lb << endl;
        double lc = luas(6.0, 4.0, true); cout << " = " << lc << endl;
        cout << defaultfloat;

    // ---- Beda Urutan Tipe ----
        cout << "\n[ 3. Overload -- Urutan Tipe Berbeda ]" << endl;
        info("Gega", 20);
        info(42, "Budi");

    // ---- Logika Berbeda Per Tipe ----
        cout << "\n[ 4. Overload -- Logika Berbeda Per Tipe ]" << endl;

        cout << "\n  nilaiMaks() -- tipe dan jumlah berbeda:" << endl;
        cout << "  nilaiMaks(10, 25)       = " << nilaiMaks(10, 25)       << endl;
        cout << "  nilaiMaks(3.7, 3.2)     = " << nilaiMaks(3.7, 3.2)     << endl;
        cout << "  nilaiMaks(5, 12, 8)     = " << nilaiMaks(5, 12, 8)     << endl;

        cout << "\n  keString() -- konversi tipe berbeda ke string:" << endl;
        cout << "  keString(42)   = " << keString(42)   << endl;
        cout << "  keString(3.14) = " << keString(3.14) << endl;
        cout << "  keString(true) = " << keString(true) << endl;

        cout << "\n  panjang() -- arti 'panjang' berbeda per tipe:" << endl;
        cout << "  panjang(\"Halo\")  = " << panjang("Halo")    << " karakter" << endl;
        cout << "  panjang(12345)   = " << panjang(12345)   << " digit"     << endl;
        cout << "  panjang(9876543) = " << panjang(9876543) << " digit"     << endl;

    // ---- Overloading vs Default ----
        cout << "\n[ 5. Overloading vs Default Parameter ]" << endl;

        cout << "\n  cetakGaris() -- pakai DEFAULT (logika sama, beda nilai):" << endl;
        cetakGaris();
        cetakGaris(20);
        cetakGaris(30, '*');

        cout << "\n  tampilkan() -- pakai OVERLOAD (tipe berbeda, output berbeda):" << endl;
        tampilkan(42);
        tampilkan(3.14159);
        tampilkan("Belajar C++");

    // ---- Yang TIDAK Bisa ----
        cout << "\n[ 6. Yang TIDAK Bisa Membedakan Overload ]" << endl;
        cout << "\n  Return type SAJA tidak bisa membedakan overload:" << endl;
        cout << "  int    f(int x) { ... }" << endl;
        cout << "  double f(int x) { ... }   <- COMPILE ERROR! Ambiguous!" << endl;
        cout << "  Compiler bingung: f(5) mau yang mana?" << endl;

        cout << "\n  Nama parameter SAJA tidak bisa membedakan overload:" << endl;
        cout << "  void f(int a) { ... }" << endl;
        cout << "  void f(int b) { ... }   <- SAMA SAJA di mata compiler" << endl;
        cout << "  Compiler hanya lihat tipe, bukan nama parameter." << endl;

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Function Overloading" << endl;
        cout << "============================================================" << endl;
        cout << "  - Nama sama, parameter berbeda (tipe/jumlah/urutan)" << endl;
        cout << "  - Compiler pilih versi yang cocok otomatis" << endl;
        cout << "  - Return type SAJA tidak cukup untuk membedakan" << endl;
        cout << "  - Nama parameter SAJA tidak membedakan" << endl;
        cout << "  - Overload: tipe berbeda / logika berbeda" << endl;
        cout << "  - Default param: logika sama, hanya nilai default" << endl;

    return 0;
}

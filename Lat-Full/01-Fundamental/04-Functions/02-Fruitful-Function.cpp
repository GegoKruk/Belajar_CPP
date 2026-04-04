#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// RETURN TYPE: int
    int tambah(int a, int b) {
        return a + b;
    }

    int kurangi(int a, int b) {
        return a - b;
    }

    int kali(int a, int b) {
        return a * b;
    }

    int maks(int a, int b) {
        if (a > b) return a;
        return b;
    }

    int mins(int a, int b) {
        if (a < b) return a;
        return b;
    }

    int nilaiAbsolut(int x) {
        if (x >= 0){
            return x;
        }
        return -x;
    }

    int faktorial(int n) {
        if (n < 0)  return -1;   // error: faktorial negatif tidak ada
        if (n <= 1) return 1;
        int hasil = 1;
        for (int i = 2; i <= n; i++) hasil *= i;
        return hasil;
    }


// RETURN TYPE: double
    double bagi(double a, double b) {
        if (b == 0) return 0.0;   // jaga-jaga division by zero
        return a / b;
    }

    double luasPersegi(double sisi) {
        return sisi * sisi;
    }

    double luasPersegiPanjang(double p, double l) {
        return p * l;
    }

    double luasLingkaran(double r) {
        const double PI = 3.14159265358979;
        return PI * r * r;
    }

    double kelilingLingkaran(double r) {
        const double PI = 3.14159265358979;
        return 2 * PI * r;
    }

    double rataRata(int arr[], int n) {
        if (n <= 0) return 0.0;
        int total = 0;
        for (int i = 0; i < n; i++) total += arr[i];
        return (double)total / n;
    }

    double celsiusKeFahrenheit(double c) {
        return (c * 9.0 / 5.0) + 32;
    }

    double fahrenheitKeCelsius(double f) {
        return (f - 32) * 5.0 / 9.0;
    }


// RETURN TYPE: bool
    bool isPositif(int n) {
        return n > 0;
    }

    bool isGenap(int n) {
        return n % 2 == 0;
    }

    bool isPrimitive(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool isNilaiValid(int nilai) {
        return nilai >= 0 && nilai <= 100;
    }

    bool isPasswordKuat(string password) {
        if (password.length() < 8)  return false;
        bool adaAngka  = false;
        bool adaHuruf  = false;
        for (char c : password) {
            if (isdigit(c))  adaAngka = true;
            if (isalpha(c))  adaHuruf = true;
        }
        return adaAngka && adaHuruf;
    }


// RETURN TYPE: string
    string getGrade(int nilai) {
        if      (nilai >= 85) return "A";
        else if (nilai >= 75) return "B";
        else if (nilai >= 65) return "C";
        else if (nilai >= 55) return "D";
        else                  return "E";
    }

    string getKategoriUsia(int usia) {
        if      (usia < 0)   return "Tidak valid";
        else if (usia < 13)  return "Anak-anak";
        else if (usia < 18)  return "Remaja";
        else if (usia < 60)  return "Dewasa";
        else                 return "Lansia";
    }

    string getNamaHari(int hari) {
        switch (hari) {
            case 1: return "Senin";
            case 2: return "Selasa";
            case 3: return "Rabu";
            case 4: return "Kamis";
            case 5: return "Jumat";
            case 6: return "Sabtu";
            case 7: return "Minggu";
            default: return "Tidak valid";
        }
    }

    string desimalKeBiner(int n) {
        if (n == 0) {
            return "0";
        }
        
        string hasil = "";
        int temp = n;
        while (temp > 0) {
            hasil = char('0' + temp % 2) + hasil;
            temp /= 2;
        }

        return hasil;
    }


// RETURN TYPE: char
    char getGradeChar(int nilai) {
        if (nilai >= 85){
            return 'A';
        } else if (nilai >= 75){
            return 'B';
        } else if (nilai >= 65){
            return 'C';
        } else if (nilai >= 55){
            return 'D';
        } else {
            return 'E';
        }
    }

    char keHurufBesar(char c) {
        if (c >= 'a' && c <= 'z') return c - 32;
        return c;
    }

    char keHurufKecil(char c) {
        if (c >= 'A' && c <= 'Z') return c + 32;
        return c;
    }


// FUNCTION MEMANGGIL FUNCTION LAIN

    // Harga akhir setelah diskon dan pajak
    double hitungHargaAkhir(double harga, double diskonPersen, double pajakPersen) {
        double setelahDiskon = harga - (harga * diskonPersen / 100.0);
        double setelahPajak  = setelahDiskon + (setelahDiskon * pajakPersen / 100.0);
        return setelahPajak;
    }

    // Hypotenusa memanggil luasPersegi dan sqrt
    double hypotenusa(double a, double b) {
        return sqrt(luasPersegi(a) + luasPersegi(b));
        //           ^ function lain      ^ function lain
    }

    // Nilai max dari tiga angka -- memanggil maks() dua kali
    int maks3(int a, int b, int c) {
        return maks(maks(a, b), c);   // nested call ke function sendiri
    }

    // Konversi suhu lengkap -- memanggil dua function konversi
    void tampilkanSemuaSuhu(double celsius) {
        double fahrenheit = celsiusKeFahrenheit(celsius);
        double kelvin     = celsius + 273.15;
        cout << "  " << celsius << " C = " << fahrenheit << " F = " << kelvin << " K" << endl;
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.2 -- Fruitful Function (Function Bernilai)" << endl;
    cout << "============================================================" << endl;

    // ---- Return int ----
        cout << "\n[ 1. Return Type: int ]" << endl;
        cout << "  tambah(10, 5)       = " << tambah(10, 5)       << endl;
        cout << "  kurangi(10, 5)      = " << kurangi(10, 5)      << endl;
        cout << "  kali(10, 5)         = " << kali(10, 5)         << endl;
        cout << "  maks(17, 42)        = " << maks(17, 42)        << endl;
        cout << "  mins(17, 42)        = " << mins(17, 42)        << endl;
        cout << "  nilaiAbsolut(-15)   = " << nilaiAbsolut(-15)   << endl;
        cout << "  nilaiAbsolut(8)     = " << nilaiAbsolut(8)     << endl;
        cout << "\n  Faktorial:" << endl;
        for (int i = 0; i <= 8; i++) {
            cout << "  faktorial(" << i << ")       = " << faktorial(i) << endl;
        }

    // ---- Return double ----
        cout << "\n[ 2. Return Type: double ]" << endl;
        cout << fixed << setprecision(2);
        cout << "  bagi(10, 3)             = " << bagi(10, 3)            << endl;
        cout << "  luasPersegi(5)          = " << luasPersegi(5)         << endl;
        cout << "  luasPersegiPanjang(8,3) = " << luasPersegiPanjang(8, 3) << endl;
        cout << "  luasLingkaran(7)        = " << luasLingkaran(7)       << endl;
        cout << "  kelilingLingkaran(7)    = " << kelilingLingkaran(7)   << endl;
        cout << "\n  Konversi Suhu:" << endl;

        double suhu[] = {0, 37, 100};
        for (double s : suhu) {
            cout << "  " << s << " C = " << celsiusKeFahrenheit(s) << " F" << endl;
        }

        int  data[] = {70, 85, 60, 90, 75};
        cout << "\n  Rata-rata nilai: " << rataRata(data, 5) << endl;
        cout << defaultfloat;

    // ---- Return bool ----
        cout << "\n[ 3. Return Type: bool ]" << endl;

        int angkaCek[] = {-5, 0, 3, 7, 12, 17};
        for (int a : angkaCek) {
            cout << "  " << setw(3) << a
                << "  positif:" << (isPositif(a) ? "ya " : "tdk")
                << "  genap:"   << (isGenap(a)   ? "ya " : "tdk")
                << "  prima:"   << (isPrimitive(a) ? "ya" : "tdk")
                << endl;
        }

        cout << "\n  isNilaiValid(85)  = " << (isNilaiValid(85)  ? "valid"   : "tidak valid") << endl;
        cout << "  isNilaiValid(105) = " << (isNilaiValid(105) ? "valid"   : "tidak valid") << endl;
        cout << "\n  isPasswordKuat(\"abc\")    = " << (isPasswordKuat("abc")    ? "kuat" : "lemah") << endl;
        cout << "  isPasswordKuat(\"abc12345\") = " << (isPasswordKuat("abc12345") ? "kuat" : "lemah") << endl;

    // ---- Return string ----
        cout << "\n[ 4. Return Type: string ]" << endl;
        int nilaiUji[] = {92, 80, 70, 60, 40};
        for (int n : nilaiUji) {
            cout << "  Nilai " << setw(3) << n
                << "  grade: " << getGrade(n)
                << "  biner: " << desimalKeBiner(n) << endl;
        }
        cout << "\n  Kategori usia:" << endl;
        int usiaCek[] = {5, 15, 25, 65};
        for (int u : usiaCek) {
            cout << "  Usia " << setw(3) << u << " -> " << getKategoriUsia(u) << endl;
        }
        cout << "\n  Nama hari:" << endl;
        for (int h = 1; h <= 7; h++) {
        cout << "  Hari " << h << " = " << getNamaHari(h) << endl;
    }

    // ---- Return char ----
        cout << "\n[ 5. Return Type: char ]" << endl;
        char huruf[] = {'a', 'B', 'c', 'D', 'z'};
        for (char c : huruf) {
            cout << "  '" << c << "' -> besar: '" << keHurufBesar(c) << "'  kecil: '" << keHurufKecil(c) << "'" << endl;
        }

    // ---- Function memanggil function ----
        cout << "\n[ 6. Function Memanggil Function Lain ]" << endl;
        cout << fixed << setprecision(2);
        cout << "  hypotenusa(3, 4)    = " << hypotenusa(3, 4) << "  (pakai luasPersegi)" << endl;
        cout << "  maks3(5, 12, 8)     = " << maks3(5, 12, 8)  << "  (pakai maks dua kali)" << endl;
        cout << "\n  Harga akhir (harga=500000, diskon=20%, pajak=11%):" << endl;
        cout << "  = Rp " << hitungHargaAkhir(500000, 20, 11) << endl;
        cout << "\n  Konversi suhu lengkap:" << endl;
            tampilkanSemuaSuhu(0);
            tampilkanSemuaSuhu(37);
            tampilkanSemuaSuhu(100);
        cout << defaultfloat;

    // ---- Cara memakai return ----
        cout << "\n[ 7. Berbagai Cara Memakai Return Value ]" << endl;
        
        // Cara 1: tampung di variabel
            int x = tambah(5, 3);
            cout << "  Cara 1 (tampung): int x = tambah(5,3);  x = " << x << endl;

        // Cara 2: langsung dipakai
            cout << "  Cara 2 (langsung): cout << tambah(5,3)  = " << tambah(5, 3) << endl;

        // Cara 3: dipakai dalam ekspresi
            int total = tambah(5, 3) * 2 + 1;
            cout << "  Cara 3 (ekspresi): tambah(5,3)*2+1      = " << total << endl;

        // Cara 4: nested call
            cout << "  Cara 4 (nested): tambah(tambah(1,2),3)  = " << tambah(tambah(1,2),3) << endl;

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Fruitful Function" << endl;
        cout << "============================================================" << endl;
        cout << "  - Return type  : int, double, bool, string, char, dll" << endl;
        cout << "  - Wajib ada    : statement return yang cocok dengan tipenya" << endl;
        cout << "  - Semua jalur  : if-else harus punya return di tiap cabang" << endl;
        cout << "  - Cara pakai   : tampung, langsung, ekspresi, nested call" << endl;
        cout << "  - Cocok untuk  : kalkulasi, konversi, validasi, cari nilai" << endl;

    return 0;
}

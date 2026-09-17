
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// CONTOH INLINE FUNCTION

    // Operasi matematika sederhana -- cocok untuk inline
    inline int kuadrat(int x) {
        return x * x;              // 1 baris -- sangat cocok inline
    }

    inline int kubik(int x) {
        return x * x * x;         // 1 baris -- cocok inline
    }

    inline double luasPersegi(double sisi) {
        return sisi * sisi;        // 1 baris
    }

    inline double luasLingkaran(double r) {
        const double PI = 3.14159265358979;
        return PI * r * r;         // 1 baris body
    }

    inline int nilaiMaks(int a, int b) {
        return (a > b) ? a : b;   // 1 baris
    }

    inline int nilaiMins(int a, int b) {
        return (a < b) ? a : b;   // 1 baris
    }

    inline bool isGenap(int n) {
        return (n % 2 == 0);      // 1 baris
    }

    inline bool isPositif(int n) {
        return n > 0;              // 1 baris
    }

    inline double celsiusKeFahrenheit(double c) {
        return (c * 9.0 / 5.0) + 32;
    }

    // Getter sederhana -- pola yang sering pakai inline (nanti di OOP)
    inline int getUsia(int tahunLahir, int tahunSekarang) {
        return tahunSekarang - tahunLahir;
    }


// BANDINGKAN: Inline vs Function Biasa (kode sama, hasil sama)

    // Versi biasa (tanpa inline)
    int kuadratBiasa(int x) {
        return x * x;
    }

    // Versi inline
    inline int kuadratInline(int x) {
        return x * x;
    }

    /*
        Dari sisi programmer: kode persis sama, cara pakai sama.
        Perbedaan hanya di bagaimana compiler menghasilkan kode mesin.
        Hasil akhir (output program): SAMA PERSIS.
    */


// CONTOH YANG TIDAK COCOK UNTUK INLINE

    // Function panjang -- tidak cocok inline (code bloat)
    // (tidak diberi keyword inline)
    double hitungIPK(int nilaiMatkul[], int sks[], int jumlahMatkul) {
        double totalBobot = 0;
        int    totalSKS   = 0;

        for (int i = 0; i < jumlahMatkul; i++) {
            double bobot;
            if      (nilaiMatkul[i] >= 85) bobot = 4.0;
            else if (nilaiMatkul[i] >= 75) bobot = 3.0;
            else if (nilaiMatkul[i] >= 65) bobot = 2.0;
            else if (nilaiMatkul[i] >= 55) bobot = 1.0;
            else                           bobot = 0.0;

            totalBobot += bobot * sks[i];
            totalSKS   += sks[i];
        }

        return (totalSKS > 0) ? totalBobot / totalSKS : 0.0;
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.5 -- Inline Function" << endl;
    cout << "============================================================" << endl;

    cout << "\n  Konsep inline: kode function dicopy ke tempat pemanggil" << endl;
    cout << "  saat kompilasi, menghilangkan overhead pemanggilan." << endl;

    // ---- Demo inline math ----
        cout << "\n[ 1. Inline Function Matematika ]" << endl;

        cout << "\n  kuadrat(n) untuk n = 1..8:" << endl;
        cout << "  n : ";
        for (int i = 1; i <= 8; i++) cout << setw(5) << i;
        cout << endl;
        cout << "  n2: ";
        for (int i = 1; i <= 8; i++) cout << setw(5) << kuadrat(i);
        cout << endl;
        cout << "  n3: ";
        for (int i = 1; i <= 8; i++) cout << setw(5) << kubik(i);
        cout << endl;

        cout << fixed << setprecision(2);
        cout << "\n  luasPersegi(sisi):" << endl;
        for (double s = 1.0; s <= 5.0; s += 1.0) {
            cout << "  sisi=" << s << " -> luas=" << luasPersegi(s) << endl;
        }

        cout << "\n  luasLingkaran(r):" << endl;
        for (double r = 1.0; r <= 4.0; r += 0.5) {
            cout << "  r=" << r << " -> luas=" << luasLingkaran(r) << endl;
        }
        cout << defaultfloat;

    // ---- Demo inline logika ----
        cout << "\n[ 2. Inline Function Logika ]" << endl;

        int angka[] = {-3, 0, 4, 7, 10, 15};
        cout << "\n  n    genap   positif  maks(n,8)  mins(n,8)" << endl;
        cout << "  ---  ------  -------  ---------  ---------" << endl;
        for (int n : angka) {
            cout << "  " << setw(3) << n
                << "  " << setw(6) << (isGenap(n)   ? "ya"  : "tidak")
                << "  " << setw(7) << (isPositif(n) ? "ya"  : "tidak")
                << "  " << setw(9) << nilaiMaks(n, 8)
                << "  " << setw(9) << nilaiMins(n, 8)
                << endl;
        }

    // ---- Demo inline konversi ----
        cout << "\n[ 3. Inline Konversi Suhu ]" << endl;
        double suhu[] = {0, 20, 37, 100};
        cout << "\n  Celsius -> Fahrenheit:" << endl;
        cout << fixed << setprecision(2);
        for (double c : suhu) {
            cout << "  " << c << " C = " << celsiusKeFahrenheit(c) << " F" << endl;
        }
        cout << defaultfloat;

    // ---- Demo inline vs biasa ----
        cout << "\n[ 4. Inline vs Biasa -- Hasil Sama, Cara Kerja Berbeda ]" << endl;
        cout << "\n  kuadratBiasa(7)  = " << kuadratBiasa(7)  << endl;
        cout << "  kuadratInline(7) = " << kuadratInline(7) << endl;
        cout << "  Hasil identik! Perbedaan hanya di level kode mesin." << endl;

    // ---- Demo inline di dalam loop (kasus penggunaan ideal) ----
        cout << "\n[ 5. Inline Ideal di Hot Path (Loop Banyak Iterasi) ]" << endl;
        cout << "\n  Menghitung jumlah bilangan ganjil dari 1-999999 (inline isGenap):" << endl;
        int jumlahGanjil = 0;
        for (int i = 1; i <= 999999; i++) {
            if (!isGenap(i)) jumlahGanjil++;   // isGenap di-inline, tidak ada overhead
        }
        cout << "  Jumlah bilangan ganjil 1-999999 = " << jumlahGanjil << endl;
        cout << "  (inline menghilangkan overhead 999999 pemanggilan function)" << endl;

    // ---- Function panjang tidak cocok inline ----
        cout << "\n[ 6. Function Panjang -- Tidak Cocok Inline ]" << endl;
        int nilai[] = {90, 80, 70, 55, 40};
        int sks[]   = {3, 4, 3, 2, 2};
        cout << fixed << setprecision(2);
        cout << "\n  IPK dengan 5 matakuliah: " << hitungIPK(nilai, sks, 5) << endl;
        cout << "  (hitungIPK tidak diberi inline -- terlalu panjang)" << endl;
        cout << defaultfloat;

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Inline Function" << endl;
        cout << "============================================================" << endl;
        cout << "  - Kode dicopy ke pemanggil, menghilangkan overhead jump" << endl;
        cout << "  - Cocok  : function 1-3 baris, dipanggil sangat sering" << endl;
        cout << "  - Hindari: function panjang, recursive, banyak percabangan" << endl;
        cout << "  - 'inline' adalah REQUEST, compiler boleh abaikan" << endl;
        cout << "  - Compiler modern sudah auto-inline tanpa kita minta" << endl;
        cout << "  - Hasil output program: SAMA dengan function biasa" << endl;

    return 0;
}

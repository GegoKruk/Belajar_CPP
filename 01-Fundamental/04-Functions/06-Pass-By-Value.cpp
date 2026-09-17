
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// BUKTI PASS BY VALUE -- ASLI TIDAK BERUBAH

    void cobaUbah(int x) {
        cout << "  Di dalam cobaUbah: x awal = " << x << endl;
        x = x * 100;   // ubah salinan, bukan aslinya
        x += 999;
        cout << "  Di dalam cobaUbah: x akhir = " << x << " (salinan diubah)" << endl;
    }

    void tambahSepuluh(int angka) {
        angka += 10;   // hanya salinan yang berubah
    }

    void swapGagal(int a, int b) {
        cout << "  Di dalam swapGagal: sebelum = a:" << a << " b:" << b << endl;
        int temp = a;
        a = b;
        b = temp;
        cout << "  Di dalam swapGagal: sesudah  = a:" << a << " b:" << b << " (hanya salinan)" << endl;
    }


// PASS BY VALUE YANG COCOK -- KALKULASI MURNI

    double hitungLuas(double panjang, double lebar) {
        return panjang * lebar;   // hanya hitung, tidak ubah p atau l
    }

    double hitungVolume(double p, double l, double t) {
        return p * l * t;
    }

    int pangkat(int base, int exp) {
        int hasil = 1;
        for (int i = 0; i < exp; i++) hasil *= base;
        return hasil;
    }

    double hitungDiskon(double harga, double persen) {
        double potongan = harga * (persen / 100.0);
        return harga - potongan;   // harga asli tidak berubah
    }

    int hitungSisaBagi(int angka, int pembagi) {
        return angka % pembagi;
    }

    bool isKabisat(int tahun) {
        return (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
    }

    double konversiSuhu(double celsius) {
        return (celsius * 9.0 / 5.0) + 32;
    }


// PASS BY VALUE STRING -- SALIN LEBIH BERAT
    /*
        Untuk tipe kecil (int, double, char, bool): pass by value efisien.
        Untuk string dan struct: pass by value menyalin SELURUH isinya,
        bisa berat untuk string panjang.

        Solusi untuk string/struct besar: pakai const reference (file 07).
        Tapi untuk belajar konsep dasar, ini dulu yang penting dipahami.
    */

    int hitungPanjangKata(string kata) {
        return (int)kata.length();   // kata disalin, tapi tidak ada perubahan
    }

    string balikKata(string kata) {
        string hasil = "";
        for (int i = (int)kata.length() - 1; i >= 0; i--) {
            hasil += kata[i];
        }
        return hasil;   // kata asli tidak berubah
    }

    bool isPalindrom(string kata) {
        string balik = balikKata(kata);
        return kata == balik;
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.6 -- Pass by Value" << endl;
    cout << "============================================================" << endl;

    cout << "\n  Pass by value: function menerima SALINAN nilai." << endl;
    cout << "  Variabel asli di pemanggil TIDAK BERUBAH." << endl;

    // ---- Bukti Asli Tidak Berubah ----
        cout << "\n[ 1. Bukti -- Variabel Asli Tidak Berubah ]" << endl;

        cout << "\n  cobaUbah():" << endl;
        int angka = 5;
        cout << "  Sebelum dipanggil  : angka = " << angka << endl;
        cobaUbah(angka);
        cout << "  Setelah dipanggil  : angka = " << angka << " <- TIDAK BERUBAH!" << endl;

        cout << "\n  tambahSepuluh():" << endl;
        int saldo = 1000;
        cout << "  Sebelum: saldo = " << saldo << endl;
        tambahSepuluh(saldo);
        cout << "  Sesudah: saldo = " << saldo << " <- tetap 1000, bukan 1010!" << endl;

        cout << "\n  swapGagal() -- swap dengan pass by value TIDAK BERHASIL:" << endl;
        int x = 10, y = 20;
        cout << "  Sebelum: x=" << x << ", y=" << y << endl;
        swapGagal(x, y);
        cout << "  Sesudah: x=" << x << ", y=" << y << " <- TIDAK TERTUKAR!" << endl;
        cout << "  (untuk swap yang berhasil, pakai pass by reference -- file 07)" << endl;

    // ---- Kapan Pass by Value Tepat ----
        cout << "\n[ 2. Kapan Pass by Value Tepat -- Kalkulasi Murni ]" << endl;

        double p = 8.5, l = 4.0, t = 3.0;
        cout << "\n  p=" << p << ", l=" << l << ", t=" << t << endl;
        cout << "  hitungLuas(p, l)      = " << hitungLuas(p, l)       << endl;
        cout << "  hitungVolume(p, l, t) = " << hitungVolume(p, l, t)  << endl;
        cout << "  p, l, t setelah fungsi: " << p << ", " << l << ", " << t << " (tidak berubah)" << endl;

        cout << "\n  pangkat(2, n):" << endl;
        for (int i = 0; i <= 10; i++) {
            cout << "  2^" << setw(2) << i << " = " << pangkat(2, i) << endl;
        }

        cout << "\n  Hitung diskon:" << endl;
        double hargaAsli = 500000.0;
        cout << fixed << setprecision(0);
        cout << "  Harga asli    : Rp " << hargaAsli << endl;
        cout << "  Diskon 10%    : Rp " << hitungDiskon(hargaAsli, 10) << endl;
        cout << "  Diskon 25%    : Rp " << hitungDiskon(hargaAsli, 25) << endl;
        cout << "  Diskon 50%    : Rp " << hitungDiskon(hargaAsli, 50) << endl;
        cout << "  Harga asli setelah semua pemanggilan: Rp " << hargaAsli << " (tidak berubah)" << endl;
        cout << defaultfloat;

        cout << "\n  Cek tahun kabisat:" << endl;
        int tahun[] = {1900, 2000, 2024, 2025, 2100};
        for (int th : tahun) {
            cout << "  " << th << " -> " << (isKabisat(th) ? "kabisat" : "bukan kabisat") << endl;
        }

        cout << "\n  Konversi suhu:" << endl;
        double suhuc[] = {0, 20, 37, 100};
        cout << fixed << setprecision(2);
        for (double c : suhuc) {
            cout << "  " << c << " C = " << konversiSuhu(c) << " F" << endl;
        }
        cout << defaultfloat;

    // ---- Pass by Value String ----
        cout << "\n[ 3. Pass by Value dengan String ]" << endl;

        string kata = "malam";
        cout << "\n  kata = \"" << kata << "\"" << endl;
        cout << "  hitungPanjangKata  = " << hitungPanjangKata(kata) << endl;
        cout << "  balikKata          = " << balikKata(kata) << endl;
        cout << "  isPalindrom        = " << (isPalindrom(kata) ? "ya" : "tidak") << endl;
        cout << "  kata setelah semua dipanggil: \"" << kata << "\" (tidak berubah)" << endl;

        string kata2 = "kasur rusak";
        cout << "\n  kata2 = \"" << kata2 << "\"" << endl;
        cout << "  isPalindrom = " << (isPalindrom(kata2) ? "ya" : "tidak") << endl;

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Pass by Value" << endl;
        cout << "============================================================" << endl;
        cout << "  - Yang dikirim     : SALINAN nilai variabel" << endl;
        cout << "  - Variabel asli    : TIDAK BERUBAH" << endl;
        cout << "  - Sintaks          : tipe nama  (tidak ada simbol khusus)" << endl;
        cout << "  - Cocok untuk      : int, double, char, bool" << endl;
        cout << "  - Cocok untuk      : kalkulasi murni, konversi, validasi" << endl;
        cout << "  - Kurang cocok     : string/struct panjang (overhead copy)" << endl;
        cout << "  - Solusi string    : const reference (lihat file 07)" << endl;

    return 0;
}

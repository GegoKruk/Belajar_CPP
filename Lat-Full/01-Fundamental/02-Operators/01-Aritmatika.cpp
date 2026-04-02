#include <iostream>
#include <iomanip>   // fixed, setprecision
#include <cmath>     // pow(), sqrt(), fmod()
using namespace std;


void operatorAritmatika() {
    cout << "========== I. Operator Aritmatika ==========" << endl;

    int a = 10;
    int b = 3;
    cout << "\nVariabel: a = " << a << ", b = " << b << endl;

    // ----- 1. Lima Operator Dasar -----
        cout << "\n1. Lima Operator Dasar" << endl;
        cout << "   a + b  = " << a + b << "   (penjumlahan)" << endl;
        cout << "   a - b  = " << a - b << "   (pengurangan)" << endl;
        cout << "   a * b  = " << a * b << "  (perkalian)" << endl;
        cout << "   a / b  = " << a / b << "   (pembagian integer!)" << endl;
        cout << "   a % b  = " << a % b << "   (sisa bagi / modulus)" << endl;

    // ----- 2. Integer Division Trap -----
        cout << "\n2. Integer Division Trap" << endl;

        int x = 7, y = 2;
        double hasilSalah = x / y;                          // 3.0, bukan 3.5!
        double hasilBenar = static_cast<double>(x) / y;     // 3.5 ✅

        cout << "   x=" << x << ", y=" << y << endl;
        cout << "   x / y (int/int)                  = " << hasilSalah << "  <- SALAH!" << endl;
        cout << "   static_cast<double>(x) / y       = " << hasilBenar << "  <- BENAR" << endl;
        cout << "   (double)x / y  (C-style, hindari)= " << (double)x / y << "  <- benar tapi kurang aman" << endl;

    // ----- 3. Modulus - Sisa Bagi -----
        cout << "\n3. Modulus (%) - Sisa Pembagian" << endl;

        cout << "   17 % 5  = " << 17 % 5 << "  (17 = 5 x 3 + 2, sisa 2)" << endl;
        cout << "   10 % 2  = " << 10 % 2 << "  (habis dibagi, sisa 0)" << endl;
        cout << "   9  % 4  = " << 9  % 4 << "  (9  = 4 x 2 + 1, sisa 1)" << endl;

        // Kegunaan modulus
        cout << "\n   Kegunaan Modulus:" << endl;
        cout << "   Cek genap/ganjil: 7 % 2 = " << 7 % 2 << " -> " << (7 % 2 == 0 ? "genap" : "ganjil") << endl;
        cout << "   Wrap angka (jam): (25 % 12) = " << 25 % 12 << " -> jam " << 25 % 12 << " (bukan jam 25)" << endl;
        cout << "   Digit terakhir  : 12345 % 10 = " << 12345 % 10 << endl;

        // fmod untuk float
        cout << "\n   fmod() untuk float/double:" << endl;
        cout << "   fmod(7.5, 2.5) = " << fmod(7.5, 2.5) << "  (7.5 % 2.5 biasa ERROR)" << endl;
        cout << "   fmod(10.3, 3)  = " << fixed << setprecision(4) << fmod(10.3, 3.0) << endl;
        cout << defaultfloat;

    // ----- 4. Operator dari <cmath> -----
        cout << "\n4. Operator Matematika dari <cmath>" << endl;

        double angka = 16.0;
        cout << "   pow(2, 10)   = " << pow(2, 10)       << "  (2^10 = 1024)" << endl;
        cout << "   sqrt(16)     = " << sqrt(angka)       << "  (akar 16 = 4)" << endl;
        cout << "   abs(-7)      = " << abs(-7)           << "  (nilai absolut)" << endl;
        cout << "   fabs(-3.14)  = " << fabs(-3.14)       << "  (absolut float)" << endl;
        cout << "   ceil(4.1)    = " << ceil(4.1)         << "  (bulatkan ke atas)" << endl;
        cout << "   floor(4.9)   = " << floor(4.9)        << "  (bulatkan ke bawah)" << endl;
        cout << "   round(4.5)   = " << round(4.5)        << "  (bulatkan terdekat)" << endl;
        cout << "   round(4.4)   = " << round(4.4)        << "  (bulatkan terdekat)" << endl;

    // ----- 5. Operator pada Tipe Campuran -----
        cout << "\n5. Operator pada Tipe Campuran (Type Promotion)" << endl;

        int    bil_int    = 7;
        double bil_double = 2.5;
        // int + double -> double (int dipromote otomatis)
        double hasil = bil_int + bil_double;
        cout << "   int " << bil_int << " + double " << bil_double << " = " << hasil << " (double)" << endl;

    // ----- 6. Contoh Praktis -----
        cout << "\n6. Contoh Praktis" << endl;

        // a. Hitung luas persegi panjang
        cout << "\n   a. Luas Persegi Panjang" << endl;
        double panjang = 12.5, lebar = 7.3;
        double luas = panjang * lebar;
        cout << "      P=" << panjang << ", L=" << lebar << " -> Luas = " << fixed << setprecision(2) << luas << endl;
        cout << defaultfloat;

        // b. Hitung diskon
        cout << "\n   b. Hitung Harga Setelah Diskon 20%" << endl;
        double harga   = 250000.0;
        double diskon  = 0.20;
        double bayar   = harga - (harga * diskon);
        cout << "      Harga asli  : Rp " << fixed << setprecision(0) << harga << endl;
        cout << "      Diskon 20%  : Rp " << harga * diskon << endl;
        cout << "      Harga bayar : Rp " << bayar << endl;
        cout << defaultfloat;

        // c. Konversi menit ke jam & sisa menit
        cout << "\n   c. Konversi Menit ke Jam + Sisa Menit" << endl;
        int totalMenit = 145;
        int jam        = totalMenit / 60;   // pembagian integer
        int sisaMenit  = totalMenit % 60;   // sisa bagi
        cout << "      " << totalMenit << " menit = " << jam << " jam " << sisaMenit << " menit" << endl;
}


int main(){

    operatorAritmatika();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

void variabel() {
    cout << "========== E. Variabel ==========" << endl;

    // ----- 1. Deklarasi & Inisialisasi -----
    cout << "\n1. Deklarasi dan Inisialisasi" << endl;

    string namaLengkap = "Gega Ramadhan"; // deklarasi + inisialisasi
    int    umur        = 18;
    double ipk         = 3.87;

    cout << "   Nama   : " << namaLengkap << endl;
    cout << "   Umur   : " << umur        << endl;
    cout << "   IPK    : " << ipk         << endl;

    // ----- 2. Variabel bisa diubah nilainya -----
    cout << "\n2. Mengubah Nilai Variabel" << endl;

    int saldo = 500000;
    cout << "   Saldo awal   : Rp " << saldo << endl;

    saldo = saldo - 150000; // tarik tunai
    cout << "   Setelah tarik: Rp " << saldo << endl;

    saldo += 200000;        // terima transfer (operator +=)
    cout << "   Setelah terima: Rp " << saldo << endl;

    // ----- 3. Multiple deklarasi satu baris -----
    cout << "\n3. Multiple Deklarasi" << endl;

    int panjang = 10, lebar = 5, tinggi = 3;
    cout << "   Panjang = " << panjang << endl;
    cout << "   Lebar = " << lebar << endl;
    cout << "   Tinggi = " << tinggi << endl;
    cout << "   Volume = " << panjang * lebar * tinggi << endl;

    // ----- 4. Uniform Initialization C++11 -----
    cout << "\n4. Uniform Initialization (C++11) — Cara Modern" << endl;

    int    nilai{90};
    double gaji{5500000.75};
    bool   aktif{true};

    cout << "   Nilai  : " << nilai << endl;
    cout << "   Gaji   : Rp " << gaji << endl;
    cout << "   Aktif  : " << (aktif ? "Ya" : "Tidak") << endl;

    // int salah{3.14};  // ❌ ERROR — narrowing! double -> int dicegah
    // ini keunggulan uniform init dibanding = biasa

    // ----- 5. Aturan & Konvensi Penamaan -----
    cout << "\n5. Aturan Penamaan Variabel:" << endl;
    cout << "   namaLengkap, _nilai, data123  -> VALID" << endl;
    cout << "   1nama, nama saya, int, @nilai -> TIDAK VALID" << endl;
    cout << "\n   Konvensi (saran terbaik):" << endl;
    cout << "   camelCase   -> variabel/fungsi   : jumlahSiswa" << endl;
    cout << "   PascalCase  -> class/struct      : DataMahasiswa" << endl;
    cout << "   UPPER_SNAKE -> konstanta         : MAX_NILAI" << endl;
}

int main(){

    variabel();

    return 0;
}
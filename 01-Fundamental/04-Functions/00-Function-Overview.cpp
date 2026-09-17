#include <iostream>
#include <string>
using namespace std;

// PROTOTYPE -- karena ada function yang didefinisi di bawah main
void tanpaFunction();
void denganFunction();
void cetakKotak(string judul);
void demoAnatomi();
void demoPrototype();
void demoNamingConvention();

int hitungJumlah(int a, int b);   // prototype dengan nama parameter
int hitungKuadrat(int);           // prototype tanpa nama parameter (juga valid)

// Untuk demo mutual recursion
bool isGenapDemo(int n);
bool isGanjilDemo(int n);


// MENGAPA BUTUH FUNCTION?
    void tanpaFunction() {
        cout << "[ Tanpa Function -- kode berulang ]" << endl;
        cout << "--------------------" << endl;
        cout << "  DATA MAHASISWA  " << endl;
        cout << "--------------------" << endl;
        cout << "Nama  : Gega" << endl;
        cout << "Nilai : 90" << endl;
        cout << endl;
        // Mau cetak lagi? Harus tulis ulang semua ini!
        cout << "--------------------" << endl;
        cout << "  DATA MAHASISWA  " << endl;
        cout << "--------------------" << endl;
        cout << "Nama  : Budi" << endl;
        cout << "Nilai : 85" << endl;
    }

// Function untuk cetak kotak -- sekali tulis, pakai berkali-kali
    void cetakKotak(string judul) {
        int lebar = 20;
            cout << "  ";
            for (int i = 0; i < lebar; i++){
                cout << "-";
            } 
            cout << endl;

        int spasi = (lebar - (int)judul.length()) / 2;
            cout << "  ";
            for (int i = 0; i < spasi; i++){
                cout << " ";
            } 

            cout << judul << endl;

            cout << "  ";
            for (int i = 0; i < lebar; i++){
                cout << "-";
            } 
            cout << endl;
    }

    void denganFunction() {
        cout << "[ Dengan Function -- tidak ada pengulangan kode ]" << endl;

        cetakKotak("DATA MAHASISWA");
        cout << "  Nama  : Gega" << endl;
        cout << "  Nilai : 90" << endl;
        cout << endl;

        cetakKotak("DATA MAHASISWA");   // panggil lagi, mudah!
        cout << "  Nama  : Budi" << endl;
        cout << "  Nilai : 85" << endl;
    }


// ANATOMI FUNCTION
    void demoAnatomi() {
        cout << "\n  Anatomi Function:" << endl;
        cout << endl;
        cout << "      [1]     [2]           [3]" << endl;
        cout << "      int hitungJumlah(int a, int b) {" << endl;
        cout << "          int hasil = a + b;                   <--- [4] Body" << endl;
        cout << "          return hasil;                        <--- [5] Return" << endl;
        cout << "      }" << endl;
        cout << endl;
        cout << "  [1] Return Type  : int" << endl;
        cout << "  [2] Nama         : hitungJumlah" << endl;
        cout << "  [3] Parameter    : int a, int b" << endl;
        cout << "  [4] Body         : logika di dalamnya" << endl;
        cout << "  [5] Return       : nilai yang dikembalikan" << endl;
        cout << endl;
        cout << "  Cara memanggil:" << endl;
        cout << "      int x = hitungJumlah(3, 4);   --> x = " << hitungJumlah(3, 4) << endl;
        cout << "      int y = hitungKuadrat(5);     --> y = " << hitungKuadrat(5)   << endl;
    }


// NAMING CONVENTION
    void demoNamingConvention() {
        cout << "\n  Naming Convention:" << endl;
        cout << "  Nama baik  : hitungLuasLingkaran, cetakLaporan, validasiInput" << endl;
        cout << "  Nama buruk : h(), prss(), fungsi1(), doStuff()" << endl;
        cout << endl;
        cout << "  Pola umum kata kerja + objek:" << endl;
        cout << "      hitung   + Total, RataRata, Luas, Diskon" << endl;
        cout << "      cetak    + Header, Laporan, Menu, Garis" << endl;
        cout << "      ambil    + Input, NilaiMaks, NilaiMin" << endl;
        cout << "      validasi + Input, Email, Password" << endl;
        cout << "      konversi + Suhu, Mata Uang, Satuan" << endl;
    }

// FUNCTION PROTOTYPE

    int hitungJumlah(int a, int b) {
        int hasil = a + b;
        return hasil;
    }

    int hitungKuadrat(int x) {
        return x * x;
    }

    bool isGenapDemo(int n) {
        if (n == 0) {
            return true;
        }
        return isGanjilDemo(n - 1);   // panggil isGanjilDemo -- butuh prototype di atas!
    }

    bool isGanjilDemo(int n) {
        if (n == 0) {
            return false;
        }
        return isGenapDemo(n - 1);
    }

    void demoPrototype() {
        cout << "\n  Demo Prototype -- hitungJumlah dan hitungKuadrat" << endl;
        cout << "  (definisinya ada di bawah main, tapi bisa dipanggil" << endl;
        cout << "   karena prototype sudah ditulis di atas file)" << endl;
        cout << endl;
        cout << "  hitungJumlah(10, 20) = " << hitungJumlah(10, 20) << endl;
        cout << "  hitungKuadrat(7)     = " << hitungKuadrat(7)     << endl;

        cout << "\n  Demo Mutual Recursion isGenap / isGanjil:" << endl;
        for (int i = 0; i <= 7; i++) {
            cout << "  " << i << " -> " << (isGenapDemo(i) ? "genap" : "ganjil") << endl;
        }
    }


int main() {
    cout << "\n\n============================================================" << endl;
    cout << "  T.0 -- Pengenalan Function" << endl;
    cout << "============================================================" << endl;

    cout << "\n\n[ Mengapa Butuh Function? ]" << endl;
    cout << endl;
    tanpaFunction();
    cout << endl;
    denganFunction();

    cout << "\n\n============================================================" << endl;
    cout << "  Anatomi Function" << endl;
    cout << "============================================================" << endl;
    demoAnatomi();

    cout << "\n\n============================================================" << endl;
    cout << "  Naming Convention" << endl;
    cout << "============================================================" << endl;
    demoNamingConvention();

    cout << "\n\n============================================================" << endl;
    cout << "  Function Prototype" << endl;
    cout << "============================================================" << endl;
    demoPrototype();

    cout << "\n\n============================================================" << endl;
    cout << "  Aturan Penting" << endl;
    cout << "============================================================" << endl;
    cout << "  1. Tidak bisa nested function (function di dalam function)" << endl;
    cout << "  2. Function harus dikenal sebelum dipanggil (pakai prototype)" << endl;
    cout << "  3. Return type harus sesuai dengan nilai yang di-return" << endl;
    cout << "  4. Semua jalur if-else harus punya return (untuk non-void)" << endl;
    cout << "  5. Hindari global variable, gunakan parameter dan return" << endl;

    cout << "\n\n  Lanjut ke file berikutnya:" << endl;
    cout << "  01-Void-Function.cpp      ---> function tanpa return value" << endl;
    cout << "  02-Fruitful-Function.cpp  ---> function dengan return value" << endl;

    return 0;
}

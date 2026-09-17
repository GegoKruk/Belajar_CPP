
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int    umur;
    double ipk;
};

struct Produk {
    string nama    = "Tidak diketahui";
    double harga   = 0.0;
    int    stok    = 0;
    bool   aktif   = true;
};

struct Titik {
    double x;
    double y;
    double z;
};

void cetakMahasiswa(const string& label, const Mahasiswa& m) {
    cout << label << ": " << m.nama << " | umur=" << m.umur << " | ipk=" << m.ipk << endl;
}

int main() {

    // ----- a. Satu per Satu -----
        cout << "=== a. Inisialisasi Satu per Satu ===" << endl;

        Mahasiswa m1;
        m1.nama = "Budi";
        m1.umur = 20;
        m1.ipk  = 3.85;
        cetakMahasiswa("m1", m1);


    // ----- b. Aggregate Initialization -----
        cout << endl << "=== b. Aggregate Initialization ===" << endl;
        cout << "Urutan HARUS sesuai urutan deklarasi member!" << endl;

        Mahasiswa m2 = {"Sari", 21, 3.90};
        cetakMahasiswa("m2", m2);

        // Hati-hati urutan!
        // Mahasiswa mSalah = {20, "Budi", 3.85};  // ERROR: tipe tidak cocok
        // Mahasiswa mSalah = {3.85, 20, "Budi"};  // ERROR: tipe tidak cocok


    // ----- c. Partial Initialization -----
        cout << endl << "=== c. Partial Initialization ===" << endl;
        cout << "Member yang tidak diisi -> nilai nol/kosong otomatis" << endl;

        Mahasiswa m3 = {"Andi"};   // umur dan ipk tidak diisi
        cetakMahasiswa("m3 (nama saja)", m3);
        // umur = 0, ipk = 0.0 otomatis

        Titik t1 = {3.0, 4.0};    // z tidak diisi
        cout << "t1: x=" << t1.x << ", y=" << t1.y << ", z=" << t1.z << " (z otomatis 0)" << endl;


    // ----- d. Default Member Values -----
        cout << endl << "=== d. Default Member Values (C++11) ===" << endl;

        Produk p1;   // semua pakai default
        cout << "Produk default:" << endl;
        cout << "  nama  : " << p1.nama  << endl;
        cout << "  harga : " << p1.harga << endl;
        cout << "  stok  : " << p1.stok  << endl;
        cout << "  aktif : " << (p1.aktif ? "ya" : "tidak") << endl;

        Produk p2;
        p2.nama  = "Keyboard";
        p2.harga = 350000.0;
        p2.stok  = 50;
        // aktif tetap default = true
        cout << endl << "Produk p2 (aktif pakai default):" << endl;
        cout << "  nama  : " << p2.nama  << endl;
        cout << "  harga : " << p2.harga << endl;
        cout << "  stok  : " << p2.stok  << endl;
        cout << "  aktif : " << (p2.aktif ? "ya" : "tidak") << " (default)" << endl;


    // ----- e. Copy / Assignment -----
        cout << endl << "=== e. Copy dari Struct Lain ===" << endl;

        Mahasiswa m4 = m2;   // salinan lengkap dari m2
        cetakMahasiswa("m4 (copy dari m2)", m4);

        // Ubah m4, m2 tidak ikut berubah (karena copy, bukan reference)
        m4.nama = "Dewi";
        m4.ipk  = 3.75;
        cetakMahasiswa("m4 setelah diubah", m4);
        cetakMahasiswa("m2 tetap         ", m2);


    // ----- f. Zero Initialization -----
        cout << endl << "=== f. Zero Initialization ===" << endl;

        Mahasiswa mZero = {};   // semua member di-zero-init
        cetakMahasiswa("mZero", mZero);
        // nama = "" (kosong), umur = 0, ipk = 0.0


    // ----- Ringkasan -----
        cout << endl << "=== Ringkasan Cara Inisialisasi ===" << endl;
        cout << "Cara                   | Keterangan" << endl;
        cout << "-----------------------+------------------------------------" << endl;
        cout << "m.nama = ...           | Satu per satu, fleksibel" << endl;
        cout << "= {val1, val2, val3}   | Aggregate, urutan sesuai deklarasi" << endl;
        cout << "= {val1}               | Partial, sisanya 0/kosong" << endl;
        cout << "= {}                   | Zero-init semua member" << endl;
        cout << "Default member values  | Nilai di struct, pakai kalau tidak di-set" << endl;
        cout << "m2 = m1                | Copy semua member" << endl;

    return 0;
}

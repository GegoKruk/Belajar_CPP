
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int    umur;
    double ipk;
};

struct Produk {
    string nama;
    double harga;
    int    stok;
};

int main() {

    // ----- 1. Dot Operator (.) - Akses Langsung -----
        cout << "=== 1. Dot Operator (.) - Variabel Langsung ===" << endl;

        Mahasiswa mhs = {"Budi", 20, 3.85};

        // READ
            cout << "READ:" << endl;
            cout << "  mhs.nama = " << mhs.nama << endl;
            cout << "  mhs.umur = " << mhs.umur << endl;
            cout << "  mhs.ipk  = " << mhs.ipk  << endl;

        // WRITE
            cout << "WRITE:" << endl;
            mhs.nama = "Sari";
            mhs.umur = 21;
            mhs.ipk  = 3.90;
            cout << "  Setelah ubah: " << mhs.nama << " | " << mhs.umur << " | " << mhs.ipk << endl;

        // Member dalam operasi
            mhs.ipk = mhs.ipk + 0.05;
            cout << "  mhs.ipk + 0.05 = " << mhs.ipk << endl;


    // ----- 2. Arrow Operator (->) - Akses via Pointer -----
        cout << endl << "=== 2. Arrow Operator (->) - via Pointer ===" << endl;

        Mahasiswa mhs2  = {"Andi", 19, 3.70};
        Mahasiswa* ptr  = &mhs2;

        // READ via pointer
            cout << "READ via pointer:" << endl;
            cout << "  ptr->nama = " << ptr->nama << endl;
            cout << "  ptr->umur = " << ptr->umur << endl;
            cout << "  ptr->ipk  = " << ptr->ipk  << endl;

        // WRITE via pointer
            cout << "WRITE via pointer:" << endl;
            ptr->nama = "Dedi";
            ptr->ipk  = 3.80;
            cout << "  Setelah ubah via ptr: " << mhs2.nama << " | " << mhs2.ipk << endl;
            cout << "  (mhs2 ikut berubah karena ptr menunjuk ke mhs2)" << endl;

        // Perbandingan sintaks
            cout << endl << "Keduanya setara:" << endl;
            cout << "  ptr->nama       = " << ptr->nama       << endl;
            cout << "  (*ptr).nama     = " << (*ptr).nama     << endl;
            cout << "  Hasilnya sama: " << (ptr->nama == (*ptr).nama ? "Ya" : "Tidak") << endl;


    // ----- 3. Akses via Reference -----
        cout << endl << "=== 3. Akses via Reference ===" << endl;

        Mahasiswa mhs3  = {"Eka", 22, 3.95};
        Mahasiswa& ref  = mhs3;   // reference ke mhs3

        cout << "READ via reference:" << endl;
        cout << "  ref.nama = " << ref.nama << endl;
        cout << "  ref.umur = " << ref.umur << endl;

        // WRITE via reference (mengubah mhs3 asli!)
            ref.ipk = 4.00;
            cout << "WRITE via reference (ref.ipk = 4.00):" << endl;
            cout << "  mhs3.ipk = " << mhs3.ipk << " (ikut berubah!)" << endl;

            cout << endl << "Reference pakai dot (.) sama seperti variabel biasa." << endl;


    // ----- 4. Perbandingan Ketiganya -----
        cout << endl << "=== 4. Perbandingan: Variabel, Pointer, Reference ===" << endl;

        Produk prod = {"Mouse", 150000.0, 30};
        Produk* pProd = &prod;
        Produk& rProd = prod;

        cout << "Via variabel    : prod.nama  = " << prod.nama   << endl;
        cout << "Via pointer     : pProd->nama= " << pProd->nama << endl;
        cout << "Via reference   : rProd.nama = " << rProd.nama  << endl;

        // Ubah via pointer, cek semua
            pProd->harga = 175000.0;
            cout << endl << "Setelah pProd->harga = 175000:" << endl;
            cout << "  prod.harga  = " << prod.harga  << " (ikut berubah)" << endl;
            cout << "  pProd->harga= " << pProd->harga << endl;
            cout << "  rProd.harga = " << rProd.harga  << " (juga ikut berubah)" << endl;
            cout << "  Ketiganya menunjuk ke memori yang SAMA." << endl;


    // ----- 5. Ringkasan -----
        cout << endl << "=== 5. Ringkasan Sintaks Akses ===" << endl;
        cout << "Cara akses          | Sintaks         | Keterangan" << endl;
        cout << "--------------------+-----------------+------------------" << endl;
        cout << "Variabel langsung   | obj.member      | Paling umum" << endl;
        cout << "Via pointer         | ptr->member     | Shorthand untuk (*ptr).member" << endl;
        cout << "Via pointer (long)  | (*ptr).member   | Sama, tapi kurang bersih" << endl;
        cout << "Via reference       | ref.member      | Sama seperti variabel biasa" << endl;

    return 0;
}

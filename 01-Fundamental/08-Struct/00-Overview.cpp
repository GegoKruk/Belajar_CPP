#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct di luar main (agar bisa dipakai di mana saja)
    struct Mahasiswa {
        string nama;
        int    umur;
        double ipk;
    };

int main() {

    // ----- Contoh paling dasar -----
        cout << "=== Contoh Dasar Struct ===" << endl;

        Mahasiswa mhs1;
        mhs1.nama = "Budi";
        mhs1.umur = 20;
        mhs1.ipk  = 3.85;

        Mahasiswa mhs2 = {"Sari", 21, 3.90};

        cout << "Mahasiswa 1:" << endl;
        cout << "  Nama : " << mhs1.nama << endl;
        cout << "  Umur : " << mhs1.umur << endl;
        cout << "  IPK  : " << mhs1.ipk  << endl;

        cout << "Mahasiswa 2:" << endl;
        cout << "  Nama : " << mhs2.nama << endl;
        cout << "  Umur : " << mhs2.umur << endl;
        cout << "  IPK  : " << mhs2.ipk  << endl;

    // sizeof struct
        cout << endl;
        cout << "sizeof(Mahasiswa) = " << sizeof(Mahasiswa) << " byte" << endl;
        cout << "(string + int + double, + kemungkinan padding)" << endl;

    return 0;
}

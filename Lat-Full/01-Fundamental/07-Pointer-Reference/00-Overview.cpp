
#include <iostream>
using namespace std;

int main() {

    // ----- Contoh paling dasar: Pointer -----
        cout << "=== Pointer - Contoh Dasar ===" << endl;

        int angka = 42;
        int* ptr  = &angka;     // ptr menyimpan ALAMAT angka

        cout << "angka       = " << angka  << endl;
        cout << "&angka      = " << &angka << " (alamat angka)" << endl;
        cout << "ptr         = " << ptr    << " (isi ptr = alamat angka)" << endl;
        cout << "*ptr        = " << *ptr   << " (nilai di alamat ptr)" << endl;


    // ----- Contoh paling dasar: Reference -----
        cout << endl << "=== Reference - Contoh Dasar ===" << endl;

        int nilai  = 10;
        int& ref   = nilai;     // ref adalah alias dari nilai

        cout << "nilai       = " << nilai << endl;
        cout << "ref         = " << ref   << " (sama dengan nilai)" << endl;

        ref = 99;   // ubah via reference
        cout << "Setelah ref = 99:" << endl;
        cout << "ref         = " << ref   << endl;
        cout << "nilai       = " << nilai << " (ikut berubah!)" << endl;
        cout << "&nilai      = " << &nilai << endl;
        cout << "&ref        = " << &ref   << " (alamat SAMA dengan &nilai)" << endl;

    return 0;
}

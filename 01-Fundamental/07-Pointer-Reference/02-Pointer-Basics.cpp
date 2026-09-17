#include <iostream>
using namespace std;

int main() {

    // ----- 1. Deklarasi dan Inisialisasi Pointer -----
        cout << "=== 1. Deklarasi dan Inisialisasi ===" << endl;

        int angka   = 42;
        int* ptr    = &angka;     // ptr menyimpan ALAMAT angka

        cout << "int angka = 42" << endl;
        cout << "int* ptr  = &angka" << endl;
        cout << endl;
        cout << "angka          = " << angka  << endl;
        cout << "&angka         = " << &angka << " (alamat angka)" << endl;
        cout << "ptr            = " << ptr    << " (isi ptr, sama dengan &angka)" << endl;
        cout << "*ptr           = " << *ptr   << " (dereference, nilai di alamat ptr)" << endl;
        cout << "&ptr           = " << &ptr   << " (alamat ptr itu sendiri)" << endl;


    // ----- 2. Modifikasi Nilai via Pointer -----
        cout << endl << "=== 2. Modifikasi via Pointer ===" << endl;

        cout << "Sebelum: angka = " << angka << endl;
        *ptr = 99;   // ubah nilai angka melalui pointer
        cout << "Setelah *ptr = 99:" << endl;
        cout << "  angka = " << angka << " (angka ikut berubah!)" << endl;
        cout << "  *ptr  = " << *ptr  << endl;


    // ----- 3. Pointer ke Berbagai Tipe -----
        cout << endl << "=== 3. Pointer ke Berbagai Tipe Data ===" << endl;

        double desimal = 3.14;
        double* dPtr   = &desimal;

        char huruf  = 'A';
        char* cPtr  = &huruf;

        bool status = true;
        bool* bPtr  = &status;

        cout << "double desimal = 3.14" << endl;
        cout << "  *dPtr = " << *dPtr << endl;

        cout << "char huruf = 'A'" << endl;
        cout << "  *cPtr = " << *cPtr << endl;

        cout << "bool status = true" << endl;
        cout << "  *bPtr = " << *bPtr << endl;


    // ----- 4. Null Pointer -----
        cout << endl << "=== 4. Null Pointer ===" << endl;

        int* pNull = nullptr;

        cout << "int* pNull = nullptr" << endl;

        // Cara aman menggunakan pointer
            if (pNull != nullptr) {
                cout << "  *pNull = " << *pNull << endl;
            } else {
                cout << "  pNull masih nullptr, aman tidak di-deref" << endl;
            }

        // Arahkan ke variabel baru
            int data = 55;
            pNull = &data;

            if (pNull != nullptr) {
                cout << "  Setelah diarahkan ke data: *pNull = " << *pNull << endl;
            }


    // ----- 5. Pointer Diubah Arah (Reassignment) -----
        cout << endl << "=== 5. Pointer Diubah Arah ===" << endl;

        int nilai1 = 10;
        int nilai2 = 20;
        int* p     = &nilai1;

        cout << "p menunjuk ke nilai1: *p = " << *p << endl;

        p = &nilai2;   // ubah arah pointer
        cout << "p diubah ke nilai2:   *p = " << *p << endl;

        // Ubah nilai2 via pointer
            *p = 99;
            cout << "Setelah *p = 99: nilai2 = " << nilai2 << endl;
            cout << "nilai1 tetap         = " << nilai1    << " (tidak berubah)" << endl;


    // ----- 6. Demonstrasi Hubungan Lengkap -----
        cout << endl << "=== 6. Hubungan Lengkap ===" << endl;

        int  x   = 100;
        int* px  = &x;

        cout << "Variabel  : x    = " << x    << endl;
        cout << "Alamat    : &x   = " << &x   << endl;
        cout << "Pointer   : px   = " << px   << " (isi ptr = alamat x)" << endl;
        cout << "Deref     : *px  = " << *px  << " (nilai di alamat px)" << endl;
        cout << "Alamat ptr: &px  = " << &px  << " (alamat px sendiri)" << endl;
        cout << endl;
        cout << "Perhatikan: px == &x karena ptr menyimpan alamat x" << endl;
        cout << "Apakah px == &x? " << (px == &x ? "Ya" : "Tidak") << endl;

    return 0;
}

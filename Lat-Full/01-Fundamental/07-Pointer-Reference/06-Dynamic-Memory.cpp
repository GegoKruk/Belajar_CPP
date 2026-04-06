
#include <iostream>
using namespace std;

int main() {

    // ----- 1. new dan delete untuk Satu Variabel -----
        cout << "=== 1. new dan delete (Satu Variabel) ===" << endl;

        int* ptr = new int(42);    // alokasi int di heap, nilai 42

        cout << "int* ptr = new int(42)" << endl;
        cout << "  ptr  = " << ptr  << " (alamat di heap)" << endl;
        cout << "  *ptr = " << *ptr << " (nilai)" << endl;

        *ptr = 99;   // modifikasi nilai
        cout << "Setelah *ptr = 99:" << endl;
        cout << "  *ptr = " << *ptr << endl;

        delete ptr;          // bebaskan memori
        ptr = nullptr;       // good practice: tandai sudah di-delete

        cout << "Setelah delete ptr + ptr = nullptr:" << endl;
        cout << "  ptr = " << ptr << " (nullptr)" << endl;


    // ----- 2. new untuk Berbagai Tipe -----
        cout << endl << "=== 2. new untuk Berbagai Tipe ===" << endl;

        double* dPtr = new double(3.14);
        char*   cPtr = new char('Z');
        bool*   bPtr = new bool(true);

        cout << "*dPtr = " << *dPtr << endl;
        cout << "*cPtr = " << *cPtr << endl;
        cout << "*bPtr = " << *bPtr << endl;

        delete dPtr;   dPtr = nullptr;
        delete cPtr;   cPtr = nullptr;
        delete bPtr;   bPtr = nullptr;
        cout << "Semua memori sudah dibebaskan." << endl;


    // ----- 3. Alokasi Array Dinamis (new[]) -----
        cout << endl << "=== 3. Array Dinamis (new[]) ===" << endl;

        int ukuran = 5;   // bisa dari input user

        int* arr = new int[ukuran];    // alokasi 5 int di heap

        cout << "int* arr = new int[" << ukuran << "]" << endl;

        // Isi array
            for (int i = 0; i < ukuran; i++) {
                arr[i] = (i + 1) * 10;
            }

            cout << "Isi array: ";
            for (int i = 0; i < ukuran; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

        // Akses dan modifikasi sama seperti array biasa
            arr[2] = 99;
            cout << "arr[2] diubah ke 99: ";
            for (int i = 0; i < ukuran; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            delete[] arr;    // WAJIB pakai [] untuk array!
            arr = nullptr;
            cout << "Array dibebaskan dengan delete[]" << endl;


    // ----- 4. Array Dinamis dengan Ukuran dari Input -----
        cout << endl << "=== 4. Ukuran Array dari Variabel (Flexibel) ===" << endl;

        int n = 4;   // simulasi ukuran dari input user
        cout << "Buat array ukuran " << n << " secara dinamis:" << endl;

        double* nilai = new double[n];

        nilai[0] = 85.5;
        nilai[1] = 90.0;
        nilai[2] = 78.3;
        nilai[3] = 92.7;

        double total = 0;
        for (int i = 0; i < n; i++) {
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
            total += nilai[i];
        }
        cout << "  Rata-rata = " << total / n << endl;

        delete[] nilai;
        nilai = nullptr;


    // ----- 5. Bahaya Memory Leak -----
        cout << endl << "=== 5. Contoh Memory Leak (JANGAN DILAKUKAN) ===" << endl;

        cout << "SALAH - Memory Leak:" << endl;
        cout << "  int* p = new int(10);" << endl;
        cout << "  p = new int(20);   // memori pertama (10) bocor!" << endl;
        cout << "  Alamat int(10) hilang, tidak bisa di-delete lagi!" << endl;

        cout << endl << "BENAR - Delete dulu sebelum reassign:" << endl;
        cout << "  int* p = new int(10);" << endl;
        cout << "  delete p;           // bebaskan dulu" << endl;
        cout << "  p = new int(20);   // baru reassign" << endl;

        // Demonstrasi yang benar:
            int* p = new int(10);
            cout << endl << "  *p awal = " << *p << endl;
            delete p;
            p = new int(20);
            cout << "  *p baru = " << *p << endl;
            delete p;
            p = nullptr;


    // ----- 6. Double Delete Protection -----
        cout << endl << "=== 6. Proteksi Double Delete ===" << endl;

        int* safe = new int(50);
        cout << "*safe = " << *safe << endl;

        delete safe;
        safe = nullptr;   // penting!

        // delete pada nullptr = AMAN, tidak crash
            delete safe;      // OK karena safe = nullptr
            cout << "delete nullptr = aman, tidak crash" << endl;


    // ----- 7. Pointer ke Pointer (double pointer) -----
        cout << endl << "=== 7. Pointer ke Pointer (int**) ===" << endl;

        int  angka = 42;
        int* ptr1  = &angka;
        int** ptr2 = &ptr1;   // pointer ke pointer

        cout << "int angka  = 42" << endl;
        cout << "int* ptr1  = &angka" << endl;
        cout << "int** ptr2 = &ptr1" << endl;
        cout << endl;
        cout << "angka   = " << angka    << endl;
        cout << "*ptr1   = " << *ptr1    << " (nilai angka via ptr1)" << endl;
        cout << "**ptr2  = " << **ptr2   << " (nilai angka via ptr2)" << endl;
        cout << "*ptr2   = " << *ptr2    << " (isi ptr1 = alamat angka)" << endl;
        cout << "ptr2    = " << ptr2     << " (alamat ptr1)" << endl;

        // Modifikasi via double pointer
            **ptr2 = 99;
            cout << endl << "Setelah **ptr2 = 99:" << endl;
            cout << "angka = " << angka << " (ikut berubah!)" << endl;

    return 0;
}

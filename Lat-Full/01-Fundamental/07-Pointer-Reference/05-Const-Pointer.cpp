#include <iostream>
using namespace std;

// Contoh fungsi baca-saja: pakai const int* agar isi array tidak bisa diubah
    void tampilArray(const int* arr, int size) {
        cout << "  ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // arr[0] = 99;  // ini akan ERROR - sesuai yang diharapkan
    }

int main() {

    int angka = 10;
    int lain  = 99;

    // ----- 1. Pointer Biasa (tidak ada const) -----
        cout << "=== 1. Pointer Biasa (tanpa const) ===" << endl;

        int* ptr = &angka;

        cout << "int* ptr = &angka (angka = " << angka << ")" << endl;
        *ptr = 55;         // OK: ubah nilai
        cout << "  *ptr = 55 -> angka = " << angka << " (nilai berubah)" << endl;
        ptr = &lain;       // OK: ubah arah
        cout << "  ptr = &lain -> *ptr = " << *ptr << " (arah berubah)" << endl;


    // ----- 2. Pointer ke Const (const int* ptr) -----
        cout << endl << "=== 2. Pointer ke Const (const int* ptr) ===" << endl;

        angka = 10;   // reset
        const int* ptrKonst = &angka;

        cout << "const int* ptrKonst = &angka" << endl;
        cout << "  *ptrKonst = " << *ptrKonst << " (bisa baca)" << endl;

        // *ptrKonst = 99;   // TIDAK BISA: ini akan compile error
        cout << "  *ptrKonst = 99  -> TIDAK BISA (nilai read-only via ptr ini)" << endl;

        ptrKonst = &lain;   // OK: pointer-nya bisa diubah arah
        cout << "  ptrKonst = &lain -> *ptrKonst = " << *ptrKonst << " (arah bisa diubah)" << endl;

        cout << endl;
        cout << "Contoh nyata penggunaan:" << endl;
        int data[4] = {10, 20, 30, 40};
        cout << "  tampilArray(data, 4): ";
        tampilArray(data, 4);


    // ----- 3. Const Pointer (int* const ptr) -----
        cout << endl << "=== 3. Const Pointer (int* const ptr) ===" << endl;

        angka = 10;   // reset
        int* const ptrFixed = &angka;

        cout << "int* const ptrFixed = &angka" << endl;
        cout << "  *ptrFixed = " << *ptrFixed << " (bisa baca)" << endl;

        *ptrFixed = 77;    // OK: nilai bisa diubah
        cout << "  *ptrFixed = 77  -> angka = " << angka << " (nilai bisa diubah)" << endl;

        // ptrFixed = &lain;   // TIDAK BISA: ini akan compile error
        cout << "  ptrFixed = &lain -> TIDAK BISA (alamat tidak bisa diubah)" << endl;


    // ----- 4. Const Pointer ke Const (const int* const ptr) -----
        cout << endl << "=== 4. Const Pointer ke Const (const int* const ptr) ===" << endl;

        angka = 10;   // reset
        const int* const ptrFullKonst = &angka;

        cout << "const int* const ptrFullKonst = &angka" << endl;
        cout << "  *ptrFullKonst = " << *ptrFullKonst << " (bisa baca)" << endl;

        // *ptrFullKonst = 99;      // TIDAK BISA
        // ptrFullKonst = &lain;    // TIDAK BISA
        cout << "  *ptrFullKonst = 99    -> TIDAK BISA" << endl;
        cout << "  ptrFullKonst = &lain  -> TIDAK BISA" << endl;
        cout << "  Keduanya terkunci setelah inisialisasi." << endl;


    // ----- 5. Ringkasan -----
        cout << endl << "=== 5. Ringkasan ===" << endl;
        cout << "Deklarasi                  | Ubah *ptr | Ubah ptr  " << endl;
        cout << "---------------------------+-----------+-----------" << endl;
        cout << "int* ptr                   |   Bisa    |   Bisa    " << endl;
        cout << "const int* ptr             | Tidak bisa|   Bisa    " << endl;
        cout << "int* const ptr             |   Bisa    | Tidak bisa" << endl;
        cout << "const int* const ptr       | Tidak bisa| Tidak bisa" << endl;

        cout << endl;
        cout << "Tips baca: dari KANAN ke KIRI" << endl;
        cout << "  const int* ptr      -> ptr adalah pointer ke int yang CONST" << endl;
        cout << "  int* const ptr      -> ptr adalah CONST pointer ke int" << endl;
        cout << "  const int* const ptr-> ptr adalah CONST pointer ke int CONST" << endl;

    return 0;
}

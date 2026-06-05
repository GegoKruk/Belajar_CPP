#include <iostream>
using namespace std;

// Fungsi yang mengubah pointer menggunakan double pointer
void alihkanPointer(int** target, int* nilaiBaru) {
    *target = nilaiBaru;   // ubah alamat yang ditunjuk oleh target
}

int main() {
    cout << "=== Pointer ke Pointer (Double Pointer) ===\n\n";

    // Contoh 1: double pointer sederhana
    int a = 10;
    int b = 20;
    int* ptrA = &a;
    int** ptrPtr = &ptrA;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "ptrA menunjuk ke a, alamat = " << ptrA << endl;
    cout << "ptrPtr = " << ptrPtr << ", isi = " << *ptrPtr << endl;
    cout << "Nilai via ptrPtr: **ptrPtr = " << **ptrPtr << endl;

    // Ubah ptrA melalui ptrPtr
    **ptrPtr = 99;
    cout << "\nSetelah **ptrPtr = 99, a = " << a << endl;

    // Contoh 2: mengubah pointer di dalam fungsi
    int* ptrB = &b;
    cout << "\nSebelum alihkanPointer: ptrA = " << ptrA << " (" << *ptrA << ")\n";
    alihkanPointer(&ptrA, ptrB);
    cout << "Setelah alihkanPointer: ptrA = " << ptrA << " (" << *ptrA << ")\n";

    // Contoh 3: dynamic 2D array (matriks)
    int baris = 3, kolom = 4;
    int** matriks = new int*[baris];
    for(int i=0; i<baris; i++) {
        matriks[i] = new int[kolom];
        for(int j=0; j<kolom; j++)
            matriks[i][j] = (i+1)*10 + (j+1);
    }

    cout << "\nDynamic 2D array (matriks 3x4):\n";
    for(int i=0; i<baris; i++) {
        for(int j=0; j<kolom; j++)
            cout << matriks[i][j] << " ";
        cout << endl;
    }

    // Bersihkan memori
    for(int i=0; i<baris; i++) delete[] matriks[i];
    delete[] matriks;

    return 0;
}
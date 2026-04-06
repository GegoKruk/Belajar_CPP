
#include <iostream>
using namespace std;

// ----- Global Array (contoh, gunakan dengan bijak) -----
    int skorGlobal[5] = {0};

// ----- Prototype (deklarasi di atas) -----
    void tampilArray(const int arr[], int size);
    void isiArray(int arr[], int size, int nilai);
    int totalArray(const int arr[], int size);
    int maxArray(const int arr[], int size);
    int minArray(const int arr[], int size);
    double rataArray(const int arr[], int size);
    int cariElemen(const int arr[], int size, int target);
    void sortArray(int arr[], int size);
    void tampilMatriks(int mat[][3], int baris, int kolom);
    int* buatStaticArray();

// ============================================================
//  IMPLEMENTASI FUNGSI UTILITY
// ============================================================

// Tampilkan semua elemen array
    void tampilArray(const int arr[], int size) {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << arr[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]";
    }

// Isi semua elemen dengan nilai tertentu
    void isiArray(int arr[], int size, int nilai) {
        for (int i = 0; i < size; i++) {
            arr[i] = nilai;
        }
    }

// Hitung total (sum)
    int totalArray(const int arr[], int size) {
        int total = 0;
        for (int i = 0; i < size; i++) total += arr[i];
        return total;
    }

// Cari nilai maksimum
    int maxArray(const int arr[], int size) {
        int maks = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > maks) maks = arr[i];
        return maks;
    }

// Cari nilai minimum
    int minArray(const int arr[], int size) {
        int mini = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] < mini) mini = arr[i];
        return mini;
    }

// Hitung rata-rata
    double rataArray(const int arr[], int size) {
        return (double)totalArray(arr, size) / size;
    }

// Cari elemen (linear search), return index atau -1
    int cariElemen(const int arr[], int size, int target) {
        for (int i = 0; i < size; i++)
            if (arr[i] == target) return i;
        return -1;
    }

// Sort ascending (Bubble Sort)
    void sortArray(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j]   = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

// Tampilkan array 2D (kolom WAJIB dicantumkan)
    void tampilMatriks(int mat[][3], int baris, int kolom) {
        for (int i = 0; i < baris; i++) {
            cout << "  ";
            for (int j = 0; j < kolom; j++) {
                cout << mat[i][j];
                if (j < kolom - 1) cout << "  ";
            }
            cout << endl;
        }
    }

// Return static array (array WAJIB static!)
    int* buatStaticArray() {
        static int arr[5] = {10, 20, 30, 40, 50};
        return arr;  // aman karena static
    }


// ============================================================
//  MAIN
// ============================================================

int main() {

    // ----- 1. Pass Array ke Function -----
        cout << "=== 1. Pass Array ke Function ===" << endl;

        int nilai[6] = {85, 90, 78, 92, 88, 76};
        int n = sizeof(nilai) / sizeof(nilai[0]);

        cout << "Array  : ";
        tampilArray(nilai, n);
        cout << endl;

        cout << "Total  : " << totalArray(nilai, n) << endl;
        cout << "Max    : " << maxArray(nilai, n)   << endl;
        cout << "Min    : " << minArray(nilai, n)   << endl;
        cout << "Rata   : " << rataArray(nilai, n)  << endl;


    // ----- 2. Array Diubah di Dalam Function -----
        cout << endl << "=== 2. Array Diubah di Dalam Function ===" << endl;

        int data[5] = {3, 1, 4, 1, 5};
        cout << "Sebelum sort: ";
        tampilArray(data, 5);
        cout << endl;

        sortArray(data, 5);

        cout << "Sesudah sort: ";
        tampilArray(data, 5);
        cout << " (array asli ikut berubah!)" << endl;


    // ----- 3. Return Lewat Parameter -----
        cout << endl << "=== 3. Return Lewat Parameter (Cara Paling Umum) ===" << endl;

        int hasilKali[5];
        int sumber[5] = {1, 2, 3, 4, 5};

        // Isi hasilKali dengan sumber dikali 3
            for (int i = 0; i < 5; i++) {
                hasilKali[i] = sumber[i] * 3;
            }

            cout << "sumber    : ";
            tampilArray(sumber, 5);
            cout << endl;
            cout << "sumber x3 : ";
            tampilArray(hasilKali, 5);
            cout << endl;


    // ----- 4. Return Static Array -----
        cout << endl << "=== 4. Return Static Array ===" << endl;

        int* ptrArr = buatStaticArray();
        cout << "Static array: [";
        for (int i = 0; i < 5; i++) {
            cout << ptrArr[i];
            if (i < 4) cout << ", ";
        }
        cout << "]" << endl;


    // ----- 5. Pass Array 2D ke Function -----
        cout << endl << "=== 5. Pass Array 2D ke Function ===" << endl;

        int matriks[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };

        cout << "Matriks (2x3):" << endl;
        tampilMatriks(matriks, 2, 3);


    // ----- 6. Global Array -----
        cout << endl << "=== 6. Global Array ===" << endl;

        cout << "Sebelum isi: ";
        tampilArray(skorGlobal, 5);
        cout << endl;

        isiArray(skorGlobal, 5, 10);

        cout << "Sesudah isi: ";
        tampilArray(skorGlobal, 5);
        cout << " (diisi dari function)" << endl;


    // ----- 7. Linear Search via Function -----
        cout << endl << "=== 7. Linear Search via Function ===" << endl;

        int dataCari[7] = {10, 25, 33, 47, 52, 68, 74};
        int target = 47;

        int idx = cariElemen(dataCari, 7, target);
        
        if (idx != -1) {
            cout << "Cari " << target << " -> ditemukan di index " << idx << endl;
        } else {
            cout << "Cari " << target << " -> tidak ditemukan" << endl;
        }

        int targetTidakAda = 99;
        int idx2 = cariElemen(dataCari, 7, targetTidakAda);
        if (idx2 != -1) {
            cout << "Cari " << targetTidakAda << " -> ditemukan di index " << idx2 << endl;
        } else {
            cout << "Cari " << targetTidakAda << " -> tidak ditemukan" << endl;
        }

    return 0;
}

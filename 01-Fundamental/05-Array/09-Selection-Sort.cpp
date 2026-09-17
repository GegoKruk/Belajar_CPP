
#include <iostream>
using namespace std;

void swapNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void cetakArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

int main() {

    // ----- 1. Selection Sort Ascending -----
        cout << "=== 1. Selection Sort Ascending ===" << endl;

        int data[5] = {64, 25, 12, 22, 11};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Sebelum: ";
        cetakArray(data, n);
        cout << endl << endl;

        for (int i = 0; i < n - 1; i++) {
            // Cari index elemen terkecil dari posisi i ke kanan
            int idxMin = i;
            for (int j = i + 1; j < n; j++) {
                if (data[j] < data[idxMin]) {
                    idxMin = j;
                }
            }

            // Swap elemen terkecil ke posisi i (jika bukan dirinya sendiri)
            if (idxMin != i) {
                swapNilai(data[i], data[idxMin]);
            }

            cout << "Pass " << i + 1 << ": ";
            cetakArray(data, n);
            cout << "   <- index " << i << " sudah FIXED" << endl;
        }

        cout << endl << "Hasil Ascending: ";
        cetakArray(data, n);
        cout << endl;


    // ----- 2. Selection Sort Descending -----
        cout << endl << "=== 2. Selection Sort Descending ===" << endl;

        int data2[5] = {64, 25, 12, 22, 11};

        cout << "Sebelum: ";
        cetakArray(data2, n);
        cout << endl;

        for (int i = 0; i < n - 1; i++) {
            // Cari index elemen TERBESAR untuk descending
            int idxMaks = i;
            for (int j = i + 1; j < n; j++) {
                if (data2[j] > data2[idxMaks]) {
                    idxMaks = j;
                }
            }
            if (idxMaks != i) {
                swapNilai(data2[i], data2[idxMaks]);
            }
        }

        cout << "Hasil Descending: ";
        cetakArray(data2, n);
        cout << endl;


    // ----- 3. Hitung jumlah swap -----
        cout << endl << "=== 3. Perbandingan Jumlah Swap ===" << endl;

        int dataBubble[5]    = {5, 4, 3, 2, 1};
        int dataSelection[5] = {5, 4, 3, 2, 1};

    // Hitung swap Bubble Sort
        int swapBubble = 0;
        for (int pass = 0; pass < 4; pass++) {
            for (int j = 0; j < 4 - pass; j++) {
                if (dataBubble[j] > dataBubble[j + 1]) {
                    swapNilai(dataBubble[j], dataBubble[j + 1]);
                    swapBubble++;
                }
            }
        }

    // Hitung swap Selection Sort
        int swapSelection = 0;
        for (int i = 0; i < 4; i++) {
            int idxMin = i;
            for (int j = i + 1; j < 5; j++) {
                if (dataSelection[j] < dataSelection[idxMin]) idxMin = j;
            }
            if (idxMin != i) {
                swapNilai(dataSelection[i], dataSelection[idxMin]);
                swapSelection++;
            }
        }

        cout << "Data awal [5, 4, 3, 2, 1] (worst case):" << endl;
        cout << "  Bubble Sort     : " << swapBubble    << " kali swap" << endl;
        cout << "  Selection Sort  : " << swapSelection << " kali swap" << endl;
        cout << "  Selection Sort jauh lebih hemat swap!" << endl;

    return 0;
}

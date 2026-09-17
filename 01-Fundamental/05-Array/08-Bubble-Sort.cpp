
#include <iostream>
using namespace std;

// Fungsi swap dua nilai
    void swapNilai(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

// Fungsi cetak array
    void cetakArray(int arr[], int n) {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "]";
    }

int main() {

    // ----- 1. Bubble Sort Ascending (naik) -----
        cout << "=== 1. Bubble Sort Ascending ===" << endl;

        int data[5] = {64, 34, 25, 12, 22};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Sebelum: ";
        cetakArray(data, n);
        cout << endl << endl;

    // Outer loop: n-1 pass
        for (int pass = 0; pass < n - 1; pass++) {
            cout << "Pass " << pass + 1 << ": ";
            // Inner loop: bandingkan elemen berdekatan
            // Tiap pass, elemen terbesar sudah di tempat -> kurangi batas
            for (int j = 0; j < n - 1 - pass; j++) {
                if (data[j] > data[j + 1]) {
                    swapNilai(data[j], data[j + 1]);
                }
            }
            cetakArray(data, n);
            cout << endl;
        }

        cout << endl << "Hasil Ascending: ";
        cetakArray(data, n);
        cout << endl;


    // ----- 2. Bubble Sort Descending (turun) -----
        cout << endl << "=== 2. Bubble Sort Descending ===" << endl;

        int data2[5] = {64, 34, 25, 12, 22};

        cout << "Sebelum: ";
        cetakArray(data2, n);
        cout << endl;

        for (int pass = 0; pass < n - 1; pass++) {
            for (int j = 0; j < n - 1 - pass; j++) {
                if (data2[j] < data2[j + 1]) {  // Tanda berbalik untuk descending
                    swapNilai(data2[j], data2[j + 1]);
                }
            }
        }

        cout << "Hasil Descending: ";
        cetakArray(data2, n);
        cout << endl;


    // ----- 3. Bubble Sort dengan Optimasi Flag -----
        cout << endl << "=== 3. Bubble Sort dengan Optimasi (Early Stop) ===" << endl;

        int data3[6] = {1, 2, 3, 4, 6, 5}; // Hampir terurut, hanya 2 terakhir salah
        int n3 = sizeof(data3) / sizeof(data3[0]);

        cout << "Sebelum: ";
        cetakArray(data3, n3);
        cout << endl;

        int jumlahPass = 0;
        for (int pass = 0; pass < n3 - 1; pass++) {
            bool adaSwap = false;
            for (int j = 0; j < n3 - 1 - pass; j++) {
                if (data3[j] > data3[j + 1]) {
                    swapNilai(data3[j], data3[j + 1]);
                    adaSwap = true;
                }
            }
            jumlahPass++;
            cout << "Pass " << jumlahPass << ": ";
            cetakArray(data3, n3);
            cout << endl;

            if (!adaSwap) {
                cout << "  Tidak ada swap -> sudah terurut, berhenti!" << endl;
                break;
            }
        }

        cout << "Total pass yang dilakukan: " << jumlahPass << " (dari maksimal " << n3-1 << ")" << endl;

    return 0;
}

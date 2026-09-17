
#include <iostream>
using namespace std;

void cetakArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

void swapNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    // ----- 1. Reverse In-place (Two-pointer) -----
        cout << "=== 1. Reverse In-place (Two-pointer) ===" << endl;

        int data[5] = {1, 2, 3, 4, 5};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Sebelum: ";
        cetakArray(data, n);
        cout << endl << endl;

        int left  = 0;
        int right = n - 1;

        while (left < right) {
            cout << "  Swap index " << left << " (" << data[left]
                << ") dengan index " << right << " (" << data[right] << ")" << endl;
            swapNilai(data[left], data[right]);
            left++;
            right--;
        }

        cout << endl << "Sesudah: ";
        cetakArray(data, n);
        cout << endl;


    // ----- 2. Reverse dengan Array Baru -----
        cout << endl << "=== 2. Reverse dengan Array Baru ===" << endl;

        int asli[6] = {10, 20, 30, 40, 50, 60};
        int na = sizeof(asli) / sizeof(asli[0]);
        int balik[6];

        cout << "Asli  : ";
        cetakArray(asli, na);
        cout << endl;

        for (int i = 0; i < na; i++) {
            balik[i] = asli[na - 1 - i];
        }

        cout << "Balik : ";
        cetakArray(balik, na);
        cout << endl;


    // ----- 3. Reverse Array Ganjil vs Genap -----
        cout << endl << "=== 3. Reverse pada Jumlah Elemen Berbeda ===" << endl;

        // Jumlah elemen genap
            int genap[4] = {1, 2, 3, 4};
            int ng = sizeof(genap) / sizeof(genap[0]);
            cout << "Sebelum (genap): ";
            cetakArray(genap, ng);
            cout << endl;

            int lg = 0, rg = ng - 1;
            while (lg < rg) { swapNilai(genap[lg++], genap[rg--]); }

            cout << "Sesudah (genap): ";
            cetakArray(genap, ng);
            cout << endl;

        // Jumlah elemen ganjil
            int ganjil[5] = {1, 2, 3, 4, 5};
            int nj = sizeof(ganjil) / sizeof(ganjil[0]);
            cout << "Sebelum (ganjil): ";
            cetakArray(ganjil, nj);
            cout << endl;

            int lj = 0, rj = nj - 1;
            while (lj < rj) { swapNilai(ganjil[lj++], ganjil[rj--]); }

            cout << "Sesudah (ganjil): ";
            cetakArray(ganjil, nj);
            cout << " (elemen tengah tetap di tempat)" << endl;

    return 0;
}

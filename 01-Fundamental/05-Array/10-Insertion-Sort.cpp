
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

int main() {

    // ----- 1. Insertion Sort Ascending -----
        cout << "=== 1. Insertion Sort Ascending ===" << endl;

        int data[5] = {12, 11, 13, 5, 6};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Sebelum: ";
        cetakArray(data, n);
        cout << endl << endl;

        for (int i = 1; i < n; i++) {
            int key = data[i];  // Elemen yang akan disisipkan
            int j = i - 1;

            // Geser elemen yang lebih besar dari key ke kanan
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }

            // Sisipkan key di posisi yang tepat
            data[j + 1] = key;

            cout << "Iter " << i << " (key=" << key << "): ";
            cetakArray(data, n);
            cout << endl;
        }

        cout << endl << "Hasil Ascending: ";
        cetakArray(data, n);
        cout << endl;


    // ----- 2. Insertion Sort Descending -----
        cout << endl << "=== 2. Insertion Sort Descending ===" << endl;

        int data2[5] = {12, 11, 13, 5, 6};

        cout << "Sebelum: ";
        cetakArray(data2, n);
        cout << endl;

        for (int i = 1; i < n; i++) {
            int key = data2[i];
            int j = i - 1;

            // Untuk descending: geser elemen yang LEBIH KECIL dari key
            while (j >= 0 && data2[j] < key) {
                data2[j + 1] = data2[j];
                j--;
            }
            data2[j + 1] = key;
        }

        cout << "Hasil Descending: ";
        cetakArray(data2, n);
        cout << endl;


    // ----- 3. Demonstrasi keunggulan untuk data hampir terurut -----
        cout << endl << "=== 3. Data Hampir Terurut (Keunggulan Insertion Sort) ===" << endl;

        int hampirTerurut[6] = {1, 2, 3, 4, 6, 5}; // Hanya 2 elemen terakhir salah
        int nh = sizeof(hampirTerurut) / sizeof(hampirTerurut[0]);

        cout << "Sebelum: ";
        cetakArray(hampirTerurut, nh);
        cout << endl;

        int geser = 0;
        for (int i = 1; i < nh; i++) {
            int key = hampirTerurut[i];
            int j = i - 1;
            while (j >= 0 && hampirTerurut[j] > key) {
                hampirTerurut[j + 1] = hampirTerurut[j];
                j--;
                geser++;
            }
            hampirTerurut[j + 1] = key;
        }

        cout << "Sesudah: ";
        cetakArray(hampirTerurut, nh);
        cout << endl;
        cout << "Total geser: " << geser << " kali (hampir tidak ada kerja!)" << endl;

    return 0;
}

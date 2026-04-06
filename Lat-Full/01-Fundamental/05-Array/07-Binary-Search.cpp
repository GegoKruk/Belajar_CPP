
#include <iostream>
using namespace std;

int main() {

    // Data WAJIB sudah terurut untuk binary search
        int data[8] = {11, 12, 22, 25, 34, 45, 64, 90};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Data (sudah terurut): ";
        for (int i = 0; i < n; i++) cout << data[i] << " ";
        cout << endl << endl;


    // ----- Binary Search Iteratif -----
        cout << "=== Binary Search Iteratif ===" << endl;

        int target = 22;
        cout << "Mencari: " << target << endl;

        int left  = 0;
        int right = n - 1;
        int posisi = -1;
        int langkah = 0;

        while (left <= right) {
            langkah++;
            int mid = (left + right) / 2;

            cout << "  Langkah " << langkah
                << ": left=" << left
                << ", right=" << right
                << ", mid=" << mid
                << ", arr[mid]=" << data[mid] << endl;

            if (data[mid] == target) {
                posisi = mid;
                break;
            } else if (data[mid] < target) {
                left = mid + 1;
                cout << "    " << data[mid] << " < " << target << " -> cari di kanan" << endl;
            } else {
                right = mid - 1;
                cout << "    " << data[mid] << " > " << target << " -> cari di kiri" << endl;
            }
        }

        if (posisi != -1) {
            cout << "Ditemukan di index " << posisi
                << " dalam " << langkah << " langkah!" << endl;
        } else {
            cout << "Tidak ditemukan." << endl;
        }


    // ----- Binary Search - Data Tidak Ada -----
        cout << endl << "=== Binary Search - Data Tidak Ada ===" << endl;
        int target2 = 50;
        cout << "Mencari: " << target2 << endl;

        int left2  = 0;
        int right2 = n - 1;
        int posisi2 = -1;

        while (left2 <= right2) {
            int mid2 = (left2 + right2) / 2;
            if (data[mid2] == target2) {
                posisi2 = mid2;
                break;
            } else if (data[mid2] < target2) {
                left2 = mid2 + 1;
            } else {
                right2 = mid2 - 1;
            }
        }

        if (posisi2 != -1) {
            cout << "Ditemukan di index " << posisi2 << endl;
        } else {
            cout << "Tidak ditemukan." << endl;
        }


    // ----- Perbandingan langkah Linear vs Binary -----
        cout << endl << "=== Perbandingan Langkah ===" << endl;
        int cariLinear = 64;
        int langkahLinear = 0;
        for (int i = 0; i < n; i++) {
            langkahLinear++;
            if (data[i] == cariLinear) break;
        }

        int cariBS = 64;
        int l = 0, r = n - 1;
        int langkahBS = 0;
        while (l <= r) {
            langkahBS++;
            int m = (l + r) / 2;
            if (data[m] == cariBS) break;
            else if (data[m] < cariBS) l = m + 1;
            else r = m - 1;
        }

        cout << "Mencari " << cariLinear << " dari " << n << " elemen:" << endl;
        cout << "  Linear Search : " << langkahLinear << " langkah" << endl;
        cout << "  Binary Search : " << langkahBS     << " langkah" << endl;

    return 0;
}

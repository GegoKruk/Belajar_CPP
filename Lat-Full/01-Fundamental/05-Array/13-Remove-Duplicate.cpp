
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

    // ----- 1. Remove Duplicate (Two-pointer, data sudah sorted) -----
        cout << "=== 1. Remove Duplicate - Two-pointer (Data Sorted) ===" << endl;

        int sorted[8] = {1, 1, 2, 3, 3, 4, 5, 5};
        int ns = sizeof(sorted) / sizeof(sorted[0]);

        cout << "Sebelum: ";
        cetakArray(sorted, ns);
        cout << " (size=" << ns << ")" << endl;

        int uniqueIndex = 0;
        for (int i = 1; i < ns; i++) {
            if (sorted[i] != sorted[uniqueIndex]) {
                uniqueIndex++;
                sorted[uniqueIndex] = sorted[i];
            }
        }
        int ukuranBaru = uniqueIndex + 1;

        cout << "Sesudah: ";
        cetakArray(sorted, ukuranBaru);
        cout << " (size=" << ukuranBaru << ")" << endl;


    // ----- 2. Remove Duplicate (Nested Loop, data tidak perlu sorted) -----
        cout << endl << "=== 2. Remove Duplicate - Nested Loop (Data Tidak Sorted) ===" << endl;

        int acak[8] = {3, 1, 4, 1, 5, 9, 2, 6};
        int na = sizeof(acak) / sizeof(acak[0]);

        cout << "Sebelum: ";
        cetakArray(acak, na);
        cout << " (size=" << na << ")" << endl;

        for (int i = 0; i < na; i++) {
            for (int j = i + 1; j < na; j++) {
                if (acak[i] == acak[j]) {
                    // Geser semua elemen ke kiri mulai dari j
                    for (int k = j; k < na - 1; k++) {
                        acak[k] = acak[k + 1];
                    }
                    na--;   // ukuran berkurang
                    j--;    // cek ulang posisi j (karena elemen sudah geser)
                }
            }
        }

        cout << "Sesudah: ";
        cetakArray(acak, na);
        cout << " (size=" << na << ")" << endl;


    // ----- 3. Find Duplicate (Cari Elemen yang Duplikat) -----
        cout << endl << "=== 3. Find Duplicate (Cari Elemen Duplikat) ===" << endl;

        int data[10] = {5, 3, 8, 3, 9, 3, 1, 8, 7, 2};
        int nd = sizeof(data) / sizeof(data[0]);

        cout << "Data: ";
        cetakArray(data, nd);
        cout << endl;
        cout << "Elemen yang duplikat:" << endl;

        // Tandai duplikat yang sudah dilaporkan agar tidak double lapor
        bool sudahLapor[10] = {false};

        for (int i = 0; i < nd; i++) {
            if (sudahLapor[i]) continue;
            for (int j = i + 1; j < nd; j++) {
                if (data[i] == data[j] && !sudahLapor[i]) {
                    cout << "  " << data[i] << " (muncul lebih dari sekali)" << endl;
                    sudahLapor[i] = true;
                    sudahLapor[j] = true;
                }
            }
        }


    // ----- 4. Hitung jumlah unik -----
        cout << endl << "=== 4. Hitung Elemen Unik ===" << endl;

        int data2[8] = {4, 2, 4, 1, 3, 2, 5, 1};
        int nd2 = sizeof(data2) / sizeof(data2[0]);

        cout << "Data: ";
        cetakArray(data2, nd2);
        cout << endl;

        int jumlahUnik = 0;
        bool sudahHitung[8] = {false};

        for (int i = 0; i < nd2; i++) {
            if (sudahHitung[i]) continue;
            jumlahUnik++;
            for (int j = i + 1; j < nd2; j++) {
                if (data2[j] == data2[i]) {
                    sudahHitung[j] = true;
                }
            }
        }

        cout << "Jumlah elemen unik: " << jumlahUnik << endl;

    return 0;
}

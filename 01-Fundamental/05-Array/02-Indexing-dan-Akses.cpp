#include <iostream>
using namespace std;

int main() {

    int nilai[5] = {85, 90, 78, 92, 88};

    // ----- Akses / Read Elemen -----
        cout << "=== Akses Elemen ===" << endl;
        cout << "nilai[0] (pertama) = " << nilai[0] << endl;
        cout << "nilai[2] (tengah)  = " << nilai[2] << endl;
        cout << "nilai[4] (terakhir)= " << nilai[4] << endl;

        // Pakai index dari ekspresi / variabel
        int idx = 3;
        cout << "nilai[idx] dimana idx=" << idx << " -> " << nilai[idx] << endl;

        // Gunakan nilai elemen dalam operasi
        int selisih = nilai[4] - nilai[2];
        cout << "nilai[4] - nilai[2] = " << selisih << endl;


    // ----- Modifikasi / Write Elemen -----
        cout << endl << "=== Modifikasi Elemen ===" << endl;
        cout << "Sebelum: nilai[0] = " << nilai[0] << endl;
        nilai[0] = 100;
        cout << "Sesudah: nilai[0] = " << nilai[0] << " (diubah jadi 100)" << endl;

        cout << "Sebelum: nilai[1] = " << nilai[1] << endl;
        nilai[1] = nilai[1] + 5;
        cout << "Sesudah: nilai[1] = " << nilai[1] << " (ditambah 5)" << endl;

        cout << "Sebelum: nilai[2] = " << nilai[2] << endl;
        nilai[2]++;
        cout << "Sesudah: nilai[2] = " << nilai[2] << " (di-increment)" << endl;


    // ----- Tampil Semua Elemen -----
        cout << endl << "=== Semua Elemen Setelah Modifikasi ===" << endl;
        int n = sizeof(nilai) / sizeof(nilai[0]);
        for (int i = 0; i < n; i++) {
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
        }


    // ----- Simulasi Cek Batas (safe access) -----
        cout << endl << "=== Contoh Akses Aman dengan Cek Batas ===" << endl;
        int indexDiminta = 3;
        if (indexDiminta >= 0 && indexDiminta < n) {
            cout << "nilai[" << indexDiminta << "] = " << nilai[indexDiminta] << " (aman)" << endl;
        } else {
            cout << "Index " << indexDiminta << " di luar batas! (0 sampai " << n-1 << ")" << endl;
        }

        int indexBerbahaya = 10;
        if (indexBerbahaya >= 0 && indexBerbahaya < n) {
            cout << "nilai[" << indexBerbahaya << "] = " << nilai[indexBerbahaya] << endl;
        } else {
            cout << "Index " << indexBerbahaya << " di luar batas! Ditolak." << endl;
        }

    return 0;
}

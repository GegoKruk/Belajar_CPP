
#include <iostream>
using namespace std;

int main() {

    int data[8] = {64, 34, 25, 12, 22, 11, 90, 45};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Data: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl << endl;


    // ----- 1. Non-Sentinel Search -----
        cout << "=== 1. Non-Sentinel Search ===" << endl;

        int target1 = 22;
        cout << "Mencari: " << target1 << endl;

        bool ketemu1 = false;
        int posisi1  = -1;
        for (int i = 0; i < n; i++) {
            if (data[i] == target1) {
                ketemu1 = true;
                posisi1 = i;
                break;
            }
        }

        if (ketemu1) {
            cout << "  Ditemukan di index " << posisi1 << endl;
        } else {
            cout << "  Tidak ditemukan" << endl;
        }

        // Cari data yang tidak ada
            int target2 = 99;

            cout << endl << "Mencari: " << target2 << endl;

            bool ketemu2 = false;
            int posisi2  = -1;

            for (int i = 0; i < n; i++) {
                if (data[i] == target2) {
                    ketemu2 = true;
                    posisi2 = i;
                    break;
                }
            }

            if (ketemu2) {
                cout << "  Ditemukan di index " << posisi2 << endl;
            } else {
                cout << "  Tidak ditemukan" << endl;
            }


    // ----- 2. Sentinel Search -----
        cout << endl << "=== 2. Sentinel Search ===" << endl;

        // Butuh array berukuran n+1 untuk ruang sentinel
        int sentinel[9] = {64, 34, 25, 12, 22, 11, 90, 45, 0}; // index ke-8 untuk sentinel
        int ns = 8; // ukuran data asli (tanpa slot sentinel)

        int target3 = 25;
        cout << "Mencari: " << target3 << endl;

        sentinel[ns] = target3; // taruh sentinel di posisi n
        
        int i = 0;

        while (sentinel[i] != target3) i++;

        if (i < ns) {
            cout << "  Ditemukan di index " << i << endl;
        } else {
            cout << "  Tidak ditemukan (yang ketemu cuma sentinel)" << endl;
        }

        int target4 = 77;
        cout << endl << "Mencari: " << target4 << endl;

        sentinel[ns] = target4;
        i = 0;
        while (sentinel[i] != target4) i++;

        if (i < ns) {
            cout << "  Ditemukan di index " << i << endl;
        } else {
            cout << "  Tidak ditemukan" << endl;
        }


    // ----- 3. Cari Semua Kemunculan -----
        cout << endl << "=== 3. Cari Semua Kemunculan ===" << endl;
        int duplikat[10] = {5, 3, 8, 3, 9, 3, 1, 3, 7, 2};
        int nd = sizeof(duplikat) / sizeof(duplikat[0]);
        int targetCari = 3;

        cout << "Data: ";
        for (int j = 0; j < nd; j++) cout << duplikat[j] << " ";
        cout << endl;
        cout << "Mencari semua kemunculan: " << targetCari << endl;

        int jumlahKetemu = 0;
        for (int j = 0; j < nd; j++) {
            if (duplikat[j] == targetCari) {
                cout << "  Ditemukan di index " << j << endl;
                jumlahKetemu++;
            }
        }
        cout << "  Total kemunculan: " << jumlahKetemu << " kali" << endl;

    return 0;
}

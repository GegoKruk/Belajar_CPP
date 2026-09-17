
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

    // ----- 1. Method 1: Nested Loop + Visited Array -----
        cout << "=== 1. Frequency Count - Nested Loop ===" << endl;

        int data[10] = {4, 2, 4, 1, 3, 2, 4, 1, 5, 2};
        int n = sizeof(data) / sizeof(data[0]);

        cout << "Data: ";
        cetakArray(data, n);
        cout << endl << endl;

        bool visited[10] = {false};

        cout << "Hasil frekuensi:" << endl;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;  // sudah dihitung, skip

            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (data[j] == data[i]) {
                    count++;
                    visited[j] = true;  // tandai duplikat
                }
            }
            cout << "  Elemen " << data[i] << " muncul " << count << " kali" << endl;
        }


    // ----- 2. Method 2: Frequency Array -----
        cout << endl << "=== 2. Frequency Count - Frequency Array ===" << endl;

        int data2[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
        int n2 = sizeof(data2) / sizeof(data2[0]);

        cout << "Data: ";
        cetakArray(data2, n2);
        cout << endl;

        // Cari nilai maksimum dulu untuk tentukan ukuran freq[]
            int maxVal = data2[0];
            for (int i = 1; i < n2; i++) {
                if (data2[i] > maxVal) maxVal = data2[i];
            }

        // Buat dan isi freq array
            int freq[10] = {0};  // cukup untuk maxVal <= 9
            for (int i = 0; i < n2; i++) {
                freq[data2[i]]++;
            }

        cout << "Hasil frekuensi:" << endl;
        for (int i = 0; i <= maxVal; i++) {
            if (freq[i] > 0) {
                cout << "  Elemen " << i << " muncul " << freq[i] << " kali" << endl;
            }
        }


    // ----- 3. Cari Elemen yang Paling Sering Muncul (Modus) -----
        cout << endl << "=== 3. Modus (Elemen Paling Sering Muncul) ===" << endl;

        int data3[10] = {1, 3, 2, 3, 5, 3, 2, 1, 3, 4};
        int n3 = sizeof(data3) / sizeof(data3[0]);

        cout << "Data: ";
        cetakArray(data3, n3);
        cout << endl;

        bool vis3[10] = {false};
        int modus      = data3[0];
        int freqModus  = 0;

        for (int i = 0; i < n3; i++) {

            if (vis3[i]) continue;

            int count = 1;

            for (int j = i + 1; j < n3; j++) {
                if (data3[j] == data3[i]) {
                    count++;
                    vis3[j] = true;
                }
            }

            if (count > freqModus) {
                freqModus = count;
                modus     = data3[i];
            }
        }

        cout << "Modus: " << modus << " (muncul " << freqModus << " kali)" << endl;


    // ----- 4. Distribusi Nilai (contoh praktis: nilai siswa) -----
        cout << endl << "=== 4. Distribusi Nilai Siswa ===" << endl;

        int nilai[12] = {85, 90, 78, 85, 92, 78, 90, 85, 76, 92, 85, 88};
        int nv = sizeof(nilai) / sizeof(nilai[0]);

        cout << "Nilai siswa: ";
        cetakArray(nilai, nv);
        cout << endl << endl;

        bool visVal[12] = {false};

        cout << "Distribusi:" << endl;
        for (int i = 0; i < nv; i++) {
            if (visVal[i]) continue;
            int count = 1;
            for (int j = i + 1; j < nv; j++) {
                if (nilai[j] == nilai[i]) {
                    count++;
                    visVal[j] = true;
                }
            }
            cout << "  Nilai " << nilai[i] << " : " << count << " siswa" << endl;
        }

    return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int BARIS = 3;
    const int KOLOM = 3;


    // ----- 1. Deklarasi dan Inisialisasi -----
        cout << "=== 1. Deklarasi dan Inisialisasi ===" << endl;

        int matriks[BARIS][KOLOM] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        cout << "Matriks 3x3:" << endl;
        for (int i = 0; i < BARIS; i++) {
            for (int j = 0; j < KOLOM; j++) {
                cout << setw(4) << matriks[i][j];
            }
            cout << endl;
        }


    // ----- 2. Akses dan Modifikasi Elemen -----
        cout << endl << "=== 2. Akses dan Modifikasi ===" << endl;

        cout << "matriks[0][1] = " << matriks[0][1] << " (baris 0, kolom 1)" << endl;
        cout << "matriks[2][2] = " << matriks[2][2] << " (baris 2, kolom 2)" << endl;

        matriks[1][1] = 99;
        cout << "Setelah matriks[1][1] = 99:" << endl;
        for (int i = 0; i < BARIS; i++) {
            for (int j = 0; j < KOLOM; j++) {
                cout << setw(4) << matriks[i][j];
            }
            cout << endl;
        }
        matriks[1][1] = 5; // Kembalikan ke 5


    // ----- 3. Penjumlahan Matriks -----
        cout << endl << "=== 3. Penjumlahan Matriks ===" << endl;

        int A[2][2] = {{1, 2}, {3, 4}};
        int B[2][2] = {{5, 6}, {7, 8}};
        int C[2][2];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                C[i][j] = A[i][j] + B[i][j];

        cout << "Matriks A:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << setw(4) << A[i][j];
            cout << endl;
        }
        cout << "Matriks B:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << setw(4) << B[i][j];
            cout << endl;
        }
        cout << "A + B = C:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << setw(4) << C[i][j];
            cout << endl;
        }


    // ----- 4. Transpose Matriks -----
        cout << endl << "=== 4. Transpose Matriks ===" << endl;

        int M[2][3] = {{1, 2, 3}, {4, 5, 6}};
        int T[3][2]; // Transpose: baris dan kolom dibalik

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                T[j][i] = M[i][j];

        cout << "Matriks M (2x3):" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) cout << setw(4) << M[i][j];
            cout << endl;
        }
        cout << "Transpose T (3x2):" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) cout << setw(4) << T[i][j];
            cout << endl;
        }


    // ----- 5. Operasi Baris/Kolom -----
        cout << endl << "=== 5. Jumlah Per Baris dan Per Kolom ===" << endl;

        int tabel[3][3] = {
            {10, 20, 30},
            {40, 50, 60},
            {70, 80, 90}
        };

        cout << "Tabel:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << setw(4) << tabel[i][j];
            cout << endl;
        }
        cout << endl;

        // Jumlah per baris
            for (int i = 0; i < 3; i++) {
                int totalBaris = 0;
                for (int j = 0; j < 3; j++) totalBaris += tabel[i][j];
                cout << "Jumlah baris " << i << " = " << totalBaris << endl;
            }
            cout << endl;

        // Jumlah per kolom
            for (int j = 0; j < 3; j++) {
                int totalKolom = 0;
                for (int i = 0; i < 3; i++) totalKolom += tabel[i][j];
                cout << "Jumlah kolom " << j << " = " << totalKolom << endl;
            }

    return 0;
}

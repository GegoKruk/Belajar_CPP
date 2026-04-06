
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int DEPTH = 2;
    const int BARIS = 3;
    const int KOLOM = 4;


    // ----- 1. Deklarasi dan Inisialisasi -----
        cout << "=== 1. Deklarasi dan Inisialisasi ===" << endl;

        int data[DEPTH][BARIS][KOLOM] = {
            {               // Lantai 0
                { 1,  2,  3,  4},
                { 5,  6,  7,  8},
                { 9, 10, 11, 12}
            },
            {               // Lantai 1
                {13, 14, 15, 16},
                {17, 18, 19, 20},
                {21, 22, 23, 24}
            }
        };

        // Iterasi dan cetak seluruh array 3D
            for (int d = 0; d < DEPTH; d++) {
                cout << "Lantai " << d << ":" << endl;
                for (int i = 0; i < BARIS; i++) {
                    cout << "  Baris " << i << ": ";
                    for (int j = 0; j < KOLOM; j++) {
                        cout << setw(4) << data[d][i][j];
                    }
                    cout << endl;
                }
            }


    // ----- 2. Akses Elemen Spesifik -----
        cout << endl << "=== 2. Akses Elemen Spesifik ===" << endl;

        cout << "data[0][0][0] = " << data[0][0][0] << " (lantai 0, baris 0, kolom 0)" << endl;
        cout << "data[0][1][2] = " << data[0][1][2] << " (lantai 0, baris 1, kolom 2)" << endl;
        cout << "data[1][2][3] = " << data[1][2][3] << " (lantai 1, baris 2, kolom 3)" << endl;


    // ----- 3. Modifikasi Elemen -----
        cout << endl << "=== 3. Modifikasi Elemen ===" << endl;

        cout << "Sebelum data[0][0][0] = " << data[0][0][0] << endl;
        data[0][0][0] = 99;
        cout << "Sesudah data[0][0][0] = " << data[0][0][0] << " (diubah ke 99)" << endl;
        data[0][0][0] = 1; // Kembalikan


    // ----- 4. Total Semua Elemen -----
        cout << endl << "=== 4. Jumlah Semua Elemen ===" << endl;

        int total = 0;
        for (int d = 0; d < DEPTH; d++)
            for (int i = 0; i < BARIS; i++)
                for (int j = 0; j < KOLOM; j++)
                    total += data[d][i][j];

        cout << "Total semua elemen = " << total << endl;
        cout << "Total elemen       = " << DEPTH * BARIS * KOLOM << " elemen" << endl;


    // ----- 5. sizeof Array 3D -----
        cout << endl << "=== 5. sizeof Array 3D ===" << endl;

        cout << "sizeof(data)            = " << sizeof(data)            << " byte (total)" << endl;
        cout << "sizeof(data[0])         = " << sizeof(data[0])         << " byte (1 lantai)" << endl;
        cout << "sizeof(data[0][0])      = " << sizeof(data[0][0])      << " byte (1 baris)" << endl;
        cout << "sizeof(data[0][0][0])   = " << sizeof(data[0][0][0])   << " byte (1 elemen)" << endl;
        cout << "Total elemen (dari sizeof) = "
            << sizeof(data) / sizeof(data[0][0][0]) << endl;


    // ----- 6. Contoh Praktis: Nilai 3 Semester, 2 Kelas, 3 Matkul -----
        cout << endl << "=== 6. Contoh Praktis: Nilai Per Semester ===" << endl;
        // [semester][kelas][matkul]

        int nilai[2][2][3] = {
            {               // Semester 1
                {80, 85, 90},   // Kelas A
                {75, 88, 92}    // Kelas B
            },
            {               // Semester 2
                {82, 87, 91},   // Kelas A
                {78, 84, 95}    // Kelas B
            }
        };

        string namaKelas[] = {"A", "B"};
        string namaMatkul[] = {"Matematika", "Fisika", "Kimia"};

        for (int s = 0; s < 2; s++) {
            cout << "Semester " << s + 1 << ":" << endl;
            for (int k = 0; k < 2; k++) {
                cout << "  Kelas " << namaKelas[k] << ": ";
                for (int m = 0; m < 3; m++) {
                    cout << namaMatkul[m] << "=" << nilai[s][k][m];
                    if (m < 2) cout << ", ";
                }
                cout << endl;
            }
        }

    return 0;
}

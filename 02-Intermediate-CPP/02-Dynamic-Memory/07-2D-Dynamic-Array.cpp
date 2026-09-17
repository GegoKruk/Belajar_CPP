#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================================================================
// HELPER: CETAK MATRIKS
// ================================================================
void cetakMatriks(int** m, int baris, int kolom, const string& label = "") {
    if (!label.empty()) cout << "  " << label << ":" << endl;
    for (int i = 0; i < baris; i++) {
        cout << "    ";
        for (int j = 0; j < kolom; j++) {
            cout << setw(5) << m[i][j];
        }
        cout << endl;
    }
}

void cetakMatriks1D(int* m, int baris, int kolom, const string& label = "") {
    if (!label.empty()) cout << "  " << label << ":" << endl;
    for (int i = 0; i < baris; i++) {
        cout << "    ";
        for (int j = 0; j < kolom; j++) {
            cout << setw(5) << m[i * kolom + j];
        }
        cout << endl;
    }
}

// ================================================================
// PENDEKATAN 1: POINTER-TO-POINTER (int**)
// ================================================================
int** buatMatriks(int baris, int kolom) {
    int** m = new int*[baris];          // alokasi array dari pointer
    for (int i = 0; i < baris; i++) {
        m[i] = new int[kolom]();        // alokasi setiap baris (nol-init)
    }
    return m;
}

void hapusMatriks(int** m, int baris) {
    for (int i = 0; i < baris; i++) {
        delete[] m[i];                  // hapus tiap baris dulu
        m[i] = nullptr;
    }
    delete[] m;                         // hapus array pointer
}

void isiIdentitas(int** m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = (i == j) ? 1 : 0;
}

int** penjumlahanMatriks(int** a, int** b, int baris, int kolom) {
    int** hasil = buatMatriks(baris, kolom);
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            hasil[i][j] = a[i][j] + b[i][j];
    return hasil;
}

int** perkalianMatriks(int** a, int** b, int bariA, int kol_A_bar_B, int kolomB) {
    int** hasil = buatMatriks(bariA, kolomB);
    for (int i = 0; i < bariA; i++)
        for (int j = 0; j < kolomB; j++)
            for (int k = 0; k < kol_A_bar_B; k++)
                hasil[i][j] += a[i][k] * b[k][j];
    return hasil;
}

int** transposeMatriks(int** m, int baris, int kolom) {
    int** hasil = buatMatriks(kolom, baris);   // dimensi dibalik
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            hasil[j][i] = m[i][j];
    return hasil;
}

// ================================================================
// PENDEKATAN 2: ARRAY 1D (cache-friendly)
// ================================================================
int* buatMatriks1D(int baris, int kolom) {
    return new int[baris * kolom]();    // satu blok berkesinambungan
}

// Akses: arr[i][j] -> arr[i * kolom + j]

void isiNilai1D(int* m, int baris, int kolom, int mulai = 1) {
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            m[i * kolom + j] = mulai++;
}

// ================================================================
// JAGGED ARRAY: TIAP BARIS PUNYA UKURAN BERBEDA
// ================================================================
void demo_jagged_array() {
    cout << "\n=== Jagged Array (Ukuran Baris Berbeda) ===" << endl;

    int baris = 4;
    int ukuranBaris[] = {2, 5, 3, 4};   // ukuran tiap baris berbeda-beda

    int** jagged = new int*[baris];
    for (int i = 0; i < baris; i++) {
        jagged[i] = new int[ukuranBaris[i]];
        for (int j = 0; j < ukuranBaris[i]; j++) {
            jagged[i][j] = (i + 1) * 10 + j;
        }
    }

    for (int i = 0; i < baris; i++) {
        cout << "  baris[" << i << "] (" << ukuranBaris[i] << " elemen): ";
        for (int j = 0; j < ukuranBaris[i]; j++) {
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < baris; i++) delete[] jagged[i];
    delete[] jagged;
}

int main() {

    // -------------------------------------------------------
    // PENDEKATAN 1: POINTER-TO-POINTER
    // -------------------------------------------------------
    cout << "=== Pendekatan 1: Pointer-to-Pointer (int**) ===" << endl;
    {
        int baris = 3, kolom = 4;
        int** m = buatMatriks(baris, kolom);

        // Isi dengan nilai berbasis indeks
        int val = 1;
        for (int i = 0; i < baris; i++)
            for (int j = 0; j < kolom; j++)
                m[i][j] = val++;

        cetakMatriks(m, baris, kolom, "Matriks 3x4");

        // Modifikasi
        m[1][2] = 999;
        cout << "  setelah m[1][2] = 999:" << endl;
        cetakMatriks(m, baris, kolom);

        hapusMatriks(m, baris);
    }

    // -------------------------------------------------------
    // OPERASI MATRIKS
    // -------------------------------------------------------
    cout << "\n=== Operasi Matriks ===" << endl;
    {
        int n = 3;
        int** a = buatMatriks(n, n);
        int** b = buatMatriks(n, n);

        // Isi a dan b
        int nilaiA[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
        int nilaiB[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                a[i][j] = nilaiA[i][j];
                b[i][j] = nilaiB[i][j];
            }

        cetakMatriks(a, n, n, "A");
        cetakMatriks(b, n, n, "B");

        int** jumlah = penjumlahanMatriks(a, b, n, n);
        cetakMatriks(jumlah, n, n, "A + B");

        int** kali = perkalianMatriks(a, b, n, n, n);
        cetakMatriks(kali, n, n, "A x B");

        int** transA = transposeMatriks(a, n, n);
        cetakMatriks(transA, n, n, "Transpose A");

        hapusMatriks(a, n);
        hapusMatriks(b, n);
        hapusMatriks(jumlah, n);
        hapusMatriks(kali, n);
        hapusMatriks(transA, n);
    }

    // -------------------------------------------------------
    // MATRIKS IDENTITAS
    // -------------------------------------------------------
    cout << "\n=== Matriks Identitas 4x4 ===" << endl;
    {
        int n = 4;
        int** id = buatMatriks(n, n);
        isiIdentitas(id, n);
        cetakMatriks(id, n, n);
        hapusMatriks(id, n);
    }

    // -------------------------------------------------------
    // PENDEKATAN 2: ARRAY 1D (CACHE-FRIENDLY)
    // -------------------------------------------------------
    cout << "\n=== Pendekatan 2: Array 1D (Cache-Friendly) ===" << endl;
    {
        int baris = 3, kolom = 4;
        int* m = buatMatriks1D(baris, kolom);
        isiNilai1D(m, baris, kolom);

        cetakMatriks1D(m, baris, kolom, "Matriks 3x4 (array 1D)");

        // Akses elemen [1][2]
        int i = 1, j = 2;
        cout << "  m[1][2] = m[" << i * kolom + j << "] = "
             << m[i * kolom + j] << endl;

        // Modifikasi
        m[0 * kolom + 3] = 777;
        cout << "  setelah m[0][3] = 777:" << endl;
        cetakMatriks1D(m, baris, kolom);

        delete[] m;   // satu delete saja!
    }

    // -------------------------------------------------------
    // JAGGED ARRAY
    // -------------------------------------------------------
    demo_jagged_array();

    // -------------------------------------------------------
    // PERBANDINGAN DUA PENDEKATAN
    // -------------------------------------------------------
    cout << "\n=== Perbandingan Dua Pendekatan ===" << endl;
    cout << "  int**  (pointer-to-pointer):" << endl;
    cout << "    + Akses natural: m[i][j]" << endl;
    cout << "    + Bisa jagged array (ukuran baris beda)" << endl;
    cout << "    - Baris tidak berkesinambungan di memory" << endl;
    cout << "    - Dealokasi kompleks (loop + delete[])" << endl;
    cout << "  int*   (array 1D diperlakukan 2D):" << endl;
    cout << "    + Satu blok berkesinambungan (cache-friendly)" << endl;
    cout << "    + Dealokasi mudah (satu delete[])" << endl;
    cout << "    - Akses verbose: m[i*kolom + j]" << endl;
    cout << "    - Ukuran kolom harus seragam" << endl;
    cout << "  Rekomendasi: gunakan vector<vector<int>> di kode produksi!" << endl;

    return 0;
}

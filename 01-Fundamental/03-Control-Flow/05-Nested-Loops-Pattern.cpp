#include <iostream>
#include <string>
using namespace std;

// BAGIAN 1 - ALUR EKSEKUSI & DASAR NESTED LOOP
void dasarNestedLoop() {
    cout << "\n==================== S. Nested Loops - Dasar & Alur Eksekusi ====================" << endl;

    // ── Visualisasi Alur Eksekusi ─────────────────────────────
        cout << "\n1. Visualisasi Alur Eksekusi Nested Loop (2x3)" << endl;
        cout << "   Format: [outer=i, inner=j]" << endl;
        cout << "   ";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "[i=" << i << ",j=" << j << "] ";
            }
        }
        cout << endl;
        cout << "   Total iterasi: 2 x 3 = 6" << endl;

    // ── Grid Koordinat ────────────────────────────────────────
        cout << "\n2. Grid Koordinat 4x5" << endl;
        cout << "   (baris i, kolom j):" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "   ";
            for (int j = 0; j < 5; j++) {
                cout << "(" << i << "," << j << ") ";
            }
            cout << endl;
        }

    // ── Inner loop selesai dulu, baru outer naik ──────────────
        cout << "\n3. Prinsip: Inner loop SELESAI SEMUA sebelum outer naik" << endl;
        cout << "   Urutan: ";
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                cout << i << j << " ";
            }
        }
        cout << endl;
        cout << "   -> 11 12 13 | 21 22 23 | 31 32 33" << endl;
}


// BAGIAN 2 - POLA PERSEGI
void polaPersegi() {
    cout << "\n\n==================== Pola Persegi ====================" << endl;
    const int N = 5;

    // ── Persegi Padat ─────────────────────────────────────────
        cout << "\n1. Persegi Padat " << N << "x" << N << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N; j++) {
                cout << "* ";
            }
            cout << endl;
        }

    // ── Persegi Berongga ──────────────────────────────────────
        cout << "\n2. Persegi Berongga " << N << "x" << N << endl;
        cout << "   Cetak * hanya di tepi: baris 0, baris N-1, kolom 0, kolom N-1" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N; j++) {
                // Tepi: baris pertama, baris terakhir, kolom pertama, kolom terakhir
                bool tepi = (i == 0) || (i == N-1) || (j == 0) || (j == N-1);
                cout << (tepi ? "* " : "  ");
            }
            cout << endl;
        }

    // ── Persegi Angka ─────────────────────────────────────────
        cout << "\n3. Persegi Angka (nilai = ixN + j + 1)" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N; j++) {
                cout.width(3);
                cout << (i * N + j + 1);
            }
            cout << endl;
        }
}


// BAGIAN 3 - POLA SEGITIGA
void polaSegitiga() {
    cout << "\n\n==================== Pola Segitiga ====================" << endl;
    const int N = 5;

    // ── Segitiga Kiri (bertambah) ─────────────────────────────
        cout << "\n1. Segitiga Kiri (j <= i)" << endl;
        cout << "   Baris ke-i -> cetak (i+1) bintang" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j <= i; j++) {   // j sampai i -> makin banyak
                cout << "* ";
            }
            cout << endl;
        }

    // ── Segitiga Terbalik ────────────────────────────────────
        cout << "\n2. Segitiga Terbalik (j < N-i)" << endl;
        cout << "   Baris ke-i -> cetak (N-i) bintang" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N - i; j++) {   // makin sedikit
                cout << "* ";
            }
            cout << endl;
        }

    // ── Segitiga Rata Kanan ───────────────────────────────────
        cout << "\n3. Segitiga Rata Kanan" << endl;
        cout << "   Spasi: (N-1-i), Bintang: (i+1)" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N - 1 - i; j++) {   // spasi di kiri
                cout << "  ";
            }
            for (int j = 0; j <= i; j++) {            // bintang di kanan
                cout << "* ";
            }
            cout << endl;
        }

    // ── Segitiga Terbalik Rata Kanan ──────────────────────────
        cout << "\n4. Segitiga Terbalik Rata Kanan" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < i; j++) {          // spasi bertambah
                cout << "  ";
            }
            for (int j = 0; j < N - i; j++) {      // bintang berkurang
                cout << "* ";
            }
            cout << endl;
        }
}


// BAGIAN 4 - POLA PIRAMIDA
void polaPiramida() {
    cout << "\n\n==================== Pola Piramida ====================" << endl;
    const int N = 5;

    // ── Piramida Normal ───────────────────────────────────────
        cout << "\n1. Piramida Normal (tengah)" << endl;
        cout << "   Baris i: spasi=(N-1-i), bintang=(2i+1)" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < N - 1 - i; j++) cout << " ";   // spasi kiri
            for (int j = 0; j < 2 * i + 1; j++) cout << "*";   // bintang
            cout << endl;
        }

    // ── Piramida Terbalik ────────────────────────────────────
        cout << "\n2. Piramida Terbalik" << endl;
        cout << "   Baris i: spasi=i, bintang=(2*(N-1-i)+1)" << endl;
        for (int i = 0; i < N; i++) {
            cout << "   ";
            for (int j = 0; j < i; j++) cout << " ";               // spasi bertambah
            for (int j = 0; j < 2 * (N - 1 - i) + 1; j++) cout << "*";  // bintang berkurang
            cout << endl;
        }

    // ── Diamond ───────────────────────────────────────────────
        cout << "\n3. Diamond (Berlian)" << endl;
        cout << "   Gabungan: piramida normal + piramida terbalik" << endl;

        // Bagian atas (termasuk baris tengah)
            for (int i = 0; i < N; i++) {
                cout << "   ";
                for (int j = 0; j < N - 1 - i; j++) cout << " ";
                for (int j = 0; j < 2 * i + 1; j++) cout << "*";
                cout << endl;
            }
            
        // Bagian bawah (tidak termasuk baris tengah)
            for (int i = N - 2; i >= 0; i--) {
                cout << "   ";
                for (int j = 0; j < N - 1 - i; j++) cout << " ";
                for (int j = 0; j < 2 * i + 1; j++) cout << "*";
                cout << endl;
            }
}


// BAGIAN 5 - POLA ANGKA
void polaAngka() {
    cout << "\n\n==================== Pola Angka ====================" << endl;
    const int N = 5;

    // ── Segitiga Angka Berulang ───────────────────────────────
        cout << "\n1. Segitiga Angka Berulang (j pada tiap baris)" << endl;
        for (int i = 1; i <= N; i++) {
            cout << "   ";
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << endl;
        }

    // ── Segitiga Angka Urut (Floyd's Triangle) ───────────────
        cout << "\n2. Floyd's Triangle (angka urut terus)" << endl;
        int angka = 1;
        for (int i = 1; i <= N; i++) {
            cout << "   ";
            for (int j = 1; j <= i; j++) {
                cout.width(3);
                cout << angka++;
            }
            cout << endl;
        }

    // ── Segitiga Angka Sama Tiap Baris ───────────────────────
        cout << "\n3. Segitiga Angka Sama (nomor baris)" << endl;
        for (int i = 1; i <= N; i++) {
            cout << "   ";
            for (int j = 1; j <= i; j++) {
                cout << i << " ";   // semua isi di baris ke-i adalah i
            }
            cout << endl;
        }

    // ── Tabel Perkalian ───────────────────────────────────────
        cout << "\n4. Tabel Perkalian " << N << "x" << N << endl;
        cout << "      ";
        for (int j = 1; j <= N; j++) { cout.width(4); cout << j; }
        cout << endl;
        cout << "   +";
        for (int j = 0; j <= N; j++) cout << "----";
        cout << endl;

        for (int i = 1; i <= N; i++) {
            cout << "   | " << i << " |";
            for (int j = 1; j <= N; j++) {
                cout.width(3);
                cout << i * j << " ";
            }
            cout << endl;
        }

    // ── Segitiga Pascal ───────────────────────────────────────
        cout << "\n5. Segitiga Pascal (5 baris)" << endl;
        int pascal[6][6] = {};
        pascal[0][0] = 1;
        for (int i = 1; i < 6; i++) {
            pascal[i][0] = 1;
            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
            pascal[i][i] = 1;
        }

        for (int i = 0; i < 6; i++) {
            cout << "   ";
            for (int sp = 0; sp < 5 - i; sp++) cout << "  ";  // spasi tengah
            for (int j = 0; j <= i; j++) {
                cout.width(4);
                cout << pascal[i][j];
            }
            cout << endl;
        }
}


// BAGIAN 6 - POLA LANJUTAN
void polaLanjutan() {
    cout << "\n\n==================== Pola Lanjutan ====================" << endl;
    const int N = 5;

    // ── Jam Pasir (Hourglass) ─────────────────────────────────
            cout << "\n1. Jam Pasir (Hourglass)" << endl;
            cout << "   Bagian atas (terbalik) + bawah (normal):" << endl;

        // Bagian atas - piramida terbalik
            for (int i = 0; i < N; i++) {
                cout << "   ";
                for (int j = 0; j < i; j++) cout << " ";
                for (int j = 0; j < N - i; j++) cout << "* ";
                cout << endl;
            }
        // Bagian bawah - piramida normal (skip baris pertama)
            for (int i = 1; i < N; i++) {
                cout << "   ";
                for (int j = 0; j < N - 1 - i; j++) cout << " ";
                for (int j = 0; j <= i; j++) cout << "* ";
                cout << endl;
            }

    // ── Kupu-kupu (Butterfly) ─────────────────────────────────
        cout << "\n2. Kupu-kupu (Butterfly)" << endl;
        // Setengah atas
            for (int i = 1; i <= N; i++) {
                cout << "   ";
                for (int j = 1; j <= i; j++) cout << "*";
                for (int j = 0; j < 2 * (N - i); j++) cout << " ";
                for (int j = 1; j <= i; j++) cout << "*";
                cout << endl;
        }

        // Setengah bawah
            for (int i = N - 1; i >= 1; i--) {
                cout << "   ";
                for (int j = 1; j <= i; j++) cout << "*";
                for (int j = 0; j < 2 * (N - i); j++) cout << " ";
                for (int j = 1; j <= i; j++) cout << "*";
                cout << endl;
            }

        // ── Papan Catur ───────────────────────────────────────────
            cout << "\n3. Papan Catur 6x6" << endl;
            for (int i = 0; i < 6; i++) {
                cout << "   ";
                for (int j = 0; j < 6; j++) {
                    // Genap/ganjil berdasarkan (i+j)
                    cout << ((i + j) % 2 == 0 ? "## " : ".. ");
                }
                cout << endl;
            }
}


// PANDUAN CARA BERPIKIR
void caraBerpikir() {
    cout << "\n\n==================== Cara Berpikir Merancang Pola Baru ====================" << endl;

    cout << R"(
        LANGKAH-LANGKAH:

        1. Gambar pola di kertas (minimal 5 baris)
            Contoh target:
                *
                * *
                * * *
                * * * *
                * * * * *

        2. Buat tabel: untuk tiap baris i (mulai 0 atau 1), ada berapa apa?
            +------+---------------------------------------+
            | i    | Isi                                   |
            +------+---------------------------------------+
            |  0   | 1 bintang                             |
            |  1   | 2 bintang                             |
            |  2   | 3 bintang                             |
            |  3   | 4 bintang                             |
            |  4   | 5 bintang                             |
            +------+---------------------------------------+

        3. Temukan rumus: jumlah bintang = i + 1  -> j <= i

        4. Terjemahkan ke loop:
            for (int i = 0; i < N; i++) {        <- N baris
                for (int j = 0; j <= i; j++) {   <- j <= i = bertambah
                    cout << "* ";
                }
                cout << endl;
            }

        5. Untuk pola yang butuh spasi (piramida tengah):
            Tabel dua kolom: spasi | bintang
            +------+--------------------+-------------------+
            | i    | spasi (N-1-i)      | bintang (2i+1)    |
            +------+--------------------+-------------------+
            |  0   | 4                  | 1                 |
            |  1   | 3                  | 3                 |
            |  2   | 2                  | 5                 |
            |  3   | 1                  | 7                 |
            |  4   | 0                  | 9                 |
            +------+--------------------+-------------------+

        TIPS CEPAT:
        -> Bertambah kanan      : j <= i
        -> Berkurang kanan      : j < N - i
        -> Spasi kiri piramida  : j < N - 1 - i
        -> Tepi persegi         : i==0 || i==N-1 || j==0 || j==N-1
        -> Papan catur          : (i+j) % 2 == 0
        -> Diagonal             : i == j  atau  i+j == N-1
    )";

    cout << "\n  Kompleksitas:" << endl;
    cout << "   Nested 2 loop -> O(n2) - masih OK untuk n kecil" << endl;
    cout << "   Nested 3 loop -> O(n3) - mulai berat untuk n > 100" << endl;
    cout << "   Jangan pakai nested loop untuk data besar (ribuan/jutaan elemen)!" << endl;
}


int main(){

    dasarNestedLoop();
    polaPersegi();
    polaSegitiga();
    polaPiramida();
    polaAngka();
    polaLanjutan();
    caraBerpikir();

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

void breakStatement() {
    cout << "\n==================== Break Statement ====================" << endl;

    // ── 1. Break Dasar ────────────────────────────────────────
        cout << "\n1. Break Dasar - Loop Berhenti Sebelum Selesai" << endl;
        {
            cout << "   Loop 1-10, berhenti saat i==5:" << endl;
            cout << "   Output: ";
            for (int i = 1; i <= 10; i++) {
                if (i == 5) {
                    cout << "[STOP]";
                    break;   // keluar dari loop - i=6..10 tidak diproses
                }
                cout << i << " ";
            }
            cout << endl;
            cout << "   -> Setelah break, program lanjut ke kode SETELAH loop." << endl;
        }

    // ── 2. Break dalam while ──────────────────────────────────
        cout << "\n2. Break dalam While Loop" << endl;
        {
            int  angka = 1;
            int  batas = 50;
            int  total = 0;

            cout << "   Jumlahkan angka, berhenti kalau total >= " << batas << ":" << endl;
            while (true) {   // infinite loop - keluar dengan break
                total += angka;
                if (total >= batas) {
                    cout << "   Total mencapai " << total << " setelah menambahkan angka ke-" << angka << endl;
                    break;
                }
                angka++;
            }
        }

    // ── 3. Break - Linear Search (Early Exit) ────────────────
        cout << "\n3. Break - Linear Search dengan Early Exit" << endl;
        {
            int  arr[]    = {14, 7, 33, 56, 2, 89, 41};
            int  ukuran   = sizeof(arr) / sizeof(arr[0]);
            int  target   = 56;
            bool ditemukan = false;
            int  posisi   = -1;

            cout << "   Array: ";
            for (int x : arr) cout << x << " ";
            cout << endl;
            cout << "   Mencari " << target << ":" << endl;

            for (int i = 0; i < ukuran; i++) {
                cout << "   -> Cek index [" << i << "] = " << arr[i];
                if (arr[i] == target) {
                    ditemukan = true;
                    posisi    = i;
                    cout << " <- KETEMU! Break." << endl;
                    break;   // tidak perlu cek sisanya
                }
                cout << " (bukan)" << endl;
            }

            if (ditemukan) {
                cout << "   Hasil: " << target << " ada di index [" << posisi << "]" << endl;
            } else {
                cout << "   Hasil: " << target << " tidak ditemukan." << endl;
            }
        }

    // ── 4. Break dalam Switch ─────────────────────────────────
        cout << "\n4. Break dalam Switch (Sudah dibahas di 02-Switch-Case)" << endl;
        {
            int pilihan = 2;
            cout << "   pilihan = " << pilihan << endl;
            switch (pilihan) {
                case 1: cout << "   -> Case 1" << endl; break;
                case 2: cout << "   -> Case 2 - break berhentikan switch, lanjut ke kode berikutnya" << endl; break;
                case 3: cout << "   -> Case 3" << endl; break;
            }
            cout << "   -> Kode ini dijalankan setelah switch selesai." << endl;
        }

    // ── 5. Break di Nested Loop - Hanya Keluar Satu Level ─────
        cout << "\n5. Break di Nested Loop - Hanya Keluar dari Loop Terdekat" << endl;
        {
            cout << "   Grid 3x5, break inner saat j==3:" << endl;
            for (int i = 0; i < 3; i++) {   // outer loop: tidak dipengaruhi break inner
                cout << "   Baris " << i << ": ";
                for (int j = 0; j < 5; j++) {   // inner loop
                    if (j == 3) {
                        cout << "[break] ";
                        break;   // keluar dari inner loop SAJA, outer tetap jalan
                    }
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << "   -> Outer loop tetap jalan 3 kali - break hanya affect inner!" << endl;
        }
}

void continueStatement() {
    cout << "\n\n==================== Continue Statement ====================" << endl;

    // ── 1. Continue Dasar ─────────────────────────────────────
        cout << "\n1. Continue Dasar - Skip Iterasi Tertentu" << endl;
        {
            cout << "   Angka 1-10, skip yang genap:" << endl;
            cout << "   Output: ";
            for (int i = 1; i <= 10; i++) {
                if (i % 2 == 0) {
                    continue;   // skip kode di bawah, langsung ke i++
                }
                cout << i << " ";   // hanya angka ganjil yang sampai sini
            }
            cout << endl;
        }

    // ── 2. Continue - Filter Data Invalid ────────────────────
        cout << "\n2. Continue - Filter Data Tidak Valid" << endl;
        {
            int data[]  = {85, -1, 90, 150, 78, -5, 92, 101, 65};
            int ukuran  = sizeof(data) / sizeof(data[0]);
            int jumlah  = 0;
            int hitungan = 0;

            cout << "   Data mentah: ";
            for (int d : data) cout << d << " ";
            cout << endl;

            cout << "   Proses (nilai valid 0-100):" << endl;
            for (int i = 0; i < ukuran; i++) {
                if (data[i] < 0 || data[i] > 100) {
                    cout << "   -> [" << i << "] = " << data[i] << " <- SKIP (tidak valid)" << endl;
                    continue;   // skip, tidak masuk akumulasi
                }
                jumlah   += data[i];
                hitungan++;
                cout << "   -> [" << i << "] = " << data[i] << " <- diproses " << endl;
            }

            cout << "   Jumlah data valid: " << hitungan << endl;
            cout << "   Rata-rata        : " << (hitungan > 0 ? (double)jumlah/hitungan : 0) << endl;
        }

    // ── 3. Continue - Perbedaan di for vs while ───────────────
        cout << "\n3. Continue di for vs while - Perbedaan Alur" << endl;
        {
            cout << "   for loop, continue di i==3:" << endl;
            cout << "   Output: ";
            for (int i = 1; i <= 5; i++) {
                if (i == 3) {
                    continue;   // langsung ke i++ -> i jadi 4, lalu cek kondisi
                }
                cout << i << " ";
            }
            cout << endl;
            cout << "   -> i++ tetap dijalankan setelah continue, loop tidak stuck." << endl;

            cout << "\n   while loop, continue di i==3:" << endl;
            cout << "   Output: ";
            int i = 0;
            while (i < 5) {
                i++;          // update HARUS sebelum continue! Kalau sesudah -> infinite loop
                if (i == 3) {
                    continue;   // langsung ke cek kondisi (i<5)
                }
                cout << i << " ";
            }
            cout << endl;
            cout << "   Di while, pastikan update (i++) ada SEBELUM continue!" << endl;
        }

    // ── 4. Continue - Cetak Kelipatan ─────────────────────────
        cout << "\n4. Continue - Cetak Bukan Kelipatan 3" << endl;
        {
            cout << "   1-20, skip kelipatan 3: ";
            for (int i = 1; i <= 20; i++) {
                if (i % 3 == 0) continue;
                cout << i << " ";
            }
            cout << endl;
        }
}

void breakVsContinue() {
    cout << "\n\n==================== Break vs Continue - Perbandingan ====================" << endl;

    cout << R"(
        +------------+----------------------------+----------------------------+
        | Aspek      | break                      | continue                   |
        +------------+----------------------------+----------------------------+
        | Efek       | HENTIKAN loop sepenuhnya   | SKIP iterasi ini saja      |
        | Loop       | Berhenti, tidak lanjut     | Tetap jalan, iterasi next  |
        | Sisa kode  | Tidak dieksekusi (loop end)| Tidak (iterasi ini saja)   |
        | Analogi    | Keluar dari gedung         | Skip 1 lantai, lanjut naik |
        | Use case   | Ketemu target, error fatal | Skip data rusak, filter    |
        +------------+----------------------------+----------------------------+
    )";

    // Demo langsung berdampingan
        cout << "   Demo berdampingan (loop 1-5):\n" << endl;
        cout << "   BREAK  di i==3: ";
        for (int i = 1; i <= 5; i++) {
            if (i == 3) { cout << "[STOP] "; break; }
            cout << i << " ";
        }
        cout << "<- loop berhenti total\n" << endl;

        cout << "   CONTINUE di i==3: ";
        for (int i = 1; i <= 5; i++) {
            if (i == 3) { cout << "[SKIP] "; continue; }
            cout << i << " ";
        }
        cout << "<- loop tetap jalan sampai selesai" << endl;
}

bool cariDiMatrix(int matrix[][4], int baris, int kolom, int target) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matrix[i][j] == target) {
                cout << "   Ditemukan di [" << i << "][" << j << "]" << endl;
                return true;   // keluar dari SEMUA loop sekaligus
            }
        }
    }
    return false;
}

void keluarNestedLoop() {
    cout << "\n\n==================== Keluar dari Nested Loop ====================" << endl;

    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    int target = 7;

    cout << "\n   Matrix 3x4:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   ";
        for (int j = 0; j < 4; j++) {
            cout.width(3);
            cout << matrix[i][j];
        }
        cout << endl;
    }

    // Cara 1: Boolean flag
        cout << "\n   Cara 1 - Boolean Flag (cari " << target << "):" << endl;
        bool ketemu = false;
        for (int i = 0; i < 3 && !ketemu; i++) {       // cek flag di kondisi outer
            for (int j = 0; j < 4 && !ketemu; j++) {   // cek flag di kondisi inner
                if (matrix[i][j] == target) {
                    cout << "   Ditemukan di [" << i << "][" << j << "]" << endl;
                    ketemu = true;   // set flag -> kedua loop berhenti
                }
            }
        }

    // Cara 2: Pakai fungsi + return (TERBAIK)
        cout << "\n   Cara 2 - Fungsi + return (cari " << target << "):" << endl;
        bool hasil = cariDiMatrix(matrix, 3, 4, target);
        cout << "   Hasil: " << (hasil ? "Ditemukan" : "Tidak Ditemukan") << endl;

        cout << "\n   -> Cara 2 (return) lebih bersih dan direkomendasikan!" << endl;
}

void gotoWarning() {
    cout << "\n\n==================== goto - Kenapa JANGAN Dipakai ====================" << endl;

    cout << R"(
        CONTOH MASALAH DENGAN GOTO:

        // CARA BURUK - sulit dibaca dan di-debug
        int i = 0;
        mulai:
            if (i >= 5) goto selesai;
            cout << i;
            i++;
            goto mulai;
        selesai:
            cout << "Done";

        // CARA BAIK - jelas, mudah dibaca
        for (int i = 0; i < 5; i++) {
            cout << i;
        }
        cout << "Done";

        ALTERNATIF UNTUK SETIAP KASUS GOTO:
        +--------------------------+------------------------------+
        | Tujuan goto              | Alternatif yang benar        |
        +--------------------------+------------------------------+
        | Keluar dari loop         | break                        |
        | Skip iterasi             | continue                     |
        | Keluar dari fungsi       | return                       |
        | Keluar dari nested loop  | flag bool / return           |
        | Error handling           | throw / try-catch            |
        +--------------------------+------------------------------+

        "goto adalah tanda bahwa struktur kode kita perlu diperbaiki."
    )";

    // Satu-satunya kasus goto yang "diterima" oleh komunitas C++:
        cout << "   Catatan: satu-satunya penggunaan goto yang kadang diterima" << endl;
        cout << "   adalah keluar dari DEEPLY nested loop (3+ level)." << endl;
        cout << "   Tapi bahkan untuk ini, lebih baik refactor ke fungsi + return." << endl;
}


int main(){

    breakStatement();
    continueStatement();
    breakVsContinue();
    keluarNestedLoop();
    gotoWarning();

    return 0;
}
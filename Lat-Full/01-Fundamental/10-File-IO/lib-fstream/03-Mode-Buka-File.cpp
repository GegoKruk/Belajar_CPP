#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bacaFile(const string& nama) {
    ifstream f(nama);
    if (!f.is_open()) { cout << "  (file tidak ada)" << endl; return; }
    string b;
    while (getline(f, b)) cout << "  | " << b << endl;
}

int main() {

    // ----- 1. ios::out (default ofstream, overwrite) -----
        cout << "=== 1. ios::out - Overwrite ===" << endl;

        ofstream f1("03_out.txt");
        f1 << "Tulis pertama - baris A" << endl;
        f1 << "Tulis pertama - baris B" << endl;
        f1.close();
        cout << "Setelah tulis pertama:" << endl;
        bacaFile("03_out.txt");

        ofstream f1b("03_out.txt");  // buka lagi -> overwrite
        f1b << "Overwrite - isi lama hilang!" << endl;
        f1b.close();
        cout << "Setelah OVERWRITE:" << endl;
        bacaFile("03_out.txt");


    // ----- 2. ios::app (append) -----
        cout << endl << "=== 2. ios::app - Append ===" << endl;

        ofstream f2a("03_app.txt");
        f2a << "Baris asli 1" << endl;
        f2a << "Baris asli 2" << endl;
        f2a.close();
        cout << "File awal:" << endl;
        bacaFile("03_app.txt");

        ofstream f2b("03_app.txt", ios::app);
        f2b << "Baris ditambah (append)" << endl;
        f2b << "Baris ditambah lagi" << endl;
        f2b.close();
        cout << "Setelah APPEND:" << endl;
        bacaFile("03_app.txt");

        // Append lagi
            ofstream f2c("03_app.txt", ios::app);
            f2c << "Append ketiga" << endl;
            f2c.close();
            cout << "Setelah APPEND kedua kali:" << endl;
            bacaFile("03_app.txt");


    // ----- 3. ios::in (baca saja) -----
        cout << endl << "=== 3. ios::in - Baca Saja ===" << endl;

        // Siapkan file dulu
            ofstream fPrep("03_in.txt");
            fPrep << "Data untuk dibaca" << endl;
            fPrep.close();

            ifstream f3("03_in.txt", ios::in);
            if (!f3.is_open()) {
                cout << "File tidak ditemukan!" << endl;
            } else {
                string b;
                getline(f3, b);
                cout << "Berhasil baca: " << b << endl;
                f3.close();
            }

        // Coba buka file yang tidak ada
            ifstream f3b("tidak_ada.txt");
            if (!f3b.is_open()) {
                cout << "File 'tidak_ada.txt' tidak ditemukan (is_open = false)" << endl;
            }


    // ----- 4. ios::in | ios::out (baca dan tulis) -----
        cout << endl << "=== 4. ios::in | ios::out (Baca + Tulis) ===" << endl;

        // Buat file dulu - fstream dengan in|out butuh file SUDAH ADA
        ofstream fPrep2("03_inout.txt");
        fPrep2 << "Baris satu\nBaris dua\nBaris tiga\n";
        fPrep2.close();

        fstream f4("03_inout.txt", ios::in | ios::out);
        if (!f4.is_open()) {
            cerr << "Gagal buka!" << endl;
        } else {
            // Baca dulu
            cout << "Isi awal:" << endl;
            string b;
            while (getline(f4, b)) cout << "  " << b << endl;

            // Pindah ke akhir dan tulis
            f4.clear();
            f4.seekp(0, ios::end);
            f4 << "Baris tambahan" << endl;
            f4.close();

            cout << "Setelah tambah baris:" << endl;
            bacaFile("03_inout.txt");
        }


    // ----- 5. ios::in | ios::out | ios::trunc -----
        cout << endl << "=== 5. ios::in | ios::out | ios::trunc ===" << endl;

        // Siapkan file berisi
        ofstream fPrep3("03_trunc.txt");
        fPrep3 << "Ini akan dihapus\nBaris lama lainnya\n";
        fPrep3.close();
        cout << "Sebelum trunc:" << endl;
        bacaFile("03_trunc.txt");

        fstream f5("03_trunc.txt", ios::in | ios::out | ios::trunc);
        f5 << "File baru setelah trunc" << endl;
        f5.close();
        cout << "Setelah trunc:" << endl;
        bacaFile("03_trunc.txt");


    // ----- 6. Ringkasan Mode -----
        cout << endl << "=== 6. Ringkasan Mode ===" << endl;
        cout << "Mode                        | Efek" << endl;
        cout << "----------------------------+------------------------------" << endl;
        cout << "ios::out (default ofstream) | Tulis, overwrite isi lama" << endl;
        cout << "ios::app                    | Tulis, tambah di akhir" << endl;
        cout << "ios::in  (default ifstream) | Baca saja" << endl;
        cout << "ios::in | ios::out          | Baca + tulis (file harus ada)" << endl;
        cout << "ios::in | ios::out|ios::trunc | Baca+tulis, hapus dulu" << endl;
        cout << "ios::binary                 | Mode biner (non-teks)" << endl;

    // Cleanup
        remove("03_out.txt");
        remove("03_app.txt");
        remove("03_in.txt");
        remove("03_inout.txt");
        remove("03_trunc.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

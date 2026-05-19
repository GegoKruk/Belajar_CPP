#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    // ----- 1. Menulis Teks Dasar -----
        cout << "=== 1. Menulis Teks Dasar ===" << endl;

        ofstream f1("01_dasar.txt");
        if (!f1.is_open()) {
            cerr << "Gagal membuat file!" << endl;
            return 1;
        }

        f1 << "Halo, ini baris pertama!" << endl;
        f1 << "Ini baris kedua." << endl;
        f1 << "Angka bulat : " << 42 << endl;
        f1 << "Angka desimal: " << 3.14 << endl;
        f1 << "Boolean : " << true << endl;
        f1.close();

        cout << "File '01_dasar.txt' berhasil dibuat." << endl;

        // Verifikasi dengan membaca kembali
            ifstream cek1("01_dasar.txt");
            string baris;
            cout << "Isi file:" << endl;
            while (getline(cek1, baris)) cout << "  " << baris << endl;
            cek1.close();


    // ----- 2. Menulis dengan Format (iomanip) -----
        cout << endl << "=== 2. Menulis dengan Format ===" << endl;

        ofstream f2("01_format.txt");
        if (!f2) {
            cerr << "Gagal!" << endl;
            return 1;
        }

        // Header tabel
        f2 << "=== Laporan Nilai Mahasiswa ===" << endl;
        f2 << left  << setw(15) << "Nama"
        << right << setw(6)  << "Umur"
        << right << setw(8)  << "IPK" << endl;
        f2 << string(29, '-') << endl;

        // Data mahasiswa
        struct DataMhs { string nama; int umur; double ipk; };
        DataMhs data[] = {
            {"Budi",  20, 3.85},
            {"Sari",  21, 3.90},
            {"Andi",  19, 3.70},
            {"Dina",  22, 3.95}
        };

        f2 << fixed << setprecision(2);
        for (const auto& m : data) {
            f2 << left  << setw(15) << m.nama
            << right << setw(6)  << m.umur
            << right << setw(8)  << m.ipk << endl;
        }
        f2 << string(29, '-') << endl;
        f2.close();

        cout << "File '01_format.txt' berhasil ditulis." << endl;

        ifstream cek2("01_format.txt");
        while (getline(cek2, baris)) cout << "  " << baris << endl;
        cek2.close();


    // ----- 3. Overwrite vs Append -----
        cout << endl << "=== 3. Overwrite vs Append ===" << endl;

        // Tulis awal
            ofstream f3a("01_append.txt");
            f3a << "Baris 1 (tulis pertama)" << endl;
            f3a << "Baris 2 (tulis pertama)" << endl;
            f3a.close();
            cout << "Ditulis pertama kali." << endl;

        // Overwrite - isi lama hilang
            ofstream f3b("01_append.txt");
            f3b << "Ini overwrite - isi lama hilang!" << endl;
            f3b.close();
            cout << "Setelah OVERWRITE:" << endl;
            ifstream cek3a("01_append.txt");
            while (getline(cek3a, baris)) cout << "  " << baris << endl;
            cek3a.close();

        // Tulis ulang untuk demo append
            ofstream f3c("01_append.txt");
            f3c << "Baris asli 1" << endl;
            f3c << "Baris asli 2" << endl;
            f3c.close();

        // Append - isi lama tetap ada
            ofstream f3d("01_append.txt", ios::app);
            f3d << "Baris tambahan (append)" << endl;
            f3d << "Baris tambahan lagi" << endl;
            f3d.close();
            cout << "Setelah APPEND:" << endl;
            ifstream cek3b("01_append.txt");
            while (getline(cek3b, baris)) cout << "  " << baris << endl;
            cek3b.close();


    // ----- 4. Cara Buka dengan open() -----
        cout << endl << "=== 4. Cara Buka dengan open() ===" << endl;

        ofstream f4;
        f4.open("01_open.txt");
        if (!f4.is_open()) {
            cerr << "Gagal!" << endl;
            return 1;
        }
        f4 << "Dibuka dengan open() terpisah." << endl;
        f4.close();

        // Buka file lain dengan objek yang sama
        f4.open("01_open2.txt");
        f4 << "File kedua dengan objek yang sama." << endl;
        f4.close();

        cout << "Dua file berhasil ditulis dengan satu objek ofstream." << endl;


    // ----- 5. Cek State Setelah Operasi -----
        cout << endl << "=== 5. Cek State Penulisan ===" << endl;

        ofstream f5("01_state.txt");
        f5 << "Data penting" << endl;

        if (f5.good()) cout << "Penulisan berhasil (good)" << endl;
        if (!f5.fail()) cout << "Tidak ada kegagalan" << endl;
        f5.close();

        // Cleanup
        remove("01_dasar.txt");
        remove("01_format.txt");
        remove("01_append.txt");
        remove("01_open.txt");
        remove("01_open2.txt");
        remove("01_state.txt");
        cout << endl << "Semua file demo dihapus." << endl;

    return 0;
}

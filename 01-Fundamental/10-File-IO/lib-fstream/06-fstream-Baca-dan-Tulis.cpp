#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cetakFile(const string& nama) {
    ifstream f(nama);
    string b;
    int no = 0;
    while (getline(f, b)) cout << "  [" << ++no << "] " << b << endl;
}

int main() {

    // ----- 1. fstream Dasar: Tulis lalu Baca -----
        cout << "=== 1. fstream Dasar: Tulis lalu Baca ===" << endl;

        // Buat file baru (trunc = hapus isi lama jika ada)
            fstream f1("06_fstream.txt", ios::in | ios::out | ios::trunc);
            if (!f1.is_open()) {
                cerr << "Gagal membuka file!" << endl;
                return 1;
            }

        // Tulis data
            f1 << "Baris pertama" << endl;
            f1 << "Baris kedua" << endl;
            f1 << "Baris ketiga" << endl;
            cout << "Data ditulis." << endl;

        // Balik ke awal untuk baca
            f1.clear();
            f1.seekg(0);

        // Baca semua
            string baris;
            cout << "Isi file:" << endl;
            while (getline(f1, baris)) {
                cout << "  " << baris << endl;
            }
            f1.close();


    // ----- 2. fstream: Tambah di Akhir lalu Baca -----
        cout << endl << "=== 2. Tambah Data lalu Baca Ulang ===" << endl;

        fstream f2("06_fstream.txt", ios::in | ios::out);
        if (!f2.is_open()) { cerr << "Gagal!" << endl; return 1; }

        // Pindah kursor tulis ke akhir
            f2.seekp(0, ios::end);
            f2 << "Baris keempat (ditambah)" << endl;
            f2 << "Baris kelima (ditambah)" << endl;
            cout << "Data tambahan ditulis." << endl;

        // Baca dari awal
            f2.clear();
            f2.seekg(0);
            cout << "Isi file setelah penambahan:" << endl;
            while (getline(f2, baris)) {
                cout << "  " << baris << endl;
            }
            f2.close();


    // ----- 3. fstream: Update Record di Tengah File -----
        cout << endl << "=== 3. Update Record di Posisi Tertentu ===" << endl;

        // File berisi string dengan panjang tetap (untuk update posisi)
        fstream f3("06_record.txt", ios::in | ios::out | ios::trunc);
        // Tiap baris punya panjang sama: 10 karakter + newline
        f3 << "Record 000" << endl;   // 11 byte (10 + newline)
        f3 << "Record 001" << endl;
        f3 << "Record 002" << endl;
        cout << "File awal:" << endl;
        cetakFile("06_record.txt");

        // Update record ke-2 (index 1, posisi byte 11 * 1 = 11)
            f3.clear();
            f3.seekp(11);   // skip baris pertama (11 byte)
            f3 << "Record XXX";   // overwrite tanpa endl
            f3.flush();

            cout << "Setelah update record ke-2:" << endl;
            f3.clear();
            f3.seekg(0);
            while (getline(f3, baris)) cout << "  " << baris << endl;
            f3.close();


    // ----- 4. fstream: Baca Dua Bagian Berbeda -----
        cout << endl << "=== 4. Baca Dua Posisi Berbeda ===" << endl;

        // Tulis file isi 20 karakter
            ofstream fw("06_dua.txt");
            fw << "ABCDEFGHIJ1234567890";
            fw.close();

            fstream f4("06_dua.txt", ios::in | ios::out);

        // Baca 5 karakter dari posisi 0
            f4.seekg(0);
            char buf1[6] = {0};
            f4.read(buf1, 5);
            cout << "5 karakter pertama: '" << buf1 << "'" << endl;

        // Baca 5 karakter dari posisi 10
            f4.seekg(10);
            char buf2[6] = {0};
            f4.read(buf2, 5);
            cout << "5 karakter mulai posisi 10: '" << buf2 << "'" << endl;

            f4.close();


    // ----- 5. Perbandingan fstream vs ifstream + ofstream -----
        cout << endl << "=== 5. fstream vs ifstream + ofstream ===" << endl;

        cout << "fstream (satu objek):" << endl;
        cout << "  + Satu objek untuk baca + tulis" << endl;
        cout << "  + Bisa seekg/seekp bolak-balik" << endl;
        cout << "  - Harus tentukan mode secara eksplisit" << endl;
        cout << "  - Lebih mudah salah (lupa seekg/seekp)" << endl;

        cout << endl << "ifstream + ofstream (terpisah):" << endl;
        cout << "  + Niat lebih jelas (baca = ifstream, tulis = ofstream)" << endl;
        cout << "  + Lebih sedikit chance error" << endl;
        cout << "  - Tidak bisa pakai satu objek untuk dua operasi" << endl;

        cout << endl << "Rekomendasi:" << endl;
        cout << "  Hanya baca     -> ifstream" << endl;
        cout << "  Hanya tulis    -> ofstream" << endl;
        cout << "  Baca + tulis   -> fstream (dengan mode eksplisit)" << endl;

    // Cleanup
        remove("06_fstream.txt");
        remove("06_record.txt");
        remove("06_dua.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

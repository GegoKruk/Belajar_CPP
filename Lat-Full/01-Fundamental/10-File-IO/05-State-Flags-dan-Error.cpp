#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void cetakState(const string& label, ifstream& f) {
    cout << label << ": "
         << "good=" << f.good() << " "
         << "eof="  << f.eof()  << " "
         << "fail=" << f.fail() << " "
         << "bad="  << f.bad()  << endl;
}

int main() {

    // ----- 1. State Awal dan Setelah Baca -----
        cout << "=== 1. State Flags ===" << endl;

        ofstream fw("05_state.txt");
        fw << "Halo dunia\n42\n";
        fw.close();

        ifstream f1("05_state.txt");

        cetakState("Setelah buka", f1);

        string baris;
        getline(f1, baris);
        cout << "Baca: '" << baris << "'" << endl;
        cetakState("Setelah baca baris 1", f1);

        getline(f1, baris);
        cout << "Baca: '" << baris << "'" << endl;
        cetakState("Setelah baca baris 2", f1);

        // Coba baca lagi (sudah EOF)
        getline(f1, baris);
        cetakState("Setelah baca melewati EOF", f1);
        f1.close();


    // ----- 2. State Saat File Tidak Ada -----
        cout << endl << "=== 2. State Saat File Tidak Ada ===" << endl;

        ifstream f2("file_tidak_ada.txt");
        cout << "is_open(): " << f2.is_open() << endl;
        cetakState("File tidak ada", f2);

        if (!f2) {
            cout << "Cara singkat: !f2 menunjukkan ada masalah." << endl;
        }


    // ----- 3. clear() - Reset Flag -----
        cout << endl << "=== 3. clear() - Reset Flag ===" << endl;

        ofstream fw3("05_clear.txt");
        fw3 << "baris satu\nbaris dua\n";
        fw3.close();

        ifstream f3("05_clear.txt");

        // Baca sampai habis
        while (getline(f3, baris)) {}
        cetakState("Setelah baca habis", f3);

        // Reset dan baca ulang
        f3.clear();
        f3.seekg(0);
        cetakState("Setelah clear() + seekg(0)", f3);

        int noBaris = 0;
        while (getline(f3, baris)) {
            noBaris++;
            cout << "  Baris " << noBaris << ": " << baris << endl;
        }
        f3.close();


    // ----- 4. fail() saat Format Salah -----
        cout << endl << "=== 4. fail() saat Format Salah ===" << endl;

        ofstream fw4("05_fail.txt");
        fw4 << "100\nabc\n200\n";
        fw4.close();

        ifstream f4("05_fail.txt");
        int angka;

        cout << "Coba baca angka dari file yang ada teks:" << endl;

        while (true) {
            f4 >> angka;
            if (f4.eof()) {
                cout << "  Selesai (EOF)" << endl;
                break;
            }
            if (f4.fail()) {
                cout << "  fail() aktif - gagal parse angka" << endl;
                f4.clear();      // reset flag fail
                string skip;
                f4 >> skip;      // skip token yang tidak bisa dibaca sebagai angka
                cout << "  Skip token: '" << skip << "'" << endl;
                continue;
            }
            cout << "  Berhasil baca: " << angka << endl;
        }
        f4.close();


    // ----- 5. Pola Aman Buka File -----
        cout << endl << "=== 5. Pola Aman Buka File ===" << endl;

        // Cara 1: is_open()
        ifstream f5a("05_state.txt");
        if (!f5a.is_open()) {
            cerr << "Gagal buka file!" << endl;
        } else {
            cout << "Cara 1 (is_open): file berhasil dibuka." << endl;
            f5a.close();
        }

        // Cara 2: konversi bool
        ifstream f5b("05_state.txt");
        if (!f5b) {
            cerr << "Gagal buka file!" << endl;
        } else {
            cout << "Cara 2 (!f): file berhasil dibuka." << endl;
            f5b.close();
        }

        // File tidak ada
        ifstream f5c("tidak_ada.txt");
        if (!f5c) {
            cout << "Cara 2 (!f): file tidak ada, berhasil terdeteksi." << endl;
        }


    // ----- 6. Ringkasan State Flags -----
        cout << endl << "=== 6. Ringkasan State Flags ===" << endl;
        cout << "Flag     | Kondisi aktif                | Recoverable?" << endl;
        cout << "---------+------------------------------+-------------" << endl;
        cout << "good()   | Tidak ada masalah            | -" << endl;
        cout << "eof()    | Baca melewati akhir file     | Ya (clear+seekg)" << endl;
        cout << "fail()   | Format salah / gagal parse   | Ya (clear)" << endl;
        cout << "bad()    | Error fatal (disk/hardware)  | Biasanya tidak" << endl;
        cout << endl;
        cout << "Tips: selalu cek !file atau !file.is_open() setelah open!" << endl;

    // Cleanup
        remove("05_state.txt");
        remove("05_clear.txt");
        remove("05_fail.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

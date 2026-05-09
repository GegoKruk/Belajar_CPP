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

        ofstream f2("02_CobaBos.txt");
        if (!f2.is_open()) {
            cerr << "Gagal membuat file!" << endl;
            return 1;
        }

        f2 << "Halo kang" << endl;
        f2 << R"(
                    Selamat malam
                                cek apakah ini bisa juga di file

                        1. Halo
                        2. Namaku
                        3. Gega
                        4. Terima kasih
        )" << endl;
        f2.close();
    }
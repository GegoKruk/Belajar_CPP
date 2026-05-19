#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator> // <-- Tambahkan ini
using namespace std;

// Helper: buat file dengan isi tertentu
void buatFile(const string& nama, const string& isi) {
    ofstream f(nama);
    f << isi;
}

int main() {

    // ----- Persiapan: buat file untuk demo -----
        buatFile("02_teks.txt",
            "Halo dunia\n"
            "Belajar File IO\n"
            "C++ sangat powerful\n"
            "Baris keempat di sini\n"
        );

        buatFile("02_kata.txt",
            "apel mangga jeruk\n"
            "pisang anggur semangka\n"
        );

        buatFile("02_angka.txt",
            "10 20 30\n"
            "40 50 60\n"
            "70 80 90\n"
        );


    // ----- CARA 1: Kata per Kata (>>) -----
        cout << "=== CARA 1: Kata per Kata (>>) ===" << endl;

        ifstream f1("02_kata.txt");
        if (!f1.is_open()) {
            cerr << "File tidak ditemukan!" << endl;
            return 1;
        }

        string kata;
        int jumlahKata = 0;
        cout << "Kata-kata:" << endl;
        while (f1 >> kata) {
            cout << "  [" << jumlahKata + 1 << "] " << kata << endl;
            jumlahKata++;
        }
        cout << "Total kata: " << jumlahKata << endl;
        f1.close();

        // Baca angka dengan >>
        cout << endl << "Baca angka dengan >>:" << endl;
        ifstream fAngka("02_angka.txt");
        int angka, total = 0, count = 0;
        while (fAngka >> angka) {
            total += angka;
            count++;
        }
        fAngka.close();
        cout << "Jumlah angka: " << count << ", Total: " << total << ", Rata-rata: " << (double)total / count << endl;


    // ----- CARA 2: Baris per Baris (getline) -----
        cout << endl << "=== CARA 2: Baris per Baris (getline) ===" << endl;

        ifstream f2("02_teks.txt");
        if (!f2.is_open()) {
            cerr << "File tidak ditemukan!" << endl;
            return 1;
        }

        string baris;
        int noBaris = 0;
        while (getline(f2, baris)) {
            noBaris++;
            cout << "  Baris " << noBaris << ": " << baris << endl;
        }
        cout << "Total baris: " << noBaris << endl;
        f2.close();


    // ----- CARA 3: Karakter per Karakter (get) -----
        cout << endl << "=== CARA 3: Karakter per Karakter (get) ===" << endl;

        ifstream f3("02_kata.txt");
        if (!f3.is_open()) { cerr << "Gagal!" << endl; return 1; }

        char c;
        int jumlahHuruf = 0;
        int jumlahSpasi = 0;
        int jumlahBaris = 0;

        while (f3.get(c)) {
            if (c == '\n')       jumlahBaris++;
            else if (c == ' ')   jumlahSpasi++;
            else                 jumlahHuruf++;
        }
        f3.close();

        cout << "Analisis karakter '02_kata.txt':" << endl;
        cout << "  Huruf/angka  : " << jumlahHuruf << endl;
        cout << "  Spasi        : " << jumlahSpasi << endl;
        cout << "  Baris (newline): " << jumlahBaris << endl;


    // ----- CARA 4: Seluruh File Sekaligus -----
        cout << endl << "=== CARA 4: Seluruh File Sekaligus ===" << endl;

        ifstream f4("02_teks.txt");
        if (!f4.is_open()) { cerr << "Gagal!" << endl; return 1; }

        string seluruhIsi{
            istreambuf_iterator<char>(f4),
            istreambuf_iterator<char>()
        };

        f4.close();
        
        cout << "Seluruh isi file (" << seluruhIsi.size() << " karakter):" << endl;
        cout << seluruhIsi;


    // ----- Perbandingan Keempat Cara -----
        cout << "=== Perbandingan 4 Cara ===" << endl;
        cout << "Cara          | Satuan Baca   | Cocok Untuk" << endl;
        cout << "--------------+---------------+---------------------------" << endl;
        cout << ">> (operator) | Kata/token    | Data angka, token dipisah spasi" << endl;
        cout << "getline       | Satu baris    | Teks umum, CSV baris" << endl;
        cout << "get           | Satu karakter | Analisis karakter, parsing" << endl;
        cout << "istreambuf    | Semua file    | File kecil, perlu isi penuh" << endl;

    // Cleanup
        remove("02_teks.txt");
        remove("02_kata.txt");
        remove("02_angka.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

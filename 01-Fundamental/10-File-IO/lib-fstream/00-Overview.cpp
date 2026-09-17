
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // ----- Demo singkat: tulis lalu baca -----
    cout << "=== Demo Singkat: Tulis lalu Baca ===" << endl;

    // 1. Tulis ke file
        ofstream fw("demo_overview.txt");
        if (!fw.is_open()) {
            cerr << "Gagal membuat file!" << endl;
            return 1;
        }
        fw << "Halo dari File I/O!" << endl;
        fw << "Baris kedua." << endl;
        fw << "Angka: " << 42 << endl;
        fw.close();
        cout << "File berhasil ditulis." << endl;

    // 2. Baca kembali
        ifstream fr("demo_overview.txt");
        if (!fr.is_open()) {
            cerr << "Gagal membaca file!" << endl;
            return 1;
        }

        cout << "Isi file:" << endl;
        string baris;
        while (getline(fr, baris)) {
            cout << "  " << baris << endl;
        }
        fr.close();

    // Hapus file demo
        remove("demo_overview.txt");
        cout << "File demo dihapus." << endl;

    return 0;
}

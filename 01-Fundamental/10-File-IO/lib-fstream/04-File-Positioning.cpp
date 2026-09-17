
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    // Buat file untuk demo
        ofstream fw("04_pos.txt");
        fw << "ABCDEFGHIJ\n";
        fw << "1234567890\n";
        fw << "Baris ketiga\n";
        fw.close();


    // ----- 1. Posisi Awal dan tellg -----
        cout << "=== 1. Kursor Awal dan tellg ===" << endl;

        ifstream f1("04_pos.txt");
        cout << "Posisi awal (tellg): " << f1.tellg() << endl;

        char c;
        f1.get(c); cout << "Baca 1 karakter: '" << c << "'" << endl;
        cout << "Posisi setelah baca 1: " << f1.tellg() << endl;

        f1.get(c); cout << "Baca 1 karakter: '" << c << "'" << endl;
        cout << "Posisi setelah baca 2: " << f1.tellg() << endl;
        f1.close();


    // ----- 2. seekg dari Awal (ios::beg) -----
        cout << endl << "=== 2. seekg dari Awal (ios::beg) ===" << endl;

        ifstream f2("04_pos.txt");

        f2.seekg(5, ios::beg);   // loncat ke byte ke-5
        cout << "Setelah seekg(5, beg), posisi: " << f2.tellg() << endl;
        f2.get(c);
        cout << "Karakter di posisi 5: '" << c << "'" << endl;

        f2.seekg(0, ios::beg);   // kembali ke awal
        f2.get(c);
        cout << "Kembali ke awal, karakter: '" << c << "'" << endl;
        f2.close();


    // ----- 3. seekg dari Akhir (ios::end) -----
        cout << endl << "=== 3. seekg dari Akhir (ios::end) ===" << endl;

        ifstream f3("04_pos.txt");

        f3.seekg(0, ios::end);
        cout << "Posisi akhir file: " << f3.tellg() << " byte" << endl;

        // Baca beberapa karakter dari akhir
        f3.seekg(-5, ios::end);   // 5 byte sebelum akhir
        cout << "5 karakter terakhir: '";
        while (f3.get(c)) cout << c;
        cout << "'" << endl;
        f3.close();


    // ----- 4. seekg dari Posisi Sekarang (ios::cur) -----
        cout << endl << "=== 4. seekg dari Posisi Sekarang (ios::cur) ===" << endl;

        ifstream f4("04_pos.txt");

        f4.seekg(3, ios::beg);   // mulai di byte 3
        cout << "Posisi awal: " << f4.tellg() << endl;

        f4.seekg(2, ios::cur);   // maju 2 byte
        cout << "Setelah seekg(2, cur): " << f4.tellg() << endl;
        f4.get(c);
        cout << "Karakter di posisi ini: '" << c << "'" << endl;

        f4.seekg(-3, ios::cur);  // mundur 3 byte
        cout << "Setelah seekg(-3, cur): " << f4.tellg() << endl;
        f4.close();


    // ----- 5. Ukuran File -----
        cout << endl << "=== 5. Ukuran File ===" << endl;

        // Cara 1: buka dengan ios::ate lalu cek tellg
        ifstream fSize("04_pos.txt", ios::ate);
        streamsize ukuran = fSize.tellg();
        cout << "Ukuran '04_pos.txt': " << ukuran << " byte" << endl;
        fSize.seekg(0);   // kembali ke awal untuk baca normal

        // Hitung baris
        string baris;
        int jmlBaris = 0;
        while (getline(fSize, baris)) jmlBaris++;
        cout << "Jumlah baris: " << jmlBaris << endl;
        fSize.close();


    // ----- 6. Reset Setelah EOF -----
        cout << endl << "=== 6. Reset Setelah EOF (clear + seekg) ===" << endl;

        ifstream f6("04_pos.txt");

        // Baca pertama kali
        cout << "Baca pertama kali:" << endl;
        while (getline(f6, baris)) {
            cout << "  " << baris << endl;
        }
        cout << "eof(): " << f6.eof() << " (1 = sudah EOF)" << endl;

        // Reset dan baca lagi
        f6.clear();    // reset flag EOF
        f6.seekg(0);   // kembali ke awal
        cout << "Setelah clear() + seekg(0): baca lagi" << endl;
        int noB = 0;
        while (getline(f6, baris)) {
            noB++;
            cout << "  Baris " << noB << ": " << baris << endl;
        }
        f6.close();


    // ----- 7. seekp untuk Menulis di Posisi Tertentu -----
        cout << endl << "=== 7. seekp - Tulis di Posisi Tertentu ===" << endl;

        // Buat file berisi 10 angka
            ofstream fw2("04_seekp.txt");
            fw2 << "0123456789";
            fw2.close();

            cout << "Sebelum seekp:" << endl;
            bacaFile:
            ifstream cek1("04_seekp.txt");
            string tmp; getline(cek1, tmp); cek1.close();
            cout << "  " << tmp << endl;

        // Timpa karakter di posisi 3 dengan 'X'
            fstream fw3("04_seekp.txt", ios::in | ios::out);
            fw3.seekp(3);
            fw3.put('X');
            fw3.seekp(7);
            fw3.put('Y');
            fw3.close();

            cout << "Setelah seekp(3)='X' dan seekp(7)='Y':" << endl;
            ifstream cek2("04_seekp.txt");
            getline(cek2, tmp); cek2.close();
            cout << "  " << tmp << endl;

        // Cleanup
            remove("04_pos.txt");
            remove("04_seekp.txt");
            cout << endl << "File demo dihapus." << endl;

    return 0;
}

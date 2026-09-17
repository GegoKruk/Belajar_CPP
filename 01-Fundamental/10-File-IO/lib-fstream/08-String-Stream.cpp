
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream> // Tambahkan ini untuk fungsi ofstream
#include <cstdio>  // Tambahkan ini untuk fungsi remove()
using namespace std;

int main() {

    // ----- 1. Konversi Angka ke String -----
        cout << "=== 1. Konversi Angka ke String ===" << endl;

        // Cara stringstream
            stringstream ss1;
            int angka = 12345;
            double pi  = 3.141592653589793;

            ss1 << angka;
            string strAngka = ss1.str();
            cout << "int " << angka << " -> string \"" << strAngka << "\"" << endl;

        // Reset dan konversi double
            ss1.str("");
            ss1.clear();
            ss1 << fixed << setprecision(4) << pi;
            string strPi = ss1.str();
            cout << "double pi -> string \"" << strPi << "\" (4 desimal)" << endl;

        // Cara modern (C++11): to_string()
            string s2 = to_string(angka);
            cout << "to_string(" << angka << ") = \"" << s2 << "\"" << endl;
            cout << "(to_string untuk format default, stringstream untuk format custom)" << endl;


    // ----- 2. Konversi String ke Angka -----
        cout << endl << "=== 2. Konversi String ke Angka ===" << endl;

        // Cara stringstream
            string strNum = "42";
            int hasil1;
            istringstream ss2(strNum);
            ss2 >> hasil1;
            cout << "string \"" << strNum << "\" -> int " << hasil1 << endl;

            string strDes = "3.14159";
            double hasil2;
            istringstream ss3(strDes);
            ss3 >> hasil2;
            cout << "string \"" << strDes << "\" -> double " << hasil2 << endl;

        // Cara modern (C++11): stoi, stod, stof
            int i   = stoi("100");
            double d = stod("2.718");
            cout << "stoi(\"100\")  = " << i << endl;
            cout << "stod(\"2.718\") = " << d << endl;


    // ----- 3. Tokenizing / Split String -----
        cout << endl << "=== 3. Tokenizing (Split dengan Spasi) ===" << endl;

        string kalimat = "satu dua tiga empat lima";
        istringstream ss4(kalimat);
        string token;
        int no = 0;
        cout << "Kalimat: \"" << kalimat << "\"" << endl;
        cout << "Token:" << endl;
        while (ss4 >> token) {
            cout << "  [" << ++no << "] " << token << endl;
        }


    // ----- 4. Parsing CSV -----
        cout << endl << "=== 4. Parsing CSV ===" << endl;

        string barisCsv = "Budi,20,3.85";
        istringstream ss5(barisCsv);

        string nama, umurStr, ipkStr;
        getline(ss5, nama,   ',');   // baca sampai ','
        getline(ss5, umurStr,',');
        getline(ss5, ipkStr, ',');

        int    umur = stoi(umurStr);
        double ipk  = stod(ipkStr);

        cout << "Baris CSV: \"" << barisCsv << "\"" << endl;
        cout << "  nama = " << nama << endl;
        cout << "  umur = " << umur << endl;
        cout << "  ipk  = " << ipk  << endl;

        // Parsing beberapa baris CSV
        cout << endl << "Parsing banyak baris CSV:" << endl;
        vector<string> barisData = {
            "Sari,21,3.90",
            "Andi,19,3.70",
            "Dina,22,3.95"
        };

        for (const string& b : barisData) {
            istringstream ss(b);
            string n, us, is;
            getline(ss, n, ',');
            getline(ss, us, ',');
            getline(ss, is, ',');
            cout << "  " << n << " | umur=" << stoi(us) << " | ipk=" << stod(is) << endl;
        }


    // ----- 5. Build String Terformat (ostringstream) -----
        cout << endl << "=== 5. Build String Terformat (ostringstream) ===" << endl;

        struct DataMhs { string nama; int umur; double ipk; };
        DataMhs mhs = {"Budi Santoso", 20, 3.856};

        ostringstream oss;
        oss << "=== Info Mahasiswa ===" << endl;
        oss << "Nama  : " << mhs.nama  << endl;
        oss << "Umur  : " << mhs.umur  << " tahun" << endl;
        oss << "IPK   : " << fixed << setprecision(2) << mhs.ipk << endl;
        oss << "Grade : " << (mhs.ipk >= 3.75 ? "A (Cumlaude)" : "B") << endl;

        string laporan = oss.str();

        cout << "Laporan yang dibangun:" << endl;
        cout << laporan;

        // Simpan ke file sekaligus
            ofstream fw("08_laporan.txt");
            fw << laporan;
            fw.close();
            cout << "Laporan disimpan ke '08_laporan.txt'" << endl;


    // ----- 6. Split dengan Delimiter Custom -----
        cout << endl << "=== 6. Split dengan Delimiter Custom ===" << endl;

        string data = "merah|hijau|biru|kuning";
        cout << "Data: \"" << data << "\"" << endl;
        cout << "Split dengan '|':" << endl;

        istringstream ss6(data);
        string bagian;
        int idx = 0;
        while (getline(ss6, bagian, '|')) {
            cout << "  [" << idx++ << "] " << bagian << endl;
        }


    // ----- 7. Reuse stringstream -----
        cout << endl << "=== 7. Reuse stringstream (str + clear) ===" << endl;

        stringstream ssReuse;

        ssReuse << 100;
        cout << "Pertama: " << ssReuse.str() << endl;

        ssReuse.str("");    // kosongkan isi
        ssReuse.clear();    // reset state flags

        ssReuse << 3.14;
        cout << "Kedua  : " << ssReuse.str() << endl;


    // Cleanup
        remove("08_laporan.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

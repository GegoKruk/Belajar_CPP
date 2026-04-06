
#include <iostream>
#include <string>
#include <sstream>   // ostringstream
#include <iomanip>   // setprecision
using namespace std;


// KONVERSI ANGKA <-> STRING
void demoAngkaKeString() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Angka ke String -- to_string()" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  to_string() mengkonversi angka menjadi string." << endl;

    // Integer
        cout << "\n  to_string() untuk integer:" << endl;
        cout << "  to_string(42)    = \"" << to_string(42)    << "\"" << endl;
        cout << "  to_string(-99)   = \"" << to_string(-99)   << "\"" << endl;
        cout << "  to_string(0)     = \"" << to_string(0)     << "\"" << endl;
        cout << "  to_string(1000000) = \"" << to_string(1000000) << "\"" << endl;

    // Double -- presisi default
        cout << "\n  to_string() untuk double (presisi default 6 desimal):" << endl;
        cout << "  to_string(3.14)    = \"" << to_string(3.14)   << "\"" << endl;
        cout << "  to_string(3.14159) = \"" << to_string(3.14159) << "\"" << endl;
        cout << "  to_string(1.0)     = \"" << to_string(1.0)     << "\"" << endl;

        cout << "\n  Masalah: presisi to_string() untuk float/double terbatas!" << endl;
        cout << "  to_string(3.14159265) = \"" << to_string(3.14159265) << "\"" << endl;
        cout << "  (dipotong di 6 desimal, bukan 8)" << endl;

    // Kegunaan to_string
        cout << "\n  Kegunaan praktis to_string():" << endl;
        string laporan = "Nilai rata-rata: " + to_string(87) + " dari " + to_string(100);
        cout << "  \"" << laporan << "\"" << endl;

    // Gabung angka ke string
        for (int i = 1; i <= 5; i++) {
            string label = "Item-" + to_string(i);
            cout << "  " << label << endl;
        }
}

void demoOstringstream() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. ostringstream -- Konversi dengan Format Presisi" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  to_string() kurang fleksibel untuk format khusus." << endl;
    cout << "  Gunakan ostringstream dari <sstream> untuk kontrol penuh." << endl;

    double nilai = 3.14159265358979;

    cout << "\n  to_string(" << nilai << "):" << endl;
    cout << "  Hasil: \"" << to_string(nilai) << "\" (presisi terbatas)" << endl;

    // ostringstream dengan setprecision
        ostringstream oss1;
        oss1 << fixed << setprecision(2) << nilai;
        cout << "\n  ostringstream dengan fixed + setprecision(2):" << endl;
        cout << "  Hasil: \"" << oss1.str() << "\"" << endl;

        ostringstream oss2;
        oss2 << fixed << setprecision(8) << nilai;
        cout << "\n  ostringstream dengan fixed + setprecision(8):" << endl;
        cout << "  Hasil: \"" << oss2.str() << "\"" << endl;

    // Format uang
        cout << "\n  Format uang dengan ostringstream:" << endl;
        double harga = 1250000.50;
        ostringstream ossHarga;
        ossHarga << fixed << setprecision(2) << harga;
        string strHarga = "Rp " + ossHarga.str();
        cout << "  " << strHarga << endl;

    // Format ilmiah
        ostringstream ossIlmiah;
        ossIlmiah << scientific << setprecision(3) << 12345678.9;
        cout << "\n  Format scientific: \"" << ossIlmiah.str() << "\"" << endl;

    // Gabung berbagai tipe
        ostringstream ossGabung;
        ossGabung << "Nama: " << "Gega" << ", Nilai: " << 90 << ", IPK: "
                << fixed << setprecision(2) << 3.87;
        cout << "\n  ostringstream gabung: \"" << ossGabung.str() << "\"" << endl;
}

void demoStringKeAngka() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. String ke Angka -- stoi, stod, dll" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Daftar fungsi konversi:" << endl;
    cout << "  +----------+---------------------------+-----------------------+" << endl;
    cout << "  | Fungsi   | Konversi                  | Contoh                |" << endl;
    cout << "  +----------+---------------------------+-----------------------+" << endl;
    cout << "  | stoi(s)  | string -> int             | stoi(\"42\") = 42       |" << endl;
    cout << "  | stol(s)  | string -> long            | stol(\"1000000\")       |" << endl;
    cout << "  | stoll(s) | string -> long long       | stoll(\"9999999999\")   |" << endl;
    cout << "  | stof(s)  | string -> float           | stof(\"3.14\")          |" << endl;
    cout << "  | stod(s)  | string -> double          | stod(\"3.14159\")       |" << endl;
    cout << "  | stold(s) | string -> long double     | stold(\"3.14159265\")   |" << endl;
    cout << "  +----------+---------------------------+-----------------------+" << endl;

    // Contoh penggunaan
        cout << "\n  Contoh:" << endl;
        string s1 = "42";
        string s2 = "3.14159";
        string s3 = "-100";
        string s4 = "9876543210";

        cout << "  stoi(\"" << s1 << "\")         = " << stoi(s1) << endl;
        cout << "  stod(\"" << s2 << "\")    = " << stod(s2) << endl;
        cout << "  stoi(\"" << s3 << "\")       = " << stoi(s3) << endl;
        cout << "  stoll(\"" << s4 << "\") = " << stoll(s4) << endl;

    // Dengan spasi di awal -- diabaikan
        cout << "\n  Spasi di awal diabaikan:" << endl;
        cout << "  stoi(\"   42\") = " << stoi("   42") << endl;

    // Dengan karakter setelah angka
        cout << "\n  Angka di awal, sisanya diabaikan:" << endl;
        cout << "  stoi(\"42abc\") = " << stoi("42abc") << "  (abc diabaikan)" << endl;
}

void demoKonversiAman() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. Konversi Aman dengan try-catch" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  BAHAYA! stoi(\"abc\") akan melempar exception dan program crash!" << endl;
    cout << "  Selalu bungkus dengan try-catch untuk input yang tidak terjamin." << endl;

    // Demo exception
        cout << "\n  Demo: stoi() dengan input tidak valid:" << endl;

        string inputs[] = {"42", "abc", "3.14", "", "99999999999"};

        for (const string &input : inputs) {
            try {
                int hasil = stoi(input);
                cout << "  stoi(\"" << input << "\") = " << hasil << "  (berhasil)" << endl;
            } catch (const invalid_argument &e) {
                cout << "  stoi(\"" << input << "\") -> invalid_argument: bukan angka!" << endl;
            } catch (const out_of_range &e) {
                cout << "  stoi(\"" << input << "\") -> out_of_range: angka terlalu besar!" << endl;
            }
        }

    // Fungsi validasi angka
        cout << "\n  Fungsi cek apakah string adalah angka:" << endl;
        auto isAngka = [](const string &s) -> bool {
            if (s.empty()) return false;
            try {
                stoi(s);
                return true;
            } catch (...) {
                return false;
            }
        };

        string tesAngka[] = {"123", "abc", "45.6", "-7", ""};
        for (const string &s : tesAngka) {
            cout << "  \"" << s << "\" -> " << (isAngka(s) ? "angka valid" : "bukan angka") << endl;
        }
}

void demoKonversiCharString() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Konversi char[] <-> std::string" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Dari char[] ke string (otomatis):" << endl;
    char cArr[] = "Halo dari C-style";
    string s1 = cArr;        // otomatis konversi
    string s2(cArr);         // constructor
    string s3 = string(cArr); // eksplisit
    cout << "  string s1 = cArr;    -> \"" << s1 << "\"" << endl;
    cout << "  string s2(cArr);     -> \"" << s2 << "\"" << endl;

    cout << "\n  Dari string ke char[] (pakai c_str()):" << endl;
    string str = "Halo dari std::string";
    const char *cPtr = str.c_str();  // const char*, read-only!
    cout << "  str.c_str()          -> \"" << cPtr << "\"" << endl;
    cout << "  Catatan: c_str() mengembalikan const char* (tidak boleh diubah!)" << endl;
    cout << "  Pointer tidak valid lagi jika str dimodifikasi!" << endl;

    cout << "\n  Jika perlu modifikasi, salin ke char array:" << endl;
    cout << "  char buf[100];" << endl;
    cout << "  strcpy(buf, str.c_str());  // salin ke char array" << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.8 -- Konversi Angka <-> String" << endl;
    cout << "============================================================" << endl;

    demoAngkaKeString();
    demoOstringstream();
    demoStringKeAngka();
    demoKonversiAman();
    demoKonversiCharString();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  to_string(n)     -> angka ke string (presisi terbatas untuk double)" << endl;
    cout << "  ostringstream    -> angka ke string dengan format presisi" << endl;
    cout << "  stoi(s)          -> string ke int" << endl;
    cout << "  stod(s)          -> string ke double" << endl;
    cout << "  stoi/stod bisa lempar exception -> SELALU pakai try-catch!" << endl;
    cout << "  char[] ke string  -> otomatis (string s = charArr)" << endl;
    cout << "  string ke char[]  -> s.c_str() (const, read-only)" << endl;

    return 0;
}

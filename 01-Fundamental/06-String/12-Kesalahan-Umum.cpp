
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>   // strcmp, strcpy
using namespace std;


// 6 KESALAHAN UMUM PADA STRING

void kesalahan1() {
    cout << "============================================================" << endl;
    cout << "  Kesalahan 1: Bandingkan char* dengan ==" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  Operator == pada dua char* membandingkan ALAMAT MEMORI," << endl;
    cout << "  bukan isi stringnya! Hasilnya tidak bisa diprediksi." << endl;

    char a[] = "Halo";
    char b[] = "Halo";

    cout << "\n  char a[] = \"Halo\", char b[] = \"Halo\"" << endl;
    cout << "  a == b?  -> " << (a == b ? "true" : "false") << "  (SALAH! Bandingkan alamat, bukan isi)" << endl;
    cout << "  &a = " << (void*)a << ", &b = " << (void*)b << "  (alamat berbeda!)" << endl;

    cout << "\n  SOLUSI 1: Pakai strcmp() untuk char[]" << endl;
    cout << "  strcmp(a, b) == 0 -> " << (strcmp(a, b) == 0 ? "true" : "false") << "  (benar!)" << endl;

    cout << "\n  SOLUSI 2: Konversi ke std::string, lalu pakai ==" << endl;
    string sa = a, sb = b;
    cout << "  string(a) == string(b) -> " << (sa == sb ? "true" : "false") << "  (benar!)" << endl;

    cout << "\n  SOLUSI 3: Pakai std::string dari awal (TERBAIK!)" << endl;
    string ss1 = "Halo", ss2 = "Halo";
    cout << "  ss1 == ss2 -> " << (ss1 == ss2 ? "true" : "false") << "  (langsung, tidak perlu fungsi khusus)" << endl;
}

void kesalahan2() {
    cout << "\n============================================================" << endl;
    cout << "  Kesalahan 2: Lupa cin.ignore() Sebelum getline()" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  Setelah cin >> variabel, karakter '\\n' (Enter)" << endl;
    cout << "  masih tersisa di buffer input." << endl;
    cout << "  getline() akan langsung membaca '\\n' itu -> string KOSONG!" << endl;

    cout << R"(
        Kode yang SALAH:
            int umur;
            string nama;
            cin >> umur;           // user ketik 20, tekan Enter
                                    // '20' terproses, '\\n' masih di buffer!
            getline(cin, nama);    // langsung baca '\\n' -> nama = "" (kosong!)

        Kode yang BENAR:
            int umur;
            string nama;
            cin >> umur;
            cin.ignore();          // buang '\\n' dari buffer
            getline(cin, nama);    // sekarang baca dengan benar

        Lebih aman:
            cin.ignore(1000, '\\n'); // buang sampai 1000 char ATAU sampai '\\n'
    )";

    cout << "  ATURAN: Selalu tambahkan cin.ignore() setelah cin >>" << endl;
    cout << "  jika ada getline() setelahnya!" << endl;
}

void kesalahan3() {
    cout << "\n============================================================" << endl;
    cout << "  Kesalahan 3: Akses Index di Luar Batas" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  s[s.size()] atau s[s.size()+1] -> undefined behavior!" << endl;
    cout << "  Program bisa crash atau memberi output tidak terduga." << endl;

    string s = "Halo";
    cout << "\n  s = \"" << s << "\", s.size() = " << s.size() << endl;
    cout << "  Index valid: 0, 1, 2, 3  (yaitu 0 sampai size()-1 = " << s.size()-1 << ")" << endl;

    cout << "\n  s[0] = '" << s[0] << "'  <- valid" << endl;
    cout << "  s[3] = '" << s[3] << "'  <- valid (terakhir)" << endl;
    cout << "  s[4] = ???  <- TIDAK VALID! index sama dengan size" << endl;

    cout << "\n  SOLUSI 1: Selalu cek index sebelum akses" << endl;
    int idx = 4;
    if (idx >= 0 && idx < (int)s.size()) {
        cout << "  s[" << idx << "] = '" << s[idx] << "'" << endl;
    } else {
        cout << "  Index " << idx << " tidak valid untuk string panjang " << s.size() << "  <- diblokir!" << endl;
    }

    cout << "\n  SOLUSI 2: Gunakan s.at(i) yang otomatis cek batas" << endl;
    try {
        char c = s.at(99);
        (void)c;
    } catch (const out_of_range &e) {
        cout << "  s.at(99) -> exception! Program tidak crash." << endl;
        cout << "  Error: " << e.what() << endl;
    }
}

void kesalahan4() {
    cout << "\n============================================================" << endl;
    cout << "  Kesalahan 4: Modifikasi Hasil c_str()" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  s.c_str() mengembalikan const char* (read-only!)" << endl;
    cout << "  Pointer ini tidak valid lagi jika string s dimodifikasi!" << endl;

    string s = "Halo Dunia";
    const char *cPtr = s.c_str();

    cout << "\n  s = \"" << s << "\"" << endl;
    cout << "  const char* p = s.c_str(); -> \"" << cPtr << "\"" << endl;

    cout << "\n  BAHAYA -- jangan modifikasi string setelah ambil c_str():" << endl;
    cout << "  s += \" tambahan\";  // modifikasi string" << endl;
    cout << "  cout << p;          // p TIDAK VALID lagi! (dangling pointer)" << endl;

    cout << "\n  BAHAYA -- jangan ubah isi via pointer c_str():" << endl;
    cout << "  char *p = (char*)s.c_str();" << endl;
    cout << "  p[0] = 'X';  // UNDEFINED BEHAVIOR!" << endl;

    cout << "\n  SOLUSI: Salin ke char array jika perlu modifikasi" << endl;
    char buffer[50];
    strcpy(buffer, s.c_str());
    buffer[0] = 'h';   // modifikasi salinan, aman
    cout << "  Salin ke buffer lalu modifikasi: \"" << buffer << "\"" << endl;
    cout << "  s asli masih: \"" << s << "\"" << endl;
}

void kesalahan5() {
    cout << "\n============================================================" << endl;
    cout << "  Kesalahan 5: stoi/stod Tanpa try-catch" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  stoi(\"abc\") melempar std::invalid_argument" << endl;
    cout << "  stoi(\"9999999999\") melempar std::out_of_range" << endl;
    cout << "  Tanpa try-catch -> program CRASH!" << endl;

    cout << "\n  Kode yang SALAH:" << endl;
    cout << "  string input = \"abc\";" << endl;
    cout << "  int n = stoi(input);  // CRASH! invalid_argument" << endl;

    cout << "\n  Kode yang BENAR:" << endl;
    cout << "  try {" << endl;
    cout << "      int n = stoi(input);" << endl;
    cout << "      // pakai n" << endl;
    cout << "  } catch (const invalid_argument &e) {" << endl;
    cout << "      cout << \"Bukan angka!\" << endl;" << endl;
    cout << "  } catch (const out_of_range &e) {" << endl;
    cout << "      cout << \"Angka terlalu besar!\" << endl;" << endl;
    cout << "  }" << endl;

    // Demo
        cout << "\n  Demo dengan berbagai input:" << endl;
        string inputs[] = {"42", "abc", "99999999999", "3.14", "-5"};
        for (const string &inp : inputs) {
            try {
                int n = stoi(inp);
                cout << "  stoi(\"" << inp << "\") = " << n << "  (berhasil)" << endl;
            } catch (const invalid_argument &) {
                cout << "  stoi(\"" << inp << "\") -> invalid_argument (bukan angka)" << endl;
            } catch (const out_of_range &) {
                cout << "  stoi(\"" << inp << "\") -> out_of_range (terlalu besar)" << endl;
            }
        }
}

void kesalahan6() {
    cout << "\n============================================================" << endl;
    cout << "  Kesalahan 6: Lupa #include <string>" << endl;
    cout << "============================================================" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  Kadang <iostream> membawa <string> secara tidak langsung," << endl;
    cout << "  tapi ini TIDAK DIJAMIN di semua compiler dan platform!" << endl;
    cout << "  Tanpa #include <string> secara eksplisit, kode bisa:" << endl;
    cout << "  - Compile di satu compiler tapi gagal di compiler lain" << endl;
    cout << "  - Compile di satu platform tapi gagal di platform lain" << endl;

    cout << "\n  SOLUSI: Selalu tulis #include <string> secara eksplisit!" << endl;
    cout << "\n  Header yang diperlukan untuk string:" << endl;
    cout << "  #include <string>     -> std::string, to_string, stoi, dll" << endl;
    cout << "  #include <sstream>    -> stringstream, ostringstream" << endl;
    cout << "  #include <algorithm>  -> reverse, transform, sort, count" << endl;
    cout << "  #include <cctype>     -> tolower, toupper, isalpha, dll" << endl;
}

void ringkasanKesalahan() {
    cout << "\n============================================================" << endl;
    cout << "  Ringkasan 6 Kesalahan Umum" << endl;
    cout << "============================================================" << endl;

    cout << R"(
        +---+----------------------------------+--------------------------------+
        | # | Kesalahan                        | Solusi                         |
        +---+----------------------------------+--------------------------------+
        | 1 | Bandingkan char* dengan ==       | Pakai strcmp() atau std::string |
        | 2 | Lupa cin.ignore() sebelum        | Tambahkan cin.ignore() atau    |
        |   | getline()                        | cin.ignore(1000,'\n')           |
        | 3 | Akses s[s.size()] (out of bounds)| Cek index, atau pakai s.at(i)  |
        | 4 | Modifikasi hasil c_str()         | Salin ke char[] dulu            |
        | 5 | stoi/stod tanpa try-catch        | Selalu bungkus try-catch        |
        | 6 | Lupa #include <string>           | Selalu tulis eksplisit          |
        +---+----------------------------------+--------------------------------+
    )";
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.12 -- Kesalahan Umum & Cara Menghindarinya" << endl;
    cout << "============================================================" << endl;

    kesalahan1();
    kesalahan2();
    kesalahan3();
    kesalahan4();
    kesalahan5();
    kesalahan6();
    ringkasanKesalahan();

    return 0;
}

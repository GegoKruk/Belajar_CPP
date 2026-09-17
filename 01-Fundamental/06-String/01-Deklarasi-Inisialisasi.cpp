
#include <iostream>
#include <string>
using namespace std;

void demoDeklarasi() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Cara Deklarasi & Inisialisasi" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Cara 1: Assignment syntax (paling umum)
        string s1 = "Halo Dunia";
        cout << "\n  string s1 = \"Halo Dunia\"  -> \"" << s1 << "\"" << endl;

    // Cara 2: Constructor syntax
        string s2("Belajar C++");
        cout << "  string s2(\"Belajar C++\") -> \"" << s2 << "\"" << endl;

    // Cara 3: String kosong (defaultnya "")
        string s3;
        cout << "  string s3;               -> \"" << s3 << "\" (kosong)" << endl;
        cout << "  s3.empty()               -> " << (s3.empty() ? "true" : "false") << endl;

    // Cara 4: String kosong eksplisit
        string s4 = "";
        cout << "  string s4 = \"\"           -> \"" << s4 << "\" (kosong eksplisit)" << endl;

    // Cara 5: Fill constructor -- isi n karakter yang sama
        string s5(5, '*');
        cout << "  string s5(5, '*')        -> \"" << s5 << "\"" << endl;

        string s6(10, '-');
        cout << "  string s6(10, '-')       -> \"" << s6 << "\"" << endl;

        string s7(3, 'A');
        cout << "  string s7(3, 'A')        -> \"" << s7 << "\"" << endl;

    // Cara 6: Copy constructor -- salin dari string lain
        string s8 = s1;
        cout << "  string s8 = s1           -> \"" << s8 << "\" (salinan s1)" << endl;

        string s9(s1);
        cout << "  string s9(s1)            -> \"" << s9 << "\" (salinan s1)" << endl;

    // Cara 7: Sebagian string (substring constructor)
        string s10(s1, 5, 5);   // dari index 5, ambil 5 karakter
        cout << "  string s10(s1, 5, 5)    -> \"" << s10 << "\" (dari index 5, 5 karakter)" << endl;

        string s11(s1, 0, 4);   // dari index 0, ambil 4 karakter
        cout << "  string s11(s1, 0, 4)    -> \"" << s11 << "\" (dari index 0, 4 karakter)" << endl;
}

void demoAssignSetelahDeklarasi() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. Assign & Reassign Setelah Deklarasi" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s;
    cout << "\n  string s;  -> \"" << s << "\" (kosong)" << endl;

    s = "Halo";
    cout << "  s = \"Halo\" -> \"" << s << "\"" << endl;

    s = "Dunia";   // ganti isi
    cout << "  s = \"Dunia\" -> \"" << s << "\" (diganti)" << endl;

    // Assign dari string lain
        string t = "Belajar";
        s = t;
        cout << "  s = t      -> \"" << s << "\" (disalin dari t)" << endl;

    // Assign karakter tunggal
        s = "X";   // string berisi 1 karakter
        cout << "  s = \"X\"   -> \"" << s << "\" (string 1 karakter)" << endl;

    // Assign angka (harus pakai to_string!)
    // s = 42;   <- COMPILE ERROR! tidak bisa assign int ke string
        s = to_string(42);
        cout << "  s = to_string(42) -> \"" << s << "\"" << endl;
}

void demoSingleVsDouble() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Single Quote vs Double Quote" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Aturan penting:" << endl;
    cout << "  'A'       <- CHAR   (single karakter, tipe: char)" << endl;
    cout << "  \"A\"     <- STRING (bisa banyak karakter, tipe: string)" << endl;

    char  c = 'A';      // char, single quote
    string s = "A";     // string dengan 1 karakter, double quote

    cout << "\n  char   c = 'A'  -> nilai: " << c << "  tipe: char  ukuran: " << sizeof(c) << " byte" << endl;
    cout << "  string s = \"A\"  -> nilai: " << s << "  panjang: " << s.length() << " karakter" << endl;

    cout << "\n  Contoh salah yang sering terjadi:" << endl;
    cout << "  string nama = 'Gega';  <- COMPILE ERROR!" << endl;
    cout << "  char   init = \"G\";     <- COMPILE ERROR!" << endl;
    cout << "  char   init = 'G';     <- Benar (char)" << endl;
    cout << "  string nama = \"Gega\"; <- Benar (string)" << endl;

    cout << "\n  Tapi char dan string bisa dikombinasikan:" << endl;
    string kata = "Halo";
    kata += '!';   // tambah char ke string
    cout << "  string kata = \"Halo\"; kata += '!'; -> \"" << kata << "\"" << endl;

    char pertama = kata[0];   // ambil char dari string
    cout << "  char pertama = kata[0]; -> '" << pertama << "'" << endl;
}

void demoStringLiteral() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. String Literal & Karakter Khusus" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  String dengan escape sequence:" << endl;
    string s1 = "Baris pertama\nBaris kedua";
    cout << "  \"Baris pertama\\nBaris kedua\" ->" << endl;
    cout << s1 << endl;

    string s2 = "Kolom1\tKolom2\tKolom3";
    cout << "\n  Dengan tab: " << s2 << endl;

    string s3 = "Dia berkata \"Halo!\"";
    cout << "  Dengan kutip: " << s3 << endl;

    string s4 = "C:\\Users\\Gega\\Documents";
    cout << "  Path Windows: " << s4 << endl;

    // Raw string literal (C++11) -- tidak perlu escape
    string s5 = R"(C:\Users\Gega\Documents\file.txt)";
    cout << "\n  Raw string literal (tidak perlu \\\\):" << endl;
    cout << "  " << s5 << endl;

    string s6 = R"(
        Line 1
        Line 2
        Line 3
    )";
    cout << "\n  Raw multiline:" << endl;
    cout << s6 << endl;
}

void demoInfoDasar() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Info Dasar String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Belajar C++ itu menyenangkan!";

    cout << "\n  string s = \"" << s << "\"" << endl;
    cout << "\n  s.length()     = " << s.length()   << "  (jumlah karakter)" << endl;
    cout << "  s.size()       = " << s.size()     << "  (sama dengan length)" << endl;
    cout << "  s.empty()      = " << (s.empty() ? "true" : "false") << endl;
    cout << "  s.capacity()   = " << s.capacity() << "  (memori yg dialokasikan, >= size)" << endl;

    string kosong;
    cout << "\n  string kosong;" << endl;
    cout << "  kosong.empty() = " << (kosong.empty() ? "true" : "false") << endl;
    cout << "  kosong.size()  = " << kosong.size()   << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.1 -- Deklarasi & Inisialisasi std::string" << endl;
    cout << "============================================================" << endl;

    demoDeklarasi();
    demoAssignSetelahDeklarasi();
    demoSingleVsDouble();
    demoStringLiteral();
    demoInfoDasar();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  string s = \"teks\";       <- cara paling umum" << endl;
    cout << "  string s(n, 'c');         <- isi n karakter 'c'" << endl;
    cout << "  string s;                 <- string kosong (default \"\")" << endl;
    cout << "  'A' = char,  \"A\" = string <- jangan tertukar!" << endl;
    cout << "  s.length() / s.size()     <- jumlah karakter" << endl;
    cout << "  s.empty()                 <- cek apakah kosong" << endl;

    return 0;
}

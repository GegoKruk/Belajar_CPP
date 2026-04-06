
#include <iostream>
#include <string>
#include <algorithm>   // transform
#include <cctype>      // tolower
using namespace std;


// OPERASI DASAR

void demoPanjangKosong() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Panjang dan Cek Kosong" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s1 = "Halo Dunia";
    string s2 = "";
    string s3;

    cout << "\n  s1 = \"" << s1 << "\"" << endl;
    cout << "  s1.length()  = " << s1.length() << endl;
    cout << "  s1.size()    = " << s1.size()   << "  (identik dengan length)" << endl;
    cout << "  s1.empty()   = " << (s1.empty() ? "true" : "false") << endl;

    cout << "\n  s2 = \"\"  (string kosong eksplisit)" << endl;
    cout << "  s2.length() = " << s2.length() << endl;
    cout << "  s2.empty()  = " << (s2.empty() ? "true" : "false") << endl;

    cout << "\n  s3;  (string kosong default)" << endl;
    cout << "  s3.length() = " << s3.length() << endl;
    cout << "  s3.empty()  = " << (s3.empty() ? "true" : "false") << endl;

    // Kegunaan empty()
        cout << "\n  Contoh pemakaian empty() dalam validasi:" << endl;
        string input = "";
        if (input.empty()) {
            cout << "  input kosong, tidak bisa diproses!" << endl;
        }

    // Panjang string Indonesia (contoh berbeda)
        string buah[] = {"apel", "mangga", "durian", "rambutan", "kelengkeng"};
        cout << "\n  Panjang tiap kata:" << endl;
        for (const string &b : buah) {
            cout << "  \"" << b << "\" -> " << b.length() << " karakter" << endl;
        }
}

void demoGabung() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. Penggabungan String (Concatenation)" << endl;
    cout << "------------------------------------------------------------" << endl;

    string nama  = "Gega";
    string kota  = "Yogyakarta";
    string spasi = " ";

    cout << "\n  nama = \"" << nama << "\", kota = \"" << kota << "\"" << endl;

    // Operator + -- buat string baru
        string gabungan1 = nama + spasi + kota;
        cout << "\n  nama + spasi + kota = \"" << gabungan1 << "\"" << endl;

    // Gabung dengan string literal
        string gabungan2 = "Halo " + nama + "!";
        cout << "  \"Halo \" + nama + \"!\" = \"" << gabungan2 << "\"" << endl;

    // Operator += -- tambah ke string yang ada
        string s = "Belajar";
        cout << "\n  s = \"" << s << "\"" << endl;
        s += " C++";
        cout << "  s += \" C++\" -> \"" << s << "\"" << endl;
        s += " itu ";
        s += "menyenangkan!";
        cout << "  s += \" itu \" += \"menyenangkan!\" -> \"" << s << "\"" << endl;

    // Gabung dengan char (bukan string)
        string kata = "Halo";
        kata += '!';   // tambah char
        cout << "\n  kata += '!' -> \"" << kata << "\"" << endl;

    // Gabung dalam loop
        cout << "\n  Gabung dengan loop:" << endl;
        string angkaStr = "";
        for (int i = 1; i <= 5; i++) {
            angkaStr += to_string(i);
            if (i < 5) angkaStr += "-";
        }
        cout << "  \"" << angkaStr << "\"" << endl;

    // Jebakan: tidak bisa gabung literal langsung
    // string salah = "Halo" + " Dunia";  <- BISA error (tergantung compiler)
    // string benar = string("Halo") + " Dunia";  <- aman
    // string benar = "Halo"s + " Dunia";          <- C++14
    cout << "\n  Catatan: jangan gabung dua string literal langsung:" << endl;
    cout << "  \"Halo\" + \" Dunia\"        <- bisa bermasalah!" << endl;
    cout << "  string(\"Halo\") + \" Dunia\" <- aman (cast ke string dulu)" << endl;
    cout << "  string s = \"Halo\"; s += \" Dunia\"; <- aman dan jelas" << endl;
}

void demoPerbandingan() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Perbandingan String" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Operator perbandingan: ==, !=, <, >, <=, >=" << endl;
    cout << "  Perbandingan LEXICOGRAPHIC (urutan kamus / ASCII)" << endl;

    string a = "apel";
    string b = "mangga";
    string c = "apel";
    string d = "ABC";

    cout << "\n  a = \"" << a << "\", b = \"" << b << "\", c = \"" << c << "\", d = \"" << d << "\"" << endl;

    cout << "\n  a == c  -> " << (a == c ? "true" : "false") << "  (sama persis)" << endl;
    cout << "  a != b  -> " << (a != b ? "true" : "false") << "  (berbeda)" << endl;
    cout << "  a == b  -> " << (a == b ? "true" : "false") << "  (berbeda)" << endl;

    cout << "\n  Perbandingan urutan kamus (lexicographic):" << endl;
    cout << "  a < b   -> " << (a < b ? "true" : "false") << "  (\"apel\" < \"mangga\" karena a < m)" << endl;
    cout << "  b > a   -> " << (b > a ? "true" : "false") << endl;

    cout << "\n  Perhatikan! Perbandingan CASE-SENSITIVE:" << endl;
    cout << "  a < d   -> " << (a < d ? "true" : "false") << "  (\"apel\" > \"ABC\" karena 'a'=97 > 'A'=65 dalam ASCII)" << endl;
    cout << "  d < a   -> " << (d < a ? "true" : "false") << endl;

    // Demo lexicographic
        cout << "\n  Cara kerja lexicographic:" << endl;
        cout << "  Bandingkan karakter per karakter dari kiri:" << endl;
        cout << "  \"abc\" vs \"abd\":" << endl;
        cout << "  a==a, b==b, c vs d: 'c' < 'd' -> \"abc\" < \"abd\"" << endl;
        cout << "  \"abc\" < \"abd\" -> " << ("abc" < string("abd") ? "true" : "false") << endl;

        cout << "\n  \"abc\" vs \"abcd\":" << endl;
        cout << "  a==a, b==b, c==c, lalu \"abc\" habis tapi \"abcd\" masih ada 'd'" << endl;
        cout << "  String lebih pendek dianggap lebih kecil" << endl;
        cout << "  \"abc\" < \"abcd\" -> " << (string("abc") < string("abcd") ? "true" : "false") << endl;
}

void demoPerbandinganInsensitive() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. Perbandingan Case-Insensitive" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Perbandingan bawaan SELALU case-sensitive." << endl;
    cout << "  Untuk case-insensitive: ubah dulu ke lowercase, baru bandingkan." << endl;

    string s1 = "Halo";
    string s2 = "halo";
    string s3 = "HALO";

    cout << "\n  s1=\"" << s1 << "\", s2=\"" << s2 << "\", s3=\"" << s3 << "\"" << endl;
    cout << "  s1 == s2  -> " << (s1 == s2 ? "true" : "false") << "  (case-sensitive)" << endl;
    cout << "  s1 == s3  -> " << (s1 == s3 ? "true" : "false") << "  (case-sensitive)" << endl;

    // Cara insensitive: konversi ke lowercase dulu
        string s1low = s1, s2low = s2, s3low = s3;
        transform(s1low.begin(), s1low.end(), s1low.begin(), ::tolower);
        transform(s2low.begin(), s2low.end(), s2low.begin(), ::tolower);
        transform(s3low.begin(), s3low.end(), s3low.begin(), ::tolower);

        cout << "\n  Setelah ubah ke lowercase:" << endl;
        cout << "  s1low=\"" << s1low << "\", s2low=\"" << s2low << "\", s3low=\"" << s3low << "\"" << endl;
        cout << "  s1low == s2low -> " << (s1low == s2low ? "true" : "false") << "  (case-insensitive)" << endl;
        cout << "  s1low == s3low -> " << (s1low == s3low ? "true" : "false") << "  (case-insensitive)" << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.3 -- Operasi Dasar String" << endl;
    cout << "============================================================" << endl;

    demoPanjangKosong();
    demoGabung();
    demoPerbandingan();
    demoPerbandinganInsensitive();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  s.length() / s.size()  -> jumlah karakter" << endl;
    cout << "  s.empty()              -> true jika kosong" << endl;
    cout << "  s1 + s2                -> gabung, buat string baru" << endl;
    cout << "  s1 += s2               -> tambah s2 ke s1" << endl;
    cout << "  ==, !=, <, >, <=, >=   -> bandingkan (lexicographic, case-sensitive)" << endl;
    cout << "  Case-insensitive: ubah ke lowercase dulu, lalu bandingkan" << endl;

    return 0;
}

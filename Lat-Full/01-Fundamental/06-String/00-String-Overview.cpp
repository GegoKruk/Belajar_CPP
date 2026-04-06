#include <iostream>
#include <string>
using namespace std;

// DEMO PERBANDINGAN
    void demoTanpaString() {
        cout << "[ Menggunakan char[] -- cara lama, ribet ]" << endl;

        // Deklarasi harus tentukan ukuran maksimal
        char nama[50] = "Gega";
        char kota[50] = "Yogyakarta";
        char gabungan[100];

        // Gabung string -- harus pakai fungsi strcpy + strcat
        // strcpy(gabungan, nama);
        // strcat(gabungan, " dari ");
        // strcat(gabungan, kota);
        // Kode di atas tidak ditampilkan karena butuh #include <cstring>

        cout << "  nama  : " << nama  << endl;
        cout << "  kota  : " << kota  << endl;
        cout << "  Untuk gabung: harus pakai strcpy() + strcat()" << endl;
        cout << "  Untuk bandingkan: harus pakai strcmp()" << endl;
        cout << "  Ukuran tetap, rawan buffer overflow!" << endl;
        (void)gabungan;
    }

    void denganString() {
        cout << "\n[ Menggunakan std::string -- cara modern, mudah ]" << endl;

        string nama = "Gega";
        string kota = "Yogyakarta";

        // Gabung langsung pakai +
        string gabungan = nama + " dari " + kota;

        // Bandingkan langsung pakai ==
        bool sama = (nama == "Gega");

        cout << "  nama     : " << nama     << endl;
        cout << "  kota     : " << kota     << endl;
        cout << "  gabungan : " << gabungan << endl;
        cout << "  nama == \"Gega\"? " << (sama ? "ya" : "tidak") << endl;
        cout << "  Panjang nama  : " << nama.length() << " karakter" << endl;
        cout << "  Ukuran dinamis, otomatis resize, aman!" << endl;
    }

    void tabelPerbandingan() {
        cout << "\n[ Perbandingan char[] vs std::string ]" << endl;
        cout << R"(
            +---------------------+-------------------------+---------------------------+
            | Aspek               | char[] (C-style)        | std::string (modern)      |
            +---------------------+-------------------------+---------------------------+
            | Header              | <cstring>               | <string>                  |
            | Deklarasi           | char s[20] = "Halo";    | string s = "Halo";        |
            | Ukuran              | Tetap (fixed)           | Dinamis (auto resize)     |
            | Null terminator     | Wajib kelola manual     | Otomatis                  |
            | Panjang             | strlen(s)               | s.length() / s.size()     |
            | Gabung              | strcat(s1, s2)          | s1 + s2  atau  s1 += s2   |
            | Bandingkan          | strcmp(s1, s2) == 0     | s1 == s2 (langsung!)      |
            | Input kalimat       | cin.getline(s, size)    | getline(cin, s)           |
            | Buffer overflow     | Rawan (berbahaya!)      | Aman (otomatis resize)    |
            | Akses karakter      | s[i]                    | s[i] atau s.at(i)         |
            | Salin               | strcpy(dst, src)        | dst = src (langsung!)     |
            | Kosongkan           | strcpy(s, "")           | s.clear() atau s = ""     |
            | Cari substring      | strstr(s, "sub")        | s.find("sub")             |
            | Rekomendasi         | Library C lama saja     | Semua kode C++ modern     |
            +---------------------+-------------------------+---------------------------+
        )";
    }

    void cheatSheet() {
        cout << "[ Cheat Sheet -- Ringkasan Semua Method std::string ]" << endl;
        cout << R"(
            DEKLARASI & INISIALISASI:
                string s = "teks";        -> cara paling umum
                string s("teks");         -> constructor syntax
                string s;                 -> string kosong ""
                string s(5, '*');         -> "*****" (5 karakter bintang)

            INFO DASAR:
                s.length() / s.size()     -> jumlah karakter
                s.empty()                 -> true jika kosong
                s.capacity()              -> memori yang dialokasikan

            AKSES KARAKTER:
                s[i]                      -> akses karakter index i (cepat, tidak cek batas)
                s.at(i)                   -> akses karakter index i (aman, cek batas)
                s.front()                 -> karakter pertama
                s.back()                  -> karakter terakhir

            OPERASI DASAR:
                s1 + s2                   -> gabung, buat string baru
                s1 += s2                  -> tambah s2 ke belakang s1
                s1 == s2                  -> bandingkan (true/false)
                s1 < s2                   -> bandingkan urutan kamus (lexicographic)

            MODIFIKASI:
                s.push_back('!')          -> tambah karakter di akhir
                s.pop_back()              -> hapus karakter terakhir
                s.clear()                 -> kosongkan semua isi
                s.resize(n)               -> ubah panjang jadi n
                s.insert(pos, str)        -> sisipkan di posisi pos
                s.erase(pos, len)         -> hapus len karakter dari pos
                s.replace(pos, len, baru) -> ganti len karakter dari pos

            PENCARIAN:
                s.find("sub")             -> index pertama, atau string::npos jika tidak ada
                s.rfind("sub")            -> cari dari belakang
                s.find_first_of("abc")    -> index karakter pertama yang ada di "abc"
                s.find_last_of("abc")     -> index karakter terakhir yang ada di "abc"

            POTONG & EKSTRAK:
                s.substr(pos, len)        -> ambil substring dari pos sepanjang len
                s.substr(pos)             -> ambil dari pos sampai akhir

            KONVERSI:
                to_string(42)             -> "42"  (angka ke string)
                stoi("42")                -> 42    (string ke int)
                stod("3.14")              -> 3.14  (string ke double)
                s.c_str()                 -> const char* (ke C-string, read-only)

            ALGORITMA (butuh <algorithm> + <cctype>):
                reverse(s.begin(), s.end())                           -> balik string
                transform(s.begin(), s.end(), s.begin(), ::tolower)   -> lowercase
                transform(s.begin(), s.end(), s.begin(), ::toupper)   -> UPPERCASE
                count(s.begin(), s.end(), 'a')                        -> hitung karakter 'a'

            INPUT/OUTPUT:
                cin >> s                  -> baca satu kata (berhenti di spasi)
                getline(cin, s)           -> baca satu baris penuh
                getline(cin, s, '|')      -> baca sampai delimiter '|'
                cout << s                 -> tampilkan

            PARAMETER FUNCTION (panduan):
                void f(string s)          -> by value, buat salinan (mahal)
                void f(const string& s)   -> const ref, tidak salin, tidak bisa ubah (TERBAIK)
                void f(string& s)         -> ref, bisa modifikasi langsung
        )";
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.0 -- Pengantar String C++" << endl;
    cout << "============================================================" << endl;

    demoTanpaString();
    denganString();
    tabelPerbandingan();
    cheatSheet();

    cout << "============================================================" << endl;
    cout << "  Urutan Belajar Selanjutnya:" << endl;
    cout << "============================================================" << endl;
    cout << "  01-Deklarasi-Inisialisasi.cpp  : Cara membuat string" << endl;
    cout << "  02-Akses-Karakter.cpp          : Akses & iterasi karakter" << endl;
    cout << "  03-Operasi-Dasar.cpp           : length, gabung, bandingkan" << endl;
    cout << "  04-Modifikasi-String.cpp       : insert, erase, replace, dll" << endl;
    cout << "  05-Pencarian-String.cpp        : find, rfind, npos" << endl;
    cout << "  06-Substr-dan-Split.cpp        : substr, tokenisasi, split" << endl;
    cout << "  07-Input-Output-String.cpp     : cin, getline, cin.ignore" << endl;
    cout << "  08-Konversi-Angka-String.cpp   : stoi, stod, to_string" << endl;
    cout << "  09-Case-dan-Karakter.cpp       : tolower, toupper, isalpha" << endl;
    cout << "  10-Algoritma-String.cpp        : reverse, palindrom, anagram" << endl;
    cout << "  11-String-dan-Function.cpp     : pass by value/ref/const ref" << endl;
    cout << "  12-Kesalahan-Umum.cpp          : 6 jebakan umum & solusinya" << endl;

    return 0;
}

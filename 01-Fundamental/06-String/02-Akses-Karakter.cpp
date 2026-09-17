

#include <iostream>
#include <string>
using namespace std;


// AKSES KARAKTER

void demoAksesIndex() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Akses dengan [] dan at()" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Halo";
    cout << "\n  string s = \"" << s << "\"  (panjang " << s.length() << ")" << endl;

    // Visualisasi
        cout << "\n  Posisi karakter:" << endl;
        cout << "  +-----+-----+-----+-----+" << endl;
        cout << "  |  H  |  a  |  l  |  o  |" << endl;
        cout << "  +-----+-----+-----+-----+" << endl;
        cout << "  | [0] | [1] | [2] | [3] |" << endl;
        cout << "  +-----+-----+-----+-----+" << endl;

    // Akses dengan []
        cout << "\n  Akses dengan []:" << endl;
        cout << "  s[0] = '" << s[0] << "'  (H)" << endl;
        cout << "  s[1] = '" << s[1] << "'  (a)" << endl;
        cout << "  s[2] = '" << s[2] << "'  (l)" << endl;
        cout << "  s[3] = '" << s[3] << "'  (o)" << endl;

    // Akses dengan at()
        cout << "\n  Akses dengan at():" << endl;
        cout << "  s.at(0) = '" << s.at(0) << "'  (sama hasilnya, tapi lebih aman)" << endl;
        cout << "  s.at(3) = '" << s.at(3) << "'" << endl;

    // Demonstrasi at() lebih aman
        cout << "\n  Perbedaan saat index salah:" << endl;
        cout << "  s[10]    -> undefined behavior! Tidak ada error message, bisa crash diam-diam" << endl;
        cout << "  s.at(10) -> melempar std::out_of_range exception (bisa ditangkap)" << endl;

    // Demo try-catch untuk at()
        try {
            char c = s.at(99);   // index tidak valid
            (void)c;
        } catch (const out_of_range& e) {
            cout << "  Exception tertangkap: " << e.what() << endl;
            cout << "  Program tidak crash! at() melindungi kita." << endl;
        }

    // Index terakhir yang valid
        cout << "\n  Index terakhir yang valid:" << endl;
        cout << "  s.length() - 1 = " << s.length()-1 << endl;
        cout << "  s[s.length()-1] = '" << s[s.length()-1] << "'" << endl;
}

void demoFrontBack() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. front() dan back() -- Karakter Pertama & Terakhir" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Pemrograman";

    cout << "\n  string s = \"" << s << "\"" << endl;
    cout << "  s.front()       = '" << s.front() << "'  (karakter pertama)" << endl;
    cout << "  s.back()        = '" << s.back()  << "'  (karakter terakhir)" << endl;
    cout << "  s[0]            = '" << s[0]       << "'  (sama dengan front())" << endl;
    cout << "  s[s.length()-1] = '" << s[s.length()-1] << "'  (sama dengan back())" << endl;

    cout << "\n  Contoh penggunaan:" << endl;
    // Cek apakah string diakhiri '!'
        string kalimat1 = "Halo!";
        string kalimat2 = "Halo";
        cout << "  \"" << kalimat1 << "\".back() == '!' ? " << (kalimat1.back() == '!' ? "ya" : "tidak") << endl;
        cout << "  \"" << kalimat2 << "\".back() == '!' ? " << (kalimat2.back() == '!' ? "ya" : "tidak") << endl;

    // Cek apakah diawali huruf kapital
        string kata = "Gega";
        cout << "  \"" << kata << "\".front() >= 'A' && <= 'Z' ? " << (kata.front() >= 'A' && kata.front() <= 'Z' ? "ya, kapital" : "tidak") << endl;
}

void demoModifikasiKarakter() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Modifikasi Karakter Lewat []" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "hello world";
    cout << "\n  Sebelum: \"" << s << "\"" << endl;

    // Ubah karakter pertama jadi kapital
        s[0] = 'H';
        cout << "  s[0] = 'H'  -> \"" << s << "\"" << endl;

    // Ubah semua karakter 'l' jadi 'L'
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == 'l') s[i] = 'L';
        }
        cout << "  Ganti 'l' jadi 'L' -> \"" << s << "\"" << endl;

    // Ubah dengan front() dan back()
        string nama = "gega";
        nama.front() = 'G';   // front() mengembalikan referensi!
        cout << "\n  nama = \"gega\", nama.front() = 'G' -> \"" << nama << "\"" << endl;
}

void demoIterasi() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. Iterasi Karakter -- Tiga Cara" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "C++ Asyik";
    cout << "\n  string s = \"" << s << "\"" << endl;

    // Cara 1: Range-based for (paling modern & bersih)
        cout << "\n  Cara 1 -- Range-based for (paling direkomendasikan):" << endl;
        cout << "  for (char c : s) -> ";
        for (char c : s) cout << "[" << c << "]";
        cout << endl;

    // Cara 2: Index-based (kalau perlu index)
        cout << "\n  Cara 2 -- Index-based (kalau perlu index):" << endl;
        cout << "  for (int i = 0; i < s.size(); i++)" << endl;
        for (int i = 0; i < (int)s.size(); i++) {
            cout << "    s[" << i << "] = '" << s[i] << "'" << endl;
        }

    // Cara 3: Iterator (gaya STL)
        cout << "\n  Cara 3 -- Iterator (gaya STL):" << endl;
        cout << "  for (auto it = s.begin(); it != s.end(); it++) -> ";
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it;
        }
        cout << endl;

    // Iterasi terbalik
        cout << "\n  Iterasi terbalik dengan rbegin/rend: ";
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            cout << *it;
        }
        cout << endl;
}

void demoIterasiModifikasi() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Iterasi dengan Referensi untuk Modifikasi" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "hello world";
    cout << "\n  Sebelum: \"" << s << "\"" << endl;

    // Range-based for dengan referensi -- bisa modifikasi
        for (char &c : s) {
            if (c >= 'a' && c <= 'z') c = c - 32;  // lowercase to uppercase manual
        }
        cout << "  Setelah  for (char &c : s) { ubah ke uppercase }:" << endl;
        cout << "  Sesudah: \"" << s << "\"" << endl;

        cout << "\n  Tanpa &: salinan karakter, asli tidak berubah" << endl;
        cout << "  Dengan &: referensi ke karakter asli, bisa diubah" << endl;
}

void demoPraktis() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  6. Contoh Praktis" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Hitung kemunculan karakter
        string kalimat = "belajar pemrograman c++ itu sangat menyenangkan";
        char cari = 'a';
        int hitung = 0;
        for (char c : kalimat) if (c == cari) hitung++;
        cout << "\n  Hitung '" << cari << "' di \"" << kalimat.substr(0, 20) << "...\"" << endl;
    cout << "  Muncul " << hitung << " kali" << endl;

    // Cek apakah semua angka
        string angkaStr = "12345";
        string campuran = "abc123";
        bool semuaAngka = true;
        for (char c : angkaStr) if (c < '0' || c > '9') { semuaAngka = false; break; }
        cout << "\n  \"" << angkaStr << "\" semua angka? " << (semuaAngka ? "ya" : "tidak") << endl;

        semuaAngka = true;
        for (char c : campuran) if (c < '0' || c > '9') { semuaAngka = false; break; }
        cout << "  \"" << campuran << "\" semua angka? " << (semuaAngka ? "ya" : "tidak") << endl;

    // Cari index karakter spesifik
        string s = "Pemrograman";
        cout << "\n  Cari karakter di \"" << s << "\":" << endl;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == 'a') cout << "  'a' di index [" << i << "]" << endl;
        }
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.2 -- Akses & Iterasi Karakter" << endl;
    cout << "============================================================" << endl;

    demoAksesIndex();
    demoFrontBack();
    demoModifikasiKarakter();
    demoIterasi();
    demoIterasiModifikasi();
    demoPraktis();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  s[i]       -> cepat, tidak cek batas (pakai jika yakin valid)" << endl;
    cout << "  s.at(i)    -> aman, lempar exception jika out of bounds" << endl;
    cout << "  s.front()  -> karakter pertama (= s[0])" << endl;
    cout << "  s.back()   -> karakter terakhir (= s[s.length()-1])" << endl;
    cout << "  for(char c : s)   -> iterasi baca (tidak bisa modifikasi)" << endl;
    cout << "  for(char &c : s)  -> iterasi dengan modifikasi" << endl;
    cout << "  for(int i=0; i<s.size(); i++) -> kalau perlu index" << endl;

    return 0;
}

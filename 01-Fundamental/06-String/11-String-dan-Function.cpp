
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


// TIGA CARA PASS STRING KE FUNCTION



// ---- Pass by Value ----
// Buat salinan -- asli tidak berpengaruh, tapi overhead copy
    void cetakDanUbahValue(string s) {
        cout << "  Di dalam function (value): \"" << s << "\"" << endl;
        s += " [DIUBAH]";   // ubah salinan
        cout << "  Setelah diubah: \"" << s << "\"" << endl;
        // s asli tidak berubah
    }

// ---- Pass by Reference ----
// Alias ke asli -- perubahan mempengaruhi asli
    void tambahSuffix(string &s, const string &suffix) {
        s += suffix;   // ubah asli!
    }

    void ubahKeUppercase(string &s) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }

// ---- Pass by Const Reference ----
// Efisien + aman, tidak bisa diubah
    int hitungKarakter(const string &s, char target) {
        int count = 0;
        for (char c : s) if (c == target) count++;
        return count;
    }

    bool mengandungSubstring(const string &teks, const string &sub) {
        return teks.find(sub) != string::npos;
    }

    string buatGaris(const string &judul, int lebar = 40) {
        int sisaKiri  = (lebar - (int)judul.length() - 2) / 2;
        int sisaKanan = lebar - (int)judul.length() - 2 - sisaKiri;
        string garis = "";
        for (int i = 0; i < sisaKiri; i++) garis += '-';
        garis += " " + judul + " ";
        for (int i = 0; i < sisaKanan; i++) garis += '-';
        return garis;
    }


// ---- Return String ----
    string ulangString(const string &s, int n) {
        string hasil = "";
        for (int i = 0; i < n; i++) hasil += s;
        return hasil;
    }

    string balikString(const string &s) {
        return string(s.rbegin(), s.rend());
    }

    string gantiSemua(string s, const string &dari, const string &ke) {
        size_t pos = s.find(dari);
        while (pos != string::npos) {
            s.replace(pos, dari.length(), ke);
            pos = s.find(dari, pos + ke.length());
        }
        return s;
    }

    string ucapanSelamat(const string &nama, int nilai) {
        if (nilai >= 90) return "Selamat " + nama + "! Nilai sempurna!";
        if (nilai >= 75) return "Bagus " + nama + "! Kamu lulus!";
        return nama + ", ayo belajar lebih giat lagi!";
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.11 -- String & Function" << endl;
    cout << "============================================================" << endl;

    // Pass by Value
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  1. Pass by Value -- Salinan, Asli Tidak Berubah" << endl;
        cout << "------------------------------------------------------------" << endl;

        string s1 = "Halo Dunia";
        cout << "\n  Sebelum panggil: \"" << s1 << "\"" << endl;
        cetakDanUbahValue(s1);
        cout << "  Setelah panggil: \"" << s1 << "\"  <- tidak berubah!" << endl;
        cout << "\n  Mahal untuk string panjang karena harus salin semua karakter." << endl;

    // Pass by Reference
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  2. Pass by Reference -- Asli Ikut Berubah" << endl;
        cout << "------------------------------------------------------------" << endl;

        string s2 = "Belajar C++";
        cout << "\n  Sebelum tambahSuffix: \"" << s2 << "\"" << endl;
        tambahSuffix(s2, " itu Seru!");
        cout << "  Setelah tambahSuffix: \"" << s2 << "\"  <- asli berubah!" << endl;

        string s3 = "hello world";
        cout << "\n  Sebelum ubahKeUppercase: \"" << s3 << "\"" << endl;
        ubahKeUppercase(s3);
        cout << "  Setelah ubahKeUppercase: \"" << s3 << "\"  <- asli berubah!" << endl;

    // Pass by Const Reference
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  3. Pass by Const Reference -- TERBAIK untuk Read-Only" << endl;
        cout << "------------------------------------------------------------" << endl;

        string kalimat = "Belajar pemrograman adalah hal yang menyenangkan";
        cout << "\n  kalimat = \"" << kalimat << "\"" << endl;
        cout << "  hitungKarakter(kalimat, 'a')           = "
            << hitungKarakter(kalimat, 'a') << endl;
        cout << "  mengandungSubstring(kalimat, \"program\") = "
            << (mengandungSubstring(kalimat, "program") ? "ya" : "tidak") << endl;
        cout << "  mengandungSubstring(kalimat, \"Java\")    = "
            << (mengandungSubstring(kalimat, "Java") ? "ya" : "tidak") << endl;
        cout << "  kalimat asli: \"" << kalimat << "\"  <- tidak berubah!" << endl;

    // Return String
        cout << "\n------------------------------------------------------------" << endl;
        cout << "  4. Return String dari Function" << endl;
        cout << "------------------------------------------------------------" << endl;

        string s = "Ha";
        cout << "\n  ulangString(\"Ha\", 5) = \"" << ulangString(s, 5) << "\"" << endl;
        cout << "  balikString(\"Halo\")  = \"" << balikString("Halo") << "\"" << endl;

        string teks = "the cat sat on the mat in the hat";
        cout << "\n  gantiSemua(\"the\" -> \"a\"):" << endl;
        cout << "  \"" << gantiSemua(teks, "the", "a") << "\"" << endl;

        cout << "\n  ucapanSelamat():" << endl;
        cout << "  " << ucapanSelamat("Gega",  95) << endl;
        cout << "  " << ucapanSelamat("Budi",  80) << endl;
        cout << "  " << ucapanSelamat("Citra", 60) << endl;

        cout << "\n  buatGaris(judul):" << endl;
        cout << "  " << buatGaris("LAPORAN NILAI") << endl;
        cout << "  " << buatGaris("SELESAI", 30) << endl;

    // Tabel perbandingan
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Perbandingan Ketiga Cara" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << R"(
        +-------------------+-----------------+------------------+--------------------+
        | Aspek             | by Value        | by Reference     | by Const Reference |
        +-------------------+-----------------+------------------+--------------------+
        | Salinan dibuat    | Ya (mahal)      | Tidak            | Tidak              |
        | Ubah asli         | Tidak           | Ya               | Tidak              |
        | Keamanan          | Aman            | Perlu hati-hati  | Aman               |
        | Performa          | Lambat (copy)   | Cepat            | Cepat              |
        | Sintaks           | void f(string s)| void f(string &s)| void f(const str&s)|
        | Kapan pakai       | Butuh modif     | Perlu ubah asli  | Hanya baca         |
        |                   | lokal saja      |                  | (TERBAIK)          |
        +-------------------+-----------------+------------------+--------------------+

        PANDUAN SINGKAT:
        - Hanya baca string  -> const string& s  (SELALU pakai ini!)
        - Perlu ubah asli    -> string& s
        - Modifikasi lokal   -> string s  (jarang dibutuhkan)
    )";

    return 0;
}

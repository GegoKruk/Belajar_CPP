
#include <iostream>
#include <string>
#include <algorithm>   // reverse, count, sort
#include <sstream>     // stringstream
#include <cctype>      // tolower
using namespace std;


void demoReverse() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Reverse String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Halo Dunia";
    cout << "\n  s = \"" << s << "\"" << endl;

    // Cara 1: reverse() -- modifikasi in-place
        string s1 = s;
        reverse(s1.begin(), s1.end());
        cout << "  reverse(s.begin(), s.end()) -> \"" << s1 << "\"" << endl;

    // Cara 2: buat string baru dari iterator terbalik
        string s2(s.rbegin(), s.rend());
        cout << "  string(s.rbegin(),s.rend()) -> \"" << s2 << "\"" << endl;

    // Cara 3: manual dengan loop
        string s3 = "";
        for (int i = (int)s.length() - 1; i >= 0; i--) s3 += s[i];
        cout << "  Loop manual                 -> \"" << s3 << "\"" << endl;

        cout << "\n  s asli tidak berubah: \"" << s << "\"" << endl;
}

void demoCount() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. count() -- Hitung Kemunculan Karakter" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "banana pisang nanas";
    cout << "\n  s = \"" << s << "\"" << endl;

    // Hitung dengan count() dari <algorithm>
        int jumlahA = count(s.begin(), s.end(), 'a');
        int jumlahN = count(s.begin(), s.end(), 'n');
        int jumlahSpasi = count(s.begin(), s.end(), ' ');

        cout << "  Jumlah 'a'  : " << jumlahA     << endl;
        cout << "  Jumlah 'n'  : " << jumlahN     << endl;
        cout << "  Jumlah spasi: " << jumlahSpasi << endl;

    // Hitung kemunculan substring
        cout << "\n  Hitung kemunculan substring \"an\":" << endl;
        string cari = "an";
        int hitungan = 0;
        size_t pos = s.find(cari);
        while (pos != string::npos) {
            hitungan++;
            pos = s.find(cari, pos + 1);
        }
        cout << "  \"an\" muncul " << hitungan << " kali" << endl;
}

void demoPalindrom() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Cek Palindrom" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Palindrom = string yang sama jika dibaca maju dan mundur" << endl;
    cout << "  Contoh: \"kasur rusak\", \"level\", \"civic\"" << endl;

    auto isPalindrom = [](string s) -> bool {
        // Normalize: lowercase, hapus spasi dan tanda baca
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) cleaned += tolower(c);
        }
        string reversed(cleaned.rbegin(), cleaned.rend());
        return cleaned == reversed;
    };

    string tests[] = {
        "level", "hello", "kasur rusak", "A man a plan a canal Panama",
        "race a car", "Was it a car or a cat I saw"
    };

    cout << "\n  Tes palindrom:" << endl;
    for (const string &t : tests) {
        cout << "  \"" << t << "\" -> " << (isPalindrom(t) ? "PALINDROM" : "bukan palindrom") << endl;
    }
}

void demoAnagram() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. Cek Anagram" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Anagram = dua kata yang tersusun dari huruf yang sama" << endl;
    cout << "  Contoh: \"listen\" dan \"silent\", \"eat\" dan \"tea\"" << endl;

    auto isAnagram = [](string a, string b) -> bool {
        // Lowercase dan sort, lalu bandingkan
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        // Hapus spasi
        a.erase(remove(a.begin(), a.end(), ' '), a.end());
        b.erase(remove(b.begin(), b.end(), ' '), b.end());
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    };

    cout << "\n  Tes anagram:" << endl;
    pair<string,string> tests[] = {
        {"listen", "silent"},
        {"hello", "world"},
        {"Astronomer", "Moon starer"},
        {"eat", "tea"},
        {"cat", "dog"}
    };

    for (auto &p : tests) {
        cout << "  \"" << p.first << "\" & \"" << p.second << "\" -> " << (isAnagram(p.first, p.second) ? "ANAGRAM" : "bukan anagram") << endl;
    }
}

void demoTrimDanLainnya() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Trim Spasi, Prefix/Suffix, Ganti Semua" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Trim spasi di kiri dan kanan
        cout << "\n  Trim spasi:" << endl;
        string s = "   Halo Dunia   ";
        cout << "  s = \"" << s << "\"" << endl;

        string trimmed = s;

    // Trim kiri
        size_t start = trimmed.find_first_not_of(" \t\n\r");
        if (start != string::npos) trimmed = trimmed.substr(start);
        else trimmed = "";
        // Trim kanan
        size_t end = trimmed.find_last_not_of(" \t\n\r");
        if (end != string::npos) trimmed = trimmed.substr(0, end + 1);

        cout << "  Setelah trim: \"" << trimmed << "\"" << endl;

    // Cek prefix dan suffix
        cout << "\n  Cek prefix dan suffix (C++20 ada starts_with/ends_with):" << endl;
        string url = "https://www.example.com";
        cout << "  url = \"" << url << "\"" << endl;

        bool isHttps = url.substr(0, 8) == "https://";
        bool dotCom  = url.length() >= 4 && url.substr(url.length()-4) == ".com";

        cout << "  Dimulai dengan \"https://\"? " << (isHttps ? "ya" : "tidak") << endl;
        cout << "  Diakhiri dengan \".com\"?    " << (dotCom  ? "ya" : "tidak") << endl;

    // Ganti semua kemunculan
        cout << "\n  Ganti semua kemunculan substring:" << endl;
        string teks = "the cat sat on the mat near the hat";
        cout << "  Sebelum: \"" << teks << "\"" << endl;

        string dari = "the", ke = "a";
        size_t pos = teks.find(dari);
        while (pos != string::npos) {
            teks.replace(pos, dari.length(), ke);
            pos = teks.find(dari, pos + ke.length());
        }
        cout << "  Ganti \"the\" -> \"a\":" << endl;
        cout << "  Sesudah: \"" << teks << "\"" << endl;

    // Hitung kata
        cout << "\n  Hitung kata dalam kalimat:" << endl;
        string kalimat = "Belajar C++ itu sangat menyenangkan sekali";
        stringstream ss(kalimat);
        string kata;
        int hitungan = 0;
        while (ss >> kata) hitungan++;
        cout << "  \"" << kalimat << "\"" << endl;
        cout << "  Jumlah kata: " << hitungan << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.10 -- Algoritma pada String" << endl;
    cout << "============================================================" << endl;

    demoReverse();
    demoCount();
    demoPalindrom();
    demoAnagram();
    demoTrimDanLainnya();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  reverse(s.begin(), s.end())    -> balik string in-place" << endl;
    cout << "  string(s.rbegin(), s.rend())   -> buat string baru yang dibalik" << endl;
    cout << "  count(s.begin(), s.end(), 'c') -> hitung kemunculan 'c'" << endl;
    cout << "  Palindrom: s == reverse(s)" << endl;
    cout << "  Anagram  : sort(a) == sort(b)" << endl;
    cout << "  Trim     : find_first_not_of + substr" << endl;

    return 0;
}

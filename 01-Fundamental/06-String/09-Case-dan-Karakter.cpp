
#include <iostream>
#include <string>
#include <algorithm>   // transform
#include <cctype>      // tolower, toupper, isalpha, isdigit, dll
using namespace std;


void demoCaseConversion() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. Konversi Case (Huruf Besar/Kecil)" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Hello World C++ 2024!";
    cout << "\n  s = \"" << s << "\"" << endl;

    // Konversi ke lowercase
        string lower = s;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        cout << "  Lowercase  : \"" << lower << "\"" << endl;

    // Konversi ke uppercase
        string upper = s;
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        cout << "  UPPERCASE  : \"" << upper << "\"" << endl;

    // Cara manual per karakter
        cout << "\n  Cara manual per karakter:" << endl;
        string manual = "hello";
        for (char &c : manual) {
            c = toupper(c);
        }
        cout << "  \"hello\" diubah ke uppercase manual: \"" << manual << "\"" << endl;

    // Title case -- huruf pertama tiap kata kapital
        cout << "\n  Title Case (huruf pertama tiap kata kapital):" << endl;
        string kalimat = "belajar pemrograman c++ itu menyenangkan";
        cout << "  Sebelum: \"" << kalimat << "\"" << endl;

        // Ubah dulu ke lowercase semua
            transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);
        // Huruf pertama kapital
            kalimat[0] = toupper(kalimat[0]);
        // Setiap karakter setelah spasi kapital
            for (int i = 1; i < (int)kalimat.length(); i++) {
                if (kalimat[i-1] == ' ') kalimat[i] = toupper(kalimat[i]);
            }
            cout << "  Sesudah  : \"" << kalimat << "\"" << endl;
}

void demoKlasifikasiKarakter() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. Klasifikasi Karakter dari <cctype>" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Fungsi-fungsi klasifikasi karakter:" << endl;
    cout << "  +------------------+----------------------------------+" << endl;
    cout << "  | Fungsi           | True jika...                     |" << endl;
    cout << "  +------------------+----------------------------------+" << endl;
    cout << "  | isalpha(c)       | Huruf (a-z, A-Z)                 |" << endl;
    cout << "  | isdigit(c)       | Angka (0-9)                      |" << endl;
    cout << "  | isalnum(c)       | Huruf atau angka                 |" << endl;
    cout << "  | isupper(c)       | Huruf kapital (A-Z)              |" << endl;
    cout << "  | islower(c)       | Huruf kecil (a-z)                |" << endl;
    cout << "  | isspace(c)       | Whitespace (spasi, tab, newline) |" << endl;
    cout << "  | ispunct(c)       | Tanda baca (! . , ; dll)         |" << endl;
    cout << "  +------------------+----------------------------------+" << endl;

    // Demo dengan berbagai karakter
    cout << "\n  Demo per karakter:" << endl;
    char chars[] = {'A', 'z', '5', ' ', '!', '@'};
    for (char c : chars) {
        cout << "  '" << c << "': " << endl;
        cout << "alpha = " << (isalpha(c)?"y":"n") << endl;
        cout << " digit = " << (isdigit(c)?"y":"n") << endl;
        cout << " alnum = " << (isalnum(c)?"y":"n") << endl;
        cout << " upper = " << (isupper(c)?"y":"n") << endl;
        cout << " lower = " << (islower(c)?"y":"n") << endl;
        cout << " space = " << (isspace(c)?"y":"n") << endl;
        cout << " punct = " << (ispunct(c)?"y":"n") << endl;
        cout << endl;
    }
}

void demoValidasiInput() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Aplikasi: Validasi Input" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Validasi username: hanya huruf dan angka
        auto isUsernameValid = [](const string &s) -> bool {
            if (s.empty() || s.length() < 3) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_') return false;
            }
            return true;
        };

        cout << "\n  Validasi username (min 3 char, hanya huruf/angka/underscore):" << endl;
        string usernames[] = {"gega123", "ab", "budi.santoso", "citra_dewi", "user name"};
        for (const string &u : usernames) {
            cout << "  \"" << u << "\" -> " << (isUsernameValid(u) ? "valid" : "tidak valid") << endl;
        }

    // Hitung jenis karakter
        cout << "\n  Analisis karakter dalam string:" << endl;
        string teks = "Halo C++ 2024!";
        int huruf=0, angka=0, spasi=0, lainnya=0;
        for (char c : teks) {
            if (isalpha(c))      huruf++;
            else if (isdigit(c)) angka++;
            else if (isspace(c)) spasi++;
            else                 lainnya++;
        }
        cout << "  \"" << teks << "\"" << endl;
        cout << "  Huruf  : " << huruf   << endl;
        cout << "  Angka  : " << angka   << endl;
        cout << "  Spasi  : " << spasi   << endl;
        cout << "  Lainnya: " << lainnya << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.9 -- Case Conversion & Klasifikasi Karakter" << endl;
    cout << "============================================================" << endl;

    demoCaseConversion();
    demoKlasifikasiKarakter();
    demoValidasiInput();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  tolower(c) / toupper(c)                      -> satu karakter" << endl;
    cout << "  transform(s.begin(),s.end(),s.begin(),::tolower) -> seluruh string" << endl;
    cout << "  isalpha(c), isdigit(c), isalnum(c)           -> klasifikasi" << endl;
    cout << "  isupper(c), islower(c), isspace(c), ispunct(c) -> klasifikasi" << endl;

    return 0;
}

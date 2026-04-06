
#include <iostream>
#include <string>
using namespace std;

void demoFind() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. find() -- Cari dari Kiri (Depan)" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Belajar C++ itu Belajar terus menerus";
    cout << "\n  s = \"" << s << "\"" << endl;
    cout << "   idx: 0123456789..." << endl;

    // find substring
        size_t pos1 = s.find("Belajar");
        cout << "\n  s.find(\"Belajar\")     = " << pos1
            << "  (kemunculan pertama)" << endl;

    // find dengan starting position -- mulai cari dari index tertentu
        size_t pos2 = s.find("Belajar", pos1 + 1);
        cout << "  s.find(\"Belajar\",8)   = " << pos2
            << "  (mulai cari dari index 8)" << endl;

    // find karakter tunggal
        size_t pos3 = s.find('C');
        cout << "  s.find('C')          = " << pos3 << endl;

        size_t pos4 = s.find('z');
        cout << "  s.find('z')          = "
            << (pos4 == string::npos ? "npos (tidak ada)" : to_string(pos4)) << endl;

    // WAJIB cek npos!
        cout << "\n  Cara benar menggunakan find():" << endl;
        if (pos1 != string::npos) {
            cout << "  \"Belajar\" ditemukan di index [" << pos1 << "]" << endl;
        } else {
            cout << "  \"Belajar\" tidak ditemukan" << endl;
        }

    // Cek apakah mengandung substring
        bool ada = s.find("C++") != string::npos;
        cout << "  Mengandung \"C++\"? " << (ada ? "ya" : "tidak") << endl;

    // Cari semua kemunculan
        cout << "\n  Semua posisi \"Belajar\" dalam string:" << endl;
        string cari = "Belajar";
        size_t pos = s.find(cari);
        while (pos != string::npos) {
            cout << "  - index [" << pos << "]" << endl;
            pos = s.find(cari, pos + 1);
        }
}

void demoRfind() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. rfind() -- Cari dari Kanan (Belakang)" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "abcabc";
    cout << "\n  s = \"" << s << "\"" << endl;

    size_t f  = s.find("abc");
    size_t rf = s.rfind("abc");
    cout << "  s.find(\"abc\")   = " << f  << "  (kemunculan pertama dari kiri)" << endl;
    cout << "  s.rfind(\"abc\")  = " << rf << "  (kemunculan pertama dari kanan)" << endl;

    string s2 = "data/file/nama.txt";
    cout << "\n  s2 = \"" << s2 << "\"" << endl;

    // Ambil nama file (setelah '/' terakhir)
        size_t lastSlash = s2.rfind('/');
        if (lastSlash != string::npos) {
            string namaFile = s2.substr(lastSlash + 1);
            cout << "  s2.rfind('/') = " << lastSlash << endl;
            cout << "  Nama file     = \"" << namaFile << "\"" << endl;
        }

    // Ambil ekstensi file (setelah '.' terakhir)
        size_t lastDot = s2.rfind('.');
        if (lastDot != string::npos) {
            string ekstensi = s2.substr(lastDot + 1);
            cout << "  Ekstensi      = \"" << ekstensi << "\"" << endl;
        }
}

void demoFindOf() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. find_first_of() & find_last_of()" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Cari posisi karakter PERTAMA yang ada di kumpulan karakter tertentu" << endl;

    string s = "Hello World";
    cout << "\n  s = \"" << s << "\"" << endl;

    // find_first_of -- cari vokal pertama
        size_t posVokal = s.find_first_of("aeiouAEIOU");
        cout << "  Vokal pertama   : index [" << posVokal << "] = '"
            << s[posVokal] << "'" << endl;

    // find_last_of -- cari vokal terakhir
        size_t posVokalLast = s.find_last_of("aeiouAEIOU");
        cout << "  Vokal terakhir  : index [" << posVokalLast << "] = '"
            << s[posVokalLast] << "'" << endl;

    // find_first_of -- cari digit pertama
        string kode = "Produk-ABC-001-2024";
        size_t posDigit = kode.find_first_of("0123456789");
        cout << "\n  kode = \"" << kode << "\"" << endl;
        cout << "  Digit pertama   : index [" << posDigit << "] = '"
            << kode[posDigit] << "'" << endl;

    // find_first_not_of -- cari karakter pertama yang BUKAN spasi (trim kiri)
        string spasi = "   Halo   ";
        size_t pertamaYgBukanSpasi = spasi.find_first_not_of(' ');
        size_t terakhirYgBukanSpasi = spasi.find_last_not_of(' ');
        cout << "\n  spasi = \"" << spasi << "\"" << endl;
        cout << "  find_first_not_of(' ') = " << pertamaYgBukanSpasi << endl;
        cout << "  find_last_not_of(' ')  = " << terakhirYgBukanSpasi << endl;

    // Trim kiri dan kanan
        string trimmed = spasi.substr(pertamaYgBukanSpasi,
                                    terakhirYgBukanSpasi - pertamaYgBukanSpasi + 1);
        cout << "  Setelah trim    : \"" << trimmed << "\"" << endl;
}

void demoNpos() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. string::npos -- Penanda Tidak Ditemukan" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  string::npos = " << string::npos << " (nilai paling besar)" << endl;
    cout << "  Artinya: substring/karakter tidak ditemukan" << endl;

    cout << "\n  WAJIB selalu cek npos sebelum pakai hasil find!" << endl;
    cout << "\n  Contoh BENAR:" << endl;
    cout << "  size_t pos = s.find(\"sub\");" << endl;
    cout << "  if (pos != string::npos) { pakai pos; }" << endl;
    cout << "  else { tidak ditemukan; }" << endl;

    cout << "\n  Contoh SALAH (tidak cek npos):" << endl;
    cout << "  size_t pos = s.find(\"sub\");" << endl;
    cout << "  string hasil = s.substr(pos, 3);  // CRASH jika pos = npos!" << endl;

    // Demo berbagai kondisi
        string s = "Belajar C++";
        cout << "\n  s = \"" << s << "\"" << endl;

        string cariList[] = {"C++", "Java", "Belajar", "Python"};
        for (const string &cari : cariList) {
            size_t pos = s.find(cari);
            if (pos != string::npos) {
                cout << "  \"" << cari << "\" -> ketemu di index [" << pos << "]" << endl;
            } else {
                cout << "  \"" << cari << "\" -> tidak ditemukan (npos)" << endl;
            }
    }
}

void demoPraktis() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Contoh Praktis" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Cek ekstensi file
        cout << "\n  Cek ekstensi file:" << endl;
        string files[] = {"gambar.png", "dokumen.pdf", "kode.cpp", "tidakadaekstensi"};
        for (const string &f : files) {
            size_t pos = f.rfind('.');
            if (pos != string::npos) {
                cout << "  \"" << f << "\" -> ekstensi: \"" << f.substr(pos+1) << "\"" << endl;
            } else {
                cout << "  \"" << f << "\" -> tidak ada ekstensi" << endl;
            }
        }

    // Hitung kemunculan substring
        cout << "\n  Hitung kemunculan \"the\" di kalimat:" << endl;
        string kalimat = "the cat sat on the mat in the hat";
        string kata = "the";
        int hitungan = 0;
        size_t pos = kalimat.find(kata);
        while (pos != string::npos) {
            hitungan++;
            pos = kalimat.find(kata, pos + 1);
        }
        cout << "  \"" << kalimat << "\"" << endl;
        cout << "  \"the\" muncul " << hitungan << " kali" << endl;

        // Validasi: cek apakah ada karakter tidak valid
        cout << "\n  Validasi username (hanya huruf, angka, underscore):" << endl;
        string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
        string usernames[] = {"gega123", "budi.santoso", "citra_dewi", "nama user"};
        for (const string &u : usernames) {
            size_t invalid = u.find_first_not_of(validChars);
            cout << "  \"" << u << "\" -> "
                << (invalid == string::npos ? "valid" : "tidak valid (ada karakter tidak diizinkan)")
                << endl;
        }
}


// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "============================================================" << endl;
    cout << "  V.5 -- Pencarian dalam String" << endl;
    cout << "============================================================" << endl;

    demoFind();
    demoRfind();
    demoFindOf();
    demoNpos();
    demoPraktis();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  find(str)                -> index pertama dari kiri, atau npos" << endl;
    cout << "  find(str, mulai)         -> mulai pencarian dari index tertentu" << endl;
    cout << "  rfind(str)               -> index pertama dari kanan" << endl;
    cout << "  find_first_of(chars)     -> index karakter pertama yang ada di chars" << endl;
    cout << "  find_last_of(chars)      -> index karakter terakhir yang ada di chars" << endl;
    cout << "  find_first_not_of(chars) -> index karakter pertama yang TIDAK di chars" << endl;
    cout << "  string::npos             -> penanda tidak ditemukan" << endl;
    cout << "  WAJIB: selalu cek != npos sebelum pakai hasil find!" << endl;

    return 0;
}

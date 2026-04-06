
#include <iostream>
#include <string>
#include <sstream>   // stringstream
#include <vector>    // vector (untuk tampung hasil split)
using namespace std;


// substr() DAN SPLIT
void demoSubstr() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. substr() -- Ambil Bagian String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Halo Dunia Indah";
    cout << "\n  s = \"" << s << "\"" << endl;
    cout << "  Panjang: " << s.length() << " karakter" << endl;
    cout << "  Index  : 0123456789..." << endl;

    // substr(pos, len) -- ambil len karakter mulai pos
        cout << "\n  substr(pos, len) -- ambil len karakter mulai index pos:" << endl;
        cout << "  s.substr(0, 4)   = \"" << s.substr(0, 4)  << "\"  (dari 0, ambil 4)" << endl;
        cout << "  s.substr(5, 5)   = \"" << s.substr(5, 5)  << "\"  (dari 5, ambil 5)" << endl;
        cout << "  s.substr(11, 5)  = \"" << s.substr(11, 5) << "\"  (dari 11, ambil 5)" << endl;

    // substr(pos) -- ambil dari pos sampai akhir
        cout << "\n  substr(pos) -- ambil dari pos sampai akhir:" << endl;
        cout << "  s.substr(5)      = \"" << s.substr(5)  << "\"  (dari index 5 ke akhir)" << endl;
        cout << "  s.substr(11)     = \"" << s.substr(11) << "\"  (dari index 11 ke akhir)" << endl;
        cout << "  s.substr(0)      = \"" << s.substr(0)  << "\"  (seluruh string)" << endl;

    // substr dengan length
        int n = s.length();
        cout << "\n  s.substr(n-5)    = \"" << s.substr(n-5)
            << "\"  (5 karakter terakhir)" << endl;

    // substr biasanya dikombinasikan dengan find()
        cout << "\n  Kombinasi find() + substr() untuk ekstrak bagian:" << endl;
        size_t posSpasi = s.find(' ');
        if (posSpasi != string::npos) {
            string katapertama = s.substr(0, posSpasi);
            cout << "  Kata pertama: \"" << katapertama << "\"" << endl;
        }
}

void demoSubstrPraktis() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. Substr untuk Ekstrak Informasi" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Ekstrak nama file dan path
        string path = "C:/Users/Gega/Documents/laporan.pdf";
        cout << "\n  path = \"" << path << "\"" << endl;

        size_t lastSlash = path.rfind('/');
        size_t lastDot   = path.rfind('.');
        string namaFile  = path.substr(lastSlash + 1);
        string namaBase  = path.substr(lastSlash + 1, lastDot - lastSlash - 1);
        string ekstensi  = path.substr(lastDot + 1);
        string dirPath   = path.substr(0, lastSlash);

        cout << "  Direktori : \"" << dirPath  << "\"" << endl;
        cout << "  Nama file : \"" << namaFile << "\"" << endl;
        cout << "  Nama base : \"" << namaBase << "\"" << endl;
        cout << "  Ekstensi  : \"" << ekstensi << "\"" << endl;

    // Ekstrak domain dari email
        cout << "\n  Ekstrak dari email:" << endl;
        string email = "gega@example.com";
        size_t at = email.find('@');
        if (at != string::npos) {
            string username = email.substr(0, at);
            string domain   = email.substr(at + 1);
            cout << "  email    = \"" << email    << "\"" << endl;
            cout << "  username = \"" << username << "\"" << endl;
            cout << "  domain   = \"" << domain   << "\"" << endl;
        }

    // Ekstrak tanggal dari format "2024-01-15"
        cout << "\n  Parse tanggal \"2024-01-15\":" << endl;
        string tanggal = "2024-01-15";
        string tahun  = tanggal.substr(0, 4);
        string bulan  = tanggal.substr(5, 2);
        string hari   = tanggal.substr(8, 2);
        cout << "  Tahun: " << tahun << ", Bulan: " << bulan << ", Hari: " << hari << endl;
}

void demoSplitStringstream() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. Split dengan stringstream -- Delimiter Spasi" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  stringstream dari <sstream> bisa 'parsing' string" << endl;
    cout << "  seperti cin membaca input -- berhenti di whitespace" << endl;

    string kalimat = "Belajar C++ itu sangat menyenangkan";
    cout << "\n  kalimat = \"" << kalimat << "\"" << endl;

    stringstream ss(kalimat);
    string kata;
    int nomor = 1;
    cout << "\n  Kata-kata:" << endl;
    while (ss >> kata) {
        cout << "  " << nomor++ << ". \"" << kata << "\"" << endl;
    }

    // Hitung kata
        stringstream ss2(kalimat);
        int jumlahKata = 0;
        while (ss2 >> kata) jumlahKata++;
        cout << "\n  Jumlah kata: " << jumlahKata << endl;
}

void demoSplitDelimiter() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. Split dengan Delimiter Tertentu" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Untuk delimiter selain spasi, pakai getline() dengan delimiter" << endl;

    // Split dengan koma (CSV)
        string csv = "Gega,20,Informatika,3.87";
        cout << "\n  CSV = \"" << csv << "\"" << endl;

        stringstream ssCsv(csv);
        string field;
        int kolom = 1;
        cout << "  Field:" << endl;
        while (getline(ssCsv, field, ',')) {
            cout << "  [" << kolom++ << "] \"" << field << "\"" << endl;
        }

    // Split dengan titik dua
        string config = "host:localhost:port:8080:db:mydb";
        cout << "\n  Config = \"" << config << "\"" << endl;
        stringstream ssConfig(config);
        string token;
        cout << "  Tokens:" << endl;
        int idx = 0;
        while (getline(ssConfig, token, ':')) {
            cout << "  [" << idx++ << "] \"" << token << "\"" << endl;
        }

    // Split dengan | sebagai delimiter
        string pilihan = "Opsi A|Opsi B|Opsi C|Opsi D";
        cout << "\n  pilihan = \"" << pilihan << "\"" << endl;
        stringstream ssPilihan(pilihan);
        cout << "  Pilihan:" << endl;
        int no = 1;
        while (getline(ssPilihan, token, '|')) {
            cout << "  " << no++ << ". " << token << endl;
        }
}

void demoSplitKeVector() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. Split dan Simpan ke vector" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Simpan hasil split ke vector<string> untuk diproses lebih lanjut" << endl;

    string data = "85,90,78,92,88,75,95,82";
    cout << "\n  data = \"" << data << "\"" << endl;

    // Split dan simpan ke vector
        vector<string> bagian;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            bagian.push_back(token);
        }

        cout << "  Hasil split (" << bagian.size() << " bagian):" << endl;
        for (int i = 0; i < (int)bagian.size(); i++) {
            cout << "  bagian[" << i << "] = \"" << bagian[i] << "\"" << endl;
        }

    // Konversi ke angka dan hitung total
        int total = 0;
        for (const string &b : bagian) total += stoi(b);
        double rata = (double)total / bagian.size();
        cout << "\n  Total: " << total << ", Rata-rata: " << rata << endl;
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.6 -- substr() dan Tokenisasi/Split" << endl;
    cout << "============================================================" << endl;

    demoSubstr();
    demoSubstrPraktis();
    demoSplitStringstream();
    demoSplitDelimiter();
    demoSplitKeVector();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  substr(pos, len) -> ambil len karakter dari pos" << endl;
    cout << "  substr(pos)      -> ambil dari pos sampai akhir" << endl;
    cout << "  substr(0)        -> salin seluruh string" << endl;
    cout << "  stringstream ss(s); ss >> kata    -> split by whitespace" << endl;
    cout << "  getline(ss, token, ',')            -> split by delimiter" << endl;
    cout << "  Kombinasikan find() + substr() untuk ekstrak bagian bermakna" << endl;

    return 0;
}

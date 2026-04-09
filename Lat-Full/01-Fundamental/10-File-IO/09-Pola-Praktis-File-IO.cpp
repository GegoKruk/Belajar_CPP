#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;

//  Struct untuk demo
    struct Kontak {
        string nama;
        string telepon;
        string email;
    };

//  Fungsi-fungsi utility

    // Cek apakah file ada
        bool fileAda(const string& namaFile) {
            ifstream f(namaFile);
            return f.is_open();
        }

    // Hitung jumlah baris dalam file
        int hitungBaris(const string& namaFile) {
            ifstream f(namaFile);
            if (!f.is_open()) return -1;
            int n = 0;
            string b;
            while (getline(f, b)) n++;
            return n;
        }

    // Hitung ukuran file dalam byte
        long long ukuranFile(const string& namaFile) {
            ifstream f(namaFile, ios::ate);
            if (!f.is_open()) return -1;
            return (long long)f.tellg();
        }

    // Log pesan ke file dengan timestamp
        void log(const string& filelog, const string& pesan) {
            ofstream f(filelog, ios::app);
            if (!f.is_open()) return;

            // Timestamp sederhana
            time_t now = time(nullptr);
            char buf[20];
            strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));

            f << "[" << buf << "] " << pesan << endl;
        }

    // Simpan vector kontak ke CSV
        void simpanKontakCSV(const string& namaFile, const vector<Kontak>& daftar) {
            ofstream f(namaFile);
            if (!f.is_open()) {
                cerr << "Gagal simpan ke " << namaFile << endl;
                return;
            }
            // Header
            f << "nama,telepon,email" << endl;
            for (const Kontak& k : daftar) {
                f << k.nama << "," << k.telepon << "," << k.email << endl;
            }
        }

    // Muat kontak dari CSV
        vector<Kontak> muatKontakCSV(const string& namaFile) {
            vector<Kontak> daftar;
            ifstream f(namaFile);
            if (!f.is_open()) return daftar;

            string baris;
            getline(f, baris);   // skip header

            while (getline(f, baris)) {
                if (baris.empty()) continue;
                stringstream ss(baris);
                Kontak k;
                getline(ss, k.nama,    ',');
                getline(ss, k.telepon, ',');
                getline(ss, k.email,   ',');
                daftar.push_back(k);
            }
            return daftar;
        }

    // Copy file (backup)
        bool copyFile(const string& sumber, const string& tujuan) {
            ifstream fs(sumber, ios::binary);
            ofstream ft(tujuan, ios::binary);
            if (!fs.is_open() || !ft.is_open()) return false;
            ft << fs.rdbuf();   // copy seluruh buffer sekaligus
            return true;
        }


//  MAIN
int main() {

    // ----- 1. Cek File Ada atau Tidak -----
        cout << "=== 1. Cek Keberadaan File ===" << endl;

        // Buat file dulu
        { ofstream f("09_ada.txt"); f << "isi" << endl; }

        cout << "'09_ada.txt'    ada? " << (fileAda("09_ada.txt")    ? "Ya" : "Tidak") << endl;
        cout << "'tidak_ada.txt' ada? " << (fileAda("tidak_ada.txt") ? "Ya" : "Tidak") << endl;


    // ----- 2. Simpan dan Muat CSV -----
        cout << endl << "=== 2. Simpan dan Muat CSV ===" << endl;

        vector<Kontak> daftarAwal = {
            {"Budi Santoso",  "081234567890", "budi@email.com"},
            {"Sari Dewi",     "082345678901", "sari@email.com"},
            {"Andi Pratama",  "083456789012", "andi@email.com"},
            {"Dina Kusuma",   "084567890123", "dina@email.com"}
        };

        simpanKontakCSV("09_kontak.csv", daftarAwal);
        cout << "Kontak disimpan ke '09_kontak.csv'" << endl;

        vector<Kontak> daftarMuat = muatKontakCSV("09_kontak.csv");
        cout << "Kontak dimuat (" << daftarMuat.size() << " entri):" << endl;
        for (const Kontak& k : daftarMuat) {
            cout << "  " << k.nama << " | " << k.telepon << " | " << k.email << endl;
        }


    // ----- 3. Sistem Logging -----
        cout << endl << "=== 3. Sistem Logging ===" << endl;

        log("09_app.log", "Program dimulai");
        log("09_app.log", "Memuat data kontak...");
        log("09_app.log", "Berhasil muat " + to_string(daftarMuat.size()) + " kontak");
        log("09_app.log", "Program selesai");

        cout << "Log ditulis ke '09_app.log':" << endl;
        ifstream flog("09_app.log");
        string b;
        while (getline(flog, b)) cout << "  " << b << endl;
        flog.close();


    // ----- 4. Hitung Statistik File -----
        cout << endl << "=== 4. Statistik File ===" << endl;

        cout << "'09_kontak.csv':" << endl;
        cout << "  Jumlah baris : " << hitungBaris("09_kontak.csv") << endl;
        cout << "  Ukuran file  : " << ukuranFile("09_kontak.csv")  << " byte" << endl;


    // ----- 5. Backup File -----
        cout << endl << "=== 5. Backup File ===" << endl;

        bool ok = copyFile("09_kontak.csv", "09_kontak_backup.csv");
        cout << "Backup ke '09_kontak_backup.csv': " << (ok ? "Berhasil" : "Gagal") << endl;

        // Verifikasi backup sama persis
        long long ukAsli   = ukuranFile("09_kontak.csv");
        long long ukBackup = ukuranFile("09_kontak_backup.csv");
        cout << "Ukuran asli  : " << ukAsli   << " byte" << endl;
        cout << "Ukuran backup: " << ukBackup << " byte" << endl;
        cout << "Identik: " << (ukAsli == ukBackup ? "Ya" : "Tidak") << endl;


    // ----- 6. Pola RAII dengan Scope Block -----
        cout << endl << "=== 6. Pola RAII dengan Scope Block ===" << endl;

        cout << "Menulis dengan scope block:" << endl;
        {
            ofstream fw("09_raii.txt");
            fw << "Ditulis dalam scope block" << endl;
            fw << "File otomatis ditutup saat keluar scope" << endl;
            cout << "  Tulis dalam block - file masih terbuka" << endl;
        }   // fw hancur di sini, file otomatis ditutup
        cout << "  Keluar dari block - file sudah ditutup otomatis" << endl;

        // Langsung bisa baca (tidak perlu tunggu close() eksplisit)
        ifstream fr("09_raii.txt");
        while (getline(fr, b)) cout << "  " << b << endl;
        fr.close();


    // ----- 7. Tulis Data Numerik Terformat -----
        cout << endl << "=== 7. Laporan Numerik ke File ===" << endl;

        struct Penjualan { string produk; int unit; double harga; };
        Penjualan lap[] = {
            {"Laptop",  5, 12500000.0},
            {"Monitor", 8,  3200000.0},
            {"Mouse",  25,   150000.0},
            {"Keyboard",15,  350000.0}
        };

        {
            ofstream fw("09_laporan.txt");
            fw << "========== Laporan Penjualan ==========" << endl;
            fw << left  << setw(12) << "Produk"
                << right << setw(8)  << "Unit"
                << right << setw(15) << "Harga"
                << right << setw(15) << "Subtotal" << endl;
            fw << string(50, '-') << endl;

            double grandTotal = 0;
            fw << fixed << setprecision(0);
            for (const auto& p : lap) {
                double subtotal = p.unit * p.harga;
                grandTotal += subtotal;
                fw << left  << setw(12) << p.produk
                << right << setw(8)  << p.unit
                << right << setw(15) << p.harga
                << right << setw(15) << subtotal << endl;
            }
            fw << string(50, '-') << endl;
            fw << right << setw(35) << "GRAND TOTAL: "
            << setw(15) << grandTotal << endl;
        }

        cout << "Laporan ditulis ke '09_laporan.txt':" << endl;
        ifstream flap("09_laporan.txt");
        while (getline(flap, b)) cout << "  " << b << endl;
        flap.close();

    // Cleanup
        remove("09_ada.txt");
        remove("09_kontak.csv");
        remove("09_kontak_backup.csv");
        remove("09_app.log");
        remove("09_raii.txt");
        remove("09_laporan.txt");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

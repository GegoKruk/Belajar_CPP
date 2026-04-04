#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


// CONTOH 1 -- SATU DEFAULT PARAMETER
    void sapa(string nama, string sapaan = "Halo") {
        cout << "  " << sapaan << ", " << nama << "!" << endl;
    }

    void cetakAngka(int nilai, int lebar = 5) {
        cout << "  |" << setw(lebar) << nilai << "|" << endl;
    }

    double hitungLingkaran(double jariJari, bool hitungLuas = true) {
        const double PI = 3.14159265358979;
        if (hitungLuas) return PI * jariJari * jariJari;
        return 2 * PI * jariJari;
    }


// CONTOH 2 -- DUA DEFAULT PARAMETER
    void cetakProfil(string nama, int usia = 20, string kota = "Yogyakarta") {
        cout << "  Nama  : " << nama << endl;
        cout << "  Usia  : " << usia << " tahun" << endl;
        cout << "  Kota  : " << kota << endl;
    }

    void cetakGaris(int panjang = 40, char karakter = '-') {
        cout << "  ";
        for (int i = 0; i < panjang; i++) cout << karakter;
        cout << endl;
    }

    double hitungDiskon(double harga, double persen = 10.0, string jenis = "Reguler") {
        double potongan  = harga * persen / 100.0;
        double bayar     = harga - potongan;
        cout << "  Jenis   : " << jenis << endl;
        cout << "  Harga   : Rp " << fixed << setprecision(0) << harga    << endl;
        cout << "  Diskon  : " << persen << "% = Rp " << potongan << endl;
        cout << "  Bayar   : Rp " << bayar << endl;
        cout << defaultfloat;
        return bayar;
    }


// CONTOH 3 -- TIGA DEFAULT PARAMETER

    void cetakHeader(string judul, int lebar = 50, char batas = '=', bool tengah = true) {
            
        // Baris atas
            cout << "  ";
            for (int i = 0; i < lebar; i++) cout << batas;
            cout << endl;

        // Baris judul
            if (tengah) {
                int spasi = (lebar - (int)judul.length()) / 2;
                cout << "  ";

                for (int i = 0; i < spasi; i++) {
                    cout << " ";
                }
                cout << judul << endl;
            } else {
                cout << "  " << judul << endl;
            }

        // Baris bawah
            cout << "  ";
            for (int i = 0; i < lebar; i++) {
                cout << batas;
            }
            cout << endl;
        }

    void konfigurasiBunga(double modal, double bungaPerTahun = 5.0, int tahun  = 1, bool bungaMajemuk = false) {
        double hasil;

        if (bungaMajemuk) {
            hasil = modal * pow(1 + bungaPerTahun / 100.0, tahun);
        } else {
            hasil = modal * (1 + (bungaPerTahun / 100.0) * tahun);
        }

        cout << fixed << setprecision(2);
        cout << "  Modal    : Rp " << modal << endl;
        cout << "  Bunga    : " << bungaPerTahun << "% per tahun" << endl;
        cout << "  Periode  : " << tahun << " tahun" << endl;
        cout << "  Tipe     : " << (bungaMajemuk ? "Majemuk" : "Sederhana") << endl;
        cout << "  Hasil    : Rp " << hasil << endl;
        cout << defaultfloat;
    }


// DEMO -- DEFAULT DI PROTOTYPE
    // Prototype -- default ditulis di sini
        void cetakLaporan(string judul, int tahun = 2024, bool ringkas = false);

    // Definisi -- TANPA default (tidak perlu ditulis ulang)
        void cetakLaporan(string judul, int tahun, bool ringkas) {
            cout << "  Judul  : " << judul << endl;
            cout << "  Tahun  : " << tahun << endl;
            if (!ringkas) {
                cout << "  Isi    : (versi lengkap -- banyak detail di sini)" << endl;
                cout << "  Lampiran: (dokumen pendukung)" << endl;
            } else {
                cout << "  Isi    : (versi ringkas)" << endl;
            }
        }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.3 -- Default Parameter" << endl;
    cout << "============================================================" << endl;

    // ---- Satu Default ----
        cout << "\n[ 1. Satu Default Parameter ]" << endl;

        cout << "\n  sapa() -- default sapaan = \"Halo\":" << endl;
        sapa("Gega");               // sapaan pakai default "Halo"
        sapa("Budi", "Selamat pagi");  // sapaan diganti
        sapa("Citra", "Hai");

        cout << "\n  cetakAngka() -- default lebar = 5:" << endl;
        cetakAngka(42);          // lebar = 5 (default)
        cetakAngka(42, 8);       // lebar = 8
        cetakAngka(1234567, 10); // lebar = 10

        cout << "\n  hitungLingkaran() -- default hitungLuas = true:" << endl;
        cout << fixed << setprecision(4);
        cout << "  r=7, luas      = " << hitungLingkaran(7)       << endl;
        cout << "  r=7, keliling  = " << hitungLingkaran(7, false) << endl;
        cout << defaultfloat;

    // ---- Dua Default ----
        cout << "\n[ 2. Dua Default Parameter ]" << endl;

        cout << "\n  cetakProfil() -- tiga variasi:" << endl;
        cout << "  Panggil: cetakProfil(\"Gega\") -> usia & kota default:" << endl;
        cetakProfil("Gega");
        cout << endl;
        cout << "  Panggil: cetakProfil(\"Budi\", 25) -> kota default:" << endl;
        cetakProfil("Budi", 25);
        cout << endl;
        cout << "  Panggil: cetakProfil(\"Citra\", 22, \"Semarang\") -> semua diisi:" << endl;
        cetakProfil("Citra", 22, "Semarang");

        cout << "\n  cetakGaris() -- variasi karakter:" << endl;
        cetakGaris();              // panjang=40, karakter='-'
        cetakGaris(20);            // panjang=20, karakter='-'
        cetakGaris(30, '*');       // panjang=30, karakter='*'
        cetakGaris(20, '=');       // panjang=20, karakter='='

        cout << "\n  hitungDiskon() -- variasi diskon:" << endl;
        cetakGaris(40, '-');
        hitungDiskon(500000);               // persen=10, jenis="Reguler"
        cetakGaris(40, '-');
        hitungDiskon(500000, 25);           // persen=25, jenis="Reguler"
        cetakGaris(40, '-');
        hitungDiskon(500000, 30, "Member"); // semua diisi

    // ---- Tiga Default ----
        cout << "\n[ 3. Tiga Default Parameter ]" << endl;

        cout << "\n  cetakHeader() -- berbagai variasi:" << endl;
        cetakHeader("LAPORAN TAHUNAN");             // semua default
        cetakHeader("DAFTAR NILAI", 30);            // lebar berbeda
        cetakHeader("RINGKASAN", 30, '*');          // lebar dan batas berbeda
        cetakHeader("KIRI RATA", 40, '-', false);   // semua diisi, tidak tengah

        cout << "\n  konfigurasiBunga():" << endl;
        cetakGaris();
        cout << "  Semua default (bunga 5%, 1 tahun, sederhana):" << endl;
        konfigurasiBunga(10000000);
        cetakGaris();
        cout << "  Bunga 8%, 5 tahun, sederhana:" << endl;
        konfigurasiBunga(10000000, 8, 5);
        cetakGaris();
        cout << "  Bunga 8%, 5 tahun, MAJEMUK:" << endl;
        konfigurasiBunga(10000000, 8, 5, true);

    // ---- Default di Prototype ----
        cout << "\n[ 4. Default di Prototype -- definisi tidak perlu ulang ]" << endl;
        cetakGaris();
        cout << "  cetakLaporan(\"Kinerja Q4\") -> tahun & ringkas default:" << endl;
        cetakLaporan("Kinerja Q4");
        cetakGaris();
        cout << "  cetakLaporan(\"Kinerja Q3\", 2023, true) -> ringkas:" << endl;
        cetakLaporan("Kinerja Q3", 2023, true);

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Default Parameter" << endl;
        cout << "============================================================" << endl;
        cout << "  - Nilai otomatis jika argumen tidak dikirim" << endl;
        cout << "  - HARUS di paling kanan parameter" << endl;
        cout << "  - Tidak bisa lewati tengah: f(1, , 3) <- ERROR" << endl;
        cout << "  - Jika pakai prototype, default hanya di prototype" << endl;
        cout << "  - Cocok untuk: nilai umum yang sering dipakai" << endl;
        cout << "  - Membuat function lebih fleksibel tanpa banyak overload" << endl;

    return 0;
}

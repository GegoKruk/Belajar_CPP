
#include <iostream>
#include <string>
using namespace std;

// ----- Struct dasar dideklarasikan DULU -----
    struct Alamat {
        string jalan;
        string kota;
        string provinsi;
        string kodePos;
    };

    struct Kontak {
        string email;
        string telepon;
    };

    // ----- Struct yang memakai struct lain sebagai member -----
        struct Pegawai {
            string  nama;
            int     nip;
            double  gaji;
            Alamat  alamat;   // nested struct
            Kontak  kontak;   // nested struct lain
        };

// ----- Nested tiga level -----
    struct Tanggal {
        int hari;
        int bulan;
        int tahun;
    };

    struct Periode {
        Tanggal mulai;
        Tanggal selesai;
    };

    struct Proyek {
        string  nama;
        double  anggaran;
        Periode jadwal;   // Periode berisi dua Tanggal
    };


void cetakAlamat(const Alamat& a) {
    cout << "    Jalan    : " << a.jalan    << endl;
    cout << "    Kota     : " << a.kota     << endl;
    cout << "    Provinsi : " << a.provinsi << endl;
    cout << "    Kode Pos : " << a.kodePos  << endl;
}

void cetakPegawai(const Pegawai& p) {
    cout << "  Nama    : " << p.nama          << endl;
    cout << "  NIP     : " << p.nip           << endl;
    cout << "  Gaji    : Rp " << p.gaji       << endl;
    cout << "  Alamat  :" << endl;
    cetakAlamat(p.alamat);
    cout << "  Email   : " << p.kontak.email  << endl;
    cout << "  Telepon : " << p.kontak.telepon << endl;
}

void cetakTanggal(const Tanggal& t) {
    cout << t.hari << "/" << t.bulan << "/" << t.tahun;
}


int main() {

    // ----- 1. Nested Struct Dasar -----
        cout << "=== 1. Nested Struct Dasar ===" << endl;

        Pegawai p1;
        p1.nama             = "Budi Santoso";
        p1.nip              = 12345;
        p1.gaji             = 8500000.0;
        p1.alamat.jalan     = "Jl. Malioboro No. 10";
        p1.alamat.kota      = "Yogyakarta";
        p1.alamat.provinsi  = "D.I. Yogyakarta";
        p1.alamat.kodePos   = "55213";
        p1.kontak.email     = "budi@email.com";
        p1.kontak.telepon   = "081234567890";

        cetakPegawai(p1);


    // ----- 2. Inisialisasi Nested dengan Kurung Kurawal -----
        cout << endl << "=== 2. Inisialisasi dengan Kurung Kurawal Bertingkat ===" << endl;

        Pegawai p2 = {
            "Sari Dewi",
            67890,
            9200000.0,
            {"Jl. Sudirman No. 5", "Bandung", "Jawa Barat", "40111"},
            {"sari@email.com", "085678901234"}
        };

        cetakPegawai(p2);


    // ----- 3. Akses dan Modifikasi Member Nested -----
        cout << endl << "=== 3. Akses dan Modifikasi Member Nested ===" << endl;

        cout << "Kota p1  : " << p1.alamat.kota  << endl;
        cout << "Email p2 : " << p2.kontak.email << endl;

        p1.alamat.kota = "Jakarta";   // pindah kota
        p1.gaji       *= 1.10;        // naik gaji 10%

        cout << "Setelah update:" << endl;
        cout << "  Kota baru : " << p1.alamat.kota << endl;
        cout << "  Gaji baru : Rp " << p1.gaji     << endl;


    // ----- 4. Nested Tiga Level -----
        cout << endl << "=== 4. Nested Tiga Level (Proyek -> Periode -> Tanggal) ===" << endl;

        Proyek proj = {
            "Sistem Informasi Akademik",
            150000000.0,
            {
                {1, 3, 2025},    // mulai: 1 Maret 2025
                {31, 12, 2025}   // selesai: 31 Desember 2025
            }
        };

        cout << "Nama Proyek : " << proj.nama     << endl;
        cout << "Anggaran    : Rp " << proj.anggaran << endl;
        cout << "Mulai       : ";
        cetakTanggal(proj.jadwal.mulai);
        cout << endl;
        cout << "Selesai     : ";
        cetakTanggal(proj.jadwal.selesai);
        cout << endl;

        // Akses dan ubah
            proj.jadwal.selesai.bulan = 11;    // dipercepat ke November
            cout << "Selesai diperbarui: ";
            cetakTanggal(proj.jadwal.selesai);
            cout << endl;


    // ----- 5. Array of Nested Struct -----
        cout << endl << "=== 5. Array of Nested Struct ===" << endl;

        Pegawai tim[3] = {
            {"Andi", 11111, 7000000, {"Jl. A", "Surabaya", "Jawa Timur", "60111"}, {"andi@email.com", "082111"}},
            {"Bela", 22222, 7500000, {"Jl. B", "Malang",   "Jawa Timur", "65111"}, {"bela@email.com", "082222"}},
            {"Cici", 33333, 8000000, {"Jl. C", "Blitar",   "Jawa Timur", "66111"}, {"cici@email.com", "082333"}},
        };

        cout << "Daftar tim:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "  " << tim[i].nama << " | " << tim[i].alamat.kota << " | Rp " << tim[i].gaji << endl;
        }

    return 0;
}

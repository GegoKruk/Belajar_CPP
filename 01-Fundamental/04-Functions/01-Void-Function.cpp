#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// VOID FUNCTION TANPA PARAMETER

    void cetakHalo() {
        cout << "  Halo! Ini adalah void function tanpa parameter." << endl;
    }

    void cetakGarisPemisah() {
        cout << "  ";
        for (int i = 0; i < 44; i++) cout << "-";
        cout << endl;
    }

    void cetakJudulProgram() {
        cout << "  ============================================" << endl;
        cout << "         SISTEM NILAI MAHASISWA               " << endl;
        cout << "  ============================================" << endl;
    }

    void cetakPanduanPenggunaan() {
    cout << "  Panduan:" << endl;
    cout << "  1. Masukkan nama mahasiswa" << endl;
    cout << "  2. Masukkan nilai ujian (0-100)" << endl;
    cout << "  3. Program akan menampilkan grade otomatis" << endl;
}


// VOID FUNCTION DENGAN PARAMETER

    // Satu parameter
        void sapa(string nama) {
            cout << "  Halo, " << nama << "! Selamat datang." << endl;
        }

        void cetakAngka(int n) {
        cout << "  Angka: " << n << endl;
    }

    // Dua parameter
        void tampilkanProfil(string nama, int usia) {
            cout << "  Nama  : " << nama << endl;
            cout << "  Usia  : " << usia << " tahun" << endl;
        }

        void tampilkanHasilUjian(string nama, int nilai) {
        cout << "  Nama  : " << nama << endl;
        cout << "  Nilai : " << nilai << endl;
        if (nilai >= 85)      cout << "  Grade : A -- Sangat Memuaskan" << endl;
        else if (nilai >= 75) cout << "  Grade : B -- Memuaskan"        << endl;
        else if (nilai >= 65) cout << "  Grade : C -- Cukup"            << endl;
        else if (nilai >= 55) cout << "  Grade : D -- Kurang"           << endl;
        else                  cout << "  Grade : E -- Tidak Lulus"      << endl;
    }

    // Tiga parameter atau lebih
        void cetakKotak(string teks, int lebar, char batas) {
            cout << "  ";
            for (int i = 0; i < lebar; i++) cout << batas;
            cout << endl;

            int spasi = (lebar - (int)teks.length() - 2) / 2;
            cout << "  " << batas;
            for (int i = 0; i < spasi; i++) cout << " ";
            cout << " " << teks << " ";
            for (int i = 0; i < spasi; i++) cout << " ";
            cout << batas << endl;

            cout << "  ";
            for (int i = 0; i < lebar; i++) cout << batas;
            cout << endl;
        }

        void cetakTabel(string nama[], int nilai[], int jumlah) {
        cout << "  +---------------------+-------+-------+" << endl;
        cout << "  | Nama                | Nilai | Grade |" << endl;
        cout << "  +---------------------+-------+-------+" << endl;
        for (int i = 0; i < jumlah; i++) {
            string grade;
            if      (nilai[i] >= 85) grade = "A";
            else if (nilai[i] >= 75) grade = "B";
            else if (nilai[i] >= 65) grade = "C";
            else if (nilai[i] >= 55) grade = "D";
            else                     grade = "E";

            cout << "  | " << left << setw(19) << nama[i]
                << " | " << right << setw(5) << nilai[i]
                << " | " << setw(5) << grade
                << " |" << endl;
        }
        cout << "  +---------------------+-------+-------+" << endl;
    }


// EARLY RETURN PADA VOID FUNCTION

    void prosesNilai(int nilai) {
        // Validasi di awal -- kalau gagal, keluar lebih awal
        if (nilai < 0) {
            cout << "  [ERROR] Nilai tidak boleh negatif: " << nilai << endl;
            return;   // keluar, tidak lanjut
        }
        if (nilai > 100) {
            cout << "  [ERROR] Nilai tidak boleh lebih dari 100: " << nilai << endl;
            return;   // keluar, tidak lanjut
        }

        // Baris ini hanya dieksekusi kalau nilai antara 0-100
        cout << "  Nilai valid: " << nilai << " -- diproses..." << endl;
        cout << "  Persentase kelulusan: " << nilai << "%" << endl;
    }

    void cetakDaftarAngka(int dari, int sampai) {
        if (dari > sampai) {
            cout << "  [ERROR] Nilai awal (" << dari << ") lebih besar dari akhir (" << sampai << ")" << endl;
            return;
        }
        cout << "  Daftar " << dari << " sampai " << sampai << ": ";
        for (int i = dari; i <= sampai; i++) {
            cout << i;
            if (i < sampai) cout << ", ";
        }
        cout << endl;
    }

// VOID FUNCTION -- PERULANGAN UNTUK REUSE

    void cetakDataMahasiswa(string nama, string jurusan, int semester, double ipk) {
        cout << "  +-------------------------------+" << endl;
        cout << "  | KARTU MAHASISWA               |" << endl;
        cout << "  +-------------------------------+" << endl;
        cout << "  | Nama     : " << left << setw(19) << nama     << " |" << endl;
        cout << "  | Jurusan  : " << setw(19) << jurusan  << " |" << endl;
        cout << "  | Semester : " << setw(19) << semester  << " |" << endl;
        cout << fixed << setprecision(2);
        cout << "  | IPK      : " << setw(19) << ipk      << " |" << endl;
        cout << defaultfloat;
        cout << "  +-------------------------------+" << endl;
    }

int main() {
    cout << "============================================================" << endl;
    cout << "  T.1 -- Void Function" << endl;
    cout << "============================================================" << endl;

    // ---- Tanpa Parameter ----
        cout << "\n[ 1. Void Function Tanpa Parameter ]" << endl;
        cetakHalo();
        cetakGarisPemisah();
        cetakJudulProgram();
        cetakPanduanPenggunaan();
        cetakGarisPemisah();

    // ---- Satu Parameter ----
        cout << "\n[ 2. Void Function Dengan Satu Parameter ]" << endl;
        sapa("Gega");
        sapa("Budi");
        sapa("Citra");
        cetakAngka(42);

    // ---- Dua Parameter ----
        cout << "\n[ 3. Void Function Dengan Dua Parameter ]" << endl;
        cetakGarisPemisah();
        tampilkanProfil("Gega Ramadhan", 20);
        cetakGarisPemisah();
        tampilkanProfil("Budi Santoso", 22);
        cetakGarisPemisah();

        cout << endl;
        tampilkanHasilUjian("Gega",  90);
        cetakGarisPemisah();
        tampilkanHasilUjian("Budi",  72);
        cetakGarisPemisah();
        tampilkanHasilUjian("Citra", 58);
        cetakGarisPemisah();

    // ---- Tiga Parameter ----
        cout << "\n[ 4. Void Function Dengan Tiga Parameter ]" << endl;
        cetakKotak("SELAMAT DATANG", 30, '=');
        cout << endl;
        cetakKotak("INFO PENTING", 30, '*');

    // ---- Tabel ----
        cout << "\n[ 5. Void Function Mencetak Tabel ]" << endl;
        string daftarNama[] = {"Gega Ramadhan", "Budi Santoso", "Citra Dewi", "Dian Pratiwi"};
        int    daftarNilai[] = {90, 72, 85, 58};
        cetakTabel(daftarNama, daftarNilai, 4);

    // ---- Early Return ----
        cout << "\n[ 6. Early Return pada Void Function ]" << endl;
        cout << "  Uji prosesNilai() dengan berbagai input:" << endl;
        prosesNilai(-5);
        prosesNilai(150);
        prosesNilai(85);
        prosesNilai(0);

        cout << "\n  Uji cetakDaftarAngka():" << endl;
        cetakDaftarAngka(1, 5);
        cetakDaftarAngka(10, 8);   // dari > sampai, early return
        cetakDaftarAngka(3, 3);    // dari == sampai, valid

    // ---- Reuse berkali-kali ----
        cout << "\n[ 7. Kekuatan Reuse -- Panggil Berulang ]" << endl;
        cetakDataMahasiswa("Gega Ramadhan", "Informatika", 4, 3.87);
        cout << endl;
        cetakDataMahasiswa("Budi Santoso", "Sistem Informasi", 6, 3.45);
        cout << endl;
        cetakDataMahasiswa("Citra Dewi", "Teknik Komputer", 2, 3.91);

    // ---- Ringkasan ----
        cout << "\n============================================================" << endl;
        cout << "  Ringkasan Void Function" << endl;
        cout << "============================================================" << endl;
        cout << "  - Return type : void (tidak mengembalikan nilai)" << endl;
        cout << "  - Cara panggil: namaFunction();  atau  namaFunction(arg);" << endl;
        cout << "  - Tidak bisa  : int x = namaVoid();  <- ERROR" << endl;
        cout << "  - Boleh ada   : return;  (tanpa nilai) untuk early exit" << endl;
        cout << "  - Cocok untuk : cetak, tampilkan, gambar, aksi tanpa hasil" << endl;
        cout << "  - Kekuatan    : dipanggil berulang tanpa tulis ulang kode" << endl;

    return 0;
}

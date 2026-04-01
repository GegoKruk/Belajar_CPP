#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Konstanta GLOBAL - letakkan di luar fungsi
// Pakai UPPER_SNAKE_CASE untuk konstanta
// ============================================================

// #define - cara lama (preprocessor, tidak punya tipe)
#define VERSI_PROGRAM "1.0.0"

// constexpr global - cara modern, lebih aman
constexpr double PI              = 3.14159265358979;
constexpr int    MAX_MAHASISWA   = 100;
constexpr int    BATAS_KELULUSAN = 75;

// Kalkulasi dari konstanta lain - dihitung saat compile!
constexpr int DETIK_PER_MENIT = 60;
constexpr int MENIT_PER_JAM   = 60;
constexpr int DETIK_PER_JAM   = DETIK_PER_MENIT * MENIT_PER_JAM; // = 3600, compile-time!
constexpr int JAM_PER_HARI    = 24;
constexpr int DETIK_PER_HARI  = DETIK_PER_JAM * JAM_PER_HARI;    // = 86400, compile-time!


void constConstexpr() {
    cout << "========== C. Const & Constexpr ==========" << endl;

    // ----- 1. const - Runtime Constant -----
    cout << "\n1. const - Konstanta Runtime" << endl;

    const double PPN        = 0.11;  // PPN 11%
    const int    HARI_KERJA = 5;

    cout << "   PPN         = " << PPN * 100 << "%" << endl;
    cout << "   Hari kerja  = " << HARI_KERJA << " hari/minggu" << endl;

    // const bisa dari runtime / input / kalkulasi
    int hargaBarang = 200000;
    const int HARGA_FINAL = hargaBarang + (hargaBarang * PPN); // OK

    cout << "   Harga barang       = Rp " << hargaBarang << endl;
    cout << "   Harga + PPN 11%    = Rp " << HARGA_FINAL << endl;

    // PPN = 0.12;  // ❌ COMPILE ERROR: cannot assign to const variable

    // ----- 2. constexpr - Compile-Time Constant -----
    cout << "\n2. constexpr - Konstanta Compile-Time" << endl;

    cout << "   PI              = " << PI             << endl;
    cout << "   MAX_MAHASISWA   = " << MAX_MAHASISWA  << endl;
    cout << "   BATAS_KELULUSAN = " << BATAS_KELULUSAN << endl;

    cout << "\n   Kalkulasi dari konstanta lain (dihitung saat compile):" << endl;
    cout << "   DETIK_PER_MENIT = " << DETIK_PER_MENIT << endl;
    cout << "   DETIK_PER_JAM   = " << DETIK_PER_JAM   << endl;
    cout << "   DETIK_PER_HARI  = " << DETIK_PER_HARI  << endl;

    // constexpr HARUS compile-time
    constexpr int KUADRAT_5 = 5 * 5;  // OK
    // int x = 10;
    // constexpr int gagal = x * 2;   // ❌ ERROR - x bukan compile-time value

    cout << "   Kuadrat 5       = " << KUADRAT_5 << endl;

    // ----- 3. Perbandingan const vs constexpr -----
    cout << "\n3. Perbandingan: const vs constexpr" << endl;
    cout << "   +-----------------------------------------------------------+" << endl;
    cout << "   |              | const                | constexpr           |" << endl;
    cout << "   +--------------+----------------------+---------------------+" << endl;
    cout << "   | Waktu nilai  | Runtime (saat jalan) | Compile-time        |" << endl;
    cout << "   | Dari input   | Ya                   | Tidak               |" << endl;
    cout << "   | Dari literal | Ya                   | Ya                  |" << endl;
    cout << "   | Kecepatan    | Normal               | Lebih cepat         |" << endl;
    cout << "   | Kapan pakai  | Nilai dinamis        | Nilai sudah pasti   |" << endl;
    cout << "   +--------------+----------------------+---------------------+" << endl;

    // ----- 4. Contoh Praktis - Luas Lingkaran -----
    cout << "\n4. Contoh Praktis: Menghitung Luas Lingkaran" << endl;

    double radius = 7.0;
    double luas   = PI * radius * radius;
    double keliling = 2 * PI * radius;

    cout << "   Radius    = " << radius   << " cm" << endl;
    cout << "   Luas      = " << luas     << " cm2" << endl;
    cout << "   Keliling  = " << keliling << " cm" << endl;

    // ----- 5. constexpr untuk ukuran array -----
    cout << "\n5. constexpr untuk Array Size (fitur penting!)" << endl;

    constexpr int UKURAN = 5;
    int data[UKURAN] = {10, 20, 30, 40, 50}; // OK karena UKURAN adalah constexpr

    cout << "   Array dengan ukuran constexpr " << UKURAN << ": ";
    for (int i = 0; i < UKURAN; i++) {
        cout << data[i];
        if (i < UKURAN - 1) cout << ", ";
    }
    cout << endl;

    // ----- 6. #define vs constexpr -----
    cout << "\n6. #define vs constexpr - Kenapa Hindari #define?" << endl;
    cout << "   Versi program (#define): " << VERSI_PROGRAM << endl;
    cout << "\n   #define NILAI 100     -> Tidak ada tipe, tidak ada scope" << endl;
    cout << "                            Rentan bug, susah di-debug" << endl;
    cout << "   constexpr int NILAI = 100 -> Ada tipe, ada scope, lebih aman" << endl;
    cout << "   Pakai constexpr, hindari #define untuk konstanta angka/tipe!" << endl;

    // ----- Tips -----
    cout << "\nTips:" << endl;
    cout << "   -> Gunakan UPPER_SNAKE_CASE untuk nama konstanta" << endl;
    cout << "   -> Prefer constexpr daripada const untuk nilai yang sudah pasti" << endl;
    cout << "   -> Prefer const/constexpr daripada #define" << endl;
    cout << "   -> Konstanta global letakkan di atas file, di luar fungsi" << endl;
}


// ============================================================
// MAIN - Entry Point
// ============================================================
int main() {
    constConstexpr();

    return 0;
}
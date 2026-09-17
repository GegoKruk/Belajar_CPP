
#include <iostream>
#include <string>
using namespace std;


// PERBANDINGAN SIDE-BY-SIDE

    // ----- enum biasa -----
    enum WarnaLama  { MERAH, HIJAU, BIRU };

    // ----- enum class -----
    enum class WarnaBaru { MERAH, HIJAU, BIRU };  // nama tidak konflik!

    // ----- Contoh konflik yang dicegah enum class -----
    enum class Arah1  { UTARA, SELATAN };
    enum class Arah2  { UTARA, SELATAN };   // OK! Tidak konflik dengan Arah1


// USE CASE: Enum biasa untuk bit flags
    enum FlagHak {
        HAK_BACA     = 1,  // 001
        HAK_TULIS    = 2,  // 010
        HAK_EKSEKUSI = 4   // 100
    };

// USE CASE: Enum class untuk status
    enum class StatusPesanan {
        BARU,
        DIKONFIRMASI,
        DIKIRIM,
        SELESAI,
        DIBATALKAN
    };

    string namaStatus(StatusPesanan s) {
        switch (s) {
            case StatusPesanan::BARU:         return "Baru";
            case StatusPesanan::DIKONFIRMASI: return "Dikonfirmasi";
            case StatusPesanan::DIKIRIM:      return "Dikirim";
            case StatusPesanan::SELESAI:      return "Selesai";
            case StatusPesanan::DIBATALKAN:   return "Dibatalkan";
            default:                          return "Tidak Dikenal";
        }
    }


int main() {

    // ----- 1. Scope: Enum vs Enum Class -----
        cout << "=== 1. Scope: Bocor vs Tersimpan ===" << endl;

        WarnaLama  w1 = MERAH;            // OK: nama bocor ke scope luar
        WarnaBaru  w2 = WarnaBaru::MERAH; // HARUS pakai WarnaBaru::

        cout << "WarnaLama MERAH (nilai int)  = " << w1 << endl;
        cout << "WarnaBaru MERAH (nilai int)  = " << static_cast<int>(w2) << endl;

        // Dengan enum biasa, MERAH bisa dipakai langsung
        int x = MERAH;            // OK - implicit conversion
        // int y = w2;            // ERROR - tidak bisa implicit
        int y = static_cast<int>(w2);  // harus explicit
        cout << "x (dari enum biasa)   = " << x << endl;
        cout << "y (dari enum class)   = " << y << endl;


    // ----- 2. Konflik yang Dicegah -----
        cout << endl << "=== 2. Konflik Nama Dicegah Enum Class ===" << endl;

        Arah1 a1 = Arah1::UTARA;
        Arah2 a2 = Arah2::UTARA;   // tidak konflik!

        cout << "Arah1::UTARA = " << static_cast<int>(a1) << endl;
        cout << "Arah2::UTARA = " << static_cast<int>(a2) << endl;
        cout << "Dua enum class bisa punya nama yang sama tanpa konflik." << endl;


    // ----- 3. Bit Flags: Enum Biasa Lebih Ringkas -----
        cout << endl << "=== 3. Bit Flags - Enum Biasa (Lebih Ringkas) ===" << endl;

        int hakUser  = HAK_BACA | HAK_TULIS;            // = 3
        int hakAdmin = HAK_BACA | HAK_TULIS | HAK_EKSEKUSI; // = 7

        cout << "Hak user  = " << hakUser  << endl;
        cout << "Hak admin = " << hakAdmin << endl;

        cout << "User bisa BACA?     " << ((hakUser & HAK_BACA)     ? "Ya" : "Tidak") << endl;
        cout << "User bisa TULIS?    " << ((hakUser & HAK_TULIS)    ? "Ya" : "Tidak") << endl;
        cout << "User bisa EKSEKUSI? " << ((hakUser & HAK_EKSEKUSI) ? "Ya" : "Tidak") << endl;

        // Dengan enum class, OR dan AND lebih verbose karena perlu static_cast
        cout << "(Untuk bit flags, enum biasa lebih praktis)" << endl;


    // ----- 4. Enum Class untuk Type Safety -----
        cout << endl << "=== 4. Enum Class - Type Safety ===" << endl;

        StatusPesanan status = StatusPesanan::DIKIRIM;

        cout << "Status pesanan: " << namaStatus(status) << endl;

        // Enum class mencegah perbandingan tidak sengaja dengan int
        // if (status == 2) ...   // ERROR! Tidak bisa compare langsung dengan int
        if (status == StatusPesanan::DIKIRIM) {  // harus spesifik
            cout << "Pesanan sedang dalam pengiriman." << endl;
        }


    // ----- 5. Ringkasan Perbandingan -----
        cout << endl << "=== 5. Ringkasan Perbandingan ===" << endl;

        cout << "Fitur                 | enum           | enum class" << endl;
        cout << "----------------------+----------------+--------------------" << endl;
        cout << "Scope nama            | Bocor ke luar  | Tersimpan sendiri" << endl;
        cout << "Akses member          | MERAH          | Warna::MERAH" << endl;
        cout << "Implicit ke int       | Bisa           | Tidak bisa" << endl;
        cout << "Konflik nama          | Bisa terjadi   | Tidak bisa" << endl;
        cout << "Type safety           | Rendah         | Tinggi" << endl;
        cout << "Cocok untuk           | Bit flags, C   | Status, modern C++" << endl;
        cout << "Direkomendasikan      | Kode lama/C    | Kode C++ baru" << endl;

        cout << endl;
        cout << "Aturan praktis:" << endl;
        cout << "  Kode C++ baru (C++11+)    -> pakai enum class" << endl;
        cout << "  Interoperasi dengan C     -> pakai enum biasa" << endl;
        cout << "  Bit flags yang di-OR      -> enum biasa lebih ringkas" << endl;
        cout << "  Status / state machine    -> enum class lebih aman" << endl;

    return 0;
}

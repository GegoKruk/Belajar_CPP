
#include <iostream>
#include <string>
using namespace std;

// ----- Enum class yang akan dipakai -----
        enum class Warna { MERAH, HIJAU, BIRU, KUNING };

        enum class Status { AKTIF, NONAKTIF, PENDING };

        enum class Level { MUDAH, SEDANG, SULIT, EXPERT };

    // Tidak ada konflik nama meski pakai nama yang sama!
    enum class Arah   { UTARA, SELATAN, TIMUR, BARAT };
    enum class Tombol { UTARA, SELATAN, KIRI, KANAN };   // UTARA & SELATAN tidak konflik!


// ----- Fungsi konversi enum class ke string -----
    string namaWarna(Warna w) {
        switch (w) {
            case Warna::MERAH:  return "Merah";
            case Warna::HIJAU:  return "Hijau";
            case Warna::BIRU:   return "Biru";
            case Warna::KUNING: return "Kuning";
            default:            return "Tidak Dikenal";
        }
    }

    string namaStatus(Status s) {
        switch (s) {
            case Status::AKTIF:    return "Aktif";
            case Status::NONAKTIF: return "Non-Aktif";
            case Status::PENDING:  return "Pending";
            default:               return "Tidak Dikenal";
        }
    }

    string namaLevel(Level l) {
        switch (l) {
            case Level::MUDAH:  return "Mudah";
            case Level::SEDANG: return "Sedang";
            case Level::SULIT:  return "Sulit";
            case Level::EXPERT: return "Expert";
            default:            return "Tidak Dikenal";
        }
    }


int main() {

    // ----- 1. Deklarasi dan Akses -----
        cout << "=== 1. Deklarasi dan Akses ===" << endl;

        Warna w = Warna::BIRU;      // WAJIB pakai Warna::
        Status s = Status::AKTIF;

        cout << "w = Warna::BIRU -> " << namaWarna(w) << endl;
        cout << "s = Status::AKTIF -> " << namaStatus(s) << endl;


    // ----- 2. Tidak Ada Implicit Conversion -----
        cout << endl << "=== 2. Tidak Ada Implicit Conversion ===" << endl;

        // int x = w;               // ERROR! Tidak bisa implicit
        int xC   = (int)w;          // OK, C-style cast
        int xCpp = static_cast<int>(Status::PENDING);  // OK, C++ style

        cout << "Warna::BIRU sebagai int (C-style cast)  : " << xC   << endl;
        cout << "Status::PENDING sebagai int (static_cast): " << xCpp << endl;
        cout << "Tidak bisa: int x = w;   <- compile error" << endl;


    // ----- 3. Tidak Ada Konflik Nama -----
        cout << endl << "=== 3. Tidak Ada Konflik Nama ===" << endl;

        Arah   arah   = Arah::UTARA;
        Tombol tombol = Tombol::UTARA;   // UTARA yang ini milik Tombol!

        cout << "Arah::UTARA   = " << static_cast<int>(arah)   << endl;
        cout << "Tombol::UTARA = " << static_cast<int>(tombol) << endl;
        cout << "Tidak konflik meski nama sama!" << endl;


    // ----- 4. Switch dengan Enum Class -----
        cout << endl << "=== 4. Switch dengan Enum Class ===" << endl;

        Level tingkat = Level::SULIT;

        switch (tingkat) {
            case Level::MUDAH:
                cout << "Level Mudah: cocok untuk pemula." << endl;
                break;
            case Level::SEDANG:
                cout << "Level Sedang: butuh sedikit pengalaman." << endl;
                break;
            case Level::SULIT:
                cout << "Level Sulit: tantangan nyata!" << endl;
                break;
            case Level::EXPERT:
                cout << "Level Expert: pro only!" << endl;
                break;
        }


    // ----- 5. Perbandingan Enum Class -----
        cout << endl << "=== 5. Perbandingan Enum Class ===" << endl;

        Status sAktif   = Status::AKTIF;
        Status sPending = Status::PENDING;

        if (sAktif == Status::AKTIF) {
            cout << "sAktif memang AKTIF" << endl;
        }

        if (sAktif != sPending) {
            cout << "sAktif != sPending" << endl;
        }

        // Operator < juga bisa (berdasarkan nilai integer)
        if (sAktif < sPending) {
            cout << "AKTIF (0) < PENDING (2)" << endl;
        }


    // ----- 6. Iterasi dengan static_cast -----
        cout << endl << "=== 6. Iterasi Enum Class ===" << endl;

        cout << "Semua warna:" << endl;
        for (int i = 0; i <= static_cast<int>(Warna::KUNING); i++) {
            Warna warna = static_cast<Warna>(i);
            cout << "  " << i << " = " << namaWarna(warna) << endl;
        }

    return 0;
}

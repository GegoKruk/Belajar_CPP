
#include <iostream>
#include <string>
using namespace std;

// ----- Enum-enum yang akan dipakai -----
    enum Hari {
        SENIN = 1,   // mulai dari 1, bukan 0
        SELASA,      // = 2
        RABU,        // = 3
        KAMIS,       // = 4
        JUMAT,       // = 5
        SABTU,       // = 6
        MINGGU       // = 7
    };

    enum Musim {
        HUJAN,       // = 0
        KEMARAU,     // = 1
        PANCAROBA    // = 2
    };

    enum HttpStatus {
        OK           = 200,
        NOT_FOUND    = 404,
        SERVER_ERROR = 500
    };

    enum Arah {
        UTARA,   // = 0
        SELATAN, // = 1
        TIMUR,   // = 2
        BARAT    // = 3
    };


int main() {

    // ----- 1. Deklarasi dan Nilai Default -----
        cout << "=== 1. Nilai Enum ===" << endl;

        cout << "Hari  : SENIN=" << SENIN << " SELASA=" << SELASA << " RABU=" << RABU << " ... MINGGU=" << MINGGU << endl;
        cout << "Musim : HUJAN=" << HUJAN << " KEMARAU=" << KEMARAU << " PANCAROBA=" << PANCAROBA << endl;
        cout << "HTTP  : OK=" << OK << " NOT_FOUND=" << NOT_FOUND << " SERVER_ERROR=" << SERVER_ERROR << endl;


    // ----- 2. Penggunaan Dasar -----
        cout << endl << "=== 2. Penggunaan Dasar ===" << endl;

        Hari hariIni = RABU;
        Musim musimIni = HUJAN;

        cout << "Hari ini (nilai int): " << hariIni << endl;

        if (hariIni == RABU) {
            cout << "Hari ini Rabu!" << endl;
        }

        if (musimIni == HUJAN) {
            cout << "Musim hujan - bawa payung!" << endl;
        }


    // ----- 3. Implicit Conversion ke int -----
        cout << endl << "=== 3. Implicit Conversion ke int ===" << endl;

        Arah arah = TIMUR;
        int nilaiArah = arah;    // implicit conversion OK
        cout << "Arah TIMUR sebagai int = " << nilaiArah << endl;

        // Arah yang lebih besar
            if (arah > SELATAN) {
                cout << "TIMUR (" << TIMUR << ") > SELATAN (" << SELATAN << ")" << endl;
            }


    // ----- 4. Konversi int ke Enum (perlu explicit cast) -----
        cout << endl << "=== 4. Konversi int ke Enum ===" << endl;

        int angka = 3;
        // Hari h = angka;              // ERROR! Tidak otomatis
        Hari h = static_cast<Hari>(angka);   // OK, explicit cast
        cout << "Hari ke-3 (0-indexed dari SENIN=1): nilai = " << h << endl;

        Arah a = (Arah)2;              // C-style cast, bisa tapi kurang disarankan
        cout << "Arah index 2 = " << a << " (TIMUR=" << TIMUR << ")" << endl;


    // ----- 5. Enum sebagai Kondisi -----
        cout << endl << "=== 5. Enum sebagai Kondisi ===" << endl;

        HttpStatus response = NOT_FOUND;

        if      (response == OK)           cout << "Request berhasil (200 OK)" << endl;
        else if (response == NOT_FOUND)    cout << "Halaman tidak ditemukan (404)" << endl;
        else if (response == SERVER_ERROR) cout << "Server error (500)" << endl;


    // ----- 6. Enum dalam Loop -----
        cout << endl << "=== 6. Enum dalam Loop ===" << endl;

        cout << "Semua hari dalam seminggu:" << endl;
        string namaHari[] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};

        for (int i = SENIN; i <= MINGGU; i++) {
            cout << "  Hari ke-" << i << ": " << namaHari[i - 1] << endl;
        }


    // ----- 7. Masalah Scope (Konflik Nama) -----
        cout << endl << "=== 7. Masalah Scope Enum Unscoped ===" << endl;
        cout << "Enum unscoped 'bocor' ke scope sekitarnya." << endl;
        cout << "Contoh masalah:" << endl;
        cout << "  enum Warna1 { MERAH, HIJAU };" << endl;
        cout << "  enum Warna2 { MERAH, BIRU };   // ERROR! MERAH sudah ada!" << endl;
        cout << "Solusi: pakai enum class (lihat 04-Enum-Class.cpp)" << endl;

    return 0;
}

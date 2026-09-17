
#include <iostream>
#include <string>
using namespace std;

// ----- Nilai custom: HTTP Status -----
    enum HttpStatus {
        HTTP_OK           = 200,
        HTTP_CREATED      = 201,
        HTTP_BAD_REQUEST  = 400,
        HTTP_UNAUTHORIZED = 401,
        HTTP_NOT_FOUND    = 404,
        HTTP_SERVER_ERROR = 500
    };

// ----- Nilai dari 1: Bulan -----
    enum Bulan {
        JAN = 1, FEB, MAR, APR, MEI, JUN,
        JUL, AGU, SEP, OKT, NOV, DES
    };

// ----- Nilai lompat: Planet -----
    enum Planet {
        MERKURIUS = 1,
        VENUS,      // = 2
        BUMI,       // = 3
        MARS,       // = 4
        JUPITER  = 100,
        SATURNUS    // = 101
    };

// ----- Bit flags: bisa di-OR -----
    enum Izin {
        BACA     = 1,    // binary: 001
        TULIS    = 2,    // binary: 010
        EKSEKUSI = 4     // binary: 100
    };

// ----- Musim untuk demonstrasi konversi ke string -----
    enum Musim { HUJAN, KEMARAU, PANCAROBA };


// ----- Fungsi konversi enum ke string -----
    string namaMusim(Musim m) {
        switch (m) {
            case HUJAN:     return "Hujan";
            case KEMARAU:   return "Kemarau";
            case PANCAROBA: return "Pancaroba";
            default:        return "Tidak Diketahui";
        }
    }

    string namaBulan(Bulan b) {
        string nama[] = {
            "", "Januari","Februari","Maret","April","Mei","Juni",
            "Juli","Agustus","September","Oktober","November","Desember"
        };
        if (b >= JAN && b <= DES) return nama[b];
        return "Tidak valid";
    }

    string namaHttpStatus(HttpStatus s) {
        switch (s) {
            case HTTP_OK:           return "200 OK";
            case HTTP_CREATED:      return "201 Created";
            case HTTP_BAD_REQUEST:  return "400 Bad Request";
            case HTTP_UNAUTHORIZED: return "401 Unauthorized";
            case HTTP_NOT_FOUND:    return "404 Not Found";
            case HTTP_SERVER_ERROR: return "500 Internal Server Error";
            default:                return "Status tidak dikenal";
        }
    }


int main() {

    // ----- 1. Nilai Custom - HTTP Status -----
        cout << "=== 1. Nilai Custom - HTTP Status ===" << endl;

        HttpStatus s1 = HTTP_OK;
        HttpStatus s2 = HTTP_NOT_FOUND;

        cout << "s1 = " << s1 << " -> " << namaHttpStatus(s1) << endl;
        cout << "s2 = " << s2 << " -> " << namaHttpStatus(s2) << endl;

        if (s1 == HTTP_OK) {
            cout << "Request berhasil!" << endl;
        }


    // ----- 2. Nilai dari 1 - Bulan -----
        cout << endl << "=== 2. Nilai dari 1 - Bulan ===" << endl;

        Bulan b = MEI;
        cout << "Bulan MEI = " << b << " -> " << namaBulan(b) << endl;

        cout << "Daftar bulan:" << endl;
        for (int i = JAN; i <= DES; i++) {
            Bulan bln = static_cast<Bulan>(i);
            cout << "  " << i << ". " << namaBulan(bln) << endl;
        }


    // ----- 3. Nilai Lompat - Planet -----
        cout << endl << "=== 3. Nilai Lompat - Planet ===" << endl;

        cout << "MERKURIUS = " << MERKURIUS << endl;
        cout << "VENUS     = " << VENUS     << endl;
        cout << "BUMI      = " << BUMI      << endl;
        cout << "MARS      = " << MARS      << endl;
        cout << "JUPITER   = " << JUPITER   << " (lompat ke 100)" << endl;
        cout << "SATURNUS  = " << SATURNUS  << " (otomatis 101)" << endl;


    // ----- 4. Bit Flags - Izin -----
        cout << endl << "=== 4. Bit Flags - Sistem Izin ===" << endl;

        // Kombinasi izin dengan OR
            int izinUser = BACA | TULIS;           // = 1 | 2 = 3
            int izinAdmin = BACA | TULIS | EKSEKUSI; // = 1 | 2 | 4 = 7

            cout << "Izin user  = " << izinUser  << " (BACA + TULIS)" << endl;
            cout << "Izin admin = " << izinAdmin << " (BACA + TULIS + EKSEKUSI)" << endl;

        // Cek izin dengan AND
            cout << endl << "Cek izin user:" << endl;
            cout << "  Bisa BACA?     " << ((izinUser & BACA)     ? "Ya" : "Tidak") << endl;
            cout << "  Bisa TULIS?    " << ((izinUser & TULIS)    ? "Ya" : "Tidak") << endl;
            cout << "  Bisa EKSEKUSI? " << ((izinUser & EKSEKUSI) ? "Ya" : "Tidak") << endl;

            cout << "Cek izin admin:" << endl;
            cout << "  Bisa BACA?     " << ((izinAdmin & BACA)     ? "Ya" : "Tidak") << endl;
            cout << "  Bisa TULIS?    " << ((izinAdmin & TULIS)    ? "Ya" : "Tidak") << endl;
            cout << "  Bisa EKSEKUSI? " << ((izinAdmin & EKSEKUSI) ? "Ya" : "Tidak") << endl;


    // ----- 5. Konversi Enum ke String -----
        cout << endl << "=== 5. Konversi Enum ke String ===" << endl;

        Musim m = PANCAROBA;
        cout << "Musim saat ini: " << namaMusim(m) << endl;
        cout << "Nilai intnya  : " << m << endl;

        for (int i = HUJAN; i <= PANCAROBA; i++) {
            Musim musim = static_cast<Musim>(i);
            cout << "  " << i << " = " << namaMusim(musim) << endl;
        }

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

// ----- Underlying type: unsigned char (hemat memory) -----
    enum class Bulan : unsigned char {
        JAN=1, FEB, MAR, APR, MEI, JUN,
        JUL, AGU, SEP, OKT, NOV, DES
    };

// ----- Underlying type: long long (nilai besar) -----
    enum class KodeError : long long {
        OK        = 0,
        PERINGATAN = 1000,
        ERROR      = 5000,
        FATAL      = 9999999999LL
    };

// ----- Enum class sebagai member struct -----
    enum class Gender { LAKI, PEREMPUAN };

    enum class StatusMahasiswa { AKTIF, CUTI, LULUS, DO };

    struct Mahasiswa {
        string         nama;
        int            umur;
        Gender         gender;
        StatusMahasiswa status;
        double         ipk;
    };

// ----- Enum class untuk state machine -----
    enum class StatePintu { TERKUNCI, TERTUTUP, TERBUKA };


// ----- Fungsi konversi -----
    string namaBulan(Bulan b) {
        string nama[] = {
            "", "Januari","Februari","Maret","April","Mei","Juni",
            "Juli","Agustus","September","Oktober","November","Desember"
        };
        int idx = static_cast<int>(b);
        return (idx >= 1 && idx <= 12) ? nama[idx] : "Tidak Valid";
    }

    string namaGender(Gender g) {
        return (g == Gender::LAKI) ? "Laki-laki" : "Perempuan";
    }

    string namaStatus(StatusMahasiswa s) {
        switch (s) {
            case StatusMahasiswa::AKTIF:  return "Aktif";
            case StatusMahasiswa::CUTI:   return "Cuti";
            case StatusMahasiswa::LULUS:  return "Lulus";
            case StatusMahasiswa::DO:     return "Drop Out";
            default:                      return "Tidak Dikenal";
        }
    }

    string namaState(StatePintu s) {
        switch (s) {
            case StatePintu::TERKUNCI:  return "Terkunci";
            case StatePintu::TERTUTUP:  return "Tertutup";
            case StatePintu::TERBUKA:   return "Terbuka";
            default:                    return "Tidak Dikenal";
        }
    }

// ----- State machine: transisi status pintu -----
    StatePintu buka(StatePintu state) {
        switch (state) {
            case StatePintu::TERKUNCI:
                cout << "  Tidak bisa dibuka, masih terkunci!" << endl;
                return state;
            case StatePintu::TERTUTUP:
                cout << "  Pintu dibuka." << endl;
                return StatePintu::TERBUKA;
            case StatePintu::TERBUKA:
                cout << "  Pintu sudah terbuka." << endl;
                return state;
            default:
                return state;
        }
    }

    StatePintu kunci(StatePintu state) {
        switch (state) {
            case StatePintu::TERBUKA:
                cout << "  Tutup dulu sebelum kunci!" << endl;
                return state;
            case StatePintu::TERTUTUP:
                cout << "  Pintu dikunci." << endl;
                return StatePintu::TERKUNCI;
            case StatePintu::TERKUNCI:
                cout << "  Pintu sudah terkunci." << endl;
                return state;
            default:
                return state;
        }
    }


int main() {

    // ----- 1. Underlying Type -----
        cout << "=== 1. Underlying Type ===" << endl;

        cout << "sizeof(Bulan) dengan unsigned char = " << sizeof(Bulan) << " byte" << endl;
        cout << "sizeof(int)                         = " << sizeof(int)   << " byte" << endl;
        cout << "Hemat " << sizeof(int) - sizeof(Bulan) << " byte per variabel!" << endl;

        Bulan b = Bulan::MEI;
        cout << endl << "Bulan::MEI = " << static_cast<int>(b) << " -> " << namaBulan(b) << endl;


    // ----- 2. KodeError dengan long long -----
        cout << endl << "=== 2. KodeError dengan long long ===" << endl;

        KodeError err = KodeError::FATAL;
        cout << "KodeError::FATAL = " << static_cast<long long>(err) << endl;
        cout << "sizeof(KodeError) = " << sizeof(KodeError) << " byte" << endl;


    // ----- 3. Enum Class sebagai Member Struct -----
        cout << endl << "=== 3. Enum Class sebagai Member Struct ===" << endl;

        Mahasiswa mhs1 = {"Budi", 20, Gender::LAKI, StatusMahasiswa::AKTIF, 3.85};
        Mahasiswa mhs2 = {"Sari", 22, Gender::PEREMPUAN, StatusMahasiswa::LULUS, 3.90};

        Mahasiswa daftar[] = {mhs1, mhs2};

        for (const Mahasiswa& m : daftar) {
            cout << m.nama << " | " << namaGender(m.gender) << " | " << namaStatus(m.status) << " | IPK=" << m.ipk << endl;
        }


    // ----- 4. State Machine dengan Enum Class -----
        cout << endl << "=== 4. State Machine - Pintu ===" << endl;

        StatePintu pintu = StatePintu::TERKUNCI;
        cout << "State awal: " << namaState(pintu) << endl;

        cout << "Coba buka:"; pintu = buka(pintu);
        cout << "State: " << namaState(pintu) << endl;

        // Kita perlu unlock dulu secara manual (simulasi)
        cout << "Unlock (simulasi)..." << endl;
        pintu = StatePintu::TERTUTUP;
        cout << "State: " << namaState(pintu) << endl;

        cout << "Coba buka:"; pintu = buka(pintu);
        cout << "State: " << namaState(pintu) << endl;

        cout << "Coba kunci:"; pintu = kunci(pintu);
        cout << "State: " << namaState(pintu) << endl;

        cout << "Coba tutup (simulasi)..." << endl;
        pintu = StatePintu::TERTUTUP;
        cout << "Coba kunci:"; pintu = kunci(pintu);
        cout << "State: " << namaState(pintu) << endl;


    // ----- 5. Iterasi Bulan -----
        cout << endl << "=== 5. Iterasi Bulan (Underlying Type) ===" << endl;

        for (int i = 1; i <= 12; i++) {
            Bulan bln = static_cast<Bulan>(i);
            cout << "  " << i << ". " << namaBulan(bln) << endl;
        }

    return 0;
}

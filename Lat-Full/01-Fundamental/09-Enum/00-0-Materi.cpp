/*
    DAFTAR ISI MODUL ENUM
    ============================================================
    00  Overview                    <- kamu di sini
    01  Enum-Unscoped
    02  Nilai-Custom-dan-Konversi
    03  Enum-dan-Switch
    04  Enum-Class
    05  Enum-Class-Fitur-Lanjutan
    06  Enum-vs-Enum-Class
    ============================================================
*/

// Z.0 - Overview

    /* APA ITU ENUM?
        -------------------------------------------------------
        Enum (Enumeration) adalah tipe data buatan sendiri yang
        berisi sekumpulan KONSTANTA BERNAMA (named constants).

        Analogi:
            Lampu lalu lintas hanya punya 3 kemungkinan:
            MERAH, KUNING, HIJAU. Tidak ada nilai lain yang valid!
            Enum sempurna untuk situasi "pilihan terbatas" seperti ini.
    */

    /* MENGAPA BUTUH ENUM?
        -------------------------------------------------------
        Tanpa enum (tidak jelas, rawan bug - "magic number"):
            int status = 1;       // 1 itu apa? Aktif? Merah? Benar?
            if (status == 3) ...  // 3 artinya apa??

        Dengan enum (jelas, aman, self-documenting):
            enum Status { AKTIF, NONAKTIF, PENDING };
            Status s = AKTIF;
            if (s == AKTIF) ...   // sangat readable!

        Keuntungan pakai enum:
            - Kode lebih mudah dibaca (self-documenting)
            - Mencegah nilai yang tidak valid
            - IDE bisa bantu autocomplete
            - Lebih mudah di-maintain
    */

    /* DUA JENIS ENUM DI C++
        -------------------------------------------------------
        1. enum (unscoped / classic)
            - Ada sejak awal C++
            - Nama "bocor" ke scope luar
            - Implicit conversion ke int
            - Bisa konflik nama

        2. enum class (scoped)
            - Diperkenalkan di C++11
            - Nama tersimpan di scope sendiri
            - Tidak ada implicit conversion ke int
            - Lebih type-safe, direkomendasikan untuk kode baru
    */

    /* PERBANDINGAN SINGKAT
        -------------------------------------------------------
        Fitur               enum              enum class
        ------------------- ---------------   ----------------
        Scope nama          Bocor ke luar     Tersimpan sendiri
        Akses member        MERAH             Warna::MERAH
        Ke int (implicit)   Bisa              Tidak bisa
        Konflik nama        Bisa terjadi      Tidak bisa
        Type safety         Rendah            Tinggi
        Direkomendasikan    Kode lama/C       Kode C++ modern
    */

// Z.1 - Enum Unscoped

    /* SYNTAX DEKLARASI ENUM
        -------------------------------------------------------
        enum NamaEnum {
            NILAI_1,    // otomatis = 0
            NILAI_2,    // otomatis = 1
            NILAI_3,    // otomatis = 2
        };

        Variabel dari tipe enum:
            NamaEnum variabel = NILAI_1;

        Nama enum biasanya UPPERCASE (konvensi umum).

    */

    /* NILAI DEFAULT
        -------------------------------------------------------
        Secara default, nilai dimulai dari 0 dan naik +1.

            enum Hari {
                SENIN,      // = 0
                SELASA,     // = 1
                RABU,       // = 2
                KAMIS,      // = 3
                JUMAT,      // = 4
                SABTU,      // = 5
                MINGGU      // = 6
            };
    */

    /* MASALAH SCOPE (NAME POLLUTION)
        -------------------------------------------------------
        Karena enum unscoped, nama-namanya masuk ke scope yang SAMA
        dengan variabel biasa di sekitarnya.

        Masalah konflik:
            enum Warna1 { MERAH, HIJAU };
            enum Warna2 { MERAH, BIRU };    // ERROR! MERAH sudah ada!

        Solusi: pakai enum class (dibahas di 04-Enum-Class.cpp)
    */

    /* IMPLICIT CONVERSION KE INT
        -------------------------------------------------------
        Enum unscoped bisa otomatis diconvert ke int:
            Warna w = HIJAU;
            int angka = w;    // OK, angka = 1

        Tapi int ke enum TIDAK otomatis:
            Warna w = 2;               // ERROR di C++
            Warna w = (Warna)2;        // OK, explicit C-cast
            Warna w = static_cast<Warna>(2);  // OK, C++ style
    */

// Z.2 - Nilai Custom dan Konversi

    /* NILAI CUSTOM DAN NILAI OTOMATIS
        -------------------------------------------------------
        Secara default, nilai dimulai dari 0, naik +1.
        Tapi bisa dikustom sesuai kebutuhan:

            enum Planet {
                MERKURIUS = 1,
                VENUS,          // = 2  (otomatis +1 dari sebelumnya)
                BUMI,           // = 3
                MARS,           // = 4
                JUPITER = 100,  // lompat ke 100
                SATURNUS        // = 101 (otomatis +1 lagi)
            };

        Aturan:
        - Kalau tidak ditentukan, nilai = nilai sebelumnya + 1
        - Nilai boleh sama antar konstanta (tapi biasanya dihindari)
        - Nilai bisa negatif
    */

    /* USE CASE NILAI CUSTOM
        -------------------------------------------------------
        HTTP Status code:
            enum HttpStatus { OK=200, NOT_FOUND=404, ERROR=500 };

        Bit flags (nilai harus kelipatan 2):
            enum Izin { BACA=1, TULIS=2, EKSEKUSI=4 };
            // bisa di-OR: izin = BACA | TULIS = 3

        Mulai dari 1 (bukan 0):
            enum Bulan { JAN=1, FEB, MAR, APR, MEI, JUN,
                        JUL, AGU, SEP, OKT, NOV, DES };
    */

    /* KONVERSI ENUM KE STRING
        -------------------------------------------------------
        C++ tidak punya cara otomatis untuk cetak nama enum.
        Harus dibuat manual, biasanya pakai switch atau array:

            string namaMusim(Musim m) {
                switch (m) {
                    case HUJAN:    return "Hujan";
                    case KEMARAU:  return "Kemarau";
                    default:       return "Tidak Diketahui";
                }
            }
    */

// Z.3 - Enum dan Switch

    /* ENUM + SWITCH: KOMBINASI FAVORIT
        -------------------------------------------------------
        Enum dan switch-case adalah pasangan yang sangat serasi.
        Switch-case menjadi sangat readable ketika casnya adalah
        konstanta enum yang bermakna.

        Contoh:
            enum Musim { HUJAN, KEMARAU, PANCAROBA };
            Musim m = HUJAN;

            switch (m) {
                case HUJAN:     cout << "Bawa payung!"; break;
                case KEMARAU:   cout << "Pakai sunscreen!"; break;
                case PANCAROBA: cout << "Waspada cuaca!"; break;
            }

        Dibandingkan dengan magic number:
            int m = 0;
            switch (m) {
                case 0:  cout << "Bawa payung!"; break;   // 0 itu apa???
                case 1:  ...
            }
    */

    /* EXHAUSTIVE SWITCH (LENGKAP)
        -------------------------------------------------------
        Best practice: tangani SEMUA kemungkinan nilai enum.
        Tambahkan default untuk keamanan.

            switch (m) {
                case HUJAN:     ...; break;
                case KEMARAU:   ...; break;
                case PANCAROBA: ...; break;
                default:
                    cout << "Nilai tidak dikenal!" << endl;
            }

        Kalau ada nilai enum yang tidak dihandle, beberapa
        compiler akan memberikan warning - manfaatkan ini!
    */

    /* ENUM SEBAGAI RETURN VALUE
        -------------------------------------------------------
        Function bisa mengembalikan enum untuk merepresentasikan
        hasil atau status operasi dengan lebih jelas.

            enum HasilLogin { LOGIN_OK, SALAH_PASSWORD, USER_TIDAK_ADA };

            HasilLogin login(string user, string pass) {
                if (user tidak ada) return USER_TIDAK_ADA;
                if (pass salah)     return SALAH_PASSWORD;
                return LOGIN_OK;
            }
    */

// Z.4 - Enum Class

    /* APA ITU ENUM CLASS?
        -------------------------------------------------------
        Diperkenalkan di C++11, enum class adalah versi yang
        LEBIH AMAN dan LEBIH KETAT dari enum biasa.

        Perbedaan utama dari enum biasa:
        - Nama tersimpan dalam SCOPE sendiri (tidak bocor)
        - TIDAK ada implicit conversion ke int
        - Lebih type-safe
    */

    /* SYNTAX
        -------------------------------------------------------
        enum class NamaEnum {
            NILAI_1,
            NILAI_2,
            NILAI_3
        };

        Akses member WAJIB pakai nama enum + :: (scope resolution):
            enum class Warna { MERAH, HIJAU, BIRU };
            Warna w = Warna::HIJAU;     // HARUS pakai Warna::
            // Warna w = HIJAU;         // ERROR! Tidak bisa langsung
    */

    /* TIDAK ADA IMPLICIT CONVERSION KE INT
        -------------------------------------------------------
            enum class Status { AKTIF, NONAKTIF };
            Status s = Status::AKTIF;

            int x = s;                      // ERROR! Tidak bisa implicit
            int x = (int)s;                 // OK, C-style cast
            int x = static_cast<int>(s);    // OK, C++ style (disarankan)
    */

    /* TIDAK ADA KONFLIK NAMA
        -------------------------------------------------------
        Karena nama tersimpan dalam scope sendiri:
            enum class Arah   { UTARA, SELATAN };
            enum class Tombol { UTARA, SELATAN };   // OK! Tidak konflik

            Arah a   = Arah::UTARA;     // jelas milik Arah
            Tombol t = Tombol::UTARA;   // jelas milik Tombol
    */

    /* SWITCH DENGAN ENUM CLASS
        -------------------------------------------------------
        Sama seperti enum biasa, tapi harus pakai NamaEnum::

            switch (s) {
                case Status::AKTIF:    ...; break;
                case Status::NONAKTIF: ...; break;
            }
    */

// Z.5 - Enum Class Fitur Lanjutan

    /* UNDERLYING TYPE (TIPE DASAR)
        -------------------------------------------------------
        Secara default, nilai enum class disimpan sebagai int (4 byte).
        Bisa diubah ke tipe lain:

        Syntax:
            enum class NamaEnum : tipe_dasar { ... };

        Contoh:
            enum class Bulan : unsigned char {   // hanya 1 byte!
                JAN=1, FEB, MAR, ...
            };

            enum class KodeError : long long {   // butuh nilai besar
                OK = 0, FATAL = 9999999999LL
            };

        Tipe yang bisa dipakai:
            char, unsigned char, short, unsigned short,
            int, unsigned int, long, long long, dll.

        Kapan berguna:
            - Hemat memory (char = 1 byte vs int = 4 byte)
            - Nilai yang sangat besar (long long)
            - Interoperasi dengan library C yang pakai tipe tertentu

    */

    /* ENUM CLASS + STRUCT
        -------------------------------------------------------
        Enum class sangat cocok dipakai sebagai member struct:

            enum class Gender { LAKI, PEREMPUAN };

            struct Orang {
                string nama;
                int    umur;
                Gender gender;   // enum class sebagai member!
            };

        Ini membuat kode lebih readable dan type-safe dibanding
        menyimpan gender sebagai int atau char.
    */

    /* ENUM CLASS SEBAGAI PARAMETER DAN RETURN 
        ------------------------------------------------------------
        Enum class bisa dipakai sebagai parameter function
        dan return value, sama seperti tipe data lainnya.
    */

// Z.6 - Enum vs Enum Class

    /* PERBANDINGAN LENGKAP
        ------------------------|----------------------|--------------------------
        Fitur                   |  enum (unscoped)     | enum class (scoped)
        ------------------------|----------------------|--------------------------
        Scope nama              |  Bocor ke luar       | Tersimpan dalam enum
        Akses member            |  MERAH               | Warna::MERAH
        Implicit ke int         |  Bisa (otomatis)     | Tidak bisa
        Explicit cast ke int    |  Bisa                | Bisa (static_cast)
        Konflik nama            |  Bisa terjadi        | Tidak bisa terjadi
        Type safety             |  Rendah              | Tinggi
        Underlying type         |  Bisa diubah (C++11) | Bisa diubah (C++11)
        Switch-case             |  Bisa                | Bisa (dengan NamaEnum::)
        Direkomendasikan        |  Kode lama/C-compat  | Kode C++ modern
    */

    /* KAPAN PAKAI ENUM (UNSCOPED)?
        -------------------------------------------------------
            - Mempertahankan kompatibilitas dengan kode C lama
            - Kode yang sering diconvert ke int secara implisit
            - Konstanta yang memang perlu "bocor" ke scope luar
            - Bit flags yang sering di-OR bersama (lebih ringkas)
    */

    /* KAPAN PAKAI ENUM CLASS?
        -------------------------------------------------------
            - Kode C++ modern (C++11 ke atas)
            - Saat ada risiko konflik nama dengan enum lain
            - Saat tidak mau konversi implicit ke int
            - Saat butuh type safety yang lebih ketat
            - Default pilihan untuk enum baru
    */

    /* ATURAN PRAKTIS
        -------------------------------------------------------
        "Untuk kode C++ baru: selalu pakai enum class.
        Untuk interoperasi dengan C atau kode lama: pakai enum."
    */
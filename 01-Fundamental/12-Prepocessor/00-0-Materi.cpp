/*
    DAFTAR ISI MODUL PREPROCESSOR
    ============================================================
    00  Overview                        <- kamu di sini
    01  include
    02  define-Konstanta-dan-Macro
    03  Macro-Lanjutan
    04  undef-dan-Predefined-Macro
    05  Include-Guard-dan-pragma-once
    06  Conditional-Compilation
    07  pragma
    08  Best-Practices-dan-Konteks-Nyata
    ============================================================
*/

// AC.0 - Overview

    /* APA ITU PREPROCESSOR?
        -------------------------------------------------------
        Preprocessor adalah tahap PERTAMA yang dijalankan sebelum
        kode C++ benar-benar dikompilasi.

        Preprocessor membaca source code dan melakukan
        TRANSFORMASI TEKS berdasarkan instruksi yang diawali #.
        Instruksi ini disebut PREPROCESSOR DIRECTIVE.

        PENTING: Preprocessor bekerja pada level TEKS, bukan
        level bahasa. Ia tidak mengerti tipe data, fungsi, atau
        class C++. Ia hanya melakukan find-and-replace pada teks.
    */

    /* ALUR KOMPILASI C++
        -------------------------------------------------------
        Source Code (.cpp)
            --> Preprocessor   (transformasi teks, jalan PERTAMA)
            --> Compiler       (ubah ke object code)
            --> Linker         (gabungkan jadi .exe)
    */

    /* YANG DILAKUKAN PREPROCESSOR
        -------------------------------------------------------
            - Menyalin isi file header ke kode (#include)
            - Mengganti nama macro dengan nilainya (#define)
            - Menghapus atau menyertakan bagian kode (#ifdef, #if)
            - Memberikan instruksi khusus ke compiler (#pragma)
    */

    /* CIRI-CIRI PREPROCESSOR DIRECTIVE
        -------------------------------------------------------
        - Selalu dimulai dengan tanda #  (hash / pound)
        - Berdiri sendiri di satu baris
        - TIDAK diakhiri dengan titik koma ( ; )
        - Diproses SEBELUM kode apapun dikompilasi

        Contoh:
            #include <iostream>    // benar
            #include <iostream>;   // salah - ada titik koma!
            int x = 5;             // ini bukan directive, ini C++
    */

    /* DAFTAR SEMUA DIRECTIVE
        -------------------------------------------------------
        Direktif              Fungsi
        --------------------  ------------------------------------------
        #include              Sertakan isi file lain
        #define               Definisikan macro atau konstanta
        #undef                Hapus definisi macro
        #ifdef / #ifndef      Kompilasi bersyarat (if defined / not)
        #if / #elif / #else   Kompilasi bersyarat (kondisi numerik)
        #endif                Tutup blok kompilasi bersyarat
        #pragma               Instruksi khusus untuk compiler
        #error                Paksa error saat kompilasi
        #warning              Tampilkan peringatan saat kompilasi
    */

// AC.1 -  include

    /* APA ITU #include?
        -------------------------------------------------------
        #include memberitahu preprocessor untuk mengambil isi
        file lain dan "menempelkannya" langsung di titik directive
        itu berada.

        Ibarat copy-paste otomatis isi file ke dalam kode kita.
    */

    /*  DUA BENTUK #include
        -------------------------------------------------------
        a. Angle brackets < >   -> untuk library standar / sistem
            Preprocessor mencari di direktori sistem / compiler.

                #include <iostream>     // cin, cout
                #include <string>       // std::string
                #include <vector>       // std::vector
                #include <algorithm>    // sort, find, dll
                #include <cmath>        // sqrt, pow, abs, dll
                #include <fstream>      // ifstream, ofstream
                #include <stdexcept>    // runtime_error, dll
                #include <iomanip>      // setw, setprecision, dll
                #include <sstream>      // stringstream

        b. Double quotes " "    -> untuk file buatan sendiri
            Preprocessor mencari di direktori yang sama dulu,
            baru cari di direktori sistem jika tidak ketemu.

                #include "mathHelper.h"
                #include "config.h"
                #include "../utils/helper.h"    // path relatif ke atas
    */

    /* APA YANG TERJADI SAAT #include?
        -------------------------------------------------------
        Misalnya kita punya myHeader.h:
            // myHeader.h
            int tambah(int a, int b) {
                return a + b;
            }

        Dan main.cpp:
            #include "myHeader.h"
            int main() {
                cout << tambah(3, 4);
            }

        Setelah preprocessor, main.cpp "seolah-olah" menjadi:
            int tambah(int a, int b) {   // isi myHeader.h disalin
                return a + b;
            }
            int main() {
                cout << tambah(3, 4);
            }
    */

    /* ISI HEADER FILE (.h) YANG UMUM
        -------------------------------------------------------
        Header file biasanya berisi:
            - Deklarasi fungsi (bukan definisi)
            - Deklarasi class / struct
            - Definisi struct, enum, typedef
            - Konstanta dan macro
            - Template definition (HARUS di header, bukan .cpp!)

        Kenapa deklarasi saja, bukan definisi?
            Karena header di-include oleh banyak file .cpp.
            Kalau ada definisi, akan ada banyak definisi ganda
            saat linker bekerja -> linker error!

        Yang BOLEH ada di header (tidak menyebabkan duplikat):
            - Deklarasi fungsi (bukan badan fungsinya)
            - Struct / class declaration
            - Inline function (badan boleh ada)
            - Template function / class (badan wajib ada)
            - constexpr / const variable
    */

    /* MASALAH MULTIPLE INCLUSION
        -------------------------------------------------------
        Kalau header di-include lebih dari sekali (langsung
        atau tidak langsung), compiler mendapat definisi ganda!

            // main.cpp
            #include "A.h"    // A.h juga include base.h
            #include "B.h"    // B.h juga include base.h
            // base.h masuk DUA KALI -> error redefinition!

        Solusi: include guards (#ifndef) atau #pragma once.
        (Dibahas detail di file 05-Include-Guard-dan-pragma-once.cpp)
    */

    /* HEADER STANDAR C++ YANG SERING DIPAKAI
        -------------------------------------------------------
        Header              Isi Utama
        ------------------  ------------------------------------
        <iostream>          cin, cout, cerr, endl
        <string>            std::string
        <vector>            std::vector
        <array>             std::array
        <map>               std::map, std::multimap
        <set>               std::set
        <algorithm>         sort, find, min, max, dll
        <numeric>           accumulate, iota, dll
        <cmath>             sqrt, pow, abs, sin, cos, dll
        <cstring>           strlen, strcpy, strcmp, dll
        <fstream>           ifstream, ofstream, fstream
        <sstream>           stringstream, istringstream
        <iomanip>           setw, setprecision, fixed
        <stdexcept>         runtime_error, invalid_argument, dll
        <memory>            unique_ptr, shared_ptr, make_unique
        <utility>           pair, make_pair, move
        <functional>        function, bind
        <chrono>            durasi dan waktu
        <random>            random number generation
        <cassert>           assert()
        <cstdlib>           exit(), abs(), rand(), dll
        <climits>           INT_MAX, INT_MIN, LLONG_MAX, dll
    */

// AC.2 - define Konstanta dan Macro

    /* APA ITU #define?
        -------------------------------------------------------
        #define mendefinisikan sebuah MACRO — nama yang akan
        digantikan preprocessor dengan teks lain SEBELUM kompilasi.

        Syntax:
            #define NAMA_MACRO   nilai_atau_teks

        Konvensi: nama macro pakai HURUF_KAPITAL_SEMUA.

        Cara kerja (text substitution):
            #define PI  3.14159265

            area = PI * r * r;
            // Preprocessor ubah jadi:
            area = 3.14159265 * r * r;
            // Compiler tidak pernah "tahu" ada PI
    */

    /* OBJECT-LIKE MACRO (Konstanta Sederhana)
        -------------------------------------------------------
        Mendefinisikan nama sebagai nilai atau teks tertentu.

            #define PI          3.14159265
            #define MAX_SIZE    100
            #define APP_NAME    "MyApp v1.0"
            #define NEWLINE     '\n'

        Perbandingan dengan const / constexpr:
            #define MAX 100              <- tidak ada tipe, tidak ada scope
            const int MAX = 100;         <- ada tipe, ada scope (lebih baik)
            constexpr int MAX = 100;     <- compile-time, ada tipe (terbaik)

        Kapan masih pakai #define:
            - Header guard (#ifndef HEADER_H)
            - Debug/platform flag yang dikontrol dari luar (g++ -DDEBUG)
            - Kompatibilitas dengan kode C lama
    */

    /* FUNCTION-LIKE MACRO
        -------------------------------------------------------
        Macro bisa menerima argumen seperti fungsi:

            #define KUADRAT(x)    ((x) * (x))
            #define MAKS(a, b)    ((a) > (b) ? (a) : (b))
            #define ABS(x)        ((x) >= 0 ? (x) : -(x))

        WAJIB pakai tanda kurung di luar DAN di setiap argumen!
    */

    /* BAHAYA #1: Tidak Ada Kurung -> Operator Precedence Salah
    -------------------------------------------------------
        #define KUADRAT_SALAH(x)   x * x

        KUADRAT_SALAH(2 + 3)
        // -> 2 + 3 * 2 + 3   <- SALAH! Precedence * lebih tinggi
        // Hasil: 11 (bukan 25!)

        KUADRAT(2 + 3)
        // -> ((2 + 3) * (2 + 3))   <- kurung melindungi
        // Hasil: 25 (benar)
    */

    /* BAHAYA #2: Side Effect - Argumen Dievaluasi Lebih dari Sekali
        -------------------------------------------------------
            int a = 5;
            int b = MAKS(a++, 3);
            // -> ((a++) > (3) ? (a++) : (3))   <- a++ dievaluasi DUA KALI!
            // Nilai a bisa jadi 6 atau 7 bergantung kondisi -> bug!

        Solusi: pakai inline function atau template.
            inline int maks(int a, int b) { return a > b ? a : b; }
            template<typename T> T maks(T a, T b) { return a > b ? a : b; }
    */

    /* MACRO MULTILINE dengan Backslash (\)
        -------------------------------------------------------
            Gunakan \ untuk lanjut ke baris berikutnya:

                #define LOG_ERROR(msg) \
                    cerr << "[ERROR] " << __FILE__ \
                        << ":" << __LINE__ \
                        << " - " << msg << endl

        Tidak boleh ada spasi setelah \ (harus langsung newline).
    */

// AC.3 - Macro Lanjutan

    /* STRINGIFICATION (#) - Ubah Argumen Jadi String
        -------------------------------------------------------
        Operator # di dalam macro mengubah argumen menjadi
        string literal (teks di dalam tanda kutip).

            #define CETAK_VAR(x)   cout << #x << " = " << (x) << endl

            int nilai = 42;
            CETAK_VAR(nilai);
            // Preprocessor ubah menjadi:
            // cout << "nilai" << " = " << (nilai) << endl;
            // Output: nilai = 42

        Berguna untuk debugging: print nama variabel sekaligus nilainya!
    */

    /* TOKEN PASTING (##) - Gabungkan Dua Token
        -------------------------------------------------------
        Operator ## menggabungkan dua token menjadi satu:

            #define BUAT_FUNGSI(nama) \
                void fungsi_##nama() { cout << "Fungsi " #nama << endl; }

            BUAT_FUNGSI(Hitung)
            // -> void fungsi_Hitung() { cout << "Fungsi Hitung" << endl; }

            BUAT_FUNGSI(Tampilkan)
            // -> void fungsi_Tampilkan() { ... }

        Berguna untuk generate nama variabel / fungsi secara otomatis.
    */

    /* DO { } WHILE(0) - Pola Aman untuk Macro Multi-Statement
        -------------------------------------------------------
        Masalah macro multi-statement tanpa wrapper:

            #define MACRO_SALAH(x)   stmt1; stmt2;

            if (kondisi)
                MACRO_SALAH(x);
            // Jadi:
            // if (kondisi)
            //     stmt1;
            // stmt2;   <- stmt2 selalu dieksekusi! Bug!

        Solusi: bungkus dengan do { ... } while(0):

            #define MACRO_AMAN(x)   do { stmt1; stmt2; } while(0)

            if (kondisi)
                MACRO_AMAN(x);
            // Jadi:
            // if (kondisi)
            //     do { stmt1; stmt2; } while(0);   <- benar!
    */

    /* VARIADIC MACRO (C++11) - Argumen Tidak Tetap
        -------------------------------------------------------
        Macro yang menerima jumlah argumen tidak tetap:

            #define LOG(fmt, ...)   printf("[LOG] " fmt "\n", ##__VA_ARGS__)

            LOG("Halo!");
            LOG("Nilai: %d", 42);
            LOG("Nama: %s, Umur: %d", "Budi", 20);

        __VA_ARGS__ digantikan dengan argumen variadic.
        ## sebelum __VA_ARGS__ mencegah comma ekstra jika tidak ada argumen.
    */

// AC.4 - undef dan Predefined Macro

    /* #undef - HAPUS DEFINISI MACRO
        -------------------------------------------------------
        #undef menghapus definisi macro yang sudah dibuat sebelumnya.
        Setelah #undef, nama macro tidak lagi dikenal di bawah titik itu.

        Syntax:
            #undef NAMA_MACRO

        Contoh:
            #define TEMP 42
            cout << TEMP;    // -> cout << 42;  (OK)

            #undef TEMP
            cout << TEMP;    // ERROR: TEMP tidak dikenal lagi!

        Kegunaan #undef:
            1. Batasi scope macro agar tidak bocor ke bawah
            2. Redefine macro dengan nilai baru (undef dulu, baru define ulang)
            3. Menghindari konflik nama dengan library lain
            4. Sengaja override macro dari library lain
    */

    /* REDEFINE MACRO DENGAN #undef
        -------------------------------------------------------
        Tidak bisa langsung #define ulang nama yang sudah ada
        (compiler bisa kasih warning). Solusinya: #undef dulu.

            #define BATAS 100
            // ... kode pakai BATAS ...

            #undef BATAS
            #define BATAS 500   // define ulang dengan nilai baru
            // ... kode pakai BATAS yang baru ...

    */

    /* PREDEFINED MACROS (SUDAH ADA DARI COMPILER)
        -------------------------------------------------------
        Macro-macro ini sudah otomatis ada, tidak perlu didefinisikan:

        Macro           Tipe     Isi
        --------------- -------- --------------------------------------
        __FILE__        string   Nama file saat ini (path lengkap/relatif)
        __LINE__        int      Nomor baris saat ini
        __func__        string   Nama fungsi saat ini (C++11)
        __DATE__        string   Tanggal kompilasi ("Jan 14 2025")
        __TIME__        string   Waktu kompilasi ("10:30:00")
        __cplusplus     long     Versi standar C++:
                                199711L = C++98/03
                                201103L = C++11
                                201402L = C++14
                                201703L = C++17
                                202002L = C++20
                                202302L = C++23

        Platform (otomatis dari compiler):
            _WIN32 / _WIN64   -> Windows
            __linux__         -> Linux
            __APPLE__         -> macOS / iOS
            __unix__          -> Unix-like
    */

    /* KEGUNAAN PREDEFINED MACROS
        -------------------------------------------------------
        1. Debug logging dengan lokasi otomatis:
            cout << "Error di " << __FILE__ << ":" << __LINE__;

        2. Assert dengan pesan lokasi:
            if (!kondisi) {
                cerr << "Gagal: " << __func__ << " baris " << __LINE__;
            }

        3. Cek versi C++ untuk fitur:
            #if __cplusplus >= 201703L
                // Pakai fitur C++17
            #endif
    */

// AC.5 - Include Guard dan pragma once

    /*  MASALAH: DOUBLE INCLUSION (MULTIPLE INCLUSION)
        -------------------------------------------------------
        Header sering di-include lebih dari sekali melalui
        rantai dependency yang tidak terlihat langsung.

        Contoh masalah:
            // main.cpp
            #include "point.h"    // include point.h langsung
            #include "shapes.h"   // shapes.h juga include point.h

            // Akibat: isi point.h masuk DUA KALI
            // -> Redefinition error dari compiler!

        Contoh rantai dependency:
            main.cpp
                includes A.h
                    includes base.h
                includes B.h
                    includes base.h  <- masuk lagi! Error!

    */

    /* SOLUSI 1: INCLUDE GUARD (Cara Klasik, Standar ISO)
        -------------------------------------------------------
        Pola:
            #ifndef NAMA_HEADER_H     <- jika belum didefinisikan
            #define NAMA_HEADER_H     <- definisikan sekarang

            // isi header di sini

            #endif                    <- tutup blok

        Cara kerja:
            Include ke-1: NAMA_HEADER_H belum ada
                        -> masuk ke blok
                        -> define NAMA_HEADER_H
                        -> isi diproses

            Include ke-2: NAMA_HEADER_H sudah ada
                        -> SELURUH blok dilewati
                        -> isi TIDAK diproses lagi

        Konvensi nama guard (ubah nama file jadi UPPER_UNDERSCORE):
            point.h        -> POINT_H
            math_helper.h  -> MATH_HELPER_H
            utils/config.h -> UTILS_CONFIG_H
    */

    /* SOLUSI 2: #pragma once (Cara Modern, Praktis)
        -------------------------------------------------------
        Cukup satu baris di paling atas header:
            #pragma once

        Memberitahu compiler: "proses file ini hanya SATU KALI,
        tidak peduli berapa kali di-include."

        Kelebihan vs include guard:
            + Lebih singkat (1 baris vs 3 baris)
            + Tidak ada risiko typo nama guard
            + Sedikit lebih cepat dikompilasi
            + Didukung semua compiler modern (GCC, Clang, MSVC)

        Kekurangan:
            - Bukan standar ISO C++ (tapi de-facto standar)
            - Bisa bermasalah jika file yang sama ada di dua path berbeda
                (edge case yang sangat jarang terjadi)
    */

    /* CONTOH HEADER LENGKAP YANG BENAR
        -------------------------------------------------------
        Dengan include guard:
            #ifndef MATH_HELPER_H
            #define MATH_HELPER_H

            #include <cmath>

            constexpr double PI = 3.14159265358979;

            inline double luasLingkaran(double r) {
                return PI * r * r;
            }

            #endif // MATH_HELPER_H  <- komentar opsional tapi membantu

        Dengan #pragma once:
            #pragma once

            #include <cmath>

            constexpr double PI = 3.14159265358979;

            inline double luasLingkaran(double r) {
                return PI * r * r;
            }
    */

    /* PILIHAN MANA?
        -------------------------------------------------------
            Proyek baru / tim modern    -> #pragma once (lebih ringkas)
            Butuh portabilitas maksimal -> include guard (standar ISO)
            Sudah ada standar di tim    -> ikuti standar yang ada
    */

// AC.6 - Conditional Compilation

    /* APA ITU CONDITIONAL COMPILATION?
        -------------------------------------------------------
        Memilih bagian kode mana yang DIKOMPILASI berdasarkan
        kondisi yang dievaluasi saat preprocessing.

        Ibarat "if-else khusus compiler" — bagian yang tidak
        memenuhi kondisi DIHAPUS TOTAL dari kode sebelum
        compiler berjalan. Tidak ada overhead runtime sama sekali!
    */

    /* #ifdef dan #ifndef
        -------------------------------------------------------
        #ifdef NAMA    -> "Jika NAMA sudah didefinisikan, kompilasi ini"
        #ifndef NAMA   -> "Jika NAMA BELUM didefinisikan, kompilasi ini"

            #define DEBUG_MODE

            #ifdef DEBUG_MODE
                cout << "Debug aktif!";    // DIKOMPILASI
            #endif

            #ifndef RELEASE
                cout << "Ini bukan release";  // DIKOMPILASI (RELEASE tidak ada)
            #endif
    */

    /* #if, #elif, #else, #endif
        -------------------------------------------------------
        Lebih powerful dari #ifdef - bisa evaluasi ekspresi numerik.

            #define VERSI 3

            #if VERSI == 1
                // kode versi 1
            #elif VERSI == 2
                // kode versi 2
            #elif VERSI >= 3
                // kode versi 3+
            #else
                // default
            #endif

        Operator yang bisa dipakai:
            ==  !=  <  >  <=  >=     (perbandingan)
            &&  ||  !                 (logika)
            defined(NAMA)             (cek apakah macro terdefinisi)
    */

    /* OPERATOR defined()
        -------------------------------------------------------
        Bisa dipakai di #if untuk cek lebih dari satu kondisi:

            #if defined(WINDOWS) && !defined(DEBUG)
                // Kode khusus Windows Release mode
            #endif

            #if defined(LINUX) || defined(MACOS)
                // Kode untuk Unix-like
            #endif
    */

    /* KEGUNAAN UTAMA
        -------------------------------------------------------
        1. DEBUG vs RELEASE mode
        2. Platform-specific code (Windows vs Linux vs Mac)
        3. Cek versi C++ untuk fitur modern
        4. Feature flags (Enterprise vs Standard edition)
        5. Include guard (sudah dibahas di file 05)
    */

    /* #error dan #warning
        -------------------------------------------------------
        #error  -> berhentikan kompilasi dengan pesan error
        #warning -> lanjut kompilasi tapi tampilkan peringatan

            #ifndef MAKS_BUFFER
                #error "MAKS_BUFFER harus didefinisikan!"
            #endif

            #if MAKS_BUFFER > 65536
                #warning "MAKS_BUFFER sangat besar, hati-hati stack!"
            #endif
    */

// AC.7 - pragma

    /* APA ITU #pragma?
        -------------------------------------------------------
        #pragma memberikan instruksi khusus kepada compiler yang
        bersifat IMPLEMENTATION-DEFINED: setiap compiler boleh
        mengimplementasikan atau mengabaikan pragma berbeda-beda.

        Ciri-ciri #pragma:
            - Tidak standar (tapi banyak yang didukung luas)
            - Diabaikan jika compiler tidak mengerti (tidak error)
            - Dipakai untuk optimasi, peringatan, dan kontrol khusus
    */

    /* #pragma once
        -------------------------------------------------------
        Sudah dibahas di file 05. Mencegah multiple inclusion.

            #pragma once   <- satu baris di atas header
    */

    /* #pragma pack - Kontrol Memory Alignment
        -------------------------------------------------------
        Mengatur bagaimana compiler mengisi "celah" (padding) di struct.

        Default:
            struct Normal {
                char  c;   // 1 byte + 3 byte padding (alignment ke 4)
                int   i;   // 4 byte
            };             // sizeof = 8 (bukan 5!)

        Dengan pack(1):
            #pragma pack(1)
            struct Packed {
                char  c;   // 1 byte
                int   i;   // 4 byte langsung, tanpa padding
            };             // sizeof = 5 (persis)
            #pragma pack() // kembalikan ke default

        Atau pakai push/pop untuk lebih aman:
            #pragma pack(push, 1)
            struct Packed { ... };
            #pragma pack(pop)

        Kapan pakai:
            - Baca/tulis file binary dengan format tertentu
            - Komunikasi jaringan / protokol (byte harus presisi)
            - Embedded systems dengan memory ketat
            - Interoperasi dengan struct C dari library lain
    */

    /* #pragma warning (MSVC) dan #pragma GCC diagnostic
        -------------------------------------------------------
        Kontrol peringatan compiler:

            // MSVC:
            #pragma warning(disable: 4996)   // matikan warning deprecated
            #pragma warning(push)
            #pragma warning(disable: 4100)   // unreferenced parameter
            // ... kode ...
            #pragma warning(pop)             // restore state

            // GCC / Clang:
            #pragma GCC diagnostic push
            #pragma GCC diagnostic ignored "-Wunused-parameter"
            // ... kode ...
            #pragma GCC diagnostic pop

        Berguna untuk: mematikan warning dari kode library pihak ketiga
        yang tidak bisa diubah, tanpa mematikan warning di kode kita sendiri.
    */

    /* #pragma comment (MSVC/Windows)
        -------------------------------------------------------
        Link library secara otomatis:
            #pragma comment(lib, "opengl32.lib")
            #pragma comment(lib, "ws2_32.lib")    <- WinSocket

        Di GCC/Clang: pakai flag saat compile:
            g++ main.cpp -lopengl32 -lws2_32
    */

    /* #pragma message
        -------------------------------------------------------
        Tampilkan pesan saat kompilasi:
            #pragma message("Mengkompilasi modul X...")
            #pragma message("PERHATIAN: fitur Y sedang dikembangkan")

        Berguna untuk: konfirmasi macro aktif, reminder untuk tim.
    */

// AC.8 - Best Practices dan Konteks Nyata

    /* KAPAN PREPROCESSOR TIDAK TERGANTIKAN
        -------------------------------------------------------
        Meski C++ modern punya banyak alternatif (#define vs
        constexpr, dll), ada kasus yang HANYA bisa diselesaikan
        preprocessor:

        1. Include guard / #pragma once
            -> Tidak bisa digantikan oleh C++ biasa

        2. Platform detection dari nama macro kompiler
            -> _WIN32, __linux__, __APPLE__ hanya bisa dicek oleh preprocessor

        3. Debug flag dari command line saat kompilasi
            -> g++ -DDEBUG main.cpp  -> bisa aktifkan/matikan kode tanpa edit file

        4. Kondisi kompilasi berdasarkan versi C++
            -> #if __cplusplus >= 201703L
    */

    /* PERBANDINGAN: LAMA (#define) vs MODERN C++
        -------------------------------------------------------
        Kebutuhan           Cara Lama (#define)         Cara Modern C++
        ------------------- --------------------------- -------------------------
        Konstanta           #define PI 3.14159           constexpr double PI = 3.14159
        Fungsi kecil        #define KUADRAT(x) (x)*(x)  inline / template function
        Kondisi kompilasi   #ifdef / #if                 if constexpr (C++17)
        Include sekali      #ifndef guard                #pragma once
        Tipe alias          #define INT32 int            using INT32 = int;
        String literal      #define NAMA "nilai"         constexpr atau string_view

        Tapi preprocessor TIDAK akan hilang sepenuhnya
        karena kasus di atas tidak bisa digantikan.
    */

    /* POLA-POLA NYATA YANG SERING DIPAKAI
        -------------------------------------------------------
        1. config.h  -> konstanta app, mode build, platform
        2. debug.h   -> macro logging aktif/nonaktif berdasarkan flag
        3. assert.h  -> assert macro dengan info file/baris/fungsi
        4. Struct untuk protokol binary dengan #pragma pack
    */

    /* YANG TIDAK BOLEH DILAKUKAN DENGAN PREPROCESSOR
        -------------------------------------------------------
        1. Jangan definisikan fungsi besar sebagai macro
            -> Pakai inline function / template (ada type checking)

        2. Jangan pakai #define untuk konstanta bertipe
            -> Pakai const atau constexpr (ada scope, ada tipe)

        3. Jangan buat logic kompleks dengan macro
            -> Sulit debug, tidak ada type safety, side-effect berbahaya

        4. Jangan include header yang tidak dibutuhkan
            -> Memperlambat kompilasi

        5. Jangan taruh definisi fungsi di header tanpa inline/static
            -> Multiple definition error saat link

        6. Jangan buat nama macro terlalu pendek / umum
            -> #define MAX 100 bisa clash dengan library lain
            -> Pakai prefix: #define MYAPP_MAX_SIZE 100
    */


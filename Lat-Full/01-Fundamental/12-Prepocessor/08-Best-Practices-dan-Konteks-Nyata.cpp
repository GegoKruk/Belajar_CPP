
#include <iostream>
#include <string>
using namespace std;


//  POLA 1: config.h (disimulasikan di sini)

    #define APP_NAME     "Aplikasi Contoh"
    #define APP_VERSION  "3.1.0"

    // Pilih mode build (biasanya dikontrol dari build system):
    // #define BUILD_DEBUG
    #define BUILD_RELEASE

    #ifdef BUILD_DEBUG
        #define LOG_LEVEL     3      // verbose
        #define ENABLE_ASSERT 1
        const string NAMA_BUILD = "DEBUG";
    #else
        #define LOG_LEVEL     1      // minimal
        const string NAMA_BUILD = "RELEASE";
    #endif

    // Platform detection otomatis dari compiler
    #if defined(_WIN32) || defined(_WIN64)
        #define PLATFORM_WINDOWS
        #define NAMA_PLATFORM "Windows"
    #elif defined(__linux__)
        #define PLATFORM_LINUX
        #define NAMA_PLATFORM "Linux"
    #elif defined(__APPLE__)
        #define PLATFORM_MACOS
        #define NAMA_PLATFORM "macOS"
    #else
        #define NAMA_PLATFORM "Unknown"
    #endif


//  POLA 2: debug.h (disimulasikan di sini)

    #ifdef BUILD_DEBUG
        #define DBG_LOG(x)   cout << "[DBG] " << x << endl
        #define DBG_VAR(x)   cout << "[DBG] " << #x << " = " << (x) << endl
        #define DBG_FUNC()   cout << "[DBG] --> " << __func__ << endl
    #else
        #define DBG_LOG(x)   // kosong di release - tidak ada overhead!
        #define DBG_VAR(x)
        #define DBG_FUNC()
    #endif


//  POLA 3: assert.h custom (disimulasikan di sini)

    #ifdef ENABLE_ASSERT
        #define MY_ASSERT(cond) \
            do { \
                if (!(cond)) { \
                    cerr << "[ASSERT] Gagal: " << #cond << endl; \
                    cerr << "  File  : " << __FILE__ << endl; \
                    cerr << "  Baris : " << __LINE__ << endl; \
                    cerr << "  Fungsi: " << __func__ << endl; \
                } \
            } while(0)
    #else
        #define MY_ASSERT(cond)  // kosong di release
    #endif


//  POLA 4: Struct binary dengan pragma pack
    #pragma pack(push, 1)
    struct RecordSiswa {
        unsigned int  id;        // 4 byte
        char          nama[30];  // 30 byte
        unsigned char umur;      // 1 byte
        float         ipk;       // 4 byte
    };                           // Total: 39 byte persis
    #pragma pack(pop)


//  Fungsi demo
    void hitungNilai(int nilai) {
        DBG_FUNC();
        DBG_VAR(nilai);

        if (nilai < 0 || nilai > 100) {
            DBG_LOG("Nilai di luar range!");
            return;
        }

        string grade;
        if      (nilai >= 85) grade = "A";
        else if (nilai >= 75) grade = "B";
        else if (nilai >= 65) grade = "C";
        else if (nilai >= 55) grade = "D";
        else                  grade = "E";

        DBG_LOG("Grade ditentukan: " + grade);
        cout << "  Nilai " << nilai << " -> Grade " << grade << endl;
    }


int main() {

    // ----- 1. Konfigurasi Aplikasi -----
        cout << "=== 1. Konfigurasi dari config.h ===" << endl;

        cout << "Nama Aplikasi : " << APP_NAME    << endl;
        cout << "Versi         : " << APP_VERSION << endl;
        cout << "Mode Build    : " << NAMA_BUILD  << endl;
        cout << "Platform      : " << NAMA_PLATFORM << endl;
        cout << "Log Level     : " << LOG_LEVEL   << endl;


    // ----- 2. Debug Logging -----
        cout << endl << "=== 2. Debug Logging (dari debug.h) ===" << endl;

        DBG_LOG("Program dimulai");

        int x = 42;
        DBG_VAR(x);

        cout << "Kode normal yang selalu jalan" << endl;

        DBG_LOG("Sebelum hitungNilai()");
        hitungNilai(85);
        hitungNilai(60);
        DBG_LOG("Setelah hitungNilai()");

        cout << endl;
        #ifdef BUILD_DEBUG
            cout << "(DBG_LOG aktif karena BUILD_DEBUG terdefinisi)" << endl;
        #else
            cout << "(DBG_LOG tidak menghasilkan output - BUILD_RELEASE)" << endl;
            cout << " Macro DBG_LOG kosong di release -> zero overhead!" << endl;
        #endif


    // ----- 3. Assert -----
        cout << endl << "=== 3. Assert Custom ===" << endl;

        int ukuran = 10;
        int idx = 3;
        int* ptr = &ukuran;

        MY_ASSERT(ukuran > 0);
        MY_ASSERT(idx >= 0 && idx < ukuran);
        MY_ASSERT(ptr != nullptr);

        #ifdef ENABLE_ASSERT
            cout << "Assert aktif - cek kondisi saat runtime (DEBUG build)" << endl;
        #else
            cout << "Assert tidak aktif (RELEASE build - MY_ASSERT kosong)" << endl;
        #endif


    // ----- 4. Struct Binary -----
        cout << endl << "=== 4. Struct Binary dengan #pragma pack ===" << endl;

        cout << "sizeof(RecordSiswa) = " << sizeof(RecordSiswa) << " byte" << endl;
        cout << "Ukuran logis: 4+30+1+4 = 39 byte" << endl;
        cout << "(Tanpa pack(1), bisa 40+ byte karena padding)" << endl;

        RecordSiswa r;
        r.id  = 1001;
        r.umur = 20;
        r.ipk  = 3.85f;

        cout << endl << "Contoh record:" << endl;
        cout << "  ID   : " << r.id   << endl;
        cout << "  Umur : " << (int)r.umur << endl;
        cout << "  IPK  : " << r.ipk  << endl;


    // ----- 5. Perbandingan #define vs Modern C++ -----
        cout << endl << "=== 5. #define vs Alternatif Modern C++ ===" << endl;

        cout << "Kebutuhan           | Cara Lama          | Cara Modern" << endl;
        cout << "--------------------+--------------------+--------------------" << endl;
        cout << "Konstanta           | #define PI 3.14    | constexpr double PI" << endl;
        cout << "Fungsi kecil        | #define SQ(x) x*x  | inline / template" << endl;
        cout << "Kondisi compile     | #ifdef / #if       | if constexpr (C++17)" << endl;
        cout << "Include sekali      | #ifndef guard      | #pragma once" << endl;
        cout << "Tipe alias          | #define INT32 int  | using INT32 = int;" << endl;


    // ----- 6. Hal yang TIDAK Boleh Dilakukan -----
        cout << endl << "=== 6. Yang TIDAK Boleh Dilakukan ===" << endl;

        cout << "JANGAN:                             SEBAIKNYA:" << endl;
        cout << "-----------------------------------  ---------------------------" << endl;
        cout << "#define fungsi besar               -> inline / template" << endl;
        cout << "#define konstanta bertipe          -> const / constexpr" << endl;
        cout << "Logika kompleks di macro           -> fungsi biasa" << endl;
        cout << "Include header tidak dibutuhkan    -> include minimal" << endl;
        cout << "Definisi fungsi di header          -> inline atau .cpp" << endl;
        cout << "Nama macro terlalu pendek (#define MAX) -> prefix: MYAPP_MAX" << endl;

    return 0;
}

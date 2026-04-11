
#include <iostream>
#include <string>
using namespace std;


//  Demonstrasi berbagai conditional compilation

    // --- Simulasi mode build ---
    // Uncomment salah satu untuk simulasi:
    // #define MODE_DEBUG
    #define MODE_RELEASE

    // --- Simulasi versi ---
    #define APP_VERSI  3

    // --- Simulasi fitur ---
    #define FITUR_LAPORAN
    // #define FITUR_EKSPOR   (sengaja tidak aktif)

    // --- Platform detection (dari compiler) ---
    // _WIN32, __linux__, __APPLE__ sudah otomatis dari compiler


//  Kode kondisional berdasarkan mode build

    #ifdef MODE_DEBUG
        #define LOG(msg)    cout << "[DEBUG] " << msg << endl
        #define ASSERT(c)   do { if(!(c)) { \
                                cout << "[ASSERT FAIL] " << #c << endl; \
                            }} while(0)
        const string BUILD_MODE = "DEBUG";
    #else
        #define LOG(msg)    // kosong di release
        #define ASSERT(c)   // kosong di release
        const string BUILD_MODE = "RELEASE";
    #endif


int main() {

    // ----- 1. #ifdef / #ifndef dasar -----
        cout << "=== 1. #ifdef / #ifndef ===" << endl;

        cout << "Build mode: " << BUILD_MODE << endl;

        #ifdef MODE_DEBUG
            cout << "Kode ini HANYA ada di build DEBUG" << endl;
        #endif

        #ifdef MODE_RELEASE
            cout << "Kode ini HANYA ada di build RELEASE" << endl;
        #endif

        #ifndef MODE_DEBUG
            cout << "#ifndef: ini muncul karena DEBUG tidak aktif" << endl;
        #endif

        LOG("Baris ini hanya ada saat DEBUG aktif");


    // ----- 2. #if / #elif / #else -----
        cout << endl << "=== 2. #if / #elif / #else ===" << endl;

        cout << "APP_VERSI = " << APP_VERSI << endl;

        #if APP_VERSI == 1
            cout << "Menjalankan kode versi 1" << endl;
        #elif APP_VERSI == 2
            cout << "Menjalankan kode versi 2" << endl;
        #elif APP_VERSI >= 3
            cout << "Menjalankan kode versi 3 atau lebih baru" << endl;
        #else
            cout << "Versi tidak dikenal" << endl;
        #endif


    // ----- 3. Operator defined() -----
        cout << endl << "=== 3. Operator defined() ===" << endl;

        #if defined(MODE_RELEASE) && !defined(MODE_DEBUG)
            cout << "Release mode, bukan debug mode." << endl;
        #endif

        #if !defined(MODE_DEBUG)
            cout << "Debug mode tidak aktif." << endl;
        #endif

        // Cek kombinasi fitur
        #if defined(FITUR_LAPORAN) && defined(FITUR_EKSPOR)
            cout << "Kedua fitur aktif: laporan + ekspor" << endl;
        #elif defined(FITUR_LAPORAN)
            cout << "Hanya fitur laporan yang aktif." << endl;
        #elif defined(FITUR_EKSPOR)
            cout << "Hanya fitur ekspor yang aktif." << endl;
        #else
            cout << "Tidak ada fitur tambahan." << endl;
        #endif


    // ----- 4. Deteksi Platform -----
        cout << endl << "=== 4. Deteksi Platform ===" << endl;

        #if defined(_WIN32) || defined(_WIN64)
            cout << "Platform: Windows" << endl;
            cout << "Gunakan: #include <windows.h>" << endl;
        #elif defined(__linux__)
            cout << "Platform: Linux" << endl;
            cout << "Gunakan: #include <unistd.h>" << endl;
        #elif defined(__APPLE__)
            cout << "Platform: macOS / iOS" << endl;
            cout << "Gunakan: #include <unistd.h>" << endl;
        #else
            cout << "Platform: Tidak dikenal" << endl;
        #endif

        // Simulasi platform-specific function
        #if defined(_WIN32)
            // void clearScreen() { system("cls"); }
            cout << "(di Windows: pakai system(\"cls\") untuk clear screen)" << endl;
        #else
            // void clearScreen() { system("clear"); }
            cout << "(di Linux/Mac: pakai system(\"clear\") untuk clear screen)" << endl;
        #endif


    // ----- 5. Cek Versi C++ -----
        cout << endl << "=== 5. Cek Versi C++ ===" << endl;

        cout << "__cplusplus = " << __cplusplus << endl;

        #if __cplusplus >= 202002L
            cout << "C++20 atau lebih baru: support concepts, ranges, coroutines." << endl;
        #elif __cplusplus >= 201703L
            cout << "C++17: support if constexpr, structured bindings, filesystem." << endl;
        #elif __cplusplus >= 201402L
            cout << "C++14: support generic lambdas, variable templates." << endl;
        #elif __cplusplus >= 201103L
            cout << "C++11: support auto, lambda, move semantics, unique_ptr." << endl;
        #else
            cout << "C++98/03: standar lama." << endl;
        #endif


    // ----- 6. Feature Flag / Konfigurasi Build -----
        cout << endl << "=== 6. Feature Flag ===" << endl;

        // Simulasi fitur yang bisa dikontrol saat compile
        cout << "Fitur yang aktif:" << endl;

        #ifdef FITUR_LAPORAN
            cout << "  - Modul Laporan: AKTIF" << endl;
        #else
            cout << "  - Modul Laporan: tidak aktif" << endl;
        #endif

        #ifdef FITUR_EKSPOR
            cout << "  - Modul Ekspor : AKTIF" << endl;
        #else
            cout << "  - Modul Ekspor : tidak aktif" << endl;
        #endif


    // ----- 7. #error dan #warning (demonstrasi via teks) -----
        cout << endl << "=== 7. #error dan #warning ===" << endl;

        cout << "#error  -> hentikan kompilasi dengan pesan:" << endl;
        cout << "    #ifndef MAKS_BUFFER" << endl;
        cout << "        #error \"MAKS_BUFFER harus didefinisikan!\"" << endl;
        cout << "    #endif" << endl;

        cout << endl << "#warning -> peringatkan tapi lanjut kompilasi:" << endl;
        cout << "    #if MAKS_BUFFER > 65536" << endl;
        cout << "        #warning \"MAKS_BUFFER sangat besar!\"" << endl;
        cout << "    #endif" << endl;

        cout << endl << "Kegunaan #error:" << endl;
        cout << "  - Pastikan macro wajib sudah didefinisikan" << endl;
        cout << "  - Paksa versi C++ minimum" << endl;
        cout << "  - Cegah compile di platform yang tidak didukung" << endl;


    // ----- 8. Conditional Compilation vs if-else biasa -----
        cout << endl << "=== 8. Conditional Compilation vs if-else Biasa ===" << endl;

        // if-else biasa: kondisi dievaluasi saat RUNTIME
        bool debug = false;
        if (debug) {
            cout << "  if-else: kode ini ADA di binary, hanya tidak jalan" << endl;
        }

        // Conditional compilation: kode dihapus saat PREPROCESSING
        #ifdef MODE_DEBUG
            cout << "  #ifdef: kode ini ADA di binary (MODE_DEBUG aktif)" << endl;
        #else
            cout << "  #ifdef: kode debug TIDAK ADA di binary (MODE_RELEASE)" << endl;
        #endif

        cout << endl << "Perbedaan penting:" << endl;
        cout << "  if-else biasa    -> overhead runtime (meski kecil)" << endl;
        cout << "  #ifdef / #if     -> zero overhead, kode tidak ada di binary!" << endl;
        cout << "  Untuk debug log  -> SELALU pakai #ifdef, bukan if(debug)" << endl;

    return 0;
}

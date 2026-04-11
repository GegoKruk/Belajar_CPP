#include <iostream>
#include <string>
using namespace std;


//  DEMO #undef
    #define NILAI_AWAL  100
    #define MODUS_AKTIF 1


//  MACRO DENGAN PREDEFINED MACROS
    #define LOKASI_SEKARANG \
        ("Baris " + to_string(__LINE__) + " di " + string(__func__))

    #define LOG_LOKASI(msg) \
        cout << "[" << __func__ << ":" << __LINE__ << "] " << (msg) << endl

    #define TRACE_MASUK() \
        cout << "  --> Masuk fungsi: " << __func__ \
            << " (" << __FILE__ << ":" << __LINE__ << ")" << endl

    #define TRACE_KELUAR() \
        cout << "  <-- Keluar fungsi: " << __func__ << endl


//  Fungsi untuk demo
    void fungsiA() {
        TRACE_MASUK();
        LOG_LOKASI("Menjalankan fungsiA");
        // ... isi fungsi ...
        TRACE_KELUAR();
    }

    void fungsiB(int nilai) {
        TRACE_MASUK();
        LOG_LOKASI("nilai = " + to_string(nilai));
        if (nilai < 0) {
            LOG_LOKASI("ERROR: nilai negatif!");
        }
        TRACE_KELUAR();
    }


int main() {

    // ----- 1. Demo #undef -----
        cout << "=== 1. #undef - Hapus Definisi Macro ===" << endl;

        cout << "NILAI_AWAL  = " << NILAI_AWAL  << " (sebelum undef)" << endl;
        cout << "MODUS_AKTIF = " << MODUS_AKTIF << " (sebelum undef)" << endl;

        #undef NILAI_AWAL
        // Setelah ini, NILAI_AWAL tidak bisa dipakai lagi
        // cout << NILAI_AWAL;  // ERROR: NILAI_AWAL tidak dikenal

        cout << "Setelah #undef NILAI_AWAL:" << endl;
        cout << "  NILAI_AWAL tidak bisa dipakai lagi." << endl;
        cout << "  MODUS_AKTIF = " << MODUS_AKTIF << " (masih ada)" << endl;


    // ----- 2. Redefine dengan #undef -----
        cout << endl << "=== 2. Redefine Macro dengan #undef ===" << endl;

        #define KAPASITAS   50
        cout << "KAPASITAS awal = " << KAPASITAS << endl;

        #undef KAPASITAS
        #define KAPASITAS   500   // define ulang dengan nilai baru

        cout << "KAPASITAS baru = " << KAPASITAS << " (setelah undef + redefine)" << endl;


    // ----- 3. #undef untuk Cegah Bocor -----
        cout << endl << "=== 3. #undef untuk Batasi Scope Macro ===" << endl;

        {   // scope block (hanya konseptual, #define tidak ikut scope C++)
            #define TEMP_NILAI  99
            cout << "TEMP_NILAI = " << TEMP_NILAI << " (dalam blok)" << endl;
        }
        // Tanpa #undef, TEMP_NILAI masih ada di luar blok!
        cout << "TEMP_NILAI = " << TEMP_NILAI << " (masih ada di luar blok!)" << endl;
        cout << "Ingat: #define tidak ikut scope C++, berbeda dari variabel biasa." << endl;

        #undef TEMP_NILAI   // hapus secara eksplisit
        cout << "Setelah #undef TEMP_NILAI: tidak bisa dipakai lagi." << endl;


    // ----- 4. Predefined Macros -----
        cout << endl << "=== 4. Predefined Macros ===" << endl;

        cout << "__FILE__    = " << __FILE__    << endl;
        cout << "__LINE__    = " << __LINE__    << endl;
        cout << "__DATE__    = " << __DATE__    << endl;
        cout << "__TIME__    = " << __TIME__    << endl;
        cout << "__cplusplus = " << __cplusplus << endl;

        // Interpretasi versi C++
        cout << endl << "Versi C++ yang dipakai: ";
        #if __cplusplus >= 202302L
            cout << "C++23" << endl;
        #elif __cplusplus >= 202002L
            cout << "C++20" << endl;
        #elif __cplusplus >= 201703L
            cout << "C++17" << endl;
        #elif __cplusplus >= 201402L
            cout << "C++14" << endl;
        #elif __cplusplus >= 201103L
            cout << "C++11" << endl;
        #else
            cout << "C++98/03 atau lebih lama" << endl;
        #endif


    // ----- 5. __func__ di Setiap Fungsi -----
        cout << endl << "=== 5. __func__ untuk Nama Fungsi ===" << endl;

        cout << "Kita sedang di fungsi: " << __func__ << endl;
        fungsiA();
        fungsiB(10);
        fungsiB(-5);


    // ----- 6. Deteksi Platform -----
        cout << endl << "=== 6. Deteksi Platform ===" << endl;

        cout << "Platform saat ini: ";
        #if defined(_WIN32) || defined(_WIN64)
            cout << "Windows" << endl;
        #elif defined(__linux__)
            cout << "Linux" << endl;
        #elif defined(__APPLE__)
            cout << "macOS / iOS" << endl;
        #elif defined(__unix__)
            cout << "Unix-like" << endl;
        #else
            cout << "Platform tidak dikenal" << endl;
        #endif


    // ----- 7. Ringkasan #undef -----
        cout << endl << "=== 7. Ringkasan Kegunaan #undef ===" << endl;
        cout << "1. Hapus macro agar tidak bocor ke kode di bawah" << endl;
        cout << "2. Redefine: #undef dulu, baru #define ulang" << endl;
        cout << "3. Override macro dari library lain" << endl;
        cout << "4. Batasi macro agar hanya aktif di bagian tertentu" << endl;

    return 0;
}

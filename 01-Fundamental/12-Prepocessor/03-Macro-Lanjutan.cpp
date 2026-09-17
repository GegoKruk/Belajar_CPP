
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


//  STRINGIFICATION (#)
    #define CETAK_VAR(x)        cout << "  " << #x << " = " << (x) << endl
    #define TIPE_DAN_NILAI(x)   cout << "  " << #x << " (tipe=" << typeid(x).name() << ") = " << (x) << endl


//  TOKEN PASTING (##)
    #define BUAT_GETTER(tipe, nama) \
        tipe get_##nama() const { return nama##_; }

    #define ITEM_VAR(n)         int item_##n
    #define CONCAT(a, b)        a##b


//  DO-WHILE(0) untuk macro multi-statement

    // SALAH: tanpa do-while
    #define MACRO_SALAH(x) \
        cout << "  step1: " << (x) << endl; \
        cout << "  step2: " << (x)*2 << endl

    // BENAR: dengan do-while(0)
    #define MACRO_AMAN(x) \
        do { \
            cout << "  step1: " << (x) << endl; \
            cout << "  step2: " << (x)*2 << endl; \
        } while(0)


//  DEBUG ASSERT MACRO (pola umum di proyek besar)
    #define MY_ASSERT(kondisi) \
        do { \
            if (!(kondisi)) { \
                cerr << "ASSERT GAGAL: " << #kondisi << endl; \
                cerr << "  File  : " << __FILE__   << endl; \
                cerr << "  Baris : " << __LINE__   << endl; \
                cerr << "  Fungsi: " << __func__   << endl; \
                abort(); \
            } \
        } while(0)

    // Assert yang tidak mati tapi hanya cetak (untuk demo)
    #define MY_CHECK(kondisi) \
        do { \
            if (!(kondisi)) { \
                cout << "  [CHECK GAGAL] " << #kondisi << endl; \
                cout << "  Baris: " << __LINE__ << endl; \
            } else { \
                cout << "  [CHECK OK] " << #kondisi << endl; \
            } \
        } while(0)


//  VARIADIC MACRO
    #define LOG_MSG(fmt, ...)   printf("[LOG] " fmt "\n", ##__VA_ARGS__)
    #define DBG_PRINT(fmt, ...) printf("[DBG] %s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)


int main() {

    // ----- 1. Stringification -----
        cout << "=== 1. Stringification (#) ===" << endl;

        int umur  = 20;
        double ipk = 3.85;
        bool aktif = true;

        cout << "CETAK_VAR:" << endl;
        CETAK_VAR(umur);
        CETAK_VAR(ipk);
        CETAK_VAR(aktif);
        CETAK_VAR(10 + 5);   // bisa juga ekspresi!
        CETAK_VAR(umur * 2);

        cout << endl << "Ini sangat berguna untuk debugging!" << endl;
        cout << "Kita tidak perlu tulis nama variabel dua kali." << endl;


    // ----- 2. Token Pasting (##) -----
        cout << endl << "=== 2. Token Pasting (##) ===" << endl;

        // Generate variabel dengan ##
        ITEM_VAR(1) = 10;
        ITEM_VAR(2) = 20;
        ITEM_VAR(3) = 30;

        cout << "item_1 = " << item_1 << endl;
        cout << "item_2 = " << item_2 << endl;
        cout << "item_3 = " << item_3 << endl;

        // Gabung token
        int abc = 42;
        cout << CONCAT(ab, c) << endl;   // -> cout << abc << endl; -> 42


    // ----- 3. do-while(0): Macro Multi-Statement -----
        cout << endl << "=== 3. do-while(0) untuk Macro Multi-Statement ===" << endl;

        int nilai = 7;

        cout << "Dengan if + MACRO_SALAH:" << endl;
        cout << "(macro salah bisa menyebabkan step2 selalu jalan)" << endl;
        if (nilai > 5)
            MACRO_AMAN(nilai);   // pakai yang aman saja untuk demo

        cout << endl << "Dengan if + MACRO_AMAN (do-while):" << endl;
        if (nilai > 100)
            MACRO_AMAN(nilai);   // kondisi false, tidak dieksekusi

        cout << "(tidak ada output - kondisi false, macro aman tidak jalan)" << endl;


    // ----- 4. Debug Assert Macro -----
        cout << endl << "=== 4. Debug Assert Macro ===" << endl;

        int ukuran = 10;
        int index  = 3;
        int* ptr   = &ukuran;

        cout << "MY_CHECK (tidak abort, hanya cetak):" << endl;
        MY_CHECK(ukuran > 0);
        MY_CHECK(index >= 0 && index < ukuran);
        MY_CHECK(ptr != nullptr);
        MY_CHECK(index > ukuran);   // ini akan gagal


    // ----- 5. Variadic Macro -----
        cout << endl << "=== 5. Variadic Macro ===" << endl;

        LOG_MSG("Program dimulai");
        LOG_MSG("Nilai x = %d", 42);
        LOG_MSG("Nama: %s, Umur: %d, IPK: %.2f", "Budi", 20, 3.85);

        cout << endl;
        DBG_PRINT("Debug info: nilai=%d", nilai);
        DBG_PRINT("Dua nilai: a=%d, b=%d", 10, 20);


    // ----- 6. Kombinasi: Debug Macro Lengkap -----
        cout << endl << "=== 6. Kombinasi: Debug Macro Lengkap ===" << endl;

        // Macro yang hanya aktif saat DEBUG didefinisikan
        // (simulasi dengan mencetak)
        cout << "Pola debug macro yang umum dipakai:" << endl;
        cout << R"(
            #ifdef DEBUG
                #define DBG(x)   cout << "[DBG] " << #x << "=" << (x) << endl
                #define LOG(msg) cout << "[LOG] " << msg << endl
            #else
                #define DBG(x)   // kosong di release
                #define LOG(msg) // kosong di release
            #endif

            // Compile debug:   g++ -DDEBUG main.cpp
            // Compile release: g++ main.cpp
            // Kode DBG dan LOG akan ada/hilang otomatis!
        )";

    return 0;
}

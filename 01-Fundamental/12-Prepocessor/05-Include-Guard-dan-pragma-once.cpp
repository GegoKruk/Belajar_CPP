
#include <iostream>
#include <string>
using namespace std;


//  Simulasi include guard di dalam satu file
//  (normalnya ini ada di file .h terpisah)

    // --- Simulasi mathHelper.h dengan include guard ---
    #ifndef SIM_MATH_HELPER_H
    #define SIM_MATH_HELPER_H

    constexpr double PI_NILAI = 3.14159265358979;

    inline double luasLingkaran(double r) {
        return PI_NILAI * r * r;
    }

    inline double kelilingLingkaran(double r) {
        return 2 * PI_NILAI * r;
    }

    #endif // SIM_MATH_HELPER_H


    // --- Simulasi include pertama (seperti file A.h yang include mathHelper.h) ---
    // Karena SIM_MATH_HELPER_H sudah didefinisikan di atas,
    // blok ini tidak akan diproses lagi:
    #ifndef SIM_MATH_HELPER_H
    #define SIM_MATH_HELPER_H
    // isi ini tidak akan diproses karena guard sudah aktif
    inline double luasLingkaran(double r) { return 999; }  // tidak akan ada
    #endif


//  Simulasi tanpa guard (untuk demonstrasi error)
    #ifndef SIM_NO_GUARD_FIRST
    #define SIM_NO_GUARD_FIRST
        const int NILAI_TANPA_GUARD = 42;
    #endif

    // Include kedua "tanpa guard" - karena kita pakai guard di sini,
    // ini aman. Tapi bayangkan kalau tidak ada guard:
    #ifndef SIM_NO_GUARD_FIRST
        // Ini tidak akan diproses (guard aktif)
        const int NILAI_TANPA_GUARD = 99;  // duplikat - akan jadi error tanpa guard!
    #endif


int main() {

    // ----- 1. Demo Include Guard Bekerja -----
        cout << "=== 1. Include Guard Bekerja ===" << endl;

        cout << "luasLingkaran(5) = " << luasLingkaran(5) << endl;
        cout << "  Hasil = PI * 5 * 5 = " << PI_NILAI * 5 * 5 << endl;
        cout << "  (Fungsi hanya didefinisikan SEKALI meski di-'include' dua kali)" << endl;

        cout << "NILAI_TANPA_GUARD = " << NILAI_TANPA_GUARD << endl;
        cout << "  (Nilainya 42, bukan 99, karena include kedua diblok guard)" << endl;


    // ----- 2. Contoh Pola Include Guard -----
        cout << endl << "=== 2. Pola Include Guard ===" << endl;

        cout << "Pola include guard yang benar:" << endl;
        cout << R"(
            // namafile.h
            #ifndef NAMAFILE_H        // jika NAMAFILE_H belum terdefinisi
            #define NAMAFILE_H        // definisikan NAMAFILE_H

            // isi header di sini
            struct Titik { int x; int y; };
            void prosesData();

            #endif // NAMAFILE_H      // tutup blok (komentar opsional)
        )";


    // ----- 3. Contoh #pragma once -----
        cout << "=== 3. Pola #pragma once ===" << endl;

        cout << "Pola #pragma once:" << endl;
        cout << R"(
            // namafile.h
            #pragma once              // satu baris ini sudah cukup!

            // isi header di sini
            struct Titik { int x; int y; };
            void prosesData();
        )";


    // ----- 4. Perbandingan -----
        cout << "=== 4. Perbandingan Include Guard vs #pragma once ===" << endl;
        cout << "Aspek              | Include Guard      | #pragma once" << endl;
        cout << "-------------------+--------------------+--------------------" << endl;
        cout << "Jumlah baris       | 3 baris            | 1 baris" << endl;
        cout << "Standar ISO        | Ya (C89+)          | Tidak (de-facto)" << endl;
        cout << "Dukungan compiler  | Semua              | Semua modern" << endl;
        cout << "Risiko typo        | Ada (nama guard)   | Tidak ada" << endl;
        cout << "Kecepatan compile  | Normal             | Sedikit lebih cepat" << endl;
        cout << "Edge case symlink  | Aman               | Bisa bermasalah" << endl;


    // ----- 5. Konvensi Nama Include Guard -----
        cout << endl << "=== 5. Konvensi Nama Include Guard ===" << endl;
        cout << "Nama file           | Nama guard yang disarankan" << endl;
        cout << "--------------------+------------------------------" << endl;
        cout << "point.h             | POINT_H" << endl;
        cout << "math_helper.h       | MATH_HELPER_H" << endl;
        cout << "utils/config.h      | UTILS_CONFIG_H" << endl;
        cout << "myapp/types.h       | MYAPP_TYPES_H" << endl;
        cout << "MyClass.h           | MYCLASS_H" << endl;
        cout << endl;
        cout << "Aturan: UPPERCASE semua, ganti '/' dan '.' dengan '_'." << endl;
        cout << "Tambah prefix unik untuk proyek besar agar tidak clash." << endl;


    // ----- 6. Checklist Header yang Baik -----
        cout << endl << "=== 6. Checklist Header File yang Baik ===" << endl;
        cout << "// namafile.h" << endl;
        cout << "#pragma once                    <- (1) baris pertama" << endl;
        cout << "" << endl;
        cout << "#include <dependensi>           <- (2) include minimal" << endl;
        cout << "" << endl;
        cout << "constexpr int MAX = 100;        <- (3) constexpr bukan #define" << endl;
        cout << "using ItemId = unsigned int;    <- (4) using bukan typedef" << endl;
        cout << "" << endl;
        cout << "class MyClass;                  <- (5) forward decl kalau cukup" << endl;
        cout << "void prosesItem(int id);        <- (6) deklarasi, bukan definisi" << endl;
        cout << "" << endl;
        cout << "inline void helper() { ... }    <- (7) inline boleh di header" << endl;
        cout << "template<T> void gen(T x){}     <- (8) template HARUS di header" << endl;

    return 0;
}

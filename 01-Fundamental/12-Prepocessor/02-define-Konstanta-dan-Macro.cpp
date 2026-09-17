
#include <iostream>
#include <string>
using namespace std;

// ----- Object-like macro -----
    #define PI          3.14159265358979
    #define MAX_SIZE    100
    #define APP_NAME    "Demo Preprocessor"
    #define VERSI       "2.0"
    #define NEWLINE     '\n'

// ----- Function-like macro (dengan kurung yang benar) -----
    #define KUADRAT(x)       ((x) * (x))
    #define KUBUS(x)         ((x) * (x) * (x))
    #define MAKS(a, b)       ((a) > (b) ? (a) : (b))
    #define MINS(a, b)       ((a) < (b) ? (a) : (b))
    #define ABS_MACRO(x)     ((x) >= 0 ? (x) : -(x))
    #define SWAP_INT(a, b)   do { int t=(a); (a)=(b); (b)=t; } while(0)

// ----- Macro multiline -----
    #define LOG_ERROR(msg) \
        cerr << "[ERROR] " << __FILE__ \
            << ":" << __LINE__ \
            << " - " << msg << endl

// ----- Macro SALAH (tanpa kurung - untuk demonstrasi) -----
    #define KUADRAT_SALAH(x)   x * x

// ----- Inline function sebagai alternatif aman -----
    inline int maksInline(int a, int b) { return a > b ? a : b; }
    template<typename T>
    T kuadratTemplate(T x) { return x * x; }


int main() {

    // ----- 1. Object-like Macro -----
        cout << "=== 1. Object-like Macro ===" << endl;

        cout << "PI       = " << PI       << endl;
        cout << "MAX_SIZE = " << MAX_SIZE << endl;
        cout << "APP_NAME = " << APP_NAME << endl;
        cout << "VERSI    = " << VERSI    << endl;

        double r = 7.0;
        double luas = PI * r * r;
        cout << "Luas lingkaran r=" << r << " : " << luas << endl;


    // ----- 2. Function-like Macro (dengan kurung benar) -----
        cout << endl << "=== 2. Function-like Macro ===" << endl;

        cout << "KUADRAT(5)     = " << KUADRAT(5)     << endl;
        cout << "KUBUS(3)       = " << KUBUS(3)        << endl;
        cout << "MAKS(8, 13)    = " << MAKS(8, 13)    << endl;
        cout << "MINS(8, 13)    = " << MINS(8, 13)    << endl;
        cout << "ABS_MACRO(-7)  = " << ABS_MACRO(-7)  << endl;
        cout << "ABS_MACRO(4)   = " << ABS_MACRO(4)   << endl;

        // SWAP_INT
        int x = 10, y = 20;
        cout << "Sebelum swap: x=" << x << ", y=" << y << endl;
        SWAP_INT(x, y);
        cout << "Sesudah swap: x=" << x << ", y=" << y << endl;


    // ----- 3. Bahaya #1: Operator Precedence -----
        cout << endl << "=== 3. Bahaya: Operator Precedence ===" << endl;

        int a = 2, b = 3;

        int hasilSalah = KUADRAT_SALAH(a + b);
        // -> a + b * a + b = 2 + 3*2 + 3 = 2+6+3 = 11 (SALAH!)
        cout << "KUADRAT_SALAH(2 + 3) = " << hasilSalah << " (seharusnya 25!)" << endl;
        cout << "  Ekspansi: a + b * a + b = " << a << " + " << b << "*" << a << " + " << b << endl;

        int hasilBenar = KUADRAT(a + b);
        // -> ((a + b) * (a + b)) = ((2+3) * (2+3)) = 25 (BENAR)
        cout << "KUADRAT(2 + 3)       = " << hasilBenar << " (benar!)" << endl;


    // ----- 4. Bahaya #2: Side Effect -----
        cout << endl << "=== 4. Bahaya: Side Effect (Argumen Dievaluasi 2x) ===" << endl;

        int nilaiA = 5;
        int hasilMacro = MAKS(nilaiA++, 3);
        // MAKS(nilaiA++, 3) -> ((nilaiA++) > (3) ? (nilaiA++) : (3))
        // nilaiA++ dievaluasi lebih dari sekali -> hasil tidak terduga!
        cout << "MAKS(nilaiA++, 3) dimana nilaiA=5:" << endl;
        cout << "  hasil = " << hasilMacro << ", nilaiA sekarang = " << nilaiA << endl;
        cout << "  (nilaiA mungkin 6 atau 7, tidak terduga!)" << endl;

        int nilaiB = 5;
        int hasilInline = maksInline(nilaiB++, 3);
        cout << "maksInline(nilaiB++, 3) dimana nilaiB=5:" << endl;
        cout << "  hasil = " << hasilInline << ", nilaiB sekarang = " << nilaiB << endl;
        cout << "  (nilaiB hanya naik sekali, aman!)" << endl;


    // ----- 5. Macro Multiline -----
        cout << endl << "=== 5. Macro Multiline ===" << endl;

        // LOG_ERROR akan dicetak ke cerr, pakai cout untuk demo terlihat
        cout << "Macro LOG_ERROR menunjuk ke baris dan file:" << endl;
        LOG_ERROR("File konfigurasi tidak ditemukan");


    // ----- 6. const vs constexpr vs #define -----
        cout << endl << "=== 6. #define vs const vs constexpr ===" << endl;

        // Tiga cara mendefinisikan konstanta
        #define BATAS_MACRO     50      // tidak ada tipe, tidak ada scope
        const int BATAS_CONST = 50;     // ada tipe int, ada scope
        constexpr int BATAS_CX = 50;    // compile-time, ada tipe, ada scope

        cout << "BATAS_MACRO     = " << BATAS_MACRO    << " (tidak ada tipe/scope)" << endl;
        cout << "BATAS_CONST     = " << BATAS_CONST    << " (tipe int, ada scope)" << endl;
        cout << "BATAS_CX        = " << BATAS_CX       << " (compile-time, ada scope)" << endl;
        cout << endl;
        cout << "Rekomendasi untuk konstanta: pakai constexpr atau const." << endl;
        cout << "#define tetap dipakai untuk: header guard, debug flag, platform flag." << endl;

    return 0;
}

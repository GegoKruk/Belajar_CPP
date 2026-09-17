#include <iostream>
#include <string>
#include <climits>   // INT_MAX, INT_MIN, dll
#include <cfloat>    // FLT_MAX, DBL_MAX, dll
using namespace std;

void tipeData() {
    cout << "\n========== G. Tipe Data ==========" << endl;

    // ----- 1. Tipe Data Primitif -----
    cout << "\n1. Tipe Data Primitif" << endl;

    int    umur       = 18;
    float  beratBadan = 65.5f;    // suffix f penting untuk float literal
    double ipk        = 3.875432;
    char   golDarah   = 'B';
    bool   lulusSMA   = true;
    string namaDepan  = "Gega";

    cout << "   int    (umur)      = " << umur       << endl;
    cout << "   float  (berat)     = " << beratBadan << endl;
    cout << "   double (ipk)       = " << ipk        << endl;
    cout << "   char   (golDarah)  = " << golDarah   << endl;
    cout << "   bool   (lulusSMA)  = " << lulusSMA   << " (1=true, 0=false)" << endl;
    cout << "   string (nama)      = " << namaDepan  << endl;

    // ----- 2. Ukuran Memori (sizeof) -----
    cout << "\n2. Ukuran Memori dengan sizeof()" << endl;

    cout << "   sizeof(int)         = " << sizeof(int)         << " byte" << endl;
    cout << "   sizeof(float)       = " << sizeof(float)       << " byte" << endl;
    cout << "   sizeof(double)      = " << sizeof(double)      << " byte" << endl;
    cout << "   sizeof(char)        = " << sizeof(char)        << " byte" << endl;
    cout << "   sizeof(bool)        = " << sizeof(bool)        << " byte" << endl;
    cout << "   sizeof(long long)   = " << sizeof(long long)   << " byte" << endl;
    cout << "   sizeof(long double) = " << sizeof(long double) << " byte" << endl;

    // ----- 3. Modifier Tipe Data -----
    cout << "\n3. Modifier Tipe Data" << endl;

    short int   nilaiKecil  = 32767;
    long long   populasiDunia = 8100000000LL; // LL = long long literal
    unsigned int stok       = 4294967295U;    // U = unsigned literal

    cout << "   short int           = " << nilaiKecil     << endl;
    cout << "   long long           = " << populasiDunia  << endl;
    cout << "   unsigned int (max)  = " << stok           << endl;

    // ----- 4. Batas Nilai Tiap Tipe (dari <climits> & <cfloat>) -----
    cout << "\n4. Batas Nilai Tipe Data" << endl;

    cout << "   INT_MIN  = " << INT_MIN  << endl;
    cout << "   INT_MAX  = " << INT_MAX  << endl;
    cout << "   LLONG_MAX= " << LLONG_MAX<< endl;
    cout << "   FLT_MAX  = " << FLT_MAX  << endl;
    cout << "   DBL_MAX  = " << DBL_MAX  << endl;

    // ----- 5. float vs double - Perbedaan Presisi -----
    cout << "\n5. float vs double - Perbedaan Presisi" << endl;

    float  f = 1.123456789012345f;
    double d = 1.123456789012345;

    cout.precision(15); // tampilkan 15 digit
    cout << "   float  : " << f << "  (hanya ~7 digit akurat)" << endl;
    cout << "   double : " << d << "  (~15 digit akurat)" << endl;
    cout.precision(6);  // reset ke default

    // ----- 6. char & ASCII -----
    cout << "\n6. Char & Nilai ASCII-nya" << endl;

    char huruf = 'A';
    cout << "   char 'A' sebagai char  = " << huruf << endl;
    cout << "   char 'A' sebagai int   = " << (int)huruf << " (nilai ASCII)" << endl;
    cout << "   char dari ASCII 97     = " << (char)97   << " (huruf a)" << endl;

    // ----- 7. bool -----
    cout << "\n7. bool - Tipe Logika" << endl;

    bool kondisi1 = true;
    bool kondisi2 = false;
    bool kondisi3 = (10 > 5);  // ekspresi perbandingan -> bool

    cout << "   true   = " << kondisi1 << endl;
    cout << "   false  = " << kondisi2 << endl;
    cout << "   10>5   = " << kondisi3 << endl;
    cout << "   (pakai boolalpha): ";
    cout << boolalpha << kondisi1 << " / " << kondisi2 << noboolalpha << endl;

    // ----- Tips -----
    cout << "\nTips Memilih Tipe Data:" << endl;
    cout << "   -> Angka bulat biasa     : int" << endl;
    cout << "   -> Angka desimal         : double (bukan float!)" << endl;
    cout << "   -> 1 karakter            : char" << endl;
    cout << "   -> Teks                  : string" << endl;
    cout << "   -> Angka sangat besar    : long long" << endl;
    cout << "   -> Hanya bilangan positif: unsigned int" << endl;
}

int main(){

    tipeData();

    return 0;
}
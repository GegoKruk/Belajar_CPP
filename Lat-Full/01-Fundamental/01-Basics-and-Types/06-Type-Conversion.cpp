#include <iostream>
#include <string>
using namespace std;

void typeConversion() {
    cout << "========== D. Type Conversion & Casting ==========" << endl;

    // ----- 1. Implicit Conversion - Safe (Widening) -----
        cout << "\n1. Implicit Conversion - Safe Direction (Widening)" << endl;
        cout << "   Tidak ada data yang hilang." << endl;

        int    nilaiInt    = 42;
        double nilaiDouble = nilaiInt;   // int -> double, otomatis, aman
        long   nilaiLong   = nilaiInt;   // int -> long, aman

        cout << "   int    = " << nilaiInt    << endl;
        cout << "   -> double (otomatis) = " << nilaiDouble << endl;
        cout << "   -> long  (otomatis)  = " << nilaiLong   << endl;

        char   huruf     = 'Z';
        int    kodeASCII = huruf;        // char -> int (nilai ASCII), aman
        cout << "   char 'Z' -> int ASCII = " << kodeASCII << endl;

    // ----- 2. Implicit Conversion - Dangerous (Narrowing) -----
        cout << "\n2. Implicit Conversion - Dangerous Direction (Narrowing)" << endl;
        cout << "   Ada data yang bisa hilang!" << endl;

        double pi           = 3.14159;
        int    piTerpotong  = pi;        // double -> int: hilang .14159
        cout << "   double " << pi << " -> int = " << piTerpotong << " (koma hilang!)" << endl;

        double tinggi         = 175.9;
        int    tinggiBulat    = tinggi;  // kehilangan .9
        cout << "   double " << tinggi << " -> int = " << tinggiBulat << " (kehilangan .9)" << endl;

        int  besar   = 300;
        char kecil   = besar;            // int 300 -> char: overflow! char max 127 (signed)
        cout << "   int 300 -> char = " << (int)kecil << " (overflow, nilai tidak terduga!)" << endl;

    // ----- 3. Explicit Cast - static_cast (Cara Modern) -----
        cout << "\n3. Explicit Cast - static_cast<T>() - Cara Modern & Dianjurkan" << endl;

        double nilai  = 9.87654;
        int    nilaiI = static_cast<int>(nilai); // potong desimal, kita yang minta
        cout << "   static_cast<int>(" << nilai << ") = " << nilaiI << endl;

        int  angka    = 65;
        char karakter = static_cast<char>(angka); // 65 = 'A' dalam ASCII
        cout << "   static_cast<char>(65)  = '" << karakter << "' (ASCII 65 = A)" << endl;

        char c     = 'a';
        int  ascii = static_cast<int>(c);
        cout << "   static_cast<int>('a')  = " << ascii << " (nilai ASCII huruf a)" << endl;

    // ----- 4. C-Style Cast - Cara Lama (Hindari!) -----
        cout << "\n4. C-Style Cast - Cara Lama (Tidak Dianjurkan)" << endl;

        double d = 7.77;
        int    i = (int)d;   // C-style cast
        cout << "   (int)7.77 = " << i << endl;
        cout << "   C-style cast tidak diperiksa compiler, lebih rawan bug." << endl;
        cout << "   Ganti dengan: static_cast<int>(7.77)" << endl;

    // ----- 5. INTEGER DIVISION TRAP ⚠️ -----
        cout << "\n5. INTEGER DIVISION TRAP - Jebakan Paling Sering!" << endl;

        int a = 7;
        int b = 2;

    // SALAH: 7/2 dihitung sebagai integer (=3) dulu, BARU dikonversi ke double
        double hasilSalah = a / b;
        cout << "   " << a << " / " << b << " (tanpa cast)          = " << hasilSalah
            << "  <- SALAH, harusnya 3.5!" << endl;

    // BENAR: Cast salah satu sebelum dibagi
        double hasilBenar1 = static_cast<double>(a) / b;
        double hasilBenar2 = a / static_cast<double>(b);
        double hasilBenar3 = a * 1.0 / b;   // alternatif: multiply 1.0

        cout << "   static_cast<double>(" << a << ") / " << b << "  = " << hasilBenar1 << endl;
        cout << "   " << a << " / static_cast<double>(" << b << ")  = " << hasilBenar2 << endl;
        cout << "   " << a << " * 1.0 / " << b << "                = " << hasilBenar3 << endl;

    // Contoh nyata: rata-rata
        cout << "\n   Contoh nyata - Hitung Rata-Rata:" << endl;
        int n1 = 80, n2 = 85, n3 = 78;
        int total = n1 + n2 + n3;

        double rataRataSalah = total / 3;   // integer division -> salah!
        double rataRataBenar = static_cast<double>(total) / 3;

        cout << "   Nilai: " << n1 << ", " << n2 << ", " << n3 << endl;
        cout << "   Rata-rata salah  = " << rataRataSalah << endl;
        cout << "   Rata-rata benar  = " << rataRataBenar << endl;

    // ----- 6. Type Promotion dalam Ekspresi Campuran -----
        cout << "\n6. Type Promotion - Operasi Tipe Campuran" << endl;
        cout << "   Aturan: tipe 'lebih kecil' otomatis dipromote ke tipe 'lebih besar'." << endl;

        int    angkaInt    = 10;
        double angkaDouble = 3.7;
        double hasilCampur = angkaInt + angkaDouble; // int dipromote ke double
        cout << "   int " << angkaInt << " + double " << angkaDouble
            << " = " << hasilCampur << " (double)" << endl;

        int   x = 5;
        float y = 2.0f;
        float z = x + y;  // int -> float
        cout << "   int " << x << " + float " << y << " = " << z << " (float)" << endl;

    // ----- 7. Narrowing Prevention dengan {} -----
        cout << "\n7. Narrowing Prevention dengan Uniform Init {}" << endl;
        cout << "   C++11 mencegah narrowing saat pakai {}." << endl;

        int    nilaiA = 3.9;     // ✅ Compiler tidak error (tapi kehilangan .9)
        // int nilaiB{3.9};      // ❌ COMPILE ERROR - narrowing dicegah!

        cout << "   int nilaiA = 3.9;   -> " << nilaiA << " (data hilang, tapi tidak error)" << endl;
        cout << "   int nilaiB{3.9};    -> COMPILE ERROR (narrowing dicegah oleh {})" << endl;
        cout << "   Pakai {} untuk menghindari konversi berbahaya tanpa sadar!" << endl;

    // ----- 8. String <-> Number Conversion -----
        cout << "\n8. String <-> Number Conversion" << endl;

        // Number -> String
        int    num1 = 42;
        double num2 = 3.14;
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        cout << "   to_string(42)   = \"" << str1 << "\"" << endl;
        cout << "   to_string(3.14) = \"" << str2 << "\"" << endl;

        // String -> Number
        string s1 = "100";
        string s2 = "9.99";
        string s3 = "55";

        int    i1 = stoi(s1);   // string to int
        double d1 = stod(s2);   // string to double
        float  f1 = stof(s3);   // string to float

        cout << "   stoi(\"100\")  = " << i1 << " (int)"    << endl;
        cout << "   stod(\"9.99\") = " << d1 << " (double)" << endl;
        cout << "   stof(\"55\")   = " << f1 << " (float)"  << endl;

        // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Pakai static_cast<T>(), hindari C-style (int)" << endl;
        cout << "   -> Hati-hati integer division! Cast dulu sebelum bagi" << endl;
        cout << "   -> Pakai {} untuk cegah narrowing conversion yang tidak sengaja" << endl;
        cout << "   -> to_string() | stoi() stod() stof() untuk String<->Number" << endl;
}

int main(){

    typeConversion();

    return 0;
}
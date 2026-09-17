#include <iostream>
#include <cmath>     // fabs() untuk perbandingan float
#include <string>
using namespace std;

void operatorPerbandingan() {
    cout << "========== L. Operator Perbandingan ==========" << endl;

    int a = 10, b = 15;
    cout << "\nVariabel: a = " << a << ", b = " << b << endl;

    // ----- 1. Semua Operator Perbandingan -----
        cout << "\n1. Demo Semua Operator (dengan boolalpha)" << endl;
        cout << boolalpha;   // tampilkan true/false, bukan 1/0

        cout << "   a == b  ->  " << (a == b) << "  (" << a << " sama dengan " << b << "?)" << endl;
        cout << "   a != b  ->  " << (a != b) << "   (" << a << " tidak sama dengan " << b << "?)" << endl;
        cout << "   a <  b  ->  " << (a <  b) << "   (" << a << " kurang dari " << b << "?)" << endl;
        cout << "   a <= b  ->  " << (a <= b) << "   (" << a << " kurang atau sama " << b << "?)" << endl;
        cout << "   a >  b  ->  " << (a >  b) << "  (" << a << " lebih dari " << b << "?)" << endl;
        cout << "   a >= b  ->  " << (a >= b) << "  (" << a << " lebih atau sama " << b << "?)" << endl;
        cout << noboolalpha;

    // ----- 2. Hasil Perbandingan adalah bool -----
        cout << "\n2. Hasil Perbandingan Tersimpan ke Variabel bool" << endl;

        bool cek1 = (a < b);
        bool cek2 = (a == 10);
        bool cek3 = (b >= 20);

        cout << "   bool cek1 = (a < b)   -> " << cek1 << endl;
        cout << "   bool cek2 = (a == 10) -> " << cek2 << endl;
        cout << "   bool cek3 = (b >= 20) -> " << cek3 << endl;

    // ----- 3. Jebakan = vs == -----
        cout << "\n3. Jebakan = vs ==" << endl;

        int nilai = 3;
        // if (nilai = 5)  // ❌ ini ASSIGNMENT! nilai jadi 5, kondisi always true
        // if (nilai == 5) // ✅ ini perbandingan

        cout << "   if (nilai = 5)   -> SALAH! Ini assignment, bukan perbandingan!" << endl;
        cout << "   if (nilai == 5)  -> BENAR! Ini perbandingan" << endl;
        cout << "\n   Tips Yoda Condition:" << endl;
        cout << "   if (5 == nilai)  -> Kalau salah ketik jadi (5 = nilai) -> compile error ✅" << endl;

    // ----- 4. Jebakan Float Comparison -----
        cout << "\n4. Jebakan Float Comparison" << endl;

        double f1 = 0.1 + 0.2;
        double f2 = 0.3;

        cout << boolalpha;
        cout << "   0.1 + 0.2 == 0.3  ->  " << (f1 == f2) << "  <- BISA SALAH!" << endl;
        cout << "   Nilai asli 0.1+0.2 = " << f1 << " (bukan persis 0.3!)" << endl;

        // Solusi: gunakan epsilon
            double epsilon = 1e-9;
            bool hampirSama = fabs(f1 - f2) < epsilon;
            cout << "   fabs(f1-f2) < 1e-9 = " << hampirSama << " <- BENAR pakai epsilon!" << endl;
            cout << noboolalpha;

    // ----- 5. Membandingkan Char & String -----
        cout << "\n5. Membandingkan Char & String" << endl;

        char ch = 'B';
        cout << "   'B' > 'A'  ->  " << (ch > 'A') << "  (berdasarkan nilai ASCII)" << endl;
        cout << "   'a' > 'A'  ->  " << ('a' > 'A') << "  (huruf kecil > huruf besar)" << endl;
        cout << "   ASCII 'A'=" << (int)'A' << ", 'a'=" << (int)'a' << endl;

        string s1 = "apel", s2 = "mangga";
        cout << "\n   string: s1=\"" << s1 << "\", s2=\"" << s2 << "\"" << endl;
        cout << boolalpha;
        cout << "   s1 == s2  ->  " << (s1 == s2) << endl;
        cout << "   s1 <  s2  ->  " << (s1 < s2)  << "  (urutan alfabet)" << endl;
        cout << noboolalpha;

    // ----- 6. Contoh Praktis -----
        cout << "\n6. Contoh Praktis" << endl;

        // a. Cek rentang nilai
            int nilaiUjian = 82;
            cout << "\n   a. Nilai ujian = " << nilaiUjian << endl;
            cout << "      >= 85 -> A?  " << (nilaiUjian >= 85 ? "Ya" : "Tidak") << endl;
            cout << "      >= 70 -> Lulus?  " << (nilaiUjian >= 70 ? "Lulus" : "Tidak Lulus") << endl;

        // b. Cek kesamaan password (tanpa operator == pada praktiknya pakai hash)
            string inputPassword = "rahasia123";
            string benarPassword  = "rahasia123";
            cout << "\n   b. Cek password:" << endl;
            cout << "      Password benar? " << (inputPassword == benarPassword ? "YA" : "TIDAK") << endl;
}

int main(){

    operatorPerbandingan();

    return 0;
}
#include <iostream>
using namespace std;

int variabelGlobal = 999;   // ada di area Global/Static

int main() {

    // ----- Variabel di Stack -----
        cout << "=== Variabel di Stack ===" << endl;

        int x = 10;
        int y = 20;
        int z = 30;

        cout << "int x = 10:" << endl;
        cout << "  Nilai    : " << x  << endl;
        cout << "  Alamat   : " << &x << endl;

        cout << "int y = 20:" << endl;
        cout << "  Nilai    : " << y  << endl;
        cout << "  Alamat   : " << &y << endl;

        cout << "int z = 30:" << endl;
        cout << "  Nilai    : " << z  << endl;
        cout << "  Alamat   : " << &z << endl;

        cout << endl;
        cout << "Perhatikan: alamat berdekatan karena di stack" << endl;


    // ----- Ukuran Tipe Data -----
        cout << endl << "=== Ukuran Tipe Data (sizeof) ===" << endl;

        cout << "sizeof(char)     = " << sizeof(char)     << " byte" << endl;
        cout << "sizeof(bool)     = " << sizeof(bool)     << " byte" << endl;
        cout << "sizeof(int)      = " << sizeof(int)      << " byte" << endl;
        cout << "sizeof(float)    = " << sizeof(float)    << " byte" << endl;
        cout << "sizeof(double)   = " << sizeof(double)   << " byte" << endl;
        cout << "sizeof(long long)= " << sizeof(long long)<< " byte" << endl;
        cout << "sizeof(int*)     = " << sizeof(int*)     << " byte  (ukuran pointer)" << endl;


    // ----- Demonstrasi Selisih Alamat -----
        cout << endl << "=== Selisih Alamat Antar Variabel ===" << endl;

        int a = 1, b = 2, c = 3;

        cout << "Alamat a: " << &a << endl;
        cout << "Alamat b: " << &b << endl;
        cout << "Alamat c: " << &c << endl;

    // Hitung selisih (cast ke long long untuk tampilkan selisih)
        long long selisihAB = (long long)&a - (long long)&b;
        cout << "Selisih &a - &b = " << selisihAB << " byte" << endl;
        cout << "(Sesuai sizeof(int) = " << sizeof(int) << " byte)" << endl;


    // ----- Variabel Global vs Local -----
        cout << endl << "=== Global vs Local ===" << endl;

        int localVar = 777;

        cout << "variabelGlobal (global area): " << variabelGlobal << " | alamat: " << &variabelGlobal << endl;
        cout << "localVar       (stack)      : " << localVar << "  | alamat: " << &localVar << endl;
        cout << endl;
        cout << "Perhatikan: alamatnya jauh berbeda!" << endl;
        cout << "Global ada di segmen berbeda dari stack." << endl;


    // ----- Operator & pada berbagai tipe -----
        cout << endl << "=== Operator Address-of (&) ===" << endl;

        double d   = 3.14;
        char   ch  = 'A';
        bool   bl  = true;

        cout << "double d = 3.14 -> &d  = " << &d  << endl;
        cout << "char ch  = 'A'  -> &ch = " << (void*)&ch << endl;  // cast agar tidak print string
        cout << "bool bl  = true -> &bl = " << (void*)&bl << endl;

    return 0;
}

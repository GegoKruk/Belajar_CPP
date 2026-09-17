#include <iostream>
#include <bitset>    // untuk tampilkan biner dengan mudah
#include <string>
using namespace std;

// ============================================================
// HELPER - Tampilkan angka dalam format biner 8-bit
// ============================================================
string toBinary8(int n) {
    return bitset<8>(n).to_string();
}
string toBinary4(int n) {
    return bitset<4>(n).to_string();
}

void operatorBitwise() {
    cout << "========== O. Operator Bitwise ==========" << endl;

    // ----- Pengenalan Biner -----
        cout << "\n--- Representasi Biner ---" << endl;
        cout << "   Desimal 5  = biner " << toBinary8(5)  << "  (0000 0101)" << endl;
        cout << "   Desimal 3  = biner " << toBinary8(3)  << "  (0000 0011)" << endl;
        cout << "   Desimal 12 = biner " << toBinary8(12) << "  (0000 1100)" << endl;
        cout << "   Desimal 15 = biner " << toBinary8(15) << "  (0000 1111)" << endl;

        int a = 5;  // 0000 0101
        int b = 3;  // 0000 0011

        cout << "\n   Pakai a=" << a << " (0101) dan b=" << b << " (0011) untuk demo:" << endl;

    // ----- 1. AND (&) -----
        cout << "\n1. AND (&) - Bit 1 hanya jika KEDUANYA 1" << endl;
        cout << "   Tabel AND: 0&0=0, 0&1=0, 1&0=0, 1&1=1" << endl;
        cout << "   Analogi: lampu nyala HANYA jika saklar A DAN B ON" << endl;
        cout << endl;
        cout << "     a  = " << toBinary4(a) << "  (" << a << ")" << endl;
        cout << "     b  = " << toBinary4(b) << "  (" << b << ")" << endl;
        cout << "     ---------" << endl;
        cout << "   a&b  = " << toBinary4(a & b) << "  (" << (a & b) << ")" << endl;
        cout << "\n   Detail bit per bit:" << endl;
        cout << "     0 1 0 1  (a=5)" << endl;
        cout << "   & 0 0 1 1  (b=3)" << endl;
        cout << "   ---------" << endl;
        cout << "     0 0 0 1  = " << (a & b) << endl;

    // ----- 2. OR (|) -----
        cout << "\n2. OR (|) - Bit 1 jika SALAH SATU atau KEDUANYA 1" << endl;
        cout << "   Tabel OR: 0|0=0, 0|1=1, 1|0=1, 1|1=1" << endl;
        cout << "   Analogi: lampu nyala jika saklar A ATAU B (atau keduanya) ON" << endl;
        cout << endl;
        cout << "     a  = " << toBinary4(a) << "  (" << a << ")" << endl;
        cout << "     b  = " << toBinary4(b) << "  (" << b << ")" << endl;
        cout << "     ---------" << endl;
        cout << "   a|b  = " << toBinary4(a | b) << "  (" << (a | b) << ")" << endl;
        cout << "\n   Detail:" << endl;
        cout << "     0 1 0 1  (a=5)" << endl;
        cout << "   | 0 0 1 1  (b=3)" << endl;
        cout << "   ---------" << endl;
        cout << "     0 1 1 1  = " << (a | b) << endl;

    // ----- 3. XOR (^) -----
        cout << "\n3. XOR (^) - Bit 1 jika bit BERBEDA" << endl;
        cout << "   Tabel XOR: 0^0=0, 0^1=1, 1^0=1, 1^1=0" << endl;
        cout << "   Analogi: lampu nyala hanya jika TEPAT SATU saklar ON (bukan keduanya)" << endl;
        cout << endl;
        cout << "     a  = " << toBinary4(a) << "  (" << a << ")" << endl;
        cout << "     b  = " << toBinary4(b) << "  (" << b << ")" << endl;
        cout << "     ---------" << endl;
        cout << "   a^b  = " << toBinary4(a ^ b) << "  (" << (a ^ b) << ")" << endl;
        cout << "\n   Detail:" << endl;
        cout << "     0 1 0 1  (a=5)" << endl;
        cout << "   ^ 0 0 1 1  (b=3)" << endl;
        cout << "   ---------" << endl;
        cout << "     0 1 1 0  = " << (a ^ b) << endl;

    // ----- 4. NOT (~) -----
        cout << "\n4. NOT (~) - Balik SEMUA bit (0->1, 1->0)" << endl;
        cout << "   Pada signed int: ~x = -(x+1)  (Two's Complement)" << endl;
        cout << endl;
        cout << "    a = " << toBinary8(a) << "  (" << a << ")" << endl;
        cout << "   ~a = " << toBinary8(~a) << "  (" << ~a << ")" << endl;
        cout << "\n   Mengapa ~5 = -6?" << endl;
        cout << "   Karena komputer pakai Two's Complement untuk bilangan negatif." << endl;
        cout << "   ~x selalu = -(x+1) untuk signed integer." << endl;
        cout << "   ~5 = -(5+1) = -6  " << endl;
        cout << "   ~0 = -(0+1) = -1  (semua bit 1)" << endl;
        cout << "   ~(-1) = 0         (semua bit 0)" << endl;

    // ----- 5. Left Shift (<<) -----
        cout << "\n5. Left Shift (<<) - Geser Kiri = Kali 2^n" << endl;
        cout << "   Formula: x << n  =  x x 2^n" << endl;
        cout << "   Bit di kiri yang keluar -> dibuang. Bit baru di kanan -> 0." << endl;
        cout << endl;

        int val = 5;
        
        cout << "   val     = " << toBinary8(val)      << "  (" << val      << ")" << endl;
        cout << "   val << 1 = " << toBinary8(val << 1) << "  (" << (val<<1) << ")  = 5 x 2^1 = 10" << endl;
        cout << "   val << 2 = " << toBinary8(val << 2) << "  (" << (val<<2) << ")  = 5 x 2^2 = 20" << endl;
        cout << "   val << 3 = " << toBinary8(val << 3) << "  (" << (val<<3) << ")  = 5 x 2^3 = 40" << endl;
        cout << "\n   Hati-hati overflow jika shift terlalu banyak!" << endl;

    // ----- 6. Right Shift (>>) -----
        cout << "\n6. Right Shift (>>) - Geser Kanan = Bagi 2^n" << endl;
        cout << "   Formula: x >> n  =  x / 2^n  (pembagian integer, sisa dibuang)" << endl;
        cout << "   Bit di kanan yang keluar -> dibuang. Bit baru di kiri -> 0 (unsigned)." << endl;
        cout << endl;

        int val2 = 40;

        cout << "   val     = " << toBinary8(val2)       << "  (" << val2       << ")" << endl;
        cout << "   val >> 1 = " << toBinary8(val2 >> 1) << "  (" << (val2>>1) << ")  = 40 / 2^1 = 20" << endl;
        cout << "   val >> 2 = " << toBinary8(val2 >> 2) << "  (" << (val2>>2) << ")  = 40 / 2^2 = 10" << endl;
        cout << "   val >> 3 = " << toBinary8(val2 >> 3) << "  (" << (val2>>3) << ")  = 40 / 2^3 = 5" << endl;

    // ----- 7. Penggunaan Praktis -----
        cout << "\n7. Penggunaan Praktis Bitwise" << endl;

        // a. Cek Genap/Ganjil
            cout << "\n   a. Cek Genap/Ganjil dengan & 1 (lebih cepat dari % 2)" << endl;
            for (int i = 4; i <= 9; i++) {
                cout << "      " << i << " & 1 = " << (i & 1) << "  -> " << ((i & 1) ? "Ganjil" : "Genap") << endl;
            }
            cout << "   Cara kerja: bit ke-0 (paling kanan) selalu 1 untuk ganjil, 0 untuk genap." << endl;

        // b. Perkalian/Pembagian cepat dengan shift
            cout << "\n   b. Perkalian & Pembagian Cepat dengan Shift" << endl;

            int n = 6;

            cout << "      " << n << " x 2   = " << (n << 1) << "  (n << 1)" << endl;
            cout << "      " << n << " x 4   = " << (n << 2) << "  (n << 2)" << endl;
            cout << "      " << n << " x 8   = " << (n << 3) << "  (n << 3)" << endl;
            cout << "      " << n << " / 2   = " << (n >> 1) << "  (n >> 1)" << endl;
            cout << "      " << n << " / 4   = " << (n >> 2) << "  (n >> 2) - hasil integer" << endl;

        // c. XOR Swap - swap tanpa variabel temp
            cout << "\n   c. XOR Swap - Swap Tanpa Variabel Temp" << endl;

            int p = 5, q = 3;

            cout << "      Sebelum: p=" << p << ", q=" << q << endl;
            p = p ^ q;   // p = 5^3 = 6
            q = p ^ q;   // q = 6^3 = 5  (nilai asli p)
            p = p ^ q;   // p = 6^5 = 3  (nilai asli q)

            cout << "      Sesudah: p=" << p << ", q=" << q << "  (tertukar!)" << endl;
            cout << "           Fun fact tapi praktis: pakai std::swap() saja di produksi!" << endl;

        // d. Cek Power of 2
            cout << "\n   d. Cek Apakah Angka Power of 2" << endl;
            cout << "      Rumus: (n > 0) && ((n & (n-1)) == 0)" << endl;

            int testAngka[] = {1, 2, 3, 4, 5, 8, 12, 16, 32};

            for (int t : testAngka) {
                bool isPow2 = (t > 0) && ((t & (t - 1)) == 0);
                cout << "      " << t << " -> " << (isPow2 ? "Power of 2 " : "Bukan") << endl;
            }

        // e. Bitmask - Flags / Permission System
            cout << "\n   e. Bitmask - Sistem Flags / Permission" << endl;
            cout << "      Contoh: permission file (seperti Linux chmod)" << endl;

            const int READ    = 0b100;  // bit ke-2 = 4
            const int WRITE   = 0b010;  // bit ke-1 = 2
            const int EXECUTE = 0b001;  // bit ke-0 = 1

            int userPerm = READ | WRITE;   // punya READ dan WRITE, tidak EXECUTE

            cout << "      Permission user: READ | WRITE = " << userPerm << " (binary: " << toBinary4(userPerm) << ")" << endl;
            cout << "      Bisa READ?    " << ((userPerm & READ)    ? "Ya" : "Tidak") << endl;
            cout << "      Bisa WRITE?   " << ((userPerm & WRITE)   ? "Ya" : "Tidak") << endl;
            cout << "      Bisa EXECUTE? " << ((userPerm & EXECUTE) ? "Ya" : "Tidak") << endl;

        // Tambah permission EXECUTE
            userPerm |= EXECUTE;

            cout << "\n      Setelah tambah EXECUTE: " << userPerm << " (binary: " << toBinary4(userPerm) << ")" << endl;
            cout << "      Bisa EXECUTE? " << ((userPerm & EXECUTE) ? "Ya" : "Tidak") << endl;

        // Cabut permission WRITE
            userPerm &= ~WRITE;

            cout << "\n      Setelah cabut WRITE: " << userPerm << " (binary: " << toBinary4(userPerm) << ")" << endl;
            cout << "      Bisa WRITE? " << ((userPerm & WRITE) ? "Ya" : "Tidak") << endl;

        // f. Set / Clear / Toggle satu bit
            cout << "\n   f. Manipulasi Bit Tertentu (Set / Clear / Toggle)" << endl;
            
            int v = 5;  // 0101
            int pos = 1; // bit ke-1

            int setBit    = v | (1 << pos);   // nyalakan bit ke-pos
            int clearBit  = v & ~(1 << pos);  // matikan bit ke-pos
            int toggleBit = v ^ (1 << pos);   // toggle bit ke-pos

            cout << "      v = " << toBinary4(v) << " (" << v << ")" << endl;
            cout << "      Set bit-"    << pos << ":    " << toBinary4(setBit)    << " (" << setBit    << ")  [v | (1<<pos)]" << endl;
            cout << "      Clear bit-"  << pos << ":  " << toBinary4(clearBit)  << " (" << clearBit  << ")  [v & ~(1<<pos)]" << endl;
            cout << "      Toggle bit-" << pos << ": " << toBinary4(toggleBit) << " (" << toggleBit << ")  [v ^ (1<<pos)]" << endl;

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Bitwise HANYA untuk integer, bukan float/double" << endl;
        cout << "   -> n & 1  lebih cepat dari n % 2 untuk genap/ganjil" << endl;
        cout << "   -> << n   lebih cepat dari x pow(2,n) untuk perkalian 2^n" << endl;
        cout << "   -> Pakai bitset<N> dari <bitset> untuk tampilkan biner dengan mudah" << endl;
        cout << "   -> ~x = -(x+1) untuk signed int (Two's Complement)" << endl;
        cout << "   -> Bitmask/flags sangat berguna untuk sistem permission & state" << endl;
}

int main(){

    operatorBitwise();

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

void operatorPenugasan() {
    cout << "\n========== J. Operator Penugasan ==========" << endl;

    // ----- 1. Assignment Dasar (=) -----
        cout << "\n1. Assignment Dasar (=)" << endl;

        int saldo = 1000000;
        cout << "   saldo = 1000000  ->  saldo = " << saldo << endl;

        // Chained assignment
            int a, b, c;
            a = b = c = 50;   // chained: c=50 dulu, lalu b=c, lalu a=b
            cout << "   a = b = c = 50  ->  a=" << a << ", b=" << b << ", c=" << c << endl;

    // ----- 2. Arithmetic Assignment -----
        cout << "\n2. Arithmetic Assignment (+=  -=  *=  /=  %=)" << endl;

        int x = 100;
        cout << "   Nilai awal x = " << x << endl;

        x += 50;   // x = x + 50
        cout << "   x += 50  ->  x = " << x << "  (100 + 50)" << endl;

        x -= 30;   // x = x - 30
        cout << "   x -= 30  ->  x = " << x << "  (150 - 30)" << endl;

        x *= 2;    // x = x * 2
        cout << "   x *= 2   ->  x = " << x << " (120 x 2)" << endl;

        x /= 4;    // x = x / 4
        cout << "   x /= 4   ->  x = " << x << "  (240 / 4)" << endl;

        x %= 7;    // x = x % 7
        cout << "   x %= 7   ->  x = " << x << "   (60 % 7 = 4)" << endl;

    // ----- 3. Compound Assignment dalam Konteks Nyata -----
        cout << "\n3. Contoh Nyata: Simulasi Transaksi Rekening" << endl;

        double rekening = 5000000.0;
        cout << fixed << setprecision(0);
        cout << "   Saldo awal       : Rp " << rekening << endl;

        rekening += 2500000;   // terima transfer
        cout << "   + transfer masuk : Rp " << rekening << endl;

        rekening -= 800000;    // bayar tagihan
        cout << "   - bayar listrik  : Rp " << rekening << endl;

        rekening *= 1.005;     // bunga 0.5%
        cout << "   x bunga 0.5%    : Rp " << rekening << endl;

        cout << "   Saldo akhir      : Rp " << rekening << endl;
        cout << defaultfloat;

    // ----- 4. Bitwise Assignment -----
        cout << "\n4. Bitwise Assignment (&=  |=  ^=  <<=  >>=)" << endl;

        int flags = 0b00001100;   // binary literal (C++14), nilai desimal = 12
        cout << "   flags awal = " << flags << " (binary: 0000 1100)" << endl;

        flags |= 0b00000011;   // nyalakan bit 0 dan 1 -> OR
        cout << "   flags |= 3  ->  " << flags << " (nyalakan bit 0&1)" << endl;

        flags &= 0b00001111;   // pertahankan hanya 4 bit bawah -> AND
        cout << "   flags &= 15 ->  " << flags << " (pertahankan 4 bit bawah)" << endl;

        flags ^= 0b00000101;   // toggle bit 0 dan 2 -> XOR
        cout << "   flags ^= 5  ->  " << flags << " (toggle bit 0&2)" << endl;

        int val = 8;
        val <<= 2;             // geser kiri 2 = kalikan 4
        cout << "   8 <<= 2     ->  " << val << " (8 x 4)" << endl;

        val >>= 1;             // geser kanan 1 = bagi 2
        cout << "   32 >>= 1    ->  " << val << " (32 / 2)" << endl;

    // ----- 5. Bahaya /= 0 -----
        cout << "\n5. Bahaya Division by Zero" << endl;
        cout << "   x /= 0;  -> RUNTIME ERROR: program crash / undefined behavior" << endl;
        cout << "   x %= 0;  -> RUNTIME ERROR: program crash / undefined behavior" << endl;
        cout << "\n   SOLUSI - Selalu validasi dulu:" << endl;
        cout << R"(
            int pembagi;
            cin >> pembagi;
            if (pembagi != 0) {
                x /= pembagi;   // aman
            } else {
                cout << "Error: pembagi tidak boleh nol!" << endl;
            }
        )";

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Shorthand (+=, -=, dll) lebih ringkas dan readable" << endl;
        cout << "   -> Chained assignment: a = b = c = 0; untuk inisialisasi banyak variabel" << endl;
        cout << "   -> <<= dan >>= lebih cepat dari *=2 dan /=2 untuk kelipatan 2" << endl;
        cout << "   -> Selalu cek pembagi != 0 sebelum /= atau %=" << endl;
}

int main(){

    operatorPenugasan();

    return 0;
}
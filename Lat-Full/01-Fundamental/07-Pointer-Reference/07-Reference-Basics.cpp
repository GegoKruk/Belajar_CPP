
#include <iostream>
#include <string>
using namespace std;

int main() {

    // ----- 1. Reference Dasar -----
        cout << "=== 1. Reference Dasar ===" << endl;

        int angka = 10;
        int& ref  = angka;   // ref adalah alias dari angka

        cout << "int angka = 10" << endl;
        cout << "int& ref  = angka" << endl;
        cout << endl;
        cout << "angka = " << angka << endl;
        cout << "ref   = " << ref   << " (sama dengan angka)" << endl;
        cout << "&angka = " << &angka << " (alamat angka)" << endl;
        cout << "&ref   = " << &ref   << " (alamat ref = SAMA!)" << endl;
        cout << "Apakah &angka == &ref? " << (&angka == &ref ? "Ya - alamat identik!" : "Tidak") << endl;


    // ----- 2. Modifikasi via Reference -----
        cout << endl << "=== 2. Modifikasi via Reference ===" << endl;

        cout << "Sebelum: angka = " << angka << endl;
        ref = 99;   // ubah via reference
        cout << "Setelah ref = 99:" << endl;
        cout << "  angka = " << angka << " (ikut berubah!)" << endl;
        cout << "  ref   = " << ref   << endl;

        // Modifikasi lewat variabel asli juga terlihat dari reference
            angka = 55;
            cout << "Setelah angka = 55:" << endl;
            cout << "  angka = " << angka << endl;
            cout << "  ref   = " << ref   << " (reference juga terlihat perubahannya)" << endl;


    // ----- 3. Reference TIDAK BISA Diarahkan Ulang -----
        cout << endl << "=== 3. Reference Tidak Bisa Reassign ===" << endl;

        int a = 10;
        int b = 20;
        int& r = a;    // r adalah alias dari a

        cout << "int a = 10, b = 20" << endl;
        cout << "int& r = a  -> r alias dari a" << endl;
        cout << "r = " << r << ", a = " << a << endl;

        r = b;   // INI bukan reassign ref! Ini mengisi NILAI a dengan nilai b
        cout << endl << "Setelah r = b:" << endl;
        cout << "  r = " << r << " (nilai b = 20)" << endl;
        cout << "  a = " << a << " (a berubah menjadi 20!)" << endl;
        cout << "  b = " << b << " (b tidak berubah)" << endl;
        cout << "  &r = " << &r << " (masih alamat a, bukan b!)" << endl;
        cout << "  &a = " << &a << endl;
        cout << "  Jadi r = b adalah COPY VALUE, bukan reassign reference!" << endl;


    // ----- 4. Reference ke Berbagai Tipe -----
        cout << endl << "=== 4. Reference ke Berbagai Tipe ===" << endl;

        double nilai  = 3.14;
        double& rNilai = nilai;

        string nama   = "Gega";
        string& rNama = nama;

        cout << "double nilai = 3.14, ref: rNilai = " << rNilai << endl;
        cout << "string nama  = Gega, ref: rNama  = " << rNama  << endl;

        rNama = "Ramadhan";
        cout << "Setelah rNama = 'Ramadhan': nama = " << nama << endl;


    // ----- 5. Const Reference -----
        cout << endl << "=== 5. Const Reference ===" << endl;

        int angka2 = 42;
        const int& cref = angka2;

        cout << "int angka2 = 42" << endl;
        cout << "const int& cref = angka2" << endl;
        cout << "cref = " << cref << " (bisa dibaca)" << endl;

        // cref = 99;  // TIDAK BISA - ini akan error compile
        cout << "cref = 99 -> TIDAK BISA (const reference, read-only)" << endl;

        // Tapi variabel asli tetap bisa diubah
        angka2 = 77;
        cout << "Setelah angka2 = 77: cref = " << cref << " (ikut terlihat)" << endl;


    // ----- 6. Const Reference ke Literal / Temporary -----
        cout << endl << "=== 6. Const Reference ke Literal/Temporary ===" << endl;

        const int&  crLiteral = 42;          // OK: bind ke literal
        const int&  crExpr    = 10 + 20;     // OK: bind ke temporary expression
        // int& rLiteral = 42;               // TIDAK BISA: non-const ke literal

        cout << "const int& crLiteral = 42    -> " << crLiteral << endl;
        cout << "const int& crExpr = 10 + 20  -> " << crExpr    << endl;
        cout << "int& rLiteral = 42           -> TIDAK BISA (non-const ref ke literal)" << endl;

        const string& greet = "Halo Dunia";
        cout << "const string& greet = \"Halo Dunia\" -> " << greet << endl;


    // ----- 7. Perbandingan Langsung -----
        cout << endl << "=== 7. Ringkasan: Reference vs Salinan ===" << endl;

        int asli    = 100;
        int salinan = asli;   // salinan: variabel baru
        int& alias  = asli;   // alias: nama lain dari asli

        cout << "asli    = " << asli    << " | &asli    = " << &asli    << endl;
        cout << "salinan = " << salinan << " | &salinan = " << &salinan << " (BEDA alamat!)" << endl;
        cout << "alias   = " << alias   << " | &alias   = " << &alias   << " (SAMA dengan asli)" << endl;

        asli = 999;
        cout << endl << "Setelah asli = 999:" << endl;
        cout << "  asli    = " << asli    << endl;
        cout << "  salinan = " << salinan << " (tidak berubah, variabel sendiri)" << endl;
        cout << "  alias   = " << alias   << " (ikut berubah, alamat sama)" << endl;

    return 0;
}

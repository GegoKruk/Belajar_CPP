#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void precedence() {
    cout << "========== Operator Precedence (Prioritas) ==========" << endl;

    // ----- 1. Contoh Dasar -----
        cout << "\n1. Contoh Dasar - Sama Seperti Matematika" << endl;

        int hasil1 = 2 + 3 * 4;        // 3*4 = 12 dulu, lalu + 2 = 14
        int hasil2 = (2 + 3) * 4;      // kurung dulu: 2+3=5, lalu *4 = 20
        int hasil3 = 10 - 4 / 2;       // 4/2 = 2 dulu, lalu 10-2 = 8
        int hasil4 = 10 % 3 + 1;       // 10%3 = 1 dulu, lalu 1+1 = 2

        cout << "   2 + 3 * 4     = " << hasil1 << "  (bukan 20, * lebih tinggi dari +)" << endl;
        cout << "   (2 + 3) * 4   = " << hasil2 << "  (kurung dikerjakan dulu)" << endl;
        cout << "   10 - 4 / 2    = " << hasil3 << "   (/ lebih tinggi dari -)" << endl;
        cout << "   10 % 3 + 1    = " << hasil4 << "   (% sama level dengan /, dikerjakan dulu)" << endl;

    // ----- 2. Associativity - Arah Evaluasi -----
        cout << "\n2. Associativity - Arah Evaluasi Saat Level Sama" << endl;

        // Left-to-right (kebanyakan operator)
            int a = 20 - 5 - 3;    // (20-5)-3 = 15-3 = 12, bukan 20-(5-3) = 18
            int b = 100 / 10 / 2;  // (100/10)/2 = 10/2 = 5, bukan 100/(10/2) = 20

            cout << "   20 - 5 - 3    = " << a << "   (Left-to-right: (20-5)-3)" << endl;
            cout << "   100 / 10 / 2  = " << b << "    (Left-to-right: (100/10)/2)" << endl;

        // Right-to-left (assignment)
            int x, y, z;
            x = y = z = 7;    // Right-to-left: z=7, y=z, x=y -> semua jadi 7
            cout << "   x = y = z = 7  -> x=" << x << ", y=" << y << ", z=" << z << "  (Right-to-left)" << endl;

    // ----- 3. Ekspresi Kompleks - Telusuri Manual -----
        cout << "\n3. Telusuri Ekspresi Kompleks Manual" << endl;

        int p = 3, q = 4, r = 2;
        int ekspresi = p + q * r - p % r + 1;

        cout << "   p=" << p << ", q=" << q << ", r=" << r << endl;
        cout << "   Ekspresi: p + q * r - p % r + 1" << endl;
        cout << "\n   Langkah-langkah (ikuti precedence):" << endl;
        cout << "     q * r   = " << q*r   << "             (step 1: * lebih tinggi)" << endl;
        cout << "     p % r   = " << p%r   << "             (step 2: % sama level dengan *)" << endl;
        cout << "     p + " << q*r << " - " << p%r << " + 1  (step 3: +/- dari kiri ke kanan)" << endl;
        cout << "     = " << p+q*r << " - " << p%r << " + 1" << endl;
        cout << "     = " << p+q*r-p%r << " + 1" << endl;
        cout << "     = " << ekspresi << endl;
        cout << "   Hasil: " << ekspresi << endl;

    // ----- 4. Precedence Logika + Perbandingan -----
        cout << "\n4. Precedence: Perbandingan > Logika" << endl;

        int umur = 20;
        bool pelajar = false;

        bool bisa = umur >= 18 && !pelajar || umur >= 25;
        // Diproses:
        // 1. umur >= 18    -> true
        // 2. !pelajar      -> true  (! lebih tinggi dari &&)
        // 3. umur >= 25    -> false
        // 4. true && true  -> true  (&& lebih tinggi dari ||)
        // 5. true || false -> true

        cout << "   umur=" << umur << ", pelajar=" << (pelajar?"true":"false") << endl;
        cout << "   umur >= 18 && !pelajar || umur >= 25" << endl;
        cout << "   = (umur>=18) && (!pelajar) || (umur>=25)   <- >= lebih tinggi dari &&" << endl;
        cout << "   = (true && true) || false                  <- && lebih tinggi dari ||" << endl;
        cout << "   = true || false" << endl;
        cout << "   = " << boolalpha << bisa << noboolalpha << endl;

        cout << "\n  Versi yang lebih jelas dengan kurung:" << endl;
        bool bisa2 = ((umur >= 18) && (!pelajar)) || (umur >= 25);
        cout << "   ((umur >= 18) && (!pelajar)) || (umur >= 25) = " << boolalpha << bisa2 << noboolalpha << endl;

    // ----- 5. sizeof -----
        cout << "\n5. Operator sizeof - Ukuran Tipe Data" << endl;
        cout << "   sizeof bukan fungsi - ini operator compile-time!" << endl;
        cout << "   Hasil dalam satuan BYTE." << endl;
        cout << endl;
        cout << "   sizeof(char)        = " << sizeof(char)        << " byte" << endl;
        cout << "   sizeof(bool)        = " << sizeof(bool)        << " byte" << endl;
        cout << "   sizeof(int)         = " << sizeof(int)         << " byte" << endl;
        cout << "   sizeof(float)       = " << sizeof(float)       << " byte" << endl;
        cout << "   sizeof(double)      = " << sizeof(double)      << " byte" << endl;
        cout << "   sizeof(long long)   = " << sizeof(long long)   << " byte" << endl;
        cout << "   sizeof(long double) = " << sizeof(long double) << " byte" << endl;

        // sizeof array
        int arr[] = {1, 2, 3, 4, 5};
        int panjangArr = sizeof(arr) / sizeof(arr[0]);
        cout << "\n   sizeof array trick:" << endl;
        cout << "   int arr[5]:  sizeof(arr)         = " << sizeof(arr)    << " byte" << endl;
        cout << "                sizeof(arr[0])       = " << sizeof(arr[0]) << " byte" << endl;
        cout << "                sizeof(arr)/sizeof(arr[0]) = " << panjangArr << "  (jumlah elemen)" << endl;
}

int main() {
    precedence();
}
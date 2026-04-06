
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    // ----- 1. Deklarasi dan Inisialisasi -----
        cout << "=== 1. Deklarasi dan Inisialisasi ===" << endl;

        char nama1[6] = "Gega";                    // Eksplisit, 4 huruf + \0
        char nama2[]  = "Ramadhan";                // Omit size, otomatis 9 (8 + \0)
        char huruf[4] = {'A', 'B', 'C', '\0'};     // Per karakter, \0 manual

        cout << "nama1  : " << nama1 << endl;
        cout << "nama2  : " << nama2 << endl;
        cout << "huruf  : " << huruf << endl;


    // ----- 2. strlen() - Panjang String -----
        cout << endl << "=== 2. strlen() - Panjang String ===" << endl;

        char kota[] = "Yogyakarta";
        cout << "kota       : " << kota         << endl;
        cout << "strlen     : " << strlen(kota) << " (tanpa \\0)" << endl;
        cout << "sizeof     : " << sizeof(kota) << " (termasuk \\0)" << endl;


    // ----- 3. strcpy() - Copy String -----
        cout << endl << "=== 3. strcpy() - Copy String ===" << endl;

        char sumber[] = "Halo Dunia";
        char tujuan[20];                // Pastikan cukup besar!

        strcpy(tujuan, sumber);

        cout << "sumber : " << sumber << endl;
        cout << "tujuan : " << tujuan << " (hasil copy)" << endl;


    // ----- 4. strcat() - Gabung String -----
        cout << endl << "=== 4. strcat() - Gabung String ===" << endl;

        char depan[30] = "Halo";    // Harus cukup besar untuk menampung hasil gabungan
        char belakang[] = " Dunia!";

        cout << "Sebelum: " << depan << endl;
        strcat(depan, belakang);
        cout << "Sesudah: " << depan << endl;


    // ----- 5. strcmp() - Bandingkan String -----
        cout << endl << "=== 5. strcmp() - Bandingkan String ===" << endl;

        char s1[] = "Apple";
        char s2[] = "Apple";
        char s3[] = "Banana";

        int hasil1 = strcmp(s1, s2);
        int hasil2 = strcmp(s1, s3);

        cout << "strcmp(\"Apple\", \"Apple\")  = " << hasil1
            << (hasil1 == 0 ? " -> sama" : " -> berbeda") << endl;
        cout << "strcmp(\"Apple\", \"Banana\") = " << hasil2
            << (hasil2 < 0 ? " -> Apple < Banana (A < B)" : " -> berbeda") << endl;

        // Cara perbandingan yang BENAR vs SALAH
            cout << endl << "Cara bandingkan yang BENAR:" << endl;
            if (strcmp(s1, s2) == 0) {
                cout << "  s1 dan s2 isinya sama" << endl;
            }


    // ----- 6. Iterasi Per Karakter -----
        cout << endl << "=== 6. Iterasi Per Karakter ===" << endl;

        char kata[] = "Halo";
        int panjang = strlen(kata);

        cout << "Karakter di \"" << kata << "\":" << endl;
        for (int i = 0; i < panjang; i++) {
            cout << "  kata[" << i << "] = '" << kata[i]
                << "'  (ASCII: " << (int)kata[i] << ")" << endl;
        }


    // ----- 7. Konversi Huruf Besar/Kecil Manual -----
        cout << endl << "=== 7. Konversi Case Manual ===" << endl;

        char teks[] = "hello world";
        cout << "Sebelum: " << teks << endl;

        // Ubah ke huruf besar (lowercase + 32 = uppercase dalam ASCII)
        for (int i = 0; teks[i] != '\0'; i++) {
            if (teks[i] >= 'a' && teks[i] <= 'z') {
                teks[i] = teks[i] - 32;
            }
        }
        cout << "Sesudah: " << teks << endl;

    return 0;
}

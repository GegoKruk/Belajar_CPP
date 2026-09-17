
#include <iostream>
using namespace std;

int main() {

    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    // ----- 1. Pointer + n (maju n elemen) -----
        cout << "=== 1. Pointer + n ===" << endl;

        int* ptr = arr;   // ptr menunjuk ke arr[0]

        cout << "ptr       menunjuk ke arr[0], nilai = " << *ptr       << endl;
        cout << "ptr + 1   menunjuk ke arr[1], nilai = " << *(ptr + 1) << endl;
        cout << "ptr + 2   menunjuk ke arr[2], nilai = " << *(ptr + 2) << endl;
        cout << "ptr + 3   menunjuk ke arr[3], nilai = " << *(ptr + 3) << endl;
        cout << "ptr + 4   menunjuk ke arr[4], nilai = " << *(ptr + 4) << endl;

        cout << endl;
        cout << "Perhatikan alamatnya:" << endl;
        cout << "ptr       = " << ptr       << endl;
        cout << "ptr + 1   = " << (ptr + 1) << endl;
        cout << "ptr + 2   = " << (ptr + 2) << endl;
        cout << "Selisih per elemen = " << sizeof(int) << " byte (sizeof int)" << endl;


    // ----- 2. Increment dan Decrement Pointer -----
        cout << endl << "=== 2. Increment dan Decrement (ptr++ / ptr--) ===" << endl;

        int* p = arr;    // mulai dari arr[0]

        cout << "Mulai: *p = " << *p << " (arr[0])" << endl;
        p++;
        cout << "p++  : *p = " << *p << " (arr[1])" << endl;
        p++;
        cout << "p++  : *p = " << *p << " (arr[2])" << endl;
        p--;
        cout << "p--  : *p = " << *p << " (arr[1] lagi)" << endl;


    // ----- 3. Traversal Array dengan Pointer -----
        cout << endl << "=== 3. Traversal Array dengan Pointer ===" << endl;

        cout << "Cara index biasa   : ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Cara pointer arit. : ";
        for (int* p2 = arr; p2 < arr + n; p2++) {
            cout << *p2 << " ";
        }
        cout << endl;

        cout << "Cara ptr[i]        : ";
        int* ptr2 = arr;
        for (int i = 0; i < n; i++) {
            cout << ptr2[i] << " ";    // ptr[i] == *(ptr + i)
        }
        cout << endl;


    // ----- 4. Selisih Dua Pointer -----
        cout << endl << "=== 4. Selisih Dua Pointer (ptr1 - ptr2) ===" << endl;

        int* pAwal  = &arr[0];
        int* pAkhir = &arr[4];

        int selisih = pAkhir - pAwal;   // dalam satuan ELEMEN, bukan byte

        cout << "pAwal  = &arr[0] = " << pAwal  << endl;
        cout << "pAkhir = &arr[4] = " << pAkhir << endl;
        cout << "pAkhir - pAwal   = " << selisih << " elemen (bukan byte)" << endl;

        // Selisih byte sebenarnya:
        long long selisihByte = (long long)pAkhir - (long long)pAwal;
        cout << "Selisih byte     = " << selisihByte << " byte" << endl;
        cout << "                 = " << selisih << " elemen x " << sizeof(int) << " byte/elemen" << endl;


    // ----- 5. Perbandingan Pointer -----
        cout << endl << "=== 5. Perbandingan Pointer ===" << endl;

        int* q1 = &arr[1];
        int* q2 = &arr[3];
        int* q3 = &arr[1];

        cout << "q1 = &arr[1], q2 = &arr[3], q3 = &arr[1]" << endl;
        cout << "q1 == q3 ? " << (q1 == q3 ? "Ya" : "Tidak") << " (menunjuk alamat sama)" << endl;
        cout << "q1 == q2 ? " << (q1 == q2 ? "Ya" : "Tidak") << " (alamat berbeda)"       << endl;
        cout << "q1 <  q2 ? " << (q1 <  q2 ? "Ya" : "Tidak") << " (q1 di kiri q2)"        << endl;
        cout << "q2 >  q1 ? " << (q2 >  q1 ? "Ya" : "Tidak") << " (q2 di kanan q1)"       << endl;


    // ----- 6. Modifikasi Nilai via Pointer Arithmetic -----
        cout << endl << "=== 6. Modifikasi via Pointer Arithmetic ===" << endl;

        int data[4] = {5, 10, 15, 20};
        int* pd = data;

        cout << "Sebelum: ";
        for (int i = 0; i < 4; i++) cout << data[i] << " ";
        cout << endl;

        // Kalikan setiap elemen dengan 2 via pointer arithmetic
        for (int i = 0; i < 4; i++) {
            *(pd + i) *= 2;
        }

        cout << "Sesudah (x2): ";
        for (int i = 0; i < 4; i++) cout << data[i] << " ";
        cout << endl;

        return 0;
}


#include <iostream>
using namespace std;

int main() {

    // ----- 1. List Initialization (Complete) -----
        cout << "1. List Initialization (Complete)" << endl;
        int nilaiLengkap[5] = {85, 90, 78, 92, 88};
        for (int i = 0; i < 5; i++) {
            cout << "   nilaiLengkap[" << i << "] = " << nilaiLengkap[i] << endl;
        }

    // ----- 2. Partial Initialization -----
        cout << endl << "2. Partial Initialization (sisa otomatis 0)" << endl;
        int nilaiSebagian[5] = {80, 90};
        for (int i = 0; i < 5; i++) {
            cout << "   nilaiSebagian[" << i << "] = " << nilaiSebagian[i] << endl;
        }

    // ----- 3. Zero Initialization -----
        cout << endl << "3. Zero Initialization (semua jadi 0)" << endl;
        int nilaiNol[5] = {0};
        for (int i = 0; i < 5; i++) {
            cout << "   nilaiNol[" << i << "] = " << nilaiNol[i] << endl;
        }

    // ----- 4. Omit Size (ukuran otomatis) -----
        cout << endl << "4. Omit Size (ukuran dihitung otomatis)" << endl;
        int nilaiAuto[] = {10, 20, 30, 40, 50};
        int ukuran = sizeof(nilaiAuto) / sizeof(nilaiAuto[0]);
        cout << "   Ukuran otomatis terdeteksi: " << ukuran << endl;
        for (int i = 0; i < ukuran; i++) {
            cout << "   nilaiAuto[" << i << "] = " << nilaiAuto[i] << endl;
        }

    // ----- 5. Uniform Initialization C++11 -----
        cout << endl << "5. Uniform Initialization (C++11, tanpa tanda =)" << endl;
        int nilaiUniform[5] {11, 22, 33, 44, 55};
        for (int i = 0; i < 5; i++) {
            cout << "   nilaiUniform[" << i << "] = " << nilaiUniform[i] << endl;
        }

    // ----- 6. Deklarasi dengan const size -----
        cout << endl << "6. Deklarasi dengan const size (best practice)" << endl;
        const int SIZE = 4;
        double ipk[SIZE] = {3.85, 3.50, 3.90, 3.75};
        for (int i = 0; i < SIZE; i++) {
            cout << "   ipk[" << i << "] = " << ipk[i] << endl;
        }

    return 0;
}

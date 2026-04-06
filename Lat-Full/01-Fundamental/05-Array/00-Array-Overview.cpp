#include <iostream>
using namespace std;

int main() {

    // Contoh paling dasar: deklarasi dan akses array
        int nilai[5] = {85, 90, 78, 92, 88};

        cout << "=== Contoh Dasar Array ===" << endl;
        cout << "nilai[0] = " << nilai[0] << endl;
        cout << "nilai[2] = " << nilai[2] << endl;
        cout << "nilai[4] = " << nilai[4] << endl;

    // Loop sederhana untuk print semua elemen
        cout << endl << "Semua elemen:" << endl;
        int n = sizeof(nilai) / sizeof(nilai[0]);
        
        for (int i = 0; i < n; i++) {
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
        }

    return 0;
}


#include <iostream>
using namespace std;

int main(){

    int nilai[6] = {85, 90, 78, 92, 88, 76};
    int n = sizeof(nilai) / sizeof(nilai[0]);


    // ----- 1. For Loop (Index-based) -----
        cout << "=== 1. For Loop (Index-based) ===" << endl;

        for (int i = 0; i < n; i++){
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
        }


    // ----- 2. Range-based For Loop (Read Only) -----
        cout << endl << "=== 2. Range-based For Loop (C++11) ===" << endl;
        
        cout << "  Elemen: ";
        for (int x : nilai){
            cout << x << " ";
        }
        cout << endl;


        // ----- 3. Range-based For Loop (Modifikasi dengan referensi) -----
        cout << endl << "=== 3. Range-based For + Referensi (Modifikasi) ===" << endl;
        int bonus[6] = {10, 20, 30, 40, 50, 60};
        
        cout << "  Sebelum: ";
        for (int x : bonus){
            cout << x << " ";
        }
        cout << endl;

    // Tambahkan 5 ke setiap elemen pakai referensi
        for (int &x : bonus){
            x += 5;
        }
        cout << "  Sesudah (+5): ";
        for (int x : bonus){
            cout << x << " ";
        }
        cout << endl;


    // ----- 4. While Loop -----
        cout << endl << "=== 4. While Loop ===" << endl;
        int i = 0;

        while (i < n){
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
            i++;
        }


    // ----- 5. Traversing Mundur (dari belakang) -----
        cout << endl << "=== 5. Traversing Mundur ===" << endl;
        
        for (int i = n - 1; i >= 0; i--){
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
        }


    // ----- 6. Traversing Hanya Elemen Genap -----
        cout << endl << "=== 6. Traversing dengan Kondisi (nilai >= 85) ===" << endl;
        for (int i = 0; i < n; i++){
            if (nilai[i] >= 85) {
                cout << "  nilai[" << i << "] = " << nilai[i] << " (>= 85)" << endl;
            }
        }

    return 0;
}

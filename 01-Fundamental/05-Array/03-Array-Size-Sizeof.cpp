
#include <iostream>
using namespace std;

// Demonstrasi jebakan sizeof di dalam function

    void demoSizeofDalamFunction(int arr[], int size) {

        // sizeof(arr) di sini = ukuran POINTER, bukan array asli!
        cout << "  sizeof(arr) di dalam function = " << sizeof(arr) << " byte (ini ukuran pointer!)" << endl;
        cout << "  Makanya ukuran harus dikirim lewat parameter: size = " << size << endl;
    }

int main() {

    // ----- sizeof pada berbagai tipe array -----
        cout << "=== sizeof() pada Berbagai Tipe ===" << endl;

        int    arrInt[5]    = {1, 2, 3, 4, 5};
        double arrDouble[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
        char   arrChar[5]   = {'a', 'b', 'c', 'd', 'e'};

        cout << "int arrInt[5]:" << endl;
        cout << "  sizeof(arrInt)        = " << sizeof(arrInt)    << " byte" << endl;
        cout << "  sizeof(arrInt[0])     = " << sizeof(arrInt[0]) << " byte" << endl;
        cout << "  Jumlah elemen         = " << sizeof(arrInt)/sizeof(arrInt[0]) << endl;

        cout << endl << "double arrDouble[5]:" << endl;
        cout << "  sizeof(arrDouble)     = " << sizeof(arrDouble)    << " byte" << endl;
        cout << "  sizeof(arrDouble[0])  = " << sizeof(arrDouble[0]) << " byte" << endl;
        cout << "  Jumlah elemen         = " << sizeof(arrDouble)/sizeof(arrDouble[0]) << endl;

        cout << endl << "char arrChar[5]:" << endl;
        cout << "  sizeof(arrChar)       = " << sizeof(arrChar)    << " byte" << endl;
        cout << "  sizeof(arrChar[0])    = " << sizeof(arrChar[0]) << " byte" << endl;
        cout << "  Jumlah elemen         = " << sizeof(arrChar)/sizeof(arrChar[0]) << endl;


    // ----- Rumus panjang array -----
        cout << endl << "=== Rumus Panjang Array ===" << endl;
        int data[] = {10, 20, 30, 40, 50, 60};
        int panjang = sizeof(data) / sizeof(data[0]);
        cout << "Array: {10, 20, 30, 40, 50, 60}" << endl;
        cout << "Panjang: sizeof(data)/sizeof(data[0]) = " << panjang << endl;


    // ----- Gunakan const size (best practice) -----
        cout << endl << "=== const SIZE (Best Practice) ===" << endl;
        const int SIZE = 4;
        int nilai[SIZE] = {85, 90, 78, 92};
        cout << "const int SIZE = " << SIZE << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "  nilai[" << i << "] = " << nilai[i] << endl;
        }


    // ----- Jebakan sizeof di dalam function -----
        cout << endl << "=== Jebakan sizeof() di Dalam Function ===" << endl;
        cout << "sizeof(arrInt) di main = " << sizeof(arrInt) << " byte (benar)" << endl;

        int ukuranBenar = sizeof(arrInt) / sizeof(arrInt[0]);

        demoSizeofDalamFunction(arrInt, ukuranBenar);

    return 0;
}

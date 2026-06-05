#include <iostream>
#include <string>
using namespace std;

// Demonstrasi overview pointer tingkat lanjut

int main() {
    cout << "=== Advanced Pointers - Overview ===\n\n";

    // Pointer ke pointer (double pointer)
    int nilai = 42;
    int* ptr = &nilai;
    int** ptr2 = &ptr;

    cout << "Nilai asli      : " << nilai << endl;
    cout << "Alamat nilai    : " << &nilai << endl;
    cout << "ptr menyimpan   : " << ptr << endl;
    cout << "ptr2 menyimpan  : " << ptr2 << endl;
    cout << "Akses via **ptr2: " << **ptr2 << endl;

    // Array of pointers (string literals)
    const char* hari[3] = {"Senin", "Selasa", "Rabu"};
    cout << "\nArray of pointers (hari):\n";
    for(int i=0; i<3; i++)
        cout << "  hari[" << i << "] = " << hari[i] << endl;

    // Function pointer sederhana
    auto tambah = [](int a, int b) -> int { return a+b; };
    int (*fp)(int,int) = tambah;
    cout << "\nFunction pointer: fp(5,3) = " << fp(5,3) << endl;

    // Void pointer
    void* vp = &nilai;
    int* ip = static_cast<int*>(vp);
    cout << "\nVoid pointer cast ke int: " << *ip << endl;

    cout << "\n[Modul ini akan membahas semua konsep di atas secara mendalam]\n";
    return 0;
}
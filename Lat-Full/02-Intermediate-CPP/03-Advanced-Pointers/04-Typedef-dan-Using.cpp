#include <iostream>
#include <vector>
using namespace std;

// Contoh fungsi untuk callback
int tambah(int a, int b) { return a + b; }
int kurang(int a, int b) { return a - b; }
int kali(int a, int b)   { return a * b; }

int main() {
    cout << "=== Typedef dan Using untuk Pointer ===\n\n";

    // --- Cara lama (typedef) ---
    typedef int* IntPtr;                 // alias untuk pointer ke int
    typedef int (*FuncPtr)(int,int);     // alias untuk function pointer

    int nilai = 100;
    IntPtr pInt = &nilai;
    FuncPtr f = tambah;

    cout << "typedef:\n";
    cout << "  *pInt = " << *pInt << endl;
    cout << "  f(10,5) = " << f(10,5) << endl;

    // --- Cara modern (using - C++11) ---
    using IntPtr2 = int*;
    using FuncPtr2 = int (*)(int,int);
    using OpsArray = FuncPtr2[3];       // alias untuk array of function pointers

    IntPtr2 pInt2 = &nilai;
    FuncPtr2 f2 = kurang;
    OpsArray ops = {tambah, kurang, kali};

    cout << "\nusing (modern):\n";
    cout << "  *pInt2 = " << *pInt2 << endl;
    cout << "  f2(10,5) = " << f2(10,5) << endl;

    cout << "  Dispatch via OpsArray:\n";
    const char* nama[] = {"tambah","kurang","kali"};
    for(int i=0; i<3; i++) {
        cout << "    " << nama[i] << "(10,4) = " << ops[i](10,4) << endl;
    }

    // --- Alias untuk pointer ke pointer ---
    using DoubleIntPtr = int**;
    int a = 42;
    int* pa = &a;
    DoubleIntPtr ppa = &pa;
    cout << "\nDoubleIntPtr: **ppa = " << **ppa << endl;

    // --- Alias untuk pointer ke const ---
    using ConstIntPtr = const int*;
    const int b = 99;
    ConstIntPtr pConst = &b;
    // *pConst = 100; // ERROR: const
    cout << "ConstIntPtr: *pConst = " << *pConst << endl;

    // --- Alias dalam struct (contoh) ---
    struct Kalkulator {
        using Operation = int (*)(int,int);
        Operation op;

        void setOperation(Operation o) { op = o; }
        int execute(int x, int y) { return op(x,y); }
    };

    Kalkulator calc;
    calc.setOperation(kali);
    cout << "\nStruct dengan alias Operation: kali(7,6) = " << calc.execute(7,6) << endl;

    return 0;
}
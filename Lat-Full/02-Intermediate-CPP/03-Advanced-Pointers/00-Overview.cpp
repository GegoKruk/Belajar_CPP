#include <iostream>
#include <string>
#include <functional>
using namespace std;

// -------------------------------------------------------
// STRUCT HELPER
// -------------------------------------------------------
struct Titik {
    double x, y;
    Titik(double x, double y) : x(x), y(y) {}
    void cetak() const {
        cout << "  (" << x << ", " << y << ")" << endl;
    }
};

// -------------------------------------------------------
// FUNCTION UNTUK DEMO FUNCTION POINTER
// -------------------------------------------------------
int tambah (int a, int b) { return a + b; }
int kurang (int a, int b) { return a - b; }
int kali   (int a, int b) { return a * b; }

// -------------------------------------------------------
// UNTUK DEMO THIS POINTER (mini class)
// -------------------------------------------------------
class Counter {
    int nilai;
public:
    Counter(int awal = 0) : nilai(awal) {}
    Counter& naik()  { nilai++; return *this; }
    Counter& turun() { nilai--; return *this; }
    void cetak() const { cout << "  counter = " << nilai << endl; }
};

int main() {

    // -------------------------------------------------------
    // 1. POINTER-TO-POINTER (int**)
    // -------------------------------------------------------
    cout << "=== 1. Pointer-to-Pointer ===" << endl;
    {
        int   x  = 42;
        int*  p  = &x;
        int** pp = &p;

        cout << "  x    = " << x    << endl;
        cout << "  *p   = " << *p   << endl;
        cout << "  **pp = " << **pp << endl;

        **pp = 99;
        cout << "  setelah **pp = 99: x = " << x << endl;

        // Ubah pointer via pp
        int y = 777;
        *pp = &y;
        cout << "  setelah *pp = &y: *p = " << *p << endl;
    }

    // -------------------------------------------------------
    // 2. ARRAY OF POINTERS
    // -------------------------------------------------------
    cout << "\n=== 2. Array of Pointers ===" << endl;
    {
        int a = 10, b = 20, c = 30, d = 40, e = 50;
        int* ptrs[] = { &a, &b, &c, &d, &e };
        int  n = 5;

        cout << "  nilai via pointer: ";
        for (int i = 0; i < n; i++) cout << *ptrs[i] << " ";
        cout << endl;

        // Ubah nilai via pointer
        *ptrs[2] = 999;
        cout << "  setelah *ptrs[2]=999: c = " << c << endl;

        // Array of C-string
        const char* hari[] = { "Senin", "Selasa", "Rabu", "Kamis", "Jumat" };
        cout << "  hari[0]=" << hari[0] << " | hari[4]=" << hari[4] << endl;
    }

    // -------------------------------------------------------
    // 3. FUNCTION POINTER LANJUTAN
    // -------------------------------------------------------
    cout << "\n=== 3. Function Pointer Lanjutan ===" << endl;
    {
        using BinaryOp = int (*)(int, int);

        BinaryOp tabel[] = { tambah, kurang, kali };
        string   nama[]  = { "tambah", "kurang", "kali" };

        for (int i = 0; i < 3; i++) {
            cout << "  " << nama[i] << "(10, 4) = " << tabel[i](10, 4) << endl;
        }

        // Function pointer sebagai return value
        auto pilih = [](char op) -> BinaryOp {
            if (op == '+') return tambah;
            if (op == '-') return kurang;
            if (op == '*') return kali;
            return nullptr;
        };

        BinaryOp fn = pilih('*');
        if (fn) cout << "  pilih('*')(6, 7) = " << fn(6, 7) << endl;
    }

    // -------------------------------------------------------
    // 4. TYPEDEF DAN USING
    // -------------------------------------------------------
    cout << "\n=== 4. Typedef dan Using ===" << endl;
    {
        // typedef (cara lama)
        typedef int* IntPtr;
        typedef int (*FuncPtr)(int, int);

        // using (cara modern, direkomendasikan)
        using IntRef    = int&;
        using BinaryFn  = int (*)(int, int);
        using TitikPtr  = Titik*;

        IntPtr   p  = new int(55);
        BinaryFn fp = tambah;
        TitikPtr t  = new Titik(3.0, 4.0);

        cout << "  IntPtr  *p  = " << *p       << endl;
        cout << "  BinaryFn fp = " << fp(3, 7)  << endl;
        cout << "  TitikPtr t  : "; t->cetak();

        delete p;  p = nullptr;
        delete t;  t = nullptr;

        // Bedanya typedef vs using
        FuncPtr fp2 = kurang;
        cout << "  typedef FuncPtr: fp2(10,3) = " << fp2(10, 3) << endl;
    }

    // -------------------------------------------------------
    // 5. VOID POINTER
    // -------------------------------------------------------
    cout << "\n=== 5. Void Pointer ===" << endl;
    {
        int    angka  = 42;
        double desimal = 3.14;
        char   huruf  = 'Z';

        void* vp;

        vp = &angka;
        cout << "  void* -> int*  : " << *static_cast<int*>(vp)    << endl;

        vp = &desimal;
        cout << "  void* -> double: " << *static_cast<double*>(vp) << endl;

        vp = &huruf;
        cout << "  void* -> char* : " << *static_cast<char*>(vp)   << endl;
    }

    // -------------------------------------------------------
    // 6. POINTER CASTING
    // -------------------------------------------------------
    cout << "\n=== 6. Pointer Casting ===" << endl;
    {
        // static_cast: konversi numerik
        double d = 9.87;
        int    i = static_cast<int>(d);
        cout << "  static_cast<int>(9.87) = " << i << endl;

        // static_cast: void* ke int*
        int  x  = 123;
        void* vp = &x;
        int*  ip = static_cast<int*>(vp);
        cout << "  static_cast void*->int*: " << *ip << endl;

        // reinterpret_cast: int* ke char* (baca byte per byte)
        int   val  = 0x41424344;   // ASCII: DCBA (little-endian)
        char* cp   = reinterpret_cast<char*>(&val);
        cout << "  reinterpret_cast byte[0] = '" << cp[0] << "'" << endl;

        // const_cast: hapus const untuk memanggil fungsi non-const
        const int cx = 100;
        const int* cptr = &cx;
        // Boleh baca:
        cout << "  const_cast baca: " << *cptr << endl;
        // Modifikasi const asli = UB, tapi cast non-const bisa untuk panggil API lama
    }

    // -------------------------------------------------------
    // 7. THIS POINTER (preview via Counter)
    // -------------------------------------------------------
    cout << "\n=== 7. This Pointer Preview ===" << endl;
    {
        Counter c(5);
        c.cetak();

        // Method chaining via return *this
        c.naik().naik().naik().turun();
        c.cetak();

        // Dua objek berbeda, this menunjuk ke masing-masing
        Counter c1(0), c2(10);
        c1.naik().naik();
        c2.turun().turun().turun();
        cout << "  c1: "; c1.cetak();
        cout << "  c2: "; c2.cetak();
    }

    return 0;
}

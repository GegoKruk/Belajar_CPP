#include <iostream>
#include <string>
#include <new>
using namespace std;

struct Titik {
    double x, y;
    Titik(double x, double y) : x(x), y(y) {}
};

struct Mahasiswa {
    string nama;
    int    nim;
    double ipk;
};

void cetakTitik(const Titik* t, const string& label) {
    cout << "  " << label << ": (" << t->x << ", " << t->y << ")" << endl;
}

int main() {

    // -------------------------------------------------------
    // ALOKASI TIPE PRIMITIF
    // -------------------------------------------------------
    cout << "=== Alokasi Primitif ===" << endl;

    int*    pi  = new int;          // tidak diinisialisasi (garbage)
    int*    pj  = new int();        // value-initialized: 0
    int*    pk  = new int(42);      // inisialisasi dengan 42
    double* pd  = new double(3.14);
    bool*   pb  = new bool(true);
    char*   pc  = new char('A');

    cout << "  *pj (value-init) = " << *pj << endl;
    cout << "  *pk = " << *pk << endl;
    cout << "  *pd = " << *pd << endl;
    cout << "  *pb = " << *pb << endl;
    cout << "  *pc = " << *pc << endl;

    delete pi;  pi = nullptr;
    delete pj;  pj = nullptr;
    delete pk;  pk = nullptr;
    delete pd;  pd = nullptr;
    delete pb;  pb = nullptr;
    delete pc;  pc = nullptr;

    // -------------------------------------------------------
    // ALOKASI STRUCT
    // -------------------------------------------------------
    cout << "\n=== Alokasi Struct ===" << endl;

    Titik* t1 = new Titik(3.0, 4.0);
    Titik* t2 = new Titik(0.0, 0.0);

    cetakTitik(t1, "t1");
    cetakTitik(t2, "t2");

    // Modifikasi via pointer arrow operator
    t2->x = 6.5;
    t2->y = 2.5;
    cetakTitik(t2, "t2 setelah modifikasi");

    delete t1; t1 = nullptr;
    delete t2; t2 = nullptr;

    // -------------------------------------------------------
    // ALOKASI STRUCT TANPA CONSTRUCTOR
    // -------------------------------------------------------
    cout << "\n=== Alokasi Struct (tanpa constructor) ===" << endl;

    Mahasiswa* mhs = new Mahasiswa;
    mhs->nama = "Budi Santoso";
    mhs->nim  = 202312345;
    mhs->ipk  = 3.87;

    cout << "  Nama : " << mhs->nama << endl;
    cout << "  NIM  : " << mhs->nim  << endl;
    cout << "  IPK  : " << mhs->ipk  << endl;

    delete mhs; mhs = nullptr;

    // -------------------------------------------------------
    // ALOKASI ARRAY (new[])
    // -------------------------------------------------------
    cout << "\n=== Alokasi Array ===" << endl;

    int  n    = 5;
    int* arr  = new int[n];         // tanpa inisialisasi
    int* arr2 = new int[n]();       // value-initialized: semua 0
    int* arr3 = new int[5]{1,2,3,4,5};  // inisialisasi langsung

    for (int i = 0; i < n; i++) arr[i] = i * i;

    cout << "  arr  (kuadrat): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "  arr2 (nol)    : ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;

    cout << "  arr3 (literal): ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;

    delete[] arr;  arr  = nullptr;
    delete[] arr2; arr2 = nullptr;
    delete[] arr3; arr3 = nullptr;

    // -------------------------------------------------------
    // NULLPTR CHECK SETELAH DELETE
    // -------------------------------------------------------
    cout << "\n=== nullptr Check ===" << endl;

    int* p = new int(55);
    cout << "  sebelum delete: p = " << p << ", *p = " << *p << endl;

    delete p;
    p = nullptr;

    cout << "  setelah delete: p = " << p << endl;
    if (p == nullptr) {
        cout << "  pointer sudah aman (nullptr)" << endl;
    }

    // -------------------------------------------------------
    // PENANGANAN GAGAL ALOKASI (bad_alloc)
    // -------------------------------------------------------
    cout << "\n=== Penanganan bad_alloc ===" << endl;

    try {
        // Minta memory sangat besar agar bisa gagal
        long long jumlah = 2000000000LL;
        int* besar = new int[jumlah];
        // Jika berhasil (jarang), hapus segera
        delete[] besar;
        cout << "  Alokasi besar berhasil (tidak terduga)" << endl;
    } catch (const bad_alloc& e) {
        cout << "  Gagal alokasi: " << e.what() << endl;
        cout << "  (Ini normal -- memory tidak cukup)" << endl;
    }

    // -------------------------------------------------------
    // NOTHROW new: TIDAK THROW, KEMBALIKAN nullptr
    // -------------------------------------------------------
    cout << "\n=== nothrow new ===" << endl;

    long long jumlahBesar = 2000000000LL;
    int* pBesar = new (nothrow) int[jumlahBesar];
    if (pBesar == nullptr) {
        cout << "  Alokasi gagal, pBesar = nullptr (aman, tidak crash)" << endl;
    } else {
        cout << "  Alokasi berhasil" << endl;
        delete[] pBesar;
    }

    // -------------------------------------------------------
    // PERBANDINGAN BIAYA: STACK vs HEAP
    // -------------------------------------------------------
    cout << "\n=== Stack vs Heap ===" << endl;

    int stackVar = 999;           // di stack
    int* heapVar = new int(999);  // di heap

    cout << "  stack var: " << stackVar << " @ " << &stackVar << endl;
    cout << "  heap  var: " << *heapVar << " @ " << heapVar   << endl;
    cout << "  (perhatikan perbedaan kisaran alamat)" << endl;

    delete heapVar; heapVar = nullptr;

    return 0;
}

#include <iostream>
#include <cstring>   // untuk memcpy
using namespace std;

// Fungsi generic (mirip qsort) yang menerima void*
void cetakArray(void* data, int jumlah, int ukuranElemen, void (*cetak)(void*)) {
    char* bytePtr = static_cast<char*>(data);
    for(int i=0; i<jumlah; i++) {
        cetak(bytePtr + i * ukuranElemen);
    }
}

void cetakInt(void* p) {
    cout << *static_cast<int*>(p) << " ";
}

void cetakDouble(void* p) {
    cout << *static_cast<double*>(p) << " ";
}

int main() {
    cout << "=== Void Pointer (void*) ===\n\n";

    // 1. void* dapat menampung alamat berbagai tipe
    int a = 10;
    double b = 3.14159;
    char c = 'X';

    void* vp;
    vp = &a;
    cout << "vp menunjuk int   : " << *static_cast<int*>(vp) << endl;
    vp = &b;
    cout << "vp menunjuk double: " << *static_cast<double*>(vp) << endl;
    vp = &c;
    cout << "vp menunjuk char  : " << *static_cast<char*>(vp) << endl;

    // 2. Tidak bisa dereferensi langsung atau arithmetic
    // cout << *vp;          // ERROR
    // vp++;                 // ERROR (tidak tahu ukuran)

    // 3. Contoh fungsi generic dengan void*
    int arrInt[] = {1,2,3,4,5};
    double arrDouble[] = {1.1, 2.2, 3.3};

    cout << "\nCetak array int via void*: ";
    cetakArray(arrInt, 5, sizeof(int), cetakInt);
    cout << endl;

    cout << "Cetak array double via void*: ";
    cetakArray(arrDouble, 3, sizeof(double), cetakDouble);
    cout << endl;

    // 4. memcpy menggunakan void* (contoh standard library)
    int src[] = {100,200,300};
    int dst[3];
    memcpy(dst, src, sizeof(src));

    cout << "\nSetelah memcpy (void*): ";
    for(int i=0; i<3; i++) cout << dst[i] << " ";
    cout << endl;

    // 5. Hati-hati: cast ke tipe yang salah -> UB
    double d = 99.99;
    void* v = &d;
    int* iptr = static_cast<int*>(v);
    cout << "\nCast void* ke int* (salah): " << *iptr << " (nilai tidak berarti)" << endl;
    // Ini undefined behavior, hasilnya tidak terduga

    // 6. C++ modern: lebih baik hindari void* kecuali untuk low-level
    cout << "\nCatatan: void* berguna untuk interoperasi dengan C dan low-level memory.\n";

    return 0;
}
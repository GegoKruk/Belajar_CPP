#include <iostream>
using namespace std;

class Base {
public:
    virtual void cetak() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    void cetak() override { cout << "Derived" << endl; }
    void fungsiKhusus() { cout << "Fungsi khusus Derived" << endl; }
};

int main() {
    cout << "=== Pointer Casting di C++ ===\n\n";

    // 1. static_cast - untuk konversi yang relatif aman
    int x = 65;
    void* vp = &x;
    int* ip = static_cast<int*>(vp);
    cout << "static_cast: *ip = " << *ip << endl;

    // Konversi antar pointer dalam hirarki (upcast)
    Derived d;
    Base* basePtr = static_cast<Base*>(&d);   // upcast aman
    basePtr->cetak();  // tetap memanggil Derived::cetak (polimorfik)

    // Downcast (tidak aman tanpa dynamic_cast, tapi bisa dilakukan)
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->fungsiKhusus();

    // 2. reinterpret_cast - casting bitwise (berbahaya)
    int angka = 0x41424344;  // 'ABCD' dalam little-endian
    int* pAngka = &angka;
    char* pChar = reinterpret_cast<char*>(pAngka);
    cout << "\nreinterpret_cast: ";
    for(size_t i=0; i<sizeof(int); i++)
        cout << pChar[i] << " ";   // mungkin menampilkan D C B A (tergantung endian)
    cout << "(depend on endianness)" << endl;

    // reinterpret_cast untuk pointer ke integer
    uintptr_t alamat = reinterpret_cast<uintptr_t>(pAngka);
    cout << "Alamat sebagai integer: 0x" << hex << alamat << dec << endl;

    // 3. const_cast - membuang const (HATI-HATI)
    const int konstanta = 100;
    const int* cp = &konstanta;
    int* nonConst = const_cast<int*>(cp);
    // *nonConst = 200;   // UNDEFINED BEHAVIOR! (konstanta sebenarnya const)
    cout << "\nconst_cast: cp menunjuk ke " << *cp << endl;
    cout << "  (mengubah melalui const_cast adalah UB jika objek asli const)" << endl;

    // Kasus yang lebih aman: menghilangkan const dari parameter yang sebenarnya bukan const
    int bisaDiubah = 50;
    const int* cp2 = &bisaDiubah;
    int* p2 = const_cast<int*>(cp2);
    *p2 = 99;
    cout << "  Setelah const_cast (aman): bisaDiubah = " << bisaDiubah << endl;

    // 4. C-style cast (tidak disarankan)
    double dbl = 3.14;
    int* badCast = (int*)&dbl;
    cout << "\nC-style cast: " << *badCast << " (hasil tidak berarti)" << endl;

    // 5. Rekomendasi penggunaan
    cout << "\n=== Rekomendasi Casting ===\n";
    cout << "- static_cast   : konversi antar tipe terkait, void* ke tipe\n";
    cout << "- reinterpret_cast : hanya untuk low-level / driver\n";
    cout << "- const_cast    : hindari, desain ulang kode\n";
    cout << "- C-style cast  : JANGAN PAKAI di C++ modern\n";

    return 0;
}
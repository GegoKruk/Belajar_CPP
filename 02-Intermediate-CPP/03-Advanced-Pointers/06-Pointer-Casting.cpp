#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdint>
using namespace std;

// ================================================================
// HIERARKI CLASS UNTUK DEMO dynamic_cast
// ================================================================
class Hewan {
public:
    string nama;
    explicit Hewan(const string& n) : nama(n) {}
    virtual void bersuara() const { cout << "  " << nama << ": ..." << endl; }
    virtual ~Hewan() = default;
};

class Kucing : public Hewan {
public:
    explicit Kucing(const string& n) : Hewan(n) {}
    void bersuara() const override { cout << "  " << nama << ": Meow!" << endl; }
    void menjilat()          const { cout << "  " << nama << " menjilat kaki." << endl; }
};

class Anjing : public Hewan {
public:
    explicit Anjing(const string& n) : Hewan(n) {}
    void bersuara() const override { cout << "  " << nama << ": Woof!" << endl; }
    void menggonggong()      const { cout << "  " << nama << " menggonggong keras!" << endl; }
};

class Ikan : public Hewan {
public:
    explicit Ikan(const string& n) : Hewan(n) {}
    void bersuara() const override { cout << "  " << nama << ": blub blub" << endl; }
};

// ================================================================
// HELPER
// ================================================================
void garis(const string& label) {
    cout << "\n=== " << label << " ===" << endl;
}

// ================================================================
// DEMO static_cast
// ================================================================
void demo_static_cast() {
    garis("static_cast");

    // a. Konversi numerik
    cout << "  -- Konversi Numerik --" << endl;
    double d = 9.87654;
    int    i = static_cast<int>(d);
    cout << "  double 9.87654 -> int: " << i << endl;

    int  angka = 7;
    double rasio = static_cast<double>(angka) / 2;
    cout << "  7 / 2 tanpa cast : " << angka / 2     << " (integer division)" << endl;
    cout << "  7 / 2 dengan cast: " << rasio          << " (double division)"  << endl;

    float  f  = 3.14f;
    long   l  = static_cast<long>(f);
    cout << "  float 3.14 -> long: " << l << endl;

    // b. Konversi enum ke int
    cout << "  -- Enum ke int --" << endl;
    enum class Warna { Merah = 0, Hijau = 1, Biru = 2 };
    Warna w = Warna::Hijau;
    int   kode = static_cast<int>(w);
    cout << "  Warna::Hijau -> int: " << kode << endl;
    Warna kembali = static_cast<Warna>(2);
    cout << "  int 2 -> Warna (Biru = 2): "
         << (kembali == Warna::Biru ? "benar" : "salah") << endl;

    // c. void* ke tipe konkret
    cout << "  -- void* ke konkret --" << endl;
    int    x   = 123;
    void*  vp  = &x;
    int*   ip  = static_cast<int*>(vp);
    cout << "  void* -> int*: " << *ip << endl;

    // d. Upcast (Derived -> Base) -- selalu aman
    cout << "  -- Upcast (Derived -> Base) --" << endl;
    Kucing* k  = new Kucing("Mimi");
    Hewan*  h  = static_cast<Hewan*>(k);   // upcast: selalu aman
    h->bersuara();
    delete k;
}

// ================================================================
// DEMO reinterpret_cast
// ================================================================
void demo_reinterpret_cast() {
    garis("reinterpret_cast");

    // a. Baca representasi bit integer
    cout << "  -- Bit Representasi --" << endl;
    unsigned int val = 0x41424344;   // ASCII: DCBA (little-endian)
    char* cp = reinterpret_cast<char*>(&val);
    cout << "  0x41424344 sebagai char[]: ";
    for (int i = 0; i < 4; i++) cout << "'" << cp[i] << "' ";
    cout << endl;

    // b. Konversi pointer ke uintptr_t dan kembali
    cout << "  -- Pointer <-> uintptr_t --" << endl;
    int   angka  = 777;
    int*  ptr    = &angka;
    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    int*      kembali = reinterpret_cast<int*>(addr);
    cout << "  int* -> uintptr_t -> int*: *kembali = " << *kembali << endl;
    cout << "  ptr == kembali: " << (ptr == kembali ? "Ya" : "Tidak") << endl;

    // c. Reinterpretasi float sebagai int (melihat bit raw)
    cout << "  -- Float bit pattern --" << endl;
    float  f      = 1.0f;
    int*   fAsInt = reinterpret_cast<int*>(&f);
    cout << "  float 1.0f bit pattern (hex): 0x";
    cout << hex << *fAsInt << dec << endl;
    cout << "  (IEEE 754: 0x3F800000 = 1.0f)" << endl;

    // d. char* ke unsigned char* (aman, TIDAK ubah data)
    cout << "  -- char* ke unsigned char* --" << endl;
    char bytes[] = { -1, 0, 127, -128 };
    unsigned char* ub = reinterpret_cast<unsigned char*>(bytes);
    cout << "  signed  : ";
    for (int i = 0; i < 4; i++) cout << (int)bytes[i] << " ";
    cout << endl;
    cout << "  unsigned: ";
    for (int i = 0; i < 4; i++) cout << (int)ub[i] << " ";
    cout << endl;
}

// ================================================================
// DEMO const_cast
// ================================================================
void cetakPesan(char* msg) {   // API lama: minta non-const
    cout << "  " << msg << endl;
}

void demo_const_cast() {
    garis("const_cast");

    // a. Hapus const untuk memanggil API lama
    cout << "  -- Hapus const untuk API lama --" << endl;
    const char* pesan = "Halo dari const char*";
    // cetakPesan(pesan);   // ERROR: tidak bisa const -> non-const implisit
    cetakPesan(const_cast<char*>(pesan));  // OK: cast eksplisit
    cout << "  (tidak memodifikasi -- hanya baca)" << endl;

    // b. Tambah const (sebenarnya implicit, tapi bisa eksplisit)
    cout << "  -- Tambah const --" << endl;
    int  x    = 42;
    int* p    = &x;
    const int* cp = const_cast<const int*>(p);  // tambah const
    cout << "  int* -> const int*: *cp = " << *cp << endl;
    // *cp = 10;   // ERROR: cp adalah const int*

    // c. Modifikasi melalui const_cast (BERBAHAYA -- hanya jika objek asli non-const)
    cout << "  -- Modifikasi via const_cast (hati-hati) --" << endl;
    int  mutable_x     = 100;
    const int* cptr    = &mutable_x;         // pointer const ke non-const int
    int*       modptr  = const_cast<int*>(cptr);
    *modptr = 200;  // AMAN: mutable_x memang non-const
    cout << "  mutable_x setelah modifikasi: " << mutable_x << endl;

    // JANGAN LAKUKAN ini -- undefined behavior:
    // const int immutable = 99;
    // int* danger = const_cast<int*>(&immutable);
    // *danger = 0;  // UNDEFINED BEHAVIOR! immutable mungkin di read-only memory

    // d. Pola idiomatis: non-const dari const overload
    cout << "  -- Pola const/non-const overload --" << endl;
    cout << "  (Biasanya dipakai dalam implementasi class, preview saja)" << endl;
}

// ================================================================
// DEMO dynamic_cast
// ================================================================
void demo_dynamic_cast() {
    garis("dynamic_cast");

    Hewan* hewan[] = {
        new Kucing("Mimi"),
        new Anjing("Rex"),
        new Ikan("Nemo"),
        new Kucing("Luna"),
        new Anjing("Buddy"),
    };
    int n = 5;

    // a. Downcast aman: Hewan* -> Kucing* atau Anjing*
    cout << "  -- Downcast dengan cek runtime --" << endl;
    for (int i = 0; i < n; i++) {
        Kucing* k = dynamic_cast<Kucing*>(hewan[i]);
        Anjing* a = dynamic_cast<Anjing*>(hewan[i]);

        if (k) {
            cout << "  Kucing ditemukan: "; k->menjilat();
        } else if (a) {
            cout << "  Anjing ditemukan: "; a->menggonggong();
        } else {
            cout << "  " << hewan[i]->nama << ": bukan Kucing maupun Anjing" << endl;
        }
    }

    // b. Polimorfisme -- virtual dispatch lewat Hewan*
    cout << "\n  -- Polimorfisme via Hewan* --" << endl;
    for (int i = 0; i < n; i++) hewan[i]->bersuara();

    // c. dynamic_cast pada pointer: gagal -> nullptr (aman)
    cout << "\n  -- dynamic_cast gagal: kembali nullptr --" << endl;
    Hewan*  h    = new Ikan("Dori");
    Kucing* bukan = dynamic_cast<Kucing*>(h);
    cout << "  Ikan di-cast ke Kucing*: "
         << (bukan == nullptr ? "nullptr (gagal -- aman)" : "berhasil") << endl;
    delete h;

    for (int i = 0; i < n; i++) delete hewan[i];
}

// ================================================================
// PERBANDINGAN: C-STYLE CAST vs C++ CAST
// ================================================================
void demo_cstyle_vs_cpp() {
    garis("C-style cast vs C++ cast");

    double d = 7.99;

    // C-style (hindari -- tidak jelas apa yang dilakukan)
    int i1 = (int)d;
    cout << "  C-style cast: (int)7.99 = " << i1 << endl;

    // C++ style (lebih eksplisit, niat lebih jelas)
    int i2 = static_cast<int>(d);
    cout << "  C++ cast    : static_cast<int>(7.99) = " << i2 << endl;

    cout << "\n  Keunggulan C++ cast:" << endl;
    cout << "  - Lebih mudah dicari (grep 'static_cast' vs grep '(')" << endl;
    cout << "  - Menunjukkan NIAT programmer dengan jelas" << endl;
    cout << "  - Compiler verifikasi sesuai jenis cast" << endl;
    cout << "  - static_cast dan dynamic_cast lebih aman dari C-style" << endl;
}

int main() {
    demo_static_cast();
    demo_reinterpret_cast();
    demo_const_cast();
    demo_dynamic_cast();
    demo_cstyle_vs_cpp();

    garis("Panduan Memilih Cast");
    cout << "  static_cast       : konversi numerik, void*, upcast/downcast tanpa cek" << endl;
    cout << "  dynamic_cast      : downcast AMAN dengan cek runtime (butuh virtual)" << endl;
    cout << "  const_cast        : tambah atau hapus const/volatile qualifier" << endl;
    cout << "  reinterpret_cast  : reinterpretasi bit mentah -- gunakan sesedikit mungkin" << endl;
    cout << "  C-style (T)x      : HINDARI -- ambigu, tidak aman, susah di-grep" << endl;

    return 0;
}

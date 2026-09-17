#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

// ================================================================
// FUNGSI GENERIK MENGGUNAKAN void* (gaya C standard library)
// ================================================================

// Cetak bytes dari alamat manapun (seperti hexdump sederhana)
void cetakBytes(const void* ptr, size_t n, const string& label) {
    const unsigned char* bytes = static_cast<const unsigned char*>(ptr);
    cout << "  " << label << " bytes: ";
    for (size_t i = 0; i < n; i++) {
        cout << (int)bytes[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

// Fungsi swap generik -- seperti memswap
void swapGenerik(void* a, void* b, size_t ukuran) {
    unsigned char* pa = static_cast<unsigned char*>(a);
    unsigned char* pb = static_cast<unsigned char*>(b);
    for (size_t i = 0; i < ukuran; i++) {
        unsigned char tmp = pa[i];
        pa[i] = pb[i];
        pb[i] = tmp;
    }
}

// Isi semua byte dengan satu nilai -- seperti memset
void isiBytes(void* ptr, unsigned char nilai, size_t n) {
    unsigned char* p = static_cast<unsigned char*>(ptr);
    for (size_t i = 0; i < n; i++) p[i] = nilai;
}

// Salin blok memori -- seperti memcpy sederhana
void salinMemori(void* dst, const void* src, size_t n) {
    unsigned char*       pd = static_cast<unsigned char*>(dst);
    const unsigned char* ps = static_cast<const unsigned char*>(src);
    for (size_t i = 0; i < n; i++) pd[i] = ps[i];
}

// ================================================================
// CONTEXT POINTER PATTERN
// Meneruskan data arbitrer ke callback tanpa tahu tipenya
// ================================================================
struct KonteksSorter {
    bool descending;
    int  batasMin;
};

void prosesArray(int* arr, int n,
                 bool (*callback)(int, void*),
                 void* context) {
    cout << "  elemen yang lolos filter: ";
    for (int i = 0; i < n; i++) {
        if (callback(arr[i], context)) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

bool filterDenganKonteks(int nilai, void* ctx) {
    KonteksSorter* k = static_cast<KonteksSorter*>(ctx);
    return nilai > k->batasMin;
}

// ================================================================
// KOMPARATOR UNTUK qsort (C standard library)
// qsort memakai void* karena generik untuk semua tipe
// ================================================================
int bandingInt(const void* a, const void* b) {
    int ia = *static_cast<const int*>(a);
    int ib = *static_cast<const int*>(b);
    return (ia > ib) - (ia < ib);   // -1, 0, atau 1
}

int bandingIntDesc(const void* a, const void* b) {
    return bandingInt(b, a);         // balik urutan untuk descending
}

int bandingDouble(const void* a, const void* b) {
    double da = *static_cast<const double*>(a);
    double db = *static_cast<const double*>(b);
    if (da < db) return -1;
    if (da > db) return  1;
    return 0;
}

// ================================================================
// GENERIC STACK SEDERHANA BERBASIS void*
// (gaya implementasi C -- sebelum template ada)
// ================================================================
struct VoidStack {
    void** data;
    int    top;
    int    kapasitas;

    void init(int k) {
        data      = new void*[k];
        top       = 0;
        kapasitas = k;
    }
    void destroy() { delete[] data; data = nullptr; }

    bool push(void* item) {
        if (top >= kapasitas) return false;
        data[top++] = item;
        return true;
    }
    void* pop() {
        if (top <= 0) return nullptr;
        return data[--top];
    }
    void* peek() const {
        if (top <= 0) return nullptr;
        return data[top - 1];
    }
    bool kosong() const { return top == 0; }
    int  ukuran() const { return top; }
};

void cetakArr(const int arr[], int n) {
    cout << "  [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    // -------------------------------------------------------
    // DASAR: VOID POINTER MENYIMPAN BERBAGAI TIPE
    // -------------------------------------------------------
    cout << "=== Dasar: void* Menyimpan Berbagai Tipe ===" << endl;
    {
        int    angka   = 42;
        double desimal = 3.14;
        char   huruf   = 'X';
        string teks    = "Halo";

        void* vp;

        vp = &angka;
        cout << "  angka   via void*: " << *static_cast<int*>(vp)    << endl;

        vp = &desimal;
        cout << "  desimal via void*: " << *static_cast<double*>(vp) << endl;

        vp = &huruf;
        cout << "  huruf   via void*: " << *static_cast<char*>(vp)   << endl;

        // String tidak di-cast via void*, pointer ke string-nya
        string* sp = &teks;
        vp = sp;
        cout << "  teks    via void*: " << *static_cast<string*>(vp) << endl;
    }

    // -------------------------------------------------------
    // INSPEKSI BYTES
    // -------------------------------------------------------
    cout << "\n=== Inspeksi Bytes via void* ===" << endl;
    {
        int    i32  = 0x01020304;
        float  f32  = 1.0f;
        double f64  = 1.0;
        char   c4[] = "ABC";

        cetakBytes(&i32, sizeof(i32), "int    0x01020304");
        cetakBytes(&f32, sizeof(f32), "float  1.0f      ");
        cetakBytes(&f64, sizeof(f64), "double 1.0       ");
        cetakBytes(c4,   4,           "char[] \"ABC\\0\"   ");
    }

    // -------------------------------------------------------
    // SWAP GENERIK
    // -------------------------------------------------------
    cout << "\n=== Swap Generik via void* ===" << endl;
    {
        int    a = 111, b = 222;
        double x = 1.5, y = 9.9;

        cout << "  sebelum: a=" << a << " b=" << b << endl;
        swapGenerik(&a, &b, sizeof(int));
        cout << "  sesudah: a=" << a << " b=" << b << endl;

        cout << "  sebelum: x=" << x << " y=" << y << endl;
        swapGenerik(&x, &y, sizeof(double));
        cout << "  sesudah: x=" << x << " y=" << y << endl;
    }

    // -------------------------------------------------------
    // qsort DARI C STANDARD LIBRARY (menggunakan void*)
    // -------------------------------------------------------
    cout << "\n=== qsort dengan void* Komparator ===" << endl;
    {
        int angka[] = { 5, 2, 9, 1, 7, 3, 8, 4, 6 };
        int n = 9;

        cout << "  sebelum: "; cetakArr(angka, n);
        qsort(angka, n, sizeof(int), bandingInt);
        cout << "  asc    : "; cetakArr(angka, n);
        qsort(angka, n, sizeof(int), bandingIntDesc);
        cout << "  desc   : "; cetakArr(angka, n);

        double dbl[] = { 3.5, 1.2, 8.9, 0.7, 5.1 };
        int    m = 5;
        cout << "  double sebelum: ";
        for (int i = 0; i < m; i++) cout << dbl[i] << " "; cout << endl;
        qsort(dbl, m, sizeof(double), bandingDouble);
        cout << "  double sesudah: ";
        for (int i = 0; i < m; i++) cout << dbl[i] << " "; cout << endl;
    }

    // -------------------------------------------------------
    // CONTEXT POINTER PATTERN
    // -------------------------------------------------------
    cout << "\n=== Context Pointer Pattern ===" << endl;
    {
        int data[] = { -3, 5, 12, -8, 7, 0, 15, -1, 9 };
        int n = 9;

        KonteksSorter k1 = { false, 0  };
        KonteksSorter k2 = { false, 5  };
        KonteksSorter k3 = { false, 10 };

        cout << "  data  : "; cetakArr(data, n);
        prosesArray(data, n, filterDenganKonteks, &k1);    // > 0
        prosesArray(data, n, filterDenganKonteks, &k2);    // > 5
        prosesArray(data, n, filterDenganKonteks, &k3);    // > 10
    }

    // -------------------------------------------------------
    // VOID STACK GENERIK
    // -------------------------------------------------------
    cout << "\n=== Void* Stack (Generic) ===" << endl;
    {
        VoidStack stk;
        stk.init(10);

        int  a = 10, b = 20, c = 30;
        double d = 3.14;
        string s = "halo";

        // Push berbagai tipe
        stk.push(&a);
        stk.push(&b);
        stk.push(&c);
        stk.push(&d);
        stk.push(&s);

        cout << "  ukuran stack: " << stk.ukuran() << endl;

        // Pop -- caller harus tahu tipe yang di-push!
        string* ps = static_cast<string*>(stk.pop());
        double* pd = static_cast<double*>(stk.pop());
        int*    pi = static_cast<int*>(stk.pop());

        cout << "  pop string : " << *ps << endl;
        cout << "  pop double : " << *pd << endl;
        cout << "  pop int    : " << *pi << endl;

        stk.destroy();
    }

    // -------------------------------------------------------
    // SALIN MEMORI GENERIK
    // -------------------------------------------------------
    cout << "\n=== Salin Memori Generik (seperti memcpy) ===" << endl;
    {
        double src[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        double dst[5] = {};

        salinMemori(dst, src, sizeof(src));

        cout << "  src: ";
        for (double x : src) cout << x << " "; cout << endl;
        cout << "  dst: ";
        for (double x : dst) cout << x << " "; cout << endl;
    }

    cout << "\n=== Catatan Penting ===" << endl;
    cout << "  void* : generik tapi tidak type-safe" << endl;
    cout << "  Pakai : interop C API, low-level memory, context pointer" << endl;
    cout << "  Hindari: kode baru C++ -- gunakan template sebagai gantinya!" << endl;

    return 0;
}

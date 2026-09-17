#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// -------------------------------------------------------
// RAII WRAPPER SEDERHANA (preview konsep utama modul ini)
// -------------------------------------------------------
class IntArray {
    int* data;
    int  n;
public:
    IntArray(int ukuran) : n(ukuran), data(new int[ukuran]()) {}
    ~IntArray() { delete[] data; }

    int& operator[](int i)       { return data[i]; }
    int  operator[](int i) const { return data[i]; }
    int  size()            const { return n; }

    IntArray(const IntArray&)            = delete;
    IntArray& operator=(const IntArray&) = delete;
};

void cetakArray(const int* arr, int n, const string& label) {
    cout << "  " << label << ": [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    // -------------------------------------------------------
    // 1. STACK vs HEAP
    // -------------------------------------------------------
    cout << "=== 1. Stack vs Heap ===" << endl;
    {
        int stackVar = 42;              // di stack -- otomatis
        int* heapVar = new int(42);     // di heap  -- manual

        cout << "  stack : " << stackVar  << " (alamat: " << &stackVar << ")" << endl;
        cout << "  heap  : " << *heapVar  << " (alamat: " << heapVar   << ")" << endl;

        delete heapVar;
        heapVar = nullptr;
    }   // stackVar otomatis terhapus di sini

    // -------------------------------------------------------
    // 2. new / delete DASAR
    // -------------------------------------------------------
    cout << "\n=== 2. new / delete Dasar ===" << endl;
    {
        int*    pi = new int(99);
        double* pd = new double(3.14);
        string* ps = new string("C++ Dynamic Memory");

        cout << "  *pi = " << *pi << endl;
        cout << "  *pd = " << *pd << endl;
        cout << "  *ps = " << *ps << endl;

        delete pi; pi = nullptr;
        delete pd; pd = nullptr;
        delete ps; ps = nullptr;
    }

    // -------------------------------------------------------
    // 3. DYNAMIC ARRAY (ukuran saat runtime)
    // -------------------------------------------------------
    cout << "\n=== 3. Dynamic Array (ukuran runtime) ===" << endl;
    {
        int n = 6;
        int* arr = new int[n];

        for (int i = 0; i < n; i++) arr[i] = (i + 1) * 10;
        cetakArray(arr, n, "arr");

        delete[] arr;
        arr = nullptr;
    }

    // -------------------------------------------------------
    // 4. MEMORY LEAK (dikomentari -- ilustrasi saja)
    // -------------------------------------------------------
    cout << "\n=== 4. Memory Leak (ilustrasi) ===" << endl;
    cout << "  [LEAK]  int* p = new int(5); -- lupa delete p!" << endl;
    cout << "  [AMAN]  selalu pasangkan new dengan delete"     << endl;

    // -------------------------------------------------------
    // 5. DANGLING POINTER
    // -------------------------------------------------------
    cout << "\n=== 5. Dangling Pointer (pencegahan) ===" << endl;
    {
        int* p = new int(77);
        cout << "  sebelum delete: *p = " << *p << endl;

        delete p;
        p = nullptr;   // cegah dangling pointer

        if (p == nullptr) {
            cout << "  setelah delete: p = nullptr (aman)" << endl;
        }
    }

    // -------------------------------------------------------
    // 6. RAII (pembersihan otomatis via destructor)
    // -------------------------------------------------------
    cout << "\n=== 6. RAII Wrapper ===" << endl;
    {
        IntArray arr(5);
        for (int i = 0; i < arr.size(); i++) arr[i] = (i + 1) * 5;

        cout << "  isi array RAII: [";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        cout << "  destructor akan dipanggil otomatis saat keluar scope" << endl;
    }   // delete[] otomatis di sini -- tidak ada leak!

    // -------------------------------------------------------
    // 7. SMART POINTER (preview -- detail di file 06)
    // -------------------------------------------------------
    cout << "\n=== 7. Smart Pointer Preview ===" << endl;
    {
        // unique_ptr: satu pemilik, auto-delete
        auto up = make_unique<int>(100);
        cout << "  unique_ptr: " << *up << endl;

        // shared_ptr: kepemilikan bersama
        auto sp1 = make_shared<string>("shared!");
        auto sp2 = sp1;    // dua pointer ke objek sama
        cout << "  shared_ptr: '" << *sp1 << "' (count=" << sp1.use_count() << ")" << endl;
    }   // keduanya auto-delete

    // -------------------------------------------------------
    // 8. DYNAMIC vs CONTAINER (std::vector)
    // -------------------------------------------------------
    cout << "\n=== 8. Dynamic Array vs vector ===" << endl;
    {
        int n = 4;

        // Manual (raw)
        int* raw = new int[n]{10, 20, 30, 40};
        cetakArray(raw, n, "raw ");
        delete[] raw;

        // Modern (vector -- recommended)
        vector<int> v = {10, 20, 30, 40};
        cout << "  vec : [";
        for (int i = 0; i < (int)v.size(); i++) {
            cout << v[i];
            if (i < (int)v.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        // tidak perlu delete -- vector urus sendiri
    }

    return 0;
}

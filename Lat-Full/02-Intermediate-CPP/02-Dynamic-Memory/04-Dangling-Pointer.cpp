#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// SITUASI 1: USE-AFTER-FREE
// Akses pointer setelah memory dibebaskan
// -------------------------------------------------------
void demo_use_after_free() {
    cout << "  --- Use-After-Free ---" << endl;

    int* p = new int(100);
    cout << "  sebelum delete: *p = " << *p << endl;

    delete p;
    // p sekarang dangling -- jangan akses!
    // cout << *p;   // UNDEFINED BEHAVIOR: dikomentari untuk keamanan

    // SOLUSI: langsung set nullptr setelah delete
    p = nullptr;

    if (p == nullptr) {
        cout << "  setelah delete+nullptr: akses dicegah (p == nullptr)" << endl;
    }
}

// -------------------------------------------------------
// SITUASI 2: POINTER KE VARIABEL LOKAL YANG SUDAH MATI
// -------------------------------------------------------
int* ambildPointerLokal_SALAH() {
    int x = 42;
    return &x;   // BAHAYA: x mati saat function selesai!
}

int* ambilDariHeap_BENAR() {
    int* p = new int(42);   // di heap -- tetap hidup setelah function selesai
    return p;               // caller bertanggung jawab delete
}

// -------------------------------------------------------
// SITUASI 3: ALIASING -- DUA POINTER KE OBJEK SAMA
// -------------------------------------------------------
void demo_aliasing() {
    cout << "  --- Aliasing (dua pointer ke objek sama) ---" << endl;

    int* p = new int(77);
    int* q = p;             // q dan p menunjuk ke tempat yang SAMA

    cout << "  p = " << p << " | *p = " << *p << endl;
    cout << "  q = " << q << " | *q = " << *q << endl;

    delete p;
    p = nullptr;
    // q sekarang dangling! q masih menyimpan alamat lama
    // cout << *q;  // UNDEFINED BEHAVIOR -- dikomentari

    // SOLUSI: sinkronkan semua pointer yang aliasing
    q = nullptr;
    cout << "  setelah delete p: p dan q di-set nullptr (aman)" << endl;
}

// -------------------------------------------------------
// SITUASI 4: POINTER DALAM STRUCT (SHALLOW COPY HAZARD)
// -------------------------------------------------------
struct Buffer {
    int* data;
    int  n;

    Buffer(int ukuran) : n(ukuran) {
        data = new int[ukuran]();
    }

    // DESTRUCTOR YANG BENAR
    ~Buffer() {
        delete[] data;
        data = nullptr;
    }

    // Disable copy untuk mencegah dangling pointer dari shallow copy
    Buffer(const Buffer&)            = delete;
    Buffer& operator=(const Buffer&) = delete;
};

void demo_struct_pointer() {
    cout << "  --- Pointer di dalam Struct ---" << endl;

    Buffer buf(5);
    for (int i = 0; i < buf.n; i++) buf.data[i] = i * 3;

    cout << "  isi buffer: ";
    for (int i = 0; i < buf.n; i++) cout << buf.data[i] << " ";
    cout << endl;

    // Shallow copy BERBAHAYA (karena copy dinonaktifkan, ini akan error compile)
    // Buffer salin = buf;   // ERROR -- sengaja diblokir via delete

    cout << "  copy diblokir -- mencegah dangling pointer dari shallow copy" << endl;
}

// -------------------------------------------------------
// SITUASI 5: DANGLING REFERENCE (bukan pointer, tapi konsep sama)
// -------------------------------------------------------
const int& ambilReferensiLokal_SALAH() {
    int x = 55;
    return x;   // BAHAYA: referensi ke variabel lokal yang akan mati
}

// -------------------------------------------------------
// DEMONSTRASI PERBAIKAN SISTEMATIS
// -------------------------------------------------------
void demo_checklist_pencegahan() {
    cout << "\n  --- Checklist Pencegahan Dangling Pointer ---" << endl;

    // 1. Langsung nullptr setelah delete
    int* a = new int(1);
    delete a;
    a = nullptr;
    cout << "  [1] delete lalu nullptr: " << (a == nullptr ? "OK" : "FAIL") << endl;

    // 2. Guard sebelum akses
    int* b = nullptr;
    if (b != nullptr) *b = 99;   // tidak dieksekusi -- aman
    else cout << "  [2] guard nullptr: akses dicegah (OK)" << endl;

    // 3. Hindari simpan alamat variabel lokal di luar scope-nya
    int* c = ambilDariHeap_BENAR();
    cout << "  [3] dari heap: *c = " << *c << " (OK)" << endl;
    delete c;
    c = nullptr;

    // 4. Satu pemilik jelas -- gunakan smart pointer
    cout << "  [4] gunakan smart pointer di kode nyata (dibahas di file 06)" << endl;
}

// -------------------------------------------------------
// DOUBLE FREE: MENGHAPUS POINTER DUA KALI
// -------------------------------------------------------
void demo_cegah_double_free() {
    cout << "\n  --- Cegah Double Free ---" << endl;

    int* p = new int(33);

    // CARA SALAH (jangan dilakukan):
    // delete p;
    // delete p;   // CRASH atau undefined behavior!

    // CARA BENAR: set nullptr setelah delete, lalu guard
    delete p;
    p = nullptr;

    if (p != nullptr) {   // false -- tidak akan masuk
        delete p;
    }
    cout << "  double free dicegah via nullptr check (OK)" << endl;
}

int main() {

    cout << "=== Situasi 1: Use-After-Free ===" << endl;
    demo_use_after_free();

    cout << "\n=== Situasi 2: Pointer ke Variabel Lokal ===" << endl;
    {
        // Cara salah: jangan jalankan, perilaku tidak terdefinisi
        // int* bahaya = ambildPointerLokal_SALAH();
        // cout << *bahaya;   // CRASH kemungkinan besar

        int* aman = ambilDariHeap_BENAR();
        cout << "  dari heap: *aman = " << *aman << endl;
        delete aman;
        aman = nullptr;
        cout << "  pointer ke heap aman -- caller bertanggung jawab delete" << endl;
    }

    cout << "\n=== Situasi 3: Aliasing ===" << endl;
    demo_aliasing();

    cout << "\n=== Situasi 4: Pointer dalam Struct ===" << endl;
    demo_struct_pointer();

    cout << "\n=== Pencegahan Sistematis ===" << endl;
    demo_checklist_pencegahan();

    cout << "\n=== Cegah Double Free ===" << endl;
    demo_cegah_double_free();

    // -------------------------------------------------------
    // NULL vs NULLPTR: RINGKASAN
    // -------------------------------------------------------
    cout << "\n=== NULL vs nullptr ===" << endl;

    int* p1 = NULL;     // cara lama (C-style)
    int* p2 = nullptr;  // cara modern (C++11) -- selalu pakai ini!

    cout << "  p1 (NULL)    == nullptr: " << (p1 == nullptr ? "Ya" : "Tidak") << endl;
    cout << "  p2 (nullptr) == nullptr: " << (p2 == nullptr ? "Ya" : "Tidak") << endl;
    cout << "  Selalu gunakan nullptr di C++ modern!" << endl;

    return 0;
}

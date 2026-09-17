#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ================================================================
// RAII WRAPPER 1: INTARRAY -- dynamic array dengan auto cleanup
// ================================================================
class IntArray {
    int* data_;
    int  n_;

public:
    explicit IntArray(int n) : n_(n), data_(new int[n]()) {
        cout << "    [IntArray] alokasi " << n_ << " elemen" << endl;
    }

    ~IntArray() {
        cout << "    [IntArray] dealokasi " << n_ << " elemen" << endl;
        delete[] data_;
        data_ = nullptr;
    }

    // Akses seperti array biasa
    int& operator[](int i)       { return data_[i]; }
    int  operator[](int i) const { return data_[i]; }
    int  size()            const { return n_; }

    // Nonaktifkan copy untuk cegah double-free
    IntArray(const IntArray&)            = delete;
    IntArray& operator=(const IntArray&) = delete;

    // Perbolehkan move
    IntArray(IntArray&& lain) noexcept : n_(lain.n_), data_(lain.data_) {
        lain.data_ = nullptr;
        lain.n_    = 0;
    }
};

// ================================================================
// RAII WRAPPER 2: FILELOGGER -- simulasi resource file
// (tanpa file I/O nyata agar tetap minimal)
// ================================================================
class FileLogger {
    string namaFile_;
    bool   terbuka_;

public:
    explicit FileLogger(const string& nama) : namaFile_(nama), terbuka_(true) {
        cout << "    [FileLogger] BUKA: " << namaFile_ << endl;
    }

    ~FileLogger() {
        if (terbuka_) {
            cout << "    [FileLogger] TUTUP (otomatis): " << namaFile_ << endl;
            terbuka_ = false;
        }
    }

    void tulis(const string& pesan) {
        if (terbuka_)
            cout << "    [FileLogger] LOG >> " << pesan << endl;
    }

    FileLogger(const FileLogger&)            = delete;
    FileLogger& operator=(const FileLogger&) = delete;
};

// ================================================================
// RAII WRAPPER 3: SCOPETIMER -- ukur waktu (simulasi)
// ================================================================
class ScopeTimer {
    string label_;

public:
    explicit ScopeTimer(const string& label) : label_(label) {
        cout << "    [Timer] MULAI: " << label_ << endl;
    }

    ~ScopeTimer() {
        cout << "    [Timer] SELESAI: " << label_ << endl;
    }

    ScopeTimer(const ScopeTimer&)            = delete;
    ScopeTimer& operator=(const ScopeTimer&) = delete;
};

// ================================================================
// RAII WRAPPER 4: TEMPLATE GENERIK -- bisa untuk tipe apapun
// ================================================================
template <typename T>
class AutoPtr {
    T* ptr_;

public:
    explicit AutoPtr(T* p = nullptr) : ptr_(p) {
        if (ptr_) cout << "    [AutoPtr] acquire" << endl;
    }

    ~AutoPtr() {
        if (ptr_) {
            cout << "    [AutoPtr] release" << endl;
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    T& operator*()        { return *ptr_; }
    T* operator->()       { return ptr_;  }
    T* get()        const { return ptr_;  }
    bool valid()    const { return ptr_ != nullptr; }

    // Move semantics -- transfer ownership
    AutoPtr(AutoPtr&& lain) noexcept : ptr_(lain.ptr_) {
        lain.ptr_ = nullptr;
    }

    AutoPtr(const AutoPtr&)            = delete;
    AutoPtr& operator=(const AutoPtr&) = delete;
};

// ================================================================
// DEMONSTRASI 1: RAII vs MANUAL (scope normal)
// ================================================================
void demo_raii_vs_manual_normal() {
    cout << "\n  [Manual] scope normal:" << endl;
    {
        int* p = new int[5]();
        for (int i = 0; i < 5; i++) p[i] = i + 1;
        cout << "    data[4] = " << p[4] << endl;
        delete[] p;   // harus ingat!
        p = nullptr;
        cout << "    manual: delete berhasil" << endl;
    }

    cout << "\n  [RAII]   scope normal:" << endl;
    {
        IntArray arr(5);
        for (int i = 0; i < 5; i++) arr[i] = i + 1;
        cout << "    arr[4]  = " << arr[4] << endl;
    }   // destructor otomatis dipanggil di sini!
}

// ================================================================
// DEMONSTRASI 2: RAII MENYELAMATKAN SAAT EXCEPTION
// ================================================================
void fungsiYangThrow() {
    throw runtime_error("operasi gagal!");
}

void demo_raii_dengan_exception() {
    cout << "\n  [Manual] dengan exception (BERBAHAYA):" << endl;
    {
        int* p = new int[10]();
        try {
            fungsiYangThrow();
            delete[] p;   // TIDAK PERNAH TERCAPAI jika throw!
            p = nullptr;
        } catch (const exception& e) {
            cout << "    exception: " << e.what() << endl;
            cout << "    PERLU ingat delete di catch block!" << endl;
            delete[] p;   // harus delete di sini juga
            p = nullptr;
        }
    }

    cout << "\n  [RAII]   dengan exception (AMAN OTOMATIS):" << endl;
    {
        IntArray arr(10);   // destructor PASTI dipanggil meski exception!
        try {
            fungsiYangThrow();
        } catch (const exception& e) {
            cout << "    exception: " << e.what() << endl;
            cout << "    RAII: tidak perlu manual delete!" << endl;
        }
    }   // destructor dipanggil otomatis BAHKAN saat exception (stack unwinding)
}

// ================================================================
// DEMONSTRASI 3: RAII DENGAN EARLY RETURN
// ================================================================
void proses_dengan_early_return(bool kondisi) {
    IntArray arr(8);
    FileLogger log("proses.log");

    log.tulis("memulai proses");

    if (kondisi) {
        log.tulis("early return -- kondisi terpenuhi");
        return;   // destructor arr DAN log dipanggil otomatis!
    }

    log.tulis("proses selesai normal");
}   // destructor dipanggil di sini jika tidak early return

// ================================================================
// DEMONSTRASI 4: BEBERAPA RESOURCE RAII BERSARANG
// ================================================================
void demo_multiple_resource() {
    cout << "\n  [RAII] Beberapa resource sekaligus:" << endl;

    ScopeTimer timer("operasi_besar");
    {
        IntArray    data(100);
        FileLogger  log("output.log");
        AutoPtr<int> config(new int(42));

        log.tulis("konfigurasi: " + to_string(*config));
        data[0] = 999;
        log.tulis("data[0] = " + to_string(data[0]));

        // Semua destruktor dipanggil terbalik saat keluar scope:
        // config -> log -> data
    }
    // timer destructor dipanggil di sini
}

// ================================================================
// DEMONSTRASI 5: AutoPtr TRANSFER OWNERSHIP (move)
// ================================================================
void demo_transfer_ownership() {
    cout << "\n  [AutoPtr] transfer ownership via move:" << endl;

    AutoPtr<int> p1(new int(77));
    cout << "    p1 valid=" << p1.valid() << " | *p1=" << *p1 << endl;

    AutoPtr<int> p2(move(p1));   // transfer kepemilikan
    cout << "    setelah move:" << endl;
    cout << "    p1 valid=" << p1.valid() << endl;    // p1 sudah tidak punya
    cout << "    p2 valid=" << p2.valid() << " | *p2=" << *p2 << endl;

    // p2 yang sekarang bertanggung jawab delete (saat destructor dipanggil)
}

int main() {

    cout << "=== Demo 1: RAII vs Manual (scope normal) ===" << endl;
    demo_raii_vs_manual_normal();

    cout << "\n=== Demo 2: RAII vs Manual (dengan exception) ===" << endl;
    demo_raii_dengan_exception();

    cout << "\n=== Demo 3: RAII dengan Early Return ===" << endl;
    cout << "  --- kondisi = true (early return) ---" << endl;
    proses_dengan_early_return(true);
    cout << "  --- kondisi = false (normal) ---" << endl;
    proses_dengan_early_return(false);

    cout << "\n=== Demo 4: Multiple Resource RAII ===" << endl;
    demo_multiple_resource();

    cout << "\n=== Demo 5: Transfer Ownership ===" << endl;
    demo_transfer_ownership();

    cout << "\n=== Ringkasan Prinsip RAII ===" << endl;
    cout << "  Constructor = Acquire resource" << endl;
    cout << "  Destructor  = Release resource (SELALU dipanggil!)" << endl;
    cout << "  Destructor dipanggil: scope normal, early return, exception" << endl;
    cout << "  RAII adalah fondasi dari unique_ptr dan shared_ptr!" << endl;

    return 0;
}

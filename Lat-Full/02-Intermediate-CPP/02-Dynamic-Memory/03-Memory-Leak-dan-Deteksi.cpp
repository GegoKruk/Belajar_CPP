#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// PELACAK MANUAL: untuk mendeteksi leak di lingkup belajar
// -------------------------------------------------------
namespace Tracker {
    int alokasi  = 0;
    int dealokasi = 0;

    void catat_new()    { alokasi++;   }
    void catat_delete() { dealokasi++; }
    void laporan(const string& konteks) {
        int selisih = alokasi - dealokasi;
        cout << "  [Tracker/" << konteks << "] "
             << "new=" << alokasi
             << " | delete=" << dealokasi
             << " | selisih=" << selisih
             << (selisih == 0 ? " (BERSIH)" : " (LEAK!)") << endl;
        alokasi = dealokasi = 0;   // reset untuk sesi berikutnya
    }
}

// -------------------------------------------------------
// SKENARIO 1: LUPA DELETE
// -------------------------------------------------------
void skenario_lupa_delete() {
    int* p = new int(42);
    Tracker::catat_new();
    // ... digunakan ...
    // LUPA: delete p; p = nullptr;
    cout << "  [Bocor] *p = " << *p << " -- p tidak pernah didelete!" << endl;
    (void)p;   // supaya tidak ada warning unused -- JANGAN lakukan ini di kode nyata
}

void skenario_lupa_delete_FIXED() {
    int* p = new int(42);
    Tracker::catat_new();
    cout << "  [Aman]  *p = " << *p << " -- akan didelete" << endl;
    delete p;
    Tracker::catat_delete();
    p = nullptr;
}

// -------------------------------------------------------
// SKENARIO 2: POINTER DITIMPA (REASSIGN TANPA DELETE)
// -------------------------------------------------------
void skenario_pointer_tertimpa() {
    int* p = new int(10);
    Tracker::catat_new();
    cout << "  [Bocor] p = " << p << " -- akan ditimpa" << endl;

    p = new int(20);           // memory int(10) hilang SELAMANYA!
    Tracker::catat_new();
    cout << "  [Bocor] p sekarang = " << p << " -- int(10) bocor!" << endl;

    delete p;                  // hanya hapus int(20)
    Tracker::catat_delete();
    p = nullptr;
}

void skenario_pointer_tertimpa_FIXED() {
    int* p = new int(10);
    Tracker::catat_new();
    cout << "  [Aman]  *p = " << *p << " -- didelete sebelum reassign" << endl;

    delete p;                  // hapus int(10) dulu!
    Tracker::catat_delete();
    p = nullptr;

    p = new int(20);           // baru assign yang baru
    Tracker::catat_new();
    cout << "  [Aman]  *p = " << *p << " (nilai baru)" << endl;

    delete p;
    Tracker::catat_delete();
    p = nullptr;
}

// -------------------------------------------------------
// SKENARIO 3: EARLY RETURN SEBELUM DELETE
// -------------------------------------------------------
void skenario_early_return(bool kondisi) {
    int* data = new int[10];
    Tracker::catat_new();
    for (int i = 0; i < 10; i++) data[i] = i;

    if (kondisi) {
        cout << "  [Bocor] early return -- delete tidak tercapai!" << endl;
        return;    // LEAK! data tidak didelete
    }

    delete[] data;
    Tracker::catat_delete();
    data = nullptr;
}

void skenario_early_return_FIXED(bool kondisi) {
    int* data = new int[10];
    Tracker::catat_new();
    for (int i = 0; i < 10; i++) data[i] = i;

    if (kondisi) {
        cout << "  [Aman]  early return -- delete sebelum return" << endl;
        delete[] data;          // delete di SETIAP exit path
        Tracker::catat_delete();
        data = nullptr;
        return;
    }

    delete[] data;
    Tracker::catat_delete();
    data = nullptr;
}

// -------------------------------------------------------
// SKENARIO 4: LEAK DALAM LOOP
// -------------------------------------------------------
void skenario_leak_dalam_loop(int iterasi) {
    int totalLeak = 0;
    for (int i = 0; i < iterasi; i++) {
        int* p = new int(i * 10);   // LEAK tiap iterasi!
        Tracker::catat_new();
        // ... proses p ...
        // LUPA: delete p;
        totalLeak++;
        (void)p;
    }
    cout << "  [Bocor] " << totalLeak << " alokasi tidak pernah didelete" << endl;
}

void skenario_leak_dalam_loop_FIXED(int iterasi) {
    for (int i = 0; i < iterasi; i++) {
        int* p = new int(i * 10);
        Tracker::catat_new();
        // ... proses p ...
        delete p;               // delete di dalam loop!
        Tracker::catat_delete();
        p = nullptr;
    }
    cout << "  [Aman]  Semua alokasi dalam loop berhasil didelete" << endl;
}

// -------------------------------------------------------
// SKENARIO 5: EXCEPTION SEBELUM DELETE
// -------------------------------------------------------
void operasiYangThrow() {
    throw runtime_error("terjadi kesalahan!");
}

void skenario_exception_leak() {
    int* p = new int(99);
    Tracker::catat_new();
    try {
        operasiYangThrow();
        delete p;               // TIDAK PERNAH TERCAPAI jika throw!
        Tracker::catat_delete();
        p = nullptr;
    } catch (const exception& e) {
        cout << "  [Bocor] Exception: " << e.what()
             << " -- p tidak didelete!" << endl;
        // lupa delete p di catch block
    }
    // p masih bocor setelah fungsi ini selesai
    // Solusi: delete di catch block, atau pakai RAII/smart pointer
    delete p;   // ← ini tidak dipanggil di path exception di atas
                //   hanya untuk menghindari crash saat demo
    Tracker::catat_delete();
}

void skenario_exception_FIXED() {
    int* p = new int(99);
    Tracker::catat_new();
    try {
        operasiYangThrow();
        delete p;
        Tracker::catat_delete();
        p = nullptr;
    } catch (const exception& e) {
        cout << "  [Aman]  Exception: " << e.what()
             << " -- delete di catch block" << endl;
        delete p;               // delete di SETIAP catch block
        Tracker::catat_delete();
        p = nullptr;
    }
}

int main() {

    cout << "=== Skenario 1: Lupa delete ===" << endl;
    skenario_lupa_delete();
    Tracker::laporan("bocor");
    skenario_lupa_delete_FIXED();
    Tracker::laporan("fixed");

    cout << "\n=== Skenario 2: Pointer Tertimpa ===" << endl;
    skenario_pointer_tertimpa();
    Tracker::laporan("bocor");
    skenario_pointer_tertimpa_FIXED();
    Tracker::laporan("fixed");

    cout << "\n=== Skenario 3: Early Return ===" << endl;
    skenario_early_return(true);
    Tracker::laporan("bocor");
    skenario_early_return_FIXED(true);
    Tracker::laporan("fixed");

    cout << "\n=== Skenario 4: Leak dalam Loop ===" << endl;
    skenario_leak_dalam_loop(5);
    Tracker::laporan("bocor");
    skenario_leak_dalam_loop_FIXED(5);
    Tracker::laporan("fixed");

    cout << "\n=== Skenario 5: Exception Sebelum Delete ===" << endl;
    skenario_exception_leak();
    Tracker::laporan("bocor-ish");
    skenario_exception_FIXED();
    Tracker::laporan("fixed");

    // -------------------------------------------------------
    // RINGKASAN CARA DETEKSI
    // -------------------------------------------------------
    cout << "\n=== Cara Deteksi Memory Leak ===" << endl;
    cout << "  1. Manual tracker (seperti Tracker:: di atas)" << endl;
    cout << "  2. Valgrind  : valgrind --leak-check=full ./program" << endl;
    cout << "  3. ASan      : compile dengan -fsanitize=address -g" << endl;
    cout << "  4. VS/Windows: _CrtDumpMemoryLeaks() dari <crtdbg.h>" << endl;
    cout << "  5. Smart ptr : pakai unique_ptr / shared_ptr -> no leak!" << endl;

    return 0;
}

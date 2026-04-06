
#include <iostream>
#include <string>
using namespace std;

void kesalahan1_WildPointer() {
    cout << "============================================================" << endl;
    cout << "  1. Wild Pointer -- Pointer Tidak Diinisialisasi" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Pointer yang dideklarasikan tapi tidak diinisialisasi.
        Nilainya adalah GARBAGE (nilai acak dari memory).
        Dereference wild pointer = crash atau korupsi data!

        int* ptr;          // BAHAYA! ptr berisi nilai acak
        *ptr = 10;         // CRASH! Menulis ke alamat acak
        cout << *ptr;      // CRASH atau nilai tidak terduga

      Kenapa berbahaya?
        - ptr menunjuk ke alamat acak yang tidak kita kontrol
        - Bisa menimpa data milik program lain
        - Bisa crash dengan Segmentation Fault
        - Bisa diam-diam merusak data tanpa crash (lebih parah!)

      SOLUSI: SELALU inisialisasi pointer!

        int* ptr = nullptr;    // aman, belum punya tujuan
        int angka = 42;
        int* ptr2 = &angka;    // langsung arahkan ke variabel
    )" << endl;

    // Demo yang benar
    int* ptr = nullptr;   // aman
    int angka = 42;
    ptr = &angka;
    cout << "  int* ptr = nullptr; (aman)" << endl;
    cout << "  ptr = &angka; *ptr = " << *ptr << " (aman)" << endl;
}

void kesalahan2_NullDeref() {
    cout << "\n============================================================" << endl;
    cout << "  2. Null Pointer Dereference" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Mendereference pointer yang berisi nullptr.
        = CRASH dengan Segmentation Fault (Segfault)

        int* ptr = nullptr;
        cout << *ptr;      // CRASH! Cannot access memory at address 0

      Kapan terjadi?
        - Pointer belum diarahkan ke variabel valid
        - Function mengembalikan nullptr dan langsung dideref
        - Pointer di-set nullptr setelah delete, lalu dideref lagi

      SOLUSI: Selalu cek != nullptr sebelum dereference!

        int* ptr = nullptr;
        if (ptr != nullptr) {
            cout << *ptr;    // aman, cek dulu
        }

      Atau dalam kode modern, gunakan smart pointer yang aman otomatis.
    )" << endl;

    // Demo cara aman
    int* ptr = nullptr;
    cout << "  int* ptr = nullptr;" << endl;
    if (ptr != nullptr) {
        cout << "  *ptr = " << *ptr << " (tidak akan dieksekusi)" << endl;
    } else {
        cout << "  ptr == nullptr, skip dereference (aman)" << endl;
    }

    int angka = 55;
    ptr = &angka;
    if (ptr != nullptr) {
        cout << "\n  Setelah ptr = &angka:" << endl;
        cout << "  *ptr = " << *ptr << " (aman)" << endl;
    }
}

void kesalahan3_DanglingPointer() {
    cout << "\n============================================================" << endl;
    cout << "  3. Dangling Pointer" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Pointer yang masih menyimpan alamat memory yang sudah tidak valid.

        Dua cara terjadinya:

        Cara 1: Setelah delete
            int* ptr = new int(42);
            delete ptr;
            cout << *ptr;   // BAHAYA! ptr masih berisi alamat lama
                              tapi memorinya sudah dibebaskan

        Cara 2: Pointer ke variabel lokal yang sudah keluar scope
            int* fungsi() {
                int lokal = 10;
                return &lokal;   // BAHAYA! lokal dihapus saat function selesai
            }
            // Memanggil fungsi() mengembalikan pointer ke memori tidak valid!

      SOLUSI:
        1. Setelah delete: set pointer ke nullptr
          delete ptr;
          ptr = nullptr;

        2. Jangan return pointer ke variabel lokal!
          Kembalikan by value, atau alokasi di heap.
    )" << endl;

    // Demo cara benar
    int* ptr = new int(42);
    cout << "  new int(42); *ptr = " << *ptr << endl;
    delete ptr;
    ptr = nullptr;   // set nullptr setelah delete
    cout << "  delete ptr; ptr = nullptr;" << endl;

    if (ptr != nullptr) {
        cout << "  *ptr = " << *ptr << " (tidak dieksekusi)" << endl;
    } else {
        cout << "  ptr == nullptr, aman dari dangling pointer" << endl;
    }
}

void kesalahan4_MemoryLeak() {
    cout << "\n============================================================" << endl;
    cout << "  4. Memory Leak -- Lupa delete" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Memory yang dialokasi dengan new tidak pernah dibebaskan.
        Program tetap berjalan, tapi RAM terus berkurang.
        Untuk program yang berjalan lama: bisa habiskan RAM -> crash!

        void fungsiLeak() {
            int* ptr = new int(10);
            // ... proses ...
            return;   // LUPA delete! Memory hilang selamanya.
        }

        Atau:
            int* ptr = new int(10);
            ptr = new int(20);   // alamat lama hilang, tidak bisa delete lagi!

      Cara mendeteksi:
        - Valgrind (Linux): valgrind --leak-check=full ./program
        - AddressSanitizer: g++ -fsanitize=address program.cpp

      SOLUSI:
        1. Selalu pasangkan new dengan delete
        2. Gunakan SMART POINTER (unique_ptr) -- tidak perlu delete manual!
        3. Minimasi penggunaan raw pointer untuk dynamic memory
    )" << endl;

    // Demo cara benar: selalu delete
    int* ptr1 = new int(10);
    cout << "  new int(10);  *ptr1 = " << *ptr1 << endl;
    delete ptr1;
    ptr1 = nullptr;
    cout << "  delete ptr1;  (aman, tidak leak)" << endl;

    // Demo urutan yang benar kalau reassign
    int* ptr2 = new int(10);
    cout << "\n  Reassign pointer dengan benar:" << endl;
    cout << "  new int(10); *ptr2 = " << *ptr2 << endl;
    delete ptr2;        // delete lama dulu!
    ptr2 = new int(20); // baru alokasi baru
    cout << "  delete dulu, baru new lagi: *ptr2 = " << *ptr2 << endl;
    delete ptr2;
    ptr2 = nullptr;
}

void kesalahan5_DoubleDelete() {
    cout << "\n============================================================" << endl;
    cout << "  5. Double Delete -- Delete Dua Kali" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Memanggil delete pada pointer yang sama dua kali.
        = CRASH atau undefined behavior!

        int* ptr = new int(42);
        delete ptr;
        delete ptr;    // CRASH! Double free!

      SOLUSI:
        Set pointer ke nullptr setelah delete.
        delete nullptr adalah operasi aman (tidak crash, tidak efek apa-apa).

        int* ptr = new int(42);
        delete ptr;
        ptr = nullptr;   // set nullptr
        delete ptr;      // delete nullptr = aman! Tidak ada efek
    )" << endl;

    // Demo cara aman dengan nullptr trick
    int* ptr = new int(42);
    cout << "  new int(42); *ptr = " << *ptr << endl;
    delete ptr;
    ptr = nullptr;
    cout << "  delete ptr; ptr = nullptr;" << endl;
    delete ptr;   // delete nullptr = aman!
    cout << "  delete ptr; (delete nullptr, aman)" << endl;
    cout << "  Program tidak crash!" << endl;
}

void kesalahan6_SalahDelete() {
    cout << "\n============================================================" << endl;
    cout << "  6. Salah Jenis Delete" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Pakai delete (tanpa []) untuk array yang dialokasi dengan new[].
        Atau pakai delete[] untuk single value.

        Hasilnya: undefined behavior -- bisa crash, bisa korupsi memory.

        int* arr = new int[5];
        delete arr;     // SALAH! Harus delete[]
        delete[] arr;   // BENAR

        int* ptr = new int(42);
        delete[] ptr;   // SALAH! Harus delete (tanpa [])
        delete ptr;     // BENAR

      ATURAN MUDAH DIINGAT:
        new     -> delete
        new[]   -> delete[]
        (pasangan harus sama!)
    )" << endl;

    // Demo cara benar
    int* single = new int(42);
    int* arr    = new int[5]{1, 2, 3, 4, 5};

    cout << "  single  = new int(42);   *single = " << *single << endl;
    cout << "  arr     = new int[5];   arr[0]  = " << arr[0]   << endl;

    delete    single;   // delete untuk single
    delete[]  arr;      // delete[] untuk array
    single = nullptr;
    arr    = nullptr;

    cout << "  delete single;   (benar, bukan delete[])" << endl;
    cout << "  delete[] arr;    (benar, bukan delete)" << endl;
}

void kesalahan7_OutOfBounds() {
    cout << "\n============================================================" << endl;
    cout << "  7. Pointer Out-of-Bounds" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      MASALAH:
        Pointer arithmetic melewati batas array yang valid.
        = Undefined behavior: crash, nilai korup, atau diam-diam salah.

        int arr[5] = {1, 2, 3, 4, 5};
        int* ptr = arr;
        ptr += 10;      // melewati batas array!
        cout << *ptr;   // CRASH atau nilai acak

      SOLUSI:
        Selalu pastikan pointer dalam rentang [arr, arr + n).
        Yaitu: antara arr[0] sampai arr[n-1].
        Arr[n] boleh sebagai batas (sentinel), tapi jangan dideref!
    )" << endl;

    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    // Loop yang aman
    cout << "  Loop aman dengan batas:" << endl;
    cout << "  ";
    for (int* p = arr; p < arr + n; p++) {
        cout << *p << " ";
    }
    cout << endl;
    cout << "  (tidak pernah melewati arr + 5)" << endl;
}

void ringkasanSolusi() {
    cout << "\n============================================================" << endl;
    cout << "  Ringkasan: Checklist Keamanan Pointer" << endl;
    cout << "============================================================" << endl;

    cout << R"(
      +---+--------------------------------+----------------------------------+
      | # | Kesalahan                      | Solusi                           |
      +---+--------------------------------+----------------------------------+
      | 1 | Wild pointer (tidak init)      | Selalu init: nullptr atau &var   |
      | 2 | Null pointer dereference       | Cek != nullptr sebelum deref     |
      | 3 | Dangling pointer               | set nullptr setelah delete       |
      | 4 | Memory leak (lupa delete)      | Setiap new HARUS ada delete      |
      | 5 | Double delete                  | Set nullptr setelah delete       |
      | 6 | Salah jenis delete             | new->delete, new[]->delete[]     |
      | 7 | Out-of-bounds pointer          | Jaga ptr dalam [arr, arr+n)      |
      +---+--------------------------------+----------------------------------+

      CHECKLIST SEBELUM PAKAI POINTER:
        [ ] Pointer sudah diinisialisasi?
        [ ] Sudah cek != nullptr sebelum dereference?
        [ ] Setiap new punya pasangan delete?
        [ ] Setelah delete, set ke nullptr?
        [ ] Tidak melewati batas array?
        [ ] new[] diikuti delete[], bukan delete?

      SARAN MODERN:
        Untuk kode C++ modern, gunakan SMART POINTER:
            unique_ptr<T>  -- kepemilikan tunggal, tidak perlu delete manual
        Ini menghilangkan hampir semua masalah di atas secara otomatis!
    )" << endl;
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "============================================================" << endl;
    cout << "  WX.2 -- Kesalahan Umum Pointer & Reference" << endl;
    cout << "============================================================" << endl;

    kesalahan1_WildPointer();
    kesalahan2_NullDeref();
    kesalahan3_DanglingPointer();
    kesalahan4_MemoryLeak();
    kesalahan5_DoubleDelete();
    kesalahan6_SalahDelete();
    kesalahan7_OutOfBounds();
    ringkasanSolusi();

    return 0;
}

/*
    DAFTAR ISI MODUL ADVANCED POINTERS
    ============================================================
    00  Overview                        <- kamu di sini
    01  Pointer-to-Pointer
    02  Array-of-Pointers
    03  Function-Pointer-Lanjutan
    04  Typedef-dan-Using
    05  Void-Pointer
    06  Pointer-Casting
    07  This-Pointer-Preview
    ============================================================
*/

// Y.0 - Overview

    /* APA ITU ADVANCED POINTERS?
        -------------------------------------------------------
        Pointer adalah variabel yang menyimpan alamat memori.
        Di modul fundamental kita sudah belajar pointer dasar:
        - Deklarasi pointer (int* ptr)
        - Alamat (&) dan dereferensi (*)
        - Pointer dan array

        Di modul ini kita naik level ke topik pointer yang lebih
        kuat dan sering dipakai di dunia nyata (terutama sistem
        programming, game engine, embedded system).

        Topik yang dipelajari:
        - Pointer ke Pointer (**)  : menyimpan alamat dari pointer
        - Array of Pointers       : array berisi alamat-alamat
        - Function Pointer Lanjutan: callback & dispatch table
        - Typedef/Using untuk pointer: membuat alias agar mudah
        - Void Pointer (void*)    : pointer generik tanpa tipe
        - Pointer Casting         : mengubah tipe pointer secara aman/tidak
        - This Pointer Preview    : pointer tersembunyi di dalam class/struct
    */

    /* MENGAPA PERLU DIPELAJARI?
        -------------------------------------------------------
        1. Pointer ke Pointer   -> digunakan untuk dynamic 2D array,
                                   parameter pointer yang bisa diubah di fungsi
        2. Array of Pointers    -> menyimpan daftar string (argv),
                                   tabel fungsi (dispatch table)
        3. Function Pointer     -> callback, strategy pattern
        4. Void Pointer         -> fungsi generic (qsort, memcpy)
        5. Pointer Casting      -> reinterpretasi data (low-level)
        6. This Pointer         -> dasar dari member function OOP

        Advanced pointer adalah "jembatan" menuju pemrograman sistem
        dan pemahaman memory management yang lebih dalam.
    */

// Y.1 - Pointer-to-Pointer (Double Pointer)

    /* APA ITU POINTER KE POINTER?
        -------------------------------------------------------
        Variabel yang menyimpan ALAMAT dari pointer lain.
        Disebut juga "double pointer" atau "nested pointer".

        Deklarasi:
            int nilai = 10;
            int* ptr = &nilai;    // pointer ke int
            int** ptr2 = &ptr;    // pointer ke pointer int

        Ilustrasi memori:
            nilai (int)  : [10]   alamat: 0x100
            ptr (int*)   : [0x100] alamat: 0x200
            ptr2 (int**) : [0x200] alamat: 0x300

        Akses nilai asli melalui ptr2:
            **ptr2   == 10
            *ptr2    == 0x100 (alamat nilai)
    */

    /* KEGUNAAN POINTER KE POINTER
        -------------------------------------------------------
        a. Mengubah pointer di dalam fungsi
            void alihkan(int** ptr, int* baru) {
                *ptr = baru;   // mengubah pointer asli di luar
            }

        b. Dynamic 2D array (array of pointers)
            int** matriks = new int*[baris];
            for(int i=0; i<baris; i++)
                matriks[i] = new int[kolom];

        c. Argumen main: char* argv[] setara dengan char** argv
    */

    /* PERHATIAN
        -------------------------------------------------------
        - Jangan bingung dengan referensi ke pointer (int*&)
        - Double pointer sering digunakan di C, di C++ lebih
          sering pakai reference ke pointer (int*&) atau std::vector
        - Akses harus bertingkat: * untuk satu level, ** untuk dua
    */

// Y.2 - Array of Pointers

    /* APA ITU ARRAY OF POINTERS?
        -------------------------------------------------------
        Array yang setiap elemennya adalah pointer (biasanya
        pointer ke tipe yang sama).

        Deklarasi:
            int* arrPtr[5];   // array of 5 pointer ke int

        Perbedaan dengan pointer ke array:
            int (*ptrArr)[5];   // pointer ke array 5 int (jarang dipakai)

        Contoh khas:
            const char* namaHari[7] = {
                "Senin", "Selasa", "Rabu", "Kamis",
                "Jumat", "Sabtu", "Minggu"
            };
            // Setiap elemen adalah pointer ke string literal
    */

    /* KEGUNAAN ARRAY OF POINTERS
        -------------------------------------------------------
        1. Menyimpan string (C-string) dengan panjang berbeda
        2. Tabel fungsi (function pointer array) lihat Y.3
        3. Menyimpan objek polimorfik (base class pointer)
        4. Matriks "jagged" (baris dengan panjang berbeda)
    */

    /* JAGGED ARRAY (2D dengan panjang baris berbeda)
        -------------------------------------------------------
        int* jagged[3];
        jagged[0] = new int[2]{1,2};
        jagged[1] = new int[4]{3,4,5,6};
        jagged[2] = new int[1]{7};

        Setiap baris bebas panjangnya.
    */

// Y.3 - Function Pointer Lanjutan

    /* REVIEW FUNCTION POINTER DASAR
        -------------------------------------------------------
        Pointer yang menyimpan alamat fungsi, bukan data.

        int tambah(int a, int b) { return a+b; }
        int (*fp)(int,int) = tambah;
        int hasil = fp(5,3);   // 8
    */

    /* ARRAY OF FUNCTION POINTERS (DISPATCH TABLE)
        -------------------------------------------------------
        // Tiga fungsi dengan signature sama
        int add(int a,int b) { return a+b; }
        int sub(int a,int b) { return a-b; }
        int mul(int a,int b) { return a*b; }

        // Array of function pointers
        int (*ops[3])(int,int) = {add, sub, mul};

        // Panggil berdasarkan index
        ops[0](10,5);  // 15
        ops[1](10,5);  // 5
        ops[2](10,5);  // 50

        Pola ini disebut DISPATCH TABLE atau jump table.
        Berguna untuk membuat interpreter, menu kalkulator, dll.
    */

    /* FUNCTION POINTER SEBAGAI PARAMETER (CALLBACK LANJUTAN)
        -------------------------------------------------------
        // Callback dengan dua parameter
        void prosesArray(int* arr, int n,
                         void (*aksi)(int)) {
            for(int i=0;i<n;i++) aksi(arr[i]);
        }

        // Callback dengan return value (predicate)
        int countIf(int* arr, int n,
                    bool (*predikat)(int)) {
            int cnt=0;
            for(int i=0;i<n;i++) if(predikat(arr[i])) cnt++;
            return cnt;
        }

        // Lambda bisa dipakai asal tanpa capture
        countIf(arr, n, [](int x){ return x>5; });
    */

    /* FUNCTION POINTER DENGAN TYPEDEF (Lihat Y.4)
        -------------------------------------------------------
        using Operation = int (*)(int,int);
        Operation op = add;
    */

// Y.4 - Typedef dan Using untuk Pointer

    /* APA ITU TYPE ALIAS?
        -------------------------------------------------------
        Memberikan nama alternatif untuk tipe data yang sudah ada.
        Sangat berguna untuk menyederhanakan tipe pointer yang rumit.
    */

    /* CARA LAMA (typedef)
        -------------------------------------------------------
        typedef int* IntPtr;              // IntPtr = pointer ke int
        typedef int (*FuncPtr)(int,int);  // FuncPtr = function pointer

        IntPtr p = &x;
        FuncPtr f = tambah;
    */

    /* CARA MODERN (using - C++11)
        -------------------------------------------------------
        using IntPtr = int*;
        using FuncPtr = int (*)(int,int);

        Kelebihan using:
        - Lebih mudah dibaca (mirip assignment)
        - Bisa digunakan dengan template (alias template)
    */

    /* CONTOH UNTUK TIPE KOMPLEKS
        -------------------------------------------------------
        // Pointer ke function yang return pointer ke int
        using ComplexFunc = int* (*)(double, char);

        // Array of function pointers
        using Operation = int (*)(int,int);
        Operation ops[3] = {add,sub,mul};

        // Pointer ke array of function pointers
        using OpsArray = Operation[3];
        OpsArray* ptr = &ops;
    */

// Y.5 - Void Pointer (void*)

    /* APA ITU VOID POINTER?
        -------------------------------------------------------
        Pointer generik yang bisa menyimpan alamat apapun
        (int, double, char, struct, dll) tanpa mengetahui tipenya.

        Deklarasi:
            void* ptr;

        ptr bisa diisi dengan alamat tipe apa pun:
            int a=5;      ptr = &a;
            double b=3.14; ptr = &b;
            char c='A';   ptr = &c;
    */

    /* KETERBATASAN VOID POINTER
        -------------------------------------------------------
        1. TIDAK BISA di-dereferensi langsung (*ptr) karena
           compiler tidak tahu ukuran data.

        2. TIDAK BISA dilakukan pointer arithmetic (ptr++, ptr+1)
           karena tidak tahu ukuran step.

        Solusi: harus di-cast ke tipe yang diketahui dulu.
    */

    /* KEGUNAAN VOID POINTER
        -------------------------------------------------------
        a. Fungsi generic ala C (qsort, memcpy, memset, malloc)
            void* malloc(size_t size);
            void* memcpy(void* dest, const void* src, size_t n);

        b. Callback yang menerima data opaque (tidak diketahui tipenya)
            void* userData;

        c. Implementasi polimorfisme manual (sebelum C++ OOP)

        Di C++ modern, lebih baik gunakan template, std::any,
        atau inheritance daripada void*.
    */

    /* CASTING VOID POINTER
        -------------------------------------------------------
        int* iptr = static_cast<int*>(ptr);
        double* dptr = static_cast<double*>(ptr);

        Hati-hati: jika cast ke tipe salah -> undefined behavior.
    */

// Y.6 - Pointer Casting

    /* APA ITU POINTER CASTING?
        -------------------------------------------------------
        Mengubah tipe dari suatu pointer ke tipe pointer lain.
        Di C++ ada 4 operator casting:
        - static_cast   : casting "aman" dalam batas tertentu
        - reinterpret_cast : casting bitwise (berbahaya)
        - const_cast    : membuang const
        - dynamic_cast  : untuk polimorfisme (akan dibahas di OOP)
    */

    /* static_cast UNTUK POINTER
        -------------------------------------------------------
        Digunakan untuk casting antar tipe pointer yang
        berhubungan dalam hirarki (up/down casting) dan
        konversi void* ke tipe tertentu.

        int a=10;
        void* vp = &a;
        int* ip = static_cast<int*>(vp);   // OK

        double* dp = static_cast<double*>(&a); // ERROR (tidak berhubungan)
    */

    /* reinterpret_cast
        -------------------------------------------------------
        Casting yang sangat berbahaya - hanya menginterpretasi ulang
        bit tanpa perubahan. Digunakan untuk:
        - Mengubah pointer ke tipe lain yang tidak berhubungan
        - Mengubah pointer ke integer (dan sebaliknya)
        - Low-level programming (driver, embedded)

        int a = 65;
        int* ip = &a;
        char* cp = reinterpret_cast<char*>(ip);
        cout << *cp;   // 'A' (jika little-endian)

        PERINGATAN: Hasil tidak portable dan sangat rawan UB.
        Hanya gunakan jika benar-benar tahu konsekuensinya.
    */

    /* const_cast
        -------------------------------------------------------
        Membuang atau menambah const qualifier pada tipe.
        Digunakan saat kita punya pointer const namun perlu
        memanggil fungsi non-const (hack).

        const int a = 10;
        const int* cp = &a;
        int* p = const_cast<int*>(cp);
        *p = 20;   // UNDEFINED BEHAVIOR (a sebenarnya const)

        Hampir tidak pernah direkomendasikan, kecuali untuk
        interop dengan library C yang tidak const-correct.
    */

    /* C-STYLE CAST (TIDAK DISARANKAN)
        -------------------------------------------------------
        (int*)ptr   atau   int* p = (int*)ptr;

        Masalah: melakukan kombinasi static_cast, const_cast,
        reinterpret_cast secara membabi buta. Susah dibaca dan
        rawan kesalahan. Di C++ hindari C-style cast.
    */

    /* REKOMENDASI
        -------------------------------------------------------
        - static_cast   -> untuk konversi yang relatif aman
        - reinterpret_cast -> hanya jika sangat yakin (low-level)
        - const_cast    -> hindari, desain ulang kode
        - dynamic_cast  -> untuk OOP (akan dipelajari nanti)
    */

// Y.7 - This Pointer (Preview)

    /* APA ITU THIS POINTER?
        -------------------------------------------------------
        Setiap member function non-static dari class/struct
        memiliki pointer tersembunyi bernama `this` yang menunjuk
        ke objek yang sedang diproses.

        this adalah pointer konstan ke objek itu sendiri.
    */

    /* CONTOH SEDERHANA
        -------------------------------------------------------
        struct Mahasiswa {
            string nama;
            void cetak() {
                // this->nama sama dengan nama (jika tidak ambigu)
                cout << this->nama;
            }
        };

        Mahasiswa m;
        m.cetak();   // di dalam cetak, this = &m
    */

    /* KEGUNAAN THIS POINTER
        -------------------------------------------------------
        1. Mengatasi nama member yang sama dengan parameter
            void setNama(string nama) {
                this->nama = nama;   // this->nama = parameter
            }

        2. Method chaining (return *this)
            Mahasiswa& setUmur(int u) {
                this->umur = u;
                return *this;
            }
            // m.setUmur(20).setNama("Budi");

        3. Mengetahui alamat objek sendiri
            if (this == &objLain) ...

        4. Dalam operator overloading (akan dipelajari di OOP)
    */

    /* CATATAN PENTING
        -------------------------------------------------------
        - this tidak bisa diubah alamatnya (this = nullptr; // ERROR)
        - Di dalam member function const, this bertipe const Mahasiswa*
        - this tidak ada di static member function (karena milik class)
        - this adalah pointer, bukan reference.

        Preview ini akan diperdalam di modul OOP (Class & Object).
    */

// ============================================================
// END OF MATERI
// ============================================================
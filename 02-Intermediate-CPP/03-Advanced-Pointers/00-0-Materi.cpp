/*
    DAFTAR ISI MODUL ADVANCED POINTERS
    ============================================================
    00  Overview
    01  Pointer-to-Pointer
    02  Array-of-Pointers
    03  Function-Pointer-Lanjutan
    04  Typedef-dan-Using
    05  Void-Pointer
    06  Pointer-Casting
    07  This-Pointer-Preview
    ============================================================
*/

// ============================================================
// Z.0 - Overview
// ============================================================

    /* RECAP: APA YANG SUDAH DIKETAHUI
        -------------------------------------------------------
        Di modul Fundamental (07-Pointer-Reference), kita sudah
        mengenal konsep dasar pointer:

            int x   = 42;
            int* p  = &x;       // p menyimpan ALAMAT x
            *p      = 99;       // dereference: ubah nilai x via p

        Dan di modul Dynamic Memory, kita sudah pakai pointer
        untuk alokasi heap:

            int* arr = new int[10];
            delete[] arr;

        Modul ini naik satu level lagi ke penggunaan pointer yang
        lebih kompleks dan idiomatis di C++.
    */

    /* APA YANG AKAN DIPELAJARI
        -------------------------------------------------------
        01  Pointer-to-Pointer   : int** -- pointer yang menunjuk ke pointer lain
                                   Dasar dari dynamic 2D array dan argv
        02  Array-of-Pointers    : int* arr[] -- array yang isinya pointer
                                   Dasar dari sistem menu, dispatch table
        03  Function Ptr Lanjutan: pointer ke fungsi member, array of FP,
                                   dan pola-pola lanjutan
        04  Typedef dan Using    : memberi alias agar sintaks pointer terbaca
        05  Void Pointer         : void* -- pointer generik tanpa tipe
                                   Dasar dari qsort, memcpy, dan API C lama
        06  Pointer Casting      : static_cast, reinterpret_cast, const_cast
                                   untuk mengubah tipe pointer
        07  This Pointer Preview : pointer implisit di dalam class
                                   yang menunjuk ke objek itu sendiri
    */

    /* MENGAPA MODUL INI PENTING?
        -------------------------------------------------------
        Advanced Pointers adalah BAHASA DALAM dari C++.
        Banyak konsep penting bergantung padanya:

        - Implementasi linked list, tree, graph -> pointer-to-pointer
        - Command-line arguments (argc, argv)   -> char** = array of pointers
        - C standard library (qsort, bsearch)   -> void*
        - Interop dengan C API                  -> void*, casting
        - OOP (this pointer)                    -> dasar class dan method
        - Template & generic programming        -> casting dan void*
        - Design patterns (Strategy, Command)   -> function pointer lanjutan

        Kuasai ini, dan kamu akan bisa membaca dan menulis hampir
        semua kode C++ yang ada di dunia nyata.
    */


// ============================================================
// Z.1 - Pointer to Pointer
// ============================================================

    /* APA ITU POINTER-TO-POINTER?
        -------------------------------------------------------
        Pointer biasa menyimpan ALAMAT dari suatu variabel.
        Pointer-to-pointer menyimpan ALAMAT dari pointer lain.

        Visualisasi tiga level:

            int   x   = 42;
            int*  p   = &x;    // p menyimpan alamat x
            int** pp  = &p;    // pp menyimpan alamat p

            Memory layout:
            +------+         +------+         +------+
            | pp   | ------> |  p   | ------> |  x   |
            | 0x30 |         | 0x20 |         |  42  |
            +------+         +------+         +------+
              0x30              0x20             0x10

        Cara mengakses nilainya:
            pp          -> alamat p  (0x20)
            *pp         -> nilai p   = alamat x (0x10) = *pp == p
            **pp        -> nilai x   = 42       = **pp == x
    */

    /* SINTAKS DEKLARASI
        -------------------------------------------------------
        int   x   = 5;
        int*  p   = &x;       // pointer ke int
        int** pp  = &p;       // pointer ke pointer ke int

        // Akses
        cout << x;            // 5
        cout << *p;           // 5
        cout << **pp;         // 5

        // Ubah nilai x via pp
        **pp = 99;
        cout << x;            // 99

        // Ubah ke mana p menunjuk, via pp
        int y = 100;
        *pp = &y;             // sekarang p menunjuk ke y, bukan x
        cout << *p;           // 100
    */

    /* KEGUNAAN 1: DYNAMIC 2D ARRAY
        -------------------------------------------------------
        Cara paling umum pointer-to-pointer dipakai:

            int** matriks = new int*[baris];
            for (int i = 0; i < baris; i++)
                matriks[i] = new int[kolom];

            matriks[i][j] = 10;   // akses natural

        Dealokasi terbalik:
            for (int i = 0; i < baris; i++) delete[] matriks[i];
            delete[] matriks;

        Sudah dibahas di modul 02-Dynamic-Memory file 07.
        Di sini kita fokus ke kegunaan lainnya.
    */

    /* KEGUNAAN 2: MEMODIFIKASI POINTER DARI DALAM FUNCTION
        -------------------------------------------------------
        Masalah: function tidak bisa mengubah pointer yang diterimanya
        karena pointer diteruskan by value.

            void alokasi(int* p) {
                p = new int(42);   // hanya ubah SALINAN p di dalam function!
                                   // p di pemanggil TIDAK berubah
            }

            int* ptr = nullptr;
            alokasi(ptr);
            cout << *ptr;     // CRASH! ptr masih nullptr

        Solusi 1: pakai pointer-to-pointer (C-style)
            void alokasi(int** pp) {
                *pp = new int(42);  // ubah pointer ASLI via dereferensi
            }
            alokasi(&ptr);
            cout << *ptr;     // OK: 42

        Solusi 2: pakai reference ke pointer (C++-style, lebih bersih)
            void alokasi(int*& ref) {
                ref = new int(42);
            }
            alokasi(ptr);
    */

    /* KEGUNAAN 3: COMMAND-LINE ARGUMENTS (argc, argv)
        -------------------------------------------------------
        int main(int argc, char** argv)
        // atau: char* argv[]  -- keduanya identik

        argv adalah array of pointers to char (C-string).
        argv[0] = nama program
        argv[1] = argumen pertama
        argv[2] = argumen kedua
        ...

        Contoh: ./program file.txt 100
            argc   = 3
            argv[0] = "./program"
            argv[1] = "file.txt"
            argv[2] = "100"

        char** adalah cara C merepresentasikan "array of string".
    */

    /* POINTER-TO-POINTER LEBIH DARI DUA LEVEL
        -------------------------------------------------------
        Secara teori bisa: int*** ppp, int**** pppp, dst.
        Tapi dalam praktik lebih dari dua level sangat jarang
        dan hampir selalu bisa digantikan dengan desain yang lebih baik.

        Aturan praktis: jika butuh tiga level pointer ke atas,
        pertimbangkan ulang desain kode -- mungkin ada abstraksi
        yang lebih tepat (class, struct, vector of vector, dll).
    */


// ============================================================
// Z.2 - Array of Pointers
// ============================================================

    /* APA ITU ARRAY OF POINTERS?
        -------------------------------------------------------
        Array yang setiap elemennya adalah sebuah POINTER.

        Array of int (biasa):
            int arr[5] = {1, 2, 3, 4, 5};
            // tiap elemen adalah int

        Array of pointer to int:
            int* ptrs[5];
            // tiap elemen adalah int* (pointer ke int)

        Visualisasi:
            ptrs[0] -> [variabel A]
            ptrs[1] -> [variabel B]
            ptrs[2] -> [alokasi heap]
            ptrs[3] -> nullptr
            ptrs[4] -> [variabel C]
    */

    /* SINTAKS DEKLARASI
        -------------------------------------------------------
        TipeData* namaArray[ukuran];

        Contoh:
            int*    arr[5];         // 5 pointer ke int
            double* dptrs[3];       // 3 pointer ke double
            char*   kata[10];       // 10 pointer ke char (array of C-string)

        JANGAN BINGUNG dengan pointer ke array:
            int (*ptr)[5];          // pointer ke array 5 int (BEDA!)
            int* arr[5];            // array dari 5 pointer ke int
    */

    /* KEGUNAAN 1: ARRAY OF STRINGS (C-STYLE)
        -------------------------------------------------------
        Cara paling klasik menyimpan kumpulan string:

            const char* bulan[] = {
                "Januari", "Februari", "Maret", "April",
                "Mei", "Juni", "Juli", "Agustus",
                "September", "Oktober", "November", "Desember"
            };

            cout << bulan[0];   // "Januari"
            cout << bulan[11];  // "Desember"

        Setiap elemen bulan[i] adalah pointer ke literal string.
        Lebih efisien dari array of std::string untuk string konstan.
    */

    /* KEGUNAAN 2: DISPATCH TABLE (TABEL PENGIRIMAN)
        -------------------------------------------------------
        Array of function pointer untuk memilih aksi secara dinamis:

            using AksiFunc = void (*)(const string&);

            void simpan(const string& data) { /* ... */ }
            void hapus(const string& data)  { /* ... */ }
            void cari (const string& data)  { /* ... */ }

            AksiFunc tabel[] = { simpan, hapus, cari };
            string nama_aksi[] = { "Simpan", "Hapus", "Cari" };

            int pilihan = 2;
            tabel[pilihan]("input");   // memanggil cari("input")

        Pola ini menghindari switch-case yang panjang dan
        memudahkan penambahan aksi baru.
    */

    /* KEGUNAAN 3: POINTER KE OBJEK POLIMORFIS (Preview OOP)
        -------------------------------------------------------
        Array of pointer sangat berguna untuk menyimpan objek
        dari berbagai tipe turunan (polymorphism):

            Hewan* kebun[3];
            kebun[0] = new Kucing();
            kebun[1] = new Anjing();
            kebun[2] = new Burung();

            for (int i = 0; i < 3; i++)
                kebun[i]->bersuara();   // virtual dispatch!

        Ini adalah pola utama OOP di C++ -- akan dibahas mendalam
        di modul 03-OOP.
    */

    /* KEGUNAAN 4: SORTING TANPA MEMINDAH DATA BESAR
        -------------------------------------------------------
        Jika objeknya besar (struct dengan banyak field), memindah-
        mindahnya saat sort sangat mahal. Solusi: sort POINTER-nya.

            Mahasiswa data[100];          // data besar, tidak dipindah
            Mahasiswa* ptrs[100];
            for (int i = 0; i < 100; i++) ptrs[i] = &data[i];

            // Sort pointer berdasarkan nilai yang ditunjuk
            sort(ptrs, ptrs + 100, [](Mahasiswa* a, Mahasiswa* b) {
                return a->ipk > b->ipk;
            });
            // data[] tidak bergerak, hanya urutan ptrs[] yang berubah
    */


// ============================================================
// Z.3 - Function Pointer Lanjutan
// ============================================================

    /* REVIEW FUNCTION POINTER DASAR
        -------------------------------------------------------
        Sudah dibahas di modul 01-Advanced-Functions file 03.
        Di sini kita bahas pola-pola yang lebih lanjut.

        Recap sintaks:
            int    tambah(int a, int b) { return a + b; }
            int (*fp)(int, int) = tambah;   // deklarasi
            fp(3, 4);                       // pemanggilan
    */

    /* FUNCTION POINTER DALAM STRUCT
        -------------------------------------------------------
        Struct bisa menyimpan function pointer sebagai "method":

            struct Operasi {
                const char* nama;
                int (*hitung)(int, int);
            };

            Operasi ops[] = {
                {"tambah", [](int a, int b){ return a+b; }},
                {"kurang", [](int a, int b){ return a-b; }},
                {"kali",   [](int a, int b){ return a*b; }},
            };

            ops[0].hitung(10, 5);   // 15
            ops[1].hitung(10, 5);   // 5

        Ini adalah versi sederhana dari "method" sebelum era OOP.
        Di C++, class menggantikan pola ini -- tapi sangat penting
        untuk memahami kode C lama dan interop.
    */

    /* FUNCTION POINTER ARRAY: DISPATCH TABLE LANJUTAN
        -------------------------------------------------------
        Menggantikan switch-case yang panjang dengan lookup O(1):

            // switch-case (sulit ditambah/ubah):
            switch (op) {
                case 0: return tambah(a, b);
                case 1: return kurang(a, b);
                case 2: return kali(a, b);
            }

            // dispatch table (mudah ditambah):
            int (*tabel[])(int,int) = { tambah, kurang, kali };
            return tabel[op](a, b);   // O(1), tanpa kondisional!
    */

    /* FUNCTION POINTER SEBAGAI RETURN VALUE
        -------------------------------------------------------
        Function bisa mengembalikan function pointer:

            // Syntax langsung (membingungkan):
            int (*pilihanOp(char op))(int, int) { ... }

            // Cara yang lebih bersih dengan alias:
            using BinaryFunc = int (*)(int, int);
            BinaryFunc pilihanOp(char op) {
                switch(op) {
                    case '+': return tambah;
                    case '-': return kurang;
                    default:  return nullptr;
                }
            }

            BinaryFunc fn = pilihanOp('+');
            fn(10, 5);   // 15
    */

    /* PASSING FUNCTION POINTER ARRAY KE FUNCTION
        -------------------------------------------------------
        Function bisa menerima array of function pointer:

            using IntBinaryOp = int (*)(int, int);

            void jalankanSemua(int a, int b,
                               IntBinaryOp ops[], int n) {
                for (int i = 0; i < n; i++)
                    cout << ops[i](a, b) << endl;
            }
    */


// ============================================================
// Z.4 - Typedef dan Using
// ============================================================

    /* MASALAH: SINTAKS POINTER YANG RUMIT
        -------------------------------------------------------
        Sintaks pointer C++ bisa sangat membingungkan:

            int (*fp)(int, int);                  // function pointer
            int (*arr)[5];                        // pointer ke array
            int* (*fp2)(int*, int*);              // function pointer yang return int*
            void (*signal(int, void(*)(int)))(int); // dari header <signal.h>!

        Tanpa alias, kode penuh dengan deklarasi yang sulit dibaca,
        sulit ditulis, dan sulit di-maintain.
    */

    /* SOLUSI 1: typedef (C-style, masih valid di C++)
        -------------------------------------------------------
        typedef tipe_lama nama_baru;

        Contoh:
            // Pointer ke int
            typedef int* IntPtr;
            IntPtr p1, p2;     // HATI-HATI: p1 dan p2 keduanya int*

            // Function pointer
            typedef int (*OperasiFunc)(int, int);
            OperasiFunc fp = tambah;   // jauh lebih bersih!

            // Pointer ke array 5 int
            typedef int (*PtrArray5)[5];
            PtrArray5 pa;

        Batasan typedef:
            - Tidak bisa untuk template (harus pakai alias template)
            - Sintaks terbalik dari C++ yang "natural"
    */

    /* SOLUSI 2: using (C++11, cara modern -- DIREKOMENDASIKAN)
        -------------------------------------------------------
        using NamaBaru = TipeLama;

        Kelebihan using atas typedef:
            - Sintaks lebih intuitif (seperti assignment)
            - Bisa untuk template alias
            - Lebih ekspresif dan mudah dibaca

        Contoh:
            // Pointer ke int
            using IntPtr = int*;

            // Function pointer
            using OperasiFunc = int (*)(int, int);
            OperasiFunc fp = tambah;

            // Pointer ke array 5 int
            using PtrArray5 = int (*)[5];

            // Template alias (hanya bisa dengan using, bukan typedef)
            template <typename T>
            using Vec = vector<T>;
            Vec<int>    angka;    // sama dengan vector<int>
            Vec<string> kata;     // sama dengan vector<string>
    */

    /* ALIAS UNTUK TIPE-TIPE UMUM DI C++
        -------------------------------------------------------
        Alias membuat kode lebih ekspresif dan self-documenting:

            // Tanpa alias (tidak jelas maksudnya):
            void proses(int (*callback)(void*, int), void* ctx);

            // Dengan alias (jelas dan mudah dibaca):
            using Callback = int (*)(void*, int);
            using Context  = void*;
            void proses(Callback callback, Context ctx);

        Alias juga berguna untuk mempersiapkan refactoring:
            using UserId = int;      // jika suatu saat berubah jadi long long,
                                     // hanya ubah satu baris ini

            using Price  = double;   // lebih ekspresif dari raw double
    */

    /* TYPEDEF vs USING: KAPAN PAKAI APA?
        -------------------------------------------------------
        Pakai typedef  : ketika berinteraksi dengan kode C lama
                         atau compiler yang belum support C++11
        Pakai using    : selalu -- ini adalah standar C++ modern

        Di kode C++ baru: SELALU pakai using.
        typedef masih valid, tidak akan hilang, tapi using lebih baik.
    */


// ============================================================
// Z.5 - Void Pointer
// ============================================================

    /* APA ITU VOID POINTER?
        -------------------------------------------------------
        void* adalah pointer yang TIDAK PUNYA TIPE -- dia bisa
        menyimpan alamat dari TIPE DATA APA PUN.

            int    x = 10;
            double d = 3.14;
            char   c = 'A';

            void* vp;
            vp = &x;    // OK: simpan alamat int
            vp = &d;    // OK: simpan alamat double
            vp = &c;    // OK: simpan alamat char

        Ini adalah pointer yang paling "generik" di C++.
    */

    /* BATASAN VOID POINTER
        -------------------------------------------------------
        Karena tidak punya tipe, void* TIDAK bisa:

        1. Di-DEREFERENCE langsung (compiler tidak tahu ukuran tipe):
               void* vp = &x;
               cout << *vp;    // ERROR: cannot dereference void pointer

        2. Dipakai untuk POINTER ARITHMETIC:
               vp++;           // ERROR: tidak tahu berapa byte per elemen

        Untuk memakai nilai di balik void*, HARUS di-CAST dulu:
               int* ip = static_cast<int*>(vp);
               cout << *ip;    // OK: 10
    */

    /* KONVERSI IMPLISIT VOID POINTER
        -------------------------------------------------------
        Di C++:
            - Tipe pointer APA PUN bisa IMPLISIT dikonversi ke void*
            - Tapi void* TIDAK bisa implisit dikonversi ke tipe lain
              (harus cast eksplisit)

            int*  ip = &x;
            void* vp = ip;         // OK: implicit conversion
            int*  ip2 = vp;        // ERROR di C++! butuh cast
            int*  ip3 = static_cast<int*>(vp);  // OK

        (Di C, void* bisa implisit ke tipe lain -- ini perbedaan C vs C++)
    */

    /* KEGUNAAN UTAMA VOID POINTER
        -------------------------------------------------------
        1. GENERIC FUNCTION di C standard library:
               void* memcpy(void* dst, const void* src, size_t n);
               void* memset(void* s, int c, size_t n);
               void  qsort(void* base, size_t n, size_t size,
                            int (*compare)(const void*, const void*));
               void* bsearch(const void* key, const void* base, ...);

           Fungsi-fungsi ini bekerja untuk SEMUA tipe karena
           menggunakan void* sebagai parameter generik.

        2. CONTEXT POINTER (membawa state ke callback):
               void jalankan(void (*callback)(void*), void* context);
               // context bisa berisi data apapun yang dibutuhkan callback

        3. INTEROP DENGAN C API:
               // Banyak library C menggunakan void* untuk genericity
               pthread_create(&thread, nullptr, threadFunc, (void*)data);

        4. IMPLEMENTASI CONTAINER GENERIK TANPA TEMPLATE (C-style):
               Sebelum ada template di C++, container generik
               diimplementasikan dengan void*. Sekarang sudah digantikan
               template, tapi kode lama banyak menggunakannya.
    */

    /* VOID POINTER DAN TYPE SAFETY
        -------------------------------------------------------
        void* mengorbankan TYPE SAFETY untuk GENERICITY.

        Risiko:
            void* vp = &angka;       // angka adalah int
            double* dp = static_cast<double*>(vp);  // SALAH tipe!
            cout << *dp;  // undefined behavior -- membaca bit int sebagai double

        Compiler TIDAK bisa mendeteksi kesalahan ini karena
        informasi tipe sudah hilang saat di-cast ke void*.

        Di C++ modern, pakai TEMPLATE agar tetap generic DAN type-safe:
            template <typename T>
            void proses(T* data) { ... }   // compiler tahu tipenya!

        Pakai void* hanya untuk interop C API atau situasi di mana
        template tidak bisa digunakan.
    */


// ============================================================
// Z.6 - Pointer Casting
// ============================================================

    /* EMPAT JENIS CAST DI C++
        -------------------------------------------------------
        C++ menyediakan empat operator cast yang eksplisit,
        menggantikan C-style cast yang tidak aman:

            (TipeData) nilai        // C-style cast -- hindari di C++!

        Empat cast C++:
            static_cast<T>       -- cast aman saat compile time
            dynamic_cast<T>      -- cast aman saat runtime (polimorfisme)
            const_cast<T>        -- hapus atau tambah const/volatile
            reinterpret_cast<T>  -- reinterpretasi bit mentah (paling berbahaya)
    */

    /* static_cast: CAST AMAN COMPILE-TIME
        -------------------------------------------------------
        Paling umum dipakai. Diverifikasi oleh compiler saat kompilasi.
        Compiler memastikan cast "masuk akal" secara tipe.

        Kegunaan:
        a. Konversi numerik:
               double d = 3.9;
               int    i = static_cast<int>(d);    // 3 (truncate)

        b. Cast antara tipe pointer yang berkaitan (up/downcast):
               Derived* d = new Derived();
               Base*    b = static_cast<Base*>(d);  // upcast -- selalu aman

        c. void* ke tipe konkret:
               void* vp  = &angka;
               int*  ip  = static_cast<int*>(vp);   // harus tahu tipe aslinya!

        d. Konversi enum ke int atau sebaliknya:
               enum class Warna { Merah, Hijau, Biru };
               int kode = static_cast<int>(Warna::Merah);
    */

    /* reinterpret_cast: REINTERPRETASI BIT MENTAH
        -------------------------------------------------------
        Paling berbahaya! Compiler tidak verifikasi apapun.
        Hanya mengubah cara MENAFSIRKAN bit yang sama di memory.

        Kegunaan yang sah:
        a. Casting antara tipe pointer yang tidak berkaitan:
               int*  ip = new int(65);
               char* cp = reinterpret_cast<char*>(ip);  // baca byte pertama

        b. Menyimpan pointer ke integer:
               uintptr_t addr = reinterpret_cast<uintptr_t>(ip);
               int* ip2 = reinterpret_cast<int*>(addr);  // kembalikan

        c. Interop dengan hardware/OS (low-level programming):
               uint32_t* reg = reinterpret_cast<uint32_t*>(0x40020000);
               // akses register hardware langsung

        PERINGATAN: Hasil reinterpret_cast hampir selalu
        implementation-defined atau undefined behavior.
        Gunakan HANYA jika benar-benar tidak ada alternatif!
    */

    /* const_cast: HAPUS ATAU TAMBAH const
        -------------------------------------------------------
        Satu-satunya cara menghapus const dari pointer.

        Kegunaan:
        a. Memanggil fungsi non-const dari pointer const:
               void cetakNama(char* nama) { cout << nama; }

               const char* nama = "Budi";
               cetakNama(const_cast<char*>(nama));  // hapus const

        b. Mengembalikan non-const dari fungsi yang menerima const:
               // Pola idiomatis untuk menghindari duplikasi:
               char* cari(char* str, char c);
               const char* cari(const char* str, char c);
               // Implementasikan satu, panggil dari yang lain

        PERINGATAN: Memodifikasi objek yang sesungguhnya const
        (bukan hanya const pointer) adalah undefined behavior!
            const int x = 10;
            int* p = const_cast<int*>(&x);
            *p = 20;   // UNDEFINED BEHAVIOR! x mungkin di read-only memory
    */

    /* dynamic_cast: CAST AMAN RUNTIME (Polimorfisme)
        -------------------------------------------------------
        Hanya untuk pointer/reference ke class dengan virtual function.
        Melakukan cek tipe saat RUNTIME (RTTI = Run-Time Type Info).

        Jika cast gagal:
            - Untuk pointer : mengembalikan nullptr
            - Untuk reference: melempar std::bad_cast

        Contoh:
            Base* b = new Derived();

            // Downcast (Base* -> Derived*):
            Derived* d = dynamic_cast<Derived*>(b);
            if (d != nullptr) {
                d->metodeDerived();   // aman!
            }

        Ini adalah satu-satunya cast yang aman untuk downcast di OOP.
        Dibahas mendalam di modul OOP (Polymorphism).
    */

    /* PANDUAN MEMILIH CAST
        -------------------------------------------------------
        Pertanyaan                           | Gunakan
        -------------------------------------|-------------------
        Konversi numerik (int <-> double)?   | static_cast
        Upcast (Derived -> Base)?            | static_cast
        Downcast dengan cek runtime?         | dynamic_cast
        Hapus/tambah const?                  | const_cast
        Reinterpretasi bit mentah?           | reinterpret_cast
        Semua hal di atas tapi unsafe?       | C-style cast (HINDARI!)

        Aturan praktis:
            Selalu gunakan C++-style cast, BUKAN C-style cast.
            C-style cast melakukan apa saja tanpa pengecekan -- sangat berbahaya.
            C++-style cast menunjukkan MAKSUD programmer dengan jelas.
    */


// ============================================================
// Z.7 - This Pointer Preview
// ============================================================

    /* APA ITU this POINTER?
        -------------------------------------------------------
        Di dalam setiap NON-STATIC member function sebuah class,
        secara implisit ada pointer bernama this yang menunjuk
        ke OBJEK yang sedang memanggil function tersebut.

        Contoh:
            class Kotak {
            public:
                int lebar;
                void setLebar(int lebar) {
                    this->lebar = lebar;   // this->lebar = member
                                           // lebar (tanpa this) = parameter
                }
            };

            Kotak k;
            k.setLebar(10);
            // Saat setLebar dipanggil, this == &k
    */

    /* TIPE DAN SIFAT this POINTER
        -------------------------------------------------------
        Tipe this di dalam member function:
            - Biasa      : TipeClass* const this
            - const func : const TipeClass* const this

        this adalah const pointer (tidak bisa diubah arahnya),
        tapi objek yang ditunjuk bisa dimodifikasi (kecuali const func).

        Di const member function:
            class Foo {
                int x;
            public:
                void ubah() const {
                    x = 10;       // ERROR: const function, tidak bisa ubah member
                    this->x = 10; // juga ERROR
                }
            };
    */

    /* KEGUNAAN this POINTER
        -------------------------------------------------------
        1. DISAMBIGUASI nama: parameter vs member dengan nama sama
               void setX(int x) {
                   this->x = x;   // this->x = member, x = parameter
               }

        2. METHOD CHAINING (Fluent Interface):
               class Builder {
               public:
                   Builder& setNama(string n)  { nama = n; return *this; }
                   Builder& setUmur(int u)     { umur = u; return *this; }
                   Builder& setEmail(string e) { email = e; return *this; }
               };

               Builder b;
               b.setNama("Budi").setUmur(20).setEmail("budi@mail.com");
               // Setiap method mengembalikan *this (objek yang sama)
               // sehingga bisa di-chain!

        3. MENERUSKAN OBJEK SENDIRI KE FUNCTION LAIN:
               void proses(Kotak* k) { ... }
               void Kotak::kirimDiri() { proses(this); }

        4. MEMBANDINGKAN OBJEK DENGAN DIRINYA SENDIRI:
               bool Kotak::sama(const Kotak& lain) const {
                   if (this == &lain) return true;  // sama persis!
                   return lebar == lain.lebar;
               }
    */

    /* this DAN RETURN *this
        -------------------------------------------------------
        Mengembalikan *this (dereferensi this) berarti mengembalikan
        OBJEK ITU SENDIRI by reference.

            class Counter {
                int count = 0;
            public:
                Counter& tambah() { count++; return *this; }
                Counter& kurang() { count--; return *this; }
                void cetak() const { cout << count << endl; }
            };

            Counter c;
            c.tambah().tambah().tambah().kurang().cetak();  // 2

        Pola ini membuat API lebih ekspresif dan ringkas.
        Dipakai di string, stream, builder pattern, dll.
    */

    /* this DI STATIC MEMBER FUNCTION
        -------------------------------------------------------
        Static member function TIDAK punya this pointer!

        Alasan: static function tidak terikat ke objek tertentu.
        Dia dipanggil lewat nama class, bukan lewat objek.

            class Foo {
                static int hitungan;
            public:
                static void reset() {
                    hitungan = 0;    // OK: akses static member
                    this->x = 0;    // ERROR: tidak ada this di static!
                }
            };

            Foo::reset();   // dipanggil tanpa objek
    */

    /* THIS POINTER SEBAGAI JEMBATAN KE OOP
        -------------------------------------------------------
        this adalah fondasi dari seluruh mekanisme OOP di C++.

        - Setiap method call secara implisit meneruskan this
        - Virtual function dispatch bergantung pada tipe yang ditunjuk this
        - Constructor dan destructor juga punya this
        - Copy assignment operator memakai this untuk deteksi self-assignment

        Saat mempelajari OOP nanti, ingat bahwa semua perilaku class
        pada akhirnya bermuara ke this pointer!
    */

// ============================================================
// END OF MATERI
// ============================================================

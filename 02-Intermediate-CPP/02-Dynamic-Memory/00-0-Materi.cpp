/*
    DAFTAR ISI MODUL DYNAMIC MEMORY
    ============================================================
    00  Overview
    01  New-Delete-Dasar
    02  Dynamic-Array
    03  Memory-Leak-dan-Deteksi
    04  Dangling-Pointer
    05  RAII-Principle               <- PENTING: jembatan ke Modern C++
    06  Smart-Pointer-Preview        <- PENTING: fondasi OOP Modern
    07  2D-Dynamic-Array
    08  Best-Practices
    ============================================================
*/

// ============================================================
// Y.0 - Overview
// ============================================================

    /* STACK vs HEAP: DUA WILAYAH MEMORY
        -------------------------------------------------------
        Memory program C++ dibagi menjadi beberapa segmen utama.
        Yang paling relevan untuk kita:

        STACK (Tumpukan)
        - Dikelola OTOMATIS oleh compiler
        - Ukuran ditentukan saat compile time
        - Variabel lokal dan parameter function ada di sini
        - Dealokasi otomatis saat keluar dari scope
        - Ukuran terbatas (biasanya 1-8 MB)
        - Sangat cepat (hanya geser stack pointer)

        Contoh alokasi Stack:
            int x = 10;           // di stack
            double arr[100];      // di stack, ukuran harus konstan

        HEAP (Free Store)
        - Dikelola MANUAL oleh programmer
        - Ukuran bisa ditentukan saat RUNTIME (fleksibel!)
        - Alokasi dengan operator new, dealokasi dengan delete
        - Tidak otomatis dibersihkan -- programmer bertanggung jawab
        - Ukuran jauh lebih besar (ratusan MB hingga GB)
        - Sedikit lebih lambat (perlu manajemen metadata)

        Contoh alokasi Heap:
            int* p = new int(10);     // di heap
            delete p;                 // programmer yang hapus!
    */

    /* MENGAPA BUTUH DYNAMIC MEMORY?
        -------------------------------------------------------
        Keterbatasan alokasi statis (stack):

        1. UKURAN HARUS DIKETAHUI SAAT COMPILE TIME
               int arr[100];      // OK
               int n;
               cin >> n;
               int arr[n];        // ERROR di standar C++ (Variable Length Array)
                                  // (beberapa compiler terima, tapi non-standar)

        2. TIDAK BISA DIUBAH UKURANNYA (TIDAK FLEKSIBEL)
               Setelah array dibuat dengan ukuran 100, tidak bisa
               diperbesar atau diperkecil saat program berjalan.

        3. TERBATAS SCOPE
               Variabel lokal mati saat function selesai.
               Tidak bisa "membawa" data besar antar function
               tanpa menyalin (kecuali lewat pointer/reference).

        Solusi: DYNAMIC MEMORY (alokasi di Heap)
               int n;
               cin >> n;
               int* arr = new int[n];   // ukuran ditentukan saat runtime!
               // ... pakai arr ...
               delete[] arr;            // hapus setelah selesai
    */

    /* KONSEP POINTER DALAM DYNAMIC MEMORY
        -------------------------------------------------------
        Alokasi heap mengembalikan POINTER ke lokasi memory yang dialokasikan.
        Pointer inilah satu-satunya cara kita mengakses data di heap.

            int* ptr = new int(42);
            //   ^           ^
            //   |           Alokasi 1 int di heap, isi dengan 42
            //   Pointer di stack yang menyimpan ALAMAT heap

        Ilustrasi memory:
            Stack:                    Heap:
            +--------+               +--------+
            | ptr    | ----------->  |   42   |
            | 0x1234 |               +--------+
            +--------+               alamat 0x1234

        Saat kita delete ptr:
            Stack:                    Heap:
            +--------+               +--------+
            | ptr    |   (invalid)   |  ????  | <- memory dibebaskan
            | 0x1234 |               +--------+
            +--------+

        BAHAYA: ptr masih menyimpan alamat 0x1234 walaupun heap sudah dibebaskan!
        Ini disebut DANGLING POINTER -- dibahas di Y.4.
    */


// ============================================================
// Y.1 - New dan Delete Dasar
// ============================================================

    /* OPERATOR new: ALOKASI HEAP
        -------------------------------------------------------
        Syntax untuk SATU objek:
            TipeData* ptr = new TipeData;           // tanpa inisialisasi
            TipeData* ptr = new TipeData();         // value-initialized (0/kosong)
            TipeData* ptr = new TipeData(nilai);    // dengan nilai awal

        Contoh:
            int*    pi = new int;        // *pi = nilai garbage
            int*    pj = new int();      // *pj = 0
            int*    pk = new int(42);    // *pk = 42
            double* pd = new double(3.14);
            string* ps = new string("Halo");

        new melakukan DUA hal sekaligus:
            1. Minta memory dari OS (heap)
            2. Memanggil constructor objek (untuk class/struct)
    */

    /* OPERATOR delete: DEALOKASI HEAP
        -------------------------------------------------------
        Syntax untuk SATU objek:
            delete ptr;     // bebaskan memory yang ditunjuk ptr

        ATURAN KETAT:
            1. delete hanya untuk memory yang dialokasikan dengan new
            2. Setelah delete, segera set ptr = nullptr
            3. Jangan delete dua kali (double free = undefined behavior!)
            4. Jangan delete pointer ke stack variable

        Pola yang BENAR:
            int* p = new int(10);
            // ... gunakan *p ...
            delete p;
            p = nullptr;       // WAJIB: cegah dangling pointer

        Yang SALAH (undefined behavior):
            int x = 5;
            int* p = &x;
            delete p;          // SALAH: p menunjuk ke stack!

            int* q = new int(7);
            delete q;
            delete q;          // SALAH: double free!
    */

    /* new DENGAN ARRAY
        -------------------------------------------------------
        Syntax:
            TipeData* arr = new TipeData[ukuran];
            // ukuran BOLEH berupa variabel (runtime!)

        Contoh:
            int n = 50;
            int* data = new int[n];       // 50 int di heap
            data[0] = 10;                 // akses seperti array biasa
            data[n-1] = 99;

        PENTING: gunakan delete[] (bukan delete) untuk array!
            delete[] data;    // BENAR: hapus array
            delete data;      // SALAH: hanya hapus elemen pertama, sisanya LEAK!

        Alasan: delete[] memanggil destructor untuk SETIAP elemen,
                sedangkan delete hanya untuk satu elemen.
    */

    /* APA YANG TERJADI JIKA new GAGAL?
        -------------------------------------------------------
        Jika heap kehabisan memory, new akan THROW EXCEPTION:
            std::bad_alloc

        Cara menangkap:
            try {
                int* besar = new int[1000000000];  // minta 4 GB!
            } catch (const bad_alloc& e) {
                cerr << "Gagal alokasi: " << e.what() << endl;
            }

        Alternatif: new (nothrow) -- tidak throw, mengembalikan nullptr
            int* p = new (nothrow) int[1000000000];
            if (p == nullptr) {
                // gagal alokasi, tangani di sini
            }

        Untuk kode yang robust, selalu tangani kemungkinan gagal alokasi.
    */


// ============================================================
// Y.2 - Dynamic Array
// ============================================================

    /* DYNAMIC ARRAY: ARRAY DENGAN UKURAN RUNTIME
        -------------------------------------------------------
        Kekuatan utama dynamic memory: ukuran array ditentukan saat program berjalan.

            int n;
            cout << "Masukkan jumlah data: ";
            cin >> n;

            int* data = new int[n];   // n baru diketahui saat runtime!

            for (int i = 0; i < n; i++) cin >> data[i];
            // ... proses data ...
            delete[] data;

        Vs array statis yang harus hardcode ukurannya:
            int data[1000];   // selalu alokasi 1000, meskipun cuma pakai 5!
    */

    /* MENGAKSES ELEMEN DYNAMIC ARRAY
        -------------------------------------------------------
        Sama persis seperti array biasa, dua cara:

        a. Notasi subscript (paling umum):
            data[0] = 10;
            cout << data[i];

        b. Notasi pointer arithmetic:
            *(data + 0) = 10;    // sama dengan data[0]
            *(data + i)          // sama dengan data[i]

        Keduanya identik secara semantik.
        Gunakan notasi subscript untuk kejelasan kode.
    */

    /* DYNAMIC ARRAY VS std::vector
        -------------------------------------------------------
        std::vector adalah dynamic array yang sudah "dibungkus rapi".

        Dynamic array manual:
            int* arr = new int[n];
            // manajemen ukuran manual
            // resize manual (alokasi baru, salin, hapus lama)
            // HARUS ingat delete[]

        std::vector<int> v(n):
            // ukuran otomatis bisa berubah (push_back, pop_back)
            // manajemen memory otomatis
            // tidak perlu delete apapun

        Kapan pakai dynamic array manual?
            - Belajar konsep dasar (saat ini!)
            - Interoperabilitas dengan API C lama
            - Implementasi container sendiri (linked list, dll)
            - Situasi yang butuh kontrol sangat detail

        Pada kode produksi modern: pakai std::vector!
    */

    /* RESIZE DYNAMIC ARRAY (MANUAL)
        -------------------------------------------------------
        Dynamic array biasa tidak bisa di-resize langsung.
        Cara manual untuk "memperbesar":

            int* arr = new int[5];          // array lama, ukuran 5
            // isi arr...

            int* arrBaru = new int[10];     // array baru, lebih besar
            for (int i = 0; i < 5; i++)
                arrBaru[i] = arr[i];        // salin isi lama

            delete[] arr;                   // hapus array lama
            arr = arrBaru;                  // arahkan pointer ke yang baru
            // sekarang arr berukuran 10

        Ini persis yang dilakukan std::vector di balik layar!
    */


// ============================================================
// Y.3 - Memory Leak dan Deteksi
// ============================================================

    /* APA ITU MEMORY LEAK?
        -------------------------------------------------------
        Memory leak terjadi ketika memory yang dialokasikan di heap
        TIDAK PERNAH DIBEBASKAN, sehingga tidak bisa dipakai lagi
        oleh program manapun hingga program berakhir.

        Penyebab paling umum:

        1. LUPA delete
               void bocor() {
                   int* p = new int(42);
                   // ... gunakan p ...
                   // LUPA delete p!
               }   // p hilang dari scope, memory 42 tetap di heap selamanya

        2. POINTER DITIMPA sebelum delete
               int* p = new int(10);
               p = new int(20);    // LEAK! memory int(10) tidak bisa diakses lagi
               delete p;           // hanya hapus int(20)

        3. EXCEPTION sebelum delete
               int* p = new int(10);
               sesuatuYangThrow();  // jika ini throw, delete tidak tercapai!
               delete p;

        4. RETURN SEBELUM delete
               int* p = new int(10);
               if (kondisi) return;   // LEAK! lupa delete sebelum return
               delete p;
    */

    /* DAMPAK MEMORY LEAK
        -------------------------------------------------------
        - Program mengonsumsi memory terus-menerus
        - Untuk program yang berjalan lama (server, daemon):
          memory habis, performa turun, akhirnya crash
        - Sulit dideteksi karena tidak ada error langsung
        - Sangat berbahaya di embedded system (memory sangat terbatas)

        Contoh nyata: server web yang tidak pernah di-restart
        bisa crash setelah beberapa hari karena memory leak kecil
        yang terakumulasi jutaan kali dari setiap request.
    */

    /* CARA MENDETEKSI MEMORY LEAK
        -------------------------------------------------------
        1. VALGRIND (Linux/Mac) -- tool paling populer
               valgrind --leak-check=full ./program

        2. ADDRESS SANITIZER (GCC/Clang)
               Compile dengan flag: -fsanitize=address
               g++ -fsanitize=address -g program.cpp -o program
               ./program

        3. VISUAL STUDIO (Windows) -- CRT Debug Library
               #include <crtdbg.h>
               _CrtDumpMemoryLeaks();  // di akhir main()

        4. MANUAL TRACKING (sederhana, untuk belajar)
               int totalAlokasi = 0;
               // setiap new: totalAlokasi++
               // setiap delete: totalAlokasi--
               // di akhir: totalAlokasi harus 0

        5. SMART POINTERS (solusi terbaik -- Y.6)
               Tidak pernah lupa delete karena otomatis!
    */

    /* POLA-POLA AMAN UNTUK MENCEGAH LEAK
        -------------------------------------------------------
        a. Single exit point: semua return path punya delete
        b. try-catch-finally pattern
        c. RAII: bungkus resource dalam objek (Y.5)
        d. Smart pointers: unique_ptr, shared_ptr (Y.6)
        e. Standard containers: vector, string, dll (tidak perlu new/delete)
    */


// ============================================================
// Y.4 - Dangling Pointer
// ============================================================

    /* APA ITU DANGLING POINTER?
        -------------------------------------------------------
        Dangling pointer adalah pointer yang masih menyimpan alamat
        memory yang sudah TIDAK VALID atau sudah DIBEBASKAN.

        Mengakses dangling pointer = UNDEFINED BEHAVIOR:
            - Program crash (segfault)
            - Data korup tanpa pesan error
            - Hasil yang tidak terduga dan tidak konsisten
            - Celah keamanan (buffer overflow exploits)

        TIGA SITUASI PALING UMUM:

        1. SETELAH delete (use-after-free)
               int* p = new int(42);
               delete p;
               cout << *p;    // BAHAYA! memory sudah dibebaskan

        2. POINTER KE VARIABEL LOKAL (pointer yang "out-of-scope")
               int* ambilPointer() {
                   int x = 10;
                   return &x;    // BAHAYA! x mati setelah function selesai
               }
               int* p = ambilPointer();
               cout << *p;       // BAHAYA! x sudah tidak ada di stack

        3. BEBERAPA POINTER KE OBJEK YANG SAMA (aliasing)
               int* p = new int(10);
               int* q = p;       // q dan p menunjuk ke tempat yang sama
               delete p;
               cout << *q;       // BAHAYA! memory sudah dibebaskan via p
    */

    /* CARA MENCEGAH DANGLING POINTER
        -------------------------------------------------------
        1. SET NULLPTR SETELAH delete
               delete p;
               p = nullptr;       // aman: akses *nullptr crash lebih jelas
               if (p != nullptr) *p = 5;  // mudah di-guard

        2. JANGAN RETURN ALAMAT VARIABEL LOKAL
               Kembalikan copy nilai, atau pakai new, atau pakai smart pointer.

        3. SATU PEMILIK JELAS (ownership)
               Tentukan siapa yang "memiliki" dan bertanggung jawab delete.
               Ini adalah konsep inti dari RAII dan Smart Pointer.

        4. PAKAI SMART POINTER (solusi permanen)
               unique_ptr otomatis null setelah move.
               shared_ptr tidak akan hapus objek selama masih ada yang pakai.
    */

    /* NULL vs NULLPTR
        -------------------------------------------------------
        NULL (cara lama, C-style): makro yang expand ke 0 atau (void*)0
            int* p = NULL;

        nullptr (C++11, cara modern): keyword khusus untuk null pointer
            int* p = nullptr;

        SELALU pakai nullptr di C++ modern karena:
            - Type-safe: tidak bisa salah dipakai sebagai int
            - Lebih jelas maksudnya
            - Tidak ada ambiguitas saat overloading function
    */


// ============================================================
// Y.5 - RAII Principle  (KONSEP KRUSIAL)
// ============================================================

    /* APA ITU RAII?
        -------------------------------------------------------
        RAII = Resource Acquisition Is Initialization
        (Perolehan Resource Terjadi Saat Inisialisasi)

        Ini adalah IDIOM PALING PENTING di C++ modern.

        PRINSIP INTI:
            Bungkus resource (memory, file, socket, mutex, dll)
            ke dalam sebuah OBJEK (class/struct).

            - Constructor  -> AMBIL resource (acquire)
            - Destructor   -> LEPAS resource (release)

        Karena destructor SELALU dipanggil saat objek keluar dari scope
        (bahkan saat exception!), resource SELALU dilepas dengan benar.

        RAII = Lifecycle resource mengikuti lifecycle objek.
    */

    /* MASALAH YANG DISELESAIKAN RAII
        -------------------------------------------------------
        Kode tanpa RAII (error-prone):

            void proses() {
                int* data = new int[100];
                File* f   = bukaFile("data.txt");

                if (kondisiError1) {
                    delete[] data;      // harus ingat hapus di SETIAP return path!
                    tutupFile(f);
                    return;
                }

                operasiYangMungkinThrow();  // jika throw, delete tidak tercapai!

                delete[] data;          // hanya tercapai jika tidak ada exception
                tutupFile(f);
            }

        Kode dengan RAII (aman otomatis):

            void proses() {
                ArrayRAII<int> data(100);   // constructor: alokasi
                FileRAII f("data.txt");     // constructor: buka file

                if (kondisiError1) return;  // destructor otomatis dipanggil!
                operasiYangMungkinThrow();  // jika throw, destructor tetap dipanggil!
            }   // destructor dipanggil di sini: delete[] dan tutup file otomatis
    */

    /* MENGAPA DESTRUCTOR SELALU DIPANGGIL?
        -------------------------------------------------------
        C++ menjamin: destructor dipanggil ketika objek keluar dari scope,
        TERMASUK saat exception propagate keluar dari scope tersebut.

        Ini disebut STACK UNWINDING:
            Saat exception terjadi, C++ "membongkar" stack dari titik
            exception ke titik catch, dan memanggil destructor SEMUA
            objek lokal yang scope-nya dilewati.

        Inilah mengapa RAII bekerja sempurna dengan exception!
    */

    /* IMPLEMENTASI RAII SEDERHANA
        -------------------------------------------------------
        template <typename T>
        class ArrayRAII {
        private:
            T* data;
            int ukuran;

        public:
            ArrayRAII(int n) : ukuran(n) {
                data = new T[n];       // ACQUIRE: alokasi di constructor
            }

            ~ArrayRAII() {
                delete[] data;         // RELEASE: dealokasi di destructor (SELALU!)
            }

            T& operator[](int i) { return data[i]; }  // akses seperti array
            int size() const { return ukuran; }

            // Nonaktifkan copy untuk menghindari double-free
            ArrayRAII(const ArrayRAII&) = delete;
            ArrayRAII& operator=(const ArrayRAII&) = delete;
        };

        Penggunaan:
            {
                ArrayRAII<int> arr(50);   // constructor dipanggil
                arr[0] = 10;
                // ...
            }   // destructor otomatis dipanggil di sini -- tidak ada leak!
    */

    /* RAII DALAM STANDARD LIBRARY
        -------------------------------------------------------
        SELURUH standard library C++ didesain dengan RAII:

        Resource              | Wrapper RAII
        ----------------------|--------------------------
        Heap memory           | unique_ptr, shared_ptr
        Array di heap         | unique_ptr<T[]>, vector<T>
        File                  | fstream (buka di ctor, tutup di dtor)
        Mutex                 | lock_guard, unique_lock
        Thread                | jthread (C++20)
        Database connection   | (desain sendiri dengan RAII)

        Implikasi: pada kode C++ modern yang baik, operator new dan delete
        RAW (langsung) JARANG muncul -- semuanya dibungkus oleh RAII wrapper.
    */

    /* RAII DAN OOP: JEMBATAN PENTING
        -------------------------------------------------------
        RAII adalah salah satu MOTIVASI UTAMA mengapa OOP (class) ada di C++.

        Tanpa class: tidak ada destructor, tidak ada RAII, resource harus
                     dikelola manual di setiap tempat.

        Dengan class: destructor memastikan resource dilepas otomatis,
                      program menjadi aman dan bebas leak.

        Ketika nanti belajar OOP, ingat: constructor dan destructor
        adalah implementasi RAII di dalam class!
    */


// ============================================================
// Y.6 - Smart Pointer Preview  (KONSEP KRUSIAL)
// ============================================================

    /* APA ITU SMART POINTER?
        -------------------------------------------------------
        Smart pointer adalah IMPLEMENTASI RAII untuk memory management.
        Mereka adalah class yang "membungkus" raw pointer dan
        mengelola lifetime objek yang ditunjuknya secara otomatis.

        Header: #include <memory>

        Tiga jenis smart pointer C++11:
            1. unique_ptr  -> kepemilikan EKSKLUSIF (satu pemilik)
            2. shared_ptr  -> kepemilikan BERSAMA (banyak pemilik, reference counting)
            3. weak_ptr    -> pengamatan tanpa kepemilikan (cegah circular reference)
    */

    /* unique_ptr: KEPEMILIKAN EKSKLUSIF
        -------------------------------------------------------
        - Satu unique_ptr = satu-satunya pemilik objek
        - Otomatis delete saat keluar scope (atau di-reset)
        - TIDAK bisa di-copy (untuk mencegah dua pemilik)
        - BISA di-move (transfer kepemilikan)
        - Overhead nol dibanding raw pointer!

        Syntax:
            unique_ptr<TipeData> ptr = make_unique<TipeData>(args);

        Contoh:
            // Cara lama (raw pointer):
            int* p = new int(42);
            // ... pakai p ...
            delete p;   // HARUS ingat!

            // Cara baru (unique_ptr):
            auto p = make_unique<int>(42);
            // ... pakai *p ...
            // delete otomatis saat p keluar scope!

        Transfer kepemilikan dengan move:
            auto p1 = make_unique<int>(42);
            auto p2 = move(p1);   // p1 sekarang nullptr, p2 jadi pemilik
    */

    /* shared_ptr: KEPEMILIKAN BERSAMA
        -------------------------------------------------------
        - BEBERAPA shared_ptr bisa menunjuk ke objek yang sama
        - Menggunakan REFERENCE COUNTING: hitung berapa banyak
          shared_ptr yang masih menunjuk ke objek
        - Objek didelete ketika reference count mencapai NOL
        - Bisa di-copy (increment reference count)
        - Ada overhead: menyimpan reference counter di heap

        Syntax:
            shared_ptr<TipeData> ptr = make_shared<TipeData>(args);

        Contoh:
            auto sp1 = make_shared<int>(100);  // count = 1
            auto sp2 = sp1;                    // count = 2 (copy!)
            auto sp3 = sp1;                    // count = 3

            // sp3 keluar scope -> count = 2
            // sp2 keluar scope -> count = 1
            // sp1 keluar scope -> count = 0 -> DELETE otomatis!

        Berguna saat: satu objek perlu "dimiliki" banyak tempat sekaligus.
    */

    /* weak_ptr: PENGAMATAN TANPA KEPEMILIKAN
        -------------------------------------------------------
        - Menunjuk ke objek yang dikelola shared_ptr
        - TIDAK menambah reference count
        - Tidak mencegah objek dari deletion
        - Harus di-"lock" dulu sebelum dipakai (bisa sudah null!)

        Kegunaan utama: memutus CIRCULAR REFERENCE pada shared_ptr.

        Masalah circular reference:
            struct A { shared_ptr<B> b; };
            struct B { shared_ptr<A> a; };

            auto a = make_shared<A>();
            auto b = make_shared<B>();
            a->b = b;    // A menunjuk B, count B = 2
            b->a = a;    // B menunjuk A, count A = 2
            // Keduanya keluar scope: count A=1, count B=1 -> TIDAK PERNAH 0 -> LEAK!

        Solusi dengan weak_ptr:
            struct B { weak_ptr<A> a; };  // weak, tidak tambah count
            // Sekarang saat keduanya keluar scope: count A=0 -> delete A -> count B=0 -> delete B
    */

    /* MEMILIH SMART POINTER YANG TEPAT
        -------------------------------------------------------
        Pertanyaan             | Jawaban         | Gunakan
        -----------------------|-----------------|------------------
        Satu pemilik jelas?    | Ya              | unique_ptr
        Kepemilikan bersama?   | Ya              | shared_ptr
        Hanya ingin observe?   | Ya              | weak_ptr
        Perlu performa maks?   | Ya              | unique_ptr (zero overhead)
        API C lama / legacy?   | Ya              | raw pointer (hati-hati!)

        PANDUAN UMUM:
            - Default: pakai unique_ptr
            - Jika perlu shared ownership: pakai shared_ptr
            - Untuk cegah circular reference: pakai weak_ptr
            - RAW new/delete: hanya jika benar-benar perlu
    */

    /* make_unique vs make_shared vs new langsung
        -------------------------------------------------------
        SELALU pakai make_unique dan make_shared, BUKAN new langsung!

        Kenapa? Pertimbangkan:
            // BERPOTENSI LEAK (jika exception antara new dan smart pointer):
            shared_ptr<int> p(new int(42));   // dua operasi terpisah

            // AMAN (atomik, exception-safe):
            auto p = make_shared<int>(42);    // satu operasi

        Selain itu, make_shared lebih efisien: mengalokasikan
        objek dan reference counter dalam SATU alokasi heap.
    */

    /* SMART POINTER DAN OOP
        -------------------------------------------------------
        Smart pointer sangat penting di OOP modern C++:

        - Menggantikan raw pointer sebagai member class
        - Mengelola objek polimorfis (base/derived class)
        - Membangun ownership graph yang jelas
        - Menghindari destructor yang kompleks

        Contoh penggunaan di OOP:
            class Kendaraan {
                unique_ptr<Mesin>  mesin;     // Kendaraan PUNYA Mesin (komposisi)
                shared_ptr<Bahan>  bahan;     // bisa berbagi Bahan dengan kendaraan lain
            };

        Ini adalah cara C++ modern mendesain hubungan antar objek!
    */


// ============================================================
// Y.7 - 2D Dynamic Array
// ============================================================

    /* PENDEKATAN 1: POINTER-TO-POINTER (Array of Pointers)
        -------------------------------------------------------
        Cara klasik: alokasi array pointer, lalu alokasi tiap baris.

            int** matriks = new int*[baris];         // alokasi array pointer
            for (int i = 0; i < baris; i++) {
                matriks[i] = new int[kolom];         // alokasi tiap baris
            }

            // Akses:
            matriks[i][j] = 10;                      // natural, seperti array 2D biasa

            // Dealokasi (urutan TERBALIK dari alokasi!):
            for (int i = 0; i < baris; i++) {
                delete[] matriks[i];                 // hapus tiap baris dulu
            }
            delete[] matriks;                        // hapus array pointer
    */

    /* PENDEKATAN 2: ARRAY 1D YANG DIPERLAKUKAN SEBAGAI 2D
        -------------------------------------------------------
        Lebih efisien: satu blok memory yang berkesinambungan.

            int* matriks = new int[baris * kolom];

            // Akses elemen [i][j]:
            matriks[i * kolom + j] = 10;

            // Dealokasi:
            delete[] matriks;   // satu delete saja!

        Kelebihan:
            - Cache-friendly (satu blok memori berkesinambungan)
            - Dealokasi lebih sederhana
            - Lebih cepat dari pendekatan 1

        Kekurangan:
            - Akses lebih verbose: matriks[i * kolom + j] bukan matriks[i][j]
            - Bisa dibungkus dengan function atau class helper
    */

    /* PERBANDINGAN DUA PENDEKATAN
        -------------------------------------------------------
        Fitur                    | Pointer-to-Pointer  | Array 1D
        -------------------------|---------------------|----------
        Akses syntax             | arr[i][j]           | arr[i*k+j]
        Memory layout            | Terpisah-pisah      | Berkesinambungan
        Cache performance        | Kurang              | Lebih baik
        Ukuran baris bisa beda   | YA (jagged array)   | Tidak
        Dealokasi                | Loop + delete[]     | Satu delete[]
        Kompleksitas             | Lebih kompleks      | Lebih sederhana
        -------------------------|---------------------|----------

        Rekomendasi: untuk matriks standar, pakai array 1D.
        Untuk "jagged array" (tiap baris ukuran beda): pakai pointer-to-pointer.
    */

    /* ALTERNATIF MODERN: vector of vector
        -------------------------------------------------------
        Cara paling aman dan nyaman untuk 2D array di C++ modern:

            vector<vector<int>> matriks(baris, vector<int>(kolom, 0));
            matriks[i][j] = 10;   // akses natural
            // Tidak perlu delete! Otomatis dikelola.

        Untuk performa tinggi (matrix besar): pakai library seperti
        Eigen atau gunakan array 1D dengan wrapper class.
    */


// ============================================================
// Y.8 - Best Practices
// ============================================================

    /* ATURAN EMAS DYNAMIC MEMORY
        -------------------------------------------------------
        1. EVERY new HAS A delete, EVERY new[] HAS A delete[]
               Jangan pernah campur: new + delete[], atau new[] + delete

        2. SET nullptr SETELAH delete
               delete p;
               p = nullptr;   // cegah use-after-free dan double-delete

        3. CEGAH DOUBLE FREE
               if (p != nullptr) {
                   delete p;
                   p = nullptr;
               }

        4. PREFER SMART POINTER ATAS RAW POINTER
               Selalu mulai dengan unique_ptr atau shared_ptr.
               Gunakan raw new/delete hanya jika benar-benar perlu.

        5. PREFER STANDARD CONTAINERS ATAS DYNAMIC ARRAY MANUAL
               vector, string, deque, dll sudah mengelola memory dengan benar.

        6. RAII: BUNGKUS RESOURCE DALAM OBJEK
               Jangan biarkan resource "bebas" di luar class/struct.
    */

    /* OWNERSHIP: KONSEP PALING KRITIS
        -------------------------------------------------------
        Setiap objek di heap HARUS punya pemilik yang jelas.
        Pemilik bertanggung jawab melakukan delete saat waktunya.

        Ownership bisa:
        a. UNIK (satu pemilik)    -> unique_ptr
        b. BERSAMA (banyak)       -> shared_ptr
        c. TIDAK ADA (observasi)  -> weak_ptr / raw pointer (non-owning)

        Panduan untuk raw pointer:
            Jika sebuah function menerima raw pointer, ia biasanya
            TIDAK memiliki objek tersebut -- hanya menggunakannya.
            Yang alokasi, yang bertanggung jawab delete.

        Dokumentasikan ownership secara eksplisit di kode!
    */

    /* HIERARKI PILIHAN MEMORY MANAGEMENT
        -------------------------------------------------------
        (Urutan dari PALING DISARANKAN ke paling tidak disarankan)

        1. Variabel lokal di stack
               int x = 10;    -- paling sederhana, paling aman

        2. Standard containers
               vector<int>, string, array<int,N>  -- RAII built-in

        3. unique_ptr
               Untuk single ownership dynamic allocation

        4. shared_ptr
               Untuk shared ownership (hati-hati circular reference)

        5. Raw new/delete
               Hanya jika 1-4 tidak bisa dipakai (misalnya API lama)
               Wajib sangat hati-hati dan dokumentasikan dengan baik

        Di C++ modern: raw new dan delete di luar class JARANG muncul!
    */

    /* POLA UMUM YANG HARUS DIHINDARI
        -------------------------------------------------------
        X   int* p = new int(5); return p;    // siapa yang delete? tidak jelas!
        X   p = new int(9);                   // lupa delete sebelum reassign
        X   int* q = p; delete p; cout << *q; // dangling pointer!
        X   delete p; delete p;               // double free!
        X   int arr[n];                       // VLA, non-standar

        Cara yang BENAR:
        V   auto p = make_unique<int>(5);     // return unique_ptr, ownership jelas
        V   p.reset(new int(9));              // lama didelete dulu
        V   shared_ptr<int> sp = ...;         // banyak pemilik aman dengan refcount
    */

    /* CODA: PERJALANAN DARI C++ LAMA KE MODERN
        -------------------------------------------------------
        C++ lama (pre-C++11):
            - new / delete di mana-mana
            - Memory management manual, error-prone
            - Programmer harus sangat disiplin

        C++11 ke atas (Modern C++):
            - Smart pointer: unique_ptr, shared_ptr, weak_ptr
            - Move semantics: transfer ownership tanpa copy
            - Range-based for: tidak perlu pointer iterasi manual
            - Standard containers: sudah RAII by design

        Dampak:
            - Memory leak dan dangling pointer jauh berkurang
            - Kode lebih singkat, lebih aman, lebih expressif
            - Performa tetap sama (zero-overhead abstraction)

        Modul ini mengajarkan DASAR agar kamu mengerti MENGAPA
        smart pointer dan RAII ada. Setelah OOP, kamu akan memakai
        semua konsep ini secara natural setiap hari!
    */

// ============================================================
// END OF MATERI
// ============================================================

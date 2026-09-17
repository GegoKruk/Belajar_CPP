/*
    DAFTAR ISI MODUL ADVANCED FUNCTIONS
    ============================================================
    00  Overview                    <- kamu di sini
    01  Function-Templates
    02  Lambda-Functions
    03  Function-Pointers
    04  Callback-Pattern
    05  Rekursi-Lanjutan
    06  Tail-Recursion
    07  Closures-dan-Capture
    08  std-function
    ============================================================
*/

// X.0 - Overview

    /* APA ITU ADVANCED FUNCTIONS?
        -------------------------------------------------------
        Di modul Fundamental, kita sudah mengenal function dasar:
        deklarasi, parameter, return value, overloading, recursion.

        Di modul ini, kita naik level ke fitur-fitur function
        yang lebih powerful dan banyak dipakai di dunia nyata:

        - Function Templates  : function yang bisa bekerja untuk
                                berbagai tipe data sekaligus
        - Lambda Functions    : function anonim yang bisa ditulis
                                langsung di tempat pemakaiannya
        - Function Pointers   : menyimpan alamat function ke dalam
                                variabel, lalu memanggilnya dinamis
        - Callback Pattern    : meneruskan function sebagai argumen
                                agar perilaku bisa dikustomisasi
        - Rekursi Lanjutan    : teknik rekursi yang lebih kompleks
                                dan pola-pola rekursi umum
        - Tail Recursion      : optimasi rekursi agar tidak stack overflow
        - Closures & Capture  : lambda yang "menangkap" variabel dari
                                lingkup sekitarnya
        - std::function       : tipe data serbaguna untuk menyimpan
                                semua jenis callable (fungsi, lambda, dll)
    */

    /* MENGAPA PENTING?
        -------------------------------------------------------
        Kemampuan ini adalah FONDASI dari banyak konsep lanjutan:

        1. Template -> dasar dari Standard Template Library (STL)
        2. Lambda   -> dipakai bersama STL (sort, find, for_each, dll)
        3. Callback -> dasar dari event-driven programming & design pattern
        4. Rekursi  -> dipakai di Tree, Graph, Divide & Conquer
        5. std::function -> dipakai di design pattern Strategy, Command

        Tanpa ini, kode kita terbatas dan tidak fleksibel.
    */

    /* PETA KETERGANTUNGAN
        -------------------------------------------------------
        Function Templates  -> dipakai di STL, class templates
        Lambda Functions    -> bergantung pada capture (Closures)
        Function Pointers   -> dipakai di Callback Pattern
        std::function       -> membungkus FP, lambda, dan functor

        Urutan belajar yang disarankan:
            01 -> 02 -> 07 -> 08 -> 03 -> 04 -> 05 -> 06
        (Tapi urutan file ini sudah disusun bertahap dari mudah ke sulit)
    */


// X.1 - Function Templates

    /* APA ITU TEMPLATE?
        -------------------------------------------------------
        Template adalah cara membuat function (atau class) yang
        GENERIK -- bisa bekerja untuk BERBAGAI TIPE DATA
        tanpa perlu menulis ulang kodenya.

        Tanpa template (repetitif):
            int    tambah(int a, int b)    { return a + b; }
            double tambah(double a, double b) { return a + b; }
            string tambah(string a, string b) { return a + b; }

        Dengan template (satu definisi, semua tipe):
            template <typename T>
            T tambah(T a, T b) { return a + b; }

        Compiler akan secara otomatis membuat versi yang tepat
        saat function dipanggil -- ini disebut INSTANTIATION.
    */

    /* SYNTAX DASAR FUNCTION TEMPLATE
        -------------------------------------------------------
        template <typename T>
        T namaFunction(T param1, T param2) {
            // T bisa dipakai seperti tipe data biasa
            T hasil = param1 + param2;
            return hasil;
        }

        Kata kunci:
            template  -> memberi tahu compiler ini adalah template
            typename  -> "T adalah nama untuk suatu tipe data"
            T         -> nama placeholder tipe (bebas, konvensi: T, U, V)
            <class T> -> alternatif dari <typename T>, maknanya sama
    */

    /* MULTIPLE TYPE PARAMETERS
        -------------------------------------------------------
        Template bisa punya lebih dari satu parameter tipe:

            template <typename T, typename U>
            void cetak(T a, U b) {
                cout << a << " dan " << b << endl;
            }

            cetak(10, 3.14);          // T=int, U=double
            cetak("halo", true);      // T=string, U=bool
    */

    /* EXPLICIT INSTANTIATION
        -------------------------------------------------------
        Biasanya compiler menebak tipe secara otomatis (deduction).
        Tapi kita bisa eksplisit menyebutkan tipenya:

            tambah<int>(5, 3);        // eksplisit: T=int
            tambah<double>(2.5, 1.5); // eksplisit: T=double
            tambah(5, 3);             // otomatis: T=int (deduction)
    */

    /* TEMPLATE SPECIALIZATION (Preview)
        -------------------------------------------------------
        Kadang perilaku umum template tidak cocok untuk tipe tertentu.
        Kita bisa buat versi khusus (specialization):

            template <>           // specialization untuk char*
            char* tambah(char* a, char* b) {
                // implementasi khusus untuk C-string
            }

        Ini dibahas lebih dalam di modul Advanced C++.
    */

    /* BATASAN TEMPLATE
        -------------------------------------------------------
        1. Kode template biasanya harus berada di FILE HEADER (.h)
           bukan di .cpp terpisah -- karena compiler butuh melihat
           definisinya saat melakukan instantiation.

        2. Error message template bisa panjang dan membingungkan.

        3. Operator yang dipakai di dalam template harus VALID
           untuk tipe yang diberikan. Contoh: jika ada "a + b",
           maka tipe T harus mendukung operator +.

        Solusi modern: C++20 Concepts (pembatas tipe eksplisit).
        Tapi ini baru dibahas di modul Expert.
    */

    /* RINGKASAN
        -------------------------------------------------------
        Tanpa template : N fungsi untuk N tipe -> duplikasi kode
        Dengan template: 1 definisi untuk semua tipe -> DRY (Don't Repeat Yourself)

        Template adalah pondasi dari STL (vector, sort, pair, dll).
        Semua container STL adalah class template!
    */


// X.2 - Lambda Functions

    /* APA ITU LAMBDA?
        -------------------------------------------------------
        Lambda adalah FUNCTION ANONIM -- function tanpa nama yang
        bisa ditulis langsung di tempat ia digunakan.

        Function biasa:
            void salam() { cout << "Halo!"; }
            salam();   // dipanggil di tempat lain

        Lambda:
            auto salam = []() { cout << "Halo!"; };
            salam();   // dipanggil langsung

        Lambda bisa dibuat sekali pakai, atau disimpan ke variabel.
    */

    /* ANATOMY LAMBDA
        -------------------------------------------------------
        [capture] (parameter) -> return_type { body }

        Bagian-bagian:
            [capture]      : variabel dari luar yang "ditangkap"
                             (dibahas detail di X.7 - Closures)
            (parameter)    : parameter input, seperti function biasa
            -> return_type : tipe return (opsional, bisa diotomatis)
            { body }       : isi fungsi

        Contoh lengkap:
            auto tambah = [](int a, int b) -> int {
                return a + b;
            };

        Versi minimal (tanpa capture, tanpa parameter, return void):
            auto sapa = [] { cout << "Halo"; };
    */

    /* BERBAGAI BENTUK LAMBDA
        -------------------------------------------------------
        a. Tanpa parameter, tanpa return:
            auto f = [] { cout << "hi"; };

        b. Dengan parameter:
            auto kuadrat = [](int x) { return x * x; };

        c. Dengan return type eksplisit:
            auto bagi = [](double a, double b) -> double {
                return a / b;
            };

        d. Dengan capture (lihat X.7):
            int n = 10;
            auto tambahN = [n](int x) { return x + n; };
    */

    /* LAMBDA DAN STL
        -------------------------------------------------------
        Kekuatan lambda terasa saat dipakai bersama algoritma STL:

            vector<int> v = {5, 2, 8, 1, 9, 3};

            // Sort dengan lambda sebagai pembanding
            sort(v.begin(), v.end(), [](int a, int b) {
                return a > b;   // descending
            });

            // Cari elemen dengan kondisi tertentu
            auto it = find_if(v.begin(), v.end(), [](int x) {
                return x > 7;
            });

            // Lakukan sesuatu untuk setiap elemen
            for_each(v.begin(), v.end(), [](int x) {
                cout << x << " ";
            });

        Tanpa lambda, semua ini butuh function terpisah!
    */

    /* LAMBDA YANG DIPANGGIL LANGSUNG (IIFE)
        -------------------------------------------------------
        Lambda bisa langsung dipanggil tanpa disimpan ke variabel:
        Ini disebut IIFE (Immediately Invoked Function Expression):

            int hasil = [](int a, int b) { return a + b; }(5, 3);
            // hasil = 8

        Jarang dipakai di C++, tapi berguna untuk inisialisasi
        variabel kompleks (const initialization).
    */


// X.3 - Function Pointers

    /* APA ITU FUNCTION POINTER?
        -------------------------------------------------------
        Setiap function di C++ memiliki ALAMAT di memory, sama
        seperti variabel. Function pointer adalah variabel yang
        menyimpan ALAMAT sebuah function.

        Dengan menyimpan alamat function, kita bisa:
        - Memilih function mana yang dipanggil saat runtime
        - Meneruskan function sebagai argumen ke function lain
        - Menyimpan daftar function dalam array
    */

    /* SYNTAX FUNCTION POINTER
        -------------------------------------------------------
        Deklarasi function pointer:
            return_type (*namaPointer)(tipe_param1, tipe_param2);

        Contoh untuk function:
            int tambah(int a, int b) { return a + b; }

        Pointer-nya:
            int (*fp)(int, int);    // deklarasi
            fp = tambah;            // assign (tanpa tanda &)
            fp = &tambah;           // ini juga valid, sama saja

        Memanggil via pointer:
            int hasil = fp(5, 3);   // sama seperti tambah(5, 3)
            int hasil2 = (*fp)(5, 3);  // cara lama, juga valid
    */

    /* TYPEDEF UNTUK FUNCTION POINTER
        -------------------------------------------------------
        Syntax function pointer bisa membingungkan. Solusinya:

        Cara lama (typedef):
            typedef int (*OperasiFunc)(int, int);
            OperasiFunc fp = tambah;

        Cara modern (using alias, C++11):
            using OperasiFunc = int (*)(int, int);
            OperasiFunc fp = tambah;

        Dengan alias, kode jadi jauh lebih mudah dibaca.
    */

    /* ARRAY OF FUNCTION POINTERS
        -------------------------------------------------------
        Bisa membuat array yang berisi beberapa function:

            int tambah(int a, int b) { return a + b; }
            int kurang(int a, int b) { return a - b; }
            int kali  (int a, int b) { return a * b; }

            int (*ops[3])(int, int) = { tambah, kurang, kali };

            // Panggil berdasarkan index
            ops[0](10, 5);   // 15
            ops[1](10, 5);   // 5
            ops[2](10, 5);   // 50

        Ini adalah dasar dari DISPATCH TABLE.
    */

    /* FUNCTION POINTER vs LAMBDA
        -------------------------------------------------------
        Function pointer hanya bisa menyimpan:
            - Regular function biasa
            - Static member function

        Tidak bisa menyimpan:
            - Lambda dengan capture (punya state tersembunyi)
            - Non-static member function
            - Functor (objek yang bisa dipanggil)

        Untuk yang lebih fleksibel, gunakan std::function (X.8).
    */


// X.4 - Callback Pattern

    /* APA ITU CALLBACK?
        -------------------------------------------------------
        Callback adalah FUNCTION yang diteruskan sebagai ARGUMEN
        ke function lain, untuk dipanggil di waktu yang tepat.

        Idenya: "Kamu kerjakan tugasmu, kalau selesai HUBUNGI INI."

        Manfaat utama:
        - Mengubah perilaku function tanpa mengubah kodenya
        - Memisahkan MEKANISME dari KEBIJAKAN
        - Dasar dari event-driven programming
    */

    /* CONTOH TANPA CALLBACK (terbatas)
        -------------------------------------------------------
        // Function hanya bisa sort ascending, tidak bisa dikustomisasi
        void urutkan(int arr[], int n) {
            for (int i = 0; i < n-1; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (arr[j] > arr[j+1])    // HARDCODED: selalu ascending
                        swap(arr[j], arr[j+1]);
        }
    */

    /* CONTOH DENGAN CALLBACK (fleksibel)
        -------------------------------------------------------
        // Kondisi perbandingan diserahkan ke pemanggil (callback)
        void urutkan(int arr[], int n, bool (*bandingkan)(int, int)) {
            for (int i = 0; i < n-1; i++)
                for (int j = 0; j < n-i-1; j++)
                    if (bandingkan(arr[j], arr[j+1]))   // DINAMIS!
                        swap(arr[j], arr[j+1]);
        }

        bool lebihBesar(int a, int b) { return a > b; }
        bool lebihKecil(int a, int b) { return a < b; }

        urutkan(data, n, lebihBesar);   // descending
        urutkan(data, n, lebihKecil);   // ascending
    */

    /* CALLBACK DENGAN LAMBDA (cara modern)
        -------------------------------------------------------
        urutkan(data, n, [](int a, int b) { return a > b; });

        Lambda langsung ditulis di tempat pemakaian, tanpa perlu
        mendeklarasikan function terpisah.
    */

    /* POLA-POLA CALLBACK UMUM
        -------------------------------------------------------
        1. Comparator     : menentukan urutan (sort, priority queue)
        2. Predicate      : menentukan kondisi (find_if, count_if)
        3. Transformer    : mengubah nilai (transform, map)
        4. Event Handler  : merespons kejadian (GUI, networking)
        5. Visitor        : mengunjungi setiap elemen (tree traversal)
    */

    /* CALLBACK DALAM KEHIDUPAN NYATA
        -------------------------------------------------------
        - std::sort(v.begin(), v.end(), komparator)
        - std::find_if(v.begin(), v.end(), predikat)
        - std::transform(v.begin(), v.end(), out.begin(), transformer)
        - Event listener di GUI (onClick, onHover, dll)
        - Completion handler di networking (onSuccess, onError)
    */


// X.5 - Rekursi Lanjutan

    /* REVIEW: APA ITU REKURSI?
        -------------------------------------------------------
        Rekursi adalah teknik di mana FUNCTION MEMANGGIL DIRINYA SENDIRI.
        Setiap rekursi wajib punya:
            1. BASE CASE  : kondisi berhenti (agar tidak infinite loop)
            2. RECURSIVE CASE: pemanggilan diri sendiri dengan input lebih kecil
    */

    /* REKURSI LINEAR
        -------------------------------------------------------
        Paling sederhana: satu pemanggilan rekursif per eksekusi.

            int faktorial(int n) {
                if (n <= 1) return 1;       // base case
                return n * faktorial(n - 1); // recursive case
            }

        Call stack untuk faktorial(4):
            faktorial(4) -> 4 * faktorial(3)
            faktorial(3) -> 3 * faktorial(2)
            faktorial(2) -> 2 * faktorial(1)
            faktorial(1) -> 1  (base case!)
            -- mundur --
            faktorial(2) = 2 * 1 = 2
            faktorial(3) = 3 * 2 = 6
            faktorial(4) = 4 * 6 = 24
    */

    /* REKURSI BINARY
        -------------------------------------------------------
        Dua pemanggilan rekursif per eksekusi. Membentuk POHON panggilan.

            int fibonacci(int n) {
                if (n <= 1) return n;
                return fibonacci(n-1) + fibonacci(n-2);
            }

        MASALAH: banyak perhitungan yang diulang!
            fibonacci(5) memanggil fibonacci(3) DUA KALI.
            Kompleksitas: O(2^n) -- sangat lambat untuk n besar!

        SOLUSI: Memoization (simpan hasil yang sudah dihitung):
            map<int,int> memo;
            int fib(int n) {
                if (n <= 1) return n;
                if (memo.count(n)) return memo[n];   // sudah ada? pakai!
                return memo[n] = fib(n-1) + fib(n-2);
            }
    */

    /* REKURSI MUTUAL (SALING MEMANGGIL)
        -------------------------------------------------------
        Dua function yang saling memanggil satu sama lain.

            bool isEven(int n);
            bool isOdd(int n);

            bool isEven(int n) {
                if (n == 0) return true;
                return isOdd(n - 1);
            }

            bool isOdd(int n) {
                if (n == 0) return false;
                return isEven(n - 1);
            }

        Butuh FORWARD DECLARATION karena isEven pakai isOdd
        yang belum didefinisikan saat itu.
    */

    /* BACKTRACKING: REKURSI DENGAN MUNDUR
        -------------------------------------------------------
        Pola di mana kita mencoba suatu pilihan, lalu "mundur"
        jika pilihan itu tidak berhasil.

        Kerangka umum:
            void selesaikan(State state) {
                if (tujuanTercapai(state)) {
                    simpanSolusi(state);
                    return;
                }
                for (Pilihan p : semuaPilihan(state)) {
                    terapkan(p, state);         // maju
                    selesaikan(state);          // rekursi
                    batalkan(p, state);         // MUNDUR (backtrack)
                }
            }

        Contoh penggunaan: N-Queens, Sudoku solver, maze solving,
        generate semua permutasi / kombinasi.
    */

    /* REKURSI vs ITERASI
        -------------------------------------------------------
        Rekursi:
            + Kode lebih bersih dan dekat dengan definisi matematika
            + Mudah untuk masalah yang rekursif secara natural (tree, dll)
            - Overhead call stack per pemanggilan
            - Risiko stack overflow jika terlalu dalam

        Iterasi:
            + Lebih efisien (tidak ada overhead call stack)
            + Tidak risiko stack overflow
            - Kode bisa lebih kompleks untuk masalah rekursif
    */


// X.6 - Tail Recursion

    /* APA ITU TAIL RECURSION?
        -------------------------------------------------------
        Tail recursion adalah bentuk rekursi di mana pemanggilan
        rekursif adalah OPERASI TERAKHIR yang dilakukan function.

        BUKAN tail recursion (masih ada operasi setelah rekursi):
            int faktorial(int n) {
                if (n <= 1) return 1;
                return n * faktorial(n - 1);  // masih ada perkalian!
            }
            // Setelah faktorial(n-1) selesai, kita kalikan dengan n.
            // Artinya frame stack harus DITAHAN sampai rekursi selesai.

        ADALAH tail recursion (rekursi adalah operasi terakhir):
            int faktorialHelper(int n, int akumulator) {
                if (n <= 1) return akumulator;
                return faktorialHelper(n - 1, n * akumulator);  // TERAKHIR!
            }
            // Tidak ada pekerjaan setelah pemanggilan rekursif.
    */

    /* MENGAPA TAIL RECURSION PENTING?
        -------------------------------------------------------
        Compiler yang mendukung TCO (Tail Call Optimization) bisa
        mengubah tail recursion menjadi LOOP secara otomatis!

        Artinya:
            - Tidak menambah frame baru ke call stack
            - Stack usage: O(1), bukan O(n)
            - Tidak ada risiko stack overflow!

        Di C++, TCO tidak dijamin oleh standar, tapi compiler seperti
        GCC dan Clang biasanya melakukannya dengan flag optimasi (-O2).
    */

    /* POLA KONVERSI KE TAIL RECURSION
        -------------------------------------------------------
        Teknik: tambahkan PARAMETER AKUMULATOR yang membawa
        hasil komputasi dari langkah sebelumnya.

        Non-tail -> Tail:
            // Non-tail
            int sum(int n) {
                if (n == 0) return 0;
                return n + sum(n - 1);   // n ditahan di stack!
            }

            // Tail (dengan akumulator)
            int sumHelper(int n, int acc) {
                if (n == 0) return acc;
                return sumHelper(n - 1, acc + n);   // acc membawa total
            }
            int sum(int n) { return sumHelper(n, 0); }

        Pola ini disebut ACCUMULATOR PATTERN.
    */

    /* KAPAN PERLU TAIL RECURSION?
        -------------------------------------------------------
        - Input sangat besar (rekursi bisa ratusan ribu level)
        - Lingkungan dengan stack terbatas (embedded system)
        - Algoritma yang secara natural rekursif (functional programming)

        Untuk C++ sehari-hari: jika rekursinya tidak terlalu dalam,
        perbedaan ini tidak signifikan. Pertimbangkan iterasi jika perlu
        efisiensi yang pasti.
    */


// X.7 - Closures dan Capture

    /* APA ITU CLOSURE?
        -------------------------------------------------------
        Closure adalah lambda yang "menangkap" (captures) variabel
        dari lingkup sekitarnya (enclosing scope) dan tetap bisa
        mengakses variabel itu bahkan setelah lingkup itu berakhir.

        Tanpa closure: function hanya bisa akses parameter & variabel lokalnya.
        Dengan closure: lambda bisa akses variabel dari fungsi pembungkusnya.
    */

    /* SYNTAX CAPTURE
        -------------------------------------------------------
        [capture_list] (parameter) { body }

        Isi capture list:
            []          : tidak tangkap apa pun (lambda murni)
            [x]         : tangkap x BY VALUE (salinan, tidak ubah asli)
            [&x]        : tangkap x BY REFERENCE (bisa ubah asli)
            [=]         : tangkap SEMUA variabel lokal by value
            [&]         : tangkap SEMUA variabel lokal by reference
            [=, &y]     : semua by value, kecuali y by reference
            [&, x]      : semua by reference, kecuali x by value
            [this]      : tangkap pointer this (di dalam class)
    */

    /* CAPTURE BY VALUE vs CAPTURE BY REFERENCE
        -------------------------------------------------------
        int batas = 10;

        // By value: salinan batas disimpan dalam lambda
        auto cekValue = [batas](int x) { return x < batas; };
        batas = 99;          // mengubah batas asli
        cekValue(5);         // masih pakai batas = 10 (salinan!)

        // By reference: lambda menyimpan referensi ke batas
        auto cekRef = [&batas](int x) { return x < batas; };
        batas = 99;          // mengubah batas asli
        cekRef(5);           // sekarang pakai batas = 99!

        PERHATIAN: Jika variabel yang di-capture by reference
        sudah tidak ada (out of scope), lambda memiliki DANGLING
        REFERENCE -- perilaku undefined (bahaya!)
    */

    /* MUTABLE LAMBDA
        -------------------------------------------------------
        Secara default, capture by value TIDAK bisa dimodifikasi
        di dalam lambda (copy-nya bersifat const).

        Pakai keyword mutable untuk mengizinkan modifikasi copy-nya:

            int counter = 0;
            auto hitung = [counter]() mutable {
                counter++;             // OK dengan mutable
                cout << counter;
            };
            hitung();   // cetak 1
            hitung();   // cetak 2
            cout << counter;  // tetap 0! (asli tidak berubah)

        Tanpa mutable, modifikasi counter di dalam lambda adalah ERROR.
    */

    /* GENERALIZED CAPTURE (C++14)
        -------------------------------------------------------
        C++14 memperkenalkan init capture: bisa inisialisasi
        variabel baru langsung di capture list.

            auto ptr = make_unique<int>(42);
            // Tidak bisa capture unique_ptr by value (not copyable)
            // Solusi: move ke dalam lambda
            auto f = [p = move(ptr)]() { cout << *p; };

        Juga berguna untuk rename:
            auto g = [x = hitungSesuatu()]() { return x * 2; };
    */


// X.8 - std::function

    /* APA ITU std::function?
        -------------------------------------------------------
        std::function adalah TIPE DATA SERBAGUNA yang bisa menyimpan
        semua jenis "callable" (sesuatu yang bisa dipanggil):
            - Regular function
            - Lambda (dengan atau tanpa capture)
            - Functor (objek dengan operator())
            - Member function (dengan bind)

        Header: #include <functional>

        Syntax:
            std::function<return_type(param_types...)> namaVariabel;

        Contoh:
            function<int(int, int)> operasi;
            operasi = tambah;                  // regular function
            operasi = [](int a, int b) { return a + b; };  // lambda
            operasi(5, 3);                     // panggil seperti biasa
    */

    /* PERBEDAAN DENGAN FUNCTION POINTER
        -------------------------------------------------------
        Feature              | Function Pointer | std::function
        ---------------------|------------------|---------------
        Regular function     | YA               | YA
        Lambda tanpa capture | YA               | YA
        Lambda dengan capture| TIDAK            | YA
        Functor              | TIDAK            | YA
        Member function      | Susah            | YA (dgn bind)
        Bisa dikosongkan     | Kaku             | nullptr / {}
        Overhead performa    | Nol              | Ada (type erasure)
        ---------------------|------------------|---------------

        Gunakan function pointer jika: performa kritis, hanya butuh
        regular function, tidak butuh capture.

        Gunakan std::function jika: butuh fleksibilitas penuh,
        menyimpan lambda dengan capture, mendesain API yang generik.
    */

    /* STD::FUNCTION SEBAGAI PARAMETER
        -------------------------------------------------------
        Ini pola yang sangat umum untuk callback yang fleksibel:

            void proses(const vector<int>& data,
                        function<void(int)> aksi) {
                for (int x : data) {
                    aksi(x);
                }
            }

            // Bisa dipanggil dengan function biasa:
            proses(data, cetakAngka);

            // Bisa dipanggil dengan lambda:
            proses(data, [](int x) { cout << x * 2; });

            // Bisa dipanggil dengan lambda ber-capture:
            int total = 0;
            proses(data, [&total](int x) { total += x; });
    */

    /* MENGOSONGKAN std::function
        -------------------------------------------------------
        std::function bisa "kosong" (tidak berisi callable apapun).
        Memanggil function kosong akan throw std::bad_function_call!

            function<int(int)> f;       // kosong
            if (f) {                    // cek dulu sebelum panggil
                f(10);
            }

            f = nullptr;                // eksplisit kosongkan
            f = {};                     // cara lain kosongkan
    */

    /* std::bind (Sekilas)
        -------------------------------------------------------
        std::bind memungkinkan "partial application" -- mengisi
        beberapa argumen function di muka:

            int tambah(int a, int b) { return a + b; }

            // Buat function baru yang selalu menambahkan 10
            auto tambah10 = bind(tambah, placeholders::_1, 10);
            tambah10(5);   // 15
            tambah10(20);  // 30

        Catatan: Di C++ modern, lambda sering lebih bersih dari bind.
        Tapi bind masih ada dan berguna untuk interoperabilitas.
    */

    /* KAPAN PAKAI APA?
        -------------------------------------------------------
        Function biasa         : logika yang tidak butuh state
        Lambda tanpa capture   : kalau cocok pakai function pointer
        Lambda dengan capture  : butuh state dari luar, one-off
        Function pointer       : callback C-style, performa kritis
        std::function          : API yang harus terima berbagai callable
        std::bind              : partial application (lambda sering lebih baik)
    */

// ============================================================
// END OF MATERI
// ============================================================

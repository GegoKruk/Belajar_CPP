/*  DAFTAR ISI MODUL POINTER & REFERENCE
    
    ============================================================
    00  Overview                    <- kamu di sini
    01  Memory-dan-Address
    02  Pointer-Basics
    03  Pointer-Arithmetic
    04  Pointer-dan-Array
    05  Const-Pointer
    06  Dynamic-Memory
    07  Reference-Basics
    08  Pass-by-Reference
    09  Pointer-vs-Reference
    ============================================================
*/


// W.0 - Pointer & Reference Overview

    /* APA ITU POINTER?
        
        -------------------------------------------------------
        Pointer adalah variabel yang menyimpan ALAMAT MEMORY
        dari variabel lain. Pointer tidak menyimpan nilai
        langsung, tapi menyimpan "DI MANA nilai itu berada".

        Analogi:
            Memory = deretan loker di sekolah
            Setiap loker punya NOMOR (alamat) dan ISI (nilai)

            Variabel biasa  = isi loker
            Pointer         = secarik kertas berisi NOMOR LOKER
    */

    /* APA ITU REFERENCE?
        
        -------------------------------------------------------
        Reference adalah ALIAS (nama lain) untuk variabel yang
        sudah ada. Bukan salinan, bukan pointer - tapi benar-
        benar nama lain yang merujuk ke lokasi memory yang SAMA.

        Analogi:
            Teman bernama "Muhammad Farhan" dipanggil "Gega".
            Keduanya merujuk ke ORANG YANG SAMA.
            Ubah rambutnya? Berubah di keduanya. Orangnya sama!

            Variabel asli  = Muhammad Farhan (nama panjang)
            Reference      = Gega (alias, merujuk ke orang sama)

    */

    /* MENGAPA POINTER PENTING?
        -------------------------------------------------------
        - Manipulasi memory secara langsung (efisien)
        - Dynamic memory allocation (alokasi saat runtime)
        - Pass array ke function dengan efisien
        - Bikin data structure kompleks (linked list, tree, dll)
        - Dasar untuk memahami OOP, STL, dan banyak fitur C++
    */

    /* MENGAPA REFERENCE PENTING?
        -------------------------------------------------------
        - Lebih simpel dan aman dari pointer untuk banyak kasus
        - Wajib diinisialisasi saat deklarasi (tidak bisa null)
        - Tidak perlu dereference (*) untuk akses nilai
        - Syntax lebih bersih, seperti variabel biasa
        - Dasar untuk memahami pass by reference di function


        PERBEDAAN UTAMA SEKILAS
        -------------------------------------------------------
        Aspek            Pointer            Reference
        ---------------  -----------------  -----------------
        Syntax           int* ptr = &x;     int& ref = x;
        Null             Bisa nullptr       Tidak bisa null
        Reassign target  Bisa               Tidak bisa
        Akses nilai      *ptr               ref (langsung)
        Keamanan         Lebih rawan bug    Lebih aman


        QUOTE DARI BJARNE STROUSTRUP (pencipta C++)
        -------------------------------------------------------
        "Gunakan reference secara default.
        Gunakan pointer hanya kalau reference tidak bisa
        melakukan tugasnya."
    */

    /* PERBEDAAN UTAMA SEKILAS

        -------------------------------------------------------
        Aspek            Pointer            Reference
        ---------------  -----------------  -----------------
        Syntax           int* ptr = &x;     int& ref = x;
        Null             Bisa nullptr       Tidak bisa null
        Reassign target  Bisa               Tidak bisa
        Akses nilai      *ptr               ref (langsung)
        Keamanan         Lebih rawan bug    Lebih aman


        QUOTE DARI BJARNE STROUSTRUP (pencipta C++)
        -------------------------------------------------------
        "Gunakan reference secara default.
        Gunakan pointer hanya kalau reference tidak bisa
        melakukan tugasnya."
    */

// W.1 - Memory dan Address

    /* BAGAIMANA KOMPUTER MENYIMPAN DATA?
        -------------------------------------------------------
        Setiap variabel yang kita buat disimpan di MEMORY (RAM).
        Memory itu ibarat deretan sel, dan setiap sel punya
        ALAMAT unik. Alamat berupa angka heksadesimal.

        Visualisasi:
            Alamat     | Isi
            -----------|------
            0x1000     |  10      <- int x = 10
            0x1004     |  20      <- int y = 20
            0x1008     |  30      <- int z = 30

        Catatan: int biasanya butuh 4 byte,
        makanya alamatnya melompat 4 setiap variabel.
    */

    /* OPERATOR ADDRESS-OF (&)
        -------------------------------------------------------
        Operator & digunakan untuk mendapatkan ALAMAT variabel.
        Bukan bitwise AND ya - beda konteks!

            int x = 10;
            cout << x;    -> menampilkan NILAI:  10
            cout << &x;   -> menampilkan ALAMAT: 0x7ffd... (hex)
    */

    /* STACK vs HEAP
        -------------------------------------------------------
        Ada dua area memory utama:

        STACK
        - Untuk variabel lokal (di dalam fungsi/main)
        - Ukuran terbatas (~1-8 MB tergantung sistem)
        - Otomatis dibersihkan ketika fungsi selesai
        - Pengelolaan OTOMATIS oleh compiler
        - Contoh: int x = 10;   -> ada di stack

        HEAP
        - Untuk dynamic memory allocation (pakai new)
        - Ukuran lebih besar (dibatasi RAM)
        - TIDAK otomatis dibersihkan, programmer wajib delete
        - Pengelolaan MANUAL oleh programmer
        - Contoh: int* ptr = new int(10);  -> ada di heap

        Layout memory (konseptual):
        +--------------------+  <- Alamat tinggi
        |       STACK        |  <- Variabel lokal, tumbuh ke bawah
        |         |          |
        |         v          |
        |                    |
        |         ^          |
        |         |          |
        |       HEAP         |  <- Dynamic allocation, tumbuh ke atas
        +--------------------+
        |  Global / Static   |
        +--------------------+
        |   Code (Program)   |
        +--------------------+  <- Alamat rendah
    */

    /* UKURAN TIPE DATA DI MEMORY
        -------------------------------------------------------
        Tipe          Ukuran     Rentang Nilai
        ------------  ---------  ----------------------------
        char          1 byte     -128 s/d 127
        bool          1 byte     true / false
        int           4 byte     ~-2 milyar s/d ~2 milyar
        float         4 byte     ~3.4e-38 s/d ~3.4e38
        double        8 byte     ~1.7e-308 s/d ~1.7e308
        long long     8 byte     ~-9.2e18 s/d ~9.2e18
        pointer       4 / 8 byte 4 byte (32-bit), 8 byte (64-bit)
    */

// W.2 - Pointer Basic

    /*  APA ITU POINTER?
        -------------------------------------------------------
        Pointer adalah variabel yang MENYIMPAN ALAMAT MEMORY
        dari variabel lain. Pointer tidak menyimpan nilai
        langsung, tapi menyimpan "dimana nilainya berada".
    */

    /* DEKLARASI POINTER
        -------------------------------------------------------
        Syntax:
            tipe_data* nama_pointer;

        Contoh:
            int*    ptr;     -> pointer ke int
            double* dPtr;    -> pointer ke double
            char*   cPtr;    -> pointer ke char
            string* sPtr;    -> pointer ke string

        Cara penulisan (semua valid, konvensi berbeda):
            int* ptr;        -> gaya C++ (bintang ke tipe) - DISARANKAN
            int *ptr;        -> gaya C (bintang ke nama)
            int * ptr;       -> gaya campuran

        JEBAKAN deklarasi dua pointer:
            int* a, b;       -> a adalah pointer, b adalah int biasa!
            int* a; int* b;  -> BENAR, keduanya pointer
    */

    /* INISIALISASI POINTER
        -------------------------------------------------------
        Ada dua cara:

        a. Arahkan ke variabel yang ada (pakai operator &)
            int angka = 42;
            int* ptr  = &angka;  -> ptr menyimpan ALAMAT angka

        b. Null pointer (tidak menunjuk ke mana-mana)
            int* ptr = nullptr;  -> modern C++11 (LEBIH BAIK)
            int* ptr = NULL;     -> cara lama (C-style)
            int* ptr = 0;        -> juga bisa, tapi kurang eksplisit

        BAHAYA - Uninitialized pointer (wild pointer):
            int* ptr;            -> BAHAYA! nilai ptr = garbage
            *ptr = 10;           -> CRASH atau undefined behavior!
            Selalu inisialisasi pointer sebelum digunakan!
    */

    /* DEREFERENCING (*) - Mengakses Nilai yang Ditunjuk
        -------------------------------------------------------
        Operator * digunakan untuk MENGAKSES atau MENGUBAH nilai
        yang berada di alamat yang disimpan pointer.

            int angka = 42;
            int* ptr  = &angka;

            cout << ptr;    -> menampilkan ALAMAT (0x7ffd...)
            cout << *ptr;   -> menampilkan NILAI di alamat: 42

        * di sini = "pergi ke alamat itu, ambil nilainya"
        Istilah teknisnya: DEREFERENCE
    */

    /* HUBUNGAN LENGKAP: Variabel, Alamat, Pointer
        -------------------------------------------------------
            int angka = 42;
            int* ptr  = &angka;

            Nama  :  angka           ptr
            Nilai :  42              0x1000  (alamat angka)
            Alamat:  0x1000          0x2000  (alamat ptr sendiri)

            cout << angka;    -> 42        (nilai angka)
            cout << &angka;   -> 0x1000    (alamat angka)
            cout << ptr;      -> 0x1000    (isi ptr = alamat angka)
            cout << *ptr;     -> 42        (nilai di alamat 0x1000)
            cout << &ptr;     -> 0x2000    (alamat ptr itu sendiri)
    */

    /* NULL POINTER & SAFETY
        -------------------------------------------------------
        nullptr = pointer yang sengaja tidak menunjuk ke mana-mana.
        Gunakan sebagai "default" sebelum diarahkan ke sesuatu.

        Cara aman:
            int* ptr = nullptr;
            if (ptr != nullptr) {
                cout << *ptr;    // aman
            } else {
                cout << "Pointer belum diinisialisasi!";
            }

        JANGAN deref null pointer:
            int* ptr = nullptr;
            cout << *ptr;   -> CRASH! (Segmentation Fault)
    */

// W.3 - Pointer Arithmetic

    /* KONSEP POINTER ARITHMETIC
        -------------------------------------------------------
        Pointer bisa ditambah atau dikurangi dengan angka integer.
        Hasilnya BUKAN tambah/kurang byte biasa, tapi melompat
        sebanyak (n * sizeof(tipe_data)) byte di memory.

        Jadi pointer arithmetic SADAR TIPE DATA!

        Contoh:
            int* ptr;
            ptr + 1  ->  maju 1 x sizeof(int) = 4 byte
            ptr + 2  ->  maju 2 x sizeof(int) = 8 byte

            double* dPtr;
            dPtr + 1 ->  maju 1 x sizeof(double) = 8 byte
    */

    /* OPERASI YANG TERSEDIA
        -------------------------------------------------------
        Operasi       Contoh       Keterangan
        ------------  -----------  ------------------------------------
        ptr + n       ptr + 1      Maju n elemen (n * sizeof(tipe))
        ptr - n       ptr - 2      Mundur n elemen
        ptr++         ptr++        Maju 1 elemen (sama dengan ptr + 1)
        ptr--         ptr--        Mundur 1 elemen
        ptr1 - ptr2   p2 - p1      Selisih posisi (dalam satuan elemen)
        ptr1 == ptr2               Apakah menunjuk alamat yang sama?
        ptr1 < ptr2                Perbandingan posisi (berguna di array)
    */

    /* VISUALISASI POINTER ARITHMETIC
        -------------------------------------------------------
        int arr[5] = {10, 20, 30, 40, 50};
        int* ptr = arr;    -> ptr menunjuk ke arr[0]

        Memory layout (tiap int = 4 byte):
        Alamat: [1000] [1004] [1008] [1012] [1016]
        Nilai:  [  10] [  20] [  30] [  40] [  50]
        Index:  [   0] [   1] [   2] [   3] [   4]

        ptr        = 1000  -> elemen 0
        ptr + 1    = 1004  -> elemen 1  (bukan 1001!)
        ptr + 2    = 1008  -> elemen 2
        *(ptr + 2) = 30    -> nilai elemen 2
    */

    /* SELISIH DUA POINTER
        -------------------------------------------------------
        int arr[5] = {10, 20, 30, 40, 50};
        int* awal  = &arr[0];
        int* akhir = &arr[4];

        int selisih = akhir - awal;  -> selisih = 4 (bukan 16 byte!)
        Hasilnya dalam satuan ELEMEN, bukan byte.
    */

    /* BAHAYA POINTER ARITHMETIC
        -------------------------------------------------------
        JANGAN keluar batas array:
            int arr[3] = {1, 2, 3};
            int* ptr   = arr + 10;   -> out of bounds!
            cout << *ptr;            -> CRASH atau nilai sampah!

        JANGAN arithmetic pointer dari variabel berbeda:
            int a = 10, b = 20;
            int* p1 = &a;
            int* p2 = &b;
            int diff = p2 - p1;      -> undefined behavior!

        Pointer arithmetic AMAN hanya dalam batas array yang sama.
    */

// W.4 - Pointer dan Array

    /* HUBUNGAN ERAT POINTER DAN ARRAY
        -------------------------------------------------------
        Di C++, nama array ADALAH pointer ke elemen pertamanya.
        Ini bukan analogi - ini benar-benar sama!

            int arr[5] = {10, 20, 30, 40, 50};

            arr         -> alamat arr[0]  (sama dengan &arr[0])
            *arr        -> nilai arr[0]   = 10
            *(arr + 1)  -> nilai arr[1]   = 20
            *(arr + i)  -> nilai arr[i]

        Ini semua SAMA:
            arr[2]  ==  *(arr + 2)  ==  *(2 + arr)  ==  2[arr]
            (semuanya menghasilkan 30)
    */

    /* ARRAY DECAY
        -------------------------------------------------------
        Saat array dilewatkan ke function sebagai parameter,
        array "berubah" menjadi pointer ke elemen pertamanya.
        Proses ini disebut ARRAY DECAY.

        Konsekuensi:
        - sizeof() di dalam function tidak bisa hitung ukuran array
        - Itulah kenapa wajib kirim SIZE sebagai parameter terpisah

            void fungsi(int arr[], int size)  -> arr[] = int* arr
            void fungsi(int* arr, int size)   -> sama saja
    */

    /* PERBEDAAN POINTER DAN ARRAY
        -------------------------------------------------------
        Aspek          Pointer              Array
        -------------  -------------------  --------------------
        Deklarasi      int* ptr;            int arr[5];
        Reassign       ptr = arr2; (bisa)   arr = arr2; (TIDAK BISA)
        sizeof()       sizeof(ptr) = 4/8    sizeof(arr) = total byte
        Arithmetic     ptr++; (bisa)        arr++; (TIDAK BISA)
        Isi            Menyimpan alamat     Adalah blok memory itu

        Intinya:
        - Array = blok memory fixed (tidak bisa dipindah)
        - Pointer = variabel yang menyimpan alamat (bisa diubah)
    */

    /* POINTER INDEXING
        -------------------------------------------------------
        Setelah pointer diarahkan ke array, bisa pakai notasi []:
            int arr[5] = {10, 20, 30, 40, 50};
            int* ptr   = arr;

            ptr[0]  -> 10  (sama dengan *ptr)
            ptr[2]  -> 30  (sama dengan *(ptr + 2))

        arr[i]  ==  *(arr + i)  ==  ptr[i]  ==  *(ptr + i)
    */

    /* POINTER KE C-STRING
        -------------------------------------------------------
        char nama[] = "Gega";
        char* p     = nama;    -> p menunjuk ke 'G'

        cout << p;             -> Output: Gega (baca sampai \0)
        cout << *p;            -> Output: G
        p++;
        cout << *p;            -> Output: e
        cout << p;             -> Output: ega (dari posisi p sekarang)
    */

// W.5 - Const Pointer

    /* KOMBINASI 1 - Pointer ke const
        -------------------------------------------------------
        Syntax: const int* ptr = &angka;
                int const* ptr = &angka;  (sama saja)

        Baca: "ptr adalah pointer ke int yang CONST"
        Artinya: nilai yang ditunjuk TIDAK BISA diubah.
                tapi pointer-nya BISA diubah arah.

            const int* ptr = &angka;
            *ptr = 99;      -> ERROR! Nilai tidak bisa diubah
            ptr  = &lain;   -> OK, pointer-nya bisa diubah arah

        Kapan dipakai:
            Saat ingin baca-saja (read-only) via pointer.
            Contoh: parameter function yang tidak boleh ubah isi array.
                void tampil(const int* arr, int size) { ... }
    */

    /* KOMBINASI 2 - Const pointer
        -------------------------------------------------------
        Syntax: int* const ptr = &angka;

        Baca: "ptr adalah CONST pointer ke int"
        Artinya: alamat yang disimpan TIDAK BISA diubah.
                tapi nilai yang ditunjuk BISA diubah.

            int* const ptr = &angka;
            *ptr = 99;      -> OK, nilai bisa diubah
            ptr  = &lain;   -> ERROR! Pointer tidak bisa diubah arah
    */

    /* KOMBINASI 3 - Const pointer ke const
        -------------------------------------------------------
        Syntax: const int* const ptr = &angka;

        Baca: "ptr adalah CONST pointer ke int yang CONST"
        Artinya: KEDUANYA tidak bisa diubah.

            const int* const ptr = &angka;
            *ptr = 99;      -> ERROR!
            ptr  = &lain;   -> ERROR!

        Kapan dipakai:
            Sangat jarang. Biasanya untuk konstanta global read-only.
    */

    /* RINGKASAN TABEL
        CONST DENGAN POINTER - ADA 3 KOMBINASI!
        -------------------------------------------------------
        Ini sering membingungkan tapi sangat penting.
        Kunci: baca deklarasi dari KANAN KE KIRI.

        -------------------------------------------------------
        Deklarasi                  Ubah *ptr   Ubah ptr
        -------------------------  ----------  ----------
        int* ptr                   Bisa        Bisa
        const int* ptr             TIDAK BISA  Bisa
        int* const ptr             Bisa        TIDAK BISA
        const int* const ptr       TIDAK BISA  TIDAK BISA
    */

    /* TIPS BACA: KANAN KE KIRI
        -------------------------------------------------------
        "const int* ptr"
            -> ptr  = pointer (*)
            -> ke   = int
            -> yang = const
            -> "ptr adalah pointer ke int yang const"
            -> Nilai tidak bisa diubah

        "int* const ptr"
            -> ptr  = const pointer (*const)
            -> ke   = int
            -> "ptr adalah const pointer ke int"
            -> Alamat tidak bisa diubah

        "const int* const ptr"
            -> ptr  = const pointer
            -> ke   = int yang const
            -> Keduanya tidak bisa diubah
    */

// W.6 - Dynamic Memory

    /* APA ITU DYNAMIC MEMORY?
        -------------------------------------------------------
        Stack: memori untuk variabel lokal, dikelola OTOMATIS.
            Ukuran terbatas. Bebas saat fungsi selesai.

        Heap : memori untuk alokasi dinamis (pakai new).
            Ukuran lebih besar. WAJIB dibebaskan manual (delete).

        Dynamic memory = alokasi memori di HEAP saat program
        berjalan (runtime), bukan saat compile-time.

        Kenapa butuh?
        - Ukuran data belum diketahui saat coding (dari input user)
        - Data perlu "hidup" lebih lama dari satu fungsi
        - Array dengan ukuran yang fleksibel
    */

    /* OPERATOR new
        -------------------------------------------------------
        Alokasi memori di heap untuk SATU variabel.

        Syntax:
            tipe* ptr = new tipe;          -> alokasi tanpa nilai awal
            tipe* ptr = new tipe(nilai);   -> alokasi dengan nilai awal

        Contoh:
            int*    ptr    = new int(42);
            double* dPtr   = new double(3.14);

        Setelah new: ptr menyimpan ALAMAT memori di heap.
    */

    /* OPERATOR delete
        -------------------------------------------------------
        Bebaskan memori heap yang sudah dialokasi dengan new.

        Syntax:
            delete ptr;      -> bebaskan satu variabel
            delete[] arr;    -> bebaskan array

        WAJIB dilakukan setelah selesai pakai!
        Kalau tidak: MEMORY LEAK (memori bocor, tidak pernah bebas)
    */

    /* ALOKASI ARRAY DINAMIS (new[])
        -------------------------------------------------------
            int* arr = new int[n];      -> alokasi n elemen
            delete[] arr;               -> bebaskan (wajib pakai [])

        Berguna saat ukuran array baru diketahui saat runtime.
    */

    /* POLA AMAN SETELAH DELETE
        -------------------------------------------------------
        Setelah delete, pointer masih menyimpan alamat lama
        (dangling pointer). Tandai dengan nullptr:

            delete ptr;
            ptr = nullptr;   -> good practice
    */

    /* BAHAYA - MEMORY LEAK
        -------------------------------------------------------
            int* p = new int(10);
            p = new int(20);    -> memori pertama (10) bocor!
                                tidak ada cara membebaskannya!

        Selalu delete sebelum reassign pointer yang ada isinya.


        BAHAYA - DOUBLE DELETE
        -------------------------------------------------------
            int* p = new int(10);
            delete p;
            delete p;    -> CRASH! Undefined behavior!

        Solusi: set ptr = nullptr setelah delete.
        delete pada nullptr = aman, tidak crash.
    */

// X.1 - Reference Basics

    /* APA ITU REFERENCE?
        -------------------------------------------------------
        Reference adalah ALIAS (nama lain) untuk variabel yang
        sudah ada. Bukan salinan, bukan pointer - tapi benar-
        benar NAMA LAIN yang merujuk ke LOKASI MEMORY yang SAMA.

        Apapun yang dilakukan via reference, variabel aslinya
        IKUT BERUBAH. Karena memang mengakses memori yang sama.
    */

    /* CARA DEKLARASI REFERENCE
        -------------------------------------------------------
        Syntax:
            tipe_data& namaRef = variabelAsli;

        Contoh:
            int angka = 10;
            int& ref  = angka;    -> ref adalah alias dari angka

            cout << angka;  -> 10
            cout << ref;    -> 10 (sama!)

            ref = 99;
            cout << angka;  -> 99 (angka IKUT BERUBAH!)
    */

    /* ATURAN REFERENCE
        -------------------------------------------------------
        1. WAJIB diinisialisasi saat deklarasi
            int& ref;          -> ERROR! Tidak boleh kosong
            int& ref = angka;  -> Benar

        2. TIDAK BISA diarahkan ulang setelah inisialisasi
            int a = 10, b = 20;
            int& ref = a;    -> ref = alias dari a
            ref = b;         -> BUKAN reassign! Ini mengisi a dengan nilai b
                                ref tetap alias dari a, a sekarang = 20
    */
    
    /* REFERENCE BUKAN VARIABEL BARU
        -------------------------------------------------------
        Reference tidak membuat salinan variabel.
        Reference dan variabel asli punya ALAMAT yang SAMA.

            int angka = 10;
            int& ref  = angka;

            &angka == &ref   -> TRUE! Alamatnya identik!
    */

    /* CONST REFERENCE
        -------------------------------------------------------
        Syntax: const int& cref = angka;

        - Bisa membaca nilai
        - TIDAK bisa mengubah nilai via reference ini
        - Bisa menerima literal / temporary value!

            const int& cr = 5 + 3;   -> OK! Temporary value 8
            int& r = 5 + 3;          -> ERROR! Non-const tidak bisa bind ke temporary
    */

    /* KEGUNAAN CONST REFERENCE
        -------------------------------------------------------
        - Baca data tanpa membuat salinan (efisien)
        - Mencegah modifikasi tidak sengaja (aman)
        - Bisa menerima literal, sangat fleksibel

        Contoh di function:
            void tampilkan(const string& nama) {
                cout << nama;   // baca saja, tidak modifikasi
            }
            // Lebih efisien dari: void tampilkan(string nama)
            // karena tidak membuat salinan string
    */

// X.2 - Pass by Reference

    /* MENGAPA PASS BY REFERENCE?
        -------------------------------------------------------
        Secara default, function menerima SALINAN nilai
        (pass by value). Perubahan di dalam function TIDAK
        mempengaruhi variabel asli.

        Dengan pass by reference, function menerima ALIAS
        variabel asli. Perubahan di dalam function LANGSUNG
        mempengaruhi variabel asli
    */

    /* TIGA CARA PASS PARAMETER
        -------------------------------------------------------

        1. Pass by VALUE (default)
        void f(int x) { x = 99; }
        -> Salinan dibuat. Asli TIDAK berubah.
        -> Cocok untuk: tipe kecil (int, double, bool) yang tidak perlu diubah

        2. Pass by REFERENCE
        void f(int& x) { x = 99; }
        -> Alias. Asli IKUT BERUBAH.
        -> Cocok untuk: saat function perlu MENGUBAH nilai asli

        3. Pass by CONST REFERENCE
        void f(const int& x) { cout << x; }
        -> Baca saja, tidak bisa ubah, tidak membuat salinan.
        -> Cocok untuk: tipe besar (string, vector, struct) yang hanya dibaca
        -> PALING DIREKOMENDASIKAN untuk read-only
    */

    /* PERBANDINGAN CARA PASS STRING
        -------------------------------------------------------
        void f(string s)          -> COPY, mahal untuk string panjang
        void f(string& s)         -> REFERENCE, bisa ubah, tidak bisa terima literal
        void f(const string& s)   -> CONST REF, efisien + aman (TERBAIK untuk read-only)
    */

    /* MULTIPLE RETURN VIA REFERENCE
        -------------------------------------------------------
        C++ hanya bisa return satu nilai. Tapi dengan reference,
        bisa "mengembalikan" beberapa nilai sekaligus via parameter!

            void hitungPersegi(int sisi, int& keliling, int& luas) {
                keliling = 4 * sisi;
                luas     = sisi * sisi;
            }

            int k, l;
            hitungPersegi(5, k, l);
            // k = 20, l = 25
    */

    /* SWAP CLASSIC - USE CASE POPULER PASS BY REFERENCE
        -------------------------------------------------------
        // SALAH - tidak swap aslinya!
        void salahSwap(int a, int b) {
            int temp = a; a = b; b = temp;
        }

        // BENAR - swap aslinya!
        void benarSwap(int& a, int& b) {
            int temp = a; a = b; b = temp;
        }
    */

// WX.1 - Pointer vs Reference

    /* POINTER vs REFERENCE - PERBANDINGAN LENGKAP
        -------------------------------------------------------
        Aspek               Pointer                     Reference
        ------------------- --------------------------- -------------------------
        Syntax deklarasi    int* ptr = &angka;           int& ref = angka;
        Inisialisasi        Boleh setelah deklarasi      WAJIB saat deklarasi
        Null                Bisa nullptr                 TIDAK BISA null
        Reassign target     Bisa (ptr = &lain)           TIDAK BISA
        Akses nilai         *ptr  (perlu dereference)    ref (langsung, seperti biasa)
        Akses member        ptr->member                  ref.member
        Alamat              ptr = alamat yang disimpan   &ref = &asli (sama!)
        Keamanan            Lebih rawan bug              Lebih aman
        Null check          Harus selalu cek nullptr     Tidak perlu (tidak bisa null)
        Kegunaan utama      Dynamic mem, array, DS       Alias, pass by ref
    */

    /* KAPAN PAKAI REFERENCE?
        -------------------------------------------------------
        1. Function perlu MENGUBAH argumen (pass by ref)
        void ganti(int& x) { x = 99; }

        2. Buat alias yang lebih readable
        int& saldo = rekening.saldo;

        3. Passing parameter besar yang tidak perlu diubah
        void tampil(const string& nama)

        4. Range-based for loop dengan objek besar
        for (auto& item : daftarBarang) { item.harga *= 1.1; }
    */

    /* KAPAN PAKAI POINTER?
        -------------------------------------------------------
        1. Perlu nullable (bisa nullptr = "tidak ada")
        Node* next = nullptr;   (di linked list)

        2. Perlu reassignment (arahkan ke variabel berbeda)
        ptr = &variabelLain;

        3. Dynamic memory allocation
        int* arr = new int[n];

        4. Array C-style dan pointer arithmetic
        for (int* p = arr; p < arr + n; p++)

        5. Implementasi data structure
        Node* head = nullptr;   (linked list, tree, dll)
    */

    /* TABEL KEPUTUSAN CEPAT
        -------------------------------------------------------
        Butuh ini?               Pakai       Alasan
        ----------------------   ----------  -------------------------------
        Alias sederhana          Reference   Syntax bersih, tidak bisa null
        Nullable ("tidak ada")   Pointer     ptr = nullptr memungkinkan
        Ubah target nanti        Pointer     Bisa arahkan ulang
        Pass arg & ubahnya       Reference   Syntax lebih simpel
        Pass arg, hanya baca     const ref   Efisien + aman
        Dynamic memory           Pointer     new / delete hanya lewat pointer
        Iterasi manual array     Pointer     Pointer arithmetic
        Return lebih dari 1 val  Reference   Lebih idiomatik
        Data structure (list)    Pointer     Node* next, bisa nullptr
    */

    /* ATURAN PRAKTIS
        -------------------------------------------------------
        "Gunakan reference secara default.
        Gunakan pointer hanya kalau reference tidak bisa
        melakukan tugasnya."
        - Bjarne Stroustrup (pencipta C++)

        "Prefer references over pointers in C++ code."
        - Google C++ Style Guide
    */

    /* REFERENCE KE REFERENCE (TIDAK ADA)
        -------------------------------------------------------
        int angka = 10;
        int& ref  = angka;
        int& ref2 = ref;    -> bukan ref ke ref! Ini ref ke angka juga.
                            &ref2 == &angka (sama)
    */

    /* POINTER KE POINTER (ADA, berguna)
        -------------------------------------------------------
        int  angka = 10;
        int* ptr   = &angka;
        int** pptr = &ptr;     -> pointer ke pointer

        **pptr = 99;           -> ubah angka via dua level pointer
    */

// WX.2 - Kesalahan Umum
    /*
        1. Wild Pointer -- pointer tidak diinisialisasi
        2. Null Pointer Dereference -- deref ptr nullptr
        3. Dangling Pointer -- pointer ke memory yang dibebaskan
        4. Memory Leak -- lupa delete
        5. Double Delete -- delete dua kali
        6. Delete vs Delete[] -- salah jenis delete
        7. Out-of-bounds -- pointer aritmetik melewati batas
        8. Ringkasan: cara menghindari semua ini
    */
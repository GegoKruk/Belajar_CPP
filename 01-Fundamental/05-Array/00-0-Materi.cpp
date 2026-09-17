    
// Daftar Isi
    /*
        ============================================================
        00 - U0 - Array-Overview            
        01 - U1 - Deklarasi-Inisialisasi
        02 - U2 - Indexing-dan-Akses
        03 - U3 - Array-Size-Sizeof
        04 - U4 - Traversing-Looping
        05 - U5 - Basic-Operations
        06 - U6 - Linear-Search
        07 - U7 - Binary-Search
        08 - U8 - Bubble-Sort
        09 - U19 - Selection-Sort
        10 - U10 - Insertion-Sort
        11 - U11 - Reverse-Array
        12 - U12 - Rotate-Array
        13 - U13 - Remove-Duplicate
        14 - U14 - Frequency-Count
        15 - U15 - Character-Array
        16 - U16 - Array-2D
        17 - U17 - Array-3D
        18 - U18 - Array-dan-Function
        ============================================================
    */

// U0 - Array Overview

    /* Apa dan Mengapa?

        APA ITU ARRAY?
        -------------------------------------------------------
        Array adalah kumpulan data dengan TIPE DATA YANG SAMA
        yang disimpan secara BERURUTAN dalam memory, dan dapat
        diakses menggunakan INDEX.


        MENGAPA BUTUH ARRAY?
        -------------------------------------------------------
        Tanpa Array  ->  banyak variabel terpisah, tidak praktis:
            int nilai1 = 85, nilai2 = 90, nilai3 = 78, nilai4 = 92;

        Dengan Array ->  satu wadah, jauh lebih ringkas:
            int nilai[4] = {85, 90, 78, 92};

        Keuntungan:
            - Hemat variabel   : tidak deklarasi satu-satu
            - Terorganisir     : data sejenis dalam satu wadah
            - Looping-friendly : bisa diproses loop secara efisien
            - Random access    : langsung akses elemen pakai index
    */

    /*  Detail Umum Array (karakter, gambaran, tipe data, kesalahan umum)

        KARAKTERISTIK ARRAY
        -------------------------------------------------------
        - Contiguous   : elemen disimpan bersebelahan di memory
        - Fixed size   : ukuran TETAP, tidak bisa di-resize
        - Same type    : semua elemen WAJIB bertipe data sama
        - Random access: akses langsung ke elemen manapun
        - Zero-indexed : index DIMULAI dari 0, bukan 1


        GAMBARAN MEMORY
        -------------------------------------------------------
        int nilai[5] = {85, 90, 78, 92, 88};

        Index :  [ 0  ] [ 1  ] [ 2  ] [ 3  ] [ 4  ]
        Value :  [ 85 ] [ 90 ] [ 78 ] [ 92 ] [ 88 ]

        nilai[0] = 85   <- elemen PERTAMA, index 0
        nilai[4] = 88   <- elemen TERAKHIR, index 4
        nilai[5] = ???  <- OUT OF BOUNDS! BAHAYA!


        TIPE DATA YANG BISA DIBUAT ARRAY
        -------------------------------------------------------
        int     dataNilai[10];
        double  suhuHarian[30];
        char    nama[50];
        bool    statusHadir[40];
        string  daftarNama[25];


        JEBAKAN PALING UMUM
        -------------------------------------------------------
        1. Out of bounds  : akses index di luar 0..(n-1)
        2. Lupa ukuran    : kirim array ke function tanpa size
        3. Garbage value  : deklarasi array tanpa inisialisasi
        4. sizeof trap    : sizeof(arr) di dalam function
                            mengembalikan ukuran pointer, bukan array


        ALTERNATIF ARRAY (untuk kebutuhan lebih lanjut)
        -------------------------------------------------------
        std::array<int, 5>   -> fixed-size, aman, ada .size()
        std::vector<int>     -> dynamic size, paling sering dipakai
        (keduanya dibahas di modul STL)
    */

// U1 - Deklarasi & Inisialisasi

    /*  Deklarasi

        SINTAKS DASAR DEKLARASI
        -------------------------------------------------------
        tipe_data nama_array[ukuran];

        Keterangan:
            tipe_data  : tipe semua elemen (int, double, char, dll)
            nama_array : nama variabel array
            ukuran     : jumlah elemen (HARUS angka positif)

        Contoh:
            int     dataNilai[10];      -> 10 data int
            double  suhuHarian[30];     -> 30 data double
            char    nama[50];           -> 50 karakter
            bool    statusHadir[40];    -> 40 data bool
            string  daftarNama[25];     -> 25 string


        ATURAN UKURAN ARRAY
        -------------------------------------------------------
        OK   : int arr[5];                     -> literal angka
        OK   : const int N = 5; int arr[N];   -> const / constexpr
        JANGAN: int n = 5; int arr[n];        -> variabel biasa
                (VLA - Variable Length Array, tidak standard C++)
    */

    /*  Inisialisasi

        CARA-CARA INISIALISASI
        -------------------------------------------------------

        1. List Initialization (Complete)
            Isi SEMUA elemen sekaligus saat deklarasi.
                int nilai[5] = {85, 90, 78, 92, 88};

        2. Partial Initialization
            Isi SEBAGIAN elemen. Sisanya otomatis 0.
                int nilai[5] = {80, 90};
                -> nilai[0]=80, nilai[1]=90, nilai[2..4]=0

        3. Zero Initialization
            Semua elemen jadi 0.
                int nilai[5] = {0};

        4. Omit Size (Auto-Detect)
            Ukuran dihitung otomatis dari jumlah elemen.
                int nilai[] = {10, 20, 30, 40, 50};
                -> Compiler tahu ukurannya = 5

        5. No Initialization (BAHAYA!)
            Elemen berisi NILAI SAMPAH (garbage value).
                int nilai[5];
                -> Jangan langsung pakai tanpa isi dulu!

        6. Uniform Initialization (C++11)
            Cara modern tanpa tanda =. Mencegah narrowing conversion.
                int nilai[5] {85, 90, 78, 92, 88};


        RINGKASAN
        -------------------------------------------------------
        Cara                  Contoh                  Keterangan
        --------------------  ----------------------  ------------------
        List Complete         int a[3] = {1, 2, 3};   Semua manual
        Partial               int a[5] = {1, 2};      Sisanya 0
        Zero                  int a[5] = {0};          Semua jadi 0
        Omit Size             int a[] = {1, 2, 3};    Ukuran otomatis 3
        No Init               int a[5];               Isi garbage!
        Uniform (C++11)       int a[5] {1,2,3,4,5};  Modern, tanpa =
    */

// U2 - Indexing & Akses

    /* Aturan Dasar

        ATURAN DASAR INDEXING
        -------------------------------------------------------
        - Index SELALU dimulai dari 0
        - Index terakhir = ukuran - 1
        - Array berukuran N -> index valid: 0 sampai N-1

        Contoh:
            int nilai[5] = {85, 90, 78, 92, 88};
            Index valid  : nilai[0], nilai[1], nilai[2], nilai[3], nilai[4]
            TIDAK VALID  : nilai[5], nilai[-1], nilai[10]
    */

    /* Read & Write

        READ / AKSES ELEMEN
        -------------------------------------------------------
        Baca nilai elemen dengan nama_array[index].

            int nilai[3] = {85, 90, 78};
            int pertama = nilai[0];      -> pertama = 85
            cout << nilai[1];            -> Output: 90
            int x = nilai[2] + 5;        -> x = 83


        WRITE / MODIFIKASI ELEMEN
        -------------------------------------------------------
        Ubah nilai elemen dengan operator penugasan (=).

            int nilai[3] = {85, 90, 78};
            nilai[0] = 100;              -> dari 85 jadi 100
            nilai[1] = nilai[1] + 5;    -> dari 90 jadi 95
            nilai[2]++;                  -> dari 78 jadi 79
            Hasil akhir: {100, 95, 79}
    */

    /* Bahaya Out Of Bounds

        OUT OF BOUNDS - BAHAYA TERBESAR ARRAY!
        -------------------------------------------------------
        Mengakses index di luar batas = OUT OF BOUNDS.

            int arr[5] = {1, 2, 3, 4, 5};
            cout << arr[5];    -> UNDEFINED BEHAVIOR!
            cout << arr[-1];   -> UNDEFINED BEHAVIOR!

        Konsekuensi:
            - Program bisa crash
            - Bisa baca/tulis memory milik variabel lain
            - Bug sangat sulit ditemukan
            - Tidak ada error message dari compiler!

        Selalu pastikan index antara 0 sampai ukuran-1 sebelum akses!
    */

// U3 - Array Size 

    /* sizeof()

        sizeof() UNTUK ARRAY
        -------------------------------------------------------
        sizeof() mengembalikan jumlah BYTE, bukan jumlah elemen.

            int nilai[5] = {85, 90, 78, 92, 88};

            sizeof(nilai)           -> 20 bytes  (5 elemen x 4 byte per int)
            sizeof(nilai[0])        -> 4 bytes   (ukuran 1 elemen int)
            sizeof(nilai)/sizeof(nilai[0]) -> 5  (jumlah elemen)

        Rumus panjang array:
            int panjang = sizeof(namaArray) / sizeof(namaArray[0]);
    */

    /* Ukuran Tiap Tipe Data

        UKURAN TIPE DATA (umumnya, bisa beda antar sistem)
        -------------------------------------------------------
            char    -> 1 byte
            int     -> 4 byte
            float   -> 4 byte
            double  -> 8 byte
            long    -> 4 atau 8 byte (tergantung platform)
            bool    -> 1 byte
    */

    /* CONST - Menyimpan Ukuran Array (Standard)

        GUNAKAN CONST UNTUK UKURAN (best practice)
        -------------------------------------------------------
        Simpan ukuran dalam konstanta agar mudah diubah.

            const int SIZE = 5;
            int nilai[SIZE] = {85, 90, 78, 92, 88};

        Keuntungan:
            - Mudah mengubah ukuran (cukup ubah nilai SIZE)
            - Lebih mudah dibaca
            - Lebih aman dari salah ketik
    */

    /* Jebakan sizeof()

        JEBAKAN sizeof() DI DALAM FUNCTION!
        -------------------------------------------------------
        Kalau array dikirim ke function sebagai parameter,
        sizeof(arr) di dalam function akan mengembalikan ukuran
        POINTER (4 atau 8 byte), BUKAN ukuran array asli.

        Solusi: kirim ukuran sebagai parameter terpisah.
        (dibahas detail di 18-Array-dan-Function.cpp)
    */

// U4 - Traversing - Looping

    /* Materi lengkap

        APA ITU TRAVERSING?
        -------------------------------------------------------
        Traversing = mengunjungi setiap elemen array satu per satu
        menggunakan loop.


        3 CARA LOOP UNTUK ARRAY
        -------------------------------------------------------

        1. For Loop (Index-based) - Paling Umum
        Cocok saat butuh INDEX elemen.

            for (int i = 0; i < n; i++) {
                cout << arr[i];
            }

        2. Range-based For Loop (C++11) - Paling Simple
        Tidak perlu index. Cocok untuk READ saja.

            for (int x : arr) {
                cout << x;
            }

        Untuk modifikasi elemen, pakai referensi:
            for (int &x : arr) {
                x *= 2;
            }

        3. While Loop
        Jarang untuk array biasa, tapi bisa untuk kondisi
        berhenti yang lebih fleksibel.

            int i = 0;
            while (i < n) {
                cout << arr[i];
                i++;
            }


        KAPAN PILIH YANG MANA?
        -------------------------------------------------------
        Butuh index elemen           -> For Loop biasa
        Hanya baca tanpa index       -> Range-based for (C++11)
        Kondisi berhenti bervariasi  -> While Loop
    */

// U5 - Basic Operational

    /* Macam2 Basic Operational

        OPERASI DASAR PADA ARRAY
        -------------------------------------------------------

        1. Total (Sum)
        Jumlahkan semua elemen dengan akumulator.
            int total = 0;
            for (int i = 0; i < n; i++) total += arr[i];

        2. Rata-rata (Average)
        Total dibagi jumlah elemen.
        HATI-HATI integer division!
            double rata = (double)total / n;   <- BENAR
            double rata = total / n;           <- SALAH (integer division)

        3. Nilai Maksimum
        Anggap elemen pertama sebagai max sementara,
        lalu bandingkan dengan semua elemen berikutnya.
            int maks = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > maks) maks = arr[i];

        4. Nilai Minimum
        Sama seperti max, tapi cari yang lebih kecil.
            int mini = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] < mini) mini = arr[i];

        5. Hitung Elemen dengan Kondisi
        Hitung berapa elemen yang memenuhi syarat.
            int count = 0;
            for (int i = 0; i < n; i++)
                if (arr[i] >= batas) count++;


        JEBAKAN INTEGER DIVISION
        -------------------------------------------------------
            int total = 433;
            double rata = total / 5;          <- Hasil: 86.0 (SALAH!)
            double rata = (double)total / 5;  <- Hasil: 86.6 (BENAR)
    */

// U6 - Sequential Search  / Linear Search

    /* Materi lengkap
        SEQUENTIAL SEARCH (LINEAR SEARCH)
        -------------------------------------------------------
        Cek satu per satu dari awal sampai akhir.
        Cocok untuk data TIDAK TERURUT.


        1. Non-Sentinel
        -------------------------------------------------------
        Loop dengan DUA kondisi:
            - i < n              : belum sampai akhir
            - arr[i] != target   : belum ketemu

            bool ketemu = false;
            int posisi = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == target) {
                    ketemu = true;
                    posisi = i;
                    break;
                }
            }

        Kompleksitas:
            Best case  : O(1)  - ketemu di elemen pertama
            Worst case : O(n)  - ketemu di akhir atau tidak ada


        2. Sentinel Search
        -------------------------------------------------------
        Tambahkan nilai target di index ke-n (posisi sentinel),
        sehingga loop PASTI berhenti dengan SATU kondisi saja.

            arr[n] = target;        // taruh di posisi sentinel
            int i = 0;
            while (arr[i] != target) i++;

            // Cek hasil:
            // i < n  -> ditemukan di posisi i
            // i == n -> tidak ada (yang ketemu cuma sentinel)

        Keuntungan:
            - Hanya 1 kondisi di loop -> sedikit lebih efisien
            - Butuh array[n+1] untuk ruang ekstra sentinel

        Catatan:
            Perbedaan performa Non-Sentinel vs Sentinel sangat
            kecil di hardware modern. Sentinel lebih relevan
            secara konseptual untuk pembelajaran algoritma.


        KAPAN PAKAI LINEAR SEARCH?
        -------------------------------------------------------
        - Data TIDAK TERURUT
        - Data KECIL (< 100 elemen)
        - Sekali cari, tidak perlu cari berulang
        - Untuk produksi: pakai std::find() dari <algorithm>
    */

// U7 - Binary Search

    /*
        BINARY SEARCH
        -------------------------------------------------------
        Jauh lebih efisien dari linear search.
        SYARAT: Data HARUS sudah terurut (sorted).

        Konsep:
            Bagi array menjadi dua di titik tengah (mid).
            Jika arr[mid] > target -> tidak perlu cek sisanya,
            karena data terurut, sisanya pasti lebih besar.

        Proses:
            left = 0, right = n-1
            mid  = (left + right) / 2

            Jika arr[mid] == target -> DITEMUKAN!
            Jika arr[mid] < target  -> cari di kanan (left = mid + 1)
            Jika arr[mid] > target  -> cari di kiri  (right = mid - 1)
            Ulangi sampai left > right (tidak ketemu)

        Visualisasi (cari 22 di [11, 12, 22, 25, 34, 45, 64, 90]):

            Langkah 1: left=0, right=7, mid=3
                    arr[3] = 25, target = 22
                    25 > 22 -> cari di kiri, right = mid-1 = 2

            Langkah 2: left=0, right=2, mid=1
                    arr[1] = 12, target = 22
                    12 < 22 -> cari di kanan, left = mid+1 = 2

            Langkah 3: left=2, right=2, mid=2
                    arr[2] = 22, target = 22
                    22 == 22 -> DITEMUKAN di index 2!

        Kompleksitas:
            O(log n) - jauh lebih cepat dari O(n) linear search
            Array 1 juta elemen -> max ~20 langkah saja!


        PERBANDINGAN LINEAR vs BINARY SEARCH
        -------------------------------------------------------
        Array 1000 elemen:
            Linear Search  : max 1000 perbandingan
            Binary Search  : max 10 perbandingan (2^10 = 1024)

        Array 1 juta elemen:
            Linear Search  : max 1.000.000 perbandingan
            Binary Search  : max 20 perbandingan (2^20 > 1.000.000)


        KAPAN PAKAI BINARY SEARCH?
        -------------------------------------------------------
        - Data TERURUT
        - Data BESAR (> 1000 elemen)
        - Untuk produksi: pakai std::binary_search() dari <algorithm>

        Jika data belum terurut: sort dulu, baru binary search.
        Tapi kalau cuma sekali cari, linear search lebih efisien
        daripada sort + binary search.
    */

// U8 - Bubble Sort

    /*
        BUBBLE SORT
        -------------------------------------------------------
        Konsep:
            Bandingkan 2 elemen bersebelahan.
            Jika salah urutan -> SWAP.
            Elemen terbesar akan "menggelembung" (bubble up)
            ke posisi paling akhir.

        Visualisasi (Ascending):
            Initial : [64, 34, 25, 12, 22]

            Pass 1  :
                64 vs 34 -> swap -> [34, 64, 25, 12, 22]
                64 vs 25 -> swap -> [34, 25, 64, 12, 22]
                64 vs 12 -> swap -> [34, 25, 12, 64, 22]
                64 vs 22 -> swap -> [34, 25, 12, 22, 64]  <- 64 FIXED

            Pass 2  :
                34 vs 25 -> swap -> [25, 34, 12, 22, 64]
                34 vs 12 -> swap -> [25, 12, 34, 22, 64]
                34 vs 22 -> swap -> [25, 12, 22, 34, 64]  <- 34 FIXED

            Pass 3  :
                25 vs 12 -> swap -> [12, 25, 22, 34, 64]
                25 vs 22 -> swap -> [12, 22, 25, 34, 64]  <- 25 FIXED

            Pass 4  :
                22 vs 12 -> ok   -> [12, 22, 25, 34, 64]  <- sorted!

        Kompleksitas:
            Time  : O(n^2)
            Space : O(1) - in-place sorting

        Optimasi:
            Tambahkan flag 'sudahTerurut'.
            Jika tidak ada swap di satu pass -> langsung berhenti.
            Untuk data yang hampir terurut, ini jauh lebih cepat.

        Kapan Pakai:
            - Tujuan belajar / memahami konsep sorting
            - Data sangat kecil (< 50 elemen)
            - Untuk produksi / data besar: pakai std::sort()
    */

// U9 - Selection Sort

    /*
        SELECTION SORT
        -------------------------------------------------------
        Konsep:
            "SELECT" elemen TERKECIL dari seluruh sisa array,
            lalu pindahkan (swap) ke posisi paling depan.
            Ulangi untuk sisa array yang belum terurut.

        Visualisasi (Ascending):
            Initial : [64, 25, 12, 22, 11]

            Pass 1  : cari min dari [64, 25, 12, 22, 11]
                    min = 11 (index 4)
                    Swap 11 <-> 64
                    [11, 25, 12, 22, 64]   <- 11 FIXED

            Pass 2  : cari min dari [25, 12, 22, 64]
                    min = 12 (index 2)
                    Swap 12 <-> 25
                    [11, 12, 25, 22, 64]   <- 12 FIXED

            Pass 3  : cari min dari [25, 22, 64]
                    min = 22 (index 3)
                    Swap 22 <-> 25
                    [11, 12, 22, 25, 64]   <- 22 FIXED

            Pass 4  : cari min dari [25, 64]
                    min = 25 (sudah di tempat, tidak perlu swap)
                    [11, 12, 22, 25, 64]   <- sorted!

        Kompleksitas:
            Time  : O(n^2) - sama seperti Bubble Sort
            Space : O(1)   - in-place sorting

        Keunggulan vs Bubble Sort:
            Jumlah SWAP jauh lebih sedikit!
            Bubble Sort: bisa swap berkali-kali per pass
            Selection Sort: paling banyak 1 swap per pass
            -> Lebih efisien jika operasi swap "mahal"

        Kapan Pakai:
            - Belajar konsep sorting
            - Saat operasi swap perlu diminimalkan
            - Untuk produksi / data besar: pakai std::sort()
    */

// U10 - Insertion Sort

    /*
        INSERTION SORT
        -------------------------------------------------------
        Konsep:
            Seperti mengurutkan kartu remi di tangan.
            Ambil satu kartu (elemen) dan sisipkan ke posisi
            yang benar di antara kartu yang sudah terurut.

        Visualisasi (Ascending):
            Initial : [12, 11, 13, 5, 6]
                    ^--- bagian "sudah terurut" dimulai dari 1 elemen

            Iter 1  : key = 11
                    11 < 12 -> geser 12 ke kanan
                    sisipkan 11 di posisi 0
                    [11, 12] | 13, 5, 6

            Iter 2  : key = 13
                    13 > 12 -> tidak perlu geser
                    [11, 12, 13] | 5, 6

            Iter 3  : key = 5
                    5 < 13 -> geser 13
                    5 < 12 -> geser 12
                    5 < 11 -> geser 11
                    sisipkan 5 di posisi 0
                    [5, 11, 12, 13] | 6

            Iter 4  : key = 6
                    6 < 13 -> geser 13
                    6 < 12 -> geser 12
                    6 < 11 -> geser 11
                    6 > 5  -> berhenti
                    sisipkan 6 setelah 5
                    [5, 6, 11, 12, 13] <- sorted!

        Kompleksitas:
            Time  : O(n^2) worst case, O(n) best case (hampir terurut)
            Space : O(1) in-place

        Keunggulan:
            SANGAT cepat untuk data yang hampir terurut.
            Untuk data hampir terurut, bisa mendekati O(n)!

        Kapan Pakai:
            - Data hampir terurut (paling efisien)
            - Data kecil (< 50 elemen)
            - Untuk produksi / data besar: pakai std::sort()


        PERBANDINGAN 3 SORTING DASAR
        -------------------------------------------------------
        Small array (< 50)     : Ketiganya OK
        Nearly sorted           : INSERTION SORT (paling efisien)
        Minimize swaps          : SELECTION SORT
        Learning / Teaching     : BUBBLE SORT (paling mudah)
        Large array (> 1000)   : Jangan pakai ketiganya!
                                Pakai std::sort() dari <algorithm>
    */

// U11 - Reverse Array

    /*
        REVERSE ARRAY
        -------------------------------------------------------
        Balik urutan array sehingga elemen terakhir jadi pertama.

        Proses (Two-pointer technique):
            - Gunakan dua pointer: left (dari awal) dan right (dari akhir)
            - Swap arr[left] dengan arr[right]
            - Geser left ke kanan, right ke kiri
            - Ulangi sampai left >= right

        Visualisasi:
            Before: [1, 2, 3, 4, 5]
                    ^           ^
                    left        right

            Step 1: Swap [0] dan [4] -> [5, 2, 3, 4, 1]   left=1, right=3
            Step 2: Swap [1] dan [3] -> [5, 4, 3, 2, 1]   left=2, right=2
            Step 3: left >= right -> berhenti

            After:  [5, 4, 3, 2, 1]

        Kompleksitas:
            Time  : O(n/2) = O(n)
            Space : O(1) - in-place, tidak butuh array baru

        Alternatif (gunakan array baru):
            Salin dari belakang ke array baru.
            Space : O(n) - butuh memory ekstra
    */

// U12 - Rotate Array

    /*
        ROTATE ARRAY
        -------------------------------------------------------
        Rotasi = geser semua elemen satu posisi ke kiri atau kanan.
        Elemen yang "jatuh" di ujung dipindah ke sisi berlawanan.


        LEFT ROTATE (Geser Kiri)
        -------------------------------------------------------
        Semua elemen geser ke KIRI satu posisi.
        Elemen PERTAMA dipindah ke posisi TERAKHIR.

        Visualisasi:
            Before: [1, 2, 3, 4, 5]
            After : [2, 3, 4, 5, 1]

        Proses:
            1. Simpan data[0] ke temp
            2. Geser semua elemen ke kiri: data[i] = data[i+1]
            3. Taruh temp di posisi terakhir


        RIGHT ROTATE (Geser Kanan)
        -------------------------------------------------------
        Semua elemen geser ke KANAN satu posisi.
        Elemen TERAKHIR dipindah ke posisi PERTAMA.

        Visualisasi:
            Before: [1, 2, 3, 4, 5]
            After : [5, 1, 2, 3, 4]

        Proses:
            1. Simpan data[n-1] ke temp
            2. Geser semua elemen ke kanan: data[i] = data[i-1]
            3. Taruh temp di posisi pertama


        ROTATE SEBANYAK K KALI
        -------------------------------------------------------
        Tinggal panggil rotate 1 langkah sebanyak k kali.
        Atau: k % n (untuk menghindari rotasi berlebihan).
        Contoh: left rotate 7 kali pada array ukuran 5
                = left rotate 7 % 5 = 2 kali
    */

// U13 - Remove Duplicate

    /*
        REMOVE DUPLICATE (HAPUS DUPLIKAT)
        -------------------------------------------------------
        Konsep:
            Hilangkan elemen yang muncul lebih dari sekali,
            pertahankan hanya satu salinan dari setiap nilai.

        METODE 1: Two-pointer (Array HARUS sudah sorted)
        -------------------------------------------------------
        Syarat WAJIB: array sudah terurut!

        Proses:
            uniqueIndex = 0  (penunjuk posisi elemen unik terakhir)
            Loop dari i=1 sampai n-1:
                Jika arr[i] != arr[uniqueIndex]:
                    -> elemen BARU yang unik
                    -> uniqueIndex++
                    -> arr[uniqueIndex] = arr[i]  (pindah ke depan)
                Kalau sama -> skip (duplikat, buang)
            New size = uniqueIndex + 1

        Visualisasi:
            Before : [1, 1, 2, 3, 3, 4, 5, 5]  size=8
            After  : [1, 2, 3, 4, 5]            size=5

        Kompleksitas:
            Time  : O(n)
            Space : O(1) - in-place


        METODE 2: Nested Loop (Array TIDAK perlu sorted)
        -------------------------------------------------------
        Proses:
            Loop i: ambil elemen acuan
            Loop j (dari i+1): cari apakah ada yang sama
            Jika ketemu duplikat: geser semua ke kiri (hapus)
            Ulangi sampai selesai

        Kompleksitas:
            Time  : O(n^2)
            Space : O(1) - in-place


        FIND DUPLICATE (Cari Elemen Duplikat)
        -------------------------------------------------------
        Cari elemen mana saja yang muncul lebih dari satu kali.

        Proses (Nested Loop):
            Loop i dari 0 sampai n-1
            Loop j dari i+1 sampai n-1
            Jika arr[i] == arr[j] -> arr[i] adalah duplikat!
    */

// U14 - Frequency Count

    /*
        FREQUENCY COUNT (HITUNG KEMUNCULAN)
        -------------------------------------------------------
        Hitung berapa kali setiap elemen muncul dalam array.


        METHOD 1: Nested Loop + Visited Array
        -------------------------------------------------------
        Cocok untuk: semua jenis data (angka besar, negatif, dll)

        Proses:
            - Loop luar : pilih elemen ke-i sebagai acuan
            - Gunakan array visited[] untuk skip yang sudah dihitung
            - Loop dalam: hitung berapa kali elemen itu muncul
            - Catat hasilnya

        Kompleksitas:
            Time  : O(n^2)
            Space : O(n) untuk array visited


        METHOD 2: Frequency Array
        -------------------------------------------------------
        Cocok untuk: angka kecil non-negatif (0 sampai maxValue)

        Proses:
            - Buat array freq[] berukuran maxValue+1, isi semua 0
            - Loop data: freq[arr[i]]++
            - Elemen i dengan freq[i] > 0 muncul sebanyak freq[i] kali

        Kompleksitas:
            Time  : O(n + maxValue)
            Space : O(maxValue)

        Kelebihan: sangat cepat untuk angka kecil
        Kekurangan: hanya untuk angka 0 sampai maxValue


        PERBANDINGAN
        -------------------------------------------------------
        Method          Cocok Untuk             Kompleksitas
        --------------- ----------------------- ---------------
        Nested Loop     Semua jenis data        O(n^2)
        Freq Array      Angka kecil (0..max)    O(n + max)
    */

// U15 - Character Array

    /*
        APA ITU CHARACTER ARRAY?
        -------------------------------------------------------
        Array yang menyimpan kumpulan karakter (char).
        Ini adalah cara LAMA (C-style) untuk menyimpan teks.
        Berbeda dengan std::string yang modern dan lebih mudah.


        NULL TERMINATOR ('\0') - WAJIB!
        -------------------------------------------------------
        Penanda berakhirnya sebuah string.
        Tidak tampil di layar, tapi WAJIB ada di akhir char array.

        Visualisasi:
            char nama[6] = "Gega";

            Index : [ 0 ] [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ]
            Value : [ G ] [ e ] [ g ] [ a ] [\0 ] [   ]

        Aturan:
            Ukuran Array = Panjang Teks + 1 (satu slot untuk \0)
            "Gega" = 4 huruf -> butuh char[5] minimal!

        Jika \0 tidak ada:
            cout akan terus baca memory sampai ketemu \0 acak
            -> Output GARBAGE (karakter aneh) -> BAHAYA!


        DEKLARASI DAN INISIALISASI
        -------------------------------------------------------
        a. Dengan ukuran eksplisit:
            char kota[6] = "Jogja";              -> 5 huruf + 1 \0 = pas
            char huruf[4] = {'A','B','C','\0'};  -> manual, \0 wajib!
            char huruf[3] = {'A','B','C'};       -> BAHAYA! Tidak ada \0!

        b. Omit size (auto-detect):
            char nama[] = "Gega";               -> Otomatis size 5 (4 + \0)

        c. Uniform Init (C++11):
            char nama[]{"Gega"};                -> Modern style


        INPUT OUTPUT
        -------------------------------------------------------
        Output   : cout << nama;              -> baca sampai \0
        Input    : cin >> nama;               -> berhenti di SPASI
        Input    : cin.getline(nama, 50);     -> baca sampai ENTER, termasuk spasi


        LIBRARY <cstring> - FUNGSI MANIPULASI
        -------------------------------------------------------
        Fungsi             Kegunaan                         Contoh
        ------------------ -------------------------------- -----------------------
        strlen(s)          Panjang string (tanpa \0)        strlen("Gega") = 4
        strcpy(dst, src)   Copy string src ke dst           strcpy(a, b)
        strcat(dst, src)   Sambung src ke belakang dst      strcat(a, " Ramadhan")
        strcmp(s1, s2)     Bandingkan dua string            strcmp(a, b)
        strchr(s, c)       Cari karakter dalam s            strchr(s, 'a')
        strstr(s1, s2)     Cari substring dalam s1          strstr(s, "ega")

        strcmp() Return:
            0    -> s1 == s2  (sama persis)
            < 0  -> s1 < s2  (s1 lebih kecil secara ASCII)
            > 0  -> s1 > s2  (s1 lebih besar secara ASCII)

        JANGAN bandingkan char array dengan == !
            if (a == b)              -> SALAH! Ini bandingkan ALAMAT memory
            if (strcmp(a, b) == 0)   -> BENAR! Ini bandingkan ISINYA


        CHAR ARRAY vs std::string
        -------------------------------------------------------
        Aspek           char Array (C-style)        std::string (Modern)
        --------------- --------------------------- -----------------------
        Ukuran          Fixed                        Dynamic (resize otomatis)
        Panjang         strlen(s)                    s.length()
        Gabung          strcat(s1, s2)               s1 + s2
        Bandingkan      strcmp(s1,s2) == 0           s1 == s2 (langsung!)
        Input           cin.getline(s, size)         getline(cin, s)
        Null terminator Manual                       Otomatis
        Safety          Rawan buffer overflow         Lebih aman

        Kapan pakai char array:
            - Interoperasi dengan fungsi C (printf, library lama)
            - Low-level programming / embedded system
    */

// U16 - Array 2D

    /*
        APA ITU ARRAY 2D?
        -------------------------------------------------------
        Array dengan dua dimensi: BARIS dan KOLOM.
        Bayangkan seperti TABEL atau MATRIKS.
        Analogi: Kursi bioskop -> [baris ke-?][kursi ke-?]


        DEKLARASI ARRAY 2D
        -------------------------------------------------------
        tipe_data nama[BARIS][KOLOM];

        Contoh:
            int matriks[3][4];    -> 3 baris, 4 kolom = 12 elemen


        INISIALISASI ARRAY 2D
        -------------------------------------------------------
        a. Per baris (lebih mudah dibaca):
            int matriks[2][3] = {
                {10, 20, 30},    // Baris 0
                {40, 50, 60}     // Baris 1
            };

        b. Flat (tanpa kurung dalam):
            int matriks[2][3] = {10, 20, 30, 40, 50, 60};

        c. Partial (sisanya otomatis 0):
            int matriks[2][3] = {{10, 20}, {40}};

        d. Zero Initialization (semua 0):
            int matriks[2][3] = {0};

        e. Omit baris (KOLOM wajib ditulis):
            int matriks[][3] = {{7, 8, 9}, {10, 11, 12}};


        AKSES ELEMEN 2D
        -------------------------------------------------------
        nama[indeks_baris][indeks_kolom]

        Baca:
            cout << matriks[0][1];   -> baris 0, kolom 1
        Tulis:
            matriks[0][0] = 99;


        ITERASI ARRAY 2D
        -------------------------------------------------------
        Wajib nested loop: luar untuk BARIS, dalam untuk KOLOM.

            for (int i = 0; i < baris; i++) {
                for (int j = 0; j < kolom; j++) {
                    cout << matriks[i][j] << " ";
                }
                cout << endl;
            }


        OPERASI MATRIKS
        -------------------------------------------------------
        Penjumlahan:
            Syarat: ukuran A == ukuran B
            Rumus : C[i][j] = A[i][j] + B[i][j]

        Perkalian:
            Syarat: kolom A == baris B
            Rumus : C[i][j] = Jumlah (A[i][k] * B[k][j])
            Contoh: A[2][3] x B[3][2] -> C[2][2]

        Transpose:
            Tukar baris dan kolom.
            Rumus: B[j][i] = A[i][j]


        SIZEOF UNTUK ARRAY 2D
        -------------------------------------------------------
        int grid[3][4];
        sizeof(grid)            -> 48 bytes (3 x 4 x 4)
        sizeof(grid[0])         -> 16 bytes (1 baris = 4 int)
        sizeof(grid[0][0])      -> 4 bytes  (1 elemen int)
        sizeof(grid)/sizeof(grid[0][0]) -> 12 elemen (3 x 4)


        BEST PRACTICE: Gunakan konstanta untuk ukuran
        -------------------------------------------------------
        const int BARIS = 3, KOLOM = 3;
        int matriks[BARIS][KOLOM];
    */

// U17 - Array 3D

    /*
        APA ITU ARRAY 3D?
        -------------------------------------------------------
        Array dengan tiga dimensi: DEPTH, BARIS, KOLOM.

        Analogi dunia nyata:
            Gedung bioskop bertingkat:
            Depth  = lantai gedung
            Baris  = baris kursi tiap lantai
            Kolom  = nomor kursi tiap baris

            gedung[lantai][baris][kursi]


        DEKLARASI ARRAY 3D
        -------------------------------------------------------
        tipe_data nama[DEPTH][BARIS][KOLOM];

        Contoh:
            int gedung[3][4][5];   -> 3 lantai, 4 baris, 5 kolom = 60 elemen


        INISIALISASI ARRAY 3D
        -------------------------------------------------------
        int data[2][2][3] = {
            {               // Depth 0 (lantai 0)
                {1, 2, 3},  // Baris 0
                {4, 5, 6}   // Baris 1
            },
            {               // Depth 1 (lantai 1)
                {7, 8, 9},  // Baris 0
                {10,11,12}  // Baris 1
            }
        };


        AKSES ELEMEN 3D
        -------------------------------------------------------
        data[depth][baris][kolom]

        Contoh:
            data[0][1][2] = 6    (lantai 0, baris 1, kolom 2)
            data[1][0][0] = 7    (lantai 1, baris 0, kolom 0)


        ITERASI ARRAY 3D (Triple Nested Loop)
        -------------------------------------------------------
            for (int d = 0; d < depth; d++) {
                for (int i = 0; i < baris; i++) {
                    for (int j = 0; j < kolom; j++) {
                        cout << data[d][i][j];
                    }
                }
            }


        TOTAL ELEMEN
        -------------------------------------------------------
        Total = DEPTH x BARIS x KOLOM
        int data[2][3][4] -> total = 2 x 3 x 4 = 24 elemen

        sizeof(data)                   -> ukuran total byte
        sizeof(data[0])                -> ukuran satu "lembaran" (1 depth)
        sizeof(data[0][0])             -> ukuran satu baris
        sizeof(data[0][0][0])          -> ukuran satu elemen


        KAPAN PAKAI ARRAY 3D?
        -------------------------------------------------------
        - Data dengan 3 dimensi alami (koordinat xyz, cube of data)
        - Simulasi ruang (fisika, game)
        - Data bertingkat (gedung, semester-kelas-nilai)
        - Untuk kebutuhan lebih kompleks: pakai vector<vector<vector<T>>>
    */

// U18 - Array dan Function

    /*
        ARRAY SELALU PASS BY POINTER!
        -------------------------------------------------------
        Saat array dipass ke function, yang dikirim adalah
        POINTER (alamat memori), BUKAN salinan seperti variabel biasa.

        Konsekuensi PENTING:
            -> Perubahan di dalam function AKAN mempengaruhi array ASLI
            -> Otomatis seperti pass by reference, khusus untuk array
            -> Tidak perlu tanda & karena array sudah otomatis jadi pointer


        SYNTAX PASS ARRAY KE FUNCTION
        -------------------------------------------------------
        // Cara 1: Pakai []  (paling umum dan jelas)
        void namaFunction(int arr[], int size) { ... }

        // Cara 2: Pakai pointer (sama saja di balik layar)
        void namaFunction(int* arr, int size) { ... }

        // Cara 3: Referensi dengan ukuran tetap (C++11)
        void namaFunction(int (&arr)[5]) { ... }   -> hanya untuk FIXED size


        KENAPA HARUS KIRIM SIZE JUGA?
        -------------------------------------------------------
        sizeof(arr) di DALAM function = sizeof pointer (4 atau 8 byte)
        sizeof(arr) di LUAR function  = ukuran array asli

        -> Ukuran array WAJIB dikirim sebagai parameter terpisah!


        PROTECT ARRAY DARI PERUBAHAN - pakai const
        -------------------------------------------------------
        void tampilArray(const int arr[], int size) { ... }
            -> arr tidak bisa diubah di dalam function
            -> Compiler error kalau coba diubah


        C++ TIDAK BISA RETURN ARRAY LANGSUNG
        -------------------------------------------------------
        int[] buatArray() { ... }   -> TIDAK VALID di C++

        Alasan: array lokal dihapus dari memory saat function selesai.
        Return pointer ke local array = UNDEFINED BEHAVIOR!

        Solusi return array:
            a. Return lewat parameter (paling umum & aman)
            b. Return pointer ke static array (hati-hati!)
            c. Gunakan std::array atau std::vector (modern C++)


        PASS ARRAY 2D KE FUNCTION
        -------------------------------------------------------
        KOLOM WAJIB dicantumkan, baris boleh dikosongkan.

        void tampilMatriks(int mat[][3], int baris, int kolom) { ... }

        Kenapa kolom wajib?
        Compiler butuh tahu jumlah kolom untuk hitung offset memory:
            mat[i][j] = *(mat + i*KOLOM + j)


        GLOBAL ARRAY
        -------------------------------------------------------
        Dideklarasikan di LUAR semua function.
        Bisa diakses dari function manapun.

        Kapan pakai:
            OK  : data yang dipakai banyak function berbeda
            OK  : lookup table (data konstan yang sering diakses)
            HINDARI : data yang seharusnya lokal (rawan bug tersembunyi!)

        Bahaya global array:
            Function lain bisa mengubah isinya tanpa sepengetahuan
            function yang memakainya -> bug yang sangat sulit dilacak!
    */






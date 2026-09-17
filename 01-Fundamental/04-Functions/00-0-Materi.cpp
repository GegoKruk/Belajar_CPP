
// T.0 - Function Overview
    /* Pengertian & Analogi

        Function adalah blok kode yang diberi nama, bisa dipanggil
        berulang kali, bisa menerima input, dan bisa menghasilkan output.

        Analogi: Function seperti mesin di pabrik.
            - Punya nama yang bisa dipanggil kapan saja
            - Bisa diberi bahan baku (parameter / input)
            - Mengolah sesuatu di dalamnya (body)
            - Bisa menghasilkan produk (return value)
    */

    /* Manfaat 

        Bayangkan program tanpa function:

            cout << "===================" << endl;
            cout << "    MENU UTAMA     " << endl;
            cout << "===================" << endl;
            // ... kode lain ...
            cout << "===================" << endl;   // tulis lagi
            cout << "    MENU UTAMA     " << endl;   // tulis lagi
            cout << "===================" << endl;   // tulis lagi

        Dengan function:

            void cetakMenu() {
                cout << "===================" << endl;
                cout << "    MENU UTAMA     " << endl;
                cout << "===================" << endl;
            }

            cetakMenu();   // panggil pertama
            cetakMenu();   // panggil lagi -- tidak perlu tulis ulang!

        MANFAAT FUNCTION:

            Reusability     : Tulis sekali, pakai berkali-kali
            Modularity      : Pecah program besar jadi bagian kecil
            Abstraksi       : Cukup tahu cara pakai, tidak perlu tahu cara kerjanya
            Readability     : Kode lebih bersih dan mudah dibaca
            Maintainability : Ubah di 1 tempat, berlaku ke semua pemanggil
    */

    /* Anatomi, Parameter/Argumen, dan Jenis

        Setiap function punya bagian-bagian berikut:

            [1]   [2]             [3]
            int   hitungJumlah   (int a, int b)
            {
                [4]
                int hasil = a + b;

                [5]
                return hasil;
            }

            [1] Return Type   : tipe data nilai yang dikembalikan
                                (int, double, string, bool, void, dll)
            [2] Nama Function : identitas function, tulis pakai camelCase
            [3] Parameter     : input yang diterima, boleh kosong ()
            [4] Body          : kode yang dijalankan saat function dipanggil
            [5] Return        : nilai yang dikembalikan ke pemanggil
                                (tidak ada return jika void)

        Saat MEMANGGIL function:

            int hasil = hitungJumlah(3, 4);
            //          [nama]       [argumen]
            // hasil = 7

        Perbedaan PARAMETER vs ARGUMEN:
            Parameter = variabel di definisi function    : (int a, int b)
            Argumen   = nilai yang dikirim saat dipanggil: hitungJumlah(3, 4)
            Sering dipakai bergantian, tapi secara teknis berbeda.

        JENIS FUNCTION:
            Void Function     : tidak mengembalikan nilai (return type = void)
            Fruitful Function : mengembalikan nilai (return type != void)

            Berdasarkan parameter:
            Tanpa parameter   : void cetakHalo()
            Dengan parameter  : int tambah(int a, int b)
            Default parameter : void info(string nama, int usia = 20)
    */

    /* Naming Convetion - Penamaan

        Nama function yang baik membuat kode mudah dibaca.

        ATURAN WAJIB (harus diikuti, kalau tidak = compile error):
            - Harus dimulai huruf atau underscore, bukan angka
            - Tidak boleh mengandung spasi
            - Tidak boleh sama dengan keyword C++ (int, return, dll)

        KONVENSI (saran -- tidak wajib tapi sangat dianjurkan):
            - camelCase: hitungTotal, cetakHeader, ambilNilai
            - Mulai dengan kata kerja: hitung, cetak, ambil, proses, validasi, cek
            - Deskriptif: hitungRataRata() lebih baik dari hitung()
            - Konsisten: pakai satu gaya di seluruh proyek

        CONTOH NAMA YANG BAIK:
            hitungLuasLingkaran()
            cetakLaporan()
            validasiInput()
            ambilNilaiMaksimum()
            konversiSuhu()

        CONTOH NAMA YANG BURUK:
            2hitung()       <- diawali angka, compile error
            hitung nilai()  <- ada spasi, compile error
            h()             <- terlalu singkat, tidak jelas
            prss()          <- singkatan membingungkan
            doStuff()       <- tidak deskriptif
            fungsi1()       <- tidak bermakna
    */

    /* Function Prototype - Mengenalkan Function

        MASALAH:
            C++ harus mengenal sebuah function SEBELUM memanggilnya.
            Jika definisi ada di BAWAH pemanggil, compiler akan error.

            void a() {
                b();    // ERROR! b belum dikenal di titik ini
            }
            void b() { ... }

        SOLUSI -- Function Prototype (Deklarasi):
            Tulis "bentuk" function di atas, implementasi boleh di bawah.
            Prototype = tanda tangan function + titik koma, tanpa body.

            void b();       // prototype -- beritahu compiler b itu ada

            void a() {
                b();    // OK! Compiler sudah tahu b dari prototype
            }

            void b() { ... }   // definisi boleh di bawah

        SYNTAX PROTOTYPE:
            return_type namaFunction(tipe1 param1, tipe2 param2);
            return_type namaFunction(tipe1, tipe2);   // nama param boleh dihilangkan

        KEGUNAAN PROTOTYPE:
            - Bolehkan definisi function di bawah main (gaya umum di C++)
            - Bolehkan dua function saling memanggil (mutual recursion)
            - Di proyek besar: prototype di .h, implementasi di .cpp

        MUTUAL RECURSION -- contoh nyata butuh prototype:
            isGenap panggil isGanjil, isGanjil panggil isGenap.
            Salah satunya harus punya prototype agar compiler tidak bingung.
    */

    /* Aturan Penting Function C++

        1. TIDAK BISA nested function
            C++ tidak mengizinkan mendefinisi function di dalam function.

            void luar() {
                void dalam() { ... }   // ERROR! Tidak boleh!
            }

            Solusi: definisi semua function di level atas (global scope).

        2. Function harus DIKENAL sebelum dipanggil
            Gunakan prototype jika definisi ada di bawah pemanggil.

        3. Return type HARUS sesuai
            Jika return type int, harus return int -- tidak bisa return string.

        4. Semua jalur harus ada return (untuk non-void)
            Jika ada if-else, semua cabang harus return nilai.

            int f(int x) {
                if (x > 0) return 1;
                
                // ERROR! Bagaimana jika x <= 0?
            }

            int f(int x) {
                if (x > 0) return 1;

                return 0;    // semua jalur ter-cover
            }

        5. Hindari global variable -- pakai parameter dan return value
    */


// T.1 - Void Function
    /* Pengertian & Overview

        Void function adalah function yang TIDAK mengembalikan nilai.
        Kata kunci "void" di return type artinya "tidak ada nilai kembali".

        Void function biasanya dipakai untuk:
            - Mencetak / menampilkan sesuatu ke layar
            - Menggambar pola / tampilan
            - Mengubah state program (mengisi variabel via reference)
            - Melakukan aksi tanpa perlu hasil (kirim email, simpan file, dll)

        SINTAKS:

            void namaFunction() {
                // body
                // tidak ada return (atau boleh "return;" untuk keluar lebih awal)
            }

            void namaFunction(tipe param1, tipe param2) {
                // body dengan parameter
            }

        CARA MEMANGGIL:
            namaFunction();           // tanpa parameter
            namaFunction(arg1, arg2); // dengan parameter

            Void function TIDAK bisa ditampung di variabel:
                int x = cetakHalo();  // ERROR! void tidak bisa ditampung
    */

    /* Early Return 
        Di dalam void function, boleh ada "return;" (tanpa nilai)
        untuk keluar dari function lebih awal (early exit).

        Ini berguna untuk:
            - Validasi input di awal (gagal cepat)
            - Menghindari nested if yang terlalu dalam
            - Membuat kode lebih mudah dibaca

        Contoh:
            void proses(int nilai) {
                if (nilai < 0) {
                    cout << "Nilai tidak boleh negatif" << endl;
                    return;   // keluar, tidak proses lanjut
                }
                // kode di bawah hanya jalan kalau nilai >= 0
                cout << "Proses: " << nilai << endl;
            }
    */


// T.2 - Fruitful Functioon
    /* Pengertian & Overview
        Fruitful function adalah function yang MENGEMBALIKAN NILAI
        ke pemanggil menggunakan statement "return".

        "Fruitful" = "berbuah" -- function ini menghasilkan sesuatu.

        Return type bisa apa saja:
            int, double, float, long long  -> angka
            bool                           -> true / false
            char                           -> satu karakter
            string                         -> teks
            (dan tipe lainnya yang akan dipelajari nanti: array, struct, dll)

        SINTAKS:

            return_type namaFunction(parameter) {
                // kode
                return nilai;   // WAJIB ada, tipenya harus cocok dengan return_type
            }

        CARA MEMAKAI HASIL RETURN:

            // 1. Tampung di variabel
            int hasil = tambah(3, 4);
            cout << hasil;

            // 2. Langsung dipakai (tanpa variabel perantara)
            cout << tambah(3, 4);

            // 3. Dipakai sebagai argumen function lain
            cout << tambah(tambah(1, 2), 3);   // nested call

            // 4. Dipakai dalam ekspresi
            int total = tambah(a, b) * 2 + 10;

        ATURAN PENTING:
            - Semua jalur if-else HARUS punya return
            - Tipe nilai yang di-return HARUS sesuai return_type
            - Setelah return dieksekusi, function langsung berhenti
    */


// T.3 - Default Parameter
    /* Pengertian & Overview

        Default parameter adalah nilai yang OTOMATIS dipakai oleh
        function ketika pemanggil tidak mengirim argumen untuk
        parameter tersebut.

        Dengan default parameter, satu function bisa dipanggil
        dengan banyak variasi jumlah argumen.

        ATURAN WAJIB -- HARUS DI PALING KANAN:

            BENAR:
                void f(int a, int b = 10)
                void f(int a, int b = 10, string c = "ok")
                void f(int a, double b = 1.5, string c = "x", bool d = true)

            SALAH (compile error!):
                void f(int a = 5, int b)           <- non-default setelah default
                void f(int a = 5, int b, int c = 1) <- non-default di tengah

        Alasan aturan ini:
            Argumen dicocokkan dari KIRI ke KANAN.
            Jika ada "lubang" di tengah, compiler tidak tahu
            argumen mana yang dilewati.

            f(10, 20)  -> a=10, b=20
            f(10)      -> a=10, b pakai default
            f(10, , 20) -> tidak valid di C++! Tidak bisa lewati tengah.

        DEFAULT DI PROTOTYPE vs DEFINISI:
            Jika pakai prototype, default HANYA ditulis di prototype.
            Jangan tulis di kedua-duanya, akan compile error.
    */


// T.4 - Function Overloading
    /* Pengertian & Overview

            Function Overloading = mendefinisikan beberapa function dengan
            NAMA YANG SAMA tetapi PARAMETER YANG BERBEDA.

            Compiler akan memilih (resolve) function yang tepat secara
            otomatis berdasarkan argumen yang dikirim saat pemanggilan.
            Ini disebut "overload resolution".

            Analogi:
                Kamu punya mesin fotokopi.
                Mesin bisa menerima: kertas A4, A3, atau foto.
                Nama operasinya sama: "fotokopi"
                Tapi prosesnya berbeda tergantung jenis inputnya.

            YANG BOLEH BERBEDA (bisa membedakan overload):
                1. Jumlah parameter    : f(int) vs f(int, int)
                2. Tipe data parameter : f(int) vs f(double)
                3. Urutan tipe         : f(int, double) vs f(double, int)

            YANG TIDAK BISA membedakan overload:
                - Return type saja: int f(int) vs double f(int) -> COMPILE ERROR
                Compiler tidak tahu versi mana yang dipanggil saat:
                    f(5);  // mau yang return int atau double?

                - Nama parameter saja: f(int a) vs f(int b) -> SAMA SAJA
                Compiler hanya lihat tipenya, bukan namanya.

            KAPAN PAKAI OVERLOADING vs DEFAULT PARAMETER?

                Pakai OVERLOADING jika:
                    - Tipe data parameter berbeda
                    - Jumlah parameter berbeda signifikan
                    - Logika di dalam function berbeda untuk tiap varian
                    - Ingin penanganan khusus per tipe

                Pakai DEFAULT PARAMETER jika:
                    - Hanya ada nilai "umum" yang sering dipakai
                    - Logika di dalam function SAMA
                    - Lebih ringkas, tidak perlu duplikasi kode
        */


// T.5 - Inline Function
    /* Pengertian & Overview

        Setiap kali function dipanggil secara normal, ada "overhead":
            1. Simpan state program saat ini (register, stack)
            2. Salin argumen ke parameter function
            3. Jump ke alamat memori function
            4. Jalankan kode function
            5. Simpan return value
            6. Jump kembali ke pemanggil
            7. Restore state

        Untuk function SANGAT PENDEK yang dipanggil ribuan kali,
        overhead ini bisa lebih lama dari function itu sendiri!

        SOLUSI: Inline Function
            Compiler "menyalin" kode function langsung ke tempat
            pemanggilnya saat kompilasi, menghilangkan overhead.

        Cara Normal (tanpa inline) -- ada lompatan:

            main()                    kuadrat()
            ...                       {
            int h = kuadrat(5); ---->     return 5 * 5;
            ...                 <----  }
            (ada overhead jump)

        Cara Inline (setelah dikompilasi) -- langsung diganti:

            main()
            ...
            int h = 5 * 5;    <- kode kuadrat DICOPY ke sini, tidak ada jump
            ...

        SINTAKS:
            inline return_type namaFunction(parameter) {
                // body -- sebaiknya 1-3 baris saja
            }

        KAPAN PAKAI inline:
            Cocok:
                - Function sangat pendek (1-3 baris)
                - Dipanggil sangat sering (hot path, inner loop)
                - Getter/setter sederhana (nanti di OOP)
                - Operasi matematika dasar

            Tidak cocok:
                - Function panjang dan kompleks -> kode membesar (code bloat)
                - Recursive function -> tidak bisa di-inline oleh compiler
                - Function dengan banyak percabangan kompleks

        PENTING -- Catatan Modern:
            - 'inline' adalah REQUEST ke compiler, bukan perintah wajib
            - Compiler BOLEH mengabaikan 'inline' jika tidak menguntungkan
            - Compiler modern (-O2/-O3) sudah bisa inline function biasa
                secara otomatis tanpa kita minta (auto-inlining)
            - Di C++ modern, inline lebih sering dipakai untuk mencegah
                "multiple definition error" di header file daripada optimasi
    */


// T.6 - Pass By Value 
    /* Pengertian & Overview
        Pass by value = default cara C++ mengirim argumen ke function.
        Yang dikirim ke function adalah SALINAN / COPY dari nilainya.
        Variabel asli di pemanggil TIDAK AKAN BERUBAH.

        Analogi:
            Kamu punya dokumen asli.
            Kamu FOTOKOPI dokumen itu dan beri ke temanmu.
            Temanmu boleh mencoret, mengubah, atau merobek fotokopiannya.
            Dokumen ASLIMU tetap aman, tidak terpengaruh apapun.

        Yang terjadi di memori:

            Pemanggil:                   Function:
            +----------+                 +----------+
            | a = 10   |                 | x = 10   |  <- salinan baru!
            +----------+                 +----------+
            (tidak berubah)              (bisa diubah bebas)

        SINTAKS (tidak ada simbol khusus, ini default):

            void namaFunction(int x) {   // x adalah salinan
                x = x * 2;               // hanya salinan yang berubah
            }

            int a = 10;
            namaFunction(a);   // a tetap 10 setelah ini

        KAPAN PAKAI PASS BY VALUE:
            - Tipe data kecil: int, double, char, bool
            - Kalkulasi murni yang tidak perlu mengubah variabel asli
            - Saat ingin KEAMANAN: pastikan function tidak bisa ubah data asli
            - Untuk data yang tidak boleh dimodifikasi function
    */

    /* Kelemahan
        Untuk tipe kecil (int, double, char, bool): pass by value efisien.
        Untuk string dan struct: pass by value menyalin SELURUH isinya,
        bisa berat untuk string panjang.

        Solusi untuk string/struct besar: pakai const reference (file 07).
        Tapi untuk belajar konsep dasar, ini dulu yang penting dipahami.
    */


// T.7 - Pass By Reference 
    /* Pengertian & Overview
        Pass by reference = kirim ALAMAT MEMORI variabel aslinya.
        Function tidak mendapat salinan -- function langsung mengakses
        variabel asli di pemanggil.

        Perubahan di dalam function LANGSUNG mengubah variabel asli.

        Analogi:
            Kamu memberi temanmu KUNCI RUMAHMU.
            Temanmu bisa masuk dan mengubah apa saja di dalam rumahmu.
            Perubahan yang dilakukan temanmu benar-benar ada di rumahmu.

        Yang terjadi di memori:

            Pemanggil:                   Function:
            +----------+                 +----------+
            | a = 10   | <-------------- | &x       |  <- bukan salinan!
            +----------+   (x menunjuk   +----------+    x adalah ALIAS dari a
                            ke a)
            (ikut berubah kalau x diubah)

        SINTAKS -- tambahkan & setelah tipe parameter:

            void namaFunction(int &x) {   // & = reference
                x = x * 2;               // x adalah alias dari variabel asli
            }

            int a = 10;
            namaFunction(a);   // a SEKARANG = 20!

        KAPAN PAKAI PASS BY REFERENCE:
            - Swap: perlu menukar dua variabel
            - Multiple return: isi beberapa variabel sekaligus
            - Modifikasi dari luar: function perlu mengubah variabel asli
            - Performa: kirim data besar (string, array, struct) tanpa copy

        CONST REFERENCE -- Kombinasi Terbaik:
            Sintaks: const tipe &nama

            - Akses via reference (tidak ada overhead copy)
            - Tapi TIDAK BISA diubah di dalam function (const)
            - Cocok untuk membaca data besar tanpa overhead copy
            - Best practice untuk parameter string, struct, vector
    */

    /* ARRAY SELALU BY REFERENCE
        Array di C++ secara otomatis selalu dikirim by reference
        (sebenarnya dikirim sebagai pointer ke elemen pertama).
        Tidak perlu simbol & untuk array.
    */

    /* CONST REFERENCE -- CEPAT TAPI AMAN
        const tipe &nama:
            - Dikirim via reference (tidak ada overhead copy) -> cepat
            - Tapi TIDAK BISA diubah di dalam function -> aman

        Cocok untuk: string, struct, vector, array yang besar
        yang hanya perlu DIBACA, bukan diubah.
    */


// T.8 - Multiple Return
    /* Pengertian & Overview
        Function di C++ hanya memiliki SATU return slot.
        Tapi sering kita butuh menghasilkan LEBIH dari satu nilai.

        Contoh kasus nyata:
            - Hitung luas DAN keliling sekaligus
            - Cari nilai minimum DAN maksimum sekaligus
            - Bagi angka, hasilkan hasil bagi DAN sisa bagi
            - Statistik: mean, min, maks sekaligus

        SOLUSI 1 -- Reference Parameter sebagai Output:
            Kirim variabel "kosong" sebagai parameter reference.
            Function mengisi variabel tersebut dari dalam.
            Setelah function selesai, variabel sudah terisi.

            Konvensi: parameter output diletakkan SETELAH input,
            sering diberi prefix "out" agar jelas mana input mana output.

            void hitung(int input, int &outHasil, int &outSisa)
                        [INPUT ]  [OUTPUT       ] [OUTPUT     ]

        SOLUSI 2 -- Return pair<T1,T2> (C++11):
            Untuk 2 nilai, return pair lebih ringkas.
            Akses dengan .first dan .second.
            Atau pakai structured binding (C++17): auto [a, b] = fungsi();
    */


// T.9 - Recursive Function
    /* Pengertian & Overview
        Recursive function adalah function yang MEMANGGIL DIRINYA SENDIRI
        untuk memecahkan masalah yang lebih kecil.

        Cara kerja: masalah besar dipecah jadi sub-masalah yang lebih kecil,
        terus menerus, sampai cukup kecil untuk diselesaikan langsung.

        DUA BAGIAN WAJIB -- TANPA KEDUANYA, REKURSI GAGAL:

            BASE CASE:
                Kondisi berhenti. Tanpa ini, rekursi jalan selamanya -> crash!
                Biasanya: if (n <= 0) return ...; atau if (n == 1) return ...;

            RECURSIVE CASE:
                Pemanggilan diri sendiri dengan input yang LEBIH KECIL.
                Harus terus mendekati base case!

        Contoh sederhana:
            int faktorial(int n) {
                if (n <= 1) return 1;          <- BASE CASE: berhenti di n=1
                return n * faktorial(n - 1);   <- RECURSIVE CASE: n mengecil
            }

        CALL STACK -- Cara Kerja di Memori:
            Setiap pemanggilan function membuat "frame" baru di stack.
            Frame berisi: nilai parameter, variabel lokal, alamat return.

            faktorial(4):
                Frame 4: menunggu faktorial(3)
                    Frame 3: menunggu faktorial(2)
                        Frame 2: menunggu faktorial(1)
                            Frame 1: return 1  <- BASE CASE, mulai balik
                        return 2 * 1 = 2
                    return 3 * 2 = 6
                return 4 * 6 = 24

        BAHAYA STACK OVERFLOW:
            Setiap frame menggunakan memori.
            Rekursi terlalu dalam (ribuan frame) -> memori habis -> CRASH.
            Selalu pastikan base case BISA tercapai dari input manapun!
    */


// T.10 - Scope Local Global
    /* Pengertian & Overview
        SCOPE = area di mana sebuah variabel bisa diakses.
        LIFETIME = berapa lama variabel ada di memori.

        Aturan dasar:
            Variabel hanya bisa diakses di dalam blok { } tempat ia dideklarasikan.
            Di luar blok itu -> tidak bisa diakses (sudah tidak ada).

        JENIS SCOPE:

        LOCAL SCOPE:
            Dideklarasikan di dalam function atau blok { }.
            Hanya bisa diakses dari dalam blok tersebut.
            Dibuat saat masuk blok, DIHAPUS saat keluar blok.
            Parameter function = local variable milik function itu.

        GLOBAL SCOPE:
            Dideklarasikan di luar semua function.
            Bisa diakses dari semua function.
            Hidup dari awal sampai akhir program.
            HINDARI -- kecuali untuk konstanta!

        SCOPE BLOK (BLOCK SCOPE):
            Variabel di dalam { } (if, for, while, blok kosong)
            hanya hidup selama blok itu aktif.
    */


// T.11 - Static Variable
    /* Pengertian & Overview
        Keyword 'static' pada variabel lokal membuatnya istimewa:
            - SCOPENYA tetap lokal (hanya bisa diakses dari function itu)
            - Tapi NILAINYA bertahan antar pemanggilan function
            - Diinisialisasi hanya SEKALI saat pertama kali dieksekusi

        Perbandingan tiga jenis variabel:

            LOCAL biasa:
                - Scope  : hanya di dalam function
                - Lifetime: dibuat saat function dipanggil, DIHAPUS saat selesai
                - Nilai  : selalu dimulai dari awal setiap pemanggilan

            STATIC LOCAL:
                - Scope  : hanya di dalam function (sama dengan local)
                - Lifetime: hidup sepanjang program (seperti global)
                - Nilai  : BERTAHAN antar pemanggilan!
                - Init   : hanya sekali, saat pertama kali dieksekusi

            GLOBAL:
                - Scope  : bisa diakses dari SEMUA function (bahaya!)
                - Lifetime: hidup sepanjang program
                - Nilai  : bertahan

        SINTAKS:
            void namaFunction() {
                static int counter = 0;   // hanya diinisialisasi sekali!
                counter++;
                cout << counter;
            }

            namaFunction();   // output: 1
            namaFunction();   // output: 2  <- counter tidak direset!
            namaFunction();   // output: 3

        KEGUNAAN:
            - Counter pemanggilan function
            - ID generator otomatis
            - Cache / memoization sederhana
            - State yang perlu diingat antar pemanggilan
    */

    /* Info
        Fibonacci rekursif naive: O(2^n) -- sangat lambat.
        Dengan static cache: setiap nilai hanya dihitung SEKALI,
        sisanya ambil dari cache.
    */

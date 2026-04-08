/*
    DAFTAR ISI MODUL STRUCT
    ============================================================
    00  Overview                    <- kamu di sini
    01  Deklarasi-dan-Member
    02  Inisialisasi
    03  Dot-Operator-dan-Akses
    04  Struct-dan-Function
    05  Array-of-Struct
    06  Nested-Struct
    07  Struct-Member-Function
    08  Struct-vs-Class
    ============================================================
*/

// Y.0 - Overview

    /* APA ITU STRUCT?
        -------------------------------------------------------
        Struct (Structure) adalah tipe data BUATAN SENDIRI yang
        mengelompokkan beberapa variabel dengan tipe berbeda-beda
        menjadi SATU KESATUAN yang bermakna.

        Setelah dideklarasikan, struct bisa digunakan seperti
        int, double, atau tipe data lainnya.
        Ini disebut USER-DEFINED TYPE.

        Analogi:
            Bayangkan sebuah KTP.
            KTP punya banyak info: nama, NIK, tempat lahir, dll.
            Semua info itu milik SATU ORANG yang sama.
            Struct = "cetakan KTP", template yang mendefinisikan
            info apa saja yang dimiliki setiap orang.
    */

    /* MENGAPA BUTUH STRUCT?
        -------------------------------------------------------
        Tanpa struct (ribet dan tidak scalable):
            string nama1 = "Budi";   int umur1 = 20;   double ipk1 = 3.85;
            string nama2 = "Sari";   int umur2 = 21;   double ipk2 = 3.90;
            string nama3 = "Andi";   int umur3 = 19;   double ipk3 = 3.70;
            // Untuk 100 mahasiswa? Mimpi buruk!

        Dengan struct (rapi dan scalable):
            Mahasiswa mhs1 = {"Budi", 20, 3.85};
            Mahasiswa mhs2 = {"Sari", 21, 3.90};
            Mahasiswa mhs3 = {"Andi", 19, 3.70};
            Mahasiswa kelas[100];   // 100 mahasiswa dalam satu array!
    */

    /* SYNTAX DASAR
        -------------------------------------------------------
        struct NamaStruct {
            tipe_data member1;
            tipe_data member2;
            tipe_data member3;
        };    <- jangan lupa titik koma di sini!

        Akses member dengan dot operator (.):
            NamaStruct objek;
            objek.member1 = nilai;
            cout << objek.member2;
    */

    /* STRUCT DI MEMORY
        -------------------------------------------------------
        Struct menyimpan member secara BERURUTAN di memory:

        Mahasiswa m = {"Budi", 20, 3.85};

        +------------------+-----------+------------------+
        |  nama ("Budi")   |  umur(20) |   ipk (3.85)     |
        +------------------+-----------+------------------+
        Semua dalam satu blok memory yang berdekatan.

        sizeof(struct) = jumlah bytes semua member
                    (+ kemungkinan padding untuk alignment)
    */

// Y.1 - Deklarasi dan Member

    /* SYNTAX DEKLARASI STRUCT
        -------------------------------------------------------
        struct NamaStruct {
            tipe_data member1;
            tipe_data member2;
            // ...
        };    <- WAJIB titik koma setelah kurung kurawal tutup!

        Setelah dideklarasikan, NamaStruct bisa dipakai seperti
        tipe data biasa: int, double, string, dll.
    */

    /* JENIS MEMBER YANG BISA DIDEKLARASIKAN
        -------------------------------------------------------
        - Tipe data primitif  : int, double, char, bool, float
        - string              : std::string
        - Array               : int nilai[5];
        - Pointer             : int* ptr;
        - Struct lain         : (nested struct, dibahas di 06)
        - Semua tipe C++      : hampir semua bisa jadi member
    */

    /* ATURAN PENTING
        -------------------------------------------------------
        1. Nama struct biasanya diawali Huruf Kapital (konvensi)
        2. Titik koma (;) wajib ada setelah tanda kurung kurawal
        3. Deklarasi struct biasanya di luar fungsi (global scope)
            agar bisa dipakai di banyak fungsi
        4. Member struct tidak perlu diinisialisasi saat deklarasi
            (kecuali pakai default member values - C++11)

    */

    /* TEMPAT DEKLARASI STRUCT
        -------------------------------------------------------
        Bisa dideklarasikan:
        - Di luar semua fungsi (global) -> paling umum, bisa dipakai di mana saja
        - Di dalam fungsi main          -> hanya bisa dipakai di dalam fungsi itu
        - Di file header (.h)           -> untuk proyek multi-file
    */

    /* DEFAULT MEMBER VALUES (C++11)
        -------------------------------------------------------
        Bisa langsung beri nilai default saat deklarasi struct:

            struct Produk {
                string nama   = "Tidak Diketahui";
                double harga  = 0.0;
                int    stok   = 0;
                bool   aktif  = true;
            };

        Objek yang dibuat tanpa isi akan pakai nilai default ini.
    */

// Y.2 - Inisialisasi

    /* CARA-CARA INISIALISASI STRUCT
        -------------------------------------------------------

        a. Satu per satu (member assignment)
            Mahasiswa m;
            m.nama = "Budi";
            m.umur = 20;
            m.ipk  = 3.85;

        b. Aggregate Initialization
            Urutan HARUS sesuai urutan deklarasi member!
            Mahasiswa m = {"Budi", 20, 3.85};

        c. Designated Initialization (C++20)
            Nama member ditulis eksplisit, urutan bebas.
            Mahasiswa m = {.nama = "Budi", .umur = 20, .ipk = 3.85};

        d. Default Member Values (C++11)
            Nilai sudah ditetapkan di dalam struct.
            struct Mahasiswa {
                string nama = "Unknown";
                int    umur = 0;
                double ipk  = 0.0;
            };
            Mahasiswa m;   // pakai semua default

        e. Copy dari struct lain (assignment)
            Mahasiswa m2 = m1;   // salinan lengkap semua member
    */

    /* PARTIAL INITIALIZATION (Aggregate)
        -------------------------------------------------------
        Mirip array, jika tidak semua member diisi:
        - Member yang tidak diisi akan di-zero-initialize
            (0, 0.0, false, string kosong)

            Mahasiswa m = {"Budi"};  // umur=0, ipk=0.0

        HATI-HATI: urutan member sangat penting untuk aggregate!
        Jika urutan salah, nilai masuk ke member yang salah.
    */

// Y.3 - Dot Operator dan Akses

    /* DOT OPERATOR (.)
        -------------------------------------------------------
        Digunakan untuk mengakses member struct secara LANGSUNG
        dari variabel struct.

        Syntax:
            namaVariabel.namaMember

        Bisa untuk READ dan WRITE:
            mhs.nama = "Budi";       // write
            cout << mhs.nama;        // read
            mhs.ipk  = mhs.ipk + 0.1;  // read + write
    */

    /* ARROW OPERATOR (->)
        -------------------------------------------------------
        Digunakan untuk mengakses member struct melalui POINTER.

        Syntax:
            namaPointer->namaMember

        Ini adalah singkatan dari: (*namaPointer).namaMember
        Keduanya setara, tapi -> jauh lebih bersih dan sering dipakai.

            Mahasiswa* ptr = &mhs;

            ptr->nama          // sama dengan (*ptr).nama
            ptr->ipk = 4.0;    // sama dengan (*ptr).ipk = 4.0
    */

    /* RINGKASAN SINGKAT
        -------------------------------------------------------
        Akses via variabel  : mhs.nama
        Akses via pointer   : ptr->nama   atau  (*ptr).nama
        Akses via reference : ref.nama   (sama seperti variabel biasa)
    */

    /* KAPAN PAKAI MASING-MASING?
        -------------------------------------------------------
        Punya variabel struct biasa  -> pakai (.)
        Punya pointer ke struct      -> pakai (->)
        Punya reference ke struct    -> pakai (.) seperti biasa
    */

// Y.4 - Struct dan Function

    /* STRUCT SEBAGAI PARAMETER FUNCTION
        -------------------------------------------------------
        Struct bisa dipass ke function seperti tipe data biasa.
        Ada tiga cara:

        a. Pass by VALUE
            void tampilkan(Mahasiswa m) { ... }
            - Salinan dibuat. Perubahan di dalam function TIDAK mengubah asli.
            - Mahal untuk struct besar (semua member disalin).
            - Cocok untuk struct kecil (Titik, Warna, dll).

        b. Pass by REFERENCE
            void update(Mahasiswa& m, double ipkBaru) { ... }
            - Alias. Perubahan MENGUBAH struct asli.
            - Tidak membuat salinan (efisien).
            - Cocok saat function perlu memodifikasi struct.

        c. Pass by CONST REFERENCE (paling direkomendasikan untuk read-only)
            void tampilkan(const Mahasiswa& m) { ... }
            - Tidak membuat salinan (efisien).
            - Tidak bisa diubah (aman).
            - Cocok untuk function yang hanya membaca struct.


    */

    /* BEST PRACTICE
        -------------------------------------------------------
        Hanya READ struct          -> const Mahasiswa& m   (efisien + aman)
        Perlu MODIFY struct        -> Mahasiswa& m
        Struct kecil (<=2 member)  -> boleh by value (Titik, Warna, dll)

    */

    /* RETURN STRUCT DARI FUNCTION
        -------------------------------------------------------
        Function bisa mengembalikan struct seperti tipe data biasa.

            Mahasiswa buatMahasiswa(string nama, int umur, double ipk) {
                Mahasiswa m;
                m.nama = nama;
                m.umur = umur;
                m.ipk  = ipk;
                return m;
            }

            Mahasiswa mhs = buatMahasiswa("Budi", 20, 3.85);

        Atau pakai aggregate initialization di return:
            return {"Budi", 20, 3.85};   // lebih ringkas
    */

// Y.5 - Array of Struct

    /* ARRAY OF STRUCT
        -------------------------------------------------------
        Kita bisa membuat array yang setiap elemennya adalah struct.
        Ini sangat powerful untuk menyimpan banyak data terstruktur.

        Syntax:
            NamaStruct namaArray[ukuran];

        Contoh:
            Mahasiswa kelas[30];    // 30 mahasiswa
            kelas[0].nama = "Budi";
            kelas[0].ipk  = 3.85;

        Akses member:
            namaArray[index].membe
    */

    /* INISIALISASI ARRAY OF STRUCT
        -------------------------------------------------------
        a. Satu per satu:
            Mahasiswa kelas[3];
            kelas[0] = {"Budi", 20, 3.85};
            kelas[1] = {"Sari", 21, 3.90};

        b. Langsung saat deklarasi:
            Mahasiswa kelas[3] = {
                {"Budi", 20, 3.85},
                {"Sari", 21, 3.90},
                {"Andi", 19, 3.70}
            };
    */

    /* USE CASE
        -------------------------------------------------------
        Array of struct adalah pola yang sangat umum di C++
        untuk menyimpan kumpulan data yang terstruktur:
        - Daftar mahasiswa / karyawan
        - Daftar produk / inventori
        - Data kontak
        - Record database sederhana
    */

// Y.6 - Nested Struct

    /* NESTED STRUCT
        -------------------------------------------------------
        Struct bisa punya member yang tipenya struct lain.
        Ini disebut NESTED STRUCT atau struct bersarang.

        Contoh:
            struct Alamat {
                string jalan;
                string kota;
                string provinsi;
            };

            struct Pegawai {
                string nama;
                int    gaji;
                Alamat alamat;    // member berupa struct lain!
            };

        Akses member nested struct:
            Pegawai p;
            p.nama             = "Budi";
            p.alamat.kota      = "Yogyakarta";   // dua dot
            p.alamat.provinsi  = "DIY";
    */

    /* ATURAN URUTAN DEKLARASI
        -------------------------------------------------------
        Struct yang dipakai sebagai member HARUS sudah
        dideklarasikan SEBELUM struct yang memakainya.

            struct B { A data; };    // ERROR jika A belum dideklarasikan
            struct A { int x; };

            Urutan yang benar:
            struct A { int x; };
            struct B { A data; };
    */

    /* KEDALAMAN NESTING
        -------------------------------------------------------
        Bisa nested lebih dari satu level:
            p.alamat.kota   (dua level)

        Secara teknis bisa lebih dalam, tapi sebaiknya
        jangan terlalu dalam agar kode masih mudah dibaca.
    */

    /* INISIALISASI NESTED STRUCT
        -------------------------------------------------------
        Pakai kurung kurawal bertingkat:
            Pegawai p = {"Budi", 5000000, {"Jl. Malioboro", "Yogyakarta", "DIY"}};
    */

// Y.7 - Struct Member Function

    /* STRUCT DENGAN MEMBER FUNCTION
        -------------------------------------------------------
        Di C++, struct BISA punya member function (berbeda dari C!).
        Member function bisa mengakses member struct lainnya
        secara langsung, tanpa perlu parameter tambahan.

        Syntax:
            struct NamaStruct {
                // member data
                tipe_data member1;

                // member function
                void namaFungsi() {
                    // bisa akses member1 langsung
                }
            };
    */

    /* PERBEDAAN MEMBER FUNCTION vs FUNCTION BIASA
        -------------------------------------------------------
        // Function biasa (dari luar struct)
        double luasPersegi(Persegi p) {
            return p.sisi * p.sisi;   // perlu p. di depan
        }

        // Member function (di dalam struct)
        struct Persegi {
            double sisi;

            double luas() {
                return sisi * sisi;   // akses langsung tanpa p.
            }
        };

        Pemanggilan:
            Persegi p = {5.0};
            p.luas();   // seperti akses member biasa

    */

    /* KAPAN PAKAI MEMBER FUNCTION?
        -------------------------------------------------------
        Pakai member function jika operasi ERAT KAITANNYA dengan
        data struct tersebut. Contoh:
        - Persegi::luas()       - menghitung dari datanya sendiri
        - Mahasiswa::tampilkan() - menampilkan datanya sendiri
        - Rekening::transfer()   - operasi pada datanya sendiri

        Jangan masukkan semua operasi ke member function.
        Kalau operasinya butuh data dari luar (lebih dari satu struct),
        lebih tepat dibuat sebagai function biasa.
    */

    /* CATATAN
        -------------------------------------------------------
        Struct dengan banyak member function sudah sangat mirip
        dengan CLASS. Kalau sudah butuh encapsulation dan
        kompleksitas lebih, saatnya pindah ke class (OOP).
    */

// Y.8 - Struct vs Class

    /* PERBEDAAN TEKNIS: HANYA SATU!
        -------------------------------------------------------
        Secara teknis, perbedaan SATU-SATUNYA antara struct dan
        class di C++ adalah DEFAULT ACCESS SPECIFIER:

            struct -> default: PUBLIC
                    semua member bisa diakses dari luar

            class  -> default: PRIVATE
                    member tidak bisa diakses langsung dari luar
    */

    /* CONTOH PERBEDAAN
        -------------------------------------------------------
        struct PointS {
            int x;     // otomatis PUBLIC
            int y;
        };

        class PointC {
            int x;     // otomatis PRIVATE
            int y;
        };

        PointS ps;
        ps.x = 5;    // OK - struct, public by default

        PointC pc;
        pc.x = 5;    // ERROR - class, private by default!
    */

    /* KONVENSI PENGGUNAAN (tidak tertulis tapi umum dipakai)
        -------------------------------------------------------
        STRUCT digunakan untuk:
            - Data sederhana tanpa behaviour (Plain Old Data / POD)
            - Kumpulan nilai yang saling berkaitan
            - Data transfer objects (DTO)
            - Tidak butuh encapsulation
            - Contoh: Titik, Warna, Ukuran, Tanggal, Record

        CLASS digunakan untuk:
            - Objek dengan state (data) DAN behaviour (fungsi)
            - Butuh encapsulation (sembunyikan detail internal)
            - Inheritance dan polymorphism
            - Invariants yang perlu dijaga
            - Contoh: BankAccount, Mahasiswa dengan logika, Car
    */

    /* RINGKASAN TABEL
        -----------------------------------------------------------
        Fitur                  |  struct          |  class
        -----------------------|------------------|----------------
        Default access         |  public          |  private
        Bisa member function   |  Ya              |  Ya
        Bisa inheritance       |  Ya              |  Ya
        Bisa access specifier  |  Ya              |  Ya
        Konvensi penggunaan    |  Data sederhana  |  Objek kompleks
        Kapan dipilih          |  POD / DTO       |  Encapsulation
    */

    /* KAPAN PINDAH KE CLASS?
        -------------------------------------------------------
        Pertimbangkan pindah ke class saat:
            - Butuh menyembunyikan data (private member)
            - Butuh validasi sebelum mengubah data
            - Butuh constructor khusus
            - Data structure jadi semakin kompleks
            - Butuh inheritance / polymorphism
    */
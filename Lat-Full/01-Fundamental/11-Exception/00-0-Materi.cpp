/*
    DAFTAR ISI MODUL EXCEPTION
    ============================================================
    00  Overview                        <- kamu di sini
    01  Try-Throw-Catch-Dasar
    02  Multiple-Catch-dan-Urutan
    03  Exception-di-Nested-Function
    04  Standard-Exception-Classes
    05  Custom-Exception
    06  Custom-Exception-Hierarki
    07  Re-throw-dan-Exception-Safety
    08  noexcept
    09  Best-Practices-dan-Anti-Pattern
    ============================================================
*/

// AB.0 - Overview

    /* APA ITU EXCEPTION?
        -------------------------------------------------------
        Exception (pengecualian) adalah kondisi TIDAK NORMAL
        yang terjadi saat program berjalan (runtime), yang
        mengganggu alur normal program.

        Contoh kondisi tidak normal:
            - Pembagian dengan nol
            - File tidak ditemukan
            - Input huruf padahal minta angka
            - Array diakses di luar batas
            - Memori habis (new gagal)
            - Konversi string gagal (stoi("abc"))
    */

    /* MASALAH TANPA EXCEPTION HANDLING
        -------------------------------------------------------
        Cara lama (return code):
            int bagi(int a, int b) {
                if (b == 0) return -1;   // kode error khusus
                return a / b;
            }

        Masalah:
            - Nilai -1 bisa juga hasil valid
            - Mudah lupa cek return code
            - Nested calls makin rumit
            - Tidak bisa dipakai untuk constructor
    */

    /* SOLUSI: EXCEPTION HANDLING
        -------------------------------------------------------
        Keuntungan:
            - Memisahkan kode normal dari kode penanganan error
            - Tidak bisa "diabaikan" seperti return code
            - Bekerja lintas function call (stack unwinding)
            - Type-safe: bisa throw/catch tipe apapun
            - Bisa dipakai di constructor
    */

    /* TIGA KEYWORD UTAMA
        -------------------------------------------------------
        try   -> blok kode yang mungkin menghasilkan error
        throw -> melempar (membangkitkan) exception
        catch -> menangkap dan menangani exception

        Pola dasar:
            try {
                // kode yang mungkin error
                if (b == 0) throw runtime_error("pembagi nol!");
                return a / b;
            }
            catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
    */

    /* ANALOGI DUNIA NYATA
        -------------------------------------------------------
        Bayangkan bermain bola:
            try    = bermain bola di lapangan
            throw  = kamu jatuh dan cedera
            catch  = perawat menangani cedera

        Alur normal (tidak ada exception):
            try -> main bola -> selesai -> lanjut aktivitas

        Alur dengan exception:
            try -> main bola -> jatuh! -> throw exception
                -> catch -> perawat tangani -> lanjut
    */

    /* HIRARKI EXCEPTION STANDARD C++
        -------------------------------------------------------
        std::exception                 <- base class semua
        +-- std::logic_error           <- kesalahan logika
        |   +-- std::invalid_argument  <- argumen tidak valid
        |   +-- std::domain_error      <- domain matematika salah
        |   +-- std::length_error      <- panjang melebihi batas
        |   +-- std::out_of_range      <- indeks di luar range
        +-- std::runtime_error         <- error saat runtime
            +-- std::overflow_error    <- overflow aritmatika
            +-- std::underflow_error   <- underflow aritmatika
            +-- std::range_error       <- hasil di luar range
            +-- std::system_error      <- error sistem operasi

        Exception khusus:
            std::bad_alloc  <- new gagal alokasi memori
            std::bad_cast   <- dynamic_cast gagal
    */

    /* STACK UNWINDING
        -------------------------------------------------------
        Saat exception di-throw, C++ secara otomatis:
            1. Menghentikan eksekusi di titik throw
            2. "Melepas" (unwind) stack frame satu per satu
            3. Memanggil destruktor semua objek lokal
            4. Mencari catch yang cocok di call stack

        Ini menjamin tidak ada resource leak saat exception!
    */

// AB.1 - Try Throw Catch Dasar

    /* BLOK TRY
        -------------------------------------------------------
        Blok try membungkus kode yang MUNGKIN melempar exception.
        Kode di dalam try berjalan normal hingga ada yang throw.

        Saat throw terjadi:
            - Eksekusi berhenti di titik throw
            - Baris setelah throw di dalam try TIDAK dieksekusi
            - C++ langsung loncat ke blok catch yang cocok

            try {
                cout << "baris 1";   // dieksekusi
                throw runtime_error("error!");
                cout << "baris 2";   // TIDAK dieksekusi
            }
    */

    /* KEYWORD throw
        -------------------------------------------------------
        throw melempar sebuah objek sebagai exception.
        Bisa throw tipe apapun, tapi sebaiknya pakai exception class.

            throw 42;                        // throw int (tidak disarankan)
            throw "error";                   // throw C-string (tidak disarankan)
            throw string("pesan");           // throw std::string (boleh)
            throw runtime_error("pesan");    // BEST PRACTICE - exception class
            throw invalid_argument("bad");   // BEST PRACTICE

        Setelah throw:
            - Eksekusi langsung berhenti
            - Destruktor objek lokal dipanggil (stack unwinding)
            - C++ cari catch yang cocok di call stack
    */

    /* BLOK catch
        -------------------------------------------------------
        catch menangkap exception yang dilempar throw.
        Harus ditulis tepat setelah blok try.

            catch (const runtime_error& e) {
                cout << e.what();   // pesan error
            }

            catch (...) {           // catch-all: tangkap semua tipe
                cout << "Ada error!";
            }

        Setelah catch selesai:
            - Program lanjut ke kode setelah blok try-catch
            - BUKAN lanjut dari titik throw!
    */

    /* FUNGSI what()
        -------------------------------------------------------
        Semua turunan std::exception punya fungsi what():
            catch (const exception& e) {
                cout << e.what();   // const char* berisi pesan error
            }
    */

    /* ALUR EKSEKUSI
        -------------------------------------------------------
        Normal (tidak ada throw):
            try { ... } -> selesai -> kode setelah try-catch

        Ada throw:
            try { ... throw ... } -> catch { ... } -> kode setelah try-catch
            (kode setelah throw di dalam try DILEWATI)
    */

// AB.2 - Multiple Catch dan Urutan

    /* MULTIPLE CATCH BLOCKS
        -------------------------------------------------------
        Satu blok try bisa diikuti BANYAK blok catch.
        Masing-masing menangani tipe exception yang berbeda.

            try {
                // kode
            }
            catch (const invalid_argument& e) { ... }
            catch (const logic_error& e)      { ... }
            catch (const exception& e)        { ... }
            catch (...)                       { ... }
    */

    /* ATURAN URUTAN - DARI SPESIFIK KE UMUM
        -------------------------------------------------------
        Catch dicocokkan dari ATAS ke BAWAH.
        Catch yang lebih SPESIFIK HARUS di atas catch yang lebih UMUM.

        Ingat hirarki inheritance:
            exception
            +-- logic_error
            |   +-- invalid_argument   <- paling spesifik
            |   +-- out_of_range
            +-- runtime_error
                +-- overflow_error

        Urutan yang BENAR:
            catch (const invalid_argument& e) { ... }  // child dulu
            catch (const logic_error& e)      { ... }  // baru parent
            catch (const exception& e)        { ... }  // terakhir base
            catch (...)                       { ... }  // catch-all paling akhir

        Urutan yang SALAH (catch terlalu umum di atas):
            catch (const exception& e)        { ... }  // SALAH - terlalu umum
            catch (const runtime_error& e)    { ... }  // TIDAK PERNAH TERCAPAI!

        Mengapa? Karena runtime_error adalah turunan exception.
        Saat exception dilempar, catch (const exception&) yang
        lebih di atas sudah "menangkap" duluan.

    */

    /* MENGAPA CATCH BY CONST REFERENCE?
        -------------------------------------------------------
        catch (const runtime_error& e)    // BENAR - const reference
        catch (runtime_error e)           // SALAH  - by value (membuat salinan)
        catch (runtime_error* e)          // SALAH  - by pointer (rumit ownership)

        Alasan catch by const reference:
        - Tidak membuat salinan (efisien)
        - Polimorfisme tetap bekerja (virtual what())
        - Tidak bisa modifikasi exception yang ditangkap (safer)
    */

// AB.3 - Exception di Nested Function

    /* EXCEPTION DI NESTED FUNCTION
        -------------------------------------------------------
        throw bisa terjadi di function manapun di call stack,
        tidak harus langsung di dalam blok try.

        C++ akan "naik" (propagate) ke atas call stack
        mencari catch yang cocok.

        Contoh:
            void levelTiga() { throw runtime_error("dari level 3"); }
            void levelDua()  { levelTiga(); }   // tidak ada catch
            void levelSatu() { levelDua();  }   // tidak ada catch

            try {
                levelSatu();   // exception "menggelembung" ke sini
            }
            catch (const runtime_error& e) {
                cout << e.what();   // tertangkap di sini
            }

        Jika tidak ada catch yang cocok di seluruh call stack:
            -> std::terminate() dipanggil -> program CRASH
    */

    /* STACK UNWINDING
        -------------------------------------------------------
        Saat exception propagate ke atas, C++ secara otomatis
        "membongkar" (unwind) setiap stack frame:

        1. Menghentikan eksekusi di titik throw
        2. Memanggil destruktor semua objek lokal di setiap frame
        3. Naik ke frame berikutnya
        4. Terus sampai menemukan catch yang cocok

        Ini menjamin: tidak ada resource leak bahkan saat exception!
        (Ini yang membuat RAII sangat powerful bersama exception)
    */

    /* VISUALISASI PROPAGATION
        -------------------------------------------------------
        main()
            +-> level1()
                    +-> level2()
                        +-> level3() <-- throw di sini
                        (unwind level3)
                    (unwind level2)
            (unwind level1)
        catch di main() <-- tertangkap di sini
    */

    /* CATCH DI LEVEL MANA SAJA
        -------------------------------------------------------
        Bisa catch di function mana saja, tidak harus di main.
        Begitu ada catch yang cocok, propagation BERHENTI.
    */

// AB.4 - Standard Exception Classes

    /* HEADER YANG DIBUTUHKAN
        -------------------------------------------------------
        #include <stdexcept>   // logic_error, runtime_error, dll
        #include <new>         // bad_alloc
        #include <typeinfo>    // bad_cast, bad_typeid
    */

    /* std::exception - BASE CLASS
        -------------------------------------------------------
        Semua exception standar C++ mewarisi dari std::exception.
        Punya satu fungsi virtual:
            virtual const char* what() const noexcept;

        Selalu catch by const reference:
            catch (const exception& e) { cout << e.what(); }
    */

    /* std::logic_error DAN TURUNANNYA
        -------------------------------------------------------
        Logic error = kesalahan yang SEHARUSNYA bisa dicegah.
        Bisa dideteksi saat desain/testing (bukan hanya di runtime).

        invalid_argument   - argumen fungsi tidak valid
            stoi("abc")          -> throw invalid_argument
            Contoh pakai manual:
            throw invalid_argument("Usia tidak boleh negatif");

        out_of_range       - nilai di luar rentang yang diizinkan
            string s = "abc";
            s.at(10)             -> throw out_of_range
            vector<int> v = {1,2,3};
            v.at(5)              -> throw out_of_range

        length_error       - ukuran/panjang melebihi batas maksimum
            string terlalu panjang -> throw length_error

        domain_error       - input di luar domain operasi matematika
            throw domain_error("sqrt dari negatif tidak valid");
    */

    /* std::runtime_error DAN TURUNANNYA
        -------------------------------------------------------
        Runtime error = kesalahan yang hanya bisa dideteksi saat jalan.
        Tidak bisa diprediksi saat compile time.

        runtime_error      - error umum saat runtime
            throw runtime_error("File tidak bisa dibuka");

        overflow_error     - hasil operasi terlalu besar
            throw overflow_error("Nilai meluap kapasitas int");

        underflow_error    - hasil operasi terlalu kecil
            throw underflow_error("Nilai terlalu kecil");

        range_error        - hasil di luar range yang diizinkan
            throw range_error("Hasil di luar jangkauan");
    */

    /* EXCEPTION KHUSUS
        -------------------------------------------------------
        bad_alloc          - new gagal alokasi memori
            int* p = new int[999999999];  -> throw bad_alloc

        bad_cast           - dynamic_cast ke referensi gagal
            Derived& d = dynamic_cast<Derived&>(*basePtr);  -> bad_cast
    */

// AB.5 - Custom Exception

    /* MENGAPA BUAT CUSTOM EXCEPTION?
        -------------------------------------------------------
        Exception standar bagus, tapi seringkali kita butuh:
            - Pesan error yang lebih spesifik untuk domain kita
            - Data tambahan (kode error, field yang salah, URL, dll)
            - Hierarki exception sesuai aplikasi kita
            - Bisa di-catch spesifik per jenis error domain

    */

    /* CARA 1 - Warisi std::exception (paling dasar)
        -------------------------------------------------------
        class NamaException : public exception {
        public:
            const char* what() const noexcept override {
                return "Pesan error tetap";
            }
        };

        Lebih baik simpan pesan di string agar fleksibel:
        class NamaException : public exception {
        private:
            string pesan_;
        public:
            NamaException(const string& p) : pesan_(p) {}
            const char* what() const noexcept override {
                return pesan_.c_str();
            }
        };
    */

    /* CARA 2 - Warisi std::runtime_error (paling umum, lebih praktis)
        -------------------------------------------------------
        Warisi runtime_error lebih praktis karena bisa pass
        pesan lewat konstruktor parent:

        class DatabaseError : public runtime_error {
        public:
            DatabaseError(const string& msg)
                : runtime_error(msg) {}   // delegate ke parent
        };

        throw DatabaseError("Koneksi gagal");
        e.what() -> "Koneksi gagal"
    */

    /* CUSTOM EXCEPTION DENGAN DATA TAMBAHAN
        -------------------------------------------------------
        class HttpException : public runtime_error {
        private:
            int statusCode_;
            string url_;
        public:
            HttpException(int code, const string& url)
                : runtime_error("HTTP " + to_string(code) + " - " + url),
                    statusCode_(code), url_(url) {}

            int    statusCode() const { return statusCode_; }
            string url()        const { return url_; }
        };

        Saat catch, bisa akses data tambahan:
            catch (const HttpException& e) {
                cout << e.statusCode() << endl;  // data tambahan
                cout << e.url()        << endl;
                cout << e.what()       << endl;
            }
    */

    /* KONVENSI PENAMAAN
        -------------------------------------------------------
            - Selalu akhiri dengan "Error" atau "Exception"
            - Contoh: DatabaseError, ValidationException, FileError
            - Warisi dari exception standar yang sesuai
            - Destruktor dan what() harus noexcept
    */

// AB.6 - Custom Exception Hierarki

    /* MENGAPA HIERARKI EXCEPTION?
        -------------------------------------------------------
        Dengan hierarki, kita bisa catch secara fleksibel:
        - Catch SPESIFIK: tangkap hanya ValidationError
        - Catch LEVEL MENENGAH: tangkap semua AppException
        - Catch UMUM: tangkap semua exception standar

        Contoh hierarki:
            exception (standar)
            +-- AppException              <- base semua app error
                +-- ValidationError       <- error validasi input
                +-- NetworkError          <- error jaringan
                |   +-- TimeoutError      <- timeout jaringan
                |   +-- ConnectionError   <- gagal koneksi
                +-- DatabaseError         <- error database
                    +-- QueryError        <- query SQL gagal
                    +-- TransactionError  <- transaksi gagal
    */

    /* CARA MEMBANGUN HIERARKI
        -------------------------------------------------------
            1. Buat base class untuk semua error aplikasi
            (biasanya warisi runtime_error)

            2. Buat kelas menengah untuk kategori error

            3. Buat kelas spesifik untuk error tertentu

            Setiap level bisa tambah data yang relevan.
    */

    /* KAPAN PAKAI HIERARKI?
        -------------------------------------------------------
        Pakai hierarki saat:
            - Aplikasi punya banyak jenis error berbeda
            - Ingin bisa catch per kategori (semua NetworkError)
            - Ingin bedakan error dari modul berbeda (DB vs Network)
            - Library yang dipakai orang lain (public API)

            Untuk program kecil, cukup custom exception flat (file 05).
    */

// AB.7 - Re-throw dan Exception Safety

    /* RE-THROW EXCEPTION
        -------------------------------------------------------
        Bisa tangkap exception, lakukan sesuatu (log, dll),
        lalu lempar ulang agar ditangkap level di atasnya.

        Cara 1: throw; (re-throw TANPA copy)
            catch (const exception& e) {
                cerr << "LOG: " << e.what() << endl;
                throw;   // lempar ulang exception yang SAMA
            }

        Cara 2: throw e; (throw SALINAN - hindari!)
            catch (const exception& e) {
                throw e;   // SALAH! Buat salinan, bisa kehilangan info
            }

        Selalu pakai: throw; (tanpa argumen)
    */

    /* EXCEPTION SAFETY - TIGA LEVEL JAMINAN
        -------------------------------------------------------
        Level 1 - No-throw guarantee (noexcept)
            Dijamin tidak pernah throw exception.
            Contoh: destruktor, swap, move constructor.
            Fungsi ditandai: noexcept

        Level 2 - Strong guarantee (commit-or-rollback)
            Kalau throw, state objek TIDAK BERUBAH (rollback).
            Seperti transaksi database: berhasil semua atau tidak sama sekali.
            Teknik: copy-then-swap idiom.

        Level 3 - Basic guarantee
            Kalau throw, tidak ada resource leak.
            State mungkin berubah tapi valid.
            Ini level MINIMUM yang harus dipenuhi.

        Level 0 - No guarantee (HINDARI!)
            Throw bisa menyebabkan resource leak atau corrupt state.
            Contoh: raw pointer tanpa RAII.
    */

    /* RAII + EXCEPTION = RESOURCE SAFETY
        -------------------------------------------------------
        RAII (Resource Acquisition Is Initialization) memastikan
        resource selalu dibebaskan, bahkan saat exception.

        Tanpa RAII (BERBAHAYA):
            int* ptr = new int[100];
            prosesData(ptr);   // kalau throw...
            delete[] ptr;      // ...ini tidak dieksekusi -> MEMORY LEAK!

        Dengan RAII (AMAN):
            unique_ptr<int[]> ptr = make_unique<int[]>(100);
            prosesData(ptr.get());  // exception? ptr tetap terhapus otomatis!
    */

    /* EXCEPTION DI CONSTRUCTOR
        -------------------------------------------------------
        Constructor tidak punya return value, sehingga tidak bisa
        kembalikan kode error. Exception adalah satu-satunya cara
        memberitahu kegagalan konstruksi.

            class FileReader {
            public:
                FileReader(const string& nama) {
                    file_.open(nama);
                    if (!file_) {
                        throw runtime_error("Tidak bisa buka: " + nama);
                    }
                }
            };

        Objek yang gagal dibuat tidak pernah ada di memori.
        Tidak ada resource leak karena destruktor member dipanggil.
    */

// AB.8 - noexcept

    /* APA ITU noexcept?
        -------------------------------------------------------
        noexcept adalah cara mendeklarasikan bahwa sebuah fungsi
        DIJAMIN tidak akan melempar exception.

        Syntax:
            void fungsi() noexcept { ... }
            int tambah(int a, int b) noexcept { return a + b; }
    */

    /* APA YANG TERJADI JIKA noexcept FUNGSI TERNYATA THROW?
        -------------------------------------------------------
        Jika fungsi yang dideklarasikan noexcept ternyata throw:
            -> std::terminate() langsung dipanggil
            -> Program CRASH seketika
            -> Tidak ada stack unwinding!

        Jadi noexcept adalah janji: "Aku tidak akan throw."
        Jika janji dilanggar, program langsung berhenti.
    */

    /* KEGUNAAN noexcept
        -------------------------------------------------------
        1. Optimasi compiler
            Compiler tidak perlu generate kode untuk stack unwinding.
            Bisa lebih cepat terutama di fungsi yang dipanggil sering.

        2. Dokumentasi
            Memberitahu pengguna: "fungsi ini aman, tidak akan throw"

        3. Wajib untuk beberapa situasi
            - Move constructor dan move assignment operator
            - Swap function
            - Destruktor (sudah implisit noexcept di C++11)
            Tanpa noexcept, STL mungkin tidak menggunakan move yang efisien.

        4. Verifikasi dengan noexcept operator
            noexcept(ekspresi) -> true / false
            Cek apakah ekspresi dijamin tidak throw.
    */

    /* NOEXCEPT KONDISIONAL
        -------------------------------------------------------
        noexcept bisa bergantung kondisi:
            template<typename T>
            void swap(T& a, T& b) noexcept(noexcept(T(T(a)))) { ... }

        Artinya: noexcept hanya jika T bisa dikonstruksi tanpa throw.
        Ini teknik lanjutan yang sering dipakai di template.
    */

    /* DESTRUKTOR DAN noexcept
        -------------------------------------------------------
        Destruktor secara implisit noexcept di C++11!
        JANGAN throw dari destruktor:
            ~MyClass() { throw SomeError(); }  // SANGAT BERBAHAYA!

        Kenapa berbahaya?
        Jika destruktor dipanggil saat stack unwinding (sudah ada exception),
        dan destruktor juga throw, maka ada DUA exception aktif sekaligus.
        C++ tidak bisa handle ini -> std::terminate() -> CRASH!
    */

// AB.9 - Best Practices dan Anti Pattern

    // BEST PRACTICES EXCEPTION HANDLING
    
    /* 1. THROW BY VALUE, CATCH BY CONST REFERENCE
        Selalu throw objek, catch sebagai const reference.

        Benar:
            throw runtime_error("pesan");
            catch (const runtime_error& e) { ... }

        Salah:
            catch (runtime_error e)   // membuat salinan - tidak efisien
            catch (runtime_error* e)  // pointer - siapa yang delete?
    */

    /* 2. URUTAN CATCH: SPESIFIK KE UMUM
        Lihat file 02 untuk penjelasan detail.

        Benar:
            catch (const invalid_argument& e) { ... }  // child dulu
            catch (const logic_error& e)      { ... }  // baru parent
            catch (const exception& e)        { ... }  // terakhir base
            catch (...)                       { ... }  // catch-all terakhir
    */

    /* 3. JANGAN "MENELAN" EXCEPTION
        catch kosong menyembunyikan error - sangat berbahaya!

        Sangat salah:
            catch (...) { }   // exception hilang tanpa jejak!

        Minimal:
            catch (...) { cerr << "Unknown error!" << endl; }

        Lebih baik:
            catch (...) { cerr << "Error"; throw; }  // re-throw!
    */

    /* 4. JANGAN THROW DARI DESTRUKTOR
        Destruktor bisa dipanggil saat stack unwinding (ada exception aktif).
        Kalau destruktor juga throw -> dua exception aktif -> terminate() -> CRASH!

        Salah:
            ~MyClass() { throw SomeError(); }

        Benar:
            ~MyClass() noexcept {
                try { bersihkan(); }
                catch (...) {  abaikan, log saja  }
            }
    */

    /* 5. PAKAI EXCEPTION STANDAR ATAU TURUNANNYA
        Jangan throw tipe primitif (int, string biasa, dll).

        Salah:
            throw 42;
            throw "error string";

        Benar:
            throw runtime_error("pesan error");
            throw invalid_argument("argumen salah");
    */

    /* 6. EXCEPTION SPECIFICATION LAMA - JANGAN DIPAKAI
        Deprecated sejak C++11, dihapus di C++17:

        Jangan:
            void f() throw(int);      // tidak dipakai lagi
            void f() throw();         // ganti dengan noexcept

        Pakai:
            void f() noexcept;        // modern
    */

    /* 7. KAPAN PAKAI EXCEPTION vs RETURN CODE
        Exception untuk: kondisi tidak normal, error dari constructor,
                            error yang tidak bisa diabaikan.
        Return/optional untuk: kondisi normal tapi gagal, kode sangat
                                performance-sensitive.
    */

    /* ANTI-PATTERN YANG HARUS DIHINDARI
        -------------------------------------------------------
            1. Exception swallowing (menelan exception)
            2. Throw dari destruktor
            3. Catch by value (bukan reference)
            4. Catch terlalu umum di tempat yang salah
            5. Exception specification lama (throw(int))
            6. Throw pointer ke objek lokal
            7. Terlalu banyak try-catch (exception bukan untuk flow control)
    */
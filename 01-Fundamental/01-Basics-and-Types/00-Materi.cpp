
// A. Program Pertama
    /*
        Ini adalah struktur paling dasar program C++.

        Setiap program C++ wajib punya:
            1. #include <iostream>  → mengaktifkan fitur input/output (cin, cout)
            2. using namespace std  → biar ga perlu nulis std::cout terus-terusan
            3. int main()           → titik awal program dijalankan (entry point)
            4. return 0             → memberitahu OS bahwa program selesai normal

        Analogi:
            main() itu seperti "pintu utama" rumah.
            Semua tamu (program) masuk lewat sini pertama kali.
    */

// B. Komentar (Comments)
    /*
        1. Pengertian
            Komentar adalah teks yang ditulis dalam code untuk memberikan penjelasan atau catatan.
            Komentar TIDAK akan dijalankan/dieksekusi oleh compiler.
            Fungsi utama: Dokumentasi, penjelasan logic, dan reminder untuk programmer.

        2. Jenis Komentar

        ┌──────────────────────┬──────────────────────────────────────┐
        │ Jenis Komentar       │ Syntax                               │
        ├──────────────────────┼──────────────────────────────────────┤
        │ Single-line          │ // teks komentar                     │
        │ Multi-line           │ /* teks komentar (bisa banyak baris) *\/ │
        └──────────────────────┴──────────────────────────────────────┘

            a. Single-Line Comment (//)
                - Digunakan untuk komentar satu baris
                - Dimulai dengan // dan berlaku sampai akhir baris
                - Contoh: // Ini adalah komentar
            
            b. Multi-Line Comment 
                - Digunakan untuk komentar lebih dari satu baris
                - Dimulai dengan /* dan diakhiri dengan 
                - Cocok untuk dokumentasi panjang atau comment out code
                - Contoh: /* Ini komentar
                            multi baris 

        3. Kapan Menggunakan Komentar
            ✅ GOOD:
                - Menjelaskan KENAPA, bukan APA
                - Dokumentasi fungsi (input, output, purpose)
                - Algoritma yang kompleks
                - TODO/FIXME markers
                - Warning untuk code yang tricky
            
            ❌ BAD:
                - Menjelaskan code yang sudah jelas sendiri
                - Komentar yang outdated atau salah
                - Terlalu verbose/bertele-tele

        4. Best Practices
            - Write comments like you're explaining to someone else
            - Keep comments up-to-date dengan code
            - Use TODO, FIXME, NOTE untuk markers
            - Gunakan untuk section dividers (seperti file ini!)
        
        MARKER KOMENTAR YANG UMUM:
            // TODO  : Sesuatu yang belum dikerjakan
            // FIXME : Bug yang perlu diperbaiki
            // NOTE  : Catatan penting
            // HACK  : Solusi sementara, nanti harus diperbaiki
            // WARN  : Peringatan khusus untuk programmer lain
    */

// C. Variabel
    /*
        Variabel adalah "kotak penyimpanan" data di dalam program.
        Sekali dibuat, nilainya bisa dipakai berkali-kali dan bisa diubah.

        SINTAKS DASAR:
            tipe_data nama_variabel;              // deklarasi saja
            tipe_data nama_variabel = nilai;      // deklarasi + inisialisasi
            tipe_data nama_variabel{nilai};       // C++11 uniform initialization (lebih aman)

        ┌─────────────────────────────────────────────────────────────┐
        │ ATURAN PENAMAAN (WAJIB)                                     │
        ├─────────────────────────────────────────────────────────────┤
        │ ✅ Boleh   : huruf, angka, underscore (_)                   │
        │ ✅ Boleh   : dimulai dengan huruf atau underscore           │
        │ ❌ Dilarang: dimulai dengan angka   → 1nama (SALAH)         │
        │ ❌ Dilarang: pakai spasi            → nama saya (SALAH)     │
        │ ❌ Dilarang: pakai keyword C++      → int, return (SALAH)   │
        │ ❌ Dilarang: karakter spesial       → nama@ (SALAH)         │
        └─────────────────────────────────────────────────────────────┘

        KONVENSI PENAMAAN (SARAN — bukan wajib, tapi penting!):
            camelCase   → untuk variabel & fungsi  : jumlahSiswa, nilaiAkhir
            PascalCase  → untuk class/struct        : DataMahasiswa, NilaiUjian
            UPPER_SNAKE → untuk konstanta           : MAX_NILAI, BATAS_USIA
            snake_case  → alternatif variabel        : jumlah_siswa (kurang umum di C++)

        DEKLARASI vs INISIALISASI:
            int umur;           // ✅ Deklarasi saja — nilai BELUM pasti (garbage value!)
            int umur = 18;      // ✅ Deklarasi + Inisialisasi — nilai sudah 18
            int umur{18};       // ✅ Uniform init C++11 — lebih aman, cegah narrowing
    */

// D. Tipe Data
    /*
        Tipe data memberitahu compiler:
            1. Berapa byte memori yang dibutuhkan
            2. Jenis nilai apa yang boleh disimpan
            3. Operasi apa saja yang boleh dilakukan

        ┌────────────────────────────────────────────────────────────────────┐
        │ TIPE PRIMITIF                                                      │
        ├──────────────┬───────────────┬──────────┬──────────────────────────│
        │ Tipe         │ Keterangan    │ Memori   │ Rentang Nilai            │
        ├──────────────┼───────────────┼──────────┼──────────────────────────│
        │ int          │ Bil. Bulat    │ 4 byte   │ -2,147,483,648 s/d +2B   │
        │ float        │ Bil. Desimal  │ 4 byte   │ ±3.4 × 10^38 (6-7 dig)   │
        │ double       │ Desimal presisi│ 8 byte  │ ±1.7 × 10^308 (15 dig)   │
        │ char         │ 1 karakter    │ 1 byte   │ -128 s/d 127 (ASCII)     │
        │ bool         │ Logika        │ 1 byte   │ true (1) / false (0)     │
        │ string       │ Teks          │ dinamis  │ (bisa sangat panjang)    │
        └──────────────┴───────────────┴──────────┴──────────────────────────│

        ┌────────────────────────────────────────────────────────────────────┐
        │ MODIFIER TIPE DATA                                                 │
        ├───────────────────────────┬────────────────────────────────────────│
        │ Modifier                  │ Efek                                   │
        ├───────────────────────────┼────────────────────────────────────────│
        │ short int                 │ Lebih kecil (2 byte)                   │
        │ long int / long long int  │ Lebih besar (8 byte)                   │
        │ unsigned int              │ Hanya positif, rentang 2x lebih besar  │
        │ long double               │ Presisi lebih tinggi dari double       │
        └───────────────────────────┴────────────────────────────────────────│

        PANDUAN MEMILIH TIPE DATA:
            Gunakan int     → angka bulat biasa (umur, jumlah, indeks)
            Gunakan double  → angka desimal (lebih presisi dari float!)
            Gunakan float   → jika memori sangat terbatas (embedded)
            Gunakan char    → 1 karakter (inisial, kode, grade)
            Gunakan bool    → kondisi benar/salah
            Gunakan string  → teks apapun
            Gunakan long long → angka sangat besar (populasi, byte data)
    */

// E. Const & Constexpr
    /*
        ┌──────────────────────────────────────────────────────────────────┐
        │ ANALOGI SEDERHANA                                                │
        │                                                                  │
        │  Variabel biasa = Papan tulis ✏️  → bisa dihapus, diubah        │
        │  const          = Tinta permanen 🖊️ → bisa dari input, tapi      │
        │                                       setelah diisi tidak bisa  │
        │                                       diubah lagi               │
        │  constexpr      = Cetak batu 🗿    → nilainya harus sudah tahu  │
        │                                       sebelum program jalan      │
        └──────────────────────────────────────────────────────────────────┘

        PERBEDAAN CONST vs CONSTEXPR:

            CONST:
                ✅ Nilai bisa dari runtime (input user, hasil kalkulasi)
                ✅ Lebih fleksibel
                ✅ Bisa di-const dari variabel lain

            CONSTEXPR:
                ✅ Nilai HARUS diketahui saat compile-time
                ✅ Lebih cepat — sudah dikalkulasi sebelum program jalan
                ✅ Wajib dipakai untuk ukuran array yang fixed
                ✅ C++11 feature

        KAPAN PAKAI APA:

            Gunakan constexpr → nilai sudah pasti saat coding
                                (PI, MAX_SIZE, batas-batas tetap)

            Gunakan const     → nilai dari input user atau kalkulasi runtime
                                (harga setelah diskon, hasil DB query)

            Gunakan #define   → hindari! Tidak ada type, tidak ada scope.
                                Lebih aman pakai constexpr.

        KEUNTUNGAN CONST/CONSTEXPR:
            ✅ Safety      : Mencegah perubahan tidak sengaja
            ✅ Readability : Jelas bahwa nilai ini fixed
            ✅ Optimization: Compiler bisa optimize lebih baik
            ✅ Bug early   : Error tertangkap saat compile, bukan runtime


        📚 Materi: Const & Constexpr
            1. Apa itu CONST?
                const = constant = tidak bisa diubah
                Analogi Simple:

                Variabel biasa = Pensil ✏️ (bisa dihapus & ditulis ulang)
                Const = Spidol Permanen 🖊️ (sekali tulis, ga bisa diubah)
            
            2. CONST vs CONSTEXPR
                
                a. CONST:
                    - Nilai bisa ditentukan saat runtime (program jalan)
                    - Lebih fleksibel
                    - Bisa dan cocok dari input user atau hasil kalkulasi
                
                b. CONSEXPR
                    - Nilai HARUS ditentukan saat compile-time (sebelum program jalan)
                    - Lebih strict
                    - Lebih cepat karena sudah dikalkulasi sebelum program jalan
                    - C++11 feature

            3. Kapan Menggunakan
                Gunakan CONSTEXPR:
                    - Nilai sudah pasti saat coding (PI, MAX_SIZE, dll)
                    - Butuh performance optimal
                    - Untuk array size yang fixed
                
                Gunakan CONST:
                    - Nilai dari input user atau kalkulasi runtime
                    - Lebih fleksibel
                    - Prevent accidental modification

            4. Keuntungan Menggunakan Const/Constexpr
                ✅ Safety: Mencegah perubahan tidak sengaja
                ✅ Readability: Jelas bahwa nilai ini fixed
                ✅ Optimization: Compiler bisa optimize lebih baik
                ✅ Bug Prevention: Error tertangkap saat compile, bukan runtime

            5. Naming Convention
                - UPPERCASE_WITH_UNDERSCORE untuk konstanta global
                - camelCase untuk const variable biasa
                Contoh: const double PI_VALUE = 3.14159;
    */

// F. Type Conversion & Casting
    /*
        Type Conversion = mengubah nilai dari satu tipe ke tipe lain.

        ADA 2 JENIS:
            1. Implicit  → compiler lakukan otomatis (kita tidak minta)
            2. Explicit  → kita yang paksa konversi (casting)

        ─────────────────────────────────────────────────────────────
        SAFE DIRECTION — tidak ada data yang hilang (widening):

            char → int → long → long long → float → double → long double

        DANGEROUS DIRECTION — bisa kehilangan data (narrowing):

            long double → double → float → long long → long → int → char
        ─────────────────────────────────────────────────────────────

        C++ STYLE CAST (pakai ini, bukan C-style!):

            static_cast<T>(nilai)
                ↳ Paling umum. Konversi antar tipe numeric, char, dll.
                Aman karena diperiksa oleh compiler.

            dynamic_cast<T>(pointer/ref)
                ↳ Untuk OOP / polymorphism. Pelajari di modul OOP.

            const_cast<T>(nilai)
                ↳ Menghapus const. SANGAT jarang dipakai, hindari.

            reinterpret_cast<T>(nilai)
                ↳ Reinterpret memori mentah. BAHAYA. Hanya untuk
                system programming tingkat rendah.

        ⚠️  JEBAKAN PALING SERING — Integer Division:

            int a = 5, b = 2;
            double hasil = a / b;    // hasil = 2.0 — SALAH!
            // Kenapa? Karena 5/2 = 2 (integer division) dulu,
            // BARU hasilnya 2 dikonversi ke double jadi 2.0

            SOLUSI: Cast salah satu operand sebelum dibagi:
            double hasil = static_cast<double>(a) / b;  // 2.5 ✅
    */

// G. Input & Output
    /*
        1. Pengertian
            a. Input 
                Program menerima suatu data, layaknya seperti program sedang mendengarkan/mencatat inputan user

            b. Output
            Program menampilkan suatu data ke layar, seperti sedang berbicara ke user 
        
        2. Selengkapnya Input & Output

            OUTPUT: Menampilkan ke layar
                Kode	        Fungsi Utama	                        Catatan Tambahan
                -------------------------------------------------------------------------------------------
                cout	        Menampilkan teks/angka 	                Butuh <<
                <<	            Operator pengaliran ke cout	            Bisa chaining
                endl	        Baris baru (newline)	                Lebih formal dari \n

            INPUT: Menerima data dari user
                Kode	        Fungsi Utama	                        Catatan Tambahan
                -------------------------------------------------------------------------------------------
                cin	            Input data (angka/kata)	                Stop di spasi
                >>	            Operator pengaliran ke variabel	        Bisa chaining
                getline()	    Input kalimat lengkap (pakai string)	Cocok untuk nama lengkap, dll
                cin.ignore()	Buang karakter sisa (biasanya \n)	    Wajib sebelum getline() setelah cin

            FORMATTING OUTPUT (butuh #include <iomanip>):

                setw(n)              → lebar field minimum n karakter
                setprecision(n)      → jumlah digit signifikan
                fixed                → aktifkan fixed-point notation
                scientific           → aktifkan scientific notation
                left / right         → alignment
                setfill(c)           → karakter pengisi (default: spasi)
                boolalpha            → tampilkan bool sebagai true/false
                noboolalpha          → kembalikan ke 0/1

            ENDL vs "\n":
                endl  → newline + flush buffer (lebih lambat, tapi aman)
                "\n"  → hanya newline (lebih cepat)
                → Dalam loop besar, pakai "\n" untuk performa lebih baik.
                → Pakai endl kalau penting bahwa output langsung muncul.         
     */

// H. Escape Sequence
    /*
    Escape Sequence adalah kombinasi karakter khusus yang dimulai
    dengan backslash (\) dan mewakili karakter yang tidak bisa
    ditulis langsung dalam string.

    ┌──────┬────────────────────────┬──────────────────────────────────┐
    │ Kode │ Nama                   │ Efek / Keterangan                │
    ├──────┼────────────────────────┼──────────────────────────────────┤
    │ \n   │ Newline                │ Pindah ke baris baru             │ ★ Sering
    │ \t   │ Horizontal Tab         │ Tab ke kanan (biasanya 4/8 spasi)│ ★ Sering
    │ \\   │ Backslash Literal      │ Menampilkan karakter \           │ ★ Sering
    │ \"   │ Double Quote           │ Menampilkan karakter "           │ ★ Sering
    │ \'   │ Single Quote           │ Menampilkan karakter '           │ ★ Sering
    │ \0   │ Null Character         │ Tanda akhir C-style string       │ ★ Sering
    │ \a   │ Bell / Alert           │ Bunyi beep di terminal           │   Jarang
    │ \b   │ Backspace              │ Hapus 1 karakter sebelumnya      │   Jarang
    │ \r   │ Carriage Return        │ Kembali ke awal baris (overwrite)│  Jarang
    │ \f   │ Form Feed              │ Pindah halaman (printer)         │   Jarang
    │ \v   │ Vertical Tab           │ Tab vertikal (jarang support)    │   Jarang
    │ \xhh │ Hex Character          │ Karakter dari kode hex           │   Advance
    │ \nnn │ Octal Character        │ Karakter dari kode oktal         │   Advance
    └──────┴────────────────────────┴──────────────────────────────────┘

    PENTING — ESCAPE DALAM CHAR vs STRING:
        char  c = '\'';     // char kutip tunggal
        char  d = '\"';     // char kutip ganda (bisa tanpa escape juga)
        string s = "Dia berkata \"Halo\"";  // string dengan kutip di dalamnya

    RAW STRING LITERAL (C++11):
        R"(...)" → semua karakter di dalamnya literal, tidak perlu escape!
        Cocok untuk path Windows, regex, multiline text.
        Contoh: string path = R"(C:\Users\Gega\Documents)";
*/
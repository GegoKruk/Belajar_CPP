#include <iostream>
#include <algorithm>    // untuk array modul — Array Algorrithm
#include <cstring>      // untuk array modul — Character Array
#include <iomanip>      // untuk array modul — array multidimensi
#include <cmath>        // untuk struct modul — struct basics
#include <fstream>      // untuk File I/O modul — File I/O
#include <sstream>      // untuk File I/O modul — stringstream
#include <filesystem>   // untuk File I/O modul — cek file exists (C++17)
#include <climits>      // untuk exception modul — LLONG_MAX, SIZE_MAX
using namespace std;

// A. Program Pertama
    void programPertama(){
        cout << "========== Program Pertama ==========" << endl;
        cout << "Halo semuanya aku adalah program pertama hehe..." << endl;
    }

// B. Komentar (Comments)
    /*
        1. Pengertian
            Komentar adalah teks yang ditulis dalam code untuk memberikan penjelasan atau catatan.
            Komentar TIDAK akan dijalankan/dieksekusi oleh compiler.
            Fungsi utama: Dokumentasi, penjelasan logic, dan reminder untuk programmer.

        2. Jenis Komentar
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
    */
    void komentar(){
        cout << endl << "========== Komentar (Comments) ==========" << endl;
        
        // Single-line comment: Komentar satu baris
        cout << "1. Single-Line Comment (//)" << endl;
        cout << "   Contoh: // Ini adalah komentar satu baris" << endl;
        
        /* 
            Multi-line comment:
            Komentar bisa lebih dari satu baris
            Berguna untuk dokumentasi panjang
        */
        cout << endl << "2. Multi-Line Comment (/* */)" << endl;
        cout << "   Contoh: /* Komentar" << endl;
        cout << "              multi baris */" << endl;
        
        // Contoh penggunaan komentar yang baik
        cout << endl << "3. Contoh Penggunaan:" << endl;
        
        // TODO: Tambahkan validasi input
        int nilaiUjian = 85; // Nilai minimal kelulusan adalah 75
        
        cout << "   Nilai Ujian: " << nilaiUjian << endl;
        
        // Formula: Nilai Akhir = (Nilai Ujian × 60%) + (Nilai Tugas × 40%)
        double nilaiTugas = 90;
        double nilaiAkhir = (nilaiUjian * 0.6) + (nilaiTugas * 0.4);
        
        cout << "   Nilai Akhir: " << nilaiAkhir << endl;
        
        cout << endl << "Tips: Komentar yang baik menjelaskan KENAPA, bukan APA" << endl;
        cout << "   Good: // Gunakan 0.6 karena bobot UTS 60% dari total" << endl;
        cout << "   Bad:  // Mengalikan dengan 0.6" << endl;
    }

// C. Const & Constexpr
    /*
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
    void constConstexpr(){
        cout << endl << "========== Const & Constexpr ==========" << endl;
        
        // ===== CONST =====
        cout << "1. CONST (Constant Variable)" << endl;
        
        // Const untuk nilai yang tidak boleh berubah
        const double PI = 3.14159265359;
        const int HARI_DALAM_MINGGU = 7;
        const double PAJAK_PPN = 0.11;  // PPN 11%
        
        cout << "   Nilai PI: " << PI << endl;
        cout << "   Hari dalam minggu: " << HARI_DALAM_MINGGU << endl;
        cout << "   Pajak PPN: " << PAJAK_PPN * 100 << "%" << endl;
        
        // Const bisa dari runtime calculation
        int hargaBarang = 100000;
        const int hargaSetelahPajak = hargaBarang + (hargaBarang * PAJAK_PPN);
        cout << "   Harga setelah pajak: Rp " << hargaSetelahPajak << endl;
        
        // Coba uncomment baris di bawah, akan error!
        // PI = 3.14;  // ❌ ERROR: assignment of read-only variable 'PI'
        
        
        // ===== CONSTEXPR =====
        cout << endl << "2. CONSTEXPR (Compile-time Constant)" << endl;
        
        // Constexpr nilai sudah pasti saat compile
        constexpr int MAX_STUDENTS = 50;
        constexpr int MIN_PASSING_GRADE = 75;
        constexpr double GOLDEN_RATIO = 1.618033988749;
        
        cout << "   Max students: " << MAX_STUDENTS << endl;
        cout << "   Min passing grade: " << MIN_PASSING_GRADE << endl;
        cout << "   Golden ratio: " << GOLDEN_RATIO << endl;
        
        // Constexpr bisa kalkulasi saat compile
        constexpr int SECONDS_IN_MINUTE = 60;
        constexpr int MINUTES_IN_HOUR = 60;
        constexpr int SECONDS_IN_HOUR = SECONDS_IN_MINUTE * MINUTES_IN_HOUR;  // Dihitung saat compile!
        
        cout << "   Seconds in hour: " << SECONDS_IN_HOUR << endl;
        
        
        // ===== PERBEDAAN =====
        cout << endl << "3. Perbedaan Const vs Constexpr" << endl;
        
        // Const: bisa dari input/runtime
        int inputUser = 10;  // Simulasi input
        const int nilaiConst = inputUser * 2;  // ✅ OK
        cout << "   Const dari runtime: " << nilaiConst << endl;
        
        // Constexpr: HARUS compile-time
        constexpr int nilaiConstexpr = 5 * 3;  // ✅ OK
        // constexpr int nilaiConstexpr2 = inputUser * 2;  // ❌ ERROR!
        cout << "   Constexpr compile-time: " << nilaiConstexpr << endl;
        
        
        // ===== PRACTICAL EXAMPLE =====
        cout << endl << "4. Contoh Praktis: Hitung Luas Lingkaran" << endl;
        
        constexpr double PI_LINGKARAN = 3.14159;
        double radius = 7.0;
        
        // Formula: Luas = π × r²
        double luas = PI_LINGKARAN * radius * radius;
        
        cout << "   Radius: " << radius << " cm" << endl;
        cout << "   Luas lingkaran: " << luas << " cm²" << endl;
        
        
        // ===== TIPS =====
        cout << endl << "Tips:" << endl;
        cout << "   - Gunakan const/constexpr untuk nilai yang tidak berubah" << endl;
        cout << "   - Constexpr lebih cepat karena dihitung saat compile" << endl;
        cout << "   - Const lebih fleksibel, bisa dari runtime calculation" << endl;
        cout << "   - UPPERCASE untuk konstanta universal (PI, MAX, dll)" << endl;
    }

// D. Type Conversion & Casting
    /*
        1. Pengertian
            Type Conversion adalah proses mengubah nilai dari satu tipe data ke tipe data lain.
            Contoh: int ke double, double ke int, char ke int, dll.
            
            Ada 2 jenis:
            - Implicit (Automatic): Compiler otomatis convert
            - Explicit (Manual): Programmer yang paksa convert (casting)

        2. Implicit Conversion (Automatic)
            Compiler otomatis convert tanpa diminta.
            
            Safe Direction (Tidak ada data loss):
                char -> int -> long -> float -> double
            
            Dangerous Direction (Ada data loss):
                double -> float -> long -> int -> char
            
            Contoh:
                int x = 5;
                double y = x;  // ✅ Aman: int -> double
                
                double a = 9.99;
                int b = a;     // ⚠️ Bahaya: b = 9 (kehilangan .99)

        3. Explicit Conversion (Manual Casting)
            
            a. C-Style Cast (Old School - Not Recommended)
                Syntax: (tipe_tujuan) nilai
                Contoh: int x = (int) 3.14;
            
            b. C++ Style Cast (Modern - Recommended!)
                
                1) static_cast<T> - Paling sering dipakai
                    Untuk konversi yang "reasonable"
                    Syntax: static_cast<tipe_tujuan>(nilai)
                    Contoh: int x = static_cast<int>(3.14);
                
                2) dynamic_cast<T> - Untuk OOP (polymorphism)
                    Akan dipelajari di modul OOP
                
                3) const_cast<T> - Remove const (jarang dipakai)
                    Bahaya! Hampir tidak pernah dibutuhkan
                
                4) reinterpret_cast<T> - Low-level casting
                    Sangat bahaya! Jangan pakai kecuali tahu benar

        4. Integer Division Trap ⚠️
            JEBAKAN PALING SERING!
            
            int a = 5, b = 2;
            double hasil = a / b;  // hasil = 2.0 (BUKAN 2.5!)
            
            Kenapa? Karena 5/2 dihitung sebagai integer division (=2) dulu!
            
            Solusi:
                double hasil = static_cast<double>(a) / b;  // 2.5 ✅

        5. Narrowing Conversion
            Konversi dari tipe besar ke kecil bisa kehilangan data
            
            double x = 1234.56;
            int y = x;  // y = 1234 (hilang .56)
            
            C++11 Uniform Initialization mencegah ini:
                int y{x};  // ❌ ERROR: narrowing conversion

        6. String Conversion
            String ↔ Number conversion (butuh #include <string>)
            
            String -> Number:
                stoi(str)  - string to int
                stof(str)  - string to float
                stod(str)  - string to double
            
            Number -> String:
                to_string(number)
    */
    void typeConversion(){
        cout << endl << "========== Type Conversion & Casting ==========" << endl;
        
        // ===== 1. IMPLICIT CONVERSION =====
        cout << "1. Implicit Conversion (Automatic)" << endl;
        
        // Safe conversion: int -> double
        int umur = 18;
        double umurDouble = umur;  // Otomatis convert
        cout << "   int ke double: " << umur << " -> " << umurDouble << endl;
        
        // Dangerous conversion: double -> int (data loss!)
        double tinggi = 175.8;
        int tinggiBulat = tinggi;  // Koma hilang!
        cout << "   double ke int: " << tinggi << " -> " << tinggiBulat << " (kehilangan .8)" << endl;
        
        
        // ===== 2. EXPLICIT CONVERSION (C++ STYLE) =====
        cout << endl << "2. Explicit Conversion dengan static_cast" << endl;
        
        double pi = 3.14159;
        int piInt = static_cast<int>(pi);  // Modern C++ way
        cout << "   static_cast<int>(" << pi << ") = " << piInt << endl;
        
        // Char ke int (ASCII value)
        char huruf = 'A';
        int ascii = static_cast<int>(huruf);
        cout << "   Huruf 'A' dalam ASCII: " << ascii << endl;
        
        // Int ke char
        int angkaASCII = 66;
        char hurufDariASCII = static_cast<char>(angkaASCII);
        cout << "   ASCII " << angkaASCII << " adalah huruf: " << hurufDariASCII << endl;
        
        
        // ===== 3. C-STYLE CAST (Old School) =====
        cout << endl << "3. C-Style Cast (Not Recommended)" << endl;
        
        double nilai = 9.99;
        int nilaiInt = (int)nilai;  // Old style
        cout << "   (int)" << nilai << " = " << nilaiInt << endl;
        cout << "   Lebih baik pakai static_cast!" << endl;
        
        
        // ===== 4. INTEGER DIVISION TRAP =====
        cout << endl << "4. INTEGER DIVISION TRAP " << endl;
        
        int a = 5;
        int b = 2;
        
        // SALAH! Hasil = 2.0 bukan 2.5
        double hasilSalah = a / b;
        cout << "   " << a << " / " << b << " (tanpa cast) = " << hasilSalah << " (Salah)" << endl;
        
        // BENAR! Cast salah satu operand
        double hasilBenar = static_cast<double>(a) / b;
        cout << "   static_cast<double>(" << a << ") / " << b << " = " << hasilBenar << " (Benar)" << endl;
        
        // Alternatif: multiply dengan 1.0
        double hasilBenar2 = a * 1.0 / b;
        cout << "   " << a << " * 1.0 / " << b << " = " << hasilBenar2 << " (Benar)" << endl;
        
        
        // ===== 5. TYPE PROMOTION IN OPERATIONS =====
        cout << endl << "5. Type Promotion dalam Operasi" << endl;
        
        int angkaInt = 10;
        double angkaDouble = 3.5;
        double hasilOperasi = angkaInt + angkaDouble;  // int dipromote jadi double
        cout << "   " << angkaInt << " (int) + " << angkaDouble << " (double) = " << hasilOperasi << " (double)" << endl;
        
        
        // ===== 6. STRING CONVERSION =====
        cout << endl << "6. String Conversion" << endl;
        
        // String to Number
        string strAngka = "123";
        int angkaDariString = stoi(strAngka);  // String to Int
        cout << "   String \"" << strAngka << "\" -> int: " << angkaDariString << endl;
        
        string strDesimal = "3.14";
        double desimalDariString = stod(strDesimal);  // String to Double
        cout << "   String \"" << strDesimal << "\" -> double: " << desimalDariString << endl;
        
        // Number to String
        int angka = 42;
        string stringDariAngka = to_string(angka);
        cout << "   int " << angka << " -> String: \"" << stringDariAngka << "\"" << endl;
        
        double desimal = 2.718;
        string stringDariDesimal = to_string(desimal);
        cout << "   double " << desimal << " -> String: \"" << stringDariDesimal << "\"" << endl;
        
        
        // ===== 7. PRACTICAL EXAMPLE =====
        cout << endl << "7. Contoh Praktis: Hitung Rata-rata" << endl;
        
        int nilai1 = 85;
        int nilai2 = 90;
        int nilai3 = 78;
        int totalNilai = nilai1 + nilai2 + nilai3;
        
        // SALAH: Integer division
        double rataRataSalah = totalNilai / 3;
        cout << "   Rata-rata (salah): " << rataRataSalah << " (Salah)" << endl;
        
        // BENAR: Cast ke double
        double rataRataBenar = static_cast<double>(totalNilai) / 3;
        cout << "   Rata-rata (benar): " << rataRataBenar << " (Benar)" << endl;
                
        // ===== TIPS =====
        cout << endl << "# Tips:" << endl;
        cout << "   - Gunakan static_cast untuk konversi explicit" << endl;
        cout << "   - Hati-hati integer division! Cast salah satu operand" << endl;
        cout << "   - Konversi besar -> kecil bisa kehilangan data" << endl;
        cout << "   - Pakai to_string() dan stoi/stof/stod untuk string conversion" << endl;

    }

// E. Variabel
    /*
        1. Pengertian
            Variabel adalah tempat menyimpan suatu data, bisa di mmasukkan suatu nilai (value) dan bisa di gunakan berulang-ulang

        2. Aturan Penamaan Variabel
            Harus dimulai dengan huruf atau underscore (_)
            Tidak boleh pakai spasi
            Hindari nama yang sama dengan keyword C++ (kayak int, return, dll)
            Gunakan nama yang deskriptif: jumlahSiswa, bukan x
    */
    void variabel(){
        string namaLengkap = "Gega Ramadhan";
        int umur = 18;
        cout << endl << "========== Variabel ===========" << endl;
        cout << "Nama Lengkap : " << namaLengkap << endl;
        cout << "Umur : " << umur << endl;
    }

// F. Input & Output
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
    */
    void inputOutput(){
        string namaDepan;
        string namaLengkap;

        cout << endl << "========== Input & Output ==========" << endl;
        cout << "Ini adalah output, menggunakan cout dan diakhiri endl untuk berpindah baris" << endl;

        cout << "Masukkan Nama Depan : ";
        cin >> namaDepan;
        cin.ignore(); // Buang newline sisa dari cin

        cout << "Masukkan Nama Lengkap : ";
        getline(cin, namaLengkap);

        cout << "\nOutput:\n";
        cout << "Nama Depan: " << namaDepan << endl;
        cout << "Nama Lengkap: " << namaLengkap << endl;
    }

// G. Tipe Data
    /*
        1. Pengertian
            Tipe data adalah kategori nilai yang bisa disimpan kedalam variabel. 
            Tipe data itu pasti dan harus dimiliki oleh suatu variabel, wwajib di deklarasikan
            C++ Butuh tahu apa tipe datanya sehingga tidak bingung
    
        2. Klasifikasi Tipe Data C++

            a. Tipe Data Primitif 
                Tipe        Keterangan          Contoh       Memory
                ---------------------------------------------------
                int         Bil Bulat           15           4 Byte
                float       Bil Desimal         3.14         4 Byte
                double      Desimal Presisi     2.718456     8 Byte
                char        Char ASCII          'A'          1 Byte
                bool        Logika              true/false   1 Byte
                string      teks                "GEGA R"   

            b. Tipe Data Modifier
                Modifier	    Contoh	                    Keterangan
                ------------------------------------------------------------------------
                short int	    short x = 10;	            Bilangan bulat kecil
                long int	    long y = 100000;	        Bilangan bulat besar
                unsigned int	unsigned z = 255;	        Bilangan bulat tanpa negatif
                long double	    long double pi = 3.14159;	Desimal sangat presisi

            c. Tipe Data Kompleks 
                Tipe	    Kegunaan
                -------------------------------------------
                array	    Menyimpan banyak nilai sejenis
                struct	    Gabungan beberapa tipe data
                class	    Blueprint objek (OOP)
                enum	    Kumpulan nilai tetap (konstanta)
                pointer	    Menyimpan alamat memori
    */
    void tipeData(){
        string namaLengkap = "Gega Ramadhan";
        int umur = 18;
        float tinggiBadan = 167.5;
        char golDarah = 'B';
        bool lulusSMA = true;
        double presisi = 18.156438;

        cout << endl << "========== Tipe Data ==========" << endl;
        cout << "String  => " << "Teks/Huruf          : " << namaLengkap << endl;
        cout << "Integer => " << "Bil. Bulat          : " << umur << endl;
        cout << "Float   => " << "Desimal             : " << tinggiBadan << endl;
        cout << "Char    => " << "1 Karakter ASCII    : " << golDarah << endl;
        cout << "Bool    => " << "Logika (True/False) : " << lulusSMA << endl;
        cout << "Double  => " << "Desimal Presisi     : " << presisi << endl;
    }

// H. Escape Sequence
    /*
        1. Pengertian
            Escape Sequence adalah suatu fitur yang dapat digunakan untuk memanipulasi string di C++

        2. Daftar Escape Sequence
            Kode	Nama & Fungsi	        Contoh Output 
            \n	    Newline 	            Pindah ke baris berikutnya                  *
            \t	    Tab horizontal	        Spasi tab (biasanya 4–8 karakter)           *
            \\	    Backslash literal	    Menampilkan \                               *
            \'	    Tanda kutip tunggal	    Menampilkan '                               *
            \"	    Tanda kutip ganda	    Menampilkan "                               *
            \a	    Bell/alert (bunyi)	    Bisa bunyi di terminal                      *
            \b	    Backspace	            Menghapus karakter sebelumnya 
            \r	    Carriage return	        Kembali ke awal baris (overwrite)
            \f	    Form feed	            Pindah ke halaman baru (jarang dipakai)
            \v	    Tab vertikal	        Tab ke bawah (jarang dipakai)
            \0	    Null character	        Menandai akhir string C-style
    */
    void escapeSequence(){
        cout << endl << "========== Escape Sequence ==========" << endl;
        cout << "1. Halo aku adalah baris pertama \n dan aku adalah baris kedua" << endl;
        cout << "2. Aku dan Dia berjauhan seperti ini: AKU \t\t DIA" << endl;
        cout << "3. Dia menarauh game di file D:\\GAME\\Steam\\Forza Horizon 5" << endl;
        cout << "4. Ibu berkata \"Makan dulu gek mandi gelak dingin\"" << endl;
        cout << "5. Bahasa Inggris: Hello, good morning y\'all" << endl;
        cout << "6. Aku bisa mengeluarkan suara lho wkwk \a" << endl;
    }

// I. Operator Aritmatika
    /*
        1. Pengertian
            Operator Aritmatika merupakan sebuah operator yang bisa digaunakan untuk menghitung suatu nilai, seperti matematika 

        2. Daftar Opeartor Aritmatika
            Operator	Nama	        Contoh	    Hasil
            ----------------------------------------------
            +	        Penjumlahan	    5 + 3	    8
            -	        Pengurangan	    5 - 3	    2
            *	        Perkalian	    5 * 3	    15
            /	        Pembagian	    6 / 2	    3
            %	        Modulus	        7 % 3	    1

        ⚠️ Catatan Penting
            Pembagian int / int akan menghasilkan bilangan bulat, bukan desimal.
                int x = 5, y = 2;
                cout << x / y;
                Hasilnya diambil depannya aja, koma diabaikan
            
            Modulus % hanya bisa untuk tipe integer, bukan float.
    */
    void operatorAritmatika(){
        int a = 10;
        int b = 5;

        int penjummlahan = a+b;
        int pengurangan = a-b;
        int perkalian = a*b;
        int pembagian = a/b;
        int modulus = a%b;

        cout << endl << "========== Operator Aritmatika ==========" << endl << endl;
        cout << "Penjumlahan => 10 + 5 = " << penjummlahan << endl;
        cout << "Pengurangan => 10 - 5 = " << pengurangan << endl;
        cout << "Perkalian   => 10 * 5 = " << perkalian << endl;
        cout << "Pembagian   => 10 / 5 = " << pembagian << endl;
        cout << "Modulus     => 10 % 5 = " << modulus << endl;
    }

// J. Operator Penugasan
    /*
        1. Pengertian
            Operator Penugasan merupakan sebuah operator yang bisa digaunakan untuk menyimpan
            nilai kedalam variabel dan juga bisa untuk mengubah nilai yang ada 

        2. Daftar Opeartor Penugasan
            Operator	Nama	            Contoh	    Artinya Sama Dengan
            ----------------------------------------------------------------
            =	        Penugasan	        x = 5	    Simpan 5 ke x
            +=	        Tambah & simpan	    x += 3	    x = x + 3
            -=	        Kurang & simpan	    x -= 2	    x = x - 2
            *=	        Kali & simpan	    x *= 4	    x = x * 4
            /=	        Bagi & simpan	    x /= 2	    x = x / 2
            %=	        Modulus & simpan	x %= 3	    x = x % 3

        3. Catatan Penting
            Operator penugasan mengubah nilai variabel secara langsung tanpa perlu deklarasi ulang
            Jangan pakai x /= 0; -> akan menyebabkan runtime error (division by zero)
            x %= 0; juga error
            x += y++ dan x += ++y punya efek berbeda karena urutan eksekusi    
    */
    void operatorPenugasan(){
        cout << endl << "========== Operator Penugasan ==========" << endl;
        int a = 50;
        cout << "Nilai a : " << a << endl;
        
        a += 10;
        cout << "a += 10 : " << a << endl;
        
        a -= 10;
        cout << "a -= 10 : " << a << endl;
        
        a *= 2;
        cout << "a *= 2  : " << a << endl;
        
        a /= 2; 
        cout << "a /= 2  : " << a << endl;
        
        a %= 2; 
        cout << "a %= 2  : " << a << endl;
        
    }

// K. Operator Increment & Decrement
    /*
        1. Pengertian
            Operator Increment digunakan untuk menaikkan 1 nilai 
            Operator Decrement digunakan untuk menurunkan 1 nilai

        2.  Bentuk dan Perilaku
            Bentuk	    Nama	            Contoh	        Artinya Sama Dengan
            ---------------------------------------------------------------------------
            x++	        Post-increment	    x = 5; x++	    x = x + 1 (setelah dipakai)
            ++x	        Pre-increment	    x = 5; ++x	    x = x + 1 (sebelum dipakai)
            x--	        Post-decrement	    x = 5; x--	    x = x - 1 (setelah dipakai)
            --x	        Pre-decrement	    x = 5; --x	    x = x - 1 (sebelum dipakai)

        3. Contoh
            int a = 5;
            int b = a++; // b = 5 (dipakai dulu), a = 6 (baru naik)
            int c = ++a; // a = 7 (naik dan langsung dipakai), c = 7 (udah langsung naik tadi)

    */
    void operatorIncrementDecrement(){
        cout << endl << "========== Operator Increment Decrement ==========" << endl;
        
        cout << "1. Post-Increment" << endl;
        int x = 5;
        int a = x++;
        int b = a + 1;
        cout << "   x = 5 "<< endl;
        cout << "   a = x++ => nilai x belum di naikkan"<< endl;
        cout << "   maka cout a tetap 5"<< endl;
        cout << "   cout a = " << a << endl;
        cout << "   b = a + 1"<< endl;
        cout << "   cout b = " << b << endl;

        cout << endl << "2. Pre-Increment" << endl;
        int y = 5;
        int i = ++y;
        int o = i + 1;
        cout << "   y = 5 "<< endl;
        cout << "   i = y++ => nilai i langsung jadi 6" << endl;
        cout << "   cout i = " << i << endl;
        cout << "   o = i + 1" << endl;
        cout << "   cout o = " << o << endl;

        cout << endl << "\t Intinya jika simbol di depan maka increment/decrement langsung dilakukan dan jika dibelakang maka akan dilakukan diakhir. Hal ini berpengaruh dan harus teliti serta hati-hati" << endl;
    }

// L. Operator Perbandingan 
    /*
        1. Pengertian
            Operator perbandingan adalah operator yang digunakan untuk membandingakan dua nilai. Hasil perbandingan akan berupa boolean. 
            Operator ini biasa digunakan dalam kondisi If, while, for, dan lainnya

        2. Daftar Operator 
            Operator	Nama	            Fungsi	                                            Contoh
            -------------------------------------------------------------------------------------------
            =           Assigment           untuk mengisi suatu variabel                        a = "gega"
            ==	        Sama dengan	        True jika kedua operand bernilai sama	            a == b
            !=	        Tidak sama	        True jika kedua operand bernilai berbeda	        a != b
            <	        Kurang dari	        True jika operand kiri lebih kecil dari kanan	    a < b
            <=	        Kurang atau sama	True jika operand kiri ≤ operand kanan	            a <= b
            >	        Lebih dari	        True jika operand kiri lebih besar dari kanan	    a > b
            >=	        Lebih atau sama	    True jika operand kiri ≥ operand kanan	            a >= b
    */
    void operatorPerbandingan(){
        int a = 10;
        int b = 15;

        cout << endl << "========== Operator Perbandingan==========" << endl;
        cout << "A = 10" << endl;
        cout << "B = 15" << endl;
        cout << "A == B : " << (a == b) << endl;
        cout << "A > B  : " << (a >  b) << endl;
        cout << "A >= B : " << (a >= b) << endl;
        cout << "A < B  : " << (a <  b) << endl;
        cout << "A <= B : " << (a <= b) << endl;

    }

// M. Operator Logika
    /*
        1. 
            Operator logika adalah operator yng berisi Not, And, dan Or. Ketiganya memiliki sifat yang berberda-beda
            Operator logika digunakan untuk menggabungkan ekspresi boolean (true/false) dan menghasilkan keputusan kompleks.

        2. Jenis2nya
            AND     =>  &&
            OR      =>  ||
            NOT     =>  !

        3. Tabel Kebenaran
            a. Tabel AND (False)
                A        B	     A && B
                -----------------------
                true	 true	 true
                true	 false	 false
                false	 true	 false
                false	 false	 false

            b. Tabel OR (True)
                A        B	     A ||B
                -----------------------
                true	 true	 true
                true	 false	 true
                false	 true	 true
                false	 false	 false

            c.  Tabel Not 
                A       !A
                --------------
                true    false
                false   true
    */
    void operatorLogika(){
        cout << endl << "========== Operator Logika ==========" << endl;
        cout << "1. Tabel AND (&&)" << endl;
        cout << "   true  && true  : " << (true && true) << endl;
        cout << "   true  && false : " << (true && false) << endl;
        cout << "   false && true  : " << (false && true) << endl;
        cout << "   false && false : " << (false && false) << endl;

        cout << endl << "2. Tabel OR (||)" << endl;
        cout << "   true  || true  : " << (true || true) << endl;
        cout << "   true  || false : " << (true || false) << endl;
        cout << "   false || true  : " << (false || true) << endl;
        cout << "   false || false : " << (false || false) << endl;
        
        cout << endl << "3. Tabel NOT (!)" << endl;
        cout << "   !true  : " << (!true ) << endl;
        cout << "   !false : " << (!false) << endl;

        
            cout << endl << "==> Coba Program IF ELSE <===" << endl;
            int nilai;

            cout << endl << "Masukkan Nilai Hasil Ujian : ";
            cin>>nilai;

            if (nilai > 85 ){
                cout << "Anda Mendapat Predikat A" << endl;
            } else if (nilai > 75 ){
                cout << "Anda Mendapat Predikat B" << endl;
            } else if (nilai > 70 ){
                cout << "Anda Mendapat Predikat C" << endl;
            } else if (nilai > 60 ){
                cout << "Anda Mendapat Predikat D" << endl;
            } else {
                cout << "Mohon maaf anda belum lulus, ulangi ujian" << endl;
            }
    }

// N. Operator Ternary
    /*
        1. Pengertian
            Operator Ternery adalaah operator penyingkat if-else, biar lebih simple dan mudah tapi harus bijak menggunakannya.
            operator ini menggunakan simbol tanda tanya (?)

        2. Struktur Umum Operator Ternary

            (condition) ? expression_if_true : expression_if_false;

            - condition             : ekspresi boolean (hasilnya true atau false)
            - expression_if_true    : dijalankan jika kondisi bernilai true
            - expression_if_false   : dijalankan jika kondisi bernilai false
    */  
    void operatorTernary(){
        cout << endl << "========== Operator Ternary ==========" << endl;

        int input;
        cout << "Masukkan nilai lebih dari 10 : " << endl;
        cin>>input;

        (input > 10) ? cout << "Sip nilai anda lebih dari 10" << endl : cout << "Tolong masukkan Nilai Lebih dari 10 dong!" << endl; 
    }

// O. Operator Bitwise
    /*
        1. Pengertian
            Operator Bitwise adalah operator yang bekerja di level BIT (binary digit).
            Berbeda dengan operator aritmatika yang bekerja dengan angka desimal,
            bitwise bekerja dengan representasi binary dari angka.
            
            Contoh Binary:
                5 (desimal) = 0101 (binary)
                3 (desimal) = 0011 (binary)

        2. Jenis-Jenis Operator Bitwise
            
            Operator	Nama	        Fungsi	                        Contoh
            --------------------------------------------------------------------------------
            &	        AND	            1 jika kedua bit 1	            5 & 3 = 1
            |	        OR	            1 jika salah satu bit 1	        5 | 3 = 7
            ^	        XOR	            1 jika bit berbeda	            5 ^ 3 = 6
            ~	        NOT	            Balik semua bit	                ~5 = -6
            <<	        Left Shift	    Geser bit ke kiri	            5 << 1 = 10
            >>	        Right Shift	    Geser bit ke kanan	            5 >> 1 = 2

        3. Bitwise AND (&)
            Rule: Hasil 1 hanya jika KEDUA bit bernilai 1
            
            Truth Table:
                A    B    A & B
                0    0      0
                0    1      0
                1    0      0
                1    1      1
            
            Contoh:
                5   -> 0101
                & 3 -> 0011
                ------------
                1   -> 0001

        4. Bitwise OR (|)
            Rule: Hasil 1 jika SALAH SATU atau KEDUA bit bernilai 1
            
            Truth Table:
                A    B    A | B
                0    0      0
                0    1      1
                1    0      1
                1    1      1
            
            Contoh:
                5   -> 0101
                | 3 -> 0011
                ------------
                7   -> 0111

        5. Bitwise XOR (^) - Exclusive OR
            Rule: Hasil 1 jika bit BERBEDA
            
            Truth Table:
                A    B    A ^ B
                0    0      0
                0    1      1
                1    0      1
                1    1      0
            
            Contoh:
                5 -> 0101
                ^ 3 -> 0011
                ------------
                6 -> 0110

        6. Bitwise NOT (~)
            Rule: BALIK semua bit (0->1, 1->0)
            
            Contoh:
                5 -> 00000101
                ~5  -> 11111010 (= -6 dalam signed int)

        7. Left Shift (<<)
            Rule: Geser bit ke KIRI n posisi, isi 0 di kanan
            Formula: x << n = x * (2^n)
            
            Contoh:
                5    -> 00000101
                5 << 1 -> 00001010 (= 10)
                5 << 2 -> 00010100 (= 20)

        8. Right Shift (>>)
            Rule: Geser bit ke KANAN n posisi
            Formula: x >> n = x / (2^n)
            
            Contoh:
                5    -> 00000101
                5 >> 1 -> 00000010 (= 2)
                5 >> 2 -> 00000001 (= 1)

        9. Penggunaan Praktis
            ✅ Cek genap/ganjil: if (n & 1) -> ganjil
            ✅ Multiply by 2^n: x << n (lebih cepat dari x * pow(2,n))
            ✅ Divide by 2^n: x >> n (lebih cepat dari x / pow(2,n))
            ✅ Swap tanpa temp variable (XOR swap)
            ✅ Set/Clear/Toggle specific bits
            ✅ Check if power of 2: (n & (n-1)) == 0
            ✅ Flags & permissions (bitmask)

        10. Catatan Penting
            ⚠️ Bitwise bekerja dengan INTEGER, bukan float/double
            ⚠️ Hati-hati dengan signed vs unsigned integers
            ⚠️ Hasil ~ tergantung ukuran tipe data (8/16/32/64 bit)
            ⚠️ Left shift berlebihan bisa overflow
    */
    void operatorBitwise(){
        cout << endl << "========== Operator Bitwise ==========" << endl;
        
        int a = 5;  // Binary: 0101
        int b = 3;  // Binary: 0011
        
        cout << "Angka: a = " << a << " (binary: 0101)" << endl;
        cout << "Angka: b = " << b << " (binary: 0011)" << endl;
        cout << endl;
        
        
        // ===== 1. BITWISE AND (&) =====
        cout << "1. Bitwise AND (&)" << endl;
        cout << "   Rule: Hasil 1 hanya jika KEDUA bit 1" << endl;
        int resultAND = a & b;
        cout << "   " << a << " & " << b << " = " << resultAND << endl;
        cout << "   Binary: 0101 & 0011 = 0001" << endl;
        
        
        // ===== 2. BITWISE OR (|) =====
        cout << endl << "2. Bitwise OR (|)" << endl;
        cout << "   Rule: Hasil 1 jika SALAH SATU bit 1" << endl;
        int resultOR = a | b;
        cout << "   " << a << " | " << b << " = " << resultOR << endl;
        cout << "   Binary: 0101 | 0011 = 0111" << endl;
        
        
        // ===== 3. BITWISE XOR (^) =====
        cout << endl << "3. Bitwise XOR (^)" << endl;
        cout << "   Rule: Hasil 1 jika bit BERBEDA" << endl;
        int resultXOR = a ^ b;
        cout << "   " << a << " ^ " << b << " = " << resultXOR << endl;
        cout << "   Binary: 0101 ^ 0011 = 0110" << endl;
        
        
        // ===== 4. BITWISE NOT (~) =====
        cout << endl << "4. Bitwise NOT (~)" << endl;
        cout << "   Rule: BALIK semua bit" << endl;
        int resultNOT = ~a;
        cout << "   ~" << a << " = " << resultNOT << endl;
        cout << "   Binary: ~0101 = 1111...1010 (signed: -6)" << endl;
        
        
        // ===== 5. LEFT SHIFT (<<) =====
        cout << endl << "5. Left Shift (<<)" << endl;
        cout << "   Rule: Geser bit ke KIRI, multiply by 2^n" << endl;
        int resultLS1 = a << 1;
        int resultLS2 = a << 2;
        cout << "   " << a << " << 1 = " << resultLS1 << " (5 * 2^1 = 10)" << endl;
        cout << "   " << a << " << 2 = " << resultLS2 << " (5 * 2^2 = 20)" << endl;
        cout << "   Binary: 0101 << 1 = 1010" << endl;
        
        
        // ===== 6. RIGHT SHIFT (>>) =====
        cout << endl << "6. Right Shift (>>)" << endl;
        cout << "   Rule: Geser bit ke KANAN, divide by 2^n" << endl;
        int resultRS1 = a >> 1;
        int resultRS2 = a >> 2;
        cout << "   " << a << " >> 1 = " << resultRS1 << " (5 / 2^1 = 2)" << endl;
        cout << "   " << a << " >> 2 = " << resultRS2 << " (5 / 2^2 = 1)" << endl;
        cout << "   Binary: 0101 >> 1 = 0010" << endl;
        
        
        // ===== 7. PRACTICAL EXAMPLES =====
        cout << endl << "7. Contoh Praktis" << endl;
        
        // A. Cek Genap/Ganjil
        cout << endl << "   A. Cek Genap/Ganjil (Super Fast!)" << endl;
        int angka = 7;
        if (angka & 1) {
            cout << "      " << angka << " adalah GANJIL" << endl;
        } else {
            cout << "      " << angka << " adalah GENAP" << endl;
        }
        cout << "      Cara kerja: " << angka << " & 1 = " << (angka & 1) << endl;
        
        // B. Multiply/Divide cepat
        cout << endl << "   B. Multiply/Divide dengan Power of 2" << endl;
        int num = 10;
        cout << "      " << num << " * 2 = " << (num << 1) << " (menggunakan <<)" << endl;
        cout << "      " << num << " * 4 = " << (num << 2) << " (menggunakan <<)" << endl;
        cout << "      " << num << " / 2 = " << (num >> 1) << " (menggunakan >>)" << endl;
        cout << "      " << num << " / 4 = " << (num >> 2) << " (menggunakan >>)" << endl;
        
        // C. XOR Swap (No Temp Variable!)
        cout << endl << "   C. Swap Tanpa Temp Variable (XOR Magic!)" << endl;
        int x = 5, y = 3;
        cout << "      Sebelum: x = " << x << ", y = " << y << endl;
        x = x ^ y;  // x sekarang = 5 ^ 3
        y = x ^ y;  // y sekarang = (5 ^ 3) ^ 3 = 5
        x = x ^ y;  // x sekarang = (5 ^ 3) ^ 5 = 3
        cout << "      Sesudah: x = " << x << ", y = " << y << endl;
        
        // D. Check Power of 2
        cout << endl << "   D. Cek Apakah Power of 2" << endl;
        int testNum = 8;
        bool isPowerOf2 = (testNum > 0) && ((testNum & (testNum - 1)) == 0);
        cout << "      Apakah " << testNum << " power of 2? " << (isPowerOf2 ? "YA" : "TIDAK") << endl;
        cout << "      Cara: " << testNum << " & " << (testNum-1) << " = " << (testNum & (testNum-1)) << endl;
        
        // E. Set/Clear/Toggle Bit
        cout << endl << "   E. Manipulasi Bit Tertentu" << endl;
        int value = 5;  // 0101
        int position = 1;
        
        // Set bit (nyalakan bit ke-n)
        int setBit = value | (1 << position);
        cout << "      Set bit-" << position << " dari " << value << " = " << setBit << " (binary: 0111)" << endl;
        
        // Clear bit (matikan bit ke-n)
        int clearBit = value & ~(1 << position);
        cout << "      Clear bit-" << position << " dari " << value << " = " << clearBit << " (binary: 0101)" << endl;
        
        // Toggle bit (flip bit ke-n)
        int toggleBit = value ^ (1 << position);
        cout << "      Toggle bit-" << position << " dari " << value << " = " << toggleBit << " (binary: 0111)" << endl;
        
        
        // ===== TIPS =====
        cout << endl << "💡 Tips:" << endl;
        cout << "   - Bitwise HANYA untuk tipe INTEGER (int, char, long, dll)" << endl;
        cout << "   - Shift operation (<<, >>) lebih cepat dari multiply/divide" << endl;
        cout << "   - XOR berguna untuk swap, encryption sederhana, toggle" << endl;
        cout << "   - n & 1 lebih cepat dari n % 2 untuk cek genap/ganjil" << endl;
        cout << "   - Berguna untuk: flags, permissions, optimization, graphics" << endl;
    }

// P. Percabangan (If, else if, else, switch case)
    /*
        1. Pengertian
            Kontrol alur adalah cara program menentukan jalur eksekusi berdasarkan kondisi atau logika. 
            Tanpa kontrol alur, program hanya berjalan lurus dari atas ke bawah.

        2. 🧱 Struktur Materi
            Submateri	                Fungsi Utama
            --------------------------------------------------------------
            if, else, else if	        Cabang logika berdasarkan kondisi
            switch-case	                Alternatif if untuk nilai tetap
            break, continue	            Kontrol eksekusi dalam loop
            Nested if	                Kondisi bertingkat
            Kombinasi dengan logika	    Gabung dengan &&, ||, !
    */
    void controlIfElse(){
        int inputNilai;

        cout << endl << "========== Control Flow If Else ==========" << endl;
        cout << "Masukkan nilai ujian anda : ";
        cin >> inputNilai;
        
        if (inputNilai >= 75) {
            cout << "Selamat nilai anda berada diatas KKM" << endl;
        } else if (inputNilai < 75) {
            cout << "Mohon maaf nilai anda masih berada dibawah KKN" << endl;
            cout << "Ikuti Ujian Remidial" << endl;
        } else {
            cout << "Nilai tidak valid, mohon coba lagi!" << endl;
        }
    }
    
    void controlSwitchCase(){
        int inputMenuMakanan;

        cout << endl << "========== Control Flow Switch Case ==========" << endl;
        cout << "[Menu Resto Pak Mursidi]__________" << endl;
        cout << "|1. Nasi Goreng Ayam             |" << endl;
        cout << "|2. Bebek Goreng                 |" << endl;
        cout << "|3. Bakmi Jawa                   |" << endl;
        cout << "|4. Sate Ayam Madura             |" << endl;
        cout << "|5. Capcay Kuah                  |" << endl;
        cout << "|________________________________|" << endl;

        cout << "Masukkan Menu Pilihan Anda (1 - 5) : ";
        cin >> inputMenuMakanan;

        switch (inputMenuMakanan)
        {
        case 1 :
            cout << "Data Sudah Masuk, Makanan yang anda pilih adalah Nasi Goreng Ayam" << endl;
            break;
        case 2 :
            cout << "Data Sudah Masuk, Makanan yang anda pilih adalah Bebek Goreng" << endl;
            break;
        case 3 :
            cout << "Data Sudah Masuk, Makanan yang anda pilih adalah Bakmi Jawa" << endl;
            break;
        case 4 :
            cout << "Data Sudah Masuk, Makanan yang anda pilih adalah Sate Ayam Madura" << endl;
            break;
        case 5 :
            cout << "Data Sudah Masuk, Makanan yang anda pilih adalah Capcay Kuah" << endl;
            break;
        default:
            cout << "Masukkan Data dengan benar, dengan mengisi angka (1 - 5). Terima kasih!" << endl;
            break;
        }
    }

    void controlNestedIfElse(){
        int ipk, masaStudi;

        cout << endl << "========== Control Flow Nested If Else ==========" << endl;
        cout << "Masukkan IPK anda : ";
        cin >> ipk;
        cout << "Masukkan masa studi anda : ";
        cin >> masaStudi;

        if (ipk >= 4){
            cout << "Selamat anda lulus dengan IPK 4" << endl;
            if (masaStudi <= 3){
                cout << "Selamat anda juga mendapat predikat Cum-Laude" << endl;
            }
        } else if (ipk > 3){
            cout << "Selamat anda lulus dengan IPK diatas 3" << endl;
        } else {
            cout << "Selamat anda lulus" << endl;
        }
    }

// Q. Perulangan (For, While, Do While)
    /*
        1. Pengertian
            Perulangan adalah proses mengulang eksekusi blok kode selama kondisi tertentu terpenuhi. 
            Cocok untuk:
            - Menampilkan data berulang
            - Melakukan kalkulasi bertahap
            - Validasi input
            - Simulasi proses
        
        2. 🧱 Jenis-Jenis Perulangan
            Jenis Loop	    Ciri Utama	                            Cocok Untuk
            ----------------------------------------------------------------------------------------
            for	            Jumlah pengulangan diketahui	        Counter tetap, tabel, kalkulasi
            while	        Pengulangan selama kondisi true	        Validasi input, proses dinamis
            do-while	    Eksekusi minimal sekali, lalu cek	    Menu interaktif, input ulang

        3. 📘 Struktur dan Contoh Sintaks 
            a. For Loop
                for (inisialisasi; kondisi; update){
                    //block kode yangg diulang
                }
                
                for (int i = 1; i <= 5; i++){
                    cout << "Perulangan ke-" << i << endl;
                }

            b. While loop
                while (kondisi){
                    //block yang diulang
                }

                int i = 10
                while (i <= 20){
                    cout << "Iterasi ke-" << i << endl;
                    i++;
                }

            c. Do While Loop
                do {
                    // blok yang diulang
                } while (kondisi);

                int i = 1;
                do {
                    cout << "Iterasi ke-" << i << endl;
                    i++;
                } while (i <= 5);
    */
    void perulanganFor(){
        int inputNilai;

        cout << endl << "========== Perulangan - For ==========" << endl;
        cout << "Masukkan angka kurang dari 10, nanti akan looping sampai 50..." << endl;
        cout << "Masukkan : ";
        cin >> inputNilai;

        for (int output = inputNilai; output <= 50; output++)
        {
            cout << "Perulangan ke-"<< output << endl;
        }
    }

    void perulanganWhile(){
        int angka1;       
        int angka2;
        int hasil;

        cout << endl << "========== Perulangan - While ==========" << endl;
        cout << "Angka Pertama Loop Hingga 25" << endl;
        cout << "Masukkan angka pertama (<10): ";
        cin >> angka1;

        int i = angka1;
        while (i <= 25){
            cout << "Perulangan angka pertama ke-"<< i << endl;
            i++;
        }

        cout << "Angka Pertama Loop Hingga 50" << endl;
        cout << "Masukkan angka kedua (<25): ";
        cin >> angka2;

        int f = angka2;
        while (f <= 50){
            cout << "Perulangan angka kedua ke-" << f << endl;
            f++;
        }
    }

    void perulanganDoWhile(){
        int pilihanUser;
        int pilihanMakanan;
        int pilihanMinuman;

        do{
            cout << "[Menu Kantin Sekolah]__________" << endl;
            cout << "|1. Makanan                   |" << endl;
            cout << "|2. Minuman                   |" << endl;
            cout << "|3. Cek Harga & Bayar         |" << endl;
            cout << "|4. Keluar                    |" << endl;
            cout << "|_____________________________|" << endl;
            cout << " Pilih : ";
            cin >> pilihanUser;

            switch(pilihanUser){
                case 1 :
                    cout << "[Menu Makanan]__________" << endl;
                    cout << "|1. Bakso              |" << endl;
                    cout << "|2. Soto Daging        |" << endl;
                    cout << "|3. Capcay Kuah        |" << endl;
                    cout << "|4. Mie Dok-Dok        |" << endl;
                    cout << "|______________________|" << endl;
                    cout << " Pilih : ";
                    cin >> pilihanMakanan;
                break;
                case 2 :
                    cout << "[Menu Minuman]__________" << endl;
                    cout << "|1. Jeruk              |" << endl;
                    cout << "|2. Teh                |" << endl;
                    cout << "|3. Wedang Ronde       |" << endl;
                    cout << "|4. Es Teler           |" << endl;
                    cout << "|______________________|" << endl;
                    cout << " Pilih : ";
                    cin >> pilihanMinuman;
                break;
            }
        
        
        } while (pilihanUser != 4);
        
    }

// R. Loop Control (Break, Continue, Goto)
    /*
        1. Pengertian
            Loop Control adalah perintah khusus untuk mengontrol alur perulangan (loop).
            Ada 3 statement utama:
            - break: Keluar dari loop seketika
            - continue: Skip iterasi saat ini, lanjut ke iterasi berikutnya  
            - goto: Jump ke label (JANGAN PAKAI!)

        2. BREAK Statement
            Fungsi: Keluar SEKETIKA dari loop (for, while, do-while, switch)
            
            Syntax:
                if (kondisi) {
                    break;  // Keluar dari loop
                }
            
            Karakteristik:
                ✅ Keluar seketika dari loop
                ✅ Hanya keluar dari loop TERDEKAT (kalau nested)
                ✅ Sering untuk "early exit" - keluar kalau kondisi tercapai
            
            Use Cases:
                - Search: stop kalau item ditemukan
                - Validation: stop kalau input valid
                - Error: stop kalau ada error fatal
                - Game: stop kalau game over

        3. CONTINUE Statement
            Fungsi: SKIP sisa code di iterasi ini, langsung ke iterasi berikutnya
            
            Syntax:
                if (kondisi) {
                    continue;  // Skip ke iterasi berikutnya
                }
            
            Karakteristik:
                ✅ Skip sisa code untuk iterasi ini
                ✅ Loop TIDAK berhenti, lanjut iterasi berikutnya
                ✅ Di for: langsung ke update (i++)
                ✅ Di while: langsung cek kondisi lagi
            
            Use Cases:
                - Skip invalid/corrupt data
                - Process hanya data tertentu
                - Skip angka genap, process ganjil
                - Filter data on-the-fly

        4. BREAK vs CONTINUE
            ┌────────────┬─────────────────┬──────────────────────┐
            │   Aspek    │      BREAK      │      CONTINUE        │
            ├────────────┼─────────────────┼──────────────────────┤
            │ Fungsi     │ Keluar dari loop│ Skip ke iterasi next │
            │ Loop       │ STOP sepenuhnya │ Tetap jalan          │
            │ Code after │ Tidak dieksekusi│ Tidak (iter ini saja)│
            │ Use case   │ Found, error    │ Skip invalid data    │
            │ Analogi    │ Keluar gedung   │ Skip tangga          │
            └────────────┴─────────────────┴──────────────────────┘

        5. GOTO Statement (AVOID!)
            Fungsi: Jump ke label tertentu
            
            KENAPA JANGAN PAKAI:
                ❌ "Spaghetti Code" - code berantakan
                ❌ Hard to debug - flow tidak jelas
                ❌ Hard to maintain - susah dipahami
                ❌ Old-school - dari era C jadul
                ❌ Ada alternatif LEBIH BAIK (break, continue, functions)
            
            Quote: "GOTO considered harmful" - Edsger Dijkstra
            
            Alternatif:
                goto -> break, continue, return, proper structure

        6. Nested Loops
            PENTING: break/continue hanya affect LOOP TERDEKAT!
            
            Untuk keluar dari multiple loops:
                - Cara 1: Boolean flag
                - Cara 2: Function + return (RECOMMENDED!)

        7. Best Practices
            ✅ Gunakan break untuk early exit optimization
            ✅ Gunakan continue untuk skip invalid data
            ✅ Hindari deep nesting dengan continue
            ✅ JANGAN gunakan goto!
            ✅ Comment kenapa pakai break/continue
            ✅ Keep it simple and readable
    */
    void loopControl(){
        cout << endl << "========== Loop Control (Break & Continue) ==========" << endl;
        
        
        // ===== 1. BREAK STATEMENT =====
        cout << "1. BREAK - Keluar dari Loop" << endl;
        
        // Contoh 1A: Search dengan break
        cout << endl << "   A. Search dengan Break (Early Exit)" << endl;
        int arr[] = {2, 5, 8, 12, 15, 20};
        int target = 12;
        bool found = false;
        int position = -1;
        
        for (int i = 0; i < 6; i++) {
            cout << "      Cek index " << i << ": " << arr[i] << endl;
            if (arr[i] == target) {
                found = true;
                position = i;
                cout << "      >>> FOUND! Breaking..." << endl;
                break;  // Keluar seketika!
            }
        }
        
        if (found) {
            cout << "      Target " << target << " ditemukan di index " << position << endl;
        }
        
        // Contoh 1B: Input validation dengan break
        cout << endl << "   B. Input Validation dengan Break" << endl;
        cout << "      (Simulasi: akan berhenti di input valid)" << endl;
        
        int testInputs[] = {15, -5, 7};  // Simulasi input
        for (int input : testInputs) {
            cout << "      Try input: " << input << " ... ";
            if (input >= 1 && input <= 10) {
                cout << "Valid! Break." << endl;
                break;  // Input valid, keluar
            }
            cout << "Invalid!" << endl;
        }
        
        
        // ===== 2. CONTINUE STATEMENT =====
        cout << endl << "2. CONTINUE - Skip ke Iterasi Berikutnya" << endl;
        
        // Contoh 2A: Print hanya angka ganjil
        cout << endl << "   A. Print Angka Ganjil (Skip Genap)" << endl;
        cout << "      Angka 1-10, skip yang genap: ";
        for (int i = 1; i <= 10; i++) {
            if (i % 2 == 0) {
                continue;  // Skip angka genap
            }
            cout << i << " ";
        }
        cout << endl;
        
        // Contoh 2B: Process valid data aja
        cout << endl << "   B. Process Valid Data (Skip Negatif)" << endl;
        int data[] = {5, -2, 8, -1, 3, 0, 7};
        int sum = 0;
        
        cout << "      Data: ";
        for (int val : data) {
            cout << val << " ";
        }
        cout << endl;
        
        cout << "      Process: ";
        for (int val : data) {
            if (val <= 0) {
                cout << "[skip " << val << "] ";
                continue;  // Skip data <= 0
            }
            sum += val;
            cout << "[+" << val << "] ";
        }
        cout << endl;
        cout << "      Sum positif: " << sum << endl;
        
        
        // ===== 3. BREAK vs CONTINUE COMPARISON =====
        cout << endl << "3. Break vs Continue - Perbandingan" << endl;
        
        cout << endl << "   Loop 1-5 dengan BREAK di i=3:" << endl;
        cout << "      ";
        for (int i = 1; i <= 5; i++) {
            if (i == 3) {
                cout << "[BREAK] ";
                break;  // Stop di 3
            }
            cout << i << " ";
        }
        cout << "-> Loop STOP" << endl;
        
        cout << endl << "   Loop 1-5 dengan CONTINUE di i=3:" << endl;
        cout << "      ";
        for (int i = 1; i <= 5; i++) {
            if (i == 3) {
                cout << "[SKIP] ";
                continue;  // Skip 3
            }
            cout << i << " ";
        }
        cout << "-> Loop LANJUT" << endl;
        
        
        // ===== 4. NESTED LOOPS =====
        cout << endl << "4. Break/Continue di Nested Loops" << endl;
        
        cout << endl << "   Break di inner loop (hanya affect inner):" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "      Row " << i << ": ";
            for (int j = 0; j < 5; j++) {
                if (j == 3) {
                    cout << "[break] ";
                    break;  // Keluar dari inner loop aja
                }
                cout << j << " ";
            }
            cout << endl;
        }
        
        
        // ===== 5. PRACTICAL PATTERNS =====
        cout << endl << "5. Practical Patterns" << endl;
        
        // Pattern A: Infinite loop dengan break
        cout << endl << "   A. Infinite Loop dengan Break (Countdown)" << endl;
        int countdown = 5;
        cout << "      Countdown: ";
        while (true) {  // Infinite!
            cout << countdown << " ";
            countdown--;
            if (countdown == 0) {
                cout << "STOP!";
                break;  // Exit point
            }
        }
        cout << endl;
        
        // Pattern B: Skip invalid, process valid
        cout << endl << "   B. Filter Data On-The-Fly" << endl;
        int scores[] = {85, -1, 90, 150, 78, 92, -5};
        cout << "      Scores: ";
        for (int s : scores) cout << s << " ";
        cout << endl;
        
        cout << "      Valid (0-100): ";
        for (int score : scores) {
            if (score < 0 || score > 100) {
                continue;  // Skip invalid
            }
            cout << score << " ";
        }
        cout << endl;
        
        
        // ===== 6. GOTO WARNING =====
        cout << endl << "6. GOTO Statement (DON'T USE!)" << endl;
        cout << "   GOTO considered HARMFUL!" << endl;
        cout << "   Causes 'spaghetti code'" << endl;
        cout << "   Hard to debug and maintain" << endl;
        cout << "   Use break/continue/return instead!" << endl;
        cout << endl;
        cout << "   // JANGAN LAKUKAN INI:" << endl;
        cout << "   // start:" << endl;
        cout << "   //     code..." << endl;
        cout << "   //     if (x) goto start;  // BAD!" << endl;
        cout << endl;
        cout << "   // LAKUKAN INI:" << endl;
        cout << "   // while (condition) {" << endl;
        cout << "   //     code..." << endl;
        cout << "   //     if (x) break;  // ✅ GOOD!" << endl;
        cout << "   // }" << endl;
        
        
        // ===== TIPS =====
        cout << endl << "Tips:" << endl;
        cout << "   - break: keluar dari loop (stop completely)" << endl;
        cout << "   - continue: skip iterasi ini (loop tetap jalan)" << endl;
        cout << "   - break untuk optimization (early exit)" << endl;
        cout << "   - continue untuk filter/skip invalid data" << endl;
        cout << "   - Nested loop: break/continue hanya affect loop terdekat" << endl;
        cout << "   - JANGAN PAKAI GOTO! Pakai break/continue/return" << endl;
    }

// S. Nested Loops
    /*
        1. Pengertian Nested Loops
            Nested Loops adalah loop yang ada DI DALAM loop lain.
            Struktur: Loop outer -> Loop inner (di dalam outer)
            
            Analogi:
                Outer loop = Lantai gedung
                Inner loop = Kamar di tiap lantai
                Untuk kunjungi semua kamar -> nested loops!
            
            Syntax:
                for (int i = 0; i < rows; i++) {      // Outer loop
                    for (int j = 0; j < cols; j++) {  // Inner loop
                        // Code di sini
                    }
                }

        2. Cara Kerja Nested Loops
            Execution flow:
                Outer i=0: Inner j complete (j=0,1,2...)
                Outer i=1: Inner j complete lagi
                Outer i=2: Inner j complete lagi
                ...
            
            Key: Inner loop SELESAI SEMUA sebelum outer increment!

        3. Pattern Printing
            Pattern printing adalah latihan TERBAIK untuk:
                ✅ Memahami nested loops mendalam
                ✅ Melatih logika programming
                ✅ Visualisasi konsep loop
                ✅ Brain gym!
            
            Kategori Pattern:
                1. Rectangle patterns (solid, hollow)
                2. Triangle patterns (right, inverted, aligned)
                3. Pyramid patterns (normal, inverted, diamond)
                4. Number patterns (sequence, Floyd's, Pascal's)
                5. Advanced patterns (butterfly, hourglass)

        4. Key Concepts Pattern
            - Outer loop (i) = Baris
            - Inner loop (j) = Kolom
            - Relasi i & j menentukan kapan print:
                • j <= i          -> increasing per baris
                • j < rows-i      -> decreasing per baris
                • j >= rows-i-1   -> right alignment
            - Spasi untuk alignment (centered, right)

        5. Thinking Process
            Step 1: Identifikasi jumlah baris dan kolom
            Step 2: Cari pola per baris (bertambah/berkurang?)
            Step 3: Tentukan relasi i dan j
            Step 4: Butuh spasi? Berapa?
            Step 5: Test dengan input kecil (3-5 baris)

        6. Performance Note
            ⚠️ Nested loops = O(n²) complexity
            ⚠️ Triple nested = O(n³) -> avoid kalau bisa
            ⚠️ Untuk data besar, pertimbangkan algorithm lain
    */
    void nestedLoopsPattern(){
        cout << endl << "========== Nested Loops & Pattern Printing ==========" << endl;
        
        
        // ===== 1. SIMPLE NESTED LOOP =====
        cout << "1. Simple Nested Loop (3x3 Grid)" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "   ";
            for (int j = 0; j < 3; j++) {
                cout << "(" << i << "," << j << ") ";
            }
            cout << endl;
        }
        
        
        // ===== 2. RECTANGLE PATTERNS =====
        cout << endl << "2. Rectangle Patterns" << endl;
        
        // A. Solid Rectangle
        cout << endl << "   A. Solid Rectangle (4x6)" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "      ";
            for (int j = 0; j < 6; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        // B. Hollow Rectangle
        cout << endl << "   B. Hollow Rectangle (5x7)" << endl;
        int rows = 5, cols = 7;
        for (int i = 0; i < rows; i++) {
            cout << "      ";
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
        
        
        // ===== 3. TRIANGLE PATTERNS =====
        cout << endl << "3. Triangle Patterns" << endl;
        
        // A. Right-Angled Triangle
        cout << endl << "   A. Right-Angled Triangle" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "      ";
            for (int j = 0; j <= i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        // B. Inverted Triangle
        cout << endl << "   B. Inverted Triangle" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "      ";
            for (int j = 0; j < 5-i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        // C. Right-Aligned Triangle
        cout << endl << "   C. Right-Aligned Triangle" << endl;
        rows = 5;
        for (int i = 0; i < rows; i++) {
            cout << "      ";
            // Spasi kiri
            for (int j = 0; j < rows-i-1; j++) {
                cout << "  ";
            }
            // Bintang
            for (int j = 0; j <= i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        
        // ===== 4. PYRAMID PATTERNS =====
        cout << endl << "4. Pyramid Patterns" << endl;
        
        // A. Pyramid
        cout << endl << "   A. Pyramid (Centered)" << endl;
        rows = 5;
        for (int i = 0; i < rows; i++) {
            cout << "      ";
            // Spasi
            for (int j = 0; j < rows-i-1; j++) {
                cout << " ";
            }
            // Bintang
            for (int j = 0; j <= i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        // B. Inverted Pyramid
        cout << endl << "   B. Inverted Pyramid" << endl;
        rows = 5;
        for (int i = 0; i < rows; i++) {
            cout << "      ";
            // Spasi
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            // Bintang
            for (int j = 0; j < rows-i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
        
        // C. Diamond
        cout << endl << "   C. Diamond" << endl;
        int n = 5;
        
        // Upper half
        for (int i = 0; i < n; i++) {
            cout << "      ";
            for (int j = 0; j < n-i-1; j++) cout << " ";
            for (int j = 0; j <= i; j++) cout << "* ";
            cout << endl;
        }
        
        // Lower half
        for (int i = 0; i < n-1; i++) {
            cout << "      ";
            for (int j = 0; j <= i; j++) cout << " ";
            for (int j = 0; j < n-i-1; j++) cout << "* ";
            cout << endl;
        }
        
        
        // ===== 5. NUMBER PATTERNS =====
        cout << endl << "5. Number Patterns" << endl;
        
        // A. Number Triangle
        cout << endl << "   A. Number Triangle" << endl;
        for (int i = 1; i <= 5; i++) {
            cout << "      ";
            for (int j = 1; j <= i; j++) {
                cout << j << " ";
            }
            cout << endl;
        }
        
        // B. Floyd's Triangle
        cout << endl << "   B. Floyd's Triangle" << endl;
        int num = 1;
        for (int i = 1; i <= 5; i++) {
            cout << "      ";
            for (int j = 1; j <= i; j++) {
                cout << num++ << " ";
            }
            cout << endl;
        }
        
        // C. Multiplication Table
        cout << endl << "   C. Multiplication Table (5x5)" << endl;
        cout << "      ";
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= 5; j++) {
                cout << i*j << "\t";
            }
            cout << endl << "      ";
        }
        
        
        // ===== 6. ADVANCED PATTERNS =====
        cout << endl << "6. Advanced Patterns" << endl;
        
        // A. Hourglass
        cout << endl << "   A. Hourglass" << endl;
        rows = 5;
        
        // Upper (inverted pyramid)
        for (int i = 0; i < rows; i++) {
            cout << "      ";
            for (int j = 0; j < i; j++) cout << " ";
            for (int j = 0; j < rows-i; j++) cout << "* ";
            cout << endl;
        }
        
        // Lower (pyramid)
        for (int i = 1; i < rows; i++) {
            cout << "      ";
            for (int j = 0; j < rows-i-1; j++) cout << " ";
            for (int j = 0; j <= i; j++) cout << "* ";
            cout << endl;
        }
        
        
        // ===== 7. PRACTICAL EXAMPLE =====
        cout << endl << "7. Practical: Matrix Coordinates" << endl;
        cout << "   Matrix 3x4:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "      ";
            for (int j = 0; j < 4; j++) {
                cout << "[" << i << "," << j << "] ";
            }
            cout << endl;
        }
        
        
        // ===== TIPS =====
        cout << endl << "Tips:" << endl;
        cout << "   - Outer loop (i) = Baris, Inner loop (j) = Kolom" << endl;
        cout << "   - j <= i -> increasing, j < rows-i -> decreasing" << endl;
        cout << "   - Gunakan spasi untuk alignment (centered/right)" << endl;
        cout << "   - Start simple (3 baris), lalu scale up" << endl;
        cout << "   - Trace dengan pen & paper dulu!" << endl;
        cout << "   - Nested loops = O(n²), hati-hati dengan data besar" << endl;
    }

// T. FUNCTION
    /* Modul T.0 — Pengertian Function
        ╔══════════════════════════════════════════════════════════╗
        ║                   BAB T — FUNCTION                       ║
        ╠══════════════════════════════════════════════════════════╣
        ║  T.0  Pengertian Function                                ║
        ║  T.1  Dasar Function (Fruitful & Void)                   ║
        ║  T.2  Default Parameter                                  ║
        ║  T.3  Function Overloading                               ║
        ║  T.4  Inline Function                                    ║
        ║  T.5  Pass by Value vs Pass by Reference                 ║
        ║  T.6  Multiple Return via Reference                      ║
        ║  T.7  Recursive Function                                 ║
        ║  T.8  Function Scope (Local vs Global)                   ║
        ║  T.9  Function Declaration / Prototype                   ║
        ╚══════════════════════════════════════════════════════════╝

        📚 PENGERTIAN FUNCTION
            Function ibaratkan sebuah mesin:
                - Punya nama yang bisa dipanggil berulang-ulang
                - Bisa diberi bahan baku (parameter/input)
                - Mengolah sesuatu di dalamnya (body)
                - Bisa menghasilkan sesuatu (return value)

        🎯 MENGAPA BUTUH FUNCTION?
            ✅ Reusability   : Bisa dipakai berkali-kali tanpa nulis ulang
            ✅ Modularity    : Memecah program besar jadi bagian kecil yang fokus
            ✅ Abstraksi     : Cukup tahu cara pakai, tidak perlu tahu cara kerjanya
            ✅ Readability   : Kode lebih bersih dan mudah dibaca
            ✅ Maintainability: Cukup ubah di 1 tempat, berlaku ke seluruh pemakai

        🏗️  ANATOMI FUNCTION
            ─────────────────────────────────────────────────────
                [A]  [B]            [C]
                int  hitungTambah  (int a, int b) {

                [D] int hasil = a + b;   // Body / Isi

                [E] return hasil;        // Return Statement
                }
            ─────────────────────────────────────────────────────
            [A] Return Type     : Tipe data nilai yang dikembalikan (int, double, string, void, dll)
            [B] Nama Function   : Menggunakan camelCase
            [C] Parameter       : Bahan baku dari pemanggil, boleh kosong ()
            [D] Body            : Seluruh kode yang dijalankan
            [E] Return          : Nilai yang dikembalikan ke pemanggil

        📌 JENIS FUNCTION BERDASARKAN RETURN
            - Fruitful Function : Menghasilkan nilai → ada return
            - Void Function     : Tidak menghasilkan nilai → tidak ada return

        📌 JENIS PARAMETER
            - Pass by Value     : Mengirim salinan, variabel asal tidak berubah (default)
            - Pass by Reference : Mengirim alamat, variabel asal ikut berubah
            - Default Parameter : Nilai otomatis jika tidak dikirim, harus di PALING KANAN

        ⚠️  ATURAN PENTING
            - TIDAK BISA nested function (function di dalam function)
            - Function harus dideklarasikan SEBELUM dipanggil
            - Gunakan Function Prototype agar definisi bisa di bawah main()
            - Hindari global variable, gunakan parameter & return value
    */

    /* Modul T.1 — DASAR FUNCTION (FRUITFUL & VOID)
        📚 DASAR FUNCTION

        1. Fruitful Function (Function Bernilai)
            - Menghasilkan nilai yang dikembalikan ke pemanggil
            - Return type BUKAN void
            - Wajib ada statement return
            - Nilai return bisa disimpan ke variabel atau langsung dipakai

            Contoh:
                int kuadrat(int x) {
                    return x * x;       // mengembalikan hasil
                }

                int hasil = kuadrat(5); // hasil = 25

        2. Void Function (Function Tanpa Nilai)
            - Tidak mengembalikan nilai apapun
            - Return type = void
            - Biasanya untuk mencetak output, mengubah state, dsb
            - Boleh ada return; (tanpa nilai) untuk keluar lebih awal

            Contoh:
                void sapa(string nama) {
                    cout << "Halo, " << nama << "!" << endl;
                    // tidak ada return
                }

        3. Cara Memanggil
            Fruitful : int x = tambah(3, 4);     // tampung hasilnya
                    cout << tambah(3, 4);      // langsung pakai
            Void     : cetakGaris();              // langsung panggil, tidak ada nilai kembali

        4. Naming Convention
            ✅ camelCase          : hitungTotal, cetakHeader, ambilNilai
            ✅ Deskriptif         : hitungRataRata(), bukan hitung()
            ❌ Jangan pakai angka di awal : 2hitung()
            ❌ Jangan terlalu singkat     : h(), prss()
    */

    /* Modul T.2 — DEFAULT PARAMETER
        📚 DEFAULT PARAMETER

        1. Apa itu Default Parameter?
            Nilai otomatis yang digunakan jika pemanggil TIDAK mengirim argumen
            untuk parameter tersebut.

        2. Aturan WAJIB
            ❗ Default parameter HARUS diletakkan di PALING KANAN
            ❗ Tidak boleh ada non-default setelah default parameter

            ✅ BENAR  : void fungsi(int a, int b = 10, string c = "ok")
            ❌ SALAH  : void fungsi(int a = 5, int b)          ← compile error!
            ❌ SALAH  : void fungsi(int a = 5, int b, int c = 1)← compile error!

        3. Cara Kerja
            void cetak(string nama, int usia = 17, string kota = "Jakarta") { ... }

            cetak("Budi");              → nama="Budi",  usia=17,  kota="Jakarta"
            cetak("Budi", 20);          → nama="Budi",  usia=20,  kota="Jakarta"
            cetak("Budi", 20, "Bogor"); → nama="Budi",  usia=20,  kota="Bogor"

        4. Kegunaan
            ✅ Membuat function lebih fleksibel
            ✅ Mengurangi overloading function yang tidak perlu
            ✅ Nilai "umum" tidak perlu dikirim terus-terusan

        5. Catatan
            Default parameter ditentukan di DEKLARASI, bukan di DEFINISI
            (penting kalau pakai function prototype)
    */

    /* Modul T.3 — FUNCTION OVERLOADING

        📚 FUNCTION OVERLOADING

        1. Apa itu Overloading?
            Mendefinisikan beberapa function dengan NAMA SAMA tapi
            PARAMETER BERBEDA (tipe data atau jumlah parameter).

            Compiler akan otomatis memilih function yang tepat
            berdasarkan argumen yang dikirim saat pemanggilan.

        2. Yang BOLEH Berbeda
            ✅ Tipe data parameter   : cetak(int) vs cetak(string)
            ✅ Jumlah parameter      : tambah(int,int) vs tambah(int,int,int)
            ✅ Urutan tipe parameter : fungsi(int,double) vs fungsi(double,int)

        3. Yang TIDAK BISA membedakan overload
            ❌ Return type saja      : int f(int) vs double f(int) → COMPILE ERROR
            ❌ Nama parameter saja   : f(int a) vs f(int b)        → SAMA SAJA

        4. Keuntungan
            ✅ Nama function intuitif dan konsisten
            ✅ Tidak perlu nama berbeda: tambahInt(), tambahDouble(), tambahTiga()
            ✅ Lebih mudah diingat dan dipakai

        5. Contoh Nyata di C++ Standard Library
            - cout << (bisa terima int, double, string, dll) → overloading operator
            - abs(int), abs(float), abs(double) → function overloading
    */

    /* Modul T.4 — INLINE FUNCTION
        📚 INLINE FUNCTION

        1. Apa itu Inline Function?
            Function yang kodenya "di-copy" langsung ke tempat pemanggilnya
            oleh compiler, TANPA mekanisme pemanggilan function normal.

        2. Bagaimana cara kerjanya?

            Cara Normal (tanpa inline):
                ┌─── main ───┐         ┌─── kuadrat ───┐
                │ ...         │ ──jump─▶│ int h = x*x;  │
                │ kuadrat(5); │ ◀─ret── │ return h;     │
                │ ...         │         └───────────────┘
                └────────────┘

            Cara Inline:
                ┌─── main (setelah compile) ─────────────────┐
                │ ...                                          │
                │ int h = 5 * 5;   ← kode kuadrat di-copy sini│
                │ ...                                          │
                └─────────────────────────────────────────────┘

        3. Kapan Pakai Inline?
            ✅ Function SANGAT PENDEK (1-3 baris)
            ✅ Dipanggil sangat sering (hot path)
            ✅ Getter/Setter sederhana
            ✅ Operasi matematika dasar

            ❌ Function panjang & kompleks → boros memory (code bloat)
            ❌ Recursive function → tidak bisa di-inline
            ❌ Mengandung loop/banyak percabangan

        4. Catatan Penting
            - Kata kunci 'inline' adalah REQUEST ke compiler, bukan perintah
            - Compiler bisa MENGABAIKAN inline jika dianggap tidak efisien
            - Compiler modern (O2/O3) juga bisa inline function biasa otomatis
            - Biasanya dipakai untuk getter/setter di class (nanti di OOP)
    */

    /* Modul T.5 — PASS BY VALUE vs PASS BY REFERENCE
        📚 MATERI T.5 — PASS BY VALUE vs PASS BY REFERENCE

        1. Pass by VALUE (default C++)
            - Yang dikirim: SALINAN/COPY dari nilai variabel
            - Variabel asli di pemanggil TIDAK BERUBAH
            - Aman: tidak ada side-effect ke luar function
            - Cocok untuk: data kecil, kalkulasi murni, data yang tidak boleh diubah

            Contoh:
                void ganda(int x) { x = x * 2; }

                int a = 5;
                ganda(a);
                // a tetap 5! (yang diganda adalah salinan a)

        2. Pass by REFERENCE (&)
            - Yang dikirim: ALAMAT MEMORY variabel aslinya
            - Perubahan di dalam function IKUT MENGUBAH variabel asli
            - Pakai simbol & setelah tipe data parameter
            - Cocok untuk: swap, multiple return, array/struct besar (hemat copy)

            Contoh:
                void ganda(int &x) { x = x * 2; }

                int a = 5;
                ganda(a);
                // a sekarang = 10! (yang diganda adalah a asli)

        3. Perbandingan
            ─────────────────────────────────────────────────────────
            Aspek              Pass by Value      Pass by Reference
            ─────────────────────────────────────────────────────────
            Yang dikirim       Salinan nilai      Alamat memori
            Ubah variabel asal ❌ Tidak           ✅ Ya
            Keamanan           ✅ Lebih aman      ⚠️  Perlu hati-hati
            Performa           Lebih lambat*      Lebih cepat*
            Simbol             Biasa              & setelah tipe
            ─────────────────────────────────────────────────────────
            *Signifikan untuk data besar seperti array, struct, string

        4. Const Reference
            - Kombinasi: Kirim referensi (cepat) tapi TIDAK BOLEH diubah (aman)
            - Syntax: const int &x
            - Best practice untuk function yang menerima data besar (string, struct)

            void tampilkan(const string &nama) {
                // nama tidak bisa diubah di sini → aman
                cout << nama;
            }
    */

    /* Modul T.6 — MULTIPLE RETURN via REFERENCE
        📚 MULTIPLE RETURN VIA REFERENCE

        1. Masalah: C++ Hanya Bisa Return 1 Nilai
            Function di C++ hanya memiliki SATU slot return.
            Tapi sering kali kita butuh menghasilkan LEBIH dari 1 nilai.

        2. Solusi: Gunakan Parameter Reference
            - Kirim parameter kosong sebagai "wadah output"
            - Function mengisi variabel tersebut melalui reference
            - Setelah function selesai, variabel tersebut sudah terisi

            Contoh:
                void hitungBangun(double r, double &luas, double &keliling) {
                    luas     = 3.14 * r * r;
                    keliling = 2 * 3.14 * r;
                }

                double l, k;
                hitungBangun(7.0, l, k);
                // l dan k sudah terisi!

        3. Alternatif Lain (untuk referensi ke depan)
            a. Return struct/pair  → dibahas di Bab Struct
            b. Return array/vector → dibahas di Bab Array/STL

        4. Konvensi
            Biasanya parameter output (reference) diletakkan SETELAH
            parameter input, dan diberi nama yang jelas:
                void hitung(int input, int &outHasil, int &outSisa)
    */

    /* Modul T.7 — RECURSIVE FUNCTION

        📚 RECURSIVE FUNCTION

        1. Apa itu Recursive Function?
            Function yang MEMANGGIL DIRINYA SENDIRI dari dalam tubuhnya.

        2. Struktur WAJIB Recursive
            Setiap recursive function HARUS punya 2 bagian:

            a. BASE CASE  → kondisi berhenti. TANPA INI = INFINITE LOOP = CRASH!
            b. RECURSIVE CASE → pemanggilan diri sendiri dengan input yang LEBIH KECIL

            int faktorial(int n) {
                if (n <= 1) return 1;       ← BASE CASE
                return n * faktorial(n-1);  ← RECURSIVE CASE
            }

        3. Cara Kerja (Stack)
            faktorial(4):
                4 * faktorial(3)
                    3 * faktorial(2)
                        2 * faktorial(1)
                            return 1        ← base case tercapai
                        return 2 * 1 = 2
                    return 3 * 2 = 6
                return 4 * 6 = 24

        4. Rekursi vs Iterasi
            ─────────────────────────────────────────────────────────
            Aspek          Rekursi              Iterasi (loop)
            ─────────────────────────────────────────────────────────
            Keterbacaan    ✅ Lebih elegan      Lebih verbose
            Performa       ⚠️  Lebih lambat     ✅ Lebih cepat
            Memori         ⚠️  Stack bisa penuh ✅ Lebih hemat
            Cocok untuk    Tree, Graph, Divide  Operasi berulang
                        and Conquer          sederhana
            ─────────────────────────────────────────────────────────

        5. Bahaya
            ❗ Stack Overflow: Rekursi terlalu dalam (ribuan level) → crash
            ❗ Selalu pastikan BASE CASE bisa tercapai!
            ❗ Hindari rekursi untuk n yang sangat besar
    */

    /* Modul T.8 — FUNCTION SCOPE (LOCAL vs GLOBAL)

        📚 FUNCTION SCOPE

        1. Apa itu Scope?
            Scope = Area berlakunya sebuah variabel.
            Di mana variabel bisa diakses dan digunakan.

        2. Local Variable
            - Dideklarasikan di DALAM function atau blok {}
            - Hanya bisa diakses di dalam function/blok tersebut
            - Dibuat saat function dipanggil, DIHAPUS saat function selesai
            - Parameter function = local variable

        3. Global Variable
            - Dideklarasikan di LUAR semua function (biasanya di atas main)
            - Bisa diakses dari SEMUA function
            - Hidup sepanjang program berjalan
            - ⚠️ HINDARI penggunaan berlebihan!

        4. Mengapa Hindari Global Variable?
            ❌ Sulit di-debug: siapa yang mengubah nilainya?
            ❌ Sulit di-test: function bergantung pada "state" luar
            ❌ Sulit dipahami: banyak bagian yang bisa mempengaruhi
            ❌ Tidak aman: data bisa diubah dari mana saja

        5. Variable Shadowing
            Jika ada local variable dengan nama SAMA dengan global,
            local variable akan "menutupi" (shadow) global variable.

            int x = 100;    // global

            void fungsi() {
                int x = 5;  // local — "shadow" global x
                cout << x;  // mencetak 5, bukan 100!
            }

        6. Best Practice
            ✅ Gunakan local variable sebisa mungkin
            ✅ Kirim data via parameter
            ✅ Kembalikan data via return value
            ✅ Global hanya untuk konstanta (const/constexpr)
    */

    /* Modul T.9 — FUNCTION DECLARATION / PROTOTYPE
        
        📚 FUNCTION DECLARATION (PROTOTYPE)

        1. Masalah: Urutan Definisi
            Secara default, C++ harus tahu fungsi SEBELUM dipanggil.
            Jika definisi fungsi di BAWAH pemanggilnya → COMPILE ERROR!

            void panggilB() {
                fungsiB(); ← ERROR! fungsiB belum dikenal di titik ini
            }
            void fungsiB() { ... }

        2. Solusi: Function Prototype (Deklarasi)
            Deklarasikan "bentuk" function di ATAS (sebelum main atau pemanggil),
            tapi boleh definisikan implementasinya di BAWAH.

            // DEKLARASI (prototype) — di atas
            void fungsiB();

            void panggilB() {
                fungsiB(); ← OK! Compiler sudah tahu bentuknya
            }

            // DEFINISI — boleh di bawah
            void fungsiB() { cout << "B!"; }

        3. Syntax Prototype
            return_type namaFungsi(tipe_param1, tipe_param2);
                                    ↑ Nama parameter BOLEH diisi atau dikosongkan
            Contoh:
                int tambah(int, int);          ← tanpa nama param (OK)
                int tambah(int a, int b);      ← dengan nama param (lebih mudah dibaca)

        4. Mengapa Prototype Penting?
            ✅ Membolehkan definisi function di bawah main
            ✅ Membolehkan dua function saling memanggil (mutual recursion)
            ✅ Memisahkan deklarasi (header) dari implementasi (.cpp)
            ✅ Standar dalam proyek besar multi-file

        5. Header File
            Pada proyek besar, prototype ditaruh di file .h (header):
                // math_utils.h
                int tambah(int a, int b);
                double rataRata(double arr[], int n);

                // math_utils.cpp
                #include "math_utils.h"
                int tambah(int a, int b) { return a + b; }

        6. Mutual Recursion (butuh prototype)
            Function A memanggil B, dan B memanggil A.
            Ini HANYA bisa dilakukan jika ada prototype salah satunya.

            bool isGanjil(int n);   ← prototype
            bool isGenap(int n) {
                if (n == 0) return true;
                return isGanjil(n - 1);  ← bisa panggil isGanjil karena ada prototype
            }
            bool isGanjil(int n) {
                if (n == 0) return false;
                return isGenap(n - 1);
            }
    */

// U. Array
    /* Modul 8.1-8.2 - Fundamental & Basic
            1. Apa itu Array?
                Array adalah kumpulan data dengan tipe data yang sama yang di simpan berurutan dalam memory 
                menggunakan index, dapat diisi, diubah, dipanggil, dan di operasikan lainnya
            
            2. Fungsi array?
                Mennyimpan data dengan tipe data yang sama secara berurutan
                sehingga TIDAK BOROS VARIABEL, cukup tuliskan 1 dan di isi dengan berbagai macam nilai dengan tipe yang sama

            3. Karakteristik Array?
                - Contiguous    - bersebelahan di memory (BERURUTAN)
                - Fixed size    - ukuran tetap (ga bisa resize)
                - Same type     - semua elemen tipe data sama
                - Random access - akses langsung dengan index
                - Start from 0  - Index array itu dimulai dari 0

            4. Bentuk Deklarasi Array?
                tipe_data nama_array[ukurannya];

                contoh:
                    int dataNilai[10];      ---> Artinya dataNilai dapat menyimpan 10 data dengan tipe data integer

            5. Cara Initialization Array? 
                a. List Initialization (Complete)
                    int nilai[5] = {1,2,3,4,5};     ---> Langsung di isi di tempat

                b. Partial Initialization
                    int nilai[5] = {80,90};         ---> Maka index 2-4 otomatis diisi/menjadi 0

                c. Zero Initialization 
                    int nilai[5] = {0}              ---> Maka isinya akan 0 semua dari index 0-4

                d. Omit Size (auto-detect)
                    int nilai[] = {10,20,30,40,50}; ---> Ukuran Otimatis mengikuti isinya yaitu 5

                e. No Initialization (DANGER!)
                    int nilai[5];                   ---> Akan error

                f. Uniform Initialization (C++11)
                    int nilai[5] {85, 90, 78, 92, 88};  ---> Tanpa (=) Lebih modern, lebih aman (prevent narrowing)

            6. Aturan Indexing?
                Start from 0  - Index array itu dimulai dari 0 - BUKAN DARI 1

                KESALAHAN:
                    int nilai[5] = {85, 90, 78, 92, 88};

                    cout << nilai[5];   --->  OUT OF BOUNDS!
                                        ---> Index valid: 0-4
                                        ---> nilai[5] tidak ada!
                                        ---> Undefined behavior! Bahaya!

            7. Array Size?
                a. Menggunakan sizeof()
                    int nilai[5] = {85, 90, 78, 92, 88};

                    int sizeByte - sizeof(nilai);                     ---> 20 Bytes (5 x 4 Bytes)
                    int length - sizeof(nilai) / sizeof(nilai[0]);    ---> 5 Bytes

                    Keterangan :
                        sizeof(nilai) = total bytes array
                        sizeof(nilai[0]) = bytes per element

                b. Menggunakan CONST
                    const int SIZE = 5;
                    int nilai[SIZE] = {85, 90, 78, 92, 88};

                    Keternagan:
                        Tanpa Const pun bisa, cuma TIDAK STANDARD

            8. Akses dan Modifikasi isi Array?
                a. Read(Access)
                    int nilai[3] = {85, 90, 78};

                    int pertama = nilai[0];     ---> Read nilai[0] -> 85
                    cout << nilai[1];           ---> Read nilai[1] -> 90

                b. Write(Modify)
                    int nilai[3] = {85, 90, 78};

                    nilai[0] = 100;             ---> Ubah nilai[0] dari 85 jadi 100
                    nilai[1] = nilai[1] + 5;    ---> Tambah 5, dari 90 jadi 95
                    nilai[2]++;                 ---> Increment, dari 78 jadi 79

                                                ---> Hasil akhir: {100, 95, 79}

            9. Traversing Array (Looping)
                a. For Loop (Index-based)
                    int nilai[5] = {85, 90, 78, 92, 88};

                    // Print semua elemen
                    for (int i = 0; i < 5; i++) {
                        cout << "nilai[" << i << "] = " << nilai[i] << endl;
                    }
                B. Range-based For Loop (C++11) - Lebih simple!
                    cppint nilai[5] = {85, 90, 78, 92, 88};

                    // Print semua elemen (tidak perlu index!)
                    for (int n : nilai) {
                        cout << n << endl;
                    }
                C. While Loop (Jarang, tapi bisa)
                    cppint nilai[5] = {85, 90, 78, 92, 88};

                    int i = 0;
                    while (i < 5) {
                        cout << nilai[i] << endl;
                        i++;
                    }

            10. Basic Operations
                - Mencari Nilai Total
                - Mencari Rata2
                - Mencari Maximum
                - Mencari Minimum
                - Menghitung elemen dengan kondisi (misal berapa nilai yang lolos)
                - Searching
    */

        void caraInisialisasi(){
                //List Initialization (Complete)
                    int array1[5] = {1,2,3,4,5};     
                    
                //Partial Initialization
                    int array2[5] = {80,90};         

                //Zero Initialization 
                    int array3[5] = {0};        
                
                //Omit Size (auto-detect)
                    int array4[] = {10,20,30,40,50}; 
                
                //No Initialization (DANGER!)
                    int array5[5];              
                
                //Uniform Initialization (C++11)
                    int array6[5] {85, 90, 78, 92, 88};  
        }

        void sizeArray(){
            int nilai[5] = {1, 2, 3, 4, 5};

            // 1. Menghitung total memori yang dipakai array (5 elemen * 4 byte)
            int totalByte = sizeof(nilai);              // Hasil: 20
            
            // 2. Menghitung ukuran memori per satu elemen saja
            int bytePerElemen = sizeof(nilai[0]);      // Hasil: 4 (karena int = 4 byte)
            
            // 3. Menghitung JUMLAH ELEMEN (Panjang Array)
            int jumlahElemen = sizeof(nilai) / sizeof(nilai[0]); // Hasil: 5 (20 / 4)

            cout << "\n==========================================" << endl;
            cout << "|         ARRAY - MODUL 8.1-8.2          |" << endl;
            cout << "==========================================" << endl;
            
            cout << "\n==========[Detail Memory]==========" << endl;
            cout << "Total Byte Array (5 int) : " << totalByte << " Byte" << endl;
            cout << "Ukuran 1 Elemen (int)    : " << bytePerElemen << " Byte" << endl;
            cout << "Jumlah Elemen (Panjang)  : " << jumlahElemen << " Elemen" << endl;

            cout << "\nRumus Jumlah Elemen = sizeof(array) / sizeof(array[0])" << endl;
        }

        void accessModifyArray() {
            int nilai[5] = {1, 2, 3, 4, 5};

            cout << "\n========== [ ACCESS & MODIFY ] ==========" << endl;

            // --- READ / ACCESS ---
            cout << "[Step 1] Membaca Element (Read):" << endl;
            // Mengakses langsung menggunakan index (dimulai dari 0)
            cout << "  > Index 0: " << nilai[0] << endl;
            cout << "  > Index 1: " << nilai[1] << endl;
            cout << "  > Index 2: " << nilai[2] << endl;

            // --- WRITE / MODIFY ---
            cout << "\n[Step 2] Mengubah Element (Modify):" << endl;
            nilai[0] = 100; // Menimpa nilai lama
            nilai[1] = 200;
            nilai[2] = 300;

            cout << "  > Update Index 0: " << nilai[0] << " (Berubah!)" << endl;
            cout << "  > Update Index 1: " << nilai[1] << " (Berubah!)" << endl;
            cout << "  > Update Index 2: " << nilai[2] << " (Berubah!)" << endl;
        }

        void traversingArrayLoop() {
            int nilaiSiswa[10] = {90, 80, 85, 78, 77, 78, 90, 88, 85, 95};
            
            // Menghitung jumlah elemen secara otomatis
            int n = sizeof(nilaiSiswa) / sizeof(nilaiSiswa[0]);

            cout << "\n========== [ TRAVERSING ARRAY ] ==========" << endl;

            // 1. FOR LOOP (Index-based) - Standar & Fleksibel
            cout << "\n1. For Loop (Index-based):" << endl;
            for (int i = 0; i < n; i++) {
                cout << "   Data ke-" << (i + 1) << " [Index " << i << "]: " << nilaiSiswa[i] << endl;
            }

            // 2. RANGE-BASED FOR LOOP (C++11) - Modern & Clean
            cout << "\n2. Range-Based Loop (Modern C++):" << endl;
            cout << "   Values: ";
            for (int nilai : nilaiSiswa) {
                cout << "[" << nilai << "] ";
            }
            cout << endl;

            // 3. WHILE LOOP - Manual control
            cout << "\n3. While Loop:" << endl;
            int j = 0;
            while (j < n) {
                cout << "   Siswa #" << (j + 1) << ": " << nilaiSiswa[j] << endl;
                j++;
            }
        }

        void demoArrayFundamentalBasic(){
            caraInisialisasi();
            sizeArray();
            accessModifyArray();
            traversingArrayLoop();
        }

    /* Modul 8.3 - Array Algorithm
        
        Apa itu algoritma array?
            algoritma array adlaah teknik untuk memanipulasi/memproses data dalam array

        ===================[ BAGIAN 1 - SEARCHING / MENCARI ] =====================
            1. Sequential Search (Linear Search)
                a. Sequential Search NON-SENTINEL 

                    - Proses:
                        Pengulangan dari elemen ke-1 sampai n
                        Pada setiap pengulangan, bandingkan data[i] dengan yang dicari
                        Jika sama -> data ditemukan
                        Jika sampai akhir tidak sama -> data tidak ada

                    - Pengecekan:
                        i < n               -> belum sampai akhir
                        arr[i] != target    -> belum ketemu
                    
                b. Sequential Search SENTINEL 
                    - Proses:
                        Simpan target di arr[n] (posisi sentinel)
                        Loop dari i=0, cek arr[i] != target
                        Jika ketemu:
                            Jika i < n -> data DITEMUKAN di posisi i
                            Jika i == n -> data TIDAK ADA (yang ketemu sentinel)
                    
                    - Kondisi Loop:
                        while (arr[i] != target)  // Hanya 1 kondisi!

            2. Binary Search
                    - KONSEP:
                        Jika arr[i] SUDAH LEBIH BESAR dari target,
                        maka TIDAK PERLU lanjut cek sisanya!
                        (karena data terurut, sisanya pasti lebih besar lagi)
                    
                    - Proses:
                        Loop dari awal
                        Jika arr[i] == target -> FOUND
                        Jika arr[i] > target -> STOP! (tidak akan ketemu)
                        Jika arr[i] < target -> lanjut
                    

            ========== BEST PRACTICES ==========
                KAPAN PAKAI SEARCHING APA?
            
            1. Data TIDAK TERURUT & KECIL (<100):
                -> Sequential Non-Sentinel
            
            2. Data TIDAK TERURUT & Butuh EFISIENSI:
                -> Sequential Sentinel (fewer checks)
            
            3. Data TERURUT & KECIL-MEDIUM:
                -> Sequential Sorted (early termination)
            
            4. Data TERURUT & BESAR (>1000):
                -> Binary Search (FASTEST!)
            
            TIPS:
            Sentinel        : Siapkan array[n+1] untuk space ekstra
            Binary          : Pastikan data SORTED dulu
            Production      : Pakai std::find() atau std::binary_search()
            Always validate : check bounds, check sorted

        ===================[ BAGIAN 2 - SHORTING / MENGURUTKAN ] =====================
            Apa itu sorting?
            Sorting itu adalah teknik mengurutkan data, entah itu dari kecil ke besar atau sebaliknya
                - Kecil ke Besar ---> Ascending
                - Besar ke Kecil ---> Descending

            Fungsinya?
                - Agar Search lebih cepat karena data sudah terurut
                - Mudah dibaca dan dipahami
                - Mudah menemukan duplikat

            1. Bubble Short
                - Konsep
                    Membandingkan 2 elemen bersebelahan, jika salah urutan akan di swap
                    Elemen terbesar akan berada di akhir (belakang)
                    Nama Bubble short sendiri bisa di bayangkan seperti gelembung udara yang naik dari bawah air

                - Proses
                    Initial: [64, 34, 25, 12, 22]
                    
                    Pass 1: Compare & swap adjacent
                            [34, 25, 12, 22, 64]  ← 64 bubble up ke akhir
                    
                    Pass 2: [25, 12, 22, 34, 64]  ← 34 bubble up
                    
                    Pass 3: [12, 22, 25, 34, 64]  ← 25 in place
                    
                    Pass 4: [12, 22, 25, 34, 64]  ← sorted!

            2. Selection Short
                - Konsep
                    "SELECT" yang berarti pilih, yaitu dengan memilih elemen terkecil dari seluruh elemen array 
                    lalu dipindah ke paling depan, berulang sampai ke semua array terurutkan

                - Proses
                    Pass 1: Cari min dari semua elemen -> swap dengan posisi 0
                    Pass 2: Cari min dari sisa array -> swap dengan posisi 1
                    Pass 3: Cari min dari sisa array -> swap dengan posisi 2
                    ...
                    Sampai semua sorted

                - Visualisasi
                    Initial: [64, 25, 12, 22, 11]
                    
                    Pass 1: min=11 (index 4)
                            Swap 11 ↔ 64
                            [11, 25, 12, 22, 64]  ← 11 FIXED
                    
                    Pass 2: min=12 (index 2)
                            Swap 12 ↔ 25
                            [11, 12, 25, 22, 64]  ← 12 FIXED
                    
                    Pass 3: min=22 (index 3)
                            Swap 22 ↔ 25
                            [11, 12, 22, 25, 64]  ← 22 FIXED
                    
                    Pass 4: min=25 (already in place)
                            [11, 12, 22, 25, 64]  ← sorted!

            3. Insertion Short
                - Konsep
                    Sorting seperti sort KARTU REMI di tangan.
                    Ambil elemen satu per satu, SISIPKAN di posisi yang benar.

                - Proses
                    Visualisasi:
                    Initial: [12, 11, 13, 5, 6]
                    
                    Iter 1: key=11
                            Insert 11 ke sorted part [12]
                            [11, 12] | 13, 5, 6  ← 11 inserted
                    
                    Iter 2: key=13
                            13 sudah di posisi benar
                            [11, 12, 13] | 5, 6
                    
                    Iter 3: key=5
                            Geser 13, 12, 11 ke kanan
                            Insert 5 di awal
                            [5, 11, 12, 13] | 6
                    
                    Iter 4: key=6
                            Geser 13, 12, 11 ke kanan
                            Insert 6 setelah 5
                            [5, 6, 11, 12, 13]  ← sorted!

            KAPAN PAKAI YANG MANA?
            
                Small array (<50)   :   Any is OK
                Nearly sorted       :   INSERTION ⭐⭐
                Minimize swaps      :   SELECTION
                Learning/Teaching   :   BUBBLE (easiest)
                Large array (>1000) :   DON'T USE THESE! 
                                        Use std::sort() instead
            
            PRODUCTION CODE WARNING! ⚠️
            
                Ketiga sorting ini (Bubble/Selection/Insertion) adalah
                untuk LEARNING PURPOSE!
                
                Untuk PRODUCTION code dengan data besar (>1000):
                    ❌ JANGAN pakai Bubble/Selection/Insertion
                    ✅ Pakai: Quick Sort, Merge Sort, Heap Sort
                    ✅ Atau: std::sort() dari STL (nanti di modul STL)

        ===================[ BAGIAN 3 - MANIPULATION ] =====================
            1. Reverse Array (Balik Urutan)
                - Konsep
                    Balik urutan array dari belakang ke depan.

                - Proses
                    Cara Kerja:
                    - Pointer left di awal (index 0)
                    - Pointer right di akhir (index n-1)
                    - Swap arr[left] dengan arr[right]
                    - Geser left ke kanan, right ke kiri
                    - Ulangi sampai left >= right

            2. Rotate Array
                a. LEFT ROTATE:
                    Geser semua elemen ke kiri.
                    Elemen pertama jadi terakhir.
                    
                    Visualisasi:
                        [1, 2, 3, 4, 5]  -> rotate left ->  [2, 3, 4, 5, 1]
                
                b. RIGHT ROTATE:
                    Geser semua elemen ke kanan.
                    Elemen terakhir jadi pertama.
                    
                    Visualisasi:
                        [1, 2, 3, 4, 5]  -> rotate right ->  [5, 1, 2, 3, 4]

            3. Remove Duplicate
                - Konsep
                    Hilangkan elemen yang duplikat, keep yang unik.

                - Proeses
                    Cara Kerja:
                    - uniqueIndex = 0 (posisi elemen unik terakhir)
                    - Loop dari i=1 sampai n-1
                    - Jika arr[i] != arr[uniqueIndex]:
                        . Berarti arr[i] adalah elemen baru (unique)
                        . uniqueIndex++
                        . arr[uniqueIndex] = arr[i]
                    - Return uniqueIndex + 1 (new size)

        ===================[ BAGIAN 4 - FREQUENCY ] =====================
            1. Frequency Count (Hitung Kemunculan)
            
                - Konsep
                    Hitung berapa kali setiap elemen muncul dalam array.
                
                    METHOD 1: Nested Loop (General, untuk semua data)
                        Kode:
                            void countFrequency(int arr[], int n) {
                                bool visited[n] = {false};
                                
                                for (int i = 0; i < n; i++) {
                                    if (visited[i]) continue;
                                    
                                    int count = 1;
                                    for (int j = i + 1; j < n; j++) {
                                        if (arr[i] == arr[j]) {
                                            count++;
                                            visited[j] = true;
                                        }
                                    }
                                    
                                    cout << arr[i] << " appears " << count << " times" << endl;
                                }
                            }
                        
                        Keterangan:
                            - Time: O(n²)
                            - Space: O(n) untuk array visited
                            - Bekerja untuk semua jenis data
                
                    METHOD 2: Frequency Array (untuk angka kecil)
                        Kode:
                            void countFrequencyArray(int arr[], int n, int maxValue) {
                                int freq[maxValue + 1] = {0};
                                
                                // Count occurrences
                                for (int i = 0; i < n; i++) {
                                    freq[arr[i]]++;
                                }
                                
                                // Print non-zero frequencies
                                for (int i = 0; i <= maxValue; i++) {
                                    if (freq[i] > 0) {
                                        cout << i << " appears " << freq[i] << " times" << endl;
                                    }
                                }
                            }
                    
                    Keterangan:
                        - Time: O(n + maxValue)
                        - Space: O(maxValue)
                        - Hanya untuk angka 0 sampai maxValue
                        - Lebih cepat dari nested loop

            2. Find Duplicates (Cari Yang Duplikat)
            
                - KONSEP:
                    Cari elemen mana saja yang muncul lebih dari sekali.
                
                    Kode:
                        void findDuplicates(int arr[], int n) {
                            bool found = false;
                            
                            for (int i = 0; i < n; i++) {
                                for (int j = i + 1; j < n; j++) {
                                    if (arr[i] == arr[j]) {
                                        cout << arr[i] << " is duplicate" << endl;
                                        found = true;
                                        break;
                                    }
                                }
                            }
                            
                            if (!found) {
                                cout << "No duplicates found" << endl;
                            }
                        }
    */

        void cetakArray(int arr[], int n){
            cout << "[ ";
            for(int i = 0; i < n; i++){
                cout << arr[i];
                if(i < n-1) cout << ", ";
            }
            cout << " ]" << endl;
        }

        void searchingArray(){

            cout << "\n==========================================" << endl;
            cout << "|            ARRAY - MODUL 8.3           |" << endl;
            cout << "==========================================" << endl;

            cout << "\n=========[Searching Array]=========" << endl;
            
            int nilaiDicari = 85;
            const int n = 10;
            int nilaiSiswa[n] = {
                90,80,85,78,77,78,90,88,85,95
            };
            cout << "\nData Array Nilai Siswa : " << endl;
            cetakArray(nilaiSiswa, n);
            cout << "Data Array yang Dicari : " << nilaiDicari << endl;
            
            cout << "\n1. Sequential Search Non-Sentinel" << endl;
            {
                bool ketemu = false;
                for(int i = 0; i < n; i++){
                    if(nilaiSiswa[i] == nilaiDicari){
                        cout << "   Ketemu di index " << i << endl;
                        ketemu = true;
                    }
                }
                if(!ketemu) cout << "   Tidak ditemukan" << endl;
            }

            cout << "\n2. Sequential Search Sentinel" << endl;
            {
                int nilaiSiswaSentinel[11];
                for(int i = 0; i < n; i++) nilaiSiswaSentinel[i] = nilaiSiswa[i];
                nilaiSiswaSentinel[n] = nilaiDicari;   // pasang sentinel di index n

                int i = 0;
                while(nilaiSiswaSentinel[i] != nilaiDicari) i++;

                if(i < n)
                    cout << "   Ketemu di index " << i << endl;
                else
                    cout << "   Tidak ditemukan (yang ketemu adalah sentinel)" << endl;
            }

            
            cout << "\n3. Binary Search (data harus sorted)" << endl;
            {
                int nilaiSiswaSorted[10] = {77, 78, 78, 80, 85, 85, 88, 90, 90, 95};
                cout << "   Data sorted : "; cetakArray(nilaiSiswaSorted, n);

                int left = 0, right = n - 1, hasilIdx = -1;
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(nilaiSiswaSorted[mid] == nilaiDicari){
                        hasilIdx = mid;
                        break;
                    } else if(nilaiSiswaSorted[mid] < nilaiDicari){
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if(hasilIdx != -1)
                    cout << "   Ketemu di index " << hasilIdx << endl;
                else
                    cout << "   Tidak ditemukan" << endl;
            }
        }

        void sortingArray(){
            cout << "\n=========[Sorting Array]=========" << endl;

            const int n = 10;
            int nilaiSiswa[n] = {
                90,80,85,78,77,78,90,88,85,95
            };
            cout << "\nData Array Nilai Siswa : " << endl;
            cetakArray(nilaiSiswa, n);

            cout << "\n0. Standard Sort Library" << endl;
            {
                sort(nilaiSiswa, nilaiSiswa + n); 
                cetakArray(nilaiSiswa, n);
            }  

            cout << "\n1. Bubble Short" << endl;
            {
                for (int i = 0; i < n; i++){
                    for (int j = 1; j < n; j++){
                        if (nilaiSiswa[j-1] > nilaiSiswa[j]){
                            int temp = nilaiSiswa[j-1];
                            nilaiSiswa[j-1] = nilaiSiswa[j];
                            nilaiSiswa[j] = temp;
                        }
                    }
                }
                cout << "Hasil Bubble Sort : " << endl;
                cetakArray(nilaiSiswa, n);
            }

            cout << "\n2. Selection Short (Ascending)" << endl;
            {
                for (int i = 0; i < n - 1; i++){            // i = "Slot" yang mau diisi (si pendek nomor 1, 2, dst)
                    
                    int minIndex = i;                       // Anggap posisi 'i' adalah yang terkecil sementara

                    for (int j = i + 1; j < n; j++){        // j = "Detektif" yang nyari di sisa barisan
                        if(nilaiSiswa[j] < nilaiSiswa[minIndex]){
                            minIndex = j;                   // "Eh, ketemu yang lebih kecil! Catat index-nya!"
                        }
                    }
                    
                    // Eksekusi Tukar Nasib (Hanya dilakukan SEKALI setelah detektif selesai tugasnya)
                    int temp = nilaiSiswa[i];
                    nilaiSiswa[i] = nilaiSiswa[minIndex];
                    nilaiSiswa[minIndex] = temp;
                }

                cout << "Hasil Selection Sort" << endl;
                cetakArray(nilaiSiswa, n);
            }

            cout << "\n3. Insertion Sort" << endl;
            {
                for (int i = 1; i < n; i++) { 
                    int key = nilaiSiswa[i]; // 1. "Eh, ambil kartu ini dulu (simpan di kantong)"
                    int j = i - 1;           // 2. "Siap-siap bandingin sama kartu di sebelah kirinya"
    
                    // 3. SELAMA kartu di kiri lebih gede dari kartu di kantong...
                    while (j >= 0 && nilaiSiswa[j] > key) {
                        nilaiSiswa[j + 1] = nilaiSiswa[j]; // 4. "Geser kartu gede itu ke kanan (kasih ruang)"
                        j--;                               // 5. "Cek lagi kartu lebih kiri lagi, ada yang gede lagi gak?"
                    }
    
                    nilaiSiswa[j + 1] = key; // 6. "Nah, lubangnya ketemu! Masukkan kartu dari kantong ke sini"
    
                    cout << "Hasil Insertion Sort" << endl;
                    cetakArray(nilaiSiswa, n);
                }
            }
        }

        void manipulationArray(){
            int asal[5] = {30, 10, 50, 20, 40};
            int tujuan[5];

            // 1. COPY: Salin 'asal' ke 'tujuan'
            copy(asal, asal + 5, tujuan);

            // 2. SORT: Urutkan array 'asal' (10, 20, 30, 40, 50)
            sort(asal, asal + 5);

            // 3. REVERSE: Balik urutannya (50, 40, 30, 20, 10)
            reverse(asal, asal + 5);

            // 4. REPLACE: Ganti angka 30 jadi 99
            replace(asal, asal + 5, 30, 99);

            // 5. FILL: Setel semua isi 'tujuan' jadi 0
            fill(tujuan, tujuan + 5, 0);

            cout << "\n=========[Manipulasi Array]=========" << endl;

            const int n = 5;
            int arr[n] = {1, 2, 3, 4, 5};
            cout << "\nData Awal : ";
            cetakArray(arr, n);

            // ===== 1. REVERSE ARRAY =====
            cout << "\n1. Reverse Array (Balik Urutan)" << endl;
            {
                int data[5] = {1, 2, 3, 4, 5};
                cout << "   Sebelum : "; cetakArray(data, 5);

                // Cara kerja: tukar elemen paling kiri & kanan, gerak ke tengah
                //   left                             right
                //    v                               v
                //   [1]   [2]   [3]   [4]   [5]
                //
                // Step 1: swap(data[0], data[4]) -> [5, 2, 3, 4, 1]   left=1, right=3
                // Step 2: swap(data[1], data[3]) -> [5, 4, 3, 2, 1]   left=2, right=2
                // Step 3: left >= right -> BERHENTI

                int left = 0;
                int right = 4;

                while(left < right){
                    // Tukar elemen kiri & kanan
                    int temp    = data[left];
                    data[left]  = data[right];
                    data[right] = temp;

                    left++;     // Geser kiri ke dalam
                    right--;    // Geser kanan ke dalam
                }

                cout << "   Sesudah : "; cetakArray(data, 5);
            }

            // ===== 2. ROTATE LEFT =====
            cout << "\n2. Rotate Left (Elemen Pertama Pindah ke Akhir)" << endl;
            {
                int data[5] = {1, 2, 3, 4, 5};
                cout << "   Sebelum : "; cetakArray(data, 5);

                // Cara kerja:
                //   Simpan data[0] dulu -> temp = 1
                //   Geser semua elemen ke KIRI satu posisi
                //   Taruh temp di posisi terakhir
                //
                //   [1]  [2]  [3]  [4]  [5]
                //    ↓
                //   temp = 1
                //   [2]  [3]  [4]  [5]  [_]   ← geser kiri
                //   [2]  [3]  [4]  [5]  [1]   ← taruh temp di akhir

                int temp = data[0];                     // Simpan elemen pertama
                for(int i = 0; i < 4; i++){
                    data[i] = data[i + 1];              // Geser semua ke kiri
                }
                data[4] = temp;                         // Taruh di posisi terakhir

                cout << "   Sesudah : "; cetakArray(data, 5);
            }

            // ===== 3. ROTATE RIGHT =====
            cout << "\n3. Rotate Right (Elemen Terakhir Pindah ke Depan)" << endl;
            {
                int data[5] = {1, 2, 3, 4, 5};
                cout << "   Sebelum : "; cetakArray(data, 5);

                // Cara kerja: kebalikan rotate left
                //   Simpan data[4] dulu -> temp = 5
                //   Geser semua elemen ke KANAN satu posisi
                //   Taruh temp di posisi pertama
                //
                //   [1]  [2]  [3]  [4]  [5]
                //                        ↓
                //                      temp = 5
                //   [_]  [1]  [2]  [3]  [4]   ← geser kanan
                //   [5]  [1]  [2]  [3]  [4]   ← taruh temp di awal

                int temp = data[4];                     // Simpan elemen terakhir
                for(int i = 4; i > 0; i--){
                    data[i] = data[i - 1];              // Geser semua ke kanan
                }
                data[0] = temp;                         // Taruh di posisi pertama

                cout << "   Sesudah : "; cetakArray(data, 5);
            }

            // ===== 4. REMOVE DUPLICATE (array SUDAH sorted) =====
            cout << "\n4. Remove Duplicate (array harus sorted dulu)" << endl;
            {
                int data[8] = {1, 1, 2, 3, 3, 4, 5, 5};
                int size = 8;
                cout << "   Sebelum : "; cetakArray(data, size);

                // Cara kerja:
                //   uniqueIndex = 0  (penunjuk posisi elemen unik terakhir)
                //   Loop dari i = 1:
                //     Kalau data[i] != data[uniqueIndex] -> elemen BARU, unik!
                //       uniqueIndex++
                //       data[uniqueIndex] = data[i]   ← pindahkan ke depan
                //     Kalau sama -> skip (duplikat, buang)
                //
                //   data = [1, 1, 2, 3, 3, 4, 5, 5]
                //          uniqueIdx=0
                //   i=1 : data[1]=1 == data[0]=1 -> skip
                //   i=2 : data[2]=2 != data[0]=1 -> uniqueIdx=1, data[1]=2
                //   i=3 : data[3]=3 != data[1]=2 -> uniqueIdx=2, data[2]=3
                //   i=4 : data[4]=3 == data[2]=3 -> skip
                //   i=5 : data[5]=4 != data[2]=3 -> uniqueIdx=3, data[3]=4
                //   ... dst
                //   Hasil : [1, 2, 3, 4, 5]  newSize = uniqueIdx+1 = 5

                int uniqueIdx = 0;
                for(int i = 1; i < size; i++){
                    if(data[i] != data[uniqueIdx]){     // Elemen baru ketemu
                        uniqueIdx++;
                        data[uniqueIdx] = data[i];      // Pindah ke posisi unik berikutnya
                    }
                    // Kalau sama -> tidak dilakukan apa-apa (otomatis terbuang)
                }
                int newSize = uniqueIdx + 1;            // Ukuran baru setelah duplikat dihapus

                cout << "   Sesudah : "; cetakArray(data, newSize);
                cout << "   Ukuran  : " << size << " -> " << newSize << endl;
            }
        }

        void demoArrayAlgorithm(){
            searchingArray();
            sortingArray();
            manipulationArray();
        }

    /* Modul 8.4 - Charcter Array

        1. Apa itu character Array?
                Adalah tempat untuk menyimpan kumpulan karakter (char)
                ini adalah cara lama (C-Style) untuk menyimpan teks/string

        2. Dua cara menyimpan teks
            a. Character Array (C-Style String) - Cara jadul
            a. std::string                      - Cara Modern, Lebih mudah

        3. Null Terminator
            Adalah penanda berakhirnya sebuah string, dengan karakter khusus '\0' (NULL/NOL)
            '\0' tidak tampil dilayar, tapi wajib
            ---> Letaknya ada di index terakhir sebuah array

            Visualisasi:
                char nama[6] = "Gega";

                    Index:  [ 0 ] [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ]
                    Value:  [ G ] [ e ] [ g ] [ a ] [\0 ] [   ]

            NB : 
                Harus melebihi 1 index untuk tempat null terminator ini
                Ukuran Array = Panjang Teks + 1 (untuk \0)
                    "Gega" = 4 huruf -> butuh char[5] (minimal)

                Kalau ukuran array kurang dan \0 tidak termuat:
                    -> cout akan terus baca memory sampai ketemu \0 acak
                    -> Output GARBAGE (karakter aneh)
                    -> UNDEFINED BEHAVIOR!
        
        4. Deklarasi dan Inialisasi
            a. Deklarasi
                Seperti array pada umumnya
                char namaArray[ukurannya];

                contoh:
                    char nama[10];                       ---> Bisa menyimpan 9 huruf + 1 \0
                    char kota[6] = "Jogja";              ---> Otomatis tambah \0 di akhir
                    char huruf[3] = {'A','B','C'};       ---> BAHAYA! Tidak ada \0!
                    char huruf[4] = {'A','B','C','\0'};  ---> Aman, ada \0

            b. Cara Inisialisasi (String Literal):
                    Dengan ukuran eksplisit:
                        char nama[6] = "Gega";           ---> Size 6, isi "Gega" + \0 + sisa 0

                    Omit size (auto-detect):        
                        char nama[] = "Gega";            ---> Otomatis size 5 (4 + \0)

                    Uniform Init (C++11):       
                        char nama[]{"Gega"};             ---> Modern style

        5. Input dan Output
            a. Output dengan cout:
                    char nama[] = "Gega";
                    cout << nama;                        ---> Output: Gega (cout baca sampai \0)

            b. Input dengan cin:
                    char nama[20];
                    cin >> nama;                         ---> Input sampai SPASI (stop di spasi)

                    Masalah cin:
                        Kalau input "Gega Ramadhan" -> nama hanya berisi "Gega"
                        Sisanya ("Ramadhan") tertinggal di buffer!

            c. Input Kalimat dengan cin.getline():
                    char nama[50];
                    cin.getline(nama, 50);              ---> Input sampai ENTER, termasuk spasi

                    Syntax cin.getline():
                        cin.getline(namaArray, ukuranMax);
                        cin.getline(namaArray, ukuranMax, delimiterKhusus);

                    ----------------------------------------------------------------------------
                    |Perbedaan cin.getline() vs getline():                                     |
                    |        cin.getline(arr, size)        ---> untuk char array (C-style)     |
                    |        getline(cin, str)             ---> untuk std::string (C++ modern) |
                    ----------------------------------------------------------------------------

        6. Library CSTRING
            jika ingin mengoperasikan/memanipulasi character array maka butuh library csting

            Nama :
                #include <cstring>

            Fungsi            Kegunaan                            Contoh
            -----------------------------------------------------------------------
            strlen(s)         Panjang string (tanpa \0)           strlen("Gega") = 4
            strcpy(dst, src)  Copy string src ke dst              strcpy(a, b)
            strcat(dst, src)  Sambung src ke belakang dst         strcat(a, b)
            strcmp(s1, s2)    Bandingkan dua string               strcmp(a, b)
            strchr(s, c)      Cari karakter c dalam s             strchr(s, 'a')
            strstr(s1, s2)    Cari substring s2 dalam s1          strstr(s, "ga")

            Detail strcmp():
                Return 0    -> s1 == s2 (sama persis)
                Return < 0  -> s1 < s2  (s1 lebih kecil secara ASCII)
                Return > 0  -> s1 > s2  (s1 lebih besar secara ASCII)

                JANGAN pakai == untuk bandingan char array!
                    char a[] = "Halo";
                    char b[] = "Halo";
                    if (a == b)              // ❌ SALAH! Ini bandingin ALAMAT memory, bukan isinya!
                    if (strcmp(a, b) == 0)   // ✅ BENAR! Ini bandingin ISINYA

        7. Perbandingan Character Array dan String

            Aspek           char Array (C-style)        std::string (C++ Modern)
            ---------------------------------------------------------------------
            Deklarasi       char s[20] = "Halo";        string s = "Halo";
            Ukuran          Fixed (harus tentukan)       Dynamic (otomatis)
            Panjang         strlen(s)                    s.length() / s.size()
            Gabung          strcat(s1, s2)               s1 + s2 atau s1 += s2
            Bandingkan      strcmp(s1,s2) == 0           s1 == s2 (langsung)
            Input           cin.getline(s, size)         getline(cin, s)
            Null terminator Wajib dikelola manual        Otomatis
            Safety          Rawan buffer overflow        Lebih aman

            Kapan pakai char array?
                - Interoperasi dengan fungsi C (printf, scanf, library lama)
                - Low-level programming / embedded
                - Saat tidak bisa pakai std::string
    */
        
        // -------[ HELPER: cetak char array per karakter dengan index ]-------
            void cetakCharArray(char arr[]){
                int len = strlen(arr);
                cout << "   Index : ";
                for(int i = 0; i < len; i++) cout << "[ " << i << " ] ";
                cout << endl;
                cout << "   Value : ";
                for(int i = 0; i < len; i++) cout << "[ " << arr[i] << " ] ";
                cout << " [\0]" << endl;
            }

            void demoCharacterArray(){
            cout << "\n==========================================" << endl;
            cout << "|         ARRAY - MODUL 8.4              |" << endl;
            cout << "|         Character Array                |" << endl;
            cout << "==========================================" << endl;


            // =====================================================================
            // 1. CARA MENYIMPAN TEKS
            // =====================================================================
            cout << "\n===[ 1. Dua Cara Menyimpan Teks ]===" << endl;
            {
                // Cara modern - std::string
                string text1 = "Gega Ramadhan";

                // Cara C-style - char array (harus tentukan ukuran, ingat +1 untuk \0)
                char text2[] = "Gega Ramadhan";   // auto-detect size = 13 + 1 = 14

                cout << "   std::string  : " << text1 << "  (size dinamis)" << endl;
                cout << "   char array[] : " << text2 << "  (size = " << sizeof(text2) << " bytes, termasuk \0)" << endl;
            }


            // =====================================================================
            // 2. DEKLARASI & INISIALISASI
            // =====================================================================
            cout << "\n===[ 2. Deklarasi & Inisialisasi ]===" << endl;
            {
                // a. Ukuran eksplisit - wajib cukup untuk isi + \0
                char kota[6] = "Jogja";           // 5 huruf + 1 \0 = pas ukuran 6

                // b. Auto-detect size - compiler hitung sendiri
                char nama[] = "Gega";             // otomatis jadi char[5]

                // c. Uniform Init C++11
                char negara[]{"Indonesia"};       // modern style, sama saja

                // d. Per karakter - \0 WAJIB ditulis manual!
                char huruf[4] = {'A','B','C','\0'};

                cout << "   char kota[6]      = \"" << kota   << "\"  (size=" << sizeof(kota)   << ")" << endl;
                cout << "   char nama[]       = \"" << nama   << "\"   (size=" << sizeof(nama)   << ")" << endl;
                cout << "   char negara[]     = \"" << negara << "\" (size=" << sizeof(negara) << ")" << endl;
                cout << "   char huruf[4]     = \"" << huruf  << "\"   (size=" << sizeof(huruf)  << ")" << endl;
            }


            // =====================================================================
            // 3. NULL TERMINATOR - VISUALISASI MEMORY
            // =====================================================================
            cout << "\n===[ 3. Null Terminator - Visualisasi Memory ]===" << endl;
            {
                char kata[] = "Halo";
                cout << "   char kata[] = \"Halo\"" << endl;
                cetakCharArray(kata);
                cout << "   strlen(kata) = " << strlen(kata) << "  (tidak hitung \0)" << endl;
                cout << "   sizeof(kata) = " << sizeof(kata) << "  (hitung \0)" << endl;
            }


            // =====================================================================
            // 4. AKSES PER KARAKTER + LOOP
            // =====================================================================
            cout << "\n===[ 4. Akses Per Karakter + Loop ]===" << endl;
            {
                char kata[] = "Belajar";

                // Akses langsung lewat index
                cout << "   kata[0] = '" << kata[0] << "'  (karakter pertama)" << endl;
                cout << "   kata[6] = '" << kata[6] << "'  (karakter terakhir)" << endl;

                // Loop pakai index
                cout << "   For loop       : ";
                for(int i = 0; i < (int)strlen(kata); i++) cout << kata[i] << " ";
                cout << endl;

                // Loop sampai ketemu \0 (cara C-style)
                cout << "   Loop s/d \\0   : ";
                for(int i = 0; kata[i] != '\0'; i++) cout << kata[i] << " ";
                cout << endl;

                // Range-based for (C++11)
                cout << "   Range-based    : ";
                for(char c : kata) if(c != '\0') cout << c << " ";
                cout << endl;
            }


            // =====================================================================
            // 5. INPUT & OUTPUT
            // =====================================================================
            cout << "\n===[ 5. Input & Output ]===" << endl;
            {
                char contohCin[20]     = "Gega";        // simulasi input cin >> (stop di spasi)
                char contohGetline[50] = "Gega Ramadhan"; // simulasi cin.getline (termasuk spasi)

                cout << "   cin >> nama          : \"" << contohCin     << "\"  (stop di spasi)" << endl;
                cout << "   cin.getline(nama,50) : \"" << contohGetline << "\"  (ambil semua)" << endl;
                cout << "   NB: pakai cin.getline() untuk input yang ada spasinya!" << endl;
            }


            // =====================================================================
            // 6. FUNGSI CSTRING
            // =====================================================================
            cout << "\n===[ 6. Fungsi <cstring> ]===" << endl;

            // --- strlen ---
            cout << "\n   [strlen] - Hitung Panjang" << endl;
            {
                char s[] = "Halo Dunia";
                cout << "   strlen(\"" << s << "\") = " << strlen(s) << endl;
            }

            // --- strcpy ---
            cout << "\n   [strcpy] - Salin String" << endl;
            {
                char src[] = "C++ Keren";
                char dst[20];                     // dst harus cukup besar!
                strcpy(dst, src);
                cout << "   src = \"" << src << "\"" << endl;
                cout << "   dst setelah strcpy = \"" << dst << "\"" << endl;
            }

            // --- strcat ---
            cout << "\n   [strcat] - Sambung String" << endl;
            {
                char depan[30] = "Halo, ";        // ukuran harus cukup untuk hasil akhir
                char belakang[] = "Gaes!";
                strcat(depan, belakang);
                cout << "   Hasil strcat = \"" << depan << "\"" << endl;
            }

            // --- strcmp ---
            cout << "\n   [strcmp] - Bandingkan String" << endl;
            {
                char p1[] = "rahasia123";
                char p2[] = "rahasia123";
                char p3[] = "salahpass";

                int cmp12 = strcmp(p1, p2);
                int cmp13 = strcmp(p1, p3);

                cout << "   strcmp(p1, p2) = " << cmp12 << "  -> " << (cmp12 == 0 ? "SAMA ✓" : "BEDA ✗") << endl;
                cout << "   strcmp(p1, p3) = " << cmp13 << "  -> " << (cmp13 == 0 ? "SAMA ✓" : "BEDA ✗") << endl;
                cout << "   ⚠ Jangan pakai == untuk bandingin char array!" << endl;

                // Simulasi login
                cout << "   Simulasi login: ";
                if(strcmp(p1, p2) == 0) cout << "Login BERHASIL ✓" << endl;
                else                    cout << "Password SALAH ✗" << endl;
            }

            // --- strchr ---
            cout << "\n   [strchr] - Cari Karakter dalam String" << endl;
            {
                char kalimat[] = "Belajar C++";
                char* hasil = strchr(kalimat, 'a');
                cout << "   Cari 'a' dalam \"" << kalimat << "\"" << endl;
                if(hasil) cout << "   Ketemu! Sisa string dari sana: \"" << hasil << "\"" << endl;
                else      cout << "   Tidak ditemukan" << endl;
            }

            // --- strstr ---
            cout << "\n   [strstr] - Cari Substring" << endl;
            {
                char kalimat[] = "Saya suka belajar C++";
                char* hasil = strstr(kalimat, "belajar");
                cout << "   Cari \"belajar\" dalam \"" << kalimat << "\"" << endl;
                if(hasil) cout << "   Ketemu! Sisa string dari sana: \"" << hasil << "\"" << endl;
                else      cout << "   Tidak ditemukan" << endl;
            }

            // =====================================================================
            // 7. CHAR ARRAY vs STD::STRING
            // =====================================================================
            cout << "\n===[ 7. Char Array vs std::string ]===" << endl;
            {
                // char array
                char cArr[30] = "Char Array";
                strcat(cArr, " + tambah");         // sambung pakai strcat
                int panjangC = strlen(cArr);

                // std::string
                string sStr = "std::string";
                sStr += " + tambah";               // sambung pakai +=
                int panjangS = sStr.length();

                cout << "   char[]      : \"" << cArr << "\"  panjang=" << panjangC << endl;
                cout << "   std::string : \"" << sStr << "\"  panjang=" << panjangS << endl;

                // Konversi std::string -> char array
                string asal = "Konversi ke char[]";
                char buf[50];
                strcpy(buf, asal.c_str());         // c_str() ubah string jadi const char*
                cout << "   Konversi string -> char[] : \"" << buf << "\"" << endl;
            }

            // =====================================================================
            // 8. ARRAY OF STRINGS (2D Char Array)
            // =====================================================================
            cout << "\n===[ 8. Array of Strings (2D Char Array) ]===" << endl;
            {
                // Tiap baris = satu string, kolom = max panjang string + \0
                char buah[5][10] = {
                    "Apel",
                    "Mangga",
                    "Jeruk",
                    "Anggur",
                    "Melon"
                };

                cout << "   Daftar buah:" << endl;
                for(int i = 0; i < 5; i++){
                    cout << "   [" << i << "] " << buah[i]
                        << "  (panjang=" << strlen(buah[i]) << ")" << endl;
                }

                // Sorting nama buah pakai strcmp + bubble sort
                cout << "   Sorted (A-Z):" << endl;
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4 - i; j++){
                        if(strcmp(buah[j], buah[j+1]) > 0){
                            char temp[10];
                            strcpy(temp,    buah[j]);
                            strcpy(buah[j], buah[j+1]);
                            strcpy(buah[j+1], temp);
                        }
                    }
                }
                for(int i = 0; i < 5; i++){
                    cout << "   [" << i << "] " << buah[i] << endl;
                }
            }
        }

    /* Modul 8.5 - Array Multidimensi

        1. Apa itu array multidimensi?
            adalah array yang memiliki lebih dari satu dimensi/index

        2. Analogi :
            - 1D        ---> Seperti Barisan        : [85, 90, 78, 92]
            - 2D        ---> Seperti Tabel 2x2      : 4 siswa × 5 mata pelajaran
            - 3D        ---> Seperti Kubus/rubix    : lantai × baris × kolom
            - nD        ---> Teoritis

        3. Kegunaan
            - 1D Array  ---> Untuk penyimanan yang simple
            - 2D Array  ---> Paling umum, seperti tabel / matriks / grid
            - 3D Array  ---> Lebih jarang, seperti kubus / data per waktu
            - nD Array  ---> Teoritis, jarang dipakai langsung

        ===================[ BAGIAN 1 - ARRAY 2 DIMENSI ] =====================
            1. Deklarasi 
                tipe_data namaArray[baris][kolom];

            2. Visualisasi Memory 2D:
                int nilai[3][4]:

                            Kolom 0  Kolom 1  Kolom 2  Kolom 3
                Baris 0 [   [0][0]   [0][1]   0][2]    [0][3] ]
                Baris 1 [   [1][0]   [1][1]   1][2]    [1][3] ]
                Baris 2 [   [2][0]   [2][1]   2][2]    [2][3] ]

                Di memory, disimpan BERURUTAN (row-major order):
                    [0][0] -> [0][1] -> [0][2] -> [0][3] -> [1][0] -> [1][1] -> ...

            3. Inisialisasi Array 2D:
                a. List Initialization Lengkap:
                    int matriks[2][3] = {
                        {1, 2, 3},      ---> Baris 0
                        {4, 5, 6}       ---> Baris 1
                    };

                b. Tanpa kurung kurawal dalam (flat):
                    int matriks[2][3] = {1, 2, 3, 4, 5, 6};     ---> Sama saja

                c. Partial Initialization:
                    int matriks[2][3] = {{1, 2}, {4}};          ---> Sisanya otomatis 0

                d. Zero Initialization:
                    int matriks[3][3] = {0};                    ---> Semua elemen jadi 0

                e. Omit Baris (auto-detect), tapi KOLOM wajib:
                    int matriks[][3] = {{1,2,3},{4,5,6}};       ---> Baris otomatis 2

            4. Akses Elemen Array 2D:
                int matriks[2][3] = {{10, 20, 30}, {40, 50, 60}};

                Baca:
                    cout << matriks[0][1];  ---> Output: 20  (baris 0, kolom 1)
                    cout << matriks[1][2];  ---> Output: 60  (baris 1, kolom 2)

                Tulis:
                    matriks[0][0] = 99;     ---> Ubah elemen [0][0] jadi 99

            5. Iterasi Array 2D (Nested Loop):
                Wajib nested for loop: loop luar untuk baris, loop dalam untuk kolom.

                for (int i = 0; i < baris; i++) {
                    for (int j = 0; j < kolom; j++) {
                        cout << matriks[i][j];
                    }
                }

        ===================[ BAGIAN 2 - OPERASI MATRIX ARRAY ] =====================
        1. Penjumlahan Matriks:
                Syarat: Ukuran matriks A == ukuran matriks B
                Rumus:  C[i][j] = A[i][j] + B[i][j]

            2. Perkalian Matriks:
                Syarat: Kolom A == Baris B
                Rumus:  C[i][j] = Σ (A[i][k] * B[k][j])

                Contoh: A[2][3] × B[3][2] -> Hasil C[2][2]

            3. Transpose Matriks:
                Tukar baris dan kolom.
                Rumus: B[j][i] = A[i][j]

                Contoh:
                    A = [1, 2, 3]     Transpose A = [1, 4]
                        [4, 5, 6]                   [2, 5]
                                                    [3, 6]

        ===================[ BAGIAN 3 - ARRAY 3 DIMENSI ] =====================
            1. Deklarasi Array 3D:
                tipe_data nama[DEPTH][BARIS][KOLOM];

                Analogi:
                    Depth  = lantai gedung
                    Baris  = baris kursi tiap lantai
                    Kolom  = kolom kursi tiap baris

                Contoh:
                    int gedung[3][4][5];    ---> 3 lantai, 4 baris, 5 kolom = 60 elemen

            2. Akses Elemen 3D:
                gedung[lantai][baris][kolom]

                Contoh:
                    gedung[0][1][2] = 10;   ---> Lantai 0, Baris 1, Kolom 2 = 10

            3. Iterasi Array 3D (Triple Nested Loop):
                for (int d = 0; d < depth; d++) {
                    for (int i = 0; i < baris; i++) {
                        for (int j = 0; j < kolom; j++) {
                            cout << data[d][i][j];
                        }
                    }
                }

        ===================[ BAGIAN 4 - TIPS & UKURAN ] =====================
            1. Cara Hitung Ukuran (sizeof):
                int grid[3][4];
                sizeof(grid)                        ---> 48 bytes (3×4×4)
                sizeof(grid[0])                     ---> 16 bytes (1 baris = 4×4)
                sizeof(grid[0][0])                  ---> 4 bytes  (1 elemen int)

                Jumlah elemen:
                    total = sizeof(grid) / sizeof(grid[0][0])   ---> 12 elemen

            2. Konstanta untuk Ukuran (Best Practice):
                const int BARIS = 3, KOLOM = 3;
                int matriks[BARIS][KOLOM];          ---> Lebih mudah diubah & dibaca
    */

        // -------[ HELPER: cetak matriks 2D dengan border rapi ]-------
            void cetakMatriks(int mat[][4], int baris, int kolom, string label = ""){
                if(label != "") cout << "   " << label << endl;
                cout << "   +";
                for(int j = 0; j < kolom; j++) cout << "------+";
                cout << endl;
                for(int i = 0; i < baris; i++){
                    cout << "   |";
                    for(int j = 0; j < kolom; j++){
                        cout << "  " << setw(3) << mat[i][j] << " |";
                    }
                    cout << "  <- Baris " << i << endl;
                    cout << "   +";
                    for(int j = 0; j < kolom; j++) cout << "------+";
                    cout << endl;
                }
            }

            void cetakMatriks3x3(int mat[3][3], int baris, int kolom, string label = ""){
                if(label != "") cout << "   " << label << endl;
                cout << "   +";
                for(int j = 0; j < kolom; j++) cout << "------+";
                cout << endl;
                for(int i = 0; i < baris; i++){
                    cout << "   |";
                    for(int j = 0; j < kolom; j++){
                        cout << "  " << setw(3) << mat[i][j] << " |";
                    }
                    cout << "  <- Baris " << i << endl;
                    cout << "   +";
                    for(int j = 0; j < kolom; j++) cout << "------+";
                    cout << endl;
                }
            }

            void demoArrayMultidimensi(){
            cout << "\n==========================================" << endl;
            cout << "|         ARRAY - MODUL 8.5              |" << endl;
            cout << "|         Array Multidimensi             |" << endl;
            cout << "==========================================" << endl;


            // =====================================================================
            // 1. DEKLARASI & INISIALISASI ARRAY 2D
            // =====================================================================
            cout << "\n===[ 1. Deklarasi & Inisialisasi Array 2D ]===" << endl;
            {
                // a. List Initialization Lengkap
                int A[2][3] = {
                    {1, 2, 3},    // Baris 0
                    {4, 5, 6}     // Baris 1
                };

                // b. Flat (sama saja, tanpa kurung kurawal dalam)
                int B[2][3] = {1, 2, 3, 4, 5, 6};

                // c. Partial - sisanya otomatis 0
                int C[2][3] = {{10, 20}, {40}};

                // d. Zero Initialization - semua jadi 0
                int D[2][3] = {0};

                // e. Omit baris (auto-detect), KOLOM wajib ditulis
                int E[][3] = {{7, 8, 9}, {10, 11, 12}};

                cout << "   A[2][3] list init    : ";
                for(int i=0;i<2;i++){ for(int j=0;j<3;j++) cout << A[i][j] << " "; cout << "| "; }
                cout << endl;

                cout << "   B[2][3] flat         : ";
                for(int i=0;i<2;i++){ for(int j=0;j<3;j++) cout << B[i][j] << " "; cout << "| "; }
                cout << endl;

                cout << "   C[2][3] partial      : ";
                for(int i=0;i<2;i++){ for(int j=0;j<3;j++) cout << C[i][j] << " "; cout << "| "; }
                cout << "  (sisanya auto=0)" << endl;

                cout << "   D[2][3] zero init    : ";
                for(int i=0;i<2;i++){ for(int j=0;j<3;j++) cout << D[i][j] << " "; cout << "| "; }
                cout << endl;

                cout << "   E[][3] omit baris    : ";
                for(int i=0;i<2;i++){ for(int j=0;j<3;j++) cout << E[i][j] << " "; cout << "| "; }
                cout << endl;
            }


            // =====================================================================
            // 2. VISUALISASI MEMORY (INDEX & AKSES)
            // =====================================================================
            cout << "\n===[ 2. Visualisasi Index & Akses Elemen ]===" << endl;
            {
                int mat[3][4] = {
                    {10, 20, 30, 40},
                    {50, 60, 70, 80},
                    {90,100,110,120}
                };

                // Tampil dengan header kolom
                cout << "   mat[3][4]:" << endl;
                cout << "            Kol[0] Kol[1] Kol[2] Kol[3]" << endl;
                cout << "         +-------+------+------+------+" << endl;
                for(int i = 0; i < 3; i++){
                    cout << "   Baris[" << i << "] |";
                    for(int j = 0; j < 4; j++) cout << "  " << setw(3) << mat[i][j] << "  |";
                    cout << endl;
                    cout << "         +-------+------+------+------+" << endl;
                }

                cout << "\n   Akses langsung:" << endl;
                cout << "   mat[0][0] = " << mat[0][0] << "   (baris 0, kolom 0)" << endl;
                cout << "   mat[1][2] = " << mat[1][2] << "   (baris 1, kolom 2)" << endl;
                cout << "   mat[2][3] = " << mat[2][3] << "  (baris 2, kolom 3)" << endl;

                // Modifikasi
                mat[1][1] = 999;
                cout << "\n   Setelah mat[1][1] = 999 :" << endl;
                cout << "            Kol[0] Kol[1] Kol[2] Kol[3]" << endl;
                cout << "         +-------+------+------+------+" << endl;
                for(int i = 0; i < 3; i++){
                    cout << "   Baris[" << i << "] |";
                    for(int j = 0; j < 4; j++) cout << "  " << setw(3) << mat[i][j] << "  |";
                    cout << endl;
                    cout << "         +-------+------+------+------+" << endl;
                }
            }


            // =====================================================================
            // 3. CONTOH NYATA: TABEL NILAI SISWA
            // =====================================================================
            cout << "\n===[ 3. Contoh Nyata: Tabel Nilai Siswa ]===" << endl;
            {
                const int JML_SISWA = 4;
                const int JML_MAPEL = 4;

                string namaSiswa[JML_SISWA] = {"Andi  ", "Budi  ", "Cici  ", "Dina  "};
                string namaMapel[JML_MAPEL] = {"MTK", "IPA", "IPS", "ING"};

                int nilai[JML_SISWA][JML_MAPEL] = {
                    {85, 90, 78, 92},   // Andi
                    {70, 88, 95, 80},   // Budi
                    {92, 75, 85, 88},   // Cici
                    {78, 82, 90, 95}    // Dina
                };

                // Header tabel
                cout << "   +----------+-----+-----+-----+-----+--------+" << endl;
                cout << "   | Nama     | MTK | IPA | IPS | ING | Rata2  |" << endl;
                cout << "   +----------+-----+-----+-----+-----+--------+" << endl;

                int idxTerbaik = 0;
                double rataMax = 0;

                for(int i = 0; i < JML_SISWA; i++){
                    int total = 0;
                    cout << "   | " << namaSiswa[i] << " |";
                    for(int j = 0; j < JML_MAPEL; j++){
                        cout << "  " << nilai[i][j] << " |";
                        total += nilai[i][j];
                    }
                    double rata = (double)total / JML_MAPEL;
                    cout << " " << fixed << setprecision(1) << rata << "  |" << endl;
                    cout << "   +----------+-----+-----+-----+-----+--------+" << endl;

                    if(rata > rataMax){ rataMax = rata; idxTerbaik = i; }
                }

                cout << "\n   Siswa terbaik: " << namaSiswa[idxTerbaik]
                     << " (rata-rata: " << rataMax << ")" << endl;
            }


            // =====================================================================
            // 4. OPERASI MATRIKS
            // =====================================================================
            cout << "\n===[ 4. Operasi Matriks ]===" << endl;
            {
                int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
                int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
                int C[3][3] = {0};

                // --- Penjumlahan ---
                cout << "\n   [Penjumlahan] C = A + B  (C[i][j] = A[i][j] + B[i][j])" << endl;
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        C[i][j] = A[i][j] + B[i][j];

                // Tampil A | + | B | = | C
                cout << "       Matriks A          +    Matriks B          =    Matriks C" << endl;
                for(int i=0;i<3;i++){
                    cout << "   [";
                    for(int j=0;j<3;j++) cout << setw(3) << A[i][j];
                    cout << " ]";
                    cout << (i==1 ? "  +  " : "     ");
                    cout << "[";
                    for(int j=0;j<3;j++) cout << setw(3) << B[i][j];
                    cout << " ]";
                    cout << (i==1 ? "  =  " : "     ");
                    cout << "[";
                    for(int j=0;j<3;j++) cout << setw(3) << C[i][j];
                    cout << " ]" << endl;
                }

                // --- Transpose ---
                cout << "\n   [Transpose] B = A^T  (B[j][i] = A[i][j])" << endl;
                int T[3][3] = {0};
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        T[j][i] = A[i][j];

                cout << "       Matriks A          ->    Transpose A" << endl;
                for(int i=0;i<3;i++){
                    cout << "   [";
                    for(int j=0;j<3;j++) cout << setw(3) << A[i][j];
                    cout << " ]";
                    cout << (i==1 ? "  ->  " : "     ");
                    cout << "[";
                    for(int j=0;j<3;j++) cout << setw(3) << T[i][j];
                    cout << " ]" << endl;
                }

                // --- Perkalian Matriks ---
                cout << "\n   [Perkalian] C = A x B  (C[i][j] = sum A[i][k]*B[k][j])" << endl;
                int P[3][3] = {0};
                for(int i=0;i<3;i++)
                    for(int j=0;j<3;j++)
                        for(int k=0;k<3;k++)
                            P[i][j] += A[i][k] * B[k][j];

                cout << "       Matriks A          x    Matriks B          =    Matriks C" << endl;
                for(int i=0;i<3;i++){
                    cout << "   [";
                    for(int j=0;j<3;j++) cout << setw(3) << A[i][j];
                    cout << " ]";
                    cout << (i==1 ? "  x  " : "     ");
                    cout << "[";
                    for(int j=0;j<3;j++) cout << setw(3) << B[i][j];
                    cout << " ]";
                    cout << (i==1 ? "  =  " : "     ");
                    cout << "[";
                    for(int j=0;j<3;j++) cout << setw(4) << P[i][j];
                    cout << " ]" << endl;
                }
            }


            // =====================================================================
            // 5. ARRAY 3 DIMENSI
            // =====================================================================
            cout << "\n===[ 5. Array 3 Dimensi ]===" << endl;
            {
                // Analogi: data suhu 2 kota, 3 hari, 2 waktu (pagi/sore)
                // suhu[kota][hari][waktu]
                int suhu[2][3][2] = {
                    { {28,33}, {27,32}, {29,34} },   // Kota 0: Jogja
                    { {31,36}, {30,35}, {32,37} }    // Kota 1: Jakarta
                };

                string namaKota[2]  = {"Jogja  ", "Jakarta"};
                string namaHari[3]  = {"Senin ", "Selasa", "Rabu  "};
                string namaWaktu[2] = {"Pagi", "Sore"};

                cout << "   Data suhu[2 kota][3 hari][2 waktu]:" << endl;
                cout << "   +-----------+--------+--------+--------+" << endl;
                cout << "   | Kota      | Senin  | Selasa | Rabu   |" << endl;
                cout << "   +-----------+--------+--------+--------+" << endl;

                for(int k = 0; k < 2; k++){
                    for(int w = 0; w < 2; w++){
                        cout << "   | " << namaKota[k] << " " << namaWaktu[w] << " |";
                        for(int h = 0; h < 3; h++){
                            cout << " " << setw(3) << suhu[k][h][w] << "°C  |";
                        }
                        cout << endl;
                    }
                    cout << "   +-----------+--------+--------+--------+" << endl;
                }

                // Akses langsung
                cout << "\n   Akses langsung suhu[1][2][0] (Jakarta, Rabu, Pagi) = "
                    << suhu[1][2][0] << "°C" << endl;
            }


            // =====================================================================
            // 6. SIZEOF ARRAY 2D
            // =====================================================================
            cout << "\n===[ 6. sizeof() pada Array 2D ]===" << endl;
            {
                int grid[3][4];

                int totalBytes  = sizeof(grid);
                int bytesBaris  = sizeof(grid[0]);
                int bytesElemen = sizeof(grid[0][0]);
                int jmlElemen   = totalBytes / bytesElemen;

                cout << "   Array int grid[3][4]:" << endl;
                cout << "   +-----------------------------+----------+" << endl;
                cout << "   | sizeof(grid)                | " << setw(4) << totalBytes  << " bytes |  (total semua)" << endl;
                cout << "   | sizeof(grid[0])             | " << setw(4) << bytesBaris  << " bytes |  (1 baris)" << endl;
                cout << "   | sizeof(grid[0][0])          | " << setw(4) << bytesElemen << " bytes |  (1 elemen int)" << endl;
                cout << "   | Jumlah elemen               | " << setw(4) << jmlElemen   << "       |  (3 x 4)" << endl;
                cout << "   +-----------------------------+----------+" << endl;
                cout << "   Rumus jumlah elemen = sizeof(grid) / sizeof(grid[0][0])" << endl;
            }
        }

    /* Modul 8.6-8.10 - Array + Function = Advance

        ===================[ MODUL 8.6 - PASS ARRAY KE FUNCTION ] =====================
            1. Konsep Dasar
                Saat array dipass ke function, yang dikirim adalah POINTER (alamat memori),
                bukan SALINAN seperti variabel biasa.

                Konsekuensi PENTING:
                    -> Perubahan di dalam function AKAN mempengaruhi array ASLI
                    -> Ini seperti pass by reference, tapi khusus untuk array
                    -> Tidak perlu tanda & karena array sudah otomatis jadi pointer

            2. Syntax Pass Array ke Function:
                // Cara 1: Pakai []
                void namaFunction(int arr[], int size) { ... }

                // Cara 2: Pakai pointer (sama saja di balik layar)
                void namaFunction(int* arr, int size) { ... }

                // Cara 3: Pakai referensi dengan ukuran tetap (C++11)
                void namaFunction(int (&arr)[5]) { ... }   ---> Hanya untuk ukuran FIXED

                Kenapa harus kirim SIZE juga?
                    Karena saat array jadi parameter, sizeof() tidak bisa diandalkan.
                    sizeof(arr) di dalam function = sizeof pointer (4/8 byte), BUKAN ukuran array!
                    Jadi ukuran array WAJIB dikirim sebagai parameter terpisah.

            3. Protect Array dari Perubahan - pakai const:
                void tampilArray(const int arr[], int size) { ... }
                    ---> arr tidak bisa diubah di dalam function

        ===================[ MODUL 8.7 - RETURN ARRAY DARI FUNCTION ] =====================
            1. Cara Return Array:
                C++ tidak bisa return array secara langsung.
                Ada beberapa solusi:

                a. Return lewat parameter (pass by reference / pointer) ← Paling umum
                    void isiArray(int arr[], int size) {
                        for (int i = 0; i < size; i++) arr[i] = i * 2;
                    }

                b. Return pointer ke static array ← Hati-hati, array harus static!
                    int* buatArray() {
                        static int arr[5] = {1,2,3,4,5};
                        return arr;
                    }

                c. Return menggunakan std::array atau std::vector ← Modern C++
                    (dibahas lebih lanjut di modul STL)

            2. Kenapa Tidak Bisa Return Array Biasa?
                int[] buatArray() { ... }   ---> ❌ TIDAK VALID di C++
                
                Karena array lokal akan dihapus dari memory saat function selesai.
                Return pointer ke local array = UNDEFINED BEHAVIOR (bahaya!)

        ===================[ MODUL 8.8 - FUNCTION UNTUK ALGORITMA ARRAY ] =====================
            Fungsi-fungsi utility yang sering dibuat untuk array:

            a. Tampil Array        : void tampilArray(arr, size)
            b. Hitung Total        : int totalArray(arr, size)
            c. Cari Nilai Max/Min  : int maxArray(arr, size)
            d. Linear Search       : int cariElemen(arr, size, target)
            e. Isi Array           : void isiArray(arr, size)
            f. Sorting             : void sortArray(arr, size)

        ===================[ MODUL 8.9 - PASS ARRAY 2D KE FUNCTION ] =====================
            1. Syntax Pass Array 2D:
                Kolom WAJIB dicantumkan, baris boleh dikosongkan.

                // Cara 1: Eksplisit baris & kolom
                void tampilMatriks(int mat[3][3], int baris, int kolom) { ... }

                // Cara 2: Baris dikosongkan
                void tampilMatriks(int mat[][3], int baris, int kolom) { ... }

                Kenapa kolom wajib?
                    Compiler butuh tahu kolom untuk hitung offset memory:
                    mat[i][j] = *(mat + i*KOLOM + j)
                    Kalau kolom tidak diketahui -> compiler tidak bisa hitung lokasi elemen!

        ===================[ MODUL 8.10 - ARRAY SEBAGAI GLOBAL ] =====================
            1. Global Array:
                Dideklarasikan di luar semua function -> bisa diakses semua function.

                int skorGlobal[5] = {0};    // Di luar main() dan function lain

                Kapan pakai global array?
                    ✅ Data yang dipakai banyak function berbeda
                    ✅ Lookup table (data konstan yang sering dipakai)
                    ❌ Hindari untuk data yang seharusnya lokal (rawan bug)

    */
    
        // ==================[ GLOBAL ARRAY - Modul 8.10 ]==================
        // Dideklarasikan di luar semua function -> bisa diakses function manapun
            int skorPemain[5] = {70, 85, 60, 90, 75};   // Global array skor 5 pemain

            void tampilSkorGlobal(){
                cout << "   [ ";
                for(int i = 0; i < 5; i++){
                    cout << "P" << i+1 << ":" << skorPemain[i];
                    if(i < 4) cout << "  ";
                }
                cout << " ]" << endl;
            }

            void tambahBonusGlobal(int bonus){
                for(int i = 0; i < 5; i++) skorPemain[i] += bonus;
            }

            void resetSkorGlobal(){
        for(int i = 0; i < 5; i++) skorPemain[i] = 0;
    }

        // ==================[ HELPER FUNCTIONS - Modul 8.8 ]==================
        // Kumpulan utility function untuk array - bisa dipakai ulang kapanpun!

            // Tampil isi array (const -> tidak bisa ubah isi dari dalam function)
            void tampilArr(const int arr[], int size, string label = ""){
                if(label != "") cout << "   " << label << endl;
                cout << "   [ ";
                for(int i = 0; i < size; i++){
                    cout << arr[i];
                    if(i < size-1) cout << ", ";
                }
                cout << " ]" << endl;
            }

            // Hitung total semua elemen
            int totalArr(const int arr[], int size){
                int total = 0;
                for(int i = 0; i < size; i++) total += arr[i];
                return total;
            }

            // Hitung rata-rata
            double rataArr(const int arr[], int size){
                return (double)totalArr(arr, size) / size;
            }

            // Cari nilai maksimum
            int maxArr(const int arr[], int size){
                int maks = arr[0];
                for(int i = 1; i < size; i++)
                    if(arr[i] > maks) maks = arr[i];
                return maks;
            }

            // Cari nilai minimum
            int minArr(const int arr[], int size){
                int mini = arr[0];
                for(int i = 1; i < size; i++)
                    if(arr[i] < mini) mini = arr[i];
                return mini;
            }

            // Linear search -> return index, atau -1 kalau tidak ketemu
            int cariArr(const int arr[], int size, int target){
                for(int i = 0; i < size; i++)
                    if(arr[i] == target) return i;
                return -1;
            }

            // Bubble sort ascending (array ASLI akan berubah!)
            void sortArr(int arr[], int size){
                for(int i = 0; i < size-1; i++)
                    for(int j = 0; j < size-i-1; j++)
                        if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
            }

            // Isi array dengan kelipatan (return via parameter - Modul 8.7)
            void isiKelipatanArr(int arr[], int size, int kelipatan){
                for(int i = 0; i < size; i++) arr[i] = (i+1) * kelipatan;
            }

            // Return pointer ke static array tabel perkalian (Modul 8.7)
            int* tabelKali(int angka){
            static int hasil[10];
            for(int i = 0; i < 10; i++) hasil[i] = angka * (i+1);
            return hasil;
        }

        // ==================[ HELPER 2D - Modul 8.9 ]==================

            // Tampil matriks 2D - kolom WAJIB dicantumkan di parameter
            void tampilMatriks2D(const int mat[][3], int baris, int kolom, string label = ""){
                if(label != "") cout << "   " << label << endl;
                cout << "   +";
                for(int j = 0; j < kolom; j++) cout << "------+";
                cout << endl;
                for(int i = 0; i < baris; i++){
                    cout << "   |";
                    for(int j = 0; j < kolom; j++) cout << "  " << setw(3) << mat[i][j] << " |";
                    cout << endl;
                    cout << "   +";
                    for(int j = 0; j < kolom; j++) cout << "------+";
                    cout << endl;
                }
            }

            // Hitung total matriks 2D
            int totalMatriks2D(const int mat[][3], int baris, int kolom){
                int total = 0;
                for(int i = 0; i < baris; i++)
                    for(int j = 0; j < kolom; j++)
                        total += mat[i][j];
                return total;
            }

            // Cari max di matriks 2D + catat posisinya
            int maxMatriks2D(const int mat[][3], int baris, int kolom, int &idxBaris, int &idxKolom){
                int maks = mat[0][0];
                idxBaris = 0; idxKolom = 0;
                for(int i = 0; i < baris; i++)
                    for(int j = 0; j < kolom; j++)
                        if(mat[i][j] > maks){
                            maks = mat[i][j];
                            idxBaris = i; idxKolom = j;
                        }
                return maks;
            }

        // ==================[ DEMO FUNCTION ]==================
            void demoArrayFunction(){
            cout << "\n==========================================" << endl;
            cout << "|         ARRAY - MODUL 8.6-8.10        |" << endl;
            cout << "|         Array + Function               |" << endl;
            cout << "==========================================" << endl;


            // =================================================================
            // MODUL 8.6 - PASS ARRAY KE FUNCTION
            // =================================================================
            cout << "\n===[ Modul 8.6: Pass Array ke Function ]===" << endl;
            {
                int data[6] = {30, 10, 50, 20, 40, 60};

                cout << "\n   Konsep: array dipass sebagai POINTER, bukan salinan!" << endl;
                cout << "   -> Perubahan di dalam function = ubah array ASLI" << endl;

                // --- Cara 1: pakai [] ---
                cout << "\n   [Cara 1 - pakai int arr[]]" << endl;
                tampilArr(data, 6, "Data awal:");

                // --- Cara 2: pakai const -> array aman, tidak bisa diubah ---
                cout << "\n   [Cara 2 - pakai const int arr[] -> array TERLINDUNGI]" << endl;
                cout << "   Cukup tampil saja, tidak bisa modif dari dalam function" << endl;
                tampilArr(data, 6, "Data (via const arr[]):");

                // --- Bukti: array asli BERUBAH kalau tidak pakai const ---
                cout << "\n   [Bukti: tanpa const -> array asli IKUT BERUBAH]" << endl;
                int bukti[5] = {1, 2, 3, 4, 5};
                cout << "   Sebelum di-pass ke function: "; 
                tampilArr(bukti, 5);

                // Fungsi inline kecil untuk demo efek samping
                auto gandakan = [](int arr[], int n){ for(int i=0;i<n;i++) arr[i]*=2; };
                gandakan(bukti, 5);

                cout << "   Sesudah  di-pass ke function (semua x2): ";
                tampilArr(bukti, 5);
                cout << "   Array asli BERUBAH! Itulah kenapa pakai const kalau tidak mau diubah." << endl;

                // --- Kenapa harus kirim SIZE ---
                cout << "\n   [Kenapa WAJIB kirim SIZE sebagai parameter terpisah?]" << endl;
                cout << "   sizeof(arr) di DALAM function = " << sizeof(int*) << " bytes (sizeof pointer!)" << endl;
                cout << "   sizeof(arr) di LUAR function  = " << sizeof(data) << " bytes (sizeof array asli)" << endl;
                cout << "   -> Compiler kehilangan info ukuran saat array jadi parameter!" << endl;
            }


            // =================================================================
            // MODUL 8.7 - RETURN ARRAY DARI FUNCTION
            // =================================================================
            cout << "\n===[ Modul 8.7: Return Array dari Function ]===" << endl;
            {
                cout << "\n   C++ TIDAK BISA return array secara langsung." << endl;
                cout << "   Solusinya ada 2 cara:" << endl;

                // --- Cara a: return lewat parameter (paling umum) ---
                cout << "\n   [Cara A: Return lewat Parameter (void + ubah array di dalam)]" << endl;
                int kelipatanTiga[6];
                isiKelipatanArr(kelipatanTiga, 6, 3);
                tampilArr(kelipatanTiga, 6, "Kelipatan 3 (1x3..6x3):");

                int kelipatanTujuh[6];
                isiKelipatanArr(kelipatanTujuh, 6, 7);
                tampilArr(kelipatanTujuh, 6, "Kelipatan 7 (1x7..6x7):");

                // --- Cara b: return pointer ke static array ---
                cout << "\n   [Cara B: Return Pointer ke Static Array]" << endl;
                cout << "   Array HARUS static! Local array akan dihapus saat function selesai." << endl;

                int angka = 8;
                int* tabel = tabelKali(angka);
                cout << "   Tabel perkalian " << angka << ":" << endl;
                cout << "   +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
                cout << "   |";
                for(int i = 0; i < 10; i++) cout << setw(2) << angka << "x" << i+1 << " |";
                cout << endl;
                cout << "   |";
                for(int i = 0; i < 10; i++) cout << "  " << setw(2) << tabel[i] << " |";
                cout << endl;
                cout << "   +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
            }


            // =================================================================
            // MODUL 8.8 - UTILITY FUNCTIONS
            // =================================================================
            cout << "\n===[ Modul 8.8: Utility Functions untuk Array ]===" << endl;
            {
                int nilai[8] = {85, 92, 70, 88, 95, 60, 78, 84};
                int n = 8;

                tampilArr(nilai, n, "Data nilai siswa:");

                cout << "\n   +-------------------+----------+" << endl;
                cout << "   | Operasi           | Hasil    |" << endl;
                cout << "   +-------------------+----------+" << endl;
                cout << "   | totalArr()        | " << setw(8) << totalArr(nilai, n)        << " |" << endl;
                cout << "   | rataArr()         | " << setw(7) << fixed << setprecision(2) << rataArr(nilai, n) << "  |" << endl;
                cout << "   | maxArr()          | " << setw(8) << maxArr(nilai, n)          << " |" << endl;
                cout << "   | minArr()          | " << setw(8) << minArr(nilai, n)          << " |" << endl;
                cout << "   +-------------------+----------+" << endl;

                // Linear search
                cout << "\n   [cariArr() - Linear Search]" << endl;
                int targets[3] = {88, 95, 100};
                for(int t : targets){
                    int pos = cariArr(nilai, n, t);
                    if(pos != -1)
                        cout << "   Cari " << setw(3) << t << " -> Ketemu  di index [" << pos << "]" << endl;
                    else
                        cout << "   Cari " << setw(3) << t << " -> Tidak ditemukan" << endl;
                }

                // Sort
                cout << "\n   [sortArr() - Bubble Sort Ascending]" << endl;
                int nilaiCopy[8] = {85, 92, 70, 88, 95, 60, 78, 84};
                tampilArr(nilaiCopy, n, "Sebelum sort:");
                sortArr(nilaiCopy, n);
                tampilArr(nilaiCopy, n, "Sesudah sort:");
            }


            // =================================================================
            // MODUL 8.9 - PASS ARRAY 2D KE FUNCTION
            // =================================================================
            cout << "\n===[ Modul 8.9: Pass Array 2D ke Function ]===" << endl;
            {
                cout << "\n   Aturan: KOLOM wajib dicantumkan, baris boleh dikosongkan." << endl;
                cout << "   -> Compiler butuh tahu kolom untuk hitung offset memory" << endl;
                cout << "   -> mat[i][j] = *(mat + i*KOLOM + j)" << endl;

                int mat[3][3] = {
                    {10, 20, 30},
                    {40, 50, 60},
                    {70, 80, 90}
                };

                cout << "\n   [tampilMatriks2D(mat, 3, 3)]" << endl;
                tampilMatriks2D(mat, 3, 3);
                cout << "   Total semua elemen : " << totalMatriks2D(mat, 3, 3) << endl;

                // Cari max + posisinya
                int iBaris, iKolom;
                int maks = maxMatriks2D(mat, 3, 3, iBaris, iKolom);
                cout << "   Nilai maksimum     : " << maks
                     << " (ada di [" << iBaris << "][" << iKolom << "])" << endl;

                // Demo pass array 2D lalu dimodifikasi
                cout << "\n   [Demo: function boleh modifikasi matriks kalau tidak pakai const]" << endl;
                auto kaliDua2D = [](int m[][3], int b, int k){
                    for(int i=0;i<b;i++) for(int j=0;j<k;j++) m[i][j] *= 2;
                };
                cout << "   Sebelum dikali 2:" << endl;
                tampilMatriks2D(mat, 3, 3);
                kaliDua2D(mat, 3, 3);
                cout << "   Sesudah dikali 2 (array asli berubah!):" << endl;
                tampilMatriks2D(mat, 3, 3);
            }


            // =================================================================
            // MODUL 8.10 - GLOBAL ARRAY
            // =================================================================
            cout << "\n===[ Modul 8.10: Global Array ]===" << endl;
            {
                cout << "\n   Global array bisa diakses & dimodifikasi dari function MANAPUN." << endl;
                cout << "   Pakai untuk: data yang dibutuhkan banyak function" << endl;
                cout << "   Hindari   : kalau data seharusnya lokal (rawan bug tersembunyi)" << endl;

                cout << "\n   [Skor awal 5 pemain (global array)]" << endl;
                tampilSkorGlobal();

                cout << "\n   tambahBonusGlobal(10) - semua pemain dapat +10" << endl;
                tambahBonusGlobal(10);
                tampilSkorGlobal();

                cout << "\n   tambahBonusGlobal(5)  - semua pemain dapat +5 lagi" << endl;
                tambahBonusGlobal(5);
                tampilSkorGlobal();

                // Cari pemain dengan skor tertinggi dari global array
                int idxJuara = 0;
                for(int i = 1; i < 5; i++)
                    if(skorPemain[i] > skorPemain[idxJuara]) idxJuara = i;
                cout << "\n   Pemain terbaik : Pemain " << idxJuara+1
                     << " dengan skor " << skorPemain[idxJuara] << endl;

                cout << "\n   resetSkorGlobal() - reset semua ke 0" << endl;
                resetSkorGlobal();
                tampilSkorGlobal();
                cout << "   Itulah bahayanya global: function lain bisa reset tanpa sepengetahuan kamu!" << endl;
            }
        }

// V. String C++ & - C-Style String

    /* MODUL 9.0 - Difference & Cheat Sheet

        Pada Bab U (Array 8.4) kita sudah belajar char[] alias C-style string,
        yaitu array karakter gaya C lama yang butuh null terminator \0 secara manual.

        Bab ini melanjutkan ke std::string, yaitu tipe data teks modern bawaan
        C++ yang jauh lebih mudah, aman, dan fleksibel untuk dipakai sehari-hari.

    
        ==================[ PERBEDAAN CEPAT: char[] vs std::string

            Aspek               char[] (C-style, Bab 8.4)          std::string (modern, Bab ini)
            ─────────────────── ─────────────────────────────────── ──────────────────────────────
            Tipe                Array karakter mentah               Object dari class <string>
            Ukuran              Tetap saat deklarasi                Dinamis, bisa berubah otomatis
            Null terminator     Wajib ada \0 di akhir               Diurus otomatis
            Penjumlahan         Pakai strcat(), ribet               Cukup pakai +
            Perbandingan        Pakai strcmp()                       Cukup pakai ==, <, >
            Keamanan            Rawan buffer overflow                Aman, ada bounds checking
            Header              #include <cstring>                  #include <string>

            --> Untuk project C++ modern: selalu gunakan std::string
                kecuali ada alasan khusus (misalnya interop dengan library C lama).


        ==================[ CHEAT SHEET - RINGKASAN CEPAT std::string

        Header              : #include <string>
        Deklarasi           : string s = "teks";
        Panjang             : s.length() atau s.size()
        Kosong?             : s.empty()
        Akses karakter      : s[i] (cepat) / s.at(i) (aman)
        Karakter pertama    : s.front()
        Karakter terakhir   : s.back()
        Gabung              : s1 + s2  atau  s1 += s2
        Cari                : s.find("sub")  --> index atau string::npos
        Cari dari belakang  : s.rfind("sub")
        Potong              : s.substr(pos, len)
        Ganti               : s.replace(pos, len, baru)
        Sisip               : s.insert(pos, str)
        Hapus bagian        : s.erase(pos, len)
        Hapus semua         : s.clear()
        Angka ke string     : to_string(42)
        String ke int       : stoi("42")
        String ke double    : stod("3.14")
        C-string ke string  : string s = cStr; (otomatis)
        string ke C-string  : s.c_str()
        Balik string        : reverse(s.begin(), s.end())
        Lowercase           : transform(s.begin(), s.end(), s.begin(), ::tolower)
        Uppercase           : transform(s.begin(), s.end(), s.begin(), ::toupper)
        Input satu kata     : cin >> s
        Input satu baris    : getline(cin, s)
        Parameter read-only : const string& s  (paling efisien)
    */  

    /* MODUL 9.1 - C-STYLE STRING (Tinjauan & Bahaya)
        1. Apa itu C-Style String?
            Array of char yang diakhiri karakter null '\0'
            Warisan dari bahasa C, masih relevan untuk dipahami.

            Contoh deklarasi:
                char nama[6]  = "Budi";          --> B-u-d-i-\0-_  (1 slot sisa)
                char kota[]   = "Jakarta";       --> compiler hitung otomatis: 7+1 = 8 slot
                char init[3]  = {'A','B','\0'};  --> manual

        2. Kenapa \0 itu kritis?
            Tanpa \0, fungsi seperti strlen(), cout, printf() tidak tahu
            kapan string berakhir --> terus baca memori sampai ketemu \0 kebetulan.
            Bug ini disebut BUFFER OVERREAD --> berbahaya!

        3. Fungsi-fungsi dari <cstring>:

            strlen(s)           --> Panjang string (tidak hitung \0)
                                    strlen("Budi") --> 4

            strcpy(dst, src)    --> Salin string src ke dst
                                    strcpy(a, "halo")

            strcat(dst, src)    --> Sambung src ke belakang dst
                                    strcat(a, " dunia")

            strcmp(s1, s2)      --> Bandingkan 2 string
                                    0  = sama
                                    <0 = s1 lebih kecil (secara ASCII)
                                    >0 = s1 lebih besar
                                    strcmp("abc","abc") --> 0

            strchr(s, c)        --> Cari karakter c di string s
                                    strchr("halo", 'a') --> pointer ke 'a'

            strstr(s, sub)      --> Cari substring di string
                                    strstr("halo dunia", "nia") --> pointer ke "nia"

        ❌ BAHAYA strcpy() & strcat():
            Tidak melakukan pengecekan panjang!
            Jika dst terlalu kecil --> BUFFER OVERFLOW --> crash / celah keamanan.
            Alternatif aman: strncpy() dan strncat()

        4. Input C-Style String:

            cin >> nama                  --> baca sampai spasi, TIDAK aman untuk kalimat panjang
            cin.getline(nama, 50)        --> baca sampai newline, max 49 karakter, lebih aman
    */
    
    /* MODUL 9.2 - DEKLARASI & OPERASI DASAR std::string
        1. Header yang dibutuhkan:
            #include <string>
            (kadang sudah terbawa <iostream>, tapi tetap tulis eksplisit)

        2. Cara Deklarasi & Inisialisasi:

            string nama = "Budi";           --> cara paling umum
            string nama("Budi");            --> constructor syntax
            string nama;                    --> string kosong ""
            string s(5, '*');               --> isi 5 karakter bintang: "*****"
            string s = "";                  --> string kosong eksplisit

        3. Operasi Dasar:

            Operasi             Contoh                          Keterangan
            ────────────────── ─────────────────────────────── ──────────────────────────
            Panjang            nama.length() / nama.size()     Jumlah karakter
            String kosong?     nama.empty()                    true jika panjang 0
            Gabung (concat)    "halo" + " " + "dunia"          Hasil: "halo dunia"
            Gabung (+=)        s += " tambahan"                Langsung tambah di belakang
            Ambil karakter     nama[0]  / nama.at(0)           Karakter pertama
            Bandingkan         s1 == s2 / s1 < s2              Seperti operator biasa

        4. Perbedaan [] vs at():

            nama[i]     --> akses langsung, TIDAK ada pengecekan batas
                            jika i >= ukuran --> undefined behavior (crash tak terduga)

            nama.at(i)  --> akses AMAN, ada pengecekan batas
                            jika i >= ukuran --> melempar exception std::out_of_range

            --> Pakai at() untuk keamanan, pakai [] untuk performa (saat sudah yakin index valid)

        5. Akses Karakter Khusus:

            nama.front()    --> karakter pertama (sama dengan nama[0])
            nama.back()     --> karakter terakhir (sama dengan nama[nama.size()-1])

        6. Modifikasi String:

            nama.push_back('!')     --> tambah satu karakter di akhir
            nama.pop_back()         --> hapus karakter terakhir
            nama.clear()            --> hapus semua isi, jadi string kosong ""
            nama.resize(n)          --> ubah panjang jadi n (potong/tambah)
            nama.resize(n, 'x')     --> ubah panjang, isi slot baru dengan 'x'

            --> Tidak seperti char[], string bisa berubah ukuran dinamis tanpa overflow!
    */

    /* MODUL 9.3 - METHOD-METHOD PENTING std::string
        1. substr(pos, len) --> Ambil bagian string
            Ambil substring mulai index pos sepanjang len karakter.
            Jika len tidak ditulis --> ambil sampai akhir.

            string s = "Hello World";
            s.substr(0, 5)      --> "Hello"
            s.substr(6)         --> "World"   (sampai akhir)
            s.substr(6, 3)      --> "Wor"

        2. find(what, start_pos) --> Cari posisi substring atau karakter
            Kembalikan index pertama ditemukan.
            Jika tidak ketemu --> kembalikan string::npos (nilai sangat besar ~4 miliar)

            "Hello World".find("World")     --> 6
            "Hello World".find("xyz")       --> string::npos
            "Hello World".find('l')         --> 2  (l pertama)
            "Hello World".find('l', 4)      --> 9  (mulai cari dari index 4)

            ⚠️  Selalu cek hasil find() != string::npos sebelum dipakai!

        3. replace(pos, len, new_str) --> Ganti bagian string
            Ganti len karakter mulai pos dengan new_str.
            Panjang pengganti boleh berbeda dari yang diganti.

            string s = "Hello World";
            s.replace(6, 5, "C++")      --> "Hello C++"

        4. insert(pos, str) --> Sisipkan string di posisi tertentu

            string s = "Halo World";
            s.insert(5, " Dunia")       --> "Halo Dunia World"

        5. erase(pos, len) --> Hapus bagian string
            Hapus len karakter mulai pos.
            Jika len tidak ditulis --> hapus sampai akhir.

            string s = "Hello World";
            s.erase(5, 6)       --> "Hello"
            s.erase(2)          --> "He"   (hapus dari index 2 sampai akhir)

        6. rfind(what) --> Cari dari belakang
            Sama seperti find() tapi mulai mencari dari akhir string.

            "abcabc".rfind('c')     --> 5  (c paling kanan)

        7. find_first_of(chars) & find_last_of(chars)
            Cari salah satu dari sekumpulan karakter.

            "Hello World".find_first_of("aeiou")    --> 1  (vokal pertama: e)
            "Hello World".find_last_of("aeiou")     --> 7  (vokal terakhir: o)

        8. compare(s2) --> Perbandingan detail
            Lebih powerful dari operator ==, bisa bandingkan sebagian string.

            s1.compare(s2)              --> 0 jika sama, negatif jika s1 < s2, positif jika s1 > s2
            s1.compare(pos, len, s2)    --> bandingkan sebagian s1 saja
    */

    /* MODUL 9.4 - INPUT & OUTPUT STRING
        1. cin >> vs getline()

            Cara input           Perilaku                                    Cocok untuk
            ──────────────────── ─────────────────────────────────────────── ─────────────────────────
            cin >> s             Berhenti di spasi/enter. Satu kata saja.    Satu kata tanpa spasi
            getline(cin, s)      Baca seluruh baris sampai Enter ditekan.    Kalimat / nama lengkap
            getline(cin, s, '|') Baca sampai delimiter tertentu (bukan '\n') Parsing custom input

        2. ⚠️  MASALAH KLASIK: cin campur getline()

            Jika pakai cin >> sebelum getline(), ada sisa '\n' di buffer.
            getline() akan langsung membaca '\n' itu --> hasil string KOSONG!

            Contoh masalah:
                int umur;
                string nama;
                cin >> umur;            // user ketik 20 lalu Enter
                getline(cin, nama);     // LANGSUNG LEWAT! nama jadi ""

            ✅  SOLUSI: tambahkan cin.ignore() setelah cin >>

                int umur;
                string nama;
                cin >> umur;
                cin.ignore();           // buang sisa '\n' di buffer
                getline(cin, nama);     // sekarang baca dengan benar

            Atau lebih aman:
                cin.ignore(1000, '\n'); // buang sampai 1000 char atau sampai '\n'

        3. Output String:
            cout << s               --> tampil tanpa newline
            cout << s << endl       --> tampil dengan newline
            cout << "Nama: " << s   --> dengan label
    */

    /* MODUL 9.5 - KONVERSI STRING <-> ANGKA
        1. String ke Angka (header: <string>)

            Fungsi          Konversi                    Contoh
            ─────────────── ─────────────────────────── ────────────────────────────
            stoi(s)         string --> int              stoi("42")      --> 42
            stol(s)         string --> long             stol("1000000") --> 1000000L
            stoll(s)        string --> long long        stoll("9999999999")
            stof(s)         string --> float            stof("3.14")    --> 3.14f
            stod(s)         string --> double           stod("3.14159") --> 3.14159
            stold(s)        string --> long double      stold("3.141592")

            ⚠️  Jika string tidak bisa dikonversi (misal stoi("abc")):
                --> melempar exception std::invalid_argument
                --> program CRASH jika tidak ditangkap dengan try-catch!

            Cara aman:
                try {
                    int n = stoi(inputUser);
                } catch (exception& e) {
                    cout << "Input tidak valid!" << endl;
                }

        2. Angka ke String

            to_string(42)       --> "42"
            to_string(3.14)     --> "3.140000"  (presisi default 6 desimal)
            to_string(-99)      --> "-99"

            ⚠️  to_string() untuk float/double: presisi bisa tidak sesuai harapan.
                Untuk kontrol format lebih detail --> gunakan std::ostringstream dari <sstream>

        3. Konversi antara C-string dan std::string

            --> Dari C-string ke std::string (OTOMATIS):
                string s = "Halo";          // dari string literal
                string s = cStrVariable;    // dari char*

            --> Dari std::string ke C-string (pakai .c_str()):
                const char* cs = s.c_str(); // pointer read-only ke isi string

            ⚠️  Pointer ini tidak valid lagi jika string s dimodifikasi setelah .c_str()!
    */

    /* MODUL 9.6 - OPERASI LANJUTAN & TIPS

        1. Iterasi Karakter String

            // Cara 1: Range-based for (paling modern & bersih)
            for (char c : s) { ... }

            // Cara 2: Index-based (kalau perlu index)
            for (int i = 0; i < s.size(); i++) { ... }

            // Cara 3: Iterator
            for (auto it = s.begin(); it != s.end(); it++) { ... }

        2. String Comparison - Urutan Lexicographic
            Operator <, >, <=, >= bekerja secara lexicographic (urutan kamus).
            Perbandingan karakter per karakter berdasarkan nilai ASCII.

            "apple" < "banana"  --> true  (a < b)
            "abc"   < "abd"     --> true  (c < d)
            "ABC"   < "abc"     --> true  (huruf kapital ASCII-nya lebih kecil dari kecil)

            ⚠️  Perbandingan CASE-SENSITIVE secara default!
                Untuk case-insensitive --> ubah dulu ke lowercase.

        3. Mengubah Case (pakai <algorithm> + <cctype>)

            // Semua jadi lowercase:
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            // Semua jadi UPPERCASE:
            transform(s.begin(), s.end(), s.begin(), ::toupper);

        4. Cek & Klasifikasi Karakter (dari <cctype>)

            Fungsi          Return true jika...
            ─────────────── ────────────────────────────────
            isalpha(c)      Huruf (a-z, A-Z)
            isdigit(c)      Angka (0-9)
            isalnum(c)      Huruf atau angka
            isupper(c)      Huruf kapital
            islower(c)      Huruf kecil
            isspace(c)      Whitespace (spasi, tab, newline)
            ispunct(c)      Tanda baca (! . , dll)

        5. Membalik String (dari <algorithm>)

            reverse(s.begin(), s.end());            // modifikasi di tempat
            string rev(s.rbegin(), s.rend());       // buat string baru yang dibalik

        6. Kapasitas vs Ukuran

            s.size()            --> jumlah karakter aktual
            s.length()          --> sama dengan size()
            s.capacity()        --> memori yang sudah dialokasikan (selalu >= size)
            s.reserve(n)        --> minta alokasi minimal n karakter (optimasi append berulang)
            s.shrink_to_fit()   --> kembalikan memori berlebih ke sistem

        7. Pola Umum yang Sering Dipakai

            a. Hitung kemunculan karakter
                count(s.begin(), s.end(), 'a');     // dari <algorithm>

            b. Cek apakah mengandung substring
                s.find("sub") != string::npos;      // true jika ketemu

            c. Trim spasi di kiri & kanan (tidak ada fungsi bawaan, manual):
                s.erase(0, s.find_first_not_of(' '));           // trim kiri
                s.erase(s.find_last_not_of(' ') + 1);           // trim kanan

            d. Split string berdasarkan delimiter (pakai stringstream dari <sstream>):
                stringstream ss("kata1 kata2 kata3");
                string token;
                while (ss >> token) {
                    // token berisi "kata1", lalu "kata2", lalu "kata3"
                }

        8. String sebagai Parameter Fungsi

            void f(string s)            --> pass by VALUE, buat salinan (mahal untuk string panjang)
            void f(const string& s)     --> pass by CONST REFERENCE, tidak buat salinan, tidak bisa diubah ✅ TERBAIK untuk read-only
            void f(string& s)           --> pass by REFERENCE, bisa dimodifikasi langsung

            --> Selalu gunakan const string& jika tidak perlu modifikasi!

        
        // KESALAHAN UMUM & CARA MENGHINDARINYA
            ❌  Pakai == untuk bandingkan char*
                --> == untuk char* membandingkan ALAMAT memori, bukan isi string!
                ✅  Gunakan strcmp() untuk C-string, atau konversi ke std::string dulu.

            ❌  Lupa cin.ignore() sebelum getline()
                --> getline() baca sisa '\n' dari cin >> sebelumnya --> string kosong
                ✅  Tambahkan cin.ignore() atau cin.ignore(1000,'\n') setelah cin >>

            ❌  Akses s[s.size()] atau lebih
                --> Index di luar batas --> undefined behavior (crash tak terduga)
                ✅  Gunakan s.at(i) yang melempar exception, atau selalu cek i < s.size()

            ❌  Modifikasi hasil c_str()
                --> c_str() kembalikan const char*, TIDAK boleh dimodifikasi
                --> Jika string diubah setelah c_str(), pointer lama tidak valid!
                ✅  Salin ke char[] baru jika perlu modifikasi

            ❌  Konversi sto*() tanpa try-catch
                --> stoi("abc") melempar std::invalid_argument --> program crash
                ✅  Bungkus dengan try { ... } catch (exception& e) { ... }

            ❌  Lupa #include <string>
                --> Kadang terbawa <iostream>, tapi tidak dijamin di semua compiler
                ✅  Selalu tulis #include <string> secara eksplisit

    */

// W. Pointers (Pengenalan)

    /* MODUL 10.0 - Gambaran Umum & Kenapa Pointer Penting
    
        Pointer adalah salah satu fitur paling powerful sekaligus paling
        bikin bingung di C++. Tapi tenang, kalau dipahami pelan-pelan,
        konsepnya sebenarnya tidak serumit yang dibayangkan.

        Analogi sederhana:
            Bayangkan memory komputer itu seperti deretan loker di sekolah.
            Setiap loker punya NOMOR (alamat) dan ISI (nilai yang disimpan).

            Variabel biasa = isi loker
            Pointer        = secarik kertas yang ditulis NOMOR LOKERNYA

            Jadi pointer tidak menyimpan nilai secara langsung,
            melainkan MENYIMPAN ALAMAT dari tempat nilai itu tinggal.

        Kenapa pointer penting?
            ✅ Manipulasi memory secara langsung (efisien)
            ✅ Dynamic memory allocation (alokasi memori saat runtime)
            ✅ Pass array ke function dengan efisien
            ✅ Bikin data structure kompleks (linked list, tree, dll)
            ✅ Dasar untuk memahami OOP, STL, dan banyak fitur modern C++
    */

    /* MODUL 10.1 - Memory & Addresses

        1. Bagaimana Komputer Menyimpan Data?

            Setiap variabel yang kita buat disimpan di MEMORY (RAM).
            Memory itu ibarat deretan sel, dan setiap sel punya ALAMAT unik.
            Alamat ini berupa angka heksadesimal, contoh: 0x7ffd3a2b1c08

            Visualisasi:
                Alamat      | Isi
                ------------|------
                0x1000      |  10      <-- int x = 10
                0x1004      |  20      <-- int y = 20
                0x1008      |  30      <-- int z = 30

            Catatan: int biasanya butuh 4 byte, makanya alamatnya melompat 4

        2. Operator Address-of (&)

            Operator & digunakan untuk mendapatkan ALAMAT sebuah variabel.
            Bukan simbol bitwise AND ya, beda konteks!

            Contoh:
                int x = 10;
                cout << x;      --> menampilkan nilai:  10
                cout << &x;     --> menampilkan alamat: 0x7ffd... (angka heks)

        3. Stack vs Heap

            Ada dua area memory utama yang sering kita pakai:

            a. STACK
                - Untuk variabel lokal (yang kita buat di dalam fungsi/main)
                - Ukuran terbatas (~1-8 MB tergantung sistem)
                - Otomatis dibersihkan ketika fungsi selesai
                - Pengelolaan OTOMATIS oleh compiler
                - Contoh: int x = 10; --> ada di stack

            b. HEAP
                - Untuk dynamic memory allocation (pakai new)
                - Ukuran lebih besar (dibatasi RAM)
                - TIDAK otomatis dibersihkan, programmer wajib bebaskan dengan delete
                - Pengelolaan MANUAL oleh programmer
                - Contoh: int* ptr = new int(10); --> ada di heap

            Ilustrasi:
                ┌────────────────────┐  ← Alamat tinggi
                │       STACK        │  ← Variabel lokal, tumbuh ke bawah
                │         ↓         │
                │                   │
                │         ↑         │
                │       HEAP         │  ← Dynamic allocation, tumbuh ke atas
                ├────────────────────┤
                │  Global/Static     │
                ├────────────────────┤
                │   Code (Program)   │
                └────────────────────┘  ← Alamat rendah
    */

    /* MODUL 10.2 - Pointer Basics

        1. Apa itu Pointer?

            Pointer adalah variabel yang MENYIMPAN ALAMAT MEMORY dari variabel lain.
            Pointer tidak menyimpan nilai langsung, tapi menyimpan "dimana nilainya berada".

        2. Deklarasi Pointer

            Syntax:
                tipe_data* nama_pointer;

            Contoh:
                int*    ptr;        --> pointer ke int
                double* dPtr;       --> pointer ke double
                char*   cPtr;       --> pointer ke char
                string* sPtr;       --> pointer ke string

            Catatan penulisan (semua valid, konvensi berbeda-beda):
                int* ptr;       --> gaya C++ (bintang menempel ke tipe) ← DISARANKAN
                int *ptr;       --> gaya C (bintang menempel ke nama)
                int * ptr;      --> gaya campuran

            ⚠️ JEBAKAN:
                int* a, b;
                --> a adalah pointer, tapi b BUKAN pointer (b adalah int biasa)!
                Kalau mau dua pointer: int* a; int* b;

        3. Inisialisasi Pointer

            Ada dua cara mengisi pointer:

            a. Arahkan ke variabel yang sudah ada (pakai &)
                int angka = 42;
                int* ptr = &angka;  --> ptr sekarang menyimpan ALAMAT angka

            b. Null Pointer (pointer tidak menunjuk ke mana-mana)
                int* ptr = nullptr; --> cara modern C++11 (LEBIH BAIK!)
                int* ptr = NULL;    --> cara lama (C-style)
                int* ptr = 0;       --> juga bisa, tapi kurang eksplisit

            ⚠️ BAHAYA: Uninitialized pointer (pointer liar / wild pointer)
                int* ptr;           --> BAHAYA! Nilai ptr tidak jelas (garbage)
                *ptr = 10;          --> CRASH atau undefined behavior!
                Selalu inisialisasi pointer!

        4. Dereferencing (*) - Mengakses Nilai yang Ditunjuk

            Operator * digunakan untuk MENGAKSES atau MENGUBAH nilai
            yang berada di alamat yang disimpan pointer.

            Contoh:
                int angka = 42;
                int* ptr = &angka;

                cout << ptr;    --> menampilkan ALAMAT (misal: 0x7ffd...)
                cout << *ptr;   --> menampilkan NILAI yang di alamat itu: 42

            * di sini = "pergi ke alamat itu, ambil nilainya"
            Istilahnya: DEREFERENCE

            Modifikasi via pointer:
                *ptr = 99;      --> mengubah nilai angka menjadi 99!
                cout << angka;  --> output: 99 (ikut berubah!)

        5. Hubungan Variabel, Alamat, dan Pointer

            Visualisasi lengkap:

                int angka = 42;         int* ptr = &angka;
                                    
                Nama:    angka           ptr
                Nilai:   42              0x1000  (alamat angka)
                Alamat:  0x1000          0x2000  (alamat ptr sendiri)

                cout << angka;      --> 42        (nilai angka)
                cout << &angka;     --> 0x1000    (alamat angka)
                cout << ptr;        --> 0x1000    (isi ptr = alamat angka)
                cout << *ptr;       --> 42        (nilai di alamat 0x1000)
                cout << &ptr;       --> 0x2000    (alamat ptr itu sendiri)

        6. Null Pointer & Safety

            nullptr adalah pointer yang sengaja tidak menunjuk ke mana-mana.
            Gunakan ini sebagai "default" pointer sebelum diarahkan ke sesuatu.

            Cara cek sebelum gunakan:
                int* ptr = nullptr;

                if (ptr != nullptr) {
                    cout << *ptr;   // aman, ptr sudah punya alamat valid
                } else {
                    cout << "Pointer belum diinisialisasi!";
                }

            ❌ JANGAN deref null pointer:
                int* ptr = nullptr;
                cout << *ptr;   --> CRASH! (Segmentation Fault)
    */

    /* MODUL 10.3 - Pointer Arithmetic

        1. Konsep Pointer Arithmetic

            Pointer bisa ditambah atau dikurangi dengan angka integer.
            Hasilnya bukan tambah/kurang biasa, tapi melompat sebanyak
            (n * sizeof(tipe_data)) byte di memory.

            Jadi pointer arithmetic sadar tipe data!

        2. Operasi yang Tersedia

            Operasi         Contoh          Keterangan
            ────────────── ─────────────── ────────────────────────────────────────
            ptr + n        ptr + 1         Maju n elemen (n * sizeof(tipe))
            ptr - n        ptr - 2         Mundur n elemen
            ptr++          ptr++           Maju 1 elemen (sama dengan ptr + 1)
            ptr--          ptr--           Mundur 1 elemen
            ptr1 - ptr2    p2 - p1         Selisih posisi (dalam satuan elemen, bukan byte)
            ptr1 == ptr2                   Perbandingan apakah menunjuk alamat sama
            ptr1 < ptr2                    Perbandingan posisi (cocok untuk array)

        3. Visualisasi Pointer Arithmetic

            int arr[5] = {10, 20, 30, 40, 50};
            int* ptr = arr;     --> ptr menunjuk ke arr[0]

            Memory layout (tiap int = 4 byte):

            Alamat:  [1000] [1004] [1008] [1012] [1016]
            Nilai:   [  10] [  20] [  30] [  40] [  50]
            Index:   [   0] [   1] [   2] [   3] [   4]

            ptr       = 1000   --> menunjuk ke elemen 0
            ptr + 1   = 1004   --> menunjuk ke elemen 1 (bukan 1001!)
            ptr + 2   = 1008   --> menunjuk ke elemen 2
            *(ptr + 2) = 30    --> nilai di elemen 2

        4. Increment & Decrement Pointer

            int arr[] = {10, 20, 30};
            int* ptr = arr;         --> menunjuk ke arr[0]

            ptr++;                  --> sekarang menunjuk ke arr[1]
            cout << *ptr;           --> output: 20

            ptr++;                  --> sekarang menunjuk ke arr[2]
            cout << *ptr;           --> output: 30

            ptr--;                  --> kembali ke arr[1]
            cout << *ptr;           --> output: 20

        5. Selisih Dua Pointer

            int arr[5] = {10, 20, 30, 40, 50};
            int* awal = &arr[0];
            int* akhir = &arr[4];

            int selisih = akhir - awal;     --> selisih = 4 (bukan 16 byte!)
            Hasilnya dalam satuan ELEMEN, bukan byte.

        6. Perbandingan Pointer

            Pointer bisa dibandingkan dengan ==, !=, <, >, <=, >=
            Ini berguna untuk loop traversal array.

            int arr[5] = {10, 20, 30, 40, 50};
            int* start = arr;
            int* end   = arr + 5;    --> satu posisi di luar elemen terakhir

            // Loop traversal pakai pointer
            for (int* p = start; p != end; p++) {
                cout << *p << " ";
            }
            // Output: 10 20 30 40 50

        7. ⚠️ Batasan & Bahaya Pointer Arithmetic

            ❌ JANGAN keluar batas array:
                int arr[3] = {1, 2, 3};
                int* ptr = arr + 10;    --> out of bounds, undefined behavior!
                cout << *ptr;           --> CRASH atau nilai sampah!

            ❌ JANGAN arithmetic pada pointer yang tidak dalam array yang sama:
                int a = 10, b = 20;
                int* p1 = &a;
                int* p2 = &b;
                int diff = p2 - p1;     --> undefined behavior! (beda variabel)

            ✅ Pointer arithmetic AMAN hanya dalam batas array yang sama.
    */

    /* MODUL 10.4 - Pointers & Arrays

        1. Hubungan Erat Pointer dan Array

            Di C++, nama array ADALAH pointer ke elemen pertamanya.
            Ini bukan analogi, ini benar-benar sama!

            int arr[5] = {10, 20, 30, 40, 50};

            arr         --> alamat arr[0]   (sama dengan &arr[0])
            *arr        --> nilai arr[0]    = 10
            *(arr + 1)  --> nilai arr[1]    = 20
            *(arr + i)  --> nilai arr[i]    (cara pointer mengakses elemen ke-i)

            // Ini SAMA SAJA:
            arr[2]      == *(arr + 2)   == *(2 + arr)   == 2[arr]   --> semua = 30

        2. Array Decay

            Ketika array dilewatkan ke function sebagai parameter,
            array "berubah" menjadi pointer ke elemen pertamanya.
            Proses ini disebut ARRAY DECAY.

            Konsekuensi:
            - sizeof() di dalam function tidak bisa hitung ukuran array
            - Itulah kenapa wajib kirim SIZE sebagai parameter terpisah
                (sudah dibahas di modul Array & Function Bab U)

            void fungsi(int arr[], int size)    // arr[] = int* arr di balik layar
            void fungsi(int* arr, int size)     // sama saja

        3. Perbedaan Pointer dan Array

            Meski mirip, ada perbedaan penting:

            Aspek               Pointer                     Array
            ─────────────────── ─────────────────────────── ────────────────────────────
            Deklarasi           int* ptr;                   int arr[5];
            Reassignment        ptr = arr2; (bisa)          arr = arr2; (❌ TIDAK BISA)
            sizeof()            sizeof(ptr) = 4/8 byte      sizeof(arr) = total byte array
            Arithmetic          ptr++; (bisa)               arr++; (❌ TIDAK BISA)
            Isi                 Menyimpan alamat             Array itu sendiri

            Intinya:
            - Array adalah blok memory yang fixed (tidak bisa dipindah)
            - Pointer adalah variabel yang menyimpan alamat (bisa diubah)

        4. Pointer Indexing

            Setelah pointer diarahkan ke array, bisa pakai notasi [] juga:

            int arr[5] = {10, 20, 30, 40, 50};
            int* ptr = arr;

            ptr[0]  --> 10  (sama dengan *ptr)
            ptr[2]  --> 30  (sama dengan *(ptr + 2))
            ptr[4]  --> 50

        5. Iterasi Array dengan Pointer

            Ada dua cara iterasi, hasilnya sama:

            // Cara 1: Index biasa
            for (int i = 0; i < 5; i++) {
                cout << arr[i] << " ";
            }

            // Cara 2: Pointer arithmetic
            for (int* p = arr; p < arr + 5; p++) {
                cout << *p << " ";
            }

            // Cara 3: Pointer dengan index
            int* ptr = arr;
            for (int i = 0; i < 5; i++) {
                cout << ptr[i] << " ";
            }

        6. Pointer ke String (C-Style)

            char nama[] = "Gega";
            char* ptr   = nama;         --> ptr menunjuk ke 'G'

            cout << ptr;                --> Output: Gega (cout baca sampai \0)
            cout << *ptr;               --> Output: G (satu karakter)
            ptr++;
            cout << *ptr;               --> Output: e (karakter berikutnya)
            cout << ptr;                --> Output: ega (mulai dari posisi ptr sekarang)

        7. const dengan Pointer - Ada 3 Kombinasi!

            Ini sering membingungkan, tapi penting:

            a. Pointer ke const (tidak bisa ubah nilai yang ditunjuk):
                const int* ptr = &angka;
                *ptr = 99;      --> ❌ ERROR! Nilai tidak bisa diubah
                ptr = &lain;    --> ✅ OK, pointer-nya bisa diubah

            b. Const pointer (alamat yang disimpan tidak bisa diubah):
                int* const ptr = &angka;
                *ptr = 99;      --> ✅ OK, nilai bisa diubah
                ptr = &lain;    --> ❌ ERROR! Pointer tidak bisa diubah

            c. Const pointer ke const (keduanya tidak bisa diubah):
                const int* const ptr = &angka;
                *ptr = 99;      --> ❌ ERROR!
                ptr = &lain;    --> ❌ ERROR!

            Trik baca: baca dari kanan ke kiri.
                "const int* ptr"       --> ptr adalah pointer (*) ke int yang const
                "int* const ptr"       --> ptr adalah const pointer (*const) ke int
                "const int* const ptr" --> ptr adalah const pointer ke int yang const

            Penggunaan umum:
                void tampilArray(const int* arr, int size) {
                    // const int* arr artinya: kita tidak akan ubah isinya
                    // ini cara aman pass array ke function read-only
                }
    */

// X. References (Referensi)

    /* MODUL 11.0 - Gambaran Umum & Kenapa Reference Penting

        Kalau Pointer itu seperti "secarik kertas yang ditulis NOMOR LOKER",
        maka Reference itu seperti "memberikan NAMA LAIN / ALIAS ke loker itu".

        Analogi sederhana:
            Bayangkan kamu punya teman bernama "Muhammad Farhan Hidayatullah",
            tapi sehari-hari dipanggil "Gega". Keduanya merujuk ke ORANG YANG SAMA.
            Ubah rambutnya? Berubah di keduanya. Karena memang orangnya sama!

            Variabel asli = Muhammad Farhan Hidayatullah (nama panjang)
            Reference     = Gega (alias/panggilan, merujuk ke orang yang sama)

        Kenapa reference penting?
            ✅ Lebih simpel & aman daripada pointer untuk banyak kasus
            ✅ Wajib diinisialisasi saat deklarasi (tidak bisa null)
            ✅ Tidak perlu dereference (*) untuk akses nilai
            ✅ Syntax lebih bersih, seperti variabel biasa
            ✅ Dasar untuk memahami pass by reference di function
    */

    /* MODUL 11.1 - Reference Basics

        1. Apa itu Reference?

            Reference adalah ALIAS (nama lain) untuk variabel yang sudah ada.
            Bukan salinan, bukan pointer — tapi benar-benar NAMA LAIN yang
            merujuk ke LOKASI MEMORY yang SAMA.

            Jadi apapun yang dilakukan pada reference, variabel aslinya IKUT BERUBAH.

        2. Cara Deklarasi Reference

            Syntax:
                tipe_data& namaReference = variabelAsli;

            Contoh:
                int angka  = 10;
                int& ref   = angka;     --> ref adalah alias dari angka

                cout << angka;  --> 10
                cout << ref;    --> 10  (sama!)

                ref = 99;               --> mengubah via reference
                cout << angka;  --> 99  (angka IKUT BERUBAH!)

        3. WAJIB Diinisialisasi!

            Reference HARUS langsung diarahkan ke variabel saat deklarasi.
            Tidak bisa dibiarkan kosong seperti pointer!

                int& ref;               --> ❌ ERROR! Reference tanpa init
                int& ref = angka;       --> ✅ OK

            Dan setelah diinisialisasi, reference TIDAK BISA diarahkan ulang
            ke variabel lain (berbeda dengan pointer yang bisa diubah).

        4. Reference vs Pointer - Perbandingan Singkat

            Aspek               Reference                   Pointer
            ─────────────────── ─────────────────────────── ────────────────────────────
            Syntax deklarasi    int& ref = angka;           int* ptr = &angka;
            Inisialisasi        WAJIB saat deklarasi         Boleh setelah deklarasi
            Null                TIDAK BISA null              Bisa nullptr
            Reassignment        TIDAK BISA ganti target      Bisa ganti target (ptr = &lain)
            Akses nilai         ref  (langsung)              *ptr  (perlu dereference)
            Alamat              &ref = &angka (sama!)        ptr = alamat yang disimpan
            Keamanan            Lebih aman                   Lebih rawan bug
            Kegunaan utama      Alias, pass by ref           Dynamic memory, array, dll

        5. Reference BUKAN Variabel Baru

            Reference tidak membuat salinan variabel.
            Reference dan variabel asli menunjuk ke ALAMAT MEMORY yang SAMA.

            int angka = 10;
            int& ref  = angka;

            &angka == &ref      --> ✅ TRUE! Alamatnya SAMA persis!

        6. Const Reference

            Reference ke nilai const — tidak boleh diubah via reference ini.

                int angka = 42;
                const int& cref = angka;

                cout << cref;   --> ✅ OK, bisa baca
                cref = 99;      --> ❌ ERROR! Tidak bisa ubah via const reference

            Kegunaan const reference:
                - Baca saja tanpa modifikasi
                - Terima literal atau ekspresi (const ref bisa bind ke temporary!)

                const int& cr = 5 + 3;  --> ✅ OK! (temporary value 8)
                int& r = 5 + 3;         --> ❌ ERROR! Non-const ref tidak bisa bind ke temporary
    */

    /* MODUL 11.2 - Pass by Reference

        1. Mengapa Pass by Reference?

            Secara default, function menerima SALINAN nilai (pass by value).
            Artinya perubahan di dalam function TIDAK mempengaruhi variabel asli.

            Dengan pass by reference, function menerima ALIAS dari variabel asli.
            Perubahan di dalam function LANGSUNG mempengaruhi variabel asli!

        2. Syntax Pass by Reference

            // Pass by VALUE (default) - salinan, asli tidak berubah
            void fungsiValue(int x) {
                x = 99;     // hanya ubah salinan lokal
            }

            // Pass by REFERENCE - alias, asli IKUT BERUBAH
            void fungsiRef(int& x) {
                x = 99;     // mengubah variabel asli!
            }

            int a = 10;
            fungsiValue(a);     --> a tetap 10
            fungsiRef(a);       --> a berubah jadi 99!

        3. Kapan Pakai Pass by Reference?

            ✅ Saat function perlu MENGUBAH nilai variabel pemanggil
            ✅ Saat "mengembalikan" lebih dari satu nilai (multiple return)
            ✅ Saat passing objek besar agar tidak membuat salinan (hemat memory)

            Contoh multiple return via reference:
                void hitungPersegi(int sisi, int& keliling, int& luas) {
                    keliling = 4 * sisi;
                    luas     = sisi * sisi;
                }

        4. Const Reference sebagai Parameter (PALING UMUM!)

            Digunakan saat function hanya MEMBACA nilai, tidak mengubahnya.
            Lebih efisien daripada pass by value untuk tipe data besar (string, vector, dll).

            void tampilkan(const string& nama) {
                cout << nama;   // baca saja, tidak modifikasi
            }

            Keuntungan const reference:
                ✅ Tidak membuat salinan (efisien)
                ✅ Tidak bisa diubah (aman)
                ✅ Bisa menerima literal / temporary

            Perbandingan cara pass parameter:

            void f(string s)          --> COPY, mahal untuk string panjang
            void f(string& s)         --> REFERENCE, bisa ubah, tidak bisa terima literal
            void f(const string& s)   --> CONST REF, efisien + aman ← PALING DIREKOMENDASIKAN untuk read-only

        5. Swap Classic - Use Case Populer Pass by Reference

            // SALAH - tidak swap aslinya!
            void salahSwap(int a, int b) {
                int temp = a;
                a = b;
                b = temp;
            }

            // BENAR - swap aslinya!
            void swap(int& a, int& b) {
                int temp = a;
                a = b;
                b = temp;
            }
    */

    /* MODUL 11.3 - Reference vs Pointer - Kapan Pakai Yang Mana?

        1. GUNAKAN REFERENCE ketika:

            ✅ Function perlu ubah argumen (pass by ref)
            ✅ Mau buat alias yang lebih readable
            ✅ Passing parameter besar yang tidak perlu diubah (const ref)
            ✅ Tidak butuh kemampuan pointer seperti nullptr atau reassignment
            ✅ Range-based for loop dengan objek besar (for (auto& x : v))

        2. GUNAKAN POINTER ketika:

            ✅ Perlu nullable (bisa nullptr = "tidak ada")
            ✅ Perlu reassignment (arahkan ke variabel berbeda)
            ✅ Dynamic memory allocation (new / delete)
            ✅ Array C-style dan pointer arithmetic
            ✅ Implementasi data structure (linked list, tree, dll)

        3. Tabel Keputusan Cepat

            Butuh ini?              Pakai      Alasan
            ─────────────────────── ────────── ─────────────────────────────────────
            Alias sederhana         Reference  Syntax bersih, tidak bisa null
            Nullable                Pointer    ptr = nullptr memungkinkan
            Ubah target nanti       Pointer    Bisa arahkan ulang
            Pass arg & ubahnya      Reference  Syntax lebih simpel
            Pass arg, hanya baca    const ref  Efisien + aman
            Dynamic memory          Pointer    new / delete hanya bisa lewat pointer
            Iterasi manual array    Pointer    Pointer arithmetic
            Return dua nilai        Reference  Lebih idiomatik

        4. Kode Aturan Praktis (Rules of Thumb)

            "Gunakan reference secara default.
            Gunakan pointer hanya kalau reference tidak bisa melakukan tugasnya."
            - Bjarne Stroustrup (pencipta C++)

            "Prefer references over pointers in C++ code."
            - Google C++ Style Guide

        5. Reference ke Reference (TIDAK ADA!)

            int angka = 10;
            int& ref  = angka;
            int& ref2 = ref;    --> bukan ref ke ref, ini ref ke angka juga!

        6. Pointer ke Pointer (ADA, dan berguna)

            int  angka = 10;
            int* ptr   = &angka;
            int** pptr = &ptr;      --> pointer ke pointer

            **pptr = 99;            --> mengubah angka via dua level pointer
    */

// Y. Struct 

    /* MODUL 12.0 - Struct Basics

        1. Apa itu Struct?

            Struct (Structure) adalah tipe data BUATAN SENDIRI yang mengelompokkan
            beberapa variabel dengan tipe berbeda-beda menjadi SATU KESATUAN.

            Analogi dunia nyata:
                Bayangkan sebuah KTP.
                KTP punya banyak info: nama, NIK, tempat lahir, tanggal lahir, dll.
                Semua info itu milik SATU ORANG yang sama.
                Struct ibarat "cetakan KTP" — template yang mendefinisikan info apa saja
                yang dimiliki setiap orang.

            Sebelum pakai struct (ribet!):
                string nama1      = "Budi";
                int    umur1      = 20;
                double ipk1       = 3.85;

                string nama2      = "Sari";
                int    umur2      = 21;
                double ipk2       = 3.90;
                // → Untuk 100 mahasiswa? Mimpi buruk!

            Dengan struct (rapi!):
                Mahasiswa mhs1    = {"Budi", 20, 3.85};
                Mahasiswa mhs2    = {"Sari", 21, 3.90};
                // → Mudah, terstruktur, dan scalable!

        2. Syntax Deklarasi Struct

            struct NamaStruct {
                tipe_data member1;
                tipe_data member2;
                tipe_data member3;
                // ... dan seterusnya
            };  ← jangan lupa titik koma di sini!

            Contoh:
                struct Mahasiswa {
                    string nama;
                    int    umur;
                    double ipk;
                };

            Setelah dideklarasi, "Mahasiswa" bisa digunakan seperti int, string, dll.
            Ini disebut USER-DEFINED TYPE (tipe yang kita buat sendiri).

        3. Membuat Objek / Variable Struct

            Setelah struct dideklarasikan, buat "instance" (variabel dari tipe itu):

                Mahasiswa mhs1;         // Deklarasi saja (member belum terisi)
                Mahasiswa mhs2 = {"Budi", 20, 3.85};  // Inisialisasi langsung

        4. Mengakses Member — Dot Operator ( . )

            Gunakan titik (.) untuk akses member:

                mhs1.nama = "Sari";
                mhs1.umur = 21;
                mhs1.ipk  = 3.90;

                cout << mhs1.nama;  // Output: Sari
                cout << mhs1.ipk;   // Output: 3.9

        5. Cara Inisialisasi Struct

            a. Satu per satu:
                Mahasiswa m;
                m.nama = "Budi";
                m.umur = 20;
                m.ipk  = 3.85;

            b. Aggregate initialization (urutan harus sesuai deklarasi):
                Mahasiswa m = {"Budi", 20, 3.85};

            c. Designated initialization (C++20, nama member explicit):
                Mahasiswa m = {.nama = "Budi", .umur = 20, .ipk = 3.85};

            d. Default member values (C++11 ke atas):
                struct Mahasiswa {
                    string nama  = "Unknown";
                    int    umur  = 0;
                    double ipk   = 0.0;
                };
                Mahasiswa m;    // nama = "Unknown", umur = 0, ipk = 0.0

        6. Struct di Memory

            Struct menyimpan member secara BERURUTAN di memory:

            Mahasiswa m = {"Budi", 20, 3.85};

            Memory layout (konseptual):
            ┌──────────────────┬───────────┬──────────────────┐
            │  nama ("Budi")   │  umur(20) │   ipk (3.85)     │
            └──────────────────┴───────────┴──────────────────┘
            Semua dalam satu blok memory yang berdekatan.
    */

    /* MODUL 12.1 - Struct Operations

        1. Passing Struct ke Function

            Seperti tipe data biasa, struct bisa dipass ke function.
            Ada tiga cara:

            a. Pass by VALUE (copy dibuat — perubahan TIDAK mengubah asli):
                void tampilkan(Mahasiswa m) { ... }

            b. Pass by REFERENCE (alias — perubahan MENGUBAH asli):
                void updateIPK(Mahasiswa& m, double ipkBaru) { ... }

            c. Pass by CONST REFERENCE (baca saja, efisien, aman):
                void tampilkan(const Mahasiswa& m) { ... }

            ⭐ BEST PRACTICE:
                - Hanya READ   → const Mahasiswa& m   (efisien + aman)
                - Perlu MODIFY → Mahasiswa& m
                - Struct kecil → boleh by value (misal: Titik, WaktuJam)

        2. Returning Struct dari Function

            Function bisa mengembalikan struct seperti tipe data biasa.

                Mahasiswa buatMahasiswa(string nama, int umur, double ipk) {
                    Mahasiswa m;
                    m.nama = nama;
                    m.umur = umur;
                    m.ipk  = ipk;
                    return m;
                }

                Mahasiswa mhs = buatMahasiswa("Budi", 20, 3.85);

        3. Array of Structs

            Bisa membuat array yang setiap elemennya adalah struct!

                Mahasiswa kelas[30];    // 30 mahasiswa
                kelas[0].nama = "Budi";
                kelas[0].ipk  = 3.85;

            Ini sangat powerful untuk menyimpan banyak data terstruktur.

        4. Nested Structs

            Struct bisa punya member yang tipenya struct juga!

                struct Alamat {
                    string jalan;
                    string kota;
                    string provinsi;
                };

                struct Pegawai {
                    string nama;
                    int    gaji;
                    Alamat alamat;   ← member berupa struct lain!
                };

                Pegawai p;
                p.nama            = "Budi";
                p.alamat.kota     = "Yogyakarta";
                p.alamat.provinsi = "DIY";

        5. Struct dan sizeof()

            sizeof(struct) = jumlah bytes semua membernya
            (+ kemungkinan padding untuk alignment di memory)

                sizeof(Titik) → biasanya 16 bytes (2 × double 8 bytes)
    */

    /* MODUL 12.2 - Struct vs Class (Preview)

        1. Perbedaan Teknis: Default Access

            Secara teknis, perbedaan SATU-SATUNYA antara struct dan class di C++
            adalah DEFAULT ACCESS SPECIFIER:

                struct → default: PUBLIC  (semua bisa akses member dari luar)
                class  → default: PRIVATE (tidak bisa akses member dari luar)

            Contoh:

                struct PointS {
                    int x;      // ← otomatis PUBLIC
                    int y;
                };

                class PointC {
                    int x;      // ← otomatis PRIVATE (tidak bisa diakses langsung!)
                    int y;
                };

                PointS ps;
                ps.x = 5;   // ✅ OK — struct, public by default

                PointC pc;
                pc.x = 5;   // ❌ ERROR — class, private by default

        2. Konvensi Penggunaan (di dunia nyata):

            Programmer C++ umumnya pakai konvensi tidak tertulis ini:

            STRUCT digunakan untuk:
                ✅ Data sederhana tanpa behaviour (Plain Old Data / POD)
                ✅ Kumpulan nilai yang saling berkaitan
                ✅ Data transfer objects (DTO)
                ✅ Tidak butuh encapsulation
                ✅ Contoh: Titik, Warna, Ukuran, Record data

            CLASS digunakan untuk:
                ✅ Objek dengan state (data) DAN behaviour (fungsi)
                ✅ Butuh encapsulation (sembunyikan detail)
                ✅ Inheritance / polymorphism
                ✅ Invariants yang perlu dijaga
                ✅ Contoh: BankAccount, Mahasiswa dengan metode, Car

        3. Struct dengan Member Function

            Di C++, struct BISA punya member function (berbeda dari C!).
            Tapi biasanya tidak perlu — kalau sudah kompleks, pakai class.

                struct Persegi {
                    double sisi;

                    double luas() {
                        return sisi * sisi;
                    }

                    double keliling() {
                        return 4 * sisi;
                    }
                };

                Persegi p = {5.0};
                cout << p.luas();       // 25
                cout << p.keliling();   // 20

        4. C-Style Struct vs C++ Struct

            C (lama):
                struct Titik { int x; int y; };
                struct Titik p1;        // harus tulis 'struct' lagi!
                p1.x = 3;

            C++ (modern):
                struct Titik { int x; int y; };
                Titik p1;               // tidak perlu kata 'struct' lagi
                p1.x = 3;

        5. Typedef + Struct (C-style, sudah jarang di C++)

            // Gaya lama C:
            typedef struct {
                int x;
                int y;
            } Titik;

            // Di C++ tidak perlu typedef — langsung:
            struct Titik {
                int x;
                int y;
            };
            Titik p;    // langsung bisa!

        6. Ringkasan

            Fitur                   struct          class
            ─────────────────────── ─────────────── ───────────────
            Default access          public          private
            Bisa member function    ✅ Ya           ✅ Ya
            Bisa inheritance        ✅ Ya           ✅ Ya
            Konvensi penggunaan     Data sederhana  Objek kompleks
            Kapan dipilih           POD / DTO       Encapsulation
    */

// Z. Enumerations

    /* MODUL 13.0 - Enum (Unscoped) — Basic Enum

        1. Apa itu Enum?

            Enum (Enumeration) adalah tipe data buatan sendiri yang berisi
            sekumpulan KONSTANTA BERNAMA (named constants).

            Analogi dunia nyata:
                Bayangkan lampu lalu lintas — hanya punya 3 kemungkinan:
                MERAH, KUNING, HIJAU. Tidak ada nilai lain yang valid!
                Enum sempurna untuk situasi seperti ini.

            Tanpa Enum (tidak jelas, rawan bug):
                int status = 1;     // 1 itu apa? Aktif? Merah? Benar?
                if (status == 1) ... // magic number, susah dibaca

            Dengan Enum (jelas dan aman):
                enum Status { AKTIF, NONAKTIF, PENDING };
                Status s = AKTIF;
                if (s == AKTIF) ...  // sangat readable!

        2. Syntax Deklarasi Enum

            enum NamaEnum {
                NILAI_1,    // otomatis = 0
                NILAI_2,    // otomatis = 1
                NILAI_3,    // otomatis = 2
                ...
            };

            Contoh:
                enum Hari {
                    SENIN,      // = 0
                    SELASA,     // = 1
                    RABU,       // = 2
                    KAMIS,      // = 3
                    JUMAT,      // = 4
                    SABTU,      // = 5
                    MINGGU      // = 6
                };

            Variabel dari tipe enum:
                Hari hari1 = SENIN;
                Hari hari2 = JUMAT;

        3. Nilai Default dan Custom

            Secara default, nilai dimulai dari 0 dan naik +1 tiap elemen.
            Tapi bisa dikustom:

                enum HttpStatus {
                    OK          = 200,
                    NOT_FOUND   = 404,
                    SERVER_ERROR= 500
                };

                enum Planet {
                    MERKURIUS = 1,
                    VENUS,          // = 2 (otomatis +1 dari sebelumnya)
                    BUMI,           // = 3
                    MARS,           // = 4
                    JUPITER = 100,  // custom lagi
                    SATURNUS        // = 101
                };

        4. Implicit Conversion ke int

            Enum (unscoped) OTOMATIS bisa diconvert ke int:

                enum Warna { MERAH, HIJAU, BIRU };
                Warna w = HIJAU;

                int angka = w;              // ✅ OK — implicit conversion
                cout << w;                  // Output: 1 (nilai int-nya)
                cout << (w == 1);           // ✅ bisa dibandingkan dengan int

            Tapi sebaliknya TIDAK otomatis (int ke enum):
                Warna w2 = 2;               // ❌ ERROR di C++
                Warna w3 = (Warna)2;        // ✅ perlu explicit cast
                Warna w4 = static_cast<Warna>(2);  // ✅ C++ style cast

        5. Enum dalam Switch-Case (Use Case Favorit!)

            Enum sangat cocok dipakai bersama switch-case:

                enum Musim { HUJAN, KEMARAU, PANCAROBA };
                Musim m = HUJAN;

                switch (m) {
                    case HUJAN:    cout << "Bawa payung!"; break;
                    case KEMARAU:  cout << "Pakai sunscreen!"; break;
                    case PANCAROBA:cout << "Waspada cuaca!"; break;
                }

        6. Masalah Unscoped Enum

            Karena enum (unscoped) nama-namanya masuk ke scope yang sama,
            bisa terjadi KONFLIK NAMA:

                enum Arah   { UTARA, SELATAN, TIMUR, BARAT };
                enum Tombol { KIRI, KANAN, ATAS, BAWAH };   // OK

                // Masalah kalau nama sama:
                enum Warna1 { MERAH, HIJAU };
                enum Warna2 { MERAH, BIRU };  // ❌ ERROR! MERAH sudah ada!

            Solusi: pakai enum class (lihat 13.2)

        7. Typedef Enum (C-style, jarang dipakai di C++ modern)

                // C-style:
                typedef enum { JAN=1, FEB, MAR } Bulan;

                // C++ (tidak perlu typedef):
                enum Bulan { JAN=1, FEB, MAR };
                Bulan b = JAN;
    */

    /* MODUL 13.1 - Enum Class (Scoped Enum) — Modern C++

        1. Apa itu Enum Class?

            Diperkenalkan di C++11, enum class adalah versi LEBIH AMAN
            dan lebih KETAT dari enum biasa.

            Perbedaan utama:
                - Nama enum tersimpan dalam SCOPE sendiri (tidak bocor ke luar)
                - TIDAK ada implicit conversion ke int
                - Lebih type-safe

        2. Syntax

            enum class NamaEnum {
                NILAI_1,
                NILAI_2,
                NILAI_3
            };

            Akses member WAJIB pakai nama enum + :: (scope resolution):

                enum class Warna { MERAH, HIJAU, BIRU };

                Warna w = Warna::HIJAU;     // ✅ harus tulis Warna::
                // Warna w = HIJAU;         // ❌ ERROR! Tidak bisa langsung

        3. Tidak Ada Implicit Conversion

            enum class Status { AKTIF, NONAKTIF };
            Status s = Status::AKTIF;

            int x = s;                      // ❌ ERROR! Tidak bisa implicit
            int x = (int)s;                 // ✅ explicit C-cast
            int x = static_cast<int>(s);    // ✅ C++ style (direkomendasikan)

            Ini justru FITUR, bukan bug — mencegah penggunaan salah!

        4. Tidak Ada Konflik Nama

            Karena tersimpan dalam scope sendiri:

                enum class Arah   { UTARA, SELATAN };
                enum class Tombol { UTARA, SELATAN };   // ✅ OK! Tidak konflik

                Arah a   = Arah::UTARA;     // jelas milik Arah
                Tombol t = Tombol::UTARA;   // jelas milik Tombol

        5. Underlying Type (Tipe Dasar)

            Secara default, nilai disimpan sebagai int.
            Bisa diubah ke tipe lain untuk hemat memory atau keperluan khusus:

                enum class Bulan : unsigned char {  // hanya 1 byte!
                    JAN = 1, FEB, MAR, APR,
                    MEI, JUN, JUL, AGU,
                    SEP, OKT, NOV, DES
                };

                enum class KodeError : long long {  // butuh nilai besar
                    OK = 0,
                    FATAL = 9999999999LL
                };

        6. Enum Class dalam Switch-Case

                enum class Level { MUDAH, SEDANG, SULIT, EXPERT };
                Level l = Level::SULIT;

                switch (l) {
                    case Level::MUDAH:  cout << "Untuk pemula"; break;
                    case Level::SEDANG: cout << "Lumayan"; break;
                    case Level::SULIT:  cout << "Tantangan"; break;
                    case Level::EXPERT: cout << "Pro level!"; break;
                }

        7. Membandingkan Enum Class

                enum class Nilai { A, B, C, D, E };
                Nilai n = Nilai::B;

                if (n == Nilai::A) cout << "Sempurna!";
                if (n >= Nilai::C) cout << "Perlu belajar lebih";
                // ✅ Operator == dan != langsung bisa
                // ✅ Operator <, >, <=, >= juga bisa

        8. Perbandingan Enum vs Enum Class

            Fitur                   enum (unscoped)     enum class (scoped)
            ──────────────────────  ─────────────────── ──────────────────────
            Scope nama              Global (bocor)      Tersimpan dalam enum
            Akses member            MERAH               Warna::MERAH
            Implicit ke int         ✅ Ya               ❌ Tidak
            Konflik nama            Bisa terjadi        Tidak bisa terjadi
            Type safety             Rendah              Tinggi
            Direkomendasikan        Kode lama/C         Kode C++ modern
            C++ version             Sejak awal          C++11+
    */

// AA. File I/O

    /* MODUL 14.0 - Reading Files (ifstream)

        1. Apa itu File I/O?

            Selama ini semua data program kita HILANG setelah program selesai.
            File I/O memungkinkan program:
                ✅ MENYIMPAN data ke file (persisten!)
                ✅ MEMBACA data dari file
                ✅ Komunikasi antar program via file

            Analogi:
                cin/cout  = ngobrol langsung (sementara)
                File I/O  = tulis/baca di buku catatan (permanen)

        2. Header yang Dibutuhkan

            #include <fstream>      // file stream utama
            #include <sstream>      // string stream (bonus)

            Tiga class utama:
                ifstream    — input  file stream (MEMBACA file)
                ofstream    — output file stream (MENULIS file)
                fstream     — input + output (baca DAN tulis)

        3. Membuka File — ifstream

            Cara 1: Konstruktor langsung
                ifstream file("nama_file.txt");

            Cara 2: open() terpisah
                ifstream file;
                file.open("nama_file.txt");

            ⚠️ Selalu cek apakah file berhasil dibuka!
                if (!file.is_open()) {
                    cerr << "Gagal buka file!" << endl;
                    return;
                }
                // atau:
                if (!file) { ... }   // sama saja

        4. Membaca File

            a. Kata per kata (operator >>):
                string kata;
                while (file >> kata) {
                    cout << kata << " ";
                }

            b. Baris per baris (getline):
                string baris;
                while (getline(file, baris)) {
                    cout << baris << endl;
                }

            c. Karakter per karakter (get):
                char c;
                while (file.get(c)) {
                    cout << c;
                }

            d. Seluruh file ke string (modern):
                string isi((istreambuf_iterator<char>(file)),
                            istreambuf_iterator<char>());

        5. Menutup File

            file.close();

            Sebenarnya file otomatis ditutup saat ifstream hancur (RAII).
            Tapi good practice untuk explicit close() kalau file masih
            butuh dipakai oleh proses lain.

        6. File Path

            Relatif  : "data.txt"            (dari direktori program)
            Absolut  : "/home/user/data.txt"  (Linux/Mac)
                        "C:\\Users\\data.txt"  (Windows)

        7. Mode Buka File (untuk fstream)

            ios::in      — baca
            ios::out     — tulis (overwrite)
            ios::app     — append (tambah di akhir)
            ios::binary  — mode binary
            ios::trunc   — hapus isi lama saat buka
            ios::ate     — posisi di akhir file saat buka

            Kombinasi: fstream f("file.txt", ios::in | ios::out);
    */

    /* MODUL 14.1 - Writing Files (ofstream)

        1. Menulis ke File — ofstream

            ofstream fileOut("output.txt");   // buka/buat file
            if (!fileOut) {
                cerr << "Gagal buka file untuk tulis!" << endl;
                return;
            }

            fileOut << "Halo, ini teks!" << endl;
            fileOut << "Baris kedua: " << 42 << endl;
            fileOut.close();

        2. Overwrite vs Append

            // OVERWRITE (default) — isi lama dihapus:
            ofstream f1("data.txt");
            ofstream f2("data.txt", ios::out);      // sama saja

            // APPEND — tambah di akhir file:
            ofstream f3("data.txt", ios::app);

        3. Menulis Angka dan Format

            ofstream f("angka.txt");
            f << fixed << setprecision(2);
            f << "Pi = " << 3.14159 << endl;
            f << "Total: " << 1000000 << endl;

        4. Pola Umum Write-Then-Read

            // 1. Tulis dulu
            {
                ofstream fw("data.txt");
                fw << "isi data" << endl;
            }   // fw ditutup otomatis di sini (RAII)

            // 2. Lalu baca
            {
                ifstream fr("data.txt");
                string baris;
                getline(fr, baris);
                cout << baris;
            }

        5. Cek Keberhasilan Operasi

            ofstream f("data.txt");
            f << "data";
            if (f.good())  cout << "Tulis berhasil";
            if (f.fail())  cout << "Ada masalah";
            if (f.bad())   cout << "Error fatal";
    */

    /* MODUL 14.2 - fstream & File Positioning

        1. fstream — Baca dan Tulis Sekaligus

            fstream f("data.txt", ios::in | ios::out);
            // atau
            fstream f("data.txt", ios::in | ios::out | ios::app);

        2. File Positioning

            Setiap file punya "kursor" yang menunjuk posisi baca/tulis saat ini.

            Untuk membaca (seekg = seek get):
                file.seekg(0);              // ke awal
                file.seekg(0, ios::beg);    // ke awal (eksplisit)
                file.seekg(0, ios::end);    // ke akhir
                file.seekg(-5, ios::cur);   // mundur 5 byte dari posisi kini

            Cek posisi kursor baca:
                streampos pos = file.tellg();
                cout << "Posisi: " << pos << endl;

            Untuk menulis (seekp = seek put):
                file.seekp(0);
                file.seekp(0, ios::end);

        3. Ukuran File

            ifstream f("file.txt", ios::ate);   // buka, langsung ke akhir
            streamsize ukuran = f.tellg();
            cout << "Ukuran: " << ukuran << " bytes" << endl;

        4. State Flags

            flag        arti
            ─────────── ───────────────────────────────────────
            good()      Semua OK, siap operasi
            eof()       Sudah sampai akhir file (End Of File)
            fail()      Operasi gagal (format salah, dll)
            bad()       Error fatal (disk penuh, dll)
            clear()     Reset semua error flags

            // Pattern aman setelah loop baca:
            file.clear();       // reset flags
            file.seekg(0);      // kembali ke awal

        5. Binary Files (Pengenalan)

            Untuk menyimpan data non-teks (gambar, audio, binary protocol):

                ofstream f("data.bin", ios::binary);
                int nilai = 12345;
                f.write(reinterpret_cast<char*>(&nilai), sizeof(nilai));

                ifstream fr("data.bin", ios::binary);
                int hasilBaca;
                fr.read(reinterpret_cast<char*>(&hasilBaca), sizeof(hasilBaca));

            Binary lebih cepat dan presisi, tapi tidak bisa dibaca manusia.
    */

    /* MODUL 14.3 - String Stream (sstream)

        1. Apa itu Stringstream?

            stringstream adalah "file" di memory — baca/tulis ke STRING,
            bukan ke file sungguhan. Sangat berguna untuk:
                ✅ Konversi tipe data (int ↔ string)
                ✅ Parsing baris CSV atau data terformat
                ✅ Format string sebelum di-print/ditulis
                ✅ Tokenizing (split string)

        2. Konversi Angka ke String

            #include <sstream>
            stringstream ss;
            int nilai = 42;
            ss << nilai;
            string hasil = ss.str();    // "42"

            // Atau pakai to_string() (lebih singkat, C++11):
            string s = to_string(nilai);

        3. Konversi String ke Angka

            stringstream ss("3.14");
            double d;
            ss >> d;    // d = 3.14

            // Atau pakai stoi(), stof(), stod() (C++11):
            int i = stoi("42");
            double x = stod("3.14");

        4. Parsing Baris Terformat (CSV)

            string baris = "Budi,20,3.85";
            stringstream ss(baris);
            string nama, umurStr, ipkStr;

            getline(ss, nama,   ',');   // "Budi"
            getline(ss, umurStr,',');   // "20"
            getline(ss, ipkStr, ',');   // "3.85"

            int    umur = stoi(umurStr);
            double ipk  = stod(ipkStr);

        5. Tokenizing (Split String)

            string kalimat = "satu dua tiga empat";
            stringstream ss(kalimat);
            string token;
            while (ss >> token) {
                cout << token << endl;
            }

        6. Build String Terformat

            stringstream ss;
            ss << "Nama: " << nama << endl;
            ss << "Umur: " << umur << " tahun" << endl;
            ss << fixed << setprecision(2) << "IPK: " << ipk << endl;
            string laporan = ss.str();
    */

// AB. Exception Handling

    /* MODUL 15.0 - Pengenalan Exception Handling

        1. Apa itu Exception?

            Exception (pengecualian) adalah kondisi TIDAK NORMAL yang terjadi
            saat program berjalan (runtime), yang mengganggu alur normal program.

            Contoh kondisi tidak normal:
                - Pembagian dengan nol  → hasil tidak terdefinisi
                - File tidak ditemukan  → tidak bisa dibaca
                - Input angka tapi user ketik huruf → format salah
                - Array diakses di luar batas → undefined behavior
                - Memori habis (bad_alloc) → new gagal
                - Konversi string salah (stoi("abc")) → invalid_argument

        2. Masalah Tanpa Exception Handling

            Tanpa exception handling, error ditangani dengan cara lama yang
            bermasalah:

            a. Return code (nilai balik untuk menandakan error):

                int bagi(int a, int b) {
                    if (b == 0) return -1;   // ← kode error khusus
                    return a / b;
                }

                int hasil = bagi(10, 0);
                if (hasil == -1) { ... }     // harus cek SETIAP kali

                Masalah:
                    ❌ Nilai -1 bisa juga hasil valid
                    ❌ Mudah lupa cek return code
                    ❌ Nested calls makin rumit
                    ❌ Tidak bisa dipakai untuk constructor

            b. Global error flag (seperti errno di C):

                errno = 0;
                sqrt(-1);
                if (errno == EDOM) { ... }

                Masalah:
                    ❌ Global state — tidak thread-safe
                    ❌ Mudah lupa reset

        3. Solusi: Exception Handling

            C++ menyediakan mekanisme exception handling yang:
                ✅ Memisahkan kode normal dari kode penanganan error
                ✅ Tidak bisa "diabaikan" seperti return code
                ✅ Bekerja lintas function call (stack unwinding)
                ✅ Tipe-safe — bisa throw/catch tipe apapun
                ✅ Bisa dipakai di constructor dan destructor

        4. Tiga Keyword Utama

            try     — blok kode yang mungkin menghasilkan error
            throw   — melempar (membangkitkan) exception
            catch   — menangkap dan menangani exception

            Pola dasar:

                try {
                    // kode yang mungkin error
                    throw SomethingError("pesan error");
                }
                catch (TipeError& e) {
                    // tangani error di sini
                    cout << e.what();
                }

        5. Analogi Dunia Nyata

            Bayangkan bermain bola:
                try    = bermain bola di lapangan
                throw  = kamu jatuh dan cedera (kejadian tidak normal!)
                catch  = perawat medis menangani cedera

            Alur normal (tidak ada exception):
                try → main bola → selesai → lanjut aktivitas berikutnya

            Alur dengan exception:
                try → main bola → jatuh! → throw exception
                → catch → perawat tangani → lanjut (atau keluar lapangan)

        6. Stack Unwinding

            Saat exception di-throw, C++ secara otomatis:
                1. Menghentikan eksekusi di titik throw
                2. "Melepas" (unwind) stack frame satu per satu
                3. Memanggil destruktor semua objek lokal yang sudah dibuat
                4. Mencari catch yang cocok di call stack

            Ini menjamin tidak ada resource leak — bahkan saat exception!
            (Inilah mengapa RAII + exception sangat powerful)

        7. Hirarki Exception Standard C++

            std::exception                  ← base class semua exception
            ├── std::logic_error            ← kesalahan logika program
            │   ├── std::invalid_argument   ← argumen tidak valid
            │   ├── std::domain_error       ← domain matematika salah
            │   ├── std::length_error       ← panjang melebihi batas
            │   └── std::out_of_range       ← indeks/nilai di luar range
            └── std::runtime_error          ← error saat runtime
                ├── std::overflow_error     ← overflow aritmatika
                ├── std::underflow_error    ← underflow aritmatika
                ├── std::range_error        ← hasil di luar range
                └── std::system_error       ← error sistem operasi

            Exception khusus (tidak turun dari logic_error/runtime_error):
                std::bad_alloc      ← new gagal alokasi memori
                std::bad_cast       ← dynamic_cast gagal
                std::bad_typeid     ← typeid pada null pointer
    */

    /* MODUL 15.1 - Try, Throw, Catch — Mekanisme Dasar

        1. Blok Try

            Blok try membungkus kode yang MUNGKIN melempar exception.
            Kode di dalam try berjalan normal hingga ada yang throw.

                try {
                    // kode normal
                    int hasil = bagi(10, 2);    // tidak throw → OK
                    int error = bagi(10, 0);    // throw! → langsung lompat ke catch
                    cout << "Baris ini TIDAK dieksekusi";
                }

        2. Keyword throw

            throw melempar sebuah objek sebagai exception.
            Bisa throw tipe apapun: int, string, struct, class.

                throw 42;                       // throw integer
                throw "error message";          // throw C-string
                throw string("pesan error");    // throw std::string
                throw runtime_error("pesan");   // throw exception class ← BEST PRACTICE
                throw invalid_argument("bad");  // throw exception class

            Setelah throw:
                - Eksekusi langsung berhenti di titik itu
                - C++ cari catch yang cocok di call stack
                - Destruktor semua objek lokal dipanggil (stack unwind)

        3. Blok Catch

            catch menangkap exception yang dilempar oleh throw.
            Harus ditulis tepat setelah blok try.

                catch (int e) {
                    cout << "Caught int: " << e;
                }

                catch (const string& e) {
                    cout << "Caught string: " << e;
                }

                catch (const runtime_error& e) {
                    cout << "Runtime error: " << e.what();
                }

                catch (...) {
                    // Catch-all: tangkap SEMUA tipe exception
                    cout << "Unknown exception!";
                }

            Urutan catch PENTING:
                - Dicocokkan dari atas ke bawah
                - Catch yang lebih spesifik harus LEBIH DULU
                - catch(...) selalu paling TERAKHIR

        4. Multiple Catch Blocks

            Satu try bisa diikuti banyak catch:

                try {
                    // kode
                }
                catch (const invalid_argument& e) {  // paling spesifik dulu
                    cout << "Invalid arg: " << e.what();
                }
                catch (const logic_error& e) {       // parent class
                    cout << "Logic error: " << e.what();
                }
                catch (const exception& e) {         // base class semua
                    cout << "Exception: " << e.what();
                }
                catch (...) {                        // catch-all paling terakhir
                    cout << "Unknown!";
                }

        5. Re-throw Exception

            Bisa tangkap exception lalu lempar ulang (untuk logging, dll):

                catch (const exception& e) {
                    cerr << "LOG: " << e.what() << endl;
                    throw;      // ← re-throw exception yang sama
                }

        6. Exception dalam Nested Function

            throw bisa terjadi di function manapun di call stack.
            C++ akan "naik" ke atas mencari catch yang cocok.

                void level3() { throw runtime_error("dari level 3"); }
                void level2() { level3(); }     // tidak ada catch di sini
                void level1() { level2(); }     // tidak ada catch di sini

                try {
                    level1();                   // exception "menggelembung" ke sini
                }
                catch (const runtime_error& e) {
                    cout << e.what();           // ← tertangkap di sini
                }

            Jika tidak ada catch yang cocok di seluruh call stack:
                → std::terminate() dipanggil → program CRASH

        7. Fungsi what()

            Semua class turunan std::exception punya fungsi what():

                catch (const exception& e) {
                    cout << e.what();   // pesan error string
                }

            what() mengembalikan const char* (C-string) berisi pesan error.
    */

    /* MODUL 15.2 - Standard Exception Classes

        1. std::exception — Base Class

            #include <stdexcept>

            Semua exception standar C++ mewarisi dari std::exception.
            Punya satu fungsi virtual: what() → const char*

                catch (const exception& e) {
                    cout << e.what();
                }

        2. std::logic_error dan Turunannya

            Logic error = kesalahan yang SEHARUSNYA bisa dicegah programmer.
            Bisa dideteksi sebelum runtime (saat desain/testing).

            a. invalid_argument — argumen yang diberikan tidak valid:
                stoi("abc")         → throw invalid_argument
                stod("xyz")         → throw invalid_argument
                throw invalid_argument("Usia tidak boleh negatif");

            b. out_of_range — nilai di luar rentang yang diizinkan:
                string s = "hello";
                s.at(10)            → throw out_of_range   (index > size)
                vector<int> v = {1,2,3};
                v.at(5)             → throw out_of_range
                throw out_of_range("Index melebihi batas");

            c. length_error — ukuran/panjang melebihi maksimum:
                string s;
                s.resize(string::max_size() + 1);   → throw length_error

            d. domain_error — input di luar domain matematika:
                throw domain_error("sqrt tidak bisa untuk nilai negatif");

        3. std::runtime_error dan Turunannya

            Runtime error = kesalahan yang hanya bisa dideteksi saat program jalan.
            Tidak bisa diprediksi saat compile time.

            a. runtime_error — error umum saat runtime:
                throw runtime_error("File tidak bisa dibuka");
                throw runtime_error("Koneksi database gagal");

            b. overflow_error — hasil terlalu besar:
                throw overflow_error("Nilai melebihi kapasitas tipe data");

            c. underflow_error — hasil terlalu kecil:
                throw underflow_error("Nilai terlalu kecil");

            d. range_error — hasil di luar range yang diizinkan:
                throw range_error("Hasil perhitungan di luar jangkauan");

        4. std::bad_alloc

            Otomatis dilempar oleh operator new saat alokasi memori gagal:

                try {
                    int* arr = new int[999999999999];   // kemungkinan gagal!
                    delete[] arr;
                }
                catch (const bad_alloc& e) {
                    cerr << "Memori habis: " << e.what() << endl;
                }

        5. std::bad_cast

            Dilempar oleh dynamic_cast<> saat cast gagal (ke referensi):

                class Base { virtual ~Base(){} };
                class Derived : public Base {};

                Base* b = new Base();
                try {
                    Derived& d = dynamic_cast<Derived&>(*b);  // cast gagal!
                }
                catch (const bad_cast& e) {
                    cerr << "Cast gagal: " << e.what() << endl;
                }

        6. Cara Construct Exception Standard

            Semua menerima string pesan di konstruktor:

                throw logic_error("pesan");
                throw runtime_error("pesan");
                throw invalid_argument("pesan");
                throw out_of_range("pesan");
                throw overflow_error("pesan");

            Retrieve pesan: e.what()
    */

    /* MODUL 15.3 - Custom Exception Classes

        1. Mengapa Buat Custom Exception?

            Exception standar bagus, tapi seringkali kita butuh:
                ✅ Pesan error yang lebih spesifik untuk domain kita
                ✅ Data tambahan (kode error, lokasi, konteks)
                ✅ Hierarki exception sesuai aplikasi kita
                ✅ Bisa di-catch spesifik per jenis error domain

        2. Cara Paling Sederhana — Warisi std::exception

            class MyException : public exception {
            public:
                const char* what() const noexcept override {
                    return "My custom error message";
                }
            };

            try {
                throw MyException();
            }
            catch (const MyException& e) {
                cout << e.what();
            }
            catch (const exception& e) {
                // juga tertangkap di sini kalau perlu
            }

        3. Warisi std::runtime_error (cara umum)

            Mewarisi runtime_error lebih praktis karena bisa pass pesan
            lewat konstruktor:

                class DatabaseError : public runtime_error {
                public:
                    DatabaseError(const string& msg)
                        : runtime_error(msg) {}
                };

                class ConnectionError : public DatabaseError {
                public:
                    ConnectionError(const string& host)
                        : DatabaseError("Gagal konek ke: " + host) {}
                };

                throw ConnectionError("localhost:5432");
                // e.what() → "Gagal konek ke: localhost:5432"

        4. Custom Exception dengan Data Tambahan

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

            try {
                throw HttpException(404, "/halaman-tidak-ada");
            }
            catch (const HttpException& e) {
                cout << "Status : " << e.statusCode() << endl;
                cout << "URL    : " << e.url() << endl;
                cout << "Pesan  : " << e.what() << endl;
            }

        5. Hierarki Custom Exception (Best Practice Besar)

            Membangun hierarki memungkinkan catch yang fleksibel:

                class AppException : public runtime_error {
                public:
                    AppException(const string& msg) : runtime_error(msg) {}
                };

                class ValidationError : public AppException {
                public:
                    ValidationError(const string& field, const string& reason)
                        : AppException("Validasi gagal [" + field + "]: " + reason),
                        field_(field) {}
                    string field() const { return field_; }
                private:
                    string field_;
                };

                class NetworkError : public AppException { ... };
                class DatabaseError : public AppException { ... };

                // Bisa catch spesifik:
                catch (const ValidationError& e) { ... }  // hanya validasi
                catch (const AppException& e)    { ... }  // semua app error
                catch (const exception& e)       { ... }  // semua exception

        6. noexcept — Fungsi yang Tidak Boleh Throw

            Tandai fungsi yang dijamin tidak throw exception:

                int tambah(int a, int b) noexcept {
                    return a + b;   // dijamin tidak throw
                }

            Kegunaan noexcept:
                ✅ Optimasi compiler (tidak perlu stack unwinding overhead)
                ✅ Dokumentasi — "fungsi ini aman, tidak throw"
                ✅ Wajib untuk beberapa situasi (move constructor, dll)
                ✅ Jika noexcept function ternyata throw → std::terminate()

            Cek apakah ekspresi noexcept:
                noexcept(tambah(1,2))   → true
                noexcept(bagi(1,0))     → false (kalau bagi bisa throw)
    */

    /* MODUL 15.4 - Best Practices & Pola Umum

        1. Throw by Value, Catch by Const Reference

            // ✅ BENAR — throw object, catch sebagai const ref
            throw runtime_error("pesan");
            catch (const runtime_error& e) { ... }

            // ❌ SALAH — catch by value (membuat salinan)
            catch (runtime_error e) { ... }

            // ❌ SALAH — catch by pointer (komplikasi ownership)
            catch (runtime_error* e) { ... }

            Mengapa catch by const reference?
                - Tidak membuat salinan (efisien)
                - Polimorfisme tetap bekerja (virtual what())
                - Tidak bisa modifikasi exception yang ditangkap

        2. Urutan Catch — Dari Spesifik ke Umum

            // ✅ BENAR
            catch (const invalid_argument& e) { ... }  // paling spesifik
            catch (const logic_error& e)       { ... }  // parent-nya
            catch (const exception& e)         { ... }  // base class
            catch (...)                        { ... }  // catch-all terakhir

            // ❌ SALAH — exception sudah tertangkap oleh parent sebelum anak
            catch (const exception& e)         { ... }  // terlalu umum di atas
            catch (const runtime_error& e)     { ... }  // tidak pernah tercapai!

        3. Jangan Abaikan Exception (Exception Safety)

            Tiga level exception safety:

            a. No-throw guarantee (noexcept):
                Dijamin tidak pernah throw exception.
                Contoh: destruktor, swap, move operation

            b. Strong guarantee:
                Kalau throw, state objek TIDAK BERUBAH (rollback).
                Contoh: copy-then-swap idiom

            c. Basic guarantee:
                Kalau throw, tidak ada resource leak, tapi state mungkin berubah.
                Ini level minimal yang harus dipenuhi

            d. No guarantee (❌ hindari!):
                Throw bisa menyebabkan resource leak atau corrupt state.

        4. RAII + Exception = Resource Safety

            RAII (Resource Acquisition Is Initialization) memastikan
            resource selalu dibebaskan, bahkan saat exception:

                // ❌ BERBAHAYA — kalau exception, ptr leak!
                int* ptr = new int[100];
                prosesData(ptr);        // kalau ini throw...
                delete[] ptr;           // ...baris ini tidak dieksekusi!

                // ✅ AMAN — unique_ptr otomatis hapus saat scope berakhir/exception
                auto ptr = make_unique<int[]>(100);
                prosesData(ptr.get());  // exception? ptr tetap terhapus!

        5. Exception dalam Constructor

            Constructor tidak punya return value, jadi tidak bisa return kode error.
            Exception adalah satu-satunya cara memberitahu kegagalan konstruksi:

                class FileReader {
                public:
                    FileReader(const string& nama) {
                        file_.open(nama);
                        if (!file_) {
                            throw runtime_error("Tidak bisa buka: " + nama);
                        }
                    }
                private:
                    ifstream file_;
                };

                try {
                    FileReader fr("tidak_ada.txt");  // throw di constructor!
                }
                catch (const runtime_error& e) {
                    cout << e.what();
                }
                // Objek fr tidak pernah selesai dibuat → tidak ada resource leak

        6. Kapan Menggunakan Exception vs Return Code

            Gunakan EXCEPTION untuk:
                ✅ Error yang "tidak seharusnya terjadi" (exceptional case)
                ✅ Error dari constructor
                ✅ Error yang tidak bisa diabaikan
                ✅ Error yang terjadi jauh di dalam call stack
                ✅ Error dari library yang dipakai orang lain

            Gunakan RETURN CODE / optional untuk:
                ✅ Error yang "biasa terjadi" dan diharapkan (expected failure)
                ✅ Kode yang sangat performance-critical
                ✅ Fungsi sederhana level rendah
                ✅ Konteks yang tidak boleh throw (interrupt handler, dll)

        7. Anti-Pattern yang Harus Dihindari

            // ❌ Catch dan buang exception — jangan pernah!
            catch (...) { }     // "swallowing" exception

            // ❌ Throw dari destruktor — sangat berbahaya!
            ~MyClass() { throw SomeError(); }   // bisa terminate program!

            // ❌ Exception specification lama (C++11 deprecated)
            void f() throw(int);    // jangan pakai ini

            // ❌ Throw pointer ke objek lokal
            catch (SomeError* e)    // siapa yang delete?

            // ❌ Catch terlalu umum di tempat yang salah
            catch (exception& e) { return; }   // menelan semua error diam-diam
    */

// AC. Preprocessor

    /* MODUL 16.0 - Apa itu Preprocessor?

        1. Pengertian

            Preprocessor adalah tahap PERTAMA yang dijalankan compiler
            sebelum kode C++ benar-benar dikompilasi.

            Preprocessor membaca source code dan melakukan TRANSFORMASI TEKS
            berdasarkan "instruksi" yang diawali dengan tanda pagar (#).
            Instruksi ini disebut PREPROCESSOR DIRECTIVE.

            Alur kompilasi C++:

                Source Code (.cpp)
                    --> Preprocessor  (jalan duluan! transformasi teks)
                    --> Compiler      (ubah ke object code)
                    --> Linker        (gabungkan jadi .exe)

            Yang dilakukan preprocessor:
                - Menyalin isi file header ke dalam kode (#include)
                - Mengganti nama macro dengan nilainya (#define)
                - Menghapus atau menyertakan bagian kode (#ifdef, #if)
                - Memberikan instruksi khusus ke compiler (#pragma)

            PENTING: Preprocessor bekerja pada level TEKS, bukan level bahasa.
            Ia tidak mengerti tipe data, fungsi, atau class C++.
            Ia hanya melakukan find-and-replace pada teks.

        2. Ciri-ciri Preprocessor Directive

            - Selalu dimulai dengan tanda #  (hash / pound)
            - Berdiri sendiri di satu baris
            - TIDAK diakhiri dengan titik koma ( ; )
            - Diproses sebelum kode apapun dikompilasi

            Contoh:
                #include <iostream>     // benar
                #include <iostream>;    // salah — ada titik koma!
                int x = 5;              // ini bukan directive — ini kode C++

        3. Daftar Directive yang Akan Dipelajari

            Direktif                Fungsi
            ─────────────────────── ────────────────────────────────────────────
            #include                Menyertakan isi file lain
            #define                 Mendefinisikan macro/konstanta
            #undef                  Menghapus definisi macro
            #ifdef / #ifndef        Kompilasi bersyarat (if defined / not defined)
            #if / #elif / #else     Kompilasi bersyarat (kondisi numerik)
            #endif                  Menutup blok kompilasi bersyarat
            #pragma                 Instruksi khusus untuk compiler
            #error                  Paksa error saat kompilasi
            #warning                Tampilkan peringatan saat kompilasi
    */

    /* MODUL 16.1 - #include — Menyertakan File Lain

        1. Apa itu #include?

            #include memberitahu preprocessor untuk mengambil isi file lain
            dan "menempelkannya" langsung di titik directive itu berada.

            Ibarat copy-paste otomatis isi file ke dalam kode kita.

        2. Dua Bentuk #include

            a. Angle brackets < > — untuk library standar / sistem:

                #include <iostream>     // cin, cout
                #include <string>       // std::string
                #include <vector>       // std::vector
                #include <algorithm>    // sort, find, dll
                #include <cmath>        // sqrt, pow, abs, dll
                #include <fstream>      // ifstream, ofstream
                #include <stdexcept>    // runtime_error, dll

                Preprocessor mencari di direktori sistem / compiler.

            b. Double quotes " " — untuk file buatan sendiri:

                #include "mathHelper.h"
                #include "config.h"
                #include "../utils/helper.h"    // path relatif ke atas

                Preprocessor mencari di direktori yang sama dengan file saat ini,
                lalu kalau tidak ketemu baru cari di direktori sistem.

        3. Apa yang Terjadi Saat #include?

            Misalnya kita punya file myHeader.h:

                // myHeader.h
                int tambah(int a, int b) {
                    return a + b;
                }

            Dan kita tulis di main.cpp:

                #include "myHeader.h"
                int main() {
                    cout << tambah(3, 4);
                }

            Setelah preprocessor jalan, main.cpp "seolah-olah" menjadi:

                int tambah(int a, int b) {   // isi dari myHeader.h disalin ke sini
                    return a + b;
                }
                int main() {
                    cout << tambah(3, 4);
                }

        4. Header File (.h) — Konvensi

            Header file biasanya berisi:
                - Deklarasi fungsi (bukan definisi)
                - Deklarasi class
                - Definisi struct, enum, typedef
                - Konstanta dan macro
                - Template definition (harus di header!)

            Kenapa deklarasi saja, bukan definisi?
                Karena header di-include oleh banyak file .cpp.
                Kalau definisi ada di header, akan ada banyak definisi
                ganda saat linker bekerja → linker error!

            Contoh yang benar:

                // fungsi.h  (deklarasi saja)
                int hitung(int a, int b);

                // fungsi.cpp  (definisi di sini)
                int hitung(int a, int b) { return a + b; }

        5. Masalah: Multiple Inclusion

            Kalau header di-include lebih dari sekali (langsung atau tidak langsung),
            compiler mendapat definisi ganda → error!

            Contoh masalah:
                // main.cpp
                #include "A.h"    // A.h juga #include "base.h"
                #include "B.h"    // B.h juga #include "base.h"
                // base.h masuk dua kali → error!

            Solusi: include guards (lihat MODUL 16.3) atau #pragma once.
    */

    /* MODUL 16.2 - #define — Macro dan Konstanta

        1. Apa itu #define?

            #define mendefinisikan sebuah MACRO — nama yang akan digantikan
            preprocessor dengan teks lain sebelum kompilasi.

            Syntax:
                #define NAMA_MACRO  nilai_atau_teks

            KONVENSI: nama macro pakai HURUF_KAPITAL_SEMUA.

        2. Object-like Macro (Konstanta Sederhana)

            #define PI          3.14159265
            #define MAX_SIZE    100
            #define APP_NAME    "MyApp v1.0"
            #define NEWLINE     '\n'

            Cara kerja (text substitution):

                area = PI * r * r;
                // Preprocessor ubah menjadi:
                area = 3.14159265 * r * r;

            Perbandingan dengan const / constexpr:

                #define MAX 100              // macro — tidak ada tipe, tidak ada scope
                const int MAX = 100;         // ada tipe, ada scope — lebih baik
                constexpr int MAX = 100;     // compile-time, ada tipe — paling baik

            Kapan masih pakai #define?
                - Header guard (#ifndef HEADER_H)
                - Debug/platform flag yang dikontrol dari luar
                - Kompatibilitas dengan kode C lama

        3. Function-like Macro

            Macro bisa menerima argumen seperti fungsi:

                #define KUADRAT(x)      ((x) * (x))
                #define MAKS(a, b)      ((a) > (b) ? (a) : (b))
                #define ABS(x)          ((x) >= 0 ? (x) : -(x))

            Penggunaan:
                int h = KUADRAT(5);     // → ((5) * (5)) → 25
                int m = MAKS(3, 7);     // → ((3) > (7) ? (3) : (7)) → 7

            BAHAYA function-like macro (harus pakai kurung!):

                #define KUADRAT_SALAH(x)  x * x   // tanpa kurung!

                KUADRAT_SALAH(2 + 3)
                // → 2 + 3 * 2 + 3   // operator precedence salah!
                // Hasil: 11 (BUKAN 25!)

                KUADRAT(2 + 3)
                // → ((2 + 3) * (2 + 3))   // kurung melindungi
                // Hasil: 25 benar

            Side effect bahaya:

                int a = 5;
                int b = MAKS(a++, 3);   // a++ dievaluasi DUA KALI → bug!

            Alternatif modern yang lebih aman:
                inline int kuadrat(int x) { return x * x; }
                template<typename T> T maks(T a, T b) { return a > b ? a : b; }

        4. Macro Multiline

            Gunakan backslash (\) untuk lanjut ke baris berikutnya:

                #define LOG_ERROR(msg) \
                    cerr << "[ERROR] " << __FILE__ \
                        << ":" << __LINE__  \
                        << " - " << msg << endl

                LOG_ERROR("File tidak ditemukan");
                // Menghasilkan: cerr << "[ERROR] main.cpp:42 - File tidak ditemukan" << endl;

        5. #undef — Hapus Definisi Macro

                #define TEMP 42
                // pakai TEMP ...
                #undef TEMP
                // TEMP sudah tidak ada di bawah sini

            Berguna untuk:
                - Batasi scope macro agar tidak bocor
                - Redefine macro dengan nilai baru
                - Menghindari konflik nama

        6. Predefined Macros (Sudah Ada dari Compiler)

            Macro           Isi                             Contoh
            ─────────────── ─────────────────────────────── ─────────────────────
            __FILE__        Nama file saat ini (string)     "main.cpp"
            __LINE__        Nomor baris saat ini (int)      42
            __func__        Nama fungsi saat ini (string)   "main"
            __DATE__        Tanggal kompilasi (string)      "Jan 14 2025"
            __TIME__        Waktu kompilasi (string)        "10:30:00"
            __cplusplus     Versi standar C++ (long)        201703L = C++17
                                                            202002L = C++20

            Penggunaan:
                cout << "File : " << __FILE__ << endl;
                cout << "Baris: " << __LINE__ << endl;
                cout << "C++  : " << __cplusplus << endl;

                // Debug macro yang menampilkan lokasi secara otomatis:
                #define TRACE() \
                    cout << "[TRACE] " << __func__ \
                        << " (" << __FILE__ << ":" << __LINE__ << ")" << endl
    */

    /* MODUL 16.3 - Include Guards & #pragma once

        1. Masalah: Double Inclusion

            Header sering di-include lebih dari sekali melalui dependency:

                // main.cpp
                #include "point.h"      // include point.h langsung
                #include "shapes.h"     // shapes.h juga include point.h

                // Akibat: isi point.h masuk DUA KALI → error redefinition!

        2. Solusi 1: Include Guards (Cara Klasik, Standar ISO)

                // point.h
                #ifndef POINT_H      // "Jika POINT_H belum didefinisikan..."
                #define POINT_H      // "...definisikan POINT_H..."

                struct Point {
                    int x;
                    int y;
                };

                #endif               // "...sampai di sini"

            Cara kerjanya:
                - Include pertama  : POINT_H belum ada → masuk ke blok → define POINT_H
                - Include kedua    : POINT_H sudah ada → SELURUH blok dilewati
                - Efek: isi header hanya diproses SATU KALI, tidak peduli berapa kali di-include

            Konvensi nama guard:
                POINT_H             → untuk point.h
                UTILS_MATH_H        → untuk utils/math.h
                MYAPP_CONFIG_H      → untuk myapp/config.h

        3. Solusi 2: #pragma once (Cara Modern, Praktis)

                // point.h
                #pragma once         // satu baris ini sudah cukup!

                struct Point {
                    int x;
                    int y;
                };

            #pragma once memberitahu compiler: "proses file ini hanya sekali".
            Tidak perlu #ifndef, #define, dan #endif.

            Kelebihan #pragma once:
                - Lebih singkat, tidak ada risiko typo nama guard
                - Didukung semua compiler modern (GCC, Clang, MSVC)
                - Sedikit lebih cepat dikompilasi

            Kekurangan #pragma once:
                - Bukan standar ISO C++ (tapi de-facto standar)
                - Bisa bermasalah jika file yang sama ada di dua path berbeda

        4. Pilihan

            Proyek baru / tim modern     → #pragma once
            Butuh portabilitas maksimal  → #ifndef include guards
            Sudah ada standar di tim     → ikuti standar yang ada

        5. Contoh Header Lengkap

            // mathHelper.h dengan include guard:
            #ifndef MATH_HELPER_H
            #define MATH_HELPER_H

            #include <cmath>

            const double PI = 3.14159265358979;

            inline double luasLingkaran(double r) {
                return PI * r * r;
            }

            #endif // MATH_HELPER_H   <-- komentar opsional tapi membantu

            // Atau dengan #pragma once:
            #pragma once
            #include <cmath>
            const double PI = 3.14159265358979;
            inline double luasLingkaran(double r) { return PI * r * r; }
    */

    /* MODUL 16.4 - Conditional Compilation (#ifdef, #if, #elif, #else, #endif)

        1. Apa itu Conditional Compilation?

            Memilih bagian kode mana yang DIKOMPILASI berdasarkan kondisi
            yang dievaluasi saat preprocessing — SEBELUM compiler berjalan.

            Ibarat "if-else khusus compiler" — bagian yang tidak memenuhi
            kondisi DIHAPUS TOTAL dari kode sebelum dikompilasi.

        2. #ifdef dan #ifndef

            #ifdef NAMA    → "Jika NAMA sudah didefinisikan, kompilasi blok ini"
            #ifndef NAMA   → "Jika NAMA BELUM didefinisikan, kompilasi blok ini"

                #define DEBUG_MODE      // aktifkan debug

                #ifdef DEBUG_MODE
                    cout << "Debug aktif: nilai x = " << x << endl;
                #endif

                #ifndef RELEASE
                    cout << "Ini bukan build release" << endl;
                #endif

        3. #if, #elif, #else, #endif

            Lebih powerful — bisa evaluasi ekspresi numerik:

                #define VERSI 3

                #if VERSI == 1
                    cout << "Fitur versi 1";
                #elif VERSI == 2
                    cout << "Fitur versi 2";
                #elif VERSI >= 3
                    cout << "Fitur versi 3+";
                #else
                    cout << "Versi tidak dikenal";
                #endif

            Operator yang bisa dipakai di #if:
                ==  !=  <  >  <=  >=   (perbandingan)
                &&  ||  !               (logika)
                defined(NAMA)           (cek apakah macro terdefinisi)

        4. Operator defined()

                #if defined(WINDOWS) && !defined(DEBUG)
                    // Kode khusus Windows Release mode
                #endif

                #if defined(LINUX) || defined(MACOS)
                    // Kode untuk Unix-like systems
                #endif

        5. Kegunaan Utama Conditional Compilation

            a. DEBUG vs RELEASE mode:

                // Kompilasi debug  : g++ -DDEBUG main.cpp
                // Kompilasi release: g++ main.cpp  (tanpa -DDEBUG)

                #ifdef DEBUG
                    #define LOG(msg)    cout << "[DEBUG] " << msg << endl
                    #define ASSERT(c)   if(!(c)) { cerr << "FAIL: " << #c; abort(); }
                #else
                    #define LOG(msg)    // kosong di release — dihapus oleh preprocessor
                    #define ASSERT(c)   // kosong di release
                #endif

                // Penggunaan sama di debug maupun release:
                LOG("Memulai proses");
                ASSERT(ptr != nullptr);

            b. Platform-specific code:

                // Compiler mendefinisikan macro platform secara otomatis:
                //   _WIN32 / _WIN64  → Windows
                //   __linux__        → Linux
                //   __APPLE__        → macOS / iOS

                #ifdef _WIN32
                    #include <windows.h>
                    void clearScreen() { system("cls"); }
                #elif defined(__linux__) || defined(__APPLE__)
                    void clearScreen() { system("clear"); }
                #else
                    void clearScreen() { } // tidak didukung di platform ini
                #endif

            c. Feature flags berdasarkan versi C++:

                #if __cplusplus >= 202002L
                    // Fitur C++20: concepts, ranges, coroutines
                    #define CPP_VERSION "C++20"
                #elif __cplusplus >= 201703L
                    // Fitur C++17: if constexpr, structured bindings, filesystem
                    #define CPP_VERSION "C++17"
                #elif __cplusplus >= 201402L
                    #define CPP_VERSION "C++14"
                #elif __cplusplus >= 201103L
                    #define CPP_VERSION "C++11"
                #else
                    #error "Butuh minimal C++11!"
                #endif

            d. Konfigurasi build:

                #define MAKS_USER 100

                #ifdef ENTERPRISE_EDITION
                    #undef  MAKS_USER
                    #define MAKS_USER 10000
                #endif

        6. #error dan #warning

            Paksa error atau peringatan saat kompilasi:

                #ifndef MAKS_BUFFER
                    #error "MAKS_BUFFER harus didefinisikan sebelum include file ini!"
                #endif

                #if MAKS_BUFFER > 65536
                    #warning "MAKS_BUFFER sangat besar — bisa habis stack memory!"
                #endif

            #error  → kompilasi berhenti dengan pesan error
            #warning → kompilasi lanjut tapi tampilkan peringatan
    */

    /* MODUL 16.5 - #pragma — Instruksi Khusus Compiler

        1. Apa itu #pragma?

            #pragma memberikan instruksi khusus kepada compiler yang bersifat
            IMPLEMENTATION-DEFINED — setiap compiler boleh mengimplementasikan
            atau mengabaikan pragma berbeda-beda.

            Tapi beberapa pragma sudah didukung hampir semua compiler modern.

        2. #pragma once

            Sudah dibahas di MODUL 16.3 — mencegah multiple inclusion header.

                #pragma once

        3. #pragma pack — Kontrol Alignment Memory

            Mengatur bagaimana compiler mengisi "celah" (padding) di struct:

                // Default: compiler bisa tambah padding untuk alignment
                struct Normal {
                    char  c;    // 1 byte + 3 byte padding (alignment ke 4)
                    int   i;    // 4 byte
                    // sizeof: 8 byte (bukan 5!)
                };

                // Padat tanpa padding:
                #pragma pack(1)
                struct Packed {
                    char  c;    // 1 byte
                    int   i;    // 4 byte
                    // sizeof: 5 byte persis
                };
                #pragma pack()   // kembalikan ke default

            Kapan pakai:
                - Baca/tulis file binary dengan format tertentu
                - Komunikasi jaringan / protokol (byte harus presisi)
                - Embedded systems dengan memory ketat

        4. #pragma comment (MSVC/Windows)

            Hubungkan library secara otomatis:

                #pragma comment(lib, "opengl32.lib")
                #pragma comment(lib, "user32.lib")

            Di GCC/Clang, link manual via flag: g++ main.cpp -lopengl32

        5. #pragma warning (MSVC) / #pragma GCC diagnostic (GCC)

            Kontrol peringatan compiler:

                // MSVC:
                #pragma warning(disable: 4996)   // matikan warning deprecated
                #pragma warning(push)
                #pragma warning(disable: 4100)   // unreferenced parameter
                // ... kode ...
                #pragma warning(pop)             // restore state warning

                // GCC / Clang:
                #pragma GCC diagnostic push
                #pragma GCC diagnostic ignored "-Wunused-parameter"
                // ... kode ...
                #pragma GCC diagnostic pop
    */

    /* MODUL 16.6 - Macro Lanjutan: Stringification & Token Pasting

        1. Stringification (#) — Ubah Argumen Macro Jadi String

            Operator # di dalam macro mengubah argumen menjadi string literal:

                #define CETAK_VAR(x) \
                    cout << #x << " = " << (x) << endl

                int nilai = 42;
                CETAK_VAR(nilai);
                // Menghasilkan: cout << "nilai" << " = " << (nilai) << endl;
                // Output: nilai = 42

                double suhu = 36.5;
                CETAK_VAR(suhu);
                // Output: suhu = 36.5

            Berguna sekali untuk debugging — print nama variabel sekaligus nilainya!

        2. Token Pasting (##) — Gabungkan Dua Token

            Operator ## menggabungkan dua token menjadi satu:

                #define BUAT_FUNGSI(nama) \
                    void fungsi_##nama() { cout << "Fungsi " #nama << endl; }

                BUAT_FUNGSI(Hitung)
                // Menghasilkan: void fungsi_Hitung() { cout << "Fungsi Hitung" << endl; }

                BUAT_FUNGSI(Tampilkan)
                // Menghasilkan: void fungsi_Tampilkan() { ... }

            Contoh lain — generate nama variabel:

                #define ITEM(n) int item_##n
                ITEM(1);  // → int item_1;
                ITEM(2);  // → int item_2;

        3. Macro Debug Assert (Pola Umum di Proyek Besar)

                #define MY_ASSERT(kondisi) \
                    do { \
                        if (!(kondisi)) { \
                            cerr << "ASSERT GAGAL: " << #kondisi \
                                << "\nFile  : " << __FILE__ \
                                << "\nBaris : " << __LINE__ \
                                << "\nFungsi: " << __func__ << endl; \
                            abort(); \
                        } \
                    } while(0)

                // Penggunaan:
                MY_ASSERT(ptr != nullptr);
                MY_ASSERT(index >= 0 && index < size);

            Kenapa do { ... } while(0)?
                Trik agar macro multi-statement aman dipakai dengan if tanpa kurung kurawal.

        4. Variadic Macro (C++11)

            Macro yang menerima jumlah argumen tidak tetap:

                #define LOG(format, ...) \
                    printf("[LOG] " format "\n", ##__VA_ARGS__)

                LOG("Halo!");
                LOG("Nilai: %d", 42);
                LOG("Nama: %s, Umur: %d", "Budi", 20);
    */

    /* MODUL 16.7 - Preprocessor dalam Konteks Nyata & Best Practices

        1. Struktur Proyek C++ Umum

                myproject/
                ├── include/
                │   ├── config.h        konfigurasi global (define, platform)
                │   ├── mathHelper.h    deklarasi fungsi
                │   └── types.h         tipe data custom, enum
                ├── src/
                │   ├── main.cpp
                │   ├── mathHelper.cpp  definisi fungsi
                │   └── utils.cpp
                └── CMakeLists.txt / Makefile

            Setiap header pakai #pragma once atau include guard.
            Setiap .cpp hanya include header yang benar-benar dibutuhkan.

        2. Pola config.h yang Umum

                // config.h
                #pragma once

                #define APP_NAME    "MyApplication"
                #define APP_VERSION "2.1.0"

                // Pilih salah satu saat build:
                // #define BUILD_DEBUG
                #define BUILD_RELEASE

                #ifdef BUILD_DEBUG
                    #define LOG_LEVEL    3      // verbose
                    #define ENABLE_ASSERT
                #else
                    #define LOG_LEVEL    1      // minimal
                #endif

                // Platform detection otomatis:
                #ifdef _WIN32
                    #define PLATFORM "Windows"
                #elif defined(__linux__)
                    #define PLATFORM "Linux"
                #elif defined(__APPLE__)
                    #define PLATFORM "macOS"
                #else
                    #define PLATFORM "Unknown"
                #endif

        3. Pola Debug Logging

                // debug.h
                #pragma once
                #include <iostream>

                #ifdef DEBUG
                    #define DBG_LOG(x) \
                        std::cout << "[DBG] " << x << std::endl
                    #define DBG_VAR(x) \
                        std::cout << "[DBG] " << #x << " = " << (x) << std::endl
                    #define DBG_FUNC() \
                        std::cout << "[DBG] Masuk: " << __func__ << std::endl
                #else
                    #define DBG_LOG(x)      // kosong di release
                    #define DBG_VAR(x)
                    #define DBG_FUNC()
                #endif

                // Cara pakai:
                // g++ -DDEBUG main.cpp      (build debug, semua log aktif)
                // g++ main.cpp              (build release, semua log hilang)

        4. Perbandingan Macro vs Alternatif Modern C++

            Kebutuhan            Cara Lama (#define)         Cara Modern C++
            ──────────────────── ─────────────────────────── ──────────────────────────
            Konstanta            #define PI 3.14159           constexpr double PI = 3.14159
            Fungsi kecil         #define KUADRAT(x) (x)*(x)  inline/template function
            Kondisi kompilasi    #ifdef / #if                 if constexpr (C++17)
            Include sekali       #pragma once                 Modules (C++20)
            Tipe alias           #define INT32 int            using INT32 = int;

            Tapi preprocessor TIDAK akan hilang — terlalu banyak kode bergantung,
            dan ada kasus yang HANYA bisa diselesaikan preprocessor:
            platform detection, header guard, debug flag dari command line.

        5. Ringkasan Kapan Pakai Apa

            Situasi                                 Solusi Preprocessor
            ─────────────────────────────────────── ─────────────────────────────────
            Cegah multiple inclusion header         #pragma once / include guard
            Konstanta global (kompatibilitas)       #define NAMA nilai
            Kode berbeda debug vs release           #ifdef DEBUG / #ifndef DEBUG
            Kode berbeda antar platform             #ifdef _WIN32, __linux__, dll
            Instruksi khusus compiler               #pragma pack, warning, dll
            Wajibkan kondisi saat kompilasi         #error / #warning
            Debug print variabel + lokasi           #define + #x, __FILE__, __LINE__
            Cek versi C++ yang dipakai              #if __cplusplus >= 201703L

        6. Hal yang TIDAK Boleh Dilakukan dengan Preprocessor

            Jangan definisikan fungsi besar sebagai macro function
                Pakai inline function atau template — ada type checking

            Jangan pakai #define untuk konstanta bertipe
                Pakai const atau constexpr — ada scope, ada type

            Jangan buat logic kompleks dengan macro
                Sulit debug, tidak ada type safety, side-effect berbahaya

            Jangan include header yang tidak dibutuhkan
                Memperlambat kompilasi (kadang drastis di proyek besar)

            Jangan taruh definisi fungsi/variabel di header tanpa inline/static
                Multiple definition error saat link

            Jangan buat nama macro yang terlalu umum atau pendek
                #define MAX 100 bisa clash dengan kode library lain

        7. Checklist Header File yang Baik

                // namafile.h
                #pragma once                    ← (1) selalu ada di baris pertama

                #include <dependensi_yang_diperlukan>   ← (2) include minimal

                // Konstanta dan tipe:
                constexpr int MAX_ITEM = 100;   ← (3) constexpr bukan #define
                using ItemId = unsigned int;    ← (4) using bukan typedef

                // Deklarasi saja — bukan definisi:
                class MyClass;                  ← (5) forward declaration kalau cukup
                void prosesItem(int id);        ← (6) deklarasi fungsi

                // Definisi yang boleh di header:
                inline void helper() { ... }   ← (7) inline function boleh
                template<T> void gen(T x){}    ← (8) template harus di header
    */

// MESIN UTAMA
    int main(){
            //programPertama();

        // -------------[FUNDAMENTALS]----------------
            //komentar();
            //constConstexpr();
            //typeConversion();
            //variabel();
            //tipeData();
            //escapeSequence();
            //inputOutput();

        // -------------[OPERATORS]----------------
            //operatorAritmatika();
            //operatorPenugasan();
            //operatorIncrementDecrement();
            //operatorPerbandingan();
            //operatorLogika();
            //operatorTernary();
            //operatorBitwise();

        // -------------[BRANCHING]----------------
            //controlIfElse();
            //controlNestedIfElse();
            //controlSwitchCase();

        // -------------[LOOPS]----------------
            //perulanganFor();
            //perulanganWhile();
            // perulanganDoWhile();
            // loopControl();
            // nestedLoopsPattern();

        // -------------[FUNCTION]----------------
            

        // -------------[Array]----------------
            // // 8.1-8.2  Fundamental & Dasar
            //     demoArrayFundamentalBasic();
            // // 8.3      Array Algorithm (Searching, Sorting, Manipulation, Frequency)
            //     demoArrayAlgorithm();
            // // 8.4      Character Array
            //     demoCharacterArray();
            // // 8.5      Array Multidimensi
            //     demoArrayMultidimensi();
            // // 8.6-8.10 Array + Function
            //     demoArrayFunction();
        return 0;
}
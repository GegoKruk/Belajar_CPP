#include <iostream>
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
                    - Bisa dari input user atau hasil kalkulasi
                
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
                char → int → long → float → double
            
            Dangerous Direction (Ada data loss):
                double → float → long → int → char
            
            Contoh:
                int x = 5;
                double y = x;  // ✅ Aman: int → double
                
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
            
            String → Number:
                stoi(str)  - string to int
                stof(str)  - string to float
                stod(str)  - string to double
            
            Number → String:
                to_string(number)
    */
    void typeConversion(){
        cout << endl << "========== Type Conversion & Casting ==========" << endl;
        
        // ===== 1. IMPLICIT CONVERSION =====
        cout << "1. Implicit Conversion (Automatic)" << endl;
        
        // Safe conversion: int → double
        int umur = 18;
        double umurDouble = umur;  // Otomatis convert
        cout << "   int ke double: " << umur << " -> " << umurDouble << endl;
        
        // Dangerous conversion: double → int (data loss!)
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
        cout << "   - Konversi besar → kecil bisa kehilangan data" << endl;
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
            Jangan pakai x /= 0; → akan menyebabkan runtime error (division by zero)
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
                5   → 0101
                & 3 → 0011
                ------------
                1   → 0001

        4. Bitwise OR (|)
            Rule: Hasil 1 jika SALAH SATU atau KEDUA bit bernilai 1
            
            Truth Table:
                A    B    A | B
                0    0      0
                0    1      1
                1    0      1
                1    1      1
            
            Contoh:
                5   → 0101
                | 3 → 0011
                ------------
                7   → 0111

        5. Bitwise XOR (^) - Exclusive OR
            Rule: Hasil 1 jika bit BERBEDA
            
            Truth Table:
                A    B    A ^ B
                0    0      0
                0    1      1
                1    0      1
                1    1      0
            
            Contoh:
                5 → 0101
                ^ 3 → 0011
                ------------
                6 → 0110

        6. Bitwise NOT (~)
            Rule: BALIK semua bit (0→1, 1→0)
            
            Contoh:
                5 → 00000101
                ~5  → 11111010 (= -6 dalam signed int)

        7. Left Shift (<<)
            Rule: Geser bit ke KIRI n posisi, isi 0 di kanan
            Formula: x << n = x * (2^n)
            
            Contoh:
                5    → 00000101
                5 << 1 → 00001010 (= 10)
                5 << 2 → 00010100 (= 20)

        8. Right Shift (>>)
            Rule: Geser bit ke KANAN n posisi
            Formula: x >> n = x / (2^n)
            
            Contoh:
                5    → 00000101
                5 >> 1 → 00000010 (= 2)
                5 >> 2 → 00000001 (= 1)

        9. Penggunaan Praktis
            ✅ Cek genap/ganjil: if (n & 1) → ganjil
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
                goto → break, continue, return, proper structure

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
        cout << "→ Loop STOP" << endl;
        
        cout << endl << "   Loop 1-5 dengan CONTINUE di i=3:" << endl;
        cout << "      ";
        for (int i = 1; i <= 5; i++) {
            if (i == 3) {
                cout << "[SKIP] ";
                continue;  // Skip 3
            }
            cout << i << " ";
        }
        cout << "→ Loop LANJUT" << endl;
        
        
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
            Struktur: Loop outer → Loop inner (di dalam outer)
            
            Analogi:
                Outer loop = Lantai gedung
                Inner loop = Kamar di tiap lantai
                Untuk kunjungi semua kamar → nested loops!
            
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
                • j <= i          → increasing per baris
                • j < rows-i      → decreasing per baris
                • j >= rows-i-1   → right alignment
            - Spasi untuk alignment (centered, right)

        5. Thinking Process
            Step 1: Identifikasi jumlah baris dan kolom
            Step 2: Cari pola per baris (bertambah/berkurang?)
            Step 3: Tentukan relasi i dan j
            Step 4: Butuh spasi? Berapa?
            Step 5: Test dengan input kecil (3-5 baris)

        6. Performance Note
            ⚠️ Nested loops = O(n²) complexity
            ⚠️ Triple nested = O(n³) → avoid kalau bisa
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
        cout << "   - j <= i → increasing, j < rows-i → decreasing" << endl;
        cout << "   - Gunakan spasi untuk alignment (centered/right)" << endl;
        cout << "   - Start simple (3 baris), lalu scale up" << endl;
        cout << "   - Trace dengan pen & paper dulu!" << endl;
        cout << "   - Nested loops = O(n²), hati-hati dengan data besar" << endl;
    }









// MESIN UTAMA
    int main(){
        //programPertama();
        //komentar();
        //constConstexpr();
        //typeConversion();
        //variabel();
        //tipeData();
        //escapeSequence();
        //inputOutput();
        //operatorAritmatika();
        //operatorPenugasan();
        //operatorIncrementDecrement();
        //operatorPerbandingan();
        //operatorLogika();
        //operatorTernary();
        //operatorBitwise();
        //controlIfElse();
        //controlNestedIfElse();
        //controlSwitchCase();
        //perulanganFor();
        //perulanganWhile();

        return 0;
    }
/*
    DAFTAR ISI MODUL FILE I/O
    ============================================================
    00  Overview                    <- kamu di sini
    01  Menulis-File-ofstream
    02  Membaca-File-ifstream
    03  Mode-Buka-File
    04  File-Positioning
    05  State-Flags-dan-Error
    06  fstream-Baca-dan-Tulis
    07  Binary-File
    08  String-Stream
    09-Pola-Praktis-File-IO
    ============================================================
*/

// AA.0 - Overview
    
    /* APA ITU FILE I/O?
        -------------------------------------------------------
        Selama ini semua data program HILANG setelah selesai.
        File I/O (Input/Output) memungkinkan program:
        - MENYIMPAN data ke file (persisten, tidak hilang)
        - MEMBACA data dari file
        - Komunikasi antar program via file

        Analogi:
            cin / cout = ngobrol langsung (sementara)
            File I/O   = tulis/baca di buku catatan (permanen)
    */

    /* HEADER YANG DIBUTUHKAN
        -------------------------------------------------------
        #include <fstream>    -> file stream utama
        #include <sstream>    -> string stream (baca/tulis ke string)
        #include <iomanip>    -> format output (setprecision, dll)
    */
    
    /* TIGA CLASS UTAMA
        -------------------------------------------------------
        ifstream   -> Input File Stream  (MEMBACA file)
        ofstream   -> Output File Stream (MENULIS file)
        fstream    -> File Stream        (MEMBACA dan MENULIS)

        Semua turunan dari:
        ios -> istream/ostream -> ifstream/ofstream/fstream
    */ 

    /* MODE BUKA FILE (ios flags)
        -------------------------------------------------------
        Flag          Keterangan
        ------------  ----------------------------------------
        ios::in       Baca (default untuk ifstream)
        ios::out      Tulis, overwrite (default untuk ofstream)
        ios::app      Append - tambah di akhir file
        ios::binary   Mode binary (bukan teks)
        ios::trunc    Hapus isi lama saat buka
        ios::ate      Posisi kursor di akhir saat dibuka

        Bisa dikombinasikan dengan |:
            fstream f("data.txt", ios::in | ios::out);
    */
    
    /* POLA DASAR (WAJIB DIIKUTI)
        -------------------------------------------------------
        1. Buka file
        2. CEK apakah berhasil dibuka  <- sering dilupakan!
        3. Baca / tulis data
        4. Tutup file

            ofstream file("data.txt");
            if (!file.is_open()) {
                cerr << "Gagal buka file!" << endl;
                return 1;
            }
            file << "data" << endl;
            file.close();
    */

    /* CARA MEMBACA FILE
        -------------------------------------------------------
        Cara               Cocok untuk
        -----------------  -----------------------------------
        file >> kata       Baca kata per kata (berhenti di spasi)
        getline(file, s)   Baca baris per baris
        file.get(c)        Baca karakter per karakter
        istreambuf_iter    Baca seluruh file ke string sekaligus
    */

    /* FILE PATH
        -------------------------------------------------------
        Relatif  : "data.txt"              (dari direktori program)
        Absolut  : "C:\\Users\\data.txt"   (Windows)
        Absolut  : "/home/user/data.txt"   (Linux/Mac)

        Tips: selalu pakai path relatif untuk portabilitas.
    */

// AA.1 - Menulis File ofstream
    
    /* ofstream - OUTPUT FILE STREAM
        -------------------------------------------------------
        Dipakai untuk MENULIS ke file.
        Jika file belum ada -> dibuat otomatis.
        Jika file sudah ada -> isinya dihapus (OVERWRITE, default).

        Syntax membuka:
            ofstream file("nama_file.txt");           // cara 1: langsung
            ofstream file("nama_file.txt", ios::out); // cara 2: eksplisit (sama)

            ofstream file;
            file.open("nama_file.txt");               // cara 3: open() terpisah

        Syntax menulis (sama persis dengan cout):
            file << "teks"    << endl;
            file << variabel  << endl;
            file << 42        << endl;
    */

    /* WAJIB CEK SEBELUM MENULIS
        -------------------------------------------------------
        Selalu cek apakah file berhasil dibuka sebelum menulis!

            if (!file.is_open()) {
                cerr << "Gagal buka file!" << endl;
                return 1;
            }
            // atau lebih singkat:
            if (!file) { ... }
    */
    
    /* OVERWRITE vs APPEND
        -------------------------------------------------------
        Overwrite (default): isi lama DIHAPUS, ditulis dari awal
            ofstream file("data.txt");
            ofstream file("data.txt", ios::out);   // sama saja

        Append: isi lama DIPERTAHANKAN, data baru ditambah di akhir
            ofstream file("data.txt", ios::app);
    */

    /* MENUTUP FILE
        -------------------------------------------------------
        file.close();

        File otomatis ditutup saat ofstream keluar scope (RAII).
        Tapi explicit close() adalah good practice, terutama jika
        file masih perlu dipakai proses lain setelah ini.
    */
    
    /* FORMAT PENULISAN
        -------------------------------------------------------
        Sama persis dengan cout, bisa pakai semua manipulator:
            file << fixed << setprecision(2) << 3.14159;
            file << setw(10) << "kanan";
            file << left << setw(10) << "kiri";
    */

// AA.2 - Membaca File ifstream
    
    /* ifstream - INPUT FILE STREAM
        -------------------------------------------------------
        Dipakai untuk MEMBACA dari file yang sudah ada.
        Jika file tidak ditemukan -> file tidak terbuka (is_open() = false).

        Syntax membuka:
            ifstream file("nama_file.txt");

            ifstream file;
            file.open("nama_file.txt");   // cara open() terpisah

        WAJIB cek sebelum baca:
            if (!file.is_open()) {
                cerr << "File tidak ditemukan!" << endl;
                return 1;
            }
    */

    // 4 CARA MEMBACA FILE

        /* CARA 1 - Kata per kata (operator >>)
            string kata;
            while (file >> kata) {
                cout << kata << " ";
            }
            - Berhenti di spasi, tab, newline
            - Cocok untuk data yang dipisah spasi / angka
            - TIDAK bisa baca baris dengan spasi sebagai satu unit
        */
    
        /* CARA 2 - Baris per baris (getline)
            string baris;
            while (getline(file, baris)) {
                cout << baris << endl;
            }
            - Membaca satu baris penuh termasuk spasi
            - Tidak menyertakan karakter newline di akhir
            - PALING UMUM dipakai
        */

        /* CARA 3 - Karakter per karakter (get)
            char c;
            while (file.get(c)) {
                cout << c;
            }
            - Membaca SATU karakter sekaligus
            - Termasuk spasi dan newline
            - Cocok untuk proses per karakter (hitung, cari, dll)
        */
        
        /* CARA 4 - Seluruh file sekaligus (istreambuf_iterator)
            string isi(
                istreambuf_iterator<char>(file),
                istreambuf_iterator<char>()
            );
            - Membaca SEMUA isi file ke satu string
            - Paling cepat untuk file kecil/sedang
            - Tidak cocok untuk file sangat besar
        */

// AA.3 - Mode Buka File

    /* MODE BUKA FILE (ios flags)
        -------------------------------------------------------
        Flag          Keterangan
        ------------  -----------------------------------------
        ios::in       Buka untuk BACA
                        - Default pada ifstream
                        - Error jika file tidak ada

        ios::out      Buka untuk TULIS (overwrite)
                        - Default pada ofstream
                        - Buat file baru jika belum ada
                        - Hapus isi lama jika file sudah ada

        ios::app      Append - tambahkan di AKHIR file
                        - Buat file baru jika belum ada
                        - Isi lama DIPERTAHANKAN
                        - Kursor selalu di akhir saat tulis

        ios::trunc    Potong/hapus isi file saat dibuka
                        - Default dipakai bersama ios::out
                        - Jarang dipakai eksplisit

        ios::binary   Mode BINARY (bukan teks)
                        - Tidak ada konversi newline otomatis
                        - Untuk data biner (gambar, audio, dll)

        ios::ate      At End - kursor langsung ke akhir saat buka
                        - Berbeda dengan app: bisa seekg ke mana saja
    */

    /* KOMBINASI MODE
        -------------------------------------------------------
        Kombinasi                      Keterangan
        -----------------------------  -------------------------
        ios::in                        Baca saja
        ios::out                       Tulis (overwrite/buat baru)
        ios::app                       Tulis append
        ios::in | ios::out             Baca dan tulis (file harus ada)
        ios::in | ios::out | ios::trunc  Baca+tulis, hapus isi lama
        ios::out | ios::binary         Tulis file binary
        ios::in  | ios::binary         Baca file binary
        ios::in  | ios::ate            Baca, kursor mulai di akhir
    */
    
    /* DEFAULT MASING-MASING KELAS
        -------------------------------------------------------
        ifstream  -> ios::in           (baca saja)
        ofstream  -> ios::out          (tulis/overwrite)
        fstream   -> tidak ada default, HARUS tentukan sendiri
    */

    /* PERBEDAAN ios::app vs ios::ate
        -------------------------------------------------------
        ios::app - kursor SELALU di akhir saat tulis, tidak bisa seekp ke tengah
        ios::ate - kursor mulai di akhir, TAPI bisa dipindah ke mana saja
    */

// AA.4 - File Positioning
    
    /* FILE POSITIONING (KURSOR FILE)
        -------------------------------------------------------
        Setiap file punya "kursor" yang menunjuk posisi
        baca/tulis saat ini, mirip kursor di text editor.

        Saat file dibuka:
        - Kursor biasanya di AWAL (posisi 0)
        - Kecuali pakai ios::ate atau ios::app

        Saat baca/tulis berlangsung:
        - Kursor otomatis maju sesuai jumlah byte
    */

    /* FUNGSI SEEK (PINDAH KURSOR)
        -------------------------------------------------------
        Untuk baca (seekg = seek get):
            file.seekg(posisi);               // dari awal file
            file.seekg(offset, arah);         // dari arah tertentu

        Untuk tulis (seekp = seek put):
            file.seekp(posisi);
            file.seekp(offset, arah);

        Arah (ios):
            ios::beg   -> dari AWAL file (posisi 0)
            ios::cur   -> dari posisi SEKARANG
            ios::end   -> dari AKHIR file

        Contoh:
            file.seekg(0);             // ke awal
            file.seekg(0, ios::end);   // ke akhir
            file.seekg(-5, ios::cur);  // mundur 5 byte dari posisi kini
            file.seekg(10, ios::beg);  // 10 byte dari awal
    */
    
    /* FUNGSI TELL (CEK POSISI KURSOR)
        -------------------------------------------------------
        streampos pos = file.tellg();   // posisi kursor baca
        streampos pos = file.tellp();   // posisi kursor tulis

        Hasilnya adalah streampos (bisa dikonversi ke long long).
    */

    /* UKURAN FILE
        -------------------------------------------------------
        Cara mudah mendapatkan ukuran file:
            ifstream f("file.txt", ios::ate);  // buka, langsung ke akhir
            streamsize ukuran = f.tellg();     // posisi kursor = ukuran file
            f.seekg(0);                        // kembalikan ke awal untuk baca
    */
    
    /* POLA RESET SETELAH LOOP BACA
        -------------------------------------------------------
        Setelah selesai baca seluruh file, kursor ada di akhir
        dan flag eof aktif. Untuk baca ulang:
            file.clear();    // reset flag EOF dan error
            file.seekg(0);   // kembali ke awal
    */

// AA.5 - State Flags dan Error
    
    /* STATE FLAGS STREAM
        -------------------------------------------------------
        Setiap stream (file, cin, cout) punya state flags
        yang menunjukkan kondisi stream saat ini.

        Flag        Fungsi         Arti
        ----------  -------------  ----------------------------------------
        good()      good()         Semua OK, siap untuk operasi
        eof()       eof()          Sudah sampai akhir file (End Of File)
        fail()      fail()         Operasi gagal (format salah, dll)
                                    Termasuk juga saat eof
        bad()       bad()          Error fatal (disk penuh, hardware error)
        rdstate()   rdstate()      Bitmask semua flag sekaligus

        Mereset flag:
        clear()     clear()        Reset SEMUA flag ke good state
        clear(mask) clear(mask)    Reset flag tertentu saja
    */

    /* KAPAN MASING-MASING AKTIF?
        -------------------------------------------------------
        good()  : tidak ada masalah apapun
        eof()   : setelah baca melewati akhir file
        fail()  : format tidak cocok (misal baca int tapi isinya huruf)
                atau baca melewati EOF
        bad()   : error serius seperti disk corrupt, tidak bisa baca
    */
    
    /* POLA CEK SETELAH OPERASI
        -------------------------------------------------------
        Cara singkat: stream dikonversi ke bool secara implisit
            if (file) { ... }      // sama dengan if (!file.fail())
            if (!file) { ... }     // ada masalah

        Cara eksplisit:
            if (file.fail())  { ... }
            if (file.bad())   { ... }
            if (file.eof())   { ... }
            if (file.good())  { ... }
    */

    /* POLA AMAN MEMBUKA FILE
        -------------------------------------------------------
        ifstream f("data.txt");
        if (!f) {
            cerr << "Gagal buka file 'data.txt'" << endl;
            return 1;
        }
    */
    
    /* KENAPA FAIL() TIDAK SAMA DENGAN BAD()?
        -------------------------------------------------------
        fail() : recoverable - bisa di-clear() lalu lanjut
                Contoh: gagal parse angka, lanjut ke token berikutnya

        bad()  : unrecoverable - biasanya tidak bisa dilanjutkan
                Contoh: hardware error, disk corrupt
    */

// AA.6 - fstream Baca dan Tulis
    
    /* fstream - FILE STREAM (BACA + TULIS)
        -------------------------------------------------------
        fstream adalah kelas yang bisa membaca DAN menulis
        dalam satu objek. Gabungan dari ifstream + ofstream.

        Kapan pakai fstream vs ifstream/ofstream?
        - Perlu baca sekaligus tulis ke file yang SAMA
        - Perlu seekg/seekp bolak-balik dalam file
        - Misalnya: update record tertentu di file

        Kapan pakai ifstream/ofstream terpisah?
        - Hanya perlu baca SAJA -> ifstream (lebih jelas)
        - Hanya perlu tulis SAJA -> ofstream (lebih jelas)
        - Kode lebih mudah dipahami dengan kelas yang spesifik
    */

    /* PENTING: fstream TIDAK PUNYA DEFAULT MODE
        -------------------------------------------------------
        ifstream default mode: ios::in
        ofstream default mode: ios::out

        fstream TIDAK ada default mode! Harus tentukan sendiri.

            fstream f("data.txt");                         // tidak ada mode -> bermasalah
            fstream f("data.txt", ios::in | ios::out);     // harus eksplisit
    */
    
    /* CARA BUKA fstream
        -------------------------------------------------------
        // Baca + tulis, file HARUS sudah ada:
        fstream f("data.txt", ios::in | ios::out);

        // Baca + tulis, hapus isi lama:
        fstream f("data.txt", ios::in | ios::out | ios::trunc);

        // Baca + tulis + append:
        fstream f("data.txt", ios::in | ios::out | ios::app);
    */

    /* DUAL KURSOR: seekg dan seekp
        -------------------------------------------------------
        fstream punya DUA kursor: satu untuk baca (g) satu untuk tulis (p).
        Keduanya biasanya sinkron, tapi bisa dimove secara terpisah.

            f.seekg(0);          // pindah kursor BACA ke awal
            f.seekp(0, ios::end); // pindah kursor TULIS ke akhir
    */

// AA.7 - Binary File
    
    /* FILE TEKS vs FILE BINARY
        -------------------------------------------------------
        File Teks:
            - Data disimpan sebagai karakter (ASCII/UTF-8)
            - Angka 12345 disimpan sebagai "12345" (5 byte karakter)
            - Newline otomatis dikonversi ('\n' <-> "\r\n" di Windows)
            - Bisa dibuka dan dibaca di Notepad
            - Lebih besar untuk data numerik

        File Binary:
            - Data disimpan dalam representasi binary asli
            - Angka 12345 (int) disimpan sebagai 4 byte (nilai biner)
            - Tidak ada konversi newline
            - Tidak terbaca di Notepad (tampil karakter aneh)
            - LEBIH KECIL dan LEBIH CEPAT untuk data numerik
            - Cocok untuk: gambar, audio, data numerik banyak
    */

    /* MENULIS BINARY: write()
        -------------------------------------------------------
        ofstream f("data.bin", ios::binary);

        Syntax:
            f.write(pointer_ke_data, jumlah_byte);

        Untuk variabel biasa (int, double, struct, dll):
            int nilai = 42;
            f.write(reinterpret_cast<char*>(&nilai), sizeof(nilai));

        reinterpret_cast<char*> = lihat data ini sebagai array byte (char*)
        sizeof(nilai)            = berapa byte yang perlu ditulis
    */
    
    /* MEMBACA BINARY: read()
        -------------------------------------------------------
        ifstream f("data.bin", ios::binary);

        Syntax:
            f.read(pointer_ke_buffer, jumlah_byte);

        Untuk variabel biasa:
            int hasil;
            f.read(reinterpret_cast<char*>(&hasil), sizeof(hasil));

        Setelah read(), cek f.gcount() untuk tahu berapa byte terbaca.
    */

    /* REINTERPRET_CAST
        -------------------------------------------------------
        reinterpret_cast<char*>(&nilai) artinya:
        "Pandang address dari variabel 'nilai' sebagai pointer ke char".

        Ini perlu karena write()/read() bekerja dengan byte (char*),
        sedangkan variabel kita bisa berupa int, double, struct, dll.
    */
    
    /* KAPAN PAKAI BINARY?
        -------------------------------------------------------
            - Simpan array besar angka (lebih cepat dan kecil)
            - Simpan struct yang tetap (fixed-size record)
            - Baca file gambar/audio/video
            - Protocol komunikasi (jaringan, serial)
            - Database sederhana
    */

// AA.8 - String Stream
    
    /* TIGA KELAS STRING STREAM
        -------------------------------------------------------
        stringstream  -> baca DAN tulis ke string
        istringstream -> hanya baca dari string (parse)
        ostringstream -> hanya tulis ke string (format/build)

        Header: #include <sstream>
    */

    /* CARA PAKAI stringstream
        -------------------------------------------------------
        // Tulis ke stringstream
        stringstream ss;
        ss << "Halo " << 42 << " nilai: " << 3.14;
        string hasil = ss.str();   // ambil hasilnya sebagai string

        // Baca dari stringstream
        stringstream ss2("10 20 30");
        int a, b, c;
        ss2 >> a >> b >> c;   // a=10, b=20, c=30

        // Reset isi
        ss.str("");    // kosongkan isi
        ss.clear();    // reset state flags
    */
    
    /* FUNGSI str()
        -------------------------------------------------------
        ss.str()          -> dapatkan isi sebagai string (read)
        ss.str("isi baru") -> set isi string (write/reset)
    */

// AA.9 - Pola Praktis File
    
    /* POLA-POLA PRAKTIS FILE I/O
        -------------------------------------------------------
        File ini mengumpulkan pola yang sering dipakai dalam
        program nyata. Bukan teori baru, tapi kombinasi dari
        semua yang sudah dipelajari sebelumnya.

        Pola yang dibahas:
            1. Simpan dan muat array struct ke/dari file teks
            2. Simpan dan muat data CSV
            3. Sistem logging ke file
            4. Cek keberadaan file (exists)
            5. Hitung jumlah baris dan kata dalam file
            6. Backup file (copy file)
            7. Pola RAII dengan scope block
    */

    /* POLA RAII UNTUK FILE
        -------------------------------------------------------
        Gunakan scope block {} untuk pastikan file ditutup otomatis:

            {
                ofstream fw("data.txt");
                fw << "data" << endl;
            }   // fw ditutup otomatis di sini

        Lebih aman dari lupa file.close() di tengah fungsi panjang.
    */
    
    /* POLA BACA STRUCTURED DATA
        -------------------------------------------------------
        Paling umum: baris per baris dengan getline,
        lalu parse setiap baris dengan stringstream.

            ifstream f("data.csv");
            string baris;
            while (getline(f, baris)) {
                stringstream ss(baris);
                string nama, nilaiStr;
                getline(ss, nama, ',');
                getline(ss, nilaiStr, ',');
                int nilai = stoi(nilaiStr);
            }
    */
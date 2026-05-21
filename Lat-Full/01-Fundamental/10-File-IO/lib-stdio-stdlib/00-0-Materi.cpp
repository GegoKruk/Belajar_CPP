/*
    DAFTAR ISI MODUL FILE I/O - GAYA C (stdio.h & stdlib.h)
    ============================================================
    00  Overview
    01  Menulis-File-fprintf
    02  Membaca-File-fscanf
    03  Mode-Buka-File
    04  File-Positioning
    05  Error-Handling
    06  Binary-File-fread-fwrite
    07  Formatted-IO-sprintf-sscanf
    08  Pola-Praktis-File-IO
    ============================================================
*/

// AA.0 - Overview

    /* APA ITU stdio.h DAN stdlib.h?
        -------------------------------------------------------
        stdio.h  (Standard Input/Output) : header utama untuk operasi I/O di C, termasuk baca/tulis file.

        stdlib.h (Standard Library)      : berisi fungsi umum
                seperti malloc, free, atoi, exit, dll.
                Untuk file I/O, stdlib.h jarang dipakai langsung,
                tapi sering disertakan bersama stdio.h.

        Di C++, versi "bersih"-nya adalah:
            #include <cstdio>    (sama dengan stdio.h tapi namespace std)
            #include <cstdlib>   (sama dengan stdlib.h tapi namespace std)

        Tapi di kuliah ini kita pakai versi C klasik: stdio.h & stdlib.h.
    */

    /* KENAPA BELAJAR INI PADAHAL ADA fstream?
        -------------------------------------------------------
        1. Legacy code : banyak kode lama (C, embedded, sistem)
            masih pakai FILE* dan stdio.h. Wajib bisa baca.

        2. Interoperabilitas : beberapa library C/C++ menerima
            parameter FILE* (bukan fstream).

        3. Lebih sederhana untuk kasus tertentu : fread/fwrite
            jauh lebih ringkas dari write() + reinterpret_cast.

        4. Wajib di mata kuliah ini : diajarkan eksplisit.
    */

    /* KONSEP UTAMA: FILE POINTER (FILE*)
        -------------------------------------------------------
        Di C, file direpresentasikan sebagai pointer ke struct FILE.

            FILE* file;

        FILE* adalah "handle" (pegangan) ke file yang sedang dibuka.
        Semua fungsi stdio menerima FILE* sebagai parameter.

        Analogi:
            FILE* file  = pegangan pintu ke sebuah ruangan (file)
            fopen()     = membuka pintu dan pegang gagangnya
            fprintf()   = menulis sesuatu ke dalam ruangan
            fclose()    = melepas gagang dan menutup pintu

        PENTING: FILE* bukan fstream. Ini dua sistem yang berbeda.
    */

    /* HEADER YANG DIBUTUHKAN
        -------------------------------------------------------
        #include <stdio.h>    : FILE*, fopen, fclose, fprintf,
                                fscanf, fgets, fgetc, fputc,
                                fread, fwrite, fseek, ftell,
                                rewind, feof, ferror, perror

        #include <stdlib.h>   : atoi, atof, malloc, free, exit

        #include <string.h>   : strlen, strcpy, strcmp, strtok
                                (sering dipakai saat proses teks dari file)

        Opsional:
        #include <errno.h>    : variabel errno untuk kode error sistem
    */

    /* POLA DASAR WAJIB (SELALU IKUTI INI)
        -------------------------------------------------------
        1. Buka file dengan fopen()
        2. CEK apakah hasilnya NULL (gagal) <- sering dilupakan!
        3. Baca atau tulis data
        4. Tutup file dengan fclose()

        Contoh:
            FILE* file = fopen("data.txt", "w");
            if (file == NULL) {
                perror("Gagal buka file");
                return 1;
            }
            fprintf(file, "Halo, File!\n");
            fclose(file);

        TIDAK ADA RAII di C! File TIDAK otomatis ditutup.
        Kalau lupa fclose(), data bisa tidak tersimpan / resource leak.
    */

    /* PERBANDINGAN CEPAT: FILE* vs fstream
        -------------------------------------------------------
        Aspek               FILE* (stdio)           fstream (C++)
        ------------------  ----------------------  ----------------------
        Header              stdio.h                 <fstream>
        Handle              FILE*                   ifstream/ofstream/fstream
        Buka file           fopen("f.txt", "r")     ifstream f("f.txt")
        Cek berhasil        hasil != NULL           f.is_open() atau !f
        Tulis               fprintf(f, "%d", x)     f << x
        Baca                fscanf(f, "%d", &x)     f >> x
        Baca baris          fgets(buf, n, f)        getline(f, str)
        Tutup               fclose(f)               f.close() atau otomatis
        RAII                TIDAK ADA               Ada (otomatis tutup)
        Binary tulis        fwrite(&x, size, n, f)  f.write((char*)&x, size)
        Binary baca         fread(&x, size, n, f)   f.read((char*)&x, size)
        Posisi kursor       ftell / fseek            tellg/tellp/seekg/seekp
        Cek EOF             feof(f)                 f.eof()
        Cek error           ferror(f)               f.fail() / f.bad()
    */

    /* FUNGSI-FUNGSI UTAMA stdio.h
        -------------------------------------------------------
        Membuka / Menutup:
            fopen(path, mode)   : buka file, return FILE* atau NULL
            fclose(FILE*)       : tutup file

        Menulis:
            fprintf(FILE*, format, ...)   : tulis dengan format (seperti printf)
            fputs(string, FILE*)          : tulis string tanpa format
            fputc(char, FILE*)            : tulis satu karakter

        Membaca:
            fscanf(FILE*, format, &var)   : baca dengan format (seperti scanf)
            fgets(buffer, ukuran, FILE*)  : baca satu baris (LEBIH AMAN)
            fgetc(FILE*)                  : baca satu karakter, return int

        Posisi kursor:
            ftell(FILE*)                        : posisi kursor saat ini
            fseek(FILE*, offset, origin)        : pindah kursor
            rewind(FILE*)                       : balik ke awal file

        Binary:
            fwrite(ptr, ukuran, jumlah, FILE*)  : tulis blok data
            fread(ptr, ukuran, jumlah, FILE*)   : baca blok data

        Cek status:
            feof(FILE*)     : return 1 jika sudah di akhir file
            ferror(FILE*)   : return 1 jika ada error I/O
            clearerr(FILE*) : reset flag eof dan error

        Pesan error:
            perror("pesan") : cetak pesan error sistem ke stderr
    */


// AA.1 - Menulis File dengan fprintf

    /* fopen() UNTUK MENULIS
        -------------------------------------------------------
        FILE* file = fopen("nama_file.txt", "w");

        Mode "w" : Write (tulis)
            - Jika file belum ada -> dibuat otomatis
            - Jika file sudah ada -> isinya DIHAPUS (overwrite)
            - Kursor mulai dari awal

        Mode "a" : Append (tambah)
            - Jika file belum ada -> dibuat otomatis
            - Jika file sudah ada -> isi lama DIPERTAHANKAN
            - Data baru ditambah di AKHIR file

        Return value:
            FILE*  : berhasil, simpan pointer ini
            NULL   : gagal (file tidak bisa dibuat/dibuka)
    */

    /* WAJIB CEK NULL SEBELUM MENULIS
        -------------------------------------------------------
        FILE* file = fopen("data.txt", "w");
        if (file == NULL) {
            perror("Gagal membuka file");   // cetak penyebab error
            return 1;                        // keluar dari fungsi
        }

        Kalau tidak dicek dan langsung fprintf ke NULL -> crash (segfault).
    */

    /* fprintf() - MENULIS DENGAN FORMAT
        -------------------------------------------------------
        Persis seperti printf(), tapi output ke FILE* bukan layar.

        Syntax:
            fprintf(FILE* file, const char* format, ...);

        Contoh:
            fprintf(file, "Nama: %s\n", nama);
            fprintf(file, "Nilai: %d\n", nilai);
            fprintf(file, "IPK: %.2f\n", ipk);
            fprintf(file, "Baris biasa tanpa variabel\n");

        Format specifier sama persis dengan printf:
            %d   : integer
            %f   : float/double
            %s   : string (char array)
            %c   : karakter
            %ld  : long int
            %lf  : double (khusus scanf, fprintf sama saja %f)
    */

    /* fputs() DAN fputc() - ALTERNATIF PENULISAN
        -------------------------------------------------------
        fputs(string, file)  : tulis string tanpa tambahan newline
            fputs("Halo dunia", file);   // tidak tambah \n otomatis
            fputs("Halo dunia\n", file); // kalau mau newline, tulis sendiri

        fputc(karakter, file) : tulis SATU karakter
            fputc('A', file);
            fputc('\n', file);

        Kapan pakai fputs vs fprintf?
            fputs  : kalau tidak perlu format, sedikit lebih cepat
            fprintf: kalau perlu sisipkan variabel ke dalam string
    */

    /* fclose() - MENUTUP FILE
        -------------------------------------------------------
        fclose(file);

        WAJIB dipanggil setelah selesai!
        Alasan:
            1. Data di buffer di-flush (ditulis) ke disk
            2. Resource file descriptor dilepas ke sistem
            3. Kalau tidak ditutup, data bisa HILANG / tidak tersimpan

        Di C++ dengan fstream, file otomatis ditutup saat keluar scope.
        Di C dengan FILE*, TIDAK ADA mekanisme otomatis seperti itu.
    */


// AA.2 - Membaca File dengan fscanf dan fgets

    /* fopen() UNTUK MEMBACA
        -------------------------------------------------------
        FILE* file = fopen("nama_file.txt", "r");

        Mode "r" : Read (baca)
            - File HARUS sudah ada. Kalau tidak ada -> return NULL.
            - Hanya bisa baca, tidak bisa tulis.
            - Kursor mulai dari awal.

        Return value:
            FILE*  : berhasil dibuka
            NULL   : file tidak ditemukan atau tidak bisa dibaca
    */

    /* CARA 1 - fscanf(): Baca dengan Format (Token per Token)
        -------------------------------------------------------
        Syntax:
            int hasil = fscanf(FILE* file, const char* format, &var, ...);

        Return value:
            - Jumlah item yang berhasil dibaca
            - EOF (-1) jika sudah akhir file atau error

        Contoh:
            int angka;
            while (fscanf(file, "%d", &angka) == 1) {
                printf("%d\n", angka);
            }

        Cocok untuk:
            - Data angka yang dipisah spasi atau newline
            - Format data yang sudah terstruktur rapi

        JEBAKAN fscanf dengan %s:
            char nama[50];
            fscanf(file, "%s", nama);   // BERBAHAYA jika nama > 49 karakter!

        Cara lebih aman:
            fscanf(file, "%49s", nama);  // batasi maksimal 49 karakter
    */

    /* CARA 2 - fgets(): Baca Satu Baris (PALING AMAN)
        -------------------------------------------------------
        Syntax:
            char* hasil = fgets(buffer, ukuran_maks, FILE* file);

        Parameter:
            buffer      : array char tempat menyimpan hasil
            ukuran_maks : maksimal karakter yang dibaca (termasuk '\0')
            file        : handle file

        Return value:
            char* (sama dengan buffer) : berhasil baca satu baris
            NULL                       : akhir file atau error

        Contoh:
            char baris[256];
            while (fgets(baris, sizeof(baris), file) != NULL) {
                printf("%s", baris);  // baris sudah mengandung '\n'
            }

        Catatan penting:
            - fgets menyertakan karakter '\n' di akhir string
            - Kalau mau hilangkan '\n', pakai:
                baris[strcspn(baris, "\n")] = '\0';

        Kenapa fgets lebih aman dari fscanf %s?
            - fgets punya batas ukuran buffer -> tidak mungkin overflow
            - fscanf %s bisa nulis melebihi buffer kalau tidak dibatasi
    */

    /* CARA 3 - fgetc(): Baca Satu Karakter
        -------------------------------------------------------
        Syntax:
            int c = fgetc(FILE* file);

        Return value:
            int (nilai karakter sebagai unsigned char) : berhasil
            EOF (-1)                                   : akhir file atau error

        Kenapa return int, bukan char?
            Karena EOF adalah -1, dan char bisa saja tidak bisa simpan -1
            (tergantung apakah char signed atau unsigned di platform itu).
            Dengan int, EOF aman dibedakan dari karakter biasa.

        Contoh:
            int c;
            while ((c = fgetc(file)) != EOF) {
                printf("%c", (char)c);
            }
    */

    /* JEBAKAN: while (!feof(file)) ADALAH POLA YANG SALAH
        -------------------------------------------------------
        JANGAN lakukan ini:
            while (!feof(file)) {
                fscanf(file, "%d", &x);  // bisa baca data sampah di akhir!
            }

        Mengapa salah?
            feof() baru return 1 SETELAH pembacaan gagal di EOF.
            Artinya, loop akan jalan SATU KALI EKSTRA setelah data habis,
            dan fscanf di iterasi terakhir itu bisa gagal atau isi x dengan
            nilai lama / tidak valid.

        CARA BENAR: cek return value fungsi baca-nya langsung:
            while (fscanf(file, "%d", &x) == 1) { ... }
            while (fgets(baris, sizeof(baris), file) != NULL) { ... }
            while ((c = fgetc(file)) != EOF) { ... }
    */


// AA.3 - Mode Buka File

    /* TABEL LENGKAP MODE fopen()
        -------------------------------------------------------
        Mode   Baca  Tulis  Buat baru  Hapus isi  Posisi awal
        -----  ----  -----  ---------  ---------  -----------
        "r"    Ya    Tidak  Tidak      Tidak      Awal
        "w"    Tidak Ya     Ya         Ya         Awal
        "a"    Tidak Ya     Ya         Tidak      Akhir
        "r+"   Ya    Ya     Tidak      Tidak      Awal
        "w+"   Ya    Ya     Ya         Ya         Awal
        "a+"   Ya    Ya     Ya         Tidak      Akhir (tulis selalu ke akhir)

        Tambahkan "b" untuk mode binary:
        "rb"   "wb"  "ab"  "rb+"  "wb+"  "ab+"

        Contoh:
            FILE* f1 = fopen("data.txt",  "r");    // baca saja
            FILE* f2 = fopen("data.txt",  "w");    // tulis, hapus isi lama
            FILE* f3 = fopen("data.txt",  "a");    // tambah di akhir
            FILE* f4 = fopen("data.txt",  "r+");   // baca dan tulis, file harus ada
            FILE* f5 = fopen("data.txt",  "w+");   // baca dan tulis, hapus isi lama
            FILE* f6 = fopen("data.bin",  "rb");   // baca binary
            FILE* f7 = fopen("data.bin",  "wb");   // tulis binary
    */

    /* DETAIL MODE "r+" vs "w+" vs "a+"
        -------------------------------------------------------
        "r+" : Baca dan Tulis
            - File HARUS sudah ada (tidak bisa buat baru)
            - Isi lama DIPERTAHANKAN
            - Bisa baca dan tulis di posisi mana saja (dengan fseek)
            - Cocok untuk UPDATE data di tengah file

        "w+" : Baca dan Tulis (dengan reset)
            - File dibuat kalau belum ada
            - Isi lama DIHAPUS
            - Bisa baca dan tulis
            - Cocok kalau mau tulis ulang dari awal tapi juga perlu baca

        "a+" : Baca dan Tulis (append)
            - File dibuat kalau belum ada
            - Penulisan SELALU ke akhir file (tidak peduli posisi kursor)
            - Pembacaan bisa dari posisi mana saja (dengan fseek)
            - Cocok untuk log yang perlu dibaca sekaligus ditambah
    */

    /* PERBANDINGAN DENGAN MODE fstream
        -------------------------------------------------------
        stdio mode   fstream equivalent
        ----------   ------------------------------------------
        "r"          ios::in
        "w"          ios::out  (atau ios::out | ios::trunc)
        "a"          ios::app
        "r+"         ios::in | ios::out
        "w+"         ios::in | ios::out | ios::trunc
        "rb"         ios::in | ios::binary
        "wb"         ios::out | ios::binary
    */


// AA.4 - File Positioning

    /* KURSOR FILE
        -------------------------------------------------------
        Setiap file yang dibuka memiliki kursor (posisi baca/tulis).
        Kursor bergerak maju otomatis setiap kali baca atau tulis.

        Contoh: file berisi "ABCDE"
            Setelah buka  : kursor di posisi 0 (sebelum 'A')
            Setelah baca 1: kursor di posisi 1 (sebelum 'B')
            Setelah baca 2: kursor di posisi 2 (sebelum 'C')

        Di C, hanya ADA SATU kursor untuk baca dan tulis (berbeda
        dengan fstream yang punya seekg dan seekp secara terpisah).
    */

    /* ftell() - DAPATKAN POSISI KURSOR SAAT INI
        -------------------------------------------------------
        Syntax:
            long posisi = ftell(FILE* file);

        Return value:
            long  : posisi kursor dalam byte dari awal file
            -1L   : error

        Contoh:
            FILE* f = fopen("data.txt", "r");
            long pos = ftell(f);     // pos = 0
            fgetc(f);                // baca satu karakter
            pos = ftell(f);          // pos = 1
    */

    /* fseek() - PINDAH KURSOR
        -------------------------------------------------------
        Syntax:
            int hasil = fseek(FILE* file, long offset, int origin);

        Parameter origin (titik acuan):
            SEEK_SET : hitung dari AWAL file        (posisi 0)
            SEEK_CUR : hitung dari POSISI SAAT INI
            SEEK_END : hitung dari AKHIR file

        offset : jumlah byte yang dipindah (bisa negatif untuk mundur)

        Return value:
            0    : berhasil
            != 0 : gagal

        Contoh:
            fseek(f, 0, SEEK_SET);    // ke awal file
            fseek(f, 0, SEEK_END);    // ke akhir file
            fseek(f, 5, SEEK_SET);    // ke byte ke-5 dari awal
            fseek(f, -3, SEEK_CUR);   // mundur 3 byte dari posisi kini
            fseek(f, -1, SEEK_END);   // 1 byte sebelum akhir file
    */

    /* rewind() - KEMBALI KE AWAL FILE
        -------------------------------------------------------
        Syntax:
            rewind(FILE* file);

        Persis sama dengan: fseek(file, 0, SEEK_SET);
        Tapi rewind() juga mereset flag error (ferror), sedangkan
        fseek(0, SEEK_SET) tidak.

        Contoh penggunaan:
            // Baca file dua kali
            while ((c = fgetc(f)) != EOF) { ... }   // baca pertama
            rewind(f);                                // balik ke awal
            while ((c = fgetc(f)) != EOF) { ... }   // baca kedua
    */

    /* POLA: HITUNG UKURAN FILE
        -------------------------------------------------------
        fseek(f, 0, SEEK_END);      // pindah ke akhir file
        long ukuran = ftell(f);     // posisi = ukuran total dalam byte
        rewind(f);                   // balik ke awal untuk baca normal

        Ini idiom umum di C untuk tahu berapa byte isi sebuah file.
    */

    /* PERBANDINGAN DENGAN fstream
        -------------------------------------------------------
        stdio               fstream
        ----------------    --------------------------------
        ftell(f)            f.tellg() atau f.tellp()
        fseek(f,x,SET)      f.seekg(x) atau f.seekp(x)
        fseek(f,x,CUR)      f.seekg(x, ios::cur)
        fseek(f,x,END)      f.seekg(x, ios::end)
        rewind(f)           f.seekg(0)

        Di stdio, hanya ada satu kursor (satu fseek/ftell).
        Di fstream, ada dua kursor terpisah: seekg (baca) dan seekp (tulis).
    */


// AA.5 - Error Handling

    /* SUMBER ERROR SAAT FILE I/O
        -------------------------------------------------------
        1. File tidak ditemukan         -> fopen() return NULL
        2. Tidak ada izin baca/tulis    -> fopen() return NULL
        3. Disk penuh saat menulis      -> ferror() return nonzero
        4. File terhapus saat dibaca    -> ferror() return nonzero
        5. Format data tidak cocok      -> fscanf() return jumlah < ekspektasi
    */

    /* CEK fopen(): SELALU CEK NULL
        -------------------------------------------------------
        FILE* f = fopen("data.txt", "r");
        if (f == NULL) {
            perror("Gagal membuka file");
            return 1;
        }

        Tanpa pengecekan ini, semua operasi selanjutnya ke f akan crash.
    */

    /* perror() - CETAK PESAN ERROR SISTEM
        -------------------------------------------------------
        Syntax:
            perror(const char* pesan_kita);

        perror() mencetak: "[pesan_kita]: [deskripsi error dari sistem]"

        Contoh output di terminal:
            perror("Gagal membuka file");
            -> "Gagal membuka file: No such file or directory"

        perror() membaca variabel global 'errno' yang diisi otomatis
        oleh sistem saat terjadi error. Output ke stderr (bukan stdout).

        Lebih informatif dari sekadar printf("Gagal!").
    */

    /* ferror() - CEK ERROR I/O SETELAH OPERASI
        -------------------------------------------------------
        Syntax:
            int hasil = ferror(FILE* file);

        Return value:
            0        : tidak ada error
            nonzero  : ada error I/O

        Kapan dipakai?
            Saat ingin tahu apakah operasi baca/tulis berhasil,
            terutama untuk fwrite() dan fread().

        Contoh:
            fwrite(data, sizeof(data), 1, f);
            if (ferror(f)) {
                perror("Gagal menulis ke file");
            }
    */

    /* feof() - CEK AKHIR FILE
        -------------------------------------------------------
        Syntax:
            int hasil = feof(FILE* file);

        Return value:
            0        : belum di akhir file
            nonzero  : sudah di akhir file

        INGAT: feof() return nonzero SETELAH pembacaan gagal karena EOF.
        Jadi jangan jadikan feof() sebagai kondisi loop utama!

        Cara benar:
            while (fgets(baris, sizeof(baris), f) != NULL) { ... }

        Cara salah:
            while (!feof(f)) { fgets(...); }   // bisa proses data duplikat!
    */

    /* clearerr() - RESET FLAG ERROR DAN EOF
        -------------------------------------------------------
        Syntax:
            clearerr(FILE* file);

        Mereset flag ferror dan feof ke 0.
        Berguna kalau mau lanjut baca/tulis setelah handle error,
        atau setelah rewind() di beberapa implementasi.

        Contoh:
            rewind(f);
            clearerr(f);   // pastikan flag EOF juga bersih
    */

    /* POLA ERROR HANDLING LENGKAP
        -------------------------------------------------------
        FILE* f = fopen("data.txt", "r");
        if (f == NULL) {
            perror("fopen gagal");
            return 1;
        }

        char baris[256];
        while (fgets(baris, sizeof(baris), f) != NULL) {
            // proses baris
        }

        if (ferror(f)) {
            perror("Error saat membaca file");
            fclose(f);
            return 1;
        }

        fclose(f);
        return 0;
    */


// AA.6 - Binary File: fread dan fwrite

    /* FILE TEKS vs FILE BINARY (REVIEW)
        -------------------------------------------------------
        File Teks:
            - Data disimpan sebagai karakter (ASCII)
            - Angka 12345 disimpan sebagai 5 karakter: '1','2','3','4','5'
            - Newline '\n' mungkin dikonversi ke '\r\n' di Windows
            - Bisa dibuka dan dibaca di Notepad

        File Binary:
            - Data disimpan dalam format biner aslinya
            - Angka 12345 (int, 4 byte) disimpan sebagai 4 byte biner
            - Tidak ada konversi newline
            - Tidak terbaca di Notepad (tampil karakter aneh)
            - Lebih kecil dan lebih cepat untuk data numerik
    */

    /* fwrite() - MENULIS DATA BINER
        -------------------------------------------------------
        Syntax:
            size_t n = fwrite(const void* ptr, size_t ukuran_elemen,
                            size_t jumlah_elemen, FILE* file);

        Parameter:
            ptr             : pointer ke data yang ingin ditulis
            ukuran_elemen   : ukuran SATU elemen dalam byte (pakai sizeof)
            jumlah_elemen   : berapa elemen yang ditulis
            file            : handle file (harus dibuka mode binary "wb" dll)

        Return value:
            size_t : jumlah elemen yang berhasil ditulis
                    jika berbeda dari jumlah_elemen -> ada error

        Contoh menulis satu int:
            int nilai = 42;
            fwrite(&nilai, sizeof(int), 1, file);

        Contoh menulis array:
            int arr[5] = {1, 2, 3, 4, 5};
            fwrite(arr, sizeof(int), 5, file);

        Contoh menulis struct:
            struct Mahasiswa mhs = {"Budi", 90};
            fwrite(&mhs, sizeof(struct Mahasiswa), 1, file);
    */

    /* fread() - MEMBACA DATA BINER
        -------------------------------------------------------
        Syntax:
            size_t n = fread(void* ptr, size_t ukuran_elemen,
                            size_t jumlah_elemen, FILE* file);

        Parameter:
            ptr             : pointer ke buffer tempat menyimpan hasil baca
            ukuran_elemen   : ukuran SATU elemen dalam byte
            jumlah_elemen   : berapa elemen yang ingin dibaca
            file            : handle file

        Return value:
            size_t : jumlah elemen yang berhasil dibaca
                    jika < jumlah_elemen -> akhir file atau error

        Contoh membaca satu int:
            int nilai;
            fread(&nilai, sizeof(int), 1, file);

        Contoh membaca array:
            int arr[5];
            size_t terbaca = fread(arr, sizeof(int), 5, file);

        Contoh membaca struct:
            struct Mahasiswa mhs;
            fread(&mhs, sizeof(struct Mahasiswa), 1, file);
    */

    /* MENGAPA fread/fwrite LEBIH SIMPEL DARI fstream?
        -------------------------------------------------------
        Di fstream (C++), untuk tulis binary:
            file.write(reinterpret_cast<char*>(&nilai), sizeof(nilai));

        Di stdio (C), cukup:
            fwrite(&nilai, sizeof(nilai), 1, file);

        Tidak perlu reinterpret_cast! fwrite menerima void* langsung,
        jadi pointer ke tipe apapun otomatis diterima tanpa cast eksplisit.
        Ini salah satu kelebihan gaya C untuk operasi binary.
    */

    /* POLA LOOP BACA BINARY SAMPAI EOF
        -------------------------------------------------------
        struct Mahasiswa mhs;
        while (fread(&mhs, sizeof(struct Mahasiswa), 1, file) == 1) {
            // proses satu record mhs
        }

        Cek return value fread() == 1 (atau == jumlah yang diharapkan)
        adalah cara benar untuk deteksi EOF, bukan feof().
    */

    /* KAPAN PAKAI BINARY?
        -------------------------------------------------------
            - Simpan array besar angka (lebih cepat dan lebih kecil)
            - Simpan struct yang ukurannya tetap (fixed-size record)
            - Baca file gambar, audio, video
            - Protokol komunikasi (serial, jaringan)
            - Database sederhana berbasis file
    */


// AA.7 - Formatted I/O: sprintf dan sscanf

    /* APA ITU sprintf DAN sscanf?
        -------------------------------------------------------
        sprintf  : seperti fprintf, tapi output ke STRING (bukan file)
        sscanf   : seperti fscanf, tapi input dari STRING (bukan file)

        Fungsi-fungsi ini adalah analog C dari stringstream di C++.

        Header: stdio.h (sudah termasuk, tidak perlu tambahan)
    */

    /* sprintf() - FORMAT KE STRING
        -------------------------------------------------------
        Syntax:
            int n = sprintf(char* buffer, const char* format, ...);

        Parameter:
            buffer  : array char tempat menyimpan hasil
            format  : format string (sama dengan printf)
            ...     : nilai-nilai yang diformat

        Return value:
            int : jumlah karakter yang ditulis (tidak termasuk '\0')

        Contoh:
            char hasil[100];
            int umur = 20;
            float ipk = 3.75;
            sprintf(hasil, "Umur: %d, IPK: %.2f", umur, ipk);
            // hasil sekarang: "Umur: 20, IPK: 3.75"

        Penggunaan umum:
            - Membangun string dari berbagai tipe data
            - Membuat nama file dinamis: sprintf(nama, "data_%d.txt", id);
    */

    /* BAHAYA sprintf(): BUFFER OVERFLOW
        -------------------------------------------------------
        sprintf TIDAK ada batas ukuran buffer!
        Jika output lebih panjang dari buffer -> BUFFER OVERFLOW!

        SELALU pakai snprintf() sebagai gantinya:

        Syntax snprintf:
            int n = snprintf(char* buffer, size_t ukuran_maks, const char* format, ...);

        snprintf hanya menulis maksimal (ukuran_maks - 1) karakter,
        lalu tambah '\0' otomatis. Aman dari overflow.

        Contoh aman:
            char buffer[50];
            snprintf(buffer, sizeof(buffer), "Data: %s", nama_panjang);
    */

    /* sscanf() - PARSE DARI STRING
        -------------------------------------------------------
        Syntax:
            int n = sscanf(const char* string, const char* format, &var, ...);

        Return value:
            int : jumlah item yang berhasil diparsing
            EOF : error

        Contoh:
            char baris[] = "Budi 85 3.50";
            char nama[50];
            int nilai;
            float ipk;
            sscanf(baris, "%s %d %f", nama, &nilai, &ipk);
            // nama = "Budi", nilai = 85, ipk = 3.50

        Contoh parse CSV (koma sebagai pemisah):
            char baris[] = "Budi,85,3.50";
            sscanf(baris, "%[^,],%d,%f", nama, &nilai, &ipk);
            // %[^,] : baca karakter sampai ketemu koma
    */

    /* POLA UMUM: fgets + sscanf UNTUK BACA FILE TERSTRUKTUR
        -------------------------------------------------------
        Ini pola yang paling sering dipakai untuk baca file teks berstruktur:

        1. Baca satu baris dengan fgets (aman, tidak overflow)
        2. Parse baris tersebut dengan sscanf (fleksibel)

        Contoh:
            char baris[256];
            char nama[50];
            int nilai;

            while (fgets(baris, sizeof(baris), file) != NULL) {
                if (sscanf(baris, "%49s %d", nama, &nilai) == 2) {
                    // berhasil parse, proses data
                }
                // kalau sscanf return != 2, skip baris itu (format tidak cocok)
            }

        Keuntungan dibanding fscanf langsung ke file:
            - fgets lebih aman (ada batas buffer)
            - Kalau satu baris format salah, tidak ganggu baris berikutnya
            - Bisa inspeksi/debug isi baris sebelum diparse
    */

    /* PERBANDINGAN DENGAN C++ stringstream
        -------------------------------------------------------
        C++ (fstream):
            stringstream ss("Budi 85");
            string nama; int nilai;
            ss >> nama >> nilai;

        C (stdio):
            char baris[] = "Budi 85";
            char nama[50]; int nilai;
            sscanf(baris, "%s %d", nama, &nilai);

        Keduanya tujuannya sama: parse data dari string.
        sscanf lebih ringkas tapi lebih rentan overflow kalau tidak hati-hati.
    */


// AA.8 - Pola Praktis File I/O (C-style)

    /* CATATAN UMUM TENTANG POLA C-STYLE
        -------------------------------------------------------
        Di C, tidak ada RAII. Tidak ada destructor yang otomatis tutup file.
        Setiap fopen() HARUS diimbangi fclose() secara eksplisit.

        Ini membuat kode C lebih rawan resource leak dibanding C++.
        Solusinya: selalu punya satu jalur keluar yang pasti panggil fclose().

        Pola aman:
            FILE* f = fopen(...);
            if (!f) return 1;
            // ... proses ...
            fclose(f);      // <- JANGAN LUPA
            return 0;
    */

    /* POLA 1: Simpan Array Struct ke File Teks
        -------------------------------------------------------
        struct Mahasiswa { char nama[50]; int nilai; };

        // Menyimpan
        FILE* fw = fopen("mhs.txt", "w");
        for (int i = 0; i < n; i++) {
            fprintf(fw, "%s %d\n", data[i].nama, data[i].nilai);
        }
        fclose(fw);

        // Memuat
        FILE* fr = fopen("mhs.txt", "r");
        int i = 0;
        while (fscanf(fr, "%49s %d", data[i].nama, &data[i].nilai) == 2) {
            i++;
        }
        fclose(fr);
    */

    /* POLA 2: Simpan Array Struct ke File Binary
        -------------------------------------------------------
        struct Mahasiswa { char nama[50]; int nilai; };

        // Menyimpan
        FILE* fw = fopen("mhs.bin", "wb");
        fwrite(data, sizeof(struct Mahasiswa), n, fw);
        fclose(fw);

        // Memuat
        FILE* fr = fopen("mhs.bin", "rb");
        struct Mahasiswa mhs;
        int i = 0;
        while (fread(&mhs, sizeof(struct Mahasiswa), 1, fr) == 1) {
            data[i++] = mhs;
        }
        fclose(fr);

        Binary jauh lebih simpel untuk struct: tulis dan baca sekaligus,
        tidak perlu format string, tidak ada risiko parse error.
    */

    /* POLA 3: Baca File CSV dengan fgets + sscanf
        -------------------------------------------------------
        // File: nilai.csv
        // Isi:
        //   Budi,85,3.50
        //   Ani,92,3.80

        FILE* f = fopen("nilai.csv", "r");
        char baris[256];
        char nama[50];
        int nilai;
        float ipk;

        while (fgets(baris, sizeof(baris), f) != NULL) {
            if (sscanf(baris, "%49[^,],%d,%f", nama, &nilai, &ipk) == 3) {
                printf("Nama: %s | Nilai: %d | IPK: %.2f\n", nama, nilai, ipk);
            }
        }
        fclose(f);
    */

    /* POLA 4: Sistem Logging (Append ke File)
        -------------------------------------------------------
        void tulis_log(const char* pesan) {
            FILE* f = fopen("app.log", "a");
            if (f == NULL) {
                perror("Gagal buka log");
                return;
            }
            fprintf(f, "[LOG] %s\n", pesan);
            fclose(f);
        }

        Dengan mode "a", setiap panggil tulis_log() akan tambah
        baris baru tanpa hapus log sebelumnya.
    */

    /* POLA 5: Hitung Ukuran File
        -------------------------------------------------------
        FILE* f = fopen("data.bin", "rb");
        fseek(f, 0, SEEK_END);
        long ukuran = ftell(f);
        rewind(f);
        printf("Ukuran file: %ld byte\n", ukuran);
        fclose(f);
    */

    /* POLA 6: Copy File (Karakter per Karakter)
        -------------------------------------------------------
        FILE* src = fopen("asli.txt", "rb");
        FILE* dst = fopen("salinan.txt", "wb");
        int c;
        while ((c = fgetc(src)) != EOF) {
            fputc(c, dst);
        }
        fclose(src);
        fclose(dst);
    */

    /* POLA 7: Copy File dengan Buffer (Lebih Cepat)
        -------------------------------------------------------
        FILE* src = fopen("asli.bin", "rb");
        FILE* dst = fopen("salinan.bin", "wb");

        char buffer[4096];     // buffer 4KB
        size_t terbaca;

        while ((terbaca = fread(buffer, 1, sizeof(buffer), src)) > 0) {
            fwrite(buffer, 1, terbaca, dst);
        }

        fclose(src);
        fclose(dst);

        Jauh lebih cepat dari karakter per karakter karena
        meminimalkan jumlah panggilan sistem (system call).
    */

    /* POLA 8: Cek Apakah File Ada
        -------------------------------------------------------
        int file_ada(const char* path) {
            FILE* f = fopen(path, "r");
            if (f == NULL) return 0;   // tidak ada atau tidak bisa dibuka
            fclose(f);
            return 1;
        }

        Tidak ada fungsi khusus "file exists" di stdio standar.
        Trik ini cukup portabel untuk kebutuhan dasar.
    */

    /* POLA 9: Baca Seluruh File ke Buffer
        -------------------------------------------------------
        FILE* f = fopen("data.txt", "rb");

        fseek(f, 0, SEEK_END);
        long ukuran = ftell(f);
        rewind(f);

        char* isi = (char*)malloc(ukuran + 1);   // +1 untuk '\0'
        fread(isi, 1, ukuran, f);
        isi[ukuran] = '\0';

        fclose(f);
        // ... gunakan isi ...
        free(isi);   // JANGAN LUPA FREE!

        Di C, malloc/free harus manual. Di C++ lebih baik pakai std::string
        dan istreambuf_iterator seperti di modul fstream.
    */

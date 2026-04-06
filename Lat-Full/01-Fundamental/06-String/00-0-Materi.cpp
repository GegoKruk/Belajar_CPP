
// V.0 - String Overview

    // DUA CARA MENYIMPAN TEKS DI C++
    /*
        C++ punya dua cara menyimpan teks:

        1. char[] -- C-Style String (warisan dari bahasa C)
            - Array karakter yang diakhiri null terminator '\0'
            - Sudah dibahas di 05-Array/10-Character-Array.cpp
            - Ukuran tetap, rentan buffer overflow, ribet dipakai

        2. std::string -- C++ Modern String
            - Tipe data khusus untuk teks dari standar C++
            - Ukuran dinamis, aman, mudah dipakai
            - Inilah yang akan kita pelajari di bab ini

        KAPAN PAKAI MANA?
            std::string  -> untuk semua kode C++ modern (99% kasus)
            char[]       -> hanya kalau perlu interop dengan library C lama
                            atau embedded system yang tidak support STL
    */

// V.1 - Deklarasi & Inisialisasi

    /*
        std::string adalah class, bukan tipe primitif seperti int.
        Tapi cara pakainya seperti variabel biasa.

        Header yang dibutuhkan: #include <string>
        (Kadang sudah terbawa <iostream>, tapi selalu tulis eksplisit!)

        CARA DEKLARASI:

        1. Cara umum (assignment syntax):
            string nama = "Gega";

        2. Constructor syntax:
            string nama("Gega");
            string kosong;              <- string kosong ""
            string isi(5, '*');         <- "*****"
            string salinan(nama);       <- salin dari string lain
            string sebagian(nama, 2, 3);  <- dari index 2, ambil 3 karakter

        3. Assign setelah deklarasi:
            string s;
            s = "Halo";

        PENTING -- Single Quote vs Double Quote:
            'A'    <- ini CHAR (satu karakter), tipe data char
            "A"    <- ini STRING (bisa lebih dari satu karakter), tipe data string
            "Halo" <- ini string literal
            'Halo' <- TIDAK VALID! Single quote hanya untuk 1 karakter
    */

// V.2 - Akses & Iterasi Karakter

    /*
        std::string menyimpan karakter secara berurutan seperti array,
        dengan index dimulai dari 0.

        string s = "Halo";
        s[0] = 'H'
        s[1] = 'a'
        s[2] = 'l'
        s[3] = 'o'
        s[4] = ??? <- index 4 tidak valid! (length = 4, valid: 0..3)

        DUA CARA AKSES:
            s[i]    -> cepat, TIDAK cek batas -> undefined behavior jika OOB
            s.at(i) -> lebih lambat sedikit, CEK batas -> lempar exception jika OOB

        KAPAN PAKAI MANA?
            s[i]    -> saat yakin 100% index valid (performa kritis)
            s.at(i) -> saat ada kemungkinan index salah (lebih aman)
    */

// V.3 - Operasi Dasar String

// V.4 - Modifikasi String

// V.5 - Pencarian dalam String

    /*
        Semua fungsi pencarian mengembalikan nilai bertipe size_t
        (unsigned integer yang bisa sangat besar).

        Jika ditemukan  -> return INDEX (posisi pertama)
        Jika tidak ada  -> return string::npos

        string::npos = nilai paling besar untuk size_t (~4 miliar di 32-bit, jauh lebih besar di 64-bit)

        WAJIB: selalu cek hasil != string::npos sebelum dipakai!
            size_t pos = s.find("sub");
            if (pos != string::npos) {
                // ketemu di posisi pos
            } else {
                // tidak ditemukan
            }
    */

// V.6 - substr() dan Tokenisasi/Split

// V.7 - Input & Output String

    /*
        DUA CARA INPUT STRING:

        1. cin >> s
            - Berhenti di SPASI / TAB / ENTER
            - Hanya ambil SATU KATA
            - "Gega Ramadhan" -> hanya simpan "Gega"
            - Cocok untuk: satu kata, username, kode, angka

        2. getline(cin, s)
            - Baca seluruh baris sampai ENTER ditekan
            - Spasi IKUT tersimpan
            - "Gega Ramadhan" -> tersimpan "Gega Ramadhan"
            - Cocok untuk: nama lengkap, alamat, kalimat

        MASALAH KLASIK -- cin campur getline():
            Setelah cin >> angka, karakter '\n' (Enter) masih
            tersisa di buffer. getline() akan langsung membaca '\n'
            ini dan menghasilkan string KOSONG!

            Solusi: tambahkan cin.ignore() setelah cin >>
    */

// V.8 - Konversi Angka <-> String

// V.9 - Case Conversion & Klasifikasi Karakter

// V.10 - Algoritma pada String

// V.11 - String & Function

    /*
    1. Pass by VALUE: void f(string s)
        - Buat SALINAN string di dalam function
        - Asli tidak terpengaruh
        - Mahal untuk string panjang (harus salin semua karakter)
        - Kapan pakai: butuh modifikasi lokal tanpa pengaruhi asli

    2. Pass by REFERENCE: void f(string &s)
        - Tidak ada salinan, alias ke string asli
        - Perubahan AKAN mempengaruhi asli
        - Efisien (tidak ada overhead copy)
        - Kapan pakai: perlu modifikasi string asli

    3. Pass by CONST REFERENCE: void f(const string &s)
        - Tidak ada salinan (efisien seperti reference)
        - TIDAK BISA diubah (aman seperti value)
        - TERBAIK untuk parameter read-only!
        - Kapan pakai: hanya perlu baca string, tidak perlu ubah
*/

// V.12 - Kesalahan Umum & Cara Menghindarinya


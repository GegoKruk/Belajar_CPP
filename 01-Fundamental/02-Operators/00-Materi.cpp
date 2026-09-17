
// I. Operator Aritmatika
    /*
        Operator yang melakukan operasi matematika pada nilai/variabel.

        ┌──────────┬──────────────┬────────────┬────────────┬──────────────────────────┐
        │ Operator │ Nama         │ Contoh     │ Hasil      │ Catatan                  │
        ├──────────┼──────────────┼────────────┼────────────┼──────────────────────────┤
        │    +     │ Penjumlahan  │  5 + 3     │    8       │                          │
        │    -     │ Pengurangan  │  5 - 3     │    2       │                          │
        │    *     │ Perkalian    │  5 * 3     │   15       │                          │
        │    /     │ Pembagian    │  6 / 2     │    3       │ ⚠️ int/int = int!        │
        │    %     │ Modulus      │  7 % 3     │    1       │ ⚠️ Hanya untuk integer   │
        └──────────┴──────────────┴────────────┴────────────┴──────────────────────────┘

        ⚠️  DUA JEBAKAN UTAMA:

        1. Integer Division:
            int a = 7, b = 2;
            cout << a / b;       // Output: 3  ← bukan 3.5!
            // Solusi: static_cast<double>(a) / b  → 3.5

        2. Modulus hanya untuk integer:
            cout << 7.5 % 3;     // ❌ COMPILE ERROR
            // Solusi pakai fmod() dari <cmath>:
            cout << fmod(7.5, 3); // ✅ Output: 1.5

        OPERATOR ARITMATIKA DARI <cmath>:
            pow(x, n)   → x pangkat n
            sqrt(x)     → akar kuadrat x
            abs(x)      → nilai absolut (integer)
            fabs(x)     → nilai absolut (float/double)
            fmod(x, y)  → modulus untuk float/double
            ceil(x)     → pembulatan ke atas
            floor(x)    → pembulatan ke bawah
            round(x)    → pembulatan ke terdekat
    */

// J. Operator Penugasan
    /*
        Operator yang menyimpan / mengubah nilai variabel.
        Shorthand assignment = operator aritmatika + assignment dalam satu langkah.

        ┌──────────┬───────────────────┬────────────────┬───────────────────────────┐
        │ Operator │ Nama              │ Contoh         │ Setara Dengan             │
        ├──────────┼───────────────────┼────────────────┼───────────────────────────┤
        │    =     │ Assignment        │ x = 5          │ simpan 5 ke x             │
        │   +=     │ Tambah & simpan   │ x += 3         │ x = x + 3                 │
        │   -=     │ Kurang & simpan   │ x -= 2         │ x = x - 2                 │
        │   *=     │ Kali & simpan     │ x *= 4         │ x = x * 4                 │
        │   /=     │ Bagi & simpan     │ x /= 2         │ x = x / 2                 │
        │   %=     │ Modulus & simpan  │ x %= 3         │ x = x % 3                 │
        ├──────────┼───────────────────┼────────────────┼───────────────────────────┤
        │   &=     │ Bitwise AND       │ x &= y         │ x = x & y                 │
        │   |=     │ Bitwise OR        │ x |= y         │ x = x | y                 │
        │   ^=     │ Bitwise XOR       │ x ^= y         │ x = x ^ y                 │
        │  <<=     │ Left shift        │ x <<= 1        │ x = x << 1  (kalikan 2)   │
        │  >>=     │ Right shift       │ x >>= 1        │ x = x >> 1  (bagi 2)      │
        └──────────┴───────────────────┴────────────────┴───────────────────────────┘

        ⚠️  PERHATIKAN:
            x /= 0  → ❌ Runtime error (division by zero)
            x %= 0  → ❌ Runtime error (modulus by zero)
            Selalu validasi pembagi sebelum /= atau %=!

        CARA BACA SHORTHAND:
            "x += 5" dibaca: "tambahkan 5 ke nilai x yang sekarang"
            "x *= 2" dibaca: "kalikan x yang sekarang dengan 2"
            Bukan "x sama dengan x ditambah 5" — tapi "x bertambah 5"
    */

// K. Operator Increment & Decrement
    /*
        Operator khusus untuk menambah (++) atau mengurangi (--) nilai
        variabel sebesar 1. Singkatan dari += 1 dan -= 1.

        ┌───────────┬────────────────┬──────────────────────────────────────────┐
        │ Operator  │ Nama           │ Perilaku                                 │
        ├───────────┼────────────────┼──────────────────────────────────────────┤
        │   x++     │ Post-increment │ GUNAKAN dulu nilai x, BARU naikkan       │
        │   ++x     │ Pre-increment  │ NAIKKAN dulu nilai x, BARU gunakan       │
        │   x--     │ Post-decrement │ GUNAKAN dulu nilai x, BARU turunkan      │
        │   --x     │ Pre-decrement  │ TURUNKAN dulu nilai x, BARU gunakan      │
        └───────────┴────────────────┴──────────────────────────────────────────┘

        ANALOGI MUDAH:
            x++ → "Pakai dulu, baru bayar"   (ambil barang → bayar)
            ++x → "Bayar dulu, baru pakai"   (bayar dulu → ambil barang)

        KUNCI PEMAHAMAN:
            Kalau increment/decrement berdiri sendiri (tidak dalam ekspresi):
                x++;  dan  ++x;  → SAMA PERSIS hasilnya

            Perbedaan hanya muncul saat digunakan DALAM ekspresi / assignment:
                int a = x++;   // a dapat nilai LAMA x, x naik belakangan
                int b = ++x;   // b dapat nilai BARU x (sudah naik)

        DI BALIK LAYAR:
            x++  kira-kira setara:
                int temp = x;   // simpan nilai lama
                x = x + 1;      // naikkan x
                return temp;     // kembalikan nilai LAMA

            ++x  kira-kira setara:
                x = x + 1;      // naikkan x dulu
                return x;        // kembalikan nilai BARU

        ⚠️  UNDEFINED BEHAVIOR — HINDARI:
            int i = 5;
            int j = i++ + i++;   // ❌ Hasilnya tidak terdefinisi!
            cout << i++ << i++;  // ❌ Urutan evaluasi tidak dijamin!
            Jangan pakai ++ atau -- lebih dari sekali pada variabel yang sama
            dalam satu ekspresi/statement.
    */

// L. Operator Perbandingan 
    /*
        Membandingkan dua nilai dan menghasilkan boolean (true/false).
        Biasa dipakai dalam if, while, for, ternary.

        ┌──────────┬───────────────────────┬──────────────────┬──────────────────┐
        │ Operator │ Nama                  │ True jika...     │ Contoh           │
        ├──────────┼───────────────────────┼──────────────────┼──────────────────┤
        │    ==    │ Sama dengan           │ a dan b sama     │  5 == 5  → true  │
        │    !=    │ Tidak sama            │ a dan b berbeda  │  5 != 3  → true  │
        │    <     │ Kurang dari           │ a lebih kecil    │  3 <  5  → true  │
        │    <=    │ Kurang dari atau sama │ a ≤ b            │  5 <= 5  → true  │
        │    >     │ Lebih dari            │ a lebih besar    │  7 >  3  → true  │
        │    >=    │ Lebih dari atau sama  │ a ≥ b            │  5 >= 5  → true  │
        └──────────┴───────────────────────┴──────────────────┴──────────────────┘

        ⚠️  JEBAKAN PALING SERING (= vs ==)

            if (x = 5)   // ❌ SALAH! Ini ASSIGNMENT, bukan comparison!
                        //    x diisi 5, kondisi selalu true (karena 5 != 0)

            if (x == 5)  // ✅ BENAR! Ini COMPARISON

            TIPS: Pakai "Yoda condition" untuk menghindari ini:
            if (5 == x)  // Kalau salah tulis jadi (5 = x) → COMPILE ERROR

        ⚠️  JEBAKAN FLOAT COMPARISON:
            double a = 0.1 + 0.2;
            if (a == 0.3)  // ❌ BISA SALAH! Floating point tidak presisi!
            // a sebenarnya = 0.30000000000000004...

            SOLUSI: Gunakan epsilon (toleransi kecil):
            if (fabs(a - 0.3) < 1e-9)   // ✅ Benar
    */

// M. Operator Logika
    /*
        Menggabungkan dua atau lebih ekspresi boolean menjadi satu keputusan.

        ┌──────────┬──────┬──────────────────────────────────────────────────────┐
        │ Operator │ Nama │ Perilaku                                             │
        ├──────────┼──────┼──────────────────────────────────────────────────────┤
        │    &&    │ AND  │ true HANYA jika KEDUA sisi true                      │
        │    ||    │ OR   │ true jika SALAH SATU atau KEDUANYA true              │
        │    !     │ NOT  │ Membalik nilai boolean (true → false, false → true)  │
        └──────────┴──────┴──────────────────────────────────────────────────────┘

        TABEL KEBENARAN LENGKAP:
            A       B       A && B    A || B
            ─────────────────────────────────
            true    true    true      true
            true    false   false     true
            false   true    false     true
            false   false   false     false

            A       !A
            ──────────
            true    false
            false   true

        SHORT-CIRCUIT EVALUATION — fitur penting C++!
            Dalam && : jika sisi KIRI sudah false  → sisi kanan TIDAK dievaluasi
            Dalam || : jika sisi KIRI sudah true   → sisi kanan TIDAK dievaluasi

            Mengapa penting?
            1. Performa: ekspresi mahal di kanan bisa dilewati
            2. Safety: mencegah crash:
                if (ptr != nullptr && ptr->value > 0)   // ✅ aman!
                // kalau ptr null, ptr->value tidak pernah diakses

        PRIORITAS (PRECEDENCE) — dari tinggi ke rendah:
            !   (NOT)   →  paling tinggi
            &&  (AND)   →  lebih tinggi dari ||
            ||  (OR)    →  paling rendah dari ketiganya

            Contoh: true || false && false
                    = true || (false && false)   ← && diproses dulu
                    = true || false
                    = true

            ✅ Selalu pakai kurung () untuk kejelasan!
    */

// N. Operator Ternary
    /*
        Operator ternary adalah versi ringkas dari if-else untuk
        ekspresi yang menghasilkan satu nilai.

        SINTAKS:
            kondisi ? nilai_jika_true : nilai_jika_false

        SETARA DENGAN:
            if (kondisi) {
                // nilai_jika_true
            } else {
                // nilai_jika_false
            }

        PERBEDAAN KUNCI dengan if-else:
            if-else   -> statement (tidak bisa langsung di dalam ekspresi)
            ternary   -> expression (bisa langsung dipakai sebagai nilai)

            Contoh keunggulan ternary:
                // if-else tidak bisa dipakai langsung di dalam cout / argumen
                cout << (x > 0 ? "positif" : "negatif");   // ✅ ternary bisa!

                // Atau untuk inisialisasi const:
                const string status = (aktif ? "Online" : "Offline");   // ✅

        NESTED TERNARY - Bersarang:
            kondisi1 ? val1 : kondisi2 ? val2 : val3

            Ini legal tapi cepat membingungkan!
            Gunakan kurung dan formatting jelas, atau ganti dengan if-else.

        KAPAN PAKAI:
            ✅ Kondisi sederhana, nilai tunggal, satu baris masih terbaca
            ✅ Inisialisasi variabel const berdasar kondisi
            ✅ Argument fungsi berdasar kondisi
            ✅ Di dalam cout untuk label/status

        KAPAN HINDARI:
            ❌ Nested lebih dari 2 level -> susah dibaca, pakai if-else
            ❌ Ekspresi sisi kiri/kanan kompleks -> pisah ke if-else
            ❌ Saat ada side-effect di keduanya -> gunakan if-else saja
            ❌ Saat ingin menjalankan multiple statement -> pakai if-else

        INGAT: Ternary untuk NILAI, if-else untuk LOGIKA KOMPLEKS.
    */

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
            
        ┌──────────┬──────────────┬───────────────────────────────┬───────────────┐
        │ Operator │ Nama         │ Aturan per bit                │ Contoh        │
        ├──────────┼──────────────┼───────────────────────────────┼───────────────┤
        │    &     │ AND          │ 1 hanya jika KEDUA bit 1      │ 5 & 3  = 1    │
        │    |     │ OR           │ 1 jika SALAH SATU bit 1       │ 5 | 3  = 7    │
        │    ^     │ XOR          │ 1 jika bit BERBEDA            │ 5 ^ 3  = 6    │
        │    ~     │ NOT          │ BALIK semua bit               │ ~5     = -6   │
        │    <<    │ Left Shift   │ Geser kiri n, isi 0 di kanan  │ 5 << 1 = 10   │
        │    >>    │ Right Shift  │ Geser kanan n                 │ 5 >> 1 = 2    │
        └──────────┴──────────────┴───────────────────────────────┴───────────────┘  

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
            ⚠️ Bitwise HANYA untuk tipe INTEGER (int, char, long, dll)
            ⚠️ Jangan pakai pada float/double → compile error
            ⚠️ Hati-hati dengan signed vs unsigned integers
            ⚠️ Hasil ~ tergantung ukuran tipe data (8/16/32/64 bit)
            ⚠️ Left shift berlebihan bisa overflow
    */

// P. Precedence & Associativity
    /*
        Precedence (prioritas) menentukan URUTAN operasi dalam ekspresi.
        Seperti matematika: perkalian dikerjakan sebelum penjumlahan.

        Associativity menentukan arah evaluasi jika precedence SAMA:
            Left-to-right  →  a - b - c  =  (a - b) - c
            Right-to-left  →  a = b = c  =  a = (b = c)

        ┌─────┬──────────────────────────────────────┬──────────────────┬─────────┐
        │ Lv  │ Operator                             │ Keterangan       │ Assoc.  │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  1  │ ::                                   │ Scope resolution │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  2  │ ()  []  .  ->  ++  -- (post)         │ Postfix, akses   │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  3  │ ++  -- (pre)  ~  !  -  +             │ Unary prefix     │ R → L   │
        │     │ (type)  sizeof  new  delete          │                  │         │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  4  │ *  /  %                              │ Perkalian        │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  5  │ +  -                                 │ Penjumlahan      │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  6  │ <<  >>                               │ Shift            │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  7  │ <  <=  >  >=                         │ Perbandingan     │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  8  │ ==  !=                               │ Kesamaan         │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │  9  │ &                                    │ Bitwise AND      │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 10  │ ^                                    │ Bitwise XOR      │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 11  │ |                                    │ Bitwise OR       │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 12  │ &&                                   │ Logical AND      │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 13  │ ||                                   │ Logical OR       │ L → R   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 14  │ ?:                                   │ Ternary          │ R → L   │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 15  │ =  +=  -=  *=  /=  %=                │ Assignment       │ R → L   │
        │     │ &=  |=  ^=  <<=  >>=                 │                  │         │
        ├─────┼──────────────────────────────────────┼──────────────────┼─────────┤
        │ 16  │ ,                                    │ Koma             │ L → R   │
        └─────┴──────────────────────────────────────┴──────────────────┴─────────┘

        Level 1 = TERTINGGI (dikerjakan paling pertama)
        Level 16 = TERENDAH (dikerjakan paling akhir)

        ATURAN EMAS:
        "Jika ragu soal precedence, selalu tambahkan kurung () untuk kejelasan."
        Kurung () selalu dikerjakan paling dulu, tidak peduli precedence.
    */

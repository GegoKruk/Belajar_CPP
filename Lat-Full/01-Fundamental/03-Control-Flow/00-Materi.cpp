// Percabangan (IF, ELSE IF, ELSE)
    /*
        Percabangan membuat program bisa mengambil keputusan:
        "Kalau kondisi ini terpenuhi -> jalankan ini, kalau tidak -> jalankan itu."

        Tanpa percabangan, program hanya berjalan lurus dari atas ke bawah.
        Dengan percabangan, program bisa memilih jalur yang berbeda.

        ┌─────────────────────────────────────────────────────────────┐
        │  BENTUK-BENTUK PERCABANGAN                                  │
        ├─────────────────────────────────────────────────────────────┤
        │  1. if tunggal         -> satu kondisi, satu aksi           │
        │  2. if-else            -> dua pilihan: benar atau salah     │
        │  3. if-else if-else    -> banyak pilihan bertingkat         │
        │  4. nested if          -> if di dalam if                    │
        └─────────────────────────────────────────────────────────────┘

        SINTAKS:

        // 1. if tunggal
            if (kondisi) {
                // dijalankan hanya jika kondisi true
            }

        // 2. if-else
            if (kondisi) {
                // jika true
            } else {
                // jika false (default / fallback)
            }

        // 3. if-else if-else
            if (kondisi1) {
                // jika kondisi1 true
            } else if (kondisi2) {
                // jika kondisi1 false, dan kondisi2 true
            } else if (kondisi3) {
                // dst...
            } else {
                // jika semua kondisi di atas false
            }

        CARA KERJA if-else if-else:
            Dievaluasi dari ATAS ke BAWAH.
            Begitu satu kondisi true -> bloknya dijalankan, sisanya DILEWATI.
            else paling bawah = "catch-all" / default.

        ⚠️  DANGLING ELSE - Jebakan Indentasi:
            if (a > 0)
                if (b > 0)
                    cout << "keduanya positif";
            else             // <- else ini milik if (b>0), BUKAN if (a>0)!
                cout << "...";

            SOLUSI: Selalu pakai kurung kurawal {} walau satu baris!
    */

// Percabangan (SWITCH-CASE)
    /*
        Switch adalah alternatif if-else if yang lebih rapi ketika
        kita membandingkan SATU variabel dengan banyak nilai TETAP.

        SINTAKS:
            switch (ekspresi) {
                case nilai1:
                    // kode jika ekspresi == nilai1
                    break;
                case nilai2:
                    // kode jika ekspresi == nilai2
                    break;
                default:
                    // kode jika tidak ada case yang cocok
                    break;
            }

        ATURAN SWITCH:
            ✅ Ekspresi harus bertipe: int, char, enum (atau tipe yang bisa
                dikonversi ke integer). Tidak bisa float/double/string!
            ✅ Nilai setiap case harus KONSTANTA (literal atau constexpr)
            ✅ break diperlukan untuk menghentikan eksekusi di tiap case
            ✅ default bersifat opsional tapi sangat dianjurkan

        ⚠️  FALL-THROUGH - Tanpa break, eksekusi berlanjut ke case berikutnya!
            switch (x) {
                case 1:
                    cout << "satu";     // <- tidak ada break!
                case 2:
                    cout << "dua";      // <- ini ikut dieksekusi kalau x==1!
                case 3:
                    cout << "tiga";     // <- ini juga!
                    break;
            }
            Jika x=1, output: "satuduatiga"  <- mungkin bukan yang diinginkan

            Fall-through SENGAJA berguna untuk menggabungkan beberapa case
            yang punya aksi yang sama.

        SWITCH vs IF-ELSE - Kapan Pakai Mana:
            ┌─────────────────────────┬───────────────┬─────────────────────┐
            │ Kondisi                 │ Pakai switch  │ Pakai if-else       │
            ├─────────────────────────┼───────────────┼─────────────────────┤
            │ Satu variabel, nilai    │ ✅ switch     │                     │
            │   tetap (int/char)      │               │                     │
            │ Banyak case (>3)        │ ✅ switch     │                     │
            │ Rentang nilai (>=, <=)  │               │ ✅ if-else          │
            │ Kondisi boolean/float   │               │ ✅ if-else          │
            │ Kondisi majemuk (&&,||) │               │ ✅ if-else          │
            └─────────────────────────┴───────────────┴─────────────────────┘
    */

// Perulangan (For, While, Do While)

    /* Review
        Perulangan (loop) mengeksekusi blok kode berulang kali selama
        kondisi tertentu terpenuhi. Tanpa loop, kita harus menulis
        kode yang sama berkali-kali.

        ┌────────────────┬─────────────────────────────┬─────────────────────────────────┐
        │ Jenis Loop     │ Ciri Utama                  │ Cocok Untuk                     │
        ├────────────────┼─────────────────────────────┼─────────────────────────────────┤
        │ for            │ Jumlah iterasi diketahui    │ Counter, index, iterasi tetap   │
        │ while          │ Selama kondisi true         │ Validasi, proses dinamis        │
        │ do-while       │ Minimal 1x jalan dulu       │ Menu, input ulang               │
        └────────────────┴─────────────────────────────┴─────────────────────────────────┘

        ┌────────────────────────────────────────────────────────────────────────────┐
        │  KAPAN PAKAI MANA?                                                         │
        │  -> Tahu berapa kali iterasi?             -> for                           │
        │  -> Tidak tahu berapa kali, cek dulu?     -> while                         │
        │  -> Harus jalan dulu minimal sekali?      -> do-while                      │
        └────────────────────────────────────────────────────────────────────────────┘
    */

    /* For Loop
        SINTAKS:
            for (inisialisasi; kondisi; update) {
                // blok yang diulang
            }

        ALUR EKSEKUSI:
            1. inisialisasi dijalankan SEKALI di awal
            2. kondisi dicek - jika false, loop berhenti
            3. blok kode dijalankan
            4. update dijalankan
            5. kembali ke langkah 2

        Contoh:
            for ( int i = 0; i < 5;  i++ ) { ... }
                    ├─────┤  ├────┤  ├──┤
                    init   cek   update

        RANGE-BASED FOR (C++11) - lebih ringkas untuk koleksi:
            for (tipe variabel : koleksi) { ... }
            for (int x : arr)   { ... }   // tiap elemen array
            for (char c : str)  { ... }   // tiap karakter string
    */

    /* While Loop
        SINTAKS:
            while (kondisi) {
                // blok yang diulang
            }

        ALUR EKSEKUSI:
            1. Cek kondisi - jika false dari awal, blok TIDAK pernah jalan
            2. Blok kode dijalankan
            3. Kembali ke langkah 1

        KAPAN PAKAI while?
            -> Ketika jumlah iterasi TIDAK diketahui sebelumnya
            -> Ketika loop bergantung pada kondisi dinamis (input user, data dari luar)

        ⚠️  INFINITE LOOP - Pastikan kondisi BISA menjadi false!
            int i = 1;
            while (i <= 10) {
                cout << i;
                // LUPA i++! -> loop jalan terus selamanya!
            }
    */

    /* Do-While Loop
        SINTAKS:
            do {
                // blok yang diulang
            } while (kondisi);   // ← titik koma WAJIB di sini!

        PERBEDAAN KUNCI dengan while:
            while     -> cek kondisi DULU, baru jalankan blok
                        -> mungkin tidak jalan sama sekali

            do-while  -> jalankan blok DULU, baru cek kondisi
                        -> dijamin minimal 1 kali jalan

        KAPAN PAKAI do-while?
            -> Menu interaktif (tampilkan dulu, baru tanya apakah ulang)
            -> Input yang harus diminta minimal sekali
            -> Proses yang harus dijalankan dulu sebelum dicek kondisinya
    */

// Loop Control (Break, Continue, Goto)

    /* Review
        Loop control adalah perintah untuk mengubah alur perulangan
        dari yang seharusnya (tidak sekedar menunggu kondisi false).

        ┌────────────────┬────────────────────────────────────────────────────────┐
        │ Statement      │ Efek                                                   │
        ├────────────────┼────────────────────────────────────────────────────────┤
        │ break          │ KELUAR dari loop / switch seketika                     │
        │ continue       │ SKIP sisa kode di iterasi ini, lanjut ke iterasi next  │
        │ goto           │ JUMP ke label - JANGAN dipakai!                        │
        └────────────────┴────────────────────────────────────────────────────────┘
    */

    /* Break
        break menghentikan loop SEKETIKA - tidak menunggu kondisi false.

        Berlaku di:  for, while, do-while, switch

        Penting: break hanya keluar dari loop TERDEKAT (satu level saja).
        Jika nested, break di inner loop tidak otomatis keluar outer loop.

        Pola umum:
            while (true) {          // infinite loop
                ...
                if (kondisiKeluar)
                    break;          // satu-satunya pintu keluar
            }
    */

    /* Continue
        continue melewati sisa kode di iterasi ini, dan langsung
        melanjutkan ke iterasi berikutnya. Loop TIDAK berhenti.

        Perbedaan kecil di for vs while:
            for:   continue -> langsung ke bagian UPDATE (i++) lalu cek kondisi
            while: continue -> langsung ke CEK KONDISI

        Pola umum:
            for (int i = 0; i < n; i++) {
                if (dataInvalid(i)) continue;  // skip data rusak
                // proses data valid
            }
    */

    /* Exit Loop
        Masalah: break hanya keluar dari satu level loop.
        Jika ingin keluar dari nested loop:

        Cara 1: Boolean flag (variabel penanda)
        Cara 2: return dari dalam fungsi (PALING DIANJURKAN)
        Cara 3: goto (JANGAN!) - satu-satunya alasan goto masih ada
    */

    /* Goto
        goto melompat ke label yang ditentukan di tempat lain dalam kode.

        Syntax:
            goto namaLabel;
            ...
            namaLabel:
                // kode setelah jump

        KENAPA GOTO BERBAHAYA:
            ❌ "Spaghetti code" - alur kode tidak bisa dilacak
            ❌ Sulit di-debug dan di-maintain
            ❌ Bisa melewati inisialisasi variabel -> undefined behavior
            ❌ Membuat kode tidak bisa dibaca orang lain
            ❌ Ada alternatif yang lebih baik untuk SEMUA kasus goto

        QUOTE TERKENAL:
            "Go To Statement Considered Harmful" - Edsger W. Dijkstra (1968)

        ALTERNATIF GOTO:
            goto (keluar loop)    -> break
            goto (ulang loop)     -> continue
            goto (keluar fungsi)  -> return
            goto (error handling) -> exception (try-catch)
    */

// Nested Loops
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

    /*
        Nested loop = loop di dalam loop.

        ALUR EKSEKUSI — Kunci memahami nested loop:
            for (int i = 0; i < 3; i++) {      ← outer: berjalan 3x
                for (int j = 0; j < 4; j++) {  ← inner: tiap outer, jalan 4x
                    // dieksekusi 3 × 4 = 12 kali
                }
            }

        Urutan eksekusi:
            i=0: j=0, j=1, j=2, j=3  → inner selesai → outer lanjut
            i=1: j=0, j=1, j=2, j=3  → inner selesai → outer lanjut
            i=2: j=0, j=1, j=2, j=3  → inner selesai → outer selesai

        ATURAN EMAS POLA:
            Outer loop (i)  → mengontrol BARIS (berapa baris)
            Inner loop (j)  → mengontrol isi tiap BARIS (berapa karakter)
            Relasi i & j    → menentukan KAPAN cetak & KAPAN spasi

        RESEP DASAR RUMUS:
            j <= i              → bertambah 1 per baris (kiri ke kanan)
            j < n - i           → berkurang 1 per baris
            j < n - i - 1       → spasi untuk piramida
            i == 0 || i == n-1  → baris pertama/terakhir
            j == 0 || j == n-1  → kolom pertama/terakhir

        CARA BERPIKIR MERANCANG POLA:
            1. Gambar pola di kertas dulu (5 baris cukup untuk latihan)
            2. Hitung: baris ke-i, ada berapa karakter? Ada berapa spasi?
            3. Temukan rumus hubungan i dan j
            4. Terjemahkan ke loop
            5. Uji dengan n=3, lalu scale up ke n=5

        ⚠️  KOMPLEKSITAS:
            Nested 2 loop → O(n²)
            Nested 3 loop → O(n³) → hindari untuk data besar!
    */

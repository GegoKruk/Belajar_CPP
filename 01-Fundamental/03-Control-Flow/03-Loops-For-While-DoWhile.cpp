#include <iostream>
#include <string>
using namespace std;

void forLoop() {
    cout << "\n==================== For Loop ====================" << endl;

    // ── 1. For Loop Dasar ─────────────────────────────────────
        cout << "\n1. For Loop Dasar (maju, step 1)" << endl;
        cout << "   Angka 1-5: ";
        for (int i = 1; i <= 5; i++) {
            cout << i << " ";
        }
        cout << endl;

    // ── 2. For Loop Mundur ────────────────────────────────────
        cout << "\n2. For Loop Mundur (countdown)" << endl;
        cout << "   Countdown 5-1: ";
        for (int i = 5; i >= 1; i--) {
            cout << i << " ";
        }
        cout << "KLIK!" << endl;

    // ── 3. For Loop dengan Step Bukan 1 ──────────────────────
        cout << "\n3. For Loop dengan Step Berbeda" << endl;
        cout << "   Genap 0-10 (step +2)    : ";
        for (int i = 0; i <= 10; i += 2) {
            cout << i << " ";
        }
        cout << endl;

        cout << "   Kelipatan 3 s/d 30       : ";
        for (int i = 3; i <= 30; i += 3) {
            cout << i << " ";
        }
        cout << endl;

        cout << "   100 -> 0, step -25        : ";
        for (int i = 100; i >= 0; i -= 25) {
            cout << i << " ";
        }
        cout << endl;

    // ── 4. For Loop - Akumulasi (Penjumlahan) ─────────────────
        cout << "\n4. Akumulasi dengan For Loop" << endl;
        {
            int total = 0;
            for (int i = 1; i <= 100; i++) {
                total += i;
            }
            cout << "   1 + 2 + 3 + ... + 100 = " << total << endl;
            cout << "   (Rumus Gauss: n(n+1)/2 = " << 100*101/2 << " ✓)" << endl;
        }

    // ── 5. Range-Based For - C++11 ────────────────────────────
        cout << "\n5. Range-Based For (C++11) - Iterasi Koleksi" << endl;
        {
            int  arr[]  = {10, 25, 30, 45, 60};
            int  total  = 0;

            cout << "   Array: ";
            for (int x : arr) {
                cout << x << " ";
                total += x;
            }
            cout << endl;
            cout << "   Total: " << total << endl;

            // Iterasi string karakter per karakter
            string nama = "Gega";
            cout << "\n   Iterasi string \"" << nama << "\": ";
            for (char c : nama) {
                cout << "[" << c << "] ";
            }
            cout << endl;

            // Range-based dengan referensi - untuk modifikasi
            int scores[] = {70, 85, 60, 90, 75};
            cout << "\n   Nilai sebelum +5 bonus: ";
            for (int s : scores) cout << s << " ";
            cout << endl;

            for (int &s : scores) {   // & = referensi -> modifikasi langsung
                s += 5;
            }
            cout << "   Nilai sesudah  +5 bonus: ";
            for (int s : scores) cout << s << " ";
            cout << endl;
        }

    // ── 6. Factorial dengan For ───────────────────────────────
        cout << "\n6. Faktorial dengan For Loop" << endl;
        {
            for (int n = 0; n <= 8; n++) {
                long long fakt = 1;
                for (int i = 1; i <= n; i++) {
                    fakt *= i;
                }
                cout << "   " << n << "! = " << fakt << endl;
            }
        }
}

void whileLoop() {
    cout << "\n\n==================== While Loop ====================" << endl;

    // ── 1. While Dasar ────────────────────────────────────────
        cout << "\n1. While Loop Dasar" << endl;
        {
            int i = 1;
            cout << "   Angka 1-5: ";
            while (i <= 5) {
                cout << i << " ";
                i++;   // ← jangan lupa update! Tanpa ini -> infinite loop
            }
            cout << endl;
        }

    // ── 2. While - Kondisi Dimulai False (Tidak Jalan) ────────
        cout << "\n2. While - Jika Kondisi Awal False" << endl;
        {
            int x = 10;
            cout << "   x=" << x << ", while (x < 5): ";
            while (x < 5) {
                cout << x << " ";   // tidak akan pernah dieksekusi
                x++;
            }
            cout << "(tidak ada output - kondisi awal sudah false)" << endl;
            cout << "   -> Perbedaan penting dengan do-while!" << endl;
        }

    // ── 3. While - Mencari Angka (Tidak Tahu Berapa Iterasi) ──
        cout << "\n3. While - Akumulasi Sampai Batas" << endl;
        {
            int angka = 1;
            int total = 0;
            cout << "   Jumlahkan angka sampai total >= 50:" << endl;
            cout << "   Menambahkan: ";
            while (total < 50) {
                total += angka;
                cout << angka;
                if (total < 50) cout << "+";
                angka++;
            }
            cout << " = " << total << endl;
            cout << "   Total angka yang dijumlahkan: " << angka - 1 << " angka" << endl;
        }

    // ── 4. While - Digit Counter ──────────────────────────────
        cout << "\n4. While - Menghitung Digit Angka" << endl;
        {
            int numbers[] = {5, 42, 100, 1234, 99999};
            for (int num : numbers) {
                int temp  = num;
                int digit = 0;
                while (temp > 0) {
                    temp /= 10;
                    digit++;
                }
                cout << "   " << num << " memiliki " << digit << " digit" << endl;
            }
        }

    // ── 5. While - Simulasi Input Validasi ────────────────────
        cout << "\n5. While - Pola Validasi Input (Simulasi)" << endl;
        {
            // Simulasi input - di program nyata pakai cin
            int simulasiInput[] = {-5, 0, 150, 85};
            int idx = 0;

            int nilai = simulasiInput[idx];
            cout << "   Input: " << nilai << " -> ";

            while (nilai < 0 || nilai > 100) {
                cout << "Tidak valid! ";
                idx++;
                nilai = simulasiInput[idx];
                cout << "Coba lagi: " << nilai << " -> ";
            }
            cout << "Valid! Nilai diterima: " << nilai << endl;
        }

    // ── 6. While - Deret Fibonacci ────────────────────────────
        cout << "\n6. While - Deret Fibonacci sampai batas" << endl;
        {
            int batas = 200;
            long long a = 0, b = 1;
            cout << "   Fibonacci s/d " << batas << ": ";
            while (a <= batas) {
                cout << a << " ";
                long long temp = a + b;
                a = b;
                b = temp;
            }
            cout << endl;
        }

    // ── 7. While - Infinite Loop yang Terkontrol ─────────────
        cout << "\n7. While (true) - Infinite Loop Terkontrol dengan break" << endl;
        {
            int cari  = 17;
            int angka = 10;
            cout << "   Mencari " << cari << " mulai dari " << angka << ": ";

            while (true) {   // infinite loop
                if (angka == cari) {
                    cout << angka << " - Ditemukan!" << endl;
                    break;   // keluar dari infinite loop
                }
                cout << angka << " ";
                angka++;
            }
        }
}

void doWhileLoop() {
    cout << "\n\n==================== Do-While Loop ====================" << endl;

    // ── 1. Perbedaan while vs do-while ────────────────────────
        cout << "\n1. Perbedaan Mendasar: while vs do-while" << endl;
        {
            int n = 10;
            cout << "   n=" << n << endl;

            cout << "   while  (n < 5): ";
            while (n < 5) {       // kondisi false dari awal -> tidak jalan
                cout << n << " ";
                n++;
            }
            cout << "(tidak jalan!)" << endl;

            n = 10;  // reset
            cout << "   do-while(n < 5): ";
            do {
                cout << n << " ";   // jalan 1x dulu walau kondisi false
                n++;
            } while (n < 5);
            cout << "(jalan 1x meskipun kondisi awal false!)" << endl;
        }

    // ── 2. Do-While - Menu Interaktif (Simulasi) ─────────────
        cout << "\n2. Do-While - Menu Interaktif (Simulasi)" << endl;
        {
            // Simulasi pilihan user: 1, 2, lalu 4 (keluar)
            int simulasi[] = {1, 2, 4};
            int idx        = 0;
            int pilihan;

            cout << "   Simulasi interaksi menu kantin:" << endl;

            do {
                cout << "\n   +- Menu Kantin ----------------+" << endl;
                cout << "   | 1. Makanan   2. Minuman      |" << endl;
                cout << "   | 3. Bayar     4. Keluar       |" << endl;
                cout << "   +------------------------------+" << endl;

                pilihan = simulasi[idx++];
                cout << "   Pilihan: " << pilihan << endl;

                switch (pilihan) {
                    case 1: cout << "   -> Menampilkan menu makanan..." << endl; break;
                    case 2: cout << "   -> Menampilkan menu minuman..." << endl; break;
                    case 3: cout << "   -> Menghitung total tagihan..." << endl; break;
                    case 4: cout << "   -> Terima kasih! Sampai jumpa!" << endl; break;
                    default: cout << "   -> Pilihan tidak valid." << endl;
                }

            } while (pilihan != 4);   // ulangi selama belum pilih "Keluar"
        }

    // ── 3. Do-While - Hitung Sampai Syarat Terpenuhi ─────────
        cout << "\n3. Do-While - Ulangi Sampai Nilai Valid" << endl;
        {
            // Simulasi: user masukkan nilai sampai dapat yang benar
            int simulasi[] = {-3, 200, 75};  // dua kali salah, ketiga benar
            int idx = 0;
            int nilai;

            cout << "   Masukkan nilai ujian (0-100):" << endl;
            do {
                nilai = simulasi[idx++];
                cout << "   Input: " << nilai;
                if (nilai < 0 || nilai > 100) {
                    cout << " - TIDAK VALID, coba lagi!" << endl;
                } else {
                    cout << " - Valid ✓" << endl;
                }
            } while (nilai < 0 || nilai > 100);

            cout << "   Nilai diterima: " << nilai << endl;
        }
}

void perbandinganDanContoh() {
    cout << "\n\n==================== Perbandingan Ketiga Loop ====================" << endl;

    // ── Tabel Perbandingan ─────────────────────────────────────
        cout << R"(
            +-------------+----------------------+---------------------------------+
            | Loop        | Cek kondisi          | Cocok untuk                     |
            +-------------+----------------------+---------------------------------+
            | for         | Sebelum tiap iterasi | Iterasi dengan counter          |
            | while       | Sebelum tiap iterasi | Kondisi dinamis, jumlah unknown |
            | do-while    | Setelah tiap iterasi | Jalan dulu minimal 1x           |
            +-------------+----------------------+---------------------------------+
        )";

    // ── Contoh Klasik: FizzBuzz ────────────────────────────────
        cout << "Contoh Klasik - FizzBuzz (1-20):" << endl;
        cout << "   (Kelipatan 3 -> Fizz, kelipatan 5 -> Buzz, keduanya -> FizzBuzz)" << endl;
        cout << "   ";
        for (int i = 1; i <= 20; i++) {
            if(i % 15 == 0){
                cout << "FizzBuzz ";
            } else if (i % 3  == 0){
                cout << "Fizz ";
            } else if (i % 5  == 0){
                cout << "Buzz ";
            } else {
                cout << i << " ";
            } 
        }
        cout << endl;

    // ── Konversi Desimal ke Biner ──────────────────────────────
        cout << "\nKonversi Desimal ke Biner dengan While:" << endl;
        {
            int angka[] = {5, 10, 42, 255};
            
            for (int num : angka) {
                int   temp   = num;
                string biner = "";

                if (temp == 0){ 
                    biner = "0"; 
                }

                while (temp > 0) {
                    biner = char('0' + temp % 2) + biner;
                    temp /= 2;
                }
                cout << "   " << num << " -> " << biner << endl;
            }
        }

    // ── Tabel Perkalian dengan Nested For ─────────────────────
        cout << "\nTabel Perkalian 1-5 (Nested For):" << endl;
        cout << "      ";
        for (int j = 1; j <= 5; j++) cout << "  " << j << " ";
        cout << endl;
        cout << "   +--------------------------+" << endl;
        for (int i = 1; i <= 5; i++) {
            cout << "   | " << i << " |";
            for (int j = 1; j <= 5; j++) {
                cout.width(3);
                cout << i * j << " ";
            }
            cout << "|" << endl;
        }
        cout << "   +--------------------------+" << endl;

    // ── Tips ──────────────────────────────────────────────────
        cout << "\nTips:" << endl;
        cout << "   -> for: pakai jika tahu jumlah iterasi" << endl;
        cout << "   -> while: pakai jika kondisi berubah secara dinamis" << endl;
        cout << "   -> do-while: pakai jika harus jalan minimal sekali" << endl;
        cout << "   -> Pastikan ada kondisi keluar untuk mencegah infinite loop!" << endl;
        cout << "   -> Range-based for (C++11) lebih aman & ringkas untuk koleksi" << endl;
        cout << "   -> Variabel loop (i,j,k) hanya hidup di dalam blok for" << endl;
}


int main(){

    forLoop();
    whileLoop();
    doWhileLoop();
    perbandinganDanContoh();

    return 0;
}
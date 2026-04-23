#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
    S-08: Sistem Manajemen Rental PC (GEGA GAMING CENTER)
    
    Konteks:
        Kamu adalah pemilik rental PC "GEGA Gaming Center". 
        Kamu butuh sistem untuk mendata komputer, penyewa, dan menghitung pendapatan secara otomatis.

    1. Spesifikasi Data (Struct)
        Kamu harus menggunakan Nested Struct (Struct di dalam Struct):

        Struct Waktu: 
            - Jam, Menit (untuk mencatat durasi main).

        Struct PC:
            - ID PC (int)
            - Tipe PC ("Reguler", "VIP", "VVIP")
            - Harga per jam (double)
            - Status ("Tersedia" atau "Dipakai")

        Struct Transaksi:
            - Nama Penyewa (string)
            - PC yang disewa (Struct PC)
            - Waktu Mulai & Waktu Selesai (Struct Waktu)
            - Total Biaya (double)

    2. Fitur Utama (Menu)
        Program harus memiliki menu interaktif:
            - Inisialisasi PC (Admin Only): Setup awal 5-10 PC dengan tipe dan harga yang berbeda-beda.
            - Daftar PC: Menampilkan tabel seluruh PC beserta statusnya.

        Sewa PC:
            - Input nama penyewa.
            - Pilih PC yang statusnya "Tersedia".
            - Input jam mulai (misal: 14:30).
            - Status PC berubah jadi "Dipakai".
        
        Selesai Sewa (Checkout):
            - Pilih PC yang sedang dipakai.
            - Input jam selesai.
        
        Logika Hitung: 
            - Program menghitung selisih waktu (Durasi) dan mengalikan dengan harga per jam PC tersebut. (Hati-hati dengan konversi menit ke jam!).
            - Tampilkan struk kecil di layar.
            - Status PC kembali "Tersedia".
        
        Laporan Pendapatan (Sorting):
            - Menampilkan daftar transaksi yang sudah selesai.
            - Urutkan transaksi berdasarkan Total Biaya Terbesar (Gunakan sorting yang sudah kamu pelajari).
        
        Cari Riwayat (Searching):
            - Cari transaksi berdasarkan Nama Penyewa menggunakan Linear atau Binary Search.

    3. Tantangan Kompleksitas (The "Gega" Level)
            - Validasi Waktu: Gimana kalau user input jam selesai lebih kecil dari jam mulai? (Misal mulai 23:00 selesai 01:00 hari berikutnya). Hint: Konversi semua ke total menit.
            - Array of Struct: Kamu akan mengelola PC daftarPC[10] dan Transaksi riwayat[100].
            - Pass by Reference: Gunakan fungsi untuk memanipulasi data PC agar statusnya benar-benar ter-update di memori utama.

    Instruksi Pengerjaan:
        - Buat file S-01-GegaGamingCenter.cpp di dalam Lat-Mandiri.
        - Cicil per fitur. Jangan langsung semua. (Misal: Hari 1 fokus ke Struct dan Menu 1-2).
        - Ingat aturan WIP commit kita kemarin kalau belum selesai.
        - No AI for Logic: 
            Coba ulik sendiri cara hitung durasi menitnya. Itu bagian paling seru!
*/

int main(){
    
    return 0;
}
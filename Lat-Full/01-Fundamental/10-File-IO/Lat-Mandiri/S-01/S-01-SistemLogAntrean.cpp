#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

/*
    🚀 TANTANGAN 10 MENIT: "Sistem Log Antrean Geffy"
    
    📋 Cerita Kasus:
        Kamu diminta membuat sistem pencatat antrean digital sederhana untuk sebuah toko. 
        Program ini harus bisa mencatat nomor antrean pelanggan secara otomatis ke dalam sebuah file teks bernama antrean.txt.

    🛠️ Tugas & Spesifikasi Jalannya Program:
        - Gunakan ofstream dengan nama objek bebas untuk membuka file antrean.txt.
        - Gunakan gaya Early Return (if gagal langsung return 1;) untuk memastikan file aman sebelum ditulis.
        - Gunakan bumbu flag yang tepat agar setiap kali program ini dijalankan (di-run), isi file lama TIDAK TERHAPUS, melainkan 
            data baru langsung menumpuk di paling bawah (Append).
        - Di dalam proses menulis, buatlah sebuah perulangan for sebanyak 3 kali untuk mensimulasikan ada 3 pelanggan baru yang datang.

        Hasil tulisan di dalam file harus rapi dan memiliki format:
        [Nomor Antrean] - Pelanggan Baru

    🎯 Output yang Diharapkan di Dalam File:
        Jika kamu menjalankan program ini untuk PERTAMA KALINYA, isi file antrean.txt harus menjadi seperti ini:

        Antrean ke-1 - Pelanggan Baru
        Antrean ke-2 - Pelanggan Baru
        Antrean ke-3 - Pelanggan Baru

        Lalu, tanpa menghapus file tersebut, kamu jalankan lagi programnya untuk KEDUA KALINYA. 
        Maka isi file antrean.txt otomatis harus bertambah di bawahnya seperti ini:

        Antrean ke-1 - Pelanggan Baru
        Antrean ke-2 - Pelanggan Baru
        Antrean ke-3 - Pelanggan Baru
        Antrean ke-1 - Pelanggan Baru
        Antrean ke-2 - Pelanggan Baru
        Antrean ke-3 - Pelanggan Baru
*/

int main(){
    cout << "==========[SOAL 1 - MEMBUAT FILE, MENULIS ISI FILE, MENYAMBUNG FILE - SISTEM LOG ANTREAN ]==========" << endl;

    ofstream filelog("antrean.txt", ios::app);
    if(!filelog.is_open()){
        cerr << "File Gagal Dibuat [!]" << endl;
        return 1;
    }

    int totalAntrean = 3;
    for (int i = 0; i < totalAntrean; i++){
        filelog << "Antrean ke-" << i+1 << " Pelanggan Baru" << endl;
    }

    filelog.close();
}
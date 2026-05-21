#include <iostream>
#include <fstream>
using namespace std;

// Struct
    struct AtributSihir {

    };

    struct Siswa {

    };

// Variabel Global
    Siswa arraySiswa[100];
    int jumlah_siswa = 0;

// Function Prototype 
    // Function2
        void initData();          // Dijalankan HANYA DI AWAL saat program pertama kali dibuka
        void saveAppendData();    // Digunakan khusus untuk menu Tambah Data (ios::app)
        void saveOverwriteData(); // Digunakan khusus untuk menu Hapus Data (overwrite)

        int Hitung_Bonus(int fokus);
        int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari);

    // Function Pointer dan Sorting (Quick Sort)
        void swapData(Siswa *a, Siswa *b);
        int partition(Siswa arr[], int low, int high);
        void quickSort(Siswa arr[], int low, int high);

    // Function Menu 
        void tambahData();
        void lihatData();
        void hapusData();
        void cetakLaporan();

int main() {
    initData(); 
        
    int pilihan;
    do {
        cout << "\n=== SISTEM MANAJEMEN AKADEMI SIHIR ===\n";
        cout << "[1] Tambah Data Siswa\n";
        cout << "[2] Lihat Data Siswa\n";
        cout << "[3] Hapus Data Siswa\n";
        cout << "[4] Cetak Laporan Kelas Remedial\n";
        cout << "[0] Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
        case 1: 
            tambahData(); 
            break;
        case 2: 
            lihatData(); 
            break;
        case 3: 
            hapusData(); 
            break;
        case 4: 
            cetakLaporan(); 
            break;
        case 0: 
            cout << "Keluar dari program...\n"; 
            break;
        default: 
            cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 0);
        
    return 0;
}

void initData() {

}

void saveAppendData() {

}

void saveOverwriteData() {

}

int Hitung_Bonus(int fokus) {

    return 0; 
}

int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari) {

    return -1;
}

void swapData(Siswa *a, Siswa *b) {

}

int partition(Siswa arr[], int low, int high) {

}

void quickSort(Siswa arr[], int low, int high) {

}

void tambahData() {

}

void lihatData() {

}

void hapusData() {

}

void cetakLaporan() {

}
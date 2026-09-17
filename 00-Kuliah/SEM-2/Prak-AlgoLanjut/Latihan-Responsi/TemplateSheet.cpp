#include <iostream>
#include <fstream>
using namespace std;

struct AtributSihir {
  // TODO: Isi dengan variabel Teori, Praktek, Level_Fokus (tipe integer)
};

struct Siswa {
  // TODO: Isi dengan variabel ID (int), Nama (string), Asrama (string)
  // Jangan lupa panggil struct AtributSihir di sini dengan nama variabel: Statistik
};

// Variabel Global
Siswa arraySiswa[100];
int jumlah_siswa = 0;

void initData();          // Dijalankan HANYA DI AWAL saat program pertama kali dibuka
void saveAppendData();    // Digunakan khusus untuk menu Tambah Data (ios::app)
void saveOverwriteData(); // Digunakan khusus untuk menu Hapus Data (overwrite)

int Hitung_Bonus(int fokus);
int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari);

// Fungsi Pointer dan Sorting (Quick Sort)
void swapData(Siswa *a, Siswa *b);
int partition(Siswa arr[], int low, int high);
void quickSort(Siswa arr[], int low, int high);

// Fungsi Menu 
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
  // TODO: Baca data dari file data_siswa.txt dan masukkan ke dalam arraySiswa.
}

void saveAppendData() {
  // KETERANGAN: Dipanggil khusus setelah berhasil menambahkan data baru
  // TODO: Tambahkan 1 data siswa terbaru dari array ke bagian bawah file data_siswa.txt (mode append).
}

void saveOverwriteData() {
  // KETERANGAN: Dipanggil khusus setelah berhasil menghapus data (shift-left)
  // TODO: Tulis ulang (overwrite) seluruh isi arraySiswa ke dalam file data_siswa.txt.
}

int Hitung_Bonus(int fokus) {
  // TODO: Hitung bonus resonansi mana menggunakan fungsi rekursif.
  return 0; 
}

int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari) {
  // TODO: Lakukan pencarian indeks array berdasarkan ID menggunakan algoritma Binary Search.
  return -1;
}

void swapData(Siswa *a, Siswa *b) {
  // TODO: Tukar nilai data struct menggunakan parameter Pointer
}

int partition(Siswa arr[], int low, int high) {
  // TODO: Tulis algoritma Quick Sort
}

void quickSort(Siswa arr[], int low, int high) {
  // TODO: Tulis algoritma Quick Sort
}

void tambahData() {
  // TODO: Minta input data siswa baru, masukkan ke dalam array, lalu simpan ke file secara real-time.
}

void lihatData() {
  // TODO: Urutkan data menggunakan Quick Sort, lalu tampilkan semua data beserta perhitungan Total Mana-nya.
}

void hapusData() {
  // TODO: Cari ID siswa, hapus datanya dari array (Shift Left), lalu perbarui file secara real-time.
}

void cetakLaporan() {
  // TODO: Cetak data siswa yang memiliki Total Mana < 150 ke dalam file kelas_remedial.txt.
}
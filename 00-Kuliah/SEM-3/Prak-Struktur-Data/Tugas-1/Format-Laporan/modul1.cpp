#include <iostream>
#include <string>
using namespace std;

// Function Helper Visual
void judulMenu(string judul) {
  system("color f0");
  system("cls");
  cout << "==========[" << judul << "]==========\n";
}

void jeda() {
  cout << "\n\t    Tekan Enter untuk lanjut...";
  cin.get();
}

// Global Variable & Deklarasi
const int KAPASITAS = 10;
int COUNTER_DATA = 0;

struct Mahasiswa {
  string nim;
  string nama;
  double ipk;
};

struct DataMahasiswa {
  Mahasiswa data[KAPASITAS];
  int jumlah;
};

// Function Prototype Logic
void init(DataMahasiswa& daftar);
bool tambahMahasiswa(DataMahasiswa& daftar, const Mahasiswa& mhs);
void tampilkan(const DataMahasiswa& daftar);
void tampilkanSatuan(const DataMahasiswa& daftar, int index);
int cariNim(const DataMahasiswa& daftar, const string& nim);
bool ubahIpk(DataMahasiswa& daftar, const string& nim, double ipkBaru);

// Function Prototype Display
void menu1(DataMahasiswa& daftar);
void menu2(const DataMahasiswa& daftar);
void menu3(const DataMahasiswa& daftar);
void menu4(DataMahasiswa& daftar);
void menu5(const DataMahasiswa& daftar);

// Main Function
int main() {
  DataMahasiswa daftar;
  init(daftar);
  int pilihanMenu;
  do {
    system("color f0");
    system("cls");
    cout << "=================[ Menu Utama ]================\n"
        << "|                                             |\n"
        << "| [1] Tambahkan Data Mahasiswa                |\n"
        << "| [2] Tampilkan Data Mahasiswa                |\n"
        << "| [3] Cari Mahasiswa Berdasarkan NIM          |\n"
        << "| [4] Ubah IPK Mahasiswa                      |\n"
        << "| [5] Jumlah Mahasiswa                        |\n"
        << "| [6] Keluar                                  |\n"
        << "===============================================\n"
        << "\n > Pilih [1-6] : ";
    cin >> pilihanMenu;
    cin.ignore();

    switch (pilihanMenu) {
      case 1:
        menu1(daftar);
        break;
      case 2:
        menu2(daftar);
        break;
      case 3:
        menu3(daftar);
        break;
      case 4:
        menu4(daftar);
        break;
      case 5:
        menu5(daftar);
        break;
      case 6:
        cout << "\n\t    [Program Selesai] - Terima Kasih\n";
        break;
      default:
        cout << "\n\t    [ERROR] - Input Tidak Valid\n";
        jeda();
        break;
    }
  } while (pilihanMenu != 6);
  return 0;
}

// Function Helper Logic
void init(DataMahasiswa& daftar) { daftar.jumlah = 0; }

bool tambahMahasiswa(DataMahasiswa& daftar, const Mahasiswa& mhs) {
  if (daftar.jumlah == KAPASITAS) return false;
  for (int i = 0; i < daftar.jumlah; i++) {
    if (daftar.data[i].nim == mhs.nim) return false;
  }
  daftar.data[daftar.jumlah] = mhs;
  daftar.jumlah++;
  return true;
}

void tampilkan(const DataMahasiswa& daftar) {
  for (int i = 0; i < daftar.jumlah; i++) {
    cout << "\n [Data Ke-" << i + 1 << "]------------------------\n"
        << " [1] Nama : " << daftar.data[i].nama << "\n"
        << " [2] NIM  : " << daftar.data[i].nim << "\n"
        << " [3] IPK  : " << daftar.data[i].ipk << "\n";
  }
}

void tampilkanSatuan(const DataMahasiswa& daftar, int index) {
  cout << "\n [Data Mahasiswa Ke-" << index + 1 << "]------------------------\n"
      << " [1] Nama : " << daftar.data[index].nama << "\n"
      << " [2] NIM  : " << daftar.data[index].nim << "\n"
      << " [3] IPK  : " << daftar.data[index].ipk << "\n";
}

int cariNim(const DataMahasiswa& daftar, const string& nim) {
  for (int i = 0; i < daftar.jumlah; i++) {
    if (daftar.data[i].nim == nim) return i;
  }
  return -1;
}

bool ubahIpk(DataMahasiswa& daftar, const string& nim, double ipkBaru) {
  if (ipkBaru < 0.0 || ipkBaru > 4.0) return false;
  int indeks = cariNim(daftar, nim);
  if (indeks == -1) return false;
  daftar.data[indeks].ipk = ipkBaru;
  return true;
}

// Function Display
void menu1(DataMahasiswa& daftar) {
  char ulang;
  Mahasiswa temp;
  do {
    judulMenu("Tambahkan Data Mahasiswa");
    if (daftar.jumlah == KAPASITAS) {
      cout << "\n\t [!] Data Mahasiswa Penuh\n";
      jeda();
      return;
    }
    cout << "\n [Data Ke-" << daftar.jumlah + 1 << "]------------------------\n";
    cout << " [1] Masukkan Nama : ";
    getline(cin, temp.nama);
    cout << " [2] Masukkan NIM  : ";
    cin >> temp.nim;
    cin.ignore();
    cout << " [3] Masukkan IPK  : ";
    cin >> temp.ipk;
    cin.ignore();

    if (tambahMahasiswa(daftar, temp)) {
      cout << "\n\t [SUKSES] Data berhasil ditambahkan\n";
    } else {
      cout << "\n\t [GAGAL] Data penuh atau NIM sudah terdaftar\n";
    }
    cout << "\n Tambah Data Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu2(const DataMahasiswa& daftar) {
  judulMenu("Tampilkan Data Mahasiswa");
  if (daftar.jumlah == 0) {
    cout << "\n\t [!] Data Mahasiswa Masih Kosong\n";
    jeda();
    return;
  }
  tampilkan(daftar);
  cout << "\n ---------------------------------------------\n";
  cout << "\n\t [SUKSES] Semua data berhasil ditampilkan\n";
  jeda();
}

void menu3(const DataMahasiswa& daftar) {
  char ulang;
  do {
    judulMenu("Cari Berdasarkan NIM");
    if (daftar.jumlah == 0) {
      cout << "\n\t [!] Data Mahasiswa Masih Kosong\n";
      jeda();
      return;
    }
    string target;
    cout << "\n [>] Masukkan NIM : ";
    cin >> target;
    cin.ignore();
    int indeks = cariNim(daftar, target);
    if (indeks != -1) {
      cout << "\n\t [SUKSES] Data Ditemukan\n";
      tampilkanSatuan(daftar, indeks);
    } else {
      cout << "\n\t [GAGAL] Data Tidak Ditemukan\n";
    }
    cout << "\n Cari Data Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu4(DataMahasiswa& daftar) {
  char ulang;
  do {
    judulMenu("Ubah IPK Mahasiswa");
    if (daftar.jumlah == 0) {
      cout << "\n\t [!] Data Mahasiswa Masih Kosong\n";
      jeda();
      return;
    }
    string target;
    double ipkBaru;
    cout << "\n [>] Masukkan NIM      : ";
    cin >> target;
    cin.ignore();
    cout << " [>] Masukkan IPK Baru : ";
    cin >> ipkBaru;
    cin.ignore();

    if (ubahIpk(daftar, target, ipkBaru)) {
      cout << "\n\t [SUKSES] IPK berhasil diubah!\n";
      tampilkanSatuan(daftar, cariNim(daftar, target));
    } else {
      cout << "\n\t [GAGAL] NIM tidak ditemukan atau IPK tidak valid!\n";
    }
    cout << "\n Ubah Data IPK Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu5(const DataMahasiswa& daftar) {
  judulMenu("Jumlah Mahasiswa");
  if (daftar.jumlah == 0) {
    cout << "\n\t [!] Data Mahasiswa Masih Kosong\n";
    jeda();
    return;
  }
  cout << "\n Jumlah Data Tercatat : " << daftar.jumlah << " Mahasiswa\n";
  jeda();
}
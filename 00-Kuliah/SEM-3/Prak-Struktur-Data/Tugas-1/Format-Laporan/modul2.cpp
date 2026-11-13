#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
  string nim, nama;
  double ipk;
};

// Function Helper Visual
void judulMenu(string judul) {
  cout << "\n==========[" << judul << "]==========\n";
}
void garis() { cout << " -----------------------------------------\n"; }

// Function Prototype
void inputData(Mahasiswa* data, int jumlah);
void tampilkanData(const Mahasiswa* data, int jumlah);
int cariNim(const Mahasiswa* data, int jumlah, const string& nim);

// Main Function
int main() {
  system("color f0");
  system("cls");
  int jumlah;
  judulMenu("Input Max Mahasiswa");
  cout << " [>] Masukkan Jumlah Max Mahasiswa : ";
  cin >> jumlah;
  cin.ignore();
  if (jumlah <= 0) return 0;

  Mahasiswa* data = new Mahasiswa[jumlah];

  judulMenu("Input Data Mahasiswa");
  inputData(data, jumlah);

  judulMenu("Tampilkan Data Mahasiswa");
  tampilkanData(data, jumlah);

  string nim;
  judulMenu("Cari Data NIM Mahasiswa");
  cout << " [>] Masukkan NIM : ";
  cin >> nim;
  cin.ignore();

  int posisi = cariNim(data, jumlah, nim);
  cout << " Index array : " << posisi << "\n";

  delete[] data;
  return 0;
}

// Function Logic
void inputData(Mahasiswa* data, int jumlah) {
  for (int i = 0; i < jumlah; i++) {
    cout << "\n [Data Ke-" << i + 1 << "]--------------------\n";
    cout << "   [1] Nama : ";
    getline(cin, data[i].nama);
    cout << "   [2] NIM  : ";
    cin >> data[i].nim;
    cin.ignore();
    cout << "   [3] IPK  : ";
    cin >> data[i].ipk;
    cin.ignore();
  }
  garis();
}

void tampilkanData(const Mahasiswa* data, int jumlah) {
  for (int i = 0; i < jumlah; i++) {
    cout << "\n [Data Ke-" << i + 1 << "]--------------------\n"
        << "   [1] Nama : " << data[i].nama << "\n"
        << "   [2] NIM  : " << data[i].nim << "\n"
        << "   [3] IPK  : " << data[i].ipk << "\n";
  }
  garis();
}

int cariNim(const Mahasiswa* data, int jumlah, const string& nim) {
  for (int i = 0; i < jumlah; i++) {
    if (data[i].nim == nim) {
      cout << "\n\t [SUKSES] Data Ditemukan\n"
          << "\n [Data Ke-" << i + 1 << "]--------------------\n"
          << "   [1] Nama : " << data[i].nama << "\n"
          << "   [2] NIM  : " << data[i].nim << "\n"
          << "   [3] IPK  : " << data[i].ipk << "\n";
      garis();
      return i;
    }
  }
  return -1;
}
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
  string nim, nama;
  double ipk;
};

struct Node {
  Mahasiswa data;
  Node* next;
};

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

// Function Prototype
bool nimTersedia(const Node* head, const string& nim);
bool tambahAkhir(Node*& head, const Mahasiswa& data);
Node* cariNim(Node* head, const string& nim);
bool hapusNim(Node*& head, const string& nim);
void tampilkanSemua(const Node* head);
int jumlahData(const Node* head);
void clear(Node*& head);
void menu1(Node*& head);
void menu2(Node*& head);
void menu3(Node*& head);
void menu4(Node*& head);
void menu5(Node*& head);

// Main Function
int main() {
  Node* head = nullptr;
  int pilihanMenu;
  do {
    system("color f0");
    system("cls");
    cout << "===============[ Menu Utama ]==============\n"
         << "| [1] Tambah Data Mahasiswa               |\n"
         << "| [2] Tampilkan Data Mahasiswa            |\n"
         << "| [3] Cari Data NIM Mahasiswa             |\n"
         << "| [4] Hapus Data Mahasiswa                |\n"
         << "| [5] Jumlah Mahasiswa                    |\n"
         << "| [6] Keluar                              |\n"
         << "===========================================\n"
         << "\n > Pilih [1-6] : ";
    cin >> pilihanMenu;
    cin.ignore();

    switch (pilihanMenu) {
      case 1: menu1(head); break;
      case 2: menu2(head); break;
      case 3: menu3(head); break;
      case 4: menu4(head); break;
      case 5: menu5(head); break;
      case 6:
        cout << "\n\t    [Program Selesai] - Terima Kasih\n"; break;
      default:
        cout << "\n\t    [ERROR] - Input Tidak Valid\n";
        jeda(); break;
    }
  } while (pilihanMenu != 6);
  clear(head);
  return 0;
}

// Function Helper & Logic
bool listKosong(const Node* head) { 
  return head == nullptr; 
}

bool nimTersedia(const Node* head, const string& nim) {
  while (head != nullptr) {
    if (nim == head->data.nim) return true;
    head = head->next;
  }
  return false;
}

bool tambahAkhir(Node*& head, const Mahasiswa& data) {
  if (nimTersedia(head, data.nim)) return false;
  Node* newNode = new Node{data, nullptr};

  if (listKosong(head)) {
    head = newNode;
    return true;
  }

  Node* temp = head;
  while (temp->next != nullptr) temp = temp->next;
  temp->next = newNode;
  return true;
}

void tampilkanSemua(const Node* head) {
  int counter = 0;
  while (head != nullptr) {
    cout << "\n [Data Ke-" << counter + 1 << "]--------------\n"
         << " [1] Nama : " << head->data.nama << "\n"
         << " [2] NIM  : " << head->data.nim << "\n"
         << " [3] IPK  : " << head->data.ipk << "\n";
    head = head->next;
    counter++;
  }
  cout << "\n -----------------------------------\n";
}

void tampilkanSatuan(const Node* node) {
  cout << "\n [Data Mahasiswa]------------------\n"
       << " [1] Nama : " << node->data.nama << "\n"
       << " [2] NIM  : " << node->data.nim << "\n"
       << " [3] IPK  : " << node->data.ipk << "\n"
       << "\n -----------------------------------\n";
}

Node* cariNim(Node* head, const string& nim) {
  while (head != nullptr) {
    if (head->data.nim == nim) return head;
    head = head->next;
  }
  return nullptr;
}

bool hapusNim(Node*& head, const string& nim) {
  if (head == nullptr) return false;
  Node *temp = head, *sebelum = nullptr;

  while (temp != nullptr && temp->data.nim != nim) {
    sebelum = temp;
    temp = temp->next;
  }
  if (temp == nullptr) return false;
  if (sebelum == nullptr)
    head = temp->next;
  else
    sebelum->next = temp->next;

  delete temp;
  return true;
}

int jumlahData(const Node* head) {
  int counter = 0;
  while (head != nullptr) {
    counter++;
    head = head->next;
  }
  return counter;
}

void clear(Node*& head) {
  while (head != nullptr) {
    Node* hapus = head;
    head = head->next;
    delete hapus;
  }
}

// Function Display (Menu)
void menu1(Node*& head) {
  char ulang;
  Mahasiswa temp;
  do {
    judulMenu("Tambahkan Data Mahasiswa");
    cout << "\n [1] Masukkan Nama : ";
    getline(cin, temp.nama);
    cout << " [2] Masukkan NIM  : ";
    cin >> temp.nim;
    cin.ignore();
    cout << " [3] Masukkan IPK  : ";
    cin >> temp.ipk;
    cin.ignore();

    if (tambahAkhir(head, temp)) {
      cout << "\n\t [SUKSES] Data ditambahkan\n";
    } else {
      cout << "\n\t [GAGAL] NIM sudah terdaftar\n";
    }
    cout << "\n Tambah Data Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu2(Node*& head) {
  judulMenu("Tampilkan Data Mahasiswa");
  if (listKosong(head)) {
    cout << "\n\t [KESALAHAN] Data Kosong\n";
    jeda();
    return;
  }
  tampilkanSemua(head);
  jeda();
}

void menu3(Node*& head) {
  char ulang;
  string target;
  do {
    judulMenu("Cari Data Mahasiswa");
    if (listKosong(head)) {
      cout << "\n\t [KESALAHAN] Data Kosong\n";
      jeda();
      return;
    }

    cout << "\n [>] Masukkan Data NIM : ";
    cin >> target;
    cin.ignore();
    Node* alamat = cariNim(head, target);

    if (alamat) {
      cout << "\n\t [SUKSES] Data Ditemukan\n";
      tampilkanSatuan(alamat);
    } else {
      cout << "\n\t [GAGAL] Data Tidak Ditemukan\n";
    }
    cout << "\n Cari Data Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu4(Node*& head) {
  char ulang;
  string target;
  do {
    judulMenu("Hapus Data Mahasiswa");
    if (listKosong(head)) {
      cout << "\n\t [KESALAHAN] Data Kosong\n";
      jeda();
      return;
    }
    cout << "\n [>] Masukkan Data NIM : ";
    cin >> target;
    cin.ignore();
    if (hapusNim(head, target)){
      cout << "\n\t [SUKSES] Data Berhasil Dihapus\n";
    } else {
      cout << "\n\t [GAGAL] Data Tidak Ditemukan\n";
    }
    cout << "\n Hapus Data Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}


void menu5(Node*& head) {
  judulMenu("Jumlah Mahasiswa");
  if (listKosong(head)) {
    cout << "\n\t [KESALAHAN] Data Kosong\n";
    jeda();
    return;
  }
  cout << "\n [>] Jumlah Data Tercatat : " << jumlahData(head) << " Mahasiswa\n";
  jeda();
}
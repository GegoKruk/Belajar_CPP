#include <iostream>
#include <string>
using namespace std;

struct Lagu {
  string judul, penyanyi;
};

struct Node {
  Lagu data;
  Node* prev;
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
bool listKosong(Node* head, Node* tail);
bool judulTersedia(const Node* head, const string& judul);
bool tambahAkhir(Node*& head, Node*& tail, const Lagu& data);
Node* cariJudul(Node* head, const string& judul);
bool hapusJudul(Node*& head, Node*& tail, const string& judul);
void tampilMaju(const Node* head);
void tampilMundur(const Node* head, const Node* tail);
void tampilSatuan(const Node* node);
int jumlahData(const Node* head);
void clear(Node*& head, Node*& tail);
void menu1(Node*& head, Node*& tail);
void menu2(Node*& head);
void menu3(Node*& head, Node*& tail);
void menu4(Node*& head);
void menu5(Node*& head, Node*& tail);
void menu6(Node*& head);

// Main Function
int main() {
  Node *head = nullptr, *tail = nullptr;
  int pilihanMenu;
  do {
    system("color f0");
    system("cls");
    cout << "=========[ Menu Utama ]=========\n"
         << "| [1] Tambah Lagu              |\n"
         << "| [2] Tampilkan Maju           |\n"
         << "| [3] Tampilkan Mundur         |\n"
         << "| [4] Cari Lagu                |\n"
         << "| [5] Hapus Lagu               |\n"
         << "| [6] Jumlah Lagu              |\n"
         << "| [7] Keluar                   |\n"
         << "================================\n"
         << "\n > Pilih [1-7] : ";
    cin >> pilihanMenu;
    cin.ignore();

    switch (pilihanMenu) {
      case 1: menu1(head, tail); break;
      case 2: menu2(head); break;
      case 3: menu3(head, tail); break;
      case 4: menu4(head); break;
      case 5: menu5(head, tail); break;
      case 6: menu6(head); break;
      case 7:
        cout << "\n\t    [Program Selesai] - Terima Kasih\n";
        exit(0);
      default:
        cout << "\n\t    [ERROR] - Input Tidak Valid\n";
        jeda(); break;
    }
  } while (pilihanMenu != 7);
  clear(head, tail);
  return 0;
}

// Function Helper & Logic
bool listKosong(Node* head, Node* tail) {
  return head == nullptr && tail == nullptr;
}

bool judulTersedia(const Node* head, const string& judul) {
  while (head != nullptr) {
    if (judul == head->data.judul) return true;
    head = head->next;
  }
  return false;
}

bool tambahAkhir(Node*& head, Node*& tail, const Lagu& data) {
  if (judulTersedia(head, data.judul)) return false;
  Node* newNode = new Node{data, nullptr, nullptr};

  if (listKosong(head, tail)) {
    head = tail = newNode;
    return true;
  }

  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
  return true;
}

Node* cariJudul(Node* head, const string& judul) {
  while (head != nullptr) {
    if (head->data.judul == judul) return head;
    head = head->next;
  }
  return nullptr;
}

void tampilMaju(const Node* head) {
  int counter = 0;
  while (head != nullptr) {
    cout << "\n [Data Lagu Ke-" << ++counter << "]-------------------\n"
         << " [1] Judul    : " << head->data.judul << "\n"
         << " [2] Penyanyi : " << head->data.penyanyi << "\n";
    head = head->next;
  }
  cout << "\n -----------------------------------\n";
}

bool hapusJudul(Node*& head, Node*& tail, const string& judul) {
  Node* target = cariJudul(head, judul);
  if (target == nullptr) return false;

  if (target == head && target == tail) {
    head = tail = nullptr;
  } else if (target == head) {
    head = target->next;
    head->prev = nullptr;
  } else if (target == tail) {
    tail = target->prev;
    tail->next = nullptr;
  } else {
    target->prev->next = target->next;
    target->next->prev = target->prev;
  }
  delete target;
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

void tampilMundur(const Node* head, const Node* tail) {
  int counter = jumlahData(head);
  while (tail != nullptr) {
    cout << "\n [Data Lagu Ke-" << counter-- << "]-------------------\n"
         << " [1] Judul    : " << tail->data.judul << "\n"
         << " [2] Penyanyi : " << tail->data.penyanyi << "\n";
    tail = tail->prev;
  }
  cout << "\n -----------------------------------\n";
}

void tampilSatuan(const Node* node) {
  cout << "\n [Data Lagu]--------------\n"
       << " [1] Judul     : " << node->data.judul << "\n"
       << " [2] Penyanyi  : " << node->data.penyanyi << "\n"
       << "\n -----------------------------------\n";
}

void clear(Node*& head, Node*& tail) {
  while (head != nullptr) {
    Node* hapus = head;
    head = head->next;
    delete hapus;
  }
  tail = nullptr;
}

// Function Display (Menu)
void menu1(Node*& head, Node*& tail) {
  char ulang;
  Lagu tempLagu;
  do {
    judulMenu("Tambah Lagu");
    cout << "\n [1] Masukkan Judul     : ";
    getline(cin, tempLagu.judul);
    cout << " [2] Masukkan Penyanyi  : ";
    getline(cin, tempLagu.penyanyi);

    if (tambahAkhir(head, tail, tempLagu))
      cout << "\n\t [SUKSES] Data berhasil ditambahkan\n";
    else
      cout << "\n\t [GAGAL] Data penuh atau Judul sudah terdaftar\n";

    cout << "\n Tambah Lagu Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu2(Node*& head) {
  judulMenu("Tampilkan Maju");
  if (jumlahData(head) == 0) {
    cout << "\n\t [KESALAHAN] Data Kosong\n";
    jeda();
    return;
  }
  tampilMaju(head);
  jeda();
}

void menu3(Node*& head, Node*& tail) {
  judulMenu("Tampilkan Mundur");
  if (jumlahData(head) == 0) {
    cout << "\n\t [KESALAHAN] Data Kosong\n";
    jeda();
    return;
  }
  tampilMundur(head, tail);
  jeda();
}

void menu4(Node*& head) {
  char ulang;
  string target;
  do {
    judulMenu("Cari Lagu");
    if (jumlahData(head) == 0) {
      cout << "\n\t [KESALAHAN] Data Kosong\n";
      jeda();
      return;
    }

    cout << "\n [>] Masukkan Judul : ";
    getline(cin, target);
    Node* alamat = cariJudul(head, target);

    if (alamat) {
      cout << "\n\t [SUKSES] Data Ditemukan\n";
      tampilSatuan(alamat);
    } else
      cout << "\n\t [GAGAL] Data Tidak Ditemukan\n";

    cout << "\n Cari Lagu Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu5(Node*& head, Node*& tail) {
  char ulang;
  string target;
  do {
    judulMenu("Hapus Lagu");
    if (jumlahData(head) == 0) {
      cout << "\n\t [KESALAHAN] Data Kosong\n";
      jeda();
      return;
    }

    cout << "\n [>] Masukkan Judul : ";
    getline(cin, target);

    if (hapusJudul(head, tail, target))
      cout << "\n\t [SUKSES] Data Berhasil Dihapus\n";
    else
      cout << "\n\t [GAGAL] Data Tidak Ditemukan\n";

    cout << "\n Hapus Lagu Lainnya? [Y/N] : ";
    cin >> ulang;
    cin.ignore();
  } while (ulang == 'y' || ulang == 'Y');
}

void menu6(Node*& head) {
  judulMenu("Jumlah Lagu");
  cout << "\n [>] Jumlah Lagu Saat ini : " << jumlahData(head) << "\n";
  jeda();
}
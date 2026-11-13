#include <iostream>
#include <string>
using namespace std;

void judulMenu(string judul) {
  system("color f0");
  system("cls");
  cout << "\n ==========[" << judul << "]==========\n";
}
void jeda() {
  cout << "\n\t Tekan untuk lanjut...\n";
  cin.get();
}

struct nodeQueue {
  int nota;
  string nama;
  nodeQueue* next;
};
struct nodeStack {
  int nota;
  string nama;
  nodeStack* next;
};
struct nodeTree {
  int nota;
  string nama;
  nodeTree* kiri;
  nodeTree* kanan;
};

nodeQueue* front = NULL;
nodeQueue* last = NULL;
nodeStack* top = NULL;
nodeTree* root = NULL;

nodeTree* tambah_tree(nodeTree* akar, int nota, string nama) {
  if (akar == NULL) {
    nodeTree* simpulBaru = new nodeTree;
    simpulBaru->nota = nota;
    simpulBaru->nama = nama;
    simpulBaru->kiri = NULL;
    simpulBaru->kanan = NULL;
    return simpulBaru;
  }
  
  if (nota < akar->nota) {
    akar->kiri = tambah_tree(akar->kiri, nota, nama);
  } else if (nota > akar->nota) {
    akar->kanan = tambah_tree(akar->kanan, nota, nama);
  }
  
  return akar;
}

nodeTree* hapus_tree(nodeTree* akar, int nota) {
  if (akar == NULL) {
    return NULL;
  }

  if (nota < akar->nota) {
    akar->kiri = hapus_tree(akar->kiri, nota);
  } else if (nota > akar->nota) {
    akar->kanan = hapus_tree(akar->kanan, nota);
  } else {
    if (akar->kiri == NULL && akar->kanan == NULL) {
      delete akar;
      return NULL;
    } else if (akar->kiri == NULL) {
      nodeTree* sisa = akar->kanan;
      delete akar;
      return sisa;
    } else if (akar->kanan == NULL) {
      nodeTree* sisa = akar->kiri;
      delete akar;
      return sisa;
    } else {
      nodeTree* pengganti = akar->kanan;
      while (pengganti->kiri != NULL) {
        pengganti = pengganti->kiri;
      }
      akar->nota = pengganti->nota;
      akar->nama = pengganti->nama;
      akar->kanan = hapus_tree(akar->kanan, pengganti->nota);
    }
  }
  return akar;
}

nodeTree* cari_tree(nodeTree* akar, int nota) {
  if (akar == NULL) {
    return NULL;
  }
  
  if (akar->nota == nota) {
    return akar;
  }
  
  if (nota < akar->nota) {
    return cari_tree(akar->kiri, nota);
  } else {
    return cari_tree(akar->kanan, nota);
  }
}

void preorder(nodeTree* akar, int& no) {
  if (akar == NULL) return;
  cout << " [" << no << "] Nomor Nota  : " << akar->nota
       << "\n     Nama Cucian : " << akar->nama
       << "\n -------------------------------\n";
  no++;
  preorder(akar->kiri, no);
  preorder(akar->kanan, no);
}

void inorder(nodeTree* akar, int& no) {
  if (akar == NULL) return;
  inorder(akar->kiri, no);
  cout << " [" << no << "] Nomor Nota  : " << akar->nota
       << "\n     Nama Cucian : " << akar->nama
       << "\n -------------------------------\n";
  no++;
  inorder(akar->kanan, no);
}

void postorder(nodeTree* akar, int& no) {
  if (akar == NULL) return;
  postorder(akar->kiri, no);
  postorder(akar->kanan, no);
  cout << " [" << no << "] Nomor Nota  : " << akar->nota
       << "\n     Nama Cucian : " << akar->nama
       << "\n -------------------------------\n";
  no++;
}

void tambah_cucian() {
  judulMenu("Tambah Cucian");
  cout << " [>] Masukkan Nomor Nota   : ";
  int nomorNota;
  cin >> nomorNota;
  cin.ignore();

  if (cin.fail() || nomorNota < 1) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0...\n";
    return;
  }

  nodeQueue* queueTemp = front;
  while (queueTemp != NULL) {
    if (queueTemp->nota == nomorNota) {
      cout << "\n [GAGAL] Nomor Nota Sudah Ada...\n";
      return;
    }
    queueTemp = queueTemp->next;
  }

  nodeStack* stackTemp = top;
  while (stackTemp != NULL) {
    if (stackTemp->nota == nomorNota) {
      cout << "\n [GAGAL] Nomor Nota Sudah Ada...\n";
      return;
    }
    stackTemp = stackTemp->next;
  }

  cout << " [>] Masukkan Nama Cucian  : ";
  string namaCucian;
  getline(cin, namaCucian);
  if (namaCucian.empty()) {
    cout << "\n [GAGAL] Nama Cucian Tidak Boleh Kosong!\n\n";
    return;
  }
  nodeQueue* nb = new nodeQueue;
  nb->nota = nomorNota;
  nb->nama = namaCucian;
  nb->next = NULL;
  if (front == NULL)
    front = last = nb;
  else {
    last->next = nb;
    last = nb;
  }
  cout << "\n [SUKSES] Memasukkan Cucian...\n";
}

void lihat_antrean() {
  if (front == NULL) {
    cout << "\n [!] Antrean Masih Kosong...\n";
    jeda();
    return;
  }
  judulMenu("Antrean Cucian");
  nodeQueue* temp = front;
  int nomor = 1;
  cout << "\n [Daftar Antrean]===============\n";
  while (temp != NULL) {
    cout << " [" << nomor << "] Nomor Nota  : " << temp->nota
         << "\n     Nama Cucian : " << temp->nama
         << "\n -------------------------------\n";
    temp = temp->next;
    nomor++;
  }
  cout << "\n [SUKSES] Semua Daftar Antrean Telah Ditampilkan!\n";
  jeda();
}

void proses_cucian() {
  if (front == NULL) {
    cout << "\n [!] Antrean Masih Kosong...\n";
    jeda();
    return;
  }
  judulMenu("Proses Cucian");
  nodeQueue* hapus = front;
  nodeStack* nodeRiwayat = new nodeStack;
  nodeRiwayat->nota = hapus->nota;
  nodeRiwayat->nama = hapus->nama;
  nodeRiwayat->next = top;
  top = nodeRiwayat;
  root = tambah_tree(root, hapus->nota, hapus->nama);
  cout << "\n [SUKSES] Berhasil Memproses Cucian " << hapus->nama << "\n";
  front = front->next;
  if (front == NULL) last = NULL;
  delete hapus;
  jeda();
}

void lihat_riwayat() {
  if (top == NULL) {
    cout << "\n [!] Belum Ada Cucian Selesai...\n";
    jeda();
    return;
  }
  judulMenu("Riwayat Cucian");
  nodeStack* temp = top;
  int nomor = 1;
  cout << "\n [Daftar Riwayat Selesai]=======\n";
  while (temp != NULL) {
    cout << " [" << nomor << "] Nomor Nota  : " << temp->nota
         << "\n     Nama Cucian : " << temp->nama
         << "\n -------------------------------\n";
    temp = temp->next;
    nomor++;
  }
  cout << "\n [SUKSES] Semua Daftar Riwayat Telah Ditampilkan!\n";
  jeda();
}

void cari_cucian() {
  if (root == NULL) {
    cout << "\n [!] Rak Masih Kosong...\n";
    jeda();
    return;
  }
  judulMenu("Cari Cucian");
  int nomorNota;
  cout << " [>] Masukkan Nomor Nota : ";
  cin >> nomorNota;
  cin.ignore();

  if (cin.fail() || nomorNota <= 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0!\n";
    jeda();
    return;
  }

  nodeTree* hasil = cari_tree(root, nomorNota);
  if (hasil == NULL)
    cout << "\n [GAGAL] Cucian Dengan Nota " << nomorNota
         << " Tidak Ditemukan Di Rak!\n";
  else {
    cout << " \n[Data Ditemukan]===============\n" 
         << "[>] No Nota Cucian : " << hasil->nota << "\n" 
         << "[>] Nama Cucian    : " << hasil->nama << "\n"
         << "\n ===============================\n";
  }
  jeda();
}

void lihat_rak() {
  if (root == NULL) {
    cout << "\n [!] Rak Masih Kosong...\n";
    jeda();
    return;
  }
  int pilihanMenu;
  int nomor = 1;
  cout << "\n ===== [Lihat Rak] ======\n"
       << " |    [1] Pre-Order     |\n"
       << " |    [2] In-Order      |\n"
       << " |    [3] Post-Order    |\n"
       << " ========================\n"
       << " Pilih Menu : ";
  if (!(cin >> pilihanMenu)) {
    cin.clear();
    cin.ignore(1000, '\n');
    pilihanMenu = -1;
  } else
    cin.ignore();

  switch (pilihanMenu) {
    case 1:
      cout << "\n [Tampilan Pre-Order]===========\n";
      preorder(root, nomor); jeda(); break;
    case 2:
      cout << "\n [Tampilan In-Order]============\n";
      inorder(root, nomor); jeda(); break;
    case 3:
      cout << "\n [Tampilan Post-Order]==========\n";
      postorder(root, nomor); jeda(); break;
    case 0: break;
    default:
      cout << "\n [!] Input salah! Silakan ketik angka antara 0 sampai 3\n"; 
      jeda(); break;
  }
}

void ambil_cucian() {
  if (root == NULL) {
    cout << "\n [!] Rak Masih Kosong...\n";
    jeda();
    return;
  }
  judulMenu("Ambil Cucian");
  int nomorNota;
  cout << " [>] Masukkan Nomor Nota : ";
  cin >> nomorNota;
  cin.ignore();

  if (cin.fail() || nomorNota <= 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0!\n";
    jeda();
    return;
  }

  nodeTree* temp = cari_tree(root, nomorNota);
  if (temp == NULL) {
    cout << " [GAGAL] Nomor Nota " << nomorNota << " Tidak Ada!\n\n";
    jeda();
    return;
  }

  cout << " \n[Data Cucian Diambil]==========\n" 
       << " [>] No Nota Cucian : " << temp->nota << "\n" 
       << " [>] Nama Cucian    : " << temp->nama << "\n" 
       << "\n [SUKSES] Cucian Berhasil Diambil...\n";
  root = hapus_tree(root, nomorNota);
  jeda();
}

int main() {
  int pilihanMenu;
  do {
    system("color f0");
    system("cls");
    cout << "\n ========== [MENU UTAMA] ==========\n"
         << " |  [1] Tambah Cucian             |\n"
         << " |  [2] Lihat Antrean Cucian      |\n"
         << " |  [3] Proses Cucian             |\n"
         << " |  [4] Lihat Cucian Selesai      |\n"
         << " |  [5] Cari Cucian di Rak        |\n"
         << " |  [6] Lihat Rak                 |\n"
         << " |  [7] Ambil Cucian              |\n"
         << " |  [0] Keluar Program            |\n"
         << " ==================================\n\n"
         << " [>] Pilih menu [0-7] : ";

    if (!(cin >> pilihanMenu)) {
      cin.clear();
      cin.ignore(1000, '\n');
      pilihanMenu = -1;
    } else {
      cin.ignore();
    } 
    switch (pilihanMenu) {
      case 1: {
        char lanjut;
        do {
          tambah_cucian();
          cout << "\n Tambah Cucian Lainnya? [Y/N] : ";
          cin >> lanjut;
          cin.ignore();
        } while (lanjut == 'y' || lanjut == 'Y'); break;
      }
      case 2: lihat_antrean(); break;
      case 3: proses_cucian(); break;
      case 4: lihat_riwayat(); break;
      case 5: cari_cucian(); break;
      case 6: lihat_rak(); break;
      case 7: ambil_cucian(); break;
      case 0:
        cout << "\n\t[ Program Selesai ]\n\tSampai jumpa kembali!\n"; 
        break;
      default:
        cout << "\n [!] Input salah! Silakan ketik angka 0 - 7\n";
        jeda(); break;
    }
  } while (pilihanMenu != 0);
  return 0;
}
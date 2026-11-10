#include <iostream>
#include <string>
using namespace std;

// Helper Visual Function
void judulNama(){
    system("color 0B");
    system("cls");
    cout << "\n ==========[PRAKTIKUM P9]==========" << endl;
    cout << " |        LATIHAN RESPONSI        |" << endl;
    cout << " |  ____________________________  |" << endl;
    cout << " |                                |" << endl;
    cout << " |      Nama  : Gega Ramadhan     |" << endl;
    cout << " |      NIM   : 123250112         |" << endl;
    cout << " |      Kelas : IF-C              |" << endl;
    cout << " |                                |" << endl;
    cout << " |________________________________|\n" << endl;
}

void judulSection(string judul){
    judulNama();
    cout << "\n ==========["<<judul<<"]==========" << endl;
}

void jeda(){
    cout << "\n\t Tekan untuk lanjut..." << endl;
    cin.get();
}

// Deklarasi & Variabel
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


// menambahkan node baru ke tree berdasarkan nomor nota.
// nota lebih kecil masuk ke kiri, nota lebih besar masuk ke kanan.
// mengembalikan akar tree setelah penambahan.
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

// mencari node di tree berdasarkan nomor nota.
// mengembalikan node yang ditemukan, atau NULL jika tidak ada.
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

// menghapus node di tree berdasarkan nomor nota.
// harus menangani 3 kasus: tanpa anak, satu anak, dan dua anak.
// mengembalikan akar tree setelah penghapusan.
nodeTree* hapus_tree(nodeTree* akar, int nota) {
    if (akar == NULL) {
        return NULL;
    }
    
    if (nota < akar->nota) {
        akar->kiri = hapus_tree(akar->kiri, nota);
    } else if (nota > akar->nota) {
        akar->kanan = hapus_tree(akar->kanan, nota);
    } else {
        // Node ditemukan
        if (akar->kiri == NULL && akar->kanan == NULL) {
            //Tanpa anak
            delete akar;
            return NULL;
        } else if (akar->kiri == NULL) {
            //Satu anak di kanan
            nodeTree* sisa = akar->kanan;
            delete akar;
            return sisa;
        } else if (akar->kanan == NULL) {
            //Satu anak di kiri
            nodeTree* sisa = akar->kiri;
            delete akar;
            return sisa;
        } else {
            //Dua anak
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

void preorder(nodeTree* akar, int& no) {
    if (akar == NULL) {
        return;
    }
    
    cout << " [" << no << "] Nomor Nota  : " << akar->nota << endl;
    cout << "     Nama Cucian : " << akar->nama << endl;
    cout << " -------------------------------" << endl;
    no++;
    
    preorder(akar->kiri, no);
    preorder(akar->kanan, no);
}

void inorder(nodeTree* akar, int& no) {
    if (akar == NULL) {
        return;
    }
    
    inorder(akar->kiri, no);
    
    cout << " [" << no << "] Nomor Nota  : " << akar->nota << endl;
    cout << "     Nama Cucian : " << akar->nama << endl;
    cout << " -------------------------------" << endl;
    no++;
    
    inorder(akar->kanan, no);
}

void postorder(nodeTree* akar, int& no) {
    if (akar == NULL) {
        return;
    }
    
    postorder(akar->kiri, no);
    postorder(akar->kanan, no);
    
    cout << " [" << no << "] Nomor Nota  : " << akar->nota << endl;
    cout << "     Nama Cucian : " << akar->nama << endl;
    cout << " -------------------------------" << endl;
    no++;
}

void tambah_cucian() {
    judulSection("Tambah Cucian");
    cout << " [>] Masukkan Nomor Nota   : ";
    int nomorNota;
    cin >> nomorNota;
    cin.ignore();

    if (cin.fail() || nomorNota < 1){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0..." << endl;
        return;
    }
    
    nodeQueue* queueTemp = front;
    while (queueTemp != NULL) {
        if (queueTemp->nota == nomorNota) {
            cout << "\n [GAGAL] Nomor Nota Sudah Ada..." << endl;
            return;
        }
        queueTemp = queueTemp->next;
    }
    nodeStack* stackTemp = top;
    while (stackTemp != NULL) {
        if (stackTemp->nota == nomorNota) {
            cout << "\n [GAGAL] Nomor Nota Sudah Ada..." << endl;
            return;
        }
        stackTemp = stackTemp->next;
    }

    cout << " [>] Masukkan Nama Cucian  : ";
    string namaCucian;
    getline(cin, namaCucian);
    if (namaCucian.empty()) {
        cout << "\n [GAGAL] Nama Cucian Tidak Boleh Kosong!" << endl << endl;
        return;
    }

    nodeQueue* nb = new nodeQueue;
    nb->nota = nomorNota;
    nb->nama = namaCucian;
    nb->next = NULL;
    
    if (front == NULL) {
        front = last = nb;
    } else {
        last->next = nb;
        last = nb;
    }
    cout << "\n [SUKSES] Memasukkan Cucian..." << endl;
}

void lihat_antrean() {
    if (front == NULL){
        cout << "\n [!] Antrean Masih Kosong..." << endl;
        jeda();
        return;
    }
    
    judulSection("Antrean Cucian");
    nodeQueue* temp = front;
    int nomor = 1;
    cout << "\n [Daftar Antrean]===============" << endl;
    while (temp != NULL){
        cout << " [" << nomor << "] Nomor Nota  : " << temp->nota << endl;
        cout << "     Nama Cucian : " << temp->nama << endl;
        cout << " -------------------------------" << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "\n [SUKSES] Semua Daftar Antrean Telah Ditampilkan!" << endl;
    jeda();
}

void proses_cucian() {
    if (front == NULL){
        cout << "\n [!] Antrean Masih Kosong..." << endl;
        jeda();
        return;
    }

    judulSection("Proses Cucian");
    
    nodeQueue* hapus = front;
    
    // Pindah
    nodeStack* nodeRiwayat = new nodeStack;
    nodeRiwayat->nota = hapus->nota;
    nodeRiwayat->nama = hapus->nama;
    nodeRiwayat->next = top;
    top = nodeRiwayat;
    
    // Masukkan
    root = tambah_tree(root, hapus->nota, hapus->nama);
    
    cout << "\n [SUKSES] Berhasil Memproses Cucian " << hapus->nama << endl;
    
    // Hapus node
    front = front->next;
    if (front == NULL) {
        last = NULL;
    }
    delete hapus;
    
    jeda();
}

void lihat_riwayat() {
    if (top == NULL){
        cout << "\n [!] Belum Ada Cucian Selesai..." << endl;
        jeda();
        return;
    }

    judulSection("Riwayat Cucian");
    
    nodeStack* temp = top;
    int nomor = 1;
    
    cout << "\n [Daftar Riwayat Selesai]=======" << endl;
    while (temp != NULL){
        cout << " [" << nomor << "] Nomor Nota  : " << temp->nota << endl;
        cout << "     Nama Cucian : " << temp->nama << endl;
        cout << " -------------------------------" << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "\n [SUKSES] Semua Daftar Riwayat Telah Ditampilkan!" << endl;
    
    jeda();
}

void cari_cucian() {
    if (root == NULL){
        cout << "\n [!] Rak Masih Kosong..." << endl;
        jeda();
        return;
    }
    judulSection("Cari Cucian");

    int nomorNota;
    cout << " [>] Masukkan Nomor Nota : ";
    cin >> nomorNota;
    cin.ignore();

    if (cin.fail() || nomorNota <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0!" << endl;
        jeda();
        return;
    }
    
    nodeTree* hasil = cari_tree(root, nomorNota);
    if (hasil == NULL) {
        cout << "\n [GAGAL] Cucian Dengan Nota " << nomorNota << " Tidak Ditemukan Di Rak!" << endl;
    } else {
        cout << " \n[Data Ditemukan]===============" << endl;
        cout << " [>] No Nota Cucian : " << hasil->nota << endl;
        cout << " [>] Nama Cucian    : " << hasil->nama << endl;
        cout << " ===============================" << endl;
    }

    jeda();
}

void lihat_rak() {
    if (root == NULL){
        cout << "\n [!] Rak Masih Kosong..." << endl;
        jeda();
        return;
    }
    int pilihanMenu;
    int nomor = 1;
    cout << "\n ===== [Lihat Rak] ======" << endl;
    cout << " |                      |" << endl;
    cout << " |   [1] Pre-Order      |" << endl;
    cout << " |   [2] In-Order       |" << endl;
    cout << " |   [3] Post-Order     |" << endl;
    cout << " |                      |" << endl;
    cout << " ========================" << endl;
    cout << "\n [>] Pilih menu [0-3] : ";
    
    if (!(cin >> pilihanMenu)) {
        cin.clear();
        cin.ignore(1000, '\n');
        pilihanMenu = -1; 
    } else {
        cin.ignore();
    }
    
    switch (pilihanMenu){
        case 1:
            cout << "\n [Tampilan Pre-Order]===========" << endl;
            preorder(root, nomor);
            cout << " ===============================" << endl;
            jeda();
            break;
        case 2:
            cout << "\n [Tampilan In-Order]============" << endl;
            inorder(root, nomor);
            cout << " ===============================" << endl;
            jeda();
            break;
        case 3:
            cout << "\n [Tampilan Post-Order]==========" << endl;
            postorder(root, nomor);
            cout << " ===============================" << endl;
            jeda();
            break;
        case 0:
            break;
        default:
            cout << "\n [!] Input salah! Silakan ketik angka antara 0 sampai 3" << endl;
            jeda();
            break;
    }
}

void ambil_cucian() {
    if (root == NULL){
        cout << "\n [!] Rak Masih Kosong..." << endl;
        jeda();
        return;
    }
    judulSection("Ambil Cucian");
    int nomorNota;
    cout << " [>] Masukkan Nomor Nota : ";
    cin >> nomorNota;
    cin.ignore();

    if (cin.fail() || nomorNota <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [GAGAL] Nomor Nota Harus Lebih Dari 0!" << endl;
        jeda();
        return;
    }

    nodeTree* temp = cari_tree(root, nomorNota);
    if (temp == NULL) {
        cout << " [GAGAL] Nomor Nota " << nomorNota << " Tidak Ada!" << endl << endl;
        jeda();
        return;
    }

    cout << " \n[Data Cucian Diambil]==========" << endl;
    cout << " [>] No Nota Cucian : " << temp->nota << endl;
    cout << " [>] Nama Cucian    : " << temp->nama << endl;
    cout << " \n [SUKSES] Cucian Berhasil Diambil..." << endl;
    root = hapus_tree(root, nomorNota);
    jeda();
}

int main(){
    int pilihanMenu;
    do {
        judulNama();
        cout << "\n ========== [MENU UTAMA] ==========" << endl;
        cout << " |                                |" << endl;
        cout << " |  [1] Tambah Cucian             |" << endl;
        cout << " |  [2] Lihat Antrean Cucian      |" << endl;
        cout << " |  [3] Proses Cucian             |" << endl;
        cout << " |  [4] Lihat Cucian Selesai      |" << endl;
        cout << " |  [5] Cari Cucian di Rak        |" << endl;
        cout << " |  [6] Lihat Rak                 |" << endl;
        cout << " |  [7] Ambil Cucian              |" << endl;
        cout << " |  [0] Keluar Program            |" << endl;
        cout << " |                                |" << endl;
        cout << " ==================================" << endl;
        cout << "\n [>] Pilih menu [0-7] : ";
        if (!(cin >> pilihanMenu)) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihanMenu = -1; 
        } else {
            cin.ignore();
        }
        switch (pilihanMenu){
            case 1:
                char lanjut;
                do{
                    tambah_cucian();
                    cout << "\n Tambah Cucian Lainnya? [Y/N] : ";
                    cin >> lanjut;
                    cin.ignore();
                } while (lanjut == 'y' || lanjut == 'Y');
                break;
            case 2:
                lihat_antrean();
                break;
            case 3:
                proses_cucian();
                break;
            case 4:
                lihat_riwayat();
                break;
            case 5:
                cari_cucian();
                break;
            case 6:
                lihat_rak();
                break;
            case 7:
                ambil_cucian();
                break;
            case 0:
                judulNama();
                cout << "\n\t[ Program Selesai ]\n\tSampai jumpa kembali!" << endl;
                break;
            default:
                cout << "\n [!] Input salah! Silakan ketik angka antara 0 sampai 7" << endl;
                jeda();
                break;
        }
    } while (pilihanMenu != 0); 
    return 0;
}

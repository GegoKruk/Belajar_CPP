#include <iostream>
#include <string>
using namespace std;

void judulNama(){
    system("color 0B");
    system("cls");
    cout << "\n ====[RESPONSI PRAK STRUKTUR DATA]====" << endl;
    cout << " |                                   |" << endl;
    cout << " |       Nama : Gega Ramadhan        |" << endl;
    cout << " |       NIM  : 123250112            |" << endl;
    cout << " |___________________________________|" << endl;
}

void judul(string judul){
    judulNama();
    cout << " ==========["<<judul<<"]==========";
}
void jeda(){
    cout << "\n\t Tekan Untuk Lanjut..." << endl;
    cin.get();
}

struct nodeQueue {
    int nota;
    string nama;
    nodeQueue* next;
};

struct nodeStack{
    int nota;
    string nama;
    nodeStack *next;
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

nodeTree* tambah_tree(nodeTree* akar, int nota, string nama){
    if (akar == NULL){
        nodeTree* simpulBaru  = new nodeTree;
        simpulBaru->nota = nota;
        simpulBaru->nama = nama;
        simpulBaru->kiri = NULL;
        simpulBaru->kanan = NULL;
        return simpulBaru;
    }

    if (nota < akar->nota){
        akar->kiri = tambah_tree(akar->kiri, nota, nama);
    } else if (nota > akar->nota) {
        akar->kanan = tambah_tree(akar->kanan, nota, nama);
    }

    return akar;
}

nodeTree* cari_tree(nodeTree* akar, int nota){
    if (akar == NULL){
        return NULL;
    }

    if (akar->nota == nota){
        return akar;
    }

    if(nota < akar->nota){
        return cari_tree(akar->kiri, nota);
    } else {
        return cari_tree(akar->kanan, nota);
    }
}

nodeTree* hapus_tree(nodeTree* akar, int nota){
    if (akar == NULL){
        return NULL;
    }

    if (nota < akar->nota){
        akar->kiri = hapus_tree(akar->kiri, nota);
    } else if (nota > akar->nota){
        akar->kanan = hapus_tree(akar->kanan, nota);
    } else {
        if (akar->kiri == NULL && akar->kanan == NULL){
            delete akar;
            return NULL;
        } else if (akar->kiri == NULL){
            nodeTree* sisa = akar->kanan;
            delete akar;
            return sisa;
        } else if (akar->kanan == NULL){
            nodeTree* sisa = akar->kiri;
            delete akar;
            return sisa;
        } else {
            nodeTree* pengganti = akar->kanan;
            while (pengganti->kiri != NULL){
                pengganti = pengganti->kiri;
            }
            akar->nota = pengganti->nota;
            akar->nama = pengganti->nama;
            akar->kanan = hapus_tree(akar->kanan, pengganti->nota);
        }
    }
    return akar;
}

void preorder(nodeTree* akar, int& no){
    if (akar == NULL){
        return;
    }
    cout << " [" << no << "] Kode Energi : " << akar->nota << endl;
    cout << "    Nama Energi : " << akar->nama << endl;
    no++;
    preorder(akar->kiri, no);
    preorder(akar->kanan, no);
}

void inorder(nodeTree* akar, int& no){
    if (akar == NULL){
        return;
    }
    inorder(akar->kiri, no);
    cout << " [" << no << "] Kode Energi : " << akar->nota << endl;
    cout << "    Nama Energi : " << akar->nama << endl;
    no++;
    inorder(akar->kanan, no);
}

void postorder(nodeTree* akar, int& no){
    if (akar == NULL){
        return;
    }
    postorder(akar->kiri, no);
    postorder(akar->kanan, no);
    cout << " [" << no << "] Kode Energi : " << akar->nota << endl;
    cout << "    Nama Energi : " << akar->nama << endl;
    no++;
}

void tambahEnergi(){
    judul("Tambah energi");
    cout << "\n [>] Masukkan Kode Energi : ";
    int kode;
    cin>>kode;
    cin.ignore();

    if (cin.fail() || kode < 1){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [!] Nomor Kode Harus Lebih Dari 0..." << endl;
    }
    
    nodeQueue* queueTemp = front;
    while (queueTemp != NULL){
        if (queueTemp->nota == kode){
            cout << "\n [!] Nomor Kode Sudah Ada..." << endl;
            return;
        }
        queueTemp = queueTemp->next;
    }

    nodeStack* stackTemp = top;
    while (stackTemp != NULL){
        if (stackTemp->nota == kode){
            cout << "\n [!] Nomor Kode Sudah Ada..." << endl;
            return;
        }
        stackTemp = stackTemp->next;
    }

    cout << " [>] Masukkan Nama Energi : ";
    string namaEnergi;
    getline(cin, namaEnergi);
    if (namaEnergi.empty()){
        cout << "\n [!] Nama Energi Tidak Boleh Kosong..." << endl;
        return;
    }

    nodeQueue* nb = new nodeQueue;
    nb->nota = kode;
    nb->nama = namaEnergi;
    nb->next = NULL;;

    if(front == NULL){
        front = last = nb;
    } else {
        last->next = nb;
        last = nb;
    }
    cout << "\n [SUKSES] Memasukkan Energi Baru..." << endl;
}

void lihat_antrean(){
    judul("Antrean Energi");
    if (front == NULL){
        cout << "\n [!] Antrean Masih Kosong..." << endl;
        jeda();
        return;
    }

    nodeQueue* temp = front;
    int no = 1;
    cout << "\n [Daftar Antrean]===============" << endl;
    while (temp != NULL){
        cout << " [" << no << "] Kode Energi : " << temp->nota << endl;
        cout << "     Nama Energi : " << temp->nama << endl;
        cout << " -----------------------------" << endl;
        temp = temp->next;
        no++;
    }
    cout << "\n [SUKSES] Menampilkan Semua Daftar Antrean Energi" << endl;
    jeda();
}

void prosesEnergi(){
    judul("Proses Energi");
    if (front == NULL){
        cout << "\n [!] Antrean Masih Kosong..." << endl;
        jeda();
        return;
    }

    nodeQueue* hapus = front;
    nodeStack* nodeRiwayat = new nodeStack;

    nodeRiwayat->nota = hapus->nota;
    nodeRiwayat->nama = hapus->nama;
    nodeRiwayat->next = top;
    top = nodeRiwayat;

    root = tambah_tree(root, hapus->nota, hapus->nama);
    cout << "\n [SUKSES] Berhasil memproses Energi..." << endl;

    front = front->next;
    if(front == NULL){
        last = NULL;
    }
    delete hapus;

    jeda();
}

void lihatRiwayat(){
    judul("Riwayat Energi Terserap");
    if (top == NULL){
        cout << "\n [!] Belum ada Energi Yang Terserap..." << endl;
        jeda();
        return;
    }

    nodeStack* temp = top;
    int no = 1;
    cout << "\n [Daftar Energi Terserap]========== " << endl;
    while (temp != NULL){
        cout << " [" << no <<"] Kode Energi : " << temp->nota << endl;
        cout << "     Nama Energi : " << temp->nama << endl;
        cout << " ----------------------------------" << endl;
        temp = temp->next;
        no++;
    }
    cout << "\n [SUKSES] Menampilkan Semua Daftar Riwayat Energi" << endl;
    jeda();
}

void hapusRiwayatAtas(){
    judul("Hapus Riwayat Enerti Teratas");
    if (top == NULL){
        cout << "\n [!] Belum ada Energi Yang Terserap..." << endl;
        jeda();
        return;
    }
    nodeStack* temp = top;

    cout << "\n [Data Energi Teratas]========== " << endl;
    cout << " [>] Kode Energi : " << temp->nota << endl;
    cout << " [>] Nama Energi : " << temp->nama << endl;
    cout << " --------------------------------" << endl;
    
    top = top->next;
    delete temp;

    cout << "\n [SUKSES] Menghapus Riwayat Energi Teratas" << endl;
    jeda();
};

void cariEnergi(){
    judul("Cari Energi di Organ");
    if (root == NULL){
        cout << "\n [!] Belum ada Energi..." << endl;
        jeda();
        return;
    }
    int nomorKode;
    cout << "\n [>] Masukkan Kode Energi : ";
    cin>>nomorKode;
    cin.ignore();

    if (cin.fail() || nomorKode <= 0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [!] Nomor Kode Harus Lebih Dari 0..." << endl;
        jeda();
        return;
    }

    nodeTree* hasil = cari_tree(root, nomorKode);
    if (hasil == NULL){
        cout << "\n [!] Energi dengan Kode " << nomorKode << "Tidak Ditemukan";
    } else {
        cout << "\n [Data Ditemukan]==========" << endl;
        cout << " [>] Kode   : " << hasil->nota << endl;
        cout << " [>] Energi : " << hasil->nama << endl;
        cout << " ==========================" << endl;
    }
    jeda();
}

void lihatOrgan(){
    if (root == NULL){
        cout << "\n [!] Belum ada Energi..." << endl;
        jeda();
        return;
    } 
    int pilihanMenu;
    int no = 1;
    cout << "\n ==== [Lihat Organ] ====" << endl;
    cout << " | [1] Pre-Order       |" << endl;
    cout << " | [2] In-Order        |" << endl;
    cout << " | [3] Post-Order      |" << endl;
    cout << " =======================" << endl;
    cout << " \n [>] Pilih Menu [1-3] : ";
    if(!(cin>>pilihanMenu)){
        cin.clear();
        cin.ignore(1000, '\n');
        pilihanMenu = -1;
    } else {
        cin.ignore();
    }

    switch (pilihanMenu) {
    case 1:
        cout << "\n [Tampilan Pre-Order]==========" << endl;
        preorder(root, no);
        cout << " ==============================" << endl;
        jeda();
        break;
    case 2:
        cout << "\n [Tampilan In-Order]==========" << endl;
        inorder(root, no);
        cout << " ==============================" << endl;
        jeda();
        break;
    case 3:
        cout << "\n [Tampilan Post-Order]==========" << endl;
        postorder(root, no);
        cout << " ==============================" << endl;
        jeda();
        break;
    case 0:
        break;
    default:
        cout << " \n [!] Input Salah! Silahkan ketik angka 1 sampai 3" << endl;
        jeda();
        break;
    }
}

void gunakanEnergi(){
    if (root == NULL){
        cout << "\n [!] Belum ada Energi..." << endl;
        jeda();
        return;
    } 
    judul("Gunakan Energi");
    int kodeEnergi;
    cout << "\n [>] Masukkan Kode Energi : ";
    cin >> kodeEnergi;
    cin.ignore();

    if(cin.fail() || kodeEnergi <= 0){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [!] Kode Energi Harus lebih dari 0..." << endl;
        jeda();
        return;
    }

    nodeTree* temp = cari_tree(root, kodeEnergi);
    if (temp == NULL){
        cout << "\n [!] Kode Energi " << kodeEnergi << " Tidak Ada..." << endl << endl;
        jeda();
        return;
    }

    cout << "\n [Data Energi Digunakan]==========" << endl;
    cout << " [>] Kode Energi : " << temp->nota << endl;
    cout << " [>] Nama Energi : " << temp->nama << endl;
    cout << "\n [SUKSES] Menggunakan Energi";
    root = hapus_tree(root, kodeEnergi);
    jeda();
}

int main(){
    int pilihan;
    do {
        judulNama();
        cout << "\n ============[Menu Utama]=============" << endl;
        cout << " | [1] Tambah Energi                 |" << endl;
        cout << " | [2] Lihat Antrean Energi          |" << endl;
        cout << " | [3] Proses Energi                 |" << endl;
        cout << " | [4] Lihat Energi yang Terserap    |" << endl;
        cout << " | [5] Hapus Riwayat Energi Teratas  |" << endl;
        cout << " | [6] Cari Energi di Organ          |" << endl;
        cout << " | [7] Lihat Isi Organ               |" << endl;
        cout << " | [8] Gunakan Energi                |" << endl;
        cout << " | [0] Keluar                        |" << endl;
        cout << " |___________________________________|" << endl;
        cout << "\n [>] Pilih Menu [0-8] : ";
        if(!(cin>>pilihan)){
            cin.clear();
            cin.ignore(1000, '\n');
            pilihan = -1;
        } else {
            cin.ignore();
        }

        switch (pilihan){
            case 1:
                char lanjut;
                do {
                    tambahEnergi();
                    cout << "\n Tambah cucian lainnya? [Y/N] : ";
                    cin >> lanjut;
                    cin.ignore();
                } while (lanjut == 'y' || lanjut == 'Y');
                break;
            case 2:
                lihat_antrean();
                break;
            case 3:
                prosesEnergi();
                break;
            case 4:
                lihatRiwayat();
                break;
            case 5:
                hapusRiwayatAtas();
                break;
            case 6:
                cariEnergi();
                break;
            case 7:
                lihatOrgan();
                break;
            case 8:
                gunakanEnergi();
                break;
            case 0:
                judulNama();
                cout << "\n\t [Program Selesai]\n\tSampai Jumpa Kembali!" << endl;
                break;
            default:
                    cout << "\n\t [!] Input Salah - Coba Lagi" << endl;
                    jeda();
                break;
        }
    } while (pilihan != 0);
}

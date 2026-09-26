#include <iostream>
using namespace std;

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t==================================" << endl;
        cout << "\t||   TUGAS 1 - Struktur Data    ||" << endl;
        cout << "\t||   ________________________   ||" << endl;
        cout << "\t||                              ||" << endl;
        cout << "\t||    Nama  : Gega Ramadhan     ||" << endl;
        cout << "\t||    NIM   : 1231250112        ||" << endl;
        cout << "\t||    Kelas : IF-B              ||" << endl;
        cout << "\t||                              ||" << endl;
        cout << "\t==================================\n\n" << endl;
    }

    void judulMenu(string judul){
        judulNama();
        cout << "==========[" << judul <<"]==========" << endl;
    }

    void garis(){
        cout << "--------------------------------------------------" << endl;
    }

    void jeda() {
        cout << "\n\t    Tekan Enter untuk lanjut...";
        cin.get();
    }

// Function Prototype
    void tambahPerserta();
    void tampilkanPersertaUtama();
    void tampilkanPersertaTunggu();
    void cariPeserta();
    void pindahPesertaTunggu();
    void hapusPesertaUtama();
    void hapusPesertaTunggu();
    
// Function Menu Utama
    void menuUtama(){
        int pilihanMenu;
        do{
            judulNama();
            cout << "=================[ Menu Utama ]================" << endl;
            cout << "|                                             |" << endl;
            cout << "| [1] Tambahkan Peserta                       |" << endl;
            cout << "| [2] Tampilkan Peserta Utama                 |" << endl;
            cout << "| [3] Tampilkan Daftar Tunggu                 |" << endl;
            cout << "| [4] Cari Peserta Berdasarkan NIM            |" << endl;
            cout << "| [5] Hapus/Batalkan Peserta Utama            |" << endl;
            cout << "| [6] Pindah Peserta Pertama di Daftar Tunggu |" << endl;
            cout << "| [7] Hapus Peserta Dari Daftar Tunggu        |" << endl;
            cout << "| [8] Keluar                                  |" << endl;
            cout << "|                                             |" << endl;
            cout << "===============================================" << endl;
            cout << "\n > Pilih [1-8] : ";
    
            cin >> pilihanMenu;
            cin.ignore();
            
            switch (pilihanMenu){
                case 1:
                    tambahPerserta();
                    break;
                case 2:
                    tampilkanPersertaUtama();
                    break;
                case 3:
                    tampilkanPersertaTunggu();
                    break;
                case 4:
                    cariPeserta();
                    break;
                case 5:
                    hapusPesertaUtama();
                    break;
                case 6:
                    pindahPesertaTunggu();
                    break;
                case 7:
                    hapusPesertaTunggu();
                    break;
                case 8:
                    judulNama();
                    cout << "\n\t    [Program Selesai] - Terima Kasih" << endl;
                    exit(0);
                    break;
                default:
                    cout << "\n\t    [ERROR] - Input Tidak Valid" << endl;
                    jeda();
                    break;
            }
        } while (pilihanMenu != 8);
    }

// Global Variable
    struct Mahasiswa {
        string nama;
        string nim;
        string prodi;
        int semester;
        double ipk;
    };

    struct Node {
        Mahasiswa mhs;
        Node *next;
    };

    // Variabel Global Linkedlist
    Node *head  = nullptr;
    Node *tail  = nullptr;
    Node *temp  = nullptr;
    Node *hapus = nullptr;
    
    // Variabel Global Peserta Tunggu
    int jumlahPesertaTunggu = 0;
    
    // Variabel Global Peserta Utama
    int headArray;
    int tailArray;
    int jumlahPesertaUtama = 0;
    const int MAX_UTAMA = 5;
    Mahasiswa pesertaUtama[MAX_UTAMA];
    

// Function Helper Logic
    bool listKosong(){
        if (head == nullptr && tail == nullptr){
            return true;
        } else {
            return false;
        }
    }

    void cetakData(Mahasiswa dataMhs, string tipe, int nomor){

        cout << "\n [Data Peserta " << tipe << " Ke-" << nomor << "]---------------------" << endl;
        cout << " [1] Nama     : " << dataMhs.nama     << endl;
        cout << " [2] NIM      : " << dataMhs.nim      << endl;
        cout << " [3] Prodi    : " << dataMhs.prodi    << endl;
        cout << " [4] Semester : " << dataMhs.semester << endl;
        cout << " [5] IPK      : " << dataMhs.ipk      << endl;
    }

// Function2 Menu
    void tambahPerserta(){
        char keluar;
        Mahasiswa mhsBaru;
        do{
            judulMenu("Tambah Peserta");
            cout << "\n [Daftar Peserta ke-"<< jumlahPesertaUtama + 1 <<"]==============" << endl;
            cout << " [1] Nama     : " ;
            getline(cin, mhsBaru.nama);
        
            cout << " [2] NIM      : " ;
            cin >> mhsBaru.nim;
            cin.ignore();

            cout << " [3] Prodi    : " ;
            getline(cin, mhsBaru.prodi);

            cout << " [4] Semester : " ;
            cin >> mhsBaru.semester;
            cin.ignore();

            cout << " [5] IPK      : " ;
            cin >> mhsBaru.ipk;
            cin.ignore();

            if (jumlahPesertaUtama < MAX_UTAMA){
                pesertaUtama[jumlahPesertaUtama] = mhsBaru;
                jumlahPesertaUtama++;
                cout << "\n------------------------------------" << endl;
                cout << "\n [SUKSES] Masuk Data Peserta Utama";
            } else {

                Node *newNode = new Node();
                newNode->mhs = mhsBaru;
                newNode->next = nullptr;

                if (listKosong()){
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }

                jumlahPesertaTunggu++;
                cout << "\n------------------------------------" << endl;
                cout << "\n\t SUKSES - DIALIHKAN] Slot Peserta Utama Penuh"; 
                cout << "\n\t Catatan - Data Akan Masuk Ke Ruang Tunggu" << endl;
            }
            cout << "\n Tambah Data Lainnya? [Y/N] : ";
            cin >> keluar;
            cin.ignore();            
        } while (keluar == 'y' || keluar == 'Y');
    }

    void tampilkanPersertaUtama(){
        judulMenu("Tampilkan Peserta Utama");
        if (jumlahPesertaUtama == 0){
            cout << "\n\t    [KESALAHAN] Data Masih Kosong - Isi Dulu" << endl;
            jeda();
            return;
        }
        
        for (int i = 0; i < jumlahPesertaUtama; i++){
            cetakData(pesertaUtama[i], "Utama" , i + 1);
        }
        
        cout << "\n --------------------------------------------" << endl;
        cout << "\n\t   [Semua Data Telah Ditampilkan]" << endl;
        jeda();
    }

    void tampilkanPersertaTunggu(){
        judulMenu("Tampilkan Daftar Tunggu");
        if (jumlahPesertaTunggu == 0){
            cout << "\n\t    [KESALAHAN] Data Masih Kosong - Isi Dulu" << endl;
            jeda();
            return;
        }
        
        int counter = 0;
        temp = head;
        while (temp != nullptr){
            cetakData(temp->mhs, "Tunggu", counter + 1);

            temp = temp->next;
            counter++;
        }

        cout << "\n -------------------------------------------" << endl;
        cout << "\n\t   [Semua Data Telah Ditampilkan]" << endl;
        jeda();
    }

    void cariPeserta(){
        char keluar;
        string target;

        do {
            judulMenu("Cari Peserta Berdasarkan NIM");
            if (jumlahPesertaUtama == 0 && jumlahPesertaTunggu == 0){
                cout << "\n\t    [KESALAHAN] Data Masih Kosong - Isi Dulu" << endl;
                jeda();
                return;
            }
            // Input Target
            cout << " [>] Masukkan NIM  : ";
            cin >> target;
            cin.ignore();

            bool ketemu = false;

            //  Search Array
            for (int i = 0; i < jumlahPesertaUtama; i++){
                if (target == pesertaUtama[i].nim){
                    cout << "\n\t [DATA DITEMUKAN - UTAMA]" << endl;
                    cetakData(pesertaUtama[i], "Utama" , i + 1);
                    ketemu = true;
                    break;
                }
            }
            
            // Search Linked List
            if (!ketemu){
                int counter = 0;
                temp = head;
                while(temp != nullptr){
                    if (target == temp->mhs.nim){
                        cout << "\n\t [DATA DITEMUKAN - RUANG TUNGGU]" << endl;
                        cetakData(temp->mhs, "Tunggu", counter + 1);
                        ketemu = true;
                        break;
                    }
                    temp = temp->next;
                    counter++;
                }
            }

            if (!ketemu) {
                cout << "\n\t [DATA TIDAK DITEMUKAN]" << endl;
            }

            cout << "\n Cari Data Lainnya? [Y/N] : ";
            cin >> keluar;
            cin.ignore();
        } while (keluar == 'y' || keluar == 'Y');
    }

    void hapusPesertaUtama(){
        char keluar;
        string target;
        do {
            judulMenu("Hapus/Batalkan Peserta Utama");
            if (jumlahPesertaUtama == 0){
                cout << "\n\t    [KESALAHAN] Data Masih Kosong - Isi Dulu" << endl;
                jeda();
                return;
            }

            // Input Target
            cout << " [>] Masukkan NIM  : ";
            cin >> target;
            cin.ignore();

            bool ketemu = false;
            for (int i = 0; i < jumlahPesertaUtama; i++){
                if (target == pesertaUtama[i].nim){
                    ketemu = true;
                    cout << "\n\t [DATA DITEMUKAN - UTAMA]" << endl;
                    cetakData(pesertaUtama[i], "Utama" , i + 1);
                    
                    for (int j = i; j < jumlahPesertaUtama - 1; j++){
                        pesertaUtama[j] = pesertaUtama[j+1];
                    }
                    
                    jumlahPesertaUtama--;
                    cout << "\n\t [SUKSES] Menghapus Data" << endl;
                    break;
                }
            }

            if (!ketemu) {
                cout << "\n\t [DATA TIDAK DITEMUKAN]" << endl;
            }

            cout << "\n Hapus Data Lainnya? [Y/N] : ";
            cin >> keluar;
            cin.ignore();
        } while (keluar == 'y' || keluar == 'Y');
    }

    void pindahPesertaTunggu(){
        judulMenu("Pindah Peserta Pertama di Daftar Tunggu");
        if (jumlahPesertaTunggu == 0 || jumlahPesertaUtama == 5){
            cout << "\n\t    [KESALAHAN] Data Masih Kosong atau Slot Peserta Utama Penuh" << endl;
            jeda();
            return;
        } 

        cout << "\n [>] Preview Data" << endl;
        cetakData(head->mhs, "Tunggu", 1);

        pesertaUtama[jumlahPesertaUtama] = head->mhs;
        jumlahPesertaUtama++;

        temp = head;
        head = head->next;

        if (head == nullptr){
            tail = nullptr;
        }
        delete temp;
        jumlahPesertaTunggu--;

        cout << "\n\t [SUKSES] Memindah Data Ke Daftar Utama" << endl;
        
        jeda();
    }

    void hapusPesertaTunggu(){
        
        char keluar;
        string target;
        do {
            judulMenu("Hapus Peserta Dari Daftar Tunggu");
            if (jumlahPesertaTunggu == 0){
                cout << "\n\t    [KESALAHAN] Data Masih Kosong - Isi Dulu" << endl;
                jeda();
                return;
            } 

            // Input Target
            cout << " [>] Masukkan NIM  : ";
            cin >> target;
            cin.ignore();

            bool ketemu = false;

            if (head != nullptr && head->mhs.nim == target){
                ketemu = true;
                cout << "\n\t [DATA DITEMUKAN - TUNGGU]" << endl;
                cetakData(head->mhs, "Tunggu" , 1);
                
                hapus = head;
                head = head->next;
                
                if (head == nullptr){
                    tail = nullptr;
                }
                
                delete hapus;
                jumlahPesertaTunggu--;
                cout << "\n\t [SUKSES] Menghapus Data" << endl;

            } else {

                int counter = 1;
                temp = head;
                while (temp != nullptr && temp->next != nullptr){
                    if (target == temp->next->mhs.nim){
                        ketemu = true;
                        cout << "\n\t [DATA DITEMUKAN - TUNGGU]" << endl;
                        cetakData(temp->next->mhs, "Tunggu" , counter+1);
                        
                        hapus = temp->next;
                        temp->next = hapus->next;

                        if (hapus == tail){
                            tail = temp;
                        }

                        delete hapus;
                        jumlahPesertaTunggu--;
                        cout << "\n\t [SUKSES] Menghapus Data" << endl;
                        break;
                    }
                    temp = temp->next;
                    counter++;
                }
            }

            if (!ketemu){
                cout << "\n\t [DATA TIDAK DITEMUKAN]" << endl;
            }
            
            cout << "\n Hapus Data Lainnya? [Y/N] : ";
            cin >> keluar;
            cin.ignore();
        } while (keluar == 'y' || keluar == 'Y');


        jeda();
    }


// Main Function
    int main(){
        menuUtama();
        return 0;
    }
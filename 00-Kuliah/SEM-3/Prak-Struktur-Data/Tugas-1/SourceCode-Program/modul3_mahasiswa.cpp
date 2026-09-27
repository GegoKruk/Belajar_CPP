#include <iostream> 
#include <string> 
using namespace std; 

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t============================================" << endl;
        cout << "\t||   MODUL 3 - Praktikum Struktur Data    ||" << endl;
        cout << "\t||   __________________________________   ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t||          Nama  : Gega Ramadhan         ||" << endl;
        cout << "\t||          NIM   : 1231250112            ||" << endl;
        cout << "\t||          Kelas : IF-D                  ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t============================================\n\n" << endl;
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

// Global Variable   &eklarasi 
    struct Mahasiswa { 
        string nim; 
        string nama; 
        double ipk; 
    }; 
    
    struct Node { 
        Mahasiswa data; 
        Node *next; 
    }; 

// Function Prototype
    // Function Logic
    bool nimTersedia(const Node *head, const string &nim); 
    bool tambahAkhir(Node *&head, const Mahasiswa &data); 
    Node *cariNim(Node *head, const string &nim); 
    bool hapusNim(Node *&head, const string &nim); 
    void tampilkanSemua(const Node *head); 
    int jumlahData(const Node *head); 
    void clear(Node *&head); 

    // Function Display
    void menu1(Node *&head);
    void menu2(Node *&head);
    void menu3(Node *&head);
    void menu4(Node *&head);
    void menu5(Node *&head);

// Main Function
    int main() {
        Node *head = nullptr;
        int pilihanMenu; 
        do {
            judulNama();
            cout << "=================[ Menu Utama ]================" << endl;
            cout << "|                                             |" << endl;
            cout << "| [1] Tambah Data Mahasiswa                   |" << endl;
            cout << "| [2] Tampilkan Data Mahasiswa                |" << endl;
            cout << "| [3] Cari Data NIM Mahasiswa                 |" << endl;
            cout << "| [4] Hapus Data Mahasiswa                    |" << endl;
            cout << "| [5] Jumlah Mahasiswa                        |" << endl;
            cout << "| [6] Keluar                                  |" << endl;
            cout << "|                                             |" << endl;
            cout << "===============================================" << endl;
            cout << "\n > Pilih [1-6] : ";
            cin >> pilihanMenu; 
            cin.ignore();
                
                switch (pilihanMenu){
                    case 1:
                        menu1(head);
                        break;
                    case 2:
                        menu2(head);
                        break;
                    case 3:
                        menu3(head);
                        break;
                    case 4:
                        menu4(head);
                        break;
                    case 5:
                        menu5(head);
                        break;
                    case 6:
                        judulNama();
                        cout << "\n\t    [Program Selesai] - Terima Kasih" << endl;
                        exit(0);
                        break;
                    default:
                        cout << "\n\t    [ERROR] - Input Tidak Valid" << endl;
                        jeda();
                        break;
                }
        } while (pilihanMenu != 6); 
        clear(head); 
        return 0; 
    }

// Function Helper Logic
    bool listKosong(Node *&head){
        if (head == nullptr){
            return true;
        }
        return false;
    }

    bool nimTersedia(const Node *head, const string &nim) { 
        while (head != nullptr){
            if (nim == head->data.nim){
                return true;
            }
            head = head->next;
        }
        return false; 
    } 
    
    bool tambahAkhir(Node *&head, const Mahasiswa &data) { 
        bool tersedia = nimTersedia(head, data.nim);
        if (tersedia == true){
            return false; 
        }

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (listKosong(head)){
            head = newNode;
            return true;
        } 
        
        Node *temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
        return true;
    } 
    
    void tampilkanSemua(const Node *head) {
        int counter = 0;
        const Node *temp = head;
        while (temp != nullptr){
            cout << "\n [Data Mahasiswa Ke-" << counter+1 << "]--------------" << endl;
            cout << " [1] Nama : " << temp->data.nama << endl;
            cout << " [2] NIM  : " << temp->data.nim << endl;
            cout << " [3] IPK  : " << temp->data.ipk << endl;
            temp = temp->next;
            counter++;
        }
        cout << "\n -----------------------------------" << endl;
    }; 

    void tampilkanSatuan(const Node *node) {
        cout << "\n [Data Mahasiswa]------------------" << endl;
        cout << " [1] Nama : " << node->data.nama << endl;
        cout << " [2] NIM  : " << node->data.nim << endl;
        cout << " [3] IPK  : " << node->data.ipk << endl;
        cout << "\n -----------------------------------" << endl;
    }; 

    Node *cariNim(Node *head, const string &nim) { 
        Node *temp = head;
        while (temp != nullptr){
            if (temp->data.nim == nim){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; 
    } 
    
    bool hapusNim(Node *&head, const string &nim) {
        if (head == nullptr){
            return false;
        }

        Node *temp    = head;
        Node *sebelum = nullptr;
        
        while (temp != nullptr && temp->data.nim != nim){
            sebelum = temp;
            temp = temp->next;
        }

        if (temp == nullptr){
            return false;
        }

        if (sebelum == nullptr){
            head = temp->next;
        } else {
            sebelum->next = temp->next;
        }

        delete temp;
        return true; 
    } 

    int jumlahData(const Node *head) {
        int counter = 0;
        const Node *temp = head;
        while (temp != nullptr){
            temp = temp->next;
            counter++;
        }
        return counter;
    };

    void clear(Node *&head) { 
        while (head != nullptr) { 
            Node* hapus = head; 
            head = head->next; 
            delete hapus; 
        } 
    } 

// Function Display
    void menu1(Node *&head){
        char ulang;
        Mahasiswa tempMhsBaru;
        do{
            judulMenu("Tambahkan Data Mahasiswa");

            cout << "\n [Input Data Mahasiswa]------------------------" << endl;
            cout << " [1] Masukkan Nama : ";
            getline(cin, tempMhsBaru.nama);
            cout << " [2] Masukkan NIM  : ";
            cin >> tempMhsBaru.nim;
            cin.ignore();
            cout << " [3] Masukkan IPK  : ";
            cin >> tempMhsBaru.ipk;
            cin.ignore();
            cout << " ---------------------------------------------" << endl;
            
            bool status = tambahAkhir(head, tempMhsBaru);

            if (status == true) {
                cout << "\n\t [SUKSES] Data berhasil ditambahkan" << endl;
            } else {
                cout << "\n\t [GAGAL] Data penuh atau NIM sudah terdaftar" << endl;
            }
            
            cout << "\n Tambah Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }
    
    void menu2(Node *&head){
        judulMenu("Tampilkan Data Mahasiswa");
        if (listKosong(head)){
            cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
            jeda();
            return;
        }
        tampilkanSemua(head);
        jeda();
    }
    
    void menu3(Node *&head){
        char ulang;
        do{
            judulMenu("Cari Data Mahasiswa");
            if (listKosong(head)){
                cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
                jeda();
                return;
            }
            string target;
            cout << "\n [>] Masukkan Data NIM : ";
            cin >> target;
            cin.ignore();
            Node *alamat = cariNim(head,target);
            if (alamat){
                cout << "\n\t [SUKSES] Data Ditemukan" << endl;
                tampilkanSatuan(alamat);
            } else {
                cout << "\n\t [GAGAL] Data Tidak Ditemukan" << endl;
            }
            cout << "\n Cari Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore(); 
        } while (ulang == 'y' || ulang == 'Y');
    }
    
    void menu4(Node *&head){
        char ulang;
        do{
            judulMenu("Hapus Data Mahasiswa");
            if (listKosong(head)){
                cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
                jeda();
                return;
            }
            string target;
            cout << "\n [>] Masukkan Data NIM : ";
            cin >> target;
            cin.ignore();
            bool status = hapusNim(head, target);
            if (status == true) {
                cout << "\n\t [SUKSES] Data Berhasil Dihapus" << endl;
            } else {
                cout << "\n\t [GAGAL] Data Tidak Ditemukan" << endl;
            }
            cout << "\n Hapus Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore(); 
        } while (ulang == 'y' || ulang == 'Y');
    }
    
    void menu5(Node *&head){
        judulMenu("Jumlah Mahasiswa");
        if (listKosong(head)){
            cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
            jeda();
            return;
        }
        cout << "\n [>] Jumlah Data Tercatat Saat Ini : " << jumlahData(head) << " Mahasiswa"<< endl;
        jeda();
    }

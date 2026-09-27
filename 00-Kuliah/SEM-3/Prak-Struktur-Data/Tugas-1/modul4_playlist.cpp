#include <iostream> 
#include <string> 
using namespace std; 

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t============================================" << endl;
        cout << "\t||   MODUL 4 - Praktikum Struktur Data    ||" << endl;
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

// Global Variable  &Deklarasi 
    struct Lagu { 
        string judul; 
        string penyanyi; 
    }; 

    struct Node { 
        Lagu data; 
        Node *prev; 
        Node *next;
    };
    
// Function Prototype
    // Function Logic
    bool judulTersedia(const Node *head, const string &judul); 
    bool tambahAkhir(Node *&head, Node *&tail, const Lagu &data); 
    void tampilMaju(const Node *head); 
    void tampilMundur(const Node *head, const Node *tail); 
    Node *cariJudul(Node *head, const string &judul); 
    bool hapusJudul(Node *&head, Node *&tail, const string &judul); 
    int jumlahData(const Node *head); 
    void clear(Node *&head, Node *&tail); 

    // Function Display
    void menu1(Node *&head, Node *&tail);
    void menu2(Node *&head);
    void menu3(Node *&head, Node *&tail);
    void menu4(Node *&head);
    void menu5(Node *&head, Node *&tail);
    void menu6(Node *&head);

// Main Function
    int main() { 
        Node* head = nullptr; 
        Node* tail = nullptr; 
        int pilihanMenu; 
        do {
            judulNama();
            cout << "=========[ Menu Utama ]=========" << endl;
            cout << "|                              |" << endl;
            cout << "| [1] Tambah Lagu              |" << endl;
            cout << "| [2] Tampilkan Maju           |" << endl;
            cout << "| [3] Tampilkan Mundur         |" << endl;
            cout << "| [4] Cari Lagu                |" << endl;
            cout << "| [5] Hapus Lagu               |" << endl;
            cout << "| [6] Jumlah Lagu              |" << endl;
            cout << "| [7] Keluar                   |" << endl;
            cout << "|                              |" << endl;
            cout << "================================" << endl;
            cout << "\n > Pilih [1-7] : ";
            cin >> pilihanMenu; 
            cin.ignore();
                
                switch (pilihanMenu){
                    case 1:
                        menu1(head, tail);
                        break;
                    case 2:
                        menu2(head);
                        break;
                    case 3:
                        menu3(head, tail);
                        break;
                    case 4:
                        menu4(head);
                        break;
                    case 5:
                        menu5(head, tail);
                        break;
                    case 6:
                        menu6(head);
                        break;
                    case 7:
                        judulNama();
                        cout << "\n\t    [Program Selesai] - Terima Kasih" << endl;
                        exit(0);
                        break;
                    default:
                        cout << "\n\t    [ERROR] - Input Tidak Valid" << endl;
                        jeda();
                        break;
                }
        } while (pilihanMenu != 7); 
        clear(head, tail); 
        return 0; 
    }

// Function Helper Logic
    bool listKosong(Node *&head, Node *&tail){
        if (head == nullptr && tail == nullptr){
            return true;
        }
        return false;
    }

    bool judulTersedia(const Node *head, const string &judul){
        const Node *temp = head; 
        while (temp != nullptr){
            if (judul == temp->data.judul){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool tambahAkhir(Node *&head, Node *&tail, const Lagu &data){
        bool tersedia = judulTersedia(head, data.judul);
        if (tersedia == true){
            return false; 
        }

        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (listKosong(head,tail)){
            head = newNode;
            tail = newNode;
            return true;
        } 

        Node *temp = tail;
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        return true;
    }

    Node *cariJudul(Node *head, const string &judul){
        Node *temp = head;
        while (temp != nullptr){
            if (temp->data.judul == judul){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; 
    }

    bool hapusJudul(Node *&head, Node *&tail, const string &judul){

        Node* target = cariJudul(head, judul);
        if (target == nullptr) {
            return false;
        }

        if (target == head && target == tail){
            head = nullptr;
            tail = nullptr;
        } else if (target == head){
            head = target->next;
            head->prev = nullptr;
        } else if (target == tail){
            tail = target->prev;
            tail->next = nullptr;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }

        delete target;
        return true;
    }

    void tampilMaju(const Node *head){
        int counter = 0;
        const Node *temp = head;
        while (temp != nullptr){
            cout << "\n [Data Lagu Ke-" << counter+1 << "]-------------------" << endl;
            cout << " [1] Judul    : " << temp->data.judul << endl;
            cout << " [2] Penyanyi : " << temp->data.penyanyi << endl;
            temp = temp->next;
            counter++;
        }
        cout << "\n -----------------------------------" << endl;
    }
    
    void tampilMundur(const Node *head, const Node *tail){
        int counter = jumlahData(head);
        const Node *temp = tail;
        while (temp != nullptr){
            cout << "\n [Data Lagu Ke-" << counter << "]-------------------" << endl;
            cout << " [1] Judul    : " << temp->data.judul << endl;
            cout << " [2] Penyanyi : " << temp->data.penyanyi << endl;
            temp = temp->prev;
            counter--;
        }
        cout << "\n -----------------------------------" << endl;
    }
    
    void tampilSatuan(const Node *node){
        cout << "\n [Data Lagu]--------------" << endl;
        cout << " [1] Judul     : " << node->data.judul << endl;
        cout << " [2] Penyanyi  : " << node->data.penyanyi << endl;
        cout << "\n -----------------------------------" << endl;
    }

    int jumlahData(const Node *head){
        int counter = 0;
        if (head ==  nullptr){
            return 0;
        }
        const Node *temp = head;
        while (temp != nullptr){
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    void clear(Node *&head, Node *&tail){
        while (head != nullptr) { 
            Node* hapus = head; 
            head = head->next; 
            delete hapus; 
        } 
        tail = nullptr;
    }


// Function Display
    void menu1(Node *&head, Node *&tail){
        char ulang;
        Lagu tempLagu;
        do{
            judulMenu("Tambah Lagu");

            cout << "\n [Input Data Lagu]---------------" << endl;
            cout << " [1] Masukkan Judul     : ";
            getline(cin, tempLagu.judul);
            cout << " [2] Masukkan Penyanyi  : ";
            getline(cin, tempLagu.penyanyi);
            cout << " --------------------------------" << endl;
            
            bool status = tambahAkhir(head, tail, tempLagu);

            if (status == true) {
                cout << "\n\t [SUKSES] Data berhasil ditambahkan" << endl;
            } else {
                cout << "\n\t [GAGAL] Data penuh atau Judul sudah terdaftar" << endl;
            }
            
            cout << "\n Tambah Lagu Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu2(Node *&head){
        judulMenu("Tampilkan Maju");
        if (jumlahData(head) == 0){
            cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
            jeda();
            return;
        }
        tampilMaju(head);
        jeda();
    }

    void menu3(Node *&head, Node *&tail){
        judulMenu("Tampilkan Mundur");
        if (jumlahData(head) == 0){
            cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
            jeda();
            return;
        }
        tampilMundur(head,tail);
        jeda();
    }

    void menu4(Node *&head){
        char ulang;
        do{
            judulMenu("Cari Lagu");
            if (jumlahData(head) == 0){
                cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
                jeda();
                return;
            }  

            cout << "\n [>] Masukkan Judul : ";
            string target;
            getline(cin, target);

            Node *alamat = cariJudul(head, target);
            if (alamat){
                cout << "\n\t [SUKSES] Data Ditemukan" << endl;
                tampilSatuan(alamat);
            } else {
                cout << "\n\t [GAGAL] Data Tidak Ditemukan" << endl;
            }

            cout << "\n Cari Lagu Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu5(Node *&head, Node *&tail){
        char ulang;
        do{
            judulMenu("Hapus Lagu");
            if (jumlahData(head) == 0){
                cout << "\n\t [KESALAHAN] Data Masih Kosong" << endl;
                jeda();
                return;
            }

            cout << "\n [>] Masukkan Judul : ";
            string target;
            getline(cin, target);

            bool status = hapusJudul(head, tail, target);
            if (status){
                cout << "\n\t [SUKSES] Data Berhasil Dihapus" << endl;
            } else {
                cout << "\n\t [GAGAL] Data Tidak Ditemukan" << endl;
            }

            cout << "\n Hapus Lagu Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu6(Node *&head){
        judulMenu("Jumlah Lagu");
        int jumlah = jumlahData(head);
        cout << "\n [>] Jumlah Lagu Saat ini : " << jumlah << endl;
        jeda();
    }

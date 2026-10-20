#include <iostream>
#include <string>
using namespace std;

// Helper Visual Function
void judulNama(){
    system("color 0B");
    system("cls");
    cout << "\n ==========[PRAKTIKUM P6]==========" << endl;
    cout << " |          LINEAR QUEUE          |" << endl;
    cout << " |  ____________________________  |" << endl;
    cout << " |                                |" << endl;
    cout << " |      Nama : Gega Ramadhan      |" << endl;
    cout << " |      NIM  : 123250112          |" << endl;
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

// Global Structure
struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;
};

Node *createNode(int nilai){
    Node *baru = new Node();
    baru->data = nilai;
    baru->next = nullptr;
    return baru;
}

bool isEmpty(Queue &q){
    if (q.front == nullptr) {
        return true;
    }
    return false;
}

// Queue
void enqueue(Queue &q, int nilai){
    Node *baru = createNode(nilai);

    if (isEmpty(q)) {
        q.front = baru;
        q.rear = baru;
    } else {
        q.rear->next = baru;
        q.rear = baru;  
    }

    cout << "\n [*] SUKSES: Menambah Data [" << nilai << "] ke dalam Antrean." << endl;
}

void dequeue(Queue &q){
    if (isEmpty(q)) {
        cout << " [!] Antrean Kosong - Tidak Ada Data" << endl;
        return;
    }

    Node *hapus = q.front;
    int nilaiKeluar = q.front->data;

    q.front = q.front->next;

    if (q.front == nullptr) {
        q.rear = nullptr;
    }

    delete hapus;

    cout << "\n [*] SUKSES: Menghapus Data [" << nilaiKeluar << "] dari Antrean." << endl;
}

void printQueue(Queue &q){
    if (isEmpty(q)) {
        cout << " [!] Antrean Kosong!" << endl;
        return;
    }

    cout << " [>] Isi Antrean (Front -> Rear) : ";
    Node *bantu = q.front;
    while (bantu != nullptr) {
        cout << bantu->data;
        if (bantu->next != nullptr) {
            cout << " -> ";
        }
        bantu = bantu->next;
    }
    cout << endl;
}

void clear(Queue &q){
    Node *bantu = q.front;
    while (bantu != nullptr) {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    q.front = nullptr;
    q.rear = nullptr;
}

// Menu Functions
void menu1(Queue &q){
    judulSection("Tambah Data (Enqueue)");
    cout << " [?] Masukkan nilai yang ingin ditambahkan : ";
    int nilai;
    
    if (!(cin >> nilai)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n [!] Input tidak valid!" << endl;
        jeda();
        return;
    }
    cin.ignore();
    
    enqueue(q, nilai);
    jeda();
}

void menu2(Queue &q){
    judulSection("Hapus Data (Dequeue)");
    if (isEmpty(q)) {
        cout << " [!] Antrean kosong!" << endl;
        jeda();
        return;
    }

    dequeue(q);
    jeda();
}

void menu3(Queue &q){
    judulSection("Lihat Antrean Paling Depan");
    if (isEmpty(q)) {
        cout << " [!] Antrean kosong!" << endl;
        jeda();
        return;
    }

    cout << " [>] Nilai antrean paling depan : " << q.front->data << endl;
    jeda();
}

void menu4(Queue &q){
    judulSection("Tampilkan Semua Antrean");
    if (isEmpty(q)) {
        cout << " [!] Antrean kosong!" << endl;
        jeda();
        return;
    }

    printQueue(q);
    jeda();
}

void menu5(Queue &q){
    judulSection("Hapus Semua Antrean");
    if (isEmpty(q)) {
        cout << " [!] Antrean sudah kosong!" << endl;
        jeda();
        return;
    }

    clear(q);
    cout << " [*] SUKSES: Semua elemen antrean berhasil dihapus!" << endl;
    jeda();
}

int main(){
    int pilihanMenu;
    Queue q;
    q.front = nullptr;
    q.rear = nullptr;

    do {
        judulNama();
        cout << "\n =========== [MENU UTAMA] ==========" << endl;
        cout << " |  [1] Tambah Data                |" << endl;
        cout << " |  [2] Hapus Data                 |" << endl;
        cout << " |  [3] Lihat Paling Depan         |" << endl;
        cout << " |  [4] Tampilkan Semua            |" << endl;
        cout << " |  [5] Hapus Semua                |" << endl;
        cout << " |  [6] Keluar Program             |" << endl;
        cout << " ===================================" << endl;
        cout << "\n [>] Pilih menu [1-6] : ";
        
        if (!(cin >> pilihanMenu)) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihanMenu = 0; 
        } else {
            cin.ignore();
        }

        switch (pilihanMenu){
            case 1: menu1(q); break;
            case 2: menu2(q); break;
            case 3: menu3(q); break;
            case 4: menu4(q); break;
            case 5: menu5(q); break;
            case 6:
                judulNama();
                cout << "\n\t[ Program Selesai ]\n\tSampai jumpa kembali!" << endl;
                break;
            default:
                cout << "\n [!] Input salah! Silakan ketik angka antara 1 sampai 6" << endl;
                jeda();
                break;
        }
    } while (pilihanMenu != 6);
    
    clear(q);
    return 0;
}
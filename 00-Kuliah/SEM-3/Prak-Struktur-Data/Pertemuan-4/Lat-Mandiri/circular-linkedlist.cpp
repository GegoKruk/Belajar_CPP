#include <iostream>
using namespace std;

void judul(){
    system("cls");
    cout << "==============================" << endl;
    cout << "|         PERTEMUAN 4        |" << endl;
    cout << "|    Circular Linked List    |" << endl;
    cout << "==============================\n" << endl;
}

void judulSection(string judulSection){
    judul();
    cout << "==========[" << judulSection << "]==========" << endl;
}

struct Node {
    int info;
    Node *next;
};

Node *newNode = nullptr;
Node *head    = nullptr;
Node *tail    = nullptr;
Node *temp    = nullptr;
Node *hapus    = nullptr;

bool listKosong(){
    if (head == nullptr && tail == nullptr){
        return true;
    } else {
        return false;
    }
}

void sisipNode(int info_baru){
    newNode = new Node();

    newNode->info = info_baru;
    newNode->next = nullptr;

    if (listKosong()){
        head = tail = newNode;              //mengubah head sekaligus tail jadi newNode
        newNode->next = head;               //menunjuk dirinya sendiri
    } else if (info_baru < head->info){     //ini apabila info_baru lebih kecil dari head
        newNode->next = head;
        head = newNode;                     //head pindah ke node baru
        tail->next = head;                  //tail menunjuk ke node baru
    } else if (info_baru >= tail->info){    //apabila info_baru lebih besar atau sama dengan tail, dia harus jadi tail baru
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    } else {                                //apabila info_baru ada di tengah-tengah
        temp = head;

        while (temp->next != head && temp->next->info <= info_baru){
            temp = temp->next;              // cari posisi yang pas
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void hapusNode(int info_hapus){
    if (listKosong()){
        cout << "     [ERROR] - List Masih Kosong" << endl;
        return;
    }

    temp = tail;
    hapus = head;

    do {
        //apabila node yang dicari ketemu
        if (hapus->info == info_hapus){
            if (head == tail){
                head = tail = nullptr;
            }else {                         //ada beberapa node
                temp->next = hapus->next;
                if (hapus == head) {        //apabila yang dihapus head
                    head = head->next;
                }
                if (head == tail){
                    head = temp;
                }
            }
            delete hapus; 
            cout << "     [SUKSES] Node " << info_hapus << " dihapus";
            return;
        }

        temp = hapus;
        hapus = hapus->next;

    } while (hapus != head);
}

void printLinkedList(){
    judulSection("Cetak Linked List");

    if (listKosong()){
        cout << "     [ERROR] - List Masih Kosong" << endl;
        return;
    }

    temp = head;
    while (temp != nullptr){

        if (temp->next != nullptr){
            cout << temp->info << " , ";
        } else {
            cout << temp->info;
        }
        temp = temp->next;
    }
    cout << endl;
}


int main (){
    sisipNode(23);
    sisipNode(1);
    sisipNode(88);
    sisipNode(53);
    sisipNode(99);
    
    cout << "\n=====[ List Awal ]=====" << endl;
    printLinkedList();
    cout << endl;
    hapusNode(99);
    cout << endl;
    cout << "\n=====[ List Akhi r]=====" << endl;
    printLinkedList();
    cout << endl;
}
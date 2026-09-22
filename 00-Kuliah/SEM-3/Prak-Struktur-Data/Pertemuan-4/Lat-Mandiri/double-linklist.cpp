#include <iostream>
using namespace std;

void judul(){
    system("cls");
    cout << "==============================" << endl;
    cout << "|         PERTEMUAN 4        |" << endl;
    cout << "|     Double Linked List     |" << endl;
    cout << "==============================\n" << endl;
}

void judulSection(string judulSection){
    judul();
    cout << "==========[" << judulSection << "]==========" << endl;
}

// Blueprint Node
struct Node {
    int info;
    Node *prev;
    Node *next;
};

// Prepare 
Node *head    = nullptr;
Node *tail    = nullptr;
Node *newNode = nullptr;
Node *temp    = nullptr;
Node *hapus    = nullptr;

// List kosong
bool listKosong(){
    if (head == nullptr && tail == nullptr){
        return true;
    } else {
        return false;
    }
}

void cetakLinkedList(){
    judulSection("Cetak Linked List");

    if (listKosong()){
        cout << "     [ERROR] - List Masih Kosong" << endl;
    } else {
        temp = head;
        while (temp != nullptr){
            
            if (temp->next != nullptr){
                cout << temp->info << ", ";
            } else {
                cout << temp->info;
            }

            temp = temp->next;
        }
    }
}

void sisipNode(int IB) {
    newNode = new Node();

    newNode->info = IB;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (listKosong()){
        head = newNode;
        tail = newNode;
    } else if (IB < head->info) { //Jika data baru lebih kecil daripada data head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (IB >= tail->info) { //Jika data baru lebih besar daripada data tail
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {                       //Jika data baru ditengah-tengah
        temp = head;

        while (temp->next != nullptr && temp->next->info < IB){
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void hapusNode(int IH){

    // Jika list masih kosong
    if (listKosong()){
        cout << "    [ERROR] List Masih Kosong" << endl;
        return;
    } 

    // Jika Data Target ada di HEAD (paling depan)
    if (IH == head->info){
        temp = head;
        
        if (head == tail){ // Jika hanya ada 1 node
            head = nullptr;
            tail = nullptr;
        } else { // Jika node lebih dari 1
            head = head->next;
            head->prev = nullptr;
        }
        
        delete(temp);
        cout << "    [SUKSES] Node " << IH << " dihapus" << endl;
        return;
    }
    
    // Cari data di setelah head (tengah atau belakang)
    temp = head->next;
    while (temp != nullptr && temp->info != IH){ 
        temp = temp->next;
    }

    // Jika node ditemukan
    if (temp != nullptr){
        // Jika node yang dihapus berada di tengah
        if (temp->prev != nullptr){
            temp->prev->next = temp->next;
        }
        
        // PERBAIKAN: Ubah pointer 'prev' milik node setelahnya
        if (temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        
        // Jika node yang dihapus ternyata adalah TAIL (paling belakang)
        if (temp == tail){
            tail = temp->prev;
            tail->next = nullptr;
        }

        delete(temp);
        cout << "    [SUKSES] Node " << IH << " Dihapus" << endl;
    } else {
        cout << "    [ERROR] Node " << IH << " Tidak Ditemukan" << endl;
    }
}

int main(){

    sisipNode(1);
    sisipNode(100);
    sisipNode(50);
    sisipNode(67);
    sisipNode(20);
    sisipNode(70);
    sisipNode(90);

    hapusNode(80);
    hapusNode(50);

    cetakLinkedList();

    return 0;
}
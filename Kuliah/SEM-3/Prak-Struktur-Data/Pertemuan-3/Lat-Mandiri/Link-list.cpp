#include <iostream>
using namespace std;

// Helper
void judul(){
    system("cls");
    cout << "=========================" << endl;
    cout << "|     Linklist P-03     |" << endl;
    cout << "=========================\n" << endl;
}

struct Node {
    int data;
    Node *next;
};

// Membaut Helper (pointer) 
Node *newNode, *helper, *head, *tail;

// Membuat list kosong
void listKosong(){
    head = NULL;
    tail = NULL;
}

// Function mencetak linklist
void printLinkList(){
    static int number = 0;
    cout << "\n=====[Print Linklist]=====" << endl;

    helper = head;
    while (helper != NULL){
        cout << helper->data << ", ";
        helper = helper->next;
    }

    cout << endl;
}

void sisipNode(int data_baru){

    newNode = new Node(); // Inisialisasi - Buat Struct
    newNode->data = data_baru; // Masukkan data
    newNode->next = NULL; // Link ke Null (belum tau data selanjutnya)

    if(head == NULL && tail == NULL){ // Kondisi 1: - Jika list masih kosong
        head = newNode;
        tail = newNode;
    } else if (newNode->data < head->data){ // Kondisi 2 - Sisip Depan
        newNode->next = head;
        head = newNode;
    } else if (newNode->data > tail->data){ // Kondisi 3 - Sisip Belakang
        tail->next = newNode;
        tail = newNode;
    } else {
        helper = head;
        while (helper != NULL && newNode->data > helper->next->data){
            helper = helper->next;
        }

        newNode->next = helper->next;
        helper->next = newNode;
    }
}

void hapusNode(int data_hapus){
    Node *hapus;
    helper = head;

    if (head != NULL && helper->data == data_hapus){
        head = head->next;
        return;
    }

    while(helper->next->data != data_hapus && helper != NULL){
        helper = helper->next;
    }

    hapus = helper->next;
    helper->next = hapus->next;
    hapus->next = NULL;
    delete(hapus);
}

int main(){
    judul();

    listKosong();
    sisipNode(10);
    sisipNode(5);
    sisipNode(25);
    sisipNode(100);
    sisipNode(50);

    hapusNode(5);
    printLinkList();
    
    hapusNode(10);
    printLinkList();
    
    hapusNode(100);
    printLinkList();


    return 0;
}
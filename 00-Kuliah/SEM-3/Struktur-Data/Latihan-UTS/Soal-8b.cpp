#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main (){
        Node ketiga = {60, nullptr};
        Node kedua = {30, &ketiga};
        Node pertama = {50, &kedua};

        Node *head = &pertama;
        Node *bantu = head;

        while (bantu != nullptr){
            cout << "Nilai : " << bantu->data << endl;
            bantu = bantu->next;
        }

        cout << endl;
        cout << "Data Pertama : " << head->data << endl;
        cout << "Data Kedua   : " << head->next->data << endl;

    /*
        Nilai : 50
        Nilai : 30
        Nilai : 60

        Data Pertama : 50
        Data Kedua   : 30
    */ 
}
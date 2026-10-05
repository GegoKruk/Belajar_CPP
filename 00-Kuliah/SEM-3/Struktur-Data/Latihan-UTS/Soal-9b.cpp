#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node ketiga = {60, nullptr};
    Node kedua = {30, &ketiga};
    Node pertama = {50, &kedua};

    Node* head = &pertama;
    Node baru = {40, nullptr};

    baru.next = kedua.next;
    kedua.next = &baru;

    cout << "Isi linked list: ";
    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }

    cout << "\nData setelah node kedua: ";
    cout << kedua.next->data << endl;
    
    return 0;
}

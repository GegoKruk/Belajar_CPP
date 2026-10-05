#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node ketiga = {75, nullptr};
    Node kedua = {35, &ketiga};
    Node pertama = {20, &kedua};

    Node* head = &pertama;
    Node* p = head->next;

    p->data = head->data + 10;
    p->next->data -= p->data;
    head = head->next;

    cout << "Isi linked list: ";

    Node* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }

    cout << "\nData pertama: " << head->data;
    cout << "\nData kedua: " << head->next->data;
    cout << "\nData node awal: " << pertama.data;
    cout << endl;

    return 0;
}

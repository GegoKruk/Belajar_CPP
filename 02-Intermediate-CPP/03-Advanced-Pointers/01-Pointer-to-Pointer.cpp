#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// MODIFIKASI POINTER DARI DALAM FUNCTION
// -------------------------------------------------------

// Cara C-style: terima int** agar bisa ubah pointer asli
void alokasi_c_style(int** pp, int nilai) {
    *pp = new int(nilai);       // ubah pointer yang ditunjuk pp
}

// Cara C++-style: terima int*& (reference ke pointer)
void alokasi_cpp_style(int*& ref, int nilai) {
    ref = new int(nilai);       // langsung ubah pointer asli
}

// SALAH: int* by value -- tidak bisa ubah pointer asli
void alokasi_salah(int* p, int nilai) {
    p = new int(nilai);         // hanya ubah SALINAN lokal -- bocor!
}

// -------------------------------------------------------
// POINTER-TO-POINTER UNTUK SWAP POINTER
// -------------------------------------------------------
void tukarPointer(int** a, int** b) {
    int* tmp = *a;
    *a = *b;
    *b = tmp;
}

// -------------------------------------------------------
// SIMULASI LINKED LIST NODE (pakai int** untuk insert di depan)
// -------------------------------------------------------
struct Node {
    int   data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void insertDepan(Node** head, int nilai) {
    Node* baru  = new Node(nilai);
    baru->next  = *head;
    *head       = baru;         // ubah head asli via pointer-to-pointer
}

void cetakList(const Node* head) {
    cout << "  list: ";
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void hapusSemuaNode(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// -------------------------------------------------------
// TIGA LEVEL POINTER (demonstrasi konsep)
// -------------------------------------------------------
void demo_tiga_level() {
    cout << "\n=== Tiga Level Pointer ===" << endl;

    int    x   = 100;
    int*   p   = &x;
    int**  pp  = &p;
    int*** ppp = &pp;

    cout << "  x          = " << x          << endl;
    cout << "  *p         = " << *p         << endl;
    cout << "  **pp       = " << **pp       << endl;
    cout << "  ***ppp     = " << ***ppp     << endl;

    ***ppp = 999;
    cout << "  setelah ***ppp = 999: x = " << x << endl;
}

// -------------------------------------------------------
// DYNAMIC 2D ARRAY DENGAN int**
// -------------------------------------------------------
void demo_2d_array() {
    cout << "\n=== Dynamic 2D Array via int** ===" << endl;

    int baris = 3, kolom = 4;

    int** m = new int*[baris];
    for (int i = 0; i < baris; i++) {
        m[i] = new int[kolom];
        for (int j = 0; j < kolom; j++)
            m[i][j] = i * kolom + j + 1;
    }

    for (int i = 0; i < baris; i++) {
        cout << "  baris[" << i << "]: ";
        for (int j = 0; j < kolom; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }

    for (int i = 0; i < baris; i++) delete[] m[i];
    delete[] m;
}

// -------------------------------------------------------
// SIMULASI argv (command-line arguments)
// -------------------------------------------------------
void simulasi_argv() {
    cout << "\n=== Simulasi Command-Line Arguments (char**) ===" << endl;

    // char** argv adalah array of C-string
    const char* args[] = {
        "./program",
        "input.txt",
        "--verbose",
        "100",
        nullptr     // sentinel: argv[argc] == nullptr
    };
    int argc = 4;
    const char** argv = args;

    cout << "  argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "  argv[" << i << "] = " << argv[i] << endl;
    }
}

int main() {

    // -------------------------------------------------------
    // DEKLARASI DAN NAVIGASI DASAR
    // -------------------------------------------------------
    cout << "=== Deklarasi Pointer-to-Pointer ===" << endl;
    {
        int   x  = 42;
        int*  p  = &x;
        int** pp = &p;

        cout << "  alamat: x=" << &x << " | p=" << p << " | pp=" << pp << endl;
        cout << "  nilai : x=" << x  << " | *p=" << *p << " | **pp=" << **pp << endl;

        // Ubah nilai x via pp
        **pp = 77;
        cout << "  setelah **pp=77 : x=" << x << ", *p=" << *p << endl;

        // Ubah arah p (ke variabel lain) via pp
        int y = 500;
        *pp = &y;
        cout << "  setelah *pp=&y  : p=" << p << ", *p=" << *p << endl;
        cout << "  x tidak berubah : x=" << x << endl;
    }

    // -------------------------------------------------------
    // MEMODIFIKASI POINTER DARI DALAM FUNCTION
    // -------------------------------------------------------
    cout << "\n=== Modifikasi Pointer dari Function ===" << endl;
    {
        int* ptr1 = nullptr;
        int* ptr2 = nullptr;

        alokasi_c_style(&ptr1, 111);
        cout << "  c_style  : *ptr1 = " << *ptr1 << endl;

        alokasi_cpp_style(ptr2, 222);
        cout << "  cpp_style: *ptr2 = " << *ptr2 << endl;

        // Demonstrasi yang "salah" -- ptr3 tetap nullptr
        int* ptr3 = nullptr;
        alokasi_salah(ptr3, 333);
        if (ptr3 == nullptr)
            cout << "  by_value : ptr3 masih nullptr (tidak berubah!)" << endl;

        delete ptr1; ptr1 = nullptr;
        delete ptr2; ptr2 = nullptr;
    }

    // -------------------------------------------------------
    // SWAP POINTER
    // -------------------------------------------------------
    cout << "\n=== Tukar Pointer via int** ===" << endl;
    {
        int a = 11, b = 22;
        int* pa = &a;
        int* pb = &b;

        cout << "  sebelum: *pa=" << *pa << ", *pb=" << *pb << endl;
        tukarPointer(&pa, &pb);
        cout << "  sesudah: *pa=" << *pa << ", *pb=" << *pb << endl;
        cout << "  a=" << a << ", b=" << b << " (nilai asli tidak berubah)" << endl;
    }

    // -------------------------------------------------------
    // LINKED LIST INSERT DI DEPAN
    // -------------------------------------------------------
    cout << "\n=== Linked List dengan int** ===" << endl;
    {
        Node* head = nullptr;

        insertDepan(&head, 30);
        insertDepan(&head, 20);
        insertDepan(&head, 10);
        cetakList(head);

        insertDepan(&head, 5);
        cetakList(head);

        hapusSemuaNode(head);
    }

    demo_tiga_level();
    demo_2d_array();
    simulasi_argv();

    return 0;
}

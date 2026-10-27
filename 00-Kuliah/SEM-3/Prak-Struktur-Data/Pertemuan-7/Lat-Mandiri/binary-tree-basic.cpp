#include <iostream>
#include <string>
using namespace std;

// Helper Visual Function
void judulNama(){
    system("color 0B");
    system("cls");
    cout << "\n ==========[PRAKTIKUM P7]==========" << endl;
    cout << " |         BINARY TREE            |" << endl;
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
    Node *left;
    Node *right;
};

Node *createNode(int nilai){
    Node *baru = new Node();
    baru->left = nullptr;
    baru->right = nullptr;
    baru->data = nilai;
    return baru;
}

bool cekRoot(Node *root){
    return (root == nullptr);
}

// Traversal Functions
void inOrder(Node *root){
    if(cekRoot(root)){ 
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root){
    if(cekRoot(root)){ 
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if(cekRoot(root)){ 
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int jumlahNode(Node* root){
    if (cekRoot(root)){
        return 0;
    }
    return 1 + jumlahNode(root->left) + jumlahNode(root->right);
}

void clear(Node*& root){
    if (cekRoot(root)){ 
        return;
    }
    clear(root->left);
    clear(root->right);

    delete root;
    root = nullptr;
}

bool cariNilai(Node *root, int nilaiCari){
    if (cekRoot(root)){
        return false;
    } 
    if (nilaiCari == root->data){
        return true;
    } 
    
    return cariNilai(root->left, nilaiCari) || cariNilai(root->right, nilaiCari);
}

// Menu Functionsreturn 0;
void menu1(Node *root){
    judulSection("Cetak In-Order");
    if(cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    }

    cout << " [>] Hasil Traversal : "; 
    inOrder(root);
    cout << endl;
    jeda();
}

void menu2(Node *&root){
    judulSection("Cetak Pre-Order");
    if(cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    }

    cout << " [>] Hasil Traversal : "; 
    preOrder(root);
    cout << endl;
    jeda();
}

void menu3(Node *&root){
    judulSection("Cetak Post-Order");
    if(cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    }

    cout << " [>] Hasil Traversal : "; 
    postOrder(root);
    cout << endl;
    jeda();
}

void menu4(Node *&root){
    judulSection("Cetak Semua Order");
    if(cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    }

    cout << " [>] In-Order   : "; inOrder(root);   cout << "\n";
    cout << " [>] Pre-Order  : "; preOrder(root);  cout << "\n";
    cout << " [>] Post-Order : "; postOrder(root); cout << "\n";
    jeda();
}

void menu5(Node *&root){
    judulSection("Cari Nilai");
    if(cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    }

    cout << " [?] Masukkan nilai yang dicari : ";
    int nilai;
    cin >> nilai;
    cin.ignore();
    
    if (cariNilai(root, nilai)){
        cout << "\n [*] SUKSES: Nilai [" << nilai << "] ditemukan di dalam Tree!" << endl;
    } else {
        cout << "\n [!] GAGAL: Nilai [" << nilai << "] tidak ditemukan!" << endl;
    }
    jeda();
}

void menu6(Node *&root){
    judulSection("Jumlah Node");
    cout << " [>] Jumlah Node Saat Ini : " << jumlahNode(root) << " node" << endl;
    jeda();
}

void menu7(Node *&root){
    judulSection("Hapus Binary Tree");
    if (cekRoot(root)){
        cout << " [!] Tree kosong!" << endl;
        jeda();
        return;
    } 
        
    clear(root);
    cout << " [*] SUKSES: Semua elemen Binary Tree berhasil dihapus!" << endl;
    jeda();
}

int main(){
    int pilihanMenu;
    Node *root = nullptr;
    
    root = createNode(50);
    root->left = createNode(80);
    root->left->left = createNode(10);
    root->left->right = createNode(70);
    root->left->right->left = createNode(30);
    root->left->right->right = createNode(40); 
    root->right = createNode(20);
    root->right->right = createNode(90);

    do {
        judulNama();
        cout << "\n =========== [MENU UTAMA] ===========" << endl;
        cout << " |  [1] Cetak In-Order             |" << endl;
        cout << " |  [2] Cetak Pre-Order            |" << endl;
        cout << " |  [3] Cetak Post-Order           |" << endl;
        cout << " |  [4] Cetak Semua Order          |" << endl;
        cout << " |  [5] Cari Nilai                 |" << endl;
        cout << " |  [6] Jumlah Node                |" << endl;
        cout << " |  [7] Hapus Binary Tree          |" << endl;
        cout << " |  [8] Keluar Program             |" << endl;
        cout << " ===================================" << endl;
        cout << "\n [>] Pilih menu [1-8] : ";
        
        if (!(cin >> pilihanMenu)) {
            cin.clear();
            cin.ignore(1000, '\n');
            pilihanMenu = 0; 
        } else {
            cin.ignore();
        }

        switch (pilihanMenu){
            case 1: menu1(root); break;
            case 2: menu2(root); break;
            case 3: menu3(root); break;
            case 4: menu4(root); break;
            case 5: menu5(root); break;
            case 6: menu6(root); break;
            case 7: menu7(root); break;
            case 8:
                judulNama();
                cout << "\n\t[ Program Selesai ]\n\tSampai jumpa kembali!" << endl;
                break;
            default:
                cout << "\n [!] Input salah! Silakan ketik angka antara 1 sampai 8" << endl;
                jeda();
                break;
        }
    } while (pilihanMenu != 8);
    
    clear(root); 
    return 0;
}

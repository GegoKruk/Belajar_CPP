#include <iostream>
#include <string>
using namespace std;

// Helper Visual Function
    void judulNama(){
        system("color 0B");
        system("cls");
        cout << "\n ==========[PRAKTIKUM P8]==========" << endl;
        cout << " |      BINARY TREE LANJUTAN      |" << endl;
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

    // Struktur Node
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    
    // Root awal
    Node* root = nullptr;

// Utils Function
    // Helper untuk mengecek apakah tree kosong beserta output visualnya
    bool cekKosong() {
        if (root == nullptr) {
            cout << " [GAGAL] Binary Tree Masih Kosong" << endl;
            jeda();
            return true;
        }
        return false;
    }
    
    // Fungsi mencari data
    const Node* cari(const Node* root, int nilai) {
        if (root == nullptr) {
            return nullptr;
        }
        if (nilai == root->data) {
            return root;
        }
        if (nilai < root->data) {
            return cari(root->left, nilai);
        }
        return cari(root->right, nilai);
    }
    
    // Fungsi menambahkan data
    bool insert(Node*& root, int nilai) {
        if (root == nullptr) {
            root = new Node{nilai, nullptr, nullptr};
            return true;
        }
        if (nilai < root->data) {
            return insert(root->left, nilai);
        }
        if (nilai > root->data) {
            return insert(root->right, nilai);
        }
        return false;
    }
    
    // Traversal Inorder
    void inorder(const Node* root) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
    // Traversal preorder
    void preorder(const Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    // Traversal postorder
    void postorder(const Node* root) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
    // Mencari nilai terkecil
    const Node* minimum(const Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    
    // Mencari Nilai
    bool cariNilai(Node *root, int nilaiCari){
        if (root == nullptr){
            return false;
        }
        if (nilaiCari == root->data){
            return true;
        } 
        return cariNilai(root->left, nilaiCari) || cariNilai(root->right, nilaiCari);
    }
    
    // Menghitung jumlah node
    int jumlahNode(const Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + jumlahNode(root->left) + jumlahNode(root->right);
    }
    
    // Fungsi menghapus data
    bool hapus(Node*& root, int nilai) {
        if (root == nullptr) {
            return false;
        }
        if (nilai < root->data) {
            return hapus(root->left, nilai);
        }
        else if (nilai > root->data) {
            return hapus(root->right, nilai);
        }
        else {

            // Kasus 0 anak (Leaf)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            }
            
            // Kasus 2 anak
            else if (root->left != nullptr && root->right != nullptr) {
                const Node* pengganti = minimum(root->right);
                root->data = pengganti->data;
                hapus(root->right, pengganti->data);
            }
            
            // Kasus 1 anak
            else {
                Node* target = root;
                if (root->left != nullptr) {
                    root = root->left;
                }
                else {
                    root = root->right;
                }
                delete target;
            }
            return true;
        }
    }
    
    // Menghapus seluruh node sebelum program selesai
    void bersihkan(Node*& root) {
        if (root == nullptr) {
            return;
        }
        bersihkan(root->left);
        bersihkan(root->right);
        delete root;
        root = nullptr;
    }
    void gambar(Node *node, int tingkat, char arah){
        if (node == nullptr){
            return;
        }
        gambar(node->right, tingkat + 1, '/');
        for (int i = 0; i < tingkat; i++){
            cout << "      ";
        }
        if (arah != ' '){
            cout << arah << "-- "; 
        }
        cout << node->data << endl; 
        gambar(node->left, tingkat + 1, '\\');
    }

// Menu Function
    void tambahNode(){
        char lanjut;
        do {
            judulSection("Tambah Node");
            cout << " [>] Masukkan Nilai  : ";
            int nilaiBaru;
            cin >> nilaiBaru;
            cin.ignore();
            if (insert(root, nilaiBaru)) {
                cout << "\n [SUKSES] Menambahkan Node"<< endl;
            } else {
                cout << "\n [GAGAL] Data Sudah Ada - Duplikat" << endl;
            }
            cout << "\n Tambah Node Lainnya? [Y/N] : ";
            cin >> lanjut;
            cin.ignore();
        } while (lanjut == 'y' || lanjut == 'Y');
    }
    
    void cetakInorder(){
        judulSection("Cetak In-Order");
        if (cekKosong()) {
            return;
        }
        cout << " [>] In-Order : "; 
        inorder(root);
        cout << "\n\n [SUKSES] Mencetak In-Order" << endl;
        jeda();
    }
    
    void cetakPreorder(){
        judulSection("Cetak Pre-Order");
        if (cekKosong()) {
            return;
        }
        cout << " [>] Pre-Order : "; 
        preorder(root);
        cout << "\n\n [SUKSES] Mencetak Pre-Order" << endl;
        jeda();
    }
    
    void cetakPostorder(){
        judulSection("Cetak Post-Order");
        if (cekKosong()) {
            return;
        }
        cout << " [>] Post-Order : "; 
        postorder(root);
        cout << "\n\n [SUKSES] Mencetak Post-Order" << endl;
        jeda();
    }
    
    void cetakAllOrder(){
        judulSection("Cetak Semua Order");
        if (cekKosong()) {
            return;
        }
        cout << "\n [>] In-Order   : "; inorder(root); cout << endl;
        cout << " [>] Pre-Order  : "; preorder(root); cout << endl;
        cout << " [>] Post-Order : "; postorder(root); cout << endl;
        cout << "\n [SUKSES] Mencetak Semua Order" << endl;
        jeda();
    }
    
    void gambarBinTree(){
        judulSection("Gambar Binary Tree");
        if (cekKosong()) {
            return;
        }
        cout << " [>] Visualisasi Struktur Binary Tree :\n" << endl;
        gambar(root, 0, ' ');
        cout << "\n [SUKSES] Menampilkan Visualisasi Binary Tree" << endl;
        jeda();
    }
    
    void cariNode(){
        char lanjut;
        do {
            judulSection("Cari Node");
            if (cekKosong()) {
                return;
            }
            cout << " [>] Masukkan Nilai yang Dicari  : ";
            int target;
            cin >> target;
            cin.ignore();
            if (cariNilai(root, target)){
                cout << "\n [SUKSES] Node " << target << " Ditemukan" << endl;
            } else {
                cout << "\n [GAGAL] Node " << target << " Tidak Ditemukan" << endl;
            }
            cout << "\n Cari Node Lainnya? [Y/N] : ";
            cin >> lanjut;
            cin.ignore();
        } while (lanjut == 'y' || lanjut == 'Y');
    }
    
    void cariNodeMIN(){
        judulSection("Cari Node (MIN)");
        if (cekKosong()) {
            return;
        }
        const Node* minNode = minimum(root);
        cout << " [>] Nilai Node Terkecil (MIN) : " << minNode->data << endl;
        cout << "\n [SUKSES] Menemukan Nilai Terkecil" << endl;
        jeda();
    }

    void jmlNode(){
        judulSection("Jumlah Node");
        cout << " [>] Jumlah Node Saat Ini : " << jumlahNode(root) << " node" << endl;
        cout << "\n [SUKSES] Menampilkan Jumlah Node" << endl;
        jeda();
    }

    void hapusNode(){
        char lanjut;
        do {
            judulSection("Hapus Node");
            if (cekKosong()) {
                return;
            }
            cout << " [>] Masukkan Nilai yang Ingin Dihapus : ";
            int target;
            cin >> target;
            cin.ignore();
            if (hapus(root, target)){
                cout << "\n [SUKSES] Node " << target << " Berhasil Dihapus" << endl;
            } else {
                cout << "\n [GAGAL] Node " << target << " Tidak Ditemukan" << endl;
            }
            if (root == nullptr){
                cout << "\n [!] Binary Tree Sekarang Kosong" << endl;
                jeda();
                return;
            }
            cout << "\n Hapus Node Lainnya? [Y/N] : ";
            cin >> lanjut;
            cin.ignore();
        } while (lanjut == 'y' || lanjut == 'Y');
    }

    void hapusBinaryTree(){
        judulSection("Hapus Binary Tree");
        if (cekKosong()) {
            return;
        }
        bersihkan(root);
        cout << " [SUKSES] Seluruh Node Binary Tree Berhasil Dihapus" << endl;
        jeda();
    }

// Main Function
    int main(){
        int pilihanMenu;
        do {
            judulNama();
            cout << "\n ========== [MENU UTAMA] ==========" << endl;
            cout << " |                                |" << endl;
            cout << " |  [1] Tambah Node               |" << endl;
            cout << " |  [2] Cetak In-Order            |" << endl;
            cout << " |  [3] Cetak Pre-Order           |" << endl;
            cout << " |  [4] Cetak Post-Order          |" << endl;
            cout << " |  [5] Cetak Semua Order         |" << endl;
            cout << " |  [6] Gambar Binary Tree        |" << endl;
            cout << " |  [7] Cari Node                 |" << endl;
            cout << " |  [8] Cari Node (MIN)           |" << endl;
            cout << " |  [9] Jumlah Node               |" << endl;
            cout << " | [10] Hapus Node                |" << endl;
            cout << " | [11] Hapus Binary Tree         |" << endl;
            cout << " |  [0] Keluar Program            |" << endl;
            cout << " |                                |" << endl;
            cout << " ==================================" << endl;
            cout << "\n [>] Pilih menu [0-11] : ";
            if (!(cin >> pilihanMenu)) {
                cin.clear();
                cin.ignore(1000, '\n');
                pilihanMenu = -1; 
            } else {
                cin.ignore();
            }
            switch (pilihanMenu){
                case 1: tambahNode(); break;
                case 2: cetakInorder(); break;
                case 3: cetakPreorder(); break;
                case 4: cetakPostorder(); break;
                case 5: cetakAllOrder(); break;
                case 6: gambarBinTree(); break;
                case 7: cariNode(); break;
                case 8: cariNodeMIN(); break;
                case 9: jmlNode(); break;
                case 10: hapusNode(); break;
                case 11: hapusBinaryTree(); break;
                case 0:
                    judulNama();
                    cout << "\n\t[ Program Selesai ]\n\tSampai jumpa kembali!" << endl;
                    break;
                default:
                    cout << "\n [!] Input salah! Silakan ketik angka antara 0 sampai 11" << endl;
                    jeda();
                    break;
            }
        } while (pilihanMenu != 0);
        bersihkan(root); 
        return 0;
    }
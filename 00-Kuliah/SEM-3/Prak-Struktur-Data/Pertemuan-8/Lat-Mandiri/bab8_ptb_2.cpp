#include <iostream>
using namespace std;

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
    gambar(node->right, tingkat+1, '/');
    for (int i = 0; i < tingkat; i++){
        cout << "      ";
    }
    if (arah != ' '){
        cout << arah << "-- " << endl;
    }
    cout << node->data << endl;
    gambar(node->left, tingkat+1, '\\');
}



// Program utama
int main() {
    int pilihan, nilai;

    do {
        system("cls");
        cout << "\n===== BINARY SEARCH TREE =====" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Cari Data" << endl;
        cout << "3. Tampilkan Inorder" << endl;
        cout << "4. Cari Nilai Terkecil" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                cin.ignore();

                if (insert(root, nilai)) {
                    cout << "Data berhasil ditambahkan." << endl;
                }
                else {
                    cout << "Data duplikat! Penambahan ditolak." << endl;
                }
                jeda();
                break;

            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> nilai;
                cin.ignore();

                if (cari(root, nilai) != nullptr) {
                    cout << "Data " << nilai << " ditemukan." << endl;
                }
                else {
                    cout << "Data tidak ditemukan." << endl;
                }
                jeda();
                break;

            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                gambar(root, 0, ' ');
                cout << endl;
                jeda();
                break;

            case 4: {
                const Node* hasil = minimum(root);

                if (hasil != nullptr) {
                    cout << "Nilai terkecil: " << hasil->data << endl;
                }
                else {
                    cout << "Pohon masih kosong." << endl;
                }
                jeda();
                break;
            }

            case 5:
                cout << "Masukkan nilai yang dihapus: ";
                cin >> nilai;
                cin.ignore();

                if (hapus(root, nilai)) {
                    cout << "Data berhasil dihapus." << endl;
                }
                else {
                    cout << "Data tidak ditemukan." << endl;
                }
                jeda();
                break;

            case 0:
                bersihkan(root);
                cout << "Program selesai." << endl;
                jeda();
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}

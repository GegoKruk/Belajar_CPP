#include <iostream> 
#include <string> 
using namespace std; 

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t============================================" << endl;
        cout << "\t||   MODUL 2 - Praktikum Struktur Data    ||" << endl;
        cout << "\t||   __________________________________   ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t||          Nama  : Gega Ramadhan         ||" << endl;
        cout << "\t||          NIM   : 1231250112            ||" << endl;
        cout << "\t||          Kelas : IF-D                  ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t============================================\n\n" << endl;
    }

    void judulMenu(string judul){
        cout << "\n==========[" << judul <<"]==========" << endl;
    }

    void garis(){
        cout << "\n -----------------------------------------" << endl;
    }

    void jeda() {
        cout << "\n\t    Tekan Enter untuk lanjut...";
        cin.get();
    }

// Global Variable  &Deklarasi 
struct Mahasiswa { 
    string nim; 
    string nama; 
    double ipk; 
}; 

// Function Prototype
    // Function Logic
    void inputData(Mahasiswa* data, int jumlah); 
    void tampilkanData(const Mahasiswa* data, int jumlah); 
    int cariNim(const Mahasiswa* data, int jumlah, const string& nim); 

// Main Function
    int main() { 
        judulNama();

        judulMenu("Input Max Mahasiswa");
        cout << " [>] Masukkan Jumlah Max Mahasiswa : ";
        int jumlah; 
        cin >> jumlah;
        cin.ignore(); 
        if (jumlah <= 0) {
            return 0;
        } 
        
        judulMenu("Input Data Mahasiswa");
        Mahasiswa *data = new Mahasiswa[jumlah]; 
        inputData(data, jumlah); 
        
        judulMenu("Tampilkan Data Mahasiswa");
        tampilkanData(data, jumlah); 
        
        judulMenu("Cari Data NIM Mahasiswa");
        cout << "\n [>] Masukkan NIM :";
        string nim; 
        cin >> nim; 
        cin.ignore();
        int posisi = cariNim(data, jumlah, nim); 
        cout << posisi << '\n'; 
    
        delete[] data; 
        data = nullptr; 
    } 
// Function Helper Logic
    void inputData(Mahasiswa *data, int jumlah) {
        for (int i = 0; i < jumlah; i++){
            cout << "\n [Data Mahasiswa Ke-" << i+1 << "]--------------------" << endl;
            cout << "   [1] Masukkan Nama : ";
            getline(cin, data[i].nama);
            cout << "   [2] Masukkan NIM  : ";
            cin >> data[i].nim;
            cin.ignore();
            cout << "   [3] Masukkan IPK  : ";
            cin >> data[i].ipk;
            cin.ignore();
        }
        garis();
    }
    
    void tampilkanData(const Mahasiswa *data, int jumlah) { 
        for (int i = 0; i < jumlah; i++){
            cout << "\n [Data Mahasiswa Ke-" << i+1 << "]--------------------" << endl;
            cout << "   [1] Masukkan Nama : " << data[i].nama << endl;
            cout << "   [2] Masukkan NIM  : " << data[i].nim << endl; 
            cout << "   [3] Masukkan IPK  : " << data[i].ipk << endl; 
        }
        garis();
    }
    
    int cariNim(const Mahasiswa *data, int jumlah, const string& nim) {
        for (int i = 0; i < jumlah; i++){
            if (data[i].nim == nim){  
                cout << "\n\t [SUKSES] Data Ditemukan" << endl;
                cout << "\n [Data Mahasiswa Ke-" << i+1 << "]--------------------" << endl;
                cout << "   [1] Nama : " << data[i].nama << endl;
                cout << "   [2] NIM  : " << data[i].nim << endl;
                cout << "   [3] IPK  : " << data[i].ipk << endl;
                garis();
                return i; 
            }
        }
        return -1; 
    }


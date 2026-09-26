#include <iostream> 
#include <string> 
using namespace std; 

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t============================================" << endl;
        cout << "\t||   MODUL 4 - Praktikum Struktur Data    ||" << endl;
        cout << "\t||   __________________________________   ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t||          Nama  : Gega Ramadhan         ||" << endl;
        cout << "\t||          NIM   : 1231250112            ||" << endl;
        cout << "\t||          Kelas : IF-D                  ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t============================================\n\n" << endl;
    }

    void judulMenu(string judul){
        judulNama();
        cout << "==========[" << judul <<"]==========" << endl;
    }

    void garis(){
        cout << "--------------------------------------------------" << endl;
    }

    void jeda() {
        cout << "\n\t    Tekan Enter untuk lanjut...";
        cin.get();
    }

// Global Variable  &Deklarasi 

// Function Prototype
    // Function Logic

    // Function Display
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();

// Main Function
    int main() { 
        int pilihanMenu; 
        do {
            judulNama();
            cout << "=================[ Menu Utama ]================" << endl;
            cout << "|                                             |" << endl;
            cout << "| [1] Menu-1                                  |" << endl;
            cout << "| [2] Menu-2                                  |" << endl;
            cout << "| [3] Menu-3                                  |" << endl;
            cout << "| [4] Menu-4                                  |" << endl;
            cout << "| [5] Jumlah Mahasiswa                        |" << endl;
            cout << "| [6] Keluar                                  |" << endl;
            cout << "|                                             |" << endl;
            cout << "===============================================" << endl;
            cout << "\n > Pilih [1-5] : ";
            cin >> pilihanMenu; 
            cin.ignore();
                
                switch (pilihanMenu){
                    case 1:
                        void menu1();
                        break;
                    case 2:
                        void menu2();
                        break;
                    case 3:
                        void menu3();
                        break;
                    case 4:
                        void menu4();
                        break;
                    case 5:
                        void menu5();
                        break;
                    case 6:
                        judulNama();
                        cout << "\n\t    [Program Selesai] - Terima Kasih" << endl;
                        exit(0);
                        break;
                    default:
                        cout << "\n\t    [ERROR] - Input Tidak Valid" << endl;
                        jeda();
                        break;
                }
        } while (pilihanMenu != 6); 
        return 0; 
    }

// Function Helper Logic

// Function Display
    void menu1(){
        judulMenu("Menu-1");
        
        jeda();
    }

    void menu2(){
        judulMenu("Menu-2");
        
        jeda();
    }

    void menu3(){
        judulMenu("Menu-3");
        
        jeda();
    }

    void menu4(){
        judulMenu("Menu-4");
        
        jeda();
    }

    void menu5(){
        judulMenu("Menu-5");
        
        jeda();
    }

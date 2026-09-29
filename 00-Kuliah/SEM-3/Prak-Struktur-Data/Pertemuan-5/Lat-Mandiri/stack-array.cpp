#include <iostream>
using namespace std;

// Helper Visual Function
    void judulNama(){
        system("color 03");
        system("cls");
        cout << "\n==========[PRAKTIKUM P5]==========" << endl;
        cout << "|          STACK ARRAY           |" << endl;
        cout << "|  ____________________________  |" << endl;
        cout << "|                                |" << endl;
        cout << "|      Nama : Gega Ramadhan      |" << endl;
        cout << "|      NIM  : 123250112          |" << endl;
        cout << "|                                |" << endl;
        cout << "----------------------------------\n" << endl;
    }

    void judulSection(string judul){
        judulNama();
        cout << "\n==========["<<judul<<"]==========" << endl;
    }

    void jeda(){
        cout << "\n\t Tekan untuk lanjut..." << endl;
        cin.get();
    }

// Global Variable 
    const int KAPASITAS = 100;
    struct Stack{
        int data[KAPASITAS];
        int top;
    };

// Function Logic
    void buatStack(Stack &s){
        s.top = -1;
    }

    bool isEmpty(Stack &s){
        return s.top == -1;
    }

    bool isFull(Stack &s){
        return s.top == KAPASITAS - 1;
    }

    bool push(Stack &s, int nilai){
        if (isFull(s)){
            return false;
        }   

        ++s.top;
        s.data[s.top] = nilai;
        
        return true;
    }
    
    void tampilkanStack(Stack &s){
        if (isEmpty(s)){
            cout << "\n\t [!] Stack Masih Kosong" << endl;
            jeda();
            return;
        }


        cout << "\n [Preview Data Stack]==========" << endl;
        for (int i = s.top; i >= 0; i--){
            if (i == s.top){
                cout << " [>] " << s.data[i] << " <--- TOP"<< endl;
            } else {
                cout << " [>] " << s.data[i] << endl;
            }
        } 
        
        cout << "\n [SUKSES] Menampilkan Seluruh Data Stack" << endl;
        jeda();
    }

// Function Prototype
    void menu1(Stack &s);
    void menu2(Stack &s);

// Main Function
    int main(){
        Stack s;
        int pilihanMenu;
        buatStack(s);
        do {
            judulNama();
            cout << "\n ==========[MENU UTAMA]==========" << endl;
            cout << " | [1] Push Data                |" << endl;
            cout << " | [2] Tampilkan Data           |" << endl;
            cout << " | [3] Exit                     |" << endl;
            cout << " |______________________________|" << endl;
            cout << "\n [>] Pilih [1-3] : ";
            cin >> pilihanMenu;
            cin.ignore();

            switch (pilihanMenu){
                case 1:
                    menu1(s);
                    break;
                case 2:
                    menu2(s);
                    break;
                case 3:
                    judulNama();
                    cout << "\n\t [Program Selesai] - Terima Kasih" << endl;
                    break;
                default:
                    cout << "\n\t [!] Input Tidak Valid - Ulangi" << endl;
                    jeda();
                    break;
                }
        } while (pilihanMenu != 3);
        return 0;
    }


// Function Menu
    void menu1(Stack &s){
        char lanjut;
        do{
            judulSection("PUSH STACK");
    
            int nilai;
            cout << "\n [>] Masukkan Nilai : ";
            cin >> nilai;
            cin.ignore();
    
            bool status = push(s, nilai);
            if (status == false){
                cout << "\n\t [!] Stack Penuh" << endl;
            } else {
                cout << "\n [SUKSES] Data Berhasil Di-Push" << endl;
            }

            cout << "\n Push Data Lainnya? [Y/N] : ";
            cin >> lanjut;
            cin.ignore();
        } while (lanjut == 'Y' || lanjut == 'y');
        
    };
    
    void menu2(Stack &s){
        judulSection("TAMPILKAN STACK");
        tampilkanStack(s);
    };

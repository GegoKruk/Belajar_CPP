#include <iostream>
using namespace std;

// Function Helper Visual
    void judulNama(){
        system("color 03");
        system("cls");
        cout << "\n=========[PRAKTIKUM P5]=========" << endl;
        cout << "|       STACK LINKED LIST      |" << endl;
        cout << "|  __________________________  |" << endl;
        cout << "|                              |" << endl;
        cout << "|     Nama : Gega Ramadhan     |" << endl;
        cout << "|     NIM  : 123250112         |" << endl;
        cout << "|                              |" << endl;
        cout << "--------------------------------\n" << endl;
    }

    void judulSection(string judul){
        judulNama();
        cout << "\n==========["<<judul<<"]==========" << endl;
    }

    void jeda(){
        cout << "\n\t Tekan untuk lanjut..." << endl;
        cin.get();
    }

// Global Variabel
    struct Node {
        int info;
        Node *next;
    };

    struct LinkedStack{
        Node *top;
    };

//  Function Helper Logic
    void buatStack(LinkedStack &stack){
        stack.top = nullptr;
    }

    bool isFull(){
        Node *temp;
        temp = new Node();
        if (temp == nullptr){
            return true;
        }
        delete temp;
        return false;
    }

    bool isEmpty(LinkedStack &stack){
        return stack.top == nullptr;
    }

    bool push(LinkedStack &stack, int infoBaru){
        Node *newNode;
        newNode = new Node();
        
        newNode->info = infoBaru;
        newNode->next = stack.top;
        stack.top = newNode;
        
        return true;
    }

    void pop(LinkedStack &stack){
        Node *temp;
        temp = stack.top;
        cout << "\n [SUKSES] POP Data : " << temp->info << endl;
        stack.top = stack.top->next;
        delete temp;
    }

    void peek(LinkedStack &stack){
        cout << "\n [>] Data Stack Paling Atas : " << stack.top->info << endl;
    }

    int hitung(LinkedStack &stack){
        int counter = 0;
        Node *temp = stack.top;
        while (temp != nullptr){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void printStack(LinkedStack &stack){
        
        Node *temp = stack.top;
        cout << "\n [Data Stack]=======================" << endl;
        
        int counter = hitung(stack);
        while (temp != nullptr){
            if (temp == stack.top){
                cout << " | Data Ke-" << counter-1 <<" : " << temp->info << " <---- TOP" << endl;
            } else {
                cout << " | Data Ke-" << counter-1 <<" : " << temp->info << endl;
            }
            
            counter--;
            temp = temp->next;
        }
    }

    void clearStack(LinkedStack &stack){
        Node *temp;
        while (stack.top != nullptr){
            temp = stack.top;
            stack.top = stack.top->next;
            delete temp;
        }
    }

// Function Prototype
    void menu1(LinkedStack &stack);
    void menu2(LinkedStack &stack);
    void menu3(LinkedStack &stack);
    void menu4(LinkedStack &stack);
    void menu5(LinkedStack &stack);

// Main Function
    int main(){
        LinkedStack stack;
        int pilihanMenu;
        buatStack(stack);
        do {
            judulNama();
            cout << "\n ==========[MENU UTAMA]==========" << endl;
            cout << " | [1] Push Data                |" << endl;
            cout << " | [2] Pop Data                 |" << endl;
            cout << " | [3] Peek Data Top            |" << endl;
            cout << " | [4] Tampilkan Data           |" << endl;
            cout << " | [5] Bersihkan Data           |" << endl;
            cout << " | [6] Exit                     |" << endl;
            cout << " |______________________________|" << endl;
            cout << "\n [>] Pilih [1-6] : ";
            cin >> pilihanMenu;
            cin.ignore();

            switch (pilihanMenu){
                case 1:
                    menu1(stack);
                    break;
                case 2:
                    menu2(stack);
                    break;
                case 3:
                    menu3(stack);
                    break;
                case 4:
                    menu4(stack);
                    break;
                case 5:
                    menu5(stack);
                    break;
                case 6:
                    judulNama();
                    cout << "\n\t [Program Selesai] - Terima Kasih" << endl;
                    break;
                default:
                    cout << "\n\t [!] Input Tidak Valid - Ulangi" << endl;
                    jeda();
                    break;
                }
        } while (pilihanMenu != 6);
        return 0;
    }

    void menu1(LinkedStack &stack){
        char ulang;
        do{
            judulSection("PUSH DATA");
            if (isFull()){
                cout << "\n\t [!] Stack Penuh" << endl;
                jeda();
                return;
            }
            
            int InputNilai;
            cout << "\n [>] Masukkan Nilai : ";
            cin >> InputNilai;
            cin.ignore();

            push(stack, InputNilai);
            cout << "\n-------------------------------" << endl;
            cout << "\n [SUKSES] Push Data" << endl;

            cout << "\n Push Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();
        } while (ulang == 'Y' || ulang == 'y');
    };

    void menu2(LinkedStack &stack){
        char ulang;
        do{
            judulSection("POP DATA");
            if (isEmpty(stack)){
                cout << "\n\t [>] Stack Masih Kosong" << endl;
                jeda();
                return;
            }
            pop(stack);
            cout << "\n Push Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();
        } while (ulang == 'Y' || ulang == 'y');
    };
    
    void menu3(LinkedStack &stack){
        judulSection("PEEK DATA TOP");
        if (isEmpty(stack)){
            cout << "\n\t [>] Stack Masih Kosong" << endl;
            jeda();
            return;
        }
        peek(stack);
        jeda();
    };

    void menu4(LinkedStack &stack){
        judulSection("TAMPILKAN DATA");
        if (isEmpty(stack)){
            cout << "\n\t [>] Stack Masih Kosong" << endl;
            jeda();
            return;
        }

        printStack(stack);
        
        cout << "\n------------------------------------" << endl;
        cout << "\n [SUKSES] Semua Data Telah Ditampilkan" << endl;
        jeda();
    };

    void menu5(LinkedStack &stack){
        judulSection("Clear Stack");
        if (isEmpty(stack)){
            cout << "\n\t [>] Stack Masih Kosong" << endl;
            jeda();
            return;
        }
        clearStack(stack);
        cout << "\n [SUKSES] Clear Seluruh Stack" << endl;
        jeda();
    };

#include <iostream>
using namespace std;

// Soal 5
/*
    #include <iostream>
    using namespace std;

    void banyakPecahan(long uang, long pecahan[]);
    
    int main(){ 
        long uang,pecahan[9] = {50000,20000,10000,5000,2000,1000,500,200,100};
        int lembar[9],i;
        cout << "Jumlah Uang Kembali : Rp "; cin >> uang; cout << "Pecahan uang kembali: " << endl; banyakPecahan(uang,pecahan);
    }
    
    void banyakPecahan(long uang, long pecahan[]){
    
    }
*/

void banyakPecahan(long uang, long pecahan[]);

void nimNama(){
    system("CLS");

    cout << "---------------------------------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan    | Nama : Rassya Arma Putra    |" << endl;
    cout << "| NIM  : 123250112        | NIM  : 123250118            |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

int main(){ 
    long uang,pecahan[9] = {50000,20000,10000,5000,2000,1000,500,200,100};
    int lembar[9];

    // Tampilkan Nama & NIM
    nimNama();

    // Tampilan Awal Programm
    cout << "\n=====[Program Penghitung KUang Kembalian]=====" << endl;
    
    cout << "Masukkan Jumlah Uang Kembali : Rp "; 
    cin >> uang; 
    cout << "Pecahan uang kembali         : " << endl; 
    
    banyakPecahan(uang,pecahan);
}

void banyakPecahan(long uang, long pecahan[]){
    for (int i = 0; i < 9; i++){
        int jumlah = uang / pecahan[i];
        if (jumlah > 0){
            if (pecahan[i] >= 1000){
                cout << " - " << jumlah << " Lembar Rp " << pecahan[i] << endl;
            } else {
                cout << " - " << jumlah << " Keping Rp " << pecahan[i] << endl;
            }
            uang = uang % pecahan[i]; // Update Uang dengan modulus
        }
    }
}

/*
    void banyakPecahan(long uang, long pecahan[]){
        for (int i = 0; i < 9; i++){
            int hasilBagi = uang / pecahan[i];

            if (hasilBagi != 0){
                cout << hasilBagi << " Lembar Rp " << pecahan[i] << endl;

                for (int j = 0; j < 9; j++){
                    int uangLebih = uang % pecahan[j];

                    if (uangLebih > 0){

                        for (int k = 0; k < 9; k++){
                            int banyakUangLebih = uangLebih / pecahan[k];
                            // 
                            if (banyakUangLebih > 0){
                                cout << banyakUangLebih << " Lembar Rp " << pecahan[k] << endl;
                                break;
                            } else if (banyakUangLebih > 0 && pecahan[k] < 1000){
                                cout << banyakUangLebih << " Keping Koin Rp " << pecahan[k] << endl;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
*/

/*
    TUGAS 1 - ALGORITMA PEMROGRAMAN LANJUT

    Menampilkan hasil searching data duplikat yang berurutan - Menggunakan Binary Search
    
*/

#include <iostream>
using namespace std;

void menu(){
    system("CLS");

    cout << "\n+===========================+" << endl;
    cout << "|  NAMA  : Gega Ramadhan    |" << endl;
    cout << "|  NIM   : 123250112        |" << endl;
    cout << "|  KELAS : IF-C             |" << endl;
    cout << "+===========================+" << endl;

    cout << "\n---------------[TUGAS 1 ALGORTIMA PEMROGRAMAN LANJUT]---------------" << endl;
    cout << "Menampilkan hasil searching data duplikat yang berurutan - Binary Search" << endl;
}

void tugas(){
    int dataAngka[13] = {1,2,3,4,5,6,6,7,7,7,8,9,10};
    bool found = false;
    int indexKiri = 0;
    int indexKanan = 12;
    int mid;
    int dataDicari;
    int posisiketemu;

    cout << "\n---> Masukkan Data Yang Dicari : ";
    cin >> dataDicari;

    while (!found && indexKiri <= indexKanan){

        mid = (indexKiri + indexKanan) / 2;

        if (dataDicari == dataAngka[mid]){
            posisiketemu = mid;
            found = true;
        } else {
            if (dataDicari < dataAngka[mid]){
                indexKanan = mid - 1;
            } else if (dataDicari > dataAngka[mid]){
                indexKiri = mid + 1;
            }
        }
    }

    if (found) {
        if (posisiketemu != false){
            int batasKiriAngka = posisiketemu;
            while (batasKiriAngka > 0 && dataAngka[batasKiriAngka - 1] == dataDicari){
                batasKiriAngka--;
            }

            int batasKananAngka = posisiketemu;
            while (batasKananAngka < indexKanan && dataAngka[batasKananAngka + 1] == dataDicari){
                batasKananAngka++;
            }

            for (int i = batasKiriAngka; i <= batasKananAngka; i++){
                cout << "Data Ditemukan dalam index ke -"  << i << endl;
            }
        } else {
            cout << "Data Ditemukan dalam index ke -"  << mid << endl;
        }
    
    } else {
        cout << "Data Tidak Ditemukan" << endl;
    }
}

int main(){
    
    menu();
    tugas();

    return 0;
}
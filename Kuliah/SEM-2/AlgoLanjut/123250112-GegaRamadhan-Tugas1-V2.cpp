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
    
    cout << "\n1. Masukkan banyak data yang akan di input : ";
    int banyakDataAngka;
    cin >> banyakDataAngka;
    
    int dataAngka[banyakDataAngka];

    cout << "\n2. Masukkan data-data Anda : " << endl;
    
    for (int i = 0; i < banyakDataAngka; i++){
        cout << "   - Data ke-" << i+1 << " : ";
        cin >> dataAngka[i];
    }

    for (int i = 0; i < banyakDataAngka; i++){
        for (int j = 1; j < banyakDataAngka; j++){
            if (dataAngka[j-1] > dataAngka[j]){
                int temp = dataAngka[j-1];
                dataAngka[j-1] = dataAngka [j];
                dataAngka[j] = temp;
            }
        }
    }

    cout << "\n3. Hasil sorting data-data Anda : " << endl;
    for (int i = 0; i < banyakDataAngka; i++){
        cout << "   - Data ke-" << i+1 << " : " << dataAngka[i] << endl;
    }


    bool found = false;
    int indexKiri = 0;
    int indexKanan = banyakDataAngka - 1;
    int mid;
    int dataDicari;
    int posisiKetemu;

    cout << "\n4. Masukkan data yang Anda cari : ";
    cin >> dataDicari;

    while (!found && indexKiri <= indexKanan){

        mid = (indexKiri + indexKanan) / 2;

        if (dataDicari == dataAngka[mid]){
            posisiKetemu = mid;
            found = true;
        } else {
            if (dataDicari > dataAngka[mid]){
                indexKiri = mid + 1;
            } else if (dataDicari < dataAngka[mid]){
                indexKanan = mid - 1;
            }
        }
    }

    if (found){

        int batasKiriAngkaSama = posisiKetemu;
        while (batasKiriAngkaSama > 0 && dataAngka[batasKiriAngkaSama-1] == dataDicari){
            batasKiriAngkaSama--;
        }

        int batasKananAngkaSama = posisiKetemu;
        while (batasKananAngkaSama < banyakDataAngka - 1 && dataAngka[batasKananAngkaSama+1] == dataDicari){
            batasKananAngkaSama++;
        }

        for (int i = batasKiriAngkaSama; i <= batasKananAngkaSama; i++){
            cout << "---> Data ditemukan pada index ke-" << i << endl;
        }

    } else {
        cout << "\n---> Data Tidak Ditemukan..." << endl;
    }
};

int main(){
    
    menu();
    tugas();

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Materi Searching
        1. Sequential Non-Sentinal
            - iterasi dari 1 sampai n
            - dibandingkan dengan data yang dicari (1 per 1)
            - kalau ketemu ya dieksekusi, kalau engga juga dikasih penjelasan



*/ 

void searchingNonSentinel(){
    int nilaiDicari;
    int dataAngka[10] = {
        55,3,89,67,27,48,49,9,99,157
    };

    cout << "==========[ Searching Non-Sentinel ]==========" << endl;
    cout << "Masukkan Nilai yang dicari : ";
    cin >> nilaiDicari;

    for(int i = 0; i < 10; i++){
        if (dataAngka[i] == nilaiDicari){
            cout << "---> Nilai Ditemukan pada index ke-" << dataAngka[i] << endl;
            return;
        } else {
            cout << "---> Nilai Tidak Ditemukan " << endl;
            return;
        }
    }
}

void binarySearch(){

    int nilaiDicari;
    int dataAngka[10] = {
            55,3,89,67,27,48,49,9,99,157
        };
    int index_first = 0;
    int index_last = 10;
    int mid;
    bool found = false;

    cout << "==========[ Searching Binary ]==========" << endl;
    cout << "Masukkan Nilai yang dicari : ";
    cin >> nilaiDicari;

    // ketika found masih false dan index_first masih lebih kecil dari index_last
    while ((!found) && (index_first <= index_last)){
        
        // nilai tengah adalah (first + last) / 2
        mid = (index_first + index_last) / 2;

        // Kondisi jika nilai tengah itu adalah nilai dicari
        if (nilaiDicari == dataAngka[mid]){
            found = true;
        // jika nilai tengah bukan yang dicari maka masuk ke else
        } else {
            // jika nilai dicari < dataangka dengan index menggunakan mid 
            if (nilaiDicari < dataAngka[mid]){
                // maka index lastnya adalah mid baru - 1
                // sehingga akan membuang yang > dari dataangka
                index_last = mid-1;
            // jika lainnya 
            } else {
                // maka index pertama yang di modifikasi menggunakan mid+1
                // sehingga akan membuang yang akhir
                index_first = mid+1;
            }
        }
    }

    if (found){
        cout << "---> Nilai Ditemukan pada index ke-" << mid+1 << endl;
    } else {
        cout << "---> Nilai tidak ditemukan!" << endl;
    }
    
}

void tugas(){
    system("CLS");

    int nilaiDicari;
    int banyakData;
    int index_first = 0;
    int mid;
    bool found = false;
    
    cout << "\n==========[ Tugas Sort + Searching Binary ]==========" << endl;
    cout << "\nMasukkan Banyak Nilai yang di Input : ";
    cin >> banyakData;

    int dataAngka[banyakData];
    int index_last = banyakData;

    cout << "\nMasukkan Data Nilai                 : " << endl;
    for (int i = 0; i < banyakData; i++){
        cout << i+1 << ". Data Ke-" << i+1 << " : ";
        cin >> dataAngka[i];    
    }
    
    cout << "\nMasukkan Nilai yang dicari          : ";
    cin >> nilaiDicari;

    sort (dataAngka, dataAngka + banyakData);

    while ((!found) && (index_first <= index_last)){
        
        mid = (index_first + index_last) / 2;

        if (nilaiDicari == dataAngka[mid]){
            found = true;
        } else {
            
            if (nilaiDicari < dataAngka[mid]){
                index_last = mid-1;
            } else {
                index_first = mid+1;
            }
        }
    }

    if (found){
        cout << "\n---> Nilai Ditemukan pada index ke-" << mid+1 << endl;
    } else {
        cout << "\n---> Nilai tidak ditemukan!" << endl;
    }
}

int main(){
    // searchingNonSentinel();
    // binarySearch();
    tugas();

    return 0;
}
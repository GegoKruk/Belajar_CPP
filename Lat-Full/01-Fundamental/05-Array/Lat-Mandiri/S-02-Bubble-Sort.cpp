#include <iostream>
#include <string>
using namespace std;

/*
    S-02: Formasi Barisan Paskibra (Bubble Sort)
    
    Konteks:
        Kamu adalah seorang komandan Paskibra. Ada 7 anggota baru yang tingginya masih acak-acakan. 
        Agar terlihat rapi saat upacara, kamu harus mengurutkan mereka mulai dari yang paling pendek ke yang paling tinggi (Ascending).

    Tugas:
        Buatlah array 1D berisi 7 angka (integer) yang merepresentasikan tinggi badan anggota (misal: 170, 165, 180, 160, 172, 168, 175).
        Implementasikan algoritma Bubble Sort untuk mengurutkan tinggi badan tersebut.
        
    Penting: 
        Untuk setiap "putaran" (pass) perulangan luar, tampilkan kondisi array saat itu. 
        Ini supaya kamu bisa melihat bagaimana angka yang besar pelan-pelan "tenggelam" atau "mengapung" ke posisi belakang seperti gelembung.
        Tampilkan hasil akhir barisan yang sudah rapi.
*/

void soal3(){
    cout << "\n==========[SOAL 3 - BUBBLE SORT]==========" << endl;
    
    int jumlahAnggota = 0;
    cout << "\nMasukkan Jumlah Anggota : ";
    cin >> jumlahAnggota;
    
    cout << "\nMasukkan Data Tinggi Badan : " << endl;
    int tbAnggota[jumlahAnggota] = {};
    for (int i = 0; i < jumlahAnggota; i++){
        cout << "\tAnggota ke-" << i+1 << " : ";
        cin >> tbAnggota[i];
    }
    
    cout << "\nDaftar Tinggi Badan (Belum Urut) : " << endl;
    for (int i = 0; i < jumlahAnggota; i++){
        cout << "\tAnggota ke-" << i+1 << " : " << tbAnggota[i] << endl;
    }

    //Bubble Sort
    int temp;
    for (int i = 0; i < jumlahAnggota - 1; i++){
        for (int j = 0; j < jumlahAnggota - 1; j++) {
            if(tbAnggota[j] > tbAnggota[j+1]){
                temp = tbAnggota[j];
                tbAnggota[j] = tbAnggota[j+1];
                tbAnggota[j+1] = temp;
            }
        }
    }
    
    cout << "\nDaftar Tinggi Badan (Sudah Urut) : " << endl;
    for (int i = 0; i < jumlahAnggota; i++){
        cout << "\tAnggota ke-" << i+1 << " : " << tbAnggota[i] << endl;
    }
}

int main(){

    soal3();

    return 0;
}
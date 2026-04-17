#include <iostream>
#include <string>
using namespace std;

/*
    S-05: Merapikan Skor Game (Insertion Sort)
    Konteks:
        Kamu sedang membangun sebuah papan skor (leaderboard) untuk sebuah game mobile. 
        Setiap kali ada pemain yang selesai bermain, skor mereka masuk ke daftar. 
        Karena kamu ingin menampilkan skor dari yang terendah ke tertinggi (untuk kategori pemain pemula), 
        kamu menggunakan Insertion Sort.

    Tugas:
        Buatlah array berisi 8 skor acak (misal: 500, 200, 700, 100, 400, 300, 600, 800).
        Implementasikan algoritma Insertion Sort:
        Ambil satu angka (sebut saja key).
        Bandingkan dengan angka-angka di sebelah kirinya yang sudah "terurut".
        Geser angka-angka yang lebih besar ke kanan untuk memberi ruang bagi si key.
        Sisipkan key ke tempat yang kosong tersebut.
        Wajib: 
            Tampilkan pesan "Menyisipkan skor [X] ke posisi yang benar" di setiap langkah perulangan luar.
        Tampilkan hasil akhir papan skor yang sudah urut.

    Tips Logika Insertion Sort:
        Berbeda dengan dua algoritma sebelumnya yang pakai dua for, 
        Insertion Sort paling enak pakai kombinasi for (untuk jalan ke depan) dan while (untuk mundur sambil menggeser angka).

        key: Angka yang sedang kita pegang untuk dicari rumah barunya.
        j: Indeks yang berjalan mundur ke kiri untuk mengecek "siapa yang lebih besar dari si key?".

        Selama data[j] > key, maka data[j+1] = data[j] (geser ke kanan).
*/


void soal5(){
    cout << "\n==========[SOAL 5 - INSERTION SORT]==========" << endl;
    
    int skor[8] {500, 200, 700, 100, 400, 300, 600, 800};
    int n = sizeof(skor) / sizeof(skor[0]);

    cout << "\n1. Data Sebelum Sorting : " << endl;
    for (int i = 0; i < n; i++){
        cout << "\t- " << skor[i] << endl;
    }

    //Proses Insertion Short
    cout << "\n2. Proses Pengurutan (insertion Sort)" << endl;
    for (int i = 1; i < n; i++){
        
        int key = skor[i];
        int j = i - 1;

        while(j >= 0 && skor[j] > key){
            skor[j + 1] = skor[j];
            j--;
        }

        skor[j+1]  = key;
        
        cout << "\t- Menyisipkan skor : (" << key << ") ke posisi yang benar" << endl;
    }
    
    cout << "\n1. Data Setelah Sorting : " << endl;
    for (int i = 0; i < n; i++){
        cout << "\t- " << skor[i] << endl;
    }
}

int main(){

    soal5();

    return 0;
}
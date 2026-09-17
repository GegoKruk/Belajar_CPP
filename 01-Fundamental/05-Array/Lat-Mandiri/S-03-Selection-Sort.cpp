#include <iostream>
#include <string>
using namespace std;

/*
    S-04: Pengurutan Rak Buku Perpustakaan (Selection Sort)
    
    Konteks:
        Kamu adalah seorang pustakawan. Ada sebuah rak buku khusus yang berisi 6 buku dengan nomor seri (integer) yang berantakan. 
        Untuk memudahkan pengunjung, kamu ingin mengurutkan nomor seri ini dari yang terkecil ke terbesar (Ascending) menggunakan metode Selection Sort.

    Tugas:
        - Buatlah array berisi 6 nomor seri buku (misal: 45, 12, 89, 5, 23, 67).
        - Implementasikan algoritma Selection Sort:
        - Cari nomor seri paling kecil di seluruh rak.
        - Tukar nomor terkecil tersebut dengan buku yang ada di posisi paling depan (index ke-i).
        - Wajib: 
            Tampilkan nomor seri buku yang terpilih sebagai "terkecil" di setiap putaran sebelum ditukar.
        - Tampilkan hasil akhir rak buku yang sudah rapi.

    Tips Logika Selection Sort:
        - Dalam kodingannya nanti, kamu butuh variabel tambahan, biasanya namanya posMin (posisi minimum).
        - Putaran luar (i) menentukan "target" tempat kita mau naruh angka terkecil.
        - Putaran dalam (j) bertugas keliling sisa array buat nyari siapa yang paling kecil.
        - Setelah putaran dalam selesai, baru lakukan sekali swap antara data[i] dengan data[posMin].
*/


const int jumlahBuku = 6;
int noSeri[jumlahBuku] = {
    45,12,89,5,23,67
};

void swapNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void soal4(){
    cout << "\n==========[SOAL 3 - SELECTION SORT]==========" << endl;
    
    cout << "\nData Sebelum Sorting : " << endl;
    for (int i = 0; i < jumlahBuku; i++){
        cout << "\tBuku " << i+1 << " : " << noSeri[i] << endl;
    }
    
    //Selection Sort

    for (int i = 0; i < jumlahBuku-1; i++){
        
        int indexMin = i;
        for (int j = i+1; j < jumlahBuku ; j++){
            if (noSeri[j] < noSeri[indexMin]){
                indexMin = j;
            }
            
        }

        //proses Tukar
        if (indexMin != i) {
            swapNilai(noSeri[i], noSeri[indexMin]);
        }
        
        
    }
    
    cout << "\nData Setelah Sorting : " << endl;
    for (int i = 0; i < jumlahBuku; i++){
        cout << "\tBuku " << i+1 << " : " << noSeri[i] << endl;
    }
    

}

int main(){

    soal4();

    return 0;
}
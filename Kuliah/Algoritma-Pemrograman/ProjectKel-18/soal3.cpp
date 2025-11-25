#include <iostream>
using namespace std;

// Soal 2
/*
    Buatlah program dari data array berikut untuk menghitung jumlah dan rata-rata nilai 
    yang lebih kecil dari 5 atau lebih besar sama dengan 7
    
    Dengan ketentuan :
    (1) data array dideklarasikan di procedure/function
    (2) proses menghitung di procedure/function
    (3) hasil jumlah dan rata-rata ditampilkan di program utama (main program)
    
    Berikut data arraynya:
        _________________________________________
        | 2 | 5 | 1 | 2 | 4 | 6 | 3 | 2 | 7 | 1 |
        
*/

void nimNama(){
    system("CLS");

    cout << "--------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan         |" << endl;
    cout << "| NIM  : 123250112             |" << endl;
    cout << "--------------------------------" << endl;
}

float penghitung(){
    // Data Array Nilai
    int nilai[10] = {2,5,1,2,4,6,3,2,7,1};
    float totalNilaiTersaring = 0;
    int banyakNilaiTersaring = 0;
    float nilaiRata;
    
    // Menampilkan Data Nilai
    cout << "1. Data Nilai: " ;
    
    for(int i = 0; i < 10; i++){
        
        cout << nilai[i] << " ";
        
        // Seleksi mencari data yang < 5 dan >= 7
        if(nilai[i] < 5 || nilai[i] >= 7){
            totalNilaiTersaring += nilai[i];
            banyakNilaiTersaring++;
        } 
    }

    nilaiRata = totalNilaiTersaring / banyakNilaiTersaring;

    cout << "\n2. Banyak data yang bernilai < 5 dan >= 7 adalah: " << banyakNilaiTersaring << endl;

    return nilaiRata;
}

int main(){
    // Tampilkan Nama & NIM
    nimNama();

    // Judul Program
    cout << "\n=====[Program Penghitung Nilai Rata-Rata]=====" << endl;

    // Memanggil Function & masuk ke variabel
    float hasil = penghitung();

    // Menampilkan Hasil Akhir
    cout << "3. Rata-rata dari nilai yang < 5 dan >= 7 adalah: " << hasil << endl;
}
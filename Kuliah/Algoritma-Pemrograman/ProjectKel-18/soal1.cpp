#include <iostream>
using namespace std;

// Soal 1
/*
    Buatlah program untuk menginputkan 10 nilai ujian mahasiswa (simpan dalam array), 
    mencari dan menampilkan nilai tertinggi yang didapat mahasiswa dan juga berapa orang 
    yang mendapat nilai tertinggi tersebut. 
    
    (catatan: untuk perulangan menggunakan sintaks while)
    
    Misal : 
        nilai-nilai yang diinput :
        60 75 85 60 85 64 77 85 76 55

        Hasil : 

        Nilai tertinggi = 85
        Banyaknya mahasiswa memiliki nilai tertinggi = 2
*/

void nimNama(){
    system("CLS");

    cout << "--------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan         |" << endl;
    cout << "| NIM  : 123250112             |" << endl;
    cout << "--------------------------------" << endl;
}

int nilaiUjian[10];
int nilaiTertinggi = 0;
int banyakNilaiTertinggi = 0;

int main(){

    // Tampilkan Nama & NIM
    nimNama();

    cout << "\n==========[Program Nilai Mahasiswa]==========" << endl;

    //Input nilai
    cout << "1. Input Nilai Mahasiswa" << endl;

    int noMhs = 0;
    while(noMhs < 10){
        cout << "   - Masukkan Nilai Mahasiswa [" << noMhs + 1 << "]: ";
        cin >> nilaiUjian[noMhs];

        if(nilaiUjian[noMhs] < 1 || nilaiUjian[noMhs] > 100){//error handling bila input di luar range
            cout << "\n=====[Input Tidak Valid - Program Selesai]=====" << endl;
            noMhs = 0;
            exit(0);
        } else if(nilaiUjian[noMhs] > nilaiTertinggi){ //Mencari nilai tertinggi
            nilaiTertinggi = nilaiUjian[noMhs];
        }

        noMhs++;
    }

    //Mencari banyak mahasiswa yang meraih nilai tertinggi
    noMhs = 0;
    while(noMhs < 10){
        
        if(nilaiTertinggi == nilaiUjian[noMhs]){
            banyakNilaiTertinggi++;
        }

        noMhs++;
    }
    
    cout << "\n2. Nilai Tertinggi : " << nilaiTertinggi << endl;
    cout << "3. Banyak Mahasiswa yang Meraih Nilai Tertinggi : " << banyakNilaiTertinggi << endl;
}
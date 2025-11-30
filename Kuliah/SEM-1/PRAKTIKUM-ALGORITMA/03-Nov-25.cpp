#include <iostream>
using namespace std;

// Program Menghitung Nilai Rata-rata Mahasiswa
/*
    Kamu diminta bikin program yang bisa menghitung rata-rata nilai mahasiswa.
    User bisa terus memasukkan nilai satu per satu
    kalau mau berhenti cukup ketik "stop".
    Program akan menampilkan total nilai, jumlah mata kuliah, dan rata-ratanya
*/

double totalNilai;
int totalMatakuliah;
int main();

float inputNilai(){
    string inputNilai;
    
    cout << "[Input Nilai Mahasiswa]______" << endl;
    
    for ( int i = 1; ; i++){
        cout << "Masukkan Nilai Mahasiswa "<< i << ": ";
        cin >> inputNilai;

        //if(inputNilai == 'stop' ){
            main();
        } 
        
        //inputNilai.to
        //totalNilai += inputNilai;
        //totalMatakuliah = i;
        
        
        cin.ignore();
    }
    
    
    //return totalNilai;
    //return totalMatakuliah;
}

float hasil(){
    float rataRata;

    return 0;
}

int main(){
    int pilihanMenu;

    do {
        cout << "[Program Penghitung Rata-rata Nilai Mahasiswa]_______________" << endl;
        cout << "| 1. Input Nilai Mahasiswa                                  |" << endl;
        cout << "| 2. Cek Hasil                                              |" << endl;
        cout << "| 3. Keluar                                                 |" << endl;
        cout << "|___________________________________________________________|" << endl;
        cout << "Pilih : ";
        cin >> pilihanMenu;
    
        if (pilihanMenu == 1){
            inputNilai();
        } else if (pilihanMenu == 2){
            hasil();
        }

    } while (pilihanMenu != 3);
}

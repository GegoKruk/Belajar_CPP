#include <iostream>
#include <string>
using namespace std;

void soal7();
void cekData();
void urutkanData();
void cariData();
void dataMax();
void dataMin();
void dataRataRata();

void garis(){
    cout << "\n==========[SOAL 7 - SISTEM MANAJEMEN SEKOLAHAN (MAX, MIN, MEAN, SORTING, & SEARCHING)]==========" << endl;
}

const int maxJmlNilai = 100;
int nilai[maxJmlNilai] {};
int jmlNilai = 0;
int totalNilai = 0;
double rataRata = 0;


void inputData(){
    system("CLS");
    garis();
    cout << "\n[INPUT DATA NILAI]__________" << endl;
    cout << "1. Masukkan jumlah siswa : ";
    cin >> jmlNilai;
    
    if(jmlNilai > maxJmlNilai){
        jmlNilai = maxJmlNilai;
    }

    cout << "\n2. Masukkan semua data nilai siswa : " << endl;
    for(int i = 0; i < jmlNilai; i++){
        cout << "\tNilai (" << i+1 << ") : ";
        cin >> nilai[i];
    }

    cout << "\n[Selesai] - Ketik apapun untuk kembali ke menu : ";
    cin.get();
    if(cin.get()){
        soal7();
    }
};

void cekData(){
    system("CLS");
    garis();

    if(jmlNilai == 0) {
        cout << "\n[!] Data masih kosong. Silakan input dulu." << endl;
        cout << "\n\tKetik apapun untuk kembali ke menu :" << endl;
        cin.get();
        if(cin.get()){
            soal7();
        }
    }

    cout << "\n[CEK DATA NILAI]__________" << endl;
    for(int i = 0; i < jmlNilai; i++){
        cout << "   " << i+1 << ". Nilai Siswa : " << nilai[i] << endl;
    }

    cout << "\n[Selesai] - Ketik apapun untuk kembali ke menu : ";
    cin.get();
    if(cin.get()){
        soal7();
    }

};

void urutkanData(){
    system("CLS");
    garis();
    cout << "\n[URUTKAN DATA NIAI]__________" << endl;

    if(jmlNilai == 0) {
        cout << "\n[!] Data masih kosong. Silakan input dulu." << endl;
        cout << "\n\tKetik apapun untuk kembali ke menu :" << endl;
        cin.get();
        if(cin.get()){
            soal7();
        }
    }

    cout << "\tData Dalam Proses Pengurutan..." << endl;
    for(int i = 0; i < jmlNilai - 1; i++){
        for(int j = 0; j < jmlNilai - 1 - i; j++){
            if(nilai[j] > nilai[j+1]){
                int temp = nilai[j];
                nilai[j] = nilai[j+1];
                nilai[j+1] = temp;
            }
        }
    }
    cout << "\n\t[Selesai] - Data telah diurutkan, pilih (2) di menu awal : ";
    cin.get();
    if(cin.get()){
        soal7();
    }

};

void cariData(){
    system("CLS");
    garis();
    cout << "\n[CARI DATA NILAI]__________" << endl;
    
    if(jmlNilai == 0) {
        cout << "[!] Input data dulu di menu 1!" << endl;
        return; 
    }

    int dicari;
    cout << "1. Masukkan nilai siswa yang dicari : ";
    cin >> dicari;
    
    bool found = false;
    int idxAwal = 0;
    int idxAkhir = jmlNilai - 1;
    int posisi;

    while(idxAwal <= idxAkhir){
        int mid = idxAwal + (idxAkhir - idxAwal) / 2; 

        if(nilai[mid] == dicari){
            posisi = mid;
            found = true; 
            break;
        } else if(nilai[mid] > dicari){
            idxAkhir = mid - 1;
        } else {
            idxAwal = mid + 1;
        }
    }

    if (found){
        cout << "\n[DITEMUKAN] Nilai " << dicari << " ada di index ke-" << posisi << endl;
    } else {
        cout << "\n[TIDAK ADA] Nilai " << dicari << " tidak ditemukan di gudang." << endl;
    }

    cin.ignore(); 
    cout << "\nKetik apapun untuk kembali : ";
    cin.get();
    soal7();
};

void dataMax(){
    system("CLS");
    garis();
    cout << "\n[CARI DATA MAX]__________" << endl;

    if(jmlNilai == 0) {
        cout << "[!] Input data dulu di menu 1!" << endl;
        return; 
    }

    int nilaiMax = 0;
    int posisi;
    for(int i = 0; i < jmlNilai; i++){
        if (nilai[i] > nilaiMax){
            nilaiMax = nilai[i];
            posisi = i;
        }
    }

    cout << "\n[DITEMUKAN] nilai max : " << nilaiMax << " berada di index ke-" << posisi << endl;


    cin.ignore(); 
    cout << "\nKetik apapun untuk kembali : ";
    cin.get();
    soal7();
};

void dataMin(){
    system("CLS");
    garis();
    cout << "\n[CARI DATA MIN]__________" << endl;

    if(jmlNilai == 0) {
        cout << "[!] Input data dulu di menu 1!" << endl;
        return; 
    }

    int nilaiMin = nilai[0];
    int posisi = 0;
    for(int i = 1; i < jmlNilai ; i++){
        if (nilai[i] < nilaiMin){
            nilaiMin = nilai[i];
            posisi = i;
        }
    }

    cout << "\n[DITEMUKAN] nilai max : " << nilaiMin << " berada di index ke-" << posisi << endl;


    cin.ignore(); 
    cout << "\nKetik apapun untuk kembali : ";
    cin.get();
    soal7();
};

void dataRataRata(){
    system("CLS");
    garis();
    cout << "\n[CARI RATA-RATA NILAI]__________" << endl;

    if(jmlNilai == 0) {
        cout << "[!] Input data dulu di menu 1!" << endl;
        return; 
    }

    totalNilai = 0;
    for(int i = 0; i < jmlNilai; i++){
        totalNilai += nilai[i];
    }

    rataRata = (double)totalNilai / jmlNilai;

    cout << "\n[NILAI RATA-RATA] : " << totalNilai << " / " << jmlNilai << endl;
    cout << "\n                  : " << rataRata  << endl;


    cin.ignore(); 
    cout << "\nKetik apapun untuk kembali : ";
    cin.get();
    soal7();
};


void soal7(){

    system("CLS");
    garis();

    cout << "\n[SISTEM MANAJEMEN SEKOLAHAN]---------------+" << endl;
    cout << "| 1. Input Data Nilai                     |" << endl;
    cout << "| 2. Cek Data Nilai                       |" << endl;
    cout << "| 3. Urutkan Data Nilai                   |" << endl;
    cout << "| 4. Cari Data Nilai                      |" << endl;
    cout << "| 5. Data Nilai Max                       |" << endl;
    cout << "| 6. Data Nilai Min                       |" << endl;
    cout << "| 7. Nilai rata-rata                      |" << endl;
    cout << "| 8. Exit                                 |" << endl;
    cout << "+-----------------------------------------+" << endl;

    int pilihanMenuAwal;
    cout << "Pilih : ";
    cin >> pilihanMenuAwal;

    switch(pilihanMenuAwal){
        case 1 : inputData();
            break;
        case 2 : cekData();
            break;
        case 3 : urutkanData();
            break;
        case 4 : cariData();
            break;
        case 5 : dataMax();
            break;
        case 6 : dataMin();
            break;
        case 7 : dataRataRata();
            break;
        case 8 : cout << "\n---> [Program Selesai] - Sampai Jumpa Lagi!" << endl;
            break;
    }
}

int main(){

    soal7();

    return 0;
}
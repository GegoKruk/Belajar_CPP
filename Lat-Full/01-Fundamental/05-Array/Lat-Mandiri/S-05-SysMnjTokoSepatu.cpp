#include <iostream>
#include <string>
using namespace std;

/*
    S-06: Sistem Manajemen Toko Sepatu (Sorting & Searching)

    Konteks:
        Kamu sedang membuat program untuk gudang toko sepatu. 
        Toko ini memiliki stok sepatu dengan ukuran yang acak. 
        Admin gudang ingin agar data sepatu tersebut diurutkan terlebih dahulu supaya rapi, 
        lalu admin bisa mencari apakah ukuran tertentu tersedia di gudang atau tidak.

    Tugas:
        Input: 
            Mintalah user memasukkan berapa banyak sepatu yang baru datang (n).

        Data: 
            Masukkan ukuran-ukuran sepatu tersebut ke dalam array (misal: 42, 38, 40, 44, 39, 41).

        - Sorting (Pilih Salah Satu): Gunakan Selection Sort atau Insertion Sort untuk mengurutkan ukuran sepatu dari yang terkecil ke terbesar.
        - Searching (Binary Search): Setelah data urut, mintalah user memasukkan ukuran sepatu yang ingin dicari. Gunakan Binary Search untuk menemukannya.
        - Output: * Tampilkan array sebelum diurutkan.

        Tampilkan array setelah diurutkan.
        Tampilkan posisi (indeks) sepatu yang dicari atau pesan "Stok Tidak Tersedia" jika tidak ada.
*/

void menuAwal();
void inputData();
void cekData();
void urutkanData();
void cariData();

void garis(){
    cout << "\n_____________[SISTEM MANAJEMEN TOKO SEPATU]_____________" << endl;
}

const int MAX_SEPATU = 100; 
int rakSepatu[MAX_SEPATU]; 
int jmlSepatuSekarang = 0;

void inputData() {
    system("CLS");
    garis();
    cout << "\n[INPUT DATA SEPATU]__________" << endl;
    cout << "1. Masukkan jumlah sepatu baru : ";
    cin >> jmlSepatuSekarang;
    
    if(jmlSepatuSekarang > MAX_SEPATU){
        jmlSepatuSekarang = MAX_SEPATU;
    }

    cout << "\n2. Masukkan semua data ukuran sepatu : " << endl;
    for(int i = 0; i < jmlSepatuSekarang; i++){
        cout << "\tSepatu (" << i+1 << ") : ";
        cin >> rakSepatu[i];
    }

    cout << "\n[Selesai] - Ketik apapun untuk kembali ke menu : ";
    cin.get();
    if(cin.get()){
        menuAwal();
    }
}

void cekData(){
    system("CLS");
    garis();

    if(jmlSepatuSekarang == 0) {
        cout << "\n[!] Data masih kosong. Silakan input dulu." << endl;
        cout << "\n\tKetik apapun untuk kembali ke menu :" << endl;
        cin.get();
        if(cin.get()){
            menuAwal();
        }
    }

    cout << "\n[CEK DATA SEPATU]__________" << endl;
    for(int i = 0; i < jmlSepatuSekarang; i++){
        cout << i+1 << ". Ukuran Sepatu: " << rakSepatu[i] << endl;
    }

    cout << "\n[Selesai] - Ketik apapun untuk kembali ke menu : ";
    cin.get();
    if(cin.get()){
        menuAwal();
    }
}

void urutkanData(){
    system("CLS");
    garis();
    cout << "\n[URUTKAN DATA SEPATU]__________" << endl;

    if(jmlSepatuSekarang == 0) {
        cout << "\n[!] Data masih kosong. Silakan input dulu." << endl;
        cout << "\n\tKetik apapun untuk kembali ke menu :" << endl;
        cin.get();
        if(cin.get()){
            menuAwal();
        }
    }

    cout << "\tData Dalam Proses Pengurutan..." << endl;
    for(int i = 0; i < jmlSepatuSekarang - 1; i++){
        for(int j = 0; j < jmlSepatuSekarang - 1 - i; j++){
            if(rakSepatu[j] > rakSepatu[j+1]){
                int temp = rakSepatu[j];
                rakSepatu[j] = rakSepatu[j+1];
                rakSepatu[j+1] = temp;
            }
        }
    }
    cout << "\n\t[Selesai] - Data telah diurutkan, pilih (2) di menu awal : ";
    cin.get();
    if(cin.get()){
        menuAwal();
    }
}

void cariData(){
    system("CLS");
    garis();
    cout << "\n[CARI DATA SEPATU]__________" << endl;
    
    if(jmlSepatuSekarang == 0) {
        cout << "[!] Input data dulu di menu 1!" << endl;
        return; 
    }

    int dicari;
    cout << "1. Masukkan ukuran sepatu yang dicari : ";
    cin >> dicari;
    
    bool found = false;
    int idxAwal = 0;
    int idxAkhir = jmlSepatuSekarang - 1;
    int posisi;

    while(idxAwal <= idxAkhir){
        int mid = idxAwal + (idxAkhir - idxAwal) / 2; 

        if(rakSepatu[mid] == dicari){
            posisi = mid;
            found = true; 
            break;
        } else if(rakSepatu[mid] > dicari){
            idxAkhir = mid - 1;
        } else {
            idxAwal = mid + 1;
        }
    }

    if (found){
        cout << "\n[DITEMUKAN] Ukuran " << dicari << " ada di index ke-" << posisi << endl;
    } else {
        cout << "\n[TIDAK ADA] Ukuran " << dicari << " tidak ditemukan di gudang." << endl;
    }

    // Pembersih buffer agar cin.get() tidak terlewat
    cin.ignore(); 
    cout << "\nKetik apapun untuk kembali : ";
    cin.get();
    menuAwal();
}

void menuAwal(){
    system("CLS");
    garis();

    cout << "\n[SISTEM MANAJEMEN TOKO SEPATU]_____________" << endl;
    cout << "| 1. Input Data Sepatu                     |" << endl;
    cout << "| 2. Cek Data Sepatu                       |" << endl;
    cout << "| 3. Urutkan Data Sepatu                   |" << endl;
    cout << "| 4. Cari Data Sepatu                      |" << endl;
    cout << "| 5. Exit                                  |" << endl;
    cout << "|__________________________________________|" << endl;

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
        case 5 : cout << "\n---> [Program Selesai] - Sampai Jumpa Lagi!" << endl;
            break;
    }
}

void soal6(){

    system("CLS");
    cout << "\n==========[SOAL 6 - SISTEM MANAJEMEN TOKO SEPATU (SORTING & SEARCHING)]==========" << endl;

    char pilihanMulai;
    cout << "\n---> Mulai Program? (Y/N) : ";
    cin >> pilihanMulai;

    if (pilihanMulai == 'Y' || pilihanMulai == 'y'){
        menuAwal();
    } else {
        cout << "\n---> [Program Selesai] - Sampai Jumpa Lagi!" << endl;
        exit(0); 
    } 
}

int main(){

    soal6();

    return 0;
}
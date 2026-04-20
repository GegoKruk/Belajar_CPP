#include <iostream>
#include <string>
using namespace std;

/*
    S-07: Sistem Portofolio Investasi Emas (Multi-User & Multi-Asset)
    
    Konteks:
        Kamu ingin membuat program untuk mencatat investasi emas beberapa pengguna. 
        Program ini menggunakan Array 2D untuk menyimpan data transaksi selama satu minggu (7 hari).

    Tugas:

        Struktur Data:
            - Gunakan string namaUser[3] untuk menyimpan nama 3 investor.
            - Gunakan double tabunganEmas[3][7] (Array 2D). 
                Baris adalah User, Kolom adalah Hari (Senin-Minggu). 
                Isi datanya adalah jumlah gram emas yang mereka beli setiap harinya.

        Fitur Program:
            - Input Data: 
                Masukkan jumlah beli emas (gram) untuk setiap user selama 7 hari.
            - Statistik Individu: 
                Hitung total akumulasi emas dan rata-rata pembelian per hari untuk setiap user.
            - Ranking Investor (Sorting): 
                Urutkan nama user berdasarkan total emas terbanyak (Gunakan Selection atau Insertion Sort).
            - Hari Terproduktif (Max): 
                Cari di hari ke-berapa (kolom mana) pembelian emas tertinggi terjadi secara global (gabungan semua user).
            - Pencarian (Search): 
                Masukkan angka gram, lalu cari apakah ada user yang pernah membeli emas tepat di angka tersebut. Jika ada, tampilkan nama user dan harinya.

    Kenapa Soal Ini Kompleks?
        Akses 2D: Kamu harus mahir menggunakan nested loop for(i...) { for(j...) }.
        Relasi Data: Saat kamu melakukan sorting pada total emas, kamu juga harus menukar posisi nama di namaUser[] agar data tetap sinkron (tidak tertukar).
        Logika Global: Mencari nilai maksimal di seluruh isi tabel (2D) menuntut ketelitian indeks.

    Tips Implementasi:
        Karena kamu sudah bisa pakai system("CLS") dan switch case, buatlah menu yang interaktif seperti di S-06.
        Gunakan konstanta untuk ukuran array agar mudah diubah, misal: const int JML_USER = 3; dan const int JML_HARI = 7;.

*/


void soal8();
void inputData();
void statistik();
void ranking();
void hariProduktif();
void pencarian();

const int MAX_USER = 5;
const int JML_HARI = 7;
int JML_USER_NOW = 0;
string namaUser[MAX_USER] {"0"};
double tabunganEmas[MAX_USER][JML_HARI] {{0}};

void garis(){
    system("CLS");
    cout << "\n==========[SOAL 8 - PROGRAM PORTOFOLIO EMAS (INPUT, TOTAL, MAX, MEAN, SORTING, & SEARCHING)]==========" << endl;
}

void cekDataJikaKosong(){
    system("CLS");
    cout << "\n==========[SOAL 8 - PROGRAM PORTOFOLIO EMAS (INPUT, TOTAL, MAX, MEAN, SORTING, & SEARCHING)]==========" << endl;

    if(JML_USER_NOW == 0){
        cout << "\n[!] Data masih kosong. Silakan input terlebih dahulu, pilih (1) di Menu Utama." << endl;
        cout << "\n\tTekan [Enter] untuk kembali ke menu : " << endl;
        cin.get();
        if(cin.get()){
            soal8();
        }
    }
}


void inputData(){
    garis();
    cout << "\n[Input Data User & Pembelian Emas]_________________" << endl;
    cout << "1. Masukkan Nama Anda : ";
    string namaUserInput;
    cin >> namaUserInput;
    cin.ignore();

    for (int i = 0; i < MAX_USER; i++){
        if(namaUserInput == namaUser[i]){
            cout << "\n[!] Data Nama sudah terdaftar. Silakan gunakan nama lain." << endl;
            cout << "\n\tTekan [Enter] untuk kembali ke menu : " << endl;
            cin.get();
            if(cin.get()){
                soal8();
            }
        } else if (JML_USER_NOW > MAX_USER){
            cout << "\n[!] Total User terdaftar telah mencapai batas maksimal. Silakan coba lagi nanti." << endl;
            cout << "\n\tTekan [Enter] untuk kembali ke menu : " << endl;
            cin.get();
            if(cin.get()){
                soal8();
            }
        } else if (namaUser[i] != "0"){
            continue;
        } else if (namaUser[i] == "0"){
            namaUser[i] = namaUserInput;
            JML_USER_NOW++;
            cout << "\n[BERHASIL] Data Nama telah terdaftar." << endl;
            cout << "Selamat Datang \""  << namaUser[i] << "\" di Program Portofolio Emas Digital" << endl;
            break;
        }
    }

    cout << "\n2. Input Data Pembelian Emas (Y/N) : ";
    char pilihan;
    cin >> pilihan;
    if (pilihan == 'n' || pilihan == 'N'){
        soal8();
    } 


};


void statistik(){
    garis();
    cekDataJikaKosong();
    
};


void ranking(){
    garis();
    cekDataJikaKosong();

};


void hariProduktif(){
    garis();
    cekDataJikaKosong();

};


void pencarian(){
    garis();
    cekDataJikaKosong();

};


void soal8(){;

    garis();
    cout << "\n[PROGRAM PORTOFOLIO EMAS]_________________" << endl;
    cout << "| 1. Input Data User & Pembelian          |" << endl;
    cout << "| 2. Statistik User                       |" << endl;
    cout << "| 3. Ranking Investor                     |" << endl;
    cout << "| 4. Hari Terproduktif                    |" << endl;
    cout << "| 5. Percarian Pembelian                  |" << endl;
    cout << "| 6. Exit                                 |" << endl;
    cout << "|_________________________________________|" << endl;

    int pilihanMenuAwal;
    cout << "Pilih : ";
    cin >> pilihanMenuAwal;

    switch(pilihanMenuAwal){
        case 1 : inputData();
            break;
        case 2 : statistik();
            break;
        case 3 : ranking();
            break;
        case 4 : hariProduktif();
            break;
        case 5 : pencarian();
            break;
        case 6 : cout << "\n---> [Program Selesai] - Sampai Jumpa Lagi!" << endl;
            break;
    }
}

int main(){
    soal8();
    return 0;
}
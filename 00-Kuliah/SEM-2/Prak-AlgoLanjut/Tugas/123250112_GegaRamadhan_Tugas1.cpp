/*
    TUGAS 1 - PRAKTIKUM ALGORITMA PEMROGRAMAN LANJUT

    Log Catatan Kebugaran (Workout Log)

    Aplikasi pencatat kebugaran membutuhkan program console untuk merekap riwayat latihan harian penggunanya.
        ● Menu: 
            Catat Sesi Workout, 
            Riwayat Latihan, 
            Cari Sesi, 
            dan Exit.

        ● Struct: 
            ID Sesi, 
            Jenis Latihan (contoh: Lari, Angkat Beban), 
            Durasi (menit), 
            dan Kalori Terbakar.

        ● Rekursi: 
            Buat fungsi rekursif hitungTotalKalori(array_sesi, n) yang menelusuri isi array of struct
            menggunakan teknik divide and conquer atau pemanggilan rekursif mundur, untuk menjumlahkan 
            seluruh Kalori Terbakar dari semua sesi latihan yang pernah dilakukan. 
            Panggil fungsi ini di menu Riwayat Latihan.
        
        ● Searching: 
            Cari sesi berdasarkan ID Sesi menggunakan Binary Search. 
            (Pastikan data diurutkan berdasarkan ID terlebih dahulu).
        
        ● Format File: 
            NIM_Nama_Tugas1.cpp
*/  

#include <iostream>
using namespace std;

void menu();

struct CatatanSesiWorkout{
    int ID;
    string jenisLatihan;
    int durasiLatihan;
    int kaloriTerbakar;
};

CatatanSesiWorkout dataLatihan[100];
int jumlahSesi = 0;

void catatSesiWorkout(){

    system("CLS");
    
    cout << "\n==========[Catat Sesi Workout]==========" << endl;
    
    
    cout << "1. ID Sesi                : " << jumlahSesi + 1 << "\n";
    dataLatihan[jumlahSesi].ID = jumlahSesi + 1;

    cout << "2. Jenis Latihan          : " ;
    cin >> dataLatihan[jumlahSesi].jenisLatihan;

    cout << "3. Durasi Latihan (Menit) : " ;
    cin >> dataLatihan[jumlahSesi].durasiLatihan;

    cout << "4. Kalori Terbakar        : " ;
    cin >> dataLatihan[jumlahSesi].kaloriTerbakar;

    jumlahSesi++;
}

double hitungTotalKalori(CatatanSesiWorkout dataLatihan[], int jumlahSesi){
    if (jumlahSesi <= 0){
        return 0;
    } else {
        return dataLatihan[jumlahSesi-1].kaloriTerbakar + hitungTotalKalori(dataLatihan, jumlahSesi-1);
    }
}

void riwayatLatihan(){
    system("CLS");

    cout << "\n==========[Riwayat Sesi Workout]==========\n" << endl;

    for (int i = 0; i < jumlahSesi; i++){
        cout << "1. ID Sesi                : " << dataLatihan[i].ID << endl;
        cout << "2. Jenis Latihan          : " << dataLatihan[i].jenisLatihan << endl;
        cout << "3. Durasi Latihan (Menit) : " << dataLatihan[i].durasiLatihan << endl;
        cout << "4. Kalori Terbakar        : " << dataLatihan[i].kaloriTerbakar << endl;
        cout << "\n-----------------------------------------\n" << endl;
    }
    
    cout << "===> TOTAL KALORI TERBAKAR : " << hitungTotalKalori(dataLatihan, jumlahSesi) << endl;
}

void cariSesiWorkout(){
    system("CLS");

    bool ketemu = false;
    int idDicari;

    int indexKiri = 0; 
    int indexKanan = jumlahSesi; 
    int mid;

    cout << "\n==========[Cari Sesi Workout]==========\n" << endl;
    cout << "Masukkan ID Sesi Workout : " ;
    cin >> idDicari;

    for (int i = 0; i < jumlahSesi; i++){
        if (ketemu != true && indexKiri <= indexKanan){

            mid = (indexKiri + indexKanan) / 2;
            
            if (idDicari == dataLatihan[mid].ID){
                ketemu = true;
            } else {
                if (idDicari < dataLatihan[mid].ID){
                    indexKanan = mid - 1;
                } else if (idDicari > dataLatihan[mid].ID){
                    indexKiri = mid + 1;
                }
            }
        }
    }
    
    if (ketemu == true){

        cout << "\n---> DATA DITEMUKAN..." << endl;

        cout << "\n==========[Hasil Pencarian Data - Sesi Workout]==========" << endl;
    
        cout << "1. ID Sesi                : " << dataLatihan[mid].ID << endl;

        cout << "2. Jenis Latihan          : " << dataLatihan[mid].jenisLatihan << endl;

        cout << "3. Durasi Latihan (Menit) : " << dataLatihan[mid].durasiLatihan << endl;

        cout << "4. Kalori Terbakar        : " << dataLatihan[mid].kaloriTerbakar << endl;

    } else {
        cout << "\n---> DATA TIDAK DITEMUKAN..." << endl;
    }

}

void menu(){
    system("CLS");

    cout << "+===========================+" << endl;
    cout << "|  NAMA  : Gega Ramadhan    |" << endl;
    cout << "|  NIM   : 123250112        |" << endl;
    cout << "|  KELAS : IF-E (Praktikum) |" << endl;
    cout << "+===========================+" << endl;
    
    bool exit;

    do{
        cout << "\n==========[Program Catatan Kebugaran]==========" << endl;
        cout << "| 1. Catat Sesi Workout                       |" << endl;  
        cout << "| 2. Riwayat Latihan                          |" << endl;  
        cout << "| 3. Cari Sesi                                |" << endl;  
        cout << "| 4. Exit                                     |" << endl;  
        cout << "-----------------------------------------------     " << endl;  
        cout << "Pilih : ";
        
        int pilihanMenu;
        cin  >> pilihanMenu;

        if (pilihanMenu == 4){

            cout << "\n==========[Program Selesai - Thank You]==========" << endl;

            exit = true;

        } else if (pilihanMenu == 1){
            catatSesiWorkout();
        } else if (pilihanMenu == 2){
            riwayatLatihan();
        } else if (pilihanMenu == 3){
            cariSesiWorkout();
        } else {

            cout << "\n*** INPUT INVALID - ULANGI ***" << endl;
        }
        
    } while (exit == false);
    
}


int main(){

    menu();

    return 0;
}
#include <iostream>
using namespace std;

// Helper Function
void judul(){
    system("cls");
    cout << "\n========================================" << endl;
    cout << "         PERTERMUAN 2 - POINTER " << endl;
    cout << "========================================\n" << endl;
}

void pemisah(string head){
    cout << "\n\n----------["<<head<<"]----------\n" << endl;
}


// Coba Pointer
void cobaPointer(){
    pemisah("Coba Pointer");

    int angka = 100;

    int *pointer = &angka;
    cout << "Nilai Asli - Awal    : " << angka << endl; // nilai asli
    cout << "Mengambil Alamat     : " << pointer << endl; // melihat hasil alamat
    cout << "Mengambil Nilai asli : " << *pointer << endl; // melihat nilai aslinya
    
    // Ubah nilai
    *pointer = 50;
    cout << "\nNilai Diubah         : " << angka << endl; // nilai asli

    // melihat hasil alamat
    cout << "Mengambil Alamat     : " << pointer << endl; 
    // melihat nilai aslinya
    cout << "Mengambil Nilai      : " << *pointer << endl;
}

void cekPerbedaanAlamat(){
    pemisah("Cek Perbedaan Alamat");

    int X = 90;
    int Y = 30;
    
    int *ptrX = &X;
    int *ptrY = &Y;

    cout << "Nilai  X : " << X << endl;
    cout << "Alamat X : " << ptrX << endl << endl;

    cout << "Nilai  Y : " << Y << endl;
    cout << "Alamat Y : " << ptrY << endl;
}

void nullPointer(){
    pemisah("Null Pointer");

    int nilai = 200;
    int *ptr = nullptr;

    if (ptr != nullptr){
        cout << "AMAN - Nilai : " << *ptr << endl;
    } else {
        cout << "ERROR - [Pointer Berisi Null]" << endl;
    }
}

void pointerStruct(){
    pemisah("Pointer Struct");

    struct Mahasiswa {
        string nim;
        string nama;
        double ipk;
    };

    Mahasiswa mhs;
    Mahasiswa* ptr = &mhs;
    ptr->nim = "123260001";
    ptr->nama = "Gega";
    ptr->ipk = 3.88;

    // Pakai Titik
    cout << "1. Akses Pakai Titik Biasa" << endl;
    cout << mhs.nama << endl;
    cout << mhs.nim << endl;
    cout << mhs.ipk << endl;

    // Pakai Panah
    cout << "\n2. Akses Pakai Panah" << endl;
    cout << ptr->nama << endl;
    cout << ptr->nim << endl;
    cout << ptr->ipk << endl;

    // Pakai Panah
    cout << "\n3. Akses Pakai Kurung" << endl;
    cout << (*ptr).nama << endl;
    cout << (*ptr).nim << endl;
    cout << (*ptr).ipk << endl;
}


// Pointer As Parameter - Tambah Nilai
void tambahNilai(int *nilai){
    *nilai += 10;
}
void pointerAsParameter1(){
    pemisah("Pointer As Parameter");

    int nilai = 100;

    cout << "Nilai Awal  : " << nilai << endl;
    tambahNilai(&nilai);
    cout << "Nilai Akhir : " << nilai << endl;
}

// Pointer As Parameter - Damage Karakter
struct KarakterGame {
    int health;
};
void terimaDamage(KarakterGame *karakter, int damage){
    karakter->health -= damage;
}
void pointerAsParameter2(){
    pemisah("Damage Karakter");
    KarakterGame gega = {100};
    
    cout << "Health Awal  : " << gega.health << endl;
    terimaDamage(&gega, 50);
    cout << "Health Akhir : " << gega.health << endl;
}


// Main Function
int main(){
    judul();

    cobaPointer();
    cekPerbedaanAlamat();
    nullPointer();
    pointerStruct();
    pointerAsParameter1();
    pointerAsParameter2();

    return 0;
}

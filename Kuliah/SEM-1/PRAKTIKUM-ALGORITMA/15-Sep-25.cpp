#include <iostream>
using namespace std;

void tiketBioskop(){
    int pilihanKategori, usiaUser;
    float perhitunganHarga, totalHarga, harga;

    int genreAction = 50000;
    int genreDrama = 40000;
    int genreAnimasi = 35000;

    cout << "========== Pembelian Tiket Bioskop ==========" << endl;

    cout << "========== Genre Film =========" << endl;
    cout << "Genre Film dan Harga : " << endl;
    cout << "1. Action = Rp50.000 " << endl;
    cout << "2. Drama = Rp40.000 " << endl;
    cout << "3. Animasi = Rp35.000 " << endl;

    cout << endl << "Pilih Genre Film yang Akan Anda Tonton : ";
    cin >> pilihanKategori;

    cout << "Pilihan Anda : " << endl;

    switch (pilihanKategori)
    {
        case 1:
            harga = genreAction;
            cout << "Action"<< endl;
            break;

        case 2:
            harga = genreDrama;
            cout << "Drama"<< endl;
            break;

        case 3:
            harga = genreAnimasi;
            cout << "Animasi" << endl;
        default:
            cout << "Masukkan Data dengan Benar!" << endl;
            break;
    }

    cout << endl << "========== Kategori Penonton =========" << endl;
    cout << "Masukkan Usia Anda : " << endl;
    cin >> usiaUser;

    if (usiaUser < 12){
        perhitunganHarga = harga * 50 / 100;
        cout << "Selamat Anda Mendapat Diskon Sebesar 50%" << endl; 
    } else if (usiaUser < 18){
        perhitunganHarga = harga * 20 / 100;
        cout << "Selamat Anda Mendapat Diskon Sebesar 20%" << endl; 
    } else if (usiaUser >=18){
        cout << "Maaf Anda Belum Mendapat Diskon" << endl;
    } else {
        cout << "Masukkan data dengan benar!" << endl;
    }

    cout << endl << "========== Pilihan Hari Menonton =========" << endl;
    cout << "Pilihan : " << endl;
}

int main(){
    tiketBioskop();

    cin.get();
    return 0;
}
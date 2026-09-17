#include <iostream>
using namespace std;

void cekPersyaratanVisaNegara(){

    // Deklarasi Variabel
    int pilihanNegara;
    string displayPilihanNegara;
    string hasil;
    int kemampuanBahasa;
    int jumlahTabungan;

    // Judul Program
    cout << "========== Program Cek Persyaratan Visa Negara ==========" << endl;
    
    // Input Pilihan Negara
    cout << "Pilihan Negara Tujuan : " << endl;
    cout << "1. Jepang" << endl;
    cout << "2. Amerika Serikat" << endl;
    cout << "3. Australia" << endl;
    cout << "Pilihan Negara Anda : ";
    cin >> pilihanNegara;

    // Input Kemampuan Bahasa
    cout << endl << "Pilih Kemampuan Bahasa Anda :" << endl;
    cout << "1. Lancar" << endl;
    cout << "2. Sedang" << endl;
    cout << "3. Tidak Bisa" << endl;
    cout << "Kemampuan Bahasa Anda : ";
    cin >> kemampuanBahasa;

    // Input Jumlah Tabungan
    cout << endl << "Masukkan Jumlah Tabungan Anda : ";
    cin >> jumlahTabungan;

    // Program Pengendalian
    if (pilihanNegara == 1){
        displayPilihanNegara = "Jepang";
        if (jumlahTabungan >= 50000000){
            if (kemampuanBahasa <= 2){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
            }
        } else if (jumlahTabungan < 50000000){
            hasil = "GAGAL";
        } else {
            cout << "Masukkan Data Dengan Benar" << endl;
        }
    } else if (pilihanNegara == 2){
        displayPilihanNegara = "Amerika Serikat";
        if (jumlahTabungan >= 100000000){
            if (kemampuanBahasa == 1){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
            }
        } else if (jumlahTabungan < 100000000){
            hasil = "GAGAL";
        } else {
            cout << "Masukkan Data Dengan Benar" << endl;
        }
    } else if (pilihanNegara == 3){
        displayPilihanNegara = "Australia";
        if (jumlahTabungan >= 70000000){
            if (kemampuanBahasa <= 2){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
            }
        } else if (jumlahTabungan < 70000000){
            hasil = "GAGAL";
        } else {
            cout << "Masukkan Data Dengan Benar" << endl;
        }
    } else {
        cout << "Masukkan Data Dengan Benar!" << endl;
    }

    // Display Hasil
    cout << endl << "========== Hasil ==========" << endl;
    cout << "Nama Negara : " << displayPilihanNegara << endl;
    cout << "Jumlah Tabungan : Rp" << jumlahTabungan << endl;
    cout << "Kemampuan Bahasa : " << kemampuanBahasa << endl;
    cout << "Status Visa : " << hasil << endl;
    
}

int main(){
    cekPersyaratanVisaNegara();

    cin.get();
    return 0;
}
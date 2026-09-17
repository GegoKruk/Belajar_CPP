#include <iostream>
using namespace std;

void cekPersyaratanVisaNegara(){

    // Deklarasi Variabel
    short inputPilihanNegara;
    short inputKemampuanBahasa;
    long jumlahTabungan;
    string displayPilihanNegara;
    string displayKemampuanBahasa;
    string hasil;
    string keterangan;

    long syaratTabunganJepang = 50000000;
    long syaratTabunganAS = 100000000;
    long syaratTabunganAustralia = 70000000;

    // Judul Program
    cout << "========== Program Cek Persyaratan Visa Negara ==========" << endl;
    
    // Input Pilihan Negara
    cout << endl << "=========> Pilihan Negara Tujuan : " << endl;
    cout << "\t 1. Jepang" << endl;
    cout << "\t 2. Amerika Serikat" << endl;
    cout << "\t 3. Australia" << endl;
    cout << "\t Pilihan Negara Anda : ";
    cin >> inputPilihanNegara;

    // Error handling 
    if(cin.fail() || inputPilihanNegara < 1 || inputPilihanNegara > 3){
        cout << "Error: Input tidak valid!" << endl;
        return;
    }

    switch (inputPilihanNegara) {
        case 1 :
            displayPilihanNegara = "Jepang";
            break;
        case 2 :
            displayPilihanNegara = "Amerika Serikat";
            break;    
        case 3 : 
            displayPilihanNegara = "Australia";
            break; 
    }

    // Input Kemampuan Bahasa
    cout << endl << "=========> Pilih Kemampuan Bahasa Anda :" << endl;
    cout << "\t 1. Lancar" << endl;
    cout << "\t 2. Sedang" << endl;
    cout << "\t 3. Tidak Bisa" << endl;
    cout << "\t Kemampuan Bahasa Anda : ";
    cin >> inputKemampuanBahasa;

    // Error handling 
    if(cin.fail() || inputKemampuanBahasa < 1 || inputKemampuanBahasa > 3){
        cout << "Error: Input tidak valid!" << endl;
        return;
    }

    switch (inputKemampuanBahasa) {
        case 1 :
            displayKemampuanBahasa = "Lancar";
            break;
        case 2 :
            displayKemampuanBahasa = "Sedang";
            break;    
        case 3 : 
            displayKemampuanBahasa = "Tidak Bisa";
            break;
    }

    // Input Jumlah Tabungan
    cout << endl << "=========> Masukkan Jumlah Tabungan Anda : ";
    cin >> jumlahTabungan;

    // Error handling 
    if(cin.fail() || jumlahTabungan < 0){
        cout << "Error: Input jumlah tabungan tidak valid!" << endl;
        return;
    }

    // Program Pengendalian
    if (inputPilihanNegara == 1){ //Blok Pilihan Negara Jepang
        if (jumlahTabungan >= syaratTabunganJepang){
            if (inputKemampuanBahasa == 1 || inputKemampuanBahasa == 2){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
                keterangan = "Kemampuan Bahasa Jepang Minimal \"Sedang\"";
            }
        } else {
            hasil = "GAGAL";
            keterangan = "Jumlah Tabungan Minimal 50 Juta Rupiah";
        }
    } else if (inputPilihanNegara == 2){ //Blok Pilihan Negara Amerika Serikat
        if (jumlahTabungan >= syaratTabunganAS){
            if (inputKemampuanBahasa == 1){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
                keterangan = "Kemampuan Bahasa Inggris Harus \"Lancar\"";
            }
        } else {
            hasil = "GAGAL";
            keterangan = "Jumlah Tabungan Minimal 100 Juta Rupiah";
        }
    } else if (inputPilihanNegara == 3){ //Blok Pilihan Negara Australia
        if (jumlahTabungan >= syaratTabunganAustralia){
            if (inputKemampuanBahasa == 1 || inputKemampuanBahasa == 2){
                hasil = "LULUS";
            } else {
                hasil = "GAGAL";
                keterangan = "Kemampuan Bahasa Inggris Minimal \"Sedang\"";
            }
        } else {
            hasil = "GAGAL";
            keterangan = "Jumlah Tabungan Minimal 70 Juta Rupiah";
        }
    } 

    // Display Hasil
    cout << endl << "========== Hasil ==========" << endl;
    cout << "Nama Negara : " << displayPilihanNegara << endl;
    cout << "Jumlah Tabungan : Rp" << jumlahTabungan << endl;
    cout << "Kemampuan Bahasa : " << displayKemampuanBahasa << endl;
    cout << "Status Visa : " << hasil << endl;

    if (hasil == "GAGAL"){
        cout << endl << "Keterangan : " << keterangan << endl;
    } else {
        cout << endl << "Selamat Anda LULUS, Visa Segera Diproses \nSampai Jumpa Lagi!" << endl;
    }
}

int main(){
    cekPersyaratanVisaNegara();
    cin.get();
    return 0;
}
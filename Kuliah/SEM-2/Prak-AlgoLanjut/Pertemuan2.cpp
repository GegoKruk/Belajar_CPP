#include <iostream>
using namespace std;

    // struct Alamat{
    //     string kota;
    //     string provinsi;
    // };

    // // membuat nested struct
    // struct Pegawai{
    //     string nama;
    //     Alamat alamat;
    //     double gaji;
    // };

    // //Membuat object
    // Pegawai p;

    // //Mengisi elemen struct
    // p.nama = "Gega";
    // p.alamat.kota = "Bantul"; //akses via dotchain


    // membuat struct
    struct Pegawai{
        string nama;
        int jam;
        double upah;
    };

    double hitungGaji(Pegawai p){
        return p.jam * p.upah;
    }

    double totalGaji(Pegawai arr[], int n){
        double total =0;
        for (int i = 0; i < n; i++){
            total += hitungGaji(arr[i]);
        }
        return total;
    }

int main(){
    // 1. Bikin daftar pegawainya (Array of Struct)
    Pegawai daftar[3] = {
        {"Gega", 10, 50000},   // Gaji: 500rb
        {"Hafidh", 5, 100000}, // Gaji: 500rb
        {"Budi", 2, 50000}     // Gaji: 100rb
    };

    // 2. Panggil fungsi totalGaji untuk menghitung semuanya
    double hasilAkhir = totalGaji(daftar, 3);

    cout << "Total pengeluaran gaji perusahaan: Rp" << hasilAkhir << endl;

for(int i = 5; i >= 0; i--){
    cout << "Izza" << endl;
};

    return 0;
}
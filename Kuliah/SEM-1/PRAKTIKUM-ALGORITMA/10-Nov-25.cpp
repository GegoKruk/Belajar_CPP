#include <iostream>
using namespace std;

//Materi Array

// Contoh Array 1 Dimensi
void array1D(){
    int nilai[5];

    cout << "===== Program Input Nilai =====" << endl;
    for (int i = 0; i < 5; i++){
        cout << "Masukkan Nilai : ";
        cin >> nilai[i];
    }

    // Tampilkan Nilai
    cout << nilai[0] << endl;
    cout << nilai[1] << endl;
    cout << nilai[2] << endl;
    cout << nilai[3] << endl;
    cout << nilai[4] << endl;
}

// Contoh Array 2 Dimensi
void array2D(){
    int nilai[5][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
        {13,14,15}
    };

    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout << "Index ke [" << i << "]" << "[" << j << "] : "<<  nilai[i][j] << endl;
        }
    }
}

// Soal Study Case 1 
/*
    Buatlah sistem penilaian untuk mahasiswa dimana diawal kita input nama dan nilai mahasiswa, lalu di outputkan semua nilai dan stringnya dan diakhir dikasih statistik penilaian nya contoh:
    ===== Program Pengolahan Nilai Mahasiswa =====

    Masukkan jumlah mahasiswa: 3

    --- Data Mahasiswa ke-1 ---
    Masukkan Nama: Budi
    Masukkan Nilai: 85

    --- Data Mahasiswa ke-2 ---
    Masukkan Nama: Ani
    Masukkan Nilai: 92

    --- Data Mahasiswa ke-3 ---
    Masukkan Nama: Chandra
    Masukkan Nilai: 78

    =======================================
    --- Hasil Pengolahan Data ---

    Daftar Nilai Mahasiswa:
    1. Budi     : 85
    2. Ani      : 92
    3. Chandra  : 78

    Statistik Nilai:
    Nilai Rata-rata : 85.00
    Nilai Tertinggi : 92 (Diraih oleh: Ani)
    Nilai Terendah  : 78 (Diraih oleh: Chandra)
*/
void studyKasusArray2D(){
    system("CLS");

    int jumlahMahasiswa;

    // Intro Program
    cout << "\n=====[ Program Pengolahan Nilai Mahasiswa ]=====" << endl;
    
    // Perintaah input jumlah mahasiswa
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> jumlahMahasiswa;

    // Deklarasi Array dengan banyak isi sesuai input jumlah mahasiswa
    string nama[jumlahMahasiswa]; 
    int nilai[jumlahMahasiswa];

    // Perulangan untuk input nama & nilai
    for(int i = 0; i < jumlahMahasiswa; i++){

            cout << "\n=====[ Data Mahasiswa " << i + 1 << " ]=====" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama[i];
            cout << "Masukkan Nilai : ";
            cin >> nilai[i];
    }

    // Menampilkan Daftar Nilai Mahasiswa
    cout << "\n=====[ Hasil Pengolahan Data Mahasiswa ]=====" << endl;
    cout << "[Daftar Nilai Mahasiswa]" << endl;
    for(int o = 0; o < jumlahMahasiswa; o++){
        cout << o + 1 << ". " << nama[o] << " : " << nilai[o] << endl;
    }

    // Program pengolahan nilai
    int totalNilai = 0;
    float rataRata;

    // Perulangan menjumlahkan semua nilai
    for (int j = 0; j < jumlahMahasiswa; j++){
        totalNilai = totalNilai + nilai[j];
    }

    // Menghitung rata-rata nilai
    rataRata = totalNilai/jumlahMahasiswa;

    // Mencari nilai tertinggi
    int nilaiTertinggi = 0;
    string namaNilaiTertinggi;
    for (int m = 0; m < jumlahMahasiswa; m++){
        if (nilai[m] >= nilaiTertinggi){
            nilaiTertinggi = nilai[m];
            namaNilaiTertinggi = nama[m];
        }
    }
    
    // Mencari nilai Terendah
    int nilaiTerendah = 100;
    string namaNilaiTerendah;
    for (int n = 0; n < jumlahMahasiswa; n++){
        if (nilai[n] <= nilaiTerendah){
            nilaiTerendah = nilai[n];
            namaNilaiTerendah = nama[n];
        }
    }
    
    // Display hasil pengolahan
    cout << "\n[Statistik Nilai Mahasiswa]" << endl;
    cout << "Nilai Rata-rata : " << rataRata << endl;
    cout << "Nilai Tertinggi : " << nilaiTertinggi << " (Diraih oleh : " << namaNilaiTertinggi << ")" << endl;
    cout << "Nilai Terendah : " << nilaiTerendah << " (Diraih oleh : " << namaNilaiTerendah << ")" << endl;

}

// Function Utama 
int main(){

    //array1D();
    //array2D();
    studyKasusArray2D();

    cin.get();
    return 0;
}
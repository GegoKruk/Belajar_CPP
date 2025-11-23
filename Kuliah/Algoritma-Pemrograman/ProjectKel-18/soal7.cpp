#include <iostream>
using namespace std;

// Soal 7
/*
    Buatlah program untuk mengkonversi angka (integer) yang diinput menjadi huruf 
    terbilang berbahasa indonesia 
    (bilangan yang dikonversi berkisar dari 1 sampai dengan 99)
    
    (Gunakan materi yang sudah kalian dapatkan di mka ini)
        petunjuk: dapat memanfaatkan operator div dan mod
        
*/

// Inisialisasi variabel 
int inputAngka;
string kataPuluhan;
string kataSatuan;
string kataBelasan;

int main(){
    system("CLS");

    // Judul Program
    cout << "\n=====[Program Konversi Angka Bahasa Indonesia]=====" << endl;

    // Syarat Perulangan
    bool loopProgram = false;
    do{
        // Input angka oleh user
        cout << "1. Masukkan Angka (1-99) : ";
        cin >> inputAngka;

        // Perhitungan puluhan dan satuan
        int puluhan = inputAngka / 10;
        int satuan = inputAngka % 10;
    
        // Cek apakah didalam range
        if (inputAngka < 1 || inputAngka > 99){
            cout << "=====[Input Tidak Valid - Diluar Range]=====" << endl;
        } else {
            if (puluhan == 1){
                if (satuan == 0){
                    kataPuluhan = "Sepuluh";
                } else if (satuan > 0){
                    if (satuan == 1){
                        kataBelasan = " Sebelas";
                    } else if (satuan == 2){
                        kataBelasan = " Duabelas";
                    } else if (satuan == 3){
                        kataBelasan = " Tigabelas";
                    } else if (satuan == 4){
                        kataBelasan = " Empatbelas";
                    } else if (satuan == 5){
                        kataBelasan = " Limabelas";
                    } else if (satuan == 6){
                        kataBelasan = " Enambelas";
                    } else if (satuan == 7){
                        kataBelasan = " Tujuhbelas";
                    } else if (satuan == 8){
                        kataBelasan = " Delapannelas";
                    } else if (satuan == 9){
                        kataBelasan = " Sembilanbelas";
                    }
                } 
            } else if (puluhan == 2){
                kataPuluhan = " Dua Puluh";
            } else if (puluhan == 3){
                kataPuluhan = " Tiga Puluh";
            } else if (puluhan == 4){
                kataPuluhan = " Empat Puluh";
            } else if (puluhan == 5){
                kataPuluhan = " Lima Puluh";
            } else if (puluhan == 6){
                kataPuluhan = " Enam Puluh";
            } else if (puluhan == 7){
                kataPuluhan = " Tujuh Puluh";
            } else if (puluhan == 8){
                kataPuluhan = " Delapan Puluh";
            } else if (puluhan == 9){
                kataPuluhan = " Sembilan Puluh";
            }
        
            if (puluhan == false || puluhan > 1){
                if (satuan == 1){
                    kataSatuan = " Satu";
                } else if (satuan == 2){
                    kataSatuan = " Dua";
                } else if (satuan == 3){
                    kataSatuan = " Tiga";
                } else if (satuan == 4){
                    kataSatuan = " Empat";
                } else if (satuan == 5){
                    kataSatuan = " Lima";
                } else if (satuan == 6){
                    kataSatuan = " Enam";
                } else if (satuan == 7){
                    kataSatuan = " Tujuh";
                } else if (satuan == 8){
                    kataSatuan = " Delapan";
                } else if (satuan == 9){
                    kataSatuan = " Sembilan";
                }
            }
            // Display hasil
            cout << "2. Hasil Konversi        :" << kataPuluhan << kataBelasan << kataSatuan << endl;
            
            // Untuk reset agar kosong lagi
            kataPuluhan = "";
            kataBelasan = "";
            kataSatuan  = "";
        }

        // Input pilihan Yes/No
        char pilihan;
        cout << "\nCoba lagi? (Y/N) : ";
        cin >> pilihan;

        if(pilihan == 'Y' || pilihan == 'y'){
            cout << "\n";
            loopProgram = false;
        } else if (pilihan == 'N' || pilihan == 'n'){
            cout << "\n=====[Program Selesai - Terima Kasih]=====" << endl;
            loopProgram = true;
        } else {
            cout << "=====[Input Tidak Valid - Program Berhenti]=====" << endl;
            exit(0);
        }
    } while (loopProgram == false);
}
#include <iostream>
using namespace std;

// Soal 2 => Output Hari Satu Minggu
int main(){

    int inputUser;
    string hasil;
    
    // Display Awal User
    cout << endl << "========== Program Pilihan Hari dalam Seminggu ==========" << endl;
    cout << "\nSiliakan Pilih Salah Satu Hari dalam Seminggu : ";
    cout << "\n1. Senin";
    cout << "\n2. Selasa";
    cout << "\n3. Rabu";
    cout << "\n4. Kamis";
    cout << "\n5. Jumat";
    cout << "\n6. Sabtu";
    cout << "\n7. Minggu";
    cout << "\nMasukkan Pilihan Anda (1-7) : ";
    cin >> inputUser;

    // Proses Pengecekan Input User
    switch (inputUser){
    case 1:
        hasil = "Senin";
        break;
    case 2:
        hasil = "Selasa";
        break;
    case 3:
        hasil = "Rabu";
        break;
    case 4:
        hasil = "Kamis";
        break;
    case 5:
        hasil = "Jumat";
        break;
    case 6:
        hasil = "Sabtu";
        break;
    case 7:
        hasil = "Minggu";
        break;
    default:
        hasil = "Angka yang dimasukkan di luar range";
        break;
    }

    // Display Hasil ke User
    cout << endl << "========== Hasil Pilihan ==========" << endl;
    cout << "Hari yang anda pilih : " << hasil << endl;

    cin.ignore();
    cin.get();
    return 0;
}
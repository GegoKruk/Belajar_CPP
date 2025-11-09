#include <iostream>
using namespace std;

// Soal 1 => Cek Bilangan Prima dari Input User
int main(){
    int inputUser;
    bool cekPrima = true;
    string hasil;

    // Display Awal User
    cout << "================ Program Cek Bilangan Prima ================" << endl;
    cout << "Inputkan bilangan : ";
    cin >> inputUser;

    // Proses Pengecekan Input User
    if (inputUser <= 1) {
        cout << "Input tidak valid, bilangan kurang dari 1\n";
    } else {
        for (int i = 2; i < inputUser; i++) {
            if (inputUser % i == 0) {
                cekPrima = false; 
                break;
            }
        }
    }

    if (cekPrima == true){
        hasil = "Bilangan Prima";
    } else {
        hasil = "Bukan Bilangan Prima";
    }

    // Disply Hasil ke User
    cout << "\n========== Hasil Pengecekan Bilangan Prima ==========" << endl;
    cout << "Hasil Input Bilangan : " << hasil << endl;

    cin.ignore();
    cin.get();
    return 0;
}
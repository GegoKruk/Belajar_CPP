#include <iostream>
using namespace std;

// Soal 1 => Cek Bilangan Prima dari Input User
void soalPertama() {
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
}

// Soal 2 => Output Hari Satu Minggu
void soalKedua(){
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
}

int main(){
    soalPertama();
    //soalKedua();

    cin.ignore();
    cin.get();
    return 0;
}
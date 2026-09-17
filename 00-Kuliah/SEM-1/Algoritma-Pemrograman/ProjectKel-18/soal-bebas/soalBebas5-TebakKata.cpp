#include <iostream>
using namespace std;

void nimNama(){
    cout << "---------------------------------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan    | Nama : Rassya Arma Putra    |" << endl;
    cout << "| NIM  : 123250112        | NIM  : 123250118            |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void inputTidakValid(){
    cout << "=====[Input Tidak Valid - Program Berhenti]=====" << endl;
    exit(0);
}

int main() {

    // Membersihkan terminal
    system("CLS");

    //Deklarasi
    string kataRahasia = "informatika"; 
    string progress(kataRahasia.length(), '_'); 
    int kesempatan = 5; // jumlah kesempatan 
    char tebakan;

    // panggil function nim nama
    nimNama();

    cout << "\n========[Program Permainan Tebak Kata]========" << endl;
    cout << "\n[Peraturan Permainan]__________________________" << endl;
	cout << "| 1. Kesempatan menebak hanya " << kesempatan << "x              |" << endl;
	cout << "| 2. Program akan memberikan clue             |" << endl;
	cout << "| 3. Jika kesempatan habis maka Anda kalah!   |" << endl;
	cout << "|_____________________________________________|" << endl;

    // loop 
    while (kesempatan > 0 && progress != kataRahasia) {

        cout << "\n-----------------------------------------------" << endl;
        cout << "\nKata: " << progress << endl;
        cout << "Masukkan huruf tebakan: ";
        cin >> tebakan;

        // perulangan mencari huruf yang sama
        bool benar = false;
        for (int i = 0; i < kataRahasia.length(); i++) {
            // jika ada yang sama maka masuk ke progress
            if (kataRahasia[i] == tebakan) {
                progress[i] = tebakan;
                benar = true;
            }
        }

        if (benar) {
            cout << "--> Huruf '" << tebakan << "' ada di kata!" << endl;
            cout << "--> Sisa kesempatan: " << kesempatan << endl;
        } else {
            kesempatan--;
            cout << "\n--> Huruf '" << tebakan << "' tidak ada" << endl;
            cout << "--> Sisa kesempatan: " << kesempatan << endl;
        }
    }

    // hasil akhir
    if (progress == kataRahasia) {
        cout << "\n***** SELAMAT *****" << endl;
        cout << "Kata berhasil ditebak: " << kataRahasia << endl;
    } else {
        cout << "\n=====[KAMU GAGAL]===== " << endl;
		cout << "Tebakanmu Masih Meleset!" << endl;
        cout << "Kesempatan sudah habis" << endl;
        cout << "Kata rahasia adalah: " << kataRahasia << endl;
    }

    return 0;
}

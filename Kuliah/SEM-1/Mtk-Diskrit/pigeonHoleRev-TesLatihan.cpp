#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

//Deklarasi Variabel
string soal;
int pigeon, hole, hasil;
char ulang;

// Function validasi input pigeon
// Rekursi (memanggil dirinya sendiri) -> tanpa do while  loop
bool validasiInput(int &pigeon){

    cin >> pigeon;

    if (cin.fail()) {
        cout << "\n=====[Peringatan]=====\n";
        cout << "Input Tidak Valid, Masukkan Hanya Angka!\n";
        cout << "Masukkan jumlah pigeon: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return validasiInput(pigeon);
    } else if (pigeon <= 0) {
        cout << "\n=====[Peringatan]=====\n";
        cout << "Jumlah pigeon harus lebih dari 0!\n";
        cout << "Masukkan jumlah pigeon: ";
        return validasiInput(pigeon);
    } else {
        return true;
    }

}

// Function validasi input ole
bool validasiInputHole (int &hole, int pigeon){

	bool inputHoleValid = false; 

	while (!inputHoleValid) {

        cin >> hole;

        if (cin.fail()) {
            cout << "\n=====[Peringatan]=====\n";
            cout << "Input Tidak Valid, Masukkan Hanya Angka!\n";
            cout << "Masukkan jumlah hole: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (hole <= 0) {
            cout << "\n=====[Peringatan]=====\n";
            cout << "Jumlah hole harus lebih dari 0!\n";
            cout << "Masukkan jumlah hole: ";
        } else if (hole > pigeon) {
            cout << "\n=====[Peringatan]=====\n";
            cout << "Jumlah hole tidak boleh lebih besar dari jumlah pigeon!\n";
            cout << "Masukkan jumlah hole: ";
        } else {
            inputHoleValid = true;
            return inputHoleValid;
        }
    }
}

// Function hitung hasil -> lebih modular
int hitungPigeonhole(int pigeon, int hole){
    hasil = ceil((double)pigeon / hole);

    return hasil;
}

// Main Function
int main(){

    // Do While Loop
    do {

        // Membersihkan CMD
        system("CLS");
    
        cout << "=== PIGEONHOLE PRINCIPLE ===\n";
        
        cout << "Masukkan deskripsi soal: ";
        cin.ignore(); 
        getline(cin, soal);
    
         // Validasi input pigeon
        cout << "Masukkan jumlah pigeon: ";
        validasiInput(pigeon);
    
        // Validasi input hole
        cout << "Masukkan jumlah hole: ";
        validasiInputHole(hole, pigeon);

        hitungPigeonhole(pigeon, hole);
    
        cout << "\n====== Penyelesaian ======\n";
        cout << "Soal: " << soal << endl;

        cout << "\nDiketahui:\n";         
        cout << "     Jumlah pigeon: " << pigeon << endl;
        cout << "     Jumlah hole: " << hole << endl;

        cout << "\nHitung:\n";
        cout << "     R = " << pigeon << " / " << hole 
            << "\n     R = " << hasil << endl;

        if (hasil == 1) {
            cout << "\nDistribusi sempurna: setiap hole berisi tepat 1 pigeon.\n";
            cout << "Tidak ada hole yang kosong atau berisi lebih dari 1.\n";
        } else {
            cout << "\nJadi, minimal ada " << hasil 
                << " pigeon yang dijamin berada dalam hole yang sama.\n";
        }


        cout << "\nIngin mencoba lagi? (y/n): ";
        cin >> ulang;
        
    } while (ulang == 'y' || ulang == 'Y');
}

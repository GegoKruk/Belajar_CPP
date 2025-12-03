#include <iostream>
using namespace std;

void nimNama(){
    cout << "---------------------------------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan    | Nama : Rassya Arma Putra    |" << endl;
    cout << "| NIM  : 123250112        | NIM  : 123250118            |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void menu(){
	// intro program
	cout << "\n========[Program Tebak Angka 1-100]========" << endl; 
	cout << "\n[Peraturan Permainan]__________________________" << endl;
	cout << "| 1. Kesempatan menebak hanya 10x             |" << endl;
	cout << "| 2. Program akan memberikan clue             |" << endl;
	cout << "| 3. Jika kesempatan habis maka Anda kalah!   |" << endl;
	cout << "|_____________________________________________|" << endl;
}

void permainan(){
	// Deklarasi 
	int angkaRahasia = 46; // Bisa diubah jika mau
	int angkaTebakan;
	int kesempatan = 10;

	// pilihan siap/tidak
	char pilihan;
	cout << "\nApakah Anda sudah siap? (Y/N) : ";
	cin >> pilihan;

	if (pilihan == 'y' || pilihan == 'Y'){
		
		// perulangan
		while (kesempatan > 0){
			
			cout << "\n-----------------------------------------------" << endl;
			cout << "\nMasukkan angka tebakanmu! (1-100) : ";
			cin >> angkaTebakan;
		
			if (angkaTebakan < 0 || angkaTebakan > 100){ // error handling jika input diluar range
				cout << "\n=====[Input Tidak Valid - Program Berhenti]=====" << endl;
				exit(0);
			} else if (angkaTebakan < angkaRahasia){ // clue jika tebakan kurang
				cout << "\n--> Tebakanmu KURANG dari angka rahasia! " << endl;
				cout << "--> Sisa Kesempatan : " << kesempatan - 1 << endl;
				kesempatan--;
			} else if (angkaTebakan > angkaRahasia){ // clue jika tebakan melebihi
				cout << "\n--> Tebakanmu MELEBIHI angka rahasia!" << endl;
				cout << "--> Sisa Kesempatan : " << kesempatan - 1 << endl;
				kesempatan--;
			} else if (angkaTebakan == angkaRahasia){ // Ucapan selamat jika tebakan tepat
				cout << "\n*****[SELAMAT]***** " << endl;
				cout << "Tebakanmu Benar!" << endl;
				cout << "Angka Rahasia adalah : "<< angkaRahasia << endl;
				kesempatan = 0;
			} else{
				cout << "\n=====[Input Tidak Valid - Program Berhenti]=====" << endl;
				exit(0);	
			}

			// Jika kesempatan habis dan angka belum benar
			if (kesempatan == 0 && angkaTebakan != angkaRahasia){
				cout << "\n=====[KAMU GAGAL]===== " << endl;
				cout << "Tebakanmu Masih Meleset!" << endl;
				cout << "Kesempatanmu sudah habis :(" << endl;
				cout << "\nAngka Rahasia adalah : "<< angkaRahasia << endl;
			}
		}

	} else if (pilihan == 'n' || pilihan == 'N'){
		cout << "\n=====[Terima Kasih Sudah Mampir! - Program Berhenti]=====" << endl;
	} else {
		cout << "\n=====[Input Tidak Valid - Program Berhenti]=====" << endl;
	}
}

int main(){
	// Membersihkan tampilan
	system("CLS");

	// panggil function nim nama
	nimNama();

	// panggil function menu
	menu();

	// panggil function permainan
	permainan();
}
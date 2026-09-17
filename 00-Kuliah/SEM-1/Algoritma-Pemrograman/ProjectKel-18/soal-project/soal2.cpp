#include <iostream>
using namespace std;

// Soal 2
/*
    Buatlah program (bahasa c++) untuk menginput suatu kalimat dan menghasilkan kalimat baru 
	seperti contoh di bawah.

	ketentuan : 
	- input kalimat di program utama/main, 
	- hasilnya dibuat dan ditampilkan di function,
	- gunakan tipe data array (array of char), statement perulangan dan kondisional

	Contoh tampilan :
		kalimat = teknik informatika upn
		hasil	= upn informatika teknik
*/

int main () {
	string kalimat;
	string kata[100];
	int jumlah_kata = 0;
	
	cout << "Masukan Kalimat: "; 
	getline(cin, kalimat);
	
	string temp = "";
	
	for (int i = 0; i < kalimat.length(); i++) {
		if (kalimat[i] == ' ') {
			kata[jumlah_kata] = temp;
			jumlah_kata++;
			temp = "";
		} else {
			temp = temp + kalimat[i];
		}
	}
		
	kata[jumlah_kata] = temp;
	jumlah_kata++;
		
	for (int i = jumlah_kata - 1; i >= 0; i--) {
		cout << "Hasil: ";
		cout << kata[i] << endl;

		if (i > 0) {
			cout << " ";
		}
	}
}

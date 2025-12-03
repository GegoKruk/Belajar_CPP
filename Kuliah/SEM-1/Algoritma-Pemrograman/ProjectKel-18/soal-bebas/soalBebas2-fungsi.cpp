#include <iostream>
using namespace std;

// Program Menghitung Jumlah Angka Ganjil

int ganjil(int angka) {
	
	int hitung = 0;
	
	while (angka != 0) {
		
		int digit = angka % 10;
		
		if (digit % 2 != 0) {
			hitung++;
		}
		angka = angka / 10;
	}
	return hitung;
}

int main () {

	// Deklarasi array
	int angka[5];
	
	// Perulangan untuk input angka ke array
	for (int i = 0; i < 5; i++){
		cout << "Angka " << i+1 << ": ";
		cin >> angka[i];
	}
	
	cout << endl;

	// Display hasil
	for (int i = 0; i < 5; i++) {
		cout << "Angka: " << angka[i] << " - Jumlah Angka Ganjil: " << ganjil(angka[i]) << endl;
	}
}

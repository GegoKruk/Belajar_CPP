#include <iostream>
using namespace std;

// Program Menghitung Kalimat Ganjil

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

	int angka[5];
	
	for (int i = 0; i < 5; i++){
		cout << "Angka " << i+1 << ": ";
		cin >> angka[i];
	}
	
	cout << endl;
	
	for (int i = 0; i < 5; i++) {
		cout << "Angka: " << angka[i]
		<< " - Jumlah Ganjil: " << ganjil(angka[i]) << endl;
	}
}

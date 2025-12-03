#include <iostream>
using namespace std;

// Soal 4
/*
    Berikut program utama untuk menginput sebuah bilangan bulat dalam satuan milimeter(mm). 
	Lengkapi dengan membuat function mengkonversi inputan bilangan mmilimeter(mm) ke dalam satuan
	Kilometer(km), meter(m), centimeter(cm), milimeter(mm), dan hasilnya ditampilkan di program utama. 
	
	Ketentuan: 
		Bilangan hasil bulat tidak decimal, 
		1 km = 1.000.000 mm
		1 m = 1.000 mm
		1 cm = 10 mm
*/

int itungKm (int mm) {
	return mm / 1000000;
}

int itungM (int mm) {
	return (mm % 1000000) / 1000;
}

int itungCm (int mm) {
	return (mm % 1000) / 10;
}

int itungMm (int mm) {
	return mm % 10;
}


int main () {
	
	int mm;
	
	cout << "Bilangan (milimeter): "; cin >> mm;
	
	int km 	 = itungKm(mm);
	int m 	 = itungM(mm);
	int cm 	 = itungCm(mm);
	int mili = itungMm(mm);
	
	cout << "Hasil Konversi: ";
	cout << km << " km, " << m << " m, " << cm << " cm, "<< mili << " mm ";
}

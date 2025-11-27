#include <iostream>
using namespace std;

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
	int km = itungKm(mm);
	int m = itungM(mm);
	int cm = itungCm(mm);
	int mili = itungMm(mm);
	cout << "Hasil Konversi: ";
	cout << km << " km, " 
		 << m << " m, " 
		 << cm << " cm, "
		 << mili << " mm ";
		 
	}

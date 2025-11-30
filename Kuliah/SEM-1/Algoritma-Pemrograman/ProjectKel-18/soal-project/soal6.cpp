#include <iostream>
using namespace std;

int itungJam (int dtk) {
	return dtk / 3600;
}

int itungMenit (int dtk) {
	return (dtk % 3600) / 60;
}

int itungDetik (int dtk) {
	return dtk % 60;
}

int main () {
	
	int dtk;
	
	cout << "Bilangan (Detik): "; cin >> dtk;
	
	int jam = itungJam(dtk);
	int mnt = itungMenit(dtk);
	int detik = itungDetik(dtk);
	
	cout << dtk <<" Detik = ";
	cout << jam << " Jam " << mnt << " Menit " << detik << " Detik ";
}

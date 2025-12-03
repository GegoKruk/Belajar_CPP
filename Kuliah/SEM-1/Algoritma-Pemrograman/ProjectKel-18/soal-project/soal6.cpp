#include <iostream>
using namespace std;

// Soal 6
/*
	Buatlah program utama untuk menginput sebuah bilangan bulat dalam satuan detik. 
	Lengkapi dan buatlah procedure/function untuk mengkonversi inputan 
	bilangan detik tersebut ke dalam satuan jam, menit, dan detik
	Hasilnya ditampilkan di program utama.
*/

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
	cout << "Bilangan (Detik): "; 
	cin >> dtk;
	
	int jam = itungJam(dtk);
	int mnt = itungMenit(dtk);
	int detik = itungDetik(dtk);
	
	cout << dtk <<" Detik = ";
	cout << jam << " Jam " << mnt << " Menit " << detik << " Detik ";
}

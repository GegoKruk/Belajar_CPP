#include <iostream>
using namespace std;

void cobaFunction(){
	cout<<"Halo Semuanya Ini Function pertama yang nanti akan dipanggil"<<endl;
}

void hitungPeregiPanjang(){
	int panjang = 10;
	int lebar = 5;
	int luasPersegiPanjang = panjang * lebar;
	cout << "Luas sebuah persegi panjang dengan panjang 10 cm dan lebar 5 cm adalah : "<< luasPersegiPanjang << endl;
}

void soalStudiKasus1(){
	int hargaBuku = 50000;
	int hargaBolpen = 5000;
	int jumlahBuku = 2;
	int jumlahBolpen = 3;
	
	int totalHargaBuku = hargaBuku*jumlahBuku;
	int totalHargaBolpen = hargaBolpen*jumlahBolpen;
	
	int totalHarga = totalHargaBuku + totalHargaBolpen;
	cout<<"Harga Buku : "<<hargaBuku<<endl;
	cout<<"Harga Bolpen : "<< hargaBolpen<<endl;
	cout<<"Andi Membeli Buku sebanyak 2 buah dan bolpen sebanyak 3 buah"<<endl;
	cout<<"Maka total harga yang harus dibayarkan oleh andi adalah : "<<totalHarga<<endl;
}

void inputOutput(){
	string namaLengkap;
	int umur;
	
	cout<<"Tuliskan Nama Lengkapmu : "<<endl;
	getline(cin, namaLengkap);
	cout<<"Berapa Umur Kamu?"<<endl;
	cin>>umur;
	
	cout<<"Siap! Data diri kamu sudah masuk : "<<endl;
	cout<<"1. Nama Lengkap : "<<namaLengkap<<endl;
	cout<<"2. Umur : "<<umur<<endl;
}

void studiKasus2(){
	string nama;
	string nim;
	string kelas;
	
	cout<<"Masukkan Nama Lengkap : "; 
	getline(cin,nama);
	cout<<"Masukkan NIM : "; 
	cin>>nim;
	cout<<"Masukkan Kelas : ";
	cin>>kelas;
	
	cout<<" "<<endl;
	
	cout<<"Data Anda Sudah Masuk!"<<endl;
	cout<<"Nama Lengkap : "<<nama<<endl;
	cout<<"NIM : "<<nim<<endl;
	cout<<"Kelas : "<<kelas;
}

int main(){
	//cobaFunction();
	//hitungPeregiPanjang();
	//soalStudiKasus1();
	//inputOutput();
	studiKasus2();
	
	cin.get();
	return 0;
}

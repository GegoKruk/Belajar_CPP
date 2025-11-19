#include <iostream>
using namespace std;

string username = "algo";
string password = "gampang";
string voucher = "JPYUM";
string inputUsername;
string inputPassword;
string inputVoucher;
int stockMenu = 100;
int pelanggan = 0;


//RESPONSI - GEGA RAMADHAN - IF E - 123250112

void functionAutentikasi(){
	
	bool autentikasi = false;

	do{
		cout << "\n=====[Login Kasir]=====" << endl;
		cout << "Masukkan Username: ";
		cin >> inputUsername;
		cout << "Masukkan Password: ";
		cin >> inputPassword;
		
		if (username == inputUsername && password == inputPassword){
			cout << "\n=====[Login Berhasil]=====" << endl;
			autentikasi = true;
		} else {
			cout << "\n=====[Username atau Password Salah]=====" << endl;
			cout << "Login Gagal, program berhenti" << endl;
			autentikasi = true;
			exit(0);
		}
	} while (autentikasi == false);
}

void tampilkanPesanan(){
	cout << "\n--- Daftar Menu ---" << endl;
	cout << "[1] Kopi Susu  : 18000" << endl;
	cout << "[2] Teh Lemon  : 15000" << endl;
	cout << "[3] Roti Bakar : 12000" << endl;
}

int main(){
	system("CLS");	
	
	int kopi = 18000;
	int tehlemon = 15000;
	int rotibakar = 12000;
	int totalHarga = 0;
	
	string namaPelanggan[stockMenu];
	int menuPilihan[stockMenu];
	string namaMenuPilihan[stockMenu];
	int jumlahMenuPilihan[stockMenu];
	int totalHargaPelanggan[stockMenu];
	int pembayaran[stockMenu];
	int kembalian[stockMenu];
	
	functionAutentikasi();
	
	bool isDiskon;
	bool exitmenu = false;
	
	do{
		cout << "\n=====[Kasir Kafe Kopi Senja]=====" << endl;
		cout << "1. Tampilkan Daftar Menu" << endl;
		cout << "2. Buat Pesanan Baru" << endl;
		cout << "3. Lihat Riwayat Pesanan" << endl;
		cout << "4. Exit" << endl;
		cout << "Pilih Menu: ";
		int inputPilihanMenu;
		cin >> inputPilihanMenu;
		
		switch (inputPilihanMenu){
			case 1:
				cin.ignore(1000, '\n');
				tampilkanPesanan();
				
			break;
			case 2:
				cin.ignore(1000, '\n');
				cout << "\n--- Buat Pesanan Baru ---" << endl;
				cout << "Masukkan Nama Pelanggan: ";
				getline(cin, namaPelanggan[pelanggan]);
				
				tampilkanPesanan();
				
				cout << "Masukkan Nomor Menu (1-3): ";
				cin >> menuPilihan[pelanggan];
				if (menuPilihan[pelanggan] == 1){
					totalHarga += kopi;
					namaMenuPilihan[pelanggan] = "Kopi Susu";
				} else if (menuPilihan[pelanggan] == 2){
					totalHarga += tehlemon;
					namaMenuPilihan[pelanggan] = "Teh Lemon";
				} else if (menuPilihan[pelanggan] == 3){
					totalHarga += rotibakar;
					namaMenuPilihan[pelanggan] = "Roti Bakar";
				}
				
				cout << "Masukkan Jumlah: ";
				cin >> jumlahMenuPilihan[pelanggan];
				
				totalHargaPelanggan[pelanggan] = totalHarga * jumlahMenuPilihan[pelanggan];
				cout << "Total Harga : "<< totalHargaPelanggan[pelanggan] << endl;
				
				char gunakanVoucher;
				cout << "Gunakan Voucher? (y/n)";
				cin >> gunakanVoucher;
				
				if (gunakanVoucher == 'Y' || gunakanVoucher == 'y'){
					cout << "Masukkan Kode Voucher: ";
					cin >> inputVoucher;
					
					if (voucher == inputVoucher){
						int diskon = totalHargaPelanggan[pelanggan] * 5 / 100;
						totalHargaPelanggan[pelanggan] -= diskon;
						totalHarga = 0;
						cout << "Diskon 5% Diterapkan!" << endl;
						isDiskon = true;
						
					} else {
						cout << "Voucher Tidak Valid!" << endl;
						isDiskon = false;
					}
					
				} else {
					cout <<"Anda Tidak Menggunakan Voucher!"<< endl;
					isDiskon = false;
				}
				
				bool paymentloop;
				
				do{
					cout << "Total tagihan yang harus dibayarkan : "<< totalHargaPelanggan[pelanggan] << endl;
					cout << "Masukkan Nominal Pembayaran : ";
					cin >> pembayaran[pelanggan];
					
					if (pembayaran[pelanggan] > totalHargaPelanggan[pelanggan]){
						kembalian[pelanggan] = pembayaran[pelanggan] - totalHargaPelanggan[pelanggan];
						cout << "Uang Kembalian : " << kembalian[pelanggan];
						paymentloop = false;
					} else if (pembayaran[pelanggan] == totalHargaPelanggan[pelanggan]){
						kembalian[pelanggan] = 0;
						paymentloop = false;
					} else if (pembayaran[pelanggan] < totalHargaPelanggan[pelanggan]){
						cout << "Uang Tidak Cukup!" << endl;
						paymentloop = true;
					} else {
						cout << "Input Tidak Valid!" << endl;
						paymentloop = true;
					}
				} while (paymentloop == true);
			break;
			case 3:
				
				cout << "\n--- Riwayat Pesanan ---" << endl;
				
				for(int i = 0; i < pelanggan; i++){
					cout << "Pesanan Ke-" << i+1 << endl;
					cout << "Nama Pelanggan			: " << namaPelanggan[i] << endl;
					cout << "Pesanan				: " << namaMenuPilihan[i] << endl;
					cout << "Jumlah				: " << jumlahMenuPilihan[i] << endl;
					cout << "Total Bayar			: " << totalHargaPelanggan[i] << endl;
					if (isDiskon == true){
						cout << "(Diskon 5%)" << endl;
					}
					cout << "--------------------------------------------------"<< endl;
				}
			break;
			default:
				cout << "Input Tidak Valid!" << endl;
				cout << "Program Berhenti" << endl;
				exit(0);
			break;
		} 
	totalHarga = 0;
	pelanggan++;
	} while (exitmenu == false);
	
	return 0;
}

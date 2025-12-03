#include <iostream>
using namespace std;

// Soal 8
/*
		Kompetisi sepak bola paling bergengsi di dunia, Piala Dunia, kembali diselenggarakan tahun ini,
	dengan Qatar sebagai tuan rumah. Jika ditarik mundur, Piala Dunia kali pertama diselenggarakan 
	pada 13 - 30 Juli 1930 di Uruguay. Piala Dunia FIFA pertama ini, merupakan kejuaraan dunia 
	untuk tim sepak bola internasional pria. FIFA memilih Uruguay sebagai tuan rumah, sebagai 
	negara yang merayakan seratus tahun konstitusi pertama pada saat itu, dan Tim nasional sepak bola
	Uruguay telah berhasil mempertahankan gelar sepak bola mereka di Olimpiade Musim Panas 1928. 
	Semua pertandingan dimainkan di ibu kota Uruguay, Montevideo, sebagian besar di Stadion Centenario,
	yang dibangun untuk turnamen.
		Tiga belas tim yang mewakili negaranya masing-masing (tujuh dari Amerika Selatan, empat 
	dari Eropa, dan dua dari Amerika Utara) ikut serta dalam turnamen. Beberapa tim Eropa memilih 
	untuk tidak berpartisipasi karena sulitnya perjalanan ke Amerika Selatan. Tim dibagi menjadi 
	empat grup, dengan pemenang dari masing-masing grup maju ke semifinal.
	
	Berdasar ilustrasi di atas bantulah FIFA untuk mengelola data tim peserta kejuaraan Piala Dunia 
	dengan cara membuat program bahasa C++ dengan ketentuan sebagai berikut:
	
	- Menggunakan array untuk menyimpan semua nama tim yang ikut serta dalam kejuaraan;
	- Terdapat menu/modul Input data tim yang berupa prosedur/fungsi dan diinputkan satu-persatu menggunakan looping for;
	- Terdapat menu/modul untuk menampilkan data tim yang berupa prosedur/fungsi dan menampilkan data tim satu-persatu dengan menggunakan looping while;
	- Tampilan menu boleh menggunakan if-else maupun case.
*/

string tim[20];
int jumlahTim = 0;

void menu () {
	system("cls");

	cout << "=== MENU ===\n";
	cout << "1. Input Data Tim\n";
	cout << "2. Lihat Data Tim\n";
	cout << "3. Keluar\n";
}

void inputdata () {
	system("cls");

	cout << "=== Input Data Tim ===\n";
	cout << "Jumlah Tim: "; 
	cin >> jumlahTim;
	cin.ignore();
	
	for (int i = 0; i < jumlahTim; i++) {
		cout << "Tim " << i + 1 << ": ";
		getline (cin, tim[i]);
	}
}

void showdata () {
	system("cls");
	
	if (jumlahTim == 0) {
        cout << "Belum Ada Data Tim\n";
        cout << "\nTekan enter untuk kembali ke menu...";
		cin.get();
        return;
    }
	
	int i = 0;
	cout << "=== Lihat Data Tim ===\n";
	
	while (i < jumlahTim) {
		cout << "Tim " << i+1 << ": ";
		cout << tim[i] << endl;
		i++;
	}

	cout << "\nTekan enter untuk kembali ke menu...";
	cin.get();
}

int main () {
	
	while (true) {

		// Panggil Function Menu
		menu();

		int pilih;
		cout << "Pilih: "; cin >> pilih;
		cin.ignore();
		
		switch (pilih) {
			case 1: 
				inputdata();
			break;
			case 2:
				showdata();
			break;
			case 3:
				system ("cls");
				cout << "\n===Program Berakhir";
			return 0;
			default: 
				cout << "Invalid";
		}
	}
}

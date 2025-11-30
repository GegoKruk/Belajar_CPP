#include <iostream>
using namespace std;

string warna[13] = {
    "",
    "1.  Orange",
    "2.  Red-Orange",
    "3.  Red",
    "4.  Red-Violet",
    "5.  Violet",
    "6.  Blue-Violet",
    "7.  Blue",
    "8.  Blue-Green",
    "9.  Green",
    "10. Yellow-Green",
    "11. Yellow",
    "12. Yellow-Orange"
};

void menu () {
	cout << "--------------------------------------------------\n";
	cout << "Nama            : Rassya Arma Putra\n";
	cout << "Nim             : 123250118\n";
	cout << "--------------------------------------------------\n";
	
	cout << "Program Menentukan Notasi, Sifat Warna, dan Perpaduan Warna Harmonis\n";
	cout << "Warna-warna: \n";
	cout << " 1.  Orange        2.  Red-Orange        3.  Red\n";
	cout << " 4.  Red-Violet    5.  Violet            6.  Blue-Violet\n";
	cout << " 7.  Blue          8.  Blue-Green        9.  Green\n";
	cout << " 10. Yellow-Green  11. Yellow            12. Yellow-Orange\n";
	cout << endl;
	}
void submenu() {
	cout << "Perpaduan Warna Harmonis\n";
	cout << "a. Perpaduan Warna Analogus\n";
	cout << "b. Perpaduan Warna Complementary\n";
	cout << "c. Perpaduan Warna Split Complementary\n";
	cout << "d. Perpaduan Warna Triadic Complementary\n";
	cout << "e. Perpaduan Warna Tetrad Complementary\n";
	}
	
int pilih;
char pilih2;

void notasi () {
	cout << warna[pilih] << endl;
	if (pilih == 3 || pilih == 11 || pilih == 7) {
		cout << "Notasi Warna: Primer\n";
		}
	else if (pilih == 1 || pilih == 9 || pilih == 5) {
		cout << "Notasi Warna: Sekunder\n";
		}
	else {
		cout << "Notasi Warna: Tersier\n";
		}
	}
void sifat () {
	if (pilih == 1 || pilih == 2 || pilih == 3 ||
	    pilih == 4 || pilih == 11 || pilih == 12) {
		cout << "Sifat Warna: Hangat\n";
		cout << endl;
		}
	else {
		cout << "Sifat Warna: Dingin\n";
		cout << endl;
		}
	}
void tipe () {
	cout << endl;
	if (pilih2 == 'a' || pilih2 == 'A') {
		cout << "Analogus: \n";
		string analogus  = warna[pilih] + "\n" + warna[(pilih % 12) + 1] + "\n" + 
						   warna[(pilih - 2 + 12) % 12 + 1] + "\n";
		string analogus2 = warna[pilih] + "\n" + warna[(pilih % 12) + 1] + "\n" +
						   warna[(pilih % 12) + 2] + "\n";
		string analogus3 = warna[pilih] + "\n" + warna[(pilih - 2 + 12) % 12 + 1] + "\n" +
						   warna[(pilih - 3 + 12) % 12 + 1] + "\n";
		cout << analogus << endl << analogus2 << endl << analogus3;
		}
	else if (pilih2 == 'b' || pilih2 == 'B') {
		cout << "Complementary: \n";
		string comp = warna[pilih] + "\n" + warna[(pilih + 6 - 1 ) % 12 + 1];
		cout << comp; 
		}
	else if (pilih2 == 'c' || pilih2 == 'C') {
		cout << "Split Complementary: \n";
		string split = warna[pilih] + "\n" + warna[(pilih + 6 - 1 ) % 12 + 2] + "\n" + 
					   warna[(pilih + 6 - 1 ) % 12];
		cout << split;
		}
	else if (pilih2 == 'd' || pilih2 == 'D') {
		cout << "Triadic Complementary\n";
		string triad = warna[pilih] + "\n" + warna[(pilih + 4 - 1) % 12 + 1] + "\n" +
					   warna[(pilih + 8 - 1) % 12 + 1];
		cout << triad;
		}
	else if (pilih2 == 'e' || pilih2 == 'E') {
		cout << "Tetrad Complementary: \n";
		string tetrad = warna[pilih] + "\n" + warna[(pilih + 3 - 1) % 12 + 1] + "\n" + 
						warna[(pilih + 6 - 1) % 12 + 1] + "\n" +
						warna[(pilih + 9 - 1) % 12 + 1];
		cout << tetrad;
		}
	else {
		cout << "Input Tidak Valid!\n";
		}
		
	}
	 
int main () {
	while (true) {
	system("cls");
	menu();
	cout << "Pilihan Warna Nomor (0. Untuk Keluar): "; cin >> pilih;
	if(cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Input Harus Angka!\n";
    cin.get();
    continue;
			}
	cout << endl;
	
	switch (pilih) {
	
    case 1 ... 12:
        notasi();
        sifat();
        submenu();
        cout << "Pilihan: "; cin >> pilih2;
        tipe();
    break;
 
    default:
    cout << "Input Tidak Valid, Coba Lagi!\n\n";
    break;
    
    case 0: return 0;
			}
	cout << "\n\nTekan Enter Buat Kembali ke Menu...";
	cin.ignore();
	cin.get(); 
	system("cls");
		}
	}

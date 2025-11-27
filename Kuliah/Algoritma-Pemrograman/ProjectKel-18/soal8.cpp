#include <iostream>
using namespace std;

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
	cout << "Jumlah Tim: "; cin >> jumlahTim;
	cin.ignore();
	for (int i = 0; i < jumlahTim; i++) {
		cout << "Tim " << i+1 << ": ";
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
	int pilih;
	while (true) {
		menu();
		cout << "Pilih: "; cin >> pilih;
		cin.ignore();
	switch (pilih) {
		case 1: 
		inputdata();
		break;
		
		case 2:
		system ("cls");
		showdata();
		break;
		
		case 3:
		system ("cls");
		cout << "\nProgram Berakhir";
		return 0;
		
		default: cout << "Invalid";
		}
		}

	}

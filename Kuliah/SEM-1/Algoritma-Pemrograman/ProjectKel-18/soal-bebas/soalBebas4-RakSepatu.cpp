#include <iostream>
using namespace std;

// Deklarasi
string NamaPemilikSepatu[5];
int NimPemilikSepatu[5];
string JurusanPemilikSepatu[5];
string MerkSepatu[5];
int penyimpanan = 0;

void menu();

void nimNama(){
    cout << "---------------------------------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan    | Nama : Rassya Arma Putra    |" << endl;
    cout << "| NIM  : 123250112        | NIM  : 123250118            |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void inputTidakValid(){
    cout << "=====[Input Tidak Valid - Program Berhenti]=====" << endl;
    exit(0);
}

void simpanSepatu(){
    char pilihanCase1;

    do {
        if (penyimpanan >= 5) {
            cout << "\nRak sepatu sudah penuh!" << endl;
            break;
        }

        cout << "\n-----------------------------------------------------" << endl;
        cout << "\n=====[Rak Penyimpanan Ke-" << penyimpanan + 1 << "]=====" << endl;

        cout << "1. Nama Lengkap     : ";
        getline(cin, NamaPemilikSepatu[penyimpanan]);

        cout << "2. NIM              : ";
        cin >> NimPemilikSepatu[penyimpanan];
        cin.ignore(100, '\n');

        cout << "3. Jurusan          : ";
        getline(cin, JurusanPemilikSepatu[penyimpanan]);

        cout << "4. Merk Sepatu      : ";
        getline(cin, MerkSepatu[penyimpanan]);

        penyimpanan++; // update posisi terakhir

        cout << "\n--> Ingin simpan sepatu lain? (Y/N): ";
        cin >> pilihanCase1;
        cin.ignore(100, '\n');

    } while ((pilihanCase1 == 'y' || pilihanCase1 == 'Y') && penyimpanan < 5);

    // Kembali ke menu
    menu();
}

void cekSepatu(){
    cout << "\n=====[Data Sepatu Tersimpan]=====" << endl;

    if (penyimpanan == 0) {
        cout << "Rak masih kosong" << endl;
    } else {
        for (int i = 0; i < penyimpanan; i++) {
            cout << "\n=====[Rak Penyimpanan Ke-" << i + 1 << "]=====" << endl;
            cout << "Nama    : " << NamaPemilikSepatu[i] << endl;
            cout << "NIM     : " << NimPemilikSepatu[i] << endl;
            cout << "Jurusan : " << JurusanPemilikSepatu[i] << endl;
            cout << "Merk    : " << MerkSepatu[i] << endl;
        }
    }

    cout << "\nKetik apapun untuk kembali ke menu : ";
    cin.get();
    menu();
}

void menu(){

    // Membersihkan tampilan
	system("CLS");

	// panggil function nim nama
	nimNama();

    // intro program
	cout << "\n========[Program Penyimpanan Sepatu Mahasiswa]========" << endl; 
	cout << "\n[Rak Sepatu 3x3]____________" << endl;
	cout << "| 1. Simpan Sepatu         |" << endl;
	cout << "| 2. Cek Isi Rak Sepatu    |" << endl;
	cout << "| 3. Keluar                |" << endl;
	cout << "|__________________________|" << endl;

    // Pilihan Menu
    int pilihanMenu;
	cout << "Pilih (1-3) : ";
	cin >> pilihanMenu;
    cin.ignore(100, '\n');

    switch (pilihanMenu){
        case 1:
            simpanSepatu();
        break;
        case 2:
            cekSepatu();
        break;
        case 3:
            cout << "=====[Terima Kasih Sudah Mampir! - Program Berhenti]=====" << endl;
            exit(0);
        break;
        default:
            inputTidakValid();
        break;
    }
}

int main(){

	// panggil function menu
	menu();
}


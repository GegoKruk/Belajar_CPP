#include <iostream>
using namespace std;

/// untuk main function
int pilihan;
char ulang;

// Soal 1: Bulan Kelahiran
void soalBulanKelahiran() {
    system("CLS");

    int M = 12;
    int N;
    int R;

    cout << "\n====== Soal 1: Bulan Kelahiran ======\n";

    cout << "\nBerapa jumlah minimum orang (N) yang dibutuhkan agar setidaknya \n";
    cout << "ada R orang yang lahir di bulan yang sama? (M = 12)\n";

    //input user
    cout << "\nMasukkan nilai R (minimal orang di bulan yang sama, R > 1): ";
    cin >> R;

    if (R <= 1) {
        cout << "R harus lebih dari 1.\n";
        return;
    }

    N = M * (R - 1) + 1;

	cout << "\n====== Penyelesaian ====== \n";
    cout << "\nDiketahui:\n";
    cout << "     Jumlah bulan (M): " << M << endl;
    cout << "     Minimal orang di bulan yang sama (R): " << R << endl;
    cout << "Hitung: \n";
    cout << "     N = " << M << " * (" << R << " - 1) + 1 = " << N << endl;
    cout << "Jadi, minimal harus ada " << N << " orang.\n";
}

// Soal 2: Pasangan Kaos Kaki
void soalKaosKaki() {
    system("CLS");

    int R = 2;
    int M;
    int N;

    cout << "\n====== Soal 2: Pasangan Kaos Kaki ======\n";

    cout << "\nDari laci berisi kaos kaki dengan M warna berbeda, berapa \n";
    cout << "jumlah minimum kaos kaki (N) yang harus diambil agar \n";
    cout << "TERJAMIN mendapat sepasang (R = 2) kaos kaki serasi?\n";

	//input user
    cout << "\nMasukkan jumlah warna kaos kaki (M > 0): ";
    cin >> M;

    if (M <= 0) {
        cout << "M harus lebih dari 0.\n";
        return;
    }

    N = M * (R - 1) + 1;
    
	cout << "\n====== Penyelesaian ====== \n";
    cout << "\nDiketahui:\n";
    cout << "  Jumlah warna (M): " << M << endl;
    cout << "  Minimal sepasang (R): " << R << endl;
    cout << "Hitung: \n";
    cout << "     N = " << M << " * (" << R << " - 1) + 1 = " << N << endl;
    cout << "Jadi, minimal harus ambil " << N << " kaos kaki agar dijamin dapat sepasang.\n";
}

// Soal 3: Titik pada Bidang 2D
void soalTitikBidang() {
    system("CLS");
    
    int R;
    int M;
    int N;

    cout << "\n====== Soal 3: Titik pada Bidang 2D ======\n";

    cout << "\nDalam ruang 2D, titik (x,y) memiliki koordinat (x,y) dengan x, y \n";
    cout << "bernilai 1 sampai M. Berapa minimum titik (N) yang dijamin \n";
    cout << "memiliki R titik dengan koordinat yang sama? (M*M sarang)\n";

	//input user
    cout << "\nMasukkan nilai M (rentang koordinat, M > 1): ";
    cin >> M;

    if (M <= 1) {
        cout << "M harus lebih dari 1.\n";
        return;
    }

    cout << "Masukkan nilai R (minimal titik di koordinat yang sama, R > 1): ";
    cin >> R;

    if (R <= 1) {
        cout << "R harus lebih dari 1.\n";
        return;
    }

    int jumlahSarang = M * M;
    N = jumlahSarang * (R - 1) + 1;

	cout << "\n====== Penyelesaian ====== \n";
    cout << "\nDiketahui:\n";
    cout << "  Rentang koordinat (M): " << M << endl;
    cout << "  Jumlah kemungkinan titik (M x M): " << jumlahSarang << endl;
    cout << "  Minimal titik di koordinat yang sama (R): " << R << endl;
    cout << "Hitung: \n";
    cout << "     N = " << jumlahSarang << " * (" << R << " - 1) + 1 = " << N << endl;
    cout << "Jadi, minimal harus ada " << N << " titik agar dijamin ada " << R << " titik di koordinat yang sama.\n";
}

// Soal 4: Angka dan Sisa Pembagian
void soalAngkaSisaBagi(){
	system("CLS");
    
    int R = 2;
    int M;
    int N;

    cout << "\n====== Soal 4: Angka dan Sisa Pembagian ======\n";

    cout << "\nDari N bilangan bulat yang diambil, buktikan bahwa pasti ada\n";
    cout << "dua bilangan yang selisihnya kelipatan M.\n";
    cout << "Ini terjadi jika dua bilangan memiliki sisa bagi yang sama terhadap M.\n";
    
    //input user
    cout << "\nMasukkan nilai Pembagi (M > 1): ";
    cin >> M;

    if (M <= 1) {
        cout << "Pembagi (M) harus lebih dari 1.\n";
        return;
    }
    
    N = M * (R - 1) + 1;
    
    cout << "\n====== Penyelesaian ====== \n";
    cout << "\nDiketahui:\n";
    cout << "  Pembagi (M): " << M << endl;
    cout << "  Jumlah kemungkinan Sisa Bagi (Sarang): " << M << endl;
    cout << "  Minimal bilangan yang sisa baginya sama (R): " << R << endl;
    cout << "Hitung: \n";
    cout << "     N = " << M << " * (" << R << " - 1) + 1 = " << N << endl;
    cout << "Jadi, minimal harus ada " << N << " bilangan agar dijamin\n";
    cout << "ada dua bilangan yang selisihnya kelipatan " << M << ".\n";
}

// Main Program
int main() {

    do {
		system("CLS");
		
        cout << "\n===============================\n";
        cout << "|  MENU PIGEONHOLE PRINCIPLE  |\n";
        cout << "===============================\n";
        cout << "1. Soal Bulan Kelahiran\n";
        cout << "2. Soal Pasangan Kaos Kaki\n";
        cout << "3. Soal Titik pada Bidang\n";
        cout << "4. Soal Angka dan Sisa Pembagian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                soalBulanKelahiran();
                break;
            case 2:
                soalKaosKaki();
                break;
            case 3:
                soalTitikBidang();
                break;
			case 4:
                soalAngkaSisaBagi();
                break;
            case 0:
                cout << "Program selesai. Terima kasih!\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
		
		do {
			cout << "\nKembali ke menu? (y/n): ";
			cin >> ulang;
			
			if (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
				cout << "Inputan tidak valid.\n";
			}
		}while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai. Terima kasih!\n";
    return 0;
}
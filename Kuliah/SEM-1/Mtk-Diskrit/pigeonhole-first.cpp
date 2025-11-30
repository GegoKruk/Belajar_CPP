#include <iostream>
#include <cmath>
#include <limits>
#include <conio.h>
#include <iomanip>

using namespace std;

// Deklarasi Global
long double N_objek, M_sarang, R_min, N_hasil;
int pilih;
bool inputValid = false;
char menusoal;

// Fungsi utilitas dari referensi (untuk validasi integer)
bool isInteger(long double num) {
    return num == static_cast<long long>(num);
}

// Prototipe Fungsi Soal
void soalBulanKelahiran();
void soalKaosKaki();
void soalTitikBidang();

// Main Program
int main() {
    system("cls"); 

    do {
        cout << "=================================================" << endl;
        cout << "| PRINSIP SARANG MERPATI (PIGEONHOLE PRINCIPLE) |" << endl;
        cout << "=================================================" << endl;
        cout << "Pilihan Soal PSP: \n";
        cout << "1. Soal Bulan Kelahiran (PSP Dasar)\n";
        cout << "2. Soal Pasangan Kaos Kaki (PSP dengan R tetap)\n";
        cout << "3. Soal Titik pada Bidang (PSP Lanjutan)\n";
        cout << "0. Keluar \n";
        cout << "Pilih: "; 
        
        // Cek input agar berupa integer
        if (!(cin >> pilih)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilih = -1; // Set ke nilai default non-valid
        }
        
        cout << "\033c"; // Clear screen (seperti system("cls"))

        switch (pilih) {
            case 1:
                soalBulanKelahiran();
                break;
            case 2:
                soalKaosKaki();
                break;
            case 3:
                soalTitikBidang();
                break;
            case 0:
                cout << "Program selesai. Terima kasih!\n";
                exit(0);
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }

        if (pilih != 0) {
            cout << "\nKembali ke menu utama (y/n)? ";
            cin >> menusoal;

            if (menusoal != 'Y' && menusoal != 'y') {
                cout << "Program selesai. Terima kasih!\n";
                exit(0);
            }

            cout << "\033c"; // Clear screen setelah kembali
        }

    } while (true);

    return 0;
}

// Implementasi Soal 1: Bulan Kelahiran
void soalBulanKelahiran() {
    cout << "\n===== Soal 1: Bulan Kelahiran (PSP Dasar) =====\n";
    cout << "Berapa jumlah minimum orang (N) yang dibutuhkan agar setidaknya \n";
    cout << "ada R orang yang lahir di bulan yang sama? (M = 12)\n";
    
    // 12 bulan
    M_sarang = 12;
    
    do {
        inputValid = true;
        cout << "Masukkan nilai R (minimum orang di bulan yang sama, R > 1): ";

        if (!(cin >> R_min) || !isInteger(R_min) || R_min <= 1) {
            cout << "Input tidak valid. R harus bilangan bulat > 1.\n";
            inputValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // Perhitungan: N = M * (R - 1) + 1
        N_hasil = M_sarang * (R_min - 1) + 1;

        cout << "\nPress any key to display the answer...\n"; 
        getch();

        cout << "\nPEMBAHASAN:\n";
        cout << "Diketahui: \n";
        cout << "  Jumlah Sarang (M): " << M_sarang << " (bulan)\n";
        cout << "  Minimum Merpati di Sarang (R): " << R_min << " orang\n";
        cout << "Rumus PSP: N = M * (R - 1) + 1\n";
        cout << "Hitung: N = " << M_sarang << " * (" << R_min << " - 1) + 1\n";
        cout << "        N = " << M_sarang << " * " << (R_min - 1) << " + 1\n";
        cout << "        N = " << (M_sarang * (R_min - 1)) << " + 1\n";
        cout << "        N = " << N_hasil << "\n";
        cout << "Jawaban: Dibutuhkan minimum " << N_hasil << " orang.\n";

    } while (!inputValid);
}

// Implementasi Soal 2: Pasangan Kaos Kaki
void soalKaosKaki() {
    cout << "\n=== Soal 2: Pasangan Kaos Kaki (PSP dengan R tetap) ===\n";
    cout << "Dari laci berisi kaos kaki dengan M warna berbeda, berapa \n";
    cout << "jumlah minimum kaos kaki (N) yang harus diambil agar \n";
    cout << "TERJAMIN mendapat sepasang (R = 2) kaos kaki serasi?\n";
    
    R_min = 2; // Sepasang
    
    do {
        inputValid = true;
        cout << "Masukkan nilai M (jumlah warna berbeda, M > 0): ";

        if (!(cin >> M_sarang) || !isInteger(M_sarang) || M_sarang <= 0) {
            cout << "Input tidak valid. M harus bilangan bulat > 0.\n";
            inputValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // Perhitungan: N = M * (R - 1) + 1
        N_hasil = M_sarang * (R_min - 1) + 1;

        cout << "\nPress any key to display the answer...\n"; 
        getch();

        cout << "\nPEMBAHASAN:\n";
        cout << "Diketahui: \n";
        cout << "  Jumlah Sarang (M): " << M_sarang << " (warna)\n";
        cout << "  Minimum Merpati di Sarang (R): " << R_min << " (sepasang)\n";
        cout << "Rumus PSP: N = M * (R - 1) + 1\n";
        cout << "Hitung: N = " << M_sarang << " * (" << R_min << " - 1) + 1\n";
        cout << "        N = " << M_sarang << " * 1 + 1\n";
        cout << "        N = " << N_hasil << "\n";
        cout << "Jawaban: Dibutuhkan minimum " << N_hasil << " kaos kaki.\n";

    } while (!inputValid);
}

// Implementasi Soal 3: Titik pada Bidang
void soalTitikBidang() {
    cout << "\n=== Soal 3: Titik pada Bidang (PSP Lanjutan) ===\n";
    cout << "Dalam ruang 2D, titik (x,y) memiliki koordinat (x,y) dengan x, y \n";
    cout << "bernilai 1 sampai M. Berapa minimum titik (N) yang dijamin \n";
    cout << "memiliki R titik dengan koordinat yang sama? (M*M sarang)\n";
    
    long double M_input;
    
    do {
        inputValid = true;
        cout << "Masukkan nilai M (rentang koordinat, M > 1): ";

        if (!(cin >> M_input) || !isInteger(M_input) || M_input <= 1) {
            cout << "Input M tidak valid. M harus bilangan bulat > 1.\n";
            inputValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            continue;
        }
        
        cout << "Masukkan nilai R (minimum titik koordinat yang sama, R > 1): ";

        if (!(cin >> R_min) || !isInteger(R_min) || R_min <= 1) {
            cout << "Input R tidak valid. R harus bilangan bulat > 1.\n";
            inputValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            continue;
        }

        // Sarang: Jumlah kemungkinan koordinat (M x M)
        M_sarang = M_input * M_input;
        
        // Perhitungan: N = M * (R - 1) + 1
        N_hasil = M_sarang * (R_min - 1) + 1;

        cout << "\nPress any key to display the answer...\n"; 
        getch();

        cout << "\nPEMBAHASAN:\n";
        cout << "Diketahui: \n";
        cout << "  Rentang Koordinat (M_input): " << M_input << "\n";
        cout << "  Jumlah Sarang (M): M_input x M_input = " << M_input << " x " << M_input << " = " << M_sarang << " (kemungkinan koordinat)\n";
        cout << "  Minimum Merpati di Sarang (R): " << R_min << " titik\n";
        cout << "Rumus PSP: N = M * (R - 1) + 1\n";
        cout << "Hitung: N = " << M_sarang << " * (" << R_min << " - 1) + 1\n";
        cout << "        N = " << M_sarang << " * " << (R_min - 1) << " + 1\n";
        cout << "        N = " << (M_sarang * (R_min - 1)) << " + 1\n";
        cout << "        N = " << N_hasil << "\n";
        cout << "Jawaban: Dibutuhkan minimum " << N_hasil << " titik.\n";

    } while (!inputValid);
}
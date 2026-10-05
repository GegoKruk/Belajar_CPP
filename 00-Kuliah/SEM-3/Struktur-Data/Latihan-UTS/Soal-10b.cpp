#include <iostream>
using namespace std;

int main() {

    int data[6] = {50, 30, 60, 20};
    int jumlah = 4;
    int posisi = 1;
    int baru = 40;

    for (int i = jumlah; i > posisi; i--) {
        data[i] = data[i - 1];
    }

    data[posisi] = baru;
    jumlah++;

    cout << "Isi array: ";
    for (int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    cout << "\nJumlah elemen: " << jumlah << endl;
    cout << "Data indeks 2: " << data[2] << endl;
    
    return 0;
}

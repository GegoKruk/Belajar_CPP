#include <iostream>
using namespace std;

void cobaFunction(int &jumlah, double &totalHarga , double hargaSatuan){

    totalHarga = hargaSatuan * jumlah;
}

int main(){

    double totalharga = 0;
    double hargaSatuan = 10.5;
    int jumlah = 25;

    cobaFunction(jumlah, totalharga, hargaSatuan);
    
    cout << "Harga Satuan   : " << hargaSatuan << endl;
    cout << "Jumlah         : " << jumlah << endl;
    cout << "Total Harga    : " << totalharga << endl;

    return 0;
}
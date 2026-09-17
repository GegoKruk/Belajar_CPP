#include <iostream>
#include <string>
using namespace std;


/*
    Soal 1: Pencarian Inventaris Gudang (Linear Search)

    Konteks:
        Sebuah toko elektronik memiliki stok barang yang belum sempat dirapikan (acak). 
        Setiap barang memiliki Kode SKU (String) dan Jumlah Stok (Integer). 
        Karena datanya masih berantakan, kamu diminta membuat fitur pencarian barang 
        untuk admin.

    Tugas:
        Buatlah struct Barang dengan member sku dan stok.
        Masukkan 5 data barang secara acak (contoh: "TV-01", "HP-05", "LAP-02", dst).
        Gunakan Linear Search untuk mencari barang berdasarkan SKU-nya.
        Jika ditemukan, tampilkan jumlah stoknya. Jika tidak ada, tampilkan pesan 
        "Barang Tidak Tersedia".

        Mengapa Linear Search? Karena datanya tidak terurut, admin tidak punya 
        pilihan lain selain mengecek satu-satu dari depan.
*/


struct barang{
    string kodeSku[5] = {
        "TV-01",
        "HP-05",
        "LAP-02",
        "KOM-03",
        "TAB-04"
    };

    int stock[5] = { 10, 5, 6, 9, 2 };
};

barang dicari;

void soal1(){
    cout << "\n==========[SOAL 1 - Linear Search]==========" << endl;
    cout << "\n[Menu - Pilih Barang yang dicari]----------" << endl;
    cout << "1. TV-01" << endl;
    cout << "2. HP-05" << endl;
    cout << "3. LAP-02" << endl;
    cout << "4. KOM-03" << endl;
    cout << "5. TAB-04" << endl;
    cout << "\nMasukkan Kode SKU  : ";
    string pilihanUser;
    getline(cin, pilihanUser);

    bool found = false;

    for(int i = 0; i < 5; i++){
        if(pilihanUser == dicari.kodeSku[i]){
            found = true;
            cout << "\nData Ditemukan!" << endl;
            cout << "Jumlah Stock : " << dicari.stock[i] << endl;
        }
        else{
            continue;
        }
    }

    if(found == false){
        cout << "\nData Tidak Ditemukan!" << endl;
    }

    cout << "\nProgram Selesai - Terima kasih" << endl;

}

int main(){

    soal1();

    return 0;
}
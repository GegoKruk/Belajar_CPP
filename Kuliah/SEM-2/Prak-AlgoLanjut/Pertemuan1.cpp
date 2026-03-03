#include <iostream>
using namespace std;

int main(){

    cout << "\n---------[Array 2 Dimensi]-----------" << endl;

    //Deklarasi Array
    int cobaArray[2][3]{
        {1,2,3},
        {4,5,6}
    };

    // Penampilan Array baris dulu
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << cobaArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n---------[Struct]-----------" << endl;

    // Membuat Struct (Blurprint)
    struct Mahasiswa{
        int umur;
        string nama;
        float ipk;
    };
    
    // Membuat Object 
    Mahasiswa mhs1;

    // Mengisi Data
    mhs1.umur = 15;
    mhs1.nama = "Sawitanto";
    mhs1.ipk = 3.9;
    
    // Menampilkan Data
    cout << "Umur Mahasiswa : " << mhs1.umur << endl;
    cout << "Nama Mahasiswa : " << mhs1.nama << endl;
    cout << "IPK Mahasiswa  : " << mhs1.ipk << endl;

    cout << "\n---------[Struct dalam Struct]-----------" << endl;

    // Membuat Struct (Blurprint)
    struct Buku{
        string nama;
        float ipk;
    };
    
    // Membuat Object 
    Mahasiswa mhs1;

    // Mengisi Data
    mhs1.umur = 15;
    mhs1.nama = "Sawitanto";
    mhs1.ipk = 3.9;
    
    // Menampilkan Data
    cout << "Umur Mahasiswa : " << mhs1.umur << endl;
    cout << "Nama Mahasiswa : " << mhs1.nama << endl;
    cout << "IPK Mahasiswa  : " << mhs1.ipk << endl;
    
}
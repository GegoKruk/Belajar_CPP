#include <iostream>
using namespace std;

int main (){
    int nilai[4] = {10,20,30,40};

    nilai[1] = 25;
    nilai[3] = nilai[0] + nilai[2];

    for (int i = 0; i < 4; i++){
        cout << "Nilai : " << nilai[i] << endl;
    }

    cout  << endl;
    cout << "Index 2 : " << nilai[2] << endl;
    return 0;

    /*
        Soal  : Tuliskan Hasil Running Program

        Nilai : 10
        Nilai : 25
        Nilai : 30
        Nilai : 40
        
        Index 2 : 30
    */ 
}
#include <iostream>
using namespace std;

// Praktikum Algoritma Pemrograman
// Function
// 27 Oktober 2025


// Fungsi Rekursif 
    /*
        Memanggil dirinya sendiri
        Seperti Looping, tapi lebih memakan memory
    */

int x = 10;
int y = 1;

void pertama(){
    cout << x << endl;
    x++;
}

void kedua(int loop){
    cout << y << endl;
    y++;

    pertama();
    
    loop++;
    if (loop > 10){
        return;
    } else {
        kedua(loop);
    }
}  

int main(){
    
    kedua(0);

    cin.get();
    return 0;
}
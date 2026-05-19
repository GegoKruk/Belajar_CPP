#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    
    FILE *f2;
    f2 = fopen("C-02-FileBiner.dat", "wb");
    
    if(f2 == NULL){
        cout << "File Gagal Dibuat [!]" << endl;
        exit(1);
    }

    int angka = 12345;
    int angka2 = 222;

    putw(angka, f2);
    putw(angka2, f2);

    fclose(f2);


    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define CTRL_Z 26

using namespace std;

int main(){

    FILE *namapointer;
    namapointer = fopen("C-03-InputConsole.txt", "w+");
    
    if (namapointer == NULL){
        cout << "File Gagal Dibuat [!]" << endl;
        exit(1);
    }

    char karakter;
        
    while((karakter = getchar()) != ' '){
        fputc(karakter, namapointer);
    }

    fclose(namapointer);

    return 0;
}
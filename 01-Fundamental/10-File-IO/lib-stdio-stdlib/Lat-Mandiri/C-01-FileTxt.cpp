#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

    FILE *namapointer;
    namapointer = fopen("C-01-FileTxt.txt", "w");
    
    if (namapointer == NULL){
        cout << "File Gagal Dibuat [!]" << endl;
        exit(1);
    }
    
    char karakter = 'g';
    string kata2 = "Namaku Gega Ramadhan";
    
    fputc('h' ,namapointer);
    fputc('\n' ,namapointer);
    fputs("Haloo Ges ini nyoba string\n" ,namapointer);
    fputs(kata2.c_str(), namapointer);
    
    fclose(namapointer);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

void coba(int array[], int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1 ; j++){
            int temp;
            if (array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(){

    const int jumlah_siswa = 10;
    int data_nilai[jumlah_siswa] = {90,78,65,78,77,95,87,70,80,65};

    coba(data_nilai, jumlah_siswa);

    for (int i = 0; i < jumlah_siswa; i++){
        cout << " - Siswa [" << i+1 << "] : " << data_nilai[i] << endl;
    }
    
}
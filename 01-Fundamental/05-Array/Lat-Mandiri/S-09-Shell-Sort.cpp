#include <iostream>
using namespace std;

void shell_sort(int array[], int size){
    for (int gap = size / 2; gap > 0; gap /= 2){
        
        for (int i = gap; i < size; i++){
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j-gap] > temp; j -= gap){
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}


int main(){
    int data_size = 10;
    int data_angka[] = {9,5,7,3,2,5,2,7,4,2};

    shell_sort(data_angka, data_size);

    cout << "Data Urut : " << endl;
    for (int i = 0; i < data_size; i++){
        cout << i+1 << ". " << data_angka[i] << endl;
    }
    
}
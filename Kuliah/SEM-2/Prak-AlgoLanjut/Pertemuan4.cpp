#include <iostream>
using namespace std;

// MATERI SORTHING - BUBBLE SHORT

void latihan(){

    // Data Array
    int n = 10;
    int dataArray[n] = {9,5,2,7,6,10,4,1,8,3};

    cout << "\n\n==========[ COBA BUBBLE SHORT ]==========" << endl;
    cout << "---> Kondisi Data Awal : ";
    for(int i = 0; i < n; i++){
        cout << dataArray[i] << ", ";
    }

    // Proses Bubble Short
    for(int i = 0; i < n; i++){

        for(int j = 1; j < n; j++){

            if(dataArray[j-1] > dataArray[j]){

                int temp = dataArray[j-1];
                dataArray[j-1] = dataArray[j];
                dataArray[j] = temp;
            }
        }
    }

    
    cout << "\n\n---> Kondisi Data Akhir : ";
    for(int i = 0; i < n; i++){
        cout << dataArray[i] << ", ";
    }

}

int main(){

    latihan();

    return 0;
}
#include <iostream>
#include "log.h" 

using namespace std;

void tulisAntrean(ofstream& fileBaru, int totalAntrean){
    for (int i = 0; i < totalAntrean; i++){
        fileBaru << "Antrean ke-" << i+1 << " Pesanan Baru [!]" << endl;
    }
}
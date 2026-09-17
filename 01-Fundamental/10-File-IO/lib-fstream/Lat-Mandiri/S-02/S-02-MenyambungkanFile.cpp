#include <iostream>
#include <fstream>
#include "log.h"

using namespace std;

int main(){
    cout << "==========[SOAL 2 - Menyambungkan File + Menulis File]==========" << endl;

    ofstream fileBaru("filebaru.txt", ios::app);

    if(!fileBaru.is_open()){
        cerr << "[!] File Gagal Dibuat" << endl;
        return 1;
    }

    int totalAntrean = 10;

    tulisAntrean(fileBaru, totalAntrean);

    fileBaru.close();
}
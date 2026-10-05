#include <iostream>
using namespace std;

int main (){

    int nilai = 75;
    int *p = &nilai;

    *p = 90;

    /*
        Soal    : Jelaskan makna &nilai, p, dan *p
        Jawaban :
            1. &nilai
                Merupakan addressof, ekspresi untuk mendapatkan alamat memori dari variabel nilai

            2. p 
                Merupakan variabel pointer yang bertipe int*. Variabel ini bertugas menyimpan alamat memori dari variabel nilai
                
            3. *p, adalah Ekspresi Dereference, operasi untuk mengakses atau mengubah nilai yang berada di alamat memori yang ditunjuk oleh p 

            4. Nilai ssekarang berisi 90
    */

    return 0;
}
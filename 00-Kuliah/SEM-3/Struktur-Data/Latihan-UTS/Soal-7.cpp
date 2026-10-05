#include <iostream>
using namespace std;

int main (){
    int a = 10;
    int b = 20;
    int *p = &a;
    int *q = &b;

    cout << "Nilai : " << a << endl;
    cout << "Nilai : " << b << endl << endl;
    
    *p = *q + 5;
    q = p;

    cout << "Nilai : " << a << endl;
    cout << "Nilai : " << b << endl << endl;
    
    *q = 30;
    cout << "Nilai : " << a << endl;
    cout << "Nilai : " << b << endl << endl;

    /*
        Soal    : Pengaruh *p = *q + 5; dan q = p; 
        Jawaban :

        a.  *p = *q + 5;
            *q berisi alamat dari variabel b, dimana isi nilainya adalah 20
            sehingga *p + 5 hasilnyya adalah 25;

            *p berisi alamat dari variabel a, dimana isi nilainya adalah 10
            operasi *p = *q + 5, adalah mengganti variabel a yang bernilai 10 dengan nilai baru hasil penjumlahan *q + 5
            sehingga hasilnya variabel a bernilai 25

        b.  q = p
            q berisi alamat dari variabel b
            p berisi alamat dari variabel a

            operasi q = p bermaksud mengisi variabel q yang berisi alamat b menjadi beralamat a
    */

    return 0;
}
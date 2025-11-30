/* 

    {kalau di algoritma ini adalah komentar pakai kurawal buka tutup}
    {tidak di proses program algoritma}

*/

#include <iostream>
#define phi 3.14
using namespace std;

int main(){
    float jariJari, luas, keliling;
    
    cout << "Masukkan nilai jari-jari lingkaran : ";
    cin >> jariJari;
    
    keliling = 2 * phi * jariJari;
    luas = phi * jariJari * jariJari;
    
    cout << "Jika nilai jari-jari adalah "<< jariJari << " Cm, Maka keliling lingkaran adalah : "<< keliling << endl;
    cout << "Jika nilai jari-jari adalah "<< jariJari << " Cm, Maka keliling lingkaran adalah : "<< luas << endl;

}




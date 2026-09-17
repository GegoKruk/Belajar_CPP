#include <iostream>
using namespace std;

int n = 5;

int rekursifIzza(int n){
    if(n == 0){
        return n;
    } else {
        cout << "Izza" << endl;
        return rekursifIzza(n-1);
    }
}

int main(){
    rekursifIzza(n);
}
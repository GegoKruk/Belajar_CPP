#include <iostream>
using namespace std;


int main (){
    int stack[5];
    int top = -1;

    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;
    
    cout << "Data Keluar    : " << stack[top] << endl;
    top--;
    
    stack[++top] = 40;
    
    cout << "Data Teratas   : " << stack[top] << endl;
    cout << "Jumlah Element : " << top + 1 << endl;

    return 0;
}
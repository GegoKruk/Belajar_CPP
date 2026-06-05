#include <iostream>
#include <vector>
using namespace std;

// Beberapa fungsi dengan signature sama (int, int) -> int
int tambah(int a, int b) { return a + b; }
int kurang(int a, int b) { return a - b; }
int kali(int a, int b)   { return a * b; }
int bagi(int a, int b)   { return (b != 0) ? a / b : 0; }

// Callback dengan return bool (predikat)
bool genap(int x) { return x % 2 == 0; }
bool ganjil(int x) { return x % 2 != 0; }
bool lebihDari5(int x) { return x > 5; }

// Fungsi yang menerima callback predikat
int hitungJika(int arr[], int n, bool (*predikat)(int)) {
    int count = 0;
    for(int i=0; i<n; i++)
        if(predikat(arr[i])) count++;
    return count;
}

// Fungsi transform dengan callback
void transform(int arr[], int n, int (*fungsi)(int)) {
    for(int i=0; i<n; i++)
        arr[i] = fungsi(arr[i]);
}

int kuadrat(int x) { return x * x; }

int main() {
    cout << "=== Function Pointer Lanjutan ===\n\n";

    // 1. Dispatch table (array of function pointers)
    int (*operasi[4])(int,int) = {tambah, kurang, kali, bagi};
    const char* namaOperasi[] = {"tambah", "kurang", "kali", "bagi"};

    int a=20, b=5;
    cout << "Dispatch table:\n";
    for(int i=0; i<4; i++) {
        int hasil = operasi[i](a,b);
        cout << "  " << namaOperasi[i] << "(" << a << "," << b << ") = " << hasil << endl;
    }

    // 2. Callback predikat
    int data[] = {1,4,7,2,9,6,3,8};
    int n = sizeof(data)/sizeof(data[0]);

    cout << "\nArray: ";
    for(int v : data) cout << v << " ";
    cout << endl;

    cout << "Jumlah bilangan genap  : " << hitungJika(data, n, genap) << endl;
    cout << "Jumlah bilangan ganjil : " << hitungJika(data, n, ganjil) << endl;
    cout << "Jumlah >5              : " << hitungJika(data, n, lebihDari5) << endl;

    // 3. Transformasi array dengan callback
    cout << "\nTransformasi dengan kuadrat:\nSebelum: ";
    for(int v : data) cout << v << " ";
    transform(data, n, kuadrat);
    cout << "\nSetelah: ";
    for(int v : data) cout << v << " ";
    cout << endl;

    // 4. Lambda sebagai callback (tanpa capture)
    int data2[] = {10,20,30,40};
    int m = 4;
    int hasil = hitungJika(data2, m, [](int x) { return x > 25; });
    cout << "\nLambda predicate: jumlah >25 = " << hasil << endl;

    return 0;
}
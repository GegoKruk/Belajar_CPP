
#include <iostream>
using namespace std;

void cetakArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// Rotasi kiri 1 langkah
void leftRotateSatu(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

// Rotasi kanan 1 langkah
void rightRotateSatu(int arr[], int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main() {

    // ----- 1. Left Rotate 1 Langkah -----
        cout << "=== 1. Left Rotate 1 Langkah ===" << endl;

        int data1[5] = {1, 2, 3, 4, 5};
        int n = sizeof(data1) / sizeof(data1[0]);

        cout << "Sebelum : ";
        cetakArray(data1, n);
        cout << endl;

        leftRotateSatu(data1, n);

        cout << "Sesudah : ";
        cetakArray(data1, n);
        cout << endl;


    // ----- 2. Right Rotate 1 Langkah -----
        cout << endl << "=== 2. Right Rotate 1 Langkah ===" << endl;

        int data2[5] = {1, 2, 3, 4, 5};

        cout << "Sebelum : ";
        cetakArray(data2, n);
        cout << endl;

        rightRotateSatu(data2, n);

        cout << "Sesudah : ";
        cetakArray(data2, n);
        cout << endl;


    // ----- 3. Left Rotate Sebanyak K Langkah -----
        cout << endl << "=== 3. Left Rotate K Langkah ===" << endl;

        int data3[5] = {1, 2, 3, 4, 5};
        int k = 3;

        cout << "Sebelum (k=" << k << "): ";
        cetakArray(data3, n);
        cout << endl;

        // Optimasi: k % n untuk hindari rotasi berlebihan
            int efektif = k % n;
            for (int i = 0; i < efektif; i++) {
                leftRotateSatu(data3, n);
                cout << "  Setelah rotate " << i + 1 << ": ";
                cetakArray(data3, n);
                cout << endl;
            }

            cout << "Sesudah : ";
            cetakArray(data3, n);
            cout << endl;


    // ----- 4. Right Rotate Sebanyak K Langkah -----
        cout << endl << "=== 4. Right Rotate K Langkah ===" << endl;

        int data4[5] = {1, 2, 3, 4, 5};
        int k2 = 2;

        cout << "Sebelum (k=" << k2 << "): ";
        cetakArray(data4, n);
        cout << endl;

        int efektif2 = k2 % n;
        for (int i = 0; i < efektif2; i++) {
            rightRotateSatu(data4, n);
        }

        cout << "Sesudah : ";
        cetakArray(data4, n);
        cout << endl;


    // ----- 5. Demonstrasi k % n (hindari rotasi berlebih) -----
        cout << endl << "=== 5. Optimasi k % n ===" << endl;

        int data5[5] = {1, 2, 3, 4, 5};
        int kBesar = 12;

        cout << "Left rotate " << kBesar << " kali pada array ukuran " << n << endl;
        cout << kBesar << " % " << n << " = " << kBesar % n
            << " (rotasi efektif)" << endl;

        int efektif3 = kBesar % n;
        for (int i = 0; i < efektif3; i++) {
            leftRotateSatu(data5, n);
        }

        cout << "Sebelum : [1, 2, 3, 4, 5]" << endl;
        cout << "Sesudah : ";
        cetakArray(data5, n);
        cout << endl;

    return 0;
}

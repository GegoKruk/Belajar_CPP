#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // Ambil elemen terakhir sebagai pivot
    int i = low - 1; // Index untuk elemen yang lebih kecil

    // PERBAIKAN: j mulai dari low, dan yang ditambah adalah j++
    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Pindahkan pivot ke posisi yang benar (setelah elemen-elemen kecil)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quick(arr, low, pi - 1);  // Urutkan kiri
        quick(arr, pi + 1, high); // Urutkan kanan
    }
}

int main(){
    int data_size = 5;
    int dataNilai[] = {3, 2, 5, 4, 1}; // Tambahkan '=' untuk inisialisasi yang standar
    
    quick(dataNilai, 0, data_size - 1);
    
    cout << "Hasil Quick Sort: ";
    for (int i = 0; i < data_size; i++){
        cout << dataNilai[i] << " ";
    }
    cout << endl;

    return 0;
}
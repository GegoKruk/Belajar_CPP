#include <iostream>
using namespace std;

int main() {
    const int jumlahTugas = 5;
    int nilaiTeori[jumlahTugas]   = {50, 55, 40, 50, 60};
    int nilaiPraktek[jumlahTugas] = {42, 45, 20, 49, 33};
    int totalNilai[jumlahTugas];

    // Hitung total nilai untuk masing-masing tugas
    for (int i = 0; i < jumlahTugas; i++) {
        totalNilai[i] = nilaiTeori[i] + nilaiPraktek[i];
    }

    // Tampilkan hasil
    cout << "---------------------------------" << endl;
    cout << "| Hasil Perhitungan Nilai Tugas |" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < jumlahTugas; i++) {
        cout << "Tugas " << i+1 << endl;
        cout << "Nilai Teori : " << nilaiTeori[i] << endl;
        cout << "Nilai Praktik : " << nilaiPraktek[i] << endl;
        cout << "Total Nilai : " << totalNilai[i] << endl;
        cout << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {

    int nilai[8] = {85, 90, 78, 92, 88, 76, 95, 82};
    int n = sizeof(nilai) / sizeof(nilai[0]);

    cout << "Data nilai: ";
    for (int i = 0; i < n; i++) cout << nilai[i] << " ";
    cout << endl << endl;


    // ----- 1. Total (Sum) -----
        cout << "=== 1. Total ===" << endl;
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += nilai[i];
        }
        cout << "  Total semua nilai = " << total << endl;


    // ----- 2. Rata-rata -----
        cout << endl << "=== 2. Rata-rata ===" << endl;
        double rataRata = (double)total / n;
        cout << "  Rata-rata = " << rataRata << endl;

        // Demonstrasi jebakan integer division
            double rataRataSalah = total / n;
            cout << "  Rata-rata (tanpa cast) = " << rataRataSalah << "  <- perhatikan bedanya!" << endl;


    // ----- 3. Nilai Maksimum -----
        cout << endl << "=== 3. Nilai Maksimum ===" << endl;
        int maks = nilai[0];
        int idxMaks = 0;

        for (int i = 1; i < n; i++) {
            if (nilai[i] > maks) {
                maks    = nilai[i];
                idxMaks = i;
            }
        }
        cout << "  Nilai maksimum = " << maks << " (ada di index " << idxMaks << ")" << endl;


    // ----- 4. Nilai Minimum -----
        cout << endl << "=== 4. Nilai Minimum ===" << endl;
        int mini = nilai[0];
        int idxMini = 0;

        for (int i = 1; i < n; i++) {
            if (nilai[i] < mini) {
                mini    = nilai[i];
                idxMini = i;
            }
        }
        cout << "  Nilai minimum = " << mini << " (ada di index " << idxMini << ")" << endl;


    // ----- 5. Hitung Elemen dengan Kondisi -----
        cout << endl << "=== 5. Hitung Elemen dengan Kondisi ===" << endl;
        int batasLulus = 80;
        int lulusCount = 0;
        int gagalCount = 0;

        for (int i = 0; i < n; i++) {
            if (nilai[i] >= batasLulus) {
                lulusCount++;
            } else {
                gagalCount++;
            }
        }

        cout << "  Batas lulus   : " << batasLulus << endl;
        cout << "  Jumlah lulus  : " << lulusCount << " orang" << endl;
        cout << "  Jumlah gagal  : " << gagalCount << " orang" << endl;


    // ----- 6. Ringkasan -----
        cout << endl << "=== Ringkasan ===" << endl;
        cout << "  Jumlah data   : " << n      << endl;
        cout << "  Total         : " << total  << endl;
        cout << "  Rata-rata     : " << rataRata << endl;
        cout << "  Maksimum      : " << maks   << endl;
        cout << "  Minimum       : " << mini   << endl;
        cout << "  Lulus (>= 80) : " << lulusCount << endl;

    return 0;
}

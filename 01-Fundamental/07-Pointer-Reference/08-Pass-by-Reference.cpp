
#include <iostream>
#include <string>
using namespace std;


// ----- Pass by VALUE -----
    void tambahValue(int x) {
        x = x + 100;   // hanya ubah salinan lokal
        cout << "  Di dalam fungsi (by value): x = " << x << endl;
    }

// ----- Pass by REFERENCE -----
    void tambahRef(int& x) {
        x = x + 100;   // mengubah variabel asli!
        cout << "  Di dalam fungsi (by ref)  : x = " << x << endl;
    }

// ----- Pass by CONST REFERENCE -----
    void tampilkanConst(const string& teks) {
        cout << "  Teks: " << teks << endl;
        // teks = "ubah";  // TIDAK BISA - compile error
    }

// ----- Swap dengan pass by reference -----
    void salahSwap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
        // ini hanya swap salinan, tidak swap aslinya!
    }

    void benarSwap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

// ----- Multiple return via reference -----
    void hitungPersegi(int sisi, int& keliling, int& luas) {
        keliling = 4 * sisi;
        luas     = sisi * sisi;
    }

// ----- Modifikasi array via pointer (pointer as parameter) -----
    void gandakanSemua(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            arr[i] *= 2;
        }
    }

// ----- Statistik array via multiple reference -----
    void statistikArray(const int arr[], int size, int& maks, int& mini, double& rata) {
        maks = arr[0];
        mini = arr[0];
        int total = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] > maks) maks = arr[i];
            if (arr[i] < mini) mini = arr[i];
            total += arr[i];
        }
        rata = (double)total / size;
    }


int main() {

    // ----- 1. Pass by Value vs Pass by Reference -----
        cout << "=== 1. Pass by Value vs Pass by Reference ===" << endl;

        int val = 10;

        cout << "Nilai awal: val = " << val << endl;

        tambahValue(val);
        cout << "Setelah tambahValue(val): val = " << val << " (TIDAK berubah)" << endl;

        cout << endl;
        cout << "Nilai awal: val = " << val << endl;

        tambahRef(val);
        cout << "Setelah tambahRef(val)  : val = " << val << " (BERUBAH!)" << endl;


    // ----- 2. Pass by Const Reference (Efisien untuk Tipe Besar) -----
        cout << endl << "=== 2. Pass by Const Reference ===" << endl;

        string kalimat = "Belajar C++ itu menyenangkan!";
        cout << "Kirim string panjang ke function:" << endl;
        tampilkanConst(kalimat);    // tidak buat salinan string
        cout << "  (tidak membuat salinan - lebih efisien)" << endl;

        // Bisa langsung kirim literal
        tampilkanConst("Literal string langsung");


    // ----- 3. Swap - Salah vs Benar -----
        cout << endl << "=== 3. Swap - Salah vs Benar ===" << endl;

        int x = 5, y = 10;
        cout << "Awal: x=" << x << ", y=" << y << endl;

        salahSwap(x, y);
        cout << "Setelah salahSwap(x, y): x=" << x << ", y=" << y << " (TIDAK swap!)" << endl;

        benarSwap(x, y);
        cout << "Setelah benarSwap(x, y): x=" << x << ", y=" << y << " (Ter-swap!)" << endl;


    // ----- 4. Multiple Return via Reference -----
        cout << endl << "=== 4. Multiple Return via Reference ===" << endl;

        int sisi = 7;
        int keliling, luas;

        hitungPersegi(sisi, keliling, luas);

        cout << "Persegi sisi = " << sisi << endl;
        cout << "  Keliling = " << keliling << " (4 x " << sisi << ")" << endl;
        cout << "  Luas     = " << luas     << " (" << sisi << " x " << sisi << ")" << endl;


    // ----- 5. Array via Pointer Parameter -----
        cout << endl << "=== 5. Array via Pointer Parameter ===" << endl;

        int data[5] = {3, 7, 2, 9, 1};

        cout << "Sebelum: ";
        for (int i = 0; i < 5; i++) cout << data[i] << " ";
        cout << endl;

        gandakanSemua(data, 5);

        cout << "Sesudah (x2): ";
        for (int i = 0; i < 5; i++) cout << data[i] << " ";
        cout << endl;


    // ----- 6. Statistik Array via Multiple Reference -----
        cout << endl << "=== 6. Statistik Array via Multiple Reference ===" << endl;

        int nilai[6] = {85, 90, 78, 92, 88, 76};
        int maks, mini;
        double rata;

        statistikArray(nilai, 6, maks, mini, rata);

        cout << "Data: ";
        for (int i = 0; i < 6; i++) cout << nilai[i] << " ";
        cout << endl;
        cout << "  Maksimum = " << maks << endl;
        cout << "  Minimum  = " << mini << endl;
        cout << "  Rata-rata= " << rata << endl;


    // ----- 7. Perbandingan 3 Cara Pass String -----
        cout << endl << "=== 7. Perbandingan Cara Pass Parameter ===" << endl;

        cout << "Cara                   | Salinan? | Ubah asli? | Terima literal?" << endl;
        cout << "-----------------------+----------+------------+----------------" << endl;
        cout << "void f(string s)       |   Ya     |   Tidak    |   Ya           " << endl;
        cout << "void f(string& s)      |   Tidak  |   Ya       |   Tidak        " << endl;
        cout << "void f(const string& s)|   Tidak  |   Tidak    |   Ya           " << endl;
        cout << endl;
        cout << "Rekomendasi:" << endl;
        cout << "  Tipe kecil, baca saja  -> pass by value  (int, double, bool)" << endl;
        cout << "  Perlu diubah           -> pass by ref    (int&, string&)" << endl;
        cout << "  Tipe besar, baca saja  -> const ref      (const string&, const vector&)" << endl;

    return 0;
}

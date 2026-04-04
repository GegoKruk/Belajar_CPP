
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


// CONTOH 1 -- FAKTORIAL

    // Rekursif
    long long faktorial(int n) {
        if (n < 0)  return -1;     // base case: error
        if (n <= 1) return 1;      // base case: 0! = 1, 1! = 1
        return (long long)n * faktorial(n - 1);  // recursive case
    }

    // Iteratif (untuk perbandingan)
    long long faktorialIteratif(int n) {
        if (n < 0) return -1;
        long long hasil = 1;
        for (int i = 2; i <= n; i++) hasil *= i;
        return hasil;
    }

    // Visualisasi dengan indentasi -- tunjukkan call stack
    void faktorialVis(int n, int level) {
        string indent(level * 3, ' ');
        cout << indent << "faktorial(" << n << ") dipanggil" << endl;
        if (n <= 1) {
            cout << indent << "BASE CASE -> return 1" << endl;
            return;
        }
        faktorialVis(n - 1, level + 1);
        cout << indent << "kembali: " << n << " * faktorial(" << n-1 << ") = "
            << n * faktorialIteratif(n-1) << endl;
    }


// CONTOH 2 -- PANGKAT

    // Rekursif sederhana: x^n = x * x^(n-1)
    double pangkat(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0)  return 1.0 / pangkat(x, -n);
        return x * pangkat(x, n - 1);
    }

    // Fast power O(log n): x^n = (x^(n/2))^2 jika n genap
    double fastPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0)  return 1.0 / fastPow(x, -n);
        if (n % 2 == 0) {
            double setengah = fastPow(x, n / 2);
            return setengah * setengah;   // hitung sekali, pakai dua kali
        }
        return x * fastPow(x, n - 1);
    }


// CONTOH 3 -- FIBONACCI

    // Rekursif naive -- O(2^n), sangat lambat untuk n besar!
    long long fibRekursif(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibRekursif(n - 1) + fibRekursif(n - 2);   // DUA pemanggilan!
    }

    // Iteratif -- O(n), jauh lebih cepat
    long long fibIteratif(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        long long a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            long long c = a + b;
            a = b;
            b = c;
        }
        return b;
    }


// CONTOH 4 -- GCD (Algoritma Euclid)
    /*
        GCD(a, b) = a         jika b == 0   (base case)
        GCD(a, b) = GCD(b, a%b)             (recursive case)
    */

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }


// CONTOH 5 -- BINARY SEARCH REKURSIF
    int binarySearch(int arr[], int kiri, int kanan, int target) {
        if (kiri > kanan) return -1;   // base case: tidak ditemukan
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == target) return tengah;   // base case: ketemu
        if (arr[tengah] > target)
            return binarySearch(arr, kiri, tengah - 1, target);
        else
            return binarySearch(arr, tengah + 1, kanan, target);
    }


// CONTOH 6 -- JUMLAH DIGIT REKURSIF
    int jumlahDigit(int n) {
        if (n < 0)  n = -n;          // handle negatif
        if (n < 10) return n;        // base case: 1 digit
        return (n % 10) + jumlahDigit(n / 10);   // digit terakhir + rekursi
    }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.9 -- Recursive Function" << endl;
    cout << "============================================================" << endl;

    cout << "\n  Rekursi: function memanggil dirinya sendiri." << endl;
    cout << "  Wajib punya BASE CASE (berhenti) dan RECURSIVE CASE (mengecil)." << endl;

    // ---- Faktorial ----
        cout << "\n[ 1. Faktorial ]" << endl;

        cout << "\n  Rekursif vs Iteratif:" << endl;
        cout << "  +-----+------------------+" << endl;
        cout << "  |  n  | Faktorial        |" << endl;
        cout << "  +-----+------------------+" << endl;
        for (int i = 0; i <= 10; i++) {
            cout << "  | " << setw(3) << i << " | "
                << setw(16) << faktorial(i) << " |" << endl;
        }
        cout << "  +-----+------------------+" << endl;

        cout << "\n  Visualisasi call stack faktorial(4):" << endl;
        faktorialVis(4, 0);

    // ---- Pangkat ----
        cout << "\n[ 2. Pangkat ]" << endl;
        cout << fixed << setprecision(0);
        cout << "\n  pangkat(2, n):" << endl;
        for (int i = 0; i <= 10; i++) {
            cout << "  2^" << setw(2) << i << " = " << pangkat(2, i) << endl;
        }
        cout << setprecision(6);
        cout << "  pangkat(2, -3) = " << pangkat(2, -3) << "  (= 1/8)" << endl;
        cout << "\n  fastPow vs pangkat (hasil sama, fastPow O(log n)):" << endl;
        cout << fixed << setprecision(0);
        cout << "  fastPow(2, 10) = " << fastPow(2, 10) << endl;
        cout << "  pangkat(2, 10) = " << pangkat(2, 10) << endl;
        cout << defaultfloat;

    // ---- Fibonacci ----
        cout << "\n[ 3. Fibonacci ]" << endl;

        cout << "\n  Deret Fibonacci:" << endl;
        cout << "  n  : ";
        for (int i = 0; i <= 12; i++) cout << setw(5) << i;
        cout << endl;
        cout << "  fib: ";
        for (int i = 0; i <= 12; i++) cout << setw(5) << fibIteratif(i);
        cout << endl;

        cout << "\n  Rekursif naive SANGAT LAMBAT untuk n besar!" << endl;
        cout << "  fib(10) rekursif  = " << fibRekursif(10) << endl;
        cout << "  fib(10) iteratif  = " << fibIteratif(10) << endl;
        cout << "  fib(40) iteratif  = " << fibIteratif(40) << "  (rekursif butuh miliaran pemanggilan!)" << endl;
        cout << "\n  Perkiraan pemanggilan fibRekursif:" << endl;
        cout << "  fib(10) : sekitar  177 kali" << endl;
        cout << "  fib(20) : sekitar 21891 kali" << endl;
        cout << "  fib(30) : sekitar 2.7 juta kali" << endl;
        cout << "  fib(40) : sekitar 331 juta kali -- SANGAT LAMBAT!" << endl;

    // ---- GCD ----
        cout << "\n[ 4. GCD dan LCM ]" << endl;

        cout << "\n  Algoritma Euclid: GCD(a,b) = GCD(b, a%b)" << endl;
        int pasangan[][2] = {{48,18},{100,75},{17,13},{36,60},{7,5}};
        cout << "  +----------+-----+-----+" << endl;
        cout << "  | Pasangan | GCD | LCM |" << endl;
        cout << "  +----------+-----+-----+" << endl;
        for (auto &p : pasangan) {
            cout << "  | (" << setw(2) << p[0] << "," << setw(2) << p[1] << ")  |"
                << setw(4) << gcd(p[0],p[1]) << " |"
                << setw(5) << lcm(p[0],p[1]) << " |" << endl;
        }
        cout << "  +----------+-----+-----+" << endl;

    // ---- Binary Search ----
        cout << "\n[ 5. Binary Search Rekursif ]" << endl;

        int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
        int ukuran = 11;
        cout << "\n  Array: ";
        for (int i = 0; i < ukuran; i++) cout << arr[i] << " ";
        cout << endl;

        int target[] = {23, 2, 91, 50, 38};
        for (int t : target) {
            int idx = binarySearch(arr, 0, ukuran - 1, t);
            cout << "  Cari " << setw(3) << t << " -> "
                << (idx != -1 ? "ketemu di index [" + to_string(idx) + "]"
                            : "tidak ditemukan") << endl;
        }

    // ---- Jumlah Digit ----
        cout << "\n[ 6. Jumlah Digit Rekursif ]" << endl;
        int angka[] = {0, 5, 42, 123, 9876, 54321};
        for (int a : angka) {
            cout << "  jumlahDigit(" << setw(5) << a << ") = " << jumlahDigit(a) << endl;
        }

    // ---- Rekursi vs Iterasi ----
        cout << "\n[ 7. Rekursi vs Iterasi ]" << endl;
        cout << R"(
            +--------------------+-------------------+----------------------+
            | Aspek              | Rekursi           | Iterasi (loop)       |
            +--------------------+-------------------+----------------------+
            | Keterbacaan        | Elegan untuk tree | Lebih verbose        |
            | Performa           | Lebih lambat      | Lebih cepat          |
            | Memori             | Stack bisa penuh  | Lebih hemat          |
            | Debug              | Lebih sulit       | Lebih mudah          |
            | Cocok untuk        | Tree, Graph,      | Perulangan biasa     |
            |                    | Divide & Conquer  | counter, akumulasi   |
            +--------------------+-------------------+----------------------+

            Panduan:
            - Bisa pakai loop biasa? Pakai loop -- lebih cepat dan aman
            - Masalah terbagi jadi sub-masalah identik? Pertimbangkan rekursi
            - Selalu pastikan BASE CASE bisa tercapai!
            - Hati-hati n besar (> ratusan level) -- stack overflow!
        )";

    return 0;
}

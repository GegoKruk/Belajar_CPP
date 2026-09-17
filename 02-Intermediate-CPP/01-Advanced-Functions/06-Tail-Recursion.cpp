#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// PERBANDINGAN: NON-TAIL vs TAIL RECURSION
// -------------------------------------------------------

// Non-tail: hasil dihitung SAAT MUNDUR (stack menumpuk)
long long faktorialNonTail(int n) {
    if (n <= 1) return 1;
    return n * faktorialNonTail(n - 1);   // masih kalikan n setelah kembali
}

// Tail: akumulator membawa hasil, tidak ada pekerjaan setelah rekursi
long long faktorialHelper(int n, long long akum) {
    if (n <= 1) return akum;
    return faktorialHelper(n - 1, n * akum);   // langsung return hasil rekursi
}
long long faktorialTail(int n) {
    return faktorialHelper(n, 1);
}

// -------------------------------------------------------
// NON-TAIL vs TAIL: SUM
// -------------------------------------------------------
int sumNonTail(int n) {
    if (n <= 0) return 0;
    return n + sumNonTail(n - 1);          // n ditahan di stack
}

int sumHelper(int n, int akum) {
    if (n <= 0) return akum;
    return sumHelper(n - 1, akum + n);     // akum membawa total
}
int sumTail(int n) {
    return sumHelper(n, 0);
}

// -------------------------------------------------------
// NON-TAIL vs TAIL: FIBONACCI
// -------------------------------------------------------
long long fibNonTail(int n) {
    if (n <= 1) return n;
    return fibNonTail(n - 1) + fibNonTail(n - 2);  // O(2^n)
}

// Tail fibonacci: dua akumulator (a=fib(n-2), b=fib(n-1))
long long fibHelper(int n, long long a, long long b) {
    if (n == 0) return a;
    return fibHelper(n - 1, b, a + b);    // geser jendela
}
long long fibTail(int n) {
    return fibHelper(n, 0, 1);
}

// -------------------------------------------------------
// NON-TAIL vs TAIL: PANGKAT
// -------------------------------------------------------
long long pangkatNonTail(long long base, int exp) {
    if (exp == 0) return 1;
    return base * pangkatNonTail(base, exp - 1);
}

long long pangkatHelper(long long base, int exp, long long akum) {
    if (exp == 0) return akum;
    return pangkatHelper(base, exp - 1, akum * base);
}
long long pangkatTail(long long base, int exp) {
    return pangkatHelper(base, exp, 1);
}

// -------------------------------------------------------
// NON-TAIL vs TAIL: REVERSE STRING
// -------------------------------------------------------
string reverseNonTail(const string& s) {
    if (s.empty()) return "";
    return reverseNonTail(s.substr(1)) + s[0];   // konkatenasi setelah rekursi
}

void reverseHelper(const string& s, int idx, string& hasil) {
    if (idx < 0) return;
    hasil += s[idx];                            // kerjakan dulu
    reverseHelper(s, idx - 1, hasil);           // lanjut rekursi (terakhir)
}
string reverseTail(const string& s) {
    string hasil;
    reverseHelper(s, (int)s.size() - 1, hasil);
    return hasil;
}

// -------------------------------------------------------
// NON-TAIL vs TAIL: GCD (GREATEST COMMON DIVISOR)
// -------------------------------------------------------
int gcdNonTail(int a, int b) {
    if (b == 0) return a;
    return gcdNonTail(b, a % b);     // ini sudah tail! Euclidean algorithm
}

// Memang sudah tail, ini untuk demonstrasi kesamaannya
int gcdTail(int a, int b) {
    if (b == 0) return a;
    return gcdTail(b, a % b);
}

// -------------------------------------------------------
// DEMONSTRASI ITERASI EKUIVALEN
// -------------------------------------------------------
long long faktorialIteratif(int n) {
    long long hasil = 1;
    for (int i = 2; i <= n; i++) hasil *= i;
    return hasil;
}

long long fibIteratif(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {

    // Faktorial: non-tail vs tail
    cout << "=== Faktorial: Non-Tail vs Tail ===" << endl;
    for (int i = 1; i <= 10; i++) {
        long long nt = faktorialNonTail(i);
        long long t  = faktorialTail(i);
        long long it = faktorialIteratif(i);
        cout << "  " << i << "! = " << nt
             << " | tail=" << t << " | iter=" << it << endl;
    }

    // Sum: non-tail vs tail
    cout << "\n=== Sum 1..N: Non-Tail vs Tail ===" << endl;
    int uji[] = {5, 10, 20, 100};
    for (int n : uji) {
        cout << "  sum(" << n << "): non-tail=" << sumNonTail(n)
             << ", tail=" << sumTail(n) << endl;
    }

    // Fibonacci: non-tail vs tail (efisiensi jauh berbeda!)
    cout << "\n=== Fibonacci: Non-Tail vs Tail ===" << endl;
    for (int i = 0; i <= 12; i++) {
        cout << "  fib(" << i << "): non-tail=" << fibNonTail(i)
             << ", tail=" << fibTail(i)
             << ", iter=" << fibIteratif(i) << endl;
    }
    // Hanya gunakan tail/iter untuk n besar
    cout << "  fib(40) tail = " << fibTail(40) << endl;
    cout << "  fib(50) tail = " << fibTail(50) << endl;

    // Pangkat: non-tail vs tail
    cout << "\n=== Pangkat: Non-Tail vs Tail ===" << endl;
    cout << "  2^10 non-tail = " << pangkatNonTail(2, 10) << endl;
    cout << "  2^10 tail     = " << pangkatTail(2, 10)    << endl;
    cout << "  3^8  non-tail = " << pangkatNonTail(3, 8)  << endl;
    cout << "  3^8  tail     = " << pangkatTail(3, 8)     << endl;

    // Reverse string
    cout << "\n=== Reverse String: Non-Tail vs Tail ===" << endl;
    string kata[] = {"rekursi", "algoritma", "Indonesia", "C++"};
    for (const string& k : kata) {
        cout << "  \"" << k << "\" -> non-tail: \"" << reverseNonTail(k)
             << "\" | tail: \"" << reverseTail(k) << "\"" << endl;
    }

    // GCD
    cout << "\n=== GCD (sudah tail secara natural) ===" << endl;
    int pasang[][2] = {{48, 18}, {100, 75}, {17, 13}, {36, 24}};
    for (auto& p : pasang) {
        cout << "  gcd(" << p[0] << ", " << p[1] << ") = "
             << gcdTail(p[0], p[1]) << endl;
    }

    // Ringkasan pola akumulator
    cout << "\n=== Ringkasan Pola Akumulator ===" << endl;
    cout << "  faktorial(12) tail = " << faktorialTail(12) << endl;
    cout << "  faktorial(12) iter = " << faktorialIteratif(12) << endl;
    cout << "  Hasil sama, kompleksitas stack berbeda." << endl;
    cout << "  Tail -> O(1) stack (dgn TCO), iterasi -> O(1) stack" << endl;
    cout << "  Non-tail -> O(n) stack, risiko stack overflow utk n besar" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// -------------------------------------------------------
// REKURSI LINEAR
// -------------------------------------------------------
long long faktorial(int n) {
    if (n <= 1) return 1;
    return n * faktorial(n - 1);
}

int sumDigit(int n) {
    if (n < 10) return n;
    return (n % 10) + sumDigit(n / 10);
}

bool palindrom(const string& s, int kiri, int kanan) {
    if (kiri >= kanan) return true;
    if (s[kiri] != s[kanan]) return false;
    return palindrom(s, kiri + 1, kanan - 1);
}

// -------------------------------------------------------
// REKURSI BINARY (FIBONACCI + MEMOIZATION)
// -------------------------------------------------------
long long fibNaif(int n) {
    if (n <= 1) return n;
    return fibNaif(n - 1) + fibNaif(n - 2);
}

map<int, long long> memo;

long long fibMemo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}

// -------------------------------------------------------
// BINARY SEARCH REKURSIF
// -------------------------------------------------------
int binarySearch(const vector<int>& v, int target, int kiri, int kanan) {
    if (kiri > kanan) return -1;
    int tengah = kiri + (kanan - kiri) / 2;
    if (v[tengah] == target) return tengah;
    if (v[tengah] > target)  return binarySearch(v, target, kiri, tengah - 1);
    return binarySearch(v, target, tengah + 1, kanan);
}

// -------------------------------------------------------
// MERGE SORT REKURSIF
// -------------------------------------------------------
vector<int> gabung(const vector<int>& kiri, const vector<int>& kanan) {
    vector<int> hasil;
    int i = 0, j = 0;
    while (i < (int)kiri.size() && j < (int)kanan.size()) {
        if (kiri[i] <= kanan[j]) hasil.push_back(kiri[i++]);
        else                      hasil.push_back(kanan[j++]);
    }
    while (i < (int)kiri.size())  hasil.push_back(kiri[i++]);
    while (j < (int)kanan.size()) hasil.push_back(kanan[j++]);
    return hasil;
}

vector<int> mergeSort(vector<int> v) {
    if (v.size() <= 1) return v;
    int mid = v.size() / 2;
    auto kiri  = mergeSort(vector<int>(v.begin(), v.begin() + mid));
    auto kanan = mergeSort(vector<int>(v.begin() + mid, v.end()));
    return gabung(kiri, kanan);
}

// -------------------------------------------------------
// BACKTRACKING: GENERATE SEMUA PERMUTASI
// -------------------------------------------------------
void permutasi(string s, int start, vector<string>& hasil) {
    if (start == (int)s.size() - 1) {
        hasil.push_back(s);
        return;
    }
    for (int i = start; i < (int)s.size(); i++) {
        swap(s[start], s[i]);
        permutasi(s, start + 1, hasil);
        swap(s[start], s[i]);   // BACKTRACK: kembalikan ke posisi awal
    }
}

// -------------------------------------------------------
// BACKTRACKING: SUBSET SUM
// -------------------------------------------------------
bool cariSubset(const vector<int>& v, int idx, int target) {
    if (target == 0) return true;
    if (idx >= (int)v.size() || target < 0) return false;

    bool ambil = cariSubset(v, idx + 1, target - v[idx]);  // ambil elemen
    bool lewat = cariSubset(v, idx + 1, target);            // lewati elemen

    return ambil || lewat;
}

// -------------------------------------------------------
// REKURSI MUTUAL (SALING MEMANGGIL)
// -------------------------------------------------------
bool isOdd(int n);

bool isEven(int n) {
    if (n == 0) return true;
    return isOdd(n - 1);
}

bool isOdd(int n) {
    if (n == 0) return false;
    return isEven(n - 1);
}

// -------------------------------------------------------
// POWER OF DIVIDE AND CONQUER
// -------------------------------------------------------
long long pangkat(long long base, int exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long setengah = pangkat(base, exp / 2);
        return setengah * setengah;          // O(log n)
    }
    return base * pangkat(base, exp - 1);
}

// -------------------------------------------------------
// HELPER
// -------------------------------------------------------
void cetakVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i < (int)v.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {

    // Rekursi linear
    cout << "=== Rekursi Linear ===" << endl;
    cout << "  faktorial(10) = " << faktorial(10) << endl;
    cout << "  sumDigit(1234) = " << sumDigit(1234) << endl;
    cout << "  palindrom('katak')   = " << palindrom("katak",   0, 4) << endl;
    cout << "  palindrom('rakun')   = " << palindrom("rakun",   0, 4) << endl;
    cout << "  palindrom('racecar') = " << palindrom("racecar", 0, 6) << endl;

    // Fibonacci naif vs memoization
    cout << "\n=== Fibonacci ===" << endl;
    cout << "  fibNaif(10) = " << fibNaif(10) << endl;
    cout << "  fibNaif(20) = " << fibNaif(20) << endl;
    for (int i = 0; i <= 15; i++) cout << fibMemo(i) << " ";
    cout << endl;
    cout << "  fibMemo(40) = " << fibMemo(40) << " (cepat!)" << endl;
    cout << "  fibMemo(50) = " << fibMemo(50) << " (sangat cepat!)" << endl;

    // Binary search rekursif
    cout << "\n=== Binary Search Rekursif ===" << endl;
    vector<int> terurut = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "  data: "; cetakVector(terurut); cout << endl;
    cout << "  cari 11  : indeks " << binarySearch(terurut, 11, 0, (int)terurut.size()-1) << endl;
    cout << "  cari  1  : indeks " << binarySearch(terurut, 1,  0, (int)terurut.size()-1) << endl;
    cout << "  cari 19  : indeks " << binarySearch(terurut, 19, 0, (int)terurut.size()-1) << endl;
    cout << "  cari 10  : indeks " << binarySearch(terurut, 10, 0, (int)terurut.size()-1) << endl;

    // Merge sort
    cout << "\n=== Merge Sort ===" << endl;
    vector<int> acak = {38, 27, 43, 3, 9, 82, 10};
    cout << "  sebelum: "; cetakVector(acak); cout << endl;
    auto rapi = mergeSort(acak);
    cout << "  sesudah: "; cetakVector(rapi); cout << endl;

    // Permutasi (backtracking)
    cout << "\n=== Permutasi (Backtracking) ===" << endl;
    vector<string> perm;
    permutasi("ABC", 0, perm);
    cout << "  Semua permutasi 'ABC' (" << perm.size() << " buah):" << endl;
    cout << "  ";
    for (const string& s : perm) cout << s << " ";
    cout << endl;

    // Subset sum
    cout << "\n=== Subset Sum (Backtracking) ===" << endl;
    vector<int> himpunan = {3, 7, 1, 8, 5};
    cout << "  himpunan: "; cetakVector(himpunan); cout << endl;
    cout << "  ada subset jumlah 15? " << (cariSubset(himpunan, 0, 15) ? "Ya" : "Tidak") << endl;
    cout << "  ada subset jumlah 11? " << (cariSubset(himpunan, 0, 11) ? "Ya" : "Tidak") << endl;
    cout << "  ada subset jumlah  2? " << (cariSubset(himpunan, 0, 2)  ? "Ya" : "Tidak") << endl;

    // Rekursi mutual
    cout << "\n=== Rekursi Mutual ===" << endl;
    for (int i = 0; i <= 8; i++) {
        cout << "  " << i << " -> "
             << (isEven(i) ? "genap" : "ganjil") << endl;
    }

    // Pangkat (divide & conquer)
    cout << "\n=== Pangkat (Divide & Conquer) ===" << endl;
    cout << "  2^10 = " << pangkat(2, 10) << endl;
    cout << "  3^8  = " << pangkat(3, 8)  << endl;
    cout << "  5^5  = " << pangkat(5, 5)  << endl;

    return 0;
}

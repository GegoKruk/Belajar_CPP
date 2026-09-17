#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// TEMPLATE DASAR: SATU TIPE PARAMETER
// -------------------------------------------------------
template <typename T>
T maksimum(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T minimum(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T>
void tukar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// -------------------------------------------------------
// TEMPLATE DENGAN DUA TIPE PARAMETER
// -------------------------------------------------------
template <typename T, typename U>
void cetakPasangan(T pertama, U kedua) {
    cout << "  (" << pertama << ", " << kedua << ")" << endl;
}

template <typename T, typename U>
double rasio(T pembilang, U penyebut) {
    return static_cast<double>(pembilang) / static_cast<double>(penyebut);
}

// -------------------------------------------------------
// TEMPLATE DENGAN NON-TYPE PARAMETER
// -------------------------------------------------------
template <typename T, int UKURAN>
void isiArray(T (&arr)[UKURAN], T nilai) {
    for (int i = 0; i < UKURAN; i++) {
        arr[i] = nilai;
    }
}

template <typename T, int UKURAN>
void cetakArray(const T (&arr)[UKURAN]) {
    cout << "  [";
    for (int i = 0; i < UKURAN; i++) {
        cout << arr[i];
        if (i < UKURAN - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// -------------------------------------------------------
// TEMPLATE: FUNCTION PENCARIAN GENERIK
// -------------------------------------------------------
template <typename T>
int cariLinear(const T arr[], int n, const T &target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// -------------------------------------------------------
// TEMPLATE DENGAN NILAI RETURN BERBEDA (C++11 auto)
// -------------------------------------------------------
template <typename T, typename U>
auto tambahDuaTipe(T a, U b) -> decltype(a + b) {
    return a + b;
}

// -------------------------------------------------------
// FUNCTION OVERLOADING vs TEMPLATE
// -------------------------------------------------------
// Overloading biasa (non-template) diprioritaskan oleh compiler
void tampilInfo(int x) {
    cout << "  [overload-int] nilai = " << x << endl;
}

template <typename T>
void tampilInfo(T x) {
    cout << "  [template]     nilai = " << x << endl;
}

int main() {

    // Dasar: template maksimum & minimum
    cout << "=== maksimum & minimum ===" << endl;
    cout << "  maks(3, 7)     = " << maksimum(3, 7)           << endl;
    cout << "  maks(3.14,2.7) = " << maksimum(3.14, 2.7)      << endl;
    cout << "  maks('z','a')  = " << maksimum('z', 'a')       << endl;
    cout << "  min(100, 200)  = " << minimum(100, 200)         << endl;

    // Explicit instantiation
    cout << "\n=== explicit instantiation ===" << endl;
    cout << "  tambah<double>(1,2) = " << tambahDuaTipe<double, double>(1.0, 2.0) << endl;

    // Tukar
    cout << "\n=== tukar ===" << endl;
    int x = 10, y = 20;
    cout << "  sebelum: x=" << x << ", y=" << y << endl;
    tukar(x, y);
    cout << "  sesudah: x=" << x << ", y=" << y << endl;

    double p = 1.5, q = 9.9;
    cout << "  sebelum: p=" << p << ", q=" << q << endl;
    tukar(p, q);
    cout << "  sesudah: p=" << p << ", q=" << q << endl;

    // Dua tipe parameter
    cout << "\n=== dua tipe parameter ===" << endl;
    cetakPasangan(42, "hello");
    cetakPasangan(true, 3.14);
    cetakPasangan(string("C++"), 2024);
    cout << "  rasio(10, 3) = " << rasio(10, 3) << endl;

    // Non-type parameter
    cout << "\n=== non-type parameter ===" << endl;
    int bufInt[5];
    double bufDbl[4];
    isiArray(bufInt, 7);
    isiArray(bufDbl, 1.5);
    cout << "  bufInt  : "; cetakArray(bufInt);
    cout << "  bufDbl  : "; cetakArray(bufDbl);

    // Pencarian generik
    cout << "\n=== cari linear (generik) ===" << endl;
    int angka[]    = {10, 30, 50, 70, 90};
    string kata[]  = {"apel", "jeruk", "mangga", "pisang"};
    cout << "  cari 50 di angka   : indeks " << cariLinear(angka, 5, 50)            << endl;
    cout << "  cari 99 di angka   : indeks " << cariLinear(angka, 5, 99)            << endl;
    cout << "  cari 'mangga'      : indeks " << cariLinear(kata, 4, string("mangga")) << endl;

    // Auto return type
    cout << "\n=== auto return type ===" << endl;
    auto h1 = tambahDuaTipe(3, 4.5);
    auto h2 = tambahDuaTipe(10, 20);
    cout << "  tambah(3, 4.5) = " << h1 << " (double)" << endl;
    cout << "  tambah(10, 20) = " << h2 << " (int)"    << endl;

    // Overload diprioritaskan vs template
    cout << "\n=== overload vs template ===" << endl;
    tampilInfo(42);         // overload int dipilih
    tampilInfo(3.14);       // template dipilih (tidak ada overload double)
    tampilInfo("teks");     // template dipilih

    return 0;
}

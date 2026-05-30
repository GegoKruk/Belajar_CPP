#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// FUNCTION-FUNCTION YANG AKAN DIGUNAKAN
// -------------------------------------------------------
int tambah  (int a, int b) { return a + b; }
int kurang  (int a, int b) { return a - b; }
int kali    (int a, int b) { return a * b; }
int bagi    (int a, int b) { return (b != 0) ? a / b : 0; }
int modulo  (int a, int b) { return (b != 0) ? a % b : 0; }

bool lebihBesar(int a, int b) { return a > b; }
bool lebihKecil(int a, int b) { return a < b; }
bool samaRata  (int a, int b) { return a == b; }

void cetakBulat (int x) { cout << "  [bulat] " << x << endl; }
void cetakPersen(int x) { cout << "  [persen] " << x << "%" << endl; }
void cetakBiner (int x) {
    cout << "  [biner]  ";
    for (int i = 7; i >= 0; i--)
        cout << ((x >> i) & 1);
    cout << endl;
}

// -------------------------------------------------------
// ALIAS TIPE DENGAN using (C++11)
// -------------------------------------------------------
using OperasiInt  = int  (*)(int, int);
using BandingInt  = bool (*)(int, int);
using AksiInt     = void (*)(int);

// -------------------------------------------------------
// FUNCTION YANG MENERIMA FUNCTION POINTER SEBAGAI PARAMETER
// -------------------------------------------------------
int hitung(int a, int b, OperasiInt operasi) {
    return operasi(a, b);
}

bool bandingkan(int a, int b, BandingInt predikat) {
    return predikat(a, b);
}

void terapkanKeArray(int arr[], int n, AksiInt aksi) {
    for (int i = 0; i < n; i++) {
        aksi(arr[i]);
    }
}

// -------------------------------------------------------
// FUNGSI YANG MENGEMBALIKAN FUNCTION POINTER
// -------------------------------------------------------
OperasiInt pilihanOperasi(char op) {
    switch (op) {
        case '+': return tambah;
        case '-': return kurang;
        case '*': return kali;
        case '/': return bagi;
        default:  return nullptr;
    }
}

// -------------------------------------------------------
// BUBBLE SORT GENERIK DENGAN FUNCTION POINTER KOMPARATOR
// -------------------------------------------------------
void bubbleSort(int arr[], int n, BandingInt harus_tukar) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (harus_tukar(arr[j], arr[j+1])) {
                int tmp = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void cetakArr(const int arr[], int n) {
    cout << "  [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    // -------------------------------------------------------
    // DEKLARASI DAN ASSIGN FUNCTION POINTER
    // -------------------------------------------------------
    cout << "=== Deklarasi Function Pointer ===" << endl;

    int (*fp1)(int, int) = tambah;        // syntax langsung
    OperasiInt fp2       = kurang;        // via alias

    cout << "  fp1(10, 3) = " << fp1(10, 3)  << endl;
    cout << "  fp2(10, 3) = " << fp2(10, 3)  << endl;

    fp1 = kali;                           // pointer bisa diganti
    cout << "  fp1 diubah ke kali(10, 3) = " << fp1(10, 3) << endl;

    // Kedua cara memanggil (langsung dan dereferensi)
    cout << "  fp1(4, 5)    = " << fp1(4, 5)    << endl;
    cout << "  (*fp1)(4, 5) = " << (*fp1)(4, 5) << endl;

    // Nullptr check
    OperasiInt fpNull = nullptr;
    if (fpNull == nullptr)
        cout << "  fpNull: belum diisi" << endl;

    // -------------------------------------------------------
    // FUNCTION POINTER SEBAGAI PARAMETER (CALLBACK DASAR)
    // -------------------------------------------------------
    cout << "\n=== Function Pointer sebagai Parameter ===" << endl;

    cout << "  hitung(10, 4, tambah)  = " << hitung(10, 4, tambah)  << endl;
    cout << "  hitung(10, 4, kurang)  = " << hitung(10, 4, kurang)  << endl;
    cout << "  hitung(10, 4, kali)    = " << hitung(10, 4, kali)    << endl;
    cout << "  hitung(10, 4, bagi)    = " << hitung(10, 4, bagi)    << endl;

    cout << "  bandingkan(5,8,lebihBesar) = " << bandingkan(5, 8, lebihBesar) << endl;
    cout << "  bandingkan(5,8,lebihKecil) = " << bandingkan(5, 8, lebihKecil) << endl;

    // -------------------------------------------------------
    // ARRAY OF FUNCTION POINTERS (DISPATCH TABLE)
    // -------------------------------------------------------
    cout << "\n=== Array of Function Pointers ===" << endl;

    OperasiInt ops[] = { tambah, kurang, kali, bagi, modulo };
    string namaOps[] = { "tambah", "kurang", "kali", "bagi", "modulo" };
    int a = 15, b = 4;

    for (int i = 0; i < 5; i++) {
        cout << "  " << namaOps[i] << "(" << a << ", " << b << ") = "
             << ops[i](a, b) << endl;
    }

    // -------------------------------------------------------
    // FUNCTION YANG MENGEMBALIKAN FUNCTION POINTER
    // -------------------------------------------------------
    cout << "\n=== Return Function Pointer ===" << endl;

    char simbol[] = {'+', '-', '*', '/'};
    for (char op : simbol) {
        OperasiInt fn = pilihanOperasi(op);
        if (fn != nullptr)
            cout << "  10 " << op << " 3 = " << fn(10, 3) << endl;
    }

    OperasiInt fnTidakAda = pilihanOperasi('?');
    if (fnTidakAda == nullptr)
        cout << "  Operasi '?' tidak dikenal" << endl;

    // -------------------------------------------------------
    // TERAPKAN AKSI KE ARRAY
    // -------------------------------------------------------
    cout << "\n=== Terapkan Aksi ke Array ===" << endl;

    int data[] = {10, 45, 7, 128, 3};
    cout << "  --- cetak bulat ---" << endl;
    terapkanKeArray(data, 5, cetakBulat);
    cout << "  --- cetak persen ---" << endl;
    terapkanKeArray(data, 5, cetakPersen);

    // -------------------------------------------------------
    // SORT GENERIK DENGAN KOMPARATOR
    // -------------------------------------------------------
    cout << "\n=== Sort dengan Function Pointer Komparator ===" << endl;

    int arr1[] = {5, 2, 8, 1, 9, 3};
    int arr2[] = {5, 2, 8, 1, 9, 3};

    bubbleSort(arr1, 6, lebihBesar);    // ascending
    bubbleSort(arr2, 6, lebihKecil);    // descending

    cout << "  ascending : "; cetakArr(arr1, 6);
    cout << "  descending: "; cetakArr(arr2, 6);

    return 0;
}

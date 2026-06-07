#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// ================================================================
// TYPEDEF -- cara lama (C-style, masih valid)
// ================================================================

typedef int                    TDInt;
typedef int*                   TDIntPtr;
typedef int&                   TDIntRef;        // tidak bisa di semua konteks
typedef int (*TDFuncPtr)(int, int);
typedef int (*TDArrayPtr)[5];
typedef unsigned long long     TDUInt64;
typedef const char*            TDCString;

// ================================================================
// USING -- cara modern C++11 (direkomendasikan)
// ================================================================

using UsInt        = int;
using UsIntPtr     = int*;
using UsIntRef     = int&;
using UsFuncPtr    = int (*)(int, int);
using UsArrayPtr   = int (*)[5];
using UsUInt64     = unsigned long long;
using UsCString    = const char*;

// Alias yang lebih ekspresif untuk domain tertentu
using NilaiMahasiswa  = double;
using KodeMataKuliah  = int;
using NamaMataKuliah  = string;
using IndeksArray     = int;
using JumlahElemen    = size_t;

// Callback types yang lebih terbaca
using Komparator      = bool (*)(int, int);
using Predikat        = bool (*)(int);
using Transformer     = int  (*)(int);
using AksiVoid        = void (*)(int);
using AksiString      = void (*)(const string&);

// ================================================================
// TEMPLATE ALIAS -- hanya bisa dengan using (bukan typedef)
// ================================================================

template <typename T>
using Vec = vector<T>;

template <typename T>
using PairVec = vector<pair<T, T>>;

template <typename K, typename V>
using Pasangan = pair<K, V>;

// ================================================================
// USING UNTUK MENYEDERHANAKAN TIPE KOMPLEKS
// ================================================================

// Tipe yang rumit tanpa alias:
// function<bool(const string&, const string&)>
// Dengan alias:
using StringKomparator = function<bool(const string&, const string&)>;

// Tipe yang sangat sulit dibaca tanpa alias:
// int (*(*)(int))(double, double)
// Function yang terima int, kembalikan pointer ke function(double,double)->int
using BinaryDoubleOp  = int  (*)(double, double);
using FuncFactory     = BinaryDoubleOp (*)(int);

// ================================================================
// FUNGSI-FUNGSI UNTUK DEMO
// ================================================================
int tambah(int a, int b) { return a + b; }
int kali  (int a, int b) { return a * b; }

bool isGanjil  (int x) { return x % 2 != 0; }
bool isPositif (int x) { return x > 0;       }

int duaKali (int x) { return x * 2; }
int kuadrat (int x) { return x * x; }

void cetakNilai(int x) { cout << "  nilai: " << x << endl; }

// ================================================================
// STRUCT YANG MEMAKAI ALIAS UNTUK KETERBACAAN
// ================================================================
struct DataMahasiswa {
    string          nama;
    NilaiMahasiswa  ipk;
    KodeMataKuliah  kodeMK;
    NamaMataKuliah  namaMK;
};

// ================================================================
// FUNCTION YANG MEMAKAI ALIAS SEBAGAI PARAMETER
// ================================================================
void filterDanCetak(const Vec<int>& data, Predikat kondisi,
                    const string& label) {
    cout << "  [" << label << "]: ";
    for (int x : data) {
        if (kondisi(x)) cout << x << " ";
    }
    cout << endl;
}

void transformDanCetak(const Vec<int>& data, Transformer ubah,
                       const string& label) {
    cout << "  [" << label << "]: ";
    for (int x : data) cout << ubah(x) << " ";
    cout << endl;
}

void sortDengan(Vec<string>& v, StringKomparator komp) {
    for (int i = 0; i < (int)v.size() - 1; i++) {
        for (int j = 0; j < (int)v.size() - i - 1; j++) {
            if (!komp(v[j], v[j + 1])) swap(v[j], v[j + 1]);
        }
    }
}

int main() {

    // -------------------------------------------------------
    // TYPEDEF VS USING: SINTAKS DASAR
    // -------------------------------------------------------
    cout << "=== typedef vs using: Tipe Dasar ===" << endl;
    {
        TDInt     a = 10;
        UsInt     b = 20;
        TDUInt64  c = 9999999999ULL;
        UsUInt64  d = 8888888888ULL;

        cout << "  typedef TDInt    = " << a << endl;
        cout << "  using   UsInt    = " << b << endl;
        cout << "  typedef TDUInt64 = " << c << endl;
        cout << "  using   UsUInt64 = " << d << endl;
    }

    // -------------------------------------------------------
    // POINTER ALIAS
    // -------------------------------------------------------
    cout << "\n=== Pointer Alias ===" << endl;
    {
        int       x  = 42;
        TDIntPtr  p1 = &x;
        UsIntPtr  p2 = &x;

        cout << "  typedef TDIntPtr: *p1 = " << *p1 << endl;
        cout << "  using   UsIntPtr: *p2 = " << *p2 << endl;

        *p1 = 77;
        cout << "  setelah *p1=77: x=" << x << ", *p2=" << *p2 << endl;

        // PERANGKAP typedef dengan multi-deklarasi:
        // TDIntPtr q1, q2;   -- q1 adalah int*, tapi q2 adalah INT (bukan pointer!)
        // using tidak punya masalah ini:
        // UsIntPtr r1, r2;   -- keduanya int* (tapi multi-deklarasi tetap tidak direkomendasikan)
        cout << "  Catatan: hindari typedef multi-deklarasi pointer" << endl;
    }

    // -------------------------------------------------------
    // FUNCTION POINTER ALIAS
    // -------------------------------------------------------
    cout << "\n=== Function Pointer Alias ===" << endl;
    {
        TDFuncPtr fp1 = tambah;
        UsFuncPtr fp2 = kali;

        cout << "  typedef TDFuncPtr tambah(8,2) = " << fp1(8, 2) << endl;
        cout << "  using   UsFuncPtr kali(8,2)   = " << fp2(8, 2) << endl;

        // Array of FP via alias -- jauh lebih bersih
        UsFuncPtr ops[] = { tambah, kali };
        string    nama[] = { "tambah", "kali" };
        for (int i = 0; i < 2; i++)
            cout << "  " << nama[i] << "(6,7) = " << ops[i](6, 7) << endl;
    }

    // -------------------------------------------------------
    // ALIAS DOMAIN-SPESIFIK
    // -------------------------------------------------------
    cout << "\n=== Alias Domain-Spesifik ===" << endl;
    {
        DataMahasiswa mhs = {
            "Andi Wijaya",
            3.87,
            101,
            "Algoritma dan Pemrograman"
        };

        cout << "  Nama   : " << mhs.nama    << endl;
        cout << "  IPK    : " << mhs.ipk     << endl;
        cout << "  Kode MK: " << mhs.kodeMK  << endl;
        cout << "  Nama MK: " << mhs.namaMK  << endl;

        // Alias membuat kode lebih self-documenting
        NilaiMahasiswa  batasPada = 3.50;
        KodeMataKuliah  cariKode  = 101;
        cout << "  IPK >= " << batasPada << " ? "
             << (mhs.ipk >= batasPada ? "Ya" : "Tidak") << endl;
        cout << "  Kode MK == " << cariKode << " ? "
             << (mhs.kodeMK == cariKode ? "Ya" : "Tidak") << endl;
    }

    // -------------------------------------------------------
    // TEMPLATE ALIAS (hanya via using)
    // -------------------------------------------------------
    cout << "\n=== Template Alias (using saja) ===" << endl;
    {
        Vec<int>    angka  = { 1, 2, 3, 4, 5 };
        Vec<string> kata   = { "apel", "jeruk", "mangga" };
        Vec<double> desimal = { 1.1, 2.2, 3.3 };

        cout << "  Vec<int>   : ";
        for (int x : angka) cout << x << " "; cout << endl;

        cout << "  Vec<string>: ";
        for (auto& s : kata) cout << s << " "; cout << endl;

        PairVec<int> pasangan = { {1,2}, {3,4}, {5,6} };
        cout << "  PairVec<int>: ";
        for (auto& p : pasangan)
            cout << "(" << p.first << "," << p.second << ") ";
        cout << endl;
    }

    // -------------------------------------------------------
    // ALIAS UNTUK CALLBACK -- PARAMETER YANG LEBIH TERBACA
    // -------------------------------------------------------
    cout << "\n=== Alias untuk Callback ===" << endl;
    {
        Vec<int> data = { -4, 3, -1, 7, 0, -5, 8, 2 };

        filterDanCetak(data, isGanjil,  "ganjil  ");
        filterDanCetak(data, isPositif, "positif ");

        transformDanCetak(data, duaKali, "duaKali ");
        transformDanCetak(data, kuadrat, "kuadrat ");
    }

    // -------------------------------------------------------
    // ALIAS UNTUK std::function
    // -------------------------------------------------------
    cout << "\n=== Alias untuk std::function ===" << endl;
    {
        Vec<string> kota = { "Yogyakarta", "Solo", "Semarang", "Malang", "Bandung" };

        // Tanpa alias: function<bool(const string&, const string&)> komp = ...
        // Dengan alias: jauh lebih bersih
        StringKomparator abjad   = [](const string& a, const string& b) { return a < b; };
        StringKomparator panjang = [](const string& a, const string& b) {
            return a.length() < b.length();
        };

        Vec<string> k1 = kota, k2 = kota;
        sortDengan(k1, abjad);
        sortDengan(k2, panjang);

        cout << "  sort abjad  : ";
        for (auto& s : k1) cout << s << " "; cout << endl;

        cout << "  sort panjang: ";
        for (auto& s : k2) cout << s << " "; cout << endl;
    }

    // -------------------------------------------------------
    // RINGKASAN: KAPAN PAKAI APA
    // -------------------------------------------------------
    cout << "\n=== Ringkasan: typedef vs using ===" << endl;
    cout << "  typedef  : masih valid, cocok untuk interop kode C lama" << endl;
    cout << "  using    : standar C++11 modern -- selalu lebih pilih ini" << endl;
    cout << "  keduanya : tidak bisa untuk template (hanya using yang bisa)" << endl;
    cout << "  manfaat  : kode lebih bersih, self-documenting, mudah refactor" << endl;

    return 0;
}

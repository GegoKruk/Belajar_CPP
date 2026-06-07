#include <iostream>
#include <string>
#include <functional>
using namespace std;

// -------------------------------------------------------
// ALIAS TIPE (agar sintaks bersih)
// -------------------------------------------------------
using IntBinaryOp  = int  (*)(int, int);
using BoolBinaryOp = bool (*)(int, int);
using StringFunc   = void (*)(const string&);
using Transformer  = int  (*)(int);

// -------------------------------------------------------
// KUMPULAN FUNGSI UNTUK DEMO
// -------------------------------------------------------
int tambah (int a, int b) { return a + b; }
int kurang (int a, int b) { return a - b; }
int kali   (int a, int b) { return a * b; }
int bagi   (int a, int b) { return (b != 0) ? a / b : 0; }
int modulo (int a, int b) { return (b != 0) ? a % b : 0; }

bool lebihBesar(int a, int b) { return a > b; }
bool lebihKecil(int a, int b) { return a < b; }
bool samaRata  (int a, int b) { return a == b; }

int duaKali (int x) { return x * 2; }
int kuadrat (int x) { return x * x; }
int nilaiAbs(int x) { return x < 0 ? -x : x; }

void cetakHurufBesar(const string& s) {
    cout << "  [UPPER] ";
    for (char c : s) cout << (char)(c >= 'a' && c <= 'z' ? c - 32 : c);
    cout << endl;
}
void cetakPanjang(const string& s) {
    cout << "  [LEN]   \"" << s << "\" = " << s.length() << " karakter" << endl;
}
void cetakTerbalik(const string& s) {
    cout << "  [REV]   ";
    for (int i = (int)s.length() - 1; i >= 0; i--) cout << s[i];
    cout << endl;
}

// -------------------------------------------------------
// STRUCT DENGAN FUNCTION POINTER (OOP C-style)
// -------------------------------------------------------
struct Operasi {
    const char* nama;
    IntBinaryOp hitung;
};

// -------------------------------------------------------
// DISPATCH TABLE DALAM FUNCTION
// -------------------------------------------------------
IntBinaryOp pilihanOperasi(char op) {
    struct Entry { char simbol; IntBinaryOp fn; };
    Entry tabel[] = {
        { '+', tambah  },
        { '-', kurang  },
        { '*', kali    },
        { '/', bagi    },
        { '%', modulo  },
    };
    for (auto& e : tabel) {
        if (e.simbol == op) return e.fn;
    }
    return nullptr;
}

// -------------------------------------------------------
// HIGHER-ORDER FUNCTION: MENERIMA DAN MENGEMBALIKAN FP
// -------------------------------------------------------
void jalankanSemua(int a, int b, IntBinaryOp ops[], const string nama[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  " << nama[i] << "(" << a << ", " << b << ") = "
             << ops[i](a, b) << endl;
    }
}

void terapkan(int arr[], int n, Transformer fn, const string& label) {
    cout << "  " << label << ": [";
    for (int i = 0; i < n; i++) {
        cout << fn(arr[i]);
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// -------------------------------------------------------
// SORT GENERIK DENGAN KOMPARATOR FUNCTION POINTER
// -------------------------------------------------------
void insertionSort(int arr[], int n, BoolBinaryOp harus_duluan) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j   = i - 1;
        while (j >= 0 && !harus_duluan(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void cetakArr(const int arr[], int n, const string& label) {
    cout << "  " << label << ": [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// -------------------------------------------------------
// FUNCTION POINTER SEBAGAI MEMBER STRUCT
// -------------------------------------------------------
struct Kalkulator {
    const char* nama;
    IntBinaryOp ops[5];
    string      namaOps[5];
    int         jumlahOps;

    void tampilkan(int a, int b) const {
        cout << "  Kalkulator [" << nama << "] a=" << a << ", b=" << b << endl;
        for (int i = 0; i < jumlahOps; i++) {
            if (ops[i])
                cout << "    " << namaOps[i] << " = " << ops[i](a, b) << endl;
        }
    }
};

int main() {

    // -------------------------------------------------------
    // DISPATCH TABLE DASAR
    // -------------------------------------------------------
    cout << "=== Dispatch Table ===" << endl;
    {
        Operasi tabel[] = {
            { "tambah", tambah },
            { "kurang", kurang },
            { "kali",   kali   },
            { "bagi",   bagi   },
            { "modulo", modulo },
        };
        int n = 5;

        for (int i = 0; i < n; i++) {
            cout << "  " << tabel[i].nama << "(15, 4) = "
                 << tabel[i].hitung(15, 4) << endl;
        }
    }

    // -------------------------------------------------------
    // PILIH OPERASI SAAT RUNTIME
    // -------------------------------------------------------
    cout << "\n=== Pilih Operasi Saat Runtime ===" << endl;
    {
        char simbol[] = { '+', '-', '*', '/', '%', '?' };
        for (char c : simbol) {
            IntBinaryOp fn = pilihanOperasi(c);
            if (fn)
                cout << "  10 " << c << " 3 = " << fn(10, 3) << endl;
            else
                cout << "  '" << c << "': operasi tidak dikenal" << endl;
        }
    }

    // -------------------------------------------------------
    // ARRAY OF FUNCTION POINTER: JALANKAN SEMUA
    // -------------------------------------------------------
    cout << "\n=== Jalankan Semua Operasi ===" << endl;
    {
        IntBinaryOp ops[]  = { tambah, kurang, kali, bagi };
        string      nama[] = { "tambah", "kurang", "kali", "bagi" };
        jalankanSemua(20, 5, ops, nama, 4);
    }

    // -------------------------------------------------------
    // TRANSFORMER: TERAPKAN KE ARRAY
    // -------------------------------------------------------
    cout << "\n=== Transformer pada Array ===" << endl;
    {
        int data[] = { -3, 1, -5, 4, -2, 6, 0, -8 };
        int n      = 8;
        cetakArr(data, n, "asli    ");
        terapkan(data, n, duaKali,  "duaKali ");
        terapkan(data, n, kuadrat,  "kuadrat ");
        terapkan(data, n, nilaiAbs, "nilaiAbs");
    }

    // -------------------------------------------------------
    // SORT DENGAN BERBAGAI KOMPARATOR
    // -------------------------------------------------------
    cout << "\n=== Sort dengan Komparator FP ===" << endl;
    {
        int asc[]  = { 5, 2, 8, 1, 9, 3, 7, 4 };
        int desc[] = { 5, 2, 8, 1, 9, 3, 7, 4 };
        int n      = 8;

        insertionSort(asc,  n, lebihKecil);
        insertionSort(desc, n, lebihBesar);

        cetakArr(asc,  n, "asc   ");
        cetakArr(desc, n, "desc  ");
    }

    // -------------------------------------------------------
    // STRING FUNCTION POINTER
    // -------------------------------------------------------
    cout << "\n=== String Function Pointer ===" << endl;
    {
        StringFunc prosesor[] = {
            cetakHurufBesar, cetakPanjang, cetakTerbalik
        };
        int n = 3;

        string input = "Hello, C++ Pointers!";
        cout << "  input: \"" << input << "\"" << endl;
        for (int i = 0; i < n; i++) prosesor[i](input);
    }

    // -------------------------------------------------------
    // KALKULATOR DENGAN FP SEBAGAI MEMBER
    // -------------------------------------------------------
    cout << "\n=== Kalkulator dengan FP Member ===" << endl;
    {
        Kalkulator kalkAritmatika;
        kalkAritmatika.nama      = "Aritmatika";
        kalkAritmatika.ops[0]    = tambah;  kalkAritmatika.namaOps[0] = "tambah";
        kalkAritmatika.ops[1]    = kurang;  kalkAritmatika.namaOps[1] = "kurang";
        kalkAritmatika.ops[2]    = kali;    kalkAritmatika.namaOps[2] = "kali";
        kalkAritmatika.ops[3]    = bagi;    kalkAritmatika.namaOps[3] = "bagi";
        kalkAritmatika.ops[4]    = modulo;  kalkAritmatika.namaOps[4] = "modulo";
        kalkAritmatika.jumlahOps = 5;

        kalkAritmatika.tampilkan(17, 5);
    }

    // -------------------------------------------------------
    // FUNCTION POINTER vs std::function (perbandingan)
    // -------------------------------------------------------
    cout << "\n=== FP vs std::function ===" << endl;
    {
        int faktor = 3;

        // Function pointer: tidak bisa capture
        IntBinaryOp fp = kali;
        cout << "  FP kali(4, 5)    = " << fp(4, 5) << endl;

        // std::function: bisa capture lambda
        function<int(int)> fnKali = [faktor](int x) { return x * faktor; };
        cout << "  std::fn x*3(7)   = " << fnKali(7)  << endl;
        cout << "  std::fn x*3(10)  = " << fnKali(10) << endl;
    }

    return 0;
}

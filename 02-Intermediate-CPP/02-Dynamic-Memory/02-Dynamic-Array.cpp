#include <iostream>
#include <string>
using namespace std;

// -------------------------------------------------------
// HELPER
// -------------------------------------------------------
void cetakArr(const int* arr, int n, const string& label = "") {
    if (!label.empty()) cout << "  " << label << ": ";
    else                cout << "  ";
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// -------------------------------------------------------
// RESIZE ARRAY: ALOKASI BARU, SALIN, HAPUS LAMA
// -------------------------------------------------------
int* resize(int* arr, int ukuranLama, int ukuranBaru) {
    int* baru = new int[ukuranBaru]();          // nol-init elemen baru
    int  salin = (ukuranBaru < ukuranLama) ? ukuranBaru : ukuranLama;
    for (int i = 0; i < salin; i++) baru[i] = arr[i];
    delete[] arr;
    return baru;
}

// -------------------------------------------------------
// SORT SEDERHANA (SELECTION SORT) UNTUK DYNAMIC ARRAY
// -------------------------------------------------------
void selectionSort(int* arr, int n, bool asc = true) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (asc ? arr[j] < arr[idx] : arr[j] > arr[idx])
                idx = j;
        }
        if (idx != i) swap(arr[i], arr[idx]);
    }
}

// -------------------------------------------------------
// CARI NILAI (LINEAR SEARCH)
// -------------------------------------------------------
int cariNilai(const int* arr, int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}

// -------------------------------------------------------
// FILTER KE ARRAY BARU
// -------------------------------------------------------
int* filterPositif(const int* arr, int n, int& hasilN) {
    hasilN = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > 0) hasilN++;

    int* hasil = new int[hasilN];
    int  idx   = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > 0) hasil[idx++] = arr[i];
    return hasil;
}

// -------------------------------------------------------
// STRUCT UNTUK DYNAMIC ARRAY MAHASISWA
// -------------------------------------------------------
struct Mahasiswa {
    string nama;
    double ipk;
};

void cetakMhs(const Mahasiswa* data, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  [" << i << "] " << data[i].nama
             << " | IPK: " << data[i].ipk << endl;
    }
}

int main() {

    // -------------------------------------------------------
    // UKURAN ARRAY DITENTUKAN SAAT RUNTIME
    // -------------------------------------------------------
    cout << "=== Ukuran Runtime ===" << endl;

    int n;
    cout << "  Masukkan jumlah elemen (contoh: 5): ";
    n = 5;   // hardcode untuk demo tanpa input manual
    cout << n << endl;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = (i + 1) * 7;
    cetakArr(arr, n, "arr");
    delete[] arr; arr = nullptr;

    // -------------------------------------------------------
    // OPERASI DASAR: AKSES, MODIFIKASI, TRAVERSAL
    // -------------------------------------------------------
    cout << "\n=== Operasi Dasar ===" << endl;
    {
        int size  = 8;
        int* data = new int[size]{15, 3, 42, 8, 27, 1, 99, 56};
        cetakArr(data, size, "awal ");

        // Modifikasi
        data[0] = 100;
        data[size - 1] = 0;
        cetakArr(data, size, "ubah ");

        // Cari nilai
        int target = 27;
        int idx = cariNilai(data, size, target);
        if (idx != -1)
            cout << "  cari " << target << " -> indeks " << idx << endl;
        else
            cout << "  cari " << target << " -> tidak ditemukan" << endl;

        // Hitung jumlah dan rata-rata
        long long total = 0;
        for (int i = 0; i < size; i++) total += data[i];
        cout << "  total   = " << total << endl;
        cout << "  rata2   = " << (double)total / size << endl;

        delete[] data; data = nullptr;
    }

    // -------------------------------------------------------
    // NOTASI POINTER ARITHMETIC
    // -------------------------------------------------------
    cout << "\n=== Notasi Pointer Arithmetic ===" << endl;
    {
        int* p = new int[4]{10, 20, 30, 40};
        cout << "  p[0]     = " << p[0]     << " | *(p+0) = " << *(p+0) << endl;
        cout << "  p[1]     = " << p[1]     << " | *(p+1) = " << *(p+1) << endl;
        cout << "  p[3]     = " << p[3]     << " | *(p+3) = " << *(p+3) << endl;

        // Iterasi dengan pointer
        cout << "  iterasi  : ";
        for (int* cur = p; cur != p + 4; cur++) cout << *cur << " ";
        cout << endl;

        delete[] p; p = nullptr;
    }

    // -------------------------------------------------------
    // RESIZE (EXPAND DAN SHRINK)
    // -------------------------------------------------------
    cout << "\n=== Resize Dynamic Array ===" << endl;
    {
        int* arr2 = new int[4]{10, 20, 30, 40};
        int  sz   = 4;
        cetakArr(arr2, sz, "awal (4)");

        // Expand ke 7 elemen
        arr2 = resize(arr2, sz, 7);
        sz   = 7;
        arr2[4] = 50; arr2[5] = 60; arr2[6] = 70;
        cetakArr(arr2, sz, "expand(7)");

        // Shrink ke 3 elemen
        arr2 = resize(arr2, sz, 3);
        sz   = 3;
        cetakArr(arr2, sz, "shrink(3)");

        delete[] arr2; arr2 = nullptr;
    }

    // -------------------------------------------------------
    // SORT DYNAMIC ARRAY
    // -------------------------------------------------------
    cout << "\n=== Sort Dynamic Array ===" << endl;
    {
        int* d1 = new int[7]{38, 7, 2, 55, 14, 81, 3};
        int* d2 = new int[7]{38, 7, 2, 55, 14, 81, 3};
        cetakArr(d1, 7, "asli     ");
        selectionSort(d1, 7, true);
        selectionSort(d2, 7, false);
        cetakArr(d1, 7, "ascending");
        cetakArr(d2, 7, "descending");
        delete[] d1; delete[] d2;
    }

    // -------------------------------------------------------
    // FILTER KE ARRAY BARU
    // -------------------------------------------------------
    cout << "\n=== Filter ke Array Baru ===" << endl;
    {
        int  data[] = {-5, 3, -2, 8, 0, 7, -1, 12, -9, 4};
        int  n2 = 10;
        cetakArr(data, n2, "semua ");

        int  nPos;
        int* positif = filterPositif(data, n2, nPos);
        cetakArr(positif, nPos, "positif");
        delete[] positif;
    }

    // -------------------------------------------------------
    // DYNAMIC ARRAY OF STRUCT
    // -------------------------------------------------------
    cout << "\n=== Dynamic Array of Struct ===" << endl;
    {
        int jumlah = 4;
        Mahasiswa* daftar = new Mahasiswa[jumlah];

        daftar[0] = {"Andi Wijaya",  3.85};
        daftar[1] = {"Budi Santoso", 3.42};
        daftar[2] = {"Citra Dewi",   3.91};
        daftar[3] = {"Deni Kurnia",  3.67};

        cout << "  Daftar mahasiswa:" << endl;
        cetakMhs(daftar, jumlah);

        // Cari IPK tertinggi
        int terbaik = 0;
        for (int i = 1; i < jumlah; i++)
            if (daftar[i].ipk > daftar[terbaik].ipk) terbaik = i;
        cout << "  IPK tertinggi: " << daftar[terbaik].nama
             << " (" << daftar[terbaik].ipk << ")" << endl;

        delete[] daftar; daftar = nullptr;
    }

    // -------------------------------------------------------
    // DYNAMIC ARRAY: TUMBUH SATU PER SATU (SIMULASI PUSH)
    // -------------------------------------------------------
    cout << "\n=== Simulasi Growable Array ===" << endl;
    {
        int* tumpuk = nullptr;
        int  kapasitas = 0;

        int inputan[] = {5, 12, 8, 3, 19, 7};
        for (int val : inputan) {
            // tambah satu slot
            int* baru = new int[kapasitas + 1];
            for (int i = 0; i < kapasitas; i++) baru[i] = tumpuk[i];
            baru[kapasitas] = val;
            delete[] tumpuk;
            tumpuk = baru;
            kapasitas++;

            cout << "  push " << val << ": ";
            cetakArr(tumpuk, kapasitas);
        }

        delete[] tumpuk; tumpuk = nullptr;
    }

    return 0;
}

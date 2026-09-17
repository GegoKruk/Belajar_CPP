#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// -------------------------------------------------------
// STRUCT MAHASISWA (untuk demo sorting pointer)
// -------------------------------------------------------
struct Mahasiswa {
    string nama;
    int    nim;
    double ipk;
};

void cetakMhs(Mahasiswa* const* ptrs, int n) {
    for (int i = 0; i < n; i++) {
        cout << "  [" << i << "] " << ptrs[i]->nama
             << " | NIM: " << ptrs[i]->nim
             << " | IPK: " << ptrs[i]->ipk << endl;
    }
}

// -------------------------------------------------------
// DISPATCH TABLE: function pointer dalam struct
// -------------------------------------------------------
struct MenuItem {
    const char* label;
    void (*aksi)();
};

void aksiSimpan()  { cout << "  >> Menyimpan data..." << endl; }
void aksiBuka()    { cout << "  >> Membuka file..."   << endl; }
void aksiHapus()   { cout << "  >> Menghapus data..."  << endl; }
void aksiKeluar()  { cout << "  >> Keluar program."   << endl; }

// -------------------------------------------------------
// JAGGED ARRAY (tiap baris berbeda panjangnya)
// -------------------------------------------------------
void demo_jagged_array() {
    cout << "\n=== Jagged Array ===" << endl;

    int  ukuran[] = { 3, 5, 2, 4 };
    int  n        = 4;
    int* baris[4];

    for (int i = 0; i < n; i++) {
        baris[i] = new int[ukuran[i]];
        for (int j = 0; j < ukuran[i]; j++)
            baris[i][j] = (i + 1) * 10 + j;
    }

    for (int i = 0; i < n; i++) {
        cout << "  baris[" << i << "]: ";
        for (int j = 0; j < ukuran[i]; j++)
            cout << baris[i][j] << " ";
        cout << endl;
        delete[] baris[i];
    }
}

// -------------------------------------------------------
// SORT POINTER TANPA MEMINDAH DATA ASLI
// -------------------------------------------------------
void demo_sort_pointer() {
    cout << "\n=== Sort via Pointer (data tidak berpindah) ===" << endl;

    Mahasiswa data[] = {
        {"Doni Saputra",  20231, 3.42},
        {"Ayu Wulandari", 20232, 3.91},
        {"Budi Santoso",  20233, 3.67},
        {"Citra Dewi",    20234, 3.55},
        {"Eka Prasetya",  20235, 3.88},
    };
    int n = 5;

    Mahasiswa* ptrs[5];
    for (int i = 0; i < n; i++) ptrs[i] = &data[i];

    cout << "  -- Urutan asli --" << endl;
    cetakMhs(ptrs, n);

    // Sort pointer by IPK descending (data[] tidak bergerak)
    sort(ptrs, ptrs + n, [](Mahasiswa* a, Mahasiswa* b) {
        return a->ipk > b->ipk;
    });
    cout << "  -- Sort by IPK (desc) --" << endl;
    cetakMhs(ptrs, n);

    // Sort pointer by nama ascending
    sort(ptrs, ptrs + n, [](Mahasiswa* a, Mahasiswa* b) {
        return a->nama < b->nama;
    });
    cout << "  -- Sort by Nama (asc) --" << endl;
    cetakMhs(ptrs, n);

    // Verifikasi: data[] di memori tidak berpindah
    cout << "  -- data[0] di memori: " << data[0].nama << " (tidak berubah) --" << endl;
}

// -------------------------------------------------------
// STRING SORTING VIA POINTER (hindari salin string panjang)
// -------------------------------------------------------
void demo_sort_string() {
    cout << "\n=== Sort String via Pointer ===" << endl;

    const char* kata[] = {
        "pisang", "apel", "mangga", "jeruk", "anggur", "durian"
    };
    int n = 6;

    cout << "  asli : ";
    for (int i = 0; i < n; i++) cout << kata[i] << " ";
    cout << endl;

    // Sort array pointer by string content
    sort(kata, kata + n, [](const char* a, const char* b) {
        // bandingkan isi string, bukan alamat pointer
        int i = 0;
        while (a[i] && b[i] && a[i] == b[i]) i++;
        return a[i] < b[i];
    });

    cout << "  sort : ";
    for (int i = 0; i < n; i++) cout << kata[i] << " ";
    cout << endl;
}

int main() {

    // -------------------------------------------------------
    // DEKLARASI DAN AKSES DASAR
    // -------------------------------------------------------
    cout << "=== Array of Pointers: Dasar ===" << endl;
    {
        int a=10, b=20, c=30, d=40, e=50;
        int* ptrs[] = { &a, &b, &c, &d, &e };
        int  n = 5;

        cout << "  akses nilai: ";
        for (int i = 0; i < n; i++) cout << *ptrs[i] << " ";
        cout << endl;

        cout << "  akses alamat: ";
        for (int i = 0; i < n; i++) cout << ptrs[i] << " ";
        cout << endl;

        // Modifikasi nilai via pointer
        *ptrs[1] = 999;
        cout << "  setelah *ptrs[1]=999: b=" << b << endl;

        // Arahkan pointer ke lokasi berbeda
        ptrs[0] = &e;
        cout << "  setelah ptrs[0]=&e: *ptrs[0]=" << *ptrs[0] << endl;
    }

    // -------------------------------------------------------
    // ARRAY OF C-STRING (const char*)
    // -------------------------------------------------------
    cout << "\n=== Array of C-String ===" << endl;
    {
        const char* bulan[] = {
            "Januari",  "Februari", "Maret",    "April",
            "Mei",      "Juni",     "Juli",     "Agustus",
            "September","Oktober",  "November", "Desember"
        };
        int n = 12;

        for (int i = 0; i < n; i++) {
            cout << "  " << (i < 9 ? " " : "") << (i+1) << ". " << bulan[i] << endl;
        }
    }

    // -------------------------------------------------------
    // DISPATCH TABLE (ARRAY OF FUNCTION POINTER)
    // -------------------------------------------------------
    cout << "\n=== Dispatch Table (Menu) ===" << endl;
    {
        MenuItem menu[] = {
            { "Simpan", aksiSimpan },
            { "Buka",   aksiBuka   },
            { "Hapus",  aksiHapus  },
            { "Keluar", aksiKeluar },
        };
        int n = 4;

        cout << "  Pilihan menu:" << endl;
        for (int i = 0; i < n; i++)
            cout << "    [" << i << "] " << menu[i].label << endl;

        // Simulasi memilih menu
        int pilihan[] = { 0, 2, 1, 3 };
        cout << "  Eksekusi:" << endl;
        for (int p : pilihan) {
            cout << "  Pilih [" << p << "] " << menu[p].label << ": ";
            menu[p].aksi();
        }
    }

    // -------------------------------------------------------
    // ARRAY OF POINTER KE STRUCT (HEAP)
    // -------------------------------------------------------
    cout << "\n=== Array of Pointer ke Struct (Heap) ===" << endl;
    {
        Mahasiswa* daftar[4];
        daftar[0] = new Mahasiswa{"Ali Hasan",    20241, 3.75};
        daftar[1] = new Mahasiswa{"Bela Sari",    20242, 3.90};
        daftar[2] = new Mahasiswa{"Candra Putra", 20243, 3.50};
        daftar[3] = new Mahasiswa{"Dina Lestari", 20244, 3.85};

        cetakMhs(daftar, 4);

        // Modifikasi via pointer
        daftar[2]->ipk = 3.95;
        cout << "  setelah update [2]: IPK=" << daftar[2]->ipk << endl;

        for (int i = 0; i < 4; i++) {
            delete daftar[i];
            daftar[i] = nullptr;
        }
    }

    demo_jagged_array();
    demo_sort_pointer();
    demo_sort_string();

    return 0;
}

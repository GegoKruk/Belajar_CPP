
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int    umur;
    double ipk;
};

struct Produk {
    string nama;
    double harga;
    int    stok;
};

void cetakMahasiswa(const Mahasiswa& m, int no) {
    cout << "  [" << no << "] " << m.nama << " | umur=" << m.umur << " | ipk=" << m.ipk << endl;
}

int main() {

    // ----- 1. Deklarasi dan Inisialisasi Array of Struct -----
        cout << "=== 1. Deklarasi dan Inisialisasi ===" << endl;

        Mahasiswa kelas[4] = {
            {"Budi",  20, 3.85},
            {"Sari",  21, 3.90},
            {"Andi",  19, 3.70},
            {"Dina",  22, 3.95}
        };

        cout << "Daftar Mahasiswa:" << endl;
        for (int i = 0; i < 4; i++) {
            cetakMahasiswa(kelas[i], i + 1);
        }


    // ----- 2. Akses dan Modifikasi -----
        cout << endl << "=== 2. Akses dan Modifikasi ===" << endl;

        cout << "Mahasiswa pertama: " << kelas[0].nama << endl;
        cout << "IPK tertinggi awal: " << kelas[3].nama << " (" << kelas[3].ipk << ")" << endl;

        // Modifikasi salah satu elemen
        kelas[2].ipk = 3.80;
        cout << "Setelah update Andi: ipk = " << kelas[2].ipk << endl;


    // ----- 3. Operasi: Cari Nilai Tertinggi -----
        cout << endl << "=== 3. Cari IPK Tertinggi ===" << endl;

        int idxTertinggi = 0;
        for (int i = 1; i < 4; i++) {
            if (kelas[i].ipk > kelas[idxTertinggi].ipk) {
                idxTertinggi = i;
            }
        }
        cout << "IPK tertinggi: " << kelas[idxTertinggi].nama
            << " dengan IPK " << kelas[idxTertinggi].ipk << endl;


    // ----- 4. Operasi: Rata-rata IPK -----
        cout << endl << "=== 4. Rata-rata IPK ===" << endl;

        double totalIPK = 0;
        for (int i = 0; i < 4; i++) {
            totalIPK += kelas[i].ipk;
        }
        cout << "Rata-rata IPK kelas: " << totalIPK / 4 << endl;


    // ----- 5. Operasi: Filter / Cari -----
        cout << endl << "=== 5. Filter: Mahasiswa IPK >= 3.85 ===" << endl;

        for (int i = 0; i < 4; i++) {
            if (kelas[i].ipk >= 3.85) {
                cout << "  " << kelas[i].nama << " (IPK " << kelas[i].ipk << ")" << endl;
            }
        }


    // ----- 6. Operasi: Sort Sederhana (Bubble Sort by IPK) -----
        cout << endl << "=== 6. Sort berdasarkan IPK (Descending) ===" << endl;

        // Bubble sort sederhana
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3 - i; j++) {
                if (kelas[j].ipk < kelas[j+1].ipk) {
                    Mahasiswa temp = kelas[j];
                    kelas[j]       = kelas[j+1];
                    kelas[j+1]     = temp;
                }
            }
        }

        cout << "Urutan IPK (tertinggi ke terendah):" << endl;
        for (int i = 0; i < 4; i++) {
            cetakMahasiswa(kelas[i], i + 1);
        }


    // ----- 7. Array of Struct - Produk -----
        cout << endl << "=== 7. Contoh: Inventori Produk ===" << endl;

        Produk toko[5] = {
            {"Laptop",    12500000.0,  5},
            {"Mouse",       150000.0, 30},
            {"Keyboard",    350000.0, 20},
            {"Monitor",   3200000.0,   8},
            {"Headset",    450000.0,  15}
        };

        cout << "Daftar Produk:" << endl;
        cout << "  No   Nama         Harga          Stok" << endl;
        cout << "  ---  -----------  -------------  ----" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  " << i+1 << "    "
                << toko[i].nama;
            // padding nama
            int padNama = 12 - toko[i].nama.length();
            for (int p = 0; p < padNama; p++) cout << " ";
            cout << "Rp " << toko[i].harga;
            // padding harga
            cout << "     " << toko[i].stok << endl;
        }

        // Total nilai inventori
            double totalNilai = 0;
            for (int i = 0; i < 5; i++) {
                totalNilai += toko[i].harga * toko[i].stok;
            }
            cout << "Total nilai inventori: Rp " << totalNilai << endl;

        // Produk stok terendah
            int idxStokMin = 0;
            for (int i = 1; i < 5; i++) {
                if (toko[i].stok < toko[idxStokMin].stok) {
                    idxStokMin = i;
                }
            }
            cout << "Produk stok terendah: " << toko[idxStokMin].nama
                << " (" << toko[idxStokMin].stok << " unit)" << endl;

    return 0;
}

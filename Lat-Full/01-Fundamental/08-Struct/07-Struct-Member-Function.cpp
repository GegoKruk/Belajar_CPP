
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ----- Struct Persegi dengan member function -----
    struct Persegi {
        double sisi;

        double luas() {
            return sisi * sisi;
        }

        double keliling() {
            return 4 * sisi;
        }

        void tampilkan() {
            cout << "Persegi: sisi=" << sisi
                << " | luas=" << luas()
                << " | keliling=" << keliling() << endl;
        }
    };

// ----- Struct Lingkaran dengan member function -----
    struct Lingkaran {
        double jariJari;

        double luas() {
            return 3.14159265 * jariJari * jariJari;
        }

        double keliling() {
            return 2 * 3.14159265 * jariJari;
        }

        double diameter() {
            return 2 * jariJari;
        }

        void tampilkan() {
            cout << "Lingkaran: r=" << jariJari << " | luas=" << luas() << " | keliling=" << keliling() << endl;
        }
    };

// ----- Struct Mahasiswa dengan member function -----
    struct Mahasiswa {
        string nama;
        int    umur;
        double ipk;

        void tampilkan() {
            cout << "Mahasiswa: " << nama << " | umur=" << umur << " | ipk=" << ipk << endl;
        }

        string grade() {
            if      (ipk >= 3.75) return "A (Cumlaude)";
            else if (ipk >= 3.50) return "A";
            else if (ipk >= 3.00) return "B";
            else if (ipk >= 2.50) return "C";
            else                  return "D";
        }

        bool lulusHonors() {
            return ipk >= 3.50;
        }

        void updateIPK(double ipkBaru) {
            ipk = ipkBaru;
        }
    };

// ----- Struct Rekening sederhana -----
    struct Rekening {
        string  pemilik;
        double  saldo;
        int     nomorRekening;

        void setor(double jumlah) {
            if (jumlah > 0) {
                saldo += jumlah;
                cout << "  Setor Rp " << jumlah << " -> saldo: Rp " << saldo << endl;
            } else {
                cout << "  Jumlah setor tidak valid!" << endl;
            }
        }

        void tarik(double jumlah) {
            if (jumlah > saldo) {
                cout << "  Saldo tidak cukup! (saldo: Rp " << saldo << ")" << endl;
            } else {
                saldo -= jumlah;
                cout << "  Tarik Rp " << jumlah << " -> saldo: Rp " << saldo << endl;
            }
        }

        void tampilkan() {
            cout << "Rekening " << nomorRekening << " (" << pemilik << ")" << " | Saldo: Rp " << saldo << endl;
        }
    };


int main() {

    // ----- 1. Member Function Persegi -----
        cout << "=== 1. Persegi dengan Member Function ===" << endl;

        Persegi p1 = {5.0};
        p1.tampilkan();

        Persegi p2;
        p2.sisi = 7.5;
        cout << "p2.luas()     = " << p2.luas()     << endl;
        cout << "p2.keliling() = " << p2.keliling() << endl;


    // ----- 2. Member Function Lingkaran -----
        cout << endl << "=== 2. Lingkaran dengan Member Function ===" << endl;

        Lingkaran l1 = {10.0};
        l1.tampilkan();

        cout << "Diameter: " << l1.diameter() << endl;


    // ----- 3. Member Function Mahasiswa -----
        cout << endl << "=== 3. Mahasiswa dengan Member Function ===" << endl;

        Mahasiswa mhs1 = {"Budi", 20, 3.85};
        Mahasiswa mhs2 = {"Sari", 21, 3.20};

        mhs1.tampilkan();
        cout << "  Grade  : " << mhs1.grade()      << endl;
        cout << "  Honors : " << (mhs1.lulusHonors() ? "Ya" : "Tidak") << endl;

        cout << endl;
        mhs2.tampilkan();
        cout << "  Grade  : " << mhs2.grade()      << endl;
        cout << "  Honors : " << (mhs2.lulusHonors() ? "Ya" : "Tidak") << endl;

        // Update via member function
            mhs2.updateIPK(3.65);
            cout << "  Setelah updateIPK(3.65):" << endl;
            mhs2.tampilkan();
            cout << "  Grade baru: " << mhs2.grade() << endl;


    // ----- 4. Member Function Rekening -----
        cout << endl << "=== 4. Rekening dengan Member Function ===" << endl;

        Rekening rek = {"Budi Santoso", 1000000.0, 1001};
        rek.tampilkan();

        rek.setor(500000);
        rek.setor(250000);
        rek.tarik(300000);
        rek.tarik(2000000);   // saldo tidak cukup

        cout << "Status akhir:" << endl;
        rek.tampilkan();


    // ----- 5. Array of Struct + Member Function -----
        cout << endl << "=== 5. Array of Struct + Member Function ===" << endl;

        Mahasiswa kelas[3] = {
            {"Andi", 19, 3.95},
            {"Bela", 20, 2.80},
            {"Cici", 21, 3.55}
        };

        for (int i = 0; i < 3; i++) {
            kelas[i].tampilkan();
            cout << "  Grade: " << kelas[i].grade() << endl;
        }

    return 0;
}

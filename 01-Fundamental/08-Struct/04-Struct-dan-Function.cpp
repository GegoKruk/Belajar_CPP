
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Mahasiswa {
    string nama;
    int    umur;
    double ipk;
};

struct Titik {
    double x;
    double y;
};

struct HasilStatistik {
    double minimum;
    double maksimum;
    double rata;
    double total;
};

// ----- a. Pass by VALUE -----
    void tampilkanValue(Mahasiswa m) {
        cout << "  [by value] " << m.nama << " | " << m.umur << " | " << m.ipk << endl;
        m.ipk = 0.0;   // hanya mengubah salinan, asli tidak berubah
    }

// ----- b. Pass by REFERENCE -----
    void updateIPK(Mahasiswa& m, double ipkBaru) {
        m.ipk = ipkBaru;   // mengubah struct asli!
    }

    void naikkanUmur(Mahasiswa& m) {
        m.umur++;
    }

// ----- c. Pass by CONST REFERENCE -----
    void tampilkanConst(const Mahasiswa& m) {
        cout << "  Nama : " << m.nama << endl;
        cout << "  Umur : " << m.umur << endl;
        cout << "  IPK  : " << m.ipk  << endl;
        // m.ipk = 0.0;   // ERROR - tidak bisa ubah via const ref
    }

// ----- Return struct dari function -----
    Mahasiswa buatMahasiswa(const string& nama, int umur, double ipk) {
        Mahasiswa m;
        m.nama = nama;
        m.umur = umur;
        m.ipk  = ipk;
        return m;
    }

// Return dengan aggregate initialization (lebih ringkas)
    Titik buatTitikTengah(Titik a, Titik b) {
        return {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    }

// Return struct untuk multiple "return values"
    HasilStatistik hitungStatistik(const double data[], int n) {
        HasilStatistik h;
        h.minimum = data[0];
        h.maksimum = data[0];
        h.total    = 0;

        for (int i = 0; i < n; i++) {
            if (data[i] < h.minimum) h.minimum = data[i];
            if (data[i] > h.maksimum) h.maksimum = data[i];
            h.total += data[i];
        }
        h.rata = h.total / n;
        return h;
    }

// Fungsi jarak dua titik (pakai const ref, tidak perlu ubah)
    double jarakTitik(const Titik& a, const Titik& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
    }


int main() {

    // ----- 1. Pass by Value -----
        cout << "=== 1. Pass by Value ===" << endl;

        Mahasiswa mhs1 = {"Budi", 20, 3.85};
        cout << "Sebelum: ipk = " << mhs1.ipk << endl;
        tampilkanValue(mhs1);
        cout << "Sesudah: ipk = " << mhs1.ipk << " (tidak berubah!)" << endl;


    // ----- 2. Pass by Reference -----
        cout << endl << "=== 2. Pass by Reference ===" << endl;

        Mahasiswa mhs2 = {"Sari", 21, 3.70};
        cout << "Sebelum: nama=" << mhs2.nama << " | umur=" << mhs2.umur << " | ipk=" << mhs2.ipk << endl;

        updateIPK(mhs2, 3.95);
        naikkanUmur(mhs2);

        cout << "Sesudah: nama=" << mhs2.nama << " | umur=" << mhs2.umur << " | ipk=" << mhs2.ipk << endl;


    // ----- 3. Pass by Const Reference -----
        cout << endl << "=== 3. Pass by Const Reference ===" << endl;

        Mahasiswa mhs3 = {"Andi", 22, 3.60};
        tampilkanConst(mhs3);


    // ----- 4. Return Struct -----
        cout << endl << "=== 4. Return Struct dari Function ===" << endl;

        Mahasiswa mhsBaru = buatMahasiswa("Dedi", 19, 3.50);
        cout << "Dibuat via function:" << endl;
        tampilkanConst(mhsBaru);


    // ----- 5. Return Struct - Titik Tengah -----
        cout << endl << "=== 5. Return Struct - Titik Tengah ===" << endl;

        Titik p1 = {0.0, 0.0};
        Titik p2 = {6.0, 4.0};
        Titik tengah = buatTitikTengah(p1, p2);

        cout << "p1      : (" << p1.x      << ", " << p1.y      << ")" << endl;
        cout << "p2      : (" << p2.x      << ", " << p2.y      << ")" << endl;
        cout << "Tengah  : (" << tengah.x  << ", " << tengah.y  << ")" << endl;
        cout << "Jarak p1-p2 : " << jarakTitik(p1, p2) << endl;


    // ----- 6. Return Struct untuk Multiple Return Values -----
        cout << endl << "=== 6. Return Struct - Multiple Values ===" << endl;

        double data[] = {85.0, 90.0, 78.0, 92.0, 88.0, 76.0};
        int nd = sizeof(data) / sizeof(data[0]);

        HasilStatistik stat = hitungStatistik(data, nd);

        cout << "Data  : 85 90 78 92 88 76" << endl;
        cout << "Min   : " << stat.minimum  << endl;
        cout << "Maks  : " << stat.maksimum << endl;
        cout << "Total : " << stat.total    << endl;
        cout << "Rata  : " << stat.rata     << endl;


    // ----- 7. Perbandingan Cara Pass -----
        cout << endl << "=== 7. Perbandingan Cara Pass ===" << endl;
        cout << "Cara                    | Salinan? | Ubah asli? | Terbaik untuk" << endl;
        cout << "------------------------+----------+------------+------------------" << endl;
        cout << "by value (Struct m)     |    Ya    |   Tidak    | Struct kecil" << endl;
        cout << "by ref (Struct& m)      |   Tidak  |    Ya      | Perlu modifikasi" << endl;
        cout << "by const ref (const&)   |   Tidak  |   Tidak    | Baca saja (TERBAIK)" << endl;

    return 0;
}

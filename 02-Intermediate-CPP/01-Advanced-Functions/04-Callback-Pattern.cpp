#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// -------------------------------------------------------
// TIPE ALIAS UNTUK CALLBACK
// -------------------------------------------------------
using Predikat    = bool (*)(int);
using Transformasi = int (*)(int);
using KomparatorStr = bool (*)(const string&, const string&);

// -------------------------------------------------------
// POLA 1: FILTER -- PILIH ELEMEN BERDASARKAN PREDIKAT
// -------------------------------------------------------
vector<int> filter(const vector<int>& v, Predikat kondisi) {
    vector<int> hasil;
    for (int x : v) {
        if (kondisi(x)) hasil.push_back(x);
    }
    return hasil;
}

bool adalahGanjil   (int x) { return x % 2 != 0; }
bool adalahPositif  (int x) { return x > 0;       }
bool adalahKelipatan5(int x){ return x % 5 == 0;  }

// -------------------------------------------------------
// POLA 2: MAP/TRANSFORM -- UBAH SETIAP ELEMEN
// -------------------------------------------------------
vector<int> transformasi(const vector<int>& v, Transformasi ubah) {
    vector<int> hasil;
    for (int x : v) hasil.push_back(ubah(x));
    return hasil;
}

int duaKali  (int x) { return x * 2; }
int kuadrat  (int x) { return x * x; }
int nilaiAbs (int x) { return (x < 0) ? -x : x; }

// -------------------------------------------------------
// POLA 3: REDUCE/FOLD -- RINGKAS JADI SATU NILAI
// -------------------------------------------------------
int reduce(const vector<int>& v, int awal, function<int(int, int)> gabung) {
    int akum = awal;
    for (int x : v) akum = gabung(akum, x);
    return akum;
}

// -------------------------------------------------------
// POLA 4: SORT DENGAN KOMPARATOR KUSTOM
// -------------------------------------------------------
void sortDengan(vector<string>& v, KomparatorStr lebihAwal) {
    for (int i = 0; i < (int)v.size() - 1; i++) {
        for (int j = 0; j < (int)v.size() - i - 1; j++) {
            if (!lebihAwal(v[j], v[j+1])) {
                string tmp = v[j];
                v[j]   = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}

bool abjadAsc  (const string& a, const string& b) { return a < b;              }
bool abjadDesc (const string& a, const string& b) { return a > b;              }
bool panjangAsc(const string& a, const string& b) { return a.length() < b.length(); }

// -------------------------------------------------------
// POLA 5: EVENT SYSTEM SEDERHANA
// -------------------------------------------------------
struct Tombol {
    string label;
    function<void(const string&)> onKlik;
    function<void(const string&)> onHover;

    void klik()  const { if (onKlik)  onKlik(label);  }
    void hover() const { if (onHover) onHover(label); }
};

// -------------------------------------------------------
// POLA 6: PIPELINE (RANTAI TRANSFORMASI)
// -------------------------------------------------------
vector<int> pipeline(const vector<int>& v,
                     const vector<function<vector<int>(const vector<int>&)>>& langkah) {
    vector<int> hasil = v;
    for (const auto& fn : langkah) {
        hasil = fn(hasil);
    }
    return hasil;
}

// -------------------------------------------------------
// HELPER
// -------------------------------------------------------
void cetakVector(const vector<int>& v) {
    cout << "  [";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i < (int)v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void cetakVectorStr(const vector<string>& v) {
    cout << "  [";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i < (int)v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    vector<int> data = {-4, 7, 2, -1, 15, 8, -3, 10, 5, 0};

    // -------------------------------------------------------
    // FILTER
    // -------------------------------------------------------
    cout << "=== Pola Filter ===" << endl;
    cout << "  data     :"; cetakVector(data);
    cout << "  ganjil   :"; cetakVector(filter(data, adalahGanjil));
    cout << "  positif  :"; cetakVector(filter(data, adalahPositif));
    cout << "  kelipatan5:";cetakVector(filter(data, adalahKelipatan5));

    // Filter dengan lambda (inline)
    auto lebihDariLima = filter(data, [](int x) { return x > 5; });
    cout << "  > 5      :"; cetakVector(lebihDariLima);

    // -------------------------------------------------------
    // TRANSFORM
    // -------------------------------------------------------
    cout << "\n=== Pola Transform ===" << endl;
    cout << "  data         :"; cetakVector(data);
    cout << "  duaKali      :"; cetakVector(transformasi(data, duaKali));
    cout << "  kuadrat      :"; cetakVector(transformasi(data, kuadrat));
    cout << "  nilaiAbs     :"; cetakVector(transformasi(data, nilaiAbs));

    // Transform dengan lambda
    auto tambah100 = transformasi(data, [](int x) { return x + 100; });
    cout << "  +100         :"; cetakVector(tambah100);

    // -------------------------------------------------------
    // REDUCE
    // -------------------------------------------------------
    cout << "\n=== Pola Reduce ===" << endl;
    vector<int> positif = filter(data, adalahPositif);
    cout << "  data positif :"; cetakVector(positif);

    int total = reduce(positif, 0,  [](int akum, int x) { return akum + x; });
    int produk = reduce(positif, 1, [](int akum, int x) { return akum * x; });
    int maks   = reduce(positif, positif[0], [](int akum, int x) { return akum > x ? akum : x; });

    cout << "  jumlah  = " << total  << endl;
    cout << "  produk  = " << produk << endl;
    cout << "  maksimum= " << maks   << endl;

    // -------------------------------------------------------
    // SORT DENGAN KOMPARATOR
    // -------------------------------------------------------
    cout << "\n=== Sort dengan Komparator ===" << endl;

    vector<string> kota = {"Yogyakarta", "Solo", "Semarang", "Bandung", "Malang"};
    cout << "  asli         :"; cetakVectorStr(kota);

    vector<string> k1 = kota, k2 = kota, k3 = kota;
    sortDengan(k1, abjadAsc);
    sortDengan(k2, abjadDesc);
    sortDengan(k3, panjangAsc);

    cout << "  abjad asc    :"; cetakVectorStr(k1);
    cout << "  abjad desc   :"; cetakVectorStr(k2);
    cout << "  panjang asc  :"; cetakVectorStr(k3);

    // -------------------------------------------------------
    // EVENT SYSTEM
    // -------------------------------------------------------
    cout << "\n=== Event System (Callback) ===" << endl;

    int hitungKlik = 0;

    Tombol btnSimpan;
    btnSimpan.label = "Simpan";
    btnSimpan.onKlik = [&hitungKlik](const string& lbl) {
        hitungKlik++;
        cout << "  [EVENT] " << lbl << " diklik! (total: " << hitungKlik << "x)" << endl;
    };
    btnSimpan.onHover = [](const string& lbl) {
        cout << "  [EVENT] Kursor di atas tombol: " << lbl << endl;
    };

    btnSimpan.hover();
    btnSimpan.klik();
    btnSimpan.klik();
    btnSimpan.klik();

    // Tombol tanpa handler hover (nullptr / kosong)
    Tombol btnBatal;
    btnBatal.label = "Batal";
    btnBatal.onKlik = [](const string& lbl) {
        cout << "  [EVENT] " << lbl << " dibatalkan." << endl;
    };
    btnBatal.hover(); // tidak ada handler, tidak ada output
    btnBatal.klik();

    // -------------------------------------------------------
    // PIPELINE (RANTAI TRANSFORMASI)
    // -------------------------------------------------------
    cout << "\n=== Pipeline ===" << endl;
    cout << "  data     :"; cetakVector(data);

    auto hasil = pipeline(data, {
        [](const vector<int>& v) { return filter(v, adalahPositif); },  // ambil positif
        [](const vector<int>& v) { return transformasi(v, kuadrat);  }, // kuadratkan
        [](const vector<int>& v) {                                       // filter > 20
            return filter(v, [](int x) { return x > 20; });
        }
    });

    cout << "  positif -> kuadrat -> > 20 :"; cetakVector(hasil);

    return 0;
}

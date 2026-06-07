#include <iostream>
#include <string>
using namespace std;

// ================================================================
// KEGUNAAN 1: DISAMBIGUASI NAMA (parameter vs member)
// ================================================================
class Persegi {
    double sisi;
    string warna;

public:
    Persegi(double sisi, const string& warna) {
        // Tanpa this: nama parameter sama dengan nama member
        this->sisi  = sisi;     // this->sisi  = member, sisi  = parameter
        this->warna = warna;    // this->warna = member, warna = parameter
    }

    void setSisi(double sisi) {
        this->sisi = sisi;      // disambiguasi
    }

    void setWarna(const string& warna) {
        this->warna = warna;
    }

    double getLuas()  const { return sisi * sisi; }
    double getSisi()  const { return sisi; }
    string getWarna() const { return warna; }

    void cetak() const {
        cout << "  Persegi: sisi=" << sisi
             << " | warna=" << warna
             << " | luas=" << getLuas() << endl;
    }
};

// ================================================================
// KEGUNAAN 2: METHOD CHAINING (Fluent Interface)
// ================================================================
class QueryBuilder {
    string tabel;
    string kondisi;
    string urutan;
    int    batas;

public:
    QueryBuilder() : batas(0) {}

    QueryBuilder& dari(const string& t) {
        tabel = t;
        return *this;            // kembalikan objek sendiri
    }

    QueryBuilder& dimana(const string& k) {
        kondisi = k;
        return *this;
    }

    QueryBuilder& urutkan(const string& u) {
        urutan = u;
        return *this;
    }

    QueryBuilder& limit(int n) {
        batas = n;
        return *this;
    }

    string bangun() const {
        string q = "SELECT * FROM " + tabel;
        if (!kondisi.empty()) q += " WHERE " + kondisi;
        if (!urutan.empty())  q += " ORDER BY " + urutan;
        if (batas > 0)        q += " LIMIT " + to_string(batas);
        return q;
    }
};

// ================================================================
// KEGUNAAN 3: SELF-COMPARISON (cegah self-assignment)
// ================================================================
class Buffer {
    int* data;
    int  n;

public:
    Buffer(int ukuran) : n(ukuran), data(new int[ukuran]()) {
        for (int i = 0; i < n; i++) data[i] = i + 1;
    }

    ~Buffer() { delete[] data; }

    // Copy assignment operator dengan self-assignment guard
    Buffer& operator=(const Buffer& lain) {
        if (this == &lain) {        // cek self-assignment via this
            cout << "  [Buffer] self-assignment dicegah" << endl;
            return *this;
        }
        delete[] data;
        n    = lain.n;
        data = new int[n];
        for (int i = 0; i < n; i++) data[i] = lain.data[i];
        cout << "  [Buffer] copy berhasil (n=" << n << ")" << endl;
        return *this;
    }

    Buffer(const Buffer& lain) : n(lain.n), data(new int[lain.n]) {
        for (int i = 0; i < n; i++) data[i] = lain.data[i];
    }

    void cetak(const string& label = "") const {
        if (!label.empty()) cout << "  " << label << ": ";
        else cout << "  ";
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << data[i];
            if (i < n - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// ================================================================
// KEGUNAAN 4: MENERUSKAN OBJEK KE FUNCTION LAIN
// ================================================================
class Vektor2D {
public:
    double x, y;

    Vektor2D(double x, double y) : x(x), y(y) {}

    double panjang() const {
        return x * x + y * y;   // kuadrat panjang (sengaja, hindari sqrt)
    }

    bool lebihPanjangDari(const Vektor2D& lain) const {
        return panjang() > lain.panjang();
    }

    // Meneruskan diri sendiri ke function lain
    void bandingkanDengan(const Vektor2D& lain) const {
        if (lebihPanjangDari(lain)) {
            cout << "  (" << x << "," << y << ") lebih panjang" << endl;
        } else if (lain.lebihPanjangDari(*this)) {   // *this = diri sendiri
            cout << "  (" << x << "," << y << ") lebih pendek" << endl;
        } else {
            cout << "  (" << x << "," << y << ") sama panjang" << endl;
        }
    }

    Vektor2D tambah(const Vektor2D& lain) const {
        return Vektor2D(x + lain.x, y + lain.y);
    }

    void cetak() const { cout << "  (" << x << ", " << y << ")" << endl; }
};

// ================================================================
// KEGUNAAN 5: RETURN *this DARI BERBAGAI TIPE
// ================================================================
class Counter {
    int nilai;
    int langkah;

public:
    Counter(int awal = 0, int step = 1) : nilai(awal), langkah(step) {}

    Counter& naik()   { nilai += langkah; return *this; }
    Counter& turun()  { nilai -= langkah; return *this; }
    Counter& reset()  { nilai = 0;        return *this; }

    Counter& setLangkah(int s) {
        langkah = s;
        return *this;
    }

    int  getNilai()   const { return nilai; }
    void cetak()      const { cout << "  counter=" << nilai
                                   << " (step=" << langkah << ")" << endl; }
};

// ================================================================
// DEMONSTRASI: this sebagai alamat objek
// ================================================================
class AlamatDemo {
    int id;
public:
    explicit AlamatDemo(int i) : id(i) {}

    void tampilkanAlamat() const {
        cout << "  objek [id=" << id << "] ada di alamat: " << this << endl;
    }

    const AlamatDemo* ambilThis() const { return this; }
};

int main() {

    // -------------------------------------------------------
    // DISAMBIGUASI NAMA
    // -------------------------------------------------------
    cout << "=== 1. Disambiguasi Nama ===" << endl;
    {
        Persegi p1(5.0, "merah");
        p1.cetak();

        p1.setSisi(7.5);
        p1.setWarna("biru");
        p1.cetak();
    }

    // -------------------------------------------------------
    // METHOD CHAINING
    // -------------------------------------------------------
    cout << "\n=== 2. Method Chaining (Fluent Interface) ===" << endl;
    {
        QueryBuilder qb;

        // Tanpa chaining (verbose):
        qb.dari("mahasiswa");
        qb.dimana("ipk > 3.5");
        qb.urutkan("nama ASC");
        qb.limit(10);
        cout << "  Tanpa chain: " << qb.bangun() << endl;

        // Dengan chaining (ringkas):
        string query = QueryBuilder()
            .dari("mahasiswa")
            .dimana("ipk > 3.5")
            .urutkan("nama ASC")
            .limit(10)
            .bangun();
        cout << "  Dengan chain: " << query << endl;

        // Chaining sebagian
        string q2 = QueryBuilder()
            .dari("nilai")
            .urutkan("skor DESC")
            .limit(5)
            .bangun();
        cout << "  Sebagian    : " << q2 << endl;
    }

    // -------------------------------------------------------
    // SELF-ASSIGNMENT GUARD
    // -------------------------------------------------------
    cout << "\n=== 3. Self-Assignment Guard (this == &lain) ===" << endl;
    {
        Buffer b1(4);
        Buffer b2(4);

        b1.cetak("b1 awal");
        b2.cetak("b2 awal");

        b2 = b1;           // copy normal
        b2.cetak("b2 setelah copy dari b1");

        b1 = b1;           // self-assignment -- harus dicegah!
        b1.cetak("b1 setelah self-assign");
    }

    // -------------------------------------------------------
    // MENERUSKAN *this KE FUNCTION
    // -------------------------------------------------------
    cout << "\n=== 4. Meneruskan *this ke Function ===" << endl;
    {
        Vektor2D v1(3.0, 4.0);
        Vektor2D v2(1.0, 1.0);
        Vektor2D v3(3.0, 4.0);

        cout << "  v1(3,4) vs v2(1,1): "; v1.bandingkanDengan(v2);
        cout << "  v2(1,1) vs v1(3,4): "; v2.bandingkanDengan(v1);
        cout << "  v1(3,4) vs v3(3,4): "; v1.bandingkanDengan(v3);

        Vektor2D hasil = v1.tambah(v2);
        cout << "  v1 + v2 = "; hasil.cetak();
    }

    // -------------------------------------------------------
    // RETURN *this: BERBAGAI OPERASI
    // -------------------------------------------------------
    cout << "\n=== 5. Return *this ===" << endl;
    {
        Counter c1;

        c1.naik().naik().naik();
        cout << "  setelah naik x3: "; c1.cetak();

        c1.setLangkah(5).naik().naik();
        cout << "  step=5, naik x2: "; c1.cetak();

        c1.reset().setLangkah(1).naik();
        cout << "  reset, step=1, naik: "; c1.cetak();

        // Dua objek bebas -- this berbeda
        Counter c2(10), c3(100);
        c2.naik().naik();
        c3.turun().turun().turun();
        cout << "  c2: "; c2.cetak();
        cout << "  c3: "; c3.cetak();
    }

    // -------------------------------------------------------
    // THIS SEBAGAI ALAMAT OBJEK
    // -------------------------------------------------------
    cout << "\n=== 6. this sebagai Alamat Objek ===" << endl;
    {
        AlamatDemo obj1(1), obj2(2), obj3(3);

        obj1.tampilkanAlamat();
        obj2.tampilkanAlamat();
        obj3.tampilkanAlamat();

        // Verifikasi bahwa this == alamat objek
        const AlamatDemo* p1 = obj1.ambilThis();
        cout << "  &obj1          = " << &obj1 << endl;
        cout << "  ambilThis()    = " << p1    << endl;
        cout << "  sama?            " << (&obj1 == p1 ? "Ya" : "Tidak") << endl;
    }

    cout << "\n=== Ringkasan: Kegunaan this ===" << endl;
    cout << "  1. Disambiguasi nama member vs parameter" << endl;
    cout << "  2. Method chaining (return *this)" << endl;
    cout << "  3. Self-assignment check (this == &lain)" << endl;
    cout << "  4. Teruskan objek sendiri ke function lain" << endl;
    cout << "  5. Fondasi dari seluruh mekanisme OOP di C++!" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
using namespace std;

// ================================================================
// HELPER: cetak heading
// ================================================================
void heading(const string& judul) {
    cout << "\n=== " << judul << " ===" << endl;
}

// ================================================================
// ATURAN 1: PASANGKAN new DENGAN delete YANG TEPAT
// ================================================================
void demo_new_delete_pasangan() {
    heading("1. Pasangkan new dengan delete yang tepat");

    // BENAR: scalar new -> scalar delete
    int* a = new int(10);
    cout << "  scalar: *a = " << *a << endl;
    delete a;
    a = nullptr;

    // BENAR: array new -> array delete
    int* b = new int[5]{1,2,3,4,5};
    cout << "  array : b[4] = " << b[4] << endl;
    delete[] b;
    b = nullptr;

    // JANGAN PERNAH: new[] dengan delete (hanya hapus elemen 0, sisanya LEAK)
    // int* c = new int[5];
    // delete c;   // SALAH -- gunakan delete[]

    cout << "  Aturan: new -> delete | new[] -> delete[]" << endl;
}

// ================================================================
// ATURAN 2: LANGSUNG SET nullptr SETELAH delete
// ================================================================
void demo_nullptr_setelah_delete() {
    heading("2. Set nullptr setelah delete");

    int* p = new int(55);

    // BENAR
    delete p;
    p = nullptr;

    // Guard sebelum akses
    if (p != nullptr) {
        cout << "  *p = " << *p << endl;
    } else {
        cout << "  p = nullptr -- akses dicegah (aman)" << endl;
    }

    // Guard sebelum delete kedua (cegah double free)
    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
    cout << "  double free dicegah via nullptr check" << endl;
}

// ================================================================
// ATURAN 3: PREFER unique_ptr SEBAGAI DEFAULT
// ================================================================
struct Data {
    string label;
    int    nilai;
    Data(const string& l, int v) : label(l), nilai(v) {
        cout << "    [Data] buat: " << label << endl;
    }
    ~Data() {
        cout << "    [Data] hapus: " << label << endl;
    }
};

void demo_prefer_unique_ptr() {
    heading("3. Prefer unique_ptr sebagai default");

    // Buruk: raw pointer -- harus ingat delete, rawan leak
    // Data* p = new Data("manual", 1);
    // delete p;   // harus ingat!

    // Baik: unique_ptr -- otomatis, zero overhead
    auto up = make_unique<Data>("unik", 42);
    cout << "  label=" << up->label << " | nilai=" << up->nilai << endl;
    // delete otomatis saat 'up' keluar scope

    // Dengan array
    auto arr = make_unique<int[]>(4);
    for (int i = 0; i < 4; i++) arr[i] = i * 5;
    cout << "  arr: ";
    for (int i = 0; i < 4; i++) cout << arr[i] << " ";
    cout << endl;
}

// ================================================================
// ATURAN 4: PREFER shared_ptr UNTUK KEPEMILIKAN BERSAMA
// ================================================================
void demo_prefer_shared_ptr() {
    heading("4. Prefer shared_ptr untuk kepemilikan bersama");

    auto sp = make_shared<Data>("bersama", 99);
    cout << "  count setelah buat: " << sp.use_count() << endl;

    {
        auto sp2 = sp;
        auto sp3 = sp;
        cout << "  count dengan 3 pemilik: " << sp.use_count() << endl;
        sp3->label = "bersama-modifikasi";
        cout << "  sp->label via sp: " << sp->label << endl;
    }

    cout << "  count setelah sp2 & sp3 mati: " << sp.use_count() << endl;
}

// ================================================================
// ATURAN 5: PREFER STANDARD CONTAINERS ATAS ARRAY MANUAL
// ================================================================
void demo_prefer_containers() {
    heading("5. Prefer standard containers atas array manual");

    // Buruk: dynamic array manual
    int n = 5;
    int* raw = new int[n]{10, 20, 30, 40, 50};
    cout << "  raw   : ";
    for (int i = 0; i < n; i++) cout << raw[i] << " ";
    cout << "(manual delete diperlukan)" << endl;
    delete[] raw;

    // Baik: vector<int> -- RAII built-in, bisa resize, aman
    vector<int> v = {10, 20, 30, 40, 50};
    v.push_back(60);   // mudah tambah elemen
    cout << "  vector: ";
    for (int x : v) cout << x << " ";
    cout << "(no delete needed!)" << endl;
}

// ================================================================
// ATURAN 6: SATU PEMILIK JELAS (OWNERSHIP)
// ================================================================

// BURUK: return raw pointer -- siapa yang delete?
int* buatData_BURUK(int val) {
    return new int(val);   // caller harus ingat delete -- tidak jelas!
}

// BAIK: return unique_ptr -- ownership eksplisit
unique_ptr<int> buatData_BAIK(int val) {
    return make_unique<int>(val);  // ownership berpindah ke caller
}

void demo_ownership_jelas() {
    heading("6. Ownership yang jelas");

    // Buruk (raw pointer -- caller harus tahu harus delete)
    int* p = buatData_BURUK(77);
    cout << "  raw return: *p = " << *p << " (caller harus delete!)" << endl;
    delete p; p = nullptr;

    // Baik (unique_ptr -- ownership jelas, otomatis)
    auto up = buatData_BAIK(88);
    cout << "  unique_ptr: *up = " << *up << " (auto delete)" << endl;
}

// ================================================================
// ATURAN 7: TANGANI KEGAGALAN ALOKASI
// ================================================================
void demo_tangani_gagal_alokasi() {
    heading("7. Tangani kegagalan alokasi");

    // Cara 1: try-catch bad_alloc
    try {
        long long n = 2000000000LL;
        int* besar = new int[n];
        delete[] besar;
    } catch (const bad_alloc& e) {
        cout << "  bad_alloc tertangkap: " << e.what() << endl;
    }

    // Cara 2: nothrow new
    long long n2 = 2000000000LL;
    int* p = new (nothrow) int[n2];
    if (p == nullptr) {
        cout << "  nothrow: alokasi gagal, p = nullptr (aman)" << endl;
    } else {
        delete[] p;
    }
}

// ================================================================
// ATURAN 8: RAII UNTUK RESOURCE APAPUN
// ================================================================
class KoneksiDB {
    string nama_;
    bool   terhubung_;
public:
    explicit KoneksiDB(const string& nama) : nama_(nama), terhubung_(true) {
        cout << "    [DB] CONNECT ke " << nama_ << endl;
    }
    ~KoneksiDB() {
        if (terhubung_) {
            cout << "    [DB] DISCONNECT dari " << nama_ << " (otomatis)" << endl;
        }
    }
    void query(const string& sql) {
        cout << "    [DB] QUERY: " << sql << endl;
    }
    KoneksiDB(const KoneksiDB&)            = delete;
    KoneksiDB& operator=(const KoneksiDB&) = delete;
};

void demo_raii_resource() {
    heading("8. RAII untuk semua jenis resource");
    {
        KoneksiDB db("localhost:5432");
        db.query("SELECT * FROM mahasiswa");
        db.query("UPDATE nilai SET ipk=3.9 WHERE id=1");
    }   // disconnect otomatis -- tidak perlu panggil disconnect manual!
}

// ================================================================
// HIRARKI PILIHAN: RINGKASAN AKHIR
// ================================================================
void tampilkan_hierarki() {
    heading("Hierarki Pilihan Memory Management");
    cout << "  (dari PALING AMAN ke paling tidak disarankan)" << endl << endl;
    cout << "  [1] Variabel lokal di stack" << endl;
    cout << "      int x = 10; -- paling sederhana dan cepat" << endl << endl;
    cout << "  [2] Standard containers" << endl;
    cout << "      vector<T>, string, array<T,N> -- RAII built-in" << endl << endl;
    cout << "  [3] unique_ptr" << endl;
    cout << "      make_unique<T> -- single ownership, zero overhead" << endl << endl;
    cout << "  [4] shared_ptr" << endl;
    cout << "      make_shared<T> -- shared ownership, overhead refcount" << endl << endl;
    cout << "  [5] Raw new/delete" << endl;
    cout << "      Hanya untuk: implementasi container, API C lama" << endl;
    cout << "      Wajib sangat disiplin dan dokumentasi jelas" << endl << endl;
    cout << "  Ingat: di C++ modern, raw new/delete di luar class JARANG muncul!" << endl;
}

int main() {
    demo_new_delete_pasangan();
    demo_nullptr_setelah_delete();
    demo_prefer_unique_ptr();
    demo_prefer_shared_ptr();
    demo_prefer_containers();
    demo_ownership_jelas();
    demo_tangani_gagal_alokasi();
    demo_raii_resource();
    tampilkan_hierarki();

    return 0;
}

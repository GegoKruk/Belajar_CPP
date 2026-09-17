#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// ================================================================
// STRUCT HELPER UNTUK DEMONSTRASI (dengan log constructor/destructor)
// ================================================================
struct Sumber {
    string nama;
    int    nilai;

    Sumber(const string& n, int v) : nama(n), nilai(v) {
        cout << "    [Sumber] +" << nama << " dibuat (nilai=" << nilai << ")" << endl;
    }

    ~Sumber() {
        cout << "    [Sumber] -" << nama << " dihapus" << endl;
    }

    void info() const {
        cout << "    [Sumber] " << nama << " | nilai=" << nilai << endl;
    }
};

// ================================================================
// BAGIAN 1: unique_ptr -- KEPEMILIKAN EKSKLUSIF
// ================================================================
void demo_unique_ptr_dasar() {
    cout << "\n  --- unique_ptr dasar ---" << endl;

    // Cara membuat (selalu pakai make_unique!)
    auto p1 = make_unique<int>(42);
    auto p2 = make_unique<Sumber>("Alpha", 100);

    cout << "    *p1 = " << *p1 << endl;
    p2->info();

    // Akses seperti pointer biasa
    *p1 = 99;
    cout << "    *p1 setelah modifikasi = " << *p1 << endl;

    // Tidak perlu delete -- otomatis saat p1 dan p2 keluar scope
}

void demo_unique_ptr_move() {
    cout << "\n  --- unique_ptr: transfer ownership (move) ---" << endl;

    auto src = make_unique<Sumber>("Beta", 200);
    cout << "    src valid = " << (src != nullptr) << endl;
    src->info();

    // Tidak bisa copy -- hanya bisa MOVE
    // auto dst = src;       // ERROR: copy dinonaktifkan

    auto dst = move(src);   // transfer kepemilikan
    cout << "    setelah move:" << endl;
    cout << "    src valid = " << (src == nullptr) << " (sekarang nullptr)" << endl;
    cout << "    dst valid = " << (dst != nullptr) << endl;
    dst->info();
}

void demo_unique_ptr_reset_release() {
    cout << "\n  --- unique_ptr: reset & release ---" << endl;

    auto p = make_unique<int>(77);
    cout << "    *p = " << *p << endl;

    p.reset(new int(88));          // hapus lama, pegang yang baru
    cout << "    setelah reset: *p = " << *p << endl;

    p.reset();                     // hapus dan set nullptr
    cout << "    setelah reset(): p valid = " << (p != nullptr) << endl;

    auto q = make_unique<int>(55);
    int* raw = q.release();        // lepas kepemilikan -- q jadi nullptr
    cout << "    setelah release: q valid = " << (q != nullptr) << endl;
    cout << "    raw ptr: *raw = " << *raw << " (kita yang bertanggung jawab!)" << endl;
    delete raw;                    // karena sudah release, kita yang delete
    raw = nullptr;
}

void demo_unique_ptr_array() {
    cout << "\n  --- unique_ptr untuk array ---" << endl;

    auto arr = make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) arr[i] = (i + 1) * 11;

    cout << "    isi: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
    // delete[] otomatis saat arr keluar scope
}

// ================================================================
// BAGIAN 2: shared_ptr -- KEPEMILIKAN BERSAMA
// ================================================================
void demo_shared_ptr_dasar() {
    cout << "\n  --- shared_ptr dasar ---" << endl;

    auto sp1 = make_shared<Sumber>("Gamma", 300);
    cout << "    use_count setelah sp1 = " << sp1.use_count() << endl;

    {
        auto sp2 = sp1;   // copy -- reference count naik
        cout << "    use_count setelah sp2 = " << sp1.use_count() << endl;

        auto sp3 = sp1;   // copy lagi
        cout << "    use_count setelah sp3 = " << sp1.use_count() << endl;
        sp3->info();
    }   // sp2 dan sp3 keluar scope -- count turun

    cout << "    use_count setelah sp2 & sp3 mati = " << sp1.use_count() << endl;

    // sp1 keluar scope di akhir fungsi ini -> count 0 -> DELETE otomatis
}

void demo_shared_ptr_banyak_pemilik() {
    cout << "\n  --- shared_ptr: satu objek, banyak pemilik ---" << endl;

    vector<shared_ptr<Sumber>> kontainer;
    {
        auto sp = make_shared<Sumber>("Delta", 400);
        kontainer.push_back(sp);
        kontainer.push_back(sp);
        kontainer.push_back(sp);

        cout << "    dalam scope: use_count = " << sp.use_count() << endl;
    }   // sp lokal mati -- tapi kontainer masih memegang

    cout << "    luar scope: use_count = " << kontainer[0].use_count() << endl;
    kontainer[0]->info();
    kontainer.clear();   // semua dibersihkan -> count 0 -> DELETE
    cout << "    setelah clear kontainer" << endl;
}

// ================================================================
// BAGIAN 3: weak_ptr -- OBSERVASI TANPA KEPEMILIKAN
// ================================================================
void demo_weak_ptr() {
    cout << "\n  --- weak_ptr: observasi tanpa kepemilikan ---" << endl;

    auto sp = make_shared<Sumber>("Epsilon", 500);
    weak_ptr<Sumber> wp = sp;   // tidak tambah reference count!

    cout << "    sp use_count = " << sp.use_count() << " (tidak berubah)" << endl;
    cout << "    wp expired   = " << wp.expired()    << " (belum kadaluarsa)" << endl;

    // Untuk akses via weak_ptr, harus lock() dulu
    if (auto locked = wp.lock()) {
        cout << "    via wp.lock(): ";
        locked->info();
    }

    // Hapus sp -- objek seharusnya didelete
    sp.reset();
    cout << "    setelah sp.reset():" << endl;
    cout << "    wp expired = " << wp.expired() << " (sudah kadaluarsa)" << endl;

    if (wp.lock() == nullptr) {
        cout << "    wp.lock() = nullptr -- objek sudah tidak ada" << endl;
    }
}

// ================================================================
// BAGIAN 4: MENCEGAH CIRCULAR REFERENCE DENGAN weak_ptr
// ================================================================
struct Node {
    string nama;
    shared_ptr<Node> kanan;   // pemilik ke kanan
    weak_ptr<Node>   kiri;    // OBSERVER ke kiri (tidak punya)

    Node(const string& n) : nama(n) {
        cout << "    [Node] +" << nama << " dibuat" << endl;
    }
    ~Node() {
        cout << "    [Node] -" << nama << " dihapus" << endl;
    }
};

void demo_circular_reference() {
    cout << "\n  --- weak_ptr: cegah circular reference ---" << endl;

    auto nodeA = make_shared<Node>("A");
    auto nodeB = make_shared<Node>("B");

    nodeA->kanan = nodeB;   // A punya B (shared)
    nodeB->kiri  = nodeA;   // B hanya observasi A (weak, tidak tambah count)

    cout << "    nodeA use_count = " << nodeA.use_count() << endl;
    cout << "    nodeB use_count = " << nodeB.use_count() << endl;

    // Saat keluar scope: A count=1 -> 0 (delete A), B count=2 -> 1 -> 0 (delete B)
    cout << "    keluar scope -> keduanya akan dihapus (tidak ada circular leak)" << endl;
}

// ================================================================
// BAGIAN 5: PERBANDINGAN RAW vs SMART POINTER
// ================================================================
void demo_perbandingan() {
    cout << "\n  --- Raw vs Smart Pointer ---" << endl;

    cout << "    [Raw]    manual new/delete:" << endl;
    {
        Sumber* p = new Sumber("Raw", 999);
        p->info();
        delete p;   // WAJIB ingat!
        p = nullptr;
    }

    cout << "    [unique] make_unique (satu pemilik):" << endl;
    {
        auto p = make_unique<Sumber>("UniqueZ", 111);
        p->info();
    }   // otomatis -- tidak perlu delete

    cout << "    [shared] make_shared (banyak pemilik):" << endl;
    {
        auto p1 = make_shared<Sumber>("SharedZ", 222);
        auto p2 = p1;
        p1->info();
        cout << "    count = " << p1.use_count() << endl;
    }   // otomatis saat count = 0
}

int main() {

    cout << "=== unique_ptr ===" << endl;
    demo_unique_ptr_dasar();
    demo_unique_ptr_move();
    demo_unique_ptr_reset_release();
    demo_unique_ptr_array();

    cout << "\n=== shared_ptr ===" << endl;
    demo_shared_ptr_dasar();
    demo_shared_ptr_banyak_pemilik();

    cout << "\n=== weak_ptr ===" << endl;
    demo_weak_ptr();
    demo_circular_reference();

    cout << "\n=== Perbandingan Raw vs Smart ===" << endl;
    demo_perbandingan();

    cout << "\n=== Panduan Memilih ===" << endl;
    cout << "  unique_ptr : default pilihan -- satu pemilik -- zero overhead" << endl;
    cout << "  shared_ptr : kepemilikan bersama -- ada overhead refcount" << endl;
    cout << "  weak_ptr   : observasi -- cegah circular reference" << endl;
    cout << "  raw new    : hanya untuk implementasi low-level / API C lama" << endl;

    return 0;
}

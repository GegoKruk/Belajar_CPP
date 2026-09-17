
#include <iostream>
#include <string>
using namespace std;


// ============================================================
// MODIFIKASI STRING
// ============================================================

void demoPushPopClear() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  1. push_back(), pop_back(), clear()" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Halo";
    cout << "\n  s = \"" << s << "\"" << endl;

    // push_back -- tambah 1 karakter di akhir
        s.push_back('!');
        cout << "  s.push_back('!') -> \"" << s << "\"" << endl;
        s.push_back('!');
        cout << "  s.push_back('!') -> \"" << s << "\"" << endl;

    // pop_back -- hapus 1 karakter di akhir
        s.pop_back();
        cout << "  s.pop_back()     -> \"" << s << "\"" << endl;
        s.pop_back();
        cout << "  s.pop_back()     -> \"" << s << "\"" << endl;

    // Bangun string karakter per karakter
        cout << "\n  Bangun string satu karakter sekaligus:" << endl;
        string hasil;
        char huruf[] = {'C', '+', '+', ' ', 'A', 's', 'y', 'i', 'k'};
        for (char c : huruf) {
            hasil.push_back(c);
            cout << "  push '" << c << "' -> \"" << hasil << "\"" << endl;
        }

    // clear -- kosongkan semua isi
        cout << "\n  s.clear():" << endl;
        cout << "  Sebelum: \"" << s << "\" (length=" << s.length() << ")" << endl;
        s.clear();
        cout << "  Sesudah: \"" << s << "\" (length=" << s.length() << ")" << endl;
        cout << "  s.empty() setelah clear: " << (s.empty() ? "true" : "false") << endl;
}

void demoResize() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  2. resize() -- Ubah Panjang String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Hello World";
    cout << "\n  s = \"" << s << "\" (length=" << s.length() << ")" << endl;

    // resize lebih kecil -- potong
        s.resize(5);
        cout << "  s.resize(5)    -> \"" << s << "\" (dipotong)" << endl;

    // resize lebih besar -- tambah karakter null
        s.resize(10);
        cout << "  s.resize(10)   -> \"" << s << "\" + 5 karakter null (\\0)" << endl;
        cout << "  s.length()     = " << s.length() << endl;

    // resize lebih besar dengan karakter pengisi
        s = "Halo";
        s.resize(10, '*');
        cout << "\n  s=\"Halo\", s.resize(10,'*') -> \"" << s << "\"" << endl;
        cout << "  (slot baru diisi '*')" << endl;
}

void demoInsert() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  3. insert() -- Sisipkan di Posisi Tertentu" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Halo World";
    cout << "\n  s = \"" << s << "\"" << endl;

    // insert(pos, str) -- sisipkan string di posisi pos
        s.insert(5, " Indah");
        cout << "  s.insert(5, \" Indah\") -> \"" << s << "\"" << endl;

    // insert di awal (posisi 0)
        s = "World";
        s.insert(0, "Halo ");
        cout << "\n  s=\"World\", s.insert(0, \"Halo \") -> \"" << s << "\"" << endl;

    // insert di akhir (pakai length sebagai posisi)
        s = "Halo";
        s.insert(s.length(), "!!!");
        cout << "  s=\"Halo\", s.insert(s.length(),\"!!!\") -> \"" << s << "\"" << endl;

    // insert karakter
        s = "HloWorld";
        s.insert(1, "a");   // sisipkan "a" di posisi 1
        s.insert(4, " ");   // sisipkan spasi di posisi 4
        cout << "\n  Sisip karakter satu per satu -> \"" << s << "\"" << endl;

    // Demonstrasi index sebelum dan sesudah insert
        cout << "\n  Cara baca insert(pos, str):" << endl;
        cout << "  Sisipkan str SEBELUM karakter di posisi pos." << endl;
        cout << "  s = \"ABCDE\", s.insert(2, \"XX\") -> \"ABXXCDE\"" << endl;
        string demo = "ABCDE";
        demo.insert(2, "XX");
        cout << "  Hasil: \"" << demo << "\"" << endl;
}

void demoErase() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  4. erase() -- Hapus Bagian String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Hello Beautiful World";
    cout << "\n  s = \"" << s << "\"" << endl;

    // erase(pos, len) -- hapus len karakter mulai pos
        s.erase(5, 10);   // hapus " Beautiful" (10 karakter dari index 5)
        cout << "  s.erase(5, 10) -> \"" << s << "\"" << endl;

    // erase(pos) -- hapus dari pos sampai akhir
        s = "Hello World Extra";
        s.erase(11);   // hapus dari index 11 sampai akhir
        cout << "\n  s=\"Hello World Extra\"" << endl;
        cout << "  s.erase(11)    -> \"" << s << "\"" << endl;

    // erase semua -- sama dengan clear()
        s = "Hapus Semua";
        s.erase(0);   // hapus dari index 0 sampai akhir = hapus semua
        cout << "\n  s.erase(0)     -> \"" << s << "\" (sama dengan clear)" << endl;

    // erase satu karakter
        s = "Haalloo";
        cout << "\n  Hapus duplikat satu per satu dari \"" << s << "\":" << endl;
        s.erase(1, 1);   // hapus 1 karakter dari index 1
        cout << "  Hapus index 1 -> \"" << s << "\"" << endl;
        s.erase(4, 1);   // hapus 1 karakter dari index 4
        cout << "  Hapus index 4 -> \"" << s << "\"" << endl;
}

void demoReplace() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  5. replace() -- Ganti Bagian String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string s = "Hello World";
    cout << "\n  s = \"" << s << "\"" << endl;

    // replace(pos, len, new_str) -- ganti len karakter dari pos dengan new_str
        s.replace(6, 5, "C++");   // ganti "World" (5 karakter dari index 6) dengan "C++"
        cout << "  s.replace(6, 5, \"C++\") -> \"" << s << "\"" << endl;

    // Pengganti boleh lebih panjang
        s = "Halo Dunia";
        s.replace(5, 5, "Indonesia Raya");
        cout << "\n  s=\"Halo Dunia\"" << endl;
        cout << "  s.replace(5,5,\"Indonesia Raya\") -> \"" << s << "\"" << endl;

    // Pengganti boleh lebih pendek / kosong
        s = "Halo Dunia Indah";
        s.replace(4, 6, "");   // ganti " Dunia" dengan "" (hapus)
        cout << "\n  s.replace(4,6,\"\") -> \"" << s << "\"" << endl;

    // Ganti semua kemunculan substring
        cout << "\n  Ganti semua 'a' dengan '@' di \"banana\":" << endl;
        string buah = "banana";
        size_t pos = buah.find('a');
        while (pos != string::npos) {
            buah.replace(pos, 1, "@");
            pos = buah.find('a', pos + 1);
        }
        cout << "  Hasil: \"" << buah << "\"" << endl;
}

void demoManajemenMemori() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  6. reserve() & shrink_to_fit() -- Manajemen Memori" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  Konsep:" << endl;
    cout << "  - size()     = jumlah karakter aktual" << endl;
    cout << "  - capacity() = memori yang sudah dialokasikan (>= size)" << endl;
    cout << "  - Saat string tumbuh, mungkin ada realokasi memori" << endl;

    string s;
    cout << "\n  string s; (kosong)" << endl;
    cout << "  size=" << s.size() << ", capacity=" << s.capacity() << endl;

    // reserve untuk optimasi -- hindari realokasi berulang
        s.reserve(100);
        cout << "\n  s.reserve(100)  <- alokasi dulu sebelum append banyak" << endl;
        cout << "  size=" << s.size() << ", capacity=" << s.capacity() << endl;

    // Sekarang append tanpa realokasi berulang
        for (int i = 0; i < 50; i++) s += 'x';
        cout << "\n  Setelah 50x append 'x':" << endl;
        cout << "  size=" << s.size() << ", capacity=" << s.capacity() << endl;

    // shrink_to_fit -- kembalikan memori berlebih
        s = "Halo";
        s.reserve(1000);
        cout << "\n  s=\"Halo\", reserve(1000): size=" << s.size() << ", capacity=" << s.capacity() << endl;
        s.shrink_to_fit();
        cout << "  Setelah shrink_to_fit(): size=" << s.size() << ", capacity=" << s.capacity() << endl;

        cout << "\n  Kapan pakai reserve():" << endl;
        cout << "  - Tahu akan append banyak data -> reserve dulu untuk efisiensi" << endl;
        cout << "  - Hindari realokasi memori berulang saat loop append" << endl;
}


// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "============================================================" << endl;
    cout << "  V.4 -- Modifikasi String" << endl;
    cout << "============================================================" << endl;

    demoPushPopClear();
    demoResize();
    demoInsert();
    demoErase();
    demoReplace();
    demoManajemenMemori();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  push_back(c)         -> tambah karakter di akhir" << endl;
    cout << "  pop_back()           -> hapus karakter terakhir" << endl;
    cout << "  clear()              -> kosongkan semua isi" << endl;
    cout << "  resize(n)            -> potong atau panjangkan" << endl;
    cout << "  resize(n, 'c')       -> panjangkan dan isi dengan 'c'" << endl;
    cout << "  insert(pos, str)     -> sisipkan str SEBELUM posisi pos" << endl;
    cout << "  erase(pos, len)      -> hapus len karakter dari pos" << endl;
    cout << "  erase(pos)           -> hapus dari pos sampai akhir" << endl;
    cout << "  replace(pos,len,baru)-> ganti len karakter dari pos" << endl;
    cout << "  reserve(n)           -> alokasi memori minimal n (optimasi)" << endl;

    return 0;
}

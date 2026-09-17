
#include <iostream>
#include <string>
using namespace std;


// ----- Struct sederhana: tipe primitif -----
    struct Titik {
        double x;
        double y;
    };

// ----- Struct dengan berbagai tipe -----
    struct Produk {
        string  nama;
        double  harga;
        int     stok;
        bool    tersedia;
    };

// ----- Struct dengan array sebagai member -----
    struct Siswa {
        string nama;
        int    umur;
        double nilai[5];    // array sebagai member
        int    jumlahNilai;
    };

// ----- Struct dengan default member values (C++11) -----
    struct Konfigurasi {
        string server   = "localhost";
        int    port     = 8080;
        bool   debug    = false;
        int    timeout  = 30;
    };

// ----- Struct dengan pointer sebagai member -----
    struct Node {
        int   data;
        Node* next;    // pointer ke struct yang sama (linked list)
    };


int main() {

    // ----- 1. Struct Titik (sederhana) -----
        cout << "=== 1. Struct Titik ===" << endl;

        Titik t1;
        t1.x = 3.5;
        t1.y = 7.2;

        Titik t2 = {-1.0, 4.5};

        cout << "t1: (" << t1.x << ", " << t1.y << ")" << endl;
        cout << "t2: (" << t2.x << ", " << t2.y << ")" << endl;
        cout << "sizeof(Titik) = " << sizeof(Titik) << " byte" << endl;


    // ----- 2. Struct Produk (berbagai tipe) -----
        cout << endl << "=== 2. Struct Produk ===" << endl;

        Produk p1;
        p1.nama      = "Laptop";
        p1.harga     = 12500000.0;
        p1.stok      = 15;
        p1.tersedia  = true;

        cout << "Nama      : " << p1.nama     << endl;
        cout << "Harga     : Rp " << p1.harga << endl;
        cout << "Stok      : " << p1.stok     << endl;
        cout << "Tersedia  : " << (p1.tersedia ? "Ya" : "Tidak") << endl;
        cout << "sizeof(Produk) = " << sizeof(Produk) << " byte" << endl;


    // ----- 3. Struct dengan Array Member -----
        cout << endl << "=== 3. Struct dengan Array Member ===" << endl;

        Siswa s1;
        s1.nama  = "Andi";
        s1.umur  = 17;
        s1.nilai[0] = 85;
        s1.nilai[1] = 90;
        s1.nilai[2] = 78;
        s1.nilai[3] = 92;
        s1.nilai[4] = 88;
        s1.jumlahNilai = 5;

        double total = 0;
        for (int i = 0; i < s1.jumlahNilai; i++) {
            total += s1.nilai[i];
        }
        double rata = total / s1.jumlahNilai;

        cout << "Nama  : " << s1.nama << endl;
        cout << "Umur  : " << s1.umur << endl;
        cout << "Nilai : ";
        for (int i = 0; i < s1.jumlahNilai; i++) {
            cout << s1.nilai[i] << " ";
        }
        cout << endl;
        cout << "Rata-rata: " << rata << endl;


    // ----- 4. Struct dengan Default Member Values -----
        cout << endl << "=== 4. Default Member Values (C++11) ===" << endl;

        Konfigurasi cfg1;   // pakai semua default
        Konfigurasi cfg2;
        cfg2.port  = 443;   // hanya ubah port
        cfg2.debug = true;  // dan debug

        cout << "Konfigurasi 1 (semua default):" << endl;
        cout << "  server  : " << cfg1.server  << endl;
        cout << "  port    : " << cfg1.port    << endl;
        cout << "  debug   : " << (cfg1.debug ? "on" : "off") << endl;
        cout << "  timeout : " << cfg1.timeout << "s" << endl;

        cout << "Konfigurasi 2 (port & debug diubah):" << endl;
        cout << "  server  : " << cfg2.server  << endl;
        cout << "  port    : " << cfg2.port    << endl;
        cout << "  debug   : " << (cfg2.debug ? "on" : "off") << endl;
        cout << "  timeout : " << cfg2.timeout << "s" << endl;


    // ----- 5. Struct dengan Pointer Member -----
        cout << endl << "=== 5. Struct dengan Pointer Member (Node) ===" << endl;

        Node n1 = {10, nullptr};
        Node n2 = {20, nullptr};
        Node n3 = {30, nullptr};

        n1.next = &n2;
        n2.next = &n3;

        cout << "Linked list sederhana:" << endl;
        Node* curr = &n1;
        while (curr != nullptr) {
            cout << "  data = " << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> nullptr" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    double ipk;

    // Constructor (akan dipelajari di OOP)
    Mahasiswa(string nama, int umur, double ipk) {
        // this-> digunakan untuk membedakan parameter dengan member
        this->nama = nama;
        this->umur = umur;
        this->ipk = ipk;
    }

    // Member function yang mencetak this pointer
    void cetakAlamatThis() {
        cout << "Alamat objek (this) : " << this << endl;
    }

    // Method chaining dengan return *this
    Mahasiswa& setNama(string nama) {
        this->nama = nama;
        return *this;
    }

    Mahasiswa& setUmur(int umur) {
        this->umur = umur;
        return *this;
    }

    Mahasiswa& setIpk(double ipk) {
        this->ipk = ipk;
        return *this;
    }

    void tampilkan() {
        cout << "Nama: " << nama << ", Umur: " << umur << ", IPK: " << ipk << endl;
    }

    // Member function const - this pointer menjadi const
    void tampilkanConst() const {
        // this->nama = "xxx"; // ERROR: this const, tidak bisa ubah member
        cout << "[const] Nama: " << nama << endl;
    }
};

int main() {
    cout << "=== This Pointer (Preview) ===\n\n";

    Mahasiswa m1("Budi", 20, 3.85);
    Mahasiswa m2("Sari", 21, 3.90);

    cout << "Alamat m1: " << &m1 << endl;
    m1.cetakAlamatThis();   // harusnya sama dengan &m1

    cout << "\nAlamat m2: " << &m2 << endl;
    m2.cetakAlamatThis();   // harusnya sama dengan &m2

    // Method chaining
    cout << "\nMethod chaining (return *this):\n";
    m1.setNama("Budi Santoso").setUmur(22).setIpk(3.95);
    m1.tampilkan();

    // Membandingkan this dengan alamat objek lain
    cout << "\nMembandingkan this dengan pointer lain:\n";
    Mahasiswa* ptrM1 = &m1;
    if (ptrM1 == &m1) {
        cout << "ptrM1 menunjuk ke m1 (benar)" << endl;
    }

    // this di dalam member function const
    cout << "\nMember function const:\n";
    const Mahasiswa& mConst = m1;
    mConst.tampilkanConst();

    // Catatan: this tidak ada di static member (belajar nanti di OOP)
    cout << "\nCatatan: this pointer hanya ada di dalam member function non-static.\n";
    cout << "Konsep ini akan diperdalam di modul Object-Oriented Programming (Class).\n";

    return 0;
}
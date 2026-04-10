#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


//  FUNGSI DENGAN DAN TANPA noexcept

    // Fungsi biasa (bisa throw)
    int bagiNormal(int a, int b) {
        if (b == 0) throw runtime_error("Pembagi nol");
        return a / b;
    }

    // Fungsi noexcept (dijamin tidak throw)
    int tambahNoexcept(int a, int b) noexcept {
        return a + b;
    }

    int kaliNoexcept(int a, int b) noexcept {
        return a * b;
    }

    // Fungsi noexcept yang TIDAK boleh throw sama sekali
    // (kalau throw, terminate())
    double hitungRasio(int a, int b) noexcept {
        if (b == 0) return 0.0;   // tangani sendiri, jangan throw!
        return (double)a / b;
    }

    // Fungsi swap yang noexcept (pola umum)
    void swapInt(int& a, int& b) noexcept {
        int temp = a;
        a = b;
        b = temp;
    }


//  NOEXCEPT OPERATOR

    // Fungsi untuk demo operator noexcept()
        void fungsiNormal() {
            throw runtime_error("bisa throw");
        }

        void fungsiNoexcept() noexcept {
            // tidak throw
        }


    //  KELAS DENGAN MOVE SEMANTICS
        class Buffer {
        private:
            int*   data_;
            size_t size_;
        public:
            explicit Buffer(size_t n) : data_(new int[n]), size_(n) {
                cout << "  Buffer(" << n << "): konstruktor" << endl;
            }

            // Move constructor - harus noexcept agar STL pakai move, bukan copy!
            Buffer(Buffer&& lain) noexcept
                : data_(lain.data_), size_(lain.size_) {
                lain.data_ = nullptr;
                lain.size_ = 0;
                cout << "  Buffer: move konstruktor (noexcept)" << endl;
            }

            // Move assignment - juga noexcept
            Buffer& operator=(Buffer&& lain) noexcept {
                if (this != &lain) {
                    delete[] data_;
                    data_ = lain.data_;
                    size_ = lain.size_;
                    lain.data_ = nullptr;
                    lain.size_ = 0;
                }
                cout << "  Buffer: move assignment (noexcept)" << endl;
                return *this;
            }

            ~Buffer() {
                delete[] data_;
                // destruktor sudah implisit noexcept di C++11
                cout << "  Buffer: destruktor" << endl;
            }

            size_t size() const noexcept { return size_; }
        };


int main() {

    // ----- 1. Fungsi noexcept Dasar -----
        cout << "=== 1. Fungsi noexcept Dasar ===" << endl;

        int a = 10, b = 3;
        cout << "tambahNoexcept(10, 3) = " << tambahNoexcept(a, b) << endl;
        cout << "kaliNoexcept(10, 3)   = " << kaliNoexcept(a, b)   << endl;
        cout << "hitungRasio(10, 3)    = " << hitungRasio(a, b)     << endl;
        cout << "hitungRasio(10, 0)    = " << hitungRasio(a, 0)     << " (0.0, bukan throw)" << endl;


    // ----- 2. Swap noexcept -----
        cout << endl << "=== 2. Swap noexcept ===" << endl;

        int x = 5, y = 10;
        cout << "Sebelum swap: x=" << x << ", y=" << y << endl;
        swapNoexcept:
        swapInt(x, y);
        cout << "Sesudah swap: x=" << x << ", y=" << y << endl;


    // ----- 3. Operator noexcept() -----
        cout << endl << "=== 3. Operator noexcept() ===" << endl;

        cout << "noexcept(tambahNoexcept(1,2)) = "
            << noexcept(tambahNoexcept(1, 2)) << " (1 = true)"  << endl;
        cout << "noexcept(bagiNormal(1,2))     = "
            << noexcept(bagiNormal(1, 2))     << " (0 = false)" << endl;
        cout << "noexcept(fungsiNoexcept())    = "
            << noexcept(fungsiNoexcept())     << " (1 = true)"  << endl;
        cout << "noexcept(fungsiNormal())      = "
            << noexcept(fungsiNormal())       << " (0 = false)" << endl;


    // ----- 4. Destruktor dan noexcept -----
        cout << endl << "=== 4. Destruktor - Sudah Implisit noexcept ===" << endl;

        cout << "Destruktor di C++11 sudah implisit noexcept." << endl;
        cout << "JANGAN throw dari destruktor!" << endl;
        cout << endl;
        cout << "Berbahaya (JANGAN lakukan):" << endl;
        cout << "  ~MyClass() {" << endl;
        cout << "      throw runtime_error(\"error\");  // CRASH jika ada exception aktif!" << endl;
        cout << "  }" << endl;
        cout << endl;
        cout << "Benar:" << endl;
        cout << "  ~MyClass() noexcept {   // eksplisit, atau biarkan implisit" << endl;
        cout << "      // bersihkan resource tanpa throw" << endl;
        cout << "  }" << endl;


    // ----- 5. Move Constructor noexcept -----
        cout << endl << "=== 5. Move Constructor noexcept ===" << endl;

        cout << "Buat Buffer:" << endl;
        Buffer b1(5);

        cout << "Move Buffer:" << endl;
        Buffer b2(move(b1));

        cout << "b1.size() setelah move = " << b1.size() << " (sudah kosong)" << endl;
        cout << "b2.size()              = " << b2.size() << endl;


    // ----- 6. Ringkasan -----
        cout << endl << "=== 6. Ringkasan noexcept ===" << endl;
        cout << "Kapan wajib pakai noexcept:" << endl;
        cout << "  - Move constructor dan move assignment" << endl;
        cout << "  - Swap function" << endl;
        cout << "  - Destruktor (sudah implisit)" << endl;
        cout << "  - Fungsi yang dipanggil sangat sering (performa)" << endl;
        cout << endl;
        cout << "Kapan tidak pakai noexcept:" << endl;
        cout << "  - Fungsi yang validasi input dan bisa throw" << endl;
        cout << "  - Fungsi yang panggil fungsi lain yang bisa throw" << endl;
        cout << "  - Kalau tidak yakin apakah bisa throw atau tidak" << endl;
        cout << endl;
        cout << "Ingat: noexcept adalah janji. Kalau dilanggar -> terminate()!" << endl;

    return 0;
}

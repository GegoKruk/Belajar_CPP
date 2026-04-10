#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


int main() {

    // ----- 1. Alur Normal: Tidak Ada throw -----
        cout << "=== 1. Alur Normal (Tidak Ada throw) ===" << endl;

        try {
            cout << "try: baris 1" << endl;
            cout << "try: baris 2" << endl;
            cout << "try: baris 3 - selesai tanpa error" << endl;
        }
        catch (const exception& e) {
            cout << "catch: " << e.what() << endl;   // tidak dieksekusi
        }
        cout << "Kode setelah try-catch tetap jalan." << endl;


    // ----- 2. Alur dengan throw -----
        cout << endl << "=== 2. Alur Dengan throw ===" << endl;

        try {
            cout << "try: baris 1" << endl;
            cout << "try: baris 2 - akan throw!" << endl;
            throw runtime_error("Terjadi kesalahan di baris 2");
            cout << "try: baris 3 - TIDAK DIEKSEKUSI" << endl;
        }
        catch (const runtime_error& e) {
            cout << "catch: Exception tertangkap!" << endl;
            cout << "catch: Pesan = " << e.what() << endl;
        }
        cout << "Kode setelah try-catch tetap jalan." << endl;


    // ----- 3. throw Berbagai Tipe -----
        cout << endl << "=== 3. Throw Berbagai Tipe ===" << endl;

        // throw int (tidak disarankan, tapi bisa)
            cout << "throw int:" << endl;
            try {
                throw 42;
            }
            catch (int e) {
                cout << "  Caught int: " << e << endl;
            }

        // throw string (boleh)
            cout << "throw string:" << endl;
            try {
                throw string("Pesan error dari string");
            }
            catch (const string& e) {
                cout << "  Caught string: " << e << endl;
            }

        // throw exception class (BEST PRACTICE)
            cout << "throw runtime_error (best practice):" << endl;
            try {
                throw runtime_error("Error saat runtime");
            }
            catch (const runtime_error& e) {
                cout << "  Caught: " << e.what() << endl;
            }

        // throw invalid_argument
            cout << "throw invalid_argument:" << endl;
            try {
                throw invalid_argument("Argumen tidak valid");
            }
            catch (const invalid_argument& e) {
                cout << "  Caught: " << e.what() << endl;
            }


    // ----- 4. Catch-All (...) -----
        cout << endl << "=== 4. Catch-All (...) ===" << endl;

        try {
            throw 3.14;   // throw double - tidak ada catch spesifik
        }
        catch (int e) {
            cout << "  Caught int (tidak ini)" << endl;
        }
        catch (...) {
            cout << "  Caught oleh catch-all (...) - tipe tidak diketahui" << endl;
        }


    // ----- 5. Kode setelah throw TIDAK Jalan -----
        cout << endl << "=== 5. Kode Setelah throw Tidak Jalan ===" << endl;

        int counter = 0;
        try {
            counter++;
            cout << "  counter = " << counter << " (sebelum throw)" << endl;
            throw runtime_error("test");
            counter++;   // TIDAK JALAN
            cout << "  Baris ini tidak akan muncul." << endl;
        }
        catch (const exception& e) {
            cout << "  Caught: " << e.what() << endl;
            cout << "  counter = " << counter << " (masih " << counter << ", tidak bertambah)" << endl;
        }


    // ----- 6. Try-catch Bisa Nested -----
        cout << endl << "=== 6. Nested Try-Catch ===" << endl;

        try {
            cout << "  Outer try: mulai" << endl;
            try {
                cout << "  Inner try: mulai" << endl;
                throw runtime_error("dari inner try");
                cout << "  Inner try: tidak sampai sini" << endl;
            }
            catch (const runtime_error& e) {
                cout << "  Inner catch: " << e.what() << endl;
                // Bisa throw lagi dari sini ke outer
            }
            cout << "  Outer try: lanjut setelah inner try-catch" << endl;
        }
        catch (const exception& e) {
            cout << "  Outer catch: " << e.what() << endl;
        }


    // ----- 7. Throw di Dalam Function -----
        cout << endl << "=== 7. throw di Dalam Function ===" << endl;

        auto cekPositif = [](int n) {
            if (n < 0) {
                throw invalid_argument("Angka harus positif, dapat: " + to_string(n));
            }
            return n * 2;
        };

        try {
            cout << "  cekPositif(5)  = " << cekPositif(5)  << endl;
            cout << "  cekPositif(-3) ..." << endl;
            cout << "  cekPositif(-3) = " << cekPositif(-3) << endl;  // throw!
        }
        catch (const invalid_argument& e) {
            cout << "  Caught: " << e.what() << endl;
        }

    return 0;
}

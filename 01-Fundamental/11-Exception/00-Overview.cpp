#include <iostream>
#include <stdexcept>
using namespace std;

// Simulasi fungsi yang bisa throw
    int bagi(int a, int b) {
        if (b == 0) {
            throw runtime_error("Pembagi tidak boleh nol!");
        }
        return a / b;
    }

int main() {

        // ----- Demo dasar: tanpa exception -----
        cout << "=== Demo Dasar: Tanpa Exception ===" << endl;
        try {
            cout << "10 / 2 = " << bagi(10, 2) << endl;
            cout << "15 / 3 = " << bagi(15, 3) << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
        cout << "Program tetap lanjut." << endl;


    // ----- Demo dasar: dengan exception -----
        cout << endl << "=== Demo Dasar: Dengan Exception ===" << endl;
        try {
            cout << "10 / 5 = " << bagi(10, 5) << endl;
            cout << "Coba 10 / 0..." << endl;
            cout << "10 / 0 = " << bagi(10, 0) << endl;   // throw!
            cout << "Baris ini TIDAK dieksekusi." << endl;
        }
        catch (const runtime_error& e) {
            cout << "Exception tertangkap: " << e.what() << endl;
        }
        cout << "Program tetap lanjut setelah catch." << endl;


    // ----- Demo stoi (standard library throw) -----
        cout << endl << "=== Demo stoi() throw exception ===" << endl;
        try {
            int n = stoi("123");
            cout << "stoi(\"123\") = " << n << endl;
            int m = stoi("abc");   // throw invalid_argument!
            cout << m << endl;     // tidak dieksekusi
        }
        catch (const invalid_argument& e) {
            cout << "invalid_argument: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "exception: " << e.what() << endl;
        }

    return 0;
}

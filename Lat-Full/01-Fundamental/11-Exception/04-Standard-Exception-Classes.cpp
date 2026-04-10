#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;


// ----- Demonstrasi setiap tipe exception -----
void demoInvalidArgument() {
    cout << "-- invalid_argument --" << endl;
    // Dari library (stoi dengan input tidak valid)
    try {
        int n = stoi("bukan_angka");
        cout << n << endl;
    }
    catch (const invalid_argument& e) {
        cout << "  stoi gagal: " << e.what() << endl;
    }
    // Throw manual
    try {
        int usia = -5;
        if (usia < 0) throw invalid_argument("Usia tidak boleh negatif: " + to_string(usia));
    }
    catch (const invalid_argument& e) {
        cout << "  Manual: " << e.what() << endl;
    }
}

void demoOutOfRange() {
    cout << "-- out_of_range --" << endl;
    // Dari string::at()
        try {
            string s = "hello";
            char c = s.at(10);   // index 10 tidak ada
            cout << c << endl;
        }
        catch (const out_of_range& e) {
            cout << "  string.at(): " << e.what() << endl;
        }
    // Dari vector::at()
        try {
            vector<int> v = {1, 2, 3};
            int x = v.at(5);     // index 5 tidak ada
            cout << x << endl;
        }
        catch (const out_of_range& e) {
            cout << "  vector.at(): " << e.what() << endl;
        }
    // Throw manual
        try {
            int nilai = 150;
            if (nilai > 100) throw out_of_range("Nilai harus 0-100, dapat: " + to_string(nilai));
        }
        catch (const out_of_range& e) {
            cout << "  Manual: " << e.what() << endl;
        }
}

void demoLogicError() {
    cout << "-- logic_error --" << endl;
    try {
        throw logic_error("Kondisi pre/post tidak terpenuhi");
    }
    catch (const logic_error& e) {
        cout << "  " << e.what() << endl;
    }
}

void demoDomainError() {
    cout << "-- domain_error --" << endl;
    try {
        double x = -4.0;
        if (x < 0) throw domain_error("sqrt tidak didefinisikan untuk negatif: " + to_string(x));
    }
    catch (const domain_error& e) {
        cout << "  " << e.what() << endl;
    }
}

void demoRuntimeError() {
    cout << "-- runtime_error --" << endl;
    try {
        throw runtime_error("Koneksi database terputus");
    }
    catch (const runtime_error& e) {
        cout << "  " << e.what() << endl;
    }
}

void demoOverflowError() {
    cout << "-- overflow_error --" << endl;
    try {
        int a = 2000000000;
        int b = 2000000000;
        // C++ tidak otomatis throw saat overflow int
        // Kita perlu deteksi manual
        if (a > 0 && b > 0 && a > (2147483647 - b)) {
            throw overflow_error("Penjumlahan " + to_string(a) + " + " + to_string(b) + " overflow int");
        }
    }
    catch (const overflow_error& e) {
        cout << "  " << e.what() << endl;
    }
}

void demoBadAlloc() {
    cout << "-- bad_alloc --" << endl;
    try {
        // Alokasi yang sangat besar kemungkinan gagal
        // Ukuran disesuaikan agar tidak terlalu lama
        long long ukuranBesar = 1000000000LL * 1000;   // 1 trillion bytes
        char* p = new char[ukuranBesar];
        delete[] p;
    }
    catch (const bad_alloc& e) {
        cout << "  Memori habis: " << e.what() << endl;
    }
}


int main() {

    // ----- 1. Demo Semua Tipe Exception -----
        cout << "=== 1. Demo Semua Tipe Standard Exception ===" << endl << endl;

        demoInvalidArgument();
        cout << endl;
        demoOutOfRange();
        cout << endl;
        demoLogicError();
        cout << endl;
        demoDomainError();
        cout << endl;
        demoRuntimeError();
        cout << endl;
        demoOverflowError();
        cout << endl;
        demoBadAlloc();


    // ----- 2. Catch Parent Class (Polimorfisme) -----
        cout << endl << "=== 2. Catch Parent Class (Polimorfisme) ===" << endl;

        // Tangkap semua logic_error dengan satu catch
        cout << "Tangkap semua logic_error dan turunannya:" << endl;
        auto throwLogic = [](int kode) {
            if (kode == 1) throw invalid_argument("arg tidak valid");
            if (kode == 2) throw out_of_range("di luar range");
            if (kode == 3) throw logic_error("logika umum");
        };

        for (int i = 1; i <= 3; i++) {
            try {
                throwLogic(i);
            }
            catch (const logic_error& e) {
                // Satu catch untuk menangkap semua turunan logic_error
                cout << "  [logic_error] kode " << i << ": " << e.what() << endl;
            }
        }


    // ----- 3. Catch exception Base Class (Semua) -----
        cout << endl << "=== 3. Catch Semua dengan exception Base Class ===" << endl;

        auto throwApa = [](int k) {
            if (k == 1) throw invalid_argument("invalid");
            if (k == 2) throw runtime_error("runtime");
            if (k == 3) throw overflow_error("overflow");
        };

        for (int i = 1; i <= 3; i++) {
            try {
                throwApa(i);
            }
            catch (const exception& e) {
                // Menangkap semua exception standar
                cout << "  [exception] kode " << i << ": " << e.what() << endl;
            }
        }


    // ----- 4. Tabel Ringkasan -----
        cout << endl << "=== 4. Ringkasan Tipe Exception Standar ===" << endl;
        cout << "Tipe                 | Kapan Dipakai" << endl;
        cout << "---------------------+------------------------------------------" << endl;
        cout << "invalid_argument     | Argumen fungsi tidak valid" << endl;
        cout << "out_of_range         | Index/nilai di luar batas" << endl;
        cout << "logic_error          | Pelanggaran logika program" << endl;
        cout << "domain_error         | Domain matematika salah" << endl;
        cout << "length_error         | Panjang melebihi batas" << endl;
        cout << "runtime_error        | Error umum saat runtime" << endl;
        cout << "overflow_error       | Nilai terlalu besar" << endl;
        cout << "underflow_error      | Nilai terlalu kecil" << endl;
        cout << "range_error          | Hasil di luar range" << endl;
        cout << "bad_alloc            | new gagal alokasi memori" << endl;
        cout << "bad_cast             | dynamic_cast gagal" << endl;

    return 0;
}

// ============================================================
//  11-Exception / 02-Multiple-Catch-dan-Urutan.cpp
//  Multiple catch blocks dan aturan urutan dari spesifik ke umum
// ============================================================

/*
    

    

    
*/

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


// Fungsi yang bisa throw berbagai tipe exception
    void prosesData(int kode) {
        switch (kode) {
            case 1:
                throw invalid_argument("Argumen tidak valid (kode 1)");
            case 2:
                throw out_of_range("Nilai di luar jangkauan (kode 2)");
            case 3:
                throw logic_error("Kesalahan logika umum (kode 3)");
            case 4:
                throw runtime_error("Error saat runtime (kode 4)");
            case 5:
                throw overflow_error("Nilai overflow (kode 5)");
            case 6:
                throw 999;   // throw int - akan ditangkap catch-all
            default:
                cout << "  Proses kode " << kode << " berhasil." << endl;
        }
    }


int main() {

    // ----- 1. Multiple Catch Blocks -----
        cout << "=== 1. Multiple Catch Blocks ===" << endl;

        for (int kode = 0; kode <= 6; kode++) {
            cout << "Kode " << kode << ": ";
            try {
                prosesData(kode);
            }
            catch (const invalid_argument& e) {
                cout << "[invalid_argument] " << e.what() << endl;
            }
            catch (const out_of_range& e) {
                cout << "[out_of_range] " << e.what() << endl;
            }
            catch (const logic_error& e) {
                cout << "[logic_error] " << e.what() << endl;
            }
            catch (const overflow_error& e) {
                cout << "[overflow_error] " << e.what() << endl;
            }
            catch (const runtime_error& e) {
                cout << "[runtime_error] " << e.what() << endl;
            }
            catch (const exception& e) {
                cout << "[exception] " << e.what() << endl;
            }
            catch (...) {
                cout << "[catch-all] exception tidak dikenal (int?)" << endl;
            }
        }


    // ----- 2. Demonstrasi Urutan Salah vs Benar -----
        cout << endl << "=== 2. Urutan Salah vs Benar ===" << endl;

        // Urutan SALAH: exception lebih umum di atas
        cout << "Urutan SALAH (exception di atas runtime_error):" << endl;
        try {
            throw runtime_error("Error ini");
        }
        catch (const exception& e) {
            // runtime_error adalah turunan exception, jadi tertangkap di sini!
            cout << "  Tertangkap oleh 'exception' (bukan 'runtime_error')" << endl;
            cout << "  what() = " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            // TIDAK PERNAH TERCAPAI karena catch di atas sudah menangkap
            cout << "  Baris ini tidak pernah dieksekusi!" << endl;
        }

        cout << endl << "Urutan BENAR (runtime_error di atas exception):" << endl;
        try {
            throw runtime_error("Error ini");
        }
        catch (const runtime_error& e) {
            // Tertangkap di sini karena lebih spesifik dan lebih di atas
            cout << "  Tertangkap oleh 'runtime_error' (benar!)" << endl;
            cout << "  what() = " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "  Catch ini untuk exception lain." << endl;
        }


    // ----- 3. invalid_argument vs logic_error -----
        cout << endl << "=== 3. invalid_argument vs logic_error ===" << endl;

        cout << "Throw invalid_argument (child dari logic_error):" << endl;
        try {
            throw invalid_argument("argumen buruk");
        }
        catch (const invalid_argument& e) {
            cout << "  Tertangkap oleh invalid_argument: " << e.what() << endl;
        }
        catch (const logic_error& e) {
            cout << "  Tertangkap oleh logic_error (tidak akan sampai sini)" << endl;
        }

        cout << endl << "Throw logic_error langsung:" << endl;
        try {
            throw logic_error("logika salah");
        }
        catch (const invalid_argument& e) {
            cout << "  Tertangkap oleh invalid_argument (tidak cocok)" << endl;
        }
        catch (const logic_error& e) {
            // logic_error bukan invalid_argument, jadi catch ini yang cocok
            cout << "  Tertangkap oleh logic_error: " << e.what() << endl;
        }


    // ----- 4. Tangkap Satu, Biarkan Lainnya Lewat -----
        cout << endl << "=== 4. Hanya Tangkap Tipe Tertentu ===" << endl;

        auto cobaProses = [](int k) {
            try {
                prosesData(k);
            }
            catch (const logic_error& e) {
                // Hanya tangkap logic_error dan turunannya
                cout << "  [Hanya logic_error] " << e.what() << endl;
            }
            // runtime_error tidak ditangkap di sini -> akan propagate ke atas
        };

        cout << "Kode 1 (invalid_argument - turunan logic_error):" << endl;
        cobaProses(1);
        cout << "Kode 3 (logic_error):" << endl;
        cobaProses(3);


    // ----- 5. Ringkasan Aturan Urutan -----
        cout << endl << "=== 5. Ringkasan Aturan Urutan ===" << endl;
        cout << "Aturan: dari SPESIFIK ke UMUM" << endl;
        cout << endl;
        cout << "  catch (const invalid_argument& e) // child - PALING ATAS" << endl;
        cout << "  catch (const out_of_range& e)     // child" << endl;
        cout << "  catch (const logic_error& e)      // parent dari dua di atas" << endl;
        cout << "  catch (const runtime_error& e)    // sibling dari logic_error" << endl;
        cout << "  catch (const exception& e)        // base class semua" << endl;
        cout << "  catch (...)                       // catch-all - PALING BAWAH" << endl;
        cout << endl;
        cout << "Kalau urutan terbalik, catch yang lebih umum menangkap semuanya" << endl;
        cout << "dan catch yang lebih spesifik tidak pernah tercapai!" << endl;

    return 0;
}

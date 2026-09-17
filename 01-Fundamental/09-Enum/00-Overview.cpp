
#include <iostream>
using namespace std;

// Enum unscoped (classic)
    enum LampuLalin { MERAH, KUNING, HIJAU };

// Enum class (modern C++11)
    enum class Status { AKTIF, NONAKTIF, PENDING };

int main() {

    // ----- Contoh enum classic -----
        cout << "=== Enum Classic ===" << endl;

        LampuLalin lampu = MERAH;

        if      (lampu == MERAH)  cout << "Berhenti!" << endl;
        else if (lampu == KUNING) cout << "Bersiap!"  << endl;
        else if (lampu == HIJAU)  cout << "Jalan!"    << endl;

        // Implicit ke int
            cout << "Nilai int MERAH  = " << MERAH  << endl;
            cout << "Nilai int KUNING = " << KUNING << endl;
            cout << "Nilai int HIJAU  = " << HIJAU  << endl;


    // ----- Contoh enum class -----
        cout << endl << "=== Enum Class (Modern) ===" << endl;

        Status s = Status::AKTIF;

        if      (s == Status::AKTIF)    cout << "Status: Aktif"    << endl;
        else if (s == Status::NONAKTIF) cout << "Status: Nonaktif" << endl;
        else if (s == Status::PENDING)  cout << "Status: Pending"  << endl;

        // Harus cast eksplisit untuk dapat nilai int
            cout << "Nilai int AKTIF = " << static_cast<int>(Status::AKTIF) << endl;

    return 0;
}

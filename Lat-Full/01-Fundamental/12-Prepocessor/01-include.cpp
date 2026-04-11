#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    // ----- Demo berbagai header standar -----
        cout << "=== Demo Library Standar ===" << endl;

        // <string>
            string nama = "C++ Programming";
            cout << "<string>    : \"" << nama << "\", panjang=" << nama.size() << endl;

        // <vector>
            vector<int> data = {5, 3, 8, 1, 9, 2};
            cout << "<vector>    : {";
            for (int i = 0; i < (int)data.size(); i++) {
                cout << data[i];
                if (i < (int)data.size()-1) cout << ",";
            }
            cout << "}" << endl;

        // <algorithm>
            sort(data.begin(), data.end());
            int maks = *max_element(data.begin(), data.end());
            cout << "<algorithm> : sorted={";
            for (int i = 0; i < (int)data.size(); i++) {
                cout << data[i];
                if (i < (int)data.size()-1) cout << ",";
            }
            cout << "}, max=" << maks << endl;

        // <cmath>
            double r = 5.0;
            cout << "<cmath>     : sqrt(25)=" << sqrt(25.0)
                << ", pow(2,10)=" << pow(2, 10)
                << ", pi*r*r=" << fixed << setprecision(2) << acos(-1.0)*r*r << endl;
            cout << defaultfloat;

        // <iomanip>
            cout << "<iomanip>   : " << setw(10) << right << "kanan"
                << " | " << setw(10) << left << "kiri" << endl;


    // ----- Struktur include yang direkomendasikan -----
        cout << endl << "=== Urutan Include yang Direkomendasikan ===" << endl;
        cout << "1. Header milik sendiri: #include \"myfile.h\"" << endl;
        cout << "2. Header library pihak ketiga" << endl;
        cout << "3. Header standar C++: #include <iostream>" << endl;
        cout << "4. Header C: #include <cmath>" << endl;
        cout << "(dari spesifik ke umum, mencegah dependensi tersembunyi)" << endl;


    // ----- Contoh struktur proyek -----
        cout << endl << "=== Contoh Struktur Proyek Multi-File ===" << endl;
        cout << "myproject/" << endl;
        cout << "  include/" << endl;
        cout << "    config.h        <- konstanta global, platform detection" << endl;
        cout << "    mathHelper.h    <- deklarasi fungsi matematika" << endl;
        cout << "    types.h         <- struct, enum, typedef" << endl;
        cout << "  src/" << endl;
        cout << "    main.cpp        <- #include \"config.h\", \"types.h\"" << endl;
        cout << "    mathHelper.cpp  <- #include \"mathHelper.h\", <cmath>" << endl;
        cout << "  CMakeLists.txt" << endl;

    return 0;
}

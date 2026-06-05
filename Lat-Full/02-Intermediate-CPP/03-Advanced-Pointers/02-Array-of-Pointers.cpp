#include <iostream>
using namespace std;

int main() {
    cout << "=== Array of Pointers ===\n\n";

    // 1. Array of pointer ke integer
    int x=1, y=2, z=3, w=4;
    int* arrPtr[4] = {&x, &y, &z, &w};

    cout << "Array of int pointers:\n";
    for(int i=0; i<4; i++)
        cout << "arrPtr[" << i << "] = " << *arrPtr[i] << " (alamat: " << arrPtr[i] << ")\n";

    // 2. Array of C-string (string literal)
    const char* namaHewan[] = {
        "Kucing",
        "Anjing",
        "Burung",
        "Ikan"
    };
    int jumlah = sizeof(namaHewan)/sizeof(namaHewan[0]);

    cout << "\nArray of string pointers:\n";
    for(int i=0; i<jumlah; i++)
        cout << "  " << namaHewan[i] << endl;

    // 3. Jagged array (setiap baris panjangnya berbeda)
    int* jagged[3];
    jagged[0] = new int[2] {1, 2};
    jagged[1] = new int[4] {3, 4, 5, 6};
    jagged[2] = new int[1] {7};

    cout << "\nJagged array (baris dengan panjang berbeda):\n";
    int lengths[] = {2,4,1};
    for(int i=0; i<3; i++) {
        cout << "Baris " << i << ": ";
        for(int j=0; j<lengths[i]; j++)
            cout << jagged[i][j] << " ";
        cout << endl;
    }

    // Bersihkan jagged array
    for(int i=0; i<3; i++) delete[] jagged[i];

    // 4. Array of pointers ke struct (preview)
    struct Point { int x, y; };
    Point p1 = {10,20}, p2 = {30,40};
    Point* ptArr[2] = {&p1, &p2};

    cout << "\nArray of pointers ke struct:\n";
    for(int i=0; i<2; i++)
        cout << "  Point " << i << ": (" << ptArr[i]->x << "," << ptArr[i]->y << ")\n";

    return 0;
}
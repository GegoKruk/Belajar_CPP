
#include <iostream>
using namespace std;

// Contoh penggunaan directive sederhana
#define APP_NAME    "Contoh Program"
#define VERSI_MAJOR 1
#define VERSI_MINOR 0

int main() {

    cout << "=== " << APP_NAME << " ===" << endl;
    cout << "Versi: " << VERSI_MAJOR << "." << VERSI_MINOR << endl;
    cout << endl;

    // Preprocessor sudah mengganti APP_NAME dengan "Contoh Program"
    // dan VERSI_MAJOR dengan 1 sebelum compiler berjalan.
    // Compiler "melihat":
    //   cout << "=== " << "Contoh Program" << " ===" << endl;

    cout << "Informasi kompilasi:" << endl;
    cout << "  File    : " << __FILE__    << endl;
    cout << "  Baris   : " << __LINE__    << endl;
    cout << "  Tanggal : " << __DATE__    << endl;
    cout << "  Waktu   : " << __TIME__    << endl;
    cout << "  C++ Ver : " << __cplusplus << endl;

    return 0;
}

#include <iostream>
using namespace std;

void programPertama(){
    cout << "========== Program Pertama ==========" << endl;
    cout << "Halo semuanya aku adalah program pertama hehe..." << endl;

    // Breakdown bagian-bagian utama program C++
    cout << "\nBreakdown struktur program C++:" << endl;
    cout << "  #include <iostream>   -> Aktifkan fitur I/O" << endl;
    cout << "  using namespace std   -> Shortcut supaya ga perlu std::" << endl;
    cout << "  int main()            -> Entry point program" << endl;
    cout << "  return 0              -> Program selesai normal" << endl;
}

int main(){

    programPertama();

    return 0;
}
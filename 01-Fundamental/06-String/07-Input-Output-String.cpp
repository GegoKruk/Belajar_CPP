
#include <iostream>
#include <string>
using namespace std;


// INPUT & OUTPUT STRING
void demoInputCin() {
    cout << "------------------------------------------------------------" << endl;
    cout << "  Konsep cin >> vs getline()" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  cin >> s:" << endl;
    cout << "  - Berhenti di SPASI, TAB, atau ENTER" << endl;
    cout << "  - Hanya baca SATU KATA" << endl;
    cout << "  - Input \"Gega Ramadhan\" -> s = \"Gega\" (sisanya di buffer)" << endl;
    cout << endl;
    cout << "  getline(cin, s):" << endl;
    cout << "  - Baca sampai ENTER ditekan" << endl;
    cout << "  - SPASI ikut tersimpan" << endl;
    cout << "  - Input \"Gega Ramadhan\" -> s = \"Gega Ramadhan\"" << endl;
    cout << endl;
    cout << "  getline(cin, s, '|'):" << endl;
    cout << "  - Baca sampai karakter '|' (delimiter custom)" << endl;
    cout << "  - Berguna untuk parsing input dengan format tertentu" << endl;
}

void demoMasalahBuffer() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  Masalah Klasik: cin + getline" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << "\n  MASALAH:" << endl;
    cout << "  int umur;" << endl;
    cout << "  string nama;" << endl;
    cout << "  cin >> umur;          // user ketik 20 lalu Enter" << endl;
    cout << "  getline(cin, nama);   // LANGSUNG LEWAT! nama jadi \"\"" << endl;
    cout << endl;
    cout << "  Kenapa? Setelah cin >> umur, buffer masih berisi '\\n'" << endl;
    cout << "  getline() langsung membaca '\\n' itu -> nama = \"\"" << endl;

    cout << "\n  SOLUSI -- tambahkan cin.ignore():" << endl;
    cout << "  int umur;" << endl;
    cout << "  string nama;" << endl;
    cout << "  cin >> umur;" << endl;
    cout << "  cin.ignore();          // buang '\\n' dari buffer" << endl;
    cout << "  getline(cin, nama);    // sekarang baca dengan benar" << endl;

    cout << "\n  Versi lebih aman (buang semua sampai '\\n'):" << endl;
    cout << "  cin.ignore(1000, '\\n');  // buang sampai 1000 karakter atau sampai '\\n'" << endl;

    cout << "\n  POLA YANG BENAR untuk input campuran:" << endl;
    cout << R"(
        int umur;
        string nama;
        string alamat;

        cout << "Umur  : ";
        cin >> umur;
        cin.ignore();            // <- WAJIB setelah cin >>

        cout << "Nama  : ";
        getline(cin, nama);      // baca nama lengkap

        cout << "Alamat: ";
        getline(cin, alamat);    // baca alamat (bisa ada spasi)
    )";
}

void demoOutputFormatting() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  Output String" << endl;
    cout << "------------------------------------------------------------" << endl;

    string nama = "Gega Ramadhan";
    int nilai = 90;
    double ipk = 3.87;

    cout << "\n  Cara output string:" << endl;
    cout << "  cout << s              -> " << nama << endl;
    cout << "  cout << s << endl      -> dengan newline" << endl;
    cout << "  cout << \"Nama: \" << s  -> Nama: " << nama << endl;

    cout << "\n  Gabung dengan angka:" << endl;
    cout << "  Nama  : " << nama  << endl;
    cout << "  Nilai : " << nilai << endl;
    cout << "  IPK   : " << ipk   << endl;

    // String dalam variabel untuk output
    string laporan = "Nama: " + nama + ", IPK: " + to_string(ipk);
    cout << "\n  String gabungan: \"" << laporan << "\"" << endl;
}

void demoContohProgram() {
    cout << "\n------------------------------------------------------------" << endl;
    cout << "  Contoh Kode Program Input Lengkap" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << R"(
        // Contoh program yang benar dengan input campuran:

        #include <iostream>
        #include <string>
        using namespace std;

        int main() {
            int umur;
            string namaDepan;
            string namaLengkap;
            string alamat;

            cout << "Umur         : ";
            cin >> umur;
            cin.ignore();          // WAJIB! buang '\n' sisa

            cout << "Nama depan   : ";
            cin >> namaDepan;
            cin.ignore();          // WAJIB! buang '\n' sisa

            cout << "Nama lengkap : ";
            getline(cin, namaLengkap);  // baca termasuk spasi

            cout << "Alamat       : ";
            getline(cin, alamat);       // baca termasuk spasi

            cout << "\n=== DATA YANG DIINPUT ===" << endl;
            cout << "Umur         : " << umur         << endl;
            cout << "Nama depan   : " << namaDepan    << endl;
            cout << "Nama lengkap : " << namaLengkap  << endl;
            cout << "Alamat       : " << alamat        << endl;

            return 0;
        }
    )";
}


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  V.7 -- Input & Output String" << endl;
    cout << "============================================================" << endl;

    demoInputCin();
    demoMasalahBuffer();
    demoOutputFormatting();
    demoContohProgram();

    cout << "\n============================================================" << endl;
    cout << "  Ringkasan" << endl;
    cout << "============================================================" << endl;
    cout << "  cin >> s            -> baca satu kata (berhenti di spasi)" << endl;
    cout << "  getline(cin, s)     -> baca satu baris penuh" << endl;
    cout << "  getline(cin, s, '|')-> baca sampai delimiter '|'" << endl;
    cout << "  cin.ignore()        -> buang '\\n' sisa (WAJIB sebelum getline setelah cin >>)" << endl;
    cout << "  cout << s           -> tampilkan string" << endl;

    return 0;
}

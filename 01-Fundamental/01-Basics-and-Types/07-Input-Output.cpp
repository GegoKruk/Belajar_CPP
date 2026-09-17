#include <iostream>
#include <string>
#include <iomanip>   // setw, setprecision, fixed, left, right
using namespace std;

void inputOutput() {
    cout << "========== F. Input & Output ==========" << endl;

    // ----- 1. Output Dasar dengan cout -----
        cout << "\n1. Output Dasar dengan cout" << endl;

        cout << "   Halo, ini output teks biasa." << endl;
        cout << "   Angka bulat  : " << 42 << endl;
        cout << "   Angka desimal: " << 3.14159 << endl;
        cout << "   Karakter     : " << 'X' << endl;
        cout << "   Bool         : " << true << " (1=true, 0=false)" << endl;

        // Chaining <<
        string nama = "Gega";
        int    umur = 18;
        cout << "   Nama: " << nama << ", Umur: " << umur << " tahun." << endl;

    // ----- 2. endl vs "\n" -----
        cout << "\n2. endl vs \"\\n\" " << endl;
        cout << "   endl  = newline + flush buffer (lebih lambat)" << endl;
        cout << "   \"\\n\" = hanya newline (lebih cepat)" << endl;
        cout << "   Baris satu\n   Baris dua (pakai \\n)" << endl;
        cout << "   Baris satu" << endl;
        cout << "   Baris dua (pakai endl)" << endl;

    // ----- 3. Format Output dengan <iomanip> -----
        cout << "\n3. Format Output (setw, setprecision, fixed, dll)" << endl;

        // setw - lebar field
        cout << "\n   a) setw(10) - lebar minimum field:" << endl;
        cout << "   |" << setw(10) << "Nama"  << "|" << setw(10) << "Nilai" << "|" << endl;
        cout << "   |" << setw(10) << "Gega"  << "|" << setw(10) << 90      << "|" << endl;
        cout << "   |" << setw(10) << "Budi"  << "|" << setw(10) << 85      << "|" << endl;
        cout << "   |" << setw(10) << "Citra" << "|" << setw(10) << 92      << "|" << endl;

        // left/right alignment
        cout << "\n   b) left / right alignment:" << endl;
        cout << left;
        cout << "   |" << setw(10) << "Gega"  << "|" << setw(8) << 90 << "|" << endl;
        cout << "   |" << setw(10) << "Budi"  << "|" << setw(8) << 85 << "|" << endl;
        cout << right; // kembalikan ke default

        // setfill - karakter pengisi
        cout << "\n   c) setfill - karakter pengisi:" << endl;
        cout << "   " << setfill('0') << setw(6) << 42 << " (nomor urut dengan leading zero)" << endl;
        cout << "   " << setfill('-') << setw(20) << "SELESAI" << endl;
        cout << setfill(' '); // reset ke spasi (default)

        // setprecision & fixed
        cout << "\n   d) setprecision & fixed:" << endl;
        double pi = 3.14159265358979;
        cout << "   Default               : " << pi << endl;
        cout << "   setprecision(3)       : " << setprecision(3) << pi << endl;
        cout << "   fixed+setprecision(5) : " << fixed << setprecision(5) << pi << endl;
        cout << "   scientific            : " << scientific << pi << endl;
        cout << fixed << setprecision(2); // atur presisi untuk contoh berikutnya

        // boolalpha
        cout << "\n   e) boolalpha:" << endl;
        cout << "   Default  : " << true << " / " << false << endl;
        cout << "   boolalpha: " << boolalpha << true << " / " << false << noboolalpha << endl;

    // ----- 4. cerr & clog -----
        cout << "\n4. cerr & clog - Output Error & Log" << endl;
        cerr << "   [cerr] Ini pesan ERROR (tidak di-buffer, langsung tampil)" << endl;
        clog << "   [clog] Ini pesan LOG (di-buffer, lebih efisien)" << endl;
        cout << "   Bedanya: cerr untuk error, clog untuk logging debug" << endl;

    // ----- 5. Input dengan cin -----
        cout << "\n5. Input dengan cin" << endl;
        cout << "   (Demo tanpa interaksi - perlihatkan konsep)" << endl;

        cout << "   Sintaks input angka  : cin >> variabel;" << endl;
        cout << "   Sintaks input string : cin >> namaDepan; (berhenti di spasi!)" << endl;
        cout << "   Chaining             : cin >> a >> b >> c;" << endl;
        cout << "     cin mengabaikan whitespace di awal, tapi berhenti di spasi/enter" << endl;

    // ----- 6. getline() - Input Kalimat -----
        cout << "\n6. getline() - Input Kalimat (termasuk spasi)" << endl;
        cout << "   Sintaks: getline(cin, variabelString);" << endl;
        cout << "      Membaca seluruh baris termasuk spasi" << endl;
        cout << "      Berhenti hanya di Enter (\\n)" << endl;

    // ----- 7. cin.ignore() - Bersihkan Buffer -----
        cout << "\n7. cin.ignore() - Membersihkan Buffer" << endl;
        cout << "   Masalah: Setelah cin >> angka, karakter '\\n' masih tersisa di buffer." << endl;
        cout << "   Kalau langsung getline(), ia akan baca '\\n' itu dan skip!" << endl;
        cout << "\n   SOLUSI - Urutan yang benar:" << endl;
        cout << "     cin >> angka;         // baca angka" << endl;
        cout << "     cin.ignore();         // buang \\n sisa" << endl;
        cout << "     getline(cin, kalimat); // sekarang aman" << endl;
        cout << "\n   Versi lebih aman (buang semua sisa, sampai newline):" << endl;
        cout << "     cin.ignore(numeric_limits<streamsize>::max(), '\\n');" << endl;

    // ----- 8. Contoh Program Input Lengkap -----
        cout << "\n8. Contoh Kode Program Input Lengkap:" << endl;
        cout << R"(
        // --- Contoh Program Input ------------------------------
            #include <iostream>
            #include <string>
            using namespace std;

            int main() {
                int    umur;
                string namaDepan;
                string namaLengkap;

                cout << "Masukkan umur       : ";
                cin >> umur;
                cin.ignore();   // <- wajib sebelum getline!

                cout << "Masukkan nama depan : ";
                cin >> namaDepan;
                cin.ignore();

                cout << "Masukkan nama lengkap: ";
                getline(cin, namaLengkap);   // <- bisa baca spasi

                cout << "\nData yang diinput:" << endl;
                cout << "Umur         : " << umur << endl;
                cout << "Nama depan   : " << namaDepan << endl;
                cout << "Nama lengkap : " << namaLengkap << endl;

                return 0;
            }
        // -------------------------------------------------------
        )";

    // ----- Tips -----
    cout << "\nTips:" << endl;
    cout << "   -> Pakai '\\n' daripada endl di dalam loop (lebih cepat)" << endl;
    cout << "   -> Wajib cin.ignore() sebelum getline() setelah cin >>" << endl;
    cout << "   -> Pakai <iomanip> untuk format tabel/laporan yang rapi" << endl;
    cout << "   -> cerr untuk error, clog untuk debug log" << endl;
}


int main(){

    inputOutput();

    return 0;
}
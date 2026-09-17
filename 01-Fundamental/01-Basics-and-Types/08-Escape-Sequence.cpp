#include <iostream>
#include <string>
using namespace std;

void escapeSequence() {
    cout << "========== H. Escape Sequence ==========" << endl;

    // ----- 1. \n - Newline -----
        cout << "\n1. \\n - Newline (pindah baris)" << endl;
        cout << "   Baris pertama\n   Baris kedua\n   Baris ketiga" << endl;

    // ----- 2. \t - Tab -----
        cout << "\n2. \\t - Horizontal Tab" << endl;
        cout << "   Nama\t\tNilai\tKeterangan" << endl;
        cout << "   Gega\t\t90\tLulus" << endl;
        cout << "   Budi\t\t72\tTidak Lulus" << endl;
        cout << "   Citra\t88\tLulus" << endl;

    // ----- 3. \\ - Backslash Literal -----
        cout << "\n3. \\\\ - Backslash Literal" << endl;
        cout << "   Path file Windows: C:\\Users\\Gega\\Documents\\catatan.txt" << endl;
        cout << "   Path game        : D:\\GAME\\Steam\\Forza Horizon 5\\" << endl;

    // ----- 4. \" - Double Quote -----
        cout << "\n4. \\\" - Double Quote dalam String" << endl;
        cout << "   Ibu berkata: \"Makan dulu, jangan begadang!\"" << endl;
        cout << "   Judul buku  : \"The Art of Clean Code\"" << endl;

    // ----- 5. \' - Single Quote -----
        cout << "\n5. \\' - Single Quote" << endl;
        cout << "   Bahasa Inggris: Hello, good morning y'all!" << endl;
        cout << "   Char literal  : '\\'' adalah karakter kutip tunggal" << endl;

        char kutip = '\'';
        cout << "   Nilai kutip   : " << kutip << endl;

    // ----- 6. \a - Bell/Alert -----
        cout << "\n6. \\a - Bell / Alert (mungkin berbunyi di terminal)" << endl;
        cout << "   \a   <- Ini harusnya ada bunyi (tergantung terminal)" << endl;
        cout << "   (Tidak semua terminal support bunyi)" << endl;

    // ----- 7. \b - Backspace -----
        cout << "\n7. \\b - Backspace (hapus 1 karakter sebelumnya)" << endl;
        cout << "   ABCDE\b\b = ABCDE lalu hapus 2 -> kelihatannya: ABC" << endl;
        cout << "   ABC\b\b = " << "ABCDE\b\b" << " (hasilnya tergantung terminal)" << endl;

    // ----- 8. \r - Carriage Return -----
        cout << "\n8. \\r - Carriage Return (kembali ke awal baris, overwrite)" << endl;
        cout << "   Ini teks awal\r   Ditimpa <-" << endl;
        cout << "   (Hasilnya: baris awal ditimpa oleh teks setelah \\r)" << endl;

    // ----- 9. \0 - Null Character -----
        cout << "\n9. \\0 - Null Character (penting untuk C-style string)" << endl;
        char cStr[] = {'H', 'a', 'l', 'o', '\0'}; // C-style string dengan null terminator
        cout << "   C-style string dengan \\0: " << cStr << endl;
        cout << "   \\0 menandai akhir string di C. Tanpanya, program bisa baca memori sembarangan!" << endl;

    // ----- 10. \x - Hexadecimal Character -----
        cout << "\n10. \\xhh - Karakter dari Kode Hex" << endl;
        cout << "   \\x41 = " << "\x41" << " (hex 41 = decimal 65 = 'A')" << endl;
        cout << "   \\x61 = " << "\x61" << " (hex 61 = decimal 97 = 'a')" << endl;
        cout << "   \\x48\\x61\\x6C\\x6F = " << "\x48\x61\x6C\x6F" << " (Halo)" << endl;

    // ----- 11. Contoh Praktis - Tabel Rapi -----
        cout << "\n11. Contoh Praktis - Membuat Tabel Rapi dengan \\t" << endl;
        cout << "   +------------------------------------------+" << endl;
        cout << "   | No\tNama\t\tNilai\tStatus     |" << endl;
        cout << "   +------------------------------------------+" << endl;
        cout << "   | 1\tGega Ramadhan\t90\tLulus      |" << endl;
        cout << "   | 2\tBudi Santoso\t72\tTidak Lulus|" << endl;
        cout << "   | 3\tCitra Dewi\t88\tLulus          |" << endl;
        cout << "   +------------------------------------------+" << endl;

    // ----- 12. Raw String Literal R"(...)" - C++11 -----
        cout << "\n12. Raw String Literal R\"(...)\" - C++11" << endl;
        cout << "   Tidak perlu escape di dalam raw string!" << endl;

    // Path Windows tanpa raw string (perlu escape)
        string pathBiasa = "C:\\Users\\Gega\\Documents\\catatan.txt";

    // Path Windows dengan raw string (lebih bersih!)
        string pathRaw   = R"(C:\Users\Gega\Documents\catatan.txt)";

        cout << "   Biasa  : " << pathBiasa << endl;
        cout << "   Raw    : " << pathRaw   << endl;

    // Multiline dalam raw string
        string multiline = R"(
        Baris 1
        Baris 2
        Baris 3
        )";
        cout << "\n   Multiline raw string:\n" << multiline << endl;

    // Regex pattern - raw string sangat berguna!
        string regex = R"(\d+\.\d{2})";   // tanpa raw: "\\d+\\.\\d{2}"
        cout << "\n   Regex pattern biasa  : \"\\\\d+\\\\.\\\\d{2}\"" << endl;
        cout << "   Regex pattern raw    : " << regex << " (jauh lebih bersih!)" << endl;

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> \\n dan \\t paling sering dipakai" << endl;
        cout << "   -> Pakai R\"(...)\" untuk path Windows dan regex" << endl;
        cout << "   -> \\0 penting untuk C-style string, biasanya otomatis di string C++" << endl;
        cout << "   -> \\a jarang berguna, \\r pakai hati-hati (overwrite)" << endl;
}


int main(){

    escapeSequence();

    return 0;
}
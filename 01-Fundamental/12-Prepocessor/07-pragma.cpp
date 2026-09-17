#include <iostream>
#include <string>
using namespace std;


//  DEMO #pragma pack
    // Struct TANPA pack (default padding dari compiler)
        struct StrukturNormal {
            char   c;    // 1 byte
            int    i;    // 4 byte (tapi ada 3 byte padding sebelumnya!)
            double d;    // 8 byte
            char   c2;   // 1 byte (+ 7 byte padding setelahnya!)
        };

    // Struct DENGAN pack(1) - tidak ada padding
        #pragma pack(push, 1)
        struct StrukturPadat {
            char   c;    // 1 byte
            int    i;    // 4 byte (langsung setelah c, tanpa padding)
            double d;    // 8 byte
            char   c2;   // 1 byte
        };
        #pragma pack(pop)   // kembalikan ke default setelah selesai

    // Struct untuk komunikasi jaringan (byte presisi penting!)
        #pragma pack(push, 1)
        struct PaketJaringan {
            unsigned char  tipe;       // 1 byte: tipe paket
            unsigned short panjang;    // 2 byte: panjang data
            unsigned int   checksum;   // 4 byte: checksum
            unsigned char  data[10];   // 10 byte: payload
        };                             // Total: 1+2+4+10 = 17 byte (tanpa pack mungkin lebih besar)
        #pragma pack(pop)


// ============================================================
//  DEMO #pragma message (uncomment untuk melihat saat compile)
// ============================================================
// #pragma message("Demo: file 07-pragma.cpp sedang dikompilasi")
// #pragma message("PERHATIAN: #pragma message tampil saat compile, bukan runtime!")


int main() {

    // ----- 1. #pragma pack: Perbandingan Ukuran -----
        cout << "=== 1. #pragma pack: Ukuran Struct ===" << endl;

        cout << "StrukturNormal (dengan padding default):" << endl;
        cout << "  sizeof(StrukturNormal) = " << sizeof(StrukturNormal) << " byte" << endl;
        cout << "  Ukuran logis: char(1) + int(4) + double(8) + char(1) = 14 byte" << endl;
        cout << "  Ukuran nyata lebih besar karena padding alignment!" << endl;

        cout << endl << "StrukturPadat (pack(1), tanpa padding):" << endl;
        cout << "  sizeof(StrukturPadat) = " << sizeof(StrukturPadat) << " byte" << endl;
        cout << "  Ukuran logis: 1+4+8+1 = 14 byte, dan sizeof juga " << sizeof(StrukturPadat) << endl;

        cout << endl << "Hemat: " << sizeof(StrukturNormal) - sizeof(StrukturPadat) << " byte per struct" << endl;


    // ----- 2. Padding Dijelaskan -----
        cout << endl << "=== 2. Mengapa Ada Padding? ===" << endl;

        cout << "CPU modern membaca memori lebih cepat jika data" << endl;
        cout << "berada di alamat yang 'aligned' (kelipatan ukuran tipe)." << endl;
        cout << endl;
        cout << "StrukturNormal layout di memori (konseptual):" << endl;
        cout << "  [c:1byte][pad:3byte][i:4byte][d:8byte][c2:1byte][pad:7byte]" << endl;
        cout << "  Total = " << sizeof(StrukturNormal) << " byte" << endl;

        cout << endl << "StrukturPadat layout di memori:" << endl;
        cout << "  [c:1byte][i:4byte][d:8byte][c2:1byte]" << endl;
        cout << "  Total = " << sizeof(StrukturPadat) << " byte" << endl;
        cout << endl;
        cout << "Peringatan: pack(1) bisa lebih lambat di CPU karena" << endl;
        cout << "unaligned access. Pakai hanya saat benar-benar dibutuhkan!" << endl;


    // ----- 3. PaketJaringan - Use Case Nyata -----
        cout << endl << "=== 3. Use Case: Paket Jaringan ===" << endl;

        cout << "sizeof(PaketJaringan) = " << sizeof(PaketJaringan) << " byte" << endl;
        cout << "Ukuran logis: 1+2+4+10 = 17 byte" << endl;
        cout << "(Tanpa pack(1), bisa jadi 20+ byte karena padding)" << endl;
        cout << endl;
        cout << "Penting untuk protokol jaringan:" << endl;
        cout << "  Pengirim dan penerima harus sepakat persis ukuran byte." << endl;
        cout << "  Tanpa pack(1), layout bisa berbeda di compiler berbeda!" << endl;

        // Isi contoh paket
        PaketJaringan paket;
        paket.tipe    = 0x01;
        paket.panjang = 10;
        paket.checksum = 0xDEADBEEF;
        for (int i = 0; i < 10; i++) paket.data[i] = (unsigned char)i;

        cout << endl << "Contoh paket:" << endl;
        cout << "  tipe      = " << (int)paket.tipe     << endl;
        cout << "  panjang   = " << paket.panjang        << endl;
        cout << "  checksum  = " << paket.checksum       << " (hex = 0xDEADBEEF)" << endl;


    // ----- 4. #pragma warning / GCC diagnostic -----
        cout << endl << "=== 4. #pragma warning / GCC diagnostic ===" << endl;

        cout << "Kontrol warning compiler:" << endl;
        cout << endl;
        cout << "MSVC (Windows):" << endl;
        cout << "  #pragma warning(push)" << endl;
        cout << "  #pragma warning(disable: 4996)  // matikan warning deprecated" << endl;
        cout << "  // ... pakai fungsi deprecated dari library lain ..." << endl;
        cout << "  #pragma warning(pop)             // restore warning" << endl;
        cout << endl;
        cout << "GCC / Clang (Linux/Mac):" << endl;
        cout << "  #pragma GCC diagnostic push" << endl;
        cout << "  #pragma GCC diagnostic ignored \"-Wunused-parameter\"" << endl;
        cout << "  // ... fungsi dengan parameter tidak terpakai ..." << endl;
        cout << "  #pragma GCC diagnostic pop" << endl;
        cout << endl;
        cout << "Kenapa pakai push/pop?" << endl;
        cout << "  Agar warning hanya dimatikan untuk bagian tertentu," << endl;
        cout << "  tidak menyebar ke seluruh file." << endl;


    // ----- 5. #pragma message -----
        cout << endl << "=== 5. #pragma message ===" << endl;

        cout << "#pragma message tampil saat KOMPILASI, bukan saat program jalan." << endl;
        cout << "Berguna untuk: konfirmasi macro aktif, reminder untuk tim." << endl;
        cout << endl;
        cout << "Contoh:" << endl;
        cout << "  #pragma message(\"Kompilasi berhasil!\")" << endl;
        cout << "  #define DEBUG" << endl;
        cout << "  #pragma message(\"Mode DEBUG aktif\")" << endl;
        cout << endl;
        cout << "Output saat compile:" << endl;
        cout << "  main.cpp: note: Kompilasi berhasil!" << endl;
        cout << "  main.cpp: note: Mode DEBUG aktif" << endl;


    // ----- 6. Ringkasan pragma -----
        cout << endl << "=== 6. Ringkasan #pragma ===" << endl;
        cout << "Pragma               | Fungsi" << endl;
        cout << "---------------------+--------------------------------------" << endl;
        cout << "#pragma once         | Cegah multiple inclusion header" << endl;
        cout << "#pragma pack(n)      | Atur padding/alignment struct" << endl;
        cout << "#pragma pack(push,n) | Simpan lalu atur alignment" << endl;
        cout << "#pragma pack(pop)    | Kembalikan alignment sebelumnya" << endl;
        cout << "#pragma warning      | Kontrol warning (MSVC)" << endl;
        cout << "#pragma GCC diagnostic | Kontrol warning (GCC/Clang)" << endl;
        cout << "#pragma comment(lib) | Link library otomatis (MSVC)" << endl;
        cout << "#pragma message      | Tampilkan pesan saat compile" << endl;

    return 0;
}

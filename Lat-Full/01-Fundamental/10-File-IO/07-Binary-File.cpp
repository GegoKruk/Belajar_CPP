#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Mahasiswa {
    char   nama[30];   // fixed-size agar mudah disimpan binary
    int    umur;
    double ipk;
};

int main() {

    // ----- 1. Tulis dan Baca Satu Integer -----
        cout << "=== 1. Tulis/Baca Satu Integer (Binary) ===" << endl;

        int nilaiTulis = 12345;

        ofstream fw1("07_int.bin", ios::binary);
        fw1.write(reinterpret_cast<char*>(&nilaiTulis), sizeof(nilaiTulis));
        fw1.close();
        cout << "Tulis: " << nilaiTulis << " ke file binary" << endl;

        int nilaiBaca = 0;
        ifstream fr1("07_int.bin", ios::binary);
        fr1.read(reinterpret_cast<char*>(&nilaiBaca), sizeof(nilaiBaca));
        fr1.close();
        cout << "Baca : " << nilaiBaca << " dari file binary" << endl;
        cout << "Sama? " << (nilaiTulis == nilaiBaca ? "Ya" : "Tidak") << endl;


    // ----- 2. Tulis dan Baca Array Integer -----
        cout << endl << "=== 2. Array Integer (Binary) ===" << endl;

        int data[] = {10, 20, 30, 40, 50};
        int n = sizeof(data) / sizeof(data[0]);

        ofstream fw2("07_array.bin", ios::binary);
        fw2.write(reinterpret_cast<char*>(data), sizeof(data));   // tulis semua sekaligus
        fw2.close();
        cout << "Ukuran file binary: " << sizeof(data) << " byte (5 int x 4 byte)" << endl;

        int hasilBaca[5] = {0};
        ifstream fr2("07_array.bin", ios::binary);
        fr2.read(reinterpret_cast<char*>(hasilBaca), sizeof(hasilBaca));
        fr2.close();

        cout << "Data terbaca: ";
        for (int i = 0; i < n; i++) cout << hasilBaca[i] << " ";
        cout << endl;


    // ----- 3. Tulis dan Baca Double -----
        cout << endl << "=== 3. Double (Binary) ===" << endl;

        double angka = 3.141592653589793;

        ofstream fw3("07_double.bin", ios::binary);
        fw3.write(reinterpret_cast<const char*>(&angka), sizeof(angka));
        fw3.close();

        double hasilD = 0.0;
        ifstream fr3("07_double.bin", ios::binary);
        fr3.read(reinterpret_cast<char*>(&hasilD), sizeof(hasilD));
        fr3.close();

        cout << "Tulis : " << angka   << endl;
        cout << "Baca  : " << hasilD  << endl;


    // ----- 4. Tulis dan Baca Struct -----
        cout << endl << "=== 4. Struct Binary (Fixed-Size Record) ===" << endl;

        Mahasiswa mhs1;
        strncpy(mhs1.nama, "Budi Santoso", sizeof(mhs1.nama) - 1);
        mhs1.umur = 20;
        mhs1.ipk  = 3.85;

        Mahasiswa mhs2;
        strncpy(mhs2.nama, "Sari Dewi", sizeof(mhs2.nama) - 1);
        mhs2.umur = 21;
        mhs2.ipk  = 3.90;

        // Tulis dua struct
        ofstream fw4("07_struct.bin", ios::binary);
        fw4.write(reinterpret_cast<char*>(&mhs1), sizeof(Mahasiswa));
        fw4.write(reinterpret_cast<char*>(&mhs2), sizeof(Mahasiswa));
        fw4.close();
        cout << "Dua struct ditulis. Ukuran file: " << 2 * sizeof(Mahasiswa) << " byte" << endl;

        // Baca kembali
        ifstream fr4("07_struct.bin", ios::binary);
        Mahasiswa baca1, baca2;
        fr4.read(reinterpret_cast<char*>(&baca1), sizeof(Mahasiswa));
        fr4.read(reinterpret_cast<char*>(&baca2), sizeof(Mahasiswa));
        fr4.close();

        cout << "Record 1: " << baca1.nama << " | umur=" << baca1.umur << " | ipk=" << baca1.ipk << endl;
        cout << "Record 2: " << baca2.nama << " | umur=" << baca2.umur << " | ipk=" << baca2.ipk << endl;


    // ----- 5. Akses Record Tertentu (Random Access) -----
        cout << endl << "=== 5. Random Access - Baca Record ke-N ===" << endl;

        // Buat file berisi 5 struct
        Mahasiswa kelas[5] = {
            {"Andi",  19, 3.70},
            {"Bela",  20, 3.80},
            {"Cici",  21, 3.90},
            {"Dodi",  22, 3.60},
            {"Eka",   20, 3.95}
        };

        ofstream fw5("07_kelas.bin", ios::binary);
        fw5.write(reinterpret_cast<char*>(kelas), sizeof(kelas));
        fw5.close();
        cout << "5 record ditulis ke file binary." << endl;

        // Baca langsung record ke-3 (index 2)
        ifstream fr5("07_kelas.bin", ios::binary);
        int indexCari = 2;
        fr5.seekg(indexCari * sizeof(Mahasiswa));   // loncat ke posisi record
        Mahasiswa hasilCari;
        fr5.read(reinterpret_cast<char*>(&hasilCari), sizeof(Mahasiswa));
        fr5.close();

        cout << "Record index " << indexCari << ": "
            << hasilCari.nama << " | " << hasilCari.umur << " | " << hasilCari.ipk << endl;


    // ----- 6. Teks vs Binary: Perbandingan Ukuran -----
        cout << endl << "=== 6. Perbandingan Ukuran Teks vs Binary ===" << endl;

        int angkaBesar[] = {100000, 200000, 300000, 400000, 500000};

        // Simpan sebagai teks
        ofstream fteks("07_teks.txt");
        for (int x : angkaBesar) fteks << x << "\n";
        fteks.close();

        // Simpan sebagai binary
        ofstream fbin("07_biner.bin", ios::binary);
        fbin.write(reinterpret_cast<char*>(angkaBesar), sizeof(angkaBesar));
        fbin.close();

        // Hitung ukuran
        ifstream cekTeks("07_teks.txt", ios::ate);
        streamsize ukTeks = cekTeks.tellg(); cekTeks.close();

        ifstream cekBin("07_biner.bin", ios::ate);
        streamsize ukBin = cekBin.tellg(); cekBin.close();

        cout << "5 angka besar:" << endl;
        cout << "  Ukuran file TEKS  : " << ukTeks  << " byte" << endl;
        cout << "  Ukuran file BINARY: " << ukBin   << " byte" << endl;
        cout << "  Binary lebih hemat " << ukTeks - ukBin << " byte." << endl;

    // Cleanup
        remove("07_int.bin");
        remove("07_array.bin");
        remove("07_double.bin");
        remove("07_struct.bin");
        remove("07_kelas.bin");
        remove("07_teks.txt");
        remove("07_biner.bin");
        cout << endl << "File demo dihapus." << endl;

    return 0;
}

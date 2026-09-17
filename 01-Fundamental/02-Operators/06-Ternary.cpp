#include <iostream>
using namespace std;

void operatorTernary() {
    cout << "========== N. Operator Ternary ==========" << endl;

    // ----- 1. Bentuk Dasar -----
        cout << "\n1. Bentuk Dasar - Bandingkan dengan if-else" << endl;

        int angka = 7;

        // Versi if-else
            string label1;
            if (angka > 0) {
                label1 = "positif";
            } else {
                label1 = "non-positif";
            }

        // Versi ternary - sama, tapi lebih ringkas
            string label2 = (angka > 0) ? "positif" : "non-positif";

            cout << "   angka = " << angka << endl;
            cout << "   Versi if-else  : " << label1 << endl;
            cout << "   Versi ternary  : " << label2 << endl;
            cout << "   -> Keduanya menghasilkan output yang SAMA." << endl;

    // ----- 2. Ternary Langsung di dalam Ekspresi -----
        cout << "\n2. Ternary Langsung sebagai Nilai" << endl;

        int nilai = 83;
        // Langsung di dalam cout
            cout << "   nilai = " << nilai << endl;
            cout << "   Status: " << (nilai >= 75 ? "LULUS" : "TIDAK LULUS") << endl;

        // Inisialisasi const dari kondisi
            const int batas  = 100;
            const string ket = (nilai >= batas) ? "Sempurna" : "Belum sempurna";
            cout << "   Keterangan: " << ket << endl;

        // Argumen langsung ke fungsi (cout sebagai contoh)
            int stok = 0;
            cout << "   Stok: " << (stok > 0 ? "Tersedia" : "Habis") << endl;

    // ----- 3. Ternary dengan Angka -----
        cout << "\n3. Ternary Menghasilkan Angka" << endl;

        int a = 8, b = 12;
        int maks = (a > b) ? a : b;   // nilai terbesar
        int mins = (a < b) ? a : b;   // nilai terkecil

        cout << "   a=" << a << ", b=" << b << endl;
        cout << "   Maksimum: " << maks << endl;
        cout << "   Minimum : " << mins << endl;

        // Hitung absolut tanpa abs()
            int negatif = -17;
            int absolut = (negatif >= 0) ? negatif : -negatif;
            cout << "   |" << negatif << "| = " << absolut << endl;

    // ----- 4. Nested Ternary - Bersarang -----
        cout << "\n4. Nested Ternary - Hati-Hati!" << endl;

        int score = 78;
        cout << "   score = " << score << endl;

        // Nested ternary - legal tapi perlu hati-hati
            string grade =
                (score >= 85) ? "A" :
                (score >= 75) ? "B" :
                (score >= 65) ? "C" :
                (score >= 55) ? "D" : "E";

            cout << "   Grade: " << grade << endl;

        // Bandingkan dengan if-else yang lebih jelas untuk kasus ini:
            cout << "\n   Versi if-else (lebih readable untuk nested):" << endl;
            cout << R"(
                string grade;
                if (score >= 85) {
                    grade = "A";
                } else if (score >= 75) {
                    grade = "B";
                } else if (score >= 65) {
                    grade = "C";
                } else if (score >= 55) {
                    grade = "D";
                } else {
                    grade = "E";
                } 
            )";

    // ----- 5. Kapan Pakai vs Hindari -----
        cout << "5. Kapan PAKAI vs HINDARI" << endl;

        cout << "\n  PAKAI - Kondisi sederhana, 1 baris masih terbaca:" << endl;
        int umur = 17;
        cout << "      Kategori: " << (umur >= 18 ? "Dewasa" : "Remaja") << endl;

        bool sudahLogin = false;
        cout << "      Status  : " << (sudahLogin ? "Selamat datang!" : "Silakan login dulu.") << endl;

        double suhu = 36.8;
        cout << "      Demam?  : " << (suhu > 37.5 ? "Ya" : "Tidak") << " (suhu " << suhu << "°C)" << endl;

        cout << "\n  HINDARI - Nested berlebihan, susah dibaca:" << endl;
        cout << "      Ini terlalu panjang untuk ternary:" << endl;
        cout << "      (a>b) ? (a>c) ? \"a terbesar\" : \"c terbesar\" : (b>c) ? \"b terbesar\" : \"c terbesar\"" << endl;
        cout << "      -> Lebih baik pakai if-else untuk kasus seperti ini." << endl;

    // ----- 6. Contoh Praktis -----
        cout << "\n6. Contoh Praktis" << endl;

        // a. Genap/Ganjil
            cout << "\n   a. Genap atau Ganjil:" << endl;
            for (int i = 1; i <= 6; i++) {
                cout << "      " << i << " adalah " << (i % 2 == 0 ? "genap" : "ganjil") << endl;
            }

        // b. Label harga diskon
            cout << "\n   b. Label Diskon Berdasar Jumlah Beli:" << endl;
            int jumlahBeli = 5;
            double hargaSatuan = 50000.0;
            double diskon = (jumlahBeli >= 10) ? 0.20 :
                            (jumlahBeli >= 5)  ? 0.10 : 0.0;
            double total  = jumlahBeli * hargaSatuan * (1 - diskon);

            cout << "      Beli " << jumlahBeli << " item @ Rp " << hargaSatuan << endl;
            cout << "      Diskon : " << (diskon * 100) << "%" << endl;
            cout << "      Total  : Rp " << total << endl;

        // c. Hari kerja atau libur
            cout << "\n   c. Hari Kerja atau Akhir Pekan:" << endl;
            for (int hari = 1; hari <= 7; hari++) {
                string namaHari;
                switch (hari) {
                    case 1: namaHari = "Senin";  break;
                    case 2: namaHari = "Selasa"; break;
                    case 3: namaHari = "Rabu";   break;
                    case 4: namaHari = "Kamis";  break;
                    case 5: namaHari = "Jumat";  break;
                    case 6: namaHari = "Sabtu";  break;
                    case 7: namaHari = "Minggu"; break;
                }
                string tipe = (hari <= 5) ? "Kerja" : "Libur";
                cout << "      " << namaHari << " -> " << tipe << endl;
            }

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Ternary untuk NILAI sederhana, if-else untuk LOGIKA kompleks" << endl;
        cout << "   -> Nested ternary maksimal 2-3 level, lebih dari itu -> if-else" << endl;
        cout << "   -> Selalu beri kurung pada kondisi: (x > 0) ? ... : ..." << endl;
        cout << "   -> Ternary bisa dipakai di dalam cout, argumen fungsi, init const" << endl;
}

int main(){

    operatorTernary();

    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <utility>   // untuk pair
using namespace std;



// SOLUSI 1 -- REFERENCE PARAMETER

    // Hitung luas dan keliling lingkaran sekaligus
        void hitungLingkaran(double r, double &outLuas, double &outKeliling) {
            const double PI = 3.14159265358979;
            outLuas     = PI * r * r;
            outKeliling = 2 * PI * r;
        }

        // Cari min, maks, dan rata-rata dari array
        void hitungStatistik(int arr[], int n,
                            int &outMin, int &outMaks, double &outRataRata) {
            if (n <= 0) return;
            outMin     = arr[0];
            outMaks    = arr[0];
            int total  = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] < outMin) outMin  = arr[i];
                if (arr[i] > outMaks) outMaks = arr[i];
                total += arr[i];
            }
            outRataRata = (double)total / n;
        }

    // Bagi dan sisa bagi sekaligus
        void bagi(int a, int b, int &outHasil, int &outSisa) {
            if (b == 0) {
                outHasil = 0;
                outSisa  = 0;
                return;
            }
            outHasil = a / b;
            outSisa  = a % b;
        }

    // Konversi detik ke jam, menit, detik
        void konversiWaktu(int totalDetik,
                        int &outJam, int &outMenit, int &outDetik) {
            outJam   = totalDetik / 3600;
            outMenit = (totalDetik % 3600) / 60;
            outDetik = totalDetik % 60;
        }

    // Harga sebelum dan sesudah diskon + pajak
        void hitungHarga(double hargaAwal, double diskonPersen, double pajakPersen,
                        double &outSetelahDiskon, double &outSetelahPajak) {
            outSetelahDiskon = hargaAwal * (1.0 - diskonPersen / 100.0);
            outSetelahPajak  = outSetelahDiskon * (1.0 + pajakPersen / 100.0);
        }


// SOLUSI 2 -- RETURN pair
    // Return min dan maks sebagai pair
        pair<int, int> cariMinMaks(int arr[], int n) {
            int minVal = arr[0];
            int maxVal = arr[0];
            for (int i = 1; i < n; i++) {
                if (arr[i] < minVal) minVal = arr[i];
                if (arr[i] > maxVal) maxVal = arr[i];
            }
            return {minVal, maxVal};
        }

    // Return hasil bagi dan sisa sebagai pair
        pair<int, int> bagiPair(int a, int b) {
            return {a / b, a % b};
        }

    // Return string nama dan usia dari kode (contoh sederhana)
        pair<string, int> parseData(string kode) {
            // Format: "NAMA-USIA" contoh: "Gega-20"
            int dash = (int)kode.find('-');
            string nama = kode.substr(0, dash);
            int usia    = stoi(kode.substr(dash + 1));
            return {nama, usia};
        }


// MAIN
int main() {
    cout << "============================================================" << endl;
    cout << "  T.8 -- Multiple Return via Reference" << endl;
    cout << "============================================================" << endl;

    cout << "\n  C++ hanya bisa return 1 nilai dari function." << endl;
    cout << "  Solusi: gunakan reference parameter sebagai wadah output." << endl;

    // ---- Solusi 1: Reference Parameter ----
        cout << "\n[ 1. Solusi 1 -- Reference Parameter sebagai Output ]" << endl;

        cout << "\n  hitungLingkaran(r=7):" << endl;
        double luas, keliling;
        hitungLingkaran(7.0, luas, keliling);
        cout << fixed << setprecision(4);
        cout << "  Luas     = " << luas     << endl;
        cout << "  Keliling = " << keliling << endl;
        cout << defaultfloat;

        cout << "\n  hitungStatistik():" << endl;
        int data[] = {85, 42, 97, 13, 76, 55, 88, 30};
        int ukuran = 8;
        cout << "  Data: ";
        for (int i = 0; i < ukuran; i++) cout << data[i] << " ";
        cout << endl;
        int minVal, maxVal;
        double rata;
        hitungStatistik(data, ukuran, minVal, maxVal, rata);
        cout << fixed << setprecision(2);
        cout << "  Min      = " << minVal << endl;
        cout << "  Maks     = " << maxVal << endl;
        cout << "  Rata2    = " << rata   << endl;
        cout << defaultfloat;

        cout << "\n  bagi(17, 5):" << endl;
        int hasil, sisa;
        bagi(17, 5, hasil, sisa);
        cout << "  17 / 5 = " << hasil << " sisa " << sisa << endl;

        cout << "\n  konversiWaktu(3725 detik):" << endl;
        int jam, menit, detik;
        konversiWaktu(3725, jam, menit, detik);
        cout << "  3725 detik = " << jam << " jam " << menit << " menit " << detik << " detik" << endl;

        cout << "\n  hitungHarga(500000, diskon=20%, pajak=11%):" << endl;
        double setelahDiskon, setelahPajak;
        hitungHarga(500000, 20, 11, setelahDiskon, setelahPajak);
        cout << fixed << setprecision(0);
        cout << "  Setelah diskon 20% : Rp " << setelahDiskon << endl;
        cout << "  Setelah pajak  11% : Rp " << setelahPajak  << endl;
        cout << defaultfloat;

    // ---- Solusi 2: pair ----
        cout << "\n[ 2. Solusi 2 -- Return pair<T1,T2> ]" << endl;

        cout << "\n  cariMinMaks():" << endl;
        pair<int,int> minmaks = cariMinMaks(data, ukuran);
        cout << "  Min = " << minmaks.first << ", Maks = " << minmaks.second << endl;

        cout << "\n  bagiPair(17, 5):" << endl;
        pair<int,int> bp = bagiPair(17, 5);
        cout << "  Hasil = " << bp.first << ", Sisa = " << bp.second << endl;

        cout << "\n  parseData():" << endl;
        pair<string,int> pd = parseData("Gega-20");
        cout << "  Nama = " << pd.first << ", Usia = " << pd.second << endl;

    // ---- Kapan Pakai Mana ----
        cout << "\n[ 3. Kapan Pakai Mana? ]" << endl;
        cout << "\n  Reference parameter: 3+ nilai output, lebih eksplisit" << endl;
        cout << "  pair             : tepat 2 nilai, lebih ringkas" << endl;
        cout << "\n  Konvensi reference parameter:" << endl;
        cout << "  void f(input1, input2, &outA, &outB)" << endl;
        cout << "         [INPUT      ]  [OUTPUT      ]" << endl;
        cout << "  Parameter output biasanya di KANAN, nama pakai prefix out..." << endl;

    return 0;
}

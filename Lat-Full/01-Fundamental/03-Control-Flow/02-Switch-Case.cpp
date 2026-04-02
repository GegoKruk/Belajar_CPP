#include <iostream>
#include <string>
using namespace std;

void switchCase() {
    cout << "\n==================== Percabangan - Switch Case ====================" << endl;

    // ── 1. Sintaks Dasar & Peran break ────────────────────────
        cout << "\n1. Switch Dasar - Menu Restoran" << endl;
        {
            int pilihan = 3;
            cout << "   Pilihan menu: " << pilihan << endl;

            switch (pilihan) {
                case 1:
                    cout << "   Kamu memilih: Nasi Goreng Ayam  - Rp 25.000" << endl;
                    break;
                case 2:
                    cout << "   Kamu memilih: Bebek Goreng       - Rp 35.000" << endl;
                    break;
                case 3:
                    cout << "   Kamu memilih: Bakmi Jawa         - Rp 20.000" << endl;
                    break;
                case 4:
                    cout << "   Kamu memilih: Sate Ayam Madura   - Rp 30.000" << endl;
                    break;
                case 5:
                    cout << "   Kamu memilih: Capcay Kuah        - Rp 18.000" << endl;
                    break;
                default:
                    cout << "   Pilihan tidak valid! Silakan pilih 1-5." << endl;
                    break;  // opsional di default, tapi bagus untuk konsistensi
            }
        }

    // ── 2. Fall-Through - Tidak Sengaja (Bahaya) ─────────────
        cout << "\n2. Fall-Through TIDAK Sengaja (Contoh Bahaya)" << endl;
        {
            int x = 1;
            cout << "   x = " << x << ", tanpa break:" << endl;
            cout << "   Output: ";

            switch (x) {
                case 1:
                    cout << "satu ";   // <- TIDAK ADA BREAK! Fall-through ke bawah
                case 2:
                    cout << "dua ";    // <- ikut dieksekusi walaupun x != 2!
                case 3:
                    cout << "tiga ";   // <- ini juga!
                    break;             // baru berhenti di sini
                case 4:
                    cout << "empat ";
                    break;
            }
            cout << endl;
            cout << "   -> Walaupun x=1, output 'satu dua tiga' karena tidak ada break!" << endl;
            cout << "   -> Selalu tambahkan break kecuali fall-through memang disengaja." << endl;
        }

    // ── 3. Fall-Through SENGAJA (Berguna) ─────────────────────
        cout << "\n3. Fall-Through SENGAJA - Beberapa Case, Aksi Sama" << endl;
        {
            int hari = 6;  // 1=Senin, ..., 7=Minggu
            cout << "   Hari ke-" << hari << endl;

            switch (hari) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    // Senin-Jumat: semua masuk sini
                    cout << "   Hari Kerja - Semangat berangkat!" << endl;
                    break;
                case 6:
                case 7:
                    // Sabtu-Minggu: masuk sini
                    cout << "   Akhir Pekan - Saatnya istirahat!" << endl;
                    break;
                default:
                    cout << "   Hari tidak valid (harus 1-7)" << endl;
                    break;
            }
            cout << "   -> Fall-through sengaja: case 1,2,3,4,5 semua menuju kode yang sama." << endl;
        }

    // ── 4. Switch dengan char ──────────────────────────────────
        cout << "\n4. Switch dengan char" << endl;
        {
            char grade = 'B';
            cout << "   Grade: " << grade << endl;

            switch (grade) {
                case 'A':
                case 'a':
                    cout << "   Predikat: Sangat Memuaskan (85-100)" << endl;
                    break;
                case 'B':
                case 'b':
                    cout << "   Predikat: Memuaskan (75-84)" << endl;
                    break;
                case 'C':
                case 'c':
                    cout << "   Predikat: Cukup (65-74)" << endl;
                    break;
                case 'D':
                case 'd':
                    cout << "   Predikat: Kurang (55-64)" << endl;
                    break;
                default:
                    cout << "   Predikat: Tidak Lulus / Grade Tidak Dikenal" << endl;
                    break;
            }
            cout << "   -> char di-switch berdasarkan nilai ASCII-nya." << endl;
            cout << "   -> Pakai fall-through untuk handle huruf besar & kecil." << endl;
        }

    // ── 5. Switch vs if-else - Perbandingan Langsung ──────────
        cout << "\n5. Switch vs if-else - Bandingkan Langsung" << endl;
        {
            int bulan = 8;
            cout << "   Bulan ke-" << bulan << endl;

            // Versi switch (rapi untuk banyak pilihan nilai tetap)
            string namaBulan;
            switch (bulan) {
                case 1:  namaBulan = "Januari";   break;
                case 2:  namaBulan = "Februari";  break;
                case 3:  namaBulan = "Maret";     break;
                case 4:  namaBulan = "April";     break;
                case 5:  namaBulan = "Mei";       break;
                case 6:  namaBulan = "Juni";      break;
                case 7:  namaBulan = "Juli";      break;
                case 8:  namaBulan = "Agustus";   break;
                case 9:  namaBulan = "September"; break;
                case 10: namaBulan = "Oktober";   break;
                case 11: namaBulan = "November";  break;
                case 12: namaBulan = "Desember";  break;
                default: namaBulan = "Tidak Valid"; break;
            }
            cout << "   Nama bulan (switch): " << namaBulan << endl;

            // Jumlah hari per bulan - perlu range, jadi if-else lebih cocok
            int jumlahHari;
            if (bulan == 2) {
                jumlahHari = 28;  // abaikan kabisat untuk simplifikasi
            } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
                jumlahHari = 30;
            } else {
                jumlahHari = 31;
            }
            cout << "   Jumlah hari (if-else): " << jumlahHari << " hari" << endl;
            cout << "   -> Switch cocok untuk nilai tetap, if-else untuk range/kondisi." << endl;
        }

    // ── 6. Contoh Praktis - Kalkulator Sederhana ─────────────
        cout << "\n6. Contoh Praktis - Kalkulator Sederhana" << endl;
        {
            double a = 20.0, b = 4.0;
            char operasi = '/';

            cout << "   " << a << " " << operasi << " " << b << " = ";

            switch (operasi) {
                case '+':
                    cout << a + b << endl;
                    break;
                case '-':
                    cout << a - b << endl;
                    break;
                case '*':
                    cout << a * b << endl;
                    break;
                case '/':
                    if (b != 0) {
                        cout << a / b << endl;
                    } else {
                        cout << "Error: pembagi tidak boleh nol!" << endl;
                    }
                    break;
                default:
                    cout << "Operator tidak dikenal!" << endl;
                    break;
            }
        }

    // ── Tips ──────────────────────────────────────────────────
        cout << "\nTips:" << endl;
        cout << "   -> Selalu tambahkan break di setiap case (kecuali fall-through disengaja)" << endl;
        cout << "   -> Selalu sertakan default sebagai 'catch-all'" << endl;
        cout << "   -> Switch hanya bisa untuk int, char, enum - TIDAK bisa float/string" << endl;
        cout << "   -> Untuk range nilai (>=, <=, &&, ||) -> pakai if-else" << endl;
        cout << "   -> Fall-through sengaja berguna untuk beberapa case dengan aksi sama" << endl;
}


int main(){

    switchCase();

    return 0;
}
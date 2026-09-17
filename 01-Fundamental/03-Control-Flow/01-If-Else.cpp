#include <iostream>
#include <string>
using namespace std;

void ifElse() {
    cout << "\n==================== Percabangan - If, Else If, Else ====================" << endl;

    // ── 1. if Tunggal ──────────────────────────────────────────
        cout << "\n1. if Tunggal - Satu Kondisi, Satu Aksi" << endl;
        {
            int suhu = 38;
            cout << "   Suhu tubuh: " << suhu << "C" << endl;

            if (suhu >= 38) {
                cout << "   Demam! Segera istirahat dan minum obat." << endl;
            }
            // Kalau suhu < 38, tidak ada yang terjadi - program lanjut biasa

            int stok = 0;
            if (stok == 0) {
                cout << "   Stok habis, tidak bisa proses pesanan." << endl;
            }
        }

    // ── 2. if-else - Dua Pilihan ──────────────────────────────
        cout << "\n2. if-else - Dua Pilihan (Benar / Salah)" << endl;
        {
            int usia = 16;
            cout << "   Usia: " << usia << " tahun" << endl;

            if (usia >= 17) {
                cout << "   Status: Boleh membuat KTP." << endl;
            } else {
                cout << "   Status: Belum cukup umur untuk membuat KTP." << endl;
            }

            double saldo = 150000.0;
            double harga = 200000.0;
            cout << "\n   Saldo: Rp " << saldo << ", Harga: Rp " << harga << endl;

            if (saldo >= harga) {
                cout << "   Transaksi berhasil. Saldo cukup." << endl;
            } else {
                cout << "   Transaksi gagal. Saldo tidak cukup." << endl;
            }
        }

    // ── 3. if-else if-else - Banyak Cabang ────────────────────
        cout << "\n3. if-else if-else - Banyak Cabang" << endl;
        {
            int nilai = 82;
            cout << "   Nilai ujian: " << nilai << endl;

            // Dievaluasi dari atas ke bawah - yang pertama true langsung diambil
            if (nilai >= 85) {
                cout << "   Grade: A - Sangat Memuaskan" << endl;
            } else if (nilai >= 75) {
                cout << "   Grade: B - Memuaskan" << endl;
            } else if (nilai >= 65) {
                cout << "   Grade: C - Cukup" << endl;
            } else if (nilai >= 55) {
                cout << "   Grade: D - Kurang" << endl;
            } else {
                cout << "   Grade: E - Tidak Lulus" << endl;
            }

            // Visualisasi alur evaluasi
            cout << "\n   Cara kerja evaluasi (nilai=82):" << endl;
            cout << "   82 >= 85? Tidak -> lanjut" << endl;
            cout << "   82 >= 75? YA    -> cetak Grade B, selesai (skip sisanya)" << endl;
        }

    // ── 4. Nested If - If di Dalam If ─────────────────────────
        cout << "\n4. Nested If - Kondisi di Dalam Kondisi" << endl;
        {
            double ipk       = 3.75;
            int    masaStudi = 4;

            cout << "   IPK: " << ipk << ", Masa Studi: " << masaStudi << " tahun" << endl;

            if (ipk >= 3.0) {
                cout << "   Status: Lulus" << endl;

                // Kondisi tambahan HANYA jika sudah lulus
                if (ipk >= 3.5 && masaStudi <= 4) {
                    cout << "   Predikat: Cum Laude " << endl;
                } else if (ipk >= 3.5) {
                    cout << "   Predikat: Lulus dengan Pujian (masa studi > 4 tahun)" << endl;
                } else {
                    cout << "   Predikat: Lulus Biasa" << endl;
                }

            } else if (ipk >= 2.0) {
                cout << "   Status: Lulus (IPK di bawah standar)" << endl;
            } else {
                cout << "   Status: Tidak Lulus - IPK terlalu rendah" << endl;
            }
        }

    // ── 5. Kombinasi dengan Operator Logika ───────────────────
        cout << "\n5. Kombinasi dengan &&, ||, !" << endl;
        {
            int  umur       = 20;
            bool punya_ktp  = true;
            bool punya_sim  = false;
            int  saldo      = 500000;

            cout << "  Umur  = " << umur << endl;
            cout << "  KTP   = " << (punya_ktp?"ya":"tidak") << endl;
            cout << "  SIM   = " << (punya_sim?"ya":"tidak") << endl;
            cout << "  Saldo = Rp" << saldo << endl;

            // Kondisi majemuk dengan &&
            if (umur >= 17 && punya_ktp) {
                cout << "   Bisa mendaftar ujian SIM: YA" << endl;
            }

            // Kondisi dengan ||
            if (punya_ktp || punya_sim) {
                cout << "   Punya identitas resmi: YA" << endl;
            }

            // Kondisi dengan !
            if (!punya_sim) {
                cout << "   Belum punya SIM - disarankan buat SIM dulu" << endl;
            }

            // Kombinasi && dan ||
            bool bolehPinjam = (umur >= 18) && (saldo >= 100000 || punya_ktp);
            cout << "   Boleh pinjam buku? " << (bolehPinjam ? "YA" : "TIDAK") << endl;
        }

    // ── 6. Dangling Else - Jebakan ────────────────────────────
        cout << "\n6. Dangling Else - Jebakan Indentasi!" << endl;
        {
            int a = 5, b = -3;

            // Tanpa kurung - berbahaya!
            // if (a > 0)
            //     if (b > 0)
            //         cout << "keduanya positif";
            // else          <- else ini milik if(b>0) bukan if(a>0)!
            //     cout << "a tidak positif";  // SALAH kapan dieksekusinya!

            // SOLUSI: Selalu pakai kurung kurawal {}
            cout << "   a=" << a << ", b=" << b << endl;
            if (a > 0) {
                if (b > 0) {
                    cout << "   Keduanya positif" << endl;
                } else {
                    cout << "   a positif, b tidak" << endl;
                }
            } else {
                cout << "   a tidak positif" << endl;
            }
            cout << "   -> Pakai {} selalu, walau isinya cuma 1 baris!" << endl;
        }

    // ── 7. Contoh Praktis: Kalkulator BMI ─────────────────────
        cout << "\n7. Contoh Praktis - Kategori BMI" << endl;
        {
            double beratKg  = 68.0;
            double tinggiM  = 1.72;
            double bmi      = beratKg / (tinggiM * tinggiM);

            cout << "   Berat: " << beratKg << " kg, Tinggi: " << tinggiM << " m" << endl;
            cout << "   BMI  : " << bmi << endl;

            string kategori;
            if (bmi < 18.5) {
                kategori = "Kekurangan Berat Badan";
            } else if (bmi < 25.0) {
                kategori = "Normal / Ideal ✓";
            } else if (bmi < 30.0) {
                kategori = "Kelebihan Berat Badan";
            } else {
                kategori = "Obesitas";
            }
            cout << "   Kategori: " << kategori << endl;
        }

    // ── 8. Contoh Praktis: Tiket Bioskop ──────────────────────
        cout << "\n8. Contoh Praktis - Harga Tiket Bioskop" << endl;
        {
            int  usia        = 12;
            bool pelajar     = true;
            bool hari_kerja  = false;   // false = akhir pekan

            cout << "  Usia=" << usia << endl;
            cout << "  Pelajar=" << (pelajar?"ya":"tidak") << endl;
            cout << "  HariKerja=" << (hari_kerja?"ya":"tidak") << endl;

            double harga;

            if (usia < 5) {
                harga = 0;
                cout << "   Kategori: Balita - GRATIS!" << endl;
            } else if (usia <= 12 || pelajar) {
                harga = hari_kerja ? 35000 : 45000;
                cout << "   Kategori: Anak/Pelajar" << endl;
            } else if (usia >= 60) {
                harga = hari_kerja ? 30000 : 40000;
                cout << "   Kategori: Lansia" << endl;
            } else {
                harga = hari_kerja ? 50000 : 65000;
                cout << "   Kategori: Umum/Dewasa" << endl;
            }

            cout << "   Harga tiket: Rp " << harga << endl;
        }

    // ── Tips ──────────────────────────────────────────────────
        cout << "\nTips:" << endl;
        cout << "   -> Selalu pakai {} walau isinya cuma 1 baris (hindari dangling else)" << endl;
        cout << "   -> else if dievaluasi dari atas - urutkan dari yang paling ketat" << endl;
        cout << "   -> Gunakan else sebagai 'catch-all' untuk kondisi tak terduga" << endl;
        cout << "   -> Kondisi majemuk: && (keduanya), || (salah satu), ! (kebalikan)" << endl;
        cout << "   -> Nested if: pakai untuk kondisi yang hanya relevan jika kondisi luar terpenuhi" << endl;
}


int main(){

    ifElse();

    return 0;
}
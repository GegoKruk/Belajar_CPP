#include <iostream>
using namespace std;

// 1. Soal Pertama
    /*
        “Toko Buah Pak Didi”
            Pak Didi menjual apel dan jeruk. 
            Setiap apel harganya 3000 rupiah, jeruk 2500 rupiah. 
            
            Buat program yang:
            - Menerima input jumlah apel dan jeruk yang dibeli.
            - Menghitung total harga.
            - Menampilkan total harga ke layar.
            Tujuan: Latihan input/output, variabel, dan operator aritmatika.
    */
    void tokoBuahDidi(){
        cout << "========== Toko Buah Pak Didi ==========" << endl;
        cout << "        ===> Cek Pembayaran <===" << endl;
    
        int hargaApel = 3000;
        int hargaJeruk = 2500;
        int totalApel, totalJeruk, totalHarga;

        cout << endl << "Jumlah apel yang anda beli : ";
        cin>>totalApel;
        cout << "Jumlah jeruk yang anda beli : ";
        cin>>totalJeruk;
        
        if (totalApel < 0 || totalJeruk < 0){
            cout << "Jumlah buah tidak boleh negatif!" << endl;
            return;
        }

        totalHarga = (totalApel * hargaApel) + (totalJeruk * hargaJeruk);

        cout << endl << "Jumlah total harga yang harus anda bayar : " << totalHarga << endl;
        cout << "Terima kasih sudah berbelanja!" << endl;
    }

// 2. Soal Kedua
    /*
        “Cek Umur SIM”

            Buat program yang:
            - Menerima input umur pengguna.
            - Menentukan apakah dia boleh membuat SIM (syarat: umur ≥ 17).
            - Menampilkan pesan “Boleh membuat SIM” atau “Belum cukup umur”.
            Tujuan: Latihan perbandingan dan logika sederhana.
    */
    void programMembuatSim(){
        cout << endl << "========== Program Pendaftaran SIM ==========" << endl;
        cout << "        ===> Masukkan Data Diri <===" << endl;

        string namaLengkap;
        int umur;

        cout << endl << "Masukkan Nama Lengkap Anda : ";
        cin>>namaLengkap;
        cout << "Masukkan Usia Anda : ";
        cin>>umur;

        if (umur < 17){
            cout << endl << "Mohon Maaf Data yang Anda Masukkan Tidak Memenuhi Syarat Pembuatan SIM " << endl;
            cout << "Usia Anda Dibawah 17 Tahun, Syarat Usia Harus Lebih dari 17 Tahun" << endl;
            cout << "Terima Kasih!" << endl;
        } else {
            cout << endl << "Data Anda Sudah Masuk!" << endl;
            cout << "Mohon Dicek Ulang..." << endl;
            cout << "1. Nama Lengkap : "<< namaLengkap << endl;
            cout << "2. Usia         : "<< umur << " Tahun"<< endl;
        }
    }

// 3. Soal Ketiga
    /*
        “Kalkulator Sederhana”
            Buat program yang:
            - Menerima dua angka dari pengguna.
            - Menerima satu karakter operator (+, -, *, /).
            - Menampilkan hasil operasi sesuai operator yang dimasukkan.
            Tujuan: Latihan input bertipe campuran dan logika seleksi.
    */
    void kalkulatorSederhana(){
        cout << endl << "========== Kalkulator Sederhana ==========" << endl;
        int input1;
        int input2;
        char perintah;
        float hasil;

        cout << endl << "Masukkan Angka Pertama : ";
        cin>>input1;
        cout << "Masukkan Perintah Matematika (+,-,*,/) : ";
        cin>>perintah;
        cout << "Masukkan Angka Kedua : ";
        cin>>input2;

        if (perintah == '+'){
            hasil = input1 + input2;
            cout << "Hasil Akhir Penjumlahan (+) : "<< hasil << endl;
        } else if (perintah == '-'){
            hasil = input1 - input2;
            cout << "Hasil Akhir Pengurangan (-) : "<< hasil << endl;
        } else if (perintah == '*'){
            hasil = input1 * input2;
            cout << "Hasil Akhir Perkalian (*) : "<< hasil << endl;
        } else if (perintah == '/'){
            hasil = input1 / input2;
            cout << "Hasil Akhir Pembagian (/) : "<< hasil << endl;
        } else {
            cout << "Perintah Tidak dikenali, mohon coba lagi!" << endl;
        }
    }

// 4. Soal KeEmpat
    /*
        “Konversi Detik ke Menit dan Detik”

            Buat program yang:
            - Menerima input total detik dari pengguna.
            - Mengubahnya menjadi format menit dan sisa detik.
            - Contoh: 125 detik → 2 menit 5 detik.
            Tujuan: Latihan operator aritmatika dan pembagian/modulus.
    */
    void detikKeMenitDetik(){
        cout << endl << "========== Konversi Detik ke Menit & Detik ==========" << endl;
        
        int inputUser, menit, sisaDetik;

        cout << "Masukkan nilai detik : ";
        cin>>inputUser;
        
        menit = (inputUser / 60);
        sisaDetik = (inputUser % 60);

        cout << "Konversi ke Menit dan Detik : "<< menit<< " Menit " << sisaDetik << " Detik " << endl;
    }

// 5. Soal KeLima
    /*
        “Skor Ujian dan Status”
            Buat program yang:
            - Menerima input nama siswa dan skor ujian.
            - Menentukan status kelulusan (≥ 75 lulus).
            - Menampilkan: “Nama: [nama], Skor: [skor], Status: Lulus/Tidak Lulus”.
            Tujuan: Latihan tipe data string dan logika perbandingan.
    */
    void skorUjianDanStatus(){
        cout << endl << "========== Program Skor Ujian dan Status ==========" << endl;
        string namaLengkap, status;
        int nilaiUjian;

        cout << "Masukkan Nama Lengkap : ";
        cin >> namaLengkap;
        cout << "Masukkan Nilai Ujian :";
        cin >> nilaiUjian;

        // Logic
        if (nilaiUjian >= 70){
            status = "LULUS";
        } else {
            status = "TIDAK LULUS";
        }

        cout << endl << "Data Anda Sudah Masuk!" << endl;
        cout << "Nama Lengkap : "<< namaLengkap << endl;
        cout << "Nilai Ujian  : "<< nilaiUjian << endl;
        cout << "Dengan Begitu Anda Dinyatakan" << status << endl;
    } 

// 6. Soal
    /*
        void numberGuesser(){
            int secret = 42;
            int guess;
            int tries = 0;
            
            while (true) {
                cout << "Guess (1-100): ";
                cin >> guess;
                tries++;
                
                // Implementasi:
                // - Kalau guess < 1 atau > 100: continue (invalid)
                // - Kalau guess == secret: break (found!)
                // - Kalau guess terlalu kecil/besar: kasih hint
                // - Max 5 tries
            }
        }
    */
    void numberGuesser(){
        system("CLS");
        int secret = 42;
        int guess;
        int tries = 5;
        
        while (true){
            cout << "Tebak angka (1-100): ";
            cin >> guess;
            

            if (guess <1 || guess > 100){
                cout << "\nTerjadi Kesalahan! Input diluar ketentuan..." << endl;
                continue;
            } else if (guess < secret){
                cout << "\nTebakan angka anda lebih kecil!" << endl;
            } else if (guess > secret){
                cout << "\nTebakan angka anda lebih besar!" << endl;
            } else if (guess == secret){
                cout << "\nTebakan angka benar!" << endl;
                break;
            } else if (tries == 0){
                cout << "\nMaaf sisa percobaan anda telah selesai" << endl;
            }

            tries--;
        }
    }





    int main(){
        // tokoBuahDidi();
        // programMembuatSim();
        // kalkulatorSederhana();
        // detikKeMenitDetik();
        // skorUjianDanStatus();
        numberGuesser();

        return 0;
    }
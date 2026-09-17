#include <iostream>
using namespace std;

// Function Program Kasir Sekolah
void programKasirSekolah(){

    //Deklarasi variabel 
    int pilihanMainMenu;

    int pilihanMakanan;
        int hargaNasiGoreng = 12000;
        int hargaMieAyam = 10000;
        int hargaRotiBakar = 15000;
    
    int pilihanMinuman;
        int hargaTeh = 3000;
        int hargaJeruk = 5000;
        int hargaSusuCoklat = 7000;

    int pilihanMenuBayar;
    char lanjutPembayaran;
    string kodePromoValid = "MUYPJ";
    string kodePromoInput;
    char pilihanKodePromo;
    int pilihanKodePromoTidakValid;
    
    int diskon;
    int totalHarga = 0;
    int inputUangUser;
    int uangKembalian;
    
    //Do-While Loop Main Menu dan Pilihan
    do {
        //Main Menu
        cout << endl << "[Kantin Sekolah Digital]_________" << endl;
        cout << "|1. Makanan                     |" << endl;
        cout << "|2. Minuman                     |" << endl;
        cout << "|3. Cek Harga & Bayar           |" << endl;
        cout << "|4. Keluar                      |" << endl;
        cout << "|_______________________________|" << endl;
        cout << " Pilih : ";
        cin >> pilihanMainMenu;

        //Switch Case Setiap Pilihan
        switch (pilihanMainMenu){
            case 1:
                //Display Menu Makanan
                cout << endl << "[Menu Makanan]________________" << endl;
                cout << "|1. Nasi Goreng    (Rp12.000)|" << endl;
                cout << "|2. Mie Ayam Afui  (Rp10.000)|" << endl;
                cout << "|3. Roti Bakar     (Rp15.000)|" << endl;
                cout << "|4. Kembali                  |" << endl;
                cout << "|____________________________|" << endl;
                cout << "Pilih : ";
                cin >> pilihanMakanan;

                //Switch Case Menu Makanan
                switch (pilihanMakanan){
                    case 1:
                        totalHarga += hargaNasiGoreng;
                        system("CLS");
                        break;
                    case 2:
                        totalHarga += hargaMieAyam;
                        system("CLS");
                        break;
                    case 3:
                        totalHarga += hargaRotiBakar;
                        system("CLS");
                        break;
                    case 4:
                        system("CLS");
                        break;
                }
                break;
                
            case 2:
                //Display Menu Makanan
                cout << endl << "[Menu Minuman]____________" << endl;
                cout << "|1. Es Teh      (Rp3.000)|" << endl;
                cout << "|2. Es Jeruk    (Rp5.000)|" << endl;
                cout << "|3. Susu Cokalt (Rp7.000)|" << endl;
                cout << "|4. Kembali              |" << endl;
                cout << "|________________________|" << endl;
                cout << "Pilih : ";
                cin >> pilihanMinuman;

                //Switch Case Menu Minuman
                switch (pilihanMinuman){
                    case 1:
                        totalHarga += hargaTeh;
                        system("CLS");
                        break;
                    case 2:
                        totalHarga += hargaJeruk;
                        system("CLS");
                        break;
                    case 3:
                        totalHarga += hargaSusuCoklat;
                        system("CLS");
                        break;
                    case 4:
                        system("CLS");
                        break;
                }
                break;

            case 3:
                //Display Pemberitahuan Belum Memilih Pesanan
                if (totalHarga == 0 || totalHarga <=0) {
                    cout << endl << "==========[Pemberitahuan]==========" << endl;
                    cout << "Mohon maaf anda belum memilih menu makanan atau minuman" << endl;
                    cout << "Silakan kembali ke menu utama" << endl;
                    cout << "Terima Kasih!" << endl;
                    cout << endl << "Ketik apa saja untuk kembali : ";

                    int kembali;
                    cin >> kembali;
                    switch (kembali){
                        default:
                        system("CLS");
                        continue;
                    }

                //Display Jika Sudah Memilih Pesanan
                } else if (totalHarga != 0){
                    //Display Cek Harga & Pembayaran
                    cout << endl << "==========[Cek Harga & Pembayaran]==========" << endl;
                    cout << "Total Harga : Rp" << totalHarga << endl; 

                    //Display Diskon
                    if (totalHarga > 10000){
                        cout << endl;
                        cout << "__________________*******_____________________" << endl;
                        cout << "|Total Belanja Anda lebih dari 10 ribu rupiah|" << endl;
                        cout << "|      Selamat Anda mendapat Diskon 10%      |" << endl;
                        cout << "|        ~ Gunakan kode promo Anda ~         |" << endl;
                        cout << "|____________________________________________|" << endl;
                        
                        //Pilihan input kode promo
                        cout << endl << "Masukkan Kode Promo? (Y/N) : ";
                        cin >> pilihanKodePromo;
                        if (pilihanKodePromo == 'Y' || pilihanKodePromo == 'y'){
                            do{
                                //Input Kode Promo
                                cout << endl << "===== PROMO =====" << endl;
                                cout << "Masukkan Kode Promo Anda : ";
                                cin >> kodePromoInput;
                                
                                cout << "Kode Promo Sedang Di Proses....." << endl;
                                if (kodePromoInput == kodePromoValid){
                                    cout << endl << "===== SELAMAT =====" << endl;
                                    cout << "Kode Promo Valid!" << endl;
                                    
                                    //Perhitungan Diskon
                                    cout << "Total Harga Sebelum Diskon : Rp" << totalHarga << endl;
                                    diskon = totalHarga * 10 / 100;
                                    totalHarga = totalHarga - diskon;
                                    cout << "Total Harga Setelah Diskon : Rp" << totalHarga << endl;

                                    
                                    cout << "Lanjut ke pembayaran? (Y/N) : " ;
                                    cin >> lanjutPembayaran;
                                    
                                } else if (kodePromoInput != kodePromoValid){
                                    cout << endl << "===== TERJADI KESALAHAN =====" << endl;
                                    cout << "Kode promo Anda tidak valid!" << endl;
                                    cout << "1. Coba Lagi" << endl;
                                    cout << "2. Lanjut tanpa promo" << endl;
                                    cout << "Pilih : ";
                                    cin >> pilihanKodePromoTidakValid;
                                
                                    switch (pilihanKodePromoTidakValid){
                                        case 1 : 
                                            continue;
                                        break;
    
                                        case 2 : 
                                            kodePromoInput = "MUYPJ";
                                            cout << "Lanjut ke pembayaran? (Y/N) : ";
                                            cin >> lanjutPembayaran;
                                        break;
                                    } 
                                }
                            } while (kodePromoInput != kodePromoValid);
                        }
                    }
                
                    if ((pilihanKodePromo == 'N' || pilihanKodePromo == 'n') || (lanjutPembayaran == 'Y' || lanjutPembayaran == 'y')){
                         //Display Pembayaran
                        cout << endl << "[Menu Pembayaran]____________" << endl;
                        cout << "|1. Bayar                   |" << endl;
                        cout << "|2. Hapus Pesanan           |" << endl;
                        cout << "|3. Kembali                 |" << endl;
                        cout << "|___________________________|" << endl;
                        cout << "Pilih : ";
                        cin >> pilihanMenuBayar;

                        //Switch Case Menu Makanan
                        switch (pilihanMenuBayar){
                            case 1:
                                cout << endl << "===== PEMBAYARAN =====" << endl;
                                cout << "Total Harga : Rp" << totalHarga << endl;
                                cout << "Masukkan uang Anda :";
                                cin >> inputUangUser;

                                if (inputUangUser == totalHarga){ //Jika Uang Pas
                                    cout << endl << "===== SELAMAT =====" << endl;
                                    cout << "Pembayaran Berhasil!" << endl;
                                    cout << "   ~Terima Kasih~   " << endl;

                                } else if (inputUangUser > totalHarga){ //Jika Uang Berlebih (Kembalian)
                                    cout << endl << "===== SELAMAT =====" << endl;
                                    cout << "Pembayaran Berhasil!" << endl;
                                    cout << "Uang Anda Berlebih..." << endl;
                                    uangKembalian = inputUangUser - totalHarga;
                                    cout << "Uang Kembalian : Rp"<< uangKembalian << endl;
                                    cout << "   ~Terima Kasih~   " << endl;

                                } else if (inputUangUser < totalHarga){ //Jika Uang Kurang
                                    cout << endl << "===== TERJADI KESALAHAN =====" << endl;
                                    cout << "Pembayaran Gagal!" << endl;
                                    cout << "Uang Anda Tidak Mencukupi"<< endl;
                                    cout << "Ketik apa saja untuk kembali : ";
                                    char kembali;
                                    cin >> kembali;
                                    if (kembali == true){
                                        system("CLS");
                                        continue;
                                    }
                                } 
                                break;

                            case 2:
                                totalHarga = 0;
                                cout << endl << "==========[Pemberitahuan]==========" << endl;
                                cout << "Seluruh pesanan telah berhasil dihapus!" << endl;
                                break;

                            case 3:
                                continue;  
                        }
                    }
                }
            default:
            break;
        }
    } while (pilihanMainMenu >= 1 && pilihanMainMenu < 4);

    //Logic exception untuk pilihan no 4
    if (pilihanMainMenu == 4){
        exit(0);
    }
}

//Mesin Utama
int main(){
    ///Panggil Function
    programKasirSekolah();

    return 0;
}
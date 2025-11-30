#include <iostream>
using namespace std;

bool exitMenu;  
string username = "algo";
string password = "asyik";
string voucher = "MUYPJ";
string inputVoucher;
string inputUserName;
string inputPassword;
int totalTiketDijual = 100;

void functionAutentikasi(){

    bool autentikasi = false;

    do {
        cout << "\n=====[Login Akun]=====" << endl;
        cout << "Masukkan Username: ";
        cin >> inputUserName;
        cout << "Masukkan Password: ";
        cin >> inputPassword;

        if ( username == inputUserName && password == inputPassword){
            cout << "\n=====[Login Berhasil]=====" << endl;
            autentikasi = true;
        } else {
            char loginUlang;

            cout << "\n=====[Username atau Password Salah]=====" << endl;
            cout << "Apakah ingin login ulang? (y/n): ";
            cin >> loginUlang;

            if (loginUlang == 'Y' || loginUlang == 'y'){
                autentikasi = false; 
            } else if (loginUlang == 'N' || loginUlang == 'n') {
                cout << "\n=====[Program Selesai Terima Kasih!]=====" << endl;
                exit(0);
            } else {
                cout << "\n=====[Input Tidak Valid]=====" << endl;
                exit(0);
            }
        }
    } while (autentikasi == false);
}

void tampilkanTiket(){
    system("CLS");

    cout << "\n=====[Tampilkan Tiket]=====" << endl;
    cout << "Kategori Tiket [1]" << endl;
    cout << "Jenis Tiket    : VIP" << endl;
    cout << "Harga Tiket    : 100.000" << endl;
    
    cout << "\nKategori Tiket [2]" << endl;
    cout << "Jenis Tiket    : Festival" << endl;
    cout << "Harga Tiket    : 50.000" << endl;
    cout << "\nKembali ke Menu ? (y/n): ";
    char kembaliMenu;
    cin >> kembaliMenu;
    
    if (kembaliMenu == 'Y' || kembaliMenu == 'y'){
        exitMenu = false;
    } else if (kembaliMenu == 'N' || kembaliMenu == 'n'){
        tampilkanTiket();
    } else {
        cout << "\n=====[Input Tidak Valid]=====" << endl;
        tampilkanTiket();
    }
}

int main(){
    system("CLS");
    string nik[totalTiketDijual];
    string namaLengkap[totalTiketDijual];
    int kategoriTiket[totalTiketDijual];
    int hargaTiket[totalTiketDijual];
    int jumlahTiket[totalTiketDijual];
    int totalHarga[totalTiketDijual];
    int nominalPembayarann[totalTiketDijual];
    int kembalian[totalTiketDijual];
    int pembeli = 0;

    cout << " =====[Selamat Datang]=====" << endl;
    cout << "[KASIR DIGITAL KONSER MUSIK]" << endl;

    // Panggil fungction login akun
    functionAutentikasi();
    
    int inputPilihMenu;

    do {
        system("CLS");
        
        cout << "\n=====[Menu Utama Kasir]=====" << endl;
        cout << "1. Tampilkan Tiket " << endl;
        cout << "2. Pembelian Tiket " << endl;
        cout << "3. Lihat Pesanan " << endl;
        cout << "4. Exit " << endl;
        cout << "Pilih Menu : ";
        cin >> inputPilihMenu;

        switch (inputPilihMenu){
            case 1 : 
                tampilkanTiket();
                break ;

            case 2 : 
                cout << "\n=====[Pembelian Tiket]=====" << endl;
        
                cout << "NIK Pembeli                      : ";
                cin >> nik[pembeli];
                cin.ignore(1000, '\n'); 
                
                cout << "Nama Pembeli                     : ";
                getline(cin, namaLengkap[pembeli]);
                
                cout << "Nomor Kategori Tiket             : ";
                cin >> kategoriTiket[pembeli];
                cin.ignore(1000, '\n');
                
                if (kategoriTiket[pembeli] == 1){
                    hargaTiket[pembeli] = 100000;
                } else if (kategoriTiket[pembeli] == 2){
                    hargaTiket[pembeli] = 50000;
                }
                cout << "Harga Tiket                      : " << hargaTiket[pembeli] << endl;

                cout << "Jumlah Tiket                     : ";
                cin >> jumlahTiket[pembeli];
                cin.ignore(1000, '\n');

                totalHarga[pembeli] = jumlahTiket[pembeli] * hargaTiket[pembeli];
                cout << "Total Harga                      : " << totalHarga[pembeli] << endl;

                bool voucherloop;
                do{
                    cout << "Input Voucher (isi 0 jika tidak) : ";
                    cin >> inputVoucher;
    
                    if (inputVoucher == voucher){
                        cin.ignore(1000, '\n');
                        cout << "\n====[Voucher Berhasil Digunakan]=====" << endl;
                        int diskon = totalHarga[pembeli] * 10 / 100;
                        totalHarga[pembeli] -= diskon;
                        cout << "Total Setelah Diskon             : " << totalHarga[pembeli] << endl;
                        voucherloop = false;
                    } else if (inputVoucher == "0") {
                        cin.ignore(1000, '\n');
                        cout << "\n====[Voucher Tidak Digunakan]=====" << endl;
                        voucherloop = false;
                    } else if (inputVoucher != voucher){
                        cin.ignore(1000, '\n');
                        cout << "\n=====[Kode Voucher Salah]=====" << endl;
                        voucherloop = true;
                    }
                } while (voucherloop == true);
                

                bool pembayaran;
                do{ 
                    cout << "Nominal Pembayaran               : ";
                    cin >> nominalPembayarann[pembeli];
            
                    if (nominalPembayarann[pembeli] > totalHarga[pembeli]){
                        cin.ignore(1000, '\n');
                        kembalian[pembeli] = nominalPembayarann[pembeli] - totalHarga[pembeli];
                        cout << "Kembalian                        : " << kembalian[pembeli] << endl;
                        pembayaran = false;
                    } else if (nominalPembayarann[pembeli] < totalHarga[pembeli]){
                        cin.ignore(1000, '\n');
                        cout << "=====[Uang Anda Tidak Cukup]=====" << endl;
                        pembayaran = true;
                    } else if (nominalPembayarann[pembeli] == totalHarga[pembeli]){
                        cin.ignore(1000, '\n');
                        cout << "Kembalian                        : 0 " << endl;
                        pembayaran = false;
                    }    
                } while (pembayaran == true);

                cout << "\n=====[Pembayaran Berhasil]=====" << endl;

                pembeli++;

                cout << "\nKembali ke menu? (Y): ";
                char pilihan;
                cin >> pilihan;
                if (pilihan == 'Y'){
                    exitMenu = false;
                }

                break ;

            case 3 : 
                cout << "=====[Riwayat Pembelian]=====" << endl;
                for(int i = 0; i < pembeli; i++){
                    cout << "\nPesanan Ke-" << (i + 1) << endl;
                    cout << "NIK             : "    << nik[i]           << endl;
                    cout << "Nama            : "    << namaLengkap[i]   << endl;
                    cout << "Jenis Tiket     : "    << kategoriTiket[i]    << endl;
                    cout << "Harga Satuan    : Rp " << hargaTiket[i]   << endl;
                    cout << "Jumlah          : "    << jumlahTiket[i]   << " tiket" << endl;
                    cout << "Total Bayar     : Rp " << totalHarga[i]    << endl;
                    cout << "Nominal Uang    : Rp " << nominalPembayarann[i]  << endl;
                    cout << "Kembalian       : Rp " << kembalian[i]     << endl;
                }

                cout << "\nKembali ke menu? (Y): ";
                cin >> pilihan;
                if (pilihan == 'Y'){
                    exitMenu = false;
                }
                break ;

            case 4 : 
                cout << "\n=====[Terima Kasih]=====" << endl;
                exitMenu = true;
                break ;
            default : cout << "\n=====[Input Tidak Valid]=====" << endl;
        }

    } while (exitMenu == false);
}
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
    S-08: Sistem Manajemen Rental PC (GEGA GAMING CENTER)
    
    Konteks:
        Kamu adalah pemilik rental PC "GEGA Gaming Center". 
        Kamu butuh sistem untuk mendata komputer, penyewa, dan menghitung pendapatan secara otomatis.

    1. Spesifikasi Data (Struct)
        Kamu harus menggunakan Nested Struct (Struct di dalam Struct):

        Struct Waktu: 
            - Jam, Menit (untuk mencatat durasi main).

        Struct PC:
            - ID PC (int)
            - Tipe PC ("Reguler", "VIP", "VVIP")
            - Harga per jam (double)
            - Status ("Tersedia" atau "Dipakai")

        Struct Transaksi:
            - Nama Penyewa (string)
            - PC yang disewa (Struct PC)
            - Waktu Mulai & Waktu Selesai (Struct Waktu)
            - Total Biaya (double)

    2. Fitur Utama (Menu)
        Program harus memiliki menu interaktif:
            - Inisialisasi PC (Admin Only): Setup awal 5-10 PC dengan tipe dan harga yang berbeda-beda.
            - Daftar PC: Menampilkan tabel seluruh PC beserta statusnya.

        Sewa PC:
            - Input nama penyewa.
            - Pilih PC yang statusnya "Tersedia".
            - Input jam mulai (misal: 14:30).
            - Status PC berubah jadi "Dipakai".
        
        Selesai Sewa (Checkout):
            - Pilih PC yang sedang dipakai.
            - Input jam selesai.
        
        Logika Hitung: 
            - Program menghitung selisih waktu (Durasi) dan mengalikan dengan harga per jam PC tersebut. (Hati-hati dengan konversi menit ke jam!).
            - Tampilkan struk kecil di layar.
            - Status PC kembali "Tersedia".
        
        Laporan Pendapatan (Sorting):
            - Menampilkan daftar transaksi yang sudah selesai.
            - Urutkan transaksi berdasarkan Total Biaya Terbesar (Gunakan sorting yang sudah kamu pelajari).
        
        Cari Riwayat (Searching):
            - Cari transaksi berdasarkan Nama Penyewa menggunakan Linear atau Binary Search.

    3. Tantangan Kompleksitas (The "Gega" Level)
            - Validasi Waktu: Gimana kalau user input jam selesai lebih kecil dari jam mulai? (Misal mulai 23:00 selesai 01:00 hari berikutnya). Hint: Konversi semua ke total menit.
            - Array of Struct: Kamu akan mengelola PC daftarPC[10] dan Transaksi riwayat[100].
            - Pass by Reference: Gunakan fungsi untuk memanipulasi data PC agar statusnya benar-benar ter-update di memori utama.

    Instruksi Pengerjaan:
        - Buat file S-01-GegaGamingCenter.cpp di dalam Lat-Mandiri.
        - Cicil per fitur. Jangan langsung semua. (Misal: Hari 1 fokus ke Struct dan Menu 1-2).
        - Ingat aturan WIP commit kita kemarin kalau belum selesai.
        - No AI for Logic: 
            Coba ulik sendiri cara hitung durasi menitnya. Itu bagian paling seru!
*/

//[Function Prototype]==================================================================================
    void menuUtama();

    void tambahkanPC();
    void daftarDataPC();
    void editDataPC();
    void inisialisasiPC();

    void daftarPC(); 

    void checkIn();

    void checkOut();

    void hitungHarga();

    void laporanPendapatan();

    void riwayat();


//[Global Variable]==================================================================================
    // menu
    int indexDipilih;
    int pilihanMenu;
    char pilihanTipe;

    // const
    const int MAX_JML_PC_USER = 10;
    double totalSaldo;

    static int IDXPC = 0;
    int JML_PC_NOW = 0;

    int IDXUSER = 0;
    int JML_USER_NOW = 0;

    static int IDXTRANSAKSI = 0;
    int JML_TRANSAKSI_NOW = 0;

    struct Waktu {
        int jam[MAX_JML_PC_USER];
        int menit[MAX_JML_PC_USER];
    };

    struct DaftarPC {
        int idPC[MAX_JML_PC_USER];
        double hargaPC[MAX_JML_PC_USER];
        char kodeTipePC[MAX_JML_PC_USER] {};
        string tipePC[MAX_JML_PC_USER] {};
        string statusPC[MAX_JML_PC_USER];
        bool readyOrNo[MAX_JML_PC_USER];
    };

    struct Transaksi {
        int idUser[MAX_JML_PC_USER];
        string userName[MAX_JML_PC_USER];
        
        int idTransaksi[MAX_JML_PC_USER];
        double tagianUser[MAX_JML_PC_USER];
        double pendataanAlurUang[MAX_JML_PC_USER];
        
        DaftarPC pcDipilih;
        Waktu waktuMulaiSelesai;
        
        string catatan[MAX_JML_PC_USER];
    };

    DaftarPC blokDaftarPC;
    Transaksi blokTransaksi;

//[Helper Function]==================================================================================
    void garis(){
        system("CLS");
        cout << "\n==========[SOAL 1 - SISTEM MANAJEMEN GAMING CENTER]==========" << endl;
    }

    void invalidInput(){
        garis();
        cout << "\n\t[!] Invalid input - Silakan ulangi " << endl;
        cin.get();
    }

    void kembaliMenuUtama(){
        cout << "\n\tTekan [Enter] untuk kembali ke menu : ";
        cin.get();
        menuUtama();
    }

    void cekPCJikaMasihKosong(){
        garis();
        if (JML_PC_NOW == 0){
            cout << "\n\t>>> [!] FAILED: Belum ada PC yang terdaftar! <<<\n";
            kembaliMenuUtama();
        } 
    }

    void cekJikaSudahPenuh(){
        garis();
        if (JML_PC_NOW == MAX_JML_PC_USER){
            cout << "\n\t>>> [!] FAILED: PC terdaftar telah mencapai batas maksimal! <<<\n";
            kembaliMenuUtama();
        } 
    }
    
    void cekUserJikaMasihKosong(){
        garis();
        if (JML_USER_NOW == 0){
            cout << "\n\t>>> [!] FAILED: Belum ada USER yang terdaftar! <<<\n";
            kembaliMenuUtama();
        } 
    }

    void listDataPC(int index){
        cout << "     1. ID PC        : " << blokDaftarPC.idPC[index] << endl;
        cout << "     2. Tipe PC      : " << blokDaftarPC.tipePC[index] << endl;
        cout << "     3. Harga PC     : Rp" << blokDaftarPC.hargaPC[index] << endl;
        cout << "     4. Status PC    : " << blokDaftarPC.statusPC[index] << endl;
    }

    void listDataTransaksi(int index){
        cout << "     1. ID Transaksi : " << blokTransaksi.idUser[index] << endl;
        cout << "     2. Nama User    : " << blokTransaksi.userName[index] << endl;
        cout << "     3. Total Waktu  : " << blokTransaksi.waktuMulaiSelesai.jam[index] << " Jam " << blokTransaksi.waktuMulaiSelesai.menit[index] << " Menit" << endl;
        cout << "     4. Tagihan User : " << blokTransaksi.tagianUser[index] << endl;
    }

//[Function2 Utama]==================================================================================
    //[Blok Inisialisasi PC & Edit Data PC]---------------------------------------------------------------------------------

    void kembaliMenuInisialisasi(){
        cout << "\n\tTekan [Enter] untuk kembali ke menu : ";
        cin.get();
        inisialisasiPC();
    }

    void pemilihanTipePC(char pilihanTipe, int index){
        if(pilihanTipe == 'a'){
            blokDaftarPC.tipePC[index] = "REGULAR";
            blokDaftarPC.kodeTipePC[index] = 'a';
            blokDaftarPC.hargaPC[index] = 10000;
        } else if(pilihanTipe == 'b'){
            blokDaftarPC.tipePC[index] = "VIP";
            blokDaftarPC.kodeTipePC[index] = 'b';
            blokDaftarPC.hargaPC[index] = 15000;
        } else if(pilihanTipe == 'c'){
            blokDaftarPC.tipePC[index] = "VVIP";
            blokDaftarPC.kodeTipePC[index] = 'c';
            blokDaftarPC.hargaPC[index] = 20000;
        }
    }

    void updateStatusPC(char pilihanTipe, int index){
        if(pilihanTipe == 'a'){
            blokDaftarPC.statusPC[index] = "[Ready]";
            blokDaftarPC.readyOrNo[index] = true;
        } else if(pilihanTipe == 'b'){
            blokDaftarPC.statusPC[index] = "[Used/Maintenance]";
            blokDaftarPC.readyOrNo[index] = false;
        } 
    }

    void tambahkanPC(){
        char pilihanTipe;

        cekJikaSudahPenuh();
        garis();
        
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|   Tambahkan PC   |____________________\n" << endl;
        cout << " [1] ID PC Tergenerate  : " << IDXPC << endl; 
        blokDaftarPC.idPC[IDXPC] = IDXPC;
        cout << "\n [2] Pilih Kategori Tipe PC" << endl;
        cout << "     +--------------------------+" << endl;
        cout << "     | [a] Regular : Rp10.000   |" << endl; 
        cout << "     | [b] VIP     : Rp15.000   |" << endl; 
        cout << "     | [c] VVIP    : Rp20.000   |" << endl; 
        cout << "     +--------------------------+" << endl;
        cout << "     Pilih Kode [a/b/c] : ";

        cin >> pilihanTipe;
        cin.ignore();

        pemilihanTipePC(pilihanTipe, IDXPC);

        cout << "\n [3] Konfirmasi Harga   : Rp" << blokDaftarPC.hargaPC[IDXPC] << "/Jam"<< endl;

        updateStatusPC('a',IDXPC);
        
        cout << "\n==============================================================" << endl;
        cout << " [ RINGKASAN DATA PC BARU ]" << endl;
        listDataPC(IDXPC);
        cout << "==============================================================" << endl;

        cout << "\n\t>>> SUCCESS: Input Data Berhasil! <<<\n";

        IDXPC++;
        JML_PC_NOW++;
        kembaliMenuInisialisasi();
    }

    void daftarDataPC(){
        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|  Daftar Data PC  |____________________\n" << endl;
        cout << " > Total PC Aktif saat ini: " << JML_PC_NOW << " Unit" << endl;
        cout << " ------------------------------------------------------------" << endl;

        for (int i = 0; i < JML_PC_NOW; i++){
            cout << " [" << i+1 << "] Rincian Unit:" << endl;
            listDataPC(i);
            cout << " ------------------------------------------------------------" << endl;
        }
        
        cout << "\n\t[!] Seluruh data telah ditampilkan" << endl;
        kembaliMenuInisialisasi();
    }

    void editDataPC(){

        cekPCJikaMasihKosong();
        garis();
        
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|      Edit PC      |____________________" << endl;
        cout << "\n [!] Database memiliki " << JML_PC_NOW << " PC terdaftar" << endl;
        cout << "     Masukan ID PC yang ingin diubah: ";
        cin >> indexDipilih;
        cin.ignore();

        cout << "\n [Data Lama]-------------------------------------------------" << endl;
        listDataPC(indexDipilih);
        
        cout << "\n [Masukkan Data Baru]----------------------------------------" << endl;
        cout << "\n   [1] ID PC            : " << blokDaftarPC.idPC[indexDipilih] << endl;
        cout << "\n   [2] Update Tipe" << endl;
        cout << "       +--------------------------+" << endl;
        cout << "       | [a] Regular : Rp10.000   |" << endl; 
        cout << "       | [b] VIP     : Rp15.000   |" << endl; 
        cout << "       | [c] VVIP    : Rp20.000   |" << endl; 
        cout << "       +--------------------------+" << endl;
        cout << "       Pilih Kode [a/b/c] : ";
        cin >> pilihanTipe;
        cin.ignore();
        pemilihanTipePC(pilihanTipe, indexDipilih);

        cout << "\n   [3] Update Harga     : Rp" << blokDaftarPC.hargaPC[indexDipilih] << "/Jam" << endl;
        cout << "\n   [4] Update Status" << endl;
        cout << "       +-----------------------+" << endl;
        cout << "       | [a] Ready             |" << endl; 
        cout << "       | [b] Used/Maintenance  |" << endl; 
        cout << "       +-----------------------+" << endl;
        cout << "       Pilih Kode [a/b] : ";
        cin >> pilihanTipe;
        cin.ignore();
        updateStatusPC(pilihanTipe,indexDipilih);

        cout << "\n==============================================================" << endl;
        cout << " [ RINGKASAN DATA PC BARU (UPDATED) ]" << endl;
        listDataPC(indexDipilih);
        cout << "==============================================================" << endl;

        cout << "\n\t>>> SUCCESS: Data PC Berhasil Diperbarui! <<<\n";
        kembaliMenuInisialisasi();
    }

    void inisialisasiPC(){
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|   Menu - Admin   |____________________" << endl;
        cout << "|                                      |" << endl;
        cout << "| 1. Tambahkan PC                      |" << endl;
        cout << "| 2. Data PC                           |" << endl;
        cout << "| 3. Edit Data PC                      |" << endl;
        cout << "| 4. Back                              |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "Pilih (1-4) : ";

        cin >> pilihanMenu;
        cin.ignore();

        switch (pilihanMenu){
        case 1:
            tambahkanPC();
            break;
        case 2:
            daftarDataPC();
        case 3:
            editDataPC();
            break;
        case 4:
            menuUtama();
            break;
        default:
            invalidInput();
            inisialisasiPC();
            break;
        }
        kembaliMenuUtama();
    };

    //[Blok Daftar Seluruh PC beserta Status, User, DLL]---------------------------------------------------------------------------------

    void daftarPC(){

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Daftar PC |____________________" << endl;
        cout << " > Total PC Aktif saat ini: " << JML_PC_NOW << " Unit\n" << endl;
        cout << " ------------------------------------------------------------" << endl;
        for (int i = 0; i < JML_PC_NOW; i++){
            cout << " [" << i+1 << "] Rincian Unit:" << endl;
            listDataPC(i);
            
            if(blokDaftarPC.readyOrNo[i] == true){
                cout << "     PC STATUS [READY] " << endl;
            } else if (blokDaftarPC.readyOrNo[i] == false && JML_USER_NOW != 0){
                cout << "\n     [!] USED " << endl;
                cout << "\n     Rincian Transaksi:" << endl;
                listDataTransaksi(i);
            }
            cout << " ------------------------------------------------------------" << endl;
        }
        
        cout << "\n\t[!] Seluruh data telah ditampilkan" << endl;
        kembaliMenuUtama();
    }; 

    //[Blok Check In]---------------------------------------------------------------------------------

    void perhitunganJam(int menit, int i, int jam = 0){
        if(menit == 60){
            blokTransaksi.waktuMulaiSelesai.jam[i] = 1;
        }else if(menit > 60){
            int jam = menit / 60;
            float sisa = (menit % 60) / 60;

            blokTransaksi.waktuMulaiSelesai.jam[i] = jam;
            blokTransaksi.waktuMulaiSelesai.menit[i] = sisa;
        }
    }

    double perhitunganHarga(char pilihanTipe, int i){
        double harga;

        if (pilihanTipe = 'a'){
            harga = (blokTransaksi.waktuMulaiSelesai.jam[i] * 10000) + (blokTransaksi.waktuMulaiSelesai.menit[i] * 10000);
        } else if(pilihanTipe = 'b'){
            harga = (blokTransaksi.waktuMulaiSelesai.jam[i] * 15000) + (blokTransaksi.waktuMulaiSelesai.menit[i] * 15000);
        } else if(pilihanTipe = 'c'){
            harga = (blokTransaksi.waktuMulaiSelesai.jam[i] * 20000) + (blokTransaksi.waktuMulaiSelesai.menit[i] * 20000);
        }

        return harga;
    }

    void checkIn(){
        double harga;
        int menit;
        int jam;

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|  Menu - Check In |____________________" << endl;

        cout << "\n [1] Pilih Kategori Tipe PC" << endl;
        cout << "     +--------------------------+" << endl;
        cout << "     | [a] Regular : Rp10.000   |" << endl; 
        cout << "     | [b] VIP     : Rp15.000   |" << endl; 
        cout << "     | [c] VVIP    : Rp20.000   |" << endl; 
        cout << "     +--------------------------+" << endl;
        cout << "     Pilih Kode [a/b/c] : ";
        cin >> pilihanTipe;
        cin.ignore();

        cout << "\n [2] Index Unit PC yang [READY] : ";
        for (int i = 0; i < JML_PC_NOW; i++){
            if(blokDaftarPC.kodeTipePC[i] == pilihanTipe && blokDaftarPC.readyOrNo[i] == true){
            } else {
                continue;
            }
        }

        cout << "\n [3] Pilih Index PC             : ";
        cin >> indexDipilih;
        cin.ignore();

        cout << "\n [4] ID Transaksi Tergenerate   : " << IDXTRANSAKSI << endl; 
        blokTransaksi.idTransaksi[indexDipilih] = IDXTRANSAKSI;
        blokTransaksi.idUser[indexDipilih] = IDXTRANSAKSI;

        cout << "\n [5] Masukkan User Name         : ";
        cin >> blokTransaksi.userName[indexDipilih];

        cout << "\n [6] Total Waktu Bermain (Menit): ";
        cin >> menit;
        perhitunganJam(menit,indexDipilih);
        harga = perhitunganHarga(pilihanTipe, indexDipilih);
        
        cout << "\n [7] Total Tagihan User         : ";
        cout << harga << endl;


        IDXTRANSAKSI++;
        JML_TRANSAKSI_NOW++;
        IDXUSER++;
        JML_USER_NOW++;
        kembaliMenuUtama();
    };

    //[Blok Check Out]---------------------------------------------------------------------------------

    void checkOut(){

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Check Out |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Perhitungan Harga Sewa]---------------------------------------------------------------------------------
    void hitungHarga(){

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|   Menu - Harga   |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Laporan Pendapatan]---------------------------------------------------------------------------------
    void laporanPendapatan(){

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Financial |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Riwayat Transaksi]---------------------------------------------------------------------------------
    void riwayat(){

        cekPCJikaMasihKosong();
        garis();
        cout << "\n[ GG GAMING CENTER ]" << endl;
        cout << "|  Menu - History  |____________________" << endl;



        kembaliMenuUtama();
    };


//[Main Function - MENU]==================================================================================
    void menuUtama(){
        garis();

        cout << "\n[ SELAMAT DATANG ]" << endl;
        cout << "|   MENU UTAMA   |___________________" << endl;
        cout << "|                                    |" << endl;
        cout << "| 1. Inisialisasi PC (Admin Only)    |" << endl;
        cout << "| 2. Daftar PC Tersedia              |" << endl;
        cout << "| 3. Booking PC (Check in)           |" << endl;
        cout << "| 4. Selesai (Check out)             |" << endl;
        cout << "| 5. Hitung Harga Sewa               |" << endl;
        cout << "| 6. Laporan Pendapatan              |" << endl;
        cout << "| 7. Riwayat Transaksi               |" << endl;
        cout << "| 8. Exit                            |" << endl;
        cout << "|____________________________________|" << endl;
        cout << "Pilih (1-8) : ";
        
        cin >> pilihanMenu;
        cin.ignore();

        switch(pilihanMenu){
            case 1 : 
                inisialisasiPC();
            break;
            case 2 : 
                daftarPC();
            break;
            case 3 : 
                checkIn();
            break;
            case 4 : 
                checkOut();
            break;
            case 5 : 
                hitungHarga();
            break;
            case 6 : 
                laporanPendapatan();
            break;
            case 7 : 
                riwayat();
            break;
            case 8 : 
                garis();
                cout << "\n\t[!] PROGRAM SELESAI - TERIMA KASIH" << endl;
                exit(0);
            break;
            default :
                invalidInput();
            break;
        }
    }

    int main(){

        menuUtama();

        return 0;
    }
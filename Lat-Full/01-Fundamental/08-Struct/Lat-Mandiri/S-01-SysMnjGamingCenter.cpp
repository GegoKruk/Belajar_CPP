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
    int pilihanMenu;

    // const
    const int MAX_JML_PC = 10;
    static int IDXPC = 0;
    int JML_USER_NOW;
    int IDXUSER;

    struct Waktu {
        int jam[MAX_JML_PC];
        int menut[MAX_JML_PC];
    };

    struct DaftarPC {
        int idPC[MAX_JML_PC];
        int tipePC[MAX_JML_PC] {};
        double hargaPC[MAX_JML_PC];
        bool statusPC[MAX_JML_PC];
    };

    struct Transaksi {
        string userName[MAX_JML_PC];
        DaftarPC pcDipilih;
        Waktu waktuMulaiSelesai;
        double tagianUser[MAX_JML_PC];
        int kodeTransaksi[MAX_JML_PC];
    };

//[Helper Function]==================================================================================
    void garis(){
        system("CLS");
        cout << "\n==========[SOAL 1 - SISTEM MANAJEMEN GAMING CENTER]==========" << endl;
    }

    void invalidInput(){
        cout << "\n\t[!] Invalid input - Silakan ulangi " << endl;
        cin.get();
    }

    void kembaliMenuUtama(){
        garis();
        cout << "\n\tTekan [Enter] untuk kembali ke menu : ";
        cin.get();
        menuUtama();
    }

//[Function2 Utama]==================================================================================
    //[Blok Inisialisasi PC & Edit Data PC]---------------------------------------------------------------------------------

    void tambahkanPC(){

        
        DaftarPC tambahDaftarPC;

        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "|   Tambahkan PC   |____________________\n" << endl;
        cout << " - ID PC : " << IDXPC << endl; 
            tambahDaftarPC.idPC[IDXPC] = IDXPC;
        cout << " _____________________________" << endl;
        cout << " | 1. Regular   (Rp10.000)   |" << endl;
        cout << " | 2. VIP       (Rp15.000)   |" << endl;
        cout << " | 3. VVIP      (Rp20.000)   |" << endl;
        cout << " |___________________________|" << endl;
        cout << " - Pilih Tipe PC (1-3) : "; 
            cin >> tambahDaftarPC.tipePC[IDXPC];
        cout << " - Harga Per-Jam : ";
            cin >> tambahDaftarPC.hargaPC[IDXPC];
        
        cin.ignore();
        cin.get();

        IDXPC++;
    }

    void editDataPC(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "|     Edit PC      |____________________" << endl;
    }

    void inisialisasiPC(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "|   Menu - Admin   |____________________" << endl;
        cout << "|                                      |" << endl;
        cout << "| 1. Tambahkan PC                      |" << endl;
        cout << "| 2. Edit Data PC                      |" << endl;
        cout << "| 3. Back                              |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "Pilih (1-3) : ";

        cin >> pilihanMenu;
        cin.ignore();

        switch (pilihanMenu){
        case 1:
            tambahkanPC();
            break;
        case 2:
            editDataPC();
            break;
        case 3:
            menuUtama();
            break;
        default:
            invalidInput();
            inisialisasiPC();
            break;
        }
        kembaliMenuUtama();
    };

    //[Function2 Utama]---------------------------------------------------------------------------------

    void daftarPC(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Daftar PC |____________________" << endl;



        kembaliMenuUtama();
    }; 

    //[Blok Check In]---------------------------------------------------------------------------------

    void checkIn(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "|  Menu - Check In |____________________" << endl;

        // cout << "|                                       " << endl;
        // cout << "|  - ID PC : " << IDXPC << endl;
        // cout << "|  _____________________________________" << endl;
        // cout << "|  | 1. Regular    ->  (Rp10.000/jam)  |" << endl;
        // cout << "|  | 2. VIP        ->  (Rp15.000/jam)  |" << endl;
        // cout << "|  | 3. VVIP       ->  (Rp20.000/jam)  |" << endl;
        // cout << "|  |___________________________________|" << endl;
        // cout << "|  - Pilih Tipe PC (1-3) : ";
        // cout << "\n|  - ";
        // cin >> pilihanMenu;

        // cout << "" << endl;


        kembaliMenuUtama();
    };

    //[Blok Check Out]---------------------------------------------------------------------------------

    void checkOut(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Check Out |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Perhitungan Harga Sewa]---------------------------------------------------------------------------------
    void hitungHarga(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "|   Menu - Harga   |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Laporan Pendapatan]---------------------------------------------------------------------------------
    void laporanPendapatan(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
        cout << "| Menu - Financial |____________________" << endl;



        kembaliMenuUtama();
    };

    //[Blok Riwayat Transaksi]---------------------------------------------------------------------------------
    void riwayat(){
        garis();
        cout << "[ GG GAMING CENTER ]" << endl;
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
                cin.ignore();
                cout << "" << endl;
            break;
        }
    }

    int main(){

        menuUtama();

        return 0;
    }
#include <iostream>
#include <string>
using namespace std;

/*
    S-07: Sistem Portofolio Investasi Emas (Multi-User & Multi-Asset)
    
    Konteks:
        Kamu ingin membuat program untuk mencatat investasi emas beberapa pengguna. 
        Program ini menggunakan Array 2D untuk menyimpan data transaksi selama satu minggu (7 hari).

    Tugas:

        Struktur Data:
            - Gunakan string namaUser[3] untuk menyimpan nama 3 investor.
            - Gunakan double tabunganEmas[3][7] (Array 2D). 
                Baris adalah User, Kolom adalah Hari (Senin-Minggu). 
                Isi datanya adalah jumlah gram emas yang mereka beli setiap harinya.

        Fitur Program:
            - Input Data: 
                Masukkan jumlah beli emas (gram) untuk setiap user selama 7 hari.
            - Statistik Individu: 
                Hitung total akumulasi emas dan rata-rata pembelian per hari untuk setiap user.
            - Ranking Investor (Sorting): 
                Urutkan nama user berdasarkan total emas terbanyak (Gunakan Selection atau Insertion Sort).
            - Hari Terproduktif (Max): 
                Cari di hari ke-berapa (kolom mana) pembelian emas tertinggi terjadi secara global (gabungan semua user).
            - Pencarian (Search): 
                Masukkan angka gram, lalu cari apakah ada user yang pernah membeli emas tepat di angka tersebut. Jika ada, tampilkan nama user dan harinya.

    Kenapa Soal Ini Kompleks?
        Akses 2D: Kamu harus mahir menggunakan nested loop for(i...) { for(j...) }.
        Relasi Data: Saat kamu melakukan sorting pada total emas, kamu juga harus menukar posisi nama di namaUser[] agar data tetap sinkron (tidak tertukar).
        Logika Global: Mencari nilai maksimal di seluruh isi tabel (2D) menuntut ketelitian indeks.

    Tips Implementasi:
        Karena kamu sudah bisa pakai system("CLS") dan switch case, buatlah menu yang interaktif seperti di S-06.
        Gunakan konstanta untuk ukuran array agar mudah diubah, misal: const int JML_USER = 3; dan const int JML_HARI = 7;.

*/

// All Function
    void menuAwal();
    void menuUtama();
    void menuReg();
    void menuLogin();
    void logout();
    void inputPembelian();
    void statistik();
    void ranking();
    void hariProduktif();
    void pencarian();

// User Management
    const int MAX_USER = 5;
    const int JML_HARI = 7;
    int JML_USER_NOW = 0;
    string namaUser[MAX_USER] {};
    int pinUser[MAX_USER] {};
    int indexUserNow;

// Management Emas
    double rataRataSeminggu[MAX_USER];
    double tabunganEmas[MAX_USER][JML_HARI] {};
    double totalTabunganUser[MAX_USER] {};
    double tempTotalTabunganUser;

// Ranking Tabungan
    double rankingTabunganUser[MAX_USER]{};
    string rankingNamaUser[MAX_USER]{};

    double rankingHariProduktif[JML_HARI];
    string rankingNamaHari[JML_HARI] {"[Senin]  ", "[Selasa] ", "[Rabu]   ", "[Kamis]  ", "[Jumat]  ", "[Sabtu]  ", "[Minggu] "};

void garis(){
    system("CLS");
    cout << "\n==========[SOAL 8 - PROGRAM PORTOFOLIO EMAS (INPUT, TOTAL, MAX, MEAN, SORTING, & SEARCHING)]==========" << endl;
}

void cekDataJikaKosong(){
    garis();

    for (int i = 0; i < JML_HARI; i++){
        if(totalTabunganUser[indexUserNow] == 0){
            cout << "\n[!] Data masih kosong. Silakan input terlebih dahulu, pilih (1) di Menu Utama." << endl;
            cout << "\n\tTekan [Enter] untuk kembali ke menu : " << endl;
            cin.get();
            if(cin.get()){
                menuUtama();
            }
        }
    }
}

void kembaliKeMenuUtama(){
    cout << "\n\tTekan [Enter] untuk ke menu utama : " << endl;
    cin.get();
        menuUtama();
}

void kembaliKeMenuAwal(){
    cout << "\n\tTekan [Enter] untuk kembali : " << endl;
    cin.get();
        menuAwal();
}

//--------------------------------------------------------------------------------------------------

void menuReg(){
    garis();
    cout << "\n[REGISTRATION - PROGRAM PORTOFOLIO EMAS]_________________" << endl;

    cout << "1. Masukkan Nama Akun Anda                : ";
    string namaUserInput;
    cin >> namaUserInput;
    cin.ignore();

    if (JML_USER_NOW >= MAX_USER){
        cout << "\n[!] Total User terdaftar telah mencapai batas maksimal. Silakan coba lagi nanti." << endl;
        cin.get();
        kembaliKeMenuAwal();
    }

    for (int i = 0; i < MAX_USER; i++){
        if(namaUserInput == namaUser[i]){
            cout << "\n[!] Data Nama sudah terdaftar di index (" << i << "). Silakan gunakan nama lain." << endl;
            kembaliKeMenuAwal();
        } else if (namaUser[i] != ""){
            continue;
        } else if (namaUser[i] == ""){
            namaUser[i] = namaUserInput;
            
            cout << "2. Masukkan PIN Akun Anda (6 Digit Angka) : ";
            int pin;
            cin >> pin;
            cin.ignore();
            pinUser[i] = pin;

            cout << "\n--------------------------------------------------------------------" << endl;

            cout << "\n[REGISTRATION BERHASIL] Data Nama telah terdaftar." << endl;
            cout << "Selamat Datang \""  << namaUser[i] << "\" di Program Portofolio Emas Digital" << endl;

            JML_USER_NOW++;
            break;
        }
    }
    kembaliKeMenuAwal();
};


void menuLogin(){
    garis();
    cout << "\n[LOGIN - PROGRAM PORTOFOLIO EMAS]_________________" << endl;

    cout << "1. Masukkan Nama Akun Anda                : ";
    
    bool ketemu = false;
    indexUserNow = 0;

    string namaUserInput;
    cin >> namaUserInput;
    cin.ignore();

    for (int i = 0; i < JML_USER_NOW; i++){
        if (namaUserInput == namaUser[i]){
            cout << "2. Masukkan PIN Akun Anda (6 Digit Angka) : ";
            int pin;
            cin >> pin;
            cin.ignore();

            if(pin == pinUser[i]){
                indexUserNow = i;
                ketemu = true;
                break;
            } else{
                cout << "\n[LOGIN GAGAL] PIN salah, silakan coba lagi";
                kembaliKeMenuAwal();
            }
        } else {
            continue;
        }
    }

    if(ketemu){
        cout << "\n[LOGIN BERHASIL] Data Akun ditemukan." << endl;
        cout << "Selamat Datang \""  << namaUserInput << "\" di Program Portofolio Emas Digital" << endl;
        kembaliKeMenuUtama();
    } else {
        cout << "\n[LOGIN GAGAL] Nama Akun tidak ditemukan, silakan coba lagi";
        kembaliKeMenuAwal();
    }
}


void logout(){
    garis();
    cout << "\n[LOGOUT - PROGRAM PORTOFOLIO EMAS]_________________" << endl;
    cout << "Anda yakin ingin Logout? (Y/N) : ";
    char pilihan;
    cin >> pilihan;
    if (pilihan == 'y' || pilihan == 'Y'){
        cout << "\n[LOGOUT BERHASIL]";
        kembaliKeMenuAwal();
    } else {
        kembaliKeMenuUtama();
    }
};


void inputPembelian(){
    garis();
    cout << "\n[Input Data Pembelian Emas]_________________" << endl;

    cout << "1. Profil Lengkap Akun : " << endl;
    cout << "\ta. Nama : " << namaUser[indexUserNow] << endl;

    cout << "\n2. Masukkan data pembelian emas (1 Minggu) : " << endl;
    for (int i = 0; i < JML_HARI; i++){
        cout << "\t- Hari ke-" << i + 1 << " (gram) : ";
        cin >> tabunganEmas[indexUserNow][i];
        cin.ignore();
    }

    tempTotalTabunganUser = 0;
    for (int i = 0; i < JML_HARI; i++){
        tempTotalTabunganUser += tabunganEmas[indexUserNow][i];
    }

    totalTabunganUser[indexUserNow] = tempTotalTabunganUser;

    cout << "\n3. Total pembelian Anda selama 1 Minggu : " << totalTabunganUser[indexUserNow] << endl;
    
    kembaliKeMenuUtama();
};


void statistik(){
    garis();
    cekDataJikaKosong();

    cout << "\n[Statistik Pembelian Emas]_________________" << endl;

    cout << "1. Profil Lengkap Akun : " << endl;
    cout << "\ta. Nama : " << namaUser[indexUserNow] << endl;

    cout << "\n2. Data Lengkap Pembelian Emas : " << endl;
    for (int i = 0; i < JML_HARI; i++){
        cout << "\t- Hari ke-" << i + 1 << " (gram) : " << tabunganEmas[indexUserNow][i] << endl;
    }
    
    int hariKe = 0;
    double hariBeliTerbanyak = tabunganEmas[indexUserNow][0];
    for (int i = 0; i < JML_HARI; i++){
        if(tabunganEmas[indexUserNow][i] > hariBeliTerbanyak){
            hariBeliTerbanyak = tabunganEmas[indexUserNow][i];
            hariKe = i;
        }
    }
    cout << "\n3. Hari dengan pembelian terbanyak : "<< endl;
    cout << "\tHari ke-" << hariKe + 1 << " dengan jumlah " << hariBeliTerbanyak << " gram" << endl;
    
    hariKe = 0;
    double hariBeliTerendah = tabunganEmas[indexUserNow][0];
    for (int i = 0; i < JML_HARI; i++){
        if(tabunganEmas[indexUserNow][i] < hariBeliTerendah){
            hariBeliTerendah = tabunganEmas[indexUserNow][i];
            hariKe = i;
        }
    }
    cout << "\n4. Hari dengan pembelian terendah : " << endl;
    cout << "\tHari ke-" << hariKe + 1 << " dengan jumlah " << hariBeliTerendah << " gram" << endl;

    rataRataSeminggu[indexUserNow] = totalTabunganUser[indexUserNow] / JML_HARI;

    cout << "\n5. Rata-rata pembelian Anda per-hari : " << totalTabunganUser[indexUserNow] << " gram / " << JML_HARI << " Hari"<< endl;
    cout << "                                     : " << rataRataSeminggu[indexUserNow] << " gram / hari" << endl;

    kembaliKeMenuUtama();
};


void ranking(){
    garis();
    cekDataJikaKosong();

    cout << "\n[Statistik Pembelian Emas]_________________" << endl;

    cout << "1. Profil Lengkap Akun : " << endl;
    cout << "\ta. Nama : " << namaUser[indexUserNow] << endl;

    cout << "\n2. Ranking Seluruh Investor : " << endl;
    if (JML_USER_NOW > 1){
        
        double totalTabunganSeluruhUser = 0;
        for (int i = 0; i < JML_USER_NOW; i++){
            if (i == indexUserNow){
                continue;
            } else {
                totalTabunganSeluruhUser += totalTabunganUser[i];
            }
        }

        for (int i = 0; i < JML_USER_NOW; i++){
            rankingTabunganUser[i] = totalTabunganUser[i];

            rankingNamaUser[i] = namaUser[i];
        }

        if (totalTabunganSeluruhUser != 0){
            for (int i = 0; i < JML_USER_NOW; i++){
                for (int j = 0; j < JML_USER_NOW - 1 - i; j++){
                    if (rankingTabunganUser[j] < rankingTabunganUser[j+1]){

                        double tempTabungan = rankingTabunganUser[j+1];
                        rankingTabunganUser[j+1] = rankingTabunganUser[j];
                        rankingTabunganUser[j] = tempTabungan;

                        string tempUsername = rankingNamaUser[j+1];
                        rankingNamaUser[j+1] = rankingNamaUser[j];
                        rankingNamaUser[j] = tempUsername;
                    }
                }
            }
            for (int k = 0; k < JML_USER_NOW; k++){
                cout << "\n\t- Rank ke-" << k+1 << "                  : " << rankingNamaUser[k] << endl;
                cout << "\t  Total tabungan emas (gram) : " << rankingTabunganUser[k] << endl;
            }
        } else {
            cout << "\n\t- Rank ke-1                  : " << namaUser[indexUserNow] << endl;
            cout << "\t  Total tabungan emas (gram) : " << totalTabunganUser[indexUserNow] << endl;
        }

    } else {
        cout << "\n\t[!] Jumlah Investor hanya ada 1, Anda berada di rank 1" << endl;
    }
    kembaliKeMenuUtama();
};


void hariProduktif(){
    garis();
    cekDataJikaKosong();

    cout << "\n[Data Hari Pembelian Emas]_________________" << endl;

    for (int i = 0; i < JML_HARI; i++){
        double tempJmlPerhari = 0;
        for (int j = 0; j < JML_USER_NOW; j++){
            tempJmlPerhari += tabunganEmas[j][i];
        }
        rankingHariProduktif[i] = tempJmlPerhari;
    }

    for (int i = 0; i < JML_HARI; i++){
        for (int j = 0; j < JML_HARI - 1 - i; j++){
            if(rankingHariProduktif[j] < rankingHariProduktif[j+1]){
                double temp = rankingHariProduktif[j+1];
                rankingHariProduktif[j+1] = rankingHariProduktif[j];
                rankingHariProduktif[j] = temp;
                
                string tempNamaHari = rankingNamaHari[j+1];
                rankingNamaHari[j+1] = rankingNamaHari[j];
                rankingNamaHari[j] = tempNamaHari;
            }
        }
    }

    cout << "1. Data Lengkap Ranking Hari Terproduktif : ";
    for (int i = 0; i < JML_HARI; i++){
        cout << "\n\t- Hari ke-" << i+1 << " " << rankingNamaHari[i] << " : " << rankingHariProduktif[i] << " gram" << endl;
        
        double rataRata = 0;
        rataRata = rankingHariProduktif[i] / JML_USER_NOW;
        cout << "\t  Rata-rata pembelian : " << rataRata << " gram" << endl;
    }
    kembaliKeMenuUtama();
};


void pencarian(){
    garis();
    cekDataJikaKosong();

    cout << "\n[Pencarian Pembelian Emas]_________________" << endl;
    cout << "| 1. Cari dengan hari                     |" << endl;
    cout << "| 2. Cari nominal pembelian               |" << endl;
    cout << "| 3. Kembali                              |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << "Pilih : ";

    int pilihan;
    cin >> pilihan;
    switch(pilihan){
        case 1 : {
                cout << "\n[Pencarian Pembelian Emas]_________________" << endl;
                cout << "1. Masukkan hari (1-7) : ";
                int hariDicari;
                cin >> hariDicari;
                cin.ignore();

                bool ketemu = false;
                for (int i = 1; i <= JML_HARI; i++){
                    if (i == hariDicari){
                        ketemu = true;
                        cout << "\n[PENCARIAN BERHASIL] Data Ditemukan" << endl; 
                        cout << "[Hari ke-"<<i<<"] Anda membeli emas sebanyak : " << tabunganEmas[indexUserNow][i-1] << " gram" << endl;
                    }
                }
                if(!ketemu){
                    cout << "\n[PENCARIAN GAGAL] Data Tidak Ditemukan" << endl; 
                }
            }
            kembaliKeMenuUtama();
            break;
        case 2 : {
                cout << "\n[Pencarian Pembelian Emas]_________________" << endl;
                cout << "1. Masukkan Nominal Pembelian (gram) : ";
                double nominalDicari;
                cin >> nominalDicari;
                cin.ignore();

                bool ketemu = false;
                for (int i = 0; i < JML_HARI; i++){
                    if (tabunganEmas[indexUserNow][i] == nominalDicari){
                        ketemu = true;
                        cout << "\n[PENCARIAN BERHASIL] Data Ditemukan" << endl; 
                        cout << "[Hari ke-"<<i+1<<"] Anda membeli emas sebanyak : " << tabunganEmas[indexUserNow][i] << " gram" << endl;
                    }
                }

                if(!ketemu){
                    cout << "\n[PENCARIAN GAGAL] Data Tidak Ditemukan" << endl; 
                }
            }
            kembaliKeMenuUtama();
            break;
        default : kembaliKeMenuUtama();
            break;
    }
};


void menuUtama(){
    
    garis();
    cout << "\n[PROGRAM PORTOFOLIO EMAS]_________________" << endl;
    cout << "| 1. Input Data Pembelian                 |" << endl;
    cout << "| 2. Statistik User                       |" << endl;
    cout << "| 3. Ranking Investor                     |" << endl;
    cout << "| 4. Hari Terproduktif                    |" << endl;
    cout << "| 5. Percarian Pembelian                  |" << endl;
    cout << "| 6. Logout                               |" << endl;
    cout << "|_________________________________________|" << endl;
    cout << "Pilih : ";

    int pilihanMenuUtama;
    cin >> pilihanMenuUtama;
    cin.ignore();

    switch(pilihanMenuUtama){
        case 1 : inputPembelian();
            break;
        case 2 : statistik();
            break;
        case 3 : ranking();
            break;
        case 4 : hariProduktif();
            break;
        case 5 : pencarian();
            break;
        case 6 : logout();
            break;
        default: 
                cout << "\n\t[!] Pilihan tidak valid! Silakan masukkan angka 1-6." << endl;
                kembaliKeMenuUtama();
            break;
    }
};


void menuAwal(){;
    garis();
    cout << "\n[PROGRAM PORTOFOLIO EMAS]_________________" << endl;
    cout << "| 1. Login                                |" << endl;
    cout << "| 2. Registration                         |" << endl;
    cout << "| 3. Exit                                 |" << endl;
    cout << "|_________________________________________|" << endl;

    int pilihanMenuAwal;
    cout << "Pilih : ";
    cin >> pilihanMenuAwal;
    cin.ignore();

    switch(pilihanMenuAwal){
        case 1 : menuLogin();
            break;
        case 2 : menuReg();
            break;
        case 3 : {
                cout << "\n---> [Program Selesai] - Sampai Jumpa Lagi!" << endl;
                exit(0);
            }
            break;
        default : 
                cout << "\n\t[!] Pilihan tidak valid! Silakan masukkan angka 1-3." << endl;
                kembaliKeMenuAwal();
            break;
    }
};


int main(){
    menuAwal();
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struct
    struct AtributSihir {
        int Teori;
        int Praktek;
        int Level_Fokus;
    };

    struct Siswa {
        int ID;
        string Nama;
        string Asrama;
        AtributSihir Statistik;
    };

// Variabel Global
    const int MAX_SISWA = 100;
    Siswa arraySiswa[MAX_SISWA];
    int jumlah_siswa = 0;

// Function Prototype 
    // Function FILE
        void initData();          
        void saveAppendData();    
        void saveOverwriteData(); 

    // Function Searching 
        int Hitung_Bonus(int fokus);

    // Function Rekursi
        int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari);

    // Function Pointer dan Sorting (Quick Sort)
        void swapData(Siswa *a, Siswa *b);
        int partition(Siswa arr[], int low, int high);
        void quickSort(Siswa arr[], int low, int high);

    // Function SubMenu 
        void tambahData();
        void lihatData();
        void hapusData();
        void cetakLaporan();
    
// Function Helper
    void namaKelas(){
        cout << "\n\t\t================================" << endl;
        cout << "\t\t||    Nama : Gega Ramadhan    ||" << endl;
        cout << "\t\t||    NIM  : 123250112        ||" << endl;
        cout << "\t\t||    Plug : IF-E             ||" << endl;
        cout << "\t\t================================\n\n" << endl;
    }

    void headerMenu(string judulMenu){
        system("CLS");
        namaKelas();
        cout << "===============[ " << judulMenu << " ]===============" << endl;
    }

    void garis(){
        cout << "--------------------------------------------------" << endl;
    }

    void jeda() {
        cout << "\n\t    Tekan Enter untuk lanjut...";
        cin.get();
    }


// Function Main
int main() {
    system("color 03");
    initData(); 
    int pilihan;

    do {
        headerMenu("SISTEM MANAJEMEN AKADEMI SIHIR");

        cout << "\n [1] Tambah Data Siswa\n";
        cout << " [2] Lihat Data Siswa\n";
        cout << " [3] Hapus Data Siswa\n";
        cout << " [4] Cetak Laporan Kelas Remedial\n";
        cout << " [0] Keluar\n\n";
        cout << " Pilih menu: ";

        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
        case 1: 
            tambahData(); 
            break;
        case 2: 
            lihatData(); 
            break;
        case 3: 
            hapusData(); 
            break;
        case 4: 
            cetakLaporan(); 
            break;
        case 0: 
            cout << "\n\t    Program Selesai - Sampai Jumpa Lagi"; 
            break;
        default: 
            cout << "\n\t[!] Pilihan tidak valid - Silakan coba lagi...";
        }
    } while (pilihan != 0);
        
    return 0;
}

//Function2 FILE
void initData() {
    ifstream bacaFile("data_siswa.txt");

    if(!bacaFile.is_open()){
        jumlah_siswa = 0;
        return;
    }

    char koma;
    char karakter;

    while(bacaFile >> arraySiswa[jumlah_siswa].ID >> koma){

        string tempNama = "";
        while(bacaFile.get(karakter) && karakter != ','){
            tempNama += karakter;
        }
        arraySiswa[jumlah_siswa].Nama = tempNama;

        string tempAsrama = "";
        while(bacaFile.get(karakter) && karakter != ','){
            tempAsrama += karakter;
        }
        arraySiswa[jumlah_siswa].Asrama = tempAsrama;

        bacaFile >> arraySiswa[jumlah_siswa].Statistik.Teori >> koma;
        bacaFile >> arraySiswa[jumlah_siswa].Statistik.Praktek >> koma;
        bacaFile >> arraySiswa[jumlah_siswa].Statistik.Level_Fokus;

        bacaFile.ignore();
        jumlah_siswa++;
    }
}

void saveAppendData() {
    ofstream saveFile("data_siswa.txt", ios::app);
    if(!saveFile.is_open()){
        cout << "\n\t[!] File Gagal Dibuat/Ditulis" << endl;
        return;
    }

    saveFile << arraySiswa[jumlah_siswa].ID << "," 
            << arraySiswa[jumlah_siswa].Nama << ","
            << arraySiswa[jumlah_siswa].Asrama << ","
            << arraySiswa[jumlah_siswa].Statistik.Teori << ","
            << arraySiswa[jumlah_siswa].Statistik.Praktek << ","
            << arraySiswa[jumlah_siswa].Statistik.Level_Fokus << endl;

    saveFile.close();
}

void saveOverwriteData() {
    ofstream saveTimpa("data_siswa.txt");

    if(!saveTimpa.is_open()){
        cout << "\n\t[!] File Gagal Dibuat/Ditulis" << endl;
        return;
    }

    for (int i = 0; i < jumlah_siswa; i++){
        saveTimpa << arraySiswa[i].ID << ","
                    << arraySiswa[i].Nama << ","
                    << arraySiswa[i].Asrama << ","
                    << arraySiswa[i].Statistik.Teori << ","
                    << arraySiswa[i].Statistik.Praktek << ","
                    << arraySiswa[i].Statistik.Level_Fokus << endl;
    }
    
    saveTimpa.close();
}

// Function Rekursi
int Hitung_Bonus(int fokus) {
    if (fokus == 0){
        return 0;
    } 
    
    return (fokus * 10) + Hitung_Bonus(fokus - 1);
}

// Function Searching
int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari) {

    while(kiri <= kanan){

        int mid = (kiri + kanan) / 2;
        
        if(arr[mid].ID == id_cari){

            return mid;

        } else if (id_cari < arr[mid].ID){
            kanan = mid - 1; 
        } else if (id_cari > arr[mid].ID){
            kiri = mid + 1; 
        }
    }
    
    cout << "\n\t[!] ID SISWA TIDAK DITEMUKAN" << endl;
    return -1;
}

// Function Sorting
void swapData(Siswa *a, Siswa *b){
    Siswa temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Siswa arr[], int low, int high){
    int pivot = arr[high].ID;
    int i = (low - 1);

    for (int j = low; j < high; j++){
        if(arr[j].ID <= pivot){
            i++;
            swapData(&arr[i], &arr[j]);
        }
    }
    
    swapData(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(Siswa arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function Validasi Input ID, Nama, Nilai
int cekIDdanNama(Siswa arr[], int jml_siswa, int id, string nama){
    for (int i = 0; i < jml_siswa; i++){
        if (arr[i].ID == id){
            cout << "\n\t[!] ID Telah Terdaftar" << endl;
            return 1;
        } else if (arr[i].Nama == nama){
            cout << "\n\t[!] Nama Telah Terdaftar dengan ID : " << arr[i].ID << endl;
            return 1;
        }
    }

    return 0;
}

int validasiNilai(int nilai = 0, int fokus = 0){
    if (nilai < 0 || nilai > 100){
        cout << "\n\t[!] Nilai Harus Sebesar 1-100" << endl;
        return 1;
    } else if (fokus < 0 || fokus > 5){
        cout << "\n\t[!] Nilai Harus Sebesar 1-5" << endl;
        return 1;
    }

    return 0;
}

// Function Sub-Menu
void tambahData(){
    
    headerMenu("TAMBAH DATA SISWA");

    // Validasi Kapaasitas Dulu
    if(jumlah_siswa > MAX_SISWA){
        cout << "\n\t[!] JUMLAH DATA SISWA MENCAPAI BATAS MAKSIMAL";
        jeda();
        return;
    }
    
    int id;
    string nama;
    string asrama;
    int nilaiTeori;
    int nilaiPraktek;
    int levelFokus;

    // Input Ke variabel + cek apakah valid
    cout << "\n Masukkan Data Siswa" << endl;
    cout << " [1] ID          : ";
    cin >> id;
    cin.ignore();

    cout << " [2] Nama        : ";
    getline(cin, nama);

    // Panggil Funtion Validasi nama dan id
    if(cekIDdanNama(arraySiswa, jumlah_siswa, id, nama) == 1){
        jeda();
        return;
    }

    cout << " [3] Asrama      : ";
    cin >> asrama;
    cin.ignore();

    cout << " [4] Teori       : ";
    cin >> nilaiTeori;
    cin.ignore();
    if (validasiNilai(nilaiTeori) == 1){
        jeda();
        return;
    } 
    
    cout << " [5] Praktek     : ";
    cin >> nilaiPraktek;
    cin.ignore();
    if (validasiNilai(nilaiPraktek) == 1){
        jeda();
        return;
    } 
    
    cout << " [6] Level Fokus : ";
    cin >> levelFokus;
    cin.ignore();
    if (validasiNilai(0,levelFokus) == 1){
        jeda();
        return;
    } 
    
    // Input ke array
    arraySiswa[jumlah_siswa].ID = id;
    arraySiswa[jumlah_siswa].Nama = nama;
    arraySiswa[jumlah_siswa].Asrama = asrama;
    arraySiswa[jumlah_siswa].Statistik.Teori = nilaiTeori;
    arraySiswa[jumlah_siswa].Statistik.Praktek = nilaiPraktek;
    arraySiswa[jumlah_siswa].Statistik.Level_Fokus = levelFokus;

    // Panggil Function Save ke File
    saveAppendData();

    cout << "\n\t    [DATA BERHASIL DITAMBAHKAN]" << endl;

    jumlah_siswa++;
    jeda();
}

void lihatData(){
    headerMenu("TAMPILKAN DATA SISWA");
    if (jumlah_siswa == 0){
        cout << "\n\t[!] DATA MASIH KOSONG - Input dulu datanya...";
        jeda();
        return;
    }

    // Manggil Quick Sort
    quickSort(arraySiswa, 0, jumlah_siswa-1);

    // Perulangan untuk tampilan data dan perhitungan Mana
    for (int i = 0; i < jumlah_siswa; i++){

        int hasilHitungFokus = Hitung_Bonus(arraySiswa[i].Statistik.Level_Fokus);
        int totalMana = arraySiswa[i].Statistik.Teori + arraySiswa[i].Statistik.Praktek + hasilHitungFokus;

        cout << "\n [DATA SISWA " << i+1 << "]---------------------------------------" << endl;
        cout << " [1] ID            : " << arraySiswa[i].ID << endl;
        cout << " [2] Nama          : " << arraySiswa[i].Nama << endl;
        cout << " [3] Asrama        : " << arraySiswa[i].Asrama << endl;
        cout << " [4] Nilai Teori   : " << arraySiswa[i].Statistik.Teori << endl;
        cout << " [5] Nilai Praktek : " << arraySiswa[i].Statistik.Praktek << endl;
        cout << " [6] Level Fokus   : " << arraySiswa[i].Statistik.Level_Fokus << endl;
        cout << " [7] Total Mana    : " << totalMana << endl;
    }

    cout << " -----------------------------------------------------" << endl;
    cout << "\n\t[!] SEMUA DATA TELAH DITAMPILKAN" << endl;
    
    jeda();
}

void hapusData() {
    char pilihan;

    do {
        headerMenu("HAPUS DATA SISWA");
        if (jumlah_siswa == 0){
            cout << "\n\t[!] DATA MASIH KOSONG - Input dulu datanya...";
            jeda();
            return;
        }

        // Manggil Quick Sort
        quickSort(arraySiswa, 0, jumlah_siswa-1);

        cout << "\n Masukkan ID Siswa : ";
        int idDicari = 0;
        cin >> idDicari;
        cin.ignore();
    
        // Panggil Binary Search
        int posisiKetemu = binarySearch(arraySiswa, 0, jumlah_siswa - 1, idDicari);
    
        if(posisiKetemu != -1){
            for (int i = posisiKetemu; i < jumlah_siswa - 1; i++){
                arraySiswa[i] = arraySiswa[i+1];
            }

            jumlah_siswa--;
            saveOverwriteData();
            cout << "\n\t[SUKSES] DATA ID \""<< idDicari <<"\" TELAH DIHAPUS" << endl;
        }
    
    
        // Menampilkan Pilihan
        cout << "\n Hapus Data Lainnya? [Y/N] : ";
        cin >> pilihan;
        cin.ignore();

    } while (pilihan == 'Y' || pilihan == 'y');

    jeda();
}

void cetakLaporan() {
    headerMenu("CETAK LAPORAN SISWA");
    if (jumlah_siswa == 0){
        cout << "\n\t[!] DATA MASIH KOSONG - Input dulu datanya...";
        jeda();
        return;
    }

    ofstream fileLaporan("kelas_remidial.txt");
    if(!fileLaporan.is_open()){
        cout << "\n\t[!] File Gagal Dibuat/Ditulis" << endl;
        return;
    }


    // Panggil Quick Sort
    quickSort(arraySiswa, 0, jumlah_siswa - 1);

    // Perulangan untuk menhitung mana sekaligus menulis yang dibawah 150/remedial
    for (int i = 0; i < jumlah_siswa; i++){
        int hasilHitungFokus = Hitung_Bonus(arraySiswa[i].Statistik.Level_Fokus);
        int totalMana = arraySiswa[i].Statistik.Teori + arraySiswa[i].Statistik.Praktek + hasilHitungFokus;

        if (totalMana < 150){
            fileLaporan << arraySiswa[i].ID << ","
                        << arraySiswa[i].Nama << ","
                        << arraySiswa[i].Asrama << ","
                        << arraySiswa[i].Statistik.Teori << ","
                        << arraySiswa[i].Statistik.Praktek << ","
                        << arraySiswa[i].Statistik.Level_Fokus << ","
                        << totalMana << endl;
        }
    }

    fileLaporan.close();

    cout << "\n\t[SUKSES] File kelas_remidial.txt Berhasil Dicetak!" << endl;
    jeda();
}
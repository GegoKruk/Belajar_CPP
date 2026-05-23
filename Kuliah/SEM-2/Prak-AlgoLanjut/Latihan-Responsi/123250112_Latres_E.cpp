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
        void initData();          // Dijalankan HANYA DI AWAL saat program pertama kali dibuka
        void saveAppendData();    // Digunakan khusus untuk menu Tambah Data (ios::app)
        void saveOverwriteData(); // Digunakan khusus untuk menu Hapus Data (overwrite)

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
    initData(); 
    int pilihan;

    do {
        headerMenu("SISTEM MANAJEMEN AKADEMI SIHIR");

        cout << " [1] Tambah Data Siswa\n";
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

}

// Function Rekursi
int Hitung_Bonus(int fokus) {

    return 0; 
}

// Function Searching
int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari) {

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

// Function Sub-Menu
void tambahData(){
    
    headerMenu("TAMBAH DATA SISWA");

    // Validasi Kapaasitas Dulu
    if(jumlah_siswa > MAX_SISWA){
        cout << "\n\t[!] JUMLAH DATA SISWA MENCAPAI BATAS MAKSIMAL";
        jeda();
        return;
    }

    // Input Ke Array & Struct
    cout << " Masukkan Data Siswa" << endl;
    cout << " [1] ID          : ";
    cin >> arraySiswa[jumlah_siswa].ID;
    cin.ignore();

    cout << " [2] Nama        : ";
    getline(cin, arraySiswa[jumlah_siswa].Nama);

    cout << " [3] Asrama      : ";
    cin >> arraySiswa[jumlah_siswa].Asrama;
    cin.ignore();

    cout << " [4] Teori       : ";
    cin >> arraySiswa[jumlah_siswa].Statistik.Teori;
    cin.ignore();

    cout << " [5] Praktek     : ";
    cin >> arraySiswa[jumlah_siswa].Statistik.Praktek;
    cin.ignore();

    cout << " [6] Level Fokus : ";
    cin >> arraySiswa[jumlah_siswa].Statistik.Level_Fokus;
    cin.ignore();

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

    jeda();
}

void hapusData() {
    headerMenu("HAPUS DATA SISWA");
    if (jumlah_siswa == 0){
        cout << "\n\t[!] DATA MASIH KOSONG - Input dulu datanya...";
        jeda();
        return;
    }



    jeda();
}

void cetakLaporan() {
    headerMenu("CETAK LAPORAN SISWA");
    if (jumlah_siswa == 0){
        cout << "\n\t[!] DATA MASIH KOSONG - Input dulu datanya...";
        jeda();
        return;
    }



    jeda();
}
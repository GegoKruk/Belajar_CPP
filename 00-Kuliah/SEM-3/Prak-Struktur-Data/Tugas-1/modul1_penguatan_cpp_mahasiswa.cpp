#include <iostream> 
#include <string> 
using namespace std; 

// Function Helper Visual 
    void judulNama(){
        system("color 03");
        system("cls");
        
        cout << "\t============================================" << endl;
        cout << "\t||   MODUL 1 - Praktikum Struktur Data    ||" << endl;
        cout << "\t||   __________________________________   ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t||          Nama  : Gega Ramadhan         ||" << endl;
        cout << "\t||          NIM   : 1231250112            ||" << endl;
        cout << "\t||          Kelas : IF-D                  ||" << endl;
        cout << "\t||                                        ||" << endl;
        cout << "\t============================================\n\n" << endl;
    }

    void judulMenu(string judul){
        judulNama();
        cout << "==========[" << judul <<"]==========" << endl;
    }

    void garis(){
        cout << "--------------------------------------------------" << endl;
    }

    void jeda() {
        cout << "\n\t    Tekan Enter untuk lanjut...";
        cin.get();
    }

// Global Variable  &Deklarasi 
    const int KAPASITAS = 10; 
    int COUNTER_DATA = 0; 

    struct Mahasiswa { 
        string nim; 
        string nama; 
        double ipk; 
    }; 

    struct DataMahasiswa { 
        Mahasiswa data[KAPASITAS]; 
        int jumlah; 
    }; 

// Function Prototype
    // Function Logic
    void init(DataMahasiswa &daftar); 
    bool tambahMahasiswa(DataMahasiswa &daftar, const Mahasiswa &mhs); 
    void tampilkan(const DataMahasiswa &daftar); 
    void tampilkanSatuan(const DataMahasiswa &daftar, int index);
    int cariNim(const DataMahasiswa &daftar, const string &nim); 
    bool ubahIpk(DataMahasiswa &daftar, const string &nim, double ipkBaru); 

    // Function Display
    void menu1(DataMahasiswa &daftar);
    void menu2(const DataMahasiswa &daftar);
    void menu3(const DataMahasiswa &daftar);
    void menu4(DataMahasiswa &daftar);
    void menu5(const DataMahasiswa &daftar);

// Main Function
    int main() { 
        DataMahasiswa daftar; 
        init(daftar); 
        int pilihanMenu; 
        do {
            judulNama();
            cout << "=================[ Menu Utama ]================" << endl;
            cout << "|                                             |" << endl;
            cout << "| [1] Tambahkan Data Mahasiswa                |" << endl;
            cout << "| [2] Tampilkan Data Mahasiswa                |" << endl;
            cout << "| [3] Cari Mahasiswa Berdasarkan NIM          |" << endl;
            cout << "| [4] Ubah IPK Mahasiswa                      |" << endl;
            cout << "| [5] Jumlah Mahasiswa                        |" << endl;
            cout << "| [6] Keluar                                  |" << endl;
            cout << "|                                             |" << endl;
            cout << "===============================================" << endl;
            cout << "\n > Pilih [1-5] : ";
            cin >> pilihanMenu; 
            cin.ignore();
                
                switch (pilihanMenu){
                    case 1:
                        menu1(daftar);
                        break;
                    case 2:
                        menu2(daftar);
                        break;
                    case 3:
                        menu3(daftar);
                        break;
                    case 4:
                        menu4(daftar);
                        break;
                    case 5:
                        menu5(daftar);
                        break;
                    case 6:
                        judulNama();
                        cout << "\n\t    [Program Selesai] - Terima Kasih" << endl;
                        break;
                    default:
                        cout << "\n\t    [ERROR] - Input Tidak Valid" << endl;
                        jeda();
                        break;
                }
        } while (pilihanMenu != 6); 
        return 0; 
    }

// Function Helper Logic
    void init(DataMahasiswa &daftar) { 
        daftar.jumlah = 0; 
    } 
    
    bool tambahMahasiswa(DataMahasiswa &daftar, const Mahasiswa &mhs) { 
        return true; 
    } 
    
    void tampilkan(const DataMahasiswa &daftar) { 
    }

    void tampilkanSatuan(const DataMahasiswa &daftar, int index) { 
    }

    int cariNim(const DataMahasiswa &daftar, const string &nim) { 
        return -1; 
    } 
    
    bool ubahIpk(DataMahasiswa &daftar, const string &nim, double ipkBaru) { 
        return true; 
    }
    

// Function Display
    void menu1(DataMahasiswa &daftar){
        char ulang;
        Mahasiswa tempMhsBaru;
        do{
            judulMenu("Tambahkan Data Mahasiswa");

            if (daftar.jumlah == KAPASITAS){
                cout << "\n\t [KESALAHAN] Data Mahasiswa Penuh" << endl;
                jeda();
                return;
            }

            cout << "\n Tambah Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu2(const DataMahasiswa &daftar){
        judulMenu("Tampilkan Data Mahasiswa");
        if (daftar.jumlah == 0){
            cout << "\n\t [KESALAHAN] Data Mahasiswa Masih Kosong" << endl;
            jeda();
            return;
        }

        jeda();
    }

    void menu3(const DataMahasiswa &daftar){
        char ulang;
        do{
            judulMenu("Cari Mahasiswa Berdasarkan NIM");
            if (daftar.jumlah == 0){
                cout << "\n\t [KESALAHAN] Data Mahasiswa Masih Kosong" << endl;
                jeda();
                return;
            }
            
            cout << "\n Cari Data Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu4(DataMahasiswa &daftar){
        char ulang;
        do{
            judulMenu("Ubah IPK Mahasiswa");
            if (daftar.jumlah == 0){
                cout << "\n\t [KESALAHAN] Data Mahasiswa Masih Kosong" << endl;
                jeda();
                return;
            }
            
            cout << "\n Ubah Data IPK Lainnya? [Y/N] : ";
            cin >> ulang;
            cin.ignore();  
        } while (ulang == 'y' || ulang == 'Y');
    }

    void menu5(const DataMahasiswa &daftar){
        judulMenu("Jumlah Mahasiswa");
        if (daftar.jumlah == 0){
            cout << "\n\t [KESALAHAN] Data Mahasiswa Masih Kosong" << endl;
            jeda();
            return;
        }

        jeda();
    }

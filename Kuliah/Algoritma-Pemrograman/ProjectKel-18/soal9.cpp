#include <iostream>
using namespace std;

// Soal 9
/*
    Buatlah program C++, untuk menghitung Luas bangun datar dan Volume bangun ruang. 
    Program ketika dirunning, pertama kali menanyakan ingin menghitung bangun datar atau bangun ruang. 
    Jika memilih bangun datar, proses selanjutnya menghitung luas bangun datar yang dipilih. 
    Jika memilih bangun ruang, proses selanjutnya menghitung volume bangun datar yang dipilih. 
    
*/

// Kebutuhan Soal 9
/*
    Berikut rumus Luas dan rumus Volume :
    1.  Bangun Datar    |  Rumus Datar
        ----------------------------------------
        Persegi            Ls = s x s
        Persegi Panjang    Ls = p x l
        Segitiga           Ls = ½ x a x t
        Lingkaran          V = π x r2
        Jajar Genjang      Ls = a x t
        Belah Ketupat      Ls = ½ x d1 x d2
        Layang-layang      Ls = ½ x d1 x d2
        Trapesium          Ls = ½ x (a1 + a2) x t
        

    2.  Bangun Ruang    |  Rumus Ruang
        -----------------------------------------
        Kubus              V = s x s x s
        Balok              V = p x l x t
        Tabung             V = π x r2 x t
        Bola               V = 4/3 x π x r3
        Kerucut            V = 1/3 x π x r2 x t
        Limas Segitiga     V = 1/3 x luas segitiga x t
        Limas Seempat      V = 1/3 x p x l x t
        Prisma Segitiga    V = luas segitiga x t
*/

// Deklarasi Variabel
const float pi = 3.14159265359;
float s, p, l, a, t, t1, r, d1, d2, a1, a2, ls, v;

// Mengenalkan function Menuu Utama
void menuUtama();

// Function untuk mereset variabel menjadi 0
void reset() {
    s = p = l = a = t = t1 = r = d1 = d2 = a1 = a2 = ls = v = 0;
}

//Function Tampilkan Nama & NIM
void nimNama(){
    cout << "---------------------------------------------------------" << endl;
    cout << "| Nama : Gega Ramadhan    | Nama : Rassya Arma Putra    |" << endl;
    cout << "| NIM  : 123250112        | NIM  : 123250118            |" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void bangunDatar(){

    //Deklarasi Variabel
    int pilihanBangunDatar;
    bool loopMenuBangunDatar = true;

    do{

        // Reset Variabel agar dapat digunakan kembali
        reset();

        // Tampilan Menu Bangun Datar
        cout << "\n-------------------------------------------------------------------" << endl;
        cout << "\n[Menghitung Luas Bangun Datar]__________" << endl;
        cout << "| 1. Persegi                           |" << endl;
        cout << "| 2. Persegi Panjang                   |" << endl;
        cout << "| 3. Segitiga                          |" << endl;
        cout << "| 4. Lingkaran                         |" << endl;
        cout << "| 5. Jajar Genjang                     |" << endl;
        cout << "| 6. Belah Ketupat                     |" << endl;
        cout << "| 7. Layang-Layang                     |" << endl;
        cout << "| 8. Trapesium                         |" << endl;
        cout << "| 9. Kembali ke Menu                   |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "Pilihan (1-9) : ";
        cin >> pilihanBangunDatar;
        cout << endl;
    
        switch (pilihanBangunDatar){
            case 1:
                cout << "=====[Menghitung Luas Persegi]=====" << endl;
                cout << "1. Masukkan nilai sisi : ";
                cin >> s;
                ls = s * s;
                
                cout << "2. Luas Persegi        : " << ls << endl;
            break;
            case 2:
                cout << "=====[Menghitung Luas Persegi Panjang]=====" << endl;
                cout << "1. Masukkan nilai sisi panjang (p) : ";
                cin >> p;
                cout << "2. Masukkan nilai sisi lebar (l)   : ";
                cin >> l;
                ls = p * l;

                cout << "3. Luas Persegi Panjang            : " << ls << endl;
            break;
            case 3:
                cout << "=====[Menghitung Luas Segitiga]=====" << endl;
                cout << "1. Masukkan nilai sisi alas (a)   : ";
                cin >> a;
                cout << "2. Masukkan nilai sisi tinggi (t) : ";
                cin >> t;
                ls = a * t / 2;
                cout << "3. Luas Segitiga                  : " << ls << endl;
            break;
            case 4:
                cout << "=====[Menghitung Luas Lingkaran]=====" << endl;
                cout << "1. Masukkan nilai jari-jari (r) : ";
                cin >> r;
                ls = pi * r * r;
                cout << "2. Luas Lingkaran               : " << ls << endl;
            break;
            case 5:
                cout << "=====[Menghitung Luas Jajar Genjang]=====" << endl;
                cout << "1. Masukkan nilai sisi panjang (p) : ";
                cin >> p;
                cout << "2. Masukkan nilai sisi tinggi (t)  : ";
                cin >> t;
                ls = p * t;
                cout << "3. Luas Jajar Genjang              : " << ls << endl;
            break;
            case 6:
                cout << "=====[Menghitung Luas Belah Ketupat]=====" << endl;
                cout << "1. Masukkan nilai diagonal 1 (d1)  : ";
                cin >> d1;
                cout << "2. Masukkan nilai diagonal 2 (d2)  : ";
                cin >> d2;
                ls = d1 * d2 / 2;
                cout << "3. Luas Belah Ketupat              : " << ls << endl;
            break;
            case 7:
                cout << "=====[Menghitung Luas Layang-Layang]=====" << endl;
                cout << "1. Masukkan nilai diagonal 1 (d1)  : ";
                cin >> d1;
                cout << "2. Masukkan nilai diagonal 2 (d2)  : ";
                cin >> d2;
                ls = d1 * d2 / 2;
                cout << "3. Luas Layang-Layang              : " << ls << endl;
            break;
            case 8:
                cout << "=====[Menghitung Luas Trapesium]=====" << endl;
                cout << "1. Masukkan nilai sisi sejajar (a1) : ";
                cin >> a1;
                cout << "2. Masukkan nilai sisi sejajar (a2) : ";
                cin >> a2;
                cout << "3. Masukkan nilai tinggi (t)        : ";
                cin >> t;
                ls = (a1 + a2) * t / 2;
                cout << "Luas Trapesium                      : " << ls << endl;
            break;
            case 9:
                loopMenuBangunDatar == false;
                menuUtama();
            break;
            default:
                cout << "=====[Input Tidak Valid - Program Berhenti]=====" << endl;
                exit(0);
            break;
        }
    } while (loopMenuBangunDatar == true);
}

void bangunRuang(){
    
    //Deklarasi Variabel
    int pilihanBangunRuang;
    bool loopMenuBangunRuang = true;
    
    do{
    
        // Reset Variabel agar dapat digunakan kembali
        reset();
    
        // Tampilan Menu Bangun Ruang
        cout << "\n-------------------------------------------------------------------" << endl;
        cout << "\n[Menghitung Volume Bangun Ruang]__________" << endl;
        cout << "| 1. Kubus                             |" << endl;
        cout << "| 2. Balok                             |" << endl;
        cout << "| 3. Tabung                            |" << endl;
        cout << "| 4. Bola                              |" << endl;
        cout << "| 5. Kerucut                           |" << endl;
        cout << "| 6. Limas Segitiga                    |" << endl;
        cout << "| 7. Limas Segiempat                   |" << endl;
        cout << "| 8. Prisma Segitiga                   |" << endl;
        cout << "| 9. Kembali ke Menu                   |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "Pilihan (1-9) : ";
        cin >> pilihanBangunRuang;
        cout << endl;
    
        switch (pilihanBangunRuang){
            case 1:
                cout << "=====[Menghitung Volume Kubus]=====" << endl;
                cout << "1. Masukkan nilai sisi (s) : ";
                cin >> s;
                v = s * s * s;
                
                cout << "2. Volume Kubus            : " << v << endl;
            break;
            case 2:
                cout << "=====[Menghitung Volume Balok]=====" << endl;
                cout << "1. Masukkan nilai sisi panjang (p) : ";
                cin >> p;
                cout << "2. Masukkan nilai sisi lebar (l)   : ";
                cin >> l;
                cout << "3. Masukkan nilai sisi tinggi (t)  : ";
                cin >> t;
                v = p * l * t;
    
                cout << "3. Volume Balok                    : " << v << endl;
            break;
            case 3:
                cout << "=====[Menghitung Volume Tabung]=====" << endl;
                cout << "1. Masukkan nilai jari-jari (r)   : ";
                cin >> r;
                cout << "2. Masukkan nilai sisi tinggi (t) : ";
                cin >> t;
                ls = pi * r * r;
                v = ls * t;
                cout << "3. Volume Tabung                  : " << v << endl;
            break;
            case 4:
                cout << "=====[Menghitung Volume Bola]=====" << endl;
                cout << "1. Masukkan nilai jari-jari (r) : ";
                cin >> r;
                v = pi * r * r * r * 4 / 3;
                cout << "2. Volume Bola                  : " << v << endl;
            break;
            case 5:
                cout << "=====[Menghitung Volume Kerucut]=====" << endl;
                cout << "1. Masukkan nilai jari-jari (r)    : ";
                cin >> r;
                cout << "2. Masukkan nilai sisi tinggi (t)  : ";
                cin >> t;
                v = (pi * r * r * t) / 3;
                cout << "3. Volume Kerucut                  : " << v << endl;
            break;
            case 6:
                cout << "=====[Menghitung Volume Limas Segitiga]=====" << endl;
                cout << "1. Masukkan nilai alas segitiga (a)   : ";
                cin >> a;
                cout << "2. Masukkan nilai tinggi segitiga (t) : ";
                cin >> t;
                cout << "3. Masukkan nilai tinggi limas (t1)   : ";
                cin >> t1;
                v =(a * t / 2) * t1 / 3;
                cout << "4. Volume Limas Segitiga              : " << v << endl;
            break;
            case 7:
                cout << "=====[Menghitung Volume Limas Segiempat]=====" << endl;
                cout << "1. Masukkan nilai panjang alas (p)  : ";
                cin >> p;
                cout << "2. Masukkan nilai lebar alas (l)    : ";
                cin >> l;
                cout << "3. Masukkan nilai tinggi limas (t)  : ";
                cin >> t;
                v = p * l * t / 3;
                cout << "Volume Limas Segiempat        : " << v << endl;
            break;
            case 8:
                cout << "=====[Menghitung Volume Prisma Segitiga]=====" << endl;
                cout << "1. Masukkan nilai alas segitiga (a)   : ";
                cin >> a;
                cout << "2. Masukkan nilai tinggi segitiga (t) : ";
                cin >> t;
                cout << "3. Masukkan nilai tinggi prisma (t1)  : ";
                cin >> t1;
                v = a * t / 2 * t1;
                cout << "Volume Prisma Segitiga        : " << v << endl;
            break;
            case 9:
                loopMenuBangunRuang == false;
                menuUtama();
            break;
            default:
                cout << "=====[Input Tidak Valid - Program Berhenti]=====" << endl;
                exit(0);
            break;
        }
    } while (loopMenuBangunRuang == true);
}

void menuUtama(){
    // Membersihkan Tampilan CMD
    system("CLS");

    // Panggil Function Nama & NIM
    nimNama();

    // Tampilan Menu Utama
    cout << "\n[Program Penghitung Luas Bangun Datar atau Volume Bangun Ruang]_____" << endl;
    cout << "| 1. Bangun Datar                                                  |" << endl;
    cout << "| 2. Bangun Ruang                                                  |" << endl;
    cout << "| 3. Keluar                                                        |" << endl;
    cout << "|__________________________________________________________________|" << endl;
    cout << " Pilih (1-3) : ";
    int pilihanMenuAwal;
    cin >> pilihanMenuAwal;
    
    switch (pilihanMenuAwal){
        case 1:
            bangunDatar();
        break;
        case 2:
            bangunRuang();
        break;
        case 3:
            cout << "\n=====[Program Selesai - Terima Kasih]=====" << endl;
            exit(0);
        break;
        default:
            cout << "\n=====[Input Tidak Valid]=====" << endl;
            exit(0);
        break;
    }
}

int main(){
    // Panggil Menu Utama
    menuUtama();
}
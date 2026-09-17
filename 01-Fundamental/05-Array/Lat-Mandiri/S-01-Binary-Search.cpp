#include <iostream>
#include <string>
using namespace std;


/*
    Soal 2: Antrean Berdasarkan Nomor Tiket (Binary Search)
        Konteks:
            Di sebuah konser musik, penonton masuk berdasarkan Nomor Tiket (Integer). 
            Hebatnya, penyelenggara sudah menyuruh semua penonton berbaris rapi dari nomor tiket yang 
            paling kecil ke yang paling besar. Panitia keamanan ingin mengecek apakah seorang penonton dengan nomor 
            tiket tertentu sudah masuk ke barisan atau belum.

        Tugas:
            - Masukkan minimal 10 nomor tiket secara berurutan (misal: 101, 105, 110, 112, 120, 125, dst).
            - Gunakan Binary Search untuk mencari nomor tiket yang diinput oleh user.
            - Karena ini konser besar, kamu harus menghitung berapa kali komputer melakukan pengecekan (pembagian mid) sampai tiketnya ketemu.
            - Tampilkan indeks tiket tersebut dan jumlah langkah pengecekannya.
            - Mengapa Binary Search? Karena penonton sudah berbaris rapi (terurut), kamu bisa membelah barisan menjadi dua 
                agar pengecekan jauh lebih cepat daripada Linear Search.

        Tips Buat Kamu:
            Untuk soal nomor 2, coba tambahkan variabel int langkah = 0; di dalam loop while Binary Search kamu. 
            Setiap kali loop berjalan, lakukan langkah++;. Ini bakal keren banget buat dokumentasimu karena membuktikan Binary Search itu 
            jauh lebih "pintar" daripada Linear Search.
*/

void soal2(){
    cout << "\n==========[SOAL 2 - Binary Search]==========" << endl;
    
    const int jumlahTiket = 10;
    int tiketKonser[jumlahTiket] {
        101, 105, 110, 112, 120, 125, 127, 130, 135, 138
    };

    int langkah = 0;
    int posisiKetemu = 0;
    bool found = false;

    int indexAwal = 0;
    int indexAkhir = jumlahTiket - 1;
    
    int noDicari;
    cout << "\nMasukkan Nomer Tiket : ";
    cin >> noDicari;
    
    while(indexAwal <= indexAkhir){
        
        langkah++;
        int mid = (indexAwal + indexAkhir) / 2;

        if(noDicari == tiketKonser[mid]){

            posisiKetemu = mid;
            found = true;
            break;

        } else if (noDicari < tiketKonser[mid]){
            indexAkhir = mid - 1;
        } else if (noDicari > tiketKonser[mid]){
            indexAwal = mid + 1;
        }
    }
    
    if(found){
        cout << "---> Data ditemukan di index ke-" << posisiKetemu << endl;
        cout << "\tTotal pengecekan dilakukan: " << langkah << " kali." << endl;
    } else {
        cout << "---> Nomor tiket tidak terdaftar di barisan ini." << endl;
        cout << "\tTotal pengecekan dilakukan: " << langkah << " kali." << endl;
    }
}

int main(){

    soal2();

    return 0;
}
#include <iostream>
using namespace std;

void operatorIncrementDecrement() {
    cout << "========== K. Operator Increment & Decrement ==========" << endl;

    // ----- 1. Berdiri Sendiri - Tidak Ada Perbedaan -----
        cout << "\n1. Berdiri Sendiri - x++ dan ++x hasilnya SAMA" << endl;

        int a = 5;
        a++;    // sama dengan: a = a + 1;  atau  a += 1;
        cout << "   a = 5, lalu a++  -> a = " << a << endl;

        int b = 5;
        ++b;    // sama dengan: b = b + 1;
        cout << "   b = 5, lalu ++b  -> b = " << b << endl;

        cout << "   -> Kalau berdiri sendiri, keduanya identik." << endl;

    // ----- 2. Post-Increment (x++) dalam Ekspresi -----
        cout << "\n2. Post-Increment (x++) - Pakai Dulu, Naikkan Belakangan" << endl;

        int x = 5;
        int hasil = x++;   // hasil = 5 (nilai LAMA), x naik jadi 6
        cout << "   x = 5" << endl;
        cout << "   int hasil = x++;" << endl;
        cout << "   hasil = " << hasil << "  <- dapat nilai LAMA (5)" << endl;
        cout << "   x     = " << x     << "  <- x sudah naik jadi 6" << endl;

        // Visualisasi urutan eksekusi
            cout << "\n   Urutan di balik layar:" << endl;
            cout << "     1. Simpan nilai lama x (= 5) ke temp" << endl;
            cout << "     2. Naikkan x (x = 5+1 = 6)" << endl;
            cout << "     3. Kembalikan temp (= 5) ke hasil" << endl;
            cout << "     -> hasil = 5,  x = 6" << endl;

    // ----- 3. Pre-Increment (++x) dalam Ekspresi -----
        cout << "\n3. Pre-Increment (++x) - Naikkan Dulu, Pakai Hasilnya" << endl;

        int y = 5;
        int hasil2 = ++y;   // y naik dulu jadi 6, hasil2 = 6
        cout << "   y = 5" << endl;
        cout << "   int hasil2 = ++y;" << endl;
        cout << "   hasil2 = " << hasil2 << "  <- dapat nilai BARU (6)" << endl;
        cout << "   y      = " << y      << "  <- y sudah naik jadi 6" << endl;

        cout << "\n   Urutan di balik layar:" << endl;
        cout << "     1. Naikkan y (y = 5+1 = 6)" << endl;
        cout << "     2. Kembalikan y yang sudah naik (= 6) ke hasil2" << endl;
        cout << "     -> hasil2 = 6,  y = 6" << endl;

    // ----- 4. Perbandingan Langsung -----
        cout << "\n4. Perbandingan Post vs Pre - Contoh Berurutan" << endl;

        int n = 10;
        cout << "   n = 10" << endl;
        cout << "   n++  dalam cout -> tampil " << n++ << ", lalu n jadi " << n << endl;

        n = 10;
        cout << "   n = 10 (reset)" << endl;
        cout << "   ++n  dalam cout -> tampil " << ++n << ", n sudah jadi " << n << endl;

    // ----- 5. Post-Decrement & Pre-Decrement -----
        cout << "\n5. Decrement (--) - Prinsip Sama, Arahnya Turun" << endl;

        int p = 10;
        int r1 = p--;    // r1 = 10 (lama), p jadi 9
        cout << "   p = 10, r1 = p--  ->  r1=" << r1 << ", p=" << p << "  (post-dec)" << endl;

        int q = 10;
        int r2 = --q;    // q turun dulu jadi 9, r2 = 9
        cout << "   q = 10, r2 = --q  ->  r2=" << r2 << ", q=" << q << "  (pre-dec)" << endl;

    // ----- 6. Increment dalam Loop -----
        cout << "\n6. Increment dalam Loop - Penggunaan Paling Umum" << endl;

        cout << "   for (int i=0; i<5; i++)  ->  0 1 2 3 4" << endl;
        cout << "   Hasil: ";
        for (int i = 0; i < 5; i++) {
            cout << i << " ";
        }
        cout << endl;

        cout << "\n   for (int i=5; i>0; i--)  ->  5 4 3 2 1" << endl;
        cout << "   Hasil: ";
        for (int i = 5; i > 0; i--) {
            cout << i << " ";
        }
        cout << endl;

        // Pre vs post di loop - hasilnya SAMA untuk counter biasa
            cout << "\n   Catatan: i++ dan ++i di loop for biasa -> hasil sama." << endl;
            cout << "   Tapi ++i sedikit lebih efisien untuk tipe kompleks (iterator, object)." << endl;

    // ----- 7. Contoh Kasus Nyata -----
        cout << "\n7. Contoh Kasus Nyata" << endl;

        // a. Nomor antrian
            cout << "\n   a. Nomor Antrian Otomatis:" << endl;
            int nomorAntrian = 0;
            cout << "      Pelanggan 1 dapat nomor: " << ++nomorAntrian << endl;   // pre: dapat 1
            cout << "      Pelanggan 2 dapat nomor: " << ++nomorAntrian << endl;   // pre: dapat 2
            cout << "      Pelanggan 3 dapat nomor: " << ++nomorAntrian << endl;   // pre: dapat 3

        // b. Akses array dengan post-increment
            cout << "\n   b. Akses Array dengan Post-Increment:" << endl;
            int arr[] = {10, 20, 30, 40, 50};
            int idx = 0;
            cout << "      arr[idx++] = " << arr[idx++] << "  (idx sekarang " << idx << ")" << endl;
            cout << "      arr[idx++] = " << arr[idx++] << "  (idx sekarang " << idx << ")" << endl;
            cout << "      arr[idx]   = " << arr[idx]   << "  (idx tetap " << idx << ")" << endl;

    // ----- 8. Undefined Behavior - Jangan Dilakukan -----
        cout << "\n8. Undefined Behavior - JANGAN DILAKUKAN" << endl;
        cout << "   int i = 5;" << endl;
        cout << "   int j = i++ + i++;   // hasilnya tidak terdefinisi!" << endl;
        cout << "   cout << i++ << i++;  // urutan evaluasi tidak dijamin!" << endl;
        cout << "\n   ATURAN AMAN: Gunakan ++ atau -- MAKSIMAL sekali" << endl;
        cout << "   pada variabel yang sama dalam satu statement." << endl;

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Kalau berdiri sendiri: x++ dan ++x identik" << endl;
        cout << "   -> Dalam ekspresi: post(x++) pakai dulu, pre(++x) naik dulu" << endl;
        cout << "   -> Di for loop: i++ paling umum, ++i sedikit lebih efisien" << endl;
        cout << "   -> Jangan campur ++ pada variabel sama dalam 1 statement!" << endl;
}

int main(){

    operatorIncrementDecrement();

    return 0;
}
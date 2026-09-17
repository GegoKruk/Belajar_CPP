#include <iostream>
using namespace std;

void operatorLogika() {
    cout << "\n========== M. Operator Logika ==========" << endl;

    // ----- 1. AND (&&) - Tabel Kebenaran -----
        cout << "\n1. AND (&&) - Menang False" << endl;
        cout << boolalpha;
        cout << "   true  && true   ->  " << (true  && true)  << endl;
        cout << "   true  && false  ->  " << (true  && false) << endl;
        cout << "   false && true   ->  " << (false && true)  << endl;
        cout << "   false && false  ->  " << (false && false) << endl;

    // ----- 2. OR (||) - Tabel Kebenaran -----
        cout << "\n2. OR (||) - Menang True" << endl;
        cout << "   true  || true   ->  " << (true  || true)  << endl;
        cout << "   true  || false  ->  " << (true  || false) << endl;
        cout << "   false || true   ->  " << (false || true)  << endl;
        cout << "   false || false  ->  " << (false || false) << endl;

    // ----- 3. NOT (!) - Membalik Nilai -----
        cout << "\n3. NOT (!) - Kebalikannya" << endl;
        cout << "   !true   ->  " << !true  << endl;
        cout << "   !false  ->  " << !false << endl;

        bool sudahLogin = true;
        cout << "   sudahLogin = true,  !sudahLogin = " << !sudahLogin << endl;

        cout << noboolalpha;

    // ----- 4. Kombinasi Operator Logika -----
        cout << "\n4. Kombinasi Operator Logika" << endl;

        int umur   = 20;
        int saldo  = 500000;
        bool punya_ktp = true;

        bool bisaPinjam = (umur >= 18) && (saldo >= 100000) && punya_ktp;
        cout << "   Umur = " << umur << endl;
        cout << "   Saldo = " << saldo << endl;
        cout << "   punya_ktp = " << punya_ktp << endl;
        cout << "   Bisa pinjam? ( umur >= 18 && saldo >= 100k && punya_ktp): "
            << (bisaPinjam ? "YA" : "TIDAK") << endl;

        // OR: cukup salah satu terpenuhi
            bool bisaMasuk = (umur >= 17) || punya_ktp;
            cout << "   Bisa masuk? ( umur >= 17 || punya_ktp): "
                << (bisaMasuk ? "YA" : "TIDAK") << endl;

    // ----- 5. Short-Circuit Evaluation -----
        cout << "\n5. Short-Circuit Evaluation - Fitur Penting!" << endl;

        cout << "   Dalam && : jika kiri FALSE  -> kanan tidak dievaluasi sama sekali" << endl;
        cout << "   Dalam || : jika kiri TRUE   -> kanan tidak dievaluasi sama sekali" << endl;

        // Demonstrasi: mencegah crash dengan short-circuit
            int* ptr = nullptr;
            // if (ptr->value > 0)             // ❌ CRASH! nullptr dereference
            bool amanCek = (ptr != nullptr) && (*ptr > 0);  // ✅ aman, kanan tidak dievaluasi (short-circuit)
            cout << "\n   Contoh keamanan pointer:" << endl;
            cout << "   ptr = nullptr" << endl;
            cout << "   (ptr != nullptr) && (ptr > 0)  ->  " << amanCek << " (tidak crash!)" << endl;

        // Demonstrasi short-circuit dengan counter
            cout << "\n   Demonstrasi short-circuit dengan counter:" << endl;
            int counter = 0;

        // Di sini kita pakai lambda-like approach dengan counter langsung
            bool kiri  = false;
            bool kanan = true;

            cout << "   false && [ekspresi]  ->  kanan TIDAK dievaluasi (short-circuit!)" << endl;
            cout << "   true  || [ekspresi]  ->  kanan TIDAK dievaluasi (short-circuit!)" << endl;
            cout << "   Ini bisa dimanfaatkan untuk optimasi & keamanan." << endl;

    // ----- 6. Prioritas Operator Logika -----
        cout << "\n6. Prioritas Operator: ! > && > ||" << endl;

        bool hasil1 = true || false && false;
        // Diproses:  true || (false && false)  <- && lebih tinggi dari ||
        //          = true || false
        //          = true
        cout << boolalpha;
        cout << "   true || false && false" << endl;
        cout << "   = true || (false && false)  <- && dulu" << endl;
        cout << "   = true || false" << endl;
        cout << "   = " << hasil1 << endl;

        bool hasil2 = !true || false && true;
        // = ((!true) || (false && true))
        // = (false || false)
        // = false
        cout << "\n   !true || false && true" << endl;
        cout << "   = (!true) || (false && true)  <- ! paling tinggi, && berikutnya" << endl;
        cout << "   = false || false" << endl;
        cout << "   = " << hasil2 << endl;
        cout << noboolalpha;

        cout << "\n  Pakai kurung () untuk lebih jelas dan aman:" << endl;
        cout << "   (true || false) && false  ->  " << ((true || false) && false) << endl;
        cout << "   true || (false && false)  ->  " << (true || (false && false)) << endl;

    // ----- 7. Contoh Praktis Kondisi Majemuk -----
        cout << "\n7. Contoh Praktis - Kondisi Majemuk" << endl;

        // a. Validasi Umur & Status
            cout << "\n   a. Sistem Tiket Bioskop:" << endl;
            int usiaPenonton = 15;
            bool didampingiOrangTua = true;
            bool filmDewasa = true;

            bool bolehNonton = !filmDewasa || (filmDewasa && (usiaPenonton >= 18 || didampingiOrangTua));
            cout << "      Usia          = " << usiaPenonton << endl;
            cout << "      Didampingi    = " << (didampingiOrangTua?"ya":"tidak") << endl;
            cout << "      Film 18+      = " << (filmDewasa?"ya":"tidak") << endl;
            cout << "      Boleh nonton? = " << (bolehNonton ? "YA" : "TIDAK") << endl;

        // b. Validasi Form Login
            cout << "\n   b. Validasi Form:" << endl;
            string username = "gega";
            string password = "12345";
            bool usernameValid = (username.length() >= 3);
            bool passwordValid = (password.length() >= 6);
            bool formValid     = usernameValid && passwordValid;

            cout << "      Username '" << username << "' valid (>= 3 char)? " << (usernameValid ? "ya" : "tidak") << endl;
            cout << "      Password '" << password << "' valid (>= 6 char)? " << (passwordValid ? "ya" : "tidak") << endl;
            cout << "      Form bisa disubmit? " << (formValid ? "YA" : "TIDAK") << endl;

        // c. Cek Tahun Kabisat
            cout << "\n   c. Tahun Kabisat (contoh logika majemuk):" << endl;
            int tahun = 2024;
            bool kabisat = (tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0);
            cout << "      Tahun " << tahun << " kabisat? " << (kabisat ? "YA" : "TIDAK") << endl;

    // ----- Tips -----
        cout << "\nTips:" << endl;
        cout << "   -> Selalu pakai () untuk ekspresi logika kompleks agar jelas" << endl;
        cout << "   -> Manfaatkan short-circuit untuk keamanan (null check) & performa" << endl;
        cout << "   -> Urutan prioritas: ! > && > || (tapi tetap pakai kurung)" << endl;
        cout << "   -> Jangan pakai == untuk float/double, pakai fabs(a-b) < epsilon" << endl;
        cout << "   -> = adalah assignment, == adalah perbandingan!" << endl;
}

int main(){

    operatorLogika();

    return 0;
}
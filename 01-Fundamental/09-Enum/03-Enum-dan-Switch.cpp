

#include <iostream>
#include <string>
using namespace std;

enum Musim      { HUJAN, KEMARAU, PANCAROBA };
enum Arah       { UTARA, SELATAN, TIMUR, BARAT };
enum Level      { MUDAH, SEDANG, SULIT, EXPERT };
enum HasilLogin { LOGIN_OK, SALAH_PASSWORD, USER_TIDAK_ADA };
enum StatusOrder{ ORDER_BARU, DIPROSES, DIKIRIM, SELESAI, DIBATALKAN };


// ----- Fungsi yang mengembalikan enum -----
    HasilLogin cekLogin(const string& username, const string& password) {
        if (username != "admin" && username != "user1") {
            return USER_TIDAK_ADA;
        }
        if (password != "pass123") {
            return SALAH_PASSWORD;
        }
        return LOGIN_OK;
    }

    string statusOrderStr(StatusOrder s) {
        switch (s) {
            case ORDER_BARU:   return "Order Baru";
            case DIPROSES:     return "Sedang Diproses";
            case DIKIRIM:      return "Sedang Dikirim";
            case SELESAI:      return "Selesai";
            case DIBATALKAN:   return "Dibatalkan";
            default:           return "Status Tidak Dikenal";
        }
    }


int main() {

    // ----- 1. Switch dengan Enum (Musim) -----
        cout << "=== 1. Switch dengan Enum (Musim) ===" << endl;

        Musim musimSekarang = HUJAN;

        switch (musimSekarang) {
            case HUJAN:
                cout << "Musim hujan - bawa payung!" << endl;
                cout << "Waspada banjir dan longsor." << endl;
                break;
            case KEMARAU:
                cout << "Musim kemarau - pakai sunscreen!" << endl;
                cout << "Hemat air." << endl;
                break;
            case PANCAROBA:
                cout << "Musim pancaroba - waspada cuaca ekstrem!" << endl;
                cout << "Jaga kesehatan." << endl;
                break;
            default:
                cout << "Musim tidak dikenal." << endl;
        }


    // ----- 2. Switch dengan Enum (Arah) -----
        cout << endl << "=== 2. Switch dengan Enum (Arah) ===" << endl;

        Arah arahJalan = TIMUR;

        switch (arahJalan) {
            case UTARA:   cout << "Menuju Utara" << endl; break;
            case SELATAN: cout << "Menuju Selatan" << endl; break;
            case TIMUR:   cout << "Menuju Timur" << endl; break;
            case BARAT:   cout << "Menuju Barat" << endl; break;
        }


    // ----- 3. Enum sebagai Parameter Level -----
        cout << endl << "=== 3. Enum Level sebagai Parameter ===" << endl;

        Level tingkat[] = {MUDAH, SEDANG, SULIT, EXPERT};
        int jumlahSoal[] = {10, 20, 35, 50};

        for (int i = 0; i < 4; i++) {
            cout << "Level " << i << ": ";
            switch (tingkat[i]) {
                case MUDAH:  cout << "MUDAH  "; break;
                case SEDANG: cout << "SEDANG "; break;
                case SULIT:  cout << "SULIT  "; break;
                case EXPERT: cout << "EXPERT "; break;
            }
            cout << "- " << jumlahSoal[i] << " soal" << endl;
        }


    // ----- 4. Enum sebagai Return Value (HasilLogin) -----
        cout << endl << "=== 4. Enum sebagai Return Value ===" << endl;

        struct TestLogin {
            string user;
            string pass;
        };

        TestLogin percobaan[] = {
            {"admin", "pass123"},
            {"admin", "salah"},
            {"unknown", "pass123"}
        };

        for (int i = 0; i < 3; i++) {
            HasilLogin hasil = cekLogin(percobaan[i].user, percobaan[i].pass);
            cout << "Login '" << percobaan[i].user << "': ";
            switch (hasil) {
                case LOGIN_OK:
                    cout << "BERHASIL! Selamat datang." << endl;
                    break;
                case SALAH_PASSWORD:
                    cout << "GAGAL - Password salah." << endl;
                    break;
                case USER_TIDAK_ADA:
                    cout << "GAGAL - User tidak ditemukan." << endl;
                    break;
            }
        }


    // ----- 5. Enum untuk Alur Status -----
        cout << endl << "=== 5. Enum untuk Alur Status Order ===" << endl;

        StatusOrder statusList[] = {ORDER_BARU, DIPROSES, DIKIRIM, SELESAI};
        int jumlahStatus = sizeof(statusList) / sizeof(statusList[0]);

        cout << "Riwayat order #12345:" << endl;
        for (int i = 0; i < jumlahStatus; i++) {
            cout << "  [" << i + 1 << "] " << statusOrderStr(statusList[i]) << endl;
        }

        // Cek apakah sudah selesai
            StatusOrder statusAkhir = SELESAI;
            if (statusAkhir == SELESAI) {
                cout << "Order sudah selesai." << endl;
            } else if (statusAkhir == DIBATALKAN) {
                cout << "Order telah dibatalkan." << endl;
            } else {
                cout << "Order masih dalam proses." << endl;
            }

    return 0;
}

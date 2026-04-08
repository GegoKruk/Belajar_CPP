
#include <iostream>
#include <string>
using namespace std;

// ----- Struct: Data sederhana, semua public -----
    struct TitikStruct {
        double x;
        double y;
        // Data dan function bisa diakses langsung dari luar
    };

// ----- Class: Dengan encapsulation -----
    class TitikClass {
        // private by default
        double x;
        double y;

        public:
        // Constructor
        TitikClass(double x, double y) : x(x), y(y) {}

        // Getter (akses controlled)
        double getX() const { return x; }
        double getY() const { return y; }

        // Setter (dengan validasi jika perlu)
        void setX(double nilaiX) { x = nilaiX; }
        void setY(double nilaiY) { y = nilaiY; }

        void tampilkan() const {
            cout << "(" << x << ", " << y << ")" << endl;
        }
    };

// ----- Struct sebagai Plain Old Data (POD) -----
    struct Warna {
        unsigned char r;   // 0-255
        unsigned char g;
        unsigned char b;
    };

// ----- Struct sebagai Data Transfer Object (DTO) -----
    struct LoginRequest {
        string username;
        string password;
        string ipAddress;
    };

    struct LoginResponse {
        bool   berhasil;
        string token;
        string pesan;
    };

// ----- Struct dengan member function (mirip class tapi konvensi struct) -----
    struct Persegi {
        double sisi;

        double luas()     { return sisi * sisi; }
        double keliling() { return 4 * sisi; }
    };

// ----- Demonstrasi akses struct vs class -----
    struct ContohStruct {
        int data;      // public by default
        void tampil() { cout << "Struct data = " << data << endl; }
    };

    class ContohClass {
        int data;      // private by default!
    public:
        void setData(int d) { data = d; }
        void tampil() { cout << "Class  data = " << data << endl; }
    };


int main() {

    // ----- 1. Perbedaan Default Access -----
        cout << "=== 1. Perbedaan Default Access ===" << endl;

        ContohStruct cs;
        cs.data = 42;       // OK - struct, public by default
        cs.tampil();

        ContohClass cc;
        // cc.data = 42;    // ERROR - class, private by default
        cc.setData(42);     // harus lewat setter
        cc.tampil();

        cout << "Struct: member langsung bisa diakses (public default)" << endl;
        cout << "Class : member tidak bisa diakses langsung (private default)" << endl;


    // ----- 2. Struct sebagai POD -----
        cout << endl << "=== 2. Struct sebagai POD (Plain Old Data) ===" << endl;

        TitikStruct t1;
        t1.x = 3.0;
        t1.y = 4.0;
        cout << "Titik: (" << t1.x << ", " << t1.y << ")" << endl;

        Warna merah = {255, 0, 0};
        Warna biru  = {0, 0, 255};
        cout << "Merah: R=" << (int)merah.r << " G=" << (int)merah.g << " B=" << (int)merah.b << endl;
        cout << "Biru : R=" << (int)biru.r  << " G=" << (int)biru.g  << " B=" << (int)biru.b  << endl;


    // ----- 3. Class dengan Encapsulation -----
        cout << endl << "=== 3. Class dengan Encapsulation ===" << endl;

        TitikClass tc(3.0, 4.0);
        cout << "TitikClass: ";
        tc.tampilkan();

        tc.setX(10.0);
        cout << "Setelah setX(10): ";
        tc.tampilkan();

        // tc.x = 5.0;   // ERROR - private


    // ----- 4. Struct sebagai DTO -----
        cout << endl << "=== 4. Struct sebagai DTO ===" << endl;

        // Simulasi kirim data login
        LoginRequest req;
        req.username  = "gega123";
        req.password  = "rahasia";
        req.ipAddress = "192.168.1.1";

        // Simulasi proses login
            LoginResponse res;
            if (req.username == "gega123" && req.password == "rahasia") {
                res.berhasil = true;
                res.token    = "abc123xyz";
                res.pesan    = "Login berhasil";
            } else {
                res.berhasil = false;
                res.token    = "";
                res.pesan    = "Username atau password salah";
            }

            cout << "Request : " << req.username << " dari " << req.ipAddress << endl;
            cout << "Response: " << (res.berhasil ? "BERHASIL" : "GAGAL") << endl;
            cout << "Pesan   : " << res.pesan << endl;
            if (res.berhasil) {
                cout << "Token   : " << res.token << endl;
            }


    // ----- 5. Ringkasan -----
        cout << endl << "=== 5. Ringkasan Struct vs Class ===" << endl;
        cout << "Aspek                 | struct          | class" << endl;
        cout << "----------------------+-----------------+------------------" << endl;
        cout << "Default access        | public          | private" << endl;
        cout << "Member function       | Bisa            | Bisa" << endl;
        cout << "Inheritance           | Bisa            | Bisa" << endl;
        cout << "Access specifier      | Bisa            | Bisa" << endl;
        cout << "Konvensi gunakan      | Data sederhana  | Objek kompleks" << endl;
        cout << "Kapan pilih           | POD / DTO       | Encapsulation" << endl;

        cout << endl;
        cout << "Aturan praktis:" << endl;
        cout << "  Data sederhana tanpa logika  -> pakai struct" << endl;
        cout << "  Butuh sembunyikan data       -> pakai class" << endl;
        cout << "  Sudah banyak member function -> pertimbangkan class" << endl;
        cout << "  (Class dibahas detail di modul OOP)" << endl;

    return 0;
}

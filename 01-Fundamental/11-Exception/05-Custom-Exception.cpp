#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


//  CARA 1: Warisi std::exception (dasar)
    class SimpleException : public exception {
    private:
        string pesan_;
    public:
        explicit SimpleException(const string& pesan) : pesan_(pesan) {}

        const char* what() const noexcept override {
            return pesan_.c_str();
        }
    };


//  CARA 2: Warisi std::runtime_error (lebih praktis)
    class FileError : public runtime_error {
    public:
        explicit FileError(const string& namaFile)
            : runtime_error("File tidak bisa dibuka: " + namaFile) {}
    };

    class DatabaseError : public runtime_error {
    public:
        explicit DatabaseError(const string& msg)
            : runtime_error("Database error: " + msg) {}
    };


//  CARA 3: Custom exception dengan data tambahan
    class ValidationError : public runtime_error {
    private:
        string field_;
        string nilai_;
    public:
        ValidationError(const string& field,
                        const string& nilai,
                        const string& alasan)
            : runtime_error("Validasi gagal [" + field + "='" + nilai + "']: " + alasan),
            field_(field), nilai_(nilai) {}

        string field() const { return field_; }
        string nilai() const { return nilai_; }
    };


    class HttpException : public runtime_error {
    private:
        int    statusCode_;
        string url_;
    public:
        HttpException(int code, const string& url, const string& pesan = "")
            : runtime_error("HTTP " + to_string(code)
                + " pada '" + url + "'"
                + (pesan.empty() ? "" : " - " + pesan)),
            statusCode_(code), url_(url) {}

        int    statusCode() const { return statusCode_; }
        string url()        const { return url_; }
    };


//  Fungsi-fungsi yang menggunakan custom exception
    void bukaFile(const string& nama) {
        // Simulasi: file dengan nama tertentu dianggap tidak ada
        if (nama.find("tidak_ada") != string::npos) {
            throw FileError(nama);
        }
        cout << "  File '" << nama << "' berhasil dibuka." << endl;
    }

    void validasiUsia(int usia) {
        if (usia < 0) {
            throw ValidationError("usia", to_string(usia), "Tidak boleh negatif");
        }
        if (usia > 150) {
            throw ValidationError("usia", to_string(usia), "Tidak masuk akal (> 150)");
        }
        cout << "  Usia " << usia << " valid." << endl;
    }

    void validasiEmail(const string& email) {
        if (email.find('@') == string::npos) {
            throw ValidationError("email", email, "Harus mengandung karakter '@'");
        }
        cout << "  Email '" << email << "' valid." << endl;
    }

    void fetchURL(const string& url, int responseCode) {
        if (responseCode == 404) throw HttpException(404, url, "Halaman tidak ditemukan");
        if (responseCode == 500) throw HttpException(500, url, "Internal server error");
        cout << "  Fetch '" << url << "' berhasil (" << responseCode << ")" << endl;
    }


int main() {

    // ----- 1. Custom Exception Dasar -----
        cout << "=== 1. SimpleException (warisi std::exception) ===" << endl;

        try {
            throw SimpleException("Ini pesan dari SimpleException");
        }
        catch (const SimpleException& e) {
            cout << "Caught SimpleException: " << e.what() << endl;
        }
        catch (const exception& e) {
            // Juga bisa ditangkap sebagai exception base
            cout << "Caught sebagai exception: " << e.what() << endl;
        }


    // ----- 2. FileError dan DatabaseError -----
        cout << endl << "=== 2. FileError dan DatabaseError ===" << endl;

        cout << "Buka file:" << endl;
        for (const string& nama : {"data.txt", "tidak_ada_file.csv"}) {
            try {
                bukaFile(nama);
            }
            catch (const FileError& e) {
                cout << "  FileError: " << e.what() << endl;
            }
        }

        cout << "Database:" << endl;
        try {
            throw DatabaseError("Koneksi timeout setelah 30 detik");
        }
        catch (const DatabaseError& e) {
            cout << "  " << e.what() << endl;
        }


    // ----- 3. ValidationError dengan Data Tambahan -----
        cout << endl << "=== 3. ValidationError (dengan data tambahan) ===" << endl;

        int usiaTest[] = {25, -3, 200};
        for (int usia : usiaTest) {
            try {
                validasiUsia(usia);
            }
            catch (const ValidationError& e) {
                cout << "  Error pada field '" << e.field()
                    << "' nilai '" << e.nilai() << "'" << endl;
                cout << "  Pesan: " << e.what() << endl;
            }
        }

        cout << endl;
        string emailTest[] = {"user@example.com", "email_tanpa_at"};
        for (const string& em : emailTest) {
            try {
                validasiEmail(em);
            }
            catch (const ValidationError& e) {
                cout << "  Error field '" << e.field() << "': " << e.what() << endl;
            }
        }


    // ----- 4. HttpException -----
        cout << endl << "=== 4. HttpException (dengan data tambahan) ===" << endl;

        struct UrlTest { string url; int code; };
        UrlTest requests[] = {
            {"/api/data",   200},
            {"/halaman",    404},
            {"/proses",     500}
        };

        for (const auto& r : requests) {
            try {
                fetchURL(r.url, r.code);
            }
            catch (const HttpException& e) {
                cout << "  HTTP " << e.statusCode()
                    << " pada '" << e.url() << "'" << endl;
                cout << "  what(): " << e.what() << endl;
            }
        }


    // ----- 5. Catch Custom sebagai Base Class -----
        cout << endl << "=== 5. Catch Custom Exception sebagai Base Class ===" << endl;

        cout << "Tangkap FileError sebagai runtime_error:" << endl;
        try {
            throw FileError("config.txt");
        }
        catch (const runtime_error& e) {
            // FileError adalah turunan runtime_error, jadi tertangkap!
            cout << "  [runtime_error] " << e.what() << endl;
        }

        cout << "Tangkap ValidationError sebagai exception:" << endl;
        try {
            throw ValidationError("nama", "", "Tidak boleh kosong");
        }
        catch (const exception& e) {
            // ValidationError adalah turunan exception, jadi tertangkap!
            cout << "  [exception] " << e.what() << endl;
        }

    return 0;
}

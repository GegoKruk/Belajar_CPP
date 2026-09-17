#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


//  HIERARKI EXCEPTION APLIKASI

    // Base: semua error dari aplikasi kita
        class AppException : public runtime_error {
        public:
            explicit AppException(const string& msg)
                : runtime_error(msg) {}
        };

    // --- Cabang 1: Validation ---
        class ValidationError : public AppException {
        private:
            string field_;
        public:
            ValidationError(const string& field, const string& msg)
                : AppException("Validasi [" + field + "]: " + msg),
                field_(field) {}
            string field() const { return field_; }
        };

    // --- Cabang 2: Network ---
        class NetworkError : public AppException {
        public:
            explicit NetworkError(const string& msg)
                : AppException("Network: " + msg) {}
        };

        class TimeoutError : public NetworkError {
        private:
            int timeoutSec_;
        public:
            TimeoutError(const string& host, int detik)
                : NetworkError("Timeout ke '" + host + "' setelah " + to_string(detik) + "s"),
                timeoutSec_(detik) {}
            int timeoutSec() const { return timeoutSec_; }
        };

        class ConnectionError : public NetworkError {
        private:
            string host_;
        public:
            explicit ConnectionError(const string& host)
                : NetworkError("Gagal konek ke '" + host + "'"),
                host_(host) {}
            string host() const { return host_; }
        };

    // --- Cabang 3: Database ---
        class DatabaseError : public AppException {
        public:
            explicit DatabaseError(const string& msg)
                : AppException("Database: " + msg) {}
        };

        class QueryError : public DatabaseError {
        private:
            string query_;
        public:
            QueryError(const string& query, const string& alasan)
                : DatabaseError("Query gagal (" + alasan + "): " + query),
                query_(query) {}
            string query() const { return query_; }
        };

        class TransactionError : public DatabaseError {
        public:
            explicit TransactionError(const string& msg)
                : DatabaseError("Transaksi gagal: " + msg) {}
        };


    //  Simulasi layer aplikasi
        void validasiForm(const string& nama, int umur, const string& email) {
            if (nama.empty())
                throw ValidationError("nama", "Tidak boleh kosong");
            if (umur < 0 || umur > 150)
                throw ValidationError("umur", "Harus antara 0-150, dapat: " + to_string(umur));
            if (email.find('@') == string::npos)
                throw ValidationError("email", "Format tidak valid: " + email);
            cout << "  Form valid: " << nama << ", umur=" << umur << endl;
        }

    void connectDB(const string& host) {
        if (host == "db-mati")
            throw ConnectionError(host);
        cout << "  Konek ke DB '" << host << "' berhasil." << endl;
    }

    void jalankanQuery(const string& sql) {
        if (sql.find("INVALID") != string::npos)
            throw QueryError(sql, "Syntax error");
        cout << "  Query berhasil: " << sql << endl;
    }

    void transferSaldo(bool gagal) {
        if (gagal)
            throw TransactionError("Rollback karena saldo tidak cukup");
        cout << "  Transfer berhasil." << endl;
    }

    void fetchAPI(const string& url, bool timeout) {
        if (timeout)
            throw TimeoutError(url, 30);
        cout << "  Fetch '" << url << "' berhasil." << endl;
    }


int main() {

    // ----- 1. Catch Spesifik -----
        cout << "=== 1. Catch Spesifik ===" << endl;

        struct FormData { string nama; int umur; string email; };
        FormData forms[] = {
            {"Budi",  25, "budi@mail.com"},
            {"",      20, "sari@mail.com"},
            {"Andi", -5,  "andi@mail.com"},
            {"Dina",  30, "dina_no_at"}
        };

        for (const auto& f : forms) {
            try {
                validasiForm(f.nama, f.umur, f.email);
            }
            catch (const ValidationError& e) {
                cout << "  [ValidationError] field='" << e.field() << "': " << e.what() << endl;
            }
        }


    // ----- 2. Catch Per Kategori -----
        cout << endl << "=== 2. Catch Per Kategori ===" << endl;

        // Semua NetworkError ditangkap satu catch
        cout << "Network tests:" << endl;
        auto testNetwork = [](bool timeout) {
            try {
                if (timeout)
                    fetchAPI("api.contoh.com", true);
                else
                    throw ConnectionError("api.contoh.com");
            }
            catch (const TimeoutError& e) {
                cout << "  [TimeoutError] timeout=" << e.timeoutSec() << "s: " << e.what() << endl;
            }
            catch (const NetworkError& e) {
                // Menangkap semua NetworkError lain (termasuk ConnectionError)
                cout << "  [NetworkError] " << e.what() << endl;
            }
        };

        testNetwork(true);
        testNetwork(false);

        // Semua DatabaseError ditangkap satu catch
        cout << "Database tests:" << endl;
        auto testDB = [](int kode) {
            try {
                if (kode == 1) connectDB("db-mati");
                if (kode == 2) jalankanQuery("SELECT INVALID SYNTAX");
                if (kode == 3) transferSaldo(true);
            }
            catch (const ConnectionError& e) {
                cout << "  [ConnectionError] host='" << e.host() << "': " << e.what() << endl;
            }
            catch (const QueryError& e) {
                cout << "  [QueryError] query='" << e.query() << "'" << endl;
            }
            catch (const DatabaseError& e) {
                // Menangkap semua DatabaseError lain
                cout << "  [DatabaseError] " << e.what() << endl;
            }
        };

        testDB(1);
        testDB(2);
        testDB(3);


    // ----- 3. Catch Semua AppException -----
        cout << endl << "=== 3. Catch Semua AppException ===" << endl;

        cout << "Tangkap semua error aplikasi dengan satu catch:" << endl;
        auto jalankanApa = [](int k) {
            if (k == 1) throw ValidationError("input",  "Data kosong");
            if (k == 2) throw TimeoutError("server", 60);
            if (k == 3) throw TransactionError("Deadlock terdeteksi");
        };

        for (int i = 1; i <= 3; i++) {
            try {
                jalankanApa(i);
            }
            catch (const AppException& e) {
                // Satu catch untuk semua error aplikasi
                cout << "  [AppException] kode " << i << ": " << e.what() << endl;
            }
        }


    // ----- 4. Visualisasi Hierarki -----
        cout << endl << "=== 4. Hierarki Exception Aplikasi ===" << endl;
        cout << "exception (standar C++)" << endl;
        cout << "  +-- runtime_error" << endl;
        cout << "      +-- AppException           <- base semua app error" << endl;
        cout << "          +-- ValidationError    <- error validasi input" << endl;
        cout << "          +-- NetworkError       <- error jaringan" << endl;
        cout << "          |   +-- TimeoutError   <- timeout" << endl;
        cout << "          |   +-- ConnectionError<- gagal konek" << endl;
        cout << "          +-- DatabaseError      <- error database" << endl;
        cout << "              +-- QueryError     <- query gagal" << endl;
        cout << "              +-- TransactionError <- transaksi gagal" << endl;

        cout << endl << "Fleksibilitas catch:" << endl;
        cout << "  catch (const ValidationError&) -> hanya validasi" << endl;
        cout << "  catch (const NetworkError&)    -> semua network" << endl;
        cout << "  catch (const AppException&)    -> semua app error" << endl;
        cout << "  catch (const exception&)       -> semua exception C++" << endl;

    return 0;
}

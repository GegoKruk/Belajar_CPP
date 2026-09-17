#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// 1. Regular Function
int tambah(int a, int b) {
    return a + b;
}

// 2. Functor (Objek dengan operator())
struct KaliFunctor {
    int operator()(int a, int b) {
        return a * b;
    }
};

// 3. std::function sebagai Parameter (Callback Pattern)
void prosesData(const vector<int>& data, function<void(int)> aksi) {
    for (int x : data) {
        aksi(x);
    }
    cout << "\n";
}

void demoStdFunctionDasar() {
    cout << "--- std::function Menyimpan Berbagai Callable ---\n";

    function<int(int, int)> operasi;

    // Menyimpan regular function
    operasi = tambah;
    cout << "Fungsi biasa (Tambah 5+3): " << operasi(5, 3) << "\n";

    // Menyimpan lambda
    operasi = [](int a, int b) { return a - b; };
    cout << "Lambda (Kurang 5-3): " << operasi(5, 3) << "\n";

    // Menyimpan functor
    KaliFunctor kali;
    operasi = kali;
    cout << "Functor (Kali 5*3): " << operasi(5, 3) << "\n\n";
}

void demoFunctionParameter() {
    cout << "--- std::function Sebagai Parameter ---\n";
    vector<int> angka = {1, 2, 3, 4, 5};

    cout << "Print elemen langsung: ";
    prosesData(angka, [](int x) { cout << x << " "; });

    int total = 0;
    // Menggunakan lambda dengan capture
    prosesData(angka, [&total](int x) { total += x; });
    cout << "Hasil kalkulasi via capture (Total): " << total << "\n\n";
}

void demoEmptyFunction() {
    cout << "--- std::function Kosong ---\n";
    function<void()> fungsiKosong; // Belum diinisialisasi

    if (!fungsiKosong) {
        cout << "Fungsi kosong, belum memiliki target untuk dipanggil.\n";
    }

    try {
        fungsiKosong(); // Akan melempar error
    } catch (const bad_function_call& e) {
        cout << "Error berhasil ditangkap: " << e.what() << "\n\n";
    }
}

void demoBind() {
    cout << "--- std::bind (Partial Application) ---\n";
    // Mengikat argumen kedua dengan nilai 10 secara permanen
    auto tambahSepuluh = bind(tambah, placeholders::_1, 10);
    
    cout << "Bind tambah 10 pada angka 5: " << tambahSepuluh(5) << "\n\n";
}

int main() {
    cout << "=====================================\n";
    cout << "          08 - std::function         \n";
    cout << "=====================================\n\n";

    demoStdFunctionDasar();
    demoFunctionParameter();
    demoEmptyFunction();
    demoBind();

    return 0;
}
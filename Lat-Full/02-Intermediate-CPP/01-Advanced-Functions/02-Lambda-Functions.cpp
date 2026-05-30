#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // -------------------------------------------------------
    // LAMBDA PALING SEDERHANA
    // -------------------------------------------------------
    cout << "=== Lambda Dasar ===" << endl;

    auto sapa = [] { cout << "  Halo dari lambda!" << endl; };
    sapa();

    auto cetak = [](string pesan) { cout << "  " << pesan << endl; };
    cetak("Lambda dengan parameter string");

    auto kuadrat = [](int x) { return x * x; };
    cout << "  kuadrat(7) = " << kuadrat(7) << endl;

    auto bagi = [](double a, double b) -> double {
        if (b == 0) return 0;
        return a / b;
    };
    cout << "  bagi(10.0, 4.0) = " << bagi(10.0, 4.0) << endl;

    // -------------------------------------------------------
    // LAMBDA DIPANGGIL LANGSUNG (IIFE)
    // -------------------------------------------------------
    cout << "\n=== IIFE (Immediately Invoked) ===" << endl;

    int hasilLangsung = [](int a, int b) { return a + b; }(15, 25);
    cout << "  hasilLangsung = " << hasilLangsung << endl;

    // Berguna untuk inisialisasi const yang kompleks
    const string kategori = [](int nilai) -> string {
        if (nilai >= 90) return "A";
        if (nilai >= 80) return "B";
        if (nilai >= 70) return "C";
        return "D";
    }(85);
    cout << "  kategori nilai 85 = " << kategori << endl;

    // -------------------------------------------------------
    // LAMBDA DISIMPAN KE VARIABEL (auto)
    // -------------------------------------------------------
    cout << "\n=== Lambda Disimpan ke auto ===" << endl;

    auto ganjil = [](int x) { return x % 2 != 0; };
    auto genap  = [](int x) { return x % 2 == 0; };
    auto positif = [](int x) { return x > 0; };

    for (int i = -2; i <= 4; i++) {
        cout << "  " << i
             << " | ganjil=" << ganjil(i)
             << " | genap="  << genap(i)
             << " | positif=" << positif(i) << endl;
    }

    // -------------------------------------------------------
    // LAMBDA DENGAN STL: sort
    // -------------------------------------------------------
    cout << "\n=== Lambda + sort ===" << endl;

    vector<int> angka = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    cout << "  asli    : ";
    for (int x : angka) cout << x << " ";
    cout << endl;

    sort(angka.begin(), angka.end(), [](int a, int b) { return a < b; });
    cout << "  asc     : ";
    for (int x : angka) cout << x << " ";
    cout << endl;

    sort(angka.begin(), angka.end(), [](int a, int b) { return a > b; });
    cout << "  desc    : ";
    for (int x : angka) cout << x << " ";
    cout << endl;

    // Sort string berdasarkan panjang
    vector<string> kata = {"apel", "mangga", "jeruk", "pisang", "anggur"};
    sort(kata.begin(), kata.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
    cout << "  kata (pendek->panjang): ";
    for (const string &k : kata) cout << k << " ";
    cout << endl;

    // -------------------------------------------------------
    // LAMBDA DENGAN STL: find_if
    // -------------------------------------------------------
    cout << "\n=== Lambda + find_if ===" << endl;

    vector<int> data = {3, 7, 2, 15, 8, 20, 1};
    auto it = find_if(data.begin(), data.end(), [](int x) { return x > 10; });
    if (it != data.end())
        cout << "  Pertama > 10: " << *it << endl;

    auto it2 = find_if(data.begin(), data.end(), [](int x) { return x % 5 == 0; });
    if (it2 != data.end())
        cout << "  Pertama kelipatan 5: " << *it2 << endl;

    // -------------------------------------------------------
    // LAMBDA DENGAN STL: for_each
    // -------------------------------------------------------
    cout << "\n=== Lambda + for_each ===" << endl;

    int jumlah = 0;
    int cacahGanjil = 0;

    for_each(data.begin(), data.end(), [&jumlah, &cacahGanjil](int x) {
        jumlah += x;
        if (x % 2 != 0) cacahGanjil++;
    });
    cout << "  Jumlah total  : " << jumlah      << endl;
    cout << "  Cacah ganjil  : " << cacahGanjil << endl;

    // -------------------------------------------------------
    // LAMBDA REKURSIF (perlu std::function)
    // -------------------------------------------------------
    cout << "\n=== Lambda Rekursif ===" << endl;

    // Lambda tidak bisa memanggil dirinya sendiri langsung via 'auto'.
    // Perlu function<> atau trik Y-combinator.
    // Cara paling mudah: gunakan function<>
    function<int(int)> faktorial = [&faktorial](int n) -> int {
        return (n <= 1) ? 1 : n * faktorial(n - 1);
    };
    cout << "  faktorial(5) = " << faktorial(5) << endl;
    cout << "  faktorial(7) = " << faktorial(7) << endl;

    // -------------------------------------------------------
    // GENERIC LAMBDA (C++14)
    // -------------------------------------------------------
    cout << "\n=== Generic Lambda (C++14) ===" << endl;

    // Pakai 'auto' sebagai tipe parameter -> seperti mini-template
    auto cetakTipe = [](auto nilai) {
        cout << "  nilai: " << nilai << endl;
    };
    cetakTipe(42);
    cetakTipe(3.14);
    cetakTipe(string("halo"));

    auto tambahGenerik = [](auto a, auto b) { return a + b; };
    cout << "  tambah(3, 4)     = " << tambahGenerik(3, 4)         << endl;
    cout << "  tambah(1.5, 2.5) = " << tambahGenerik(1.5, 2.5)     << endl;

    return 0;
}

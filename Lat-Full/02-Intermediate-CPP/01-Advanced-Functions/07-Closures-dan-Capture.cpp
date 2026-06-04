#include <iostream>
#include <string>
#include <memory>

using namespace std;

void demoCaptureValueVsRef() {
    int batas = 10;

    // Capture by value: menyimpan salinan nilai saat lambda dibuat
    auto cekValue = [batas](int x) { return x < batas; };
    
    // Capture by reference: mengacu langsung pada variabel asli
    auto cekRef = [&batas](int x) { return x < batas; };

    batas = 99; // Mengubah nilai asli

    cout << "--- Capture Value vs Reference ---\n";
    cout << "Cek angka 5 dengan Value (batas tetap 10): " << (cekValue(5) ? "True" : "False") << "\n";
    cout << "Cek angka 5 dengan Ref (batas ikut jadi 99): " << (cekRef(5) ? "True" : "False") << "\n\n";
}

void demoMutableLambda() {
    int counter = 0;

    // Default lambda capture by value bersifat konstan. 
    // Keyword 'mutable' memungkinkan salinan tersebut dimodifikasi di dalam lambda.
    auto hitung = [counter]() mutable {
        counter++;
        cout << "Counter di dalam lambda: " << counter << "\n";
    };

    cout << "--- Mutable Lambda ---\n";
    hitung();
    hitung();
    cout << "Counter asli di luar lambda: " << counter << " (tidak berubah)\n\n";
}

void demoGeneralizedCapture() {
    // Unique pointer tidak bisa di-copy, harus di-move
    auto ptr = make_unique<int>(42);

    // Init capture (C++14): memindahkan ownership ke dalam lambda
    auto tampilkan = [p = move(ptr)]() {
        cout << "Nilai dari smart pointer: " << *p << "\n";
    };

    cout << "--- Generalized Capture (C++14) ---\n";
    tampilkan();
    cout << "\n";
}

int main() {
    cout << "=====================================\n";
    cout << "       07 - CLOSURES & CAPTURE       \n";
    cout << "=====================================\n\n";

    demoCaptureValueVsRef();
    demoMutableLambda();
    demoGeneralizedCapture();

    return 0;
}
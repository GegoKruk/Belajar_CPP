#include <iostream>
using namespace std;

void komentar(){
    cout << endl << "========== Komentar (Comments) ==========" << endl;
    
    // Single-line comment: Komentar satu baris
    cout << "1. Single-Line Comment (//)" << endl;
    cout << "   Contoh: // Ini adalah komentar satu baris" << endl;
    
    /* 
        Multi-line comment:
        Komentar bisa lebih dari satu baris
        Berguna untuk dokumentasi panjang
    */
    cout << endl << "2. Multi-Line Comment (/* */)" << endl;
    cout << "   Contoh: /* Komentar" << endl;
    cout << "              multi baris */" << endl;
    
    // Contoh penggunaan komentar yang baik
    cout << endl << "3. Contoh Penggunaan:" << endl;
    
    // TODO: Tambahkan validasi input
    int nilaiUjian = 85; // Nilai minimal kelulusan adalah 75
    
    cout << "   Nilai Ujian: " << nilaiUjian << endl;
    
    // Formula: Nilai Akhir = (Nilai Ujian × 60%) + (Nilai Tugas × 40%)
    double nilaiTugas = 90;
    double nilaiAkhir = (nilaiUjian * 0.6) + (nilaiTugas * 0.4);
    
    cout << "   Nilai Akhir: " << nilaiAkhir << endl;
    
    cout << endl << "Tips: Komentar yang baik menjelaskan KENAPA, bukan APA" << endl;
    cout << "   Good: // Gunakan 0.6 karena bobot UTS 60% dari total" << endl;
    cout << "   Bad:  // Mengalikan dengan 0.6" << endl;
}

int main(){

    komentar();

    return 0;
}
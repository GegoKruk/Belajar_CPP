
#include <iostream>
#include <string>
using namespace std;


// ----- Demonstrasi: Pass by Ref vs Pointer -----
   void ubahViaRef(int& x, int nilaiBaru) {
      x = nilaiBaru;
   }

   void ubahViaPtr(int* ptr, int nilaiBaru) {
      if (ptr != nullptr) {
         *ptr = nilaiBaru;
      }
   }

// ----- Simulasi Node Linked List (pointer) -----
   struct Node {
      int   data;
      Node* next;   // pointer ke node berikutnya, bisa nullptr
   };


int main() {

    // ----- 1. Syntax Dasar: Pointer vs Reference -----
      cout << "=== 1. Syntax: Pointer vs Reference ===" << endl;

      int angka = 42;

      int* ptr = &angka;   // pointer
      int& ref = angka;    // reference

      cout << "angka = " << angka << endl;
      cout << endl;
      cout << "Via Pointer :" << endl;
      cout << "  ptr  = " << ptr  << " (isi = alamat)" << endl;
      cout << "  *ptr = " << *ptr << " (deref untuk nilai)" << endl;

      cout << "Via Reference :" << endl;
      cout << "  ref  = " << ref  << " (langsung nilai, tidak perlu deref)" << endl;
      cout << "  &ref = " << &ref << " (sama dengan &angka)" << endl;


    // ----- 2. Perbedaan Null dan Reassign -----
      cout << endl << "=== 2. Null dan Reassign ===" << endl;

      int lain = 99;

      // Pointer bisa null
      int* pNull = nullptr;
      cout << "Pointer bisa nullptr: pNull = " << pNull << endl;
      // int& rNull;  // ERROR - reference tidak bisa null/kosong

      // Pointer bisa reassign
      int* p = &angka;
      cout << "Sebelum reassign: *p = " << *p << endl;
      p = &lain;   // pindah ke variabel lain
      cout << "Setelah reassign: *p = " << *p << " (pindah ke lain)" << endl;

      // Reference tidak bisa reassign
      int& r = angka;
      r = lain;    // INI bukan reassign! Ini copy nilai lain ke angka
      cout << "r = lain -> bukan reassign, angka = " << angka << " (nilai lain dicopy ke angka)" << endl;


    // ----- 3. Pass by Ref vs Pass by Pointer -----
      cout << endl << "=== 3. Pass by Ref vs Pass by Pointer ===" << endl;

      int nilai = 10;

      ubahViaRef(nilai, 55);
      cout << "ubahViaRef(nilai, 55) -> nilai = " << nilai << endl;

      angka = 10;   // reset
      ubahViaPtr(&angka, 77);
      cout << "ubahViaPtr(&angka, 77) -> angka = " << angka << endl;

      cout << endl;
      cout << "Perbedaan cara pemanggilan:" << endl;
      cout << "  By ref : ubahViaRef(nilai, 55)    <- syntax lebih bersih" << endl;
      cout << "  By ptr : ubahViaPtr(&angka, 77)   <- perlu & eksplisit" << endl;


    // ----- 4. Pointer untuk Nullable (use case linked list) -----
      cout << endl << "=== 4. Pointer untuk Nullable ===" << endl;

      Node n1 = {10, nullptr};
      Node n2 = {20, nullptr};
      Node n3 = {30, nullptr};

      n1.next = &n2;
      n2.next = &n3;

      cout << "Linked list: 10 -> 20 -> 30 -> nullptr" << endl;
      cout << "Traversal: ";
      Node* curr = &n1;
      while (curr != nullptr) {
         cout << curr->data;
         if (curr->next != nullptr) cout << " -> ";
         curr = curr->next;
      }
      cout << " -> nullptr" << endl;
      cout << "(nullptr menandai akhir list - tidak bisa dilakukan dengan reference!)" << endl;


    // ----- 5. Pointer ke Pointer -----
      cout << endl << "=== 5. Pointer ke Pointer (int**) ===" << endl;

      int  x    = 10;
      int* px   = &x;
      int** ppx = &px;

      cout << "x     = " << x     << endl;
      cout << "*px   = " << *px   << " (via ptr satu level)" << endl;
      cout << "**ppx = " << **ppx << " (via ptr dua level)" << endl;

      **ppx = 88;
      cout << "Setelah **ppx = 88: x = " << x << endl;


    // ----- 6. Tabel Keputusan -----
      cout << endl << "=== 6. Tabel Keputusan Kapan Pakai Apa ===" << endl;

      cout << "Kebutuhan                | Solusi      | Alasan" << endl;
      cout << "-------------------------+-------------+-------------------------------" << endl;
      cout << "Alias sederhana          | Reference   | Bersih, tidak bisa null" << endl;
      cout << "Nullable (tidak ada)     | Pointer     | ptr = nullptr memungkinkan" << endl;
      cout << "Ubah target nanti        | Pointer     | Bisa arahkan ulang" << endl;
      cout << "Pass arg & ubahnya       | Reference   | Syntax lebih simpel" << endl;
      cout << "Pass arg, baca saja      | const ref   | Efisien + aman" << endl;
      cout << "Dynamic memory (new)     | Pointer     | new/delete hanya via pointer" << endl;
      cout << "Iterasi array manual     | Pointer     | Pointer arithmetic" << endl;
      cout << "Return lebih dari 1 val  | Reference   | Lebih idiomatik" << endl;
      cout << "Data structure (list)    | Pointer     | Node* next, bisa nullptr" << endl;

      cout << endl;
      cout << "Aturan praktis:" << endl;
      cout << "  Gunakan reference secara default." << endl;
      cout << "  Gunakan pointer hanya kalau reference tidak bisa melakukannya." << endl;

   return 0;
}

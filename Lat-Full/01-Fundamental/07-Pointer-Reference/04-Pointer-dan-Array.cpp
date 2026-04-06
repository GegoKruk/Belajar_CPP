
#include <iostream>
#include <cstring>
using namespace std;

// Demonstrasi array decay di function
    void demonstrasiDecay(int arr[], int size) {
        cout << "  Di dalam function:" << endl;
        cout << "  sizeof(arr)  = " << sizeof(arr) << " byte (ukuran POINTER, bukan array!)" << endl;
        cout << "  Makanya wajib kirim 'size' = " << size << " sebagai parameter terpisah" << endl;
    }

int main() {

    // ----- 1. Nama Array = Pointer ke Elemen Pertama -----
        cout << "=== 1. Nama Array = Pointer ke Elemen Pertama ===" << endl;

        int arr[5] = {10, 20, 30, 40, 50};

        cout << "arr         = " << arr    << " (alamat elemen 0)" << endl;
        cout << "&arr[0]     = " << &arr[0]<< " (sama!)" << endl;
        cout << "*arr        = " << *arr   << " (nilai elemen 0)" << endl;
        cout << "*(arr + 1)  = " << *(arr+1)<< " (nilai elemen 1)" << endl;
        cout << "*(arr + 4)  = " << *(arr+4)<< " (nilai elemen 4)" << endl;

        cout << endl;
        cout << "Ekspresi yang SAMA untuk arr[2]:" << endl;
        cout << "  arr[2]      = " << arr[2]      << endl;
        cout << "  *(arr + 2)  = " << *(arr + 2)  << endl;
        cout << "  *(2 + arr)  = " << *(2 + arr)  << " (matematika commutative)" << endl;
        cout << "  2[arr]      = " << 2[arr]       << " (trik - jangan pakai ini)" << endl;


    // ----- 2. Pointer Diarahkan ke Array -----
        cout << endl << "=== 2. Pointer Diarahkan ke Array ===" << endl;

        int* ptr = arr;   // ptr menunjuk ke arr[0]

        cout << "Akses via ptr[i] (notasi index):" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  ptr[" << i << "] = " << ptr[i] << endl;
        }

        cout << "Akses via *(ptr + i) (pointer arithmetic):" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "  *(ptr + " << i << ") = " << *(ptr + i) << endl;
        }


    // ----- 3. Array Decay di Function -----
        cout << endl << "=== 3. Array Decay di Function ===" << endl;

        cout << "sizeof(arr) di main = " << sizeof(arr) << " byte (benar: 5 x 4)" << endl;
        int panjang = sizeof(arr) / sizeof(arr[0]);
        cout << "Panjang array       = " << panjang << " elemen" << endl;
        demonstrasiDecay(arr, panjang);


    // ----- 4. Perbedaan Pointer dan Array -----
        cout << endl << "=== 4. Perbedaan Pointer dan Array ===" << endl;

        int data[4] = {1, 2, 3, 4};
        int* pData  = data;

        cout << "sizeof(data)  = " << sizeof(data)  << " byte (total array)" << endl;
        cout << "sizeof(pData) = " << sizeof(pData) << " byte (hanya pointer)" << endl;

        // Pointer bisa diubah arah, array tidak
        int lain[4] = {5, 6, 7, 8};
        pData = lain;   // OK, pointer bisa reassign
        // data = lain; // TIDAK BISA - error compile

        cout << "pData diubah ke array lain, *pData = " << *pData << endl;

        // Pointer bisa di-increment, array tidak
        pData++;         // OK
        // data++;       // TIDAK BISA - error compile
        cout << "pData++ -> *pData = " << *pData << endl;


    // ----- 5. Pointer ke C-Style String -----
        cout << endl << "=== 5. Pointer ke C-Style String ===" << endl;

        char nama[] = "Gega";
        char* pChar = nama;    // menunjuk ke 'G'

        cout << "pChar = " << pChar  << " (tampil sampai null terminator)" << endl;
        cout << "*pChar = " << *pChar << " (satu karakter)" << endl;

        pChar++;   // geser ke 'e'
        cout << "Setelah pChar++:" << endl;
        cout << "  *pChar = " << *pChar << " (karakter berikutnya)" << endl;
        cout << "  pChar  = " << pChar  << " (sisa string dari posisi ini)" << endl;

        // Iterasi karakter dengan pointer
        cout << endl << "Iterasi karakter per karakter:" << endl;
        pChar = nama;   // kembalikan ke awal
        while (*pChar != '\0') {
            cout << "  " << *pChar;
            pChar++;
        }
        cout << endl;


    // ----- 6. Notasi Ekuivalen -----
        cout << endl << "=== 6. Notasi Ekuivalen: arr[i] == *(arr+i) ===" << endl;

        int nums[5] = {100, 200, 300, 400, 500};
        int* pNums  = nums;

        cout << "i   arr[i]  *(arr+i)  ptr[i]  *(ptr+i)" << endl;
        cout << "--- ------  --------  ------  --------" << endl;
        for (int i = 0; i < 5; i++) {
            cout << i << "   "
                << nums[i]      << "     "
                << *(nums + i)  << "       "
                << pNums[i]     << "     "
                << *(pNums + i) << endl;
        }

    return 0;
}

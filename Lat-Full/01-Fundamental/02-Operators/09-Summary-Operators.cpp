#include <iostream>
#include <string>
using namespace std;

void ringkasanOperator() {
    cout << "\n========== Ringkasan Semua Operator C++ ==========" << endl;

    cout << R"(
        KATEGORI          OPERATOR                CONTOH / KETERANGAN
        -----------------------------------------------------------------
        Aritmatika        +  -  *  /  %           a + b, a * b, a % b
        Penugasan         =  +=  -=  *=  /=  %=   x += 5  (x = x + 5)
        Bitwise assign    &= |= ^= <<= >>=        x &= mask
        Increment         ++  --                  x++, --y (post & pre)
        Perbandingan      ==  !=  <  <=  >  >=    a == b  -> bool
        Logika            &&  ||  !               A && B, !A, A || B
        Bitwise           &   |   ^   ~  <<  >>   5 & 3, 5 | 3, ~5
        Ternary           ?:                      cond ? val1 : val2
        sizeof            sizeof                  sizeof(int)  -> 4
        Koma              ,                       (a++, b++)   -> jarang
        -----------------------------------------------------------------
        Prioritas (tinggi -> rendah):
        Unary(! ~ ++) > * / % > + - > << >> > < <= > >= > == != >
        & > ^ > | > && > || > ?: > = += -= > ,
        -----------------------------------------------------------------
        ATURAN EMAS: Kalau ragu -> tambahkan kurung ()!
    )";
}

int main() {

    ringkasanOperator();

    return 0;
}

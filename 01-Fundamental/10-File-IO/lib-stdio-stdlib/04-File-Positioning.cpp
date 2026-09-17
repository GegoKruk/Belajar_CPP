/*
    04-File-Positioning.cpp
    -------------------------------------------------------
    Demonstrasi cara mengelola posisi kursor file:
        - ftell()  : dapatkan posisi kursor saat ini
        - fseek()  : pindah kursor ke posisi tertentu
        - rewind() : balik kursor ke awal file
        - Pola: hitung ukuran file
        - Pola: baca file dua kali
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("=== Demonstrasi File Positioning ===\n\n");


    // -------------------------------------------------------
    // Persiapan: buat file untuk keperluan demo
    // -------------------------------------------------------

    FILE* prep = fopen("04-demo-pos.txt", "w");
    if (prep == NULL) { perror("Gagal buat file"); return 1; }
    fprintf(prep, "ABCDEFGHIJ\n");   // 10 huruf + newline = 11 byte
    fprintf(prep, "1234567890\n");   // 10 angka + newline = 11 byte
    fclose(prep);

    printf("[SETUP] File '04-demo-pos.txt' berhasil dibuat.\n\n");


    // -------------------------------------------------------
    // BAGIAN 1: ftell() - lihat posisi kursor
    // -------------------------------------------------------

    printf("[1] ftell() - posisi kursor saat ini:\n");

    FILE* f = fopen("04-demo-pos.txt", "r");
    if (f == NULL) { perror("Gagal buka"); return 1; }

    printf("    Posisi setelah buka    : %ld\n", ftell(f));

    fgetc(f);
    printf("    Posisi setelah fgetc() : %ld\n", ftell(f));

    fgetc(f);
    fgetc(f);
    printf("    Posisi setelah 2x lagi : %ld\n", ftell(f));

    // Baca karakter keempat
    int c = fgetc(f);
    printf("    Karakter ke-4          : '%c' (posisi: %ld)\n",
           (char)c, ftell(f));

    fclose(f);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 2: fseek() dengan SEEK_SET
    // -------------------------------------------------------

    printf("[2] fseek() dengan SEEK_SET (dari awal file):\n");

    FILE* f2 = fopen("04-demo-pos.txt", "r");
    if (f2 == NULL) { perror("Gagal buka"); return 1; }

    // Langsung lompat ke byte ke-5 dari awal
    fseek(f2, 5, SEEK_SET);
    printf("    Baca dari posisi 5 (SEEK_SET): '%c'\n", (char)fgetc(f2));

    // Lompat ke byte ke-0 (awal)
    fseek(f2, 0, SEEK_SET);
    printf("    Baca dari posisi 0 (SEEK_SET): '%c'\n", (char)fgetc(f2));

    fclose(f2);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 3: fseek() dengan SEEK_CUR
    // -------------------------------------------------------

    printf("[3] fseek() dengan SEEK_CUR (dari posisi kini):\n");

    FILE* f3 = fopen("04-demo-pos.txt", "r");
    if (f3 == NULL) { perror("Gagal buka"); return 1; }

    // Baca karakter pertama
    printf("    Baca karakter pertama: '%c'\n", (char)fgetc(f3));

    // Skip 3 karakter ke depan dari posisi saat ini
    fseek(f3, 3, SEEK_CUR);
    printf("    Setelah skip 3 ke depan: '%c'\n", (char)fgetc(f3));

    // Mundur 2 karakter dari posisi saat ini
    fseek(f3, -2, SEEK_CUR);
    printf("    Setelah mundur 2: '%c'\n", (char)fgetc(f3));

    fclose(f3);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 4: fseek() dengan SEEK_END
    // -------------------------------------------------------

    printf("[4] fseek() dengan SEEK_END (dari akhir file):\n");

    FILE* f4 = fopen("04-demo-pos.txt", "r");
    if (f4 == NULL) { perror("Gagal buka"); return 1; }

    // Pindah ke akhir file
    fseek(f4, 0, SEEK_END);
    printf("    Posisi akhir file: %ld byte\n", ftell(f4));

    // Mundur 2 dari akhir (karakter sebelum newline terakhir)
    fseek(f4, -2, SEEK_END);
    printf("    2 karakter sebelum akhir: '%c'\n", (char)fgetc(f4));

    fclose(f4);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 5: rewind() - balik ke awal
    // -------------------------------------------------------

    printf("[5] rewind() - balik ke awal file:\n");

    FILE* f5 = fopen("04-demo-pos.txt", "r");
    if (f5 == NULL) { perror("Gagal buka"); return 1; }

    // Baca beberapa karakter
    char buf[20];
    fgets(buf, sizeof(buf), f5);
    printf("    Baris pertama: %s", buf);
    printf("    Posisi sekarang: %ld\n", ftell(f5));

    // Balik ke awal dengan rewind()
    rewind(f5);
    printf("    Posisi setelah rewind(): %ld\n", ftell(f5));

    // Baca lagi dari awal
    char buf2[20];
    fgets(buf2, sizeof(buf2), f5);
    printf("    Baris pertama (dibaca ulang): %s", buf2);

    fclose(f5);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 6: Pola hitung ukuran file
    // -------------------------------------------------------

    printf("[6] Pola hitung ukuran file dengan fseek + ftell:\n");

    FILE* f6 = fopen("04-demo-pos.txt", "rb");
    if (f6 == NULL) { perror("Gagal buka"); return 1; }

    fseek(f6, 0, SEEK_END);       // pindah ke akhir file
    long ukuran = ftell(f6);      // posisi = ukuran total
    rewind(f6);                   // balik ke awal

    printf("    Ukuran file '04-demo-pos.txt': %ld byte\n", ukuran);
    fclose(f6);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 7: Pola baca file dua kali dengan rewind
    // -------------------------------------------------------

    printf("[7] Baca file dua kali menggunakan rewind():\n");

    FILE* f7 = fopen("04-demo-pos.txt", "r");
    if (f7 == NULL) { perror("Gagal buka"); return 1; }

    int jumlah_baris = 0;
    char baris[256];

    // Bacaan pertama: hitung jumlah baris
    while (fgets(baris, sizeof(baris), f7) != NULL) {
        jumlah_baris++;
    }
    printf("    Bacaan ke-1: file punya %d baris.\n", jumlah_baris);

    // Balik ke awal
    rewind(f7);

    // Bacaan kedua: tampilkan isinya
    printf("    Bacaan ke-2: isi file:\n");
    while (fgets(baris, sizeof(baris), f7) != NULL) {
        printf("    > %s", baris);
    }

    fclose(f7);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 8: Update data di tengah file dengan fseek
    // -------------------------------------------------------

    printf("[8] Update karakter tertentu di tengah file dengan fseek:\n");

    // Buat file baru
    FILE* fw = fopen("04-update.txt", "w");
    fprintf(fw, "Nilai: 00\n");   // placeholder "00" yang akan kita update
    fclose(fw);

    printf("    Isi awal : ");
    FILE* cek1 = fopen("04-update.txt", "r");
    fgets(baris, sizeof(baris), cek1);
    printf("%s", baris);
    fclose(cek1);

    // Buka dengan "r+" lalu lompat ke posisi "00"
    // "Nilai: " = 7 karakter, jadi "00" ada di posisi 7
    FILE* fu = fopen("04-update.txt", "r+");
    if (fu == NULL) { perror("Gagal"); return 1; }
    fseek(fu, 7, SEEK_SET);
    fprintf(fu, "95");   // ganti "00" dengan "95"
    fclose(fu);

    printf("    Setelah update: ");
    FILE* cek2 = fopen("04-update.txt", "r");
    fgets(baris, sizeof(baris), cek2);
    printf("%s", baris);
    fclose(cek2);

    printf("\n=== Selesai ===\n");
    return 0;
}

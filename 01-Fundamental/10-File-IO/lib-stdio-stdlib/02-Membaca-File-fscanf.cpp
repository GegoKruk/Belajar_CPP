/*
    02-Membaca-File-fscanf.cpp
    -------------------------------------------------------
    Demonstrasi cara membaca file teks menggunakan:
        - fscanf() untuk baca data terformat (token per token)
        - fgets()  untuk baca satu baris penuh (lebih aman)
        - fgetc()  untuk baca satu karakter
        - Penjelasan jebakan while(!feof())

    File ini membuat data dummy sendiri sebelum membacanya,
    sehingga bisa langsung dijalankan tanpa file eksternal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------------------------------
// Helper: buat file data dummy untuk keperluan demo
// -------------------------------------------------------
void buat_file_data() {
    FILE* f = fopen("02-data-angka.txt", "w");
    fprintf(f, "10 20 30 40 50\n");
    fprintf(f, "60 70 80\n");
    fclose(f);

    FILE* f2 = fopen("02-data-nama.txt", "w");
    fprintf(f2, "Budi 88\n");
    fprintf(f2, "Ani 95\n");
    fprintf(f2, "Candra 72\n");
    fclose(f2);

    FILE* f3 = fopen("02-data-baris.txt", "w");
    fprintf(f3, "Baris pertama dengan spasi di sini\n");
    fprintf(f3, "Baris kedua juga ada spasinya\n");
    fprintf(f3, "Baris ketiga terakhir\n");
    fclose(f3);
}

int main() {

    printf("=== Demonstrasi Membaca File (fscanf, fgets, fgetc) ===\n\n");

    // Siapkan file data terlebih dahulu
    buat_file_data();
    printf("[SETUP] File data berhasil dibuat.\n\n");


    // -------------------------------------------------------
    // CARA 1: fscanf() - baca token per token dengan format
    // -------------------------------------------------------

    printf("[1] fscanf() - baca angka per angka:\n");

    FILE* f1 = fopen("02-data-angka.txt", "r");
    if (f1 == NULL) { perror("Gagal buka"); return 1; }

    int angka;
    int jumlah = 0;
    int total  = 0;

    // Cek return value fscanf == 1 (berhasil baca 1 item)
    // JANGAN pakai while(!feof(f1)) - itu pola yang salah!
    while (fscanf(f1, "%d", &angka) == 1) {
        printf("    Terbaca: %d\n", angka);
        total += angka;
        jumlah++;
    }

    printf("    Jumlah data: %d | Total: %d | Rata-rata: %.1f\n\n",
           jumlah, total, (float)total / jumlah);

    fclose(f1);


    // -------------------------------------------------------
    // CARA 2: fscanf() - baca string dan integer berpasangan
    // -------------------------------------------------------

    printf("[2] fscanf() - baca nama dan nilai berpasangan:\n");

    FILE* f2 = fopen("02-data-nama.txt", "r");
    if (f2 == NULL) { perror("Gagal buka"); return 1; }

    char nama[50];
    int  nilai;

    // fscanf return 2 kalau berhasil baca 2 item (%s dan %d)
    while (fscanf(f2, "%49s %d", nama, &nilai) == 2) {
        printf("    Nama: %-10s | Nilai: %d\n", nama, nilai);
    }

    fclose(f2);
    printf("\n");


    // -------------------------------------------------------
    // CARA 3: fgets() - baca satu baris penuh
    // -------------------------------------------------------

    printf("[3] fgets() - baca baris per baris:\n");

    FILE* f3 = fopen("02-data-baris.txt", "r");
    if (f3 == NULL) { perror("Gagal buka"); return 1; }

    char baris[256];
    int nomor = 1;

    // fgets return NULL saat akhir file atau error
    while (fgets(baris, sizeof(baris), f3) != NULL) {
        // fgets menyertakan '\n' di akhir string
        // baris[strcspn(baris, "\n")] = '\0' untuk hilangkan '\n'
        baris[strcspn(baris, "\n")] = '\0';

        printf("    Baris %d: [%s]\n", nomor, baris);
        nomor++;
    }

    fclose(f3);
    printf("\n");


    // -------------------------------------------------------
    // CARA 4: fgetc() - baca satu karakter sekaligus
    // -------------------------------------------------------

    printf("[4] fgetc() - baca karakter per karakter dan hitung:\n");

    FILE* f4 = fopen("02-data-baris.txt", "r");
    if (f4 == NULL) { perror("Gagal buka"); return 1; }

    int c;
    int jumlah_huruf   = 0;
    int jumlah_spasi   = 0;
    int jumlah_newline = 0;

    // fgetc return int, bukan char!
    // EOF adalah -1, dan char mungkin tidak bisa simpan -1 di semua platform
    while ((c = fgetc(f4)) != EOF) {
        if (c == ' ')  jumlah_spasi++;
        else if (c == '\n') jumlah_newline++;
        else if (c >= 'a' && c <= 'z') jumlah_huruf++;
        else if (c >= 'A' && c <= 'Z') jumlah_huruf++;
    }

    printf("    Huruf  : %d\n", jumlah_huruf);
    printf("    Spasi  : %d\n", jumlah_spasi);
    printf("    Newline: %d\n", jumlah_newline);

    fclose(f4);
    printf("\n");


    // -------------------------------------------------------
    // DEMONSTRASI: Kenapa while(!feof) itu salah
    // -------------------------------------------------------

    printf("[5] Demonstrasi jebakan feof():\n");

    // Buat file dengan satu angka
    FILE* tmp = fopen("02-satu-angka.txt", "w");
    fprintf(tmp, "99\n");
    fclose(tmp);

    FILE* f5 = fopen("02-satu-angka.txt", "r");
    if (f5 == NULL) { perror("Gagal buka"); return 1; }

    printf("    [CARA BENAR] Cek return value fscanf:\n");
    int x;
    while (fscanf(f5, "%d", &x) == 1) {
        printf("    Terbaca: %d\n", x);
    }
    printf("    Loop berhenti tepat setelah data habis.\n\n");

    // Cara salah sengaja tidak didemonstrasikan di sini karena
    // bisa menghasilkan output ganda yang membingungkan.
    // Penjelasannya sudah ada di 00-0-Materi.cpp.

    fclose(f5);

    printf("=== Selesai ===\n");
    return 0;
}

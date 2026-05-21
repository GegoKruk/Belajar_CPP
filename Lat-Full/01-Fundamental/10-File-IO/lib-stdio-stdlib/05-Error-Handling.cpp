/*
    05-Error-Handling.cpp
    -------------------------------------------------------
    Demonstrasi penanganan error saat File I/O di C:
        - Pengecekan NULL dari fopen()
        - perror()   : cetak pesan error sistem
        - ferror()   : cek error I/O setelah operasi
        - feof()     : cek akhir file
        - clearerr() : reset flag error dan EOF
        - Pola error handling yang lengkap dan aman
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {

    printf("=== Demonstrasi Error Handling File I/O ===\n\n");


    // -------------------------------------------------------
    // BAGIAN 1: Pengecekan NULL dari fopen()
    // -------------------------------------------------------

    printf("[1] fopen() gagal karena file tidak ada (mode 'r'):\n");

    FILE* f1 = fopen("file-yang-tidak-ada.txt", "r");
    if (f1 == NULL) {
        // perror() otomatis cetak deskripsi error dari sistem
        perror("    perror() mengatakan");

        // errno berisi kode error numerik
        printf("    Kode errno: %d\n", errno);
        printf("    fopen() return NULL -> kita aman karena cek NULL.\n");
    }
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 2: perror() untuk berbagai situasi
    // -------------------------------------------------------

    printf("[2] Demonstrasi perror() dengan berbagai pesan:\n");

    // Coba buka file di direktori yang tidak ada
    FILE* f2 = fopen("/direktori/palsu/data.txt", "w");
    if (f2 == NULL) {
        perror("    Buka ke direktori tidak ada");
    }

    // Coba buka tanpa nama file (string kosong)
    FILE* f3 = fopen("", "r");
    if (f3 == NULL) {
        perror("    Buka dengan nama kosong");
    }

    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 3: ferror() - cek error I/O setelah operasi baca
    // -------------------------------------------------------

    printf("[3] ferror() - cek status error setelah operasi:\n");

    // Buat file dulu untuk dipakai
    FILE* prep = fopen("05-demo.txt", "w");
    fprintf(prep, "Data baris satu.\n");
    fprintf(prep, "Data baris dua.\n");
    fclose(prep);

    FILE* f4 = fopen("05-demo.txt", "r");
    if (f4 == NULL) { perror("Gagal buka"); return 1; }

    char baris[256];
    while (fgets(baris, sizeof(baris), f4) != NULL) {
        printf("    Dibaca: %s", baris);
    }

    // Cek apakah loop berhenti karena EOF atau karena error
    if (feof(f4)) {
        printf("    Loop berhenti karena EOF (normal, tidak ada error).\n");
    }
    if (ferror(f4)) {
        printf("    Ada error I/O saat membaca!\n");
    }

    fclose(f4);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 4: feof() - mendeteksi akhir file
    // -------------------------------------------------------

    printf("[4] feof() - deteksi akhir file:\n");

    FILE* f5 = fopen("05-demo.txt", "r");
    if (f5 == NULL) { perror("Gagal buka"); return 1; }

    printf("    feof() setelah buka (belum baca): %d\n", feof(f5));

    // Baca sampai habis
    while (fgets(baris, sizeof(baris), f5) != NULL) { }

    printf("    feof() setelah semua data terbaca: %d\n", feof(f5));
    printf("    (nonzero = sudah di akhir file)\n");

    fclose(f5);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 5: clearerr() - reset flag error dan EOF
    // -------------------------------------------------------

    printf("[5] clearerr() - reset flag setelah EOF:\n");

    FILE* f6 = fopen("05-demo.txt", "r");
    if (f6 == NULL) { perror("Gagal buka"); return 1; }

    // Baca sampai EOF
    while (fgetc(f6) != EOF) { }

    printf("    feof() sebelum clearerr: %d\n", feof(f6));

    // Reset flag
    clearerr(f6);
    printf("    feof() setelah clearerr: %d\n", feof(f6));

    // Sekarang bisa rewind dan baca lagi
    rewind(f6);
    printf("    Baca ulang setelah clearerr + rewind:\n");
    while (fgets(baris, sizeof(baris), f6) != NULL) {
        printf("    > %s", baris);
    }

    fclose(f6);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 6: Pola error handling lengkap dan aman
    // -------------------------------------------------------

    printf("[6] Pola error handling lengkap:\n");

    // Fungsi ini menunjukkan pola yang benar:
    // buka -> cek NULL -> proses -> cek ferror -> tutup

    const char* target = "05-demo.txt";
    FILE* f7 = fopen(target, "r");

    if (f7 == NULL) {
        // Gagal di tahap buka
        fprintf(stderr, "    GAGAL: Tidak bisa buka '%s': ", target);
        perror("");   // perror("") cetak hanya pesan sistem tanpa prefix
        return 1;
    }

    // Proses: baca dan hitung kata
    int jumlah_kata = 0;
    char kata[100];
    while (fscanf(f7, "%99s", kata) == 1) {
        jumlah_kata++;
    }

    // Cek apakah loop berhenti karena EOF atau error
    if (ferror(f7)) {
        fprintf(stderr, "    ERROR saat membaca: ");
        perror("");
        fclose(f7);
        return 1;
    }

    // EOF -> normal
    printf("    Berhasil baca '%s': %d kata ditemukan.\n",
           target, jumlah_kata);

    fclose(f7);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 7: Demonstrasi akibat TIDAK cek NULL (simulasi aman)
    // -------------------------------------------------------

    printf("[7] Pentingnya cek NULL:\n");
    printf("    Jika fopen() gagal dan kita TIDAK cek NULL:\n");
    printf("    -> fprintf(NULL, ...) -> CRASH (segmentation fault)\n");
    printf("    -> fgets(buf, n, NULL) -> CRASH\n");
    printf("    -> fclose(NULL) -> CRASH\n");
    printf("\n");
    printf("    Selalu lakukan:\n");
    printf("        FILE* f = fopen(...);\n");
    printf("        if (f == NULL) { perror(\"...\"); return 1; }\n");
    printf("        // baru lanjut operasi\n");

    printf("\n=== Selesai ===\n");
    return 0;
}

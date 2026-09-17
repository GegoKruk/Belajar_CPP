/*
    00-Overview.cpp
    -------------------------------------------------------
    Demonstrasi konsep dasar File I/O gaya C menggunakan
    stdio.h dan stdlib.h.

    Topik yang ditunjukkan:
        - Perbedaan FILE* dengan fstream
        - Siklus hidup file: fopen, operasi, fclose
        - Pengenalan fungsi-fungsi utama stdio
        - Mengapa pengecekan NULL itu wajib
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    // BAGIAN 1: Tulis file sederhana dengan fprintf

    printf("=== Demonstrasi Overview stdio File I/O ===\n\n");

    // Buka file untuk ditulis (mode "w" = write, overwrite)
    FILE* file_tulis = fopen("00-overview-output.txt", "w");

    // WAJIB: cek apakah fopen berhasil
    if (file_tulis == NULL) {
        perror("Gagal membuka file untuk ditulis");
        return 1;
    }

    // Tulis beberapa baris ke file
    fprintf(file_tulis, "Halo dari stdio!\n");
    fprintf(file_tulis, "Ini adalah File I/O gaya C.\n");
    fprintf(file_tulis, "Angka: %d\n", 42);
    fprintf(file_tulis, "Desimal: %.2f\n", 3.14);

    // WAJIB: tutup file setelah selesai
    fclose(file_tulis);
    printf("[1] File '00-overview-output.txt' berhasil ditulis.\n");


    // BAGIAN 2: Baca kembali file yang baru ditulis

    FILE* file_baca = fopen("00-overview-output.txt", "r");

    if (file_baca == NULL) {
        perror("Gagal membuka file untuk dibaca");
        return 1;
    }

    printf("\n[2] Isi file yang dibaca:\n");
    printf("    --------------------\n");

    char baris[256];
    while (fgets(baris, sizeof(baris), file_baca) != NULL) {
        printf("    %s", baris);   // baris sudah mengandung '\n'
    }

    printf("    --------------------\n");

    fclose(file_baca);


    // BAGIAN 3: Demonstrasi perbedaan gaya C vs C++

    printf("\n[3] Ringkasan perbedaan FILE* vs fstream:\n");
    printf("    FILE* pakai : fopen, fprintf, fscanf, fclose\n");
    printf("    fstream pakai: ofstream/ifstream, operator <<, >>, close()\n");
    printf("    FILE* tidak punya RAII -> fclose() HARUS manual\n");
    printf("    fstream punya RAII -> otomatis tutup saat keluar scope\n");


    // BAGIAN 4: Demonstrasi apa yang terjadi kalau file gagal dibuka

    printf("\n[4] Coba buka file yang tidak ada:\n");

    FILE* tidak_ada = fopen("file-yang-tidak-ada.xyz", "r");

    if (tidak_ada == NULL) {
        // perror() cetak pesan error sistem secara otomatis
        perror("    Hasil perror()");
        printf("    fopen() return NULL -> file tidak berhasil dibuka.\n");
        printf("    Program tidak crash karena kita cek NULL dulu.\n");
    }

    // tidak_ada adalah NULL, jadi tidak perlu fclose


    // BAGIAN 5: Menampilkan fungsi-fungsi utama yang akan dipelajari

    printf("\n[5] Fungsi-fungsi utama stdio.h:\n");
    printf("    fopen()    -> buka file\n");
    printf("    fclose()   -> tutup file\n");
    printf("    fprintf()  -> tulis dengan format\n");
    printf("    fputs()    -> tulis string\n");
    printf("    fputc()    -> tulis satu karakter\n");
    printf("    fscanf()   -> baca dengan format\n");
    printf("    fgets()    -> baca satu baris (AMAN)\n");
    printf("    fgetc()    -> baca satu karakter\n");
    printf("    fwrite()   -> tulis data binary\n");
    printf("    fread()    -> baca data binary\n");
    printf("    fseek()    -> pindah posisi kursor\n");
    printf("    ftell()    -> dapatkan posisi kursor\n");
    printf("    rewind()   -> balik ke awal file\n");
    printf("    feof()     -> cek akhir file\n");
    printf("    ferror()   -> cek error I/O\n");
    printf("    perror()   -> cetak pesan error sistem\n");

    printf("\n=== Selesai ===\n");
    return 0;
}

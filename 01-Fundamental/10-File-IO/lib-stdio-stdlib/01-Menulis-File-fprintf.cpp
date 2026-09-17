/*
    01-Menulis-File-fprintf.cpp
    -------------------------------------------------------
    Demonstrasi cara menulis file teks menggunakan:
        - fopen() dengan mode "w" dan "a"
        - fprintf() untuk menulis data terformat
        - fputs()  untuk menulis string
        - fputc()  untuk menulis satu karakter
        - fclose() untuk menutup file
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("=== Demonstrasi Menulis File dengan fprintf ===\n\n");


    // -------------------------------------------------------
    // BAGIAN 1: Menulis file baru (mode "w" = overwrite)
    // -------------------------------------------------------

    printf("[1] Menulis file baru dengan mode 'w'...\n");

    FILE* f = fopen("01-data-mahasiswa.txt", "w");
    if (f == NULL) {
        perror("Gagal membuka file");
        return 1;
    }

    // fprintf: seperti printf tapi outputnya ke file
    fprintf(f, "=== Data Mahasiswa ===\n");
    fprintf(f, "\n");

    // Tulis data dengan berbagai format specifier
    fprintf(f, "Nama  : %s\n",   "Budi Santoso");
    fprintf(f, "NIM   : %s\n",   "2023001");
    fprintf(f, "Nilai : %d\n",   88);
    fprintf(f, "IPK   : %.2f\n", 3.72);

    fprintf(f, "\n");
    fprintf(f, "Nama  : %s\n",   "Ani Rahayu");
    fprintf(f, "NIM   : %s\n",   "2023002");
    fprintf(f, "Nilai : %d\n",   95);
    fprintf(f, "IPK   : %.2f\n", 3.91);

    fclose(f);
    printf("    File '01-data-mahasiswa.txt' berhasil ditulis.\n\n");


    // -------------------------------------------------------
    // BAGIAN 2: fputs dan fputc sebagai alternatif
    // -------------------------------------------------------

    printf("[2] Menulis dengan fputs() dan fputc()...\n");

    FILE* f2 = fopen("01-demo-fputs.txt", "w");
    if (f2 == NULL) {
        perror("Gagal membuka file");
        return 1;
    }

    // fputs: tulis string, TIDAK tambah newline otomatis
    fputs("Baris pertama dengan fputs\n",   f2);
    fputs("Baris kedua dengan fputs\n",     f2);
    fputs("Tanpa newline ini nyambung",     f2);
    fputs(" dengan ini\n",                  f2);

    // fputc: tulis satu karakter
    fputc('A', f2);
    fputc('B', f2);
    fputc('C', f2);
    fputc('\n', f2);   // newline juga karakter

    fclose(f2);
    printf("    File '01-demo-fputs.txt' berhasil ditulis.\n\n");


    // -------------------------------------------------------
    // BAGIAN 3: Mode "a" (append) - tambah di akhir file
    // -------------------------------------------------------

    printf("[3] Demonstrasi mode 'a' (append)...\n");

    // Pertama, buat file dengan mode "w"
    FILE* f3 = fopen("01-log.txt", "w");
    if (f3 == NULL) { perror("Gagal"); return 1; }
    fprintf(f3, "[LOG] Baris awal saat file dibuat.\n");
    fclose(f3);

    // Lalu tambah isi dengan mode "a" (dua kali)
    FILE* f4 = fopen("01-log.txt", "a");
    if (f4 == NULL) { perror("Gagal"); return 1; }
    fprintf(f4, "[LOG] Baris tambahan pertama (append).\n");
    fclose(f4);

    FILE* f5 = fopen("01-log.txt", "a");
    if (f5 == NULL) { perror("Gagal"); return 1; }
    fprintf(f5, "[LOG] Baris tambahan kedua (append).\n");
    fclose(f5);

    printf("    File '01-log.txt' berhasil di-append 2 kali.\n\n");


    // -------------------------------------------------------
    // BAGIAN 4: Format angka yang lebih lengkap
    // -------------------------------------------------------

    printf("[4] Menulis file dengan berbagai format angka...\n");

    FILE* f6 = fopen("01-format-angka.txt", "w");
    if (f6 == NULL) { perror("Gagal"); return 1; }

    int    i    = 12345;
    float  fl   = 3.14159f;
    double db   = 2.718281828;
    char   c    = 'Z';
    char   str[] = "teks contoh";

    fprintf(f6, "Integer          : %d\n",    i);
    fprintf(f6, "Integer oktal    : %o\n",    i);
    fprintf(f6, "Integer hex      : %x\n",    i);
    fprintf(f6, "Float 2 desimal  : %.2f\n",  fl);
    fprintf(f6, "Float 5 desimal  : %.5f\n",  fl);
    fprintf(f6, "Double           : %.9f\n",  db);
    fprintf(f6, "Karakter         : %c\n",    c);
    fprintf(f6, "String           : %s\n",    str);
    fprintf(f6, "Lebar kolom 10   : %10d\n",  i);
    fprintf(f6, "Rata kiri lebar 10: %-10d|\n", i);

    fclose(f6);
    printf("    File '01-format-angka.txt' berhasil ditulis.\n\n");


    // -------------------------------------------------------
    // BAGIAN 5: Verifikasi - baca dan tampilkan isi file pertama
    // -------------------------------------------------------

    printf("[5] Isi file '01-data-mahasiswa.txt':\n");
    printf("    --------------------------------\n");

    FILE* cek = fopen("01-data-mahasiswa.txt", "r");
    if (cek == NULL) { perror("Gagal buka untuk verifikasi"); return 1; }

    char baris[256];
    while (fgets(baris, sizeof(baris), cek) != NULL) {
        printf("    %s", baris);
    }
    fclose(cek);

    printf("    --------------------------------\n");
    printf("\n=== Selesai ===\n");
    return 0;
}

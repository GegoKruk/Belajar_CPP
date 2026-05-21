/*
    03-Mode-Buka-File.cpp
    -------------------------------------------------------
    Demonstrasi semua mode string pada fopen():
        "r"   "w"   "a"
        "r+"  "w+"  "a+"
        "rb"  "wb"  (mode binary)

    Setiap mode didemonstrasikan secara nyata sehingga
    kamu bisa melihat efeknya secara langsung.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper: cetak isi file ke layar
void cetak_isi_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) {
        printf("    (file tidak ada atau tidak bisa dibaca)\n");
        return;
    }
    char baris[256];
    while (fgets(baris, sizeof(baris), f) != NULL) {
        printf("    > %s", baris);
    }
    fclose(f);
}

int main() {

    printf("=== Demonstrasi Mode Buka File fopen() ===\n\n");


    // -------------------------------------------------------
    // MODE "w" : Write (buat baru / overwrite)
    // -------------------------------------------------------

    printf("[MODE w] Buat file baru / overwrite isi lama:\n");

    FILE* fw = fopen("03-demo-mode.txt", "w");
    if (fw == NULL) { perror("Gagal"); return 1; }

    fprintf(fw, "Tulis pertama dengan mode w.\n");
    fprintf(fw, "Baris kedua.\n");
    fclose(fw);

    printf("    Setelah tulis pertama:\n");
    cetak_isi_file("03-demo-mode.txt");

    // Buka lagi dengan "w" -> isi lama DIHAPUS
    FILE* fw2 = fopen("03-demo-mode.txt", "w");
    if (fw2 == NULL) { perror("Gagal"); return 1; }
    fprintf(fw2, "Ini isi baru, isi lama sudah terhapus.\n");
    fclose(fw2);

    printf("    Setelah buka 'w' kedua kali (overwrite):\n");
    cetak_isi_file("03-demo-mode.txt");
    printf("\n");


    // -------------------------------------------------------
    // MODE "a" : Append (tambah di akhir)
    // -------------------------------------------------------

    printf("[MODE a] Append - tambah data di akhir tanpa hapus isi:\n");

    // Reset dulu dengan "w"
    FILE* reset = fopen("03-demo-append.txt", "w");
    fprintf(reset, "Baris awal.\n");
    fclose(reset);

    printf("    Isi awal:\n");
    cetak_isi_file("03-demo-append.txt");

    // Append dua kali
    FILE* fa1 = fopen("03-demo-append.txt", "a");
    if (fa1 == NULL) { perror("Gagal"); return 1; }
    fprintf(fa1, "Tambahan dari append ke-1.\n");
    fclose(fa1);

    FILE* fa2 = fopen("03-demo-append.txt", "a");
    if (fa2 == NULL) { perror("Gagal"); return 1; }
    fprintf(fa2, "Tambahan dari append ke-2.\n");
    fclose(fa2);

    printf("    Isi setelah dua kali append:\n");
    cetak_isi_file("03-demo-append.txt");
    printf("\n");


    // -------------------------------------------------------
    // MODE "r" : Read only (file harus ada)
    // -------------------------------------------------------

    printf("[MODE r] Read only - file harus sudah ada:\n");

    // Coba buka file yang ada
    FILE* fr = fopen("03-demo-append.txt", "r");
    if (fr == NULL) {
        perror("Gagal buka file yang ada");
    } else {
        printf("    File yang ada berhasil dibuka untuk dibaca.\n");
        fclose(fr);
    }

    // Coba buka file yang tidak ada
    FILE* fr_tidak_ada = fopen("file-tidak-ada-xyz.txt", "r");
    if (fr_tidak_ada == NULL) {
        printf("    File yang tidak ada -> fopen return NULL (wajar).\n");
        // perror("    Detail error");   // uncomment untuk lihat pesan error
    }
    printf("\n");


    // -------------------------------------------------------
    // MODE "r+" : Baca dan tulis, file HARUS ada
    // -------------------------------------------------------

    printf("[MODE r+] Baca dan tulis, file harus sudah ada:\n");

    // Buat file dulu
    FILE* prep = fopen("03-demo-rplus.txt", "w");
    fprintf(prep, "ABCDE\n");
    fclose(prep);

    // Buka dengan r+: bisa baca dan bisa tulis di posisi tertentu
    FILE* frplus = fopen("03-demo-rplus.txt", "r+");
    if (frplus == NULL) { perror("Gagal"); return 1; }

    // Baca dulu
    char buf[20];
    fgets(buf, sizeof(buf), frplus);
    printf("    Dibaca  : %s", buf);

    // Balik ke awal lalu tulis (overwrite karakter pertama)
    rewind(frplus);
    fputc('X', frplus);   // ganti 'A' jadi 'X'

    fclose(frplus);

    printf("    Setelah karakter pertama diganti:\n");
    cetak_isi_file("03-demo-rplus.txt");
    printf("\n");


    // -------------------------------------------------------
    // MODE "w+" : Baca dan tulis, hapus isi lama
    // -------------------------------------------------------

    printf("[MODE w+] Baca dan tulis, hapus isi lama:\n");

    FILE* fwplus = fopen("03-demo-wplus.txt", "w+");
    if (fwplus == NULL) { perror("Gagal"); return 1; }

    // Tulis dulu
    fprintf(fwplus, "Data yang baru ditulis.\n");

    // Balik ke awal lalu baca
    rewind(fwplus);
    char baca_buf[100];
    fgets(baca_buf, sizeof(baca_buf), fwplus);
    printf("    Langsung baca setelah tulis: %s", baca_buf);

    fclose(fwplus);
    printf("\n");


    // -------------------------------------------------------
    // MODE "a+" : Baca dan append
    // -------------------------------------------------------

    printf("[MODE a+] Baca dan append:\n");

    // Siapkan file
    FILE* prep2 = fopen("03-demo-aplus.txt", "w");
    fprintf(prep2, "Baris lama 1.\n");
    fprintf(prep2, "Baris lama 2.\n");
    fclose(prep2);

    FILE* faplus = fopen("03-demo-aplus.txt", "a+");
    if (faplus == NULL) { perror("Gagal"); return 1; }

    // Baca dari awal
    rewind(faplus);
    printf("    Baca isi lama:\n");
    char baris[256];
    while (fgets(baris, sizeof(baris), faplus) != NULL) {
        printf("    > %s", baris);
    }

    // Tulis selalu ke akhir meski fseek ke awal
    fprintf(faplus, "Baris baru dari a+.\n");
    fclose(faplus);

    printf("    Setelah tambah baris baru:\n");
    cetak_isi_file("03-demo-aplus.txt");
    printf("\n");


    // -------------------------------------------------------
    // MODE BINARY: "rb" dan "wb"
    // -------------------------------------------------------

    printf("[MODE rb/wb] Mode binary:\n");

    // Tulis beberapa integer sebagai binary
    FILE* fwb = fopen("03-demo.bin", "wb");
    if (fwb == NULL) { perror("Gagal"); return 1; }

    int data[5] = {10, 20, 30, 40, 50};
    fwrite(data, sizeof(int), 5, fwb);
    fclose(fwb);
    printf("    5 integer ditulis ke file binary.\n");

    // Baca kembali
    FILE* frb = fopen("03-demo.bin", "rb");
    if (frb == NULL) { perror("Gagal"); return 1; }

    int hasil[5];
    size_t terbaca = fread(hasil, sizeof(int), 5, frb);
    fclose(frb);

    printf("    Dibaca kembali (%zu elemen): ", terbaca);
    for (int i = 0; i < 5; i++) {
        printf("%d ", hasil[i]);
    }
    printf("\n\n");


    // -------------------------------------------------------
    // RINGKASAN TABEL MODE
    // -------------------------------------------------------

    printf("--- Ringkasan Mode fopen() ---\n");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "Mode", "Baca", "Tulis", "Buat baru", "Hapus isi", "Posisi awal");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "------","-----","-----","----------","----------","------------");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "r",    "Ya",  "Tidak","Tidak",     "Tidak",     "Awal");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "w",    "Tidak","Ya", "Ya",         "Ya",        "Awal");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "a",    "Tidak","Ya", "Ya",         "Tidak",     "Akhir");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "r+",   "Ya",  "Ya",  "Tidak",      "Tidak",     "Awal");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "w+",   "Ya",  "Ya",  "Ya",         "Ya",        "Awal");
    printf("%-6s %-5s %-5s %-10s %-10s %-12s\n",
           "a+",   "Ya",  "Ya",  "Ya",         "Tidak",     "Akhir (tulis)");

    printf("\n=== Selesai ===\n");
    return 0;
}

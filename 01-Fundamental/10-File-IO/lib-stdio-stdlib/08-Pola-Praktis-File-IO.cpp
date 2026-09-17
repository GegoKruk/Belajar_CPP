/*
    08-Pola-Praktis-File-IO.cpp
    -------------------------------------------------------
    Kumpulan pola praktis File I/O gaya C yang sering
    digunakan di program nyata. Semua pola menggunakan
    fungsi stdio.h yang sudah dipelajari di modul sebelumnya.

    Pola yang dibahas:
        1. Simpan dan muat array struct ke file teks
        2. Simpan dan muat array struct ke file binary
        3. Baca file CSV dengan fgets + sscanf
        4. Sistem logging ke file (append)
        5. Hitung ukuran file
        6. Copy file (karakter per karakter)
        7. Copy file dengan buffer (lebih cepat)
        8. Cek apakah file ada
        9. Baca seluruh file ke buffer (malloc)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------------------------------
// Struct yang dipakai di berbagai pola
// -------------------------------------------------------
struct Siswa {
    char nama[50];
    int  nilai;
};

// -------------------------------------------------------
// POLA 8: Cek apakah file ada (deklarasi duluan karena dipakai di main)
// -------------------------------------------------------
int file_ada(const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) return 0;
    fclose(f);
    return 1;
}

// -------------------------------------------------------
// POLA 4: Logging ke file (dipakai berulang di main)
// -------------------------------------------------------
void tulis_log(const char* path_log, const char* pesan) {
    FILE* f = fopen(path_log, "a");
    if (f == NULL) {
        perror("Gagal tulis log");
        return;
    }
    fprintf(f, "[LOG] %s\n", pesan);
    fclose(f);
}

// -------------------------------------------------------
// Helper: cetak isi file ke layar dengan prefix
// -------------------------------------------------------
void cetak_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) { printf("    (tidak bisa baca file)\n"); return; }
    char baris[256];
    while (fgets(baris, sizeof(baris), f) != NULL) {
        printf("    > %s", baris);
    }
    fclose(f);
}

int main() {

    printf("=== Pola Praktis File I/O Gaya C ===\n\n");


    // -------------------------------------------------------
    // POLA 1: Simpan dan muat array struct ke file TEKS
    // -------------------------------------------------------

    printf("[POLA 1] Simpan array struct ke file teks:\n");

    struct Siswa kelas[4] = {
        {"Budi",   88},
        {"Ani",    95},
        {"Candra", 72},
        {"Dian",   85}
    };
    int jumlah = 4;

    // SIMPAN
    FILE* fw1 = fopen("08-siswa.txt", "w");
    if (fw1 == NULL) { perror("Gagal buka"); return 1; }

    fprintf(fw1, "%d\n", jumlah);   // simpan jumlah dulu di baris pertama
    for (int i = 0; i < jumlah; i++) {
        fprintf(fw1, "%s %d\n", kelas[i].nama, kelas[i].nilai);
    }
    fclose(fw1);
    printf("    %d siswa disimpan ke '08-siswa.txt'.\n", jumlah);

    // MUAT
    FILE* fr1 = fopen("08-siswa.txt", "r");
    if (fr1 == NULL) { perror("Gagal buka"); return 1; }

    int n_baca;
    struct Siswa hasil1[10];

    fscanf(fr1, "%d\n", &n_baca);
    for (int i = 0; i < n_baca; i++) {
        fscanf(fr1, "%49s %d", hasil1[i].nama, &hasil1[i].nilai);
    }
    fclose(fr1);

    printf("    Dimuat kembali (%d siswa):\n", n_baca);
    for (int i = 0; i < n_baca; i++) {
        printf("    %-10s : %d\n", hasil1[i].nama, hasil1[i].nilai);
    }
    printf("\n");


    // -------------------------------------------------------
    // POLA 2: Simpan dan muat array struct ke file BINARY
    // -------------------------------------------------------

    printf("[POLA 2] Simpan array struct ke file binary:\n");

    // SIMPAN (satu fwrite untuk seluruh array)
    FILE* fw2 = fopen("08-siswa.bin", "wb");
    if (fw2 == NULL) { perror("Gagal buka"); return 1; }
    fwrite(&jumlah, sizeof(int),          1,      fw2);   // tulis jumlah
    fwrite(kelas,   sizeof(struct Siswa), jumlah, fw2);   // tulis array
    fclose(fw2);
    printf("    Binary disimpan ke '08-siswa.bin'.\n");

    // MUAT
    FILE* fr2 = fopen("08-siswa.bin", "rb");
    if (fr2 == NULL) { perror("Gagal buka"); return 1; }

    int n_bin;
    struct Siswa hasil2[10];

    fread(&n_bin,   sizeof(int),          1,     fr2);
    fread(hasil2,   sizeof(struct Siswa), n_bin, fr2);
    fclose(fr2);

    printf("    Dimuat kembali (%d siswa):\n", n_bin);
    for (int i = 0; i < n_bin; i++) {
        printf("    %-10s : %d\n", hasil2[i].nama, hasil2[i].nilai);
    }
    printf("\n");


    // -------------------------------------------------------
    // POLA 3: Baca file CSV dengan fgets + sscanf
    // -------------------------------------------------------

    printf("[POLA 3] Baca file CSV:\n");

    // Buat file CSV dulu
    FILE* fcsv = fopen("08-data.csv", "w");
    if (fcsv == NULL) { perror("Gagal"); return 1; }
    fprintf(fcsv, "Budi,88,3.72\n");
    fprintf(fcsv, "Ani,95,3.91\n");
    fprintf(fcsv, "Candra,79,3.55\n");
    fclose(fcsv);

    // Baca CSV
    FILE* fr3 = fopen("08-data.csv", "r");
    if (fr3 == NULL) { perror("Gagal buka"); return 1; }

    char baris[256];
    char nm[50];
    int  nl;
    float ip;

    printf("    %-12s %-8s %-5s\n", "Nama", "Nilai", "IPK");
    while (fgets(baris, sizeof(baris), fr3) != NULL) {
        if (sscanf(baris, "%49[^,],%d,%f", nm, &nl, &ip) == 3) {
            printf("    %-12s %-8d %.2f\n", nm, nl, ip);
        }
    }
    fclose(fr3);
    printf("\n");


    // -------------------------------------------------------
    // POLA 4: Sistem logging dengan mode append
    // -------------------------------------------------------

    printf("[POLA 4] Sistem logging:\n");

    // Hapus log lama jika ada (untuk demo yang bersih)
    remove("08-app.log");

    tulis_log("08-app.log", "Program dimulai.");
    tulis_log("08-app.log", "Memproses data...");
    tulis_log("08-app.log", "Data berhasil diproses.");
    tulis_log("08-app.log", "Program selesai.");

    printf("    Isi log '08-app.log':\n");
    cetak_file("08-app.log");
    printf("\n");


    // -------------------------------------------------------
    // POLA 5: Hitung ukuran file
    // -------------------------------------------------------

    printf("[POLA 5] Hitung ukuran file:\n");

    const char* path_cek = "08-siswa.txt";
    FILE* fu = fopen(path_cek, "rb");
    if (fu == NULL) { perror("Gagal"); return 1; }
    fseek(fu, 0, SEEK_END);
    long ukuran = ftell(fu);
    fclose(fu);

    printf("    Ukuran '%s': %ld byte\n\n", path_cek, ukuran);


    // -------------------------------------------------------
    // POLA 6: Copy file karakter per karakter
    // -------------------------------------------------------

    printf("[POLA 6] Copy file karakter per karakter:\n");

    FILE* src6 = fopen("08-siswa.txt", "rb");
    FILE* dst6 = fopen("08-siswa-copy.txt", "wb");
    if (src6 == NULL || dst6 == NULL) {
        perror("Gagal buka");
        if (src6) fclose(src6);
        if (dst6) fclose(dst6);
        return 1;
    }

    int c;
    long byte_count = 0;
    while ((c = fgetc(src6)) != EOF) {
        fputc(c, dst6);
        byte_count++;
    }

    fclose(src6);
    fclose(dst6);
    printf("    %ld byte berhasil dicopy ke '08-siswa-copy.txt'.\n\n",
           byte_count);


    // -------------------------------------------------------
    // POLA 7: Copy file dengan buffer (lebih cepat)
    // -------------------------------------------------------

    printf("[POLA 7] Copy file dengan buffer 4KB:\n");

    FILE* src7 = fopen("08-siswa.bin", "rb");
    FILE* dst7 = fopen("08-siswa-copy.bin", "wb");
    if (src7 == NULL || dst7 == NULL) {
        perror("Gagal buka");
        if (src7) fclose(src7);
        if (dst7) fclose(dst7);
        return 1;
    }

    char   buf[4096];
    size_t terbaca;
    long   total_byte = 0;

    while ((terbaca = fread(buf, 1, sizeof(buf), src7)) > 0) {
        fwrite(buf, 1, terbaca, dst7);
        total_byte += (long)terbaca;
    }

    fclose(src7);
    fclose(dst7);
    printf("    %ld byte dicopy ke '08-siswa-copy.bin' (via buffer 4KB).\n\n",
           total_byte);


    // -------------------------------------------------------
    // POLA 8: Cek apakah file ada
    // -------------------------------------------------------

    printf("[POLA 8] Cek keberadaan file:\n");

    const char* files[] = {
        "08-siswa.txt",
        "08-app.log",
        "file-yang-tidak-ada.xyz"
    };

    for (int i = 0; i < 3; i++) {
        printf("    '%s' : %s\n",
               files[i],
               file_ada(files[i]) ? "ADA" : "TIDAK ADA");
    }
    printf("\n");


    // -------------------------------------------------------
    // POLA 9: Baca seluruh file ke dalam buffer (malloc)
    // -------------------------------------------------------

    printf("[POLA 9] Baca seluruh file ke dalam buffer:\n");

    FILE* f9 = fopen("08-app.log", "rb");
    if (f9 == NULL) { perror("Gagal buka"); return 1; }

    // Hitung ukuran file
    fseek(f9, 0, SEEK_END);
    long sz = ftell(f9);
    rewind(f9);

    // Alokasi buffer
    char* isi = (char*)malloc(sz + 1);   // +1 untuk null terminator
    if (isi == NULL) {
        fprintf(stderr, "Gagal alokasi memori!\n");
        fclose(f9);
        return 1;
    }

    // Baca seluruh isi sekaligus
    size_t dibaca = fread(isi, 1, sz, f9);
    isi[dibaca] = '\0';   // tambah null terminator

    fclose(f9);

    printf("    File '08-app.log' dimuat: %zu byte.\n", dibaca);
    printf("    Isi (sebagai satu string):\n");
    printf("    ----\n%s    ----\n", isi);

    // WAJIB: bebaskan memori setelah selesai
    free(isi);
    printf("    Memory berhasil dibebaskan dengan free().\n");

    printf("\n=== Selesai ===\n");
    return 0;
}

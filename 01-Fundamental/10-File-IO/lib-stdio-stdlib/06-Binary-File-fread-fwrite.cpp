/*
    06-Binary-File-fread-fwrite.cpp
    -------------------------------------------------------
    Demonstrasi File I/O binary menggunakan:
        - fwrite() : menulis data biner ke file
        - fread()  : membaca data biner dari file
        - Simpan dan muat integer, struct, dan array
        - Perbandingan ukuran file teks vs binary
        - Pola loop baca binary sampai EOF
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct yang akan disimpan ke file binary
struct Mahasiswa {
    char nama[50];
    int  nim;
    int  nilai;
    float ipk;
};

// Helper: hitung ukuran file dalam byte
long ukuran_file(const char* path) {
    FILE* f = fopen(path, "rb");
    if (f == NULL) return -1;
    fseek(f, 0, SEEK_END);
    long ukuran = ftell(f);
    fclose(f);
    return ukuran;
}

// Helper: cetak isi file teks ke layar
void cetak_file_teks(const char* path) {
    FILE* f = fopen(path, "r");
    if (f == NULL) return;
    char baris[256];
    while (fgets(baris, sizeof(baris), f) != NULL) {
        printf("    > %s", baris);
    }
    fclose(f);
}

int main() {

    printf("=== Demonstrasi Binary File (fread dan fwrite) ===\n\n");


    // -------------------------------------------------------
    // BAGIAN 1: Tulis dan baca satu integer secara binary
    // -------------------------------------------------------

    printf("[1] Simpan dan muat satu integer:\n");

    int nilai_tulis = 12345;

    // Tulis
    FILE* fw1 = fopen("06-satu-int.bin", "wb");
    if (fw1 == NULL) { perror("Gagal buka"); return 1; }
    fwrite(&nilai_tulis, sizeof(int), 1, fw1);
    fclose(fw1);
    printf("    Nilai yang ditulis : %d\n", nilai_tulis);
    printf("    Ukuran file        : %ld byte (sesuai sizeof(int))\n",
           ukuran_file("06-satu-int.bin"));

    // Baca
    int nilai_baca = 0;
    FILE* fr1 = fopen("06-satu-int.bin", "rb");
    if (fr1 == NULL) { perror("Gagal buka"); return 1; }
    fread(&nilai_baca, sizeof(int), 1, fr1);
    fclose(fr1);
    printf("    Nilai yang dibaca  : %d\n\n", nilai_baca);


    // -------------------------------------------------------
    // BAGIAN 2: Tulis dan baca array integer
    // -------------------------------------------------------

    printf("[2] Simpan dan muat array integer:\n");

    int data_tulis[6] = {10, 20, 30, 40, 50, 60};
    int n = 6;

    FILE* fw2 = fopen("06-array-int.bin", "wb");
    if (fw2 == NULL) { perror("Gagal buka"); return 1; }

    // fwrite(pointer, ukuran_1_elemen, jumlah_elemen, file)
    size_t tertulis = fwrite(data_tulis, sizeof(int), n, fw2);
    fclose(fw2);
    printf("    Ditulis: %zu elemen\n", tertulis);
    printf("    Ukuran file: %ld byte (%d x sizeof(int)=%zu)\n",
           ukuran_file("06-array-int.bin"), n, sizeof(int));

    // Baca semuanya sekaligus
    int data_baca[6] = {0};
    FILE* fr2 = fopen("06-array-int.bin", "rb");
    if (fr2 == NULL) { perror("Gagal buka"); return 1; }

    size_t terbaca = fread(data_baca, sizeof(int), 6, fr2);
    fclose(fr2);

    printf("    Terbaca: %zu elemen: ", terbaca);
    for (int i = 0; i < (int)terbaca; i++) {
        printf("%d ", data_baca[i]);
    }
    printf("\n\n");


    // -------------------------------------------------------
    // BAGIAN 3: Tulis dan baca array struct
    // -------------------------------------------------------

    printf("[3] Simpan dan muat array struct Mahasiswa:\n");

    struct Mahasiswa daftar[3] = {
        {"Budi Santoso",  2023001, 88, 3.72f},
        {"Ani Rahayu",    2023002, 95, 3.91f},
        {"Candra Wijaya", 2023003, 79, 3.55f}
    };
    int jumlah = 3;

    // Tulis semua sekaligus (satu panggilan fwrite)
    FILE* fw3 = fopen("06-mahasiswa.bin", "wb");
    if (fw3 == NULL) { perror("Gagal buka"); return 1; }
    fwrite(daftar, sizeof(struct Mahasiswa), jumlah, fw3);
    fclose(fw3);
    printf("    %d struct ditulis ke file binary.\n", jumlah);

    // Baca satu per satu dengan loop
    FILE* fr3 = fopen("06-mahasiswa.bin", "rb");
    if (fr3 == NULL) { perror("Gagal buka"); return 1; }

    struct Mahasiswa mhs;
    printf("    Hasil bacaan:\n");
    printf("    %-20s %-10s %-7s %-5s\n", "Nama", "NIM", "Nilai", "IPK");
    printf("    %-20s %-10s %-7s %-5s\n",
           "--------------------","----------","-------","-----");

    // Loop cek return value fread == 1 (bukan feof!)
    while (fread(&mhs, sizeof(struct Mahasiswa), 1, fr3) == 1) {
        printf("    %-20s %-10d %-7d %.2f\n",
               mhs.nama, mhs.nim, mhs.nilai, mhs.ipk);
    }

    fclose(fr3);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 4: Perbandingan ukuran file teks vs binary
    // -------------------------------------------------------

    printf("[4] Perbandingan ukuran file teks vs binary:\n");

    double angka[5] = {3.14159, 2.71828, 1.61803, 1.41421, 1.73205};

    // Tulis sebagai teks
    FILE* fteks = fopen("06-angka-teks.txt", "w");
    if (fteks == NULL) { perror("Gagal"); return 1; }
    for (int i = 0; i < 5; i++) {
        fprintf(fteks, "%.5f\n", angka[i]);
    }
    fclose(fteks);

    // Tulis sebagai binary
    FILE* fbin = fopen("06-angka-bin.bin", "wb");
    if (fbin == NULL) { perror("Gagal"); return 1; }
    fwrite(angka, sizeof(double), 5, fbin);
    fclose(fbin);

    printf("    5 angka double:\n");
    printf("    Ukuran file teks  : %ld byte\n", ukuran_file("06-angka-teks.txt"));
    printf("    Ukuran file binary: %ld byte (%zu x sizeof(double))\n",
           ukuran_file("06-angka-bin.bin"), sizeof(double));
    printf("    Isi file teks:\n");
    cetak_file_teks("06-angka-teks.txt");
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 5: fwrite dan fread - cek return value
    // -------------------------------------------------------

    printf("[5] Cek return value fwrite dan fread:\n");

    int buffer[10] = {1,2,3,4,5,6,7,8,9,10};

    FILE* fw5 = fopen("06-cek-return.bin", "wb");
    if (fw5 == NULL) { perror("Gagal"); return 1; }
    size_t ditulis = fwrite(buffer, sizeof(int), 10, fw5);
    if (ditulis != 10) {
        fprintf(stderr, "    PERINGATAN: hanya %zu dari 10 elemen tertulis!\n",
                ditulis);
    } else {
        printf("    fwrite() berhasil: %zu elemen ditulis.\n", ditulis);
    }
    fclose(fw5);

    FILE* fr5 = fopen("06-cek-return.bin", "rb");
    if (fr5 == NULL) { perror("Gagal"); return 1; }
    int hasil[10] = {0};
    size_t dibaca = fread(hasil, sizeof(int), 10, fr5);
    if (dibaca != 10) {
        fprintf(stderr, "    PERINGATAN: hanya %zu dari 10 elemen terbaca!\n",
                dibaca);
    } else {
        printf("    fread()  berhasil: %zu elemen dibaca.\n", dibaca);
    }
    fclose(fr5);

    printf("\n=== Selesai ===\n");
    return 0;
}

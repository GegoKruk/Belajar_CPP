/*
    07-Formatted-IO-sprintf-sscanf.cpp
    -------------------------------------------------------
    Demonstrasi formatted I/O ke dan dari string:
        - sprintf()  : format data ke dalam char array
        - snprintf() : versi aman sprintf (ada batas ukuran)
        - sscanf()   : parse data dari char array
        - Pola umum: fgets + sscanf untuk baca file terstruktur
        - Perbandingan dengan stringstream C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("=== Demonstrasi Formatted I/O (sprintf dan sscanf) ===\n\n");


    // -------------------------------------------------------
    // BAGIAN 1: sprintf() - format ke string
    // -------------------------------------------------------

    printf("[1] sprintf() - format data ke dalam char array:\n");

    char hasil[200];
    int  umur   = 20;
    float ipk   = 3.85f;
    char nama[] = "Budi";

    // sprintf: seperti printf tapi output ke buffer, bukan layar
    sprintf(hasil, "Nama: %s | Umur: %d | IPK: %.2f", nama, umur, ipk);
    printf("    Hasil: %s\n\n", hasil);

    // Membuat nama file secara dinamis
    int id = 7;
    char nama_file[100];
    sprintf(nama_file, "data_mahasiswa_%03d.txt", id);
    printf("    Nama file dinamis: %s\n\n", nama_file);

    // Membuat string untuk baris CSV
    char baris_csv[200];
    sprintf(baris_csv, "%s,%d,%.2f", nama, 88, ipk);
    printf("    Baris CSV: %s\n\n", baris_csv);


    // -------------------------------------------------------
    // BAGIAN 2: snprintf() - sprintf yang aman
    // -------------------------------------------------------

    printf("[2] snprintf() - versi aman dengan batas ukuran:\n");

    char buffer_kecil[20];

    // snprintf: parameter kedua adalah ukuran maksimum buffer
    // Hanya tulis maksimal (ukuran - 1) karakter + '\0'
    int n = snprintf(buffer_kecil, sizeof(buffer_kecil),
                     "Ini teks yang agak panjang dan mungkin tidak muat");

    printf("    Buffer ukuran 20 karakter.\n");
    printf("    Panjang string asli: %d karakter.\n", n);
    printf("    Hasil yang masuk buffer: [%s]\n", buffer_kecil);
    printf("    (dipotong otomatis, tidak overflow)\n\n");

    // Cek apakah output terpotong
    if (n >= (int)sizeof(buffer_kecil)) {
        printf("    CATATAN: Output terpotong! Panjang asli %d "
               "melebihi buffer %zu.\n\n", n, sizeof(buffer_kecil));
    }


    // -------------------------------------------------------
    // BAGIAN 3: sscanf() - parse dari string
    // -------------------------------------------------------

    printf("[3] sscanf() - parse data dari string:\n");

    // Parse data yang dipisah spasi
    char data1[] = "Ani 95 3.91";
    char nama_parse[50];
    int  nilai_parse;
    float ipk_parse;

    int item = sscanf(data1, "%s %d %f", nama_parse, &nilai_parse, &ipk_parse);
    printf("    Input   : '%s'\n", data1);
    printf("    Terparsing %d item:\n", item);
    printf("    nama    = %s\n", nama_parse);
    printf("    nilai   = %d\n", nilai_parse);
    printf("    ipk     = %.2f\n\n", ipk_parse);

    // Parse data CSV (koma sebagai pemisah)
    char data2[] = "Candra,72,3.55";
    char nama2[50];
    int  nilai2;
    float ipk2;

    // %[^,] artinya: baca karakter apapun sampai ketemu koma
    sscanf(data2, "%49[^,],%d,%f", nama2, &nilai2, &ipk2);
    printf("    Input CSV: '%s'\n", data2);
    printf("    Terparsing:\n");
    printf("    nama  = %s\n", nama2);
    printf("    nilai = %d\n", nilai2);
    printf("    ipk   = %.2f\n\n", ipk2);


    // -------------------------------------------------------
    // BAGIAN 4: Pola fgets + sscanf untuk baca file terstruktur
    // -------------------------------------------------------

    printf("[4] Pola fgets + sscanf untuk baca file terstruktur:\n");

    // Buat file data dulu
    FILE* fw = fopen("07-data-nilai.txt", "w");
    if (fw == NULL) { perror("Gagal buat file"); return 1; }
    fprintf(fw, "Budi 88 3.72\n");
    fprintf(fw, "Ani 95 3.91\n");
    fprintf(fw, "Candra 79 3.55\n");
    fprintf(fw, "# ini baris komentar, diabaikan\n");
    fprintf(fw, "Dian 82 3.60\n");
    fclose(fw);

    // Baca dengan pola fgets + sscanf
    FILE* fr = fopen("07-data-nilai.txt", "r");
    if (fr == NULL) { perror("Gagal buka"); return 1; }

    char baris[256];
    char nm[50];
    int  nl;
    float ip;

    printf("    %-15s %-8s %-5s\n", "Nama", "Nilai", "IPK");
    printf("    %-15s %-8s %-5s\n", "---------------", "--------", "-----");

    while (fgets(baris, sizeof(baris), fr) != NULL) {
        // Lewati baris komentar (diawali '#') atau baris kosong
        if (baris[0] == '#' || baris[0] == '\n') {
            continue;
        }

        // Parse baris
        if (sscanf(baris, "%49s %d %f", nm, &nl, &ip) == 3) {
            printf("    %-15s %-8d %.2f\n", nm, nl, ip);
        }
    }

    fclose(fr);
    printf("\n");


    // -------------------------------------------------------
    // BAGIAN 5: sscanf untuk validasi input string
    // -------------------------------------------------------

    printf("[5] sscanf sebagai validator format data:\n");

    const char* test_cases[] = {
        "123",           // valid integer
        "3.14",          // valid float
        "abcdef",        // bukan angka
        "42 extra",      // ada sisa teks
        ""               // string kosong
    };
    int total_test = 5;

    for (int i = 0; i < total_test; i++) {
        int angka_int;
        float angka_float;
        char sisa[50];

        int cek_int   = sscanf(test_cases[i], "%d %49s", &angka_int, sisa);
        int cek_float = sscanf(test_cases[i], "%f",       &angka_float);

        printf("    Input '%s':\n", test_cases[i]);
        if (cek_int == 1) {
            printf("        -> integer valid: %d\n", angka_int);
        } else if (cek_float == 1) {
            printf("        -> float valid: %.2f\n", angka_float);
        } else {
            printf("        -> bukan angka valid\n");
        }
    }

    printf("\n=== Selesai ===\n");
    return 0;
}

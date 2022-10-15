#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

/* Jika kondisi tidak terpenuhi maka keluar dari program dengan pesan kesalahan. */
void check(_Bool condition, const char* func, int line) {
    if (condition) {
        return;
    }
        
    perror(func);
    fprintf(stderr, "%s failed in file %s at line # %d\n", func, __FILE__, line - 1);
    exit(EXIT_FAILURE);
}

int main(void) {
    /* Siapkan array nilai FP. */
#define SIZE 5
    double A[SIZE] = { 1.1,2.,3.,4.,5. };

    /* Tulis array ke file. */
    const char* fname = "/tmp/test.bin";
    FILE* file = fopen(fname, "wb");
    check(file != NULL, "fopen()", __LINE__);

    const int write_count = fwrite(A, sizeof(double), SIZE, file);
    check(write_count == SIZE, "fwrite()", __LINE__);

    fclose(file);

    /* Baca nilai FP ke dalam larik B. */
    double B[SIZE];
    file = fopen(fname, "rb");
    check(file != NULL, "fopen()", __LINE__);

    long int pos = ftell(file); /* indikator posisi di awal file */
    check(pos != -1L, "ftell()", __LINE__);
    printf("pos: %ld\n", pos);

    const int read_count = fread(B, sizeof(double), 1, file); /* baca satu nilai FP */
    check(read_count == 1, "fread()", __LINE__);

    pos = ftell(file); /* indikator posisi setelah membaca satu nilai FP */
    check(pos != -1L, "ftell()", __LINE__);
    printf("pos: %ld\n", pos);
    printf("B[0]: %.1f\n", B[0]); /* cetak satu nilai FP */

    _getch();
    return EXIT_SUCCESS;
}
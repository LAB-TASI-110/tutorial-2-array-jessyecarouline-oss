#include <stdio.h>   // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Diperlukan untuk INT_MAX dan INT_MIN
#include <stdlib.h>  // Diperlukan untuk fungsi malloc dan free
#include <float.h>   // Diperlukan untuk DBL_MAX

int main() {
    int n;           // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int *numbers;    // Pointer untuk array dinamis yang akan menyimpan semua bilangan
    int min_val = INT_MAX; // Inisialisasi nilai terkecil
    int max_val = INT_MIN; // Inisialisasi nilai terbesar
    double min_avg = DBL_MAX; // Inisialisasi rata-rata terkecil dengan nilai double maksimum

    // 1. Meminta input untuk jumlah bilangan (n)
    printf("Masukkan jumlah bilangan yang akan dianalisis (n): ");
    if (scanf("%d", &n) != 1 || n < 1) { // n harus positif
        printf("Masukan tidak valid. n harus merupakan bilangan bulat positif.\n");
        return 1; // Mengakhiri program dengan kode error
    }

    // 2. Alokasi memori dinamis untuk n bilangan
    numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; // Mengakhiri program dengan kode error
    }

    // 3. Loop untuk menerima n baris masukan berikutnya dan menemukan min/max
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Masukan tidak valid. Mohon masukkan bilangan bulat.\n");
            free(numbers); // Bebaskan memori sebelum keluar
            return 1;      // Mengakhiri program dengan kode error
        }

        // Memastikan bilangan berada dalam rentang -100 hingga 100
        if (numbers[i] < -100 || numbers[i] > 100) {
            printf("Peringatan: Bilangan %d di luar rentang -100 hingga 100. Tetap diproses.\n", numbers[i]);
        }

        // Membandingkan dengan min_val dan max_val saat ini
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    // 4. Menghitung rata-rata terendah dari dua nilai yang dimasukkan berturut
    if (n < 2) {
        // Tidak ada pasangan untuk dihitung rata-ratanya
        min_avg = DBL_MAX; // Biarkan sebagai nilai default atau indikator tidak ada
    } else {
        for (int i = 0; i < n - 1; i++) { // Loop hingga n-2 untuk pasangan (i, i+1)
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        }
    }

    // 5. Menampilkan hasil analisis
    printf("\n--- Hasil Analisis ---\n");
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);
    if (n >= 2) { // Tampilkan rata-rata hanya jika ada pasangan yang bisa dihitung
        printf("Rata-rata terendah dari dua nilai berturut: %.2f\n", min_avg);
    } else {
        printf("Tidak cukup bilangan untuk menghitung rata-rata dari dua nilai berturut.\n");
    }


    // 6. Bebaskan memori yang dialokasikan secara dinamis
    free(numbers);

    return 0; // Mengakhiri program dengan sukses
}


#include <stdio.h>
#include <limits.h>


int main() {
    int n;   
    int num;     
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    printf("Masukkan jumlah bilangan yang akan dianalisis (n): ");
     if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Masukan tidak valid. n harus merupakan bilangan bulat positif.\n");
         return 1;

      }

      printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            printf("Masukan tidak valid. Mohon masukkan bilangan bulat.\n");
            return 1; 

        }

        if (num < -100 || num > 100) {
            printf("Peringatan: Bilangan %d di luar rentang -100 hingga 100. Tetap diproses.\n", num);

        }

        if (num < min_val) {
            min_val = num;

        }

        if (num > max_val) {
            max_val = num;
        }
    }

    printf("\n--- Hasil Analisis ---\n");
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);

    return 0; 
}


    



#include <stdio.h>   
#include <limits.h>  
#include <stdlib.h>  
#include <float.h>   

int main() {
    int n;           
    int *numbers;    
    int min_val = INT_MAX; 
    int max_val = INT_MIN; 
    double min_avg = DBL_MAX; 

    
    printf("Masukkan jumlah bilangan yang akan dianalisis (n): ");
    if (scanf("%d", &n) != 1 || n < 1) { 
        printf("Masukan tidak valid. n harus merupakan bilangan bulat positif.\n");
        return 1; 
    }

    
    numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; 
    }

    
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Masukan tidak valid. Mohon masukkan bilangan bulat.\n");
            free(numbers); 
            return 1;     
        }

        
        if (numbers[i] < -100 || numbers[i] > 100) {
            printf("Peringatan: Bilangan %d di luar rentang -100 hingga 100. Tetap diproses.\n", numbers[i]);
        }

        
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

   
    if (n < 2) {
        
        min_avg = DBL_MAX; 
    } else {
        for (int i = 0; i < n - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        }
    }

   
    printf("\n--- Hasil Analisis ---\n");
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);
    if (n >= 2) { 
        printf("Rata-rata terendah dari dua nilai berturut: %.2f\n", min_avg);
    } else {
        printf("Tidak cukup bilangan untuk menghitung rata-rata dari dua nilai berturut.\n");
    }


    
    free(numbers);

    return 0; 
}


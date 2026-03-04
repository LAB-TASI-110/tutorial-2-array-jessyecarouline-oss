#include <stdio.h>
#include <limits.h> // Untuk INT_MAX, INT_MIN
#include <float.h>  // Untuk DBL_MAX

int main() {
    int n;
    scanf("%d", &n);

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    double minAvg = DBL_MAX; // Inisialisasi dengan nilai double terbesar
    int previousValue;
    int currentValue;

    // Pastikan ada setidaknya satu nilai untuk diproses
    if (n > 0) {
        // Baca nilai pertama
        scanf("%d", &currentValue);
        minVal = currentValue;
        maxVal = currentValue;
        previousValue = currentValue; // Simpan nilai pertama sebagai previousValue

        // Iterasi untuk nilai-nilai berikutnya (mulai dari indeks 1 hingga n-1)
        for (int i = 1; i < n; i++) {
            scanf("%d", &currentValue);

            // Perbarui nilai minimum dan maksimum keseluruhan
            if (currentValue < minVal) {
                minVal = currentValue;
            }
            if (currentValue > maxVal) {
                maxVal = currentValue;
            }

            // Hitung rata-rata pasangan saat ini dan perbarui rata-rata minimum
            double currentAvg = (double)(previousValue + currentValue) / 2.0;
            if (currentAvg < minAvg) {
                minAvg = currentAvg;
            }

            previousValue = currentValue; // Perbarui previousValue untuk iterasi berikutnya
        }
    }
    
    // Tampilkan nilai terkecil dan terbesar
    printf("%d\n", minVal);
    printf("%d\n", maxVal);

    // Tampilkan rata-rata terkecil jika ada setidaknya dua nilai (memungkinkan terbentuknya pasangan)
    if (n >= 2) {
        printf("%.2f\n", minAvg);
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int n;
    scanf("%d", &n);

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    double minAvg = DBL_MAX;
    double maxAvg = DBL_MIN;
    int previousValue;
    int currentValue;

    if (n > 0) {
        scanf("%d", &currentValue);
        minVal = currentValue;
        maxVal = currentValue;
        previousValue = currentValue;

        for (int i = 1; i < n; i++) {
            scanf("%d", &currentValue);

            if (currentValue < minVal) {
                minVal = currentValue;
            }
            if (currentValue > maxVal) {
                maxVal = currentValue;
            }

            double currentAvg = (double)(previousValue + currentValue) / 2.0;

            if (currentAvg < minAvg) {
                minAvg = currentAvg;
            }
            
            if (currentAvg > maxAvg) {
                maxAvg = currentAvg;
            }

            previousValue = currentValue;
        }
    }
    
    printf("%d\n", minVal);
    printf("%d\n", maxVal);

    if (n >= 2) {
        printf("%.2f\n", minAvg);
        printf("%.2f\n", maxAvg);
    }

    return 0;
}
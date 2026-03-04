#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int currentValue;

    for (int i = 0; i < n; i++) {
        scanf("%d", &currentValue);
        if (currentValue < minVal) {
            minVal = currentValue;
        }
        if (currentValue > maxVal) {
            maxVal = currentValue;
        }
    }

    printf("%d\n", minVal);
    printf("%d\n", maxVal);

    return 0;
}
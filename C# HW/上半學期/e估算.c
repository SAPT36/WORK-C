#include <stdio.h>
#include <math.h>

int main() {
    double e = 1.0f;
    int n, i = 1;
    long f = 1;
    printf("Enter n:");
    scanf("%d", &n);
    while (n < 0) {
        printf("Error! Please enter again!\n");
        printf("Enter n:");
        scanf("%d", &n);

    }

    while (i <= n) {
        e += 1.0 / f;
        f *= ++i;
    }
    printf("e=%.10f", e);
}
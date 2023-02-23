#include <stdio.h>

/* Conversao Fahrenheit-Celsius */

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {

    float celsius, fahr;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%.0f\t%.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
    return 0;
}

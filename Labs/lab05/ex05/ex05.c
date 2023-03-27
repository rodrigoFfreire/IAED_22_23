/* iaed-23 - ist1106485 - lab05/ex05 */

#include <stdio.h>

typedef struct {
    int h;
    int m;
} Horas;

Horas soma_horas(Horas h1, Horas h2) {
    Horas sum;
    int sum_min;
    sum_min = (h1.h * 60 + h1.m) + (h2.h * 60 + h2.m);

    sum.m = sum_min % 60;
    sum.h = (sum_min - sum.m) / 60;
    return sum;
}


int main() {
    Horas h1, h2, sum;
    scanf("%d:%d %d:%d", &h1.h, &h1.m, &h2.h, &h2.m);

    sum = soma_horas(h1, h2);
    printf("%02d:%02d\n", sum.h, sum.m);
    return 0;

}
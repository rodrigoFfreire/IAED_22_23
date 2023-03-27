
#include <stdio.h>


typedef struct {
    float real;
    float img;
} Complexo;


Complexo sum_complexos(Complexo c1, Complexo c2) {
    Complexo sum = {0};
    sum.real = c1.real + c2.real;
    sum.img = c1.img + c2.img;

    return sum;
}

int main() {
    Complexo c1, c2, sum;
    char op1, op2;
    scanf("%f%c%fi %f%c%fi", &c1.real, &op1, &c1.img, &c2.real, &op2, &c2.img);
    
    c1.img *= (op1 == '-') ? -1 : 1;
    c2.img *= (op2 == '-') ? -1 : 1;

    sum = sum_complexos(c1, c2);
    printf("%.2f%+.2fi\n", sum.real, sum.img);

    return 0;
}
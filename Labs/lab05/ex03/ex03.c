/* iaed-23 - ist1106485 - lab05/ex03 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[10];
    float valor;
    float taxa;
} Stock;


Stock read_stock() {
    char n[10];
    float v, t;
    Stock stock;

    scanf("%s%f%f", n, &v, &t);
    stock.valor = v, stock.taxa = t;
    strcpy(stock.nome, n);

    return stock;
}

Stock max_stock(Stock *stocks, int len) {
    int i, max = 0;
    for (i = 0; i < len; i++) {
        if (stocks[i].valor > max) {
            max = i;
        }
    }
    return stocks[max];
}

void print_stock(Stock stock) {
    printf("%s %.2f %.2f\n", stock.nome, stock.valor, stock.taxa);
}


int main() {
    Stock stocks[1000] = {0};
    Stock max;
    int i, n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        stocks[i] = read_stock();
    }
    max = max_stock(stocks, n);
    print_stock(max);

    return 0;
}
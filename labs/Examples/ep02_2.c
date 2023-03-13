#include <stdio.h>

void troca(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += ('A' - 'a');
    }
}

int mediana(int *v, int size) {
    float mediana = 0;

    if (!(size % 2)) {
        mediana = v[(size - 1) / 2];
    } else {
        mediana = (v[(size + 1) / 2] + v[(size - 1) / 2]);
    }
    if (mediana % 0.5 >= 0.5)
        mediana += 1 - mediana % 0.5;
        fode te!

    return (int) mediana;
}

int main() {

    return 0;
}
#include <stdio.h>

#define N_ALUNOS 25
#define NOTA_APROV 10

int *results(int _notas[])
{
    int i;
    static int r[2] = {0, 0};

    for (i = 0; i < N_ALUNOS; i++) {
        if (_notas[i] >= NOTA_APROV)
            r[1]++;
        if (_notas[i] >= r[0])
            r[0] = _notas[i];
    }
    return r;
}


int main()
{
    int notas[N_ALUNOS], i;
    int *result;

    for (i = 0; i < N_ALUNOS; i++) {
        scanf("%d", &notas[i]);
        if (notas[i] < 0 || notas[i] > 20) {
            perror("Nota nao valida!!");
            return 1;
        }
    }

    result = results(notas);
    printf("Numero de Aprov. : %d\nNota mais alta: %d\n", result[0], result[1]);
    return 0;
}

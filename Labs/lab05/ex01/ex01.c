
#include <stdio.h>

#define ALUNOS 10
#define DISCPLINAS 5


long score_displina(int disciplina, int valores[][DISCPLINAS]) {
    long soma = 0;
    int i;
    for (i = 0; i < ALUNOS; i++) {
        soma += valores[i][disciplina];
    }
    return soma;
}

long score_aluno(int aluno, int valores[][DISCPLINAS]) {
    long soma = 0;
    int i;
    for (i = 0; i < DISCPLINAS; i++) {
        soma += valores[aluno][i];
    }
    return soma;
}



int main() {
    int n = 0, valores[ALUNOS][DISCPLINAS] = {0};
    int i, a, d, v;
    long score, max_score;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &d, &v);
        valores[a][d]= v;
    }

    max_score = score_aluno(0, valores);
    a = 0;
    for (i = 1; i < ALUNOS; i++) {
        score = score_aluno(i, valores);
        if (score > max_score) {
            max_score = score;
            a = i;
        }
    }
    max_score = score_displina(0, valores);
    d = 0;
    for (i = 1; i < DISCPLINAS; i++) {
        score = score_displina(i, valores);
        if (score > max_score) {
            max_score = score;
            d = i;
        }
    }

    printf("%d\n%d\n", d, a);
    return 0;
}

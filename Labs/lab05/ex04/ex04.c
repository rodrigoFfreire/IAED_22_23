
#include <stdio.h>
#include <string.h>

#define MAXDIM 100
#define X "x\n"
#define O "o\n"
#define E "?\n"

int ganha(int dim, char tab[][MAXDIM], char player) {
    int i, j;
    int horiz = 0, vert = 0, diag = 0;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if ((i == j || j == dim - i - 1) && tab[i][j] == player)
                diag++;
            if (tab[j][i] == player)
                vert++;
            if (tab[i][j] == player)
                horiz++;
        }
        if (diag > 2 || horiz > 2 || vert > 2) {
            return 1;
        }
        horiz = vert = 0;
    }
    return 0;
}


int main() {
    char player, tab[MAXDIM][MAXDIM] = {0};
    int i, d, ent;
    int w, l;
    int p1, p2;
    scanf("%d%d", &d, &ent);

    for (i = 0; i < ent; i++) {
        scanf("%d %d %c", &w, &l, &player);
        tab[l][w] = player;
    }
    p1 = ganha(d, tab, 'x'), p2 = ganha(d, tab, 'o');
    if (p1 && !p2)
        printf(X);
    else if (!p1 && p2)
        printf(O);
    else
        printf(E);
    return 0;
}
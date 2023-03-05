/* iaed-23 - ist1106485 - lab03/ex05 */
#include <stdio.h>

#define DIM 100
#define TRUE 1
#define FALSE 0

int main()
{
    char str[DIM];
    int i, c, word = FALSE;

    for (i = 0; i < DIM - 1 && (c = getchar()) && c != EOF && c!= '\n'; i++) {
        str[i] = c;
    }
    str[i] = '\0';

    for (i = 0; i < DIM - 1 && str[i] != '\0'; i++) {
        if (i < DIM - 2 && str[i] == '\\') {
            printf("%c", str[i + 1]);
            i++;
            continue;
        }
        if (str[i] == '\"') {
            word = (word) ? FALSE: TRUE;        /* Comecar palavra se nao for palavra e vice-versa */
            continue;
        }
        (word) ? printf("%c", str[i]): printf("\n");
    }
    printf("\n");
    return 0;
}

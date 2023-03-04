/* iaed-23 - ist1106485 - lab03/ex05 */
#include <stdio.h>

#define DIM 100

int main()
{
    char str[DIM];
    int i, c, word = 0;

    for (i = 0; i < DIM - 1 && (c = getchar()) && c != EOF && c!= '\n'; i++) {
        str[i] = c;
    }
    str[i] = '\0';

    for (i = 0; i < DIM - 1 && str[i] != '\0'; i++) {
        if (str[i] == '\"')
            word++;
        if (word % 2 != 0 && str[i] != '\"')
            printf("%c", str[i]);
        else if (word % 2 == 0 && str[i] == '\"')
            printf("\n");
    }

    return 0;
}
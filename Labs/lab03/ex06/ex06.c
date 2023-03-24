/* iaed-23 - ist1106485 - lab03/ex06 */
#include <stdio.h>

#define DIM 100
#define OFFSET 48        /* ASCII OFFSET */


int main()
{   
    char c, str[DIM];
    int i, sum;

    for (i = 0; i < DIM - 1 && (c = getchar()) != '\n' && c != EOF; i++)
        str[i] = c;
    str[i] = '\0';

    for (i = 0; i < DIM - 1 && str[i] != '\0'; i++) {
        sum += ((int) str[i]) - OFFSET;
    }

    (sum % 9 == 0) ? printf("yes\n") : printf("no\n");
    return 0;
}
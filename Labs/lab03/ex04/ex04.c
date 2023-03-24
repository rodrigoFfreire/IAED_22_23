/* iaed-23 - ist1106485 - lab03/ex04 */

#include <stdio.h>

#define DIM 100

int main()
{
    char str[DIM], result[DIM];
    int i, c, clean = 1, count = 0;

    for (i = 0; i < DIM - 1 && (c = getchar()) != EOF; i++) {
        str[i] = c;
    }
    str[i] = '\0';


    for (i = 0; i < DIM - 1 && (str[i] != '\0'); i++) {
        if (((str[i - 1] == ' ' || str[i - 1] == '\n') && str[i] == '0') || (i == 0 && str[i] == '0'))
            clean = 0;

        if (!((i == 0 && str[i] == '0') || ((str[i - 1] == ' ' || str[i - 1] == '\n') && str[i] == '0')) ||
            (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\n') && str[i] == '0' && (str[i + 1] == ' ' || str[i + 1] == '\n')) ||
            (i == 0 && str[i] == '0' && (str[i + 1] == ' ' || str[i + 1] == '\n'))) {

            if (str[i] != '0' || (str[i] == '0' && (str[i + 1] == ' ' || str[i + 1] == '\n')))
                clean = 1;
            if (clean) {
                result[count] = str[i];
                count++;
            }
        }
    }
    result[count] = '\0';
    printf("%s", result);
    return 0;
}
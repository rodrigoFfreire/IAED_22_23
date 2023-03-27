#include <stdio.h>

#define DIM 100
#define OFFSET 48       /* ASCII OFFSET */
#define SUM 0
#define SUB 1

int main()
{
    char c, str[DIM];
    int i, op = SUM, n = 0, result = 0;

    for (i = 0; i < DIM - 1 && (c = getchar()) != '\n'; i++)
        str[i] = c;
    str[i] = '\0';

    for (i = 0; i < DIM - 1 && str[i] != '\0'; i++) {
        int ascii = (int) str[i];
        if (ascii >= 48 && ascii <= 57) {       /* 0 to 9 in ASCII*/
            n = n * 10 + ((int) str[i] - OFFSET);
            if (str[i + 1] == '\0' || str[i + 1] == ' ') {
                if (op == SUM)
                    result += n;
                else
                    result -= n;
                n = 0;
            }
        }
        if (str[i] == '+')
            op = SUM;
        else if (str[i] == '-')
            op = SUB;
        
    }
    printf("%d\n", result);

    return 0;
}

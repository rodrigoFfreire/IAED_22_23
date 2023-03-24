/* iaed-23 - ist1106485 - lab04/ex05 */
#include <stdio.h>

#define MAX 80

int leLinha(char s[])
{
    int i, count = 0;
    char c;

    for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
        count++;
    }
    s[i] = '\0';
    return count;
}

int main()
{
    char str[MAX];
    leLinha(str);

    printf("%s\n", str);

    return 0;
}
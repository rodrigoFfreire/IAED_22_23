#include <stdio.h>

#define MAX 80
#define CASE_OFFSET 32

void maiusculas(char s[])
{
    int i;
    char c;

    for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if ((int) c >= 97 && (int) c <= 122)
            c = (char) (((int) c) - CASE_OFFSET);
        s[i] = c;
    }
    s[i] = '\0';
}

int main()
{
    char str[MAX];
    maiusculas(str);

    printf("%s\n", str);

    return 0;
}
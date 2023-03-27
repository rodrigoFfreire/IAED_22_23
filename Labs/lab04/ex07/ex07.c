#include <stdio.h>
#include <string.h>

#define MAX 80

void apagaCaracter(char s[], char c)
{
    int i, j;
    for (i = 0; i < MAX - 1 && s[i] != '\0'; i++) {
        if (s[i] == c) {
            for (j = i; s[j] != '\0'; j++)
                s[j] = s[j + 1];
            i--;
        }
    }
}

int main()
{
    char str[MAX], ch;
    int i;

    for (i = 0; i < MAX - 1 && (ch = getchar()) != EOF && ch != '\n'; i++) {
        str[i] = ch;
    }
    str[i] = '\0';
    scanf("%c", &ch);

    apagaCaracter(str, ch);
    printf("%s\n", str);

    return 0;
}
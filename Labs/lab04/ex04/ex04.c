#include <stdio.h>

#define MAX 80
#define TRUE 1
#define FALSE 0
#define CASE_OFFSET 32

char toLower(char c)
{
    if ((int)c >= 97 && (int)c <= 122)
        return (char) ((int) c - CASE_OFFSET);

    return c;
}


int main()
{
    char str[MAX];
    int flag = TRUE, i, count;

    scanf("%s", str);
    for (count = 0; str[count] != '\0' && count < MAX - 1; count++);

    for (i = 0; i < count; i++) {
        if (toLower(str[i]) != toLower(str[count - 1 - i])) {
            flag = FALSE;
            break;
        }
    }
    (flag) ? printf("yes\n") : printf("no\n");

    return 0;
}
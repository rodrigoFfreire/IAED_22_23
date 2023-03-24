/* iaed-23 - ist1106485 - lab04/ex08 */
#include <stdio.h>

#define MAX 100

int main()
{
    int i;
    char n1[MAX], n2[MAX];
    scanf("%s", n1);
    scanf("%s", n2);

    for (i = 0; i < MAX && n1[i] != '\0' && n2[i] != '\0' && n1[i] == n2[i]; i++);
    (n1[i] > n2[i]) ? printf("%s\n", n1) : printf("%s\n", n2);

    return 0;
}

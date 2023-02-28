#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLen(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);

    return i;
}



int main()
{
    char C[10];
    C[0] = 'N';
    C[1] = 'N';
    C[2] = 'N';
    C[3] = 'N';
    C[4] = 'N';
    C[5] = '\0';
    int len = getLen(C);
    printf("%d", len);
    return 0;
}

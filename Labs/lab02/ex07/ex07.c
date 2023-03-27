
#include <stdio.h>

int main()
{
    int n, i;
    int count = 0;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        (n % i == 0) ? count++ : 0;
    }
    printf("%d\n", count);
    
    return 0;
}
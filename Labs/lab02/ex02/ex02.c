
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    (n >= m) ? printf("%d\n%d\n", m, n) : printf("%d\n%d\n", n, m);
    
    return 0;
}

/* iaed-23 - ist1106485 - lab02/ex03 */

#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    (n % m == 0) ? printf("yes\n") : printf("no\n");
    
    return 0;
}

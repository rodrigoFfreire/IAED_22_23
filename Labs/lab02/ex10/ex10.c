/* iaed-23 - ist1106485 - lab02/ex10 */

#include <stdio.h>

int main()
{
    int n, sum, count;
    scanf("%d", &n);

    sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = (n / 10) - ((n / 10) % 1);
        count++;
    }
    printf("%d\n%d\n", count, sum);
    
    return 0;
}

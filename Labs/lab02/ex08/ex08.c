/* iaed-23 - ist1106485 - lab02/ex08 */

#include <stdio.h>

int main()
{
    float media, num;
    int n, i;
    scanf("%d", &n);

    media = 0;
    for (i = 0; i < n; i++) {
        scanf("%f", &num);
        media += num;
    }
    media /= n;
    printf("%.2f\n", media);

    return 0;
}

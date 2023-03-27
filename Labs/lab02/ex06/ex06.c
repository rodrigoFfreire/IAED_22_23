
#include <stdio.h>

int main()
{
    float min, max, num;
    int i, n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%f", &num);
        if (i == 0) {
            max = min = num;
        } else {
            if (num >= max) {
                max = num;
            } else if (num <= min) {
                min = num;
            }
        }
    }
    printf("min: %f, max: %f\n", min, max);

    return 0;
}

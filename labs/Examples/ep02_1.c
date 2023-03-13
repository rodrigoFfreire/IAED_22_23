#include <stdio.h>
#include <math.h>

#define MAX 10


double polyval(double *pol, int size, double x) {
    double y = 0;
    int i;

    for (i = 0; i < size; i++) {
        y += pol[i] * pow(x, i);
    }
    return y;
}

int moda() {
    int i = 0, count = 0, j, k, num;
    int max_count = 0, mode = 0;
    int arr[MAX];

    while (num >= 0 && i < MAX) {
        scanf("%d", &num);
        if (num >= 0)
            arr[i++] = num;
    }
    for (j = 0; j < i; j++) {
        count = 0;
        for (k = 0; k < i; k++) {
            if (arr[k] == arr[j])
                count++;
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[j];
        } else if (count == max_count) {
            mode = (arr[j] < mode) ?
                arr[j]:
                mode;
        }
    }
    printf("\n%d\n", mode);
}



int main()
{   
    moda();
    return 0;
}
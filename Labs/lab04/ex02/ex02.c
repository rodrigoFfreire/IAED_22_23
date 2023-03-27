#include <stdio.h>

#define VECMAX 100

int main()
{
    int i, j, n, max = 0, graph[VECMAX];
    scanf("%d", &n);

    graph[0] = 1;
    for (i = 1; i <= n && i <= VECMAX; i++) {
        scanf("%d", &graph[i]);
        max = (graph[i] >= max) ? graph[i]: max;
        graph[0]++;
    }

    for (i = 0; i < max; i++) {
        for (j = 1; j < graph[0]; j++) {
            if (graph[j] - i > 0)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
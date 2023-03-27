#include <stdio.h>

#define VECMAX 100

int main()
{
    int i, j, n, graph[VECMAX];
    scanf("%d", &n);

    graph[0] = 1;
    for (i = 1; i <= n && i <= VECMAX; i++) {
        scanf("%d", &graph[i]);
        graph[0]++;
    }

    for (i = 1; i < graph[0]; i++) {
        for (j = 0; j < graph[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}       
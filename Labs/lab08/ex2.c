#include <stdio.h>

#define MAX_ELEM 10

int main() {
  int a[MAX_ELEM];
  int i, soma = 0;
  
  for (i = 1; i < MAX_ELEM; i++)
    scanf("%d", &a[i]);
  
  for (i = 0; i <= MAX_ELEM; i++)
    soma += a[i];
  
  printf("A soma é %d\n", soma);
  
  return 0;
}

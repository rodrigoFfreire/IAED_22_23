#include <stdio.h>

#define MAX_ELEM 10

void copiaString(char s[], char r[]) {
  int i = 0;
  for (i = 0; s[i] != '\0'; i++)
    r[i] = s[i];
}

int main() {
  char r[MAX_ELEM], s[MAX_ELEM];

  scanf("%s", s);
  
  copiaString(s, r);
  
  printf("A string original %s\n", s);
  printf("A string copiada %s\n", r);
  
  return 0;
}

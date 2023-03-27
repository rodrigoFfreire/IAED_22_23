#include <stdio.h>

int main() {
  int x, y, res;
  
  scanf("%d", &y);

  if (x > 0) 
    res = x*y;
  else
    res = -x*y;
  
  printf("|%d| * %d = %d\n", x, y, res);
  
  return 0;
}

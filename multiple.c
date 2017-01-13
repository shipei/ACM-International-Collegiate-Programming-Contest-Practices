#include <stdio.h>

typedef int boolean;
enum { false, true };

boolean isDecimal;
void DFS(long dec, int num, int level) {
  if(isDecimal)
    return;
  if(dec % num == 0) {
    printf("%ld\n", dec);
    isDecimal = true;
    return;
  }
  if(level == 19)
      return;
  DFS(dec*10, num, level+1);
  DFS(dec*10+1, num, level+1);
}
int main() {
  int num;
  scanf("%d", &num);
  while(scanf("%d", &num) != 0) {
    DFS(1,num,0);
  }
    return 0;
}

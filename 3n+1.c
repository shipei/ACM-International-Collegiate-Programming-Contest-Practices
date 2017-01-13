#include <stdio.h>

int cycleLength(int num) {
  int length = 1;
  while(num != 1) {
    if((num % 2) != 0)
      num = num * 3 + 1;
    else
      num = num / 2;
    ++length;
  }
  return length;
}

int maxLength(int i, int j) {
  if(i > j) {
    int temp = i;
    i = j;
    j = temp;
  }
  int maxCycle = 0;
  int a;
  int m;
  for(a = i; a <= j; a++) {
    m = cycleLength(a);
    if(m > maxCycle)
      maxCycle = m;
  }
  return maxCycle;
}

int main() {
  int x;
  int y;
  while(scanf("%d %d", &x, &y) != EOF) {
    int max = maxLength(x, y);
    printf("%d %d %d\n", x, y, max);
  }
  return 0;
}

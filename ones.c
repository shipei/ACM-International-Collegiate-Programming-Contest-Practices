#include <stdio.h>

int calc(int num) {
  long digits = 1;
  long k = 1;
  long n = 1;
  while(k) {
    if(n < num) {
      n = n*10+1;
      digits++;
    }
    k = n%num;
    n = k;
  }
  return digits;
}

int main() {
  int num;
  while(scanf("%d", &num) != EOF) {
    printf("%d\n", calc(num));
  }
  return 0;
}

#include <stdio.h>
#include <math.h>

int isPrime(int x) {
  int i;
  if(x == 2 || x == 3) return 1;
  if(x % 2 == 0) return 0;
  for(i = 3; i < sqrt(x)+1; i += 2) {
    if(x % i == 0)
      return 0;
  }
  return 1;
}

void goldBach(int x) {
  int i = 0, index = 0, left, right;
  int primes[x];
  for(i = 0; i < x; i++) {
    if(isPrime(i) == 1) {
      primes[index] = i;
      index++;
    }
  }
  left = 0;
  right = index-1;
  while(left <= right) {
    if(primes[left] + primes[right] == x) break;
    else if(primes[left] + primes[right] < x) left++;
    else right--;
  }
  printf("%d %d\n", primes[left], primes[right]);
}

int main() {
  int num;
  while(scanf("%d", &num) != EOF) {
    if(num < 8) printf("Impossible.");
    else {
      if(num % 2 == 0) {
        printf("%d %d ", 2, 2);
        goldBach(num-4);
      }
      else {
        printf("%d %d ", 2, 3);
        goldBach(num-5);
      }
    }
  }
  return 0;
}

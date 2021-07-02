#include <stdio.h>

int fib(int n) {
  if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else {
    return fib(n - 1) + fib(n - 2);
  }
}

int main(void) {
  int ans = fib(5);
  printf("%d ", ans);
  return 0;
}

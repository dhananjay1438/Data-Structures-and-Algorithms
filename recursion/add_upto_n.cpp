#include <iostream>
int add_upto(int n) {
  if (n == 0)
    return n;
  else
    return n + add_upto(n - 1);
}

int main(void) {

  int n;
  std::cin >> n;

  std::cout << add_upto(n);
  return 0;
}

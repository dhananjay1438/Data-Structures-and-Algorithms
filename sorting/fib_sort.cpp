#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

int main(void) {

  std::vector<int> arr;
  std::default_random_engine engine;
  std::normal_distribution<int> distribution(1, 100);
  auto random_number = std::bind(distribution, engine);

  for (int i = 0; i < 10; i++) {
  }

  return 0;
}

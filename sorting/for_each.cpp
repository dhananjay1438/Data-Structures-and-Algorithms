#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

int main(void) {

  std::minstd_rand0 generator;
  std::uniform_int_distribution<int> distribution(
      std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

  auto seed = std::chrono::steady_clock::now().time_since_epoch().count();

  generator.seed(seed);

  std::vector<int> vec;
  for (int i = 0; i < 10000; i++) {
    vec.push_back(distribution(generator));
  }

  // Instead of this
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }

  // You can use this
  for (auto &x : vec) {
    std::cout << x << " ";
  }
  return 0;
}

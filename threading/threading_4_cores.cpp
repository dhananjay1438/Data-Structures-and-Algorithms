#include <chrono>
#include <iostream>
#include <thread>
#include <typeinfo>

void print1to100() {
  for (int i = 0; i < 1000000; i++)
    std::cout << i << " ";
}
void print100to200() {
  for (int i = 20; i < 3000000; i++)
    std::cout << i << " ";
}
void yes_threading() {

  std::thread first(print1to100);
  std::thread second(print100to200);
  first.join();
  second.join();
}
void no_threading() {
  for (int i = 0; i < 20000000; i++) {
    std::cout << i << " ";
  }
}
int main(void) {

  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  std::thread second(print100to200);
  std::thread first(print1to100);
  std::cout << "hello\n" << std::endl;
  std::cout << "no\n" << std::endl;
  first.detach();
  second.detach();
  for (int i = 30; i < 4000000; i++)
    std::cout << i << " ";
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  std::chrono::duration<double> time_required =
      std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
  std::cout << time_required.count();

  return 0;
}

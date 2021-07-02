#include <fstream>
#include <iostream>

int main(void) {

  std::fstream out;

  out.open("file.txt", std::ios::out);

  return 0;
}

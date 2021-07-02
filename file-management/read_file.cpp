#include <fstream>
#include <iostream>

int main(void) {

  std::fstream in;
  in.open("file.txt");

  in.seekg(0, in.end);
  int length = in.tellg();
  in.seekg(0, in.beg);
  char *buffer = new char[length];
  std::string line;

  // Reading all at once

  if (in.is_open()) {
    in.read(buffer, length);

    std::cout << buffer;
  }
  // Reading line by line
  // if (in.is_open()) {
  //  while (!in.eof()) {
  //    std::getline(in, line);
  //    std::cout << line << "\n";
  //  }
  //}
  in.close();

  return 0;
}

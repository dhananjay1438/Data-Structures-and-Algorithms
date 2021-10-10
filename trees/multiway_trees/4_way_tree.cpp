#include <array>
#include <iostream>

#define SIZE 4
class Node {
public:
  std::array<int, SIZE - 1> keys;
  std::array<Node *, SIZE> pointers;
}

class Btree {
  Node *root;

public:
  void insert();
};

int main(void) { return 0; }

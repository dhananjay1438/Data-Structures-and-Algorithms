#include <iostream>
#include <stack>

#define SIZE 10

struct ETREE {
  struct ETREE *left;
  char data;
  struct ETREE *right;
};

typedef struct ETREE etree;

class stack {

private:
  etree *A[SIZE];
  int top;

public:
  stack();
  bool isempty();
  bool isfull();
};
stack::stack() { top = -1; }

bool stack::isempty() {
  if (top == -1) {
    return true;
  }
  return false;
}

bool stack::isfull() {
  if (top == SIZE - 1) {
    return true;
  }
  return false;
}

class myetree {
  etree *root;

public:
  myetree();
  void construct_tree(std::string);
};

myetree::myetree() { root = nullptr; }

void myetree::construct_tree(std::string exp) {

  for (size_t i = 0; i < exp.size(); i++) {
  }
}

int main(void) { return 0; }

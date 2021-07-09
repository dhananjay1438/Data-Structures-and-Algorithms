#include "../headers/binary_search_tree.hh"
#include <iostream>
#include <queue>
#include <stack>

struct node {
  node *left;
  int data;
  node *right;
  node(int);
};

node::node(int data) : left(nullptr), data(data), right(nullptr){};

class MyBST : public BST<node> {
  static int _compare(node *, node *);
public:
  friend int compare(MyBST, MyBST);
};

int MyBST::_compare(node *first, node *second) {

  std::stack<node *> fstack;
  std::queue<node *> fqueue;
  std::stack<node *> sstack;
  std::queue<node *> squeue;

  while (first || !fstack.empty()) {
    while (first) {
      fstack.push(first);
      first = first->left;
    }
    first = fstack.top();
    fstack.pop();
    fqueue.push(first);

    first = first->right;
  }

  while (second || !sstack.empty()) {
    while (second) {
      sstack.push(second);
      second = second->left;
    }
    second = sstack.top();
    sstack.pop();
    squeue.push(second);

    second = second->right;
  }

  if (fqueue.size() != squeue.size()) {
    return -2;
  }
  while (!fqueue.empty()) {

    if (fqueue.front()->data != squeue.front()->data) {
      return -1;
    }
    fqueue.pop();
    squeue.pop();
  }
  return 1;
};

int compare(MyBST first, MyBST second) {
	return MyBST::_compare(first.root, second.root);
}

int main(void) {
  MyBST first, second;

  first.insert(50);

  second.insert(50);

  std::cout << compare(first, second);

  return 0;
}

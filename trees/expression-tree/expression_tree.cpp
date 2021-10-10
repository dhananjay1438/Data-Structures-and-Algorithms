#include <iostream>

class Node {
  Node *left;
  int data;
  Node *right;
};

class ExpressionTree {

private:
  Node *root;
  void _insert();

public:
  ExpressionTree();
  void insert(std::string);
  int solve();
};

ExpressionTree::ExpressionTree() : root(nullptr) {}

void ExpressionTree::insert(std::string str) {}
int main(void) {

  std::string str;
  std::cin >> str;

  ExpressionTree exp_tree;
  exp_tree.insert(str);

  std::cout << exp_tree.solve();

  return 0;
}

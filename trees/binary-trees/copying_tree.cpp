#include "../headers/binary_search_tree.hh"
#include <iostream>

struct node {

  node *left;
  int data;
  node *right;
  node(int);
};

node::node(int data) : left(nullptr), data(data), right(nullptr) {}

class MyBST : public BST<node> {
public:
  void copytree(MyBST);
};

void MyBST::copytree(MyBST bst) {
  std::vector<int> preorder = bst.preorder();
  for (auto &x : preorder) {
    this->insert(x);
  }
}
int main(void) {

  MyBST bst, copied;
  std::vector<int> v;

  bst.insert(50);
  bst.insert(70);
  bst.insert(60);
  bst.insert(35);
  bst.insert(30);

  v = bst.preorder();

  for (auto &x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  copied.copytree(bst);

  v = copied.preorder();

  for (auto &x : v) {
    std::cout << x << " ";
  }

  return 0;
}

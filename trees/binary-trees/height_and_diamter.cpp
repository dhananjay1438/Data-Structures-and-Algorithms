#include "../headers/binary_search_tree.hh"
#include <iostream>
#include <queue>

class MyBST : public BST<> {

  int _height(node *);
  int _diameter(node *);

public:
  int height();
  int diameter();
};
int MyBST::height() { return _height(root); }
int MyBST::diameter() { return _diameter(root); }

int MyBST::_height(node *root) {

  if (root == nullptr) {
    return -1;
  }
  int lheight = _height(root->left);
  int rheight = _height(root->right);
  return std::max(lheight, rheight) + 1;
}
int MyBST::_diameter(node *root) {

  // TODO: Write diameter method
}
int main(void) {
  MyBST b;
  b.insert(50);
  b.insert(70);

  std::cout << b.height() << "\n";
  std::cout << b.diameter() << "\n";

  return 0;
}

#include "../headers/binary_search_tree.hh"
#include <iostream>

class MyBST : public BST<node> {
  BST<node> bst;
  void _mirror(node *);

public:
  void mirror();
};

void MyBST::mirror() { _mirror(root); }
void MyBST::_mirror(node *root) {
  if (root == nullptr) {
    return;
  }
  node *temp = root->left;

  root->left = root->right;
  root->right = temp;

  _mirror(root->left);
  _mirror(root->right);
}

int main(void) {

  MyBST bst;
  bst.insert(4);
  bst.insert(2);
  bst.insert(1);
  bst.insert(3);
  bst.insert(7);
  bst.insert(6);
  bst.insert(9);

  std::vector<int> arr;
  arr = bst.inorder();

  for (auto &x : arr) {
    std::cout << x << " ";
  }
  bst.mirror();
  std::cout << "\n";

  arr = bst.inorder();
  for (auto &x : arr) {
    std::cout << x << " ";
  }
  return 0;
}

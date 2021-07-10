#include "../headers/binary_search_tree.hh"
#include <iostream>

class MyBST : public BST<> {
  void _print_non_leaf_nodes(node *);

public:
  void print_non_leaf_nodes();
};

void MyBST::print_non_leaf_nodes() { _print_non_leaf_nodes(this->root); }

void MyBST::_print_non_leaf_nodes(node *root) {

  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return;
  } else {

    std::cout << root->data << " ";
  }

  _print_non_leaf_nodes(root->left);
  _print_non_leaf_nodes(root->right);
}

int main(void) {

  MyBST bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(25);
  bst.insert(70);
  bst.insert(75);

  bst.print_non_leaf_nodes();

  return 0;
}

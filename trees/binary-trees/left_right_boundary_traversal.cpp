#include "../headers/binary_search_tree.hh"
#include <iostream>

class MyBST : public BST<> {

private:
  void _left_boundary_traversal(node *);
  void _right_boundary_traversal(node *);

public:
  void left_boundary_traversal();
  void right_boundary_traversal();
};

void MyBST::left_boundary_traversal() { _left_boundary_traversal(this->root); }
void MyBST::right_boundary_traversal() {
  _right_boundary_traversal(this->root);
}

// Can also be called as left view of the tree (I guess)
void MyBST::_left_boundary_traversal(node *root) {

  if (root == nullptr) {
    return;
  }
  if (root->left) {
    std::cout << root->data << " ";
    _left_boundary_traversal(root->left);
  } else {
    std::cout << root->data << " ";
    _left_boundary_traversal(root->right);
  }
}

// Can also be called as right view of the tree (I guess)
void MyBST::_right_boundary_traversal(node *root) {
  if (root == nullptr) {
    return;
  }
  if (root->right) {
    std::cout << root->data << " ";
    _right_boundary_traversal(root->right);
  } else {
    std::cout << root->data << " ";
    _right_boundary_traversal(root->left);
  }
}
int main(void) {
  MyBST bst;

  bst.insert(50);
  bst.insert(60);
  bst.insert(70);

  bst.left_boundary_traversal();
  std::cout << "\n";
  bst.right_boundary_traversal();
  return 0;
}

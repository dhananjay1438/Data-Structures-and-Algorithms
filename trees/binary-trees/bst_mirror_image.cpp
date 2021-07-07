#include "../headers/binary_search_tree.hh"
#include <iostream>

typedef struct node {
  struct node *left;
  int data;
  struct node *right;
  node(int);
} Node;

node::node(int data) : left(nullptr), data(data), right(nullptr) {}

class MyBST : public BST<Node> {
  BST<Node> bst;
  void _mirror(Node *);

public:
  void mirror();
};

void MyBST::mirror() { _mirror(root); }
void MyBST::_mirror(Node *root) {
  if (root == nullptr) {
    return;
  }
  Node *temp = root->left;

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

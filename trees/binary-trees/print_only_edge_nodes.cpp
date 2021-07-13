// Printing edge (first and last) nodes of each level in tree
// Wrong for 50,40,30 output should be 50,40,30 but prints only 50,40
#include "../headers/binary_search_tree.hh"
#include <iostream>
#include <queue>

class MyBST : public BST<> {

  void _print_edge_nodes(node *);
  void _levelorder(node *);

public:
  void levelorder();
  void print_edge_nodes();
};

void MyBST::print_edge_nodes() { _print_edge_nodes(this->root); }

void MyBST::_print_edge_nodes(node *root) {

  if (root == nullptr) {
    return;
  }
  std::queue<node *> queue;
  std::vector<int> vec;
  queue.push(root);
  node *iteration = root;
  bool end = false;

  while (!queue.empty()) {
    root = queue.front();
    if (root->left != nullptr) {
      queue.push(root->left);
    }
    if (root->right != nullptr) {
      queue.push(root->right);
    }
    /*
     * Checking if a iteration has compeleted
     * If an iteration is completed we know that next element will be the first
     * element for level order traversal in that iteration , so we add it to
     * vector
     */
    if (end == true) {
      vec.push_back(root->data);
      end = false;
    } else if (iteration == root) {
      vec.push_back(root->data);
      iteration = queue.back();
      end = true;
    }
    queue.pop();
  }
  for (auto x : vec) {
    std::cout << x << " ";
  }
}
int main(void) {

  MyBST bst;

  bst.insert(50);
  bst.insert(40);
  bst.insert(30);
  bst.insert(20);
  bst.print_edge_nodes();

  return 0;
}

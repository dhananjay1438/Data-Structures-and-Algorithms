#include "../headers/binary_search_tree.hh"
#include <iostream>

class ThreadedNode {
protected:
  ThreadedNode *left;
  bool lthread;
  int data;
  ThreadedNode *right;
  bool rthread;
  ThreadedNode(int);
};
ThreadedNode::ThreadedNode(int data)
    : left(nullptr), lthread(false), data(data), right(nullptr),
      rthread(false) {}
// TBT = Threaded Binary Tree
// class ThreadedBinaryTree : public BST<ThreadedNode> {
//
// private:
//  void _inorder(Node *);
//
// public:
//  void create_threaded_tree();
//  void inorder();
//};

// void ThreadedBinaryTree::inorder() { _inorder(root); }
// void ThreadedBinaryTree::create_threaded_tree() {}

int main(void) {
  BST<ThreadedNode *> bst;

  bst.insert(50);
  bst.insert(40);
  bst.insert(60);
  std::vector<int> arr = bst.inorder();

  for (auto &x : arr) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  arr = bst.postorder();

  for (auto &x : arr) {
    std::cout << x << " ";
  }
  return 0;
}

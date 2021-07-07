#pragma once
#include <vector>
template <class T> class BST {
private:
  std::vector<int> traversal;

  T *_insert(T *, int);
  T *_remove(T *, int);
  T *_inorder_successor(T *);
  int _height(T *);
  void _inorder(T *);
  void _postorder(T *);
  void _preorder(T *);

protected:
  T *root;

public:
  BST();
  void insert(int);
  void remove(int);
  int height();
  std::vector<int> inorder();
  std::vector<int> postorder();
  std::vector<int> preorder();
};
#include "bst_templates_implemention.tpp"

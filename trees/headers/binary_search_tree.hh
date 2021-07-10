#pragma once
#include <vector>
struct node {
	struct node* left;
	int data;
	struct node* right;
	node(int);
};

node::node(int data) : left(nullptr), data(data), right(nullptr){}
template <class T = node> class BST {
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

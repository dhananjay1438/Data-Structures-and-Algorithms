#include <iostream>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
  int balance_factor;

  node(int t_data)
      : data(t_data), left(nullptr), right(nullptr), balance_factor(0) {}
} Node;

class AVL {

private:
  Node *_right_subtree_min(Node *);
  Node *_insert(Node *, int);
  Node *_remove(Node *, int);
  void _inorder(Node *);
  int _height(Node *);
  void _set_balance_factor(Node *);
  Node *_left_rotate(Node *);
  Node *_right_rotate(Node *);
  Node *_balance_if_unbalanced(Node *, int);

public:
  Node *root;
  AVL();
  void inorder();
  void insert(int);
  void remove(int);
  int search(int);
  int height();
};

AVL::AVL() { root = nullptr; }

void AVL::_set_balance_factor(Node *root) {

  if (root == NULL) {
    return;
  }
  root->balance_factor = _height(root->left) - _height(root->right);
}

Node *AVL::_right_rotate(Node *traverse) {

  Node *t2 = traverse->left;
  Node *temp = t2->right;

  t2->right = traverse;
  traverse->left = temp;
  return t2;
}

Node *AVL::_left_rotate(Node *traverse) {

  Node *t2 = traverse->right;
  Node *temp = t2->left;

  t2->left = traverse;
  traverse->right = temp;

  return t2;
}

node *AVL::_insert(Node *traverse, int data) {
  if (traverse == NULL) {
    traverse = new Node(data);
    return traverse;
  }
  if (data < traverse->data) {
    traverse->left = _insert(traverse->left, data);
  } else if (data > traverse->data) {
    traverse->right = _insert(traverse->right, data);
  }

  _set_balance_factor(traverse);
  if (traverse->balance_factor > 1 && data < traverse->left->data) {
    // LL problem
    // R rotation
    return _right_rotate(traverse);
  }
  if (traverse->balance_factor < -1 && data > traverse->right->data) {
    // RR Problem
    // L rotation required
    return _left_rotate(traverse);
  }
  if (traverse->balance_factor > 1 && data > traverse->left->data) {
    // LR Rotation required
    traverse->left = _left_rotate(traverse->left);
    return _right_rotate(traverse);
  }
  if (traverse->balance_factor < -1 && data < traverse->right->data) {
    // RL Rotation required
    traverse->right = _right_rotate(traverse->right);
    return _left_rotate(traverse);
  }
  return traverse;
}

void AVL::insert(int data) { root = _insert(root, data); }

void AVL::_inorder(Node *root) {

  if (root == NULL) {
    return;
  }
  _inorder(root->left);
  _inorder(root->right);
  std::cout << root->data << " ";
}

void AVL::inorder() { _inorder(root); }

void AVL::remove(int data) { root = _remove(root, data); }

Node *AVL::_remove(Node *root, int data) {

  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = _remove(root->left, data);
  } else if (data > root->data) {
    root->right = _remove(root->right, data);
  } else {

    if (root->left == NULL) {
      Node *temp = root->right;
      delete root;
      return temp;

    } else if (root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    } else {
      node *right_max = _right_subtree_min(root->right);
      root->data = right_max->data;
      root->right = _remove(root->right, root->data);
    }
  }

  _set_balance_factor(root);
  _set_balance_factor(root->left);
  _set_balance_factor(root->right);

  if (root->balance_factor == 2 && root->left->balance_factor >= 0) {

    // R rotation
    return _right_rotate(root);
  } else if (root->balance_factor == -2 && root->right->balance_factor <= 0) {

    // L rotation
    return _left_rotate(root);
  } else if (root->balance_factor == 2 && root->left->balance_factor == -1) {

    // LR rotation
    root->left = _left_rotate(root->left);
    return _right_rotate(root);

  } else if (root->balance_factor == -2 && root->right->balance_factor == 1) {
    // RL rotation
    root->right = _right_rotate(root->right);
    return _left_rotate(root);
  }
  return root;
}

Node *AVL::_right_subtree_min(Node *traverse) {
  while (traverse->left) {
    traverse = traverse->left;
  }
  return traverse;
}

int AVL::height() { return _height(root); }

int AVL::_height(Node *root) {

  if (root == NULL) {
    return -1;
  }
  int lheight = _height(root->left);
  int rheight = _height(root->right);

  return (std::max(lheight, rheight) + 1);
}

int main(void) {

  AVL avl;

  avl.insert(50);
  avl.insert(60);
  avl.insert(40);
  avl.insert(45);

  avl.remove(60);

  avl.inorder();

  return 0;
}

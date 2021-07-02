#include <iostream>

struct node {
  struct node *left;
  int data;
  int balance_factor;
  struct node *right;

  node(int);
};
node::node(int data)
    : left(nullptr), data(data), balance_factor(0), right(nullptr) {}

class AVL {

private:
  void _set_balance_factor(node *);
  int _height(node *);
  node *_insert(node *, int);
  node *_remove(node *, int);
  node *_left_rotate(node *);
  node *_right_rotate(node *);
  node *_inorder_successor(node *);
  void _postorder(node *);

protected:
  node *root;

public:
  int height();
  void insert(int);
  void remove(int);
  void postorder();
};

void AVL::postorder() { _postorder(root); }

void AVL::_postorder(node *root) {

  if (root == NULL) {
    return;
  }

  _postorder(root->left);
  _postorder(root->right);
  std::cout << root->data << " ";
}
node *AVL::_left_rotate(node *t1) {

  node *t2 = t1->right;
  node *temp = t2->left;

  t2->left = t1;
  t1->right = temp;

  //"t2" is the new root
  return t2;
}

node *AVL::_right_rotate(node *t1) {
  node *t2 = t1->left;
  node *temp = t2->right;

  t2->right = t1;
  t1->left = temp;

  //"t2" is the new root
  return t2;
}

void AVL::insert(int data) { root = _insert(root, data); }

node *AVL::_insert(node *root, int data) {
  if (root == NULL) {
    root = new node(data);
    return root;
  }

  if (data < root->data) {
    root->left = _insert(root->left, data);
  } else if (data > root->data) {
    root->right = _insert(root->right, data);
  }
  _set_balance_factor(root);
  if (root->balance_factor > 1 && data < root->left->data) {
    // LL Problem
    // R rotation
    std::cout << "R rotation\n";
    return _right_rotate(root);
  }
  if (root->balance_factor > 1 && data > root->left->data) {
    // LR rotation
    root->left = _left_rotate(root->left);
    return _right_rotate(root);
  }
  if (root->balance_factor < -1 && data > root->right->data) {
    // RR problem
    // L rotation
    std::cout << "L rotation\n";
    return _left_rotate(root);
  }
  if (root->balance_factor < -1 && data < root->right->data) {
    // RL rotation
    root->right = _right_rotate(root->right);
    return _left_rotate(root);
  }

  return root;
}
int AVL::height() { return _height(root); }

int AVL::_height(node *root) {

  if (root == NULL) {
    return -1;
  }
  int lheight = _height(root->left);
  int rheight = _height(root->right);

  return (std::max(lheight, rheight) + 1);
}

void AVL::remove(int data) { root = _remove(root, data); }

node *AVL::_remove(node *root, int data) {

  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = _remove(root->left, data);
  } else if (data > root->data) {
    root->right = _remove(root->right, data);
  } else {

    if (root->left == NULL) {
      node *temp = root->right;
      delete root;
      return temp;

    } else if (root->right == NULL) {
      node *temp = root->left;
      delete root;
      return temp;
    } else {
      node *right_max = _inorder_successor(root->right);
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

node *AVL::_inorder_successor(node *root) {
  while (root->left) {
    root = root->left;
  }
  return root;
}
void AVL::_set_balance_factor(node *root) {
  if (root == NULL) {
    return;
  }
  root->balance_factor = _height(root->left) - _height(root->right);
}

int main(void) {
  AVL avl;

  avl.insert(50);
  avl.insert(60);
  avl.insert(40);
  avl.insert(45);
  avl.postorder();

  std::cout << "\n";
  avl.remove(60);

  avl.postorder();
  std::cout << "\n" << avl.height();

  return 0;
}

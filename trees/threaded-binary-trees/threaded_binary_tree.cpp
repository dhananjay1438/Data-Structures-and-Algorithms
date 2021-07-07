#include <cassert>
#include <iostream>
#include <queue>
#include <stack>

struct node {
  struct node *left;
  bool lthread;
  int data;
  struct node *right;
  bool rthread;

  node(int);
};

node::node(int data)
    : left(nullptr), lthread(false), data(data), right(nullptr),
      rthread(false) {}

class BST {

private:
  int _height(node *);
  node *_insert(node *, int);
  node *_remove(node *, int);
  node *_inorder_successor(node *);
  void _postorder(node *);
  void _create_single_threaded_binary_tree(node *);
  void _create_double_threaded_binary_tree(node *);
  void _inorder_threaded(node *);
  void _inorder_iterative(node *);

protected:
  node *root;
public:
  int height();
  void insert(int);
  void remove(int);
  void postorder();
  void create_single_threaded_binary_tree();
  void create_double_threaded_binary_tree();
  void inorder_threaded();
  void inorder_iterative();
  BST();
};

BST::BST() : root(nullptr) {}

int BST::height() { return _height(root); }

void BST::insert(int data) { root = _insert(root, data); }

void BST::remove(int data) { root = _remove(root, data); }

void BST::postorder() { _postorder(root); }


void BST::create_single_threaded_binary_tree() {
	_create_single_threaded_binary_tree(root);
}

void BST::create_double_threaded_binary_tree() {
	_create_double_threaded_binary_tree(root);
}

void BST::inorder_threaded() {
	_inorder_threaded(root);
}

void BST::inorder_iterative() {
	_inorder_iterative(root);
}



void BST::_postorder(node *root) {

  if (root == NULL) {
    return;
  }

  _postorder(root->left);
  _postorder(root->right);
  std::cout << root->data << " ";
}

node *BST::_insert(node *root, int data) {
  if (root == NULL) {
    root = new node(data);
    return root;
  }
  if (data < root->data) {
    root->left = _insert(root->left, data);
  } else if (data > root->data) {
    root->right = _insert(root->right, data);
  }
  return root;
}

int BST::_height(node *root) {

  if (root == NULL) {
    return -1;
  }
  int lheight = _height(root->left);
  int rheight = _height(root->right);

  return (std::max(lheight, rheight) + 1);
}


node *BST::_remove(node *root, int data) {

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
  return root;
}

node *BST::_inorder_successor(node *root) {
  while (root->left) {
    root = root->left;
  }
  return root;
}

void BST::_inorder_threaded(node *root) {

  node *temp = root->left;
  if (temp == nullptr) {
    temp = root->right;
    std::cout << root->data << " ";
    if (temp == nullptr) {
      return;
    }
  }
  while (temp != nullptr) {

    while (temp->left != nullptr && temp->lthread == false) {
      temp = temp->left;
    }
    std::cout << temp->data << " ";
    while (temp->rthread == true) {
      temp = temp->right;
      std::cout << temp->data << " ";
    }
    temp = temp->right;
  }
}

void BST::_inorder_iterative(node *root) {

  std::stack<node *> stack;

  while (root != nullptr || !stack.empty()) {

    while (root != nullptr) {
      stack.push(root);
      root = root->left;
    }
    root = stack.top();
    stack.pop();
    std::cout << root->data << " ";
    root = root->right;
  }
}

void BST::_create_single_threaded_binary_tree(node *root) {

  std::queue<node *> queue;
  std::stack<node *> stack;

  while (!stack.empty() || root != nullptr) {
    while (root != nullptr) {
      stack.push(root);
      root = root->left;
    }
    root = stack.top();
    stack.pop();
    queue.push(root);
    root = root->right;
  }

  node *current = queue.front();
  queue.pop();
  while (!queue.empty()) {
    if (current->right == nullptr && current->rthread == false) {
      current->right = queue.front();
      current->rthread = true;
    }
    current = queue.front();
    queue.pop();
  }
}


void BST::_create_double_threaded_binary_tree(node *r) {

  std::stack<node *> stack;
  std::queue<node *> queue;
  node *root = r;

  while (root != nullptr || !stack.empty()) {
    while (root != nullptr) {
      stack.push(root);
      root = root->left;
    }

    root = stack.top();
    stack.pop();
    queue.push(root);
    root = root->right;
  }

  // next = inorder successor of current;

  node *first_inorder_element = queue.front();
  node *current = nullptr;
  node *predecessor = nullptr;
  while (!queue.empty()) {
    current = queue.front();
    queue.pop();
    if (current->left == nullptr && current != first_inorder_element) {
      current->left = predecessor;
      current->lthread = true;
    }
    if (current->right == nullptr && current != r && !queue.empty()) {
      //"!queue.empty" to check if it is the last element in inorder
      // traversal. If queue is empty then it is already in "current" object. As
      // it is the last element in inorder traversal we know that it must be the
      // largest value and it's right pointer must be nullptr
      //
      // "current != r" so to stop ourselves from assigning rthread or lthread
      // to root node.
      current->right = queue.front();
      current->rthread = true;
    }
    predecessor = current;
  }
}

int main(void) {

  BST bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(40);

  bst.insert(70);
  bst.insert(60);
  bst.insert(500);
  bst.insert(5000);
  bst.insert(10);
  bst.insert(45);
  bst.insert(32);
  bst.insert(100);

  bst.create_double_threaded_binary_tree();
  // bst.create_single_threaded_binary_tree(bst.root);

  bst.inorder_threaded();

  return 0;
}

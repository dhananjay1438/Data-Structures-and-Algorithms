#include <iostream>
#include <queue>

class node {
public:
  node *left;
  int data;
  node *right;
  node(int);
  node();
};
node::node(int t_data) : left(nullptr), data(t_data), right(nullptr) {}

node::node() {}

class bst {
  node *root;
  void _postorder(node *);
  void _levelorder(node *);
  node *_findparent(int);
  node *_insert(node *, int);
  node *_remove(node *, int);
  node *_find_smallest_node_in_left_subtree(node *);

public:
  bst();
  void insert(int);
  void remove(int);
  void postorder();
  void levelorder();
  int height(node *);
  void depth();
  void recursive_levelorder(node *, int);
  node *&getroot() { return root; }
};

bst::bst() : root(nullptr){};

int bst::height(node *traverse) {

  if (traverse == NULL)
    return -1;

  int lheight = height(traverse->left);
  int rheight = height(traverse->right);

  if (lheight > rheight) {
    return lheight + 1;
  } else {
    return rheight + 1;
  }
}

node *bst::_find_smallest_node_in_left_subtree(node *traverse) {
  while (traverse->left != NULL) {
    traverse = traverse->left;
  }
  return traverse;
}

void bst::remove(int data) { root = _remove(root, data); }

node *bst::_remove(node *traverse, int data) {
  if (traverse == NULL) {
    std::cout << "Tree is empty!";
    return traverse;
  }
  if (data < traverse->data) {
    traverse->left = _remove(traverse->left, data);
  } else if (data > traverse->data) {
    traverse->right = _remove(traverse->right, data);
  } else {

    if (traverse->left == NULL && traverse->right == NULL) {
      delete traverse;
      return NULL;
    } else if (traverse->right == NULL || traverse->left == NULL) {

      if (traverse->left == NULL) {
        node *temp = traverse->right;
        delete traverse;
        return temp;

      } else {
        node *temp = traverse->left;
        delete traverse;
        return temp;
      }
    } else {
      node *min = _find_smallest_node_in_left_subtree(traverse->right);
      traverse->data = min->data;
      traverse->right = _remove(traverse->right, min->data);
    }
  }
  return traverse;
}

void bst::insert(int data) { root = _insert(root, data); }

node *bst::_insert(node *traverse, int data) {

  if (traverse == NULL) {
    return new node(data);
  }
  if (data < traverse->data) {
    traverse->left = _insert(traverse->left, data);
  } else {
    traverse->right = _insert(traverse->right, data);
  }
  return traverse;
}

void bst::levelorder() { _levelorder(root); }

void bst::_levelorder(node *traverse) {

  std::queue<node *> q;
  q.push(traverse);

  while (!q.empty()) {
    node *temp = q.front();
    std::cout << temp->data << " ";
    q.pop();

    if (temp->left) {
      q.push(temp->left);
    }
    if (temp->right) {
      q.push(temp->right);
    }
  }
}

void bst::postorder() { _postorder(root); }

void bst::_postorder(node *traverse) {
  if (traverse == NULL) {
    return;
  }
  _postorder(traverse->left);
  _postorder(traverse->right);
  std::cout << traverse->data << " ";
}

int main(void) {
  bst b;
  b.insert(50);
  b.insert(70);
  b.insert(40);
  b.insert(30);
  b.insert(80);
  b.insert(35);
  b.insert(45);
  b.insert(44);
  b.insert(46);
  b.insert(42);
  b.insert(41);
  b.insert(43);
  std::cout << "\n" << b.height(b.getroot());

  return 0;
}

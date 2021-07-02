#include <iostream>
#include <queue>
#include <stack>

class node {
public:
  node *left;
  int data;
  node *right;

public:
  node(int);
};
node::node(int t_data) : left(nullptr), data(t_data), right(nullptr) {}

class bst {
  node *root;

public:
  bst();
  void insert(int);
  void remove(int);
  void search(int);
  void levelorder(node *);
  void postorder(node *);
  node *&getroot();
};

bst::bst() : root(nullptr) {}

node *&bst::getroot() { return root; }
void bst::insert(int data) {

  if (root == nullptr) {
    root = new node(data);
    return;
  }

  node *temp = root;
  while (temp != NULL) {
    if (data < temp->data) {
      if (temp->left == NULL) {
        temp->left = new node(data);
        break;
      } else {
        temp = temp->left;
      }
    } else {
      if (temp->right == NULL) {
        temp->right = new node(data);
        break;
      } else {
        temp = temp->left;
      }
    }
  }
}
void bst::levelorder(node *traverse) {
  if (root == nullptr) {
    return;
  }
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

void bst::postorder(node *traverse) {
  if (traverse == NULL) {
    return;
  }
  postorder(traverse->left);
  postorder(traverse->right);

  std::cout << traverse->data << " ";
}
int main(void) {
  bst b;
  b.insert(50);
  b.insert(40);
  b.insert(60);
  b.insert(30);
  b.insert(20);
  b.insert(70);

  b.postorder(b.getroot());
  std::cout << "\n";
  b.levelorder(b.getroot());
  return 0;
}

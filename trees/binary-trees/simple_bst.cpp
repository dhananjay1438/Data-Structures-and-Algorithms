#include <iostream>

class node {
public:
  node *left;
  int data;
  node *right;

  node(int t_data) : left(nullptr), data(t_data), right(nullptr) {}
};

class bst {

public:
  node *root;
  bst() { root = nullptr; }
  void insert(int);
  void remove(int);
  void postorder(node *);
  node *search(int);
  node *find_parent(node *);
  node *find_min_successor_right(node *);
};

node *bst::find_min_successor_right(node *traverse) {
  while (traverse->left != nullptr) {
    traverse = traverse->left;
  }
  return traverse;
}
node *bst::find_parent(node *traverse) {
  node *temp = root;

  while (temp != nullptr) {
    if (temp->left == traverse || temp->right == traverse) {
      return temp;
    } else if (traverse->data < temp->data) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return nullptr;
}
node *bst::search(int data) {
  node *traverse = root;

  while (traverse != nullptr) {
    if (traverse->data == data) {
      return traverse;
    } else if (data < traverse->data) {
      traverse = traverse->left;
    } else {
      traverse = traverse->right;
    }
  }
  return nullptr;
}
void bst::insert(int data) {
  // If it is first element
  node *temp = new node(data);
  node *traverse = root;
  if (root == nullptr) {
    root = temp;
    return;
  }

  while (traverse != nullptr) {
    if (data < traverse->data) {
      if (traverse->left == nullptr) {
        traverse->left = temp;
        break;
      } else {
        traverse = traverse->left;
      }
    } else {
      if (traverse->right == nullptr) {
        traverse->right = temp;
        break;
      } else {

        traverse = traverse->right;
      }
    }
  }
}

void bst::remove(int data) {
  node *traverse = search(data);

  if (traverse == nullptr) {
    std::cout << "Element not found\n";
    return;
  }

  node *parent = find_parent(traverse);

  if (traverse->left == nullptr) {
    // If node to be deleted is a leaf node
    if (traverse->right == nullptr) {
      if (parent->left == traverse) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
      delete traverse;
    } else {
      // If there is a node connected to right side of it
      if (parent->left == traverse) {
        parent->left = traverse->right;
      } else {
        parent->right = traverse->right;
      }
      delete traverse;
    }
  } else if (traverse->right == nullptr) {

    if (parent->left == traverse) {
      parent->left = traverse->left;
    } else {
      parent->right = traverse->left;
    }
    delete traverse;
  } else {
    // If two nodes are connected to it
    node *min = find_min_successor_right(traverse->right);
    int temp_data = min->data;
    std::cout << temp_data << "\n";
    remove(min->data);
    traverse->data = temp_data;
  }
}

void bst::postorder(node *traverse) {
  if (traverse != nullptr) {
    std::cout << traverse->data << " ";
    postorder(traverse->left);
    postorder(traverse->right);
  }
}
int main(void) {

  bst b;
  b.insert(40);
  b.insert(4);
  b.insert(34);
  b.insert(14);
  b.insert(13);
  b.insert(15);

  b.insert(45);
  b.insert(55);
  b.insert(48);

  b.insert(47);
  b.insert(49);

  b.postorder(b.root);

  return 0;
}

#include <iostream>

class node {
  node *left;
  int data;
  node *right;

public:
  node(int);
  node *&getleft();
  int &getdata();
  node *&getright();
};

node::node(int t_data) : left(NULL), data(t_data), right(NULL){};

node *&node::getleft() { return left; }

node *&node::getright() { return right; }

int &node::getdata() { return data; }

class bst {
  node *root = NULL;

public:
  bst();
  bst(int);
  void insert(node *, int);
  void remove(int);
  void postorder(node *);
  node *search(int);
  node *getroot();
  node *getparent(node *);
  node *find_min_successor_right(node *);
};

bst::bst(int val) : root(new node(val)){};

bst::bst(){};

node *bst::getroot() { return root; }

void bst::postorder(node *traverse) {
  if (traverse == NULL) {
    return;
  }

  postorder(traverse->getleft());
  std::cout << traverse->getdata() << " ";
  postorder(traverse->getright());
}

node *bst::search(int data) {

  node *traverse = root;

  while (traverse != NULL) {

    if (traverse->getdata() == data) {
      return traverse;
    } else if (data < traverse->getdata()) {
      traverse = traverse->getleft();
    } else {
      traverse = traverse->getright();
    }
  }
  return NULL;
}
node *bst::getparent(node *traverse) {
  node *parent = root;

  while (parent != NULL) {

    if (parent->getleft() == traverse || parent->getright() == traverse) {
      return parent;
    } else if (traverse->getdata() < parent->getdata()) {
      parent = parent->getleft();
    } else {
      parent = parent->getright();
    }
  }
  return NULL;
}

void bst::remove(int data) {

  node *traverse = search(data);

  if (traverse == NULL) {
    std::cout << "Element not found!\n";
    return;
  }

  node *parent = getparent(traverse);
  // If it is a leaf node or one node is connected to it
  if (traverse->getleft() == NULL) {
    // Considering it is a leaf node
    if (traverse->getright() == NULL) {
      if (parent->getleft() == traverse) {
        parent->getleft() = NULL;
      } else {
        parent->getright() = NULL;
      }
      delete traverse;
    }
    // Considering if there is a node connected to it
    else {
      if (parent->getleft() == traverse) {
        parent->getleft() = traverse->getright();
      } else {
        parent->getright() = traverse->getright();
      }
      delete traverse;
    }
  }
  // If it has one node connected to it
  else if (traverse->getright() == NULL) {
    if (parent->getleft() == traverse) {
      parent->getleft() = traverse->getleft();
    } else {
      parent->getright() = traverse->getleft();
    }
    delete traverse;
  }
  // If node is connected to 2 nodes
  else {
    node *temp = find_min_successor_right(traverse->getright());
    int val = temp->getdata();
    remove(temp->getdata());
    traverse->getdata() = val;
  }
}

node *bst::find_min_successor_right(node *traverse) {

  while (traverse->getleft() != NULL) {
    traverse = traverse->getleft();
  }
  return traverse;
}
void bst::insert(node *traverse, int val) {
  node *temp = new node(val);
  // If root is null i.e it is first element
  if (traverse == NULL) {
    traverse = temp;
    return;
  }
  while (traverse != NULL) {
    if (val < traverse->getdata()) {
      if (traverse->getleft() == NULL) {
        traverse->getleft() = temp;
        break;
      } else {
        traverse = traverse->getleft();
      }
    } else {
      if (traverse->getright() == NULL) {
        traverse->getright() = temp;
        break;
      } else {
        traverse = traverse->getright();
      }
    }
  }
}

int main(void) {
  bst b(40);
  b.insert(b.getroot(), 4);
  b.insert(b.getroot(), 34);
  b.insert(b.getroot(), 14);
  b.insert(b.getroot(), 13);
  b.insert(b.getroot(), 15);

  b.insert(b.getroot(), 45);
  b.insert(b.getroot(), 55);
  b.insert(b.getroot(), 48);

  b.insert(b.getroot(), 47);
  b.insert(b.getroot(), 49);

  b.postorder(b.getroot());
  return 0;
}


#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

class node {
  node *m_left;
  int data;
  node *m_right;

public:
  node(int);
  node *&getleft();
  node *&getright();
  int &getdata();
};

node::node(int t_data) : m_left(NULL), data(t_data), m_right(NULL) {}

node *&node::getleft() { return m_left; }

node *&node::getright() { return m_right; }

int &node::getdata() { return data; }

class binary_search_tree {
  node *m_root;

public:
  binary_search_tree(node *);
  void insert(node *);
  void display(node *);
  node *search(node *, int);
  node *get_root();
  void delete_element(node *, int);
  node *find_min_successor_right(node *);
  node *find_parent(node *);
};

binary_search_tree::binary_search_tree(node *t_root) : m_root(t_root) {}
void binary_search_tree::insert(node *x) {

  node *temp = m_root;

  while (temp != NULL) {
    if (x->getdata() < temp->getdata()) {
      if (temp->getleft() == NULL) {
        temp->getleft() = x;
        break;
      } else {
        temp = temp->getleft();
      }
    } else {
      if (temp->getright() == NULL) {
        temp->getright() = x;
        break;
      } else {
        temp = temp->getright();
      }
    }
  }
}

node *binary_search_tree::search(node *root, int x) {
  node *traverse = root;
  while (traverse != NULL) {
    if (traverse->getdata() == x) {
      return traverse;
    } else if (traverse->getdata() > x) {
      traverse = traverse->getleft();
    } else {
      traverse = traverse->getright();
    }
  }
  return NULL;
}

void binary_search_tree::display(node *traverse) {

  if (traverse != NULL) {

    display(traverse->getleft());
    std::cout << traverse->getdata() << " ";
    display(traverse->getright());
  }
}

node *binary_search_tree::get_root() { return m_root; }

node *binary_search_tree::find_parent(node *to_search) {

  node *traverse = m_root;
  node *parent = traverse;

  while (traverse->getdata() != to_search->getdata()) {
    if (traverse->getdata() > to_search->getdata()) {
      parent = traverse;
      traverse = traverse->getleft();
    } else {
      parent = traverse;
      traverse = traverse->getright();
    }
  }
  return parent;
}

void binary_search_tree::delete_element(node *root, int x) {

  node *traverse = search(root, x);

  // Real deletion
  if (traverse == NULL) {
    std::cout << "Element not found!\n";
    return;
  }
  // Trial
  // If both are null that is it has zero nodes attached to it
  node *parent = find_parent(traverse);
  if (traverse->getleft() == NULL && traverse->getright() == NULL) {
    if (parent->getleft() == traverse) {

      node *temp = parent->getleft();
      parent->getleft() = NULL;
      delete temp;
    } else {
      node *temp = parent->getright();
      parent->getright() = NULL;
      delete temp;
    }

  } else if (traverse->getleft() == NULL) {
    // This means there's an element to right of the traverse node
    std::cout << "Parent : " << parent->getdata() << "\n";
    std::cout << "child: " << traverse->getdata() << "\n";
    if (parent->getleft() == traverse) {
      parent->getleft() = traverse->getright();
    } else {
      parent->getright() = traverse->getright();
    }

    delete traverse;

  }
  // When there is node to left side of traverse i.e when it has one node
  else if (traverse->getright() == NULL) {

    std::cout << "traverse -> getright() == NULL\n";
    std::cout << "Parent : " << parent->getdata() << "\n";
    std::cout << "child: " << traverse->getdata() << "\n";
    std::cout << "child->left: " << traverse->getleft()->getdata() << "\n";
    if (parent->getleft() == traverse) {
      std::cout << "Parent -> getleft == traverse\n";
      parent->getleft() = traverse->getleft();
    } else {
      std::cout << "Parent -> getright == traverse\n";
      parent->getright() = traverse->getleft();
    }
    delete traverse;

  }
  // If there are two elements connected to node
  else {

    node *min = find_min_successor_right(traverse->getright());
    int temp_data = min->getdata();
    delete_element(traverse->getright(), min->getdata());
    traverse->getdata() = temp_data;
  }
  ///////////////////////////////////////////////////////////////////////////////////////
  // If there is no node connected to it

  /*
     if (traverse -> getleft() == NULL && traverse -> getright() == NULL)
     {
     std::cout << "Node has no nodes connected\n";

     node* parent = find_parent(traverse);

     if (parent -> getleft() != NULL && parent -> getleft() -> getdata() ==
  traverse -> getdata())
     {
     std::cout << "here";
     node * temp = parent -> getleft();
     parent -> getleft() = NULL;
     delete temp;
     }
     else
     {
     std::cout << "now here\n";

     node *temp = parent -> getright();
     parent -> getright() = NULL;
     delete temp;
     }
     }

  // If there is 1 node connected to it
  else if (traverse -> getleft() == NULL || traverse -> getright() == NULL)
  {
  std::cout << "If there is 1 node connected to it\n";
  if (traverse -> getleft() == NULL)
  {
  traverse -> getdata() = traverse -> getright() -> getdata();
  node * temp = traverse -> getright();
  traverse -> getright() = NULL;
  delete temp;
  }
  else if (traverse -> getright() == NULL)
  {
  traverse -> getdata() = traverse -> getleft() -> getdata();
  node* temp = traverse -> getleft();
  traverse -> getleft() = NULL;
  delete temp;
  }
  }
  // If there are 2 nodes connected to node which is to be deleted
  else
  {
  std::cout  << "If two nodes are connected ";
  node * temp = find_min_successor_right(traverse->getright());
  std::cout << temp ->getdata() << std::endl;
  int temp_data = temp -> getdata();
  assert(temp != NULL);
  delete_element(temp, temp -> getdata());
  traverse -> getdata() = temp_data;
  }

*/
}

node *binary_search_tree::find_min_successor_right(node *traverse) {

  while (traverse->getleft() != NULL) {
    traverse = traverse->getleft();
  }
  return traverse;
}

//////////////////////////////////////////////////////

struct Node {
  int key;
  struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    inorder(root->right);
    std::cout << root->key << " ";
  }
}

/* A utility function to
   insert a new Node with given key in
 * BST */
struct Node *insert(struct Node *Node, int key) {
  /* If the tree is empty, return a new Node */
  if (Node == NULL)
    return newNode(key);

  /* Otherwise, recur down the tree */
  if (key < Node->key)
    Node->left = insert(Node->left, key);
  else
    Node->right = insert(Node->right, key);

  /* return the (unchanged) Node pointer */
  return Node;
}

/* Given a non-empty binary search
   tree, return the Node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
struct Node *minValueNode(struct Node *Node) {
  struct Node *current = Node;

  /* loop down to find the leftmost leaf */
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct Node *deleteNode(struct Node *root, int key) {
  // base case
  if (root == NULL)
    return root;

  // If the key to be deleted
  // is smaller than the root's
  // key, then it lies in left subtree
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  // If the key to be deleted
  // is greater than the root's
  // key, then it lies in right subtree
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  // if key is same as root's key,
  // then This is the Node
  // to be deleted
  else {
    // Node with only one child or no child
    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)
    struct Node *temp = minValueNode(root->right);

    // Copy the inorder
    // successor's content to this Node
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

/////////////////////////////////

int main(void) {

  binary_search_tree b(new node(50));
  b.insert(new node(40));
  b.insert(new node(30));
  b.insert(new node(20));
  b.insert(new node(45));
  /*
  b.insert(new node(30));
  b.insert(new node(78));
  b.insert(new node(54));
  b.insert(new node(79));
  b.insert(new node(80));
  b.insert(new node(55));

  b.delete_element(b.get_root(), 79);
  b.delete_element(b.get_root(), 1);
  b.delete_element(b.get_root(), 45);
  b.delete_element(b.get_root(), 55);
  */
  b.display(b.get_root());
  return 0;
}

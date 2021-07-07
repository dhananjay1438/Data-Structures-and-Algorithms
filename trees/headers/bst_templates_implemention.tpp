template <class T> BST<T>::BST() : root(nullptr) {}

template <class T> void BST<T>::insert(int data) { root = _insert(root, data); }

template <class T> void BST<T>::remove(int data) { root = _remove(root, data); }

template <class T> int BST<T>::height() { return _height(root); }

template <class T> std::vector<int> BST<T>::inorder() {
  traversal.clear();
  _inorder(root);
  return traversal;
}

template <class T> std::vector<int> BST<T>::postorder() {
  traversal.clear();
  _postorder(root);
  return traversal;
}

template <class T> std::vector<int> BST<T>::preorder() {
  traversal.clear();
  _preorder(root);
  return traversal;
}

template <class T> T BST<T>::_insert(T root, int data) {
  if (root == nullptr) {
    root = new T(data);
    return root;
  }
  if (data < root->data) {
    root->left = _insert(root->left, data);
  } else if (data > root->data) {
    root->right = _insert(root->right, data);
  }
  return root;
}
template <class T> T BST<T>::_remove(T root, int data) {

  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = _remove(root->left, data);
  } else if (data > root->data) {
    root->right = _remove(root->right, data);
  } else {

    if (root->left == NULL) {
      T temp = root->right;
      delete root;
      return temp;

    } else if (root->right == NULL) {
      T temp = root->left;
      delete root;
      return temp;
    } else {
      T right_max = _inorder_successor(root->right);
      root->data = right_max->data;
      root->right = _remove(root->right, root->data);
    }
  }
  return root;
}

template <class T> T BST<T>::_inorder_successor(T root) {
  while (root->left) {
    root = root->left;
  }
  return root;
}
template <class T> int BST<T>::_height(T root) {

  if (root == NULL) {
    return -1;
  }
  int lheight = _height(root->left);
  int rheight = _height(root->right);

  return (std::max(lheight, rheight) + 1);
}

template <class T> void BST<T>::_inorder(T root) {
  if (root == nullptr) {
    return;
  }

  _inorder(root->left);
  traversal.push_back(root->data);
  _inorder(root->right);
}

template <class T> void BST<T>::_postorder(T root) {
  if (root == nullptr) {
    return;
  }

  _postorder(root->left);
  _postorder(root->right);
  traversal.push_back(root->data);
}

template <class T> void BST<T>::_preorder(T root) {
  if (root == nullptr) {
    return;
  }

  traversal.push_back(root->data);
  _preorder(root->left);
  _preorder(root->right);
}

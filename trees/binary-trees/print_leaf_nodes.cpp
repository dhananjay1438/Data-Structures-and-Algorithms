#include <iostream>
#include "../headers/binary_search_tree.hh"

class MyBST : public BST<> {

	private:
		void _print_leaf_nodes(node*);
	public:
		void print_leaf_nodes();

};

void MyBST::print_leaf_nodes() {
	_print_leaf_nodes(this->root);

}

void MyBST::_print_leaf_nodes(node* root) {

	if (root == nullptr) {
		return;
	}
	if (root->left == nullptr && root->right == nullptr) {
		std::cout << root->data << " ";
	}
	_print_leaf_nodes(root->left);
	_print_leaf_nodes(root->right);

}
int main(void) {

	MyBST bst;

	bst.insert(50);
	bst.insert(60);
	bst.insert(65);
	bst.insert(30);
	bst.insert(20);
	bst.insert(100);

	bst.print_leaf_nodes();

	return 0;
}

#include <iostream>

typedef struct node {
	struct node* left;
	int data;
	struct node* right;
	node(int);
}Node;

node::node(int data): left(nullptr), data(data), right(nullptr) {

}
	
void mirror(Node* root) {
	if (root == nullptr) {
		return;
	}
	Node* temp = root->left;

	root->left = root->right;
	root->right = temp;

	mirror(root->left);
	mirror(root->right);
	
}

int main(void) { 

	Node* root = new node(4);

	root->left = new node(2);
	root->left->left = new node(1);
	root->left->right = new node(3);

	root->right = new node(7);
	root->right->left = new node(6);
	root->right->right = new node(9);

	std::cout << root->left->data << " ";
	std::cout << root->right->data << " ";

	mirror(root);
	std::cout << root->left->data << " ";
	std::cout << root->right->data << " ";
	
	return 0; 
}

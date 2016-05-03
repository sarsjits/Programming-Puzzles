/**
  * Program for Inorder, Preorder and Postorder traversal
  * Resources:
  * @ sarsjits
**/

#include <iostream>

using namespace std;

struct btNode {
	int data;
	btNode *left;
	btNode *right;
};

btNode* newNode(int data);
void inorder(btNode *root);
void preorder(btNode *root);
void postorder(btNode *root);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	inorder(root);
	cout << "\n";
	preorder(root);
	cout << "\n";
	postorder(root);
	cout << "\n";
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
}

void inorder(btNode *root) {
	if(root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(btNode *root) {
	if(root == nullptr)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(btNode *root) {
	if(root == nullptr)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

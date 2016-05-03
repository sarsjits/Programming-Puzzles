/**
  * Program for printing leaf node, right-to-left and left-to-right
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
void right_to_left(btNode *root);
void left_to_right(btNode *root);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	right_to_left(root);
	cout << "\n";
	left_to_right(root);
	cout << "\n";
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
}

void right_to_left(btNode *root) {
	if(root->left == nullptr && root->right == nullptr)
		cout << root->data << " ";
	if(root->right != nullptr)
		right_to_left(root->right);
	if(root->left != nullptr)
		right_to_left(root->left);
}

void left_to_right(btNode *root) {
	if(root->left == nullptr && root->right == nullptr)
		cout << root->data << " ";
	if(root->left != nullptr)
		left_to_right(root->left);
	if(root->right != nullptr)
		left_to_right(root->right);
}

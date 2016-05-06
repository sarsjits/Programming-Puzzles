/**
  * Connect nodes of binary tree at same level for complete binary tree
  * by extending pre order traversal
  * Resources:
  * @ sarsjits
**/

#include <iostream>

using namespace std;

struct btNode {
	int data;
	btNode *left;
	btNode *right;
	btNode *next;
};

btNode* newNode(int data);
void connect(btNode *root);
void connectRecur(btNode *root);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	connect(root);
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
	tmpNode->next = nullptr;
}

void inorder(btNode *root) {
	if(root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void connect(btNode *root) {
	root->next = nullptr;
	connectRecur(root);
}

void connectRecur(btNode *root) {
	if(root == nullptr)
		return;
		
	if(root->left != nullptr) {
		root->left->next = root->right;
	}
	
	if(root->right != nullptr) {
		root->right->next = (root->next != nullptr)?(root->next->left):nullptr;
	}
	
	connectRecur(root->left);
	connectRecur(root->right);
}

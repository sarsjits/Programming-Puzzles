/**
  * Program for finding diameter of binary tree O(n^2)
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
int height(btNode *root);
int diameter(btNode *root);
int max(int a, int b) {
	if(a>b) return a;
	else return b;
}

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	cout << diameter(root);
	cout << "\n";
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
}

int height(btNode *root) {
	if(root == nullptr) return 0;
	return max(height(root->left),height(root->right)) + 1;
}

int diameter(btNode *root) {
	if(root == nullptr) return 0;
	int lheight = height(root->left);
	int rheight = height(root->right);
	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->right);
	return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

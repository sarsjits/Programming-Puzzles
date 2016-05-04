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
int diameter(btNode *root, int *height);
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
	int height = 0;
	cout << diameter(root,&height);
	cout << "\n";
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
}

int diameter(btNode *root,int *height) {
	if(root == nullptr) {
		*height = 0;
		return 0;
	}
	int lh = 0, rh = 0;
	int ld = 0, rd = 0;
	
	ld = diameter(root->left,&lh);
	rd = diameter(root->right,&rh);
	
	*height = max(lh,rh) + 1;
	
	return max(lh+rh+1,max(ld,rd));
}

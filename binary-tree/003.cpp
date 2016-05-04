/**
  * Program for printing nodes at each level
  * Resources:
  * This method takes the time O(n^2) Since for root O(1), for next O(2) ... O(n)
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
void printLevelOrder(btNode *root);
void printGivenLevel(btNode *root,int level);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	printLevelOrder(root);
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
	if(root == nullptr)
		return 0;
	int lheight = height(root->left);
	int rheight = height(root->right);
	if(lheight > rheight) return lheight + 1;
	else return rheight + 1;
}

void printLevelOrder(btNode *root) {
	int h = height(root);
	for(int i=1;i<=h;i++) {
		printGivenLevel(root,i);
	}
}

void printGivenLevel(btNode *root,int level) {
	if(root == nullptr) return;
	if(level == 1) cout << root->data << " ";
	else {
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

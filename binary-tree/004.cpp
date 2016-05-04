/**
  * Program for printing nodes at each level
  * Resources:
  * This method takes the time O(n^2) Since for root O(1), for next O(2) ... O(n)
  * @ sarsjits
**/

#include <iostream>
#include <queue>

using namespace std;

struct btNode {
	int data;
	btNode *left;
	btNode *right;
};

btNode* newNode(int data);
void printLevelOrder(btNode *root);

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

void printLevelOrder(btNode *root) {
	if(root == nullptr) return;
	
	queue<btNode *> Q;
	Q.push(root);
	while(Q.empty() == false) {
		btNode *cur = Q.front();
		cout << cur->data << " ";
		Q.pop();
		if(cur->right != nullptr)
			Q.push(cur->right);
		if(cur->left != nullptr)
			Q.push(cur->left);
	}
}

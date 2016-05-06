/**
  * Connect nodes of binary tree at same level
  * Resources:
  * @ sarsjits
**/

#include <iostream>
#include <queue>

using namespace std;

struct btNode {
	int data;
	int level;
	btNode *left;
	btNode *right;
	btNode *next;
};

btNode* newNode(int data);
void inorder(btNode *root);
void connectNode(btNode *root);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	inorder(root);
	cout << "\n";
	connectNode(root);
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
	tmpNode->next = nullptr;
	tmpNode->level = -1;
}

void inorder(btNode *root) {
	if(root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void connectNode(btNode *root) {
	if(root == nullptr)
		return;
	queue <btNode *> Q;
	Q.push(root);
	Q.push(nullptr);
	while(true) {
		btNode *cur = Q.front();
		Q.pop();
		if(cur != nullptr) {
			cur->next = Q.front();
			if(cur->left != nullptr)
				Q.push(cur->left);
			if(cur->right != nullptr)
				Q.push(cur->right);
		} else if(Q.empty() == false) {
			Q.push(nullptr);
		} else {
			break;
		}
	}
}

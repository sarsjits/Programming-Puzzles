/**
  * Clone a binary tree with a random pointer using map in C++
  * Resources:
  * @ sarsjits
**/

#include <iostream>
#include <map>

using namespace std;

struct btNode {
	int data;
	btNode *left;
	btNode *right;
	btNode *random;
};

btNode* newNode(int data);
void inorder(btNode *root);
btNode *cloneTree(btNode *root);
btNode *cloneLeftRight(btNode *root,map<btNode *,btNode *> *hmap);
void cloneRandom(btNode *cloneRoot, btNode *root,map<btNode *,btNode *>*hmap);

int main() {
	btNode *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->right = newNode(4);
	root->right->right = newNode(5);
	root->random = root->left;
	root->left->left->random = root->right;
	inorder(root);
	cout << "\n";
	btNode *cloneRoot = cloneTree(root);
	inorder(cloneRoot);
	cout << "\n";
	return 0;
}

btNode* newNode(int data) {
	btNode* tmpNode = new btNode;
	tmpNode->data = data;
	tmpNode->left = nullptr;
	tmpNode->right = nullptr;
	tmpNode->random = nullptr;
}

void inorder(btNode *root) {
	if(root == nullptr)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

btNode *cloneTree(btNode *root) {
	if(root == nullptr)
		return nullptr;
	map<btNode *,btNode *> *hmap = new map<btNode *,btNode *>;
	btNode *cloneRoot = cloneLeftRight(root,hmap);
	cloneRandom(cloneRoot,root,hmap);
	return cloneRoot; 
}

btNode *cloneLeftRight(btNode *root,map<btNode *,btNode *> *hmap) {
	if(root == nullptr)
		return nullptr;
	btNode *tmp = newNode(root->data);
	(*hmap)[root] = tmp; // Used in cloneRandom method, cloneRoot->random = (*hmap)[root->random];
	tmp->left = cloneLeftRight(root->left,hmap);
	tmp->right = cloneLeftRight(root->right,hmap);
	return tmp;
}

void cloneRandom(btNode *cloneRoot, btNode *root,map<btNode *,btNode *> *hmap) {
	if(cloneRoot == nullptr)
		return;
	cloneRoot->random = (*hmap)[root->random];
	cloneRandom(cloneRoot->left,root->left,hmap);
	cloneRandom(cloneRoot->right,root->right,hmap);
}

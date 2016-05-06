/**
  * Check if a binary tree is a subtree of another tree
  * Hint: Traverse the bigger tree in pre-order fashion
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
bool isSubtree(btNode *T, btNode *S);
bool isIdentical(btNode *T, btNode *S);

int main() {
	btNode *T = newNode(1);
	T->left = newNode(2);
	T->left->left = newNode(3);
	T->right = newNode(4);
	btNode *S = newNode(2);
	S->left = newNode(3);
	inorder(T);
	cout << "\n";
	inorder(S);
	cout << "\n";
	cout << isSubtree(T,S) << "\n";
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

bool isSubtree(btNode *T, btNode *S) {
	if(S == nullptr)
		return true;
	
	if(T == nullptr)
		return false;
		
	if(isIdentical(T,S))
		return true;
	
	return isSubtree(T->left,S) || isSubtree(T->right,S);
}

bool isIdentical(btNode *T, btNode *S) {
	if(T == nullptr && S == nullptr)
		return true;
	if(T == nullptr || S == nullptr)
		return false;
		
	return ( ( T->data == S->data ) && 
				isIdentical(T->left,S->left) && 
				isIdentical(T->right,S->right) );
}

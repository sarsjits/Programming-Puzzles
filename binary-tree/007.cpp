/**
  * Program for Inorder traversal without recursion
  * Resources:
  * @ sarsjits
**/

#include <iostream>
#include <stack>

using namespace std;

struct btNode {
	int data;
	btNode *left;
	btNode *right;
};

btNode* newNode(int data);
void inorder(btNode *root);
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
	inorder(root);
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
	stack <btNode *> st;
	btNode *cur = root;
	bool done = false;
	while(done == false) {
		if(cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		} else if(st.empty() == false) {
			cur = st.top();
			st.pop();
			cout << cur->data << " ";
			cur = cur->right;
		} else {
			done = true;
		}
	}
}

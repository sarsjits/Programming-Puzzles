// Linked List Insertion

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(): data(-1),next(nullptr) {}
	Node(int val): data(val), next(nullptr) {}
};

void insert_after(Node **prevNode,int data) {
	if((*prevNode) == nullptr) {
		cout << "The given node must not be NULL.\n";
		exit(1);
	}
	Node *newNode = new Node(data);
	newNode->next = (*prevNode)->next;
	(*prevNode)->next = newNode;
}

void printList(Node *head) {
	while(head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

int main() {
	Node *head = nullptr;
	//insert_after(&head,2);
	Node *first = new Node(1);
	head = first;
	insert_after(&first,2);
	printList(head);
	return 0;
}

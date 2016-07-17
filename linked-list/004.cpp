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

void insert_end(Node **head,int data) {
	Node *newNode = new Node(data);
	if((*head) == nullptr) {
		(*head) = newNode;
		return;
	}
	Node *tmpNode = (*head);
	while(tmpNode->next != nullptr) {
		tmpNode = tmpNode->next;
	}
	tmpNode->next = newNode;
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
	insert_end(&head,1);
	insert_end(&head,2);
	insert_end(&head,3);
	printList(head);
	return 0;
}

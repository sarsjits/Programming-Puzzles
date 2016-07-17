// Linked List Insertion

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(): data(-1),next(nullptr) {}
	Node(int val): data(val), next(nullptr) {}
};

void insert_beg(Node **head, int data) {
	Node *newNode = new Node(data);
	newNode->next = *head;
	*head = newNode;
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
	insert_beg(&head,4);
	insert_beg(&head,3);
	insert_beg(&head,2);
	insert_beg(&head,1);
	printList(head);
	return 0;
}

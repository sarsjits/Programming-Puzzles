// Linked List Basics

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(): data(-1), next(nullptr) {}
	Node(int val) : data(val), next(nullptr) {}
};

void printList(Node *head) {
	while(head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

int main() {
	Node *head = new Node(4);
	Node *second = new Node(1);
	Node *third = new Node(2);
	
	head->next = second;
	second->next = third;
	
	printList(head);
	return 0;
}

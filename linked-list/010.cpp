// Merge two sorted linked list Recursively 

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

// Recursive Solution
Node *sortedMerge(Node *a, Node *b) {
	Node *result = nullptr;
	if(a == nullptr) {
		return b;
	} else if(b == nullptr) {
		return a;
	}
	
	if(a->data <= b->data) {
		result = a;
		result->next = sortedMerge(a->next,b);
	} else {
		result = b;
		result->next = sortedMerge(a,b->next);
	}
	return result;
}

int main (int argc, char const* argv[])
{
	Node *head = nullptr;
	insert_beg(&head,7);
	insert_beg(&head,5);
	insert_beg(&head,3);
	insert_beg(&head,1);
	
	Node *head2 = nullptr;
	insert_beg(&head2,8);
	insert_beg(&head2,6);
	insert_beg(&head2,4);
	insert_beg(&head2,2);
	
	printList(head);
	printList(head2);
	
	Node *res = sortedMerge(head,head2);
	
	printList(res);
	return 0;
}

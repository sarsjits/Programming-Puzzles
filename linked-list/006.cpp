// Delete a node in linked list at given position

#include <iostream>
#include <cstdlib>

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
	if(head == nullptr) {
		cout << "List is empty.\n";
	}
	while(head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void delete_at(Node **head, int pos) {
	// Check if the list is empty or not
	if((*head) == nullptr) {
		cout << "The list is empty.\n";
		return;
	}
	
	// Check if the pos is negative, since position should be > 0
	if(pos <= 0) {
		cout << "Position must be > 0.\n";
		return;
	}
	
	Node *tmp = (*head);
	// If the position is 1
	if(pos == 1) {
		(*head) = (*head)->next;
		delete tmp;
		return;
	}
	
	for(int i=1;i<pos-1 && tmp != nullptr;i++) {
		tmp = tmp->next;
	}
	
	if(tmp == nullptr || tmp->next == nullptr) {
		cout << "The position is out of bound.\n";
		return;
	}
	
	Node *nxt = tmp->next->next;
	delete tmp->next;
	tmp->next = nxt;
}

int main() {
	Node *head = nullptr;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	printList(head);
	delete_at(&head,5);
	printList(head);
	return 0;
}

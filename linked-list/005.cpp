// Delete the first occurrence of the key in the linked list

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

// Deletes the first occurrence of the key in the linked list
void delete_key(Node **head, int key) {
	// Check if the list is empty or not
	if((*head) == nullptr) {
		cout << "The list is empty.\n";
		return;
	}
	// Check if the head itself points to the key to be deleted
	Node *tmp = (*head), *prev = nullptr;
	if(tmp->data == key) {
		(*head) = (*head)->next;
		delete tmp;
		return;
	}
	
	while(tmp != nullptr && tmp->data != key) {
		prev = tmp;
		tmp = tmp->next;
	}
	
	if(tmp == nullptr) {
		cout << "The key was not found in the list.\n";
	} else {
		prev->next = tmp->next;
		delete tmp;
	}
	return;
}

int main() {
	Node *head = nullptr;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	printList(head);
	delete_key(&head,1);
	printList(head);
	return 0;
}

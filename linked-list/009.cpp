// Search a key in the linked list

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(): data(-1),next(nullptr) {}
	Node(int d): data(d),next(nullptr) {}
};

void insert_beg(Node **head, int data) {
	Node *newNode = new Node(data);
	newNode->next = *head;
	*head = newNode;
}

void swapNodes(Node **head,int x,int y) {
	if(x == y) return;
	Node *nodeX = (*head), *nodeY = (*head), *prevX = nullptr, *prevY = nullptr;
	while(nodeX != nullptr && nodeX->data != x) {
		prevX = nodeX;
		nodeX = nodeX->next;
	}
	while(nodeY != nullptr && nodeY->data != y) {
		prevY = nodeY;
		nodeY = nodeY->next;
	}
	if(nodeX == nullptr || nodeY == nullptr) return;
	if(prevX != nullptr) {
		prevX->next = nodeY;
	} else {
		(*head) = nodeY;
	}
	if(prevY != nullptr) {
		prevY->next = nodeX;
	} else {
		(*head) = nodeX;
	}
	
	Node *tmp = nodeX->next;
	nodeX->next = nodeY->next;
	nodeY->next = tmp;
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

int main (int argc, char const* argv[])
{
	Node *head = nullptr;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	printList(head);
	swapNodes(&head,1,2);
	printList(head);
	return 0;
}

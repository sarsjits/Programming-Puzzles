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

// The function returns the position of key if found, -1 otherwise
// Iterative version
int search(Node *head,int key) {
	int pos = 1;
	while(head != nullptr && head->data != key) {
		head = head->next;
		pos += 1;
	}
	
	if(head == nullptr) {
		cout << "Key not found in the list.\n";
		return -1;
	} else {
		return pos;
	}
}

// Main recursive function
int searchMain(Node *head, int key, int pos) {
	if(head == nullptr)
		return -1;
	if(head->data == key)
		return pos;
	searchMain(head->next,key,pos+1);
}

// Recursive version
int searchRec(Node *head, int key) {
	int pos = 1;
	return searchMain(head,key,pos);
}

int main (int argc, char const* argv[])
{
	Node *head = nullptr;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	cout << searchRec(head,4) << "\n";
	return 0;
}

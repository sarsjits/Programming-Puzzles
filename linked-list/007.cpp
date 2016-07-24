// Find the length of linked list: Iteratively and Recursively

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

int lenIter(Node *head) {
	int length = 0;
	while (head != nullptr) {
		head = head->next;
		length++;
	}
	return length;
}

int lenRec(Node *head) {
	if(head == nullptr)
		return 0;
	return lenRec(head->next) + 1;
}

int main (int argc, char const* argv[])
{
	Node *head = nullptr;
	insert_beg(&head,1);
	insert_beg(&head,2);
	insert_beg(&head,3);
	insert_beg(&head,4);
	cout << "Length: " << lenIter(head) << "\n";
	cout << "Length: " << lenRec(head) << "\n";
	return 0;
}

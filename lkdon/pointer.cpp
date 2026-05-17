#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
Node* createNode(int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = nullptr;
	return newNode;
}
void addFirst(Node *& head,int value) {
	Node *p = createNode(value);
	p->next = head;
	head = p;
}
void addLast(Node *& head,int value) {
	if(head == nullptr) {
		addFirst(head,value);
		return;
	}
	Node *p = createNode(value);
	Node *a = head;
	while(a->next != nullptr) {
		a = a->next; // 1 2 3null
	}
	a->next = p;
}
void addAny(Node *& head,int value,int pos) {
	if(head == nullptr || pos <= 1) {
		addFirst(head,value);
		return;
	}
	int countPosition = 1;
	Node *p = createNode(value);
	Node *a = head;
	while(a != nullptr) {
		if(countPosition == pos-1) {
			p->next = a->next;
			a->next = p; // 7 5next 3 4 6null
			return;
			break;
		} else {
		countPosition += 1;
		a = a->next;
	 }
	}
} 
void sapxep(Node *& head) {
	if(head == nullptr) {
		return;
	}
	for(Node *i = head;i != nullptr;i = i->next) {
		for(Node *j = i->next;j != nullptr;j = j->next) {
			if(i->data > j->data) {
				swap(i->data,j->data);
			}
		}
	}
}
void display(Node *& head) {
	if(head == nullptr) {
		return;
	}
	Node *p = head;
	while(p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
}
int main() {
  Node *head = nullptr;
  addFirst(head,7);
  addLast(head,5);
  addFirst(head,4);
  addLast(head,6);
  addAny(head,3,2);
  sapxep(head);
  display(head);
	
	
	
	return 0;
}
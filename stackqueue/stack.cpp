#include<iostream>
using namespace std;
struct Node {
  int data;
  Node*next;
};
Node*makeNode(int data) {
  Node*newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  return newNode;
}
void deleteFirst(Node*&head) {
  if(head == nullptr) {
    cout << "Stack is empty. Cannot pop." << endl;
    return;
  }
  Node*temp = head;
  head = head->next;
  delete temp;
}
void addLast(Node * &head,int data) {
  if(head == nullptr) {
    Node*p = makeNode(data);
    head = p;
    return;
  }
  Node*tmp = head;
  while(tmp->next!=nullptr) {
    tmp = tmp->next;
  }
  Node*p = makeNode(data);
  tmp->next = p;
}
void addFirst(Node*&head,int value) {
  Node*p = makeNode(value);
  p->next = head;
  head = p;
}
void display(Node *head) {
  if(head == nullptr) {
    cout << "Stack is empty." << endl;
    return;
  }
  Node*tmp = head;
  while(tmp!=nullptr) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << endl;
}
int main() {
  Node*head = nullptr;
  addFirst(head, 10);
  addFirst(head, 20);
  cout << "Stack after pushing  10, 20:" << endl;
  deleteFirst(head);
  cout << "Stack after popping:" << endl;
   display(head);

  return 0;
}
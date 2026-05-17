#include<iostream>
using namespace std;
struct Node {
  int data;
  Node *next;
};
Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->next = nullptr;
  return node;
}
void dau(Node *& head,int data) {
   Node *a = newNode(data);
   a->next = head;
   head = a;
}
void l(Node *& head,Node *& head2,Node *& head3) {
  if(head == nullptr || head2 == nullptr) {
    return;
  }
  Node *p = head3;
  Node *a = head;
  Node *b = head2;
  while(a != nullptr && b != nullptr) {
      dau(head3,b->data);
      dau(head3,a->data);
      a = a->next;
      b = b->next;
  }
}
void display(Node *& head) {
  if(head == nullptr) {
    return;
  }
  Node *p = head;
  while(p != nullptr) {
    cout << p->data << " " << endl;
    p = p->next;
  }
}
int main() {
  Node *head = nullptr;
  Node *head2 = nullptr;
  Node *head3 = nullptr;
  dau(head,1);
  dau(head,2);  
  dau(head2,3);
  dau(head2,4);

  l(head,head2,head3);
  display(head3);

  return 0;
}
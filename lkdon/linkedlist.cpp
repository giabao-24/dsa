#include<iostream>
#include<string>
using namespace std;
struct Node {
  int passWord;
  Node *next;
};
Node *makeNode(int pass) {
  Node *newNode = new Node();
  newNode->passWord = pass;
  newNode->next = nullptr;
  return newNode;
}
void addFirst(Node *& head,int pass) {
  Node *p = makeNode(pass);
  p->next = head;
  head = p;
}
void display(Node *& head3) {
  if(head3 == nullptr) {
    return;
  }
  Node *p = head3;
  while(p != nullptr) {
    cout << p->passWord << " " << endl;
    p = p->next;
  }
}
void addLast(Node *& head,int pass) {
  if(head == nullptr) {
    addFirst(head,pass);
    return;
  }
  Node *p = head;
  Node *a = makeNode(pass);
  while(p->next != nullptr) {
    p = p->next;
  }
  p->next = a;
}
void addHead3(Node *& head,Node *& head2,Node *& head3) {
  Node *p = head;
  Node *p1 = head2;
  bool flag = false;
  while(p != nullptr) {
    flag = false;
    Node *a = head3;
    while(a != nullptr) {
      if (a->passWord == p->passWord) {
        flag = true;
        break;
      }
      a = a->next;
    }
    if(flag == false) {
      addLast(head3,p->passWord);
    }
    p = p->next;
  }
  while(p1 != nullptr) {
    flag = false;
    Node *a = head3;
    while(a != nullptr) {
      if (a->passWord == p1->passWord) {
        flag = true;
        break;
      }
      a = a->next;
    }
    if(flag == false) {
      addLast(head3,p1->passWord);
    }
    p1 = p1->next;
  }
}
int main() {
  Node *head = nullptr;
  Node *head2 = nullptr;
  Node *head3 = nullptr;
  addFirst(head,1);
  addLast(head2,1);
  addLast(head2,2);
  addLast(head,3);
  addFirst(head,4);
  addHead3(head,head2,head3);
  display(head3);

  return 0;
}
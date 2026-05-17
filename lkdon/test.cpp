#include<iostream>
#include<string>
using namespace std;
struct Node {
 string name;
 int age;
 Node *next;
};
Node *makeNode(string name,int age) {
  Node *newNode = new Node();
  newNode->name = name;
  newNode->age = age;
  newNode->next = nullptr;
  return newNode;
}
void addFirst(Node *& head,int age,string name) {
  Node *p = makeNode(name,age);
  p->next = head;
  head = p;
}
void addLast(Node *& head,int age,string name) {
  if(head == nullptr) {
    Node *p = makeNode(name,age);
    head = 0;  
    return;
  }
  Node *p = head;
  Node *a = makeNode(name,age);
  while(p->next != nullptr) {
    p = p->next;
  }
  p->next = a;
}
void display(Node *& head) {
  if(head == nullptr) {
    return;
  }
  Node *p = head;
  while(p != nullptr) {
    cout << p->name << " " << p->age << " " << endl;
    p = p->next;
  }
}
void addAny(Node *& head,int age,string name,int pos) {
  if(pos < 1) {
    cout << "Vi tri khong hop le" << endl;
    return;
  }
  if(pos == 1) {
    Node *p = makeNode(name,age);
    p->next = head;
    head = p;
    return;
  }
  Node *p = head;
  int countPos = 1;
  while(p->next != nullptr && countPos < pos - 1) {
    p = p->next;
    countPos++;
    if(countPos == pos - 1) {
      Node *a = makeNode(name,age);
      a->next = p->next;
      p->next = a;
      return;
    }
  }
  if(countPos == pos - 1) {
    Node *a = makeNode(name,age);
    a->next = p->next;
    p->next = a;
    return;
  }

}
int main() {
  Node *head = nullptr;
  addFirst(head,32,"Nguyen Van Long");
  addLast(head,12,"AAA");
  addAny(head,22,"BBB",2);
  display(head);

  return 0;
}
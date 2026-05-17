#include<iostream>
using namespace std;
struct Node{
  int value;
  Node *tiep;
};
Node*makeNode(int value) {
  Node *newNode = new Node();
  newNode->value = value;
  newNode->tiep = NULL;
  return newNode;
}
void deleteFirstMinus(Node *& head) {
  if(head == nullptr) {
    return;
  }
  if(head->value < 0) {
    Node*temp = head;
    head = head->tiep;
    delete temp;
    return;
  }
  Node *temp = head;
  while (temp->tiep != nullptr) 
  {
    if(temp -> tiep -> value < 0) {
      Node*sec = temp->tiep;
      temp->tiep = temp->tiep->tiep;
      delete sec;
      return;
    }
    temp = temp -> tiep;
  }
  return;
} 
int countEven(Node *& head) {
  if(head == nullptr) {
    return 0;
  }
  int count = 0;
  Node *p = head;
  while(p != nullptr) {
    if(p->value % 2 == 0) {
      count++;
    }
    p = p->tiep;
  }
  return count;
}
void addAny(Node *& head,int valueAdd) {
  if(head == nullptr) {
    return;
  }
  Node*p = head;
  while(p != nullptr) {
    if(p->value % 2 == 0) {
     Node*k = makeNode(valueAdd);
     k->tiep = p->tiep;
     p->tiep = k;
      return;
    }
    p=p->tiep;
  }
}
void addBefore(Node *&head,int target,int value) {
  if(head == nullptr) {
    return;
  }
  if(head->value == target) {
    Node*p = makeNode(value);
    p->tiep = head;
    head = p;
    return;
  }
  Node *p = head;
  while(p->tiep != nullptr) {
    if(p->tiep->value == target) {
      Node*k = makeNode(value); // 1 3 4 2 3
      k->tiep = p->tiep;
      p->tiep = k;
      return;
    }
    p = p->tiep;
  }
}
int main() {



  return 0;
}
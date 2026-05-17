#include<iostream>
using namespace std;
struct Node {
  int soNguyen;
  string muc;
  Node *next;
};  
Node *makeNode(int so,string muc) {
  Node *p = new Node();
  p->soNguyen = so;
  p->muc = muc;
  p->next=nullptr;
  return p;
}
void demSoMucChuong(Node*head,int chuong)  {
  if(head == nullptr) {
    cout << "Rong" << endl;
    return;
  }
  Node*p = head;
  int count = 0;
  while(p != nullptr) {
    if(p->soNguyen == chuong) {
       count++;
    }
    p=p->next;
  }
  cout << count << endl;
}
void addLast(Node *&head,int chuong,string muc) {
  if(head == nullptr) {
    Node*n = makeNode(chuong,muc);
    head = n;
    return;
  }
  Node*p = head;
  while(p->next != nullptr) {
    p = p->next;
  }
  Node*a = makeNode(chuong,muc);
  p->next = a;
}
void display(Node *& head) {
  if(head == nullptr) {
    return;
  }
  Node*p = head;
  while(p != nullptr) {
    cout << p->soNguyen << " ";
    p = p->next;
  }
}

int main() {
  Node*head = nullptr;
  addLast(head,3,"222");
  addLast(head,5,"222");
  addLast(head,3,"222");
  display(head);
  demSoMucChuong(head,3);


  return 0;
}
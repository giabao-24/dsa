#include<iostream>
using namespace std;
struct Node {
   int So;
   Node*Tiep;
};
Node*makeNode(int value) {
  Node * p = new Node();
  p->Tiep = nullptr;
  p->So = value;
  return p;
}
bool checkTangDan(Node *& head) {
  if(head == nullptr) {
    return false;
  }
  Node*p = head->Tiep;
  int currentValue = head->So;
  while(p != nullptr) {
    if(currentValue > p->So) {
      return false;
    }
    currentValue = p->So;
    p = p->Tiep;
  }
  return true;
}
void addFirst(Node *& head,int value) {
  Node*p = makeNode(value);
  p->Tiep = head;
  head = p;
}
void them(Node*&head,Node*&head2,Node*&head3) {
    if(head == nullptr || head2 == nullptr) {
      return;
    }
    Node*p = head;
    bool found = false;
    while(p != nullptr) {
     
       Node*q = head2;
      while(q != nullptr) {
        if(p->So == q->So) {
          Node*k = head3;
          bool found = false;
          while (k != nullptr)
          {
            found = false;
            if(k->So == q->So) {
              found = true;
              break;
            }
            k = k->Tiep;
          }
          if(found == false) {
            addFirst(head3,p->So);
          }
        }
        q = q->Tiep;
      }
      p = p->Tiep;
    }
}
void display(Node*head3) {
  if(head3 == nullptr) {
    return;
  }
  Node*p = head3;
  while(p != nullptr) {
    cout << p->So << " " ;
    p=p->Tiep;
  }
}
//cách 2 dùng 2 con trỏ
/*Vì đề đã cho 2 ds đã sắp xếp nên ta có head: 1-3-4 và head2: 1-2-4 ta đi head và head2 có 1 thêm vào,head 3 head2 
2 ko thêm,tương tự 4 thì thêm vào head3 */
void them2(Node *& head,Node*&head2,Node*&head3) {
    if(head == nullptr || head2 == nullptr) {
       return;
    }
    Node*p = head;
    Node*q = head2;
    while(p != nullptr && q != nullptr) {
      if(p->So == q->So) {
        addFirst(head3,p->So);
        p= p->Tiep;
        q = q->Tiep;
      }
      else if(p->So > q->So) {
        q= q->Tiep;
      } else {
      p = p->Tiep;
      }
    }
}
int main() {
  Node*head = nullptr;
  Node*head3 = nullptr;
  Node*head2 = nullptr;
  addFirst(head,3);
  addFirst(head,2);
  addFirst(head,1);
  addFirst(head2,1);
  addFirst(head2,2);
  addFirst(head2,6);
  them(head,head2,head3);
  display(head3);

  return 0;
}
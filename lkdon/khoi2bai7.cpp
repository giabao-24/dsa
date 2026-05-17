#include<iostream>
using namespace std;
struct Nut {
   int infor;
   Nut*next;
};
Nut*makeNut(int infor) {
  Nut*p = new Nut();
  p->infor = infor;
  p->next=nullptr;
  return p;
}
void Push(Nut*&top,int x) {
  Nut*p = makeNut(x);
  p->next=top;
  top = p;
}
int Pop(Nut*&top) {
  if(top == nullptr) return -1;
   int dropValue = top->infor;
   Nut*p = top->next;
   delete top;
   top = p;
   return dropValue;
}
void display(Nut*&head) {
  if(head == nullptr) return;
  Nut*p = head;
  while(p != nullptr) {
    cout << p->infor << " ";
    p = p->next;
  }
}
void displayRecusion(Nut*head) {
  if(head == nullptr) return;
  cout << head->infor << " ";
  displayRecusion(head->next);
}
int main() {
  Nut*head = nullptr;
  Push(head,3);
  Push(head,4);
  displayRecusion(head);

  return 0;
}
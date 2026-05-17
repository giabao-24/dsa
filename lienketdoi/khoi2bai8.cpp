#include<iostream>
using namespace std;
struct HLQ{
  string tenLHQ;
  HLQ*tiep;
};
struct Ham{
  string Name;
  string Description;
  Ham*next;
  HLQ*SeeAlso;
};
HLQ*makeHLQ(string tenlhq) {
  HLQ* p = new HLQ();
  p->tenLHQ = tenlhq;
  p->tiep = nullptr;
  return p;
}
Ham*makeHam(string name,string descrition,string tenlhq) {
   Ham*p = new Ham();
   p->Name = name;
   p->Description = descrition;
   p->next = nullptr;
   p->SeeAlso = makeHLQ(tenlhq);
   return p;
}
void addFirst(Ham*&head,string name,string description,string tenlhq) {
  Ham*p = makeHam(name,description,tenlhq);
  p->next = head;
  head = p;
}
// void addLastLHQ(Ham*&head,string tenlhq) {
//   Ham*p = head;
//   bool checkTrung = false;
//   while(p != nullptr) {
//     HLQ*a = p->SeeAlso;
//     while(a != nullptr) {
//       if(a->tenLHQ == tenlhq) {
//         cout << "Khong the them-trung ten";
//         return;
//       }
//       a=a->tiep;
//     }
//     p = p->next;
//   }
//   while(p != nullptr) {
//     HLQ*a = p->SeeAlso;
//     while(a->tiep != nullptr) {
//       a=a->tiep;
//     }
//     HLQ*n = makeHLQ(tenlhq);
//     a->tiep=n;
//     p = p->next;
//   }
// }
void display(Ham*head) {
  if(head == nullptr) return;
  Ham *p = head;
  while(p != nullptr) {
    cout << p->Name << " ";
    HLQ*a = p->SeeAlso;
    while(a != nullptr) {
      cout << a->tenLHQ << " ";
        a=a->tiep;
    }
    p = p->next;
  }
}
int main() {
   Ham*head = nullptr;
   addFirst(head,"A","B","C");
   display(head);



  return 0;
}
#include<iostream>
using namespace std;
struct NutM {
  int maM;
  NutM*Tiep;
};
struct NutGV {
  string maGV;
  string hoTen;
  NutGV*DOWN;
  NutM*DSM;
};
struct NutMH{
   int maMH;
   string tenMH;
   int soDVHT;
   NutMH*next; 
};
//2.1a
NutMH*Addr(NutMH*&p,int maMH) {
    if(p == nullptr) {
      return nullptr;
    }
    NutMH*current = p;
    while(current != nullptr) {
      if(current->maMH == maMH) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
}
NutMH*makeNode(int maMH, string tenMH, int soDVHT) {
  NutMH*newNode = new NutMH;
  newNode->maMH = maMH;
  newNode->tenMH = tenMH;
  newNode->soDVHT = soDVHT;
  newNode->next = nullptr;
  return newNode;
}
void addNutFirstMH(NutMH*&p,int maMH, string tenMH, int soDVHT) {
  NutMH*moi = makeNode(maMH, tenMH, soDVHT);
  moi->next = p;
  p = moi;
}



void addGV(NutGV*&DSGV, string maGV, string hoTen) {
  NutGV*newNode = new NutGV;
  newNode->maGV = maGV;
  newNode->hoTen = hoTen;
  newNode->DOWN = DSGV;
  newNode->DSM = nullptr;
  DSGV = newNode;
}
void addM(NutGV*&DSGV, string maGV, int maM) {
  NutGV*current = DSGV;
  while(current != nullptr) {
    if(current->maGV == maGV) {
      NutM*newNode = new NutM;
      newNode->maM = maM;
      newNode->Tiep = current->DSM;
      current->DSM = newNode;
      break;
    }
    current = current->DOWN;
  }
}
void display(NutGV*&FirstT,string maGV) {
  if(FirstT == nullptr) {
    cout << "Danh sach trong!" << endl;
    return;
  }
  NutGV*currentGV = FirstT;
  while(currentGV != nullptr) {
      if(currentGV->maGV == maGV) {
        cout << "Ma GV: " << currentGV->maGV << ", Ho Ten: " << currentGV->hoTen << endl;
        NutM*currentM = currentGV->DSM;
        cout << "Danh sach mon hoc:" << endl;
        while(currentM != nullptr) {
          cout << "- Ma M: " << currentM->maM << endl;
          currentM = currentM->Tiep;
        }
        break;
      }
      currentGV = currentGV->DOWN;
  }
}
int main() {
   /*NutGV*FirstT = nullptr;
   addGV(FirstT, "GV01", "Nguyen Van A");
   addGV(FirstT, "GV02", "Le Thi B");
   addM(FirstT, "GV01", 101);
   addM(FirstT, "GV01", 102);
   display(FirstT,"GV01");*/ //2.1b
   //2.1a
   NutMH*p = nullptr;
   addNutFirstMH(p, 101, "Toan", 3);
    addNutFirstMH(p, 102, "Ly", 4);
   cout << Addr(p, 101) << endl; //2.1a
  return 0;
}
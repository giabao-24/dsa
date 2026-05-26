#include<iostream>
using namespace std;
struct Node {
   int key;
   Node * left,*right;
};
Node *makeNode(int value) {
  Node *p = new Node();
  p->key = value;
  p->left = nullptr;
  p->right = nullptr;
  return p;
}
bool addNode(Node*&root,int value) {
      if(root != nullptr) {
        if(root->key == value) return false;//Da ton tai gia tri ,khong them
        if(root->key > value) return addNode(root->left,value);
        if(root->key < value) return addNode(root->right,value);
      }
      root = makeNode(value);
      return true;
}
void display(Node*root,int value) {
  if(root == nullptr) {cout << "Not found " << value << endl;return;}//cay rong,khong duyet
    bool check = false;
  //duyet tien thu tu
  if(root->key == value) {
    cout << "Found " << value;
    return;
  }
  if(value < root->key) {
    display(root->left,value);
  } else {
    display(root->right,value);
  }
}
int main() {
  Node*root = nullptr;
   addNode(root,3);
   addNode(root,2);
   addNode(root,5);
   addNode(root,1);
  display(root,11);
  display(root,2);
}
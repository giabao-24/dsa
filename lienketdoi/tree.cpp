#include<iostream>
#include<stack>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
Node *makeNode(int value) {
  Node *a= new Node();
  a->data = value;
  a->left = nullptr;
  a->right= nullptr;
  return a;
}
/*
void addNode(Node *& head,int value) {
  Node *p = makeNode(value);
  p->next = head;
  head = p;
}*/
void display(Node *& root) {
  if(root == nullptr) {
    return;
  }
   stack<Node*>st;
   st.push(root);
   while(!st.empty()) {
    Node *a = st.top();
    st.pop();
    cout << a->data << " " << endl;
    if(a->right != nullptr) {
      st.push(a->right);
    }
    if(a->left != nullptr) {
      st.push(a->left);
    }
   }
}
int levelOfTree(Node *& root) {
  if(root == nullptr) return 0;
  int leftLV = levelOfTree(root->left);
  int rightLV = levelOfTree(root->right);
  return max(leftLV,rightLV)+1; 
}
int main() {
  Node *root = nullptr;
  root = makeNode(1);
  root->left = makeNode(3);
  root->right = makeNode(2);
  root->left->left = makeNode(4);
  root->left->right = makeNode(5);
  //display(root);
 /*  
        1
       / \
      3   2
     / \
    4   5
 */
 cout << levelOfTree(root);
  return 0;
}
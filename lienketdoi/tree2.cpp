#include<iostream>
#include<stack>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
Node *makeNode(int data) {
 Node *p = new Node();
 p->data = data;
 p->left = nullptr;
 p->right = nullptr;
 return p;
}
void display(Node *root) {
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
int main() {
 Node *root = makeNode(1);
 root->left = makeNode(3);
  root->right = makeNode(2);
  display(root);

  return 0;
}
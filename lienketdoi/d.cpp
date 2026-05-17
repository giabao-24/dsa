#include<iostream>
#include<stack>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}
void duyetNode(Node *root) {
  if(root == nullptr) {
    return;
  }
  int count = 0;
  stack<Node*>st;
  st.push(root);
  int minValue = 10000;
  while(!st.empty()) {
    Node *a = st.top();
    st.pop();
    if(a->left == nullptr && a->right == nullptr) {
      count++;
    }
    if(a->left != nullptr) {
      st.push(a->left);
    }
    if(a->right != nullptr) {
      st.push(a->right);
    }
  }
  cout << count << endl;
}
int main() {
  Node *root = newNode(1);
  root->left = newNode(6);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(2);
  /*  1
   * / \
   * 6   3
   * / \
   * 4   5
   */
  duyetNode(root);
  return 0;
}
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
int countLeaves(Node * head) {
  if(head == nullptr) {
    return 0; //if tree is null then this tree doesn't have any leaves,return to 0
  } 
  Node*p = head; //declare a Node p = head
  if(p->left == nullptr && p->right == nullptr) {
    return 1; //Is a leaf if it left and right is null,we return 1;
  } 
  return countLeaves(p->left) + countLeaves(p->right); 
}
int countLeaves2(Node * head) {
   /*  
        1
       / \
      3   2
     / \
    4   5
 */
  int count = 0;
  if(head) {
    if(head->left == nullptr && head->right == nullptr) {
      count += 1;
    }
    if(head->left) {
      count += countLeaves2(head->left);
    }
    if(head->right) {
      count += countLeaves2(head->right);
    }
  }
  return count;
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
int levelOfTree(Node * root) {
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
  root->right->left = makeNode(6);
  root->right->right = makeNode(7);
  //display(root);
 /*  
        1
       / \
      3   2
     / \ / \
    4  5 6  7
 */
 cout << levelOfTree(root) << endl;
 cout << countLeaves2(root);
  return 0;
}
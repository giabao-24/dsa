#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node{
	int value;
	Node*left;
	Node*right;
};
Node* createNode(int value) {
	Node*p = new Node();
	p->value = value;
	p->left=nullptr;
	p->right=nullptr;
	return p;
}
void display(Node *& root) {
	stack<Node*>st;
	Node *p = root;
	while(p != nullptr || !st.empty()) { //trai goc phai
		while(p != nullptr) {
			st.push(p);
			p = p->left;
		}
		p = st.top();
		st.pop();
		cout << p->value << " ";
		p = p->right;
	}
}
void Xoa(Node *& root) {
	if(root == nullptr) {
		cout << "Cay rong-Khong the xoa!"<<endl;
		return;
	}
	stack<Node*>st;
	st.push(root);
	while(!st.empty()) {
		Node *p = st.top();
		st.pop();
		if(p->left != nullptr) st.push(p->left);
		if(p->right != nullptr) st.push(p->right);
		delete p;
	}
	root = nullptr;
}
void xoaDeQui(Node *& root) {
	if(root == nullptr) {
		return;
	}
	xoaDeQui(root->left);
	xoaDeQui(root->right);
	delete root;
	root = nullptr;
}
int height(Node *& root) {
	if(root == nullptr) return 0;
	int leftH = height(root->left);
	int rightH = height(root->right);
	return max(leftH,rightH)+1;
}
void displayMinByQueue(Node * root) {
	if(root == nullptr) {
		cout << "Danh sach rong";
		return;
	}
	queue<Node*>qu;
	qu.push(root);
	int minValue = root->value;
	while(!qu.empty()) {
		Node*p = qu.front();
		qu.pop();
		if(minValue > p->value) {
			minValue = p->value;
		}
		if(p->left != nullptr) qu.push(p->left);
		if(p->right != nullptr) qu.push(p->right);
	}
	cout << minValue ;
}
void findMin(Node *& root) {
	Node *p = root;
	stack<Node*>st;
	int minValue = root->value;
	while(!st.empty() || p != nullptr) {
		while(p != nullptr) {
			st.push(p);
			p = p->left;
		}
		p = st.top();
		st.pop();
		if (p->value < minValue) {
			minValue = p->value;
		}
		p = p->right;
	}
	cout << "Min value is " << minValue << endl;;
	/*
	2
  /  \
 /    4
3 	 /
    1
	LIFO last in first out st
     1.minValue = root->value(2) duyet goc den trai null thi dung ta co st.push(2),st.push(3),null ta co stack [2,3]
     2.Check stack xem thu be hon minValue thi gan --> duyet 3 (bo qua) duyet phai null,duyet 2 ok duyet phai null,null stack rong
     3.duyet phai ta co 4,st.push(4),st.push(1),null ta co stack [4,1]
     4.Check stack xem thu be hon minValue thi gan --> ta co p = st.pop(1) be hon 2 *swap*,st.pop(1),p = st.top(4) bo qua
	 5.null roi thi dung ta co min == 1 
	*/
}
void displayQueue(Node *root) {
  if(root == nullptr) return;
  queue<Node*>qu;
  qu.push(root);
  while(!qu.empty()) {
    Node*p = qu.front();
    qu.pop();
    cout << p->value << " ";
    if(p->left != nullptr) qu.push(p->left);
    if(p->right != nullptr) qu.push(p->right);
  }
}
void displayByStack(Node * root) {
  if(root == nullptr) return;
  stack<Node*>st;
  Node*p = root;
  while(!st.empty() || p != nullptr) {
    while(p != nullptr) {
      st.push(p);
      p = p->left;
    }
    p = st.top();
    st.pop();
    cout << p->value << " ";
    p = p->right;
  }
}
void displayRecusion(Node*root) {
  if(root == nullptr) return;
  displayRecusion(root->left);
  displayRecusion(root->right);
  cout << root->value << " ";
}
int main() {
	Node *root = createNode(2);
	root->left = createNode(3);
	root->right = createNode(4);
	root->right->left = createNode(1);
	displayRecusion(root);
	return 0;
}
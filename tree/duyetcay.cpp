#include <iostream>
using namespace std;

// Cấu trúc một nút trong BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// 1. Duyệt Tiền tự (Pre-order: N - L - R)
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";     // Thăm Gốc
        preOrder(root->left);          // Sang Trái
        preOrder(root->right);         // Sang Phải
    }
}

// 2. Duyệt Trung tự (In-order: L - N - R)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);           // Sang Trái
        cout << root->data << " ";     // Thăm Gốc
        inOrder(root->right);          // Sang Phải
    }  1223123
}

// 3. Duyệt Hậu tự (Post-order: L - R - N)
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);         // Sang Trái
        postOrder(root->right);        // Sang Phải
        cout << root->data << " ";     // Thăm Gốc
    }
}
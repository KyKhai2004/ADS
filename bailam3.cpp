#include <iostream>
using namespace std;

// Define the Node structure for the BST
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to traverse the BST 
void traverse(Node* root) {  
    if (root != nullptr) {
        cout << root->value << ", ";
        traverse(root->right);
        traverse(root->left);
    }
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    int X[] = {20, 60, 14, 5, 13, 38, 90};
    int n = sizeof(X) / sizeof(X[0]);

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, X[i]);
    }

    cout << "Traversal result: ";
    traverse(root); 
    cout << endl;

    deleteTree(root);
    return 0;
}

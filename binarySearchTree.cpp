#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        root = getNewNode(val);
    }
    else if (val <= root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool Search(Node* root, int num) {
    if (root == NULL) {
        return false;
    }
    if (root->data == num) {
        return true;
    }
    else if (num <= root->data) {
        return Search(root->left, num);
    }
    else {
        return Search(root->right, num);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    bool found = Search(root, 10);
    cout << found;
}
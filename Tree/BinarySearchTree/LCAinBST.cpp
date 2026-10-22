#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        if (root == nullptr) {
            return nullptr;
        }

        int curr = root->data;

        if (curr > n1->data && curr > n2->data) {
            return findLCA(root->left, n1, n2);
        }

        if (curr < n1->data && curr < n2->data) {
            return findLCA(root->right, n1, n2);
        }

        return root;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildbst() {
    Node* root = nullptr;
    int x;

    while (cin >> x && x != -1) {
        root = insert(root, x);
    }

    return root;
}

// Search for a node in the BST
Node* search(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) {
            return root;
        }

        if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }

    return nullptr;
}

int main() {
    Solution obj;

    cout << "Enter BST values (-1 to stop): ";
    Node* root = buildbst();

    int a, b;
    cout << "Enter two node values: ";
    cin >> a >> b;

    Node* n1 = search(root, a);
    Node* n2 = search(root, b);

    if (n1 == nullptr || n2 == nullptr) {
        cout << "One or both nodes do not exist." << endl;
        return 0;
    }

    Node* ans = obj.findLCA(root, n1, n2);

    cout << "LCA: " << ans->data << endl;

    return 0;
}
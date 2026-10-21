#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root==nullptr){
            return ;
        }
        swap(root->left,root->right);
        mirror(root->left);
        mirror(root->right);
    }
};
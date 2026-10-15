#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
}; 


class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root==nullptr) return 0;
        if(root->left==nullptr &&root->right==nullptr){
            return 1;
        }
        return countLeaves(root->left)+countLeaves(root->right);
    }
};
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
    bool hasPathSum(Node *root, int target) {
        // code here
        if(root==nullptr){
            return false;
        }
        if(root->left==nullptr &&root->right==nullptr){
            return target==root->data;
        }
        target-=root->data;
        bool l=hasPathSum(root->left,target);
        bool r=hasPathSum(root->right,target);
        return l||r;
    }
};
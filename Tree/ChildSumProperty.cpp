#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root==nullptr){
            return true;
        }
        if(root->left==nullptr &&root->right==nullptr){
            return true;
        }
        int left=0;
        int right=0;
        if(root->left!=nullptr){
            left=root->left->data;
        }
        if(root->right!=nullptr){
            right=root->right->data;
        }
        if(root->data!=left+right){
            return false;
        }
        return isSumProperty(root->left)&&isSumProperty(root->right);
    }
};
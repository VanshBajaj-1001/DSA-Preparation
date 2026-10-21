#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> preorder;
               Node* curr=root;
               while(curr!=nullptr){
                   if(curr->left==nullptr){
                       preorder.push_back(curr->data);
                       curr=curr->right;
                   }
                   else{
                       Node* prev=curr->left;
                       while(prev->right && prev->right!=curr){
                           prev=prev->right;
                       }
                       if(prev->right==nullptr){
                           prev->right=curr;
                           preorder.push_back(curr->data);
                           curr=curr->left;
                       }
                       else{
                           prev->right=nullptr;
                           curr=curr->right;
                       }
                   }
               }
               return preorder;
    }
};
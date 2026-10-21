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
  bool isLeaf(Node* root){
      return root!=nullptr && root->right==nullptr&&root->left==nullptr;
  }
  void leftboundary(Node* root, vector<int>& ans){
      Node* curr=root->left;
      while(curr!=nullptr){
          if(!isLeaf(curr)){
              ans.push_back(curr->data);
          }
          if(curr->left!=NULL){
              curr=curr->left;
          }
          else{
              curr=curr->right;
          }
      }
  }
  void leaves(Node* root,vector<int>& ans){
      if(root==nullptr){
          return;
      }
      if(isLeaf(root)){
          ans.push_back(root->data);
          return ;
      }
      leaves(root->left,ans);
      leaves(root->right,ans);
  }
  void rightboundary(Node* root, vector<int>& ans){
      Node* curr=root->right;
      vector<int> temp;
      while(curr!=nullptr){
          if(!isLeaf(curr)){
              temp.push_back(curr->data);
          }
          if(curr->right){
              curr=curr->right;
          }
          else{
              curr=curr->left;
          }
      }
      for(int i=temp.size()-1;i>=0;i--){
          ans.push_back(temp[i]);
      }
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        else{
            return {root->data};
        }
        leftboundary(root,ans);
        leaves(root,ans);
        rightboundary(root,ans);
        return ans;
    }
};
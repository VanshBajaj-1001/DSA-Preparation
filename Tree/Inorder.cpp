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
  public:vector<int> ans;
  void inorder(Node* root){
      if(root==nullptr){
          return;
      }
      inorder(root->left);
      ans.push_back(root->data);
      inorder(root->right);
  }
    vector<int> inOrder(Node* root) {
        // code here
        inorder(root);
        return ans;
    }
};
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
  int maxi=INT_MIN;
  int pathsum(Node* root){
      if(root==nullptr){
          return 0;
      }
      int left=max(0,pathsum(root->left));
      int right=max(0,pathsum(root->right));
      maxi=max(maxi,root->data+left+right);
      return root->data+max(left,right);
  }
    int findMaxSum(Node *root) {
        // code here
        pathsum(root);
        return maxi;
        
    }
};
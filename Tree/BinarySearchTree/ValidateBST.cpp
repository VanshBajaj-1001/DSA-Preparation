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
  bool valid(Node* root,long long min,long long max){
      if(root==nullptr){
          return true;
      }
      if(root->data<=min||root->data>=max){
          return false;
      }
      return valid(root->left,min,root->data)&&valid(root->right,root->data,max);
  }
    bool isBST(Node* root) {
        // code here
        return valid(root,LLONG_MIN,LLONG_MAX);
        
    }
};
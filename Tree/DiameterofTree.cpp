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
  int dia=0;
  int height(Node* root){
      if(root==nullptr){
          return 0;
      }
      int lh=height(root->left);
      int rh=height(root->right);
      dia=max(dia,rh+lh);
      return 1+max(rh,lh);
  }
    int diameter(Node* root) {
        // code here
        height(root);
        return dia;
        
    }
};
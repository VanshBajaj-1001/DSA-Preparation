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
  void solve(Node* root,vector<int>& path,vector<vector<int>>& ans){
      if(root==nullptr){
          return ;
      }
      path.push_back(root->data);
      if(root->left==nullptr&&root->right==nullptr){
          ans.push_back(path);
      }
      else{
          solve(root->left,path,ans);
          solve(root->right,path,ans);
      }
      path.pop_back();
  }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<int> path;
        vector<vector<int>> ans;
        solve(root,path,ans);
        return ans;
    }
};
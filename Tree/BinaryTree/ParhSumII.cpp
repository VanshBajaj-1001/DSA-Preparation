#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
vector<vector<int>> ans;
vector<int> path;
void solve(TreeNode* root,int target){
    if(root==nullptr){
        return ;
    }
    path.push_back(root->val);
    target-=root->val;
    if(root->right==nullptr&&root->left==NULL){
        if(target==0){
            ans.push_back(path);
        }
    }
    else{
        solve(root->left,target);
        solve(root->right,target);
    }
path.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum);
        return ans;
    }
};
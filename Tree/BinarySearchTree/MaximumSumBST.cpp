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
int maxsum;
struct info{
    bool isbst;
    int sum;
    int minval;
    int maxval;
};
info solve(TreeNode* root){
    if(root==nullptr){
        return {true,0,INT_MAX,INT_MIN};
    }
    info l=solve(root->left);
    info r=solve(root->right);
    if(l.isbst&&r.isbst&&root->val>l.maxval&&root->val<r.minval){
        int sum=root->val+r.sum+l.sum;
        maxsum=max(sum,maxsum);
        return {true,sum,min(root->val,l.minval),max(root->val,r.maxval)};

    }
    return {false,0,0,0};
}
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        solve(root);
        return maxsum;
    }
};
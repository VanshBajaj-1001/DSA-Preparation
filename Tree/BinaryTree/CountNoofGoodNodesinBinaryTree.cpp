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
int ans=0;
void solve(TreeNode* root,int maxsofar){
    if(root==nullptr){
        return ;
    }
    if(root->val>=maxsofar){
        ans++;
    }
    maxsofar=max(maxsofar,root->val);
    solve(root->left,maxsofar);
    solve(root->right,maxsofar);
}
    int goodNodes(TreeNode* root) {
        ans=0;
        solve(root,INT_MIN);
        return ans;
    }
};
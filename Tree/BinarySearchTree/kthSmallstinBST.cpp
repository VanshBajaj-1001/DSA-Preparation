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
void inorder(TreeNode* root, int& k, int& cnt,int& ans){
    if(root==nullptr){
    return;
    }
    inorder(root->left,k,cnt,ans);
    cnt++;
    if(cnt==k){
        ans=root->val;
        return;
    }
    inorder(root->right,k,cnt,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
  inorder(root,k,cnt,ans);
  return ans;
    }
};
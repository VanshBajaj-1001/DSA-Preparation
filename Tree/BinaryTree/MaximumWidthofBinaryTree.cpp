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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        long long ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long minidx=q.front().second;
            long long first=0,last=0;
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                TreeNode* node=curr.first;
                long long idx=curr.second-minidx;
                if(i==0){
                    first=idx;
                }
                if(i==size-1){
                    last=idx;
                }
                if(node->left){
                    q.push({node->left,2*idx+1});

                }
                if(node->right){
                    q.push({node->right,2*idx+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};
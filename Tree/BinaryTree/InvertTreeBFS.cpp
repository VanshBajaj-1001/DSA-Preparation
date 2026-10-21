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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()!=1){
            TreeNode* temp=q.front();
            q.pop();
            swap(temp->left,temp->right);
            if(temp->left!=NULL){
                q.push(temp->left);
            }
             if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        return root;
    }
};
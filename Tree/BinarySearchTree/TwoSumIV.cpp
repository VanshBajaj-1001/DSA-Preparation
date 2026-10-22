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
    bool findTarget(TreeNode* root, int k) {
        stack <TreeNode*> st1,st2;
        TreeNode* curr=root;
        while(curr){
            st1.push(curr);
            curr=curr->left;
        }
        curr=root;
        while(curr){
            st2.push(curr);
            curr=curr->right;
        }
        while(!st1.empty()&&!st2.empty()){
            TreeNode* l=st1.top();
            TreeNode* r=st2.top();
            if(l->val>=r->val){
                return false;
            }
            int sum=l->val+r->val;
            if(sum==k){
                return true;
            }
            else if(sum<k){
                st1.pop();
                curr=l->right;
                while(curr){
                    st1.push(curr);
                    curr=curr->left;
                }
            }
            else{
                st2.pop();
                curr=r->left;
                while(curr){
                    st2.push(curr);
                    curr=curr->right;
                }
            }
        }
        return false;
    }
};
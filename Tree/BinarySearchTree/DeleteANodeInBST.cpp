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
TreeNode* helper(TreeNode* root){
    if(root->left==nullptr){
        return root->right;
    }
    if(root->right==nullptr){
        return root->left;
    }
    TreeNode* rightchild=root->right;
    TreeNode* leftchild=root->left;
    TreeNode* succesor=rightchild;
    while(succesor->left!=nullptr){
        succesor=succesor->left;
    }
    succesor->left=leftchild;
    return rightchild;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->val>key){
                if(curr->left && curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right->val==key && curr->right){
                    curr->right=helper(curr->right);
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};
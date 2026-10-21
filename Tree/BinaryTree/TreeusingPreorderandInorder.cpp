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
unordered_map<int,int> mp;//stores index of inorder elements
int preidx=0;//decides the next element
TreeNode* build(vector<int>& preorder,int instart,int inend){
    if(instart>inend){
        return nullptr;
    }
    int rootvalue=preorder[preidx];
    preidx++;
    TreeNode* root=new TreeNode(rootvalue);
    int rootidx=mp[rootvalue];
    root->left=build(preorder,instart,rootidx-1);
    root->right=build(preorder,rootidx+1,inend);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         preidx=0;
        mp.clear();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};
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
unordered_map<int,int> mp;
int postidx;
TreeNode* build(vector<int>& postorder,int instart,int inend){
if(instart>inend){
    return nullptr;
}
int rootvalue=postorder[postidx];
postidx--;
TreeNode* root=new TreeNode(rootvalue);
int rootidx=mp[rootvalue];
root->right=build(postorder,rootidx+1,inend);
root->left=build(postorder,instart,rootidx-1);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear();
        for(int i=0;i<postorder.size();i++){
            mp[inorder[i]]=i;
        }
        postidx=postorder.size()-1;
        return build(postorder,0,postorder.size()-1);
    }
};
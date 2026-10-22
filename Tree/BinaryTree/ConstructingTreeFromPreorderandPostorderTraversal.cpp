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
unordered_map<int,int> pos;
TreeNode* build(vector<int>& pre,vector<int>& post,int prestart,int preend,int poststart,int postend){
    if(prestart>preend){
        return nullptr;
    }
    TreeNode* root=new TreeNode(pre[prestart]);
    if(prestart==preend){
        return root;
    }
    int leftroot=pre[prestart+1];
    int idx=pos[leftroot];
    int leftsize=idx-poststart+1;
    root->left=build(pre,post,prestart+1,prestart+leftsize,poststart,idx);
    root->right=build(pre,post,prestart+1+leftsize,preend,idx+1,postend-1);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            pos[postorder[i]]=i;
        }
        return build(preorder,postorder,0,n-1,0,n-1);
    }
};
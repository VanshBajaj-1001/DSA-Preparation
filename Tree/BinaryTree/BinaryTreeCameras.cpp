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
unordered_set<TreeNode*> covered;
int cam;
void dfs(TreeNode* node,TreeNode* parent){
    if(node!=nullptr){
        dfs(node->left,node);
        dfs(node->right,node);
        if((parent==nullptr&&covered.find(node)==covered.end())||covered.find(node->left)==covered.end()||covered.find(node->right)==covered.end()){
            cam++;
            covered.insert(node);
            covered.insert(parent);
            covered.insert(node->left);
            covered.insert(node->right);
        }
    }
}
    int minCameraCover(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        cam=0;
        covered.clear();
        covered.insert(nullptr);
        dfs(root,nullptr);
        return cam;
    }
};
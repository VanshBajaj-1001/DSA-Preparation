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
void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parents,TreeNode*& target,int start){
   queue<TreeNode*> q;
   q.push(root);
   parents[root]=nullptr;
   while(!q.empty()){
    TreeNode* node=q.front();
    q.pop();
    if(node->val==start){
    target=node;
    }
    if(node->left){
        parents[node->left]=node;
        q.push(node->left);
    }
    if(node->right){
        parents[node->right]=node;
        q.push(node->right);
    }
   } 
}
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target=nullptr;
        unordered_map<TreeNode*,TreeNode*> parents;
        markparents(root,parents,target,start);
        queue<TreeNode*>q;
        unordered_set<TreeNode*> visited;
        q.push(target);
  visited.insert(target);
  int time=-1;
      while(!q.empty()){
        int size=q.size();
        time++;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left&&!visited.count(node->left)){
                visited.insert(node->left);
                q.push(node->left);
            }
            if(node->right&&!visited.count(node->right)){
                visited.insert(node->right);
                q.push(node->right);
            }
            if(parents[node]&&!visited.count(parents[node])){
                visited.insert(parents[node]);
                q.push(parents[node]);
            }
        }
      }
      return time;
    }
};
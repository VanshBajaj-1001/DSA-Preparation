#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
void markparents(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>& parent){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*> parent;
    markparents(root,target,parent);
    unordered_set<TreeNode*> visited;
    int dis=0;
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);
    while(!q.empty()){
        int size=q.size();
        if(dis==k){
            vector<int> ans;
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
        }
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !visited.count(node->left)){
                visited.insert(node->left);
                q.push(node->left);
            }
            if(node->right && !visited.count(node->right)){
                visited.insert(node->right);
                q.push(node->right);
            }
            if(parent.count(node)&& !visited.count(parent[node])){
                visited.insert(parent[node]);
                q.push(parent[node]);
            }
        }
        dis++;
    }
    return {};
    }
};
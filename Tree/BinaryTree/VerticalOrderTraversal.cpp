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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            int r=curr.second.first;
            int c=curr.second.second;
            mp[c][r].insert(node->val);
            if(node->left){
                q.push({node->left,{r+1,c-1}});

            }
            if(node->right){
                q.push({node->right,{r+1,c+1}});
            }   
        }
        vector<vector<int>> ans;
        for(auto col:mp){
            vector<int> temp;
            for(auto row: col.second){
                for(int x:row.second){
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
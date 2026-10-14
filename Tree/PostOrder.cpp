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
 TreeNode* buildTree(){
    int x;
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    TreeNode* root=new TreeNode(x);
       cout << "Enter left child of " << x << ": ";
    root->left = buildTree();

    cout << "Enter right child of " << x << ": ";
    root->right = buildTree();
    return root;
 }
class Solution {
public:
vector<int> ans;
void postorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};
int main(){
    Solution obj;
      cout<<"enter root value(-1 for null)"<<endl;
    TreeNode* root=buildTree();
    vector<int> ans=obj.postorderTraversal(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
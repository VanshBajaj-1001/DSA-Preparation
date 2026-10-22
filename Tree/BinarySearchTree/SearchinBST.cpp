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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr){
            if(root->val==val){
                return root;
            }
            if(root->val>val){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return nullptr;
    }
};
TreeNode* insert(TreeNode* root,int val){
    if(root==nullptr){
        return new TreeNode(val);
    }
    if(val<root->val){
        root->left=insert(root->left,val);
    }
    else if(val>root->val){
        root->right=insert(root->right,val);
    }
    return root;
}
TreeNode* buildbst(){
    TreeNode* root=nullptr;
    int x;
    while(cin>>x &&x!=-1){
        root=insert(root,x);
    }
    return root;
}
int main(){
    Solution obj;
 cout << "Enter BST values (-1 to stop): ";
    TreeNode* root = buildbst();
int key;
cout<<"ENter value to search"<<endl;
cin>>key;
TreeNode* ans=obj.searchBST(root,key);
if(ans!=nullptr){
    cout<<"Found";
}
else{
    cout<<"not found";
}
return 0;

}
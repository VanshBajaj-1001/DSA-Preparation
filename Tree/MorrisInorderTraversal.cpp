#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> inorder;
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};
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
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        while(root!=nullptr){
            if(root->data==x){
                ceil=root->data;
                return ceil;
            }
            if(root->data<x){
                root=root->right;
            }
            else{//if root is greater than given element
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
    }
};

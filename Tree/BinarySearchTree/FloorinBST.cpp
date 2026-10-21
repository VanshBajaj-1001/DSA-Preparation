#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int floor=-1;
        while(root!=nullptr){
            if(root->data==k){
                floor=root->data;
                return floor;
            }
            if(root->data>k){
            root=root->left;
            }
            else{
                floor=root->data;
                root=root->right;
            }
        }
        return floor;
    }
};
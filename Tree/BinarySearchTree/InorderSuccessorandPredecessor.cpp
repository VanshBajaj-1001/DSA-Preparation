#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; 

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre=nullptr;
        Node* suc=nullptr;
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->data<key){
                pre=curr;
                curr=curr->right;
            }
            else{
                curr=curr->left;
            }
        }
        curr=root;
        while(curr!=nullptr){
            if(curr->data<=key){
                curr=curr->right;
            }
            else{
                suc=curr;
                curr=curr->left;
            }
        }
        return {pre,suc};
    }
};
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
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        int successor=-1;
        while(root!=nullptr){
            if(k->data>=root->data){
                root=root->right;
            }
            else{
                successor=root->data;
                root=root->left;
            }
        }
        return successor;
    }
};
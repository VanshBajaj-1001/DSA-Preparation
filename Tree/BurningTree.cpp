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
  void markparents(Node* root,unordered_map<Node*,Node*>& parents,Node*& targetnode,int target){
      queue<Node*> q;
      q.push(root);
      parents[root]=nullptr;
      while(!q.empty()){
          Node* temp=q.front();
          q.pop();
          if(temp->data==target){
              targetnode=temp;
          }
          if(temp->left){
              parents[temp->left]=temp;
              q.push(temp->left);
          }
          if(temp->right){
              parents[temp->right]=temp;
              q.push(temp->right);
          }
      }
  }
    int minTime(Node* root, int target) {
        // code here
        Node* targetnode=nullptr;
        unordered_map<Node*,Node*> parent;
        markparents(root,parent,targetnode,target);
        queue<Node*> q;
        unordered_set<Node*> visited;
        q.push(targetnode);
        visited.insert(targetnode);
        int time=-1;
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(node->left &&!visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right&& !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parent[node]&& !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }
        return time;
        
    }
};
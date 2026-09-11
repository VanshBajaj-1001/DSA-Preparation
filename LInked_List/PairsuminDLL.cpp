#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; 

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        Node* left=head;
        Node* right=tail;
        vector<vector<int>> ans;
        while(left!=right&&left->prev!=right){
            int sum=left->data+right->data;
            if(sum==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target){
                left=left->next;
            }
            else{
                right=right->prev;
            }
            
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
     Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode=new Node(x);
        if(head==nullptr){
           head=newnode;
           tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;

        }
    }
    int target;
    cin>>target;
    vector<vector<int>> ans=obj.givenSumPairs(head,target);
    for(auto i:ans){
        cout<<"[";
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<"]";
    }
return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution {
  public:
  struct compare{
      bool operator()(Node* a,Node* b){
          return a->data>b->data;
      }
  };
    Node* flatten(Node* head) {
        // code here
        if(head==NULL){
            return head;
        }
        priority_queue<Node*,vector<Node*>,compare> pq;
        Node* temp=head;
        while(temp!=NULL){
            pq.push(temp);
            temp=temp->next;
        }
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        while(!pq.empty()){
            Node* curr=pq.top();
            pq.pop();
            tail->bottom=curr;
            tail=tail->bottom;
            if(curr->bottom!=NULL){
                pq.push(curr->bottom);
            }
        }
        return dummy->bottom;
        
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        Node* first=nullptr;
        Node* bottomLast=nullptr;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            Node* newnode=new Node(x);
            if(first==NULL){
                first=newnode;
                bottomLast=newnode;
            }
            else{
                bottomLast->bottom=newnode;
                bottomLast=bottomLast->bottom;
            }
        }
        if(head==NULL){
            head=first;
            tail=first;
        }
        else{
            tail->next=first;
            tail=tail->next;
        }
    }
    Node* ans=obj.flatten(head);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->bottom;
    }
    return 0 ;
}
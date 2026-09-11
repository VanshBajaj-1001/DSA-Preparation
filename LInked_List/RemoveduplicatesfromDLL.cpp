#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if(headRef==NULL){
            return headRef;
        }
        Node* curr=headRef;
        while(curr!=NULL&&curr->next!=NULL){
  if(curr->data==curr->next->data){
      Node* duplicate=curr->next;
      curr->next=duplicate->next;
      if(duplicate->next!=NULL){
          duplicate->next->prev=curr;
      }
  }else{
      curr=curr->next;
  }

        }
        return headRef;
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
    Node*ans=obj.removeDuplicates(head);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}
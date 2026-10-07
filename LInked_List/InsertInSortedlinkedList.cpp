#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; 
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newnode= new Node(data);
        if(head==nullptr){
            newnode->next=newnode;
            return newnode;
        }
        if(data <= head->data) {
            Node* last = head;

            while(last->next != head) {
                last = last->next;
            }

            newnode->next = head;
            last->next = newnode;

            return newnode;
        }
        Node* curr=head;
        while(true){
            if(curr->data<=data&&data<=curr->next->data){
                break;
            }
            if(curr->data>curr->next->data){
                if(curr->data<=data||data<=curr->next->data){
                    break;
                }
            }
            curr=curr->next;
            if(curr==head){
                break;
            }
        }
        newnode->next=curr->next;
        curr->next=newnode;
        return head;
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
            tail=tail->next;
        }}
        if(head != nullptr) {
        tail->next = head;
    }

        int data;
        cin>>data;
        Node* ans=obj.sortedInsert(head,data);
      Node* temp=ans;
      for(int i=0;i<n+1;i++){
        cout<<temp->data<<" ";
        temp=temp->next;
      }
        return 0;

}
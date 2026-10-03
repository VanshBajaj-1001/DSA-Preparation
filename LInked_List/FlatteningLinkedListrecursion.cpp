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
  Node* merge(Node*l1,Node* l2){
      Node* dummy=new Node(-1);
      Node* result=dummy;
      while(l1!=NULL &&l2!=NULL){
          if(l1->data<l2->data){
              result->bottom=l1;
              
              l1=l1->bottom;
          }
          else{
              result->bottom=l2;
              l2=l2->bottom;
          }
          result=result->bottom;
      }
      if(l1!=NULL){
          result->bottom=l1;
      }
      if(l2!=NULL){
          result->bottom=l2;
      }
      return dummy->bottom;
  }
    Node* flatten(Node* head) {
        // code here
        if(head==NULL ||head->next==NULL){
            return head;
        }
        Node* mergedhead=flatten(head->next);
        head=merge(head,mergedhead);
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
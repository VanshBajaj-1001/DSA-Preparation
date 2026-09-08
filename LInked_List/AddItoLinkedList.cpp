#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
  Node* reverseLL(Node* head){
      if(head==NULL || head->next==NULL){
          return head;
      }
      Node* newnode=reverseLL(head->next);
      Node* front=head->next;
      front->next=head;
      head->next=NULL;
      return newnode;
  }
    Node* addOne(Node* head) {
        // code here
        head=reverseLL(head);
        int carry=1;
        Node* curr=head;
        while(curr && carry){
            int sum=curr->data+carry;
            curr->data=sum%10;
            carry=sum/10;
            if(!curr->next && carry){
                curr->next= new Node(carry);
                carry=0;
            }
            curr=curr->next;
        }
        head=reverseLL(head);
        return head;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
      Node* head1=nullptr;
    Node* tail1=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newnode= new Node(x);
        if(head1==nullptr){
            head1=newnode;
            tail1=newnode;
        }
        else{
            tail1->next=newnode;
            tail1=tail1->next;
        }
    }
    Node* ans=obj.addOne(head1);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}
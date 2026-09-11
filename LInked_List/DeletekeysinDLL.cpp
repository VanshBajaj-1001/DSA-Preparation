#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node* curr=head;
        Node* nextnode=curr->next;
        while(curr!=NULL){
            if(curr->data==x){
                if(curr->prev){
                    curr->prev->next=curr->next;
                }
                else{
                    head=curr->next;
                }
                if(curr->next){
                    curr->next->prev=curr->prev;
                }
            }
            curr=curr->next;
        }
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
            newnode->prev=tail;
            tail=newnode;

        }
    }
    int x;
    cin>>x;
    Node* ans=obj.deleteAllOccurOfX(head,x);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
     node() : val(0), next(nullptr) {}
      node(int x) : val(x), next(nullptr) {}
      node(int x, node *next) : val(x), next(next) {}
};
class Solution{
    public:
    node* reverseLL(node* head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        node* newhead=reverseLL(head->next);
        node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
    }
bool palindrome(node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
        if(fast!=NULL){
            slow=slow->next;
        }
        node* newhead=reverseLL(slow);
        node* first=head;
        node* second=newhead;
        while(second!=NULL){
            if(second->val!=first->val){
                reverseLL(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newhead);
        return true;
    
}
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    node* head=nullptr;
    node* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        node* newnode=new node(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    bool ans=obj.palindrome(head);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
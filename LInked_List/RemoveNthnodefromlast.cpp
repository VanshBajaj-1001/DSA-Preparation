#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 class Solution {
    public:
    ListNode* removefromend(ListNode* head,int n){
         ListNode* slow=head;
         ListNode* fast=head;
      for(int i=0;i<n;i++){
        fast=fast->next;
      }
      if(fast==NULL){
        ListNode* temp=head;
        head=head->next;
        return head;
      }
      while(fast->next!=NULL){
      slow=slow->next;
      fast=fast->next;
      }
      ListNode* temp=slow->next;
      slow->next=slow->next->next;
      return head;
    }
 };
 int main(){
    Solution obj;
    int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* newnode= new ListNode(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    int i;
    cin>>i;
    ListNode* ans=obj.removefromend(head,i);
    while(ans!=NULL){
        cout<<ans->val;
        ans=ans->next;
    }
    return 0;
 }
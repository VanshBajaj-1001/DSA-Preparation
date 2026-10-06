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
ListNode* reverseLL(ListNode* head){
    if(head==NULL){
        return head;
    }
    ListNode* prev=nullptr;
    while(head!=NULL){
        ListNode* front=head->next;
        head->next=prev;
        prev=head;
        head=front;
    }
    return prev;
}
    ListNode* removeNodes(ListNode* head) {
        head=reverseLL(head);
        int maxval=head->val;
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL){
            if(curr->next->val<maxval){
                curr->next=curr->next->next;
            }
            else{
                curr=curr->next;
                maxval=curr->val;
            }
        }
        head=reverseLL(head);
        return head;
    }
};
int  main(){
    Solution obj;
    int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* newnode=new ListNode(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
    }
    ListNode* ans=obj.removeNodes(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
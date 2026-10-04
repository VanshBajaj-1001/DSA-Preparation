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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return ;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=second;
        while(curr!=NULL){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        second=prev;
        ListNode* first=head;
        while(second!=NULL){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
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
    obj.reorderList(head);
    ListNode* curr=head;
    while(curr!=nullptr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    return 0;
}
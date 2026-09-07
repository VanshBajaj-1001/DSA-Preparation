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
ListNode* merge(ListNode* list1,ListNode* list2){
    ListNode* dummyNode=new ListNode(-1);

    ListNode* temp=dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;

        }
        temp=temp->next;
        
    }
    if(list1!=NULL){
        temp->next=list1;
        list1=list1->next;
    }
    else{
        temp->next=list2;
        list2=list2->next;
    }
    return  dummyNode->next;
}
ListNode* middle(ListNode* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  ListNode* slow=head;
  ListNode* fast=head->next;
  while(fast!=NULL&&fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* mid=middle(head);
        ListNode* left=head; 
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
       return merge(left,right);
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
    ListNode* ans=obj.sortList(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}
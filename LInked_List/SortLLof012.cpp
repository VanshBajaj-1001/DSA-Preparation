#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 class Solution{
    public:
    ListNode* sortzeroonetwo(ListNode*head){
        ListNode* zerodummy=new ListNode(-1);
        ListNode* onedummy=new ListNode(-1);
        ListNode* twodummy=new ListNode(-1);
        ListNode* zero=zerodummy;
        ListNode* one=onedummy;
        ListNode* two=twodummy;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==0){
                zero->next=curr;
                zero=zero->next;

            }
            else if(curr->val==1){
                one->next=curr;
                one=one->next;
            }
            else{
                two->next=curr;
                two=two->next;
            }
            curr=curr->next;
        }
        zero->next=onedummy->next;
        one->next=twodummy->next;
        two->next=NULL;
        head=zerodummy->next;
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
      ListNode* ans=obj.sortzeroonetwo(head);
      while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
      }
      return 0;
 }
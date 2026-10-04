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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessdummy=new ListNode(0);
        ListNode* greaterdummy=new ListNode(0);
        ListNode* less=lessdummy;
        ListNode* greater=greaterdummy;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val<x){
                less->next=curr;
                less=less->next;
            }
            else{
                greater->next=curr;
                greater=greater->next;
            }
            curr=curr->next;
        }
        greater->next=NULL;
        less->next=greaterdummy->next;
        return lessdummy->next;
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
    int y;
    cin>>y;
   ListNode* ans=obj.partition(head,y);
   while(ans!=NULL){
    cout<<ans->val<<" ";
    ans=ans->next;
   }
   return 0;
}
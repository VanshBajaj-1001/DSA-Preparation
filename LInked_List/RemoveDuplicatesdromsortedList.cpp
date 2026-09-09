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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        while(curr!=NULL&&curr->next!=NULL){
          if(curr->val==curr->next->val){
            curr->next=curr->next->next;
          }
          else{
            curr=curr->next;
          }
        }
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
    ListNode* ans=obj.deleteDuplicates(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return  0;
}
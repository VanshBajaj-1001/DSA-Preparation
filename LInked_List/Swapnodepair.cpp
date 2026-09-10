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
    ListNode* swapPairs(ListNode* head) {
         ListNode* dummy=new ListNode(-1);
         dummy->next=head;
         ListNode* prev=dummy;
         while(prev->next!=NULL &&prev->next->next!=NULL){
            ListNode* first=prev->next;
            ListNode* second=first->next;
            ListNode* third=second->next;
            first->next=third;
            second->next=first;
            prev->next=second;
            prev=first;
         }
         return dummy->next;
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
    ListNode* ans=obj.swapPairs(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
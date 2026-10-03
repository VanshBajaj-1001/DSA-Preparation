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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||left==right){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* a=dummy;
        for(int i=1;i<left;i++){
            a=a->next;
        }
        ListNode* curr=a->next;
        ListNode* prev=nullptr;
        ListNode* tail=a->next;
        for(int i=left;i<=right;i++){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        a->next=prev;
        tail->next=curr;
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
    int l,r;
    cin>>l>>r;
   ListNode* ans=obj.reverseBetween(head,l,r);
   while(ans!=NULL){
    cout<<ans->val<<" ";
    ans=ans->next;
   }
   return 0;
}
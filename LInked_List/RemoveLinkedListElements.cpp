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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* dummy=new ListNode(-1);
       dummy->next=head;
        ListNode* curr=dummy;
        while(curr->next!=NULL){
       if(curr->next->val==val){
        curr->next=curr->next->next;
       }
       else{
        curr=curr->next;
       }
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
    int val;
    cin>>val;
    ListNode* ans=obj.removeElements(head,val);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
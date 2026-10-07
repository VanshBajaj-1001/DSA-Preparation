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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverseLL(slow);
        ListNode* first=head;
        int ans=0;
        while(second!=NULL){
            ans=max(ans,second->val+first->val);
            second=second->next;
            first=first->next;
        }
        return ans;
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
    int ans=obj.pairSum(head);
    cout<<ans<<endl;
    return 0;   
}
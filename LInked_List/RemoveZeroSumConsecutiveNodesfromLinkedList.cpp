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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        int sum=0;
        unordered_map<int,ListNode*> mp;
        ListNode* curr=dummy;
        while(curr!=NULL){
            sum+=curr->val;
            mp[sum]=curr;
            curr=curr->next;
        }
        sum=0;
        curr=dummy;
        while(curr!=NULL){
            sum+=curr->val;
            curr->next=mp[sum]->next;
            curr=curr->next;
        }
        return dummy->next;
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
    ListNode* ans=obj.removeZeroSumSublists(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
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
ListNode* mergeTwoLL(ListNode* a,ListNode* b){
    ListNode* dummy=new ListNode(0);
    ListNode* curr=dummy;
    while(a!=NULL&&b!=NULL){
        if(a->val<=b->val){
            curr->next=a;
            a=a->next;
        }
        else{
            curr->next=b;
            b=b->next;
        }
        curr=curr->next;
    }
    if(a!=NULL){
        curr->next=a;
    }
    if(b!=NULL){
        curr->next=b;
    }
    return dummy->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode* ans=nullptr;
        for(int i=0;i<lists.size();i++){
            ans=mergeTwoLL(ans,lists[i]);
        }
        return ans;
    }
};
int main(){
    int k;
    cin>>k;
    vector<ListNode*>lists;
    for(int i=0;i<k;i++){
   int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int j=0;j<n;j++){
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
    lists.push_back(head);
    }
    Solution obj;
    ListNode* ans=obj.mergeKLists(lists);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL||k==0){
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        tail->next=head;
        k=k%len;
        if(k==0){
            return head;
        }
        int stepsTonewtail=len-k;
        ListNode* newTail=head;
        for(int i=1;i<stepsTonewtail;i++){
        newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        newTail->next=NULL;
        return newHead;
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
    int k;
    cin>>k;
    ListNode* ans=obj.rotateRight(head,k);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
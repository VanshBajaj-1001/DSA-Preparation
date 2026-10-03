
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
ListNode* findkthnode(ListNode* curr,int k){
    while(curr!=NULL&&k>1){
        curr=curr->next;
        k--;
    }
    return curr;
}
ListNode* reverseLL(ListNode* head){
    ListNode*curr=head;
    ListNode* prev=nullptr;
    while(curr!=NULL){
        ListNode* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return head;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL ||k<=1){
            return head;
        }
        ListNode* temp=head;;
        ListNode* prevLast=nullptr;
        while(temp!=NULL){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==nullptr){
                if(prevLast!=nullptr){
                    prevLast->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;
            reverseLL(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevLast->next=kthnode;
            }
            prevLast=temp;
            temp=nextnode;
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
        }}
        int k;
        cin>>k;
        ListNode* ans=obj.reverseKGroup(head,k);
        while(ans!=NULL){
            cout<<ans->val<<" ";
            ans=ans->next;
        }
    return 0;
}
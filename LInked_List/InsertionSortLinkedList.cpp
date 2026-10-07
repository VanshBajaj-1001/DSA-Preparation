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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted=nullptr;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* next=curr->next;
            if(sorted==nullptr||curr->val<=sorted->val){
                curr->next=sorted;
                sorted=curr;
            }
            else{
                ListNode* temp=sorted;
                while(temp->next!=nullptr&&temp->next->val<curr->val){
                    temp=temp->next;
                }
                curr->next=temp->next;
                temp->next=curr;
            }
            curr=next;
        }
        return sorted;
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
    ListNode* ans=obj.insertionSortList(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
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
    ListNode* prev=NULL;
    while(head!=NULL){
        ListNode* front=head->next;
        head->next=prev;
        prev=head;
        head=front;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        int carry=0;
        while(carry|| l1!=NULL||l2!=NULL){
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            int digit=sum%10;
             carry=sum/10;
            ListNode* newnode=new ListNode(digit);
            if(head==nullptr){
                head=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=tail->next;
            }

        }
        head=reverseLL(head);
        return head;

    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
 ListNode* head1=nullptr;
    ListNode* tail1=nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ListNode* newnode=new ListNode(x);
        if(head1==nullptr){
            head1=newnode;
            tail1=newnode;

        }
        else{
            tail1->next=newnode;
            tail1=tail1->next;
        }
    }
    int m;
    cin>>m;
 ListNode* head2=nullptr;
    ListNode* tail2=nullptr;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        ListNode* newnode=new ListNode(x);
        if(head2==nullptr){
            head2=newnode;
            tail2=newnode;

        }
        else{
            tail2->next=newnode;
            tail2=tail2->next;
        }
    }
    ListNode* ans=obj.addTwoNumbers(head1,head2);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
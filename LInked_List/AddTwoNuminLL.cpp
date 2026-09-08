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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0;
        while(carry||l1!=NULL||l2!=NULL){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
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
        ListNode* newnode= new ListNode(x);
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
        ListNode* newnode= new ListNode(x);
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
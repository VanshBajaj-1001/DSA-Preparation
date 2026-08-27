#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode (int x,ListNode* next): val(x), next(next) {}
};
class Solution {
    public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        ListNode* newhead=reverseLL(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
return newhead;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ListNode* newnode=new ListNode(x);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    ListNode* ans=obj.reverseLL(head);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}
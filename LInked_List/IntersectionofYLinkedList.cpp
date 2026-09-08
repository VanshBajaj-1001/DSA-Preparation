#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* d1=headA;
    ListNode* d2=headB;
    while(d1!=d2){
        if(d1==NULL){
            d1=headB;

        }
        else{
            d1=d1->next;
        }
        if(d2==NULL){
            d2=headA;
        }
        else{
            d2=d2->next;
        }
    }
    return d1;
    }
};int main(){
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
       int k;
    cin >> k;

    ListNode* commonHead = NULL;
    ListNode* commonTail = NULL;

    for(int i = 0; i < k; i++) {

        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if(commonHead == NULL) {
            commonHead = newNode;
            commonTail = newNode;
        }
        else {
            commonTail->next = newNode;
            commonTail = newNode;
        }
    }
       if(tail1 != NULL)
        tail1->next = commonHead;
    else
        head1 = commonHead;
if(tail2 != NULL)
        tail2->next = commonHead;
    else
        head2 = commonHead;
        ListNode* ans=obj.getIntersectionNode(head1,head2);
        if(ans!=NULL){
            cout<<"Intersection at "<<ans->val<<endl;
        }
else{
    cout<<"No Intersection found"<<endl;
}
return 0;
}
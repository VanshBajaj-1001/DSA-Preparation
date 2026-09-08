#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
    public:
    ListNode* intersection(ListNode* head1,ListNode* head2){
        int l1=0;
ListNode* curr1=head1;
        while(curr1!=NULL){
              l1++;
              curr1=curr1->next;
        }
        int l2=0;
        ListNode* curr2=head2;
   while(curr2!=NULL){
    l2++;
    curr2=curr2->next;
   }
   int diff=l1-l2;
  if(diff<0){
 while(diff++!=0){
  head2=head2->next;
 }
  }
  else{
    while(diff--!=0){
      head1=head1->next;
    }
  }
  while(head1!=NULL){
    if(head1==head2){
      return head1;
    }
    head1=head1->next;
    head2=head2->next;
  }

return head1;
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
ListNode* ans=obj.intersection(head1,head2);
if(ans!=NULL){
  cout<<"Intersection at"<<ans->val<<endl;
}
else{
  cout<<"Not Found"<<endl;
}
return 0;
  }
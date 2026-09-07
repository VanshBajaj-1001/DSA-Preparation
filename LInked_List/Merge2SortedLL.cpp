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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){return list2;}
        if(list2==NULL)return list1;
        ListNode *head=NULL;
        ListNode *tail=NULL;
        if(list1->val<list2->val){
            head=tail=list1;
            list1=list1->next;
        }
        else{
            head=tail=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(list1!=NULL){
            tail->next=list1;
        }
        if(list2!=NULL){
            tail->next=list2;
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
    ListNode* ans=obj.mergeTwoLists(head,head2);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    return 0;
}
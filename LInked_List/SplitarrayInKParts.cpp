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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int size=n/k;
        int extra=n%k;
        vector<ListNode*> ans;
        ListNode* curr=head;
        for(int i=0;i<k;i++){
          int partSize=size;
          if(extra>0){
            partSize++;
            extra--;
          }
          if(partSize==0){
            ans.push_back(NULL);
            continue;
          }
          ListNode*partHead=curr;
          for(int j=1;j<partSize;j++){
            curr=curr->next;
          }
          ListNode* nextpart=curr->next;
          curr->next=nullptr;
          curr=nextpart;
          ans.push_back(partHead);
        }
        return ans;
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
    int k;
    cin>>k;
    vector<ListNode*> ans=obj.splitListToParts(head,k);
    for(int i=0;i<ans.size();i++){
        ListNode* temp=ans[i];
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
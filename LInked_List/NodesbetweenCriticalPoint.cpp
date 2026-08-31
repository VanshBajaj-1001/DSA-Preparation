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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1;
        int prevcritical=-1;
        int index=1;
        int mindis=INT_MAX;
        ListNode* prev=head;
        ListNode * curr=head->next;
        while(curr->next!=nullptr){
            ListNode* next=curr->next;
            bool locmaxima=curr->val>next->val && curr->val>prev->val;
            bool locminima=curr->val<next->val && curr->val<prev->val;
            if(locmaxima||locminima){
                if(first==-1){
                    first=index;
                    prevcritical=index;
                }
                else{
                    mindis=min(mindis,index-prevcritical);
                    prevcritical=index;
                }
            }
            prev=curr;
            curr=next;
            index++;

        }
        if(first==prevcritical){
            return {-1,-1};
        }
        int maxdis=prevcritical-first;
        return {mindis,maxdis};
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
    vector<int> ans=obj.nodesBetweenCriticalPoints(head);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
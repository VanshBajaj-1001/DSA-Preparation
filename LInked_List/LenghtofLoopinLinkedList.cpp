#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x),next(next) {}
};
class Solution {
    public:
    int lengthofloop(ListNode* head){
        int l=0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                l=1;
                ListNode* temp=slow->next;
                while(temp!=fast){
                    l++;
                    temp=temp->next;
                }

                return l;
            }
        }
        return 0;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* tail=nullptr;
    vector<ListNode*> nodes;
    for(int i=0;i<n;i++){
   int x;
   cin>>x;
   ListNode* newnode=new ListNode(x);
   nodes.push_back(newnode);
   if(head==nullptr){
    head=newnode;
    tail=newnode;
   }
   else{
    tail->next=newnode;
    tail=newnode;
   }
    }
    int pos;
    cin>>pos;
    if(pos!=-1){
        tail->next=nodes[pos];
    }
    int ans=obj.lengthofloop(head);
    cout<<ans<<endl;
    return 0;
}
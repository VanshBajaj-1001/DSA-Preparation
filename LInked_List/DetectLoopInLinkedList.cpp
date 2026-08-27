#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
    int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;

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
    cin >> pos;
     // Create cycle
    if(pos != -1) {
        tail->next = nodes[pos];
    }
    bool ans=obj.hasCycle(head);
    if(ans){
        cout<<"Cycle Detected"<<endl;
    }
    else{
  cout<<"Cycle not detected"<<endl;
    }
return 0;
}
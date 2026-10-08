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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL){
            ans=ans*2+head->val;
            head=head->next;
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
    cout<<obj.getDecimalValue(head)<<endl;
    return 0;
}
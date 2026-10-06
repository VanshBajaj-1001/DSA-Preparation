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
public://comvert LL into array
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
       vector<int> nums;
       while(curr!=NULL){
        nums.push_back(curr->val);
        curr=curr->next;
       }
       vector<int> ans(nums.size(),0);
       stack<int> st;
       for(int i=0;i<nums.size();i++){
        while(!st.empty()&&nums[i]>nums[st.top()]){
            ans[st.top()]=nums[i];
            st.pop();
        }
        st.push(i);
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
    vector<int> ans=obj.nextLargerNodes(head);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
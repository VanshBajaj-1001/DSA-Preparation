#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>  st;
        int n=nums.size();
        vector<int> ans(nums.size(),-1);
        for(int i=2*n-1;i>=0;i--){
            int index=i%n;
            while(!st.empty()&&st.top()<=nums[index]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ans[index]=st.top();
                }
            }
            st.push(nums[index]);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> ans=obj.nextGreaterElements(nums);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
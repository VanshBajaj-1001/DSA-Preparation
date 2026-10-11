#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //next greater elemnt implementation
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top()-i;
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
    vector<int> nums(n);
    for(int i=0;i<n;i++){
cin>>nums[i];
    }
    vector<int> ans=obj.dailyTemperatures(nums);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
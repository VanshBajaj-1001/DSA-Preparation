#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> nse(vector<int> &nums){
    int n=nums.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while
        (!st.empty()&&nums[st.top()]>=nums[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans; 
}
vector<int> pse(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,-1);
   stack<int> st;
   for(int i=0;i<n;i++){
    while(!st.empty()&&nums[st.top()]>nums[i]){
        st.pop();
    }
    if(!st.empty()){
        ans[i]=st.top();
    }
    st.push(i);
   }
   return ans;
}
   long long sumSubarrayMins(vector<int>& arr) {
int n=arr.size();
vector<int> a(n);
vector<int> b(n);
          a=pse(arr);
         b=nse(arr);
        long long total=0;
        long long mod=1000000007;
        for(int i=0;i<n;i++){
           long long left=i-a[i];
            long long right=b[i]-i;
        total+=right*left*arr[i];

        }
        return total;
    }
  vector<int> nge(vector<int>&arr){
stack<int> st;
        vector<int> ans(arr.size(),arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
  }
  vector<int> pge(vector<int> arr){
    stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
  }
  long long sumSubarrayMax(vector<int>& nums) {
    int n=nums.size();
    vector<int> a(n);
    vector<int> b(n);
    a=pge(nums);
    b=nge(nums);
    long long total=0;
    for(int i=0;i<n;i++){
      long long  left=i-a[i];
        long long right=b[i]-i;
        total+=right*left*nums[i];
    }
    return total;
  }
    long long subArrayRanges(vector<int>& nums) {
return sumSubarrayMax(nums)-sumSubarrayMins(nums);
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
    cout<<obj.subArrayRanges(nums)<<endl;
    return 0;
}
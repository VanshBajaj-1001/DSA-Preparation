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
    int sumSubarrayMins(vector<int>& arr) {
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
long long contribution=left * right % mod;;
contribution=contribution*arr[i]%mod;
total=(total+contribution)%mod;
        }
        return (int)total;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=obj.sumSubarrayMins(arr);
    cout<<ans<<endl;
    return 0;
}
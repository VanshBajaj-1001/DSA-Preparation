#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i,int end,vector<int>& nums,vector<int> &dp){
    if(i>end){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int rob=nums[i]+solve(i+2,end,nums,dp);
    int skip=solve(i+1,end,nums,dp);
    dp[i]=max(rob,skip);
    return dp[i];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> arr1(n,-1);
        vector<int> arr2(n,-1);
        int case1=solve(0,n-2,nums,arr1);
        int case2=solve(1,n-1,nums,arr2);
        return max(case1,case2);
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
    cout<<obj.rob(nums)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i,vector<int>& points,vector<int>&dp){
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int take=points[i]+solve(i-2,points,dp);
    int skip=solve(i-1,points,dp);
    dp[i]=max(take,skip);
    return dp[i];
}
    int deleteAndEarn(vector<int>& nums) {
        int maximum=*max_element(nums.begin(),nums.end());
        vector<int> points(maximum+1,0);
        for(int i:nums){
            points[i]+=i;
        }
        vector<int> dp(maximum+1,-1);
return solve(maximum,points,dp);
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
cout<<obj.deleteAndEarn(nums)<<endl;
return 0;
}
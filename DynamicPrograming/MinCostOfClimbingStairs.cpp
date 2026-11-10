#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int climb(int i,vector<int>& cost,vector<int>&dp){
    int n=cost.size();
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int one=climb(i+1,cost,dp);
    int two=climb(i+2,cost,dp);
    return dp[i]=cost[i]+min(one,two);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(climb(0,cost,dp),climb(1,cost,dp));
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<int> cost(n);
    for(int i=0;i<n;i++){
cin>>cost[i];
    }
    cout<<obj.minCostClimbingStairs(cost)<<endl;
    return 0;
}
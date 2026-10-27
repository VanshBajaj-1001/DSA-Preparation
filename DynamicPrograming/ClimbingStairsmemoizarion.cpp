#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(vector<int>& dp,int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int onestep=solve(dp,n-1);
    int twostep=solve(dp,n-2);
    dp[n]=onestep+twostep;
    return dp[n];
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    cout<<obj.climbStairs(n)<<endl;
    return 0;
}
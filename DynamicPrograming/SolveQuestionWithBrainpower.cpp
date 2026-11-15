#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
long long solve(int i,vector<vector<int>>& questions,vector<long long>&dp){
    if(i>=questions.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    long long solveq=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
    long long skipq=solve(i+1,questions,dp);
    dp[i]=max(solveq,skipq);
    return dp[i];
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,dp);
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<vector<int>> questions(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>questions[i][0]>>questions[i][1];
    }
    cout<<obj.mostPoints(questions)<<endl;
    return 0;
}
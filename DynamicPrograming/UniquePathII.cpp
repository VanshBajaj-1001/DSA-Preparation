#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
if(obstacleGrid[i][j]==1){
    dp[i][j]=0;
    continue;
}
if(i==0&&j==0){
    continue;
}
int up=0;
int left=0;
if(i>0){
    up=dp[i-1][j];
}
if(j>0){
    left=dp[i][j-1];
}
dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};
int main(){
    Solution obj;
 int m;
 int n;
 cin>>m>>n;
 vector<vector<int>> grid(m,vector<int>(n));
 for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>grid[i][j];
    }
 }
 cout<<obj.uniquePathsWithObstacles(grid)<<endl;
 return 0;
}
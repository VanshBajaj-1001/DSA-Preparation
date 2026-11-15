#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};
int main(){
    Solution obj;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
     for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }}
            cout<<obj.minPathSum(grid)<<endl;
            return 0;
}



/*class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};*/
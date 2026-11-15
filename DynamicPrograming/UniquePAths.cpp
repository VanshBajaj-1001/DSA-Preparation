#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
            dp[0][0]=1;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
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
    int n;
    int m;
    cin>>m>>n;
    cout<<obj.uniquePaths(m,n)<<endl;
    return 0;
}
/*

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                dp[j] = dp[j] + dp[j - 1];

            }
        }

        return dp[n - 1];
    }
};
space optimized code
*/
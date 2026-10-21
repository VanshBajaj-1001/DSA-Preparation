#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        int min=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }

        }
        while(!q.empty()&&fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                int nr,nc;
                nr=row-1;
                nc=col;
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});//addind rotten orange to queue
                }
                nr=row+1;
                nc=col;
                 if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});//addind rotten orange to queue
                }
                nr=row;
                nc=col-1;
                 if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});//addind rotten orange to queue
                }
                nr=row;
                nc=col+1;
                 if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});//addind rotten orange to queue
                }
            }
            min++;
        }
        if(fresh>0){
            return -1;
        }
        return min;
    }
};
int  main(){
    Solution obj;
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<"Time:"<<obj.orangesRotting(grid)<<endl;
    return 0;
}
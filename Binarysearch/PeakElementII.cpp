#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int row=0;
            for(int i=0;i<n;i++){
                if(mat[i][mid]>mat[row][mid]){
                    row=i;
                }  
            }
            int left=(mid>0)?mat[row][mid-1]:-1;
            int right=(mid<m-1)?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<right){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return {-1,-1};
    }
};
int main()
{
    Solution obj;
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<int> ans=obj.findPeakGrid(mat);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}
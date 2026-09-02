#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int h=m*n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target){
                return  true;
            }       
            else if(matrix[r][c]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
             }
             return false;

    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> matrix (n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
}
int x;
cin>>x;
bool ans=obj.searchMatrix(matrix,x);
if(ans){
    cout<<"True";
}
else{
    cout<<"False";
}
return 0;
}
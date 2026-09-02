#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int column=m-1;
        while(row<n && column>=0){
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]<target){
                row++;
            }
            else{
                column--;
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
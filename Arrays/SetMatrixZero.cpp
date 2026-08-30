#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();    // no of rows
        int m = matrix[0].size(); // no of columns;
        bool firstrowhaszero=false;
        bool firstcolhaszero=false;
        //check if the first row has 0
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                firstrowhaszero=true;
                break;
            }
        }
        //similarly check if first column has 0
        for(int j=0;j<n;j++){
            if(matrix[j][0]==0){
                firstcolhaszero=true;
                break;
            }
        }
        //mark for the rest of the array 
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }

            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0|| matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrowhaszero){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(firstcolhaszero){
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }
    }
};
int main(){
    Solution obj;
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> matrix(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    obj.setZeroes(matrix);
    cout<<"output "<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;

    }
}
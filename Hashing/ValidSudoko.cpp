#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10]={};
        bool col[9][10]={};
        bool box[9][10]={};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int num=board[i][j]-'0';
                int boxIndex=(i/3)*3 +(j/3);
                if(row[i][num]||col[j][num]||box[boxIndex][num]){
                    return false;
                }
                row[i][num]=true;
                  col[j][num]=true;
                  box[boxIndex][num]=true;
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
 vector<vector<char>> board(9,vector<char>(9));
 for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
  cin>>board[i][j];
    }
 }
 bool ans=obj.isValidSudoku(board);
 if(ans){
    cout<<"true";
 }
 else{
    cout<<"false";
 }
 return 0;
}
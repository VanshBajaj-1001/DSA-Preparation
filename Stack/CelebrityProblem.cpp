#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(mat[b][a]==1){
                st.push(a);
            }
            else{   
                st.push(b);
            }
        }
        if(st.empty()){
            return -1;
        }
        int candidate=st.top();
        st.pop();
        for(int i=0;i<n;i++){
            if(i==candidate)continue;
            if(mat[candidate][i]==1||mat[i][candidate]==0){
                return -1;
            }
        }
        return candidate;
    }
};
int main(){
    Solution obj;
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<obj.celebrity(mat)<<endl;
    return 0;
}
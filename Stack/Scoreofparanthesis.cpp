#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c:s){
            if(c=='('){
                st.push(0);
            }
            else{
                int x=st.top();
                st.pop();
                int score;
                if(x==0){
                    score=1;
                }
                else{
                    score=2*x;
                }
                st.top()+=score;
            }
        }
        return st.top();
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.scoreOfParentheses(s)<<endl;
    return 0;
}
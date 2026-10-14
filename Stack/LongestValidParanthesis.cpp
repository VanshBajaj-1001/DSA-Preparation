#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else {
                    maxi=max(maxi,i-st.top());
                }
            }
        }
        return maxi;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.longestValidParentheses(s)<<endl;
    return 0;
}
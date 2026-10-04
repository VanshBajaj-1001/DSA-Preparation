#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char>st;
        for(char ch:S){
            st.push(ch);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    string ans=obj.reverse(s);
    cout<<ans<<endl;
    return 0;
}
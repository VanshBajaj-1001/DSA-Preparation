#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(char ch:s){
           if(ch=='('||ch=='{'||ch=='['){
                st.push(ch);
            }
            else{
            if(st.empty()){
                return false;
                
            }
            if(ch==')'&&st.top()!='('){
                return false;
            }
            if(ch=='}'&&st.top()!='{'){
                return false;
            }
            if(ch==']'&&st.top()!='['){
                return false;
            }
            st.pop();
            }
            
        }
        return st.empty();
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    bool ans=obj.isBalanced(s);
    if(ans){
        cout<<"True";
    }
    else{
        cout<<"false";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        int n=path.size();
        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            string part="";
            while(i<n && path[i]!='/'){
                part+=path[i];
                i++;
            }
            if(part=="."){
                continue;
            }
            else if(part==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(part);
            }
        }
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.empty()){
            return "/";
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.simplifyPath(s)<<endl;
    return 0;
}
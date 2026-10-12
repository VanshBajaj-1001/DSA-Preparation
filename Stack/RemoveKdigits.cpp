#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch:num){
            while(!st.empty()&&st.top()>ch&&k>0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()&&ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        if(ans=="")return "0";
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
int k;
cin>>k;
string ans=obj.removeKdigits(s,k);
cout<<ans<<endl;
return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
    if(s[0]!='0'){
        dp[1]=1;
    }
    for(int i=2;i<=n;i++){
        if(s[i-1]!='0'){
            dp[i]+=dp[i-1];
        }
        int num=(s[i-2]-'0')*10+(s[i-1]-'0');
        if(num>=10&&num<=26){
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
    }
};
int main(){
    Solution obj;
    string s;
    getline(cin,s);
    cout<<"No of ways to decode "<<s<<" are "<<obj.numDecodings(s)<<endl;
    return 0;
}
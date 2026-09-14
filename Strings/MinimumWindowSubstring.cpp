#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(char c:t){
            mp[c]++;
        }
        int l=0;
        int start=0;
        int minLen=INT_MAX;
        int cnt=0;
        for(int r=0;r<s.size();r++){
            if(mp[s[r]]>0){
                cnt++;
            }
            mp[s[r]]--;
            while(cnt==t.size()){
            if(r-l+1<minLen){
                minLen=r-l+1;
                start=l;
            }
            mp[s[l]]++;//removing left element
            if(mp[s[l]]>0){
              cnt--;
            }
            l++;
            }
        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};
int main(){
    Solution obj;
    string s;
    string t;
    cin>>s;
    cin>>t;
    if(t.size()>s.size()){
        return 0;
    }
    cout<<obj.minWindow(s,t)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        unordered_map<char,int> mp;
        int n=s.size();
        int maxlen=0;
        while(r<n){
            if(mp.count(s[r])==1){
                mp.erase(s[l]);
                l++;
            }
            else{
            mp[s[r]]++;
              maxlen=max(maxlen,r-l+1);
              r++;
            }
        }
        return maxlen;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.lengthOfLongestSubstring(s)<<endl;
    return 0;
}
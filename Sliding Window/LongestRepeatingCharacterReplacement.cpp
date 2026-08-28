#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int ans=0;
        int maxfreq=0;
        vector<int> freq(26,0);
        for(int r=0;r<s.size();r++){
          freq[s[r]-'A']++;
          maxfreq=max(maxfreq,freq[s[r]-'A']);
          while((r-l+1)-maxfreq>k){
            freq[s[l]-'A']--;
            l++;
          }
          ans=max(ans,r-l+1);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    int k;
    cin>>s;
    cin>>k;
    cout<<obj.characterReplacement(s,k)<<endl;
    return 0;
}
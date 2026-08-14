#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,int> freq;
        for(int right=0;right<s.size();right++){
          freq[s[right]]++;
          while(freq[s[right]]>2){
            freq[s[left]]--;
            left++;
          }
          ans=max(ans,right-left+1);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    int ans=obj.maximumLengthSubstring(s);
    cout<<"output "<<ans<<endl;
    return 0;
}
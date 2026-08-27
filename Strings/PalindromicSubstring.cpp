#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            int left=i;
            int right=i;
            while(left>=0 &&right<s.size()&&s[left]==s[right]){
                count++;
                left--;
                right++;
            }
             left=i;
             right=i+1;
            while(left>=0 && right<s.size()&& s[left]==s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
int ans=obj.countSubstrings(s);
cout<<ans<<endl;
return 0;
}
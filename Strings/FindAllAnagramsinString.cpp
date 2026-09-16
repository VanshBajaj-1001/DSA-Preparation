#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        int m=s.size();
        int n=p.size();
        if(n>m){
            return ans;
        }
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(char ch:p){
            f1[ch-'a']++;
        }
        for(int i=0;i<n;i++){
            f2[s[i]-'a']++;
        }
        if(f1==f2){
            ans.push_back(0);
        }
        for(int i=n;i<m;i++){
            f2[s[i]-'a']++;
            f2[s[i-n]-'a']--;
            if(f1==f2){
                ans.push_back(i-n+1);
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    vector<int> ans=obj.findAnagrams(s1,s2);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
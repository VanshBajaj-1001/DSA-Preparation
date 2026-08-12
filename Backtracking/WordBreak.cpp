#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
vector<int> dp;
unordered_set<string> dict;
bool solve(string &s,int index){
    if(index==s.size()){
        return true;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    for(int i=index;i<s.size();i++){
        string word=s.substr(index,i-index+1);
        if(dict.count(word)){
            if(solve(s,i+1)){
                dp[index]=true;
                return dp[index];
            }
        }
    }
    dp[index]=false;
    return dp[index];
}
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string i:wordDict){
            dict.insert(i);
        }
        dp.resize(s.length(),-1);
        int ans=solve(s,0);
        return ans;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    int n;
    cout << "Enter number of words: ";
    cin >> n;
    cout<<"Enter elements in dictionary"<<endl;
    vector<string> wordDict(n);
    for(int i=0;i<n;i++){
        cin>>wordDict[i];
    }
    bool ans=obj.wordBreak(s,wordDict);
    cout<<"Output " ;
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
    
}
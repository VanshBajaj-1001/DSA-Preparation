#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<string>> ans;
vector<string> curr;
bool isPalindrome(string s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string s,int start){
    if(start==s.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=start;i<s.size();i++){
        if(isPalindrome(s,start,i)){
            curr.push_back(s.substr(start,i-start+1));
            solve(s,i+1);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
    solve(s,0);
    return ans;
    }
};
int main(){
    Solution obj;
    cout<<"Enter a string"<<endl;
    string s;
    cin>>s;
    vector<vector<string>> ans=obj.partition(s);
    cout<<"Output "<<endl;
    for(auto i: ans){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"]";
    }
    return 0;
}
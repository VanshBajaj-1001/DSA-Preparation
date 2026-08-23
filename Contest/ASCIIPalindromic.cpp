#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindromic(string s) {
        string binary="";
        for(char ch:s){
            int x=ch;
            for(int i=7;i>=0;i--){
             binary+=(((x>>i)&1)+'0');
                
            }
        }
        int l=0;
        int r=binary.size()-1;
        while(l<r){
            if(binary[l]!=binary[r]){
                return false;
            }
                l++;
                r--;
        }
        return true;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    bool ans=obj.isPalindromic(s);
    if(ans){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false";
    }
    return 0;
}

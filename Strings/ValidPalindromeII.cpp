#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isPalindrome(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return isPalindrome(s,left+1,right)||isPalindrome(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};
int main(){
    Solution obj;
    string s;
    cin>>s;
    bool ans=obj.validPalindrome(s);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
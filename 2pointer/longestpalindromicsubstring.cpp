#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            //odd palindrome string
           int  left=i;
            int right=i;
            while(left>=0 && right<=s.size() && s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
            //even palindrome string
             left=i;
             right=i+1;
             while(left>=0 && right<=s.size() && s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    start=left;
                }
                left--;
                right++;
             }
        }
        return s.substr(start,maxlen);
    }
};
int main(){
    Solution obj;
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    string ans=obj.longestPalindrome(s);
    cout<<"Output "<<ans<<endl;
    return 0;
}
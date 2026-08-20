#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            while(left< right && !isalnum((unsigned char)s[left])){
                left++;
            }
            while(left<right && !isalnum((unsigned char)s[right])){
                right--;
            }
            if(tolower((unsigned char)s[left])!= tolower((unsigned char)s[right])){
                return false;
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
    getline(cin,s);
    bool ans=obj.isPalindrome(s);
    cout<<ans<<endl;
    return 0;
    
}
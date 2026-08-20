#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s=s+" ";
        int start=0;
        for(int i=0;i<s.size();i++){
            if(i==s.size() || s[i]==' '){
                int left=start;
                int right=i-1;
                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                start=i+1;
            }
        }
        s.pop_back();
        return s;
    }
};
int main(){
    Solution obj;
    string s;
    getline(cin,s);
    string ans=obj.reverseWords(s);
    cout<<ans<<endl;
    return 0;
}